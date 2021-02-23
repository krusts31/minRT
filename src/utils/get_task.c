#include "parcer.h"
#include "minRT.h"
#include "get_next_line.h"

#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <limits.h>
#include <stdio.h>

void	free_var(t_pars_vars **vars)
{
	if (vars != NULL)
	{
		if (*vars != NULL)
		{
			free((*vars)->line);
			free(*vars); 
			(*vars) = NULL;
		}
	}
}

char	ft_parce_args2(t_task **task, t_pars_vars **vars)
{
	if (ft_strchr((*vars)->line, 'l') && !ft_strchr((*vars)->line, 'p'))
	{
		if (!ft_parc_light(task, vars))
			return (error(vars, 0, task));
	}
	if (ft_strchr((*vars)->line, 's') && ft_strchr((*vars)->line, 'p'))
	{
		if (!ft_parc_sp(task, vars))
			return (error(vars, 0, task));
	}
	if (ft_strchr((*vars)->line, 'l') && ft_strchr((*vars)->line, 'p'))
	{
		if (!ft_parc_pl(task, vars))
			return (error(vars, 0, task));
	}
	if (ft_strchr((*vars)->line, 's') && ft_strchr((*vars)->line, 'q'))
	{
		if (!ft_parc_sq(task, vars))
			return (error(vars, 0, task));
	}
	if (ft_strchr((*vars)->line, 't') && ft_strchr((*vars)->line, 'r'))
	{
		if (!ft_parc_tr(task, vars))
			return (error(vars, 0, task));
	}
	if (ft_strchr((*vars)->line, 'c') && ft_strchr((*vars)->line, 'y'))
	{
		if (!ft_parc_cy(task, vars))
			return (error(vars, 0, task));
	}
	(*vars)->line_cnt++;
	free((*vars)->line);
	(*vars)->line = NULL;
	printf("this is line_cnt %ld\n",(*vars)->line_cnt);
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

int	new_task(int argc, char **argv, t_task **task)
{
	t_pars_vars	*vars;
//	t_task		*task;

	if (argc == 1)
	{
		argc_error("Error: No .rt file\n");
		return (0);
	}
	if (argc > 3)
	{
		argc_error("Error: To many arguments.\n");
		return (0);
	}
	if (!parce_argv_1(argv[1]))
	{
		printf("Error\nBad name for file!\n");
		return (0);
	}
	if (!init(task, &vars))
	{
		printf("Error\nWTF!\n");
		error(&vars, -1, task);
		return (0);
	}
	vars->fd = open(argv[1], O_RDONLY);
	if (vars->fd == -1)
	{
		printf("Error: %s\n", strerror(errno));
		error(&vars, -1, task);
		return (0);
	}	
	if (!ft_parce_args(task, &vars))
	{
		printf("Error\nFailed to parce args!\n");
		return (0);
	}
//	else
//		print_res(*task);
	free_var(&vars);
	return (1);
//	return (task);
}
