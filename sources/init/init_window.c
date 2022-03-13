/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:13:53 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/13 18:29:16 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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
