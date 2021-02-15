#include "parcer.h"

void		ft_lstadd_back_sp(t_sp **lst, t_sp *new)
{
	t_sp *tmp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast_sp(*lst);
		tmp->next = new;
	}
}

t_sp	*ft_lstlast_sp(t_sp *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_sp	*ft_new_sp()
{
	t_sp	*tmp;

	tmp = malloc(sizeof(t_sp));
	if (tmp == NULL)
		return (NULL);
	else if (tmp)
	{
		tmp->x_cor = 0.0;
		tmp->y_cor = 0.0;
		tmp->z_cor = 0.0;
		tmp->r_col = 0.0;
		tmp->g_col = 0.0;
		tmp->b_col = 0.0;
		tmp->diameter = 0.0;
		tmp->next = NULL;
	}
	return (tmp);
}

char	ft_parc_sp(t_task **task, t_pars_vars **vars)
{
	char		hit;
	char		hit_dig;
	t_sp		*tmp;

	hit_dig = 0;
	hit = 0;
	(*vars)->i = 0;
	tmp = ft_new_sp();
	if (tmp == NULL)
		return (0);
	hit_dig = ft_sp_con(&tmp, vars, hit, hit_dig);
	ft_lstadd_back_sp(&(*task)->sp, tmp);
	if (hit_dig == 0)
	{
		printf("HEEEEEEYYY!\n");
		return (0);
	}
/*	if (hit_dig != 2)
	{
		printf("Error\n2 numbers needed for A on line %ld\n", (*vars)->line_cnt);
		return (0);
	}*/
	return (1);
}

char	ft_check_sp(char hit, char hit_dig, char b_char, size_t line)
{
	if (hit > 2 && hit_dig == (char)1)
	{
		printf("Error\nInvalid order of elements on line: %ld\n", line);
		return (0);
	}
	if (!ft_strchr("0123456789sp-,. \n", b_char))
	{
		printf("Error\nInvalid char: \"%c\" on line: %ld\n", b_char, line);
		return (0);
	}
	if (hit_dig == (char)8)
	{
		printf("Error\nBad numbers for l on line: %ld\n", line);
		return (0);
	}
	if (hit > (char)3)
	{
		printf("Error\nOnly one of l alowed per.rt file: %ld\n", line);
		return (0);
	}
	return (1);
}
