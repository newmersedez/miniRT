/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:12:55 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/31 01:24:44 by dmitry           ###   ########.fr       */
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
int			clear_scene(t_scene *scene);

/* Render */
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);
void		convert_camera_basis(const t_vec *dir, t_vec *b_x, t_vec *b_y);
t_vec		convert_to_viewport(t_minirt *minirt, double x, double y);
t_point		create_ray(t_minirt *minirt, double x, double y);
t_intersect	cast_ray(t_minirt *minirt, t_point *origin, t_vec *ray);
void		render(t_minirt *minirt);
t_color		raytrace(t_minirt *minirt, t_point *origin, t_vec *dir);
t_color		calculate_light(t_minirt *minirt, t_object *object,
				t_point *intersection_point);

/* Math */
t_vec		vec_create(double x, double y, double z);
double		vec_length(const t_vec *vec);
t_vec		vec_normalize(const t_vec *vec);
t_vec		vec_add(const t_vec *vec1, const t_vec *vec2);
t_vec		vec_subtract(const t_vec *vec1, const t_vec *vec2);
t_vec		vec_multiply_by_num(const t_vec *vec, double n);
double		vec_dot(const t_vec *vec1, const t_vec *vec2);
t_vec		vec_cross(const t_vec *vec1, const t_vec *vec2);
t_vec		change_plane_normal(const t_vec *normal_vec, const t_vec *ray);
t_vec		get_sphere_normal_vec(const void *data,
				const t_point *intersection);
t_vec		get_plane_normal_vec(const void *data,
				const t_point *intersection);
t_vec		get_cylinder_normal_vec(const void *data,
				const t_point *intersection);
t_point		ray_intersect_sphere(const void *data,
				const t_point *start_point, const t_vec *ray);
t_point		ray_intersect_plane(const void *data,
				const t_point *start_point, const t_vec *ray);
t_point		ray_intersect_cylinder(const void *data,
				const t_point *start_point, const t_vec *ray);
int			is_closest_intersection_point(const t_point *origin_point,
				const t_point *intersection_point,
				const t_point *closest_point);

/* Utils */
int			close_hook(t_minirt *minirt);
void		set_default_color(t_color *color);
void		set_default_point(t_point *point);
int			is_intersection_point(const t_point *point);

#endif
