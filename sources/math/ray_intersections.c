#include "../../includes/minirt.h"

t_vec2	ray_intersect_sphere(t_vec3 *start, t_vec3 *end, t_sphere *sphere)
{
	t_vec3	oc;
	t_vec2	collisions = {0, 0, 0};
	double	k1;
	double	k2;
	double	k3;
	double 	discriminant;

	oc = vec_subtract(start, &sphere->pos);
	k1 = vec_dot(end, end);
	k2 = 2 * vec_dot(&oc, end);
	k3 = vec_dot(&oc, &oc) - ((sphere->diameter / 2) * (sphere->diameter / 2));
	discriminant = k2 * k2 - 4 * k1 * k3;
	{
		collisions.z = -1;
		return (collisions);
	}
	else
	{
		t1 = (-k2 + sqrt(discriminant)) / (2*k1)
    	t2 = (-k2 - sqrt(discriminant)) / (2*k1)
	}
}
