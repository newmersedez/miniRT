/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:23:21 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/22 18:09:08 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static float	get_diameter(char **line, int *code)
{
	float	diameter;

	skip_spaces(line);
	diameter = get_float_param(line, code);
	if (!ft_isspace(**line) || diameter <= 0)
		*code = 1;
	return (diameter);
}

static float	get_height(char **line, int *code)
{
	float	height;

	skip_spaces(line);
	height = get_float_param(line, code);
	if (!ft_isspace(**line) || height <= 0)
		*code = 1;
	return (height);
}

int	parse_cylinder(char *line, t_minirt *minirt)
{
	int			code;
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)
		return (0);
	code = 0;
	cylinder->pos = get_pos(&line, &code);
	if (code == 1)
		return (0);
	cylinder->normal = get_normal(&line, &code);
	if (code == 1)
		return (0);
	cylinder->diameter = get_diameter(&line, &code);
	if (code == 1)
		return (0);
	cylinder->height = get_height(&line, &code);
	if (code == 1)
		return (0);
	cylinder->color = get_color(&line, &code);
	if (code == 1)
		return (0);
	push_back(&(minirt->scene->figures_list), (void *)cylinder, CYLINDER);
	return (1);
}
