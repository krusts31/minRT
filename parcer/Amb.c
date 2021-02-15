#include "parcer.h"

char	ft_check_Amb(char hit, char hit_dig, char b_char, size_t line)
{
	if (hit == 0 && hit_dig == 1)
	{
		printf("Error\nInvalid order of elements on line: %ld\n", line);
		return (0);
	}
	if (!ft_strchr("0123456789A,. \n", b_char))
	{
		printf("Error\nInvalid char: \"%c\" on line: %ld\n", b_char, line);
		return (0);
	}
	if (hit_dig == (char)5)
	{
		printf("Error\nBad numbers for A on line: %ld\n", line);
		return (0);
	}
	if (hit == (char)2)
	{
		printf("Error\nOnly one of A alowed per.rt file: %ld\n", line);
		return (0);
	}
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
		return (char_parce(&(*task)->Amb_light->r_col, vars));
	if (hit_dig == 3)
		return (char_parce(&(*task)->Amb_light->g_col, vars));
	if (hit_dig == 4)
		return (char_parce(&(*task)->Amb_light->b_col, vars));
	return (1);
}

char	ft_check_Amb2(char hit_dig, t_pars_vars **vars, char comma)
{
	if (hit_dig >= 2 && ((*vars)->line[(*vars)->i] == ','))
		comma++;
	if ((hit_dig <= 1 && ((*vars)->line[(*vars)->i] == ',')) || comma == 3)
	{
		printf("Error\nIncorect commas on line %ld\n", (*vars)->line_cnt);
		return (-1);
	}
	return (comma);
}

char	ft_Amb_con(t_task **task, t_pars_vars **vars, char hit, char hit_dig)
{
	char	comma;

	comma = 0;
	while ((*vars)->line[(*vars)->i])
	{
		comma = ft_check_Amb2(hit_dig, vars, comma);
		if (comma == -1 || comma == 3)
			return (0);
		if ((*vars)->line[(*vars)->i] == 'A')
			hit++;
		if (ft_isfloat((*vars)->line[(*vars)->i]))
		{
			hit_dig++;
			if(!ft_Amb_con1(task, vars, hit_dig))
			{
				printf("Error\nBad values for element on line: %ld\n", (*vars)->line_cnt);
				return (0);
			}
		}
		else
			(*vars)->i++;
		if (!ft_check_Amb(hit, hit_dig, (*vars)->line[(*vars)->i], (*vars)->line_cnt))
			return (0);
	}
	return (hit_dig);
}

char	ft_parc_Amb(t_task **task, t_pars_vars **vars)
{
	char	hit;
	char	hit_dig;

	hit_dig = 0;
	hit = 0;
	(*vars)->i = 0;
	hit_dig = ft_Amb_con(task, vars, hit, hit_dig);
	if (hit_dig == 0)
		return (0);
/*	if (hit_dig != 2)
	{
		printf("Error\n2 numbers needed for A on line %ld\n", (*vars)->line_cnt);
		return (0);
	}*/
	return (1);
}
