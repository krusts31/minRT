#include "parcer.h"

char	ft_check_res(char hit, char hit_dig, char b_char)
{
	if (hit == 0 && hit_dig == 1)
		return (0);
	if (!ft_strchr("0123456789R \n", b_char))
		return (0);
	if (hit == (char)2)
		return (0);
	return (1);
}

char	ft_res_con(t_task **task, t_pars_vars **vars, char *hit, char hit_dig)
{
	while ((*vars)->line[(*vars)->i])
	{
		if ((*vars)->line[(*vars)->i] == 'R')
			*hit = *hit + 1;
		if (ft_isdigit((*vars)->line[(*vars)->i]))
		{
			hit_dig++;
			if (hit_dig == 1)
			{
				(*task)->X_res = ft_atoi((*vars)->line + (*vars)->i);
				(*vars)->i += ft_size_t_len((*task)->X_res);
			}
			if (hit_dig == 2)
			{
				(*task)->Y_res = ft_atoi((*vars)->line + (*vars)->i);
				(*vars)->i += ft_size_t_len((*task)->Y_res);
			}
		}
		else
			(*vars)->i++;
		if (!ft_check_res(*hit, hit_dig, (*vars)->line[(*vars)->i]))
			return (0);
	}
	return (hit_dig);
}

char	ft_parc_res(t_task **task, t_pars_vars **vars)
{
	static char hitR = 0;
	char	hit_dig;

	hit_dig = 0;
	(*vars)->i = 0;
	hit_dig = ft_res_con(task, vars, &hitR, hit_dig);
	if (hit_dig != 2)
	{
		printf("Error\n2 numbers needed for R on line %ld\n", (*vars)->line_cnt);
		return (0);
	}
	return (1);
}
