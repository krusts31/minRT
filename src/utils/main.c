#include "minRT.h"
#include "parcer.h"
#include "error.h"
#include <math.h>
#include <limits.h>
#include <stdio.h>

t_vec	*color(t_ray **ray, t_task **task, int depth)
{
	t_col_var	*var;

	(void)depth;
	init_col_var(&var);
	var->hit = malloc(sizeof(t_hit) * 1);
	if (var->hit == NULL)
		exit(!printf("Error\nmain.c:15\n"));
	if (hitable_list(ray, INT_MAX, &var->hit, task))
		return (var->hit->color);
	return (new_vector(0, 0, 0));
}

int		draw_back_ground(void *img, t_task **task)
{
	t_draw		*draw;

	init_draw(&draw, (*task)->X_res, (*task)->Y_res, 5);
	for (int j = draw->y - 1; j >= 0; j--)
	{
		for (int i = 0; i < draw->x; i++)
		{
			draw->col = new_vector(0.0, 0.0, 0.0);
			draw->col = get_color(task, &draw, i, j);
			draw->temp = vec_div_num(draw->col, (float)draw->n); 
			free(draw->col);
			draw->col = draw->temp;
			draw->temp = NULL;
			draw->new_col = new_vector(sqrt(draw->col->e[0]), sqrt(draw->col->e[1]), sqrt(draw->col->e[2]));
			draw->ir = (int)255.99 * draw->new_col->e[0];
			draw->ig = (int)255.99 * draw->new_col->e[1];
			draw->ib = (int)255.99 * draw->new_col->e[2];
			draw->ret = create_trgb(draw->t, draw->ir, draw->ig, draw->ib);
			my_mlx_pixel_put(img, i, j, draw->ret);
			free(draw->ray);
			free(draw->col);
			draw->ray = NULL;
			draw->col = NULL;
		}
	}
//	return (free_task_draw(task, &draw, 1));
	return (0);
}

/*
**	I have implemented
**		sp
**		lights
**	I can try to work on trinalges
**	I can work on the --save feature
**	Fix memmory leaks
**	Norm
**int     mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
*/


int     main(int argc, char **argv)
{
	t_data		*data;
	int		x;
	int		y;

	x = 0;
	y = 0;
	data = malloc(sizeof(t_data) * 1);
	if (data == NULL)
		exit(!printf("Error\nmain.c:80\n"));
	new_task(argc, argv, &data->task);
	ft_init_mlx(&data, &data->task);
	mlx_get_screen_size(&data->mlx, &x, &y);
	if (x <= 0 || y <= 0)
		exit(!printf("Error\nRes of screem broken!\n"));
	if (((size_t)x < data->task->X_res) || ((size_t)x < data->task->X_res))
	{
		if ((size_t)x < data->task->X_res)
			data->task->X_res = x / 4;
		if ((size_t)y < data->task->Y_res)
			data->task->Y_res = y / 4;
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		ft_init_mlx(&data, &data->task);
	}
	draw_back_ground(&data->img, &data->task);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_hook(data->mlx_win, 2, 1L<<0, close_win, data);
	mlx_hook(data->mlx_win, 17, 1L<<13, close_red, data);
	mlx_loop(data->mlx);
	return (0);
}
