#include "parcer.h"

char	ft_tr_con2(t_tr **tr, t_pars_vars **vars, char hit_dig)
{
	if (hit_dig == 1)
		return (fl_parce(&(*tr)->x_cor1, vars));
	if (hit_dig == 2)
		return (fl_parce(&(*tr)->y_cor1, vars));
	if (hit_dig == 3)
		return (fl_parce(&(*tr)->z_cor1, vars));
	if (hit_dig == 4)
		return (fl_parce(&(*tr)->x_cor2, vars));
	if (hit_dig == 5)
		return (fl_parce(&(*tr)->y_cor2, vars));
	if (hit_dig == 6)
		return (fl_parce(&(*tr)->z_cor2, vars));
	if (hit_dig == 7)
		return (fl_parce(&(*tr)->x_cor3, vars));
	if (hit_dig == 8)
		return (fl_parce(&(*tr)->y_cor3, vars));
	if (hit_dig == 9)
		return (fl_parce(&(*tr)->z_cor3, vars));
	if (hit_dig == 10)
		return (char_parce(&(*tr)->r_col, vars));
	if (hit_dig == 11)
		return (char_parce(&(*tr)->g_col, vars));
	if (hit_dig == 12)
		return (char_parce(&(*tr)->b_col, vars));
	return (1);
}

char	ft_tr_con(t_tr **tr, t_pars_vars **vars, char hit, char hit_dig)
{
	char	comma;

	comma = 0;
	while ((*vars)->line[(*vars)->i])
	{
		if ((*vars)->line[(*vars)->i] == ',')
			comma = ft_check_tr2(hit_dig, vars, comma);
		if ((comma == -1 || comma == 9)  || (hit_dig == 1 && comma == 0))
			return (0);
		if ((*vars)->line[(*vars)->i] == 't')
			hit++;
		if ((*vars)->line[(*vars)->i] == 'r')
			hit++;
		if (ft_isfloat((*vars)->line[(*vars)->i]))
		{
			hit_dig++;
			ft_tr_con2(tr, vars, hit_dig);
		}
		else
			(*vars)->i++;
		if (!ft_check_tr(hit, hit_dig, (*vars)->line[(*vars)->i], (*vars)->line_cnt))
			return (0);
	}
	return (hit_dig);
}

char	ft_check_tr2(char hit_dig, t_pars_vars **vars, char comma)
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
		if (comma > 5)
		{
			printf("lols2\n");
			return (-1);
		}
	}
	if (hit_dig <= 10 && hit_dig >= 8)
	{
		if (comma > 7)
		{
			printf("lols3\n");
			return (-1);
		}
	}
	if (hit_dig <= 13 && hit_dig >= 11)
	{
		if (comma >= 9)
		{
			printf("lols4\n");
			return (-1);
		}
	}
	return (comma);
}
