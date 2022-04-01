/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:49:04 by lorphan           #+#    #+#             */
/*   Updated: 2022/04/01 17:57:26 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# define SPHERE		0
# define PLANE		1
# define CYLINDER	2

/* Utils */

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_point	t_vec;

/* Service objects */

typedef struct s_ambient
{
	t_color	color;
	double	lighting_ratio;
}	t_ambient;

typedef struct s_camera
{
	t_point	pos;
	t_vec	dir;
	double	fov;
	t_vec	basis_x;
	t_vec	basis_y;
}	t_camera;

typedef struct s_light
{
	t_point	pos;
	t_color	color;
	double	brightness_ratio;
}	t_light;

/* Geometric objects */

typedef struct s_object
{
	void	*figure;
	int		type;
	t_color	color;
}	t_object;

typedef struct s_intersect
{
	t_point		point;
	t_object	*object;
}	t_intersect;

typedef struct s_sphere
{
	t_point	pos;
	t_color	color;
	double	diameter;
}	t_sphere;

typedef struct s_plane
{
	t_point	pos;
	t_color	color;
	t_vec	dir;
}	t_plane;

typedef struct s_cylinder
{
	t_point	pos;
	t_color	color;
	t_vec	dir;
	double	diameter;
	double	height;
}	t_cylinder;

#endif
