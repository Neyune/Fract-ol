/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 02:22:22 by ereali            #+#    #+#             */
/*   Updated: 2021/09/19 02:22:27 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	julia(int x, int y, t_fractal values)
{
	int				it;
	double			tmp;
	double			result;
	unsigned int	color;

	it = 0;
	values.z_x = (((double)x / values.zoom - 1.5) * values.offset);
	values.z_y = (((double)y / values.zoom - 1.5) * values.offset);
	result = 0;
	while (it < NB_IT && result < 4)
	{
		it++;
		tmp = values.z_x;
		values.z_x = values.z_x * values.z_x - values.z_y
			* values.z_y + values.c_x;
		values.z_y = 2 * values.z_y * tmp + values.c_y;
		result = values.z_x * values.z_x + values.z_y * values.z_y;
	}
	if (result >= 2)
		color = it * it * it;
	else
		color = 0;
	return (color);
}
// jolie julia  0.12 -0.6
// 0.12 -0.7
// 0.42 0.69

unsigned int	mandelbrot(int x, int y, t_fractal values)
{
	int				it;
	double			tmp;
	double			result;
	unsigned int	color;

	it = 0;
	values.c_x = (((double)x / values.zoom - 2.1) * values.offset);
	values.c_y = (((double)y / values.zoom - 1.2) * values.offset);
	values.z_x = 0;
	values.z_y = 0;
	result = 0;
	while (it < NB_IT && result < 4)
	{
		it++;
		tmp = values.z_x;
		values.z_x = values.z_x * values.z_x - values.z_y
			* values.z_y + values.c_x;
		values.z_y = 2 * values.z_y * tmp + values.c_y;
		result = values.z_x * values.z_x + values.z_y * values.z_y;
	}
	if (result >= 2)
		color = it * it * it ;
	else
		color = 0;
	return (color);
}
