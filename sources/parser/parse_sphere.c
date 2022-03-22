/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:21:35 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/22 20:31:41 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static float	get_diameter(char **line, int *code)
{
	float	diameter;

	skip_spaces(line);
	diameter = get_float_param(line, code);
	if (!ft_isspace(**line) || diameter <= 0)
		*code = 1;
	return (diameter);
}

int	parse_sphere(char *line, t_minirt *minirt)
{
	int			code;
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		return (0);
	code = 0;
	sphere->pos = get_pos(&line, &code);
	if (code == 1)
		return (0);
	sphere->diameter = get_diameter(&line, &code);
	if (code == 1)
		return (0);
	sphere->color = get_color(&line, &code);
	if (code == 1)
		return (0);
	push_back(&(minirt->scene->figures_list), (void *)sphere, SPHERE);
	return (1);
}
