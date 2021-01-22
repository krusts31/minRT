#include "minRT.h"

void	*free_camera(t_camera **camera)
{
	free((*camera)->lower_left_corner);
	free((*camera)->horizontal);
	free((*camera)->vertical);
	free((*camera)->origin);
	free(*camera);
	return (NULL);
}

t_camera	*new_camera()
{
	t_camera	*new;

	new = malloc(sizeof(t_camera) * 1);
	if (new == NULL)
		return (NULL);
	new->lower_left_corner = NULL;
	new->origin = NULL;
	new->horizontal = NULL;
	new->vertical = NULL;
	new->lower_left_corner = new_vector(-2.0, -1.0, -1.0);
	new->origin = new_vector(0.0, 0.0, 0.0);
	new->horizontal = new_vector(4.0, 0.0, 0.0);
	new->vertical  = new_vector(0.0, 2.0, 0.0);
	if (!new->lower_left_corner || !new->origin)
		return (free_camera(&new));
	if (!new->horizontal || !new->vertical)
		return (free_camera(&new));
	return (new);
}

t_ray	*get_ray(float u, float v, t_camera *cam)
{
	t_ray	*new;
	t_vec	*sum_lower_hor;
	t_vec	*diff_ver_origin;
	t_vec	*fin;
	t_vec	*tmp;
	t_vec	*tmp1;

	tmp = vec_times_num(cam->horizontal, u);
	if (tmp == NULL)
		return (NULL);
	tmp1 = vec_times_num(cam->vertical, v);
	if (tmp1 == NULL)
		return (NULL);
	sum_lower_hor = vec_plus_vec(cam->lower_left_corner, tmp);
	diff_ver_origin = vec_minus_vec(tmp1, cam->origin);	
	fin = vec_plus_vec(sum_lower_hor, diff_ver_origin);
	free(sum_lower_hor);
	free(diff_ver_origin);
	new = new_ray(cam->origin, fin);
	if (new == NULL)
		return (NULL);
	return (new);
}
