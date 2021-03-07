#include "minRT.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float	length_of_vector(t_vec *s)
{
	return (sqrt((pow(s->e[0], 2) + pow(s->e[1], 2) + pow(s->e[2], 2))));
}

t_vec	*cross_vector(t_vec *v1, t_vec *v2)
{
	t_vec	*new;

	new = malloc(sizeof(t_vec) * 1);
	if (new == NULL)
		exit(!printf("Error\vector.c:16\n"));
	new->e[0] = (v1->e[1] * v2->e[2] - v1->e[2] * v2->e[1]);
	new->e[1] = - (v1->e[0] * v2->e[2] - v1->e[2] * v2->e[0]);
	new->e[2] = (v1->e[0] * v2->e[1] - v1->e[1] * v2->e[0]);
	return (new);
}

float	dot_vector(t_vec *v1, t_vec *v2)
{
	return (v1->e[0] * v2->e[0] + v1->e[1] * v2->e[1] + v1->e[2] * v2->e[2]);
}

t_vec	*vec_plus_vec(t_vec *v1, t_vec *v2)
{
	t_vec	*new;

	new = malloc(sizeof(t_vec) * 1);
	if (new == NULL)
		exit(!printf("Error\vector.c:34\n"));
	new->e[0] = (v1->e[0] + v2->e[0]);
	new->e[1] = (v1->e[1] + v2->e[1]);
	new->e[2] = (v1->e[2] + v2->e[2]);
	return (new);
}

t_vec	*vec_plus_num(t_vec *v1, float num)
{
	t_vec	*new;

	new = malloc(sizeof(t_vec) * 1);
	if (new == NULL)
		exit(!printf("Error\vector.c:49\n"));
	new->e[0] = (v1->e[0] + num);
	new->e[1] = (v1->e[1] + num);
	new->e[2] = (v1->e[2] + num);
	return (new);
}
