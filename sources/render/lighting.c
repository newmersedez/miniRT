/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:39:51 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/29 19:01:59 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// static t_color	calculate_shadow(t_minirt *minirt, t_point *origin, t_vec *ray)
// {
// 	t_color		color;
// 	t_list		*objects_list;
// 	t_point		new_intersection_point;
// 	t_point		closest_point;
// 	t_object	*closest_object;
// 	set_default_color(&color);
// 	set_default_point(&closest_point);
// 	objects_list = minirt->scene->objects_list;	
// 	while (objects_list)
// 	{
// 		new_intersection_point = objects_list->object->ray_intersection(
// 			objects_list->object->figure, origin, ray);
// 		if (is_closest_intersection_point(origin,
// 				&new_intersection_point, &closest_point))
// 			{
// 				closest_point = new_intersection_point;
// 				closest_object = objects_list->object;
// 			}
// 		objects_list = objects_list->next;
// 	}
// 	if (closest_point.x != INFINITY)
// 	{
// 		color = closest_object->color;
// 	}
// 	return (color);
// }

static int	point_in_shadow(t_minirt *minirt, t_object *object, t_point *origin, t_vec *ray)
{
	t_list	*objects_list;
	t_point	intersection_point;
	t_point	closest_point;
	t_object *closest_object;
	t_point	origin_0;
	t_vec	dir;

	closest_object = NULL;
	set_default_point(&closest_point);
	dir = *ray;
	dir = vec_multiply_by_num(&dir, 0.1);
	origin_0 = vec_add(origin, &dir);
	
	objects_list = minirt->scene->objects_list;
	while (objects_list)
	{
		intersection_point = objects_list->object->ray_intersection(
			objects_list->object->figure, &origin_0, ray);
		if (is_closest_intersection_point(&origin_0,
				&intersection_point, &closest_point))
			{
				closest_object = objects_list->object;
				closest_point = intersection_point;
			}
		objects_list = objects_list->next;
	}
	if (closest_object)
	{
		t_vec	new_ray;
		t_vec	default_ray;

		new_ray = vec_subtract(&closest_point, &minirt->scene->light->pos);
		// new_ray = vec_normalize(&new_ray);
		
		default_ray = vec_subtract(&origin_0, &minirt->scene->light->pos);
		// default_ray = vec_normalize(&default_ray);

		if (vec_length(&new_ray) < vec_length(&default_ray))
			return (1);
	}
	return (0);
}

t_color	calculate_light(t_minirt *minirt, t_object *object, t_point *intersection_point)
{
	t_color	color;
	t_vec	normal_vec;
	t_vec	light_ray;
	double	dot_pruduct;
	double	angle;

	set_default_color(&color);
	normal_vec = object->get_normal_vector(object->figure, intersection_point);
	light_ray = vec_subtract(intersection_point, &minirt->scene->light->pos);
	light_ray = vec_normalize(&light_ray);
	if (object->type == PLANE)
		normal_vec = change_plane_normal(&normal_vec, &light_ray);
	dot_pruduct = vec_dot(&light_ray, &normal_vec);
	angle = dot_pruduct / (vec_length(&light_ray) * vec_length(&normal_vec));
	if (angle >= 0. && angle <= 1.)
	{
		if (point_in_shadow(minirt, object, intersection_point, &light_ray))
		{
			color = object->color;
			color.r = color.r * angle * minirt->scene->light->brightness_ratio / 2;
			color.g = color.g * angle * minirt->scene->light->brightness_ratio / 2;
			color.b = color.b * angle * minirt->scene->light->brightness_ratio / 2;
		}
		else
		{
			color = object->color;
			color.r = color.r * angle * minirt->scene->light->brightness_ratio;
			color.g = color.g * angle * minirt->scene->light->brightness_ratio;
			color.b = color.b * angle * minirt->scene->light->brightness_ratio;
		}
	}
	return (color);
}
