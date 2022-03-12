/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:20:51 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/13 01:47:30 by dmitry           ###   ########.fr       */
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

static double	get_brightness_ratio(char **line, int *code)
{
	double	brightness;

	skip_spaces(line);
	brightness = get_double_param(line, code);
	if (!ft_isspace(**line) || !(brightness >= 0.0 && brightness <= 1.0))
		*code = 1;
	return (brightness);
}

static t_color	get_color(char **line, int *code)
{
	t_color	color;

	skip_spaces(line);
	color.r = get_int_param(line, code);
	if (**line != ',' || !(color.r >= 0 && color.r <= 255))
		*code = 1;
	(*line)++;
	color.g = get_int_param(line, code);
	if (**line != ',' || !(color.g >= 0 && color.g <= 255))
		*code = 1;
	(*line)++;
	color.b = get_int_param(line, code);
	skip_spaces(line);
	if (**line != '\0' || !(color.b >= 0 && color.b <= 255))
		*code = 1;
	return (color);
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
	minirt->light = (t_light *)malloc(sizeof(t_light));
	if (!minirt->light)
		return (0);
	minirt->light->pos = pos;
	minirt->light->color = color;
	minirt->light->brightness_ratio = brightness_ratio;
	return (1);
}
