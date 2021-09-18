#include "fract-ol.h"

int	error_exit(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->mlx_img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx); 
	free(mlx->mlx);
	exit(0);
	return (0);
}

int deal_mouse(int button, int x, int y, t_fractal *values)
{
	// t_data	mlx;

	printf("x = %i y = %i\n", x, y);
	if (button == UP_SCROLL)
	{
		values->offset *= 0.8;
		// mlx_destroy_image(values->mlx.mlx, values->mlx.mlx_img);
		pixel_gen(&(values->mlx), values->f, *values);
	}
	if (button == DOWN_SCROLL)
	{
		values->offset *= 1.2;
		pixel_gen(&(values->mlx), values->f, *values);
	}
    return (0);
}

int	deal_key(int key, t_data *mlx)
{
	if (key == ESC)
		error_exit(mlx);
	if (key == W)
	{}
	if (key == S)
	{}
	if (key == A)
	{}
	if (key == D)
	{}	
    return (0);
}
