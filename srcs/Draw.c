#include "fract-ol.h"

unsigned int		julia(int x, int y, t_fractal values)
{
			int it;
		double tmp;
		double result;
		unsigned int color;

		it = 0;
		if (values.c_x == 0 && values.c_y == 0)
		{
		values.c_x = -0.4;
		values.c_y = 0.6;
		}
		values.z_x = ((double)x / values.zoom - 1.5);
		values.z_y = ((double)y / values.zoom - 1.5);
		result = 0;
		while (it < NB_IT && result < 2)
		{
			it++;
			tmp = values.z_x;
			values.z_x = values.z_x * values.z_x - values.z_y * values.z_y + values.c_x;
			values.z_y = 2 * values.z_y * tmp + values.c_y;
			result = sqrt(values.z_x * values.z_x + values.z_y * values.z_y);
		}
		if (result >= 2)
			color = it * it * it;
		else
			color = 0;
		return(color);
}

// unsigned int		mandelbrot(int x, int y, t_fractal *valuess)
// {
// 			int it;
// 		double tmp;
// 		double result;
// 		unsigned int color;

// 		it = 0;
// 		values.c_x = ((double)x / (SIZE_X/3) - 2.1);
// 		values.c_y = ((double)y / (SIZE_Y/3) - 1.2);
// 		result = 0;
// 		while (it < NB_IT && result < 2)
// 		{
// 			it++;
// 			tmp = values.z_x;
// 			values.z_x = values.z_x * values.z_x - values.z_y * values.z_y + values.c_x;
// 			values.z_y = 2 * values.z_y * tmp + values.c_y;
// 			result = sqrt(values.z_x * values.z_x + values.z_y * values.z_y);
// 		}
// 		if (result >= 2)
// 			color = it * it * it;
// 		else
// 			color = 0;
// 		return(color);
// }

unsigned int		mandelbrot(int x, int y, t_fractal values)
{
		int it;
		double tmp;
		double result;
		unsigned int color;

		it = 0;
		values.c_x = ((double)x / values.zoom - 2.1) - ((double)x / (values.zoom * 1.2));
		values.c_y = ((double)y / values.zoom - 1.2) - ((double)y / (values.zoom * 1.2));
		values.z_x = 0;
		values.z_y = 0;
		result = 0;
		while (it < NB_IT && result < 2)
		{
			it++;
			tmp = values.z_x;
			values.z_x = values.z_x * values.z_x - values.z_y * values.z_y + values.c_x;
			values.z_y = 2 * values.z_y * tmp + values.c_y;
			result = sqrt(values.z_x * values.z_x + values.z_y * values.z_y);
		}
		if (result >= 2)
			color = it *it *it ;
		else
			color = 0;
		return(color);
}