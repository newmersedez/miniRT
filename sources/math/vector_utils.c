/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:24:48 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/23 01:32:05 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	vec_length(t_vec *vec)
{
	if (!vec)
		return (0);
	return (sqrtf(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z));
}

t_vec	vec_normalize(t_vec *vec)
{
	float	temp;

	temp = vec_length(vec);
	vec->x /= temp;
	vec->y /= temp;
	vec->z /= temp;
	return (*vec);
}

