#ifndef PARCER_H
#define PARCER_H
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"
#include <stdio.h>


/*
**	Square
**	rotation: the rotation around noral vector constant and not deffined by user!
*/

typedef struct		s_sq
{
	float		x_cor_center;
	float		y_cor_center;
	float		z_cor_center;
	float		x_norm;
	float		y_norm;
	float		z_norm;
	unsigned char	r_col;
	unsigned char	g_col;
	unsigned char	b_col;
	float		side_size;
	const float	rotation;
	struct s_sq	*next;
}			t_sq;

/*
**	Plane
*/

typedef struct		s_pl
{
	float		x_cor_center;
	float		y_cor_center;
	float		z_cor_center;
	float		x_norm;
	float		y_norm;
	float		z_norm;
	unsigned char	r_col;
	unsigned char	g_col;
	unsigned char	b_col;
	struct s_pl	*next;
}			t_pl;

/*
**	Cylinder
*/

typedef struct		s_cy
{
	float		x_cor_center;
	float		y_cor_center;
	float		z_cor_center;
	float		x_norm;
	float		y_norm;
	float		z_norm;
	unsigned char	r_col;
	unsigned char	g_col;
	unsigned char	b_col;
	float		diameter;
	float		hight;
	struct s_cy	*next;
}			t_cy;

/*
**	Triangle
*/

typedef	struct		s_tr
{
	float		x_cor_1;
	float		y_cor_1;
	float		z_cor_1;
	float		x_cor_2;
	float		y_cor_2;
	float		z_cor_2;
	float		x_cor_3;
	float		y_cor_3;
	float		z_cor_3;
	unsigned char	r_col;
	unsigned char	g_col;
	unsigned char	b_col;
	struct s_tr	*next;
}			t_tr;

/*
**	Sphere
*/

typedef struct		s_sp
{
	float		x_cor_center;
	float		y_cor_center;
	float		z_cor_center;
	unsigned char	r_col;
	unsigned char	g_col;
	unsigned char	b_col;
	float		diameter;
	struct s_sp	*next;
}			t_sp;

/*
**	Ambient light
*/

typedef struct		s_amb_light
{
	float		ratio;
	unsigned char	r_col;
	unsigned char	g_col;
	unsigned char	b_col;
}			t_amb_light;

/*
**	Camera
*/

typedef struct		s_camera
{
	float		x_cor;
	float		y_cor;
	float		z_cor;
	float		x_norm;
	float		y_norm;
	float		z_norm;
	float		FOV;
	struct s_camera	*next;
}			t_camera;

/*
**	ratio:	the brights ratio values [0.0, 1.0]
*/

typedef struct		s_light
{
	float		x_cor;
	float		y_cor;
	float		z_cor;
	unsigned char	r_col;
	unsigned char	g_col;
	unsigned char	b_col;
	float		ratio;
	struct s_light	*next;
}			t_light;

typedef struct		s_task
{
	size_t		X_res;
	size_t		Y_res;
	t_amb_light	*Amb_light;
	t_sq		**sq;
	t_pl		**pl;
	t_cy		**cy;
	t_sp		**sp;
	t_tr		**tr;
	t_light		**light;
	t_camera	**camera;
	char		save;
}			t_task;

typedef struct		s_pars_vars
{
	char		*line;
	int		fd;
	int		ret;
	int		i;
	size_t		line_cnt;
}			t_pars_vars;

t_camera	*ft_new_camera();
t_camera	*ft_lstlast_c(t_camera *lst);
char		ft_parc_camera(t_task **task, t_pars_vars **vars);
void		ft_lstadd_back_c(t_camera **lst, t_camera *new);
char		ft_camera_con(t_camera **camera, t_pars_vars **vars, char hit, char hit_dig);
char		ft_camera_con2(t_camera **camera, t_pars_vars **vars, char hit_dig);
char		ft_camera_con3(t_camera **camera, t_pars_vars **vars, char hit_dig);
char		ft_check_camera(char hit, char hit_dig, char b_char, size_t line);
char		ft_check_camera2(char hit_dig, t_pars_vars **vars, char comma);
float		ft_atof(const char *nptr);
float		ft_check_float(const char *nptr, float res, float max, float negative);
float		ft_atof_con(const char *nptr, float res, float negative, float max);
size_t		ft_isfloat(char fl);
char		fl_parce(float *value, t_pars_vars **vars);
#endif
