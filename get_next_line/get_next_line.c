/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:21:58 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/12 17:23:33 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	write_to_line(char **line, char buffer[BUFFER_SIZE + 1])
{
	int		i;
	int		end;
	int		flag;

	i = 0;
	end = 0;
	while (buffer[end] && buffer[end] != '\n')
		end++;
	flag = buffer[end];
	if (end > 0)
		*line = ft_strjoin_all_clear(*line, ft_substr(buffer, 0, end));
	if (!(*line))
		return (-1);
	while (i + 1 < BUFFER_SIZE - end)
	{
		buffer[i] = buffer[end + i + 1];
		i++;
	}
	while (i < BUFFER_SIZE)
		buffer[i++] = 0;
	if (flag == '\n')
		return (1);
	else
		return (0);
}

int	assignment(char **line, void *data)
{
	if (!data || !line)
		return (0);
	*line = data;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];
	int			i;
	int			count;
	int			returned;

	i = 0;
	count = -1;
	if (read(fd, 0, 0) == -1 || !line || !assignment(line, malloc(1)) || \
			BUFFER_SIZE < 1)
		return (-1);
	(*line)[0] = 0;
	while (1)
	{
		if (!buffer[fd][0])
		{
			count = read(fd, buffer[fd], BUFFER_SIZE);
			buffer[fd][count] = 0;
		}
		returned = write_to_line(line, buffer[fd]);
		if (count == 0)
			return (0);
		if (returned == 1 || returned == -1)
			return (returned);
	}
}
