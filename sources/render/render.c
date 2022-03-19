/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:17:43 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/19 20:48:09 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_color	raytrace(t_pos *camera_pos, double x, double y)
{
	t_color	color = {0, 0, 0};
	(void)x;
	(void)camera_pos;
	(void)y;
	return (color);
}

void	render(t_minirt *minirt)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT)
		{
			my_mlx_pixel_put(minirt->image, i, j, 0xFFFFFF);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(minirt->window->mlx, minirt->window->mlx_win, minirt->image->img, 0, 0);
}
