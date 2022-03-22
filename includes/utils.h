#ifndef UTILS_H
# define UTILS_H

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
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
	float	lighting_ratio;
}	t_ambient;

typedef struct s_camera
{
	float	fov;
	t_vec3	pos;
	t_vec3	normal;
}	t_camera;

typedef struct s_light
{
	t_vec3	pos;
	t_color	color;
	float	brightness_ratio;
}	t_light;

#endif
