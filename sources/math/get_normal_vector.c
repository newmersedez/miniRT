/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 01:30:19 by dmitry            #+#    #+#             */
/*   Updated: 2022/03/23 01:36:24 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vec	get_sphere_normal_vec(const void *data, const t_point *intersection)
{
	(void)data;
	(void)intersection;
	t_vec	vec;

	vec.x = 0;
	vec.y = 0;
	vec.z = 0;
	return (vec);
}

t_vec	get_plane_normal_vec(const void *data, const t_point *intersection)
{
	(void)data;
	(void)intersection;
	t_vec	vec;

	vec.x = 0;
	vec.y = 0;
	vec.z = 0;
	return (vec);
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
