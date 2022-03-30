/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:39:51 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/31 02:08:42 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	point_in_shadow(t_minirt *minirt, t_object *object,
				t_point *origin, t_vec *ray)
{
	t_intersect	intersection;
	t_list		*objects_list;
	t_vec		new_ray;

	new_ray = vec_subtract(&minirt->scene->light->pos, origin);
	new_ray = vec_normalize(&new_ray);
	intersection = cast_ray(minirt, object,
			&minirt->scene->light->pos, &new_ray);
	if (intersection.object && intersection.object == object)
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
	if (angle >= 0 && angle <= 1)
	{
		color = object->color;
		color.r = color.r * angle * minirt->scene->light->brightness_ratio;
		color.g = color.g * angle * minirt->scene->light->brightness_ratio;
		color.b = color.b * angle * minirt->scene->light->brightness_ratio;
		if (point_in_shadow(minirt, object, intersection_point, &light_ray))
		{
			color.r /= 3;
			color.g /= 3;
			color.b /= 3;
		}
	}
	return (color);
}
