/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:37:56 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/21 15:40:22 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(char const *s, char c)
{
	size_t	i;
	size_t	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

static char	*get_word(const char **s, char c)
{
	size_t	i;
	size_t	len;
	char	*word;

	i = 0;
	while ((*s)[i] && (*s)[i] != c)
		i++;
	word = (char *)malloc(i + 1);
	if (!word)
		return (NULL);
	len = i;
	i = 0;
	while (i < len && **s)
	{
		word[i] = **s;
		(*s)++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	clear_mem(char **array_of_words, size_t len)
{
	size_t	i;

	if (array_of_words)
	{
		i = 0;
		while (i < len)
		{
			free(array_of_words[i]);
			i++;
		}
		free(array_of_words);
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**array_of_words;

	if (!s)
		return (NULL);
	array_of_words = (char **)ft_calloc((get_size(s, c) + 1), sizeof(char *));
	if (!array_of_words)
		return (NULL);
	count = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			array_of_words[count] = get_word(&s, c);
			if (!array_of_words[count])
			{
				clear_mem(array_of_words, count);
				return (NULL);
			}
			count++;
		}
		s++;
	}
	array_of_words[count] = NULL;
	return (array_of_words);
}
