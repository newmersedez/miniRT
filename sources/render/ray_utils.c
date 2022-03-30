/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:39:11 by dmitry            #+#    #+#             */
/*   Updated: 2022/03/31 02:01:37 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	convert_camera_basis(const t_vec *dir, t_vec *b_x, t_vec *b_y)
{
	t_vec	temp;

	temp = vec_create(1, 0, 0);
	if (fabs(vec_dot(dir, &temp)) < 0.5)
		*b_x = vec_create(1, 0, 0);
	else
		*b_x = vec_create(0, 0, 1);
	temp = vec_cross(dir, b_x);
	*b_y = vec_normalize(&temp);
	temp = vec_cross(dir, b_y);
	*b_x = vec_normalize(&temp);
	if (b_y->y < 0.0)
		*b_y = vec_multiply_by_num(b_y, -1.);
	if (dir->z < 0.0 && b_x->x > 0.0)
		*b_x = vec_multiply_by_num(b_x, -1.);
	else if (dir->z > 0.0 && b_x->x < 0.0)
		*b_x = vec_multiply_by_num(b_x, -1.);
}

t_vec	convert_to_viewport(t_minirt *minirt, double x, double y)
{
	t_vec	vec;
	double	fov;
	double	aspect_ratio;

	aspect_ratio = (double)WINDOW_WIDTH / WINDOW_HEIGHT;
	fov = minirt->scene->camera->fov / (double)DEFAULT_FOV;
	vec.x = (x - (double)WINDOW_WIDTH / 2.0)
		* (fov / (double)WINDOW_WIDTH) * aspect_ratio;
	vec.y = -1.0 * (y - (double)WINDOW_HEIGHT / 2.0)
		* (fov / (double)WINDOW_HEIGHT);
	vec_normalize(&vec);
	return (vec);
}

t_point	create_ray(t_minirt *minirt, double x, double y)
{
	t_point	on_screen;
	t_vec	basis_nx;
	t_vec	basis_ny;
	t_point	ans;
	t_vec	temp;

	on_screen = convert_to_viewport(minirt, x, y);
	basis_nx = vec_multiply_by_num(&minirt->scene->camera->basis_x,
			on_screen.x);
	basis_ny = vec_multiply_by_num(&minirt->scene->camera->basis_y,
			on_screen.y);
	temp = vec_add(&basis_nx, &basis_ny);
	temp = vec_add(&temp, &minirt->scene->camera->dir);
	ans = vec_normalize(&temp);
	return (ans);
}

t_intersect	cast_ray(t_minirt *minirt, t_object *object,
				t_point *origin, t_vec *ray)
{
	t_intersect	intersection;
	t_point		point;
	t_list		*objects_list;

	set_default_point(&intersection.point);
	intersection.object = object;
	objects_list = minirt->scene->objects_list;
	while (objects_list)
	{
		point = objects_list->object->ray_intersection(
				objects_list->object->figure, origin, ray);
		if (is_closest_intersection_point(origin,
				&point, &intersection.point))
		{
			intersection.point = point;
			intersection.object = objects_list->object;
		}
		objects_list = objects_list->next;
	}
	return (intersection);
}
