/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:24:48 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/21 19:12:30 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vec3	vec_add(t_vec3 *vec1, t_vec3 *vec2)
{
	t_vec3	res_vec;

	res_vec.x = vec1->x + vec2->x;
	res_vec.y = vec1->y + vec2->y;
	res_vec.z = vec1->z + vec2->z;
	return (res_vec);
}

t_vec3	vec_subtract(t_vec3 *vec1, t_vec3 *vec2)
{
	t_vec3	res_vec;

	res_vec.x = vec2->x - vec1->x;
	res_vec.y = vec2->y - vec1->y;
	res_vec.z = vec2->z - vec1->z;
	return (res_vec);
}

t_vec3	vec_normalize(t_vec3 *vec)
{
	double	temp;

	temp = sqrtf(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
	vec->x /= temp;
	vec->y /= temp;
	vec->z /= temp;
	return (*vec);
}

double	vec_dot(t_vec3 *vec1, t_vec3 *vec2)
{
	return (vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z);
}
