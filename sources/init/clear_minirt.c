/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_minirt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:11:17 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/13 20:29:35 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	clear_minirt(t_minirt *minirt)
{
	if (!minirt)
		return (0);
	mlx_destroy_image(minirt->window->mlx, minirt->image->img);
	mlx_destroy_window(minirt->window->mlx, minirt->window->mlx_win);
	clear_figures(minirt);
	return (1);
}

int	clear_figures(t_minirt *minirt)
{
	if (!minirt)
		return (0);
	if (minirt->ambient_light)
		free(minirt->ambient_light);
	if (minirt->camera)
		free(minirt->camera);
	if (minirt->light)
		free(minirt->light);
	if (minirt->figures_list)
		clear_list(&minirt->figures_list);
	return (1);
}
