/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:53:50 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/30 02:12:23 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	handle_errors(const t_minirt *minirt, int argc, char *argv[])
{
	char		*filename;

	if (argc != 2)
		exit(EXIT_FAILURE);
	filename = argv[1];
	if (!check_file_extension(filename))
		fail_exit(NULL, FILE_EXT_ERROR);
	if (!create_minirt(minirt))
		fail_exit(minirt, INIT_ERROR);
	if (!parse_info_from_file(filename, minirt))
		fail_exit(minirt, PARSE_FILE_ERROR);
	if (!check_scene_correctness(minirt))
		success_exit(minirt, SCENE_WARNING);
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

int	check_line_comment(const char *line)
{
	if (!line)
		return (0);
	while (*line && ft_isspace(*line))
		line++;
	if (*line && *line == '#')
		return (1);
	return (0);
}

int	check_scene_correctness(const t_minirt *minirt)
{
	if (!minirt->scene->camera)
		return (0);
	if (!minirt->scene->light && !minirt->scene->ambient_light)
		return (0);
	return (1);
}
