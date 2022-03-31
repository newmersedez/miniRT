/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:40:11 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/31 21:37:40 by lorphan          ###   ########.fr       */
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

int		mix_colors(t_color *color)
{
	return ((int)color->r << 16) | ((int)color->g << 8) | (int)color->b;
}

void	add_coefficient(t_color *color, t_color *light_color, double coef)
{
	if (!color || !light_color)
		return ;
	color->r += coef * light_color->r / 255.;
	color->g += coef * light_color->g / 255.;
	color->b += coef * light_color->b / 255.;
}

t_color	build_color(t_color *color, t_color *light_color)
{
	t_color	res_color;

	res_color.r = 0;
	res_color.g = 0;
	res_color.b = 0;
	if (!color || !light_color)
		return (res_color);
	res_color.r = color->r * light_color->r;
	res_color.g = color->g * light_color->g;
	res_color.b = color->b * light_color->b;
	if (res_color.r > 255)
		res_color.r = 255;
	if (res_color.g > 255)
		res_color.g = 255;
	if (res_color.b > 255)
		res_color.b = 255;
	return (res_color);
}
