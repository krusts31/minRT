#include "minRT.h"

/*
**		MAKE A STRUCT FOT THE VARIBLES
**		POSSIBLY DO THAT FOR EVERY FUNCTION
*/

static t_vec		*free_rand(t_sphere_difuse_var **var)
{
	free((*var)->one);
	free((*var)->rand);
	free((*var)->tmp);
	free((*var)->point);
	free(*var);
	return (NULL);
}

static void		set_rand(t_sphere_difuse_var **var)
{
	(*var)->one = NULL;
	(*var)->rand = NULL;
	(*var)->point = NULL;
	(*var)->tmp = NULL;
}

static t_vec		*compute_rand(t_sphere_difuse_var **var)
{
	t_vec	*temp;

	(*var)->rand = new_vector(drand48(), drand48(), drand48());
	if ((*var)->rand == NULL)
		return (NULL);
	(*var)->tmp = vec_times_num((*var)->rand, 2.0);
	if ((*var)->tmp == NULL)
		return (NULL);
	free((*var)->rand);
	(*var)->rand = (*var)->tmp;
	(*var)->tmp = NULL;
	temp = vec_minus_vec((*var)->rand, (*var)->one);
	if (temp == NULL)
		return (NULL);
	free((*var)->rand);
	(*var)->rand = NULL;
	return (temp);
}

t_vec			*rand_in_unit_sphere()
{
	t_sphere_difuse_var	*var;
	t_vec			*ret;

	var = malloc(sizeof(t_sphere_difuse_var) * 1);
	if (var == NULL)
		return (NULL);
	set_rand(&var);
	var->one = new_vector(1.0, 1.0, 1.0);
	if (var->one == NULL)
		return (free_rand(&var));
	var->point = compute_rand(&var);
	if (var->point == NULL)
		return (free_rand(&var));
	while (length_of_vector_pow2(var->point) >= 1.0)
	{
		var->point = compute_rand(&var);
		if (var->point == NULL)
			return (free_rand(&var));
	}
	ret = vec_copy(var->point);
	free_rand(&var);
	return (ret);
}

int			hit_sphere(t_ray *ray, float t_min, float t_max, t_hit *hit, t_sphere *sphere)
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
