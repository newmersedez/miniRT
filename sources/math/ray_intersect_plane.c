/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect_plane.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:00:38 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/24 20:37:51 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_point	ray_intersect_plane(const void *data, const t_point *start_point,
			const t_vec *ray)
{
	t_point	point;
	t_plane	*plane;
	t_vec	ray_normal;
	t_vec	vec;
	double	denom;
	double	t;

	plane = (t_plane *)data;
	set_default_point(&point);
	ray_normal = vec_normalize(ray);
	denom = vec_dot(&plane->normal, &ray_normal);
	if (denom > 1e-6)
	{
		vec = vec_subtract(start_point, &plane->pos);
		t = vec_dot(&vec, &plane->normal) / denom;
		point = vec_multiply_by_num(ray, t);
		point = vec_add(start_point, &point);
	}
	return (point);
}
