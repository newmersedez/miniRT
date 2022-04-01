/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:12:10 by lorphan           #+#    #+#             */
/*   Updated: 2022/04/01 14:55:34 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "minirt.h"
# include "../libft/libft.h"

typedef struct s_minirt	t_minirt;

/* Check some cases*/
void	handle_errors(t_minirt *minirt, int argc, char *argv[]);
int		check_file_extension(char *filename);
int		check_line_empty(char *line);
int		check_line_comment(char *line);
int		check_scene_correctness(t_minirt *minirt);

/* Exit functions */
void	success_exit(t_minirt *minirt, char *msg);
void	fail_exit(t_minirt *minirt, char *msg);

/* Utils */
void	display_message(char *msg, int fd);

#endif
