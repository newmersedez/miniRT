/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:12:55 by lorphan           #+#    #+#             */
/*   Updated: 2022/04/01 18:04:53 by lorphan          ###   ########.fr       */
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
	t_list		*objects_list;
}	t_scene;

typedef struct s_minirt
{
	t_window	window;
	t_image		image;
	t_scene		scene;

}	t_minirt;

/* Init and clear*/
int			create_minirt(t_minirt *minirt);
t_scene		create_scene(void);
t_window	create_window(int width, int height, char *name);
t_image		create_image(t_minirt *minirt);
t_object	*create_sphere_object(t_sphere *sphere);
t_object	*create_plane_object(t_plane *plane);
t_object	*create_cylinder_object(t_cylinder *cylinder);
int			clear_minirt(t_minirt *minirt);
int			clear_scene(t_scene *scene);

/* Render */
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);
void		convert_camera_basis(t_vec *dir, t_vec *b_x, t_vec *b_y);
t_vec		convert_to_viewport(t_minirt *minirt, double x, double y);
t_point		create_ray(t_minirt *minirt, double x, double y);
t_intersect	cast_ray(t_minirt *minirt, t_object *object,
				t_point *origin, t_vec *ray);
void		render(t_minirt *minirt);
t_color		raytrace(t_minirt *minirt, t_point *origin, t_vec *dir);
t_color		calculate_light(t_minirt *minirt, t_object *object,
				t_point *intersection_point);

/* Math */
t_vec		vec_create(double x, double y, double z);
double		vec_length(t_vec *vec);
t_vec		vec_normalize(t_vec *vec);
t_vec		vec_add(t_vec *vec1, t_vec *vec2);
t_vec		vec_subtract(t_vec *vec1, t_vec *vec2);
t_vec		vec_multiply_by_num(t_vec *vec, double n);
double		vec_dot(t_vec *vec1, t_vec *vec2);
t_vec		vec_cross(t_vec *vec1, t_vec *vec2);
t_vec		change_plane_normal(t_vec *normal_vec, t_vec *ray);
t_vec		get_normal_vec(t_object *object, t_point *intersection);
t_point		ray_intersection(t_object *object, t_point *start, t_vec *ray);
t_vec		get_sphere_normal_vec(void *data,
				t_point *intersection);
t_vec		get_plane_normal_vec(void *data,
				t_point *intersection);
t_vec		get_cylinder_normal_vec(void *data,
				t_point *intersection);
t_point		ray_intersect_sphere(void *data,
				t_point *start_point, t_vec *ray);
t_point		ray_intersect_plane(void *data,
				t_point *start_point, t_vec *ray);
t_point		ray_intersect_cylinder(void *data,
				t_point *start_point, t_vec *ray);
int			is_closest_intersection_point(t_point *origin_point,
				t_point *intersection_point, t_point *closest_point);

/* Utils */
int			close_hook(t_minirt *minirt);
int			keyboard_hook(int keycode, t_minirt *minirt);

void		set_default_color(t_color *color);
void		set_sky_color(t_minirt *minirt, t_color *color, t_vec *ray);
int			mix_colors(t_color *color);
void		add_coefficient(t_color *color, t_color *light_color, double coef);
t_color		build_color(t_color *color, t_color *light_color);
void		set_default_point(t_point *point);
int			is_intersection_point(t_point *point);

#endif
