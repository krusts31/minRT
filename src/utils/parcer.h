#ifndef PARCER_H
# define PARCER_H
# include "varibles.h"
# include "get_next_line.h"
# include "../libs/libft/libft.h"

/*
**	Square
**	rotation: the rotation around noral vector constant and not deffined by user!
*/
t_cameraP	*ft_new_camera();
t_cameraP	*ft_lstlast_c(t_cameraP *lst);
char		ft_parc_camera(t_task **task, t_pars_vars **vars);
void		ft_lstadd_back_c(t_cameraP **lst, t_cameraP *new);
char		ft_cameraP_con(t_cameraP **camera, t_pars_vars **vars, char hit, char hit_dig);
char		ft_cameraP_con2(t_cameraP **camera, t_pars_vars **vars, char hit_dig);
char		ft_cameraP_con3(t_cameraP **camera, t_pars_vars **vars, char hit_dig);
char		ft_check_camera(char hit, char hit_dig, char b_char);
char		ft_check_camera2(char hit_dig, t_pars_vars **vars, char comma);
float		ft_atof(const char *nptr);
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
int		new_task(int argc, char **argv, t_task **task);
void		print_res(t_task *task);
void		free_var(t_pars_vars **vars);
char		free_task(t_task **task);
void		free_camera(t_task **task);
#endif
