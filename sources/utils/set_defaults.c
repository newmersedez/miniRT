/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_defaults.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:58:24 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/31 02:12:57 by dmitry           ###   ########.fr       */
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
	color->r = 135 * minirt->scene->light->brightness_ratio;
	color->g = 206 * minirt->scene->light->brightness_ratio;
	color->b = 235 * minirt->scene->light->brightness_ratio;
}

void	set_default_point(t_point *point)
{
	point->x = INFINITY;
	point->y = INFINITY;
	point->z = INFINITY;
}

int	is_intersection_point(const t_point *point)
{
	if (point->x == INFINITY && point->y == INFINITY && point->z == INFINITY)
		return (0);
	return (1);
}
