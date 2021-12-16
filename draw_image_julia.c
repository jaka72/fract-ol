/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_image_julia.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 16:27:27 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/12/05 10:37:42 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	find_julia(t_window *w, int x, int y)
{
	int		i;
	double	temp;

	w->julia_real = 2 * w->range.max_real * x / w->image.width
		- w->range.max_real;
	w->julia_imgn = 2 * w->range.max_imgn * y / w->image.height
		- w->range.max_imgn;
	w->julia_imgn *= -1;
	w->julia_real = w->julia_real + w->move_julia_real;
	w->julia_imgn = w->julia_imgn + w->move_julia_imgn;
	w->range.c_real = t_mouse_temp.x;
	w->range.c_imgn = t_mouse_temp.y;
	i = 0;
	while (i < w->range.max_iterations && (w->julia_real * w->julia_real
			+ w->julia_imgn * w->julia_imgn) < 2.5)
	{
		temp = w->julia_real;
		w->julia_real = w->julia_real * w->julia_real - w->julia_imgn
			* w->julia_imgn + w->range.c_real;
		w->julia_imgn = 2 * temp * w->julia_imgn + w->range.c_imgn;
		i++;
	}
	return (i);
}

void	draw_image_julia(t_window *w)
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
			w->range.nr_iterations = find_julia(w, x, y);
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
