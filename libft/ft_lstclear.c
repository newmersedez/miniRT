/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:37:09 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/21 15:37:10 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_ptr;

	if (!lst || !(*lst) || !del)
		return ;
	while (*lst)
	{
		temp_ptr = *lst;
		*lst = (*lst)->next;
		del(temp_ptr->content);
		free(temp_ptr);
	}
}
