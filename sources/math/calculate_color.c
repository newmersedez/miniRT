/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:39:51 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/27 20:04:41 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_vec	change_plane_normal(t_vec *normal_vec, t_vec *ray)
{
	t_vec	new_normal_vec;
	double	dot_product;
	double	cos_angle;

	dot_product = vec_dot(normal_vec, ray);
	cos_angle = dot_product / (vec_length(normal_vec) + vec_length(ray));
	if (cos_angle >= 0 && cos_angle <= 1)
		new_normal_vec = *normal_vec;
	else
		new_normal_vec = vec_multiply_by_num(normal_vec, -1);
	return (new_normal_vec);
}

t_color	calculate_color(t_minirt *minirt, t_object *object, t_point *intersection_point)
{
	t_color	color;
	t_vec	normal_vec;
	t_vec	light_vec;
	double	dot_product_light;
	double	light_angle;

	set_default_color(&color);
	normal_vec = object->get_normal_vector(object->figure, intersection_point);
	if (object->type == CYLINDER)
		light_vec = vec_subtract(&minirt->scene->light->pos, intersection_point);
	else
		light_vec = vec_subtract(intersection_point, &minirt->scene->light->pos);
	light_vec = vec_normalize(&light_vec);
	if (object->type == PLANE)
		normal_vec = change_plane_normal(&normal_vec, &light_vec);
	dot_product_light = vec_dot(&light_vec, &normal_vec);
	light_angle = dot_product_light / (vec_length(&light_vec) * vec_length(&normal_vec));
	
	if (light_angle >= 0 && light_angle <= 1)
	{
		color = object->color;
		color.r = color.r * light_angle * minirt->scene->light->brightness_ratio;
		color.g = color.g * light_angle * minirt->scene->light->brightness_ratio;
		color.b = color.b * light_angle * minirt->scene->light->brightness_ratio;
	}

	// t_color	color;
	// set_default_color(&color);
	// if (intersection_point->x != INFINITY)
	// 	color = object->color;
	return (color);
}
