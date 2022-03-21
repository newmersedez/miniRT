#include "../../includes/minirt.h"

t_vec3	convert_to_viewport(t_minirt *minirt, double x, double y)
{
	t_vec3	end_vec;
	double	converted_fov;
	double	aspect_ratio;
	double	angle_x;
	double	angle_y;
	double	angle_z;

	aspect_ratio = (double)WINDOW_WIDTH  / (double)WINDOW_HEIGHT;
	converted_fov = minirt->scene->camera->fov / (double)DEFAULT_FOV;
	end_vec.x = aspect_ratio
		* (x - WINDOW_WIDTH / 2) * (converted_fov / (double)WINDOW_WIDTH);
	end_vec.y = -(y - WINDOW_HEIGHT / 2)
		* (converted_fov / (double)WINDOW_HEIGHT);
	end_vec.z = 1;
	rotate_ox(&minirt->scene->camera->normal);
	rotate_oy(&minirt->scene->camera->normal);
	rotate_oz(&minirt->scene->camera->normal);
	return (end_vec);
}
