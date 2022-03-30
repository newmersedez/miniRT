/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:20:13 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/30 21:20:14 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static double	find_t(t_sphere *sphere, t_point *origin, t_vec *ray)
{
	t_vec	l;
	double	d2;
	double	tca;
	double	thc;
	double	t_values[3];

	t_values[2] = INFINITY;
	l = vec_subtract(origin, &sphere->pos);
	tca = vec_dot(&l, ray);
	d2 = vec_dot(&l, &l) - tca * tca;
	if (d2 > (sphere->diameter * sphere->diameter) / 4.0)
		return (INFINITY);
	thc = sqrt((sphere->diameter * sphere->diameter) / 4.0 - d2);
	t_values[0] = tca - thc;
	t_values[1] = tca + thc;
	if ((t_values[0] >= 0 && t_values[0] <= INFINITY)
		&& (t_values[0] < t_values[2]))
		t_values[2] = t_values[0];
	if ((t_values[1] >= 0 && t_values[1] <= INFINITY)
		&& (t_values[1] < t_values[2]))
		t_values[2] = t_values[1];
	return (t_values[2]);
}

t_point	ray_intersect_sphere(const void *data, const t_point *start_point,
			const t_vec *ray)
{
	t_sphere	*sphere;
	t_point		point;
	double		t;

	sphere = (t_sphere *)data;
	set_default_point(&point);
	t = find_t(sphere, start_point, ray);
	if (t >= 0 && t < INFINITY)
	{
		point = vec_multiply_by_num(ray, t);
		point = vec_add(start_point, &point);
	}
	return (point);
}
