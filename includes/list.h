/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:35:44 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/11 21:06:07 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
	void			*figure;
	struct s_list	*next;
}	t_list;
	
t_list	*create_new_elem(void	*data, int type);
void	push_back(t_list *list, void *data, int type);
void	clear_list(t_list **list);

#endif
