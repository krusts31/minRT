#include "minRT.h"
#include "parcer.h"
#include "error.h"
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>

t_vec	*color(t_ray **ray, t_task **task, int depth)
{
	t_col_var	*var;
//	int		iter;
	t_vec		*att;
	t_ray		*scatt;
	t_vec		*unit;
	float		t;
//	iter = 0;
//	while (1)
//	{
		if (!init_col_var(&var))
			return (NULL);
		var->hit = malloc(sizeof(t_hit) * 1);
		if (var->hit == NULL)
			return (NULL);
		if (hitable_list(ray, INT_MAX, &var->hit, (*task)->sp))
		{
			if (depth < 50 && scatter(&var->hit, &scatt, &att))
			{
				depth++;
				return (vec_times_vec(att, color(&scatt, task, depth)));
			}
			else
				return (new_vector(0, 0, 0));
		}
		else
		{
			unit = unit_vec((*ray)->v2);
			t = 0.5 * (unit->e[1] + 1.0);
			return (vec_plus_vec(vec_times_num(new_vector(1, 1, 1), 1.0 - t), vec_times_num(new_vector(0.5, 0.7, 1.0), t)));
		}
//			is_hit(&var, &(*draw)->ray, &iter);
//		else
//			return (c_e(&var, &holding, &iter, draw));
//	}
}

static int	draw_back_ground(t_data *img, t_task **task)
{
	t_draw	*draw;

	if(!init_draw(&draw, (*task)->X_res, (*task)->Y_res, 15))
		return (free_task_draw(task, &draw, 0));
	for (int j = draw->y - 1; j >= 0; j--)
	{
		for (int i = 0; i < draw->x; i++)
		{
			draw->col = new_vector(0.0, 0.0, 0.0);
			if (draw->col == NULL)
				exit(!printf("Error\nOut of mem main.c new_v\n"));
			draw->col = get_color(task, &draw, i, j);
			if (draw->col == NULL)
				exit(!printf("Error\nOut of mem main.c g_col\n"));
			draw->temp = vec_div_num(draw->col, (float)draw->n); 
			if (draw->temp == NULL)
				exit(!printf(ERROR_9));
			free(draw->col);
			draw->col = draw->temp;
			draw->temp = NULL;
			draw->new_col = new_vector(sqrt(draw->col->e[0]), sqrt(draw->col->e[1]), sqrt(draw->col->e[2]));
			if (draw->new_col == NULL)
				exit(!printf("Error\nOut of mem main.c new_vl\n"));
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
	mlx_win = mlx_new_window(mlx, task->X_res, task->Y_res, "HELLO WOLRD!");
	img.img = mlx_new_image(mlx, task->X_res, task->Y_res);
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
