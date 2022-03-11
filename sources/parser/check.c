/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:53:50 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/11 20:17:41 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	check_file_extension(const char *filename)
{
	char	*ext;

	ext = ft_strchr(filename, '.');
	if (!ext)
		return (0);
	else
	{
		++ext;
		if (ft_strlen(ext) != 2)
			return (0);
		else if (ext[0] != 'r' || ext[1] != 't')
			return (0);
	}
	return (1);
}