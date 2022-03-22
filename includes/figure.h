/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:49:04 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/22 18:09:08 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURE_H
# define FIGURE_H

# define SPHERE		0
# define PLANE		1
# define CYLINDER	2

typedef struct s_pos
{
	float	x;
	float	y;
	float	z;
}	t_pos;

typedef struct s_pos	t_vec3;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_ambient
{
	t_color	color;
	float	lighting_ratio;
}	t_ambient;

typedef struct s_camera
{
	float	fov;
	t_pos	pos;
	t_pos	normal;
}	t_camera;

typedef struct s_light
{
	t_pos	pos;
	t_color	color;
	float	brightness_ratio;
}	t_light;

typedef struct s_sphere
{
	t_pos	pos;
	t_color	color;
	float	diameter;
}	t_sphere;

typedef struct s_plane
{
	t_pos	pos;
	t_color	color;
	t_pos	normal;
}	t_plane;

typedef struct s_cylinder
{
	t_pos	pos;
	t_color	color;
	t_pos	normal;
	float	diameter;
	float	height;
}	t_cylinder;

void	print_figure(void *data, int type);

#endif
