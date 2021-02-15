#include "parcer.h"
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <float.h>
#include <limits.h>

char	ft_parce_args2(t_task **task, t_pars_vars **vars)
{
	if (ft_strchr((*vars)->line, 'l') && !ft_strchr((*vars)->line, 'p'))
	{
		if (!ft_parc_light(task, vars))
		{
			printf("l ERROR\n");
			return (error(vars, 0, task));
		}
	}
	if (ft_strchr((*vars)->line, 's') && ft_strchr((*vars)->line, 'p'))
	{
		if (!ft_parc_sp(task, vars))
		{
			printf("sp ERROR\n");
			return (error(vars, 0, task));
		}
	}
	if (ft_strchr((*vars)->line, 'l') && ft_strchr((*vars)->line, 'p'))
	{
		if (!ft_parc_pl(task, vars))
		{
			printf("lp ERROR\n");
			return (error(vars, 0, task));
		}
	}
	if (ft_strchr((*vars)->line, 's') && ft_strchr((*vars)->line, 'q'))
	{
		printf("this line %s\n", (*vars)->line);
		if (!ft_parc_sq(task, vars))
		{
			printf("sq ERROR\n");
			return (error(vars, 0, task));
		}
	}
	if (ft_strchr((*vars)->line, 't') && ft_strchr((*vars)->line, 'r'))
	{
		if (!ft_parc_tr(task, vars))
		{
			printf("tr ERROR\n");
			return (error(vars, 0, task));
		}
	}
	if (ft_strchr((*vars)->line, 'c') && ft_strchr((*vars)->line, 'y'))
	{
		if (!ft_parc_cy(task, vars))
		{
			printf("cy ERROR\n");
			return (error(vars, 0, task));
		}
	}
	(*vars)->line_cnt++;
	free((*vars)->line);
	(*vars)->line = NULL;
	return (1);
}
int	ft_parce_args(t_task **task, t_pars_vars **vars)
{
	while ((*vars)->ret)
	{
		(*vars)->ret = get_next_line((*vars)->fd, &(*vars)->line);
		if ((*vars)->ret == -1)
			return (error(vars, 0, task));
		if (ft_strchr((*vars)->line, 'R'))
		{
			if (!ft_parc_res(task, vars))
				return (error(vars, 0, task));
		}
		if (ft_strchr((*vars)->line, 'A'))
		{
			if (!ft_parc_Amb(task, vars))
				return (error(vars, 0, task));
		}
		if (ft_strchr((*vars)->line, 'c') && !ft_strchr((*vars)->line, 'y'))
		{
			if (!ft_parc_camera(task, vars))
				return (error(vars, 0, task));
		}
		if (!ft_parce_args2(task, vars))
			return (error(vars, 0, task));
	}
	return (1);
}

