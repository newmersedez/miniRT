/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:49:04 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/12 20:12:36 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURE_H
# define FIGURE_H

# define SPHERE		0
# define PLANE		1
# define CYLINDER	2

typedef struct s_pos
{
	double	x;
	double	y;
	double	z;
}	t_pos;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_ambient
{
	double	lighting_ratio;
	t_color	color;
}	t_ambient;

typedef struct s_camera
{
	t_pos	pos;
	t_pos	normal_vec;
	double	fov;
}	t_camera;

typedef struct s_light
{
	t_pos	pos;
	double	brightness_ratio;
	t_color	color;
}	t_light;

typedef struct s_sphere
{
	t_pos	pos;
	double	diameter;
	t_color	color;
}	t_sphere;

typedef struct s_plane
{
	t_pos	pos;
	t_pos	normal_vec;
	t_color	color;
}	t_plane;

typedef struct s_cylinder
{
	t_pos	pos;
	t_pos	normal_vec;
	double	diameter;
	double	height;
	t_color	color;
}	t_cylinder;

#endif
