/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:39:51 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/31 20:33:49 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	point_in_shadow(t_minirt *minirt, t_object *object,
				t_point *origin, t_vec *ray)
{
	t_list	*objects_list;
	t_vec	n_ray;
	t_point	intersection;
	t_point	closest;
	t_object *closest_object;

	n_ray = vec_subtract(&minirt->scene->light->pos, origin);
	n_ray = vec_normalize(&n_ray);
	set_default_point(&closest);
	closest_object = object;
	objects_list = minirt->scene->objects_list;	
	while (objects_list)
	{
		intersection = objects_list->object->ray_intersection(
			objects_list->object->figure, &minirt->scene->light->pos, &n_ray);
		if (is_closest_intersection_point(&minirt->scene->light->pos,
		&intersection, &closest))
		{
			closest = intersection;
			closest_object = objects_list->object;
		}
		objects_list = objects_list->next;
	}
	if (closest_object && closest_object == object)
		return (0);
	return (1);
}

t_color	calculate_light(t_minirt *minirt, t_object *object,
			t_point *intersection_point)
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
	if (minirt->scene->ambient_light)
	{
		// printf("ambient coloor\n");	
		add_coeficient(&color, &minirt->scene->ambient_light->color, minirt->scene->ambient_light->lighting_ratio);
	}
	if (angle >= 0)
	{
		if (minirt->scene->light)
		{
			// printf("light color\n");	
			add_coeficient(&color, &minirt->scene->light->color, angle * minirt->scene->light->brightness_ratio);
		}
		color = build_color(&object->color, &color);
		if (point_in_shadow(minirt, object, intersection_point, &light_ray))
		{
			color.r /= 3;
			color.g /= 3;
			color.b /= 3;
		}
	}
	return (color);
}
