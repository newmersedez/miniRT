/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minirt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:16:18 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/13 19:53:32 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	init_minirt(t_minirt *minirt)
{
	if (!minirt)
		return (0);
	minirt->ambient_light = NULL;
	minirt->camera = NULL;
	minirt->light = NULL;
	minirt->figures_list = NULL;
	minirt->window = init_window(WINDOW_WIDTH, WINDOW_HEIGHT, "minirt");
	if (!minirt->window)
		return (0);
	minirt->image = init_image(minirt);
	if (!minirt->image)
		return (0);
	return (1);
}
