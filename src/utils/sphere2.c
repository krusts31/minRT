#include "parcer.h"
#include "minRT.h"

#include <stdio.h>

void	ft_lstadd_back_sp(t_sp **lst, t_sp *new)
{
	t_sp	*tmp;

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

t_sp	*ft_new_sp(void)
{
	t_sp	*tmp;

	tmp = malloc(sizeof(t_sp));
	if (tmp == NULL)
		return (NULL);
	else if (tmp)
	{
		tmp->cor = new_vector(0, 0, 0);
		tmp->col = new_vector_uc(0, 0, 0);
		tmp->diameter = 0.0;
		tmp->next = NULL;
	}
	if (tmp->cor == NULL || tmp->col == NULL)
		return (NULL);
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
	if (hit_dig != 7)
	{
		printf("Error\nBad elements on line %ld\n", (*vars)->line_cnt);
		return (0);
	}
	ft_lstadd_back_sp(&(*task)->sp, tmp);
	return (1);
}

char	ft_check_sp(char hit, char hit_dig, char b_char)
{
	if (hit > 2 && hit_dig == (char) 1)
		return (0);
	if (!ft_strchr("0123456789sp-,. \n", b_char))
		return (0);
	if (hit > (char) 3)
		return (0);
	return (1);
}
