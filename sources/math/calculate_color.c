/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:39:51 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/24 22:07:57 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_color	calculate_color(t_minirt *minirt, t_object *object, t_point *intersection_point)
{
	t_vec	normal_vec;
	t_vec	light_vec;
	t_color	color;
	float	angle;
	float	dot_product;

	set_default_color(&color);
	normal_vec = object->get_normal_vector(object->figure, intersection_point);
	light_vec = vec_subtract(intersection_point, &minirt->scene->light->pos);
	light_vec = vec_normalize(&light_vec);
	dot_product = vec_dot(&light_vec, &normal_vec);
	angle = dot_product / (vec_length(&light_vec) * vec_length(&normal_vec));
	if (angle >= 0 && angle <= 1)
	{
		color = object->color;
		color.r = color.r * angle * minirt->scene->light->brightness_ratio;
		color.g = color.g * angle * minirt->scene->light->brightness_ratio;
		color.b = color.b * angle * minirt->scene->light->brightness_ratio;
	}
	return (color);
}
