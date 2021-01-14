#include "minRT.h"

int     main()
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 1000, "HELLO WOLRD!");
	img.img = mlx_new_image(mlx, 1280, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//get_next_line(0, &line);
	ft_circle(&img, 1280, 1000, 45, 440, 250);
	ft_circle(&img, 1280, 1000, 45, 640, 450);
	ft_circle(&img, 1280, 1000, 45, 840, 650);
	ft_square(&img, 685, 295, 90);
	ft_square(&img, 495, 495, 90);
	ft_triangle(&img, 895, 295, 90);
	ft_triangle1(&img, 695, 495, 90);
//	ft_hex(&img, 845, 495, 80);
//	ft_hex1(&img, 895, 495, 90);
//	ft_hex2(&img, 195, 395, 90);
//	ft_hex3(&img, 895, 295, 90);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
