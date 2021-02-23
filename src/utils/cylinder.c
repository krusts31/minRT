#include "parcer.h"
#include "minRT.h"

#include <stdio.h>

void	ft_lstadd_back_cy(t_cy **lst, t_cy *new)
{
	t_cy	*tmp;

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

t_cy	*ft_new_cy(void)
{
	t_cy	*tmp;

	tmp = malloc(sizeof(t_cy));
	if (tmp == NULL)
		return (NULL);
	else if (tmp)
	{
		tmp->cor = new_vector(0, 0, 0);
		tmp->norm = new_vector(0, 0, 0);
		tmp->col = new_vector_uc(0, 0, 0);
		tmp->diameter = 0.0;
		tmp->height = 0.0;
		tmp->next = NULL;
	}
	if (tmp->cor == NULL || tmp->norm == NULL || tmp->col == NULL)
		return (NULL);
	return (tmp);
}

void	ft_parc_cy(t_task **task, t_pars_vars **vars)
{
	char	hit;
	char	hit_dig;
	t_cy	*tmp;

	hit_dig = 0;
	hit = 0;
	(*vars)->i = 0;
	tmp = ft_new_cy();
	if (tmp == NULL)
		exit(!printf("Error\nOut of mem ft_new_cy()\n!"));
	hit_dig = ft_cy_con(&tmp, vars, hit, hit_dig);
	if (hit_dig != 11)
		exit(!printf("Error\non line %ld\n", (*vars)->line_cnt));
	ft_lstadd_back_cy(&(*task)->cy, tmp);
}

char	ft_check_cy(char hit, char hit_dig, char b_char)
{
	if (hit > 2 && hit_dig == 1)
		return (0);
	if (!ft_strchr("0123456789cy-,. \n", b_char))
		return (0);
	if (hit == (char) 3)
		return (0);
	return (1);
}
