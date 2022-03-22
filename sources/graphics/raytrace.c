/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:38:35 by dmitry            #+#    #+#             */
/*   Updated: 2022/03/23 01:32:05 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_color	raytrace(t_minirt *minirt, t_vec *origin, t_vec *dir)
{
	
	t_list	*objects;
	t_color	color;

	objects = minirt->scene->figures_list;
	while (objects)
	{
		objects = objects->next;
	}
	return (color);

	return (color);
}
