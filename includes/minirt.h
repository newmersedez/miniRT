#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>

# include "list.h"
# include "figure.h"
# include "parser.h"
# include "errors.h"

typedef struct s_minirt
{
	t_ambient	*ambient_light;
	t_camera	*camera;
	t_light		*light;
	t_list		*figures_list;

}	t_minirt;

/* Initizlization */
int	init_minirt(t_minirt *minirt);

#endif

// typedef struct figure
// {
// 	void	*figure;
// 	double	(*intersect_with)(t_vector *ray, t_vector *begin_point, void* figure) 
// 	double	(*get_)(t_vector *, t_vector *begin_point, void* figure) 
// }	figure;


// double	intersect_with_plane(t_vector ray, t_vector begin_point, void* figure)
// {

// }

// double	intersect_with_sphere(t_vector ray, t_vector begin_point, void* figure)
// {

// }

// figure fig = new figure;	//пусть это плоскость
// figure = fig->intersect_with = intersect_with_plane;

