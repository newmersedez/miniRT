/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_minirt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:16:18 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/24 13:52:23 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	create_minirt(t_minirt *minirt)
{
	if (!minirt)
		return (0);
	minirt->scene = create_scene();
	if (!minirt->scene)
		return (0);
	minirt->window = create_window(WINDOW_WIDTH, WINDOW_HEIGHT, "minirt");
	if (!minirt->window)
		return (0);
	minirt->image = create_image(minirt);
	if (!minirt->image)
		return (0);
	return (1);
}

t_scene	*create_scene(void)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->ambient_light = NULL;
	scene->camera = NULL;
	scene->light = NULL;
	scene->objects_list = NULL;
	return (scene);
}

t_image	*create_image(t_minirt *minirt)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->img = mlx_new_image(minirt->window->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	if (!image->img || !image->addr)
	{
		if (image->img)
			free(image->img);
		if (image->addr)
			free(image->addr);
		free(image);
		return (NULL);
	}
	return (image);
}

t_window	*create_window(int width, int height, char *name)
{
	t_window	*window;

	window = (t_window *)malloc(sizeof(t_window));
	if (!window)
		return (NULL);
	window->mlx = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx, width, height, name);
	if (!window->mlx || !window->mlx_win)
	{
		if (window->mlx)
			free(window->mlx);
		if (window->mlx_win)
			free(window->mlx_win);
		free(window);
		return (NULL);
	}
	return (window);
}
