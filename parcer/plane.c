#include "parcer.h"

void		ft_lstadd_back_pl(t_pl **lst, t_pl *new)
{
	t_pl *tmp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast_pl(*lst);
		tmp->next = new;
	}
}

t_pl	*ft_lstlast_pl(t_pl *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_pl	*ft_new_pl()
{
	t_pl	*tmp;

	tmp = malloc(sizeof(t_pl));
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
		tmp->r_col = 0.0;
		tmp->g_col = 0.0;
		tmp->b_col = 0.0;
		tmp->next = NULL;
	}
	return (tmp);
}

char	ft_parc_pl(t_task **task, t_pars_vars **vars)
{
	char		hit;
	char		hit_dig;
	t_pl	*tmp;

	hit_dig = 0;
	hit = 0;
	(*vars)->i = 0;
	tmp = ft_new_pl();
	if (tmp == NULL)
		return (0);
	hit_dig = ft_pl_con(&tmp, vars, hit, hit_dig);
	ft_lstadd_back_pl(&(*task)->pl, tmp);
	if (hit_dig != 9)
	{
		printf("Error\nBad elements on line %ld\n", (*vars)->line_cnt);
		return (0);
	}
/*	if (hit_dig != 2)
	{
		printf("Error\n2 numbers needed for A on line %ld\n", (*vars)->line_cnt);
		return (0);
	}*/
	return (1);
}

char	ft_check_pl(char hit, char hit_dig, char b_char)
{
	if (hit > 2 && hit_dig == 1)
		return (0);
	if (!ft_strchr("0123456789pl-,. \n", b_char))
		return (0);
	if (hit == (char)3)
		return (0);
	return (1);
}
