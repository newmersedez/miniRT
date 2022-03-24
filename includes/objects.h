/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:49:04 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/24 15:40:48 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# define SPHERE		0
# define PLANE		1
# define CYLINDER	2

/* Utils */

typedef struct s_point3d
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_point3d	t_vec;

/* Service objects */

typedef struct s_ambient
{
	t_color	color;
	double	lighting_ratio;
}	t_ambient;

typedef struct s_camera
{
	t_point	pos;
	t_vec	normal;
	double	fov;
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
	t_vec	(*get_normal_vector)(const void *data, const t_point *intersection);
	t_point	(*ray_intersection)(const void *data, const t_point *start_point,
				const t_vec *ray);

}	t_object;

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
	t_vec	normal;
}	t_plane;

typedef struct s_cylinder
{
	t_point	pos;
	t_color	color;
	t_vec	normal;
	double	diameter;
	double	height;
}	t_cylinder;

#endif
