/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_minirt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:11:17 by lorphan           #+#    #+#             */
/*   Updated: 2022/04/01 16:33:45 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	clear_minirt(t_minirt *minirt)
{
	if (!minirt)
		return (0);
	if ((minirt->window.mlx || minirt->window.mlx_win)
		&& (minirt->image.img || minirt->image.addr))
		mlx_destroy_image(minirt->window.mlx, minirt->image.img);
	if (minirt->window.mlx || minirt->window.mlx_win)
		mlx_destroy_window(minirt->window.mlx, minirt->window.mlx_win);
	clear_scene(&minirt->scene);
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
