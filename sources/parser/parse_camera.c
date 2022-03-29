/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:19:43 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/29 16:42:30 by dmitry           ###   ########.fr       */
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

	code = 0;
	if (minirt->scene->camera)
		return (0);
	minirt->scene->camera = (t_camera *)malloc(sizeof(t_camera));
	if (!minirt->scene->camera)
		return (0);
	minirt->scene->camera->pos = get_pos(&line, &code);
	minirt->scene->camera->dir = get_normal(&line, &code);
	minirt->scene->camera->fov = get_fov(&line, &code);
	if (code == 1)
	{
		free(minirt->scene->camera);
		minirt->scene->camera = NULL;
		return (0);
	}
	convert_camera_basis(&minirt->scene->camera->dir,
		&minirt->scene->camera->basis_x, &minirt->scene->camera->basis_y);
	return (1);
}
