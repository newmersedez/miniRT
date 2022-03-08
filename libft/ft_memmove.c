/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:38:34 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/21 15:38:35 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src_temp;
	unsigned char	*dest_temp;

	i = 0;
	src_temp = (unsigned char *)src;
	dest_temp = (unsigned char *)dest;
	if (dest_temp > src_temp)
	{
		while (n-- != 0)
			dest_temp[n] = src_temp[n];
	}
	if (src_temp > dest_temp)
	{
		while (i < n)
		{
			dest_temp[i] = src_temp[i];
			i++;
		}
	}
	return (dest);
}
