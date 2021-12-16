/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zoom_keys.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 16:19:00 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/11/30 16:06:56 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom_in(t_window *w)
{
	float	percentage_real;
	float	percentage_imgn;

	percentage_real = (w->range.max_real - w->range.min_real) * 0.1;
	percentage_imgn = (w->range.max_imgn - w->range.min_imgn) * 0.1;
	w->range.min_real += percentage_real;
	w->range.max_real -= percentage_real;
	w->range.min_imgn += percentage_imgn;
	w->range.max_imgn -= percentage_imgn;
	w->draw_image(w);
	return (0);
}

int	zoom_out(t_window *w)
{
	float	percentage_real;
	float	percentage_imgn;

	if (w->range.min_real > -6.0)
	{
		percentage_real = (w->range.max_real - w->range.min_real) * 0.1;
		percentage_imgn = (w->range.max_imgn - w->range.min_imgn) * 0.1;
		w->range.min_real -= percentage_real;
		w->range.max_real += percentage_real;
		w->range.min_imgn -= percentage_imgn;
		w->range.max_imgn += percentage_imgn;
		w->draw_image(w);
	}
	return (0);
}
