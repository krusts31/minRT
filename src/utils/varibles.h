#ifndef VARIBLES_H
# define VARIBLES_H
# include <stddef.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vec
{
	float		e[3];
}			t_vec;

typedef struct s_vec_uc
{
	unsigned char	e[3];
}			t_vec_uc;

/*
**		v1 is origin
**		v2 if direction
*/

typedef struct s_ray
{
	t_vec	*v1;
	t_vec	*v2;
}			t_ray;

typedef struct s_hit
{
	float	t;
	t_vec	*p;
	t_vec	*normal;
	t_vec	*color;
}			t_hit;

typedef struct s_sphere_difuse_var
{
	t_vec	*point;
	t_vec	*rand;
	t_vec	*one;
	t_vec	*tmp;
}			t_sphere_difuse_var;

typedef struct s_camera
{
	t_vec	*origin;
	t_vec	*lower_left_corner;
	t_vec	*horizontal;
	t_vec	*vertical;
}			t_camera;

typedef struct s_draw
{
	t_ray	*ray;
	t_vec	*p;
	t_vec	*temp;
	t_vec	*col;
	t_vec	*new_col;
	int		x;
	int		y;
	int		ret;
	int		t;
	int		n;
	float	u;
	float	v;
	int		ir;
	int		ig;
	int		ib;
}			t_draw;

typedef struct s_col_var
{
	t_hit	*hit;
	t_vec	*unit_dir;
	float	t;
	t_vec	*new;
	t_vec	*new1;
	t_vec	*ret;
	t_vec	*tmp;
	t_vec	*random;
	t_ray	*new_r;
	t_vec	*some_vec;
}			t_col_var;

typedef struct s_sq
{
	t_vec		*cor;
	t_vec		*norm;
	t_vec_uc	*col;
	float		side_size;
	const float	rotation;
	struct s_sq	*next;
}			t_sq;

/*
**	Plane
*/

typedef struct s_pl
{
	t_vec		*cor;
	t_vec		*norm;
	t_vec_uc	*col;
	struct s_pl	*next;
}			t_pl;

/*
**	Cylinder
*/

typedef struct s_cy
{
	t_vec		*cor;
	t_vec		*norm;
	t_vec_uc	*col;
	float		diameter;
	float		height;
	struct s_cy	*next;
}			t_cy;

/*
**	Triangle
*/

typedef struct s_tr
{
	t_vec		*cor1;
	t_vec		*cor2;
	t_vec		*cor3;
	t_vec_uc	*col;
	struct s_tr	*next;
}			t_tr;

/*
**	Sphere
*/

typedef struct s_sp
{
	t_vec		*cor;
	t_vec_uc	*col;
	float		diameter;
	struct s_sp	*next;
}			t_sp;

/*
**	Ambient light
*/

typedef struct s_amb_light
{
	float		ratio;
	t_vec_uc	*col;
}			t_amb_light;

/*
**	Camera
*/

typedef struct s_image_var
{
	t_vec		*u;
	t_vec		*v;
	t_vec		*w;
	t_vec		*tmp;
	t_vec		*tmp2;
	t_vec		*tmp3;
	t_vec		*tmp4;
	float		theta;
	float		half_width;
	float		half_height;
}			t_image_var;

typedef struct s_image_plane
{
	t_vec		*upper_left;
	t_vec		*horizontal;
	t_vec		*vertical;
}			t_image_plane;

typedef struct s_cameraPP
{
	t_image_plane		*image;
	t_vec				*cor;
	t_vec				*norm;
	float				FOV;
	struct s_cameraPP	*next;
}			t_cameraP;

/*
**	ratio:	the brights ratio values [0.0, 1.0]
*/

typedef struct s_light
{
	t_vec			*cor;
	t_vec_uc		*col;
	float			ratio;
	struct s_light	*next;
}		t_light;

typedef struct s_task
{
	size_t		X_res;
	size_t		Y_res;
	t_amb_light	*Amb_light;
	t_sq		*sq;
	t_pl		*pl;
	t_cy		*cy;
	t_sp		*sp;
	t_tr		*tr;
	t_light		*light;
	t_cameraP	*camera;
	char		save;
}			t_task;

typedef struct s_pars_vars
{
	char		*line;
	int			fd;
	int			ret;
	int			i;
	size_t		line_cnt;
}			t_pars_vars;

typedef struct s_hit_sp
{
	float		a;
	float		b;
	float		c;
	float		disc;
	float		closest;
	t_vec		*test;
	t_vec		*oc;
}			t_hit_sp;

#endif
