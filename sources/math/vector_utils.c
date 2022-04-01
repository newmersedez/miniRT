/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:24:48 by lorphan           #+#    #+#             */
/*   Updated: 2022/04/01 14:51:45 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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
	return (sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z));
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
