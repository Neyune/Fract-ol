
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

unsigned int		mandelbrot(int x, int y) 
{
		int i;
		int it;
		double c_x;
		double c_y;
		double z_x;
		double z_y;
		double tmp;
		double result;
		unsigned int color;

		// i =  SIZE_X/3;
		it = 0;
		c_x = (double)x / (SIZE_X/3) -2;
		// printf("valeur de x: %d\n", x);
		c_y = (double)y / (SIZE_Y/3) - 1.6;
		z_x = 0;
		z_y = 0;
		result = 0;
		while (it < NB_IT && result < 2)
		{
			it++;
			tmp = z_x;
			z_x = z_x * z_x - z_y * z_y + c_x;
			z_y = 2 * z_y * tmp + c_y;
			result = sqrt(z_x * z_x + z_y * z_y);
		}
		if (result >= 2)
			color = 0;
		color = it * it * it + 88888888888;
		return(color);
}

unsigned int		pixel_color(int x, int y)
{
		int color;

		color = mandelbrot(x, y);
		return (color);
}

void	img_pixel_put(char *addr, int x, int y)
{
	char	*pixel;

	pixel = addr + ((y * SIZE_X) + x)*4;
	(*(unsigned int *)pixel) = mandelbrot(x, y);
}

void	pixel_gen(t_data *mlx)
{
	 	int x; 
	 	int y;
	
		y = 0;
		while (y < SIZE_Y)
		{
			x = 0;
			while (x < SIZE_X)
			{
				img_pixel_put(mlx->addr , x , y);
				// mlx_pixel_put(mlx->mlx, mlx->mlx_win, x, y, pixel_color(x,y));
				x++;
			}
			y++;
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
	mlx_key_hook(mlx.mlx_win, deal_key, &mlx);
	mlx_mouse_hook(mlx.mlx_win, deal_mouse, (void*)0);
	mlx_hook(mlx.mlx_win, 17, 0, error_exit , &mlx);
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

