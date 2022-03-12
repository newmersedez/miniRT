/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:20:51 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/13 01:58:03 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static double	get_brightness_ratio(char **line, int *code)
{
	double	brightness;

	skip_spaces(line);
	brightness = get_double_param(line, code);
	if (!ft_isspace(**line) || !(brightness >= 0.0 && brightness <= 1.0))
		*code = 1;
	return (brightness);
}

int	parse_light(char *line, t_minirt *minirt)
{
	int		code;
	t_pos	pos;
	t_color	color;
	double	brightness_ratio;

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
	if (minirt->light)
		return (0);
	minirt->light = (t_light *)malloc(sizeof(t_light));
	if (!minirt->light)
		return (0);
	minirt->light->pos = pos;
	minirt->light->color = color;
	minirt->light->brightness_ratio = brightness_ratio;
	return (1);
}
