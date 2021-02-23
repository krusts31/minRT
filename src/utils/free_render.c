#include "minRT.h"
#include <stdlib.h>

int	init_draw(t_draw **draw, int xs, int ys, int ns)
{
	*draw = malloc(sizeof(t_draw) * 1);
	if (*draw == NULL)
		return (0);
	(*draw)->ray = NULL;
	(*draw)->p = NULL;
	(*draw)->temp = NULL;
	(*draw)->col = NULL;
	(*draw)->new_col = NULL;
	(*draw)->x = xs;
	(*draw)->y = ys;
	(*draw)->ret = 0;
	(*draw)->t = 0;
	(*draw)->n = ns;
	(*draw)->u = 0;
	(*draw)->v = 0;
	return (1);
}

void	*free_draw(t_draw **draw)
{
	free((*draw)->ray);
	free((*draw)->p);
	free((*draw)->temp);
	free((*draw)->col);
	free((*draw)->new_col);
	free(*draw);
	*draw = NULL;
	return (NULL);
}

int	init_col_var(t_col_var **var)
{
	(*var) = malloc(sizeof(t_col_var) * 1);
	if (*var == NULL)
		return (-1);
	(*var)->hit = NULL; 
	(*var)->unit_dir = NULL;
	(*var)->t = 0.0;
	(*var)->new = NULL;
	(*var)->new1 = NULL;
	(*var)->ret = NULL;
	(*var)->tmp = NULL;
	(*var)->random = NULL;
	(*var)->new_r = NULL;
	(*var)->some_vec = NULL;
	return (1);
}
