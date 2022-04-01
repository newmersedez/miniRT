/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_minirt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:16:18 by lorphan           #+#    #+#             */
/*   Updated: 2022/04/01 16:29:24 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	create_minirt(t_minirt *minirt)
{
	minirt->window = create_window(WINDOW_WIDTH, WINDOW_HEIGHT, "minirt");
	minirt->image = create_image(minirt);
	minirt->scene = create_scene();
	return (1);
}

t_window	create_window(int width, int height, char *name)
{
	t_window	window;

	window.mlx = mlx_init();
	window.mlx_win = mlx_new_window(window.mlx, width, height, name);
	return (window);
}

t_image	create_image(t_minirt *minirt)
{
	t_image	image;

	image.img = mlx_new_image(minirt->window.mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	return (image);
}

t_scene	create_scene(void)
{
	t_scene	scene;

	scene.ambient_light = NULL;
	scene.camera = NULL;
	scene.light = NULL;
	scene.objects_list = NULL;
	return (scene);
}
