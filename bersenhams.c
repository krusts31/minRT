//#include "minRT.h"
/*
void	draw_line()
{
	
}
*/
/*
void bresenham(t_data *img, int x1, int x2, int y1, int y2)
{
	//int	fill_x;
	//int	fill_y;
	int	m_new;
	int	slope_error_new;

	m_new = 2 * (y2 - y1);
	slope_error_new = m_new - (x2 - x1);
	for (int x = x1, y = y1; x <= x2; x++)
	{
		slope_error_new	+= m_new;
		printf("this is x %d this is y %d\n", x, y);
		if (slope_error_new >= 0)
		{
			y++;
			slope_error_new -= 2 * (x2 - x1);
		}
		my_mlx_pixel_put(img, x, y, 0x221100FF);
	}
}
*/
/*
#include <stdio.h>

int	bersenham1(float coeficient, int x, int y, int x1, int y1)
{

	int	res;
	//int	hold;

			res = coeficient * x + 1 - y;
			printf("this is res: %d\n", res);
	while (x1 != 0)
	{
		hold = y1;
		while (hold != 0)
		{
		}
		x1--;
	}
	return (0);
}

int	main()
{	
	bersenham1(0.5, 100, 100, 400, 400);
	return (0);
}
*/
