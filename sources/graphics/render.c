/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:17:43 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/27 05:07:13 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void fill_cam_basis(const t_vec *dir, t_vec *b_x, t_vec *b_y)
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

static t_vec	convert_to_viewport(t_minirt *minirt, double x, double y)
{
	t_vec	end_vec;
	double	fov;
	double	aspect_ratio;

	aspect_ratio = (double)WINDOW_WIDTH  / WINDOW_HEIGHT;
	fov = minirt->scene->camera->fov / (double)DEFAULT_FOV;
	end_vec.x = (x - WINDOW_WIDTH / 2) * (fov / WINDOW_WIDTH) * aspect_ratio;
	end_vec.y = -1 * (y - WINDOW_HEIGHT / 2) * (fov / WINDOW_HEIGHT);
	vec_normalize(&end_vec);
	return (end_vec);
}

static t_point	cast_ray(t_minirt *minirt, double x, double y)
{
    t_point	on_screen;
    t_vec	basis_nx;
    t_vec	basis_ny;
    t_point	ans;
	t_vec	temp;

    on_screen = convert_to_viewport(minirt, x, y);
    basis_nx = vec_multiply_by_num(&minirt->scene->camera->basis_x, on_screen.x);
    basis_ny = vec_multiply_by_num(&minirt->scene->camera->basis_y, on_screen.y);
	temp = vec_add(&basis_nx, &basis_ny);
	temp = vec_add(&temp, &minirt->scene->camera->dir);
    ans = vec_normalize(&temp);
    return (ans);
}

void	render(t_minirt *minirt)
{
	size_t	x;
	size_t	y;
	t_vec	dir;
	t_color	color;

	fill_cam_basis(&minirt->scene->camera->dir, &minirt->scene->camera->basis_x, &minirt->scene->camera->basis_y);
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			dir = cast_ray(minirt, (double)x, (double)y);
			color = raytrace(minirt, &minirt->scene->camera->pos, &dir);
			my_mlx_pixel_put(minirt->image, x, y,
				((color.r & 0xFF) << 16)
				+ ((color.g & 0xFF) << 8)
				+ (color.b & 0xFF));
			++y;
		}
		++x;
	}
	mlx_put_image_to_window(minirt->window->mlx, minirt->window->mlx_win,
		minirt->image->img, 0, 0);
}
