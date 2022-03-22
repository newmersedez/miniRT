/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:12:55 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/23 00:00:17 by dmitry           ###   ########.fr       */
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
int			init_minirt(t_minirt *minirt);
t_scene		*init_scene(void);
t_window	*init_window(int width, int height, char *name);
t_image		*init_image(t_minirt *minirt);
int			clear_minirt(t_minirt *minirt);
int			clear_figures(t_minirt *minirt);

/* Render */
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);
void		render(t_minirt *minirt);
t_color		raytrace(t_minirt *minirt, t_vec3d *origin, t_vec3d *dir);

/* Math */
float		vec_length(t_vec3d *vec);
t_vec3d		vec_normalize(t_vec3d *vec);
t_vec3d		vec_add(t_vec3d *vec1, t_vec3d *vec2);
t_vec3d		vec_subtract(t_vec3d *vec1, t_vec3d *vec2);
t_vec3d		vec_multiply_by_num(t_vec3d *vec, float n);
float		vec_dot(t_vec3d *vec1, t_vec3d *vec2);
void		rotate_ox(t_vec3d *vec);
void		rotate_oy(t_vec3d *vec);
void		rotate_oz(t_vec3d *vec);

/* Utils */
t_vec3d		convert_to_viewport(t_minirt *minirt, float x, float y);
int			close_hook(t_minirt *minirt);

#endif
