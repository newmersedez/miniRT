/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:40:56 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/23 02:55:31 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"
#include "../../includes/objects.h"

t_list	*create_new_elem(t_object *object)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->object = object;
	new_elem->next = NULL;
	return (new_elem);
}

void	push_back(t_list **list, t_object *object)
{
	t_list	*new_elem;
	t_list	*temp_elem;

	if (!list)
		return ;
	new_elem = create_new_elem(object);
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
		free(temp_ptr->object->figure);
		free(temp_ptr->object);
		free(temp_ptr);
	}
}

size_t	size(t_list *list)
{
	size_t	size;

	size = 0;
	if (!list)
		return (0);
	while (list)
	{
		list = list->next;
		++size;	
	}
	return (size);
}

void	display_object(t_object *object)
{
	if (object->type == SPHERE)
	{
		t_sphere *sphere = (t_sphere *)object->figure;
		printf("sphere = %.1f %.1f %.1f %.1f %d %d %d\n", sphere->pos.x, sphere->pos.y, sphere->pos.z,
			sphere->diameter, sphere->color.r, sphere->color.g, sphere->color.b);
		
	}
	else if (object->type == PLANE)
	{
		t_plane *plane = (t_plane *)object->figure;
		printf("plane = %.1f %.1f %.1f %.1f %.1f %.1f %d %d %d\n",
			plane->pos.x, plane->pos.y, plane->pos.z,
			plane->normal.x, plane->normal.y, plane->normal.z,
			plane->color.r, plane->color.g, plane->color.b);
	}
	else if (object->type == CYLINDER)
	{
		t_cylinder *cylinder = (t_cylinder *)object->figure;
		printf("cylinder = %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %d %d %d",
			cylinder->pos.x, cylinder->pos.y, cylinder->pos.z,
			cylinder->normal.x, cylinder->normal.y, cylinder->normal.z, 
			cylinder->diameter, cylinder->height,
			cylinder->color.r, cylinder->color.g, cylinder->color.b);
	}
}
