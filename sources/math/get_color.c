/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 01:21:13 by dmitry            #+#    #+#             */
/*   Updated: 2022/03/23 01:31:56 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_color	get_sphere_color(const void *data, const t_point *intersection)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)data;
	return (sphere->color);
}

t_color	get_plane_color(const void *data, const t_point *intersection)
{
	t_plane	*plane;

	plane = (t_plane *)data;
	return (plane->color);
}

t_color	get_cylinder_color(const void *data, const t_point *intersection)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)data;
	return (cylinder->color);
}
