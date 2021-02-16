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
	float		x_cor;
	float		y_cor;
	float		z_cor;
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
	float		x_cor;
	float		y_cor;
	float		z_cor;
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
	float		x_cor;
	float		y_cor;
	float		z_cor;
	float		x_norm;
	float		y_norm;
	float		z_norm;
	unsigned char	r_col;
	unsigned char	g_col;
	unsigned char	b_col;
	float		diameter;
	float		height;
	struct s_cy	*next;
}			t_cy;

/*
**	Triangle
*/

typedef	struct		s_tr
{
	float		x_cor1;
	float		y_cor1;
	float		z_cor1;
	float		x_cor2;
	float		y_cor2;
	float		z_cor2;
	float		x_cor3;
	float		y_cor3;
	float		z_cor3;
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
	float		x_cor;
	float		y_cor;
	float		z_cor;
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

typedef struct		s_cameraPP
{
	float		x_cor;
	float		y_cor;
	float		z_cor;
	float		x_norm;
	float		y_norm;
	float		z_norm;
	float		FOV;
	struct s_cameraPP	*next;
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
	t_sq		*sq;
	t_pl		*pl;
	t_cy		*cy;
	t_sp		*sp;
	t_tr		*tr;
	t_light		*light;
	t_camera	*camera;
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
char		ft_check_camera(char hit, char hit_dig, char b_char);
char		ft_check_camera2(char hit_dig, t_pars_vars **vars, char comma);
float		ft_atof(const char *nptr);
float		ft_check_float(const char *nptr, float res, float max, float negative);
float		ft_atof_con(const char *nptr, float res, float negative, float max);
size_t		ft_isfloat(char fl);
char		fl_parce(float *value, t_pars_vars **vars);
void		free_light(t_task **task);
void		free_tr(t_task **task);
void		free_sp(t_task **task);
void		free_pl(t_task **task);
void		free_cy(t_task **task);
size_t		ft_size_t_len(size_t nr);
int		argc_error(char *str);
void		free_sq(t_task **task);
char		init(t_task **task, t_pars_vars **vars);
char		init_task(t_task **task);
void		error_con(t_pars_vars **vars, t_task **task);
short		error(t_pars_vars **vars, short ret, t_task **task);
char		char_parce(unsigned char *col, t_pars_vars **vars);
char		ft_check_Amb(char hit, char hit_dig, char b_char);
char		ft_parc_Amb(t_task **task, t_pars_vars **vars);
char		ft_Amb_con(t_task **task, t_pars_vars **vars, char *hit, char hit_dig);
char		ft_check_Amb2(char hit_dig, t_pars_vars **vars, char comma);
char		ft_Amb_con1(t_task **task, t_pars_vars **vars, char hit_dig);
char		ft_parc_res(t_task **task, t_pars_vars **vars);
char		ft_res_con(t_task **task, t_pars_vars **vars, char *hit, char hit_dig);
char		ft_check_res(char hit, char hit_dig, char b_char);
char		ft_check_light2(char hit_dig, t_pars_vars **vars, char comma);
char		ft_light_con(t_light **light, t_pars_vars **vars, char hit, char hit_dig);
char		ft_parc_light(t_task **task, t_pars_vars **pars);
char		ft_check_light(char hit, char hit_dig, char b_char);
char		ft_parc_light(t_task **task, t_pars_vars **vars);
void		ft_lstadd_back_l(t_light **lst, t_light *new);
char		ft_check_sp2(char hit_dig, t_pars_vars **vars, char comma);
char		ft_sp_con(t_sp **sp, t_pars_vars **vars, char hit, char hit_dig);
char		ft_sp_con2(t_sp **sp, t_pars_vars **vars, char hit_dig);
char		ft_check_sp(char hit, char hit_dig, char b_char);
char		ft_parc_sp(t_task **task, t_pars_vars **vars);
t_sp		*ft_new_sp();
t_sp		*ft_lstlast_sp(t_sp *lst);
void		ft_lstadd_back_sp(t_sp **lst, t_sp *new);
t_light		*ft_lstlast_l(t_light *lst);
t_light		*ft_new_light();
char		ft_check_pl(char hit, char hit_dig, char b_char);
char		ft_parc_pl(t_task **task, t_pars_vars **vars);
t_pl		*ft_new_pl();
t_pl		*ft_lstlast_pl(t_pl *lst);
void		ft_lstadd_back_pl(t_pl **lst, t_pl *new);
char		ft_check_pl2(char hit_dig, t_pars_vars **vars, char comma);
char		ft_pl_con(t_pl **camera, t_pars_vars **vars, char hit, char hit_dig);
char		ft_pl_con2(t_pl **camera, t_pars_vars **vars, char hit_dig);
char		ft_check_sq(char hit, char hit_dig, char b_char);
char		ft_parc_sq(t_task **task, t_pars_vars **vars);
t_sq		*ft_new_sq();
t_sq		*ft_lstlast_sq(t_sq *lst);
void		ft_lstadd_back_sq(t_sq **lst, t_sq *new);
char		ft_check_sq2(char hit_dig, t_pars_vars **vars, char comma);
char		ft_sq_con(t_sq **sq, t_pars_vars **vars, char hit, char hit_dig);
char		ft_sq_con2(t_sq **sq, t_pars_vars **vars, char hit_dig);
char		ft_check_cy(char hit, char hit_dig, char b_char);
char		ft_parc_cy(t_task **task, t_pars_vars **vars);
t_cy		*ft_new_cy();
t_cy		*ft_lstlast_cy(t_cy *lst);
void		ft_lstadd_back_cy(t_cy **lst, t_cy *new);
char		ft_check_cy2(char hit_dig, t_pars_vars **vars, char comma);
char		ft_cy_con(t_cy **cy, t_pars_vars **vars, char hit, char hit_dig);
char		ft_cy_con2(t_cy **cy, t_pars_vars **vars, char hit_dig);
char		ft_check_tr(char hit, char hit_dig, char b_char);
char		ft_parc_tr(t_task **task, t_pars_vars **vars);
t_tr		*ft_new_tr();
t_tr		*ft_lstlast_tr(t_tr *lst);
void		ft_lstadd_back_tr(t_tr **lst, t_tr *new);
char		ft_check_tr2(char hit_dig, t_pars_vars **vars, char comma);
char		ft_tr_con(t_tr **tr, t_pars_vars **vars, char hit, char hit_dig);
char		ft_tr_con2(t_tr **tr, t_pars_vars **vars, char hit_dig);
char		ft_check_tr3(char hit_dig, char comma);
char		ft_check_cy3(char hit_dig, char comma);
t_task		*new_task(int argc, char **argv);
#endif
