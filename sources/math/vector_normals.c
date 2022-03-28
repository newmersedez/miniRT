/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 01:30:19 by dmitry            #+#    #+#             */
/*   Updated: 2022/03/29 00:13:32 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vec	get_sphere_normal_vec(const void *data, const t_point *intersection)
{
	t_vec		vec;
	t_sphere	*sphere;

	sphere = (t_sphere *)data;
	vec = vec_subtract(&sphere->pos, intersection);
	vec = vec_normalize(&vec);
	return (vec);
}

t_vec	get_plane_normal_vec(const void *data, const t_point *intersection)
{
	t_vec	vec;
	t_plane	*plane;

	plane = (t_plane *)data;
	return (plane->dir);
}

t_vec	get_cylinder_normal_vec(const void *data, const t_point *intersection)
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
