/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:17:43 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/22 23:06:20 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static float	*intersect_ray_sphere(t_vec3 *camera_vec, t_vec3 *d_vec, t_sphere *sphere)
{
	float	*intersections;
	float	k1;
	float	k2;
	float	k3;
	float	discriminant;
	t_vec3	oc_vec;

	intersections = (float *)malloc(2 * sizeof(float));
	if (!intersections)
		return (NULL);
	oc_vec = vec_subtract(&sphere->pos, camera_vec);
	k1 = vec_dot(d_vec, d_vec);
	k2 = 2 * vec_dot(&oc_vec, d_vec);
	k3 = vec_dot(&oc_vec, &oc_vec) - (sphere->diameter / 2) * (sphere->diameter / 2);
	discriminant = k2 * k2 - 4 * k1 * k3;
    if (discriminant < 0)
	{
		intersections[0] = INFINITY;
		intersections[1] = INFINITY;
	}
	else
	{
		intersections[0] = (-k2 + sqrtf(discriminant)) / (2 * k1);
    	intersections[1] = (-k2 - sqrtf(discriminant)) / (2 * k1);
	}
	return (intersections);
}

static t_color	calculate_light(t_minirt *minirt, t_vec3 *pixel, t_sphere *sphere)
{
	t_vec3	normal_vec;
	t_vec3	light_vec;
	t_color	color;
	float	angle;
	float	dot_product;

	normal_vec.x = pixel->x - sphere->pos.x;
	normal_vec.y = pixel->y - sphere->pos.y;
	normal_vec.z = pixel->z - sphere->pos.z;
	normal_vec = vec_normalize(&normal_vec);

	light_vec.x = pixel->x - minirt->scene->light->pos.x;
	light_vec.y = pixel->y - minirt->scene->light->pos.y;
	light_vec.z = pixel->z - minirt->scene->light->pos.z;
	light_vec = vec_normalize(&light_vec);

	dot_product = vec_dot(&light_vec, &normal_vec);
	angle = dot_product / (vec_length(&light_vec) * vec_length(&normal_vec));
	color = sphere->color;	
	if (angle >= 0 && angle <= 1)
	{
		color.r *= angle * minirt->scene->light->brightness_ratio;
		color.g *= angle * minirt->scene->light->brightness_ratio;
		color.b *= angle * minirt->scene->light->brightness_ratio;
	}
	else
	{
		color.r = 0;
		color.g = 0;
		color.b = 0;
	}
	return (color);
}

static t_color	raytrace(t_minirt *minirt, t_vec3 *origin, t_vec3 *dir)
{
	float		closest_t;
	float		*t_array;
	t_sphere	*closest_sphere;
	t_list		*figure_list;
	t_color		color = {0, 0, 0};

	closest_t = INFINITY;
	closest_sphere = NULL;
	figure_list = minirt->scene->figures_list;
	while (figure_list)
	{
		t_array = intersect_ray_sphere(origin, dir, (t_sphere *)figure_list->figure);
		if (t_array)
		{
			if ((t_array[0] >= 1 && t_array[0] <= INFINITY) && (t_array[0] < closest_t))
			{
				closest_t = t_array[0];
				closest_sphere = (t_sphere *)figure_list->figure;
			}
			if ((t_array[1] >= 1 && t_array[1] <= INFINITY) && (t_array[1] < closest_t))
			{
				closest_t = t_array[1];
				closest_sphere = (t_sphere *)figure_list->figure;
			}
			free(t_array);
			t_array = NULL;
		}
		figure_list = figure_list->next;
	}
	if (closest_sphere)
	{	
		t_vec3	pixel = vec_multiply_by_num(dir, closest_t);
		color = calculate_light(minirt, &pixel, closest_sphere);
		// color = closest_sphere->color;
	}
	return (color);
}

void	render(t_minirt *minirt)
{
	size_t	x;
	size_t	y;
	t_vec3	dir;
	t_color	color;
	float	*intersections;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			dir = convert_to_viewport(minirt, (float)x, (float)y);
			color = raytrace(minirt, &minirt->scene->camera->pos, &dir);
			my_mlx_pixel_put(minirt->image, x, y,
				((color.r & 0xFF) << 16)
				+ ((color.g & 0xFF) << 8)
				+ (color.b & 0xFF));
			++y;
		}
		++x;
	}
	mlx_put_image_to_window(minirt->window->mlx, minirt->window->mlx_win,
		minirt->image->img, 0, 0);
}
