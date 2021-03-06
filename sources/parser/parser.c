/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:17:45 by lorphan           #+#    #+#             */
/*   Updated: 2022/04/01 15:04:11 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static int	parse_line(char *line, t_minirt *minirt)
{
	int	status;

	status = 0;
	skip_spaces(&line);
	if (*line == 'A')
		status = parse_ambient(line + 1, minirt);
	else if (*line == 'C')
		status = parse_camera(line + 1, minirt);
	else if (*line == 'L')
		status = parse_light(line + 1, minirt);
	else if (*line == 's' && *(line + 1) == 'p')
		status = parse_sphere(line + 2, minirt);
	else if (*line == 'p' && *(line + 1) == 'l')
		status = parse_plane(line + 2, minirt);
	else if (*line == 'c' && *(line + 1) == 'y')
		status = parse_cylinder(line + 2, minirt);
	else
		status = 1;
	return (status);
}

int	parse_info_from_file(char *filename, t_minirt *minirt)
{
	int		fd;
	int		status;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	status = 1;
	while (status > 0)
	{
		status = get_next_line(fd, &line);
		if (!check_line_empty(line) && !check_line_comment(line))
		{
			if (!parse_line(line, minirt))
			{
				free(line);
				return (0);
			}
		}
		if (line)
			free(line);
		line = NULL;
	}
	close(fd);
	return (1);
}
