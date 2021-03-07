#include "minRT.h"

#include <limits.h>
#include <stdlib.h>

int	ft_camera_size(t_cameraP *cam)
{
	int	size;

	size = 0;
	if (cam == NULL)
		return (0);
	while (cam)
	{
		size++;
		if (size == INT_MAX)
			return (-1);
		cam = cam->next;
	}
	return (size);
}

int	close_win(int key, t_data *d)
{
	if (key == 53)
	{
		mlx_destroy_image(d->mlx, d->img);
		mlx_destroy_window(d->mlx, d->mlx_win);
		exit(0);
	}
	if (key == 123)
	{
		d->task->curent = d->task->curent - 1;
		draw_back_ground(&d->img, &d->task);
		mlx_put_image_to_window(d->mlx, d->mlx_win, d->img, 0, 0);
	}
	if (key == 124)
	{
		d->task->curent = d->task->curent + 1;
		draw_back_ground(&d->img, &d->task);
		mlx_put_image_to_window(d->mlx, d->mlx_win, d->img, 0, 0);
	}
	return (0);
}

int	close_red(t_data *d)
{
	mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->mlx_win);
	exit(0);
}
