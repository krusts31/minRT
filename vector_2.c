#include "minRT.h"

t_vec	*vec_minus_vec(t_vec *v1, t_vec *v2)
{
	t_vec	*new;

	new = malloc(sizeof(t_vec) * 1);
	if (new == NULL)
		return (0);
	new->e[0] = (v1->e[0] - v2->e[0]);
	new->e[1] = (v1->e[1] - v2->e[1]);
	new->e[2] = (v1->e[2] - v2->e[2]);
	return (new);
}
