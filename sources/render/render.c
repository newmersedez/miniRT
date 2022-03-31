/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:17:43 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/31 20:33:06 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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
			dir = create_ray(minirt, (double)x, (double)y);
			color = raytrace(minirt, &minirt->scene->camera->pos, &dir);
			my_mlx_pixel_put(minirt->image, x, y,
				(((int)color.r & 0xFF) << 16)
				+ (((int)color.g & 0xFF) << 8)
				+ ((int)color.b & 0xFF));
			++y;
		}
		++x;
	}
	mlx_put_image_to_window(minirt->window->mlx, minirt->window->mlx_win,
		minirt->image->img, 0, 0);
}
