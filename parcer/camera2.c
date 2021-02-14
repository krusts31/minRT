#include "parcer.h"

char	ft_camera_con3(t_camera **camera, t_pars_vars **vars, char hit_dig)
{
	if (hit_dig == 7)
	{
		if (!fl_parce(&(*camera)->FOV, vars))
			return (-2);
	}
	if (hit_dig == 6)
	{
		if (!fl_parce(&(*camera)->z_norm, vars))
			return (-2);
	}
	if (hit_dig == 5)
	{
		if (!fl_parce(&(*camera)->y_norm, vars))
			return (-2);
	}
	if (hit_dig == 4)
	{
		if (!fl_parce(&(*camera)->x_norm, vars))
			return (-2);
	}
	return (1);
}

char	ft_camera_con2(t_camera **camera, t_pars_vars **vars, char hit_dig)
{
	if (hit_dig == 3)
	{
		if (!fl_parce(&(*camera)->z_cor, vars))
			return (-2);
	}
	if (hit_dig == 2)
	{
		if (!fl_parce(&(*camera)->y_cor, vars))
			return (-2);
	}
	if (hit_dig == 1)
	{
		if (!fl_parce(&(*camera)->x_cor, vars))
			return (-2);
	}
	return (ft_camera_con3(camera, vars, hit_dig));
}

char	ft_camera_con(t_camera **camera, t_pars_vars **vars, char hit, char hit_dig)
{
	char	comma;

	comma = 0;
	while ((*vars)->line[(*vars)->i])
	{
		if ((*vars)->line[(*vars)->i] == ',')
			comma = ft_check_camera2(hit_dig, vars, comma);
		if ((comma == -1 || comma == 5)  || (hit_dig == 1 && comma == 0))
			return (-1);
		if ((*vars)->line[(*vars)->i] == 'c')
			hit++;
		if (ft_isfloat((*vars)->line[(*vars)->i]))
		{
			hit_dig++;
			ft_camera_con2(camera, vars, hit_dig);
		}
		else
			(*vars)->i++;
		if (!ft_check_camera(hit, hit_dig, (*vars)->line[(*vars)->i], (*vars)->line_cnt))
			return (0);
	}
	return (hit_dig);
}

char	ft_check_camera2(char hit_dig, t_pars_vars **vars, char comma)
{
	if (hit_dig >= 1 && ((*vars)->line[(*vars)->i] == ','))
		comma++;
	if ((hit_dig < 4 && hit_dig < 7))
	{
		if (hit_dig != comma)
			return (-1);
	}
	if (hit_dig >= 4 && hit_dig < 7)
	{
		if (hit_dig != comma + 1)
			return (-1);
	}
	if ((hit_dig >= 7 && ((*vars)->line[(*vars)->i] == ',')) || comma == 5)
		return (-1);
	return (comma);
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
