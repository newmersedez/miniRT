/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:20:51 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/22 18:09:08 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static float	get_brightness_ratio(char **line, int *code)
{
	float	brightness;

	skip_spaces(line);
	brightness = get_float_param(line, code);
	if (!ft_isspace(**line) || !(brightness >= 0.0 && brightness <= 1.0))
		*code = 1;
	return (brightness);
}

int	parse_light(char *line, t_minirt *minirt)
{
	int		code;
	t_pos	pos;
	t_color	color;
	float	brightness_ratio;

	code = 0;
	pos = get_pos(&line, &code);
	if (code == -1)
		return (0);
	brightness_ratio = get_brightness_ratio(&line, &code);
	if (code == 1)
		return (0);
	color = get_color(&line, &code);
	if (code == 1)
		return (0);
	if (minirt->scene->light)
		return (0);
	minirt->scene->light = (t_light *)malloc(sizeof(t_light));
	if (!minirt->scene->light)
		return (0);
	minirt->scene->light->pos = pos;
	minirt->scene->light->color = color;
	minirt->scene->light->brightness_ratio = brightness_ratio;
	return (1);
}
