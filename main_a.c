#include "minilibx/mlx.h"
#include <stdlib.h>

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_img;

typedef struct	s_window
{
	void	*mlx;
	void	*mlx_win;
}		t_window;

int	ft_exit(int key, t_window *win)
{
	if (key == 53)
	{
		mlx_destroy_window(win->mlx, win->mlx_win);
		exit(0);
	}
	return (0);
}

void	ft_put_pixel(t_img *img, int x, int y, unsigned int color)
{
	*(unsigned int*)(img->addr + x * (img->bits_per_pixel / 8) 
	+ y * img->line_length) = color;
}

int     main()
{
	t_img		buffer;
	t_window	test;
	int		x;
	int		y;

	x = 640;
	test.mlx = mlx_init();
	test.mlx_win = mlx_new_window(test.mlx, 1280, 720, "TAGIL");
	buffer.img = mlx_new_image(test.mlx, 1280, 720);
	buffer.addr = mlx_get_data_addr(buffer.img, &buffer.bits_per_pixel, &buffer.line_length, &buffer.endian);
	while (x != 600)
	{
		y = 360;
		while (y != 320)
		{
			ft_put_pixel(&buffer, x, y, 0x00ffffff);
			y--;
		}
		x--;
	}
	x = 640;
	while (x != 600)
	{
		y = 360;
		while (y != 320)
		{
			ft_put_pixel(&buffer, x, y, 0x00ff112a);
			y--;
		}
		x--;
	}

	mlx_put_image_to_window(test.mlx, test.mlx_win, buffer.img, 0, 0);
	mlx_key_hook(test.mlx_win, ft_exit, &test.mlx);
	mlx_loop(test.mlx);
	return (0);
}
