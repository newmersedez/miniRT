/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:16:18 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/12 18:16:37 by lorphan          ###   ########.fr       */
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
	return (1);
}
