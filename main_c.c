#include "minilibx/mlx.h"
#include <stdlib.h>
#include "gnl/get_next_line.h"
#include "ft_printf/ft_printf.h"
#include <math.h>
#include <limits.h>
#include <stdio.h>
//#include "ft_printf/libft/libft.h"

typedef struct  s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int     main()
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;
	int	x;
	int	y;
	char	*line;
	int	z;

	z = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 720, "HELLO WOLRD!");
	img.img = mlx_new_image(mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	y = 0;
	while (y < 720)
	{
		x = 0;
		while (1280)
		{
			if (THIS CURRENT POINT IS IN CIRCLE(specifics of the circle, x, y))
				RETURN WHITE PIXEL;
			else
				RETURN BLACK PIXEL;
			x++;
		}
		y++;
	}
	/*
	**	ALTERNATICE FOR TRIANGLE
	*/
/*
	x = 100;
	y = 100;
	if (ft_strnstr(line, "circle", 6) || ft_strnstr(line, "all", 3))
	{
		while (x && y)
		{
			z = x;
			while (z)
			{
				my_mlx_pixel_put(&img, x, z, 0x00FFFF00);
				z--;
			}
			z = y;
			while (z)
			{
				z--;
			}
			x--;
			y--;
		}
	}
*/
	y = 0;
	x = 100;
	if (ft_strnstr(line, "circle", 6) || ft_strnstr(line, "all", 3))
	{
		x = sqrt(x) - 2 * y - 1;
		x = sqrt(x);
		if (x < 0)
			x = -x;
		my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
		x--;
	}
/*
		while (ang != 0)
		{
			x = sin(ang) * r;
			if (x < 0)
				x = -x;
			x = x + 99;
			while (x != 99)
			{
				z = cos(ang) * r;
				if (z < 0)
					z = -z;
				z = z + 99;
				while (z != 99)
				{
					my_mlx_pixel_put(&img, x, z, 0x00FFFFFF);
					z--;
				}
				x--;
			}
			ang--;
		}
		ang = 360;

//		int	ret;
		while (ang != 0)
		{
			x = cos(ang) * r;
			if (x < 0)
				x = -x;
			while (x != 100)
			{
				y = sin(ang) * r;
				if (y < 0)
					y = -y;
				while (y != 100)
				{
					if ( x < 5)
						printf("this is x: |%d| this is |%d|\n", x, y);
//					ret = get_next_line(0, &line);
					my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
					y++;
				}
				x++;
			}
			ang--;
		}
		x = 100;
		while (x != 200)
		{
			y = 0;
			while (y != 100)
			{
				my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
				y++;
			}
			x++;
		}
		x = 0;
		while (x != 100)
		{
			y = 100;
			while (y != 200)
			{
				my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
				y++;
			}
			x++;
		}












		int	test;

		
		int	a;
		int	lol;

		lol = 0;
		a = 5;
		x = 100;
		test = 100;
		while (x)
		{
			//pow(x - a, 2) - pow(y - a, 2) = pow(test);
			y  = sqrt(pow(test, 2) - pow((x - a), 2)) + a;
			my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
//			printf("this is y: %d\n", y);
			x--;
			test--;
		}
		x = 200;
		test = 200;
		while (x)                                             	
        	{
        		//pow(x - a, 2) - pow(y - a, 2) = pow(test);
        		y  = sqrt(pow(test, 2) - pow((x - a), 2)) + a;
        		my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
  //      		printf("this is y: %d\n", y);
        		x--;
        		test--;
        	}
*/











/*
	if (ft_strnstr(line, "circle", 6) || ft_strnstr(line, "all", 3))
	{
		double	aang;
		aang = 0.00;
		while (aang < )
		{
			x = asin(aang) * r;
			printf("this is aang: %f\n", aang);
			if (x < 0)
				x = -x;
			printf("this is x: %d\n", x);
			while (x != 0)
			{
				z = acos(aang) * r;
				printf("this is d: %d\n", z);
				if (z < 0)
					z = -z;
				while (z != 0)
				{
					my_mlx_pixel_put(&img, x, z, 0x00FFFFFF);
					z--;
				}
				x--;
			}
			aang = aang + 0.01;
		}
*/
	mlx_put_image_to_window(mlx, mlx_win, img.img, 200, 200);
	mlx_loop(mlx);
	return (0);
}
