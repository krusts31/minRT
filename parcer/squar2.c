#include "parcer.h"

char	ft_sq_con2(t_sq **sq, t_pars_vars **vars, char hit_dig)
{
	if (hit_dig == 1)
		return (fl_parce(&(*sq)->x_cor, vars));
	if (hit_dig == 2)
		return (fl_parce(&(*sq)->y_cor, vars));
	if (hit_dig == 3)
		return (fl_parce(&(*sq)->z_cor, vars));
	if (hit_dig == 4)
		return (fl_parce(&(*sq)->x_norm, vars));
	if (hit_dig == 5)
		return (fl_parce(&(*sq)->y_norm, vars));
	if (hit_dig == 6)
		return (fl_parce(&(*sq)->z_norm, vars));
	if (hit_dig == 7)
		return (fl_parce(&(*sq)->side_size, vars));
	if (hit_dig == 8)
		return (char_parce(&(*sq)->r_col, vars));
	if (hit_dig == 9)
		return (char_parce(&(*sq)->g_col, vars));
	if (hit_dig == 10)
		return (char_parce(&(*sq)->b_col, vars));
	return (1);
}

char	ft_sq_con(t_sq **sq, t_pars_vars **vars, char hit, char hit_dig)
{
	char	comma;

	comma = 0;
	while ((*vars)->line[(*vars)->i])
	{
		if ((*vars)->line[(*vars)->i] == ',')
			comma = ft_check_sq2(hit_dig, vars, comma);
		if ((comma == -1 || comma == 7)  || (hit_dig == 1 && comma == 0))
			return (0);
		if ((*vars)->line[(*vars)->i] == 's')
			hit++;
		if ((*vars)->line[(*vars)->i] == 'q')
			hit++;
		if (ft_isfloat((*vars)->line[(*vars)->i]))
		{
			hit_dig++;
			ft_sq_con2(sq, vars, hit_dig);
		}
		else
			(*vars)->i++;
		if (!ft_check_sq(hit, hit_dig, (*vars)->line[(*vars)->i], (*vars)->line_cnt))
			return (0);
	}
	return (hit_dig);
}

char	ft_check_sq2(char hit_dig, t_pars_vars **vars, char comma)
{
	if (hit_dig >= 1 && ((*vars)->line[(*vars)->i] == ','))
		comma++;
	if (hit_dig <= 4)
	{
		if (comma > 3)
		{
			printf("lols\n");
			return (-1);
		}
	}
	if (hit_dig <= 8 && hit_dig >= 5)
	{
		if (comma > 5)
		{
			printf("lols2234\n");
			return (-1);
		}
	}
	if (hit_dig <= 10 && hit_dig >= 9)
	{
		if (comma >= 7)
		{
			printf("this is coma %d and this is hit_dig %d\n", comma, hit_dig);
			printf("lols3\n");
			return (-1);
		}
	}
	if ((hit_dig >= 7 && ((*vars)->line[(*vars)->i] == ',')) || comma == 5)
		return (-1);
	return (comma);
}
