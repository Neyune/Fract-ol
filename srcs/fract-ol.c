
#include <unistd.h>
#include "fract-ol.h"
#include <stdio.h>


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 1869, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 1869, 9, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

/*
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1 , "\tYou must passed in parameter :\n·\t\tjulia\n·\t\tmandelbrot\n" , 57);
		return (0);
	}
	if (ft_strcmp(argv[1], "julia\0") == 0)
	{
		printf("%s" ,argv[1]);
	}
	else if (ft_strcmp(argv[1] ,"mandelbrot\0") == 0)
	{
		printf("%s" ,argv[1]);
	}
	else 
		write(1 , "\tYou must passed in parameter :\n·\t\tjulia\n·\t\tmandelbrot\n" , 57);
	return (0);
}
*/
