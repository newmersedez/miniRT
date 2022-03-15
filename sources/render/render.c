/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:17:43 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/15 14:17:18 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	render(t_minirt *minirt)
{
	double	radius = 100;
	double	x = 500;
	double	y = 500;

	for (double i = x - radius; i <= x + radius; i++)
	{
		for (double j = y - radius; j <= y + radius; j++)
		{	
			double	dist = sqrtf((i - x) * (i - x) + (j - y) * (j - y));
			if (fabs(radius - dist) <= 1)
				my_mlx_pixel_put(minirt->image, i, j, 0xFFFFFF);
			else if (radius - dist > 1)
				my_mlx_pixel_put(minirt->image, i, j, 0xFF0000);
		}
	}
	mlx_put_image_to_window(minirt->window->mlx, minirt->window->mlx_win, minirt->image->img, 0, 0);
}
