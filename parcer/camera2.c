#include "parcer.h"

char	ft_camera_con2(t_camera **camera, t_pars_vars **vars, char hit_dig)
{
	if (hit_dig == 3)
		return (fl_parce(&(*camera)->z_cor, vars));
	if (hit_dig == 2)
		return (fl_parce(&(*camera)->y_cor, vars));
	if (hit_dig == 1)
		return (fl_parce(&(*camera)->x_cor, vars));
	if (hit_dig == 7)
		return (fl_parce(&(*camera)->FOV, vars));
	if (hit_dig == 6)
		return (fl_parce(&(*camera)->z_norm, vars));
	if (hit_dig == 5)
		return (fl_parce(&(*camera)->y_norm, vars));
	if (hit_dig == 4)
		return (fl_parce(&(*camera)->x_norm, vars));
	return (1);
}

char	ft_camera_con(t_camera **camera, t_pars_vars **vars, char hit, char hit_dig)
{
	char	comma;

	comma = 0;
	while ((*vars)->line[(*vars)->i])
	{
		comma = ft_check_camera2(hit_dig, vars, comma);
		if (comma == -1 || (hit_dig == 1 && comma == 0))
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
		if (!ft_check_camera(hit, hit_dig, (*vars)->line[(*vars)->i]))
			return (0);
	}
	return (hit_dig);
}

char	ft_check_camera2(char hit_dig, t_pars_vars **vars, char comma)
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
	if (hit_dig == 7 && comma != 4)
		return (-1);
	if (comma == 5)
		return (-1);
	return (comma);
}
