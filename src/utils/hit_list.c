#include "minRT.h"

#include <stdlib.h>

int	hitable_list(t_ray **ray, float closest_so_far, t_hit **hit, t_sp *sp)
{
	t_hit	*temp_hit;
	int		hit_anything;

	hit_anything = 0;
	temp_hit = malloc(sizeof(t_hit) * 1);
	if (temp_hit == NULL)
		return (0);
	temp_hit->color = new_vector(0, 0, 0);
	while (sp)
	{
		if (hit_sp(ray, closest_so_far, &temp_hit, sp))
		{
			hit_anything = 1;
			closest_so_far = temp_hit->t;
			*hit = temp_hit;
		}
		sp = sp->next;
	}
	return (hit_anything);
}
