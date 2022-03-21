/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:12:55 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/21 17:50:42 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// # include <mlx.h>
# include "../mlx_linux/mlx.h"
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
t_color		raytrace(t_minirt *minirt, t_vec3 *camera_vec, t_vec3 *d_vec);

/* Math */
t_vec3		vec_add(t_vec3 *vec1, t_vec3 *vec2);
t_vec3		vec_subtract(t_vec3 *vec1, t_vec3 *vec2);
double		vec_dot(t_vec3 *vec1, t_vec3 *vec2);

/* Drawing utils */
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);

/* Clear */
int			clear_minirt(t_minirt *minirt);
int			clear_figures(t_minirt *minirt);

/* Events */
int			close_hook(t_minirt *minirt);

/* Converters */
t_vec3		convert_to_viewport(t_minirt *minirt, double x, double y);

#endif


// double	intersect_with_plane(t_vector ray, t_vector begin_point, void* figure)
// {

// }

// double	intersect_with_sphere(t_vector ray, t_vector begin_point, void* figure)
// {

// }

