/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:39:51 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/28 03:07:44 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	pixel_in_shadow(t_minirt *minirt, const t_object *object, const t_point *origin, const t_vec *ray)
{
	t_list	*objects_list;
	t_point	intersection_point;
	t_vec	normal_vec;
	t_point	closest_point;
	t_point	origin_0;
	t_vec	origin_normal_vec;

	set_default_point(&closest_point);
	origin_normal_vec = object->get_normal_vector(object->figure, origin);
	origin_normal_vec = vec_multiply_by_num(&origin_normal_vec, 1.1);
	origin_0 = vec_add(origin, &origin_normal_vec);
	objects_list = minirt->scene->objects_list;
	while (objects_list)
	{
		intersection_point = objects_list->object->ray_intersection(
			objects_list->object->figure, &origin_0, ray);
		// normal_vec = objects_list->object->get_normal_vector(
		// 	objects_list->object->figure, &intersection_point);
		// intersection_point = vec_add(&intersection_point, &normal_vec);
		if (is_closest_intersection_point(&origin_0,
				&intersection_point, &closest_point))
			closest_point = intersection_point;
		objects_list = objects_list->next;
	}
	if (closest_point.x != INFINITY)
		return (1);
	return (0);
}

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

t_color	calculate_light(t_minirt *minirt, t_object *object, t_point *intersection_point)
{
	t_color	color;
	t_vec	normal_vec;
	t_vec	light_ray;
	double	dot_product_light;
	double	light_angle;

	set_default_color(&color);
	normal_vec = object->get_normal_vector(object->figure, intersection_point);
	light_ray = vec_subtract(intersection_point, &minirt->scene->light->pos);
	light_ray = vec_normalize(&light_ray);
	if (object->type == PLANE)
		normal_vec = change_plane_normal(&normal_vec, &light_ray);
	dot_product_light = vec_dot(&light_ray, &normal_vec);
	light_angle = dot_product_light / (vec_length(&light_ray) * vec_length(&normal_vec));
	if (light_angle >= 0 && light_angle <= 1)
	{
		// color = calculate_shadow(minirt, intersection_point, &light_ray);
		if (pixel_in_shadow(minirt, object, intersection_point, &light_ray))
		{
			color = object->color;
			color.r = 0;
			color.g = 0;
			color.b = 0;
		}
		else
		{
			color = object->color;
			color.r = color.r * light_angle * minirt->scene->light->brightness_ratio;
			color.g = color.g * light_angle * minirt->scene->light->brightness_ratio;
			color.b = color.b * light_angle * minirt->scene->light->brightness_ratio;
		}
	}
	return (color);
}
