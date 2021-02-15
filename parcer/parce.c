#include "parcer.h"

char	char_parce(unsigned char *col, t_pars_vars **vars)
{
	char		index;
	unsigned short	nr;

	index = 0;
	nr = ft_atoi((*vars)->line + (*vars)->i);
	if (nr > 255)
		return (0);
	while (ft_isdigit((*vars)->line[(*vars)->i + (int)index]))
	{
		if (index > 3)
			return (0);
		index++;
	}
	*col = nr;
	(*vars)->i += ft_intlen(*col);
	return (1);
}

char	fl_parce(float *value, t_pars_vars **vars)
{
	size_t	index;
	size_t	minuss;
	size_t	check;

	check = 0;
	minuss = 0;
	index = 0;
	*value = ft_atof((*vars)->line + (*vars)->i);
	while (ft_isfloat((*vars)->line[(*vars)->i]))
	{
		if (((*vars)->line[(*vars)->i]) == '.')
			check++;
		if (check == 2)
			return (0);
		if ((*vars)->line[(*vars)->i] == '-')
			minuss++;
		if ((index >= 9 && minuss == 0) || minuss >= 2)
			return (0);
		if (index >= 10 && minuss == 1)
			return (0);
		index++;
		(*vars)->i++;
	}
	return (1);
}
