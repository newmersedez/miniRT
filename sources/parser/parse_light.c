/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:20:51 by lorphan           #+#    #+#             */
/*   Updated: 2022/04/01 16:36:10 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static double	get_brightness(char **line, int *code)
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

	code = 0;
	if (minirt->scene.light)
		return (0);
	minirt->scene.light = (t_light *)malloc(sizeof(t_light));
	if (!minirt->scene.light)
		return (0);
	minirt->scene.light->pos = get_pos(&line, &code);
	minirt->scene.light->brightness_ratio = get_brightness(&line, &code);
	minirt->scene.light->color = get_color(&line, &code);
	if (code == 1)
	{
		free(minirt->scene.light);
		minirt->scene.light = NULL;
		return (0);
	}
	return (1);
}
