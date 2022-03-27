/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:24:48 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/27 04:03:08 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

#define GET_VARIABLE_NAME(Variable) (#Variable)

t_vec	vec_create(double x, double y, double z)
{
	t_vec	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

double	vec_length(t_vec *vec)
{
	if (!vec)
		return (0);
	return (sqrtf(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z));
}

t_vec	vec_normalize(t_vec *vec)
{
	double	temp;
	t_vec	normal_vec;

	temp = vec_length(vec);
	normal_vec.x = vec->x / temp;
	normal_vec.y = vec->y / temp;
	normal_vec.z = vec->z / temp;
	return (normal_vec);
}

t_vec	vec_cross(t_vec *vec1, t_vec *vec2)
{
	double	x;
	double	y;
	double	z;

	x = vec1->y * vec2->z - vec1->z * vec2->y;
	y = vec1->z * vec2->x - vec1->x * vec2->z;
	z = vec1->x * vec2->y - vec1->y * vec2->x;
	return (vec_create(x, y, z));
}
