#include "minRT.h"

/*
**		MAKE A STRUCT FOT THE VARIBLES
**		POSSIBLY DO THAT FOR EVERY FUNCTION
**		I ADD * 4 A IN LINE 24
**		A / 2 LINT 28 AND 37 AND IT FIXED THE CODE NO IDEA WHY..
*/

int	hit_sphere(t_ray *ray, float t_min, float t_max, t_hit *hit, t_sphere *sphere)
{
	t_vec	*test;
	t_vec	*oc;
	t_vec	*tmp;
	float	a;
	float	b;
	float	c;
	float	discriminant;
	float	temp;

	test = ray->v1;
	oc = vec_minus_vec(test, sphere->center);
	a = dot_vector(ray->v2, ray->v2);
	b = dot_vector(oc, ray->v2);
	c = dot_vector(oc, oc) - pow(sphere->radius, 2);
	discriminant = pow(b, 2) - a * c;
	if (discriminant > 0.0)
	{
		temp = (-b - sqrt(discriminant)) /  a ;
		if (temp < t_max && temp > t_min)
		{
			hit->t = temp;
			hit->p = point_at_param(ray, hit->t);
			hit->normal = vec_minus_vec(hit->p, sphere->center);
			tmp = vec_div_num(hit->normal, sphere->radius);
			free(hit->normal);
			hit->normal = tmp;
			return (1);
		}
		temp = (-b + sqrt(discriminant)) /  a ;
		if (temp < t_max && temp > t_min)
		{
			hit->t = temp;
			hit->p = point_at_param(ray, hit->t);
			hit->normal = vec_minus_vec(hit->p, sphere->center);
			tmp = vec_div_num(hit->normal, sphere->radius);
			free(hit->normal);
			hit->normal = tmp;
			return (1);
		}
	}
	return (0);
}
