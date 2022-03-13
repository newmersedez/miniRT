/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:25:37 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/13 20:27:45 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	close_hook(t_minirt *minirt)
{
	(void)minirt;
	clear_minirt(minirt);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_minirt	minirt;
	char		*filename;

	if (!check_start_errors(argc, argv))
		return (1);
	if (!init_minirt(&minirt))
		return (1);
	filename = argv[1];
	if (!parse_info_from_file(filename, &minirt))
		return (1);
	mlx_hook(minirt.window->mlx_win, 17, 0, close_hook, &minirt);
	mlx_loop(minirt.window->mlx);
	return (0);
}
