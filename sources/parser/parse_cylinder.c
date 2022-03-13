/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:23:21 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/13 17:19:55 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static double	get_diameter(char **line, int *code)
{
	double	diameter;

	skip_spaces(line);
	diameter = get_double_param(line, code);
	if (!ft_isspace(**line) || diameter <= 0)
		*code = 1;
	return (diameter);
}

static double	get_height(char **line, int *code)
{
	double	height;

	skip_spaces(line);
	height = get_double_param(line, code);
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
	push_back(&(minirt->figures_list), (void *)cylinder, CYLINDER);
	return (1);
}
