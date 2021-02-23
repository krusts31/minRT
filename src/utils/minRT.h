#ifndef MINRT_H
# define MINRT_H
# include "../libs/minilibx/mlx.h"
# include "varibles.h"

/*
**	CAMERA FUNCTIONS 
*/

t_vec			*rand_in_unit_sphere(void);
t_ray			*get_ray(float u, float v, t_cameraP *cam);
t_camera		*new_camera(void);
int				init_col_var(t_col_var **var);
t_image_plane	*ft_init_image_plane(void);
t_image_plane	*new_image_plane(float FOV, float portion, t_cameraP *camera);
t_image_var		*ft_init_image(void);
void			*ft_free_image_vars(t_image_var **vars);
void			*ft_free_image(t_image_plane **plane);
void			*ft_image_error(t_image_var **var, t_image_plane **plane);
int				i_con2(t_image_plane **new, t_image_var **var, t_cameraP *c);

/*
**		VECTOR FUNTIONS
*/

void			*free_draw(t_draw **draw);
int				init_draw(t_draw **draw, int xs, int ys, int ns);
t_vec			*vec_copy(t_vec *src);
float			length_of_vector(t_vec *slef);
t_vec_uc		*new_vector_uc(int num1, int num2, int num3);
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
**		DRAW SQUARE
*/

int				ft_square(t_data *img, int x, int y, int size);

/*
**		TRIANGLE
*/

int				ft_triangle(t_data *img, int x, int y, int size);
int				ft_triangle1(t_data *img, int x, int y, int size);

/*
**		HEXAGON
*/

int				ft_hex1(t_data *img, int x, int y, int size);
int				ft_hex(t_data *img, int x, int y, int size);
int				ft_hex3(t_data *img, int x, int y, int size);
int				ft_hex2(t_data *img, int x, int y, int size);

/*
**		SPHERE
*/

int				hitable_list(t_ray *ray, float t_max, t_hit **hit, t_sp *sp);
int				hit_sp(t_ray *ray, float close, t_hit *hit, t_sp *sp);
char			c_sp(t_hit **hit, t_hit_sp **hit_sp, t_sp *sp, t_ray *ray);
char			ft_calc_sphere2(t_hit **hit, float temp, t_sp *sp, t_ray *ray);

/*
**		COLORS
*/

int				create_trgb(int t, int r, int g, int b);
int				get_b(int trgb);
int				get_g(int trgb);
int				get_r(int trgb);
int				get_t(int trgb);
t_vec			*get_color(t_task **task, t_draw **draw, int i, int j);
t_vec			*color(t_ray *ray, t_task **task);

/*
**		hit_list functions
*/

char			free_task(t_task **task);
int				is_hit(t_col_var **var, t_ray **ray, int *iter);
t_vec			*color_else2(t_col_var **var, t_vec **holding, int *iter);
t_vec			*c_e(t_col_var **var, t_vec **h, int *iter, t_ray **ray);
int				free_task_draw(t_task **task, t_draw **draw, int ret);
#endif
