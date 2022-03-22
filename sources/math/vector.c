/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:24:48 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/22 19:44:23 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	vec_length(t_vec3 *vec)
{
	if (!vec)
		return (0);
	return (sqrtf(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z));
}

t_vec3	vec_normalize(t_vec3 *vec)
{
	float	temp;

	temp = vec_length(vec);
	vec->x /= temp;
	vec->y /= temp;
	vec->z /= temp;
	return (*vec);
}

