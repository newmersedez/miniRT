/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_constructors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:28:55 by dmitry            #+#    #+#             */
/*   Updated: 2022/04/01 17:59:55 by lorphan          ###   ########.fr       */
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
	object->color = sphere->color;
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
	object->color = plane->color;
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
	object->color = cylinder->color;
	return (object);
}
