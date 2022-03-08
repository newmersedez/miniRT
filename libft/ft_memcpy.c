/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:38:35 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/21 15:38:36 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src_temp;
	unsigned char	*dest_temp;

	if (!dest && !src)
		return (NULL);
	i = 0;
	src_temp = (unsigned char *)src;
	dest_temp = (unsigned char *)dest;
	while (i < n)
	{
		dest_temp[i] = src_temp[i];
		i++;
	}
	return (dest);
}
