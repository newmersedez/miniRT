/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minirt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:16:18 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/15 15:21:28 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	init_minirt(t_minirt *minirt)
{
	if (!minirt)
		return (0);
	minirt->scene = init_scene();
	if (!minirt->scene)
		return (0);
	minirt->window = init_window(WINDOW_WIDTH, WINDOW_HEIGHT, "minirt");
	if (!minirt->window)
		return (0);
	minirt->image = init_image(minirt);
	if (!minirt->image)
		return (0);
	return (1);
}

t_scene	*init_scene(void)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->ambient_light = NULL;
	scene->camera = NULL;
	scene->light = NULL;
	scene->figures_list = NULL;
	return (scene);
}

t_image	*init_image(t_minirt *minirt)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->img = mlx_new_image(minirt->window->mlx,
			WINDOW_HEIGHT, WINDOW_HEIGHT);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	if (!image->img || !image->addr)
	{
		free(image);
		return (NULL);
	}
	return (image);
}

t_window	*init_window(int width, int height, char *name)
{
	t_window	*window;

	window = (t_window *)malloc(sizeof(t_window));
	if (!window)
		return (NULL);
	window->mlx = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx, width, height, name);
	if (!window->mlx || !window->mlx_win)
	{
		free(window);
		return (NULL);
	}
	return (window);
}
