#ifndef MINRT_H
# define MINRT_H
#include "minilibx/mlx.h"
#include "gnl/get_next_line.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>

typedef struct		s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_data;


/*
**		PIXEL FUNCTIONS
*/
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*
**		DRAW CIRCLE FUNCTIONS
*/
void			drawCircle(t_data *img,int xc, int yc, int x, int y);
void			circleBres(t_data *img, int xc, int yc, int r);
char			*ft_circle(t_data *img, int x, int y, int r, int rx, int ry);
int			ft_do_this(int x, int y, int r, int rx, int ry);

/*
**		DRAW SQUARE
*/

int			ft_square(t_data *img, int x, int y, int size);
#endif
