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

# define ESC			0xff1b
# define W				119
# define A				97
# define S				115
# define D				100
# define SP				32
# define UP_SCROLL		4
# define DOWN_SCROLL	5

typedef struct      s_data
{
    void    *mlx;
    void    *mlx_win;
    void    *mlx_img;
	char	*addr;
	char	*addr2;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}                   t_data;

typedef struct		s_rgb
{
	unsigned int r;
	unsigned int g;
	unsigned int b;
}					t_rgb;

typedef struct		s_fractal
{
		t_data	mlx;
		double	zoom;
		double	offset;
		double	z_x;
		double	z_y;
		double	c_x;
		double	c_y;
		int		f;
		t_rgb	color;

}					t_fractal;


unsigned int	mandelbrot(int x, int y, t_fractal values);
unsigned int	julia(int x, int y, t_fractal values);
int				ft_strisdigit(char *c);
int				ft_strcmp(const char *s1, const char *s2);
double			ft_atof(char *str);
void			pixel_gen(t_data *mlx, int f, t_fractal values);
int				error_exit(t_data *mlx);
int				deal_mouse(int button, int x, int y, t_fractal *values);
int				deal_key(int key, t_data *mlx);

#endif
