#include "minRT.h"
#include "parcer.h"
#include "error.h"
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>

t_vec	*color(t_ray *ray, t_task **task)
{
	t_col_var	*var;
	int		iter;
	t_vec		*holding;

	iter = 0;
	while (1)
	{
		if (!init_col_var(&var))
			return (NULL);
		var->hit = malloc(sizeof(t_hit) * 1);
		if (var->hit == NULL)
			return (NULL);
		if (hitable_list(ray, INT_MAX, &var->hit, (*task)->sp))
		{
			if (!is_hit(&var, &ray, &iter))
				return (NULL);
		}
		else
			return (c_e(&var, &holding, &iter, &ray));
	}
}

static int	draw_back_ground(t_data *img, t_task **task)
{
	t_draw	*draw;

	if(!init_draw(&draw, 1280, 720, 2))
		return (free_task_draw(task, &draw, 0));
	for (int j = draw->y - 1; j >= 0; j--)
	{
		for (int i = 0; i < draw->x; i++)
		{
			draw->col = new_vector(0.0, 0.0, 0.0);
			if (draw->col == NULL)
				return (free_task_draw(task, &draw, 0));
			draw->col = get_color(task, &draw, i, j);
			if (draw->col == NULL)
				return (free_task_draw(task, &draw, 0));
			draw->temp = vec_div_num(draw->col, (float)draw->n); 
			if (draw->temp == NULL)
				exit(!printf(ERROR_9));
			free(draw->col);
			draw->col = draw->temp;
			draw->temp = NULL;
			draw->new_col = new_vector(sqrt(draw->col->e[0]), sqrt(draw->col->e[1]), sqrt(draw->col->e[2]));
			if (draw->new_col == NULL)
				return (free_task_draw(task, &draw, 0));
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
	return (free_task_draw(task, &draw, 1));
}

int     main(int argc, char **argv)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_task		*task;

	if (!new_task(argc, argv, &task))
		return (-1);
	if (task == NULL)
		return (-1);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 720, "HELLO WOLRD!");
	img.img = mlx_new_image(mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	if (!draw_back_ground(&img, &task))
	{
		printf("Error\nFaield to create image!");
		return (-1);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
