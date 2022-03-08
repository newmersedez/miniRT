/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:36:40 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/24 17:54:39 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long int	tmp_result;
	long long int	result;
	int				negative;

	result = 0;
	negative = 1;
	while (ft_is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		tmp_result = result;
		result = result * 10 + (*str - '0');
		if ((tmp_result != (result - (*str - '0')) / 10) && negative == 1)
			return (-1);
		else if ((tmp_result != (result - (*str - '0')) / 10) && negative == -1)
			return (0);
		str++;
	}	
	return ((int)(negative * result));
}
