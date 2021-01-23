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
}			t_data;

typedef struct		s_vec
{
	float	e[3];
}			t_vec;

/*
**		v1 is origin
**		v2 if direction
*/

typedef struct		s_ray
{
	t_vec	*v1;
	t_vec	*v2;
}			t_ray;

/*
**	Working on a sphere
*/

typedef struct		s_hit
{
	float	t;
	t_vec	*p;
	t_vec	*normal;
}			t_hit;

typedef struct		s_sphere
{
	t_vec	*center;
	float	radius;
}			t_sphere;

typedef struct		s_hit_list
{
	int		list_size;
	t_sphere	**list;
}			t_hit_list;

typedef	struct		s_sphere_difuse_var
{
	t_vec	*point;
	t_vec	*rand;
	t_vec	*one;
	t_vec	*tmp;
}			t_sphere_difuse_var;

t_vec     *rand_in_unit_sphere();

/*
**	CAMERA STRCUCT
*/

typedef struct		s_camera
{
	t_vec	*origin;
	t_vec	*lower_left_corner;
	t_vec	*horizontal;
	t_vec	*vertical;
}			t_camera;

t_ray		*get_ray(float u, float v, t_camera *cam);
t_camera	*new_camera();
void		*free_camera(t_camera **camera);

/*
**		VECTOR FUNTIONS
*/

t_vec			*vec_copy(t_vec *src);
float			length_of_vector(t_vec *slef);
t_vec			*cross_vector(t_vec *v1, t_vec *v2);
float			dot_vector(t_vec *v1, t_vec *v2);
t_vec			*vec_plus_vec(t_vec *v1, t_vec *v2);
t_vec			*vec_plus_num(t_vec *v1, float num);
t_vec			*vec_times_num(t_vec *v1, float num);
t_vec			*new_vector(float num1, float num2, float num3);
t_vec			*unit_vec(t_vec *v);
t_vec			*vec_div_num(t_vec *v1, float num);
t_vec			*vec_minus_vec(t_vec *v1, t_vec *v2);
float			length_of_vector_pow2(t_vec *self);

/*
**		RAY FUNTIONS
*/

t_vec			*point_at_parm(float num, t_ray *ray);
t_ray			*new_ray(t_vec *vec1, t_vec *vec2);
t_vec			*point_at_param(t_ray *ray, float t);

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

/*
**		TRIANGLE
*/

int			ft_triangle(t_data *img, int x, int y, int size);
int			ft_triangle1(t_data *img, int x, int y, int size);

/*
**		HEXAGON
*/

int			ft_hex1(t_data *img, int x, int y, int size);
int			ft_hex(t_data *img, int x, int y, int size);
int			ft_hex3(t_data *img, int x, int y, int size);
int			ft_hex2(t_data *img, int x, int y, int size);

/*
**		SPHERE
*/

int			hit_sphere(t_ray *ray, float t_min, float t_max, t_hit *hit, t_sphere *sphere);

/*
**		BRESENHAM
*/

void			bresenham(t_data *img, int x1, int x2, int y1, int y2);

/*
**		COLORS
*/
int		create_trgb(int t, int r, int g, int b);
int		get_b(int trgb);
int		get_g(int trgb);
int		get_r(int trgb);
int		get_t(int trgb);

/*
**		hit_list functions
*/

int	hitable_list(t_ray *ray, float t_min, float t_max, t_hit **hit, t_hit_list *hit_list);
#endif
