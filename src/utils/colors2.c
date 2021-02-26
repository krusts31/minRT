#include "minRT.h"

#include <stdio.h>
#include <stdlib.h>

t_vec	*get_color(t_task **task, t_draw **draw, int i, int j)
{
	int	s;
	t_vec	*tmp;
	int	depth;

	depth = 0;
	s = 0;
	while (s < (*draw)->n)
	{
		(*draw)->u = (i + drand48()) / (*draw)->x;
		(*draw)->v = (j + drand48()) / (*draw)->y;
		(*draw)->ray = get_ray((*draw)->u, (*draw)->v, (*task)->camera);
		if ((*draw)->ray == NULL)
			exit(!printf("Error\nget_ray out of mem col2\n"));
		(*draw)->p = point_at_param((*draw)->ray, 2.0);
		tmp = color(&(*draw)->ray, task, depth);
		if (!tmp)
			exit(!printf("Error\ncolor failed!\n"));
		(*draw)->temp = vec_plus_vec((*draw)->col, tmp);
		if ((*draw)->temp == NULL)
			exit(!printf("Error\nvec_plus_vec faile! g_col\n"));
		free((*draw)->col);
		free(tmp);
		(*draw)->col = (*draw)->temp;
		s++;
	}
	return ((*draw)->col);
}
