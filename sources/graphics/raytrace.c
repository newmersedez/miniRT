/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:38:35 by dmitry            #+#    #+#             */
/*   Updated: 2022/03/24 16:28:49 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_color	raytrace(t_minirt *minirt, t_vec *origin, t_vec *dir)
{
	t_list		*object_list;
	t_object	*closest_object;
	t_point		closest_point;
	t_point		intersect_point;
	t_color		color;

	set_default_color(&color);
	set_default_closest_point(&closest_point);
	closest_object = NULL;
	object_list = minirt->scene->objects_list;
	while (object_list)
	{
		intersect_point = object_list->object->ray_intersection(object_list->object, origin, dir);
		object_list = object_list->next;
	}
	if (closest_object)
	{
		// color = calculate_color(&closest_object);
	}
	return (color);
}
