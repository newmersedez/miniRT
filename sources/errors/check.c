/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:53:50 by lorphan           #+#    #+#             */
/*   Updated: 2022/04/01 16:33:22 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	handle_errors(t_minirt *minirt, int argc, char *argv[])
{
	char		*filename;

	if (argc != 2)
		fail_exit(NULL, ARGS_COUNT_ERROR);
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

int	check_file_extension(char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (!ext)
		return (0);
	else
	{
		++ext;
		if (ft_strlen(ext) != 2)
			return (0);
		if (ext[0] != 'r' && ext[1] != 't')
			return (0);
	}
	return (1);
}

int	check_line_empty(char *line)
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

int	check_line_comment(char *line)
{
	if (!line)
		return (0);
	while (*line && ft_isspace(*line))
		line++;
	if (*line && *line == '#')
		return (1);
	return (0);
}

int	check_scene_correctness(t_minirt *minirt)
{
	if (!minirt->scene.camera)
		return (0);
	if (!minirt->scene.light)
		return (0);
	return (1);
}
