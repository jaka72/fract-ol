/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 15:16:11 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/12/01 14:13:02 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//0-right 1-left 2-forward 3-backwards 4-zoom in, 5-zoom out
void	init_keys(t_window *window)
{
	window->key[0] = FALSE;
	window->key[1] = FALSE;
	window->key[2] = FALSE;
	window->key[3] = FALSE;
	window->key[4] = FALSE;
	window->key[5] = FALSE;
}

int	key_press(int key, t_window *w)
{
	if (key == w->keys.arrow_right)
		w->key[RIGHT] = TRUE;
	else if (key == w->keys.arrow_left)
		w->key[LEFT] = TRUE;
	else if (key == w->keys.arrow_up)
		w->key[UP] = TRUE;
	else if (key == w->keys.arrow_down)
		w->key[DOWN] = TRUE;
	else if (key == w->keys.i)
		w->key[ZOOM_IN] = TRUE;
	else if (key == w->keys.o)
		w->key[ZOOM_OUT] = TRUE;
	else if (key == w->keys.esc)
		close_and_free(w);
	else if (key == w->keys.increase_iter || key == w->keys.decrease_iter)
		change_max_iterations(key, w);
	else
		color_schemes(key, w);
	return (0);
}

int	key_release(int key, t_window *w)
{
	if (key == w->keys.arrow_right)
		w->key[RIGHT] = FALSE;
	if (key == w->keys.arrow_left)
		w->key[LEFT] = FALSE;
	if (key == w->keys.arrow_up)
		w->key[UP] = FALSE;
	if (key == w->keys.arrow_down)
		w->key[DOWN] = FALSE;
	if (key == w->keys.i)
		w->key[ZOOM_IN] = FALSE;
	if (key == w->keys.o)
		w->key[ZOOM_OUT] = FALSE;
	return (0);
}
