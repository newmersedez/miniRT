/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:23:21 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/27 17:04:47 by dmitry           ###   ########.fr       */
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

static t_cylinder	*get_cylinder_info(char *line)
{
	int			code;
	t_cylinder	*cylinder;

	code = 0;
	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)
		return (NULL);
	cylinder->pos = get_pos(&line, &code);
	if (code == 1)
		return (NULL);
	cylinder->dir = get_normal(&line, &code);
	if (code == 1)
		return (NULL);
	cylinder->diameter = get_diameter(&line, &code);
	if (code == 1)
		return (NULL);
	cylinder->height = get_height(&line, &code);
	if (code == 1)
		return (NULL);
	cylinder->color = get_color(&line, &code);
	if (code == 1)
		return (NULL);
	return (cylinder);
}

int	parse_cylinder(char *line, t_minirt *minirt)
{
	t_cylinder	*cylinder;
	t_object	*object;

	cylinder = get_cylinder_info(line);
	if (!cylinder)
		return (0);
	object = create_cylinder_object(cylinder);
	if (!object)
	{
		free(cylinder);
		return (0);
	}
	push_back(&(minirt->scene->objects_list), object);
	return (1);
}
