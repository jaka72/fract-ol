/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/22 17:43:06 by jaka          #+#    #+#                 */
/*   Updated: 2021/12/05 11:37:28 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Alternating black and white
int	color_scheme_zebra(t_window *w)
{
	if (w->range.nr_iterations % 2 == 0)
		w->color.color = 0xffffff;
	else
		w->color.color = 0x111111;
	return (0);
}

int	color_scheme_orange(t_window *w)
{
	if (w->range.nr_iterations % 10 == 0)
		w->color.color = 0xffff00;
	else if (w->range.nr_iterations % 10 == 1)
		w->color.color = 0x8b0000;
	else if (w->range.nr_iterations % 10 == 2)
		w->color.color = 0xFF4500;
	else if (w->range.nr_iterations % 10 == 3)
		w->color.color = 0xFF6347;
	else if (w->range.nr_iterations % 10 == 4)
		w->color.color = 0xE26310;
	else if (w->range.nr_iterations % 10 == 5)
		w->color.color = 0xF5761A;
	else if (w->range.nr_iterations % 10 == 6)
		w->color.color = 0xFD673A;
	else if (w->range.nr_iterations % 10 == 7)
		w->color.color = 0xFFA836;
	else if (w->range.nr_iterations % 10 == 8)
		w->color.color = 0xED9121;
	else if (w->range.nr_iterations % 10 == 9)
		w->color.color = 0xFF4F00;
	return (0);
}

int	color_scheme_mix(t_window *w)
{
	if (w->range.nr_iterations % 10 == 0)
		w->color.color = 0xffffff;
	else if (w->range.nr_iterations % 10 == 1)
		w->color.color = 0x646496;
	else if (w->range.nr_iterations % 10 == 2)
		w->color.color = 0xcc0000;
	else if (w->range.nr_iterations % 10 == 3)
		w->color.color = 0x0000cc;
	else if (w->range.nr_iterations % 10 == 4)
		w->color.color = 0xff6600;
	else if (w->range.nr_iterations % 10 == 5)
		w->color.color = 0x9900cc;
	else if (w->range.nr_iterations % 10 == 6)
		w->color.color = 0xffcc00;
	else if (w->range.nr_iterations % 10 == 7)
		w->color.color = 0x006600;
	else if (w->range.nr_iterations % 10 == 8)
		w->color.color = 0xff0066;
	else if (w->range.nr_iterations % 10 == 9)
		w->color.color = 0xff0066;
	return (0);
}
