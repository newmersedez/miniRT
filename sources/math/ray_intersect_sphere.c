#include "../../includes/minirt.h"

static double	calculate_closest_intersection(t_sphere *sphere, const t_point *start_point, const t_vec *ray)
{
	t_vec	oc_vec;
	double	k[3];
	double	t_array[2];
	double	discriminant;

	t_array[0] = INFINITY;
	t_array[1] = INFINITY;
	oc_vec = vec_subtract(&sphere->pos, start_point);
	k[0] = vec_dot(ray, ray);
	k[1] = 2 * vec_dot(&oc_vec, &oc_vec);
	k[2] = vec_dot(&oc_vec, &oc_vec) - (sphere->diameter / 2) * (sphere->diameter / 2);
	discriminant = k[1] * k[1] - 4 * k[0] * k[2];
	if (discriminant >= 0)
	{
		t_array[0] = (-k[1] + sqrtf(discriminant)) / (2 * k[0]);
    	t_array[1] = (-k[1] - sqrtf(discriminant)) / (2 * k[0]);
	}
	if (t_array[0] < t_array[1])
		return (t_array[0]);
	return (t_array[1]);
}

t_point	ray_intersect_sphere(const void *data, const t_point *start_point,
			const t_vec *ray)
{
	t_point		point;
	t_sphere	*sphere;
	double		t;
	t_vec		new_ray;

	sphere = (t_sphere *)sphere;
	set_default_point(&point);
	t = calculate_closest_intersection(sphere, start_point, ray);
	if (t != INFINITY)
	{
		new_ray = vec_multiply_by_num(ray, t);
		new_ray = vec_add(&start_point, start_point);
		point = new_ray;
	}	
	return (point);
}
