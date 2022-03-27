/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 01:30:19 by dmitry            #+#    #+#             */
/*   Updated: 2022/03/27 02:33:30 by dmitry           ###   ########.fr       */
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
	return (plane->normal);
}

t_vec	get_cylinder_normal_vec(const void *data, const t_point *intersection)
{
	t_cylinder	*cylinder;
	t_vec		n;
	t_vec		v;
	t_vec		temp;
	double		k;
	t_point		c0;

	cylinder = (t_cylinder *)data;
	v = vec_subtract(intersection, &cylinder->pos);
	temp = vec_multiply_by_num(&cylinder->normal, vec_dot(&v, &cylinder->normal));
	c0 = vec_add(&cylinder->pos, &temp);
	temp = vec_subtract(intersection, &c0);
	n = vec_normalize(&temp);
	return (n);
}
