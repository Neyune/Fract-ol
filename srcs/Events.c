#include "fract-ol.h"

int error_exit(int button, int x, int y, t_data *mlx)
{
	// if (mlx->mlx_img != NULL)
	// 	mlx_destroy_image(mlx->mlx_win, mlx->mlx_img);
	// mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
    return (0);
}

int deal_mouse(int button, int x, int y, void *params)
{
	printf("x = %i y = %i\n", x, y);
    return (0);
}

int	deal_key(int key, t_data *mlx)
{
	if (key == 0xff1b)
	{
		// if (mlx->mlx_img != NULL)
		// 	mlx_destroy_image(mlx->mlx_win, mlx->mlx_img);
		// mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		exit(0);
	}
    return (0);
}