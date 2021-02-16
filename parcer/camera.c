#include "parcer.h"

void		ft_lstadd_back_c(t_camera **lst, t_camera *new)
{
	t_camera *tmp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast_c(*lst);
		tmp->next = new;
	}
}

t_camera	*ft_lstlast_c(t_camera *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_camera	*ft_new_camera()
{
	t_camera	*tmp;

	tmp = malloc(sizeof(t_camera));
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
		tmp->FOV = 0.0;
		tmp->next = NULL;
	}
	return (tmp);
}

char	ft_parc_camera(t_task **task, t_pars_vars **vars)
{
	char		hit;
	char		hit_dig;
	t_camera	*tmp;

	hit_dig = 0;
	hit = 0;
	(*vars)->i = 0;
	tmp = ft_new_camera();
	if (tmp == NULL)
		return (0);
	hit_dig = ft_camera_con(&tmp, vars, hit, hit_dig);
	ft_lstadd_back_c(&(*task)->camera, tmp);
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

char	ft_check_camera(char hit, char hit_dig, char b_char)
{
	if (hit == 0 && hit_dig == 1)
		return (0);
	if (!ft_strchr("0123456789c-,. \n", b_char))
		return (0);
	if (hit == (char)2)
		return (0);
	return (1);
}
