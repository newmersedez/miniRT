#include "../../includes/minirt.h"

static	double	calculate_discriminant(t_sphere *sphere, const t_point *start_point, const t_vec *ray)
{
	t_vec	oc_vec;
	double	k1;
	double	k2;
	double	k3;
	double	discriminant;

	oc_vec = vec_subtract(&sphere->pos, start_point);
	k1 = vec_dot(ray, ray);
	k2 = 2 * vec_dot(&oc_vec, &oc_vec);
	k3 = vec_dot(&oc_vec, &oc_vec) - (sphere->diameter / 2) * (sphere->diameter / 2);
	discriminant = k2 * k2 - 4 * k1 * k3;
	return (discriminant)
}

t_point	ray_intersect_sphere(const void *data, const t_point *start_point,
			const t_vec *ray)
{
	t_point		point;
	t_sphere	*sphere;
	double		discriminant;

	sphere = (t_sphere *)sphere;
	set_default_point(&point);
	discriminant = calculate_discriminant(sphere, start_point, ray);
	return (point);
}

t_point	ray_intersect_plane(const void *data, const t_point *start_point,
			const t_vec *ray)
{
	t_point	point;
	// printf("plane intersection\n");
	(void)data;
	(void)start_point;
	(void)ray;
	return (point);
}

t_point	ray_intersect_cylinder(const void *data, const t_point *start_point,
			const t_vec *ray)
{
	t_point	point;
	// printf("cylinder intersection\n");
	(void)data;
	(void)start_point;
	(void)ray;
	return (point);
}
