#include "parcer.h"
#include "minRT.h"
#include "get_next_line.h"
#include "error.h"

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

void	ft_parce_args2(t_task **task, t_pars_vars **vars)
{
	if (ft_strchr((*vars)->line, 'l') && !ft_strchr((*vars)->line, 'p'))
		ft_parc_light(task, vars);
	if (ft_strchr((*vars)->line, 's') && ft_strchr((*vars)->line, 'p'))
		ft_parc_sp(task, vars);
	if (ft_strchr((*vars)->line, 'l') && ft_strchr((*vars)->line, 'p'))
		ft_parc_pl(task, vars);
	if (ft_strchr((*vars)->line, 's') && ft_strchr((*vars)->line, 'q'))
		ft_parc_sq(task, vars);
	if (ft_strchr((*vars)->line, 't') && ft_strchr((*vars)->line, 'r'))
		ft_parc_tr(task, vars);
	if (ft_strchr((*vars)->line, 'c') && ft_strchr((*vars)->line, 'y'))
		ft_parc_cy(task, vars);
	(*vars)->line_cnt++;
	free((*vars)->line);
	(*vars)->line = NULL;
}

int	ft_parce_args(t_task **task, t_pars_vars **vars)
{
	while ((*vars)->ret)
	{
		(*vars)->ret = get_next_line((*vars)->fd, &(*vars)->line);
		if ((*vars)->ret == -1)
			exit(!printf(ERROR_6));
		if (ft_strchr((*vars)->line, 'R'))
			ft_parc_res(task, vars);
		if (ft_strchr((*vars)->line, 'A'))
			ft_parc_Amb(task, vars);
		if (ft_strchr((*vars)->line, 'c') && !ft_strchr((*vars)->line, 'y'))
			ft_parc_camera(task, vars);
		ft_parce_args2(task, vars);
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
	if ((argv[index - 1] != 't') || (argv[index - 2] != 'r'))
		return (0);
	if (argv[index - 3] != '.')
		return (0);
	return (1);
}

int	new_task(int argc, char **argv, t_task **task)
{
	t_pars_vars	*vars;

	if (argc == 1)
		exit(!printf(ERROR_1));
	if (argc > 3)
		exit(!printf(ERROR_2));
	if (!parce_argv_1(argv[1]))
		exit(!printf(ERROR_3));
	
	init(task, &vars);
	vars->fd = open(argv[1], O_RDONLY);
	if (vars->fd == -1)
		exit(!printf("Error: %s\n", strerror(errno)));
	ft_parce_args(task, &vars);
	free_var(&vars);
	return (1);
}
