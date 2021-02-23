#include "parcer.h"
#include "minRT.h"

#include <stdio.h>

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
		tmp->cor1 = new_vector(0, 0, 0);
		tmp->cor2 = new_vector(0, 0, 0);
		tmp->cor3 = new_vector(0, 0, 0);
		tmp->col = new_vector_uc(0, 0, 0);
		tmp->next = NULL;
	}
	if (tmp->cor1 == NULL || tmp->cor2 == NULL || tmp->cor3 == NULL ||
		tmp->col == NULL)
		return (NULL);
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
	if (hit_dig != 12)
	{
		printf("Error\nBad elements on line %ld\n", (*vars)->line_cnt);	
		return (0);
	}
	ft_lstadd_back_tr(&(*task)->tr, tmp);
	return (1);
}

char	ft_check_tr(char hit, char hit_dig, char b_char)
{
	if (hit > 2 && hit_dig == 1)
		return (0);
	if (!ft_strchr("0123456789tr-,. \n", b_char))
		return (0);
	if (hit == (char)3)
		return (0);
	return (1);
}
