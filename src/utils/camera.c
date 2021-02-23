#include "parcer.h"
#include "minRT.h"
#include "error.h"

#include <stdio.h>

void	ft_lstadd_back_c(t_cameraP **lst, t_cameraP *new)
{
	t_cameraP	*tmp;

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

t_cameraP	*ft_lstlast_c(t_cameraP *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_cameraP	*ft_new_camera(void)
{
	t_cameraP	*tmp;

	tmp = malloc(sizeof(t_cameraP));
	if (tmp == NULL)
		return (NULL);
	else if (tmp)
	{
		tmp->cor = new_vector(0, 0, 0);
		tmp->norm = new_vector(0, 0, 0);
		tmp->FOV = 0.0;
		tmp->image = NULL;
		tmp->next = NULL;
	}
	if (tmp->cor == NULL || tmp->norm == NULL)
		return (NULL);
	return (tmp);
}

void	ft_parc_camera(t_task **task, t_pars_vars **vars)
{
	char		hit;
	char		hit_dig;
	t_cameraP	*tmp;

	hit_dig = 0;
	hit = 0;
	(*vars)->i = 0;
	tmp = ft_new_camera();
	if (tmp == NULL)
		exit(!printf(ERROR_7));
	hit_dig = c_con(&tmp, vars, hit, hit_dig);
	if (hit_dig != 7)
		exit(!printf("Error\non line %ld\n", (*vars)->line_cnt));
	tmp->image = new_image_plane(tmp->FOV, (*task)->X_res / (*task)->Y_res, tmp);
	if (tmp->image == NULL)
		exit(!printf("Error\nImage error on line %ld\n", (*vars)->line_cnt));
	ft_lstadd_back_c(&(*task)->camera, tmp);
}

char	ft_check_camera(char hit, char hit_dig, char b_char)
{
	if (hit == 0 && hit_dig == 1)
		return (0);
	if (!ft_strchr("0123456789c-,. \n", b_char))
		return (0);
	if (hit == (char) 2)
		return (0);
	return (1);
}
