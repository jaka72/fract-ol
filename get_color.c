/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/22 17:43:06 by jaka          #+#    #+#                 */
/*   Updated: 2021/10/27 17:33:23 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	choose_color(t_window *w)
{
	if (w->range.nr_iterations == 1)		// white
		w->color.color = 0xffffff;
	else if (w->range.nr_iterations == 2)	// red
		w->color.color = 0xcc0000;
	else if (w->range.nr_iterations == 3)	// blue
		w->color.color = 0x0000cc;
	else if (w->range.nr_iterations == 4)	// orange
		w->color.color = 0xff6600;
	else if (w->range.nr_iterations == 5)	// violet
		w->color.color = 0x9900cc;
	else if (w->range.nr_iterations == 6)	// yellow
		w->color.color = 0xffcc00;
	else if (w->range.nr_iterations == 7)	// green
		w->color.color = 0x006600;
	else if (w->range.nr_iterations == 8)	// pink
		w->color.color = 0xff0066;
	else if (w->range.nr_iterations == 9)	// light blue
		w->color.color = 0xff0066;
	else if (w->range.nr_iterations == 10)	// light green
		w->color.color = 0x99ff66;
	else
		w->color.color = 0x909090;
	return (0);
}


int	calculate_color(t_window *w)
{
	if (w->color.r < 0)
		w->color.r = (w->color.r - 0xffffff00) * 0x10000;
	else
		w->color.r = w->color.r * 0x10000;
	if (w->color.g < 0)
		w->color.g = (w->color.g - 0xffffff00) * 0x100;
	else
		w->color.g = w->color.g * 0x100;
	if (w->color.b < 0)
		w->color.b = w->color.b - 0xffffff00;
	w->color.color = w->color.r + w->color.b + w->color.g;
	return (0);
}
