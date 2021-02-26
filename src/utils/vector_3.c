#include "minRT.h"

#include <stdlib.h>
#include <stdio.h>

t_vec	*vec_uc_div_num(t_vec_uc *v1, float num)
{
	t_vec	*new;

	new = malloc(sizeof(t_vec) * 1);
	if (new == NULL)
		exit(!printf("Error\nOut of mem v_d_n v_3\n"));
	new->e[0] = v1->e[0] / num;
	new->e[1] = v1->e[1] / num;
	new->e[2] = v1->e[2] / num;
	return (new);
}

t_vec	*vec_times_vec(t_vec *v1, t_vec *v2)
{
	t_vec	*new;

	new = malloc(sizeof(t_vec) * 1);
	if (new == NULL)
		exit(!printf("Error\nOut of memmory in vector_2.c\n"));
	new->e[0] = v1->e[0] * v2->e[0];
	new->e[1] = v1->e[1] * v2->e[1];
	new->e[2] = v1->e[2] * v2->e[2];
	return (new);
}
