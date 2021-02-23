#include "minRT.h"
#include <stdlib.h>

t_vec	*point_at_parm(float num, t_ray *ray)
{
	t_vec	*new;

	new = vec_times_num(ray->v2, num);
	if (new == NULL)
		return (NULL);
	return (vec_plus_vec(ray->v1, new));
}

t_ray	*new_ray(t_vec *vec1, t_vec *vec2)
{
	t_ray *new;

	new = malloc(sizeof(t_ray) * 1);
	if (new == NULL)
		return (NULL);
	new->v1 = vec1;
	new->v2 = vec2;
	return (new);
}

t_vec	*point_at_param(t_ray *ray, float t)
{
	t_vec	*new;

	new = vec_times_num(ray->v2, t);
	return (vec_plus_vec(ray->v1, new));
}
