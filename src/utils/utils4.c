#include "parcer.h"
#include "minRT.h"

short	error(t_pars_vars **vars, short ret, t_task **task)
{
	if (task != NULL)
		free_task(task);
	if (vars != NULL)
		free_var(vars);
	return (ret);
}

char	free_task(t_task **task)
{
	if (*task != NULL)
	{
		free_sq(task);
		free_pl(task);
		free_cy(task);
		free_sp(task);
		free_tr(task);
		free_light(task);
		free_camera(task);
		free((*task)->Amb_light);
		free(*task);
		(*task) = NULL;
	}
	return (-1);
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
	if ((*task)->Amb_light == NULL)
		return (0);
	(*task)->Amb_light->col = new_vector_uc(0, 0, 0);
	if ((*task)->Amb_light->col == NULL)
	{
		free((*task)->Amb_light);
		return (0);
	}
	return (1);
}

char	init(t_task **task, t_pars_vars **vars)
{
	*task = malloc(sizeof(t_task) * 1);
	if (*task == NULL)
		return (0);
	*vars = malloc(sizeof(t_pars_vars) * 1);
	if (*vars == NULL)
		return error(vars, 0, task);
	(*vars)->line = NULL;
	(*vars)->line_cnt = 0;
	(*vars)->ret = 1;
	(*vars)->i = 0;
	(*vars)->fd = 0;
	if (!init_task(task))
		return error(vars, 0, task);
	return (1);
}

void	free_camera(t_task **task)
{
	t_cameraP	*tmp;

	if ((*task) != NULL)
	{
		while ((*task)->camera)
		{
			tmp = (*task)->camera->next;
			free((*task)->camera->image->upper_left);
			free((*task)->camera->image->horizontal);
			free((*task)->camera->image->vertical);
			free((*task)->camera->image);
			free((*task)->camera->norm);
			free((*task)->camera->cor);
			free((*task)->camera);
			(*task)->camera = tmp;
		}
	}
}
