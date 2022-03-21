#include "../../includes/minirt.h"

t_vec3	convert_to_viewport(t_minirt *minirt, double x, double y)
{
	t_vec3	d_vec;
	double	converted_fov;
	double	aspect_ratio;

	aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	converted_fov = minirt->scene->camera->fov / (double)DEFAULT_FOV;

	d_vec.x = (x - WINDOW_WIDTH / 2) * (converted_fov / (double)WINDOW_WIDTH) * aspect_ratio;
	d_vec.y = -(y - WINDOW_HEIGHT / 2) * (converted_fov / (double)WINDOW_HEIGHT);
	d_vec.z = 1;
	return (d_vec);
}
