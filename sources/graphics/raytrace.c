/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:38:35 by dmitry            #+#    #+#             */
/*   Updated: 2022/03/24 17:26:15 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	is_closest_intersection_point(t_point *origin_point,
				t_point *intersection_point, t_point *closest_point)
{
	t_vec	intersection_vec;
	t_vec	closest_vec;
	double	intersection_vec_length;
	double	closest_vec_length;

	if (intersection_point->x == INFINITY && intersection_point->y == INFINITY
			&& intersection_point->z == INFINITY)
		return (0);
	else
	{
		if (closest_point->x == INFINITY && closest_point->y == INFINITY
				&& closest_point->z == INFINITY)
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
	t_list		*object_list;
	t_object	*closest_object;
	t_point		closest_point;
	t_point		intersect_point;
	t_color		color;

	set_default_color(&color);
	set_default_point(&closest_point);
	closest_object = NULL;
	object_list = minirt->scene->objects_list;
	while (object_list)
	{
		intersect_point = object_list->object->ray_intersection(object_list->object, origin, dir);
		if (is_closest_intersection_point(origin, &intersect_point, &closest_point))
		{
			closest_point = intersect_point;
			closest_object = object_list->object;
		}
		object_list = object_list->next;
	}
	if (closest_object)
	{
		if (closest_object->type == SPHERE)
			color = ((t_sphere *)closest_object)->color;
		else if (closest_object->type == PLANE)
			color = ((t_plane *)closest_object)->color;
		else if (closest_object->type == CYLINDER)
			color = ((t_cylinder *)closest_object)->color;
	}
	return (color);
}
