#include "minRT.h"

#include <stdio.h>
#include <stdlib.h>

int	scatter(t_hit **rec, t_ray **scatt, t_vec **att)
{
	t_vec	*tmp;
	t_vec	*tmp2;

	tmp = vec_plus_vec((*rec)->p, (*rec)->normal);
	if (tmp == NULL)
		exit(!printf("Error\nOut of mem material.c vpv\n"));
	tmp2 = vec_plus_vec(tmp, rand_in_unit_sphere());
	if (tmp2 == NULL)
		exit(!printf("Error\nOut of mem material.c vpv\n"));
	free(tmp);
	tmp = vec_minus_vec(tmp2, (*rec)->p);
	*scatt = new_ray((*rec)->p, tmp);
	if (*scatt == NULL)
		exit(!printf("Error\nOut of mem material.c nr\n"));
	free(tmp2);
	(*att) = (*rec)->color;
	return (1);
}

/*
int	diffuse_light()
{
	return ();
}
*/
