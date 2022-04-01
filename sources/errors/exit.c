/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:53:09 by lorphan           #+#    #+#             */
/*   Updated: 2022/04/01 15:02:58 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/errors.h"

void	display_message(char *msg, int fd)
{
	if (!msg)
		return ;
	ft_putstr_fd((char *)msg, fd);
}

void	success_exit(t_minirt *minirt, char *msg)
{
	if (!minirt)
	{
		display_message(msg, 1);
		exit(EXIT_FAILURE);
	}
	clear_minirt(minirt);
	display_message(msg, 1);
	exit(EXIT_SUCCESS);
}

void	fail_exit(t_minirt *minirt, char *msg)
{
	if (!minirt)
	{
		display_message(msg, 2);
		exit(EXIT_FAILURE);
	}
	clear_minirt(minirt);
	display_message(msg, 2);
	exit(EXIT_FAILURE);
}
