/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_plane.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 15:29:40 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/11/30 15:47:15 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	move_left(t_window *w)
{
	float	percentage_real;

	percentage_real = (w->range.max_real - w->range.min_real) * 0.05;
	w->range.min_real += percentage_real;
	w->range.max_real += percentage_real;
	w->draw_image(w);
	return (0);
}

int	move_right(t_window *w)
{
	float	percentage_real;

	percentage_real = (w->range.max_real - w->range.min_real) * 0.05;
	w->range.min_real -= percentage_real;
	w->range.max_real -= percentage_real;
	w->draw_image(w);
	return (0);
}

int	move_up(t_window *w)
{
	float	percentage_imgn;

	percentage_imgn = (w->range.max_imgn - w->range.min_imgn) * 0.05;
	w->range.min_imgn += percentage_imgn;
	w->range.max_imgn += percentage_imgn;
	w->draw_image(w);
	return (0);
}

int	move_down(t_window *w)
{
	float	percentage_imgn;

	percentage_imgn = (w->range.max_imgn - w->range.min_imgn) * 0.05;
	w->range.min_imgn -= percentage_imgn;
	w->range.max_imgn -= percentage_imgn;
	w->draw_image(w);
	return (0);
}
