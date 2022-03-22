/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:35:44 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/23 02:47:31 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdio.h>
# include <stdlib.h>

# include "objects.h"

typedef struct s_list
{
	t_object		*object;
	struct s_list	*next;
}	t_list;

/* List functions */
t_list	*create_new_elem(t_object *object);
void	push_back(t_list **list, t_object *object);
void	clear_list(t_list **list);
size_t	size(t_list *list);
void	display_object(t_object *object);

#endif
