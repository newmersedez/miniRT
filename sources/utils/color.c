/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:40:11 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/31 20:27:44 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	set_default_color(t_color *color)
{
	color->r = 0;
	color->g = 0;
	color->b = 0;
}

void	set_sky_color(t_minirt *minirt, t_color *color)
{
	color->r = 0 * minirt->scene->light->brightness_ratio;
	color->g = 150 * minirt->scene->light->brightness_ratio;
	color->b = 255 * minirt->scene->light->brightness_ratio;
}

void	add_coeficient(t_color *object_color, t_color *light_color, double coef)
{
	if (!object_color || !light_color)
		return ;
	object_color->r += coef * light_color->r * pow(255, -1);
	object_color->g += coef * light_color->g * pow(255, -1);
	object_color->b += coef * light_color->b * pow(255, -1);
}

t_color	build_color(t_color *object_color, t_color *light_color)
{
	t_color	res_color;

	if (!object_color || !light_color)
		return (res_color);
	res_color.r = object_color->r * light_color->r;
	res_color.g = object_color->g * light_color->g;
	res_color.b = object_color->b * light_color->b;
	if (res_color.r > 255)
		res_color.r = 255;
	if (res_color.g > 255)
		res_color.g = 255;
	if (res_color.b > 255)
		res_color.b = 255;
	return (res_color);
}
// int	build_color(int color, double rgb[3])
// {
// 	unsigned int	mask;
// 	unsigned int	r;
// 	unsigned int	g;
// 	unsigned int	b;

// 	mask = 255 << 16;
// 	r = rgb[0] * ((color & mask) >> 16);
// 	mask >>= 8;
// 	g = rgb[1] * ((color & mask) >> 8);
// 	mask >>= 8;
// 	b = rgb[2] * (color & mask);
// 	if (r > 255)
// 		r = 255;
// 	if (g > 255)
// 		g = 255;
// 	if (b > 255)
// 		b = 255;
// 	return (mix_colors(r, g, b));
// }
