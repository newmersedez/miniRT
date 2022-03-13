/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:22:09 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/13 15:35:23 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	parse_plane(char *line, t_minirt *minirt)
{
	int		code;
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		return (0);
	code = 0;
	plane->pos = get_pos(&line, &code);
	if (code == 1)
		return (0);
	plane->normal = get_pos(&line, &code);
	if (code == 1)
		return (0);
	plane->color = get_color(&line, &code);
	if (code == 1)
		return (0);
	push_back(&(minirt->figures_list), (void *)plane, PLANE);
	return (1);
}
