#include "minRT.h"
#include "error.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int	new_img_con(float FOV, float p, t_image_var **var, t_cameraP *c)
{
	(*var)->theta = FOV * M_PI / 180;
	(*var)->half_height = tan((*var)->theta / 2);
	(*var)->half_width = p * (*var)->half_height;
	(*var)->tmp = vec_minus_vec(c->cor, c->norm);
	if ((*var)->tmp == NULL)
		return (0);
	(*var)->w = unit_vec((*var)->tmp);
	if ((*var)->w == NULL)
		return (0);
	free((*var)->tmp);
	(*var)->tmp = new_vector(0, 1, 0);
	if ((*var)->tmp == NULL)
		return (0);
	(*var)->tmp = cross_vector((*var)->tmp, (*var)->w);
	(*var)->u = unit_vec((*var)->tmp);
	if ((*var)->u == NULL)
		return (0);
	(*var)->v = cross_vector((*var)->u, (*var)->w);
	if ((*var)->v == NULL)
		return (0);
	return (1);
}

int	new_img_con2(t_image_plane **new, t_image_var **vari, t_cameraP *camera)
{
	(*vari)->tmp = vec_times_num((*vari)->u, (*vari)->half_width);
	(*vari)->tmp2 = vec_times_num((*vari)->v, (*vari)->half_height);
	if ((*vari)->tmp == NULL || (*vari)->tmp2 == NULL)
		return (0);
	(*new)->vertical = vec_times_num((*vari)->tmp2, 2);
	if ((*new)->vertical == NULL)
		return (0);
	(*new)->horizontal = vec_times_num((*vari)->tmp, 2);
	if ((*new)->horizontal == NULL)
		return (0);
	(*vari)->tmp3 = vec_minus_vec(camera->cor, (*vari)->tmp);
	(*vari)->tmp4 = vec_minus_vec((*vari)->tmp3, (*vari)->tmp2);
	if (!(*vari)->tmp3 || !(*vari)->tmp4)
		return (0);
	(*new)->upper_left = vec_minus_vec((*vari)->tmp4, (*vari)->w);
	if (!(*new)->upper_left || !(*new)->horizontal || !(*new)->vertical)
		return (0);
	return (1);
}

t_image_plane	*new_image_plane(float FOV, float portion, t_cameraP *camera)
{
	t_image_plane	*new;
	t_image_var		*var;

	var = ft_init_image();
	new = ft_init_image_plane();
	if (new == NULL || var == NULL)
		return (ft_image_error(&var, &new));
	if (!new_img_con(FOV, portion, &var, camera))
		return (ft_image_error(&var, &new));
	if (!new_img_con2(&new, &var, camera))
		return (ft_image_error(&var, &new));
	ft_free_image_vars(&var);
	return (new);
}

static t_ray	*free_get_ray(t_vec *cor, t_vec *fin, t_vec **tmp1, t_vec **tmp)
{
	t_ray	*ray;

	free(*tmp1);
	free(*tmp);
	ray = new_ray(cor, fin);
	return (ray);
}

t_ray	*get_ray(float u, float v, t_cameraP *cam)
{
	t_vec	*sum_lower_hor;
	t_vec	*fin;
	t_vec	*tmp;
	t_vec	*tmp1;
	t_vec	*tmp3;

	tmp = vec_times_num(cam->image->horizontal, u);
	tmp1 = vec_times_num(cam->image->vertical, v);
	if (tmp1 == NULL || tmp == NULL)
		exit(!printf(ERROR_8));
	sum_lower_hor = vec_plus_vec(cam->image->upper_left, tmp);
	tmp3 = vec_minus_vec(tmp1, cam->cor);
	if (tmp3 == NULL || sum_lower_hor == NULL)
		exit(!printf(ERROR_8));
	fin = vec_plus_vec(sum_lower_hor, tmp3);
	if (fin == NULL)
		exit(!printf("Error\nvec_plus_vec failed on file cCore.c\n"));
	free(sum_lower_hor);
	free(tmp3);
	return (free_get_ray(cam->cor, fin, &tmp1, &tmp));
}
