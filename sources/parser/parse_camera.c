/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:19:43 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/13 01:42:39 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static t_pos	get_pos(char **line, int *code)
{
	t_pos	pos;
	
	skip_spaces(line);
	pos.x = get_double_param(line, code);
	if (**line != ',')
		*code = 1;
	(*line)++;
	pos.y = get_double_param(line, code);
	if (**line != ',')	
		*code = 1;
	(*line)++;
	pos.z = get_double_param(line, code);
	if (!ft_isspace(**line))
		*code = 1;
	return (pos);
}

static t_pos	get_normal_vec(char **line, int *code)
{
	t_pos	normal_vec;
	
	skip_spaces(line);
	normal_vec.x = get_double_param(line, code);
	if (**line != ',' || !(normal_vec.x >= -1.0 && normal_vec.x <= 1.0))
		*code = 1;
	(*line)++;
	normal_vec.y = get_double_param(line, code);
	if (**line != ',' || !(normal_vec.y >= -1.0 && normal_vec.y <= 1.0))
		*code = 1;
	(*line)++;
	normal_vec.z = get_double_param(line, code);
	if (!ft_isspace(**line) || !(normal_vec.z >= -1.0 && normal_vec.z <= 1.0))
		*code = 1;
	return (normal_vec);
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
	t_pos	normal_vec;

	code = 0;
	pos = get_pos(&line, &code);
	if (code == 1)	
		return (0);
	normal_vec = get_normal_vec(&line, &code);
	if (code == 1)
		return (0);
	fov = get_fov(&line, &code);
	if (code == 1)
		return (0);
	minirt->camera = (t_camera *)malloc(sizeof(t_camera));
	if (!minirt->camera)
		return (0);
	minirt->camera->fov = fov;
	minirt->camera->pos = pos;
	minirt->camera->normal_vec = normal_vec;
	return (1);
}
