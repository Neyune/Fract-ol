
#include "fract-ol.h"

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	void 	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// 	int		i;

// 	i = 0;
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img = mlx_new_image(mlx, 1920, 1080);
// 	// addr = mlx_get_data_addr(img, &bits_per_pixel, &line_length,
// 	// 							&endian);
// 	while (i < 700)
// 	{
// 		mlx_pixel_put(mlx, mlx_win, i, i, 0x00FF0000);
// 		i++;
// 	}
// 	mlx_loop(mlx);
// }

int		mandelbrot(int x, int y) 
{
		int i;
		int it;
		double init;
		double result;

		i = -1;
		it = 0;
		init = x + y ;
		result = init;
		while (it < NB_IT)
		{
			result = result * result + init; 
			it++;
		}
		return(result);
}

int		pixel_color(int x, int y)
{
		int color;

		printf("%d", mandelbrot(x,y));
		color = mandelbrot(x, y);
		return (color);
}

void	img_pixel_put(char *addr, int x, int y, int color)
{
	char	*pixel;

	pixel = addr + (y * SIZE_X) + x;
	(*(int *)pixel) = color;
}

void	pixel_gen(t_data *mlx)
{
	 	int x; 
	 	int y;
	
		y = 0;
		while (y <= SIZE_Y)
		{
			x = 0;
			while (x < SIZE_X)
			{
				img_pixel_put(mlx->addr, x, y, pixel_color(x,y));
				x++;
			}
			y += 2;
		}
}

void	create_window(char *str)
{
	t_data	mlx;

	mlx =(t_data){};
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, SIZE_X, SIZE_Y, str);
	mlx.mlx_img = mlx_new_image(mlx.mlx, SIZE_X, SIZE_Y);
	mlx.addr = mlx_get_data_addr(mlx.mlx_img, &mlx.bits_per_pixel, &mlx.line_length,
								&mlx.endian);
	pixel_gen(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.mlx_img, 0, 0);
	mlx_hook(mlx.mlx_win, 17, 0, error_exit , &mlx);
	mlx_key_hook(mlx.mlx_win, deal_key, &mlx);
	mlx_mouse_hook(mlx.mlx_win, deal_mouse, (void*)0);
	mlx_loop(mlx.mlx);
}

int	main(int argc, char **argv)
{
	int x;
	int y;

	if (argc < 2)
		write(1 , "\tYou must passed in parameter :\n·\t\tjulia\n·\t\tmandelbrot\n" , 57);
	else if (ft_strcmp(argv[1], "julia\0") == 0)
	{
		if (argc == 4)
		{
			x = ft_atoi(argv[2]);
			y = ft_atoi(argv[3]);
		}
		else
			create_window(argv[1]);
	}
	else if (ft_strcmp(argv[1] ,"mandelbrot\0") == 0)
	{
		create_window(argv[1]);
	}
	else 
		write(1 , "\tYou must passed in parameter :\n·\t\tjulia\n·\t\tmandelbrot\n" , 57);
	return (0);
}

