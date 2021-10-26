/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_mandelbrot.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 17:00:04 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/26 19:10:46 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	get_real(int x, t_window *w)
{
	double	range;

	range = w->range.max_real - w->range.min_real;
	// [0, width]
	// [0, max_real - min_real] - val * range / width
	// [min_real, max_real] - last_step = min_real

//	w->image.width = w->image.width * 8;

	return (x * (range / w->image.width) + w->range.min_real);
}

double	get_imgn(int y, t_window *w)
{
	double	range;

	range = w->range.max_imgn - w->range.min_imgn;

//	w->image.height = w->image.height * 8;

	return (y * (range / w->image.height) + w->range.min_imgn);
}

int	find_mandelbrot(t_window *w/*double c_real, double c_imgn, int max_iterations*/)
{
	int	i;
	double	z_real;
	double	z_imgn;
	double	x_temp;

	z_real = 0.0;
	z_imgn = 0.0;
	i = 0;
//	printf("Start mandl: i%d\n", i);
	while (i < w->range.max_iterations && (z_real * z_real + z_imgn * z_imgn) < 4.0)
	{
		x_temp = z_real * z_real - z_imgn * z_imgn + w->range.c_real;
		z_imgn = 2.0 * z_real * z_imgn + w->range.c_imgn;
		z_real = x_temp;
		i++;
	}
//	printf(" nr_iter:%d \n", i);
	return (i);
}
