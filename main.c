#include "minRT.h"
#include <float.h>

/*
**		POSIBLE IMPLEMENTATIONS
**		CAMERA INIT ARR
**	float		arr[3][2];
*/
static t_vec	*color(t_ray *ray, t_hit_list *hit_list)
{
	t_hit	*hit;
	t_vec	*unit_dir;
	float	t;
	t_vec	*new;
	t_vec	*new1;
	t_vec	*new2;
	t_vec	*ret;
	t_vec	*tmp;

	hit = malloc(sizeof(t_hit) * 1);
	if (hit == NULL)
		return (NULL);
	if (hitable_list(ray, 0.0, FLT_MAX, &hit, hit_list))
	{
		new = vec_plus_num(hit->normal, 1);
		if (new == NULL)
			return (NULL);
		new2 = vec_times_num(new, 0.5);
		if (new2 == NULL)
			return (NULL);
		return (new2);
	}
	else
	{
		unit_dir = unit_vec(ray->v2);
		t = 0.5 * (unit_dir->e[1] + 1.0);
		new = new_vector(1.0, 1.0, 1.0);
		if (new == NULL)
			return (NULL);
		new1 = new_vector(0.5, 0.7, 1.0);
		if (new1 == NULL)
			return (NULL);
		tmp = vec_times_num(new, (1.0 - t));
		if (tmp == NULL)
			return (NULL);
		free(new);
		new = tmp;
		tmp = vec_times_num(new1, t);
		if (tmp == NULL)
			return (NULL);
		free(new1);
		new1 = tmp;
		ret = vec_plus_vec(new, new1);
		if (ret == NULL)
			return (NULL);
		return (ret);
	}
}

static void	*draw_back_ground(t_data *img, t_camera *camera, t_hit_list *list)
{
	t_ray	*ray;
	t_vec	*col;
	t_vec	*p;

	int	x;
	int	y;
	int	ret;
	int	t;
	int	ns;
	
	float	u;
	float	v;

	
	t = 0;
	x = 1280;
	y = 720;
	ns = 20;
	for (int j = y - 1; j >= 0; j--)
	{
		for (int i = 0; i < x; i++)
		{
			col = new_vector(0.0, 0.0, 0.0);
			for (int s = 0; s < ns; s++)
			{
				u = (i + drand48()) / x;
				v = (j + drand48()) / y;
				ray = get_ray(u, v, camera);
				if (ray == NULL)
					return (NULL);
				p = point_at_param(ray, 2.0);
				col = vec_plus_vec(col, color(ray, list));
			}
			col = vec_div_num(col, (float)ns); 
			int ir = (int)255.99 * col->e[0];
			int ig = (int)255.99 * col->e[1];
			int ib = (int)255.99 * col->e[2];
			ret = create_trgb(t, ir, ig, ib);
			if (ret < 0)
				ret = -ret;
			my_mlx_pixel_put(img, i, j, ret);
			free(ray);
			free(col);
		}
	}
	return (NULL);
}

static t_hit_list	*malloc_list_2d(int size)
{
	t_hit_list	*new;

	new = malloc(sizeof(t_hit_list) * 1);
	new->list = malloc(sizeof(t_sphere) * size);
	return (new);
}

int     main()
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;
	t_sphere	*sphere;
	t_sphere	*sphere1;
	t_hit_list	*list_of;
	t_camera	*camera;

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
	mlx_win = mlx_new_window(mlx, 1280, 720, "HELLO WOLRD!");
	img.img = mlx_new_image(mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	draw_back_ground(&img, camera, list_of);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
