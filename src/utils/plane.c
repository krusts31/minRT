#include "parcer.h"
#include "minRT.h"

#include <stdio.h>

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
		tmp->cor = new_vector(0, 0, 0);
		tmp->norm = new_vector(0, 0, 0);;
		tmp->col = new_vector_uc(0, 0, 0);
		tmp->next = NULL;
	}
	if (tmp->cor == NULL || tmp->norm == NULL ||
		tmp->col == NULL)
		return (NULL);
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
	if (hit_dig != 9)
	{
		printf("Error\nBad elements on line %ld\n", (*vars)->line_cnt);
		return (0);
	}
	ft_lstadd_back_pl(&(*task)->pl, tmp);
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
