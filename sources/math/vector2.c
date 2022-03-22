#include "../../includes/minirt.h"

t_vec3d	vec_add(t_vec3d *vec1, t_vec3d *vec2)
{
	t_vec3d	res_vec;

	res_vec.x = vec1->x + vec2->x;
	res_vec.y = vec1->y + vec2->y;
	res_vec.z = vec1->z + vec2->z;
	return (res_vec);
}

t_vec3d	vec_subtract(t_vec3d *vec1, t_vec3d *vec2)
{
	t_vec3d	res_vec;

	res_vec.x = vec2->x - vec1->x;
	res_vec.y = vec2->y - vec1->y;
	res_vec.z = vec2->z - vec1->z;
	return (res_vec);
}

t_vec3d	vec_multiply_by_num(t_vec3d *vec, float n)
{
	t_vec3d	res_vec;

	res_vec.x = n * vec->x;
	res_vec.y = n * vec->y;
	res_vec.z = n * vec->z;
	return (res_vec);
}

float	vec_dot(t_vec3d *vec1, t_vec3d *vec2)
{
	return (vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z);
}
