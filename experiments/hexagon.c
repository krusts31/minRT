#include "minRT.h"

int	ft_hex(t_data *img, int x, int y, int size)
{
	int	iy;
	int	ix;
	int	hold;

	ix = (x - size) + 35;
	iy = (y - size) + 25;
	while (x != ix)
	{
		hold = y;
		while (hold != iy)
		{
			my_mlx_pixel_put(img, x, hold, 0x00AAAAFF);
			hold--;
		}
		y--;
		x--;
	}
	return (0);
}

int	ft_hex1(t_data *img, int x, int y, int size)
{
	int	iy;
	int	ix;
	int	hold;

	ix = (x - size) + 35;
	iy = (y - size);
	while (x != ix)
	{
		hold = y;
		while (hold != iy)
		{
			my_mlx_pixel_put(img, hold, x, 0x00AAAAFF);
			hold--;
		}
		y--;
		x--;
	}
	return (0);
}

int	ft_hex2(t_data *img, int x, int y, int size)
{
	int	iy;
	int	ix;
	int	hold;

	ix = (x - size) + 20;
	iy = (y - size);
	while (x != ix)
	{
		hold = 0;
		while (hold != iy && hold < size)
		{
			my_mlx_pixel_put(img, x, hold, 0x00AAAAAA);
			hold++;
		}
		iy--;
		x--;
	}
	return (0);
}

int	ft_hex3(t_data *img, int x, int y, int size)
{
	int	iy;
	int	ix;
	int	hold;

	ix = x - size;
	x = 0;
	iy = (y - size);
	while (x < size - 20)
	{
		hold = iy;
		while (hold != iy)
		{
			my_mlx_pixel_put(img, hold, x, 0x0000BBFF);
			hold--;
		}
		iy--;
		x++;
	}
	return (0);
}
