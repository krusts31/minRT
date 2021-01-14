#include "minRT.h"

void drawCircle(t_data *img,int xc, int yc, int x, int y)
{
    my_mlx_pixel_put(img, xc+x, yc+y, 0x00FF00FF);
    my_mlx_pixel_put(img, xc-x, yc+y, 0x00FF00FF);
    my_mlx_pixel_put(img, xc+x, yc-y, 0x00FF00FF);
    my_mlx_pixel_put(img, xc-x, yc-y, 0x00FF00FF);
    my_mlx_pixel_put(img, xc+y, yc+x, 0x00FF00FF);
    my_mlx_pixel_put(img, xc-y, yc+x, 0x00FF00FF);
    my_mlx_pixel_put(img, xc+y, yc-x, 0x00FF00FF);
    my_mlx_pixel_put(img, xc-y, yc-x, 0x00FF00FF);
}

// Function for circle-generation
// using Bresenham's algorithm
void circleBres(t_data *img, int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(img, xc, yc, x, y);
    while (y >= x)
    {
        // for each pixel we will
        // draw all eight pixels

        x++;

        // check for decision parameter
        // and correspondingly
        // update d, x, y
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        drawCircle(img, xc, yc, x, y);
    }
}

int	ft_do_this(int x, int y, int r, int rx, int ry)
{
	x = x - rx;
	y = y - ry;
	if (pow(r, 2) <= (pow(x, 2) + pow(y, 2)))
	{
//		printf("%d <= %d\n", (int)pow(r, 2), (int)(pow(x, 2) + pow(y,2)));
		return (1);
	}
	else
	{
//		printf("%d > %d\n", (int)pow(r, 2), (int)(pow(x, 2) + pow(y,2)));
		return (0);
	}
}

char	*ft_circle(t_data *img, int x, int y, int r, int rx, int ry)
{
	int	hold;

	while (x != 0)
	{
		hold = y;
		while (hold != 0)
		{
			if (ft_do_this(x, hold, r, rx, ry))
			{
				//	    my_mlx_pixel_put(img, x, hold, 0x00FF00FF);
			}
			else
				    my_mlx_pixel_put(img, x, hold, 0x00FFFF00);
			hold--;
		}
		x--;
	}
	return (NULL);
}
