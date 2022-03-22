/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:19:43 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/22 18:09:08 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static float	get_fov(char **line, int *code)
{
	float	fov;

	skip_spaces(line);
	fov = get_float_param(line, code);
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
	if (minirt->scene->camera)
		return (0);
	minirt->scene->camera = (t_camera *)malloc(sizeof(t_camera));
	if (!minirt->scene->camera)
		return (0);
	minirt->scene->camera->fov = fov;
	minirt->scene->camera->pos = pos;
	minirt->scene->camera->normal = vec_normalize(&normal);
	return (1);
}
