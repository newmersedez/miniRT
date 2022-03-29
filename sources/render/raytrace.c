/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:38:35 by dmitry            #+#    #+#             */
/*   Updated: 2022/03/30 00:58:31 by dmitry           ###   ########.fr       */
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
			if (intersection_vec_length <= closest_vec_length)
				return (1);
		}
	}	
	return (0);
}

t_color	raytrace(t_minirt *minirt, t_vec *origin, t_vec *dir)
{
	t_list		*objects_list;
	t_object	*closest_object;
	t_point		closest_point;
	t_point		intersect_point;
	t_color		color;

	set_default_color(&color);
	// color.r = 135 * minirt->scene->light->brightness_ratio;
	// color.g = 206 * minirt->scene->light->brightness_ratio;
	// color.b = 235 * minirt->scene->light->brightness_ratio;
	set_default_point(&closest_point);
	closest_object = NULL;
	objects_list = minirt->scene->objects_list;
	while (objects_list)
	{
		intersect_point = objects_list->object->ray_intersection(
				objects_list->object->figure, origin, dir);
		if (is_closest_intersection_point(origin,
				&intersect_point, &closest_point))
		{
			closest_point = intersect_point;
			closest_object = objects_list->object;
		}
		objects_list = objects_list->next;
	}
	if (closest_object)
		color = calculate_light(minirt, closest_object, &closest_point);
	return (color);
}
