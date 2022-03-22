/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:17:43 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/22 19:58:43 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_vec3	convert_to_viewport(t_minirt *minirt, float x, float y)
{
	t_vec3	end_vec;
	float	converted_fov;
	float	aspect_ratio;

	aspect_ratio = (float)WINDOW_WIDTH  / (float)WINDOW_HEIGHT;
	converted_fov = minirt->scene->camera->fov / (float)DEFAULT_FOV;
	end_vec.x = aspect_ratio
		* (x - WINDOW_WIDTH / 2) * (converted_fov / (float)WINDOW_WIDTH);
	end_vec.y = -(y - WINDOW_HEIGHT / 2)
		* (converted_fov / (float)WINDOW_HEIGHT);
	end_vec.z = 1;
	return (vec_normalize(&end_vec));
}

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

static t_color	calculate_light(t_minirt *minirt, t_vec3 *pixel, t_color *color)
{
	if (minirt->scene->light != NULL)
	{
		if (color->b == 255)
			color->b = 100;
	}
	if (minirt->scene->ambient_light != NULL)
	{
	}
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
		color = closest_sphere->color;
	
	t_vec3	dir_new = vec_multiply_by_num(dir, closest_t);
	t_vec3	p = vec_add(&origin, &dir_new);
	color = calculate_light(minirt, &p, &color);
	return (color);
}

void	render(t_minirt *minirt)
{
	size_t	x;
	size_t	y;
	t_vec3	dir_vec;
	t_color	color;
	float	*intersections;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			dir_vec = convert_to_viewport(minirt, (float)x, (float)y);
			color = raytrace(minirt, &minirt->scene->camera->pos, &dir_vec);
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
