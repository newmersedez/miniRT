#include "../../includes/minirt.h"

t_vec3	convert_to_viewport(t_minirt *minirt, float x, float y)
{
	t_vec3	end_vec;
	float	fov;
	float	aspect_ratio;

	aspect_ratio = (float)WINDOW_WIDTH  / WINDOW_HEIGHT;
	fov = minirt->scene->camera->fov / (float)DEFAULT_FOV;
	end_vec.x = (x - WINDOW_WIDTH / 2) * (fov / WINDOW_WIDTH) * aspect_ratio;
	end_vec.y = -1 * (y - WINDOW_HEIGHT / 2) * (fov / WINDOW_HEIGHT);
	end_vec.z = 1;
	return (vec_normalize(&end_vec));
}
