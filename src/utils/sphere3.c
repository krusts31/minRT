#include "minRT.h"

#include <math.h>
#include <stdlib.h>

char	ft_calc_sphere2(t_hit **hit, float temp, t_sp *sp, t_ray *ray)
{
	t_vec	*tmp;

	(*hit)->t = temp;
	(*hit)->p = point_at_param(ray, (*hit)->t);
	(*hit)->normal = vec_minus_vec((*hit)->p, sp->cor);
	tmp = vec_div_num((*hit)->normal, sp->diameter / 2);
	free((*hit)->normal);
	(*hit)->normal = tmp;
	return (1);
}

char	c_sp(t_hit **hit, t_hit_sp **hit_sp, t_sp *sp, t_ray *ray)
{
	float	temp;
	t_vec	*tmp;

	temp = - ((*hit_sp)->b) - sqrt((*hit_sp)->disc) / (*hit_sp)->a;
	if (temp < (*hit_sp)->closest && temp > 0.001)
	{
		(*hit)->t = temp;
		(*hit)->p = point_at_param(ray, (*hit)->t);
		(*hit)->normal = vec_minus_vec((*hit)->p, sp->cor);
		tmp = vec_div_num((*hit)->normal, sp->diameter / 2);
		free((*hit)->normal);
		(*hit)->normal = tmp;
		return (1);
	}
	temp = - ((*hit_sp)->b) + sqrt((*hit_sp)->disc) / (*hit_sp)->a;
	if (temp < (*hit_sp)->closest && temp > 0.001)
		return (ft_calc_sphere2(hit, temp, sp, ray));
	return (0);
}
