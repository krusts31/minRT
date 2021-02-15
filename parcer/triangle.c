#include "parcer.h"

void		ft_lstadd_back_tr(t_tr **lst, t_tr *new)
{
	t_tr *tmp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast_tr(*lst);
		tmp->next = new;
	}
}

t_tr	*ft_lstlast_tr(t_tr *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_tr	*ft_new_tr()
{
	t_tr	*tmp;

	tmp = malloc(sizeof(t_tr));
	if (tmp == NULL)
		return (NULL);
	else if (tmp)
	{
		tmp->x_cor1 = 0.0;
		tmp->y_cor1 = 0.0;
		tmp->z_cor1 = 0.0;
		tmp->x_cor2 = 0.0;
		tmp->y_cor2 = 0.0;
		tmp->z_cor2 = 0.0;
		tmp->x_cor3 = 0.0;
		tmp->y_cor3 = 0.0;
		tmp->z_cor3 = 0.0;
		tmp->r_col = 0.0;
		tmp->g_col = 0.0;
		tmp->b_col = 0.0;
		tmp->next = NULL;
	}
	return (tmp);
}

char	ft_parc_tr(t_task **task, t_pars_vars **vars)
{
	char		hit;
	char		hit_dig;
	t_tr	*tmp;

	hit_dig = 0;
	hit = 0;
	(*vars)->i = 0;
	tmp = ft_new_tr();
	if (tmp == NULL)
		return (0);
	hit_dig = ft_tr_con(&tmp, vars, hit, hit_dig);
	ft_lstadd_back_tr(&(*task)->tr, tmp);
	if (hit_dig == 0)
		return (0);
/*	if (hit_dig != 2)
	{
		printf("Error\n2 numbers needed for A on line %ld\n", (*vars)->line_cnt);
		return (0);
	}*/
	return (1);
}

char	ft_check_tr(char hit, char hit_dig, char b_char, size_t line)
{
	if (hit > 2 && hit_dig == 1)
	{
		printf("Error\nInvalid order of elements on line: %ld\n", line);
		return (0);
	}
	if (!ft_strchr("0123456789tr-,. \n", b_char))
	{
		printf("Error\nInvalid char: \"%c\" on line: %ld\n", b_char, line);
		return (0);
	}
	if (hit_dig == (char)13)
	{
		printf("Error\nBad numbers for tr on line: %ld\n", line);
		return (0);
	}
	if (hit == (char)3)
	{
		printf("Error\nOnly one of tr alowed per line: %ld\n", line);
		return (0);
	}
	return (1);
}