char	parce_argv_1(char *argv)
{
	size_t	index;

	index = 0;
	while (argv[index] != '\0')
	{
		if (index == INT_MAX)
			return (0);
		index++;
	}
	if (index < 2)
		return (0);
	if ((argv[index -1] != 't') || (argv[index - 2] != 'r') ||
		(argv[index - 3] != '.'))
		return (0);
	return (1);
}
int	main(int argc, char **argv)
{
	t_pars_vars	*vars;
	t_task		*task;
	int	index;

	if (argc == 1)
		return (argc_error("Error: No .rt file\n"));
	if (argc > 3)
		return (argc_error("Error: To many arguments.\n"));
	if (!parce_argv_1(argv[1]))
	{
		printf("Error\nBad name for file!\n");
		return (0);
	}
	if (!init(&task, &vars))
		return (error(&vars, -1, &task));
	vars->fd = open(argv[1], O_RDONLY);
	if (vars->fd == -1)
	{
		printf("Error: %s\n", strerror(errno));
		return (error(&vars, -1, &task));
	}	
	if (!ft_parce_args(&task, &vars))
		return (-1);
	else
	{
			printf("************************************************************\n");
			printf("******************RESULUTIO*********************************\n");
			printf("************************************************************\n");
		printf("this is X_res %zu\n", task->X_res);
		printf("this is Y_res %zu\n", task->Y_res);
		if (task->Amb_light)
		{
			printf("************************************************************\n");
			printf("******************AMB_light*********************************\n");
			printf("************************************************************\n");
			printf("this is rartio %f\n", task->Amb_light->ratio);
			printf("this is r %d\n", task->Amb_light->r_col);
			printf("this is g %d\n", task->Amb_light->g_col);
			printf("this is b %d\n", task->Amb_light->b_col);
		}
		else
			printf("Amb failed\n");
		if (task->camera)
		{
			printf("************************************************************\n");
			printf("******************CAMERA************************************\n");
			printf("************************************************************\n");
			index = 0;
			while (task->camera != NULL)
			{
				printf("this is x_cor %f for camera %d\n", task->camera->x_cor, index);
				printf("this is y_cor %f for camera %d\n", task->camera->y_cor, index);
				printf("this is z_cor %f for camera %d\n", task->camera->z_cor, index);
				printf("this is x_norm %f for camera %d\n", task->camera->x_norm, index);
				printf("this is y_norm %f for camera %d\n", task->camera->y_norm, index);
				printf("this is z_norm %f for camera %d\n", task->camera->z_norm, index);
				printf("this is FOV %f for camera %d\n", task->camera->FOV, index);
				task->camera = task->camera->next;
				index++;
			}
		}
		else
			printf("cam failed\n");
		if (task->light)
		{
			printf("************************************************************\n");
			printf("******************LIGHT*************************************\n");
			printf("************************************************************\n");
			index = 0;
			while (task->light != NULL)
			{
				printf("this is x_cor %f for light %d\n", task->light->x_cor, index);
				printf("this is y_cor %f for light %d\n", task->light->y_cor, index);
				printf("this is z_cor %f for light %d\n", task->light->z_cor, index);
				printf("this is x_norm %d for light %d\n", task->light->r_col, index);
				printf("this is y_norm %d for light %d\n", task->light->g_col, index);
				printf("this is z_norm %d for light %d\n", task->light->b_col, index);
				printf("this is ratio %f for light %d\n", task->light->ratio, index);
				task->light = task->light->next;
				index++;
			}
		}
		else
			printf("light failed\n");
		if (task->sp)
		{
			printf("************************************************************\n");
			printf("******************SQHIER************************************\n");
			printf("************************************************************\n");
			index = 0;
			while (task->sp != NULL)
			{
				printf("this is x_cor %f for sp %d\n", task->sp->x_cor, index);
				printf("this is y_cor %f for sp %d\n", task->sp->y_cor, index);
				printf("this is z_cor %f for sp %d\n", task->sp->z_cor, index);
				printf("this is x_norm %d for sp %d\n", task->sp->r_col, index);
				printf("this is y_norm %d for sp %d\n", task->sp->g_col, index);
				printf("this is z_norm %d for sp %d\n", task->sp->b_col, index);
				printf("this is ratio %f for sp %d\n", task->sp->diameter, index);
				task->sp = task->sp->next;
				index++;
			}
		}
		else
			printf("cy failed\n");
		if (task->pl)
		{
			printf("************************************************************\n");
			printf("******************PLANE*************************************\n");
			printf("************************************************************\n");
			index = 0;
			while (task->pl != NULL)
			{
				printf("this is x_cor %f for pl %d\n", task->pl->x_cor, index);
				printf("this is y_cor %f for pl %d\n", task->pl->y_cor, index);
				printf("this is z_cor %f for pl %d\n", task->pl->z_cor, index);
				printf("this is x_cor %f for pl %d\n", task->pl->x_norm, index);
				printf("this is y_cor %f for pl %d\n", task->pl->y_norm, index);
				printf("this is z_cor %f for pl %d\n", task->pl->z_norm, index);
				printf("this is x_norm %d for pl %d\n", task->pl->r_col, index);
				printf("this is y_norm %d for pl %d\n", task->pl->g_col, index);
				printf("this is z_norm %d for pl %d\n", task->pl->b_col, index);
				task->pl = task->pl->next;
				index++;
			}
		}
		else
			printf("pl failed\n");
		if (task->sq)
		{
			printf("************************************************************\n");
			printf("******************SQUARE************************************\n");
			printf("************************************************************\n");
			index = 0;
			while (task->sq != NULL)
			{
				printf("this is x_cor %f for sq %d\n", task->sq->x_cor, index);
				printf("this is y_cor %f for sq %d\n", task->sq->y_cor, index);
				printf("this is z_cor %f for sq %d\n", task->sq->z_cor, index);
				printf("this is x_cor %f for sq %d\n", task->sq->x_norm, index);
				printf("this is y_cor %f for sq %d\n", task->sq->y_norm, index);
				printf("this is z_cor %f for sq %d\n", task->sq->z_norm, index);
				printf("this is x_norm %d for sq %d\n", task->sq->r_col, index);
				printf("this is y_norm %d for sq %d\n", task->sq->g_col, index);
				printf("this is z_norm %d for sq %d\n", task->sq->b_col, index);
				printf("this is side_size %f for sq %d\n", task->sq->side_size, index);
				task->sq = task->sq->next;
				index++;
			}
		}
		else
			printf("sq failed\n");
		if (task->cy)
		{
			index = 0;
			printf("************************************************************\n");
			printf("******************CYLINDER**********************************\n");
			printf("************************************************************\n");
			while (task->cy != NULL)
			{
				printf("this is x_cor %f for cy %d\n", task->cy->x_cor, index);
				printf("this is y_cor %f for cy %d\n", task->cy->y_cor, index);
				printf("this is z_cor %f for cy %d\n", task->cy->z_cor, index);
				printf("this is x_norm %f for cy %d\n", task->cy->x_norm, index);
				printf("this is y_norm %f for cy %d\n", task->cy->y_norm, index);
				printf("this is z_norm %f for cy %d\n", task->cy->z_norm, index);
				printf("this is diameter %f for cy %d\n", task->cy->diameter, index);
				printf("this is height %f for cy %d\n", task->cy->height, index);
				printf("this is r  %d for cy %d\n", task->cy->r_col, index);
				printf("this is g  %d for cy %d\n", task->cy->g_col, index);
				printf("this is b  %d for cy %d\n", task->cy->b_col, index);
				task->cy = task->cy->next;
				index++;
			}
		}
		else
			printf("cy failed\n");
		if (task->tr)
		{
			printf("************************************************************\n");
			printf("******************TRINAGLE**********************************\n");
			printf("************************************************************\n");
			index = 0;
			while (task->tr != NULL)
			{
				printf("this is x_cor1 %f for tr %d\n", task->tr->x_cor1, index);
				printf("this is y_cor1 %f for tr %d\n", task->tr->y_cor1, index);
				printf("this is z_cor1 %f for tr %d\n", task->tr->z_cor1, index);
				printf("this is x_cor2 %f for tr %d\n", task->tr->x_cor2, index);
				printf("this is y_cor2 %f for tr %d\n", task->tr->y_cor2, index);
				printf("this is z_cor2 %f for tr %d\n", task->tr->z_cor2, index);
				printf("this is x_cor3 %f for tr %d\n", task->tr->x_cor3, index);
				printf("this is y_cor3 %f for tr %d\n", task->tr->y_cor3, index);
				printf("this is z_cor3 %f for tr %d\n", task->tr->z_cor3, index);
				printf("this is x_norm %d for tr %d\n", task->tr->r_col, index);
				printf("this is y_norm %d for tr %d\n", task->tr->g_col, index);
				printf("this is z_norm %d for tr %d\n", task->tr->b_col, index);
				task->tr = task->tr->next;
				index++;
			}
		}
		else
			printf("tr failed\n");
	}
//	if (argc == 3)
	//	ft_get_flag();
//	check_task();
	
	return (0);
}
