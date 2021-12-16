/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 13:21:31 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/12/05 10:40:02 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_move_plane(t_window *w)
{
	if (w->key[LEFT] == TRUE)
		move_right(w);
	else if (w->key[RIGHT] == TRUE)
		move_left(w);
	else if (w->key[UP] == TRUE)
		move_up(w);
	else if (w->key[DOWN] == TRUE)
		move_down(w);
}

void	render_move_julia_plane(t_window *w)
{
	if (w->key[LEFT] == TRUE)
		move_right_julia(w);
	else if (w->key[RIGHT] == TRUE)
		move_left_julia(w);
	else if (w->key[UP] == TRUE)
		move_down_julia(w);
	else if (w->key[DOWN] == TRUE)
		move_up_julia(w);
}

void	render_zoom(t_window *w)
{
	if (w->key[ZOOM_IN] == TRUE)
		zoom_in(w);
	else if (w->key[ZOOM_OUT] == TRUE)
		zoom_out(w);
}

int	render(t_window *w)
{
	if (w->key[RIGHT] == TRUE || w->key[LEFT] == TRUE
		|| w->key[UP] == TRUE || w->key[DOWN] == TRUE)
	{
		if (w->is_julia == 1)
			render_move_julia_plane(w);
		else
			render_move_plane(w);
	}
	if (w->key[ZOOM_IN] == TRUE || w->key[ZOOM_OUT] == TRUE)
		render_zoom(w);
	return (0);
}
