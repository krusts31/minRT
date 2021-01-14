#include "minRT.h"

int	ft_triangle(t_data *img, int x, int y, int size)
{
	int	iy;
	int	ix;
	int	hold;

	ix = (x - size);
	iy = (y - size);
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

int	ft_triangle1(t_data *img, int x, int y, int size)
{
	int	iy;
	int	ix;
	int	hold;

	ix = (x - size);
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
