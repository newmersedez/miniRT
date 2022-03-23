/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:25:37 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/23 12:18:38 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int argc, char *argv[])
{
	t_minirt	minirt;

	handle_errors(&minirt, argc, argv);
	// render(&minirt);
	mlx_hook(minirt.window->mlx_win, 17, 0, close_hook, &minirt);
	mlx_loop(minirt.window->mlx);
	clear_minirt(&minirt);
	return (0);
}
