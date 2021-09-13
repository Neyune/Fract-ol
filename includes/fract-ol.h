#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# define SIZE_X 1080
# define SIZE_Y 1080
# define NB_IT 350
# define MIDDLE_X SIZE_X/2
# define MIDDLE_Y SIZE_Y/2

typedef struct      s_data
{
    void    *mlx;
    void    *mlx_win;
    void    *mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}                   t_data;

typedef struct		s_fractal
{
		double zoom;
		double len_x;
		double len_y;
		double z_x;
		double z_y;
		double c_x;
		double c_y;

}					t_fractal;

unsigned int	mandelbrot(int x, int y, t_fractal values);
unsigned int	julia(int x, int y, t_fractal values);
int	ft_strisdigit(char *c);
int	ft_strcmp(const char *s1, const char *s2);
double	ft_atof(char *str);
void error_exit(t_data *mlx);
int deal_mouse(int button, int x, int y);
int	deal_key(int key, t_data *mlx);

#endif
