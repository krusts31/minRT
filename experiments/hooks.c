#include "minRT.h"

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;



int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);

int             key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int close1(void *param)
{
    (void)param;
    exit(0);
}

int             close2(int keycode, t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}


int		mouse_press(int button, int x, int y, void *param)
{
	printf("x: %d y: %d\n", x, y);	
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	printf("x: %d y: %d\n", x, y);
	return (0);
}

int	say_hi()
{
	printf("Hello!\n");
	return (0);
}

//int key_press(int keycode, void *param);
#define Button1 53
int             main(void)
{
    t_vars      vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 6, 0, mouse_move, &vars);
	mlx_hook(vars.win, 5, 0, mouse_press, &vars);
	mlx_hook(vars.win, 17, 0, close1, &vars);
	mlx_hook(vars.win, 7, 0, say_hi, &vars);
    mlx_loop(vars.mlx);
	return (0);
} 
