/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:25:37 by lorphan           #+#    #+#             */
/*   Updated: 2022/04/01 14:27:39 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int argc, char *argv[])
{
	t_minirt	minirt;

	handle_errors(&minirt, argc, argv);
	render(&minirt);
	mlx_hook(minirt.window->mlx_win, 17, 0, close_hook, &minirt);
	mlx_hook(minirt.window->mlx_win, 2, 5, keyboard_hook, &minirt);
	mlx_loop(minirt.window->mlx);
	clear_minirt(&minirt);
	return (0);
}
