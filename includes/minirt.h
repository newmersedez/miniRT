/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:12:55 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/22 16:07:50 by dmitry           ###   ########.fr       */
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

/* Initizlization and clear*/
int			init_minirt(t_minirt *minirt);
t_scene		*init_scene(void);
t_window	*init_window(int width, int height, char *name);
t_image		*init_image(t_minirt *minirt);
int			clear_minirt(t_minirt *minirt);
int			clear_figures(t_minirt *minirt);

/* Render */
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);
void		render(t_minirt *minirt);

/* Math */
double		vec_length(t_vec3 *vec);
t_vec3		vec_normalize(t_vec3 *vec);
t_vec3		vec_add(t_vec3 *vec1, t_vec3 *vec2);
t_vec3		vec_subtract(t_vec3 *vec1, t_vec3 *vec2);
double		vec_dot(t_vec3 *vec1, t_vec3 *vec2);
void		rotate_ox(t_vec3 *vec);
void		rotate_oy(t_vec3 *vec);
void		rotate_oz(t_vec3 *vec);

/* Utils */
int			close_hook(t_minirt *minirt);

#endif
