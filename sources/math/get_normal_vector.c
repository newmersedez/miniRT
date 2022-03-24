/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 01:30:19 by dmitry            #+#    #+#             */
/*   Updated: 2022/03/24 22:05:27 by lorphan          ###   ########.fr       */
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
	//преобразования с поворотом
	// return (vec);
	return (plane->normal);
}

t_vec	get_cylinder_normal_vec(const void *data, const t_point *intersection)
{
	(void)data;
	(void)intersection;
	t_vec	vec;

	vec.x = 0;
	vec.y = 0;
	vec.z = 0;
	return (vec);
}
