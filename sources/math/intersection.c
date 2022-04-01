/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:01:09 by lorphan           #+#    #+#             */
/*   Updated: 2022/04/01 18:06:13 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_point	ray_intersection(t_object *object, t_point *start, t_vec *ray)
{
	t_point	intersection;

	if (object->type == SPHERE)
		intersection = ray_intersect_sphere(object->figure, start, ray);
	if (object->type == PLANE)
		intersection = ray_intersect_plane(object->figure, start, ray);
	if (object->type == CYLINDER)
		intersection = ray_intersect_cylinder(object->figure, start, ray);
	return (intersection);
}
