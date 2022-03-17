/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:12:10 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/17 21:28:18 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "minirt.h"
# include "../libft/libft.h"

typedef struct s_minirt	t_minirt;

/* Check some cases*/
void	handle_errors(t_minirt *minirt, int argc, char *argv[]);
int		check_file_extension(const char *filename);
int		check_line_empty(const char *line);
int		check_line_comment(const char *line);

/* Exit functions */
void	success_exit(t_minirt *minirt, const char *msg);
void	fail_exit(t_minirt *minirt, const char *msg);

/* Utils */
void	display_message(const char *msg, int fd);

#endif
