#include "minRT.h"

#include <stdlib.h>

t_vec	*color_else2(t_col_var **var, t_vec **holding, int *iter)
{
	free((*var)->new1);
	(*var)->new1 = (*var)->tmp;
	(*var)->ret = vec_plus_vec((*var)->new, (*var)->new1);
	if ((*var)->ret == NULL)
		return (NULL);
	free((*var)->hit);
	free((*var)->new);
	free((*var)->new1);
	while (*iter > 0)
	{
		*holding = vec_times_num((*var)->ret, 0.5);
		free((*var)->ret);
		(*var)->ret = *holding;
		*iter = *iter - 1;
	}
	return ((*var)->ret);
}

t_vec	*c_e(t_col_var **var, t_vec **holding, int *iter, t_ray **ray)
{
	(*var)->unit_dir = unit_vec((*ray)->v2);
	(*var)->t = 0.5 * ((*var)->unit_dir->e[1] + 1.0);
	(*var)->new = new_vector(1.0, 1.0, 1.0);
	if ((*var)->new == NULL)
		return (NULL);
	(*var)->new1 = new_vector(0.5, 0.7, 1.0);
	if ((*var)->new1 == NULL)
		return (NULL);
	(*var)->tmp = vec_times_num((*var)->new, (1.0 - (*var)->t));
	if ((*var)->tmp == NULL)
		return (NULL);
	free((*var)->new);
	(*var)->new = (*var)->tmp;
	(*var)->tmp = vec_times_num((*var)->new1, (*var)->t);
	if ((*var)->tmp == NULL)
		return (NULL);
	return (color_else2(var, holding, iter));
}

int	is_hit(t_col_var **var, t_ray **ray, int *iter)
{
	(*var)->new = vec_plus_vec((*var)->hit->normal, (*var)->hit->p);
	if ((*var)->new == NULL)
		return (0);
	(*var)->random = vec_plus_vec((*var)->new, rand_in_unit_sphere());
	free((*var)->new);
	if ((*var)->random == NULL)
		return (0);
	(*var)->some_vec = vec_minus_vec((*var)->random, (*var)->hit->p);
	free((*var)->random);
	(*var)->new_r = new_ray((*var)->hit->p, (*var)->some_vec);
	if ((*var)->new_r == NULL)
	{
		free((*var)->hit);
		free((*var)->new);
		return (0);
	}
	(*ray) = (*var)->new_r;
	free((*var)->hit);
	free((*var));
	*iter = *iter + 1;
	return (1);
}

int	free_task_draw(t_task **task, t_draw **draw, int ret)
{
	free_task(task);
	free_draw(draw);
	return (ret);
}
