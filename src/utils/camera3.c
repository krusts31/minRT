#include "minRT.h"

#include <stdlib.h>

t_image_var	*ft_init_image(void)
{
	t_image_var	*tmp;

	tmp = malloc(sizeof(t_image_var) * 1);
	if (tmp == NULL)
		return (NULL);
	tmp->u = NULL;
	tmp->v = NULL;
	tmp->w = NULL;
	tmp->tmp = NULL;
	tmp->tmp2 = NULL;
	return (tmp);
}

t_image_plane	*ft_init_image_plane(void)
{
	t_image_plane	*tmp;

	tmp = malloc(sizeof(t_image_var) * 1);
	if (tmp == NULL)
		return (NULL);
	tmp->upper_left = NULL;
	tmp->horizontal = NULL;
	tmp->vertical = NULL;
	return (tmp);
}

void	*ft_free_image_vars(t_image_var **vars)
{
	free((*vars)->u);
	free((*vars)->v);
	free((*vars)->w);
	free((*vars)->tmp);
	free((*vars)->tmp2);
	free(*vars);
	return (NULL);
}

void	*ft_free_image(t_image_plane **plane)
{
	free((*plane)->upper_left);
	free((*plane)->horizontal);
	free((*plane)->vertical);
	free(*plane);
	return (NULL);
}

void	*ft_image_error(t_image_var **var, t_image_plane **plane)
{
	ft_free_image_vars(var);
	ft_free_image(plane);
	return (NULL);
}
