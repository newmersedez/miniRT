/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:40:56 by lorphan           #+#    #+#             */
/*   Updated: 2022/04/01 15:04:34 by lorphan          ###   ########.fr       */
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
