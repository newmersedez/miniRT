#include "../../includes/minirt.h"

double	ray_intersect_sphere(t_vec3 *start, t_vec3 *end, t_sphere *sphere, int *intersected)
{
	(void)start;
	(void)end;
	(void)sphere;
	(void)intersected;
	// t_vec3	oc;
	// double	k1;
	// double	k2;
	// double	k3;
	// double 	discriminant;
	// double	t1;
	// double	t2;

	// oc = vec_subtract(start, &sphere->pos);
	// k1 = vec_dot(end, end);
	// k2 = 2 * vec_dot(&oc, end);
	// k3 = vec_dot(&oc, &oc) - ((sphere->diameter / 2) * (sphere->diameter / 2));
	// discriminant = k2 * k2 - 4 * k1 * k3;
	// if (discriminant < 0)
	// {
	// 	*intersected = 0;	
	// 	return (0);
	// }
	// else
	// {
	// 	*intersected = 1;
	// 	t1 = (-k2 + sqrt(discriminant)) / (2*k1)
    // 	t2 = (-k2 - sqrt(discriminant)) / (2*k1)
	// }
	// if (t1 < 2
	// return ()
	return (0);
}
