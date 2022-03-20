/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:17:43 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/21 01:24:31 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_color	raytrace(t_vec3 *start, t_vec3 *end, double x, double y)
{
	void	*closest_figure;
	t_color	color = {x / 10, y / 10, 0};

	(void)x;
	(void)y;
	(void)start;
	(void)end;
	(void)closest_figure;
	return (color);
}

void	render(t_minirt *minirt)
{
	size_t	x;
	size_t	y;
	t_vec3	d_vec;
	t_color	color;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			d_vec = convert_to_viewport(minirt, (double)x, (double)y);
			color = raytrace(&minirt->scene->camera->pos, &d_vec,
					(double)x, (double)y);
			my_mlx_pixel_put(minirt->image, x, y,
				((color.r & 0xFF) << 16)
				+ ((color.g & 0xFF) << 8)
				+ (color.b & 0xFF));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(minirt->window->mlx, minirt->window->mlx_win,
		minirt->image->img, 0, 0);
}
