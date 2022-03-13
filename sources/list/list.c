/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:40:56 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/13 16:33:07 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"
#include "../../includes/figure.h"

void	print_figure(void *data, int type)
{
	if (type == SPHERE)
	{
		t_sphere *a = data;
		printf("sp %.2f,%.2f,%.2f %.2f %d,%d,%d\n",
			a->pos.x, a->pos.y, a->pos.z, a->diameter,
			a->color.r, a->color.g, a->color.b);
	}
	else if (type == PLANE)
	{
		t_plane *a = data;
		printf("pl %.2f,%.2f,%.2f %.2f,%.2f,%.2f %d,%d,%d\n",
			a->pos.x, a->pos.y, a->pos.z,
			a->normal.x, a->normal.y, a->normal.z,
			a->color.r, a->color.g, a->color.b);
	}
	else if (type == CYLINDER)
	{
		t_cylinder *a = data;
		printf("cl %.2f,%.2f,%.2f %.2f,%.2f,%.2f %.2f, %.2f, %d,%d,%d\n",
			a->pos.x, a->pos.y, a->pos.z,
			a->normal.x, a->normal.y, a->normal.z,
			a->diameter, a->height,
			a->color.r, a->color.g, a->color.b);
	}
}

t_list	*create_new_elem(void *data, int type)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->type = type;
	new_elem->figure = data;
	new_elem->next = NULL;
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
