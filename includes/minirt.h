/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:12:55 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/23 01:48:31 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// # include <mlx.h>
# include "../mlx_linux/mlx.h"
# include <math.h>

# include "list.h"
# include "objects.h"
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

/* Init and clear*/
int			create_minirt(t_minirt *minirt);
t_scene		*create_scene(void);
t_window	*create_window(int width, int height, char *name);
t_image		*create_image(t_minirt *minirt);
t_object	*create_sphere_object(t_sphere *sphere);
t_object	*create_plane_object(t_plane *plane);
t_object	*create_cylinder_object(t_cylinder *cylinder);
int			clear_minirt(t_minirt *minirt);
int			clear_figures(t_minirt *minirt);

/* Render */
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);
void		render(t_minirt *minirt);
t_color		raytrace(t_minirt *minirt, t_vec *origin, t_vec *dir);

/* Math */
float		vec_length(t_vec *vec);
t_vec		vec_normalize(t_vec *vec);
t_vec		vec_add(t_vec *vec1, t_vec *vec2);
t_vec		vec_subtract(t_vec *vec1, t_vec *vec2);
t_vec		vec_multiply_by_num(t_vec *vec, float n);
float		vec_dot(t_vec *vec1, t_vec *vec2);
t_color		get_sphere_color(const void *data,
				const t_point *intersection);
t_color		get_plane_color(const void *data,
				const t_point *intersection);
t_color		get_cylinder_color(const void *data,
				const t_point *intersection);
t_vec		get_sphere_normal_vec(const void *data,
				const t_point *intersection);
t_vec		get_plane_normal_vec(const void *data,
				const t_point *intersection);
t_vec		get_cylinder_normal_vec(const void *data,
				const t_point *intersection);
float		ray_intersect_sphere(const void *data,
				const t_point *start_point,
				const t_vec *ray, t_point *intersection);
float		ray_intersect_plane(const void *data,
				const t_point *start_point,
				const t_vec *ray, t_point *intersection);
float		ray_intersect_cylinder(const void *data,
				const t_point *start_point,
				const t_vec *ray, t_point *intersection);

/* Utils */
int			close_hook(t_minirt *minirt);

#endif
