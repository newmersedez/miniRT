/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:40:56 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/11 21:55:17 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"
#include "../../includes/figure.h"

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
	new_elem->figure = data;
	new_elem->next = NULL;
	return (new_elem);
}

void	push_back(t_list *list, void *data, int type)
{
	t_list	*new_elem;

	new_elem = create_new_elem(data, type);
	if (!new_elem)
		return ;
	while (list->next)
		list = list->next;
	list->next = new_elem;
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
