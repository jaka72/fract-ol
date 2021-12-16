/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zoom_mouse.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/29 20:27:37 by jaka          #+#    #+#                 */
/*   Updated: 2021/11/30 16:26:52 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mouse_zoom_in(t_window *w, float pct_real, float pct_imgn)
{
	pct_real = (w->range.max_real - w->range.min_real) * 0.1;
	pct_imgn = (w->range.max_imgn - w->range.min_imgn) * 0.1;
	w->range.min_real += pct_real;
	w->range.max_real -= pct_real;
	w->range.min_imgn += pct_imgn;
	w->range.max_imgn -= pct_imgn;
	w->draw_image(w);
}

void	mouse_zoom_out(t_window *w, float pct_real, float pct_imgn)
{
	pct_real = (w->range.max_real - w->range.min_real) * 0.1;
	pct_imgn = (w->range.max_imgn - w->range.min_imgn) * 0.1;
	w->range.min_real -= pct_real;
	w->range.max_real += pct_real;
	w->range.min_imgn -= pct_imgn;
	w->range.max_imgn += pct_imgn;
	w->draw_image(w);
}

int	mouse(int mouse, int x, int y, t_window *w)
{
	float	percentage_real;
	float	percentage_imgn;

	(void)x;
	(void)y;
	percentage_real = 0.0;
	percentage_imgn = 0.0;
	if (mouse == 4)
		mouse_zoom_in(w, percentage_real, percentage_imgn);
	if (mouse == 5 && w->range.min_real > -6.0)
		mouse_zoom_out(w, percentage_real, percentage_imgn);
	return (0);
}
