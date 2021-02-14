#include "parcer.h"
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <float.h>
//if (!ft_strchr("-0123456789.,RAclpsqcytr \n", (*vars)->line[i]))


/*
size_t	ft_isfloat(char fl)
{
	return (ft_isdigit(fl) || fl == '.' || fl == '-');
}

float	ft_atof_con(const char *nptr, float res, float negative, float max)
{
	float	add;
	float	nr;

	nr = 1.0;
	add = 0.0;
	nptr++;
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		add = (add * 10 + (*nptr - 48));
		if (max < 1 && negative < 0)
			return (0);
		else if (max < 1 && negative > 0)
			return (-1);
		max = max / 10;
		nptr++;
		nr *= 10.0;
	}
	add = add / nr;
	return ((res + add) * negative);
}

float	ft_check_float(const char *nptr, float res, float max, float negative)
{
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		res = res * 10.0 + (*nptr - 48.0);
		if (max < 1.0 && negative < 0.0)
			return (0.0);
		else if (max < 1.0 && negative > 0.0)
			return (-1.0);
		max = max / 10.0;
		nptr++;
	}
	return (res);
}

float	ft_atof(const char *nptr)
{
	float			res;
	float			negative;
	float			max;

	negative = 1.0;
	res = 0.0;
	max = FLT_MAX;
	while (*nptr && (*nptr == ' ' || *nptr == '\n' || *nptr == '\t' ||
			*nptr == '\v' || *nptr == '\f' || *nptr == '\r'))
		nptr++;
	negative = 1.0;
	if (*nptr == '-')
		negative = -1.0;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	res = ft_check_float(nptr, res, max, negative);
	while (*nptr && *nptr >= '0' && *nptr <= '9')
		nptr++;
	if (*nptr == '.')
		return (ft_atof_con(nptr, res, negative, max));
	return ((int)res * negative);
}
*/
int	argc_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (-1);
}
size_t	ft_size_t_len(size_t nr)
{
	int	ret;

	ret = 0;
	if (nr == 0)
		return (1);
	if (nr < 0)
	{
		nr = -nr;
		ret++;
	}
	while (nr >= 1)
	{
		ret++;
		nr = nr / 10;
	}
	return (ret);
}

void	free_sq(t_task **task)
{
	int	index;

	index = 0;
	if ((*task)->sq != NULL)
	{
		while ((*task)->sq[index])
		{
			free((*task)->sq[index]);
			index++;
		}
		free((*task)->sq);
	}
}

void	free_pl(t_task **task)
{
	int	index;

	index = 0;
	if ((*task)->pl != NULL)
	{
		while ((*task)->pl[index])
		{
			free((*task)->pl[index]);
			index++;
		}
		free((*task)->pl);
	}
}

void	free_cy(t_task **task)
{
	int	index;

	index = 0;
	if ((*task)->cy != NULL)
	{
		while ((*task)->cy[index])
		{
			free((*task)->cy[index]);
			index++;
		}
		free((*task)->cy);
	}
}

void	free_sp(t_task **task)
{
	int	index;

	index = 0;
	if ((*task)->sp != NULL)
	{
		while ((*task)->sp[index])
		{
			free((*task)->sp[index]);
			index++;
		}
		free((*task)->sp);
	}
}

void	free_tr(t_task **task)
{
	int	index;

	index = 0;
	if ((*task)->tr != NULL)
	{
		while ((*task)->tr[index])
		{
			free((*task)->tr[index]);
			index++;
		}
		free((*task)->tr);
	}
}

void	free_light(t_task **task)
{
	int	index;

	index = 0;
	if ((*task)->light != NULL)
	{
		while ((*task)->light[index])
		{
			free((*task)->light[index]);
			index++;
		}
		free((*task)->light);
	}
}

