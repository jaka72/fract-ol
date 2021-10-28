/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_plane.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 15:29:40 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/28 12:23:12 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	move_left(t_window *w)
{
//	if (w->key[FORW] == TRUE)
	printf(" move left ...  \n");
	w->range.min_real += 0.2;
	w->range.max_real += 0.2;
	printf(" minR:%f, maxR:%f \n", w->range.min_real, w->range.max_real);
	draw_image(w);
	return (0);
}

int	move_right(t_window *w)
{
//	if (w->key[FORW] == TRUE)
	printf(" move left ...  \n");
	w->range.min_real -= 0.2;
	w->range.max_real -= 0.2;
	printf(" minR:%f, maxR:%f \n", w->range.min_real, w->range.max_real);
	draw_image(w);
	return (0);
}