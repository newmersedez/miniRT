/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_constructors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:28:55 by dmitry            #+#    #+#             */
/*   Updated: 2022/03/23 01:46:03 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_object	*create_sphere_object(t_sphere *sphere)
{
	t_object	*object;

	object = (t_object *)malloc(sizeof(t_object));
	if (!object)
		return (NULL);
	object->figure = (void *)sphere;
	object->type = SPHERE;
	object->get_color = get_sphere_color;
	object->get_normal_vector = get_sphere_normal_vec;
	object->ray_intersection = ray_intersect_sphere;
	return (object);
}

t_object	*create_plane_object(t_plane *plane)
{
	t_object	*object;

	object = (t_object *)malloc(sizeof(t_object));
	if (!object)
		return (NULL);
	object->figure = (void *)plane;
	object->type = PLANE;
	object->get_color = get_plane_color;
	object->get_normal_vector = get_plane_normal_vec;
	object->ray_intersection = ray_intersect_plane;
	return (object);
}

t_object	*create_cylinder_object(t_cylinder *cylinder)
{
	t_object	*object;

	object = (t_object *)malloc(sizeof(t_object));
	if (!object)
		return (NULL);
	object->figure = (void *)cylinder;
	object->type = CYLINDER;
	object->get_color = get_cylinder_color;
	object->get_normal_vector = get_cylinder_normal_vec;
	object->ray_intersection = ray_intersect_cylinder;
	return (object);
}

