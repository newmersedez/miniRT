/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:00:38 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/29 00:13:02 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vec	change_plane_normal(const t_vec *normal_vec, const t_vec *ray)
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

static double	find_t(t_plane *plane, t_vec *plane_normal,
					t_point *origin, t_vec *ray)
{
	double	denom;
	t_vec	vec;
	double	t;

	t = INFINITY;
	denom = vec_dot(plane_normal, ray);
	if (denom > 0.0001f)
	{
		vec = vec_subtract(origin, &plane->pos);
		t = vec_dot(&vec, plane_normal) / denom;
	}
	return (t);
}

t_point	ray_intersect_plane(const void *data, const t_point *start_point,
			const t_vec *ray)
{
	t_plane	*plane;
	t_point	point;
	t_vec	plane_normal;
	double	t;

	plane = (t_plane *)data;
	set_default_point(&point);
	plane_normal = change_plane_normal(&plane->dir, ray);
	t = find_t(plane, &plane_normal, start_point, ray);
	if (t >= 0 && t <= INFINITY)
	{
		point = vec_multiply_by_num(ray, t);
		point = vec_add(start_point, &point);
	}
	return (point);
}
