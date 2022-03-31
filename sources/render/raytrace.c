/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:38:35 by dmitry            #+#    #+#             */
/*   Updated: 2022/04/01 00:32:59 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	is_closest_intersection_point(const t_point *origin_point,
			const t_point *intersection_point, const t_point *closest_point)
{
	t_vec	intersection_vec;
	t_vec	closest_vec;
	double	intersection_vec_length;
	double	closest_vec_length;

	if (intersection_point->x == INFINITY)
		return (0);
	else
	{
		if (closest_point->x == INFINITY)
			return (1);
		else
		{
			intersection_vec = vec_subtract(origin_point, intersection_point);
			closest_vec = vec_subtract(origin_point, closest_point);
			intersection_vec_length = vec_length(&intersection_vec);
			closest_vec_length = vec_length(&closest_vec);
			if (intersection_vec_length < closest_vec_length)
				return (1);
		}
	}	
	return (0);
}

t_color	raytrace(t_minirt *minirt, t_point *origin, t_vec *ray)
{
	t_intersect	intersection;
	t_list		*objects_list;
	t_color		color;

	set_sky_color(minirt, &color, ray);
	intersection = cast_ray(minirt, NULL, origin, ray);
	if (intersection.object)
		color = calculate_light(minirt, intersection.object,
				&intersection.point);
	return (color);
}
