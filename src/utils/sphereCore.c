#include "minRT.h"
#include <math.h>
#include <stdlib.h>

static t_vec	*free_rand(t_sphere_difuse_var **var)
{
	free((*var)->one);
	free((*var)->rand);
	free((*var)->tmp);
	free((*var)->point);
	free(*var);
	return (NULL);
}

static void	set_rand(t_sphere_difuse_var **var)
{
	(*var)->one = NULL;
	(*var)->rand = NULL;
	(*var)->point = NULL;
	(*var)->tmp = NULL;
}

static t_vec	*compute_rand(t_sphere_difuse_var **var)
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

t_vec	*rand_in_unit_sphere(void)
{
	t_sphere_difuse_var	*var;
	t_vec				*ret;

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

int	hit_sp(t_ray **ray, float closest_so_far, t_hit **hit, t_sp *sp)
{
	t_hit_sp	*hit_sp;

	hit_sp = malloc(sizeof(t_hit_sp) * 1);
	if (hit_sp == NULL)
		return (0);
	hit_sp->closest = closest_so_far;
	hit_sp->test = (*ray)->v1;
	hit_sp->oc = vec_minus_vec(hit_sp->test, sp->cor);
	hit_sp->a = dot_vector((*ray)->v2, (*ray)->v2);
	hit_sp->b = dot_vector(hit_sp->oc, (*ray)->v2);
	hit_sp->c = dot_vector(hit_sp->oc, hit_sp->oc) - pow(sp->diameter / 2, 2);
	hit_sp->disc = pow(hit_sp->b, 2) - hit_sp->a * hit_sp->c;
	if (hit_sp->disc > 0.0)
		return (c_sp(hit, &hit_sp, sp, ray));
	return (0);
}
