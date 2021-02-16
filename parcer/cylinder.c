#include "parcer.h"

void		ft_lstadd_back_cy(t_cy **lst, t_cy *new)
{
	t_cy *tmp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast_cy(*lst);
		tmp->next = new;
	}
}

t_cy	*ft_lstlast_cy(t_cy *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_cy	*ft_new_cy()
{
	t_cy	*tmp;

	tmp = malloc(sizeof(t_cy));
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
		tmp->diameter = 0.0;
		tmp->height = 0.0;
		tmp->next = NULL;
	}
	return (tmp);
}

char	ft_parc_cy(t_task **task, t_pars_vars **vars)
{
	char		hit;
	char		hit_dig;
	t_cy	*tmp;

	hit_dig = 0;
	hit = 0;
	(*vars)->i = 0;
	tmp = ft_new_cy();
	if (tmp == NULL)
		return (0);
	hit_dig = ft_cy_con(&tmp, vars, hit, hit_dig);
	ft_lstadd_back_cy(&(*task)->cy, tmp);
	if (hit_dig != 11)
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

char	ft_check_cy(char hit, char hit_dig, char b_char)
{
	if (hit > 2 && hit_dig == 1)
		return (0);
	if (!ft_strchr("0123456789cy-,. \n", b_char))
		return (0);
	if (hit == (char)3)
		return (0);
	return (1);
}
