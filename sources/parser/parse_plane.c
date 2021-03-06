/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:22:09 by lorphan           #+#    #+#             */
/*   Updated: 2022/04/01 16:36:07 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static t_plane	*get_plane_info(char *line)
{
	int		code;
	t_plane	*plane;

	code = 0;
	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->pos = get_pos(&line, &code);
	plane->dir = get_normal(&line, &code);
	plane->dir = vec_normalize(&plane->dir);
	plane->color = get_color(&line, &code);
	if (code == 1)
	{
		free(plane);
		return (NULL);
	}
	return (plane);
}

int	parse_plane(char *line, t_minirt *minirt)
{
	t_plane		*plane;
	t_object	*object;

	plane = get_plane_info(line);
	if (!plane)
		return (0);
	object = create_plane_object(plane);
	if (!object)
	{
		free(plane);
		return (0);
	}
	push_back(&(minirt->scene.objects_list), object);
	return (1);
}
