/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:39:51 by lorphan           #+#    #+#             */
/*   Updated: 2022/04/01 00:40:17 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_point	reflect_ray(t_vec *ray, t_vec *normal)
{
	t_vec	new_normal;

	new_normal = vec_multiply_by_num(normal, 2 * vec_dot(normal, ray));
	return (vec_subtract(ray, &new_normal));
}

static int	point_in_shadow(t_minirt *minirt, t_object *object,
				t_point *origin, t_vec *ray)
{
	t_list		*objects_list;
	t_vec		new_ray;
	t_intersect	intersection;

	new_ray = vec_subtract(&minirt->scene->light->pos, origin);
	new_ray = vec_normalize(&new_ray);
	intersection = cast_ray(minirt, object,
					&minirt->scene->light->pos, &new_ray);
	if (intersection.object && intersection.object == object)
		return (0);
	return (1);
}

static double	get_specular(t_minirt *minirt, t_vec *normal,
					t_point *intersection_point)
{
	double	light;
	double	dot_pruduct;
	double	angle;
	t_vec	direction;
	t_vec	reflected;

	direction = vec_subtract(intersection_point, &minirt->scene->light->pos);
	reflected = (reflect_ray(&direction, normal));
	dot_pruduct = vec_dot(&reflected, &direction);
	angle = dot_pruduct / (vec_length(&reflected) * vec_length(&direction));
	light = minirt->scene->light->brightness_ratio * pow(fmax(0.0, angle), 32);
	return (light);
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
	if (minirt->scene->ambient_light)
		add_coefficient(&color, &minirt->scene->ambient_light->color,
			minirt->scene->ambient_light->lighting_ratio);
	if (dot_pruduct > 0 && !point_in_shadow(minirt, object,
			intersection_point, &light_ray))
	{
		angle = dot_pruduct
			/ (vec_length(&light_ray) * vec_length(&normal_vec));
		angle *= minirt->scene->light->brightness_ratio;
		add_coefficient(&color, &minirt->scene->light->color, angle);
		angle = get_specular(minirt, &normal_vec, intersection_point);
		add_coefficient(&color, &minirt->scene->light->color, angle);
	}
	color = build_color(&object->color, &color);
	return (color);
}
