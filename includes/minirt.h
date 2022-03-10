#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_pos
{
	double	x;
	double	y;
	double	z;
}	t_pos;

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct	s_ambient
{
	double	ratio;
	t_color	color;
}	t_ambient;

typedef struct	s_camera
{
	t_pos	pos;
	t_pos	normal_vec_pos;
	double	fov;
}	t_camera;

#endif