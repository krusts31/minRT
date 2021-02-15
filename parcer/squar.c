#include "parcer.h"

void		ft_lstadd_back_sq(t_sq **lst, t_sq *new)
{
	t_sq *tmp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast_sq(*lst);
		tmp->next = new;
	}
}

t_sq	*ft_lstlast_sq(t_sq *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_sq	*ft_new_sq()
{
	t_sq	*tmp;

	tmp = malloc(sizeof(t_sq));
	if (tmp == NULL)
		return (NULL);
	else if (tmp)
	{
		tmp->x_cor = 0.0;
		tmp->y_cor = 0.0;
		tmp->z_cor = 0.0;
		tmp->x_norm = 0.0;
		tmp->y_norm = 0.0;
		tmp->z_norm = 0.0;
		tmp->side_size = 0.0;
		tmp->r_col = 0.0;
		tmp->g_col = 0.0;
		tmp->b_col = 0.0;
		tmp->next = NULL;
	}
	return (tmp);
}

char	ft_parc_sq(t_task **task, t_pars_vars **vars)
{
	char		hit;
	char		hit_dig;
	t_sq	*tmp;

	hit_dig = 0;
	hit = 0;
	(*vars)->i = 0;
	tmp = ft_new_sq();
	if (tmp == NULL)
		return (0);
	hit_dig = ft_sq_con(&tmp, vars, hit, hit_dig);
	ft_lstadd_back_sq(&(*task)->sq, tmp);
	if (hit_dig == 0)
		return (0);
/*	if (hit_dig != 2)
	{
		printf("Error\n2 numbers needed for A on line %ld\n", (*vars)->line_cnt);
		return (0);
	}*/
	return (1);
}

char	ft_check_sq(char hit, char hit_dig, char b_char, size_t line)
{
	if (hit > 2 && hit_dig == 1)
	{
		printf("Error\nInvalid order of elements on line: %ld\n", line);
		return (0);
	}
	if (!ft_strchr("0123456789sq-,. \n", b_char))
	{
		printf("Error\nInvalid char: \"%c\" on line: %ld\n", b_char, line);
		return (0);
	}
	if (hit_dig == (char)11)
	{
		printf("Error\nBad numbers for sq on line: %ld\n", line);
		return (0);
	}
	if (hit == (char)3)
	{
		printf("Error\nOnly one of sq alowed per line: %ld\n", line);
		return (0);
	}
	return (1);
}
