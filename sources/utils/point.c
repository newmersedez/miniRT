/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:40:14 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/31 17:41:09 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"


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