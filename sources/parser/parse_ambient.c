/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:17:40 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/12 23:43:54 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static double	get_lighting_ratio(char **line, int *code)
{
	double	value;

	*code = 0;
	skip_spaces(line);
	value = get_double_param(line, code);
	if (!ft_isspace(**line))
		*code = 1;
	return (value);
}

static t_color	get_color(char **line, int *code)
{
	t_color	color;

	*code = 0;
	skip_spaces(line);
	color.r = get_int_param(line, code);
	if (**line != ',' || color.r < 0)
		*code = 1;
	(*line)++;
	color.g = get_int_param(line, code);
	if (**line != ',' || color.g < 0)
		*code = 1;
	(*line)++;
	color.b = get_int_param(line, code);
	skip_spaces(line);
	if (**line != '\0' || color.b < 0)	
		*code = 1;
	return (color);
}

int	parse_ambient(char *line, t_minirt *minirt)
{
	int		exit_code;
	double	lighting_ratio;
	t_color	color;

	exit_code = 0;
	lighting_ratio = get_lighting_ratio(&line, &exit_code);
	if (exit_code == 1)
		return (0);
	color = get_color(&line, &exit_code);
	if (exit_code == 1)
		return (0);
	minirt->ambient_light = (t_ambient *)malloc(sizeof(t_ambient));
	if (!minirt->ambient_light)
		return (0);
	minirt->ambient_light->lighting_ratio = lighting_ratio;
	minirt->ambient_light->color = color;
	return (1);
}
