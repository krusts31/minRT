#include "minRT.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int	hit_sp_sh(t_ray **ray, float closest_so_far, t_sp *sp, t_hit **hit)
{
	t_hit_sp	*hit_sp;

	hit_sp = malloc(sizeof(t_hit_sp) * 1);
	if (hit_sp == NULL)
		exit(!printf("Error\nshade.c:9\n"));
	hit_sp->closest = closest_so_far;
	hit_sp->test = (*ray)->v1;
	hit_sp->oc = vec_minus_vec(hit_sp->test, sp->cor);
	hit_sp->a = dot_vector((*ray)->v2, (*ray)->v2);
	hit_sp->b = dot_vector(hit_sp->oc, (*ray)->v2);
	hit_sp->c = dot_vector(hit_sp->oc, hit_sp->oc) - pow(sp->diameter / 2, 2);
	hit_sp->disc = pow(hit_sp->b, 2) - hit_sp->a * hit_sp->c;
	if (hit_sp->disc > 0.0)
		return (c_sp_sh(&hit_sp, hit, ray, sp));
	return (0);
}

char	c_sp_sh(t_hit_sp **hit_sp, t_hit **hit, t_ray **ray, t_sp *sp)
{
	float	temp;
	t_vec	*tmp;

	temp = - ((*hit_sp)->b) - sqrt((*hit_sp)->disc) / (*hit_sp)->a;
	if (temp < (*hit_sp)->closest && temp > 0.001)
	{
		(*hit)->t = temp;
		(*hit)->p = point_at_param((*ray), (*hit)->t);
		(*hit)->normal = vec_minus_vec((*hit)->p, sp->cor);
		tmp = vec_div_num((*hit)->normal, sp->diameter / 2);
		free((*hit)->normal);
		free((*hit)->p);
		(*hit)->normal = tmp;
		return (1);
	}
	temp = - ((*hit_sp)->b) + sqrt((*hit_sp)->disc) / (*hit_sp)->a;
	if (temp < (*hit_sp)->closest && temp > 0.001)
	{
		(*hit)->t = temp;
		(*hit)->p = point_at_param((*ray), (*hit)->t);
		(*hit)->normal = vec_minus_vec((*hit)->p, sp->cor);
		tmp = vec_div_num((*hit)->normal, sp->diameter / 2);
		free((*hit)->normal);
		free((*hit)->p);
		(*hit)->normal = tmp;
		return (1);
	}
	return (0);
}

/*
**	hit->p is the cord of the oint vector
*/

int	sp_shade(t_light *light, t_sp *sp, t_sp *curent, t_hit **hit)
{
	t_ray	*now;
	float	closest_so_far;

	closest_so_far = INT_MAX;
	now = new_ray((*hit)->p, light->cor);
	if (now == NULL)
		exit(!printf("Error\nline 67 faild in shad.c\n"));
/*
**	clalc surface normal with regards to he light source
*/
	while (sp)
	{
		if (sp != curent)
		{
			if (hit_sp_sh(&now, closest_so_far, sp, hit))
				return (1);
		}
		sp = sp->next;
	}
	return (0);
}
