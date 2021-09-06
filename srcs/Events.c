#include "fract-ol.h"

void error_exit(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->mlx_img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
}

int deal_mouse(int button, int x, int y)
{
	printf("x = %i y = %i\n", x, y);
    return (0);
}

int	deal_key(int key, t_data *mlx)
{
	if (key == 0xff1b)
	{
		mlx_destroy_image(mlx->mlx, mlx->mlx_img);
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		exit(0);
	}
    return (0);
}