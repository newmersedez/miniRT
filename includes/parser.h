/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:50:13 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/11 22:04:11 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

/* Errors */
int	check_start_errors(int argc, char *argv[]);
int	check_file_extension(const char *filename);

/* Parsing */
int	parse_info_from_file(const char *filename);

#endif
