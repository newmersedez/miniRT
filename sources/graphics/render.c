/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:17:43 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/22 19:10:11 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_vec3	convert_to_viewport(t_minirt *minirt, float x, float y)
{
	t_vec3	end_vec;
	double	converted_fov;
	double	aspect_ratio;

	aspect_ratio = (double)WINDOW_WIDTH  / (double)WINDOW_HEIGHT;
	converted_fov = minirt->scene->camera->fov / (double)DEFAULT_FOV;
	end_vec.x = aspect_ratio
		* (x - WINDOW_WIDTH / 2) * (converted_fov / (double)WINDOW_WIDTH);
	end_vec.y = -(y - WINDOW_HEIGHT / 2)
		* (converted_fov / (double)WINDOW_HEIGHT);
	end_vec.z = 1;
	return (vec_normalize(&end_vec));
}

static double	*intersect_ray_sphere(t_vec3 *camera_vec, t_vec3 *d_vec, t_sphere *sphere)
{
	double	*intersections;
	double	k1;
	double	k2;
	double	k3;
	double	discriminant;
	t_vec3	oc_vec;

	intersections = (double *)malloc(2 * sizeof(double));
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

static t_color	raytrace(t_minirt *minirt, t_vec3 *origin, t_vec3 *dir)
{
	double		closest_t;
	double		*t_array;
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
			// printf("%zu %zu\n", x, y);
			++y;
		}
		++x;
	}
	mlx_put_image_to_window(minirt->window->mlx, minirt->window->mlx_win,
		minirt->image->img, 0, 0);
}
