#include "minRT.h"

int	hitable_list(t_ray *ray, float t_min, float t_max, t_hit **hit, t_hit_list *hit_list)
{
	t_hit		*temp_hit;
	int		hit_anything;
	double		closest_so_far;

	hit_anything = 0;
	closest_so_far = t_max;
	temp_hit = malloc(sizeof(t_hit) * 1);
	if (temp_hit == NULL)
		return (0);
	for (int i = 0; i < hit_list->list_size; i++)
	{
		if (hit_sphere(ray, t_min, closest_so_far, temp_hit, hit_list->list[i]))
		{
			hit_anything = 1;
			closest_so_far = temp_hit->t;
			*hit = temp_hit;
		}
	}
	return (hit_anything);
}
