#include "../../includes/minirt.h"

t_vec	vec_add(const t_vec *vec1, const t_vec *vec2)
{
	t_vec	res_vec;

	res_vec.x = vec1->x + vec2->x;
	res_vec.y = vec1->y + vec2->y;
	res_vec.z = vec1->z + vec2->z;
	return (res_vec);
}

t_vec	vec_subtract(const t_vec *vec1, const t_vec *vec2)
{
	t_vec	res_vec;

	res_vec.x = vec2->x - vec1->x;
	res_vec.y = vec2->y - vec1->y;
	res_vec.z = vec2->z - vec1->z;
	return (res_vec);
}

t_vec	vec_multiply_by_num(const t_vec *vec, double n)
{
	t_vec	res_vec;

	res_vec.x = n * vec->x;
	res_vec.y = n * vec->y;
	res_vec.z = n * vec->z;
	return (res_vec);
}

double	vec_dot(const t_vec *vec1, const t_vec *vec2)
{
	return (vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z);
}

t_vec	vec_cross(const t_vec *vec1, const t_vec *vec2)
{
	double	x;
	double	y;
	double	z;

	x = vec1->y * vec2->z - vec1->z * vec2->y;
	y = vec1->z * vec2->x - vec1->x * vec2->z;
	z = vec1->x * vec2->y - vec1->y * vec2->x;
	return (vec_create(x, y, z));
}
