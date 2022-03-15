/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:12:55 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/15 16:39:49 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include <math.h>

# include "list.h"
# include "figure.h"
# include "parser.h"
# include "errors.h"
# include "defines.h"

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
}	t_window;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_scene
{
	t_ambient	*ambient_light;
	t_camera	*camera;
	t_light		*light;
	t_list		*figures_list;
}	t_scene;

typedef struct s_minirt
{
	t_window	*window;
	t_image		*image;
	t_scene		*scene;

}	t_minirt;

/* Initizlization */
int			init_minirt(t_minirt *minirt);
t_scene		*init_scene(void);
t_window	*init_window(int width, int height, char *name);
t_image		*init_image(t_minirt *minirt);

/* Render */
void		render(t_minirt *minirt);

/* Math */
t_vec		vec_add(t_vec vec1, t_vec vec2);
t_vec		vec_subtract(t_vec vec1, t_vec vec2);
t_vec		vec_scalar_multiply(t_vec vec1, t_vec vec2);


/* Drawing utils */
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);

/* Clear */
int			clear_minirt(t_minirt *minirt);
int			clear_figures(t_minirt *minirt);

/* Events */
int			close_hook(t_minirt *minirt);

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