void	error_con(t_pars_vars **vars, t_task **task)
{
	if (task != NULL)
	{
		free_sq(task);
		free_pl(task);
		free_cy(task);
		free_sp(task);
		free_tr(task);
		free_light(task);
		free((*task)->Amb_light);
		free(*task);
	}
	if (vars != NULL)
	{
		free((*vars)->line);
		free(*vars);
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
	(*task)->sq = malloc(sizeof(t_sq) * 1);
	(*task)->pl = malloc(sizeof(t_pl) * 1);
	(*task)->cy = malloc(sizeof(t_cy) * 1);
	(*task)->sp = malloc(sizeof(t_sp) * 1);
	(*task)->tr = malloc(sizeof(t_tr) * 1);
	(*task)->light = malloc(sizeof(t_light) * 1);
	(*task)->Amb_light = malloc(sizeof(t_amb_light) * 1);
	(*task)->camera = malloc(sizeof(t_camera) * 1);
	if ((*task)->sq == NULL || (*task)->pl == NULL || (*task)->cy == NULL
		|| (*task)->sp == NULL ||(*task)->tr == NULL || (*task)->camera == NULL ||
		(*task)->light == NULL || (*task)->Amb_light == NULL)
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

char	ft_check_res(char hit, char hit_dig, char b_char, size_t line)
{
	if (hit == 0 && hit_dig == 1)
	{
		printf("Error\nInvalid order of elements %ld\n", line);
		return (0);
	}
	if (!ft_strchr("0123456789R \n", b_char))
	{
		printf("Error\nInvalid char: \"%c\" on line: %ld\n", b_char, line);
		return (0);
	}
	if (hit_dig == (char)3)
	{
		printf("Error\nBad numbers for R %ld\n", line);
		return (0);
	}
	if (hit == (char)2)
	{
		printf("Error\nOnly one of R alowed per.rt file: %ld\n", line);
		return (0);
	}
	return (1);
}

char	ft_res_con(t_task **task, t_pars_vars **vars, char hit, char hit_dig)
{
	while ((*vars)->line[(*vars)->i])
	{
		if ((*vars)->line[(*vars)->i] == 'R')
			hit++;
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
		if (!ft_check_res(hit, hit_dig, (*vars)->line[(*vars)->i], (*vars)->line_cnt))
			return (0);
	}
	return (hit_dig);
}

char	ft_parc_res(t_task **task, t_pars_vars **vars)
{
	char	hit;
	char	hit_dig;

	hit_dig = 0;
	hit = 0;
	(*vars)->i = 0;
	hit_dig = ft_res_con(task, vars, hit, hit_dig);
	if (hit_dig != 2)
	{
		printf("Error\n2 numbers needed for R on line %ld\n", (*vars)->line_cnt);
		return (0);
	}
	return (1);
}

char	ft_check_Amb(char hit, char hit_dig, char b_char, size_t line)
{
	if (hit == 0 && hit_dig == 1)
	{
		printf("Error\nInvalid order of elements on line: %ld\n", line);
		return (0);
	}
	if (!ft_strchr("0123456789A,. \n", b_char))
	{
		printf("Error\nInvalid char: \"%c\" on line: %ld\n", b_char, line);
		return (0);
	}
	if (hit_dig == (char)5)
	{
		printf("Error\nBad numbers for A on line: %ld\n", line);
		return (0);
	}
	if (hit == (char)2)
	{
		printf("Error\nOnly one of A alowed per.rt file: %ld\n", line);
		return (0);
	}
	return (1);
}

char	ft_Amb_con2(t_task **task, t_pars_vars **vars, char hit_dig)
{
	size_t	nr;

	if (hit_dig == 3)
	{
		nr = ft_atoi((*vars)->line + (*vars)->i);
		if (nr > 255)
			return (0);
		(*task)->Amb_light->g_col = nr;
		(*vars)->i += ft_intlen((*task)->Amb_light->g_col);
	}
	if (hit_dig == 4)
	{
		nr = ft_atoi((*vars)->line + (*vars)->i);
		if (nr > 255)
			return (0);
		(*task)->Amb_light->b_col = nr;
		(*vars)->i += ft_intlen((*task)->Amb_light->b_col);
	}
	return (1);
}

char	ft_Amb_con1(t_task **task, t_pars_vars **vars, char hit_dig)
{
	size_t	nr;
	char	check;

	check = 0;
	if (hit_dig == 1)
	{
		(*task)->Amb_light->ratio = ft_atof((*vars)->line + (*vars)->i);
		if ((*task)->Amb_light->ratio < 0.0 &&
			 (*task)->Amb_light->ratio > 1.0)
			return (0);
		while (ft_isfloat((*vars)->line[(*vars)->i]))
		{
			if (((*vars)->line[(*vars)->i]) == '.')
				check++;
			if (check == 2)
				return (0);
			(*vars)->i++;
		}
	}
	if (ft_strchr(((*vars)->line + (*vars)->i), '.'))
		return (0);
	if (hit_dig == 2)
	{
		nr = ft_atoi((*vars)->line + (*vars)->i);
		if (nr > 255)
			return (0);
		(*task)->Amb_light->r_col = nr;
		(*vars)->i += ft_intlen((*task)->Amb_light->r_col);
	}
	return (ft_Amb_con2(task, vars, hit_dig));
}

char	ft_check_Amb2(char hit_dig, t_pars_vars **vars, char comma)
{
	if (hit_dig >= 2 && ((*vars)->line[(*vars)->i] == ','))
		comma++;
	if ((hit_dig <= 1 && ((*vars)->line[(*vars)->i] == ',')) || comma == 3)
	{
		printf("Error\nIncorect commas on line %ld\n", (*vars)->line_cnt);
		return (-1);
	}
	return (comma);
}

char	ft_Amb_con(t_task **task, t_pars_vars **vars, char hit, char hit_dig)
{
	char	comma;

	comma = 0;
	while ((*vars)->line[(*vars)->i])
	{
		comma = ft_check_Amb2(hit_dig, vars, comma);
		if (comma == -1 || comma == 3)
			return (0);
		if ((*vars)->line[(*vars)->i] == 'A')
			hit++;
		if (ft_isfloat((*vars)->line[(*vars)->i]))
		{
			hit_dig++;
			if(!ft_Amb_con1(task, vars, hit_dig))
			{
				printf("Error\nBad values for element on line: %ld\n", (*vars)->line_cnt);
				return (0);
			}
		}
		else
			(*vars)->i++;
		if (!ft_check_Amb(hit, hit_dig, (*vars)->line[(*vars)->i], (*vars)->line_cnt))
			return (0);
	}
	return (hit_dig);
}

char	ft_parc_Amb(t_task **task, t_pars_vars **vars)
{
	char	hit;
	char	hit_dig;

	hit_dig = 0;
	hit = 0;
	(*vars)->i = 0;
	hit_dig = ft_Amb_con(task, vars, hit, hit_dig);
	if (hit_dig == 0)
		return (0);
/*	if (hit_dig != 2)
	{
		printf("Error\n2 numbers needed for A on line %ld\n", (*vars)->line_cnt);
		return (0);
	}*/
	return (1);
}
/*
char	ft_check_camera(char hit, char hit_dig, char b_char, size_t line)
{
	if (hit == 0 && hit_dig == 1)
	{
		printf("Error\nInvalid order of elements on line: %ld\n", line);
		return (0);
	}
	if (!ft_strchr("0123456789c-,. \n", b_char))
	{
		printf("Error\nInvalid char: \"%c\" on line: %ld\n", b_char, line);
		return (0);
	}
	if (hit_dig == (char)8)
	{
		printf("Error\nBad numbers for c on line: %ld\n", line);
		return (0);
	}
	if (hit == (char)2)
	{
		printf("Error\nOnly one of c alowed per.rt file: %ld\n", line);
		return (0);
	}
	return (1);
}

char	ft_camera_con3(t_camera **camera, t_pars_vars **vars, char hit_dig, char check)
{
	if (hit_dig == 6)
	{
		(*camera)->z_norm = ft_atof((*vars)->line + (*vars)->i);
		if ((*camera)->z_norm < -1.0 &&
			 (*camera)->z_norm > 1.0)
			return (0);
		while (ft_isfloat((*vars)->line[(*vars)->i]))
		{
			if (((*vars)->line[(*vars)->i]) == '.')
				check++;
			if (check == 2)
				return (0);
			(*vars)->i++;
		}
	}
	if (hit_dig == 7)
	{
		(*camera)->FOV = ft_atof((*vars)->line + (*vars)->i);
		if ((*camera)->FOV < -180.0 &&
			 (*camera)->FOV > 180.0)
			return (0);
		while (ft_isfloat((*vars)->line[(*vars)->i]))
		{
			if (((*vars)->line[(*vars)->i]) == '.')
				check++;
			if (check == 2)
				return (0);
			(*vars)->i++;
		}
	}
	return (1);
}
char	ft_camera_con2(t_camera **camera, t_pars_vars **vars, char hit_dig, char check)
{
	if (hit_dig == 4)
	{
		(*camera)->x_norm = ft_atof((*vars)->line + (*vars)->i);
		if ((*camera)->x_norm < -1.0 &&
			 (*camera)->x_norm > 1.0)
			return (0);
		while (ft_isfloat((*vars)->line[(*vars)->i]))
		{
			if (((*vars)->line[(*vars)->i]) == '.')
				check++;
			if (check == 2)
				return (0);
			(*vars)->i++;
		}
	}
	if (hit_dig == 5)
	{
		(*camera)->y_norm = ft_atof((*vars)->line + (*vars)->i);
		if ((*camera)->y_norm < -1.0 &&
			 (*camera)->y_norm > 1.0)
			return (0);
		while (ft_isfloat((*vars)->line[(*vars)->i]))
		{
			if (((*vars)->line[(*vars)->i]) == '.')
				check++;
			if (check == 2)
				return (0);
			(*vars)->i++;
		}
	}
	return (ft_camera_con3(camera, vars, hit_dig, check));
}

char	ft_camera_con1(t_camera **camera, t_pars_vars **vars, char hit_dig)
{
	char	check;

	check = 0;
	if (hit_dig == 1)
	{
		(*camera)->x_cor = ft_atof((*vars)->line + (*vars)->i);
		while (ft_isfloat((*vars)->line[(*vars)->i]))
		{
			if (((*vars)->line[(*vars)->i]) == '.')
				check++;
			if (check == 2)
				return (0);
			(*vars)->i++;
		}
	}
	if (hit_dig == 2)
	{
		(*camera)->y_cor = ft_atof((*vars)->line + (*vars)->i);
		while (ft_isfloat((*vars)->line[(*vars)->i]))
		{
			if (((*vars)->line[(*vars)->i]) == '.')
				check++;
			if (check == 2)
				return (0);
			(*vars)->i++;
		}
	}
	if (hit_dig == 3)
	{
		(*camera)->z_cor = ft_atof((*vars)->line + (*vars)->i);
		while (ft_isfloat((*vars)->line[(*vars)->i]))
		{
			if (((*vars)->line[(*vars)->i]) == '.')
				check++;
			if (check == 2)
				return (0);
			(*vars)->i++;
		}
	}
	return (ft_camera_con2(camera, vars, hit_dig, check));
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

char	ft_camera_con(t_camera **camera, t_pars_vars **vars, char hit, char hit_dig)
{
	char	comma;

	comma = 0;
	while ((*vars)->line[(*vars)->i])
	{
		if ((*vars)->line[(*vars)->i] == ',')
			comma = ft_check_camera2(hit_dig, vars, comma);
		if ((comma == -1 || comma == 5)  || (hit_dig == 1 && comma == 0))
		{
			printf("Error\nIncorect commas on line %ld\n", (*vars)->line_cnt);
			return (0);
		}
		if ((*vars)->line[(*vars)->i] == 'c')
			hit++;
		if (ft_isfloat((*vars)->line[(*vars)->i]))
		{
			hit_dig++;
			if(!ft_camera_con1(camera, vars, hit_dig))
			{
				printf("Error\nBad values for element on line: %ld\n", (*vars)->line_cnt);
				return (0);
			}
		}
		else
			(*vars)->i++;
		if (!ft_check_camera(hit, hit_dig, (*vars)->line[(*vars)->i], (*vars)->line_cnt))
			return (0);
	}
	return (hit_dig);
}

char	ft_parc_camera(t_task **task, t_pars_vars **vars)
{
	char		hit;
	char		hit_dig;
	t_camera	*tmp;

	hit_dig = 0;
	hit = 0;
	(*vars)->i = 0;
	tmp = ft_new_camera();
	if (tmp == NULL)
		return (0);
	hit_dig = ft_camera_con(&tmp, vars, hit, hit_dig);
	ft_lstadd_back_c((*task)->camera, tmp);
	if (hit_dig == 0)
		return (0);
	if (hit_dig != 2)
	{
		printf("Error\n2 numbers needed for A on line %ld\n", (*vars)->line_cnt);
		return (0);
	}
	return (1);
}
*/
char	ft_parce_args2(t_task **task, t_pars_vars **vars)
{
	/*
		if (ft_strnstr("l ", line, ft_strlen(line)) && !ft_strnstr("pl ", line, ft_strlen(line)))
			
		if (ft_strnstr("pl ", line, ft_strlen(line)))
			
		if (ft_strnstr("sq ", line, ft_strlen(line)))
			
		if (ft_strnstr("tr ", line, ft_strlen(line)))
			
		if (ft_strnstr("cy ", line, ft_strlen(line)))
			;
*/
	(void)task;
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
			return (error(vars, -1, task));
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
		ft_parce_args2(task, vars);
	}
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
	if (!init(&task, &vars))
		return (error(&vars, -1, &task));
	vars->fd = open(argv[1], O_RDONLY);
	if (vars->fd == -1)
		printf("Error: %s\n", strerror(errno));
	if (!ft_parce_args(&task, &vars))
		return (-1);
	else
	{
		index = 0;
		printf("this is X_res %zu\n", task->X_res);
		printf("this is Y_res %zu\n", task->Y_res);
		printf("this is rartio %f\n", task->Amb_light->ratio);
		printf("this is r %d\n", task->Amb_light->r_col);
		printf("this is g %d\n", task->Amb_light->g_col);
		printf("this is b %d\n", task->Amb_light->b_col);
		while (task->camera[index])
		{
			printf("this is x_cor %f for camera %d\n", task->camera[index]->x_cor, index);
			printf("this is y_cor %f for camera %d\n", task->camera[index]->y_cor, index);
			printf("this is z_cor %f for camera %d\n", task->camera[index]->z_cor, index);
			printf("this is x_norm %f for camera %d\n", task->camera[index]->x_norm, index);
			printf("this is y_norm %f for camera %d\n", task->camera[index]->y_norm, index);
			printf("this is z_norm %f for camera %d\n", task->camera[index]->z_norm, index);
			printf("this is FOV %f for camera %d\n", task->camera[index]->FOV, index);
			index++;
		}
	}
//	if (argc == 3)
	//	ft_get_flag();
//	check_task();
	
	return (0);
}
