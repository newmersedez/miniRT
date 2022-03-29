/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_minirt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:11:17 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/29 17:46:22 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	clear_minirt(t_minirt *minirt)
{
	if (!minirt)
		return (0);
	if (minirt->scene)
	{
		clear_scene(minirt->scene);
		free(minirt->scene);
	}
	if (minirt->image)
	{
		mlx_destroy_image(minirt->window->mlx, minirt->image->img);
		free(minirt->image);
	}
	if (minirt->window)
	{
		mlx_destroy_window(minirt->window->mlx, minirt->window->mlx_win);
		free(minirt->window);
	}
	return (1);
}

int	clear_scene(t_scene *scene)
{
	if (!scene)
		return (0);
	if (scene->ambient_light)
		free(scene->ambient_light);
	if (scene->camera)
		free(scene->camera);
	if (scene->light)
		free(scene->light);
	if (scene->objects_list)
		clear_list(&scene->objects_list);
	return (1);
}
