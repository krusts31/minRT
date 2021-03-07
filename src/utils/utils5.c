#include "minRT.h"

#include <stdlib.h>
#include <stdio.h>

t_vec	*color_else2(t_col_var **var, t_vec **holding, int *iter, t_draw **draw)
{
	free((*var)->new1);
	(*var)->new1 = (*var)->tmp;
	(*var)->ret = vec_plus_vec((*var)->new, (*var)->new1);
	if ((*var)->ret == NULL)
		exit(!printf("Error\nOut of mem vec_plus_vec()!\n"));
	free((*var)->hit);
	free((*var)->new);
	free((*var)->new1);
	while (*iter > 0)
	{
		(void)draw;
//		*holding = vec_times_vec((*var)->ret, (*draw)->col);
		*holding = vec_times_num((*var)->ret, 0.5);
		free((*var)->ret);
		(*var)->ret = *holding;
		*iter = *iter - 1;
	}
	return ((*var)->ret);
}

t_vec	*c_e(t_col_var **var, t_vec **holding, int *iter, t_draw **draw)
{
	(*var)->unit_dir = unit_vec(((*draw)->ray)->v2);
	(*var)->t = 0.5 * ((*var)->unit_dir->e[1] + 1.0);
	(*var)->new = new_vector(1.0, 1.0, 1.0);
	if ((*var)->new == NULL)
		exit(!printf("Error\nOut of mem new_vector()!\n"));
	(*var)->new1 = new_vector(0.5, 0.7, 1.0);
	if ((*var)->new1 == NULL)
		exit(!printf("Error\nOut of mem new_vector()!\n"));
	(*var)->tmp = vec_times_num((*var)->new, (1.0 - (*var)->t));
	if ((*var)->tmp == NULL)
		exit(!printf("Error\nOut of mem vet_times_num()!\n"));
	free((*var)->new);
	(*var)->new = (*var)->tmp;
	(*var)->tmp = vec_times_num((*var)->new1, (*var)->t);
	if ((*var)->tmp == NULL)
		exit(!printf("Error\nOut of mem vet_times_num()!\n"));
	return (color_else2(var, holding, iter, draw));
}

int	is_hit(t_col_var **var, t_ray **ray, int *iter)
{
	t_vec	*tmp;

	(*var)->new = vec_plus_vec((*var)->hit->normal, (*var)->hit->p);
	tmp = rand_in_unit_sphere();
	if (tmp == NULL)
		exit(!printf("Error\nOut of mem rand_in_unit_sphere()!\n"));
	(*var)->random = vec_plus_vec((*var)->new, tmp);
	free((*var)->new);
	free(tmp);
	if ((*var)->random == NULL)
		exit(!printf("Error\nOut of mem vec_plus_vec()!\n"));
	(*var)->some_vec = vec_minus_vec((*var)->random, (*var)->hit->p);
	free((*var)->random);
	(*var)->new_r = new_ray((*var)->hit->p, (*var)->some_vec);
	if ((*var)->new_r == NULL)
		exit(!printf("Error\nOut of mem new_ray()!\n"));
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

void	ft_init_mlx(t_data **d, t_task **t)
{
	(*d)->mlx = mlx_init();
	if ((*d)->mlx == NULL)
		exit(!(printf("Error\nutils5.c:88")));
	(*d)->mlx_win = mlx_new_window((*d)->mlx, (*t)->X_res, (*t)->Y_res, "MINIRT");
	if ((*d)->mlx_win == NULL)
		exit(!(printf("Error\nutils5.c:91")));
	(*d)->img = mlx_new_image((*d)->mlx, (*t)->X_res, (*t)->Y_res);
	(*d)->addr = mlx_get_data_addr((*d)->img, &((*d)->bits_per_pixel), &(*d)->line_length, &(*d)->endian);
}
