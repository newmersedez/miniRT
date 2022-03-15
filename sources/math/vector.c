/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:24:48 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/15 15:32:43 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vec	vec_add(t_vec vec1, t_vec vec2)
{
	t_vec	res_vec;

	res_vec.x = vec1.x + vec2.x;
	res_vec.y = vec1.y + vec2.y;
	res_vec.z = vec1.z + vec2.z;
	return (res_vec);
}

t_vec	vec_subtract(t_vec vec1, t_vec vec2)
{
	t_vec	res_vec;

	res_vec.x = vec1.x - vec2.x;
	res_vec.y = vec1.y - vec2.y;
	res_vec.z = vec1.z - vec2.z;
	return (res_vec);
}

t_vec	vec_scalar_multiply(t_vec vec1, t_vec vec2)
{
	t_vec	res_vec;

	res_vec.x = vec1.x * vec2.x;
	res_vec.y = vec1.y * vec2.y;
	res_vec.z = vec1.z * vec2.z;
	return (res_vec);
}
