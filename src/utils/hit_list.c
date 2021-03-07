#include "minRT.h"

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

int	in_shade(t_light *light, t_task **task, t_sp *curent, t_hit **hit)
{
	if (sp_shade(light, (*task)->sp, curent, hit))
		return (1);
/*	if (tr_shade((*task)-tr))
		return (0);
	if (pl_shade((*task)-pl))
		return (0);
	if (sq_shade((*task)-sq))
		return (0);
	if (cy_shade((*task)-cy))
		return (0);*/
	return (0);
}

int	sp_light(t_hit **hit, t_task **task, t_sp *sp)
{
	t_light	*li;

	li = (*task)->light;
	while (li)
	{
		if (!in_shade(li, task, sp, hit))
		{
			(*hit)->color->e[0] = sp->col->e[0] / 255.99 * (*hit)->normal->e[1];
			(*hit)->color->e[1] = sp->col->e[1] / 255.99 * (*hit)->normal->e[1];
			(*hit)->color->e[2] = sp->col->e[2] / 255.99 * (*hit)->normal->e[1];
		}
		else
		{
			(*hit)->color->e[0] = 1;
			(*hit)->color->e[1] = 1;
			(*hit)->color->e[2] = 1;
		}
//			lumen_sp(hit, task, sp)
		li = li->next;
	}
	return (0);
}

int	hitable_list(t_ray **ray, float closest_so_far, t_hit **hit, t_task **task)
{
	t_hit	*temp_hit;
	int		hit_anything;
	t_sp	*sp;

	sp = (*task)->sp;
	hit_anything = 0;
	temp_hit = malloc(sizeof(t_hit) * 1);
	if (temp_hit == NULL)
		exit(!printf("Error\nhit_list.c:55\n"));
	temp_hit->color = new_vector(0, 0, 0);
	while (sp)
	{
		if (hit_sp(ray, closest_so_far, &temp_hit, sp))
		{
			hit_anything = 1;
			closest_so_far = temp_hit->t;
			*hit = temp_hit;
			sp_light(hit, task, sp);
		}
		sp = sp->next;
	}
	return (hit_anything);
}
