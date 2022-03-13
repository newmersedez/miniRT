/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:40:56 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/13 03:01:34 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"
#include "../../includes/figure.h"
#include <stdio.h>
void	print_figure(void *data, int type)
{
	if (type == SPHERE)
	{
		t_sphere *a = data;
		printf("sp %.2f,%.2f,%.2f %.2f %d,%d,%d\n", a->pos.x, a->pos.y, a->pos.z, a->diameter, a->color.r, a->color.g, a->color.b);
	}
}

static int	deepcopy(void *figure, void *data, int type)
{
	print_figure(data, type);
	if (type == SPHERE)
	{
		((t_sphere *)(figure))->pos = ((t_sphere *)data)->pos;
		((t_sphere *)(figure))->color = ((t_sphere *)data)->color;
		((t_sphere *)(figure))->diameter = ((t_sphere *)data)->diameter;
	}
	else if (type == PLANE)
	{
		((t_plane *)(figure))->pos = ((t_plane *)data)->pos;
		((t_plane *)(figure))->color = ((t_plane *)data)->color;
		((t_plane *)(figure))->normal = ((t_plane *)data)->normal;
	}
	else if (type == CYLINDER)
	{
		((t_cylinder *)(figure))->pos = ((t_cylinder *)data)->pos;
		((t_cylinder *)(figure))->normal= ((t_cylinder *)data)->normal;
		((t_cylinder *)(figure))->height = ((t_cylinder *)data)->height;
		((t_cylinder *)(figure))->diameter = ((t_cylinder *)data)->diameter;
		((t_cylinder *)(figure))->color = ((t_cylinder *)data)->color;
	}
	print_figure(figure, type);
	return (1);
}

t_list	*create_new_elem(void *data, int type)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	if (type == SPHERE)
		new_elem->figure = (t_sphere *)malloc(sizeof(t_sphere));
	else if (type == PLANE)
		new_elem->figure = (t_plane *)malloc(sizeof(t_plane));
	else if (type == CYLINDER)
		new_elem->figure = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!new_elem->figure)
	{
		free(new_elem);
		return (NULL);
	}
	if (!deepcopy(new_elem->figure, data, type))
	{
		free(new_elem);
		return (NULL);
	}
	new_elem->type = type;
	new_elem->next = NULL;
	print_figure(new_elem->figure, type);
	return (new_elem);
}

void	push_back(t_list **list, void *data, int type)
{
	t_list	*new_elem;
	t_list	*temp_elem;

	if (!list)
		return ;
	new_elem = create_new_elem(data, type);
	if (!new_elem)
		return ;
	if (!*list)
	{
		*list = new_elem;
		return ;
	}
	else
	{
		temp_elem = *list;
		while (temp_elem->next)
			temp_elem = temp_elem->next;
		temp_elem->next = new_elem;
	}
	print_figure(temp_elem->next->figure, type);
}

void	clear_list(t_list **list)
{
	t_list	*temp_ptr;

	while (*list)
	{
		temp_ptr = *list;
		*list = (*list)->next;
		free(temp_ptr->figure);
		free(temp_ptr);
	}
}
