/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:50:13 by lorphan           #+#    #+#             */
/*   Updated: 2022/04/01 15:02:13 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# include "minirt.h"
# include "../libft/libft.h"
# include "../sources/get_next_line/get_next_line.h"

typedef struct s_minirt	t_minirt;
typedef struct s_color	t_color;

/* Parsing */
int			parse_info_from_file(char *filename, t_minirt *minirt);
int			parse_camera(char *line, t_minirt *minirt);
int			parse_light(char *line, t_minirt *minirt);
int			parse_ambient(char *line, t_minirt *minirt);
int			parse_sphere(char *line, t_minirt *minirt);
int			parse_plane(char *line, t_minirt *minirt);
int			parse_cylinder(char *line, t_minirt *minirt);

/* Utils */
size_t		numberlen(int n);
int			ft_isspace(char c);
void		skip_spaces(char **line);
int			get_int_param(char**line, int *code);
double		get_double_param(char **line, int *code);
t_point		get_pos(char **line, int *code);
t_color		get_color(char **line, int *code);
t_vec		get_normal(char **line, int *code);

#endif