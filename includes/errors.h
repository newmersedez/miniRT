/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:12:10 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/12 20:12:11 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/* Check some cases*/
int		check_start_errors(int argc, char *argv[]);
int		check_file_extension(const char *filename);
int		check_line_empty(const char *line);

#endif
