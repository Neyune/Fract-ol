#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# define SIZE_X 640
# define SIZE_Y 480
# define NB_IT 15

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

int	ft_strcmp(const char *s1, const char *s2);
int	ft_atoi(char *str);
int error_exit(int button, int x, int y, t_data *mlx);
int deal_mouse(int button, int x, int y, void *params);
int	deal_key(int key, t_data *mlx);

#endif
