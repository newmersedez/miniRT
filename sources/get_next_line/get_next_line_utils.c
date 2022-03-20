/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:21:39 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/12 17:25:11 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	else if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start + 1;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	j = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (src_len + size);
	while (dst[i])
		i++;
	while (src[j] && j < size - dst_len - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (src_len + dst_len);
}

char	*ft_strjoin_all_clear(char *s1, char *s2)
{
	char	*ans;
	int		len1;
	int		len2;

	if (!s1 || !s2)
	{
		if (s1)
			free(s1);
		if (s2)
			free(s2);
		return (NULL);
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ans = malloc((len1 + len2 + 1) * sizeof(char));
	if (!ans)
		return (NULL);
	ans[0] = 0;
	ft_strlcat(ans, s1, len1 + 1);
	ft_strlcat(ans, s2, len1 + len2 + 1);
	free(s1);
	free(s2);
	return (ans);
}
