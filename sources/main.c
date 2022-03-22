/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:25:37 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/23 02:57:02 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	display_ambient_light(t_ambient *ambient)
{
	printf("ambient = %.1f %d %d %d\n", ambient->lighting_ratio,
		ambient->color.r, ambient->color.g, ambient->color.b);
}

static void	display_light(t_light *light)
{
	printf("light = %.1f %.1f %.1f %.1f %d %d %d\n",
		light->pos.x, light->pos.y, light->pos.z,
		light->brightness_ratio,
		light->color.r, light->color.g, light->color.b);
}

static void	display_camera(t_camera *camera)
{
	printf("camera = %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", camera->pos.x, camera->pos.y, camera->pos.z,
		camera->normal.x, camera->normal.y, camera->normal.z, camera->fov);
}


int	main(int argc, char *argv[])
{
	t_minirt	minirt;

	handle_errors(&minirt, argc, argv);
	// render(&minirt);
	
	if (minirt.scene->ambient_light)
		display_ambient_light(minirt.scene->ambient_light);
	if (minirt.scene->light)
		display_light(minirt.scene->light);
	if (minirt.scene->camera)
		display_camera(minirt.scene->camera);
	t_list	*list = minirt.scene->figures_list;
	printf("size = %zu\n", size(list));
	while (list)
	{
		display_object(list->object);
		list = list->next;
	}
	mlx_hook(minirt.window->mlx_win, 17, 0, close_hook, &minirt);
	mlx_loop(minirt.window->mlx);
	return (0);
}
