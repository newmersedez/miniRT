/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:38:33 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/21 15:38:34 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	symbol;

	i = 0;
	ptr = (unsigned char *)b;
	symbol = (unsigned char)c;
	while (i < len)
	{
		*(ptr + i) = symbol;
		i++;
	}
	return (b);
}
