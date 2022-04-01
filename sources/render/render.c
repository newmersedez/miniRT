/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:17:43 by lorphan           #+#    #+#             */
/*   Updated: 2022/04/01 16:33:02 by lorphan          ###   ########.fr       */
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
			color = raytrace(minirt, &minirt->scene.camera->pos, &dir);
			my_mlx_pixel_put(&minirt->image, x, y, mix_colors(&color));
			++y;
		}
		++x;
	}
	mlx_put_image_to_window(minirt->window.mlx, minirt->window.mlx_win,
		minirt->image.img, 0, 0);
}
