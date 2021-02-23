#include "minRT.h"
#include <stdlib.h>

t_vec	*get_color(t_task **task, t_draw **draw, int i, int j)
{
	int	s;

	s = 0;
	while (s < (*draw)->n)
	{
		(*draw)->u = (i + drand48()) / (*draw)->x;
		(*draw)->v = (j + drand48()) / (*draw)->y;
		(*draw)->ray = get_ray((*draw)->u, (*draw)->v, (*task)->camera);
		if ((*draw)->ray == NULL)
			return (NULL);
		(*draw)->p = point_at_param((*draw)->ray, 2.0);
		(*draw)->temp = vec_plus_vec((*draw)->col, color((*draw)->ray, task));
		if ((*draw)->temp == NULL)
			return (NULL);
		free((*draw)->col);
		(*draw)->col = (*draw)->temp;
		s++;
	}
	return ((*draw)->col);
}
