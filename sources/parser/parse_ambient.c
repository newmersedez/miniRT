/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:17:40 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/29 16:42:43 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static double	get_lighting(char **line, int *code)
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

	code = 0;
	if (minirt->scene->ambient_light)
		return (0);
	minirt->scene->ambient_light = (t_ambient *)malloc(sizeof(t_ambient));
	if (!minirt->scene->ambient_light)
		return (0);
	minirt->scene->ambient_light->lighting_ratio = get_lighting(&line, &code);
	minirt->scene->ambient_light->color = get_color(&line, &code);
	if (code == 1)
	{
		free(minirt->scene->ambient_light);
		minirt->scene->ambient_light = NULL;
		return (0);
	}
	return (1);
}
