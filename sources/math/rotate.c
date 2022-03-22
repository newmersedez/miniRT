#include "../../includes/minirt.h"

void	rotate_ox(t_vec3 *vec)
{
	float	angle;
	t_vec3	normal_vec;

	normal_vec.x = 1;
	normal_vec.y = 0;
	normal_vec.z = 0;
	angle = 180 * vec_dot(&normal_vec, vec)
		/ (vec_length(&normal_vec) * vec_length(vec));
	// printf("angle x = %f\n", angle);
	vec->x = vec->x;
	vec->y = vec->y * cos(angle) + vec->z * sin(angle);
	vec->z = -vec->y * sin(angle) + vec->z * cos(angle);
}

void	rotate_oy(t_vec3 *vec)
{
	float	angle;
	t_vec3	normal_vec;

	normal_vec.x = 0;
	normal_vec.y = 1;
	normal_vec.z = 0;
	angle = 180 * vec_dot(&normal_vec, vec)
		/ (vec_length(&normal_vec) * vec_length(vec));
	// printf("angle y = %f\n", angle);
	vec->x = vec->x * cos(angle) + vec->z * sin(angle);
	vec->y = vec->y;
	vec->z = -vec->x * sin(angle) + vec->z * cos(angle);
}

void	rotate_oz(t_vec3 *vec)
{
	float	angle;
	t_vec3	normal_vec;
	normal_vec.x = 0;
	normal_vec.y = 0;
	normal_vec.z = 1;
	angle = 180 * vec_dot(&normal_vec, vec)
		/ (vec_length(&normal_vec) * vec_length(vec));
	// printf("angle z = %f\n\n", angle);
	vec->x = vec->x * cos(angle) - vec->y * sin(angle);
	vec->y = -vec->x * sin(angle) + vec->y * cos(angle);
	vec->z = vec->z;
}
