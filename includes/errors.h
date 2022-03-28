/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:12:10 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/28 23:23:26 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "minirt.h"
# include "../libft/libft.h"

typedef struct s_minirt	t_minirt;

/* Check some cases*/
void	handle_errors(const t_minirt *minirt, int argc, char *argv[]);
int		check_file_extension(const char *filename);
int		check_line_empty(const char *line);
int		check_line_comment(const char *line);
int		check_scene_correctness(const t_minirt *minirt);

/* Exit functions */
void	success_exit(t_minirt *minirt, const char *msg);
void	fail_exit(t_minirt *minirt, const char *msg);

/* Utils */
void	display_message(const char *msg, int fd);

#endif
