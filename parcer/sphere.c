#include "parcer.h"

char	ft_sp_con2(t_sp **sp, t_pars_vars **vars, char hit_dig)
{
	if (hit_dig == 1)
		return (fl_parce(&(*sp)->x_cor, vars));
	if (hit_dig == 2)
		return (fl_parce(&(*sp)->y_cor, vars));
	if (hit_dig == 3)
		return (fl_parce(&(*sp)->z_cor, vars));
	if (hit_dig == 4)
		return (fl_parce(&(*sp)->diameter, vars));
	if (hit_dig == 5)
		return (char_parce(&(*sp)->r_col, vars));
	if (hit_dig == 6)
		return (char_parce(&(*sp)->g_col, vars));
	if (hit_dig == 7)
		return (char_parce(&(*sp)->b_col, vars));
	return (1);
}

char	ft_sp_con(t_sp **sp, t_pars_vars **vars, char hit, char hit_dig)
{
	char	comma;

	comma = 0;
	while ((*vars)->line[(*vars)->i])
	{
		if ((*vars)->line[(*vars)->i] == ',')
			comma = ft_check_sp2(hit_dig, vars, comma);
		if (comma == -1 || (hit_dig == 1 && comma == 0))
		{
			printf("BINGO123!\n");
			return (0);
		}
		if ((*vars)->line[(*vars)->i] == 's')
			hit++;
		if ((*vars)->line[(*vars)->i] == 'p')
			hit++;
		if (ft_isfloat((*vars)->line[(*vars)->i]))
		{
			hit_dig++;
			if (!ft_sp_con2(sp, vars, hit_dig))
			{
				printf("BYEEE!\n");
				return (0);
			}
		}
		else
			(*vars)->i++;
		if (!ft_check_sp(hit, hit_dig, (*vars)->line[(*vars)->i], (*vars)->line_cnt))
		{
			printf("BINGO!\n");
			return (0);
		}
	}
	return (hit_dig);
}

char	ft_check_sp2(char hit_dig, t_pars_vars **vars, char comma)
{
	if (hit_dig >= 1 && ((*vars)->line[(*vars)->i] == ','))
		comma++;
	if (hit_dig <= 5)
	{
		if (comma > 3)
		{
			printf("lols\n");
			return (-1);
		}
	}
	if (hit_dig >= 6)
	{
		if (comma >= 5)
		{
			printf("lols2\n");
			return (-1);
		}
	}
	if (comma == 5)
		return (-1);
	return (comma);
}
