/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 02:23:12 by ereali            #+#    #+#             */
/*   Updated: 2021/09/19 03:17:04 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	error_exit(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->mlx_img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
	return (0);
}

int	deal_mouse(int button, int x, int y, t_fractal *values)
{
	(void)x;
	(void)y;
	if (button == UP_SCROLL)
	{
		values->offset *= 0.8;
		pixel_gen(&(values->mlx), values->f, values);
	}
	if (button == DOWN_SCROLL)
	{
		values->offset *= 1.2;
		pixel_gen(&(values->mlx), values->f, values);
	}
	return (0);
}

int	deal_key(int key, t_data *mlx)
{
	if (key == ESC)
		error_exit(mlx);
	return (0);
}
