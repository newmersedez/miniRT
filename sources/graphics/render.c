/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:17:43 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/21 02:40:20 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_color	raytrace(t_minirt *minirt, t_vec3 *start, t_vec3 *end)
{
	t_vec3	oc;
	double	k1;
	double	k2;
	double	k3;
	double 	discriminant;
	double	t1;
	double	t2;
	double	closest_t = 0;
	t_sphere *closest_sphere = NULL;

	(void)t1;
	(void)t2;
	(void)closest_t;
	t_color	color = {0, 0, 0};
	t_list *head = minirt->scene->figures_list;


	while (head)
	{
		oc = vec_subtract(start, &((t_sphere *)(head->figure))->pos);
		k1 = vec_dot(end, end);
		k2 = 2 * vec_dot(&oc, end);
		k3 = vec_dot(&oc, &oc) - ((((t_sphere *)(head->figure))->diameter / 2) * (((t_sphere *)(head->figure))->diameter / 2));
		discriminant = k2 * k2 - 4 * k1 * k3;
		if (discriminant < 0)
		{
			printf("lalka\n");	
			head = head->next;
		}
		else
		{
			t1 = (-k2 + sqrtf(discriminant)) / (2 * k1);
			t2 = (-k2 - sqrtf(discriminant)) / (2 * k1);
		}
		if (t1 >= 1 && t1 < t2)
		{
			closest_t = t1;
			closest_sphere = (t_sphere *)head->figure;	
		}
		if (t2 >= 1 && t2 < t1)
		{
			closest_t = t2;
			closest_sphere = (t_sphere *)head->figure;	
		}
		head = head->next;
	}
	if (closest_sphere)
	{
		color = closest_sphere->color;
	}
	printf("return %d %d %d\n", color.r, color.g, color.b);
	return (color);
}

void	render(t_minirt *minirt)
{
	size_t	x;
	size_t	y;
	t_vec3	d_vec;
	t_color	color;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			d_vec = convert_to_viewport(minirt, (double)x, (double)y);
			color = raytrace(minirt, &minirt->scene->camera->pos, &d_vec);
			my_mlx_pixel_put(minirt->image, x, y,
				((color.r & 0xFF) << 16)
				+ ((color.g & 0xFF) << 8)
				+ (color.b & 0xFF));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(minirt->window->mlx, minirt->window->mlx_win,
		minirt->image->img, 0, 0);
}
