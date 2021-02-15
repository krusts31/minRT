#include "parcer.h"

char	ft_pl_con2(t_pl **pl, t_pars_vars **vars, char hit_dig)
{
	if (hit_dig == 1)
		return (fl_parce(&(*pl)->x_cor, vars));
	if (hit_dig == 2)
		return (fl_parce(&(*pl)->y_cor, vars));
	if (hit_dig == 3)
		return (fl_parce(&(*pl)->z_cor, vars));
	if (hit_dig == 4)
		return (fl_parce(&(*pl)->x_norm, vars));
	if (hit_dig == 5)
		return (fl_parce(&(*pl)->y_norm, vars));
	if (hit_dig == 6)
		return (fl_parce(&(*pl)->z_norm, vars));
	if (hit_dig == 7)
		return (char_parce(&(*pl)->r_col, vars));
	if (hit_dig == 8)
		return (char_parce(&(*pl)->g_col, vars));
	if (hit_dig == 9)
		return (char_parce(&(*pl)->b_col, vars));
	return (1);
}

char	ft_pl_con(t_pl **pl, t_pars_vars **vars, char hit, char hit_dig)
{
	char	comma;

	comma = 0;
	while ((*vars)->line[(*vars)->i])
	{
		if ((*vars)->line[(*vars)->i] == ',')
			comma = ft_check_pl2(hit_dig, vars, comma);
		if ((comma == -1 || comma == 5)  || (hit_dig == 1 && comma == 0))
			return (-1);
		if ((*vars)->line[(*vars)->i] == 'p')
			hit++;
		if ((*vars)->line[(*vars)->i] == 'l')
			hit++;
		if (ft_isfloat((*vars)->line[(*vars)->i]))
		{
			hit_dig++;
			ft_pl_con2(pl, vars, hit_dig);
		}
		else
			(*vars)->i++;
		if (!ft_check_pl(hit, hit_dig, (*vars)->line[(*vars)->i], (*vars)->line_cnt))
			return (0);
	}
	return (hit_dig);
}

char	ft_check_pl2(char hit_dig, t_pars_vars **vars, char comma)
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
	if (hit_dig <= 9 && hit_dig >= 8)
	{
		if (comma >= 7)
		{
			printf("lols2\n");
			return (-1);
		}
	}
	if ((hit_dig >= 7 && ((*vars)->line[(*vars)->i] == ',')) || comma == 5)
		return (-1);
	return (comma);
}
