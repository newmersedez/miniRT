#include "../../includes/minirt.h"

static double	*calculate_closest_intersection(t_sphere *sphere, const t_point *start_point, const t_vec *ray)
{
	t_vec	oc_vec;
	double	k[3];
	double	*t_array;
	double	discriminant;

	// printf("cam = %f %f %f\t", start_point->x, start_point->y, start_point->z);
	// printf("ray = %f %f %f\t", ray->x, ray->y, ray->z);
	t_array = (double *)malloc(2 * sizeof(double));
	if (!t_array)
		return (NULL);
	// printf("pos = %f %f %f\n", sphere->pos.x, sphere->pos.y, sphere->pos.z);
	oc_vec = vec_subtract(&sphere->pos, start_point);
	k[0] = vec_dot(ray, ray);
	k[1] = 2 * vec_dot(&oc_vec, ray);
	k[2] = vec_dot(&oc_vec, &oc_vec) - (sphere->diameter / 2) * (sphere->diameter / 2);
	discriminant = k[1] * k[1] - 4 * k[0] * k[2];
	if (discriminant < 0)
	{
		t_array[0] = INFINITY;
		t_array[1] = INFINITY;
	}
	else
	{
		t_array[0] = (-k[1] + sqrtf(discriminant)) / (2 * k[0]);
    	t_array[1] = (-k[1] - sqrtf(discriminant)) / (2 * k[0]);
	}
	// printf("oc = (%f, %f, %f)\tk[0]=%f, k[1]=%f, k[2]=%f\tdiscr=%f\n",
		// oc_vec.x, oc_vec.y, oc_vec.z,
		// k[0], k[1], k[2], discriminant);
	return (t_array);
}

t_point	ray_intersect_sphere(const void *data, const t_point *start_point,
			const t_vec *ray)
{
	t_point		point;
	t_sphere	*sphere;
	t_vec		new_ray;
	double		*t_array;
	double		closest_t;

	sphere = (t_sphere *)data;
	closest_t = INFINITY;
	set_default_point(&point);
	t_array = calculate_closest_intersection(sphere, start_point, ray);
	if ((t_array[0] >= 1 && t_array[0] <= INFINITY) && (t_array[0] < closest_t))
		closest_t = t_array[0];
	if ((t_array[1] >= 1 && t_array[1] <= INFINITY) && (t_array[1] < closest_t))
		closest_t = t_array[1];
	if (closest_t != INFINITY)
	{
		point = vec_multiply_by_num(ray, closest_t);
		point = vec_add(start_point, &point);
		// printf("point1 = (%f %f %f)\n", point.x, point.y, point.z);
	}
	// printf("point2 = (%f %f %f)\n", point.x, point.y, point.z);
	return (point);
}
