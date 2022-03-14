/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:53:50 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/14 22:08:45 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	handle_errors(t_minirt *minirt, int argc, char *argv[])
{
	char		*filename;

	if (argc != 2)
		fail_exit(minirt, ARGS_COUNT_ERROR);
	filename = argv[1];
	if (!check_file_extension(filename))
		fail_exit(minirt, FILE_EXT_ERROR);
	if (!init_minirt(minirt))
		fail_exit(minirt, INIT_ERROR);
	if (!parse_info_from_file(filename, minirt))
		fail_exit(minirt, PARSE_FILE_ERROR);
}

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

int	check_line_empty(const char *line)
{
	if (!line)
		return (1);
	while (*line)
	{
		if (!ft_isspace(*line))
			return (0);
		line++;
	}
	return (1);
}
