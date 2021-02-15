#include "parcer.h"

char	ft_cy_con2(t_cy **cy, t_pars_vars **vars, char hit_dig)
{
	if (hit_dig == 1)
		return (fl_parce(&(*cy)->x_cor, vars));
	if (hit_dig == 2)
		return (fl_parce(&(*cy)->y_cor, vars));
	if (hit_dig == 3)
		return (fl_parce(&(*cy)->z_cor, vars));
	if (hit_dig == 4)
		return (fl_parce(&(*cy)->x_norm, vars));
	if (hit_dig == 5)
		return (fl_parce(&(*cy)->y_norm, vars));
	if (hit_dig == 6)
		return (fl_parce(&(*cy)->z_norm, vars));
	if (hit_dig == 7)
		return (fl_parce(&(*cy)->diameter, vars));
	if (hit_dig == 8)
		return (fl_parce(&(*cy)->height, vars));
	if (hit_dig == 9)
		return (char_parce(&(*cy)->r_col, vars));
	if (hit_dig == 10)
		return (char_parce(&(*cy)->g_col, vars));
	if (hit_dig == 11)
		return (char_parce(&(*cy)->b_col, vars));
	return (1);
}

char	ft_cy_con(t_cy **cy, t_pars_vars **vars, char hit, char hit_dig)
{
	char	comma;

	comma = 0;
	while ((*vars)->line[(*vars)->i])
	{
		if ((*vars)->line[(*vars)->i] == ',')
			comma = ft_check_cy2(hit_dig, vars, comma);
		if ((comma == -1 || comma == 7)  || (hit_dig == 1 && comma == 0))
			return (-1);
		if ((*vars)->line[(*vars)->i] == 'c')
			hit++;
		if ((*vars)->line[(*vars)->i] == 'y')
			hit++;
		if (ft_isfloat((*vars)->line[(*vars)->i]))
		{
			hit_dig++;
			ft_cy_con2(cy, vars, hit_dig);
		}
		else
			(*vars)->i++;
		if (!ft_check_cy(hit, hit_dig, (*vars)->line[(*vars)->i], (*vars)->line_cnt))
			return (0);
	}
	return (hit_dig);
}

char	ft_check_cy2(char hit_dig, t_pars_vars **vars, char comma)
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
	if (hit_dig <= 7 && hit_dig >= 5)
	{
		if (comma >= 5)
		{
			printf("lols2\n");
			return (-1);
		}
	}
	if (hit_dig <= 11 && hit_dig >= 8)
	{
		if (comma >= 8)
		{
			printf("lols3\n");
			return (-1);
		}
	}
	return (comma);
}
