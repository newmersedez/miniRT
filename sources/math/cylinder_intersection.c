/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:01:25 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/29 00:11:27 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	solve_square(double k[3], double *d1, double *d2)
{
	double	discriminant;
	double	a;

	a = k[2];
	*d1 = INFINITY;
	*d2 = INFINITY;
	if (k[1] * k[1] < 4 * k[2] * k[0])
		return (0);
	discriminant = sqrt(k[1] * k[1] - 4 * k[2] * k[0]);
	*d1 = (-k[1] + discriminant) / (2 * a);
	*d2 = (-k[1] - discriminant) / (2 * a);
	return (2);
}

static double	get_solution(t_cylinder *cyl, t_point *origin,
					t_vec *dir, double *x)
{
	t_vec	calc_vec;

	calc_vec = vec_multiply_by_num(dir, x[1]);
	calc_vec = vec_add(origin, &calc_vec);
	calc_vec = vec_subtract(&cyl->pos, &calc_vec);
	if (x[1] > 0 && x[1] < INFINITY
		&& fabs(vec_dot(&cyl->dir, &calc_vec)) < cyl->height / 2)
		return (x[1]);
	calc_vec = vec_multiply_by_num(dir, x[0]);
	calc_vec = vec_add(origin, &calc_vec);
	calc_vec = vec_subtract(&cyl->pos, &calc_vec);
	if (x[0] > 0 && x[0] < INFINITY
		&& fabs(vec_dot(&cyl->dir, &calc_vec)) < cyl->height / 2)
		return (x[0]);
	return (INFINITY);
}

static double	find_t(t_cylinder *cyl, t_point *origin, t_vec *dir)
{
	t_vec	oc;
	t_vec	temp;
	double	t[3];
	double	x[2];

	oc = vec_subtract(origin, &cyl->pos);
	t[2] = pow(dir->x, 2) + pow(dir->y, 2) + pow(dir->z, 2);
	t[1] = -2 * (dir->x * oc.x + dir->y * oc.y + dir->z * oc.z);
	t[0] = pow(oc.x, 2) + pow(oc.y, 2) + pow(oc.z, 2);
	x[0] = vec_dot(dir, &cyl->dir);
	x[1] = vec_dot(&oc, &cyl->dir);
	t[2] -= pow(x[0], 2);
	t[1] -= -2 * x[0] * x[1];
	t[0] -= pow(x[1], 2);
	t[0] += -pow(cyl->diameter / 2, 2);
	solve_square(t, &x[0], &x[1]);
	return (get_solution(cyl, origin, dir, x));
}

t_point	ray_intersect_cylinder(const void *data, const t_point *start_point,
			const t_vec *ray)
{
	t_cylinder	*cylinder;
	t_point		point;
	double		t;

	cylinder = (t_cylinder *)data;
	set_default_point(&point);
	t = find_t(cylinder, start_point, ray);
	if (t >= 0 && t <= INFINITY)
	{	
		point = vec_multiply_by_num(ray, t);
		point = vec_add(start_point, &point);
	}
	return (point);
}
