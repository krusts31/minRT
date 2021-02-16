#include "minRT.h"

static t_vec	*color(t_ray *ray, t_hit_list *hit_list)
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
		if (hitable_list(ray, 0.001, INT_MAX, &var->hit, hit_list))
		{
			var->new = vec_plus_vec(var->hit->normal, var->hit->p);
			if (var->new == NULL)
				return (NULL);
			var->random = vec_plus_vec(var->new, rand_in_unit_sphere());
			free(var->new);
			if (var->random == NULL)
				return (NULL);
			var->some_vec = vec_minus_vec(var->random, var->hit->p);
			free(var->random);
			var->new_r = new_ray(var->hit->p, var->some_vec);
			if (var->new_r == NULL)
			{
				free(var->hit);
				free(var->new);
				return (NULL);
			}
			ray = var->new_r;
			free(var->hit);
			free(var);
			iter++;
		}
		else
		{
			var->unit_dir = unit_vec(ray->v2);
			var->t = 0.5 * (var->unit_dir->e[1] + 1.0);
			var->new = new_vector(1.0, 1.0, 1.0);
			if (var->new == NULL)
				return (NULL);
			var->new1 = new_vector(0.5, 0.7, 1.0);
			if (var->new1 == NULL)
				return (NULL);
			var->tmp = vec_times_num(var->new, (1.0 - var->t));
			if (var->tmp == NULL)
				return (NULL);
			free(var->new);
			var->new = var->tmp;
			var->tmp = vec_times_num(var->new1, var->t);
			if (var->tmp == NULL)
				return (NULL);
			free(var->new1);
			var->new1 = var->tmp;
			var->ret = vec_plus_vec(var->new, var->new1);
			if (var->ret == NULL)
				return (NULL);
			free(var->hit);
			free(var->new);
			free(var->new1);
			while (iter > 0)
			{
				holding = vec_times_num(var->ret, 0.5);
				free(var->ret);
				var->ret = holding;
				iter--;
			}
			return (var->ret);
		}
	}
}

/*
**	NS is resposible for anti aliasing which is bonus behavoiur
**	disable it for now becaus it slows down redering or set it to 1
*/

static void	*draw_back_ground(t_data *img, t_camera *camera, t_hit_list *list, clock_t t, clock_t original)
{
	t_draw	*draw;

	if(!init_draw(&draw, 1280, 720, 2))
		return (NULL);
	for (int j = draw->y - 1; j >= 0; j--)
	{
/*		t = clock() - original;
		double time_taken = ((double)t)/CLOCKS_PER_SEC;
		printf("foor loop start :%f\n", time_taken); */
		for (int i = 0; i < draw->x; i++)
		{
			draw->col = new_vector(0.0, 0.0, 0.0);
			if (draw->col == NULL)
				return (free_draw(&draw));
			for (int s = 0; s < draw->n; s++)
			{
				draw->u = (i + drand48()) / draw->x;
				draw->v = (j + drand48()) / draw->y;
				draw->ray = get_ray(draw->u, draw->v, camera);
				if (draw->ray == NULL)
					return (free_draw(&draw));
				draw->p = point_at_param(draw->ray, 2.0);
				draw->temp = vec_plus_vec(draw->col, color(draw->ray, list));
				if (draw->temp == NULL)
					return (free_draw(&draw));
				free(draw->col);
				draw->col = draw->temp;
			}
			draw->temp = vec_div_num(draw->col, (float)draw->n); 
			if (draw->temp == NULL)
				return (free_draw(&draw));
			free(draw->col);
			draw->col = draw->temp;
			draw->temp = NULL;
			draw->new_col = new_vector(sqrt(draw->col->e[0]), sqrt(draw->col->e[1]), sqrt(draw->col->e[2]));
			if (draw->new_col == NULL)
				return (free_draw(&draw));
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
		t = clock() - original;
		time_taken = ((double)t)/CLOCKS_PER_SEC;
		printf("for loop end :%f\n", time_taken);
	}
	return (free_draw(&draw));
}

static t_hit_list	*malloc_list_2d(int size)
{
	t_hit_list	*new;

	new = malloc(sizeof(t_hit_list) * 1);
	new->list = malloc(sizeof(t_sphere) * size);
	return (new);
}

int     main(int argc, char **argv)
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;
	t_sphere	*sphere;
	t_sphere	*sphere1;
	t_hit_list	*list_of;
	t_camera	*camera;
	clock_t		original;
	clock_t		t;
	t_task		*task;

	task = new_task(argc, argv);
	if (task == NULL)
		return (-1);
	original = clock();
	camera = new_camera();
	if (camera == NULL)
		return (0);
	list_of = malloc_list_2d(3);
	sphere = malloc(sizeof(t_sphere) * 1);
	if (sphere == NULL)
		return (0);
	sphere->radius = 0.5;
	sphere->center = new_vector(0.0, 0.0, -1.0);
	sphere1 = malloc(sizeof(t_sphere) * 1);
	if (sphere1 == NULL)
		return (0);
	sphere1->radius = 100;
	sphere1->center = new_vector(0.0, -100.5, -1.0);
	list_of->list[0] = sphere;
	list_of->list[1] = sphere1;
	list_of->list_size = 2;

	mlx = mlx_init();
/*	t = clock() - original;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;*/
	printf("time to init all the varible :%f\n", time_taken);
	mlx_win = mlx_new_window(mlx, 1280, 720, "HELLO WOLRD!");
	img.img = mlx_new_image(mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	t = clock() - original;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("time to init all the MLX :%f\n", time_taken);
	draw_back_ground(&img, camera, list_of, t, original);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
