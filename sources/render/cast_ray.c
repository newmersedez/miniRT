/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:39:11 by dmitry            #+#    #+#             */
/*   Updated: 2022/03/29 00:49:03 by dmitry           ###   ########.fr       */
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
	if (b_y->y < 0)
		*b_y = vec_multiply_by_num(b_y, -1.);
	if (dir->z < 0 && b_x->x > 0)
		*b_x = vec_multiply_by_num(b_x, -1.);
	else if (dir->z > 0 && b_x->x < 0)
		*b_x = vec_multiply_by_num(b_x, -1.);
}

t_vec	convert_to_viewport(t_minirt *minirt, double x, double y)
{
	t_vec	end_vec;
	double	fov;
	double	aspect_ratio;

	aspect_ratio = (double)WINDOW_WIDTH / WINDOW_HEIGHT;
	fov = minirt->scene->camera->fov / (double)DEFAULT_FOV;
	end_vec.x = (x - WINDOW_WIDTH / 2) * (fov / WINDOW_WIDTH) * aspect_ratio;
	end_vec.y = -1 * (y - WINDOW_HEIGHT / 2) * (fov / WINDOW_HEIGHT);
	vec_normalize(&end_vec);
	return (end_vec);
}

t_point	cast_ray(t_minirt *minirt, double x, double y)
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
