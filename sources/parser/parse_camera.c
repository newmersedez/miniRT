/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:19:43 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/13 17:19:47 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

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
