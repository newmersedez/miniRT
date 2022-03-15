/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:17:40 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/15 14:15:30 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static double	get_lighting_ratio(char **line, int *code)
{
	double	lighting;

	skip_spaces(line);
	lighting = get_double_param(line, code);
	if (!ft_isspace(**line) || !(lighting >= 0.0 && lighting <= 1.0))
		*code = 1;
	return (lighting);
}

int	parse_ambient(char *line, t_minirt *minirt)
{
	int		code;
	double	lighting_ratio;
	t_color	color;

	code = 0;
	lighting_ratio = get_lighting_ratio(&line, &code);
	if (code == 1)
		return (0);
	color = get_color(&line, &code);
	if (code == 1)
		return (0);
	if (minirt->scene->ambient_light)
		return (0);
	minirt->scene->ambient_light = (t_ambient *)malloc(sizeof(t_ambient));
	if (!minirt->scene->ambient_light)
		return (0);
	minirt->scene->ambient_light->lighting_ratio = lighting_ratio;
	minirt->scene->ambient_light->color = color;
	return (1);
}
