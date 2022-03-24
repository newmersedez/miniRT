#ifndef UTILS_H
# define UTILS_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_ambient
{
	t_color	color;
	double	lighting_ratio;
}	t_ambient;

typedef struct s_camera
{
	double	fov;
	t_vec3	pos;
	t_vec3	normal;
}	t_camera;

typedef struct s_light
{
	t_vec3	pos;
	t_color	color;
	double	brightness_ratio;
}	t_light;

#endif
