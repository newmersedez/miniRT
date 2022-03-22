/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:17:43 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/22 18:05:43 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_vec3	convert_to_viewport(t_minirt *minirt, double x, double y)
{
	t_vec3	norm_device_coord;
	t_vec3	pixel_screen_coord;
	t_vec3	pixel_camera_coord;
	double	aspect_ratio;
	double	fov;

	aspect_ratio = (double)WINDOW_WIDTH / WINDOW_HEIGHT;
	fov = tan(minirt->scene->camera->fov / 2);
	
	norm_device_coord.x = (x + 0.5) / WINDOW_WIDTH;
	norm_device_coord.y = (y + 0.5) / WINDOW_HEIGHT;
	
	pixel_screen_coord.x = (2 * norm_device_coord.x - 1);
	pixel_screen_coord.y = 1 - 2 * norm_device_coord.y;

	pixel_camera_coord.x = (2 * pixel_screen_coord.x - 1) * aspect_ratio * fov;
	pixel_camera_coord.y = (1 - 2 * pixel_screen_coord.x) * fov;
	pixel_camera_coord.z = 1;
	return (vec_normalize(&pixel_camera_coord));
}

static t_color	raytrace(t_minirt *minirt, t_vec3 *origin, t_vec3 *dir)
{
	
}

void	render(t_minirt *minirt)
{
	size_t	x;
	size_t	y;
	t_vec3	dir_vec;
	t_color	color;
	double	*intersections;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			dir_vec = convert_to_viewport(minirt, (double)x, (double)y);
			color = raytrace(minirt, &minirt->scene->camera->pos, &dir_vec);
			// my_mlx_pixel_put(minirt->image, x, y,
			// 	((color.r & 0xFF) << 16)
			// 	+ ((color.g & 0xFF) << 8)
			// 	+ (color.b & 0xFF));
			++y;
		}
		++x;
	}
	mlx_put_image_to_window(minirt->window->mlx, minirt->window->mlx_win,
		minirt->image->img, 0, 0);
}
