/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:19:43 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/13 02:43:15 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static t_pos	get_normal(char **line, int *code)
{
	t_pos	normal;
	
	skip_spaces(line);
	normal.x = get_double_param(line, code);
	if (**line != ',' || !(normal.x >= -1.0 && normal.x <= 1.0))
		*code = 1;
	(*line)++;
	normal.y = get_double_param(line, code);
	if (**line != ',' || !(normal.y >= -1.0 && normal.y <= 1.0))
		*code = 1;
	(*line)++;
	normal.z = get_double_param(line, code);
	if (!ft_isspace(**line) || !(normal.z >= -1.0 && normal.z <= 1.0))
		*code = 1;
	return (normal);
}

static double	get_fov(char **line, int *code)
{
	double	fov;

	skip_spaces(line);
	fov = get_double_param(line, code);
	skip_spaces(line);
	if (**line != '\0' || !(fov >= 0 && fov <= 180))
		*code = 1;
	return (fov);
}

int	parse_camera(char *line, t_minirt *minirt)
{
	int		code;
	int		fov;
	t_pos	pos;
	t_pos	normal;

	code = 0;
	pos = get_pos(&line, &code);
	if (code == 1)	
		return (0);
	normal = get_normal(&line, &code);
	if (code == 1)
		return (0);
	fov = get_fov(&line, &code);
	if (code == 1)
		return (0);
	if (minirt->camera)
		return (0);
	minirt->camera = (t_camera *)malloc(sizeof(t_camera));
	if (!minirt->camera)
		return (0);
	minirt->camera->fov = fov;
	minirt->camera->pos = pos;
	minirt->camera->normal = normal;
	return (1);
}
