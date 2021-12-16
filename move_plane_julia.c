/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_plane_julia.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 15:29:40 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/11/30 15:46:44 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// GETS STUCK ??
// ?? w->move_julia_real = w->move_julia_real + percentage_real;
int	move_left_julia(t_window *w)
{
	float	percentage_real;

	percentage_real = (w->range.max_real - w->range.min_real) * 0.05;
	w->move_julia_real = w->move_julia_real + percentage_real;
	w->draw_image(w);
	return (0);
}

int	move_right_julia(t_window *w)
{
	float	percentage_real;

	percentage_real = (w->range.max_real - w->range.min_real) * 0.05;
	w->move_julia_real = w->move_julia_real - percentage_real;
	w->draw_image(w);
	return (0);
}

int	move_up_julia(t_window *w)
{
	float	percentage_imgn;

	percentage_imgn = (w->range.max_imgn - w->range.min_imgn) * 0.05;
	w->move_julia_imgn = w->move_julia_imgn + percentage_imgn;
	w->draw_image(w);
	return (0);
}

int	move_down_julia(t_window *w)
{
	float	percentage_imgn;

	percentage_imgn = (w->range.max_imgn - w->range.min_imgn) * 0.05;
	w->move_julia_imgn = w->move_julia_imgn - percentage_imgn;
	w->draw_image(w);
	return (0);
}
