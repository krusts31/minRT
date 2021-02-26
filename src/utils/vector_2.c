#include "minRT.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

t_vec	*vec_minus_vec(t_vec *v1, t_vec *v2)
{
	t_vec	*new;

	new = malloc(sizeof(t_vec) * 1);
	if (new == NULL)
		exit(!printf("Error\nOut of memmory in vector_2.c\n"));
	new->e[0] = (v1->e[0] - v2->e[0]);
	new->e[1] = (v1->e[1] - v2->e[1]);
	new->e[2] = (v1->e[2] - v2->e[2]);
	return (new);
}

float	length_of_vector_pow2(t_vec *self)
{
	return (pow(self->e[0], 2) + pow(self->e[1], 2) + pow(self->e[2], 2));
}

t_vec	*vec_copy(t_vec *src)
{
	t_vec	*dest;

	dest = malloc(sizeof(t_vec) * 1);
	if (dest == NULL)
		exit(!printf("Error\nOut of memmory in vector_2.c\n"));
	dest->e[0] = src->e[0];
	dest->e[1] = src->e[1];
	dest->e[2] = src->e[2];
	return (dest);
}

t_vec_uc	*new_vector_uc(int num1, int num2, int num3)
{
	t_vec_uc	*new;

	new = malloc(sizeof(t_vec_uc) * 1);
	if (new == NULL)
		exit(!printf("Error\nOut of memmory in vector_2.c\n"));
	new->e[0] = num1;
	new->e[1] = num2;
	new->e[2] = num3;
	return (new);
}

t_vec	*vec_uc_times_vec(t_vec *v1, t_vec_uc *v2)
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
