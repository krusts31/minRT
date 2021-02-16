#include "parcer.h"

void		ft_lstadd_back_l(t_light **lst, t_light *new)
{
	t_light *tmp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast_l(*lst);
		tmp->next = new;
	}
}

t_light	*ft_lstlast_l(t_light *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_light	*ft_new_light()
{
	t_light	*tmp;

	tmp = malloc(sizeof(t_light));
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
		tmp->ratio = 0.0;
		tmp->next = NULL;
	}
	return (tmp);
}

char	ft_parc_light(t_task **task, t_pars_vars **vars)
{
	char		hit;
	char		hit_dig;
	t_light		*tmp;

	hit_dig = 0;
	hit = 0;
	(*vars)->i = 0;
	tmp = ft_new_light();
	if (tmp == NULL)
		return (0);
	hit_dig = ft_light_con(&tmp, vars, hit, hit_dig);
	ft_lstadd_back_l(&(*task)->light, tmp);
	if (hit_dig != 7)
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

char	ft_check_light(char hit, char hit_dig, char b_char)
{
	if (hit == 0 && hit_dig == 1)
		return (0);
	if (!ft_strchr("0123456789l-,. \n", b_char))
		return (0);
	if (hit == (char)2)
		return (0);
	return (1);
}
