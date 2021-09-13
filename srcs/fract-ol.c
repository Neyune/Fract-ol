
#include "fract-ol.h"

// unsigned int		pixel_color(int x, int y)
// {
// 		int color;

// 		color = mandelbrot(x, y);
// 		return (color);
// }

void	img_pixel_put(char *addr, int x, int y, unsigned int color)
{
	char	*pixel;

	pixel = addr + ((y * SIZE_X) + x) * 4;
	(*(unsigned int *)pixel) = color;
}

void	pixel_gen(t_data *mlx, int f, t_fractal values)
{
	 	int x; 
	 	int y;
	
		y = 0;
		while (y < SIZE_Y)
		{
			x = 0;
			while (x < SIZE_X)
			{
				if (f == 0)
					img_pixel_put(mlx->addr , x , y, mandelbrot(x, y, values));
				if (f == 1)
					img_pixel_put(mlx->addr , x , y, julia(x, y, values));
				x++;
			}
			y++;
		}
}

void	create_window(int f, t_fractal values)
{
	t_data	mlx;

	mlx =(t_data){};
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, SIZE_X, SIZE_Y, "Fractol\0");
	mlx.mlx_img = mlx_new_image(mlx.mlx, SIZE_X, SIZE_Y);
	mlx.addr = mlx_get_data_addr(mlx.mlx_img, &mlx.bits_per_pixel, &mlx.line_length,
								&mlx.endian);
	pixel_gen(&mlx, f, values);
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
	t_fractal values;

	values = (t_fractal){values.zoom = SIZE_X/3};
	// printf("%lf", values.zoom );
	if ((argc >= 4 && (!ft_strisdigit(argv[2]))) || (argc >= 4 && !(ft_strisdigit(argv[3]))))
		argc = 2;
	if (argc < 2)
		write(1 , "\tYou must use in parameter :\n·\t\tjulia\n·\t\tmandelbrot\n" , 54);
	else if (ft_strcmp(argv[1], "julia\0") == 0)
	{
		if (argc == 4)
		{
			values.c_x = ft_atof(argv[2]);
			values.c_y = ft_atof(argv[3]);
			// printf("X == %lf Y == %lf\n", ft_atof(argv[2]) , ft_atof(argv[3]));
		}
		create_window(1, values);
	}
	else if (ft_strcmp(argv[1] ,"mandelbrot\0") == 0)
		create_window(0, values);
	else 
		write(1 , "\tYou must use in parameter :\n·\t\tjulia\n·\t\tmandelbrot\n" , 54);
	return (0);
}