/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:39:51 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/28 23:58:38 by dmitry           ###   ########.fr       */
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

static int	point_in_shadow(t_minirt *minirt, t_object *object, t_point *intersection)
{
	/*
	* на свежую голову перечитать еще раз статью, по идее тут просто найти то, про что говорил дима
	* то есть просто пустить смещенный лучь из точки пересечения в источник света, найти ближайщую 
	* точку пересечения к позиции света и проверить, если расстояние от полученной точки до источника света
	* меньше, чем расстояние от поданной точки до источника света, то перед точкой что-то есть, и она в тени
	*/
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
	if (point_in_shadow(minirt, object, intersection_point))
		return (color);
	else
	{
		dot_pruduct = vec_dot(&light_ray, &normal_vec);
		angle = dot_pruduct / (vec_length(&light_ray) * vec_length(&normal_vec));
		if (angle >= 0. && angle <= 1.)
		{
			color = object->color;
			color.r = color.r * angle * minirt->scene->light->brightness_ratio;
			color.g = color.g * angle * minirt->scene->light->brightness_ratio;
			color.b = color.b * angle * minirt->scene->light->brightness_ratio;
		}
	}
	return (color);
}
