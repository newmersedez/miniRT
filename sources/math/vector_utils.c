/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:24:48 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/24 21:57:05 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

#define GET_VARIABLE_NAME(Variable) (#Variable)

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

void	display_vector(const t_vec *vec)
{
	printf("%s = (%f, %f, %f)\n", GET_VARIABLE_NAME(vec), vec->x, vec->y, vec->z);
}

