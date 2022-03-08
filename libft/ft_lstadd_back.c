/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:37:05 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/21 15:37:06 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp_ptr;

	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		temp_ptr = *lst;
		while (temp_ptr->next)
			temp_ptr = temp_ptr->next;
		temp_ptr->next = new;
	}
}
