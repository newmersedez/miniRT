/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:49:48 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/12 19:56:59 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static size_t	numberlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	get_int_param(char**line, int *code)
{
	int	value;
	int	negative;

	negative = 1;
	if (**line == '-')
	{
		negative = -1;
		(*line)++;
	}
	if (!ft_isdigit(**line))
		*code = 1;
	while (**line && ft_isdigit(**line))
		value = value * 10 + (*((*line)++) - '0');
	return (negative * value);
}

double	get_double_param(char **line, int *code)
{
	int		negative;
	double	value;
	int		fract;

	value = 0;
	fract = 0;
	negative = 1;
	if (**line == '-')
	{
		negative = -1;
		(*line)++;
	}
	if (!ft_isdigit(**line))
		*code = 1;
	while (**line && ft_isdigit(**line))
		value = value * 10 + (*((*line)++) - '0');
	if (*((*line)++) != '.')
		*code = 1;
	if (!ft_isdigit(**line))
		*code = 1;
	while (**line && ft_isdigit(**line))
		fract = fract* 10 + (*((*line)++) - '0');
	return (negative * (value + ((double)fract / pow(10, numberlen(fract)))));
}

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
