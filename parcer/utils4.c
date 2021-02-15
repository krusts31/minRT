#include "parcer.h"

void	error_con(t_pars_vars **vars, t_task **task)
{
	if (*task != NULL)
	{
		free_sq(task);
		free_pl(task);
		free_cy(task);
		free_sp(task);
		free_tr(task);
		free_light(task);
		free((*task)->Amb_light);
		free(*task);
		(*task) = NULL;
	}
	if (*vars != NULL)
	{
		free((*vars)->line);
		free(*vars);
		(*vars) = NULL;
	}
}

short	error(t_pars_vars **vars, short ret, t_task **task)
{
	error_con(vars, task);
	return (ret);
}

/*
**	task will contain all the information simillar to printf stuct for flags
*/

char	init_task(t_task **task)
{
	(*task)->sq = NULL;
	(*task)->pl = NULL;
	(*task)->cy = NULL;
	(*task)->sp = NULL;
	(*task)->tr = NULL;
	(*task)->light = NULL;
	(*task)->Amb_light = NULL;
	(*task)->camera = NULL;
	(*task)->Amb_light = malloc(sizeof(t_amb_light) * 1);
/*	(*task)->sq = malloc(sizeof(t_sq) * 1);
	(*task)->pl = malloc(sizeof(t_pl) * 1);
	(*task)->cy = malloc(sizeof(t_cy) * 1);
	(*task)->sp = malloc(sizeof(t_sp) * 1);
	(*task)->tr = malloc(sizeof(t_tr) * 1);
	(*task)->light = malloc(sizeof(t_light) * 1);
	(*task)->camera = malloc(sizeof(t_camera) * 1); */
/*	if ((*task)->sq == NULL || (*task)->pl == NULL || (*task)->cy == NULL
		|| (*task)->sp == NULL ||(*task)->tr == NULL || (*task)->camera == NULL ||
		(*task)->light == NULL || (*task)->Amb_light == NULL)
		return (0);*/
	if ((*task)->Amb_light == NULL)
		return (0);
	return (1);
}

char	init(t_task **task, t_pars_vars **vars)
{
	*task = malloc(sizeof(t_task) * 1);
	if (*task == NULL)
		return (0);
	*vars = malloc(sizeof(t_pars_vars) * 1);
	if (*vars == NULL)
		return (0);
	(*vars)->line = NULL;
	(*vars)->line_cnt = 0;
	(*vars)->ret = 1;
	(*vars)->i = 0;
	(*vars)->fd = 0;
	if (!init_task(task))
		return (0);
	return (1);
}
