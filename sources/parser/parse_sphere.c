/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:21:35 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/23 02:18:22 by dmitry           ###   ########.fr       */
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

static t_sphere	*get_sphere_info(char *line)
{
	int			code;
	t_sphere	*sphere;

	code = 0;
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->pos = get_pos(&line, &code);
	if (code == 1)
		return (NULL);
	sphere->diameter = get_diameter(&line, &code);
	if (code == 1)
		return (NULL);
	sphere->color = get_color(&line, &code);
	if (code == 1)
		return (NULL);
	return (sphere);
}

int	parse_sphere(char *line, t_minirt *minirt)
{
	t_object	*object;
	t_sphere	*sphere;

	sphere = get_sphere_info(line);
	if (!sphere)
		return (0);
	object = create_sphere_object(sphere);
	if (!object)
	{
		free(sphere);
		return (0);
	}
	push_back(&(minirt->scene->figures_list), object);
	return (1);
}
