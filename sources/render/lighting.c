/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:39:51 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/30 20:58:49 by lorphan          ###   ########.fr       */
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
	t_vec	normal_vec;
	t_vec	new_ray;
	t_point	new_origin;
	t_point	intersection;
	t_point	closest;
	t_object *closest_object;

	new_ray = vec_subtract(&minirt->scene->light->pos, origin);
	new_ray = vec_normalize(&new_ray);
	set_default_point(&closest);
	closest_object = object;
	objects_list = minirt->scene->objects_list;	
	while (objects_list)
	{
		intersection = objects_list->object->ray_intersection(
			objects_list->object->figure, &minirt->scene->light->pos, &new_ray);
		if (is_closest_intersection_point(&minirt->scene->light->pos, &intersection, &closest))
		{
			closest = intersection;
			closest_object = objects_list->object;
		}
		objects_list = objects_list->next;
	}
	if (closest_object && closest_object == object)
	{
		// printf("%p %p\n", closest_object, object );
		return (0);
	}
	return (1);
	// normal_vec = object->get_normal_vector(object->figure, origin);
	// if (object->type == PLANE)
	// 	normal_vec = change_plane_normal(&normal_vec, ray);
	// normal_vec = vec_multiply_by_num(&normal_vec, BIAS);
	// new_origin = vec_add(origin, &normal_vec);
	// new_ray = vec_subtract(&new_origin, &minirt->scene->light->pos);
	// new_ray = vec_normalize(&new_ray);	
	// set_default_point(&closest);
	// objects_list = minirt->scene->objects_list;	
	// while (objects_list)
	// {
	// 	intersection = objects_list->object->ray_intersection(
	// 		objects_list->object->figure, &new_origin, &new_ray);
	// 	if (is_closest_intersection_point(&minirt->scene->light->pos,
	// 			&intersection, &closest))
	// 			closest = intersection;
	// 	objects_list = objects_list->next;
	// }
	// if (is_intersection_point(&closest))
	// {
	// 	t_vec	closest_ray;
	// 	t_vec	new_origin_ray;

	// 	// closest_ray = vec_subtract(&closest, &minirt->scene->light->pos);
	// 	closest_ray = vec_subtract(&new_origin, &closest);
	// 	new_origin_ray = vec_subtract(&new_origin, &minirt->scene->light->pos);
	// 	// printf("closest = (%f %f %f) = %f, new_ray = (%f %f %f)%f\n",
	// 	// 	closest_ray.x, closest_ray.y, closest_ray.z, vec_length(&closest_ray),
	// 	// 	new_ray.x, new_ray.y, new_ray.z, vec_length(&new_ray));
	// 	if (vec_length(&closest_ray) < vec_length(&new_origin_ray))
	// 		return (1);
	// }
	// return (0);
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
	if (angle >= 0 && angle <= 1)
	{
		color = object->color;
		color.r = color.r * angle * minirt->scene->light->brightness_ratio;
		color.g = color.g * angle * minirt->scene->light->brightness_ratio;
		color.b = color.b * angle * minirt->scene->light->brightness_ratio;
		if (point_in_shadow(minirt, object, intersection_point, &light_ray))
		{
			// color.r = 255;
			color.r /= 3;
			color.g /= 3;
			color.b /= 3;
		}
	}
	return (color);
}
