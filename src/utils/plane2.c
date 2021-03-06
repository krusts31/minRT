#include "parcer.h"
#include "minRT.h"

char	ft_pl_con2(t_pl **pl, t_pars_vars **vars, char hit_dig)
{
	if (hit_dig == 1)
		return (fl_parce(&(*pl)->cor->e[0], vars));
	if (hit_dig == 2)
		return (fl_parce(&(*pl)->cor->e[1], vars));
	if (hit_dig == 3)
		return (fl_parce(&(*pl)->cor->e[2], vars));
	if (hit_dig == 4)
		return (fl_parce(&(*pl)->norm->e[0], vars));
	if (hit_dig == 5)
		return (fl_parce(&(*pl)->norm->e[1], vars));
	if (hit_dig == 6)
		return (fl_parce(&(*pl)->norm->e[2], vars));
	if (hit_dig == 7)
		return (char_parce(&(*pl)->col->e[0], vars));
	if (hit_dig == 8)
		return (char_parce(&(*pl)->col->e[1], vars));
	if (hit_dig == 9)
		return (char_parce(&(*pl)->col->e[2], vars));
	return (1);
}

char	pl_con(t_pl **pl, t_pars_vars **vars, char hit, char hit_d)
{
	char	comma;

	comma = 0;
	while ((*vars)->line[(*vars)->i])
	{
		comma = ft_check_pl2(hit_d, vars, comma);
		if (comma == -1 || (hit_d == 1 && comma == 0))
			return (0);
		if ((*vars)->line[(*vars)->i] == 'p')
			hit++;
		if ((*vars)->line[(*vars)->i] == 'l')
			hit++;
		if (ft_isfloat((*vars)->line[(*vars)->i]))
		{
			hit_d++;
			ft_pl_con2(pl, vars, hit_d);
		}
		else
			(*vars)->i++;
		if (!ft_check_pl(hit, hit_d, (*vars)->line[(*vars)->i]))
			return (0);
	}
	return (hit_d);
}

char	ft_check_pl2(char hit_dig, t_pars_vars **vars, char comma)
{
	if (hit_dig >= 1 && ((*vars)->line[(*vars)->i] == ','))
		comma++;
	if (hit_dig == 1 && comma != 1)
		return (-1);
	if (hit_dig == 2 && comma != 2)
		return (-1);
	if (hit_dig == 3 && comma != 2)
		return (-1);
	if (hit_dig == 4 && comma != 3)
		return (-1);
	if (hit_dig == 5 && comma != 4)
		return (-1);
	if (hit_dig == 6 && comma != 4)
		return (-1);
	if (hit_dig == 7 && comma != 5)
		return (-1);
	if (hit_dig == 8 && comma != 6)
		return (-1);
	if (hit_dig == 9 && comma != 6)
		return (-1);
	if (comma == 7)
		return (-1);
	return (comma);
}
