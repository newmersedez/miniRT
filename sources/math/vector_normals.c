/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 01:30:19 by dmitry            #+#    #+#             */
/*   Updated: 2022/04/01 15:05:26 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vec	get_sphere_normal_vec(void *data, t_point *intersection)
{
	t_vec		vec;
	t_sphere	*sphere;

	sphere = (t_sphere *)data;
	vec = vec_subtract(&sphere->pos, intersection);
	vec = vec_normalize(&vec);
	return (vec);
}

t_vec	get_plane_normal_vec(void *data, t_point *intersection)
{
	t_plane	*plane;

	(void)intersection;
	plane = (t_plane *)data;
	return (plane->dir);
}

t_vec	get_cylinder_normal_vec(void *data, t_point *intersection)
{
	t_cylinder	*cylinder;
	t_vec		n;
	t_vec		v;
	t_vec		temp;
	t_point		c0;

	cylinder = (t_cylinder *)data;
	v = vec_subtract(&cylinder->pos, intersection);
	temp = vec_multiply_by_num(&cylinder->dir, vec_dot(&v, &cylinder->dir));
	c0 = vec_add(&cylinder->pos, &temp);
	temp = vec_subtract(&c0, intersection);
	n = vec_normalize(&temp);
	return (n);
}
