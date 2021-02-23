#include "parcer.h"
#include "minRT.h"

#include <stdio.h>

char	ft_check_Amb(char hit, char hit_dig, char b_char)
{
	if (hit == 0 && hit_dig == 1)
		return (0);
	if (!ft_strchr("0123456789A,. \n", b_char))
		return (0);
	if (hit == (char)2)
		return (0);
	return (1);
}

char	ft_Amb_con1(t_task **task, t_pars_vars **vars, char hit_dig)
{
	char	check;

	check = 0;
	if (hit_dig == 1)
	{
		fl_parce(&(*task)->Amb_light->ratio, vars);
		if ((*task)->Amb_light->ratio < 0.0 &&
			 (*task)->Amb_light->ratio > 1.0)
			return (0);
		return (1);
	}
	if (ft_strchr(((*vars)->line + (*vars)->i), '.'))
		return (0);
	if (hit_dig == 2)
		return (char_parce(&(*task)->Amb_light->col->e[0], vars));
	if (hit_dig == 3)
		return (char_parce(&(*task)->Amb_light->col->e[1], vars));
	if (hit_dig == 4)
		return (char_parce(&(*task)->Amb_light->col->e[2], vars));
	return (1);
}

char	ft_check_Amb2(char hit_dig, t_pars_vars **vars, char comma)
{
	if (hit_dig >= 1 && ((*vars)->line[(*vars)->i] == ','))
		comma++;
	if (hit_dig == 1 && comma != 0)
		return (-1);
	if (hit_dig == 2 && comma != 1)
		return (-1);
	if (hit_dig == 3 && comma != 2)
		return (-1);
	if (hit_dig == 4 && comma != 2)
		return (-1);
	if (comma == 3)
		return (-1);
	return (comma);
}

char	ft_Amb_con(t_task **task, t_pars_vars **vars, char *hit, char hit_dig)
{
	char	comma;

	comma = 0;
	while ((*vars)->line[(*vars)->i])
	{
		comma = ft_check_Amb2(hit_dig, vars, comma);
		if (comma == -1)
			return (0);
		if ((*vars)->line[(*vars)->i] == 'A')
			*hit = *hit + 1;
		if (ft_isfloat((*vars)->line[(*vars)->i]))
		{
			hit_dig++;
			if(!ft_Amb_con1(task, vars, hit_dig))
				return (0);
		}
		else
			(*vars)->i++;
		if (!ft_check_Amb(*hit, hit_dig, (*vars)->line[(*vars)->i]))
			return (0);
	}
	return (hit_dig);
}

char	ft_parc_Amb(t_task **task, t_pars_vars **vars)
{
	static char	hitA = 0;
	char		hit_dig;

	hit_dig = 0;
	(*vars)->i = 0;
	hit_dig = ft_Amb_con(task, vars, &hitA, hit_dig);
	if (hit_dig != 4)
	{
		printf("Error\nBad elements on line %ld\n", (*vars)->line_cnt);
		return (0);
	}
	return (1);
}
