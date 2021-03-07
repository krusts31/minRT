#include "minRT.h"

#include <stdlib.h>
#include <stdio.h>

t_vec	*vec_times_num(t_vec *v1, float num)
{
	t_vec	*new;

	new = malloc(sizeof(t_vec) * 1);
	if (new == NULL)
		exit(!printf("Error\nvector_1.c:10\n"));
	new->e[0] = v1->e[0] * num;
	new->e[1] = v1->e[1] * num;
	new->e[2] = v1->e[2] * num;
	return (new);
}

t_vec	*new_vector(float num1, float num2, float num3)
{
	t_vec	*new;

	new = malloc(sizeof(t_vec) * 1);
	if (new == NULL)
		exit(!printf("Error\nvector_1.c:23\n"));
	new->e[0] = num1;
	new->e[1] = num2;
	new->e[2] = num3;
	return (new);
}

t_vec	*vec_div_vec(t_vec *v1, t_vec *v2)
{
	t_vec	*new;

	new = malloc(sizeof(t_vec) * 1);
	if (new == NULL)
		exit(!printf("Error\nvector_1.c:37\n"));
	new->e[0] = v1->e[0] / v2->e[0];
	new->e[1] = v1->e[1] / v2->e[1];
	new->e[2] = v1->e[2] / v2->e[2];
	return (new);
}

t_vec	*vec_div_num(t_vec *v1, float num)
{
	t_vec	*new;

	new = malloc(sizeof(t_vec) * 1);
	if (new == NULL)
		exit(!printf("Error\nvector_1.c:51\n"));
	new->e[0] = v1->e[0] / num;
	new->e[1] = v1->e[1] / num;
	new->e[2] = v1->e[2] / num;
	return (new);
}

t_vec	*unit_vec(t_vec *v)
{
	t_vec	*ret;

	ret = vec_div_num(v, length_of_vector(v));
	if (ret == NULL)
		exit(!printf("Error\nvector_1.c:65\n"));
	return (ret);
}
