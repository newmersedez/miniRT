/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:38:39 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/21 15:38:40 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
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
		if (src_temp[i] == (unsigned char)c)
			return ((unsigned char *)dest + i + 1);
		i++;
	}
	return (NULL);
}
