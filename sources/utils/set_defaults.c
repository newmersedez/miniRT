/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_defaults.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:58:24 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/29 01:02:04 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	set_default_color(t_color *color)
{
	color->r = 0;
	color->g = 0;
	color->b = 0;
}

void	set_default_point(t_point *point)
{
	point->x = INFINITY;
	point->y = INFINITY;
	point->z = INFINITY;
}

int	is_default_point(const t_point *point)
{
	if (point->x == INFINITY && point->y == INFINITY && point->z == INFINITY)
		return (1);
	return (0);
}
