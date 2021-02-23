#include "minRT.h"
#include <stdlib.h>

t_vec	*get_color(t_task **task, t_draw **draw, int i, int j)
{
	for (int s = 0; s < (*draw)->n; s++)
	{
		(*draw)->u = (i + drand48()) / (*draw)->x;
		(*draw)->v = (j + drand48()) / (*draw)->y;
		(*draw)->ray = get_ray((*draw)->u, (*draw)->v, (*task)->camera);
		if ((*draw)->ray == NULL)
		{
			free_task(task);
			return (free_draw(draw));
		}
		(*draw)->p = point_at_param((*draw)->ray, 2.0);
		(*draw)->temp = vec_plus_vec((*draw)->col, color((*draw)->ray, task));
		if ((*draw)->temp == NULL)
		{
			free_task(task);
			return (free_draw(draw));
		}
		free((*draw)->col);
		(*draw)->col = (*draw)->temp;
	}
	return ((*draw)->col);
}
