/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:21:35 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/13 03:03:27 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static double	get_diameter(char **line, int *code)
{
	double	diameter;

	skip_spaces(line);
	diameter = get_double_param(line, code);
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
	push_back(&(minirt->figures_list), (void *)sphere, SPHERE);
	printf("___\n");
	print_figure(minirt->figures_list->figure, SPHERE);
	printf("___\n");
	
	printf("%f %f %f\n",
					(sphere)->pos.x,
					(sphere)->pos.y,
					(sphere)->pos.z);
					
	if (minirt->figures_list)
	{
		t_list	*temp = minirt->figures_list;
		while (temp)
		{
			if (temp->type == SPHERE)
				printf("%f %f %f\n",
					((t_sphere *)temp->figure)->pos.x,
					((t_sphere *)temp)->pos.y,
					((t_sphere *)temp)->pos.z);
			else if (temp->type == PLANE)
				printf("%f %f %f\n",
					((t_plane *)temp)->pos.x,
					((t_plane *)temp)->pos.y,
					((t_plane *)temp)->pos.z);
			else if (temp->type == CYLINDER)
				printf("%f %f %f\n",
					((t_cylinder *)temp)->pos.x,
					((t_cylinder *)temp)->pos.y,
					((t_cylinder *)temp)->pos.z);
			temp = temp->next;
		}
	}
	return (1);
}
