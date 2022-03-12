/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:25:37 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/12 23:49:28 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

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
	{
		printf("Error\n");
		return (1);
	}
	printf("krasava\n");
	return (0);
}
