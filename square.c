#include "minRT.h"

int	ft_square(t_data *img, int x, int y, int size)
{
	int	iy;
	int	ix;
	int	hold;

	ix = x - size;
	iy = y - size;
	while (x != ix)
	{
		hold = y;
		while (hold != iy)
		{
			my_mlx_pixel_put(img, x, hold, 0x000000FF);
			hold--;
		}
		x--;
	}
	return (0);
}
