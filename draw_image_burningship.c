/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_image_burningship.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 16:31:18 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/12/01 16:56:49 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// The equation for Mandelbrot
// f(x) = x2 + C
// C = 1 + 1i
// x = C
//		   Xr  Xi  *  Xr  Xi  +	 Cr  Ci
// f(x) = (1 + 1i) * (1 + 1i) + (1 + 1i) 
int	find_burningship(t_window *w)
{
	int		i;
	double	real;
	double	imgn;
	double	temp;

	real = 0.0;
	imgn = 0.0;
	i = 0;
	while (i < w->range.max_iterations && (real * real + imgn * imgn) < 4)
	{
		temp = real * real - imgn * imgn + w->range.c_real;
		imgn = fabs(2 * real * imgn) + w->range.c_imgn;
		real = temp;
		i++;
	}
	return (i);
}

// c_real and c_imgn represent 2 parts of a complex number,
// which represents a point on the complex plain
void	draw_image_burningship(t_window *w)
{
	int		x;
	int		y;
	double	step_real;
	double	step_imgn;

	step_real = (w->range.max_real - w->range.min_real) / w->image.width;
	step_imgn = (w->range.max_imgn - w->range.min_imgn) / w->image.height;
	y = 0;
	while (y < w->image.height)
	{
		x = 0;
		while (x < w->image.width)
		{
			w->range.c_real = x * step_real + w->range.min_real;
			w->range.c_imgn = y * step_imgn + w->range.min_imgn;
			w->range.nr_iterations = find_burningship(w);
			w->color_scheme(w);
			if (w->range.nr_iterations > w->range.max_iterations - 1)
				w->color.color = 0x000000;
			my_pixel_put(w, x, y, w->color.color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
}
