/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:17:43 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/24 17:39:46 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_vec	convert_to_viewport(t_minirt *minirt, double x, double y)
{
	t_vec	end_vec;
	double	fov;
	double	aspect_ratio;

	aspect_ratio = (double)WINDOW_WIDTH  / WINDOW_HEIGHT;
	fov = minirt->scene->camera->fov / (double)DEFAULT_FOV;
	end_vec.x = (x - WINDOW_WIDTH / 2) * (fov / WINDOW_WIDTH) * aspect_ratio;
	end_vec.y = -1 * (y - WINDOW_HEIGHT / 2) * (fov / WINDOW_HEIGHT);
	end_vec.z = 1;
	return (vec_normalize(&end_vec));
}

void	render(t_minirt *minirt)
{
	size_t	x;
	size_t	y;
	t_vec	dir;
	t_color	color;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			dir = convert_to_viewport(minirt, (double)x, (double)y);
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
