#include "minRT.h"

void	draw_back_ground(t_data *img, t_vec *test)
{
	int	x;
	int	y;
	int	ret;
	int	t;

	t = 0;
	x = 1280;
	y = 720;
	for (int j = y-1; j >= 0; j--)
	{
		for (int i = 0; i < x; i++)
		{
			float r = (float)i / (float)x;
			float g = (float)j / (float)y;
			float b = 0.2;
			int ir = (int)255.99*r;
			int ig = (int)255.99*g;
			int ib = (int)255.99*b;
			ret = create_trgb(t, ir, ig, ib);
			my_mlx_pixel_put(img, i, j, ret);
		}
	}
}

int     main()
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 720, "HELLO WOLRD!");
	img.img = mlx_new_image(mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_back_ground(&img, test);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
	//get_next_line(0, &line);
/*
	ft_circle(&img, 1280, 1000, 45, 440, 250);
	ft_circle(&img, 1280, 1000, 45, 640, 450);
	ft_circle(&img, 1280, 1000, 45, 840, 650);
	ft_square(&img, 685, 295, 90);
	ft_square(&img, 495, 495, 90);
	ft_triangle(&img, 895, 295, 90);
	ft_triangle1(&img, 695, 495, 90);
*/
//	bresenham(&img, 0, 100, 0, 100);
//	bresenham(&img, 100, 100, 0, 100);
//	ft_hex(&img, 845, 495, 80);
//	ft_hex1(&img, 895, 495, 90);
//	ft_hex2(&img, 195, 395, 90);
//	ft_hex3(&img, 895, 295, 90);

/*
	long long	ret;
	//char		*color;
	int	t;
	int	r;
	int	g;
	int	b;

	int	x;
	int	y;

	x = 0;
	y = 0;

	ret = 0;
	t = 0;
	r = 100;
	g = 100;
	b = 100;
//	while (t != 256)
//	{
	r = 200;
	while (r != 256)
	{
		g = 200;
		while (g != 256)
		{
			b = 0;
			while (b != 256)
			{
				x++;
				if (x == 1279)
				{
					x = 0;
					y++;
				}
				if (y == 980)
				{
					mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
					mlx_loop(mlx);
					return (0);
				}
				b++;
			}
			g++;
		}
		r++;
	}
*/

