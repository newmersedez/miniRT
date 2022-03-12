/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:49:48 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/12 23:06:27 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

void	skip_spaces(char **line)
{
	while (**line && ft_isspace(**line))
		(*line)++;
}
