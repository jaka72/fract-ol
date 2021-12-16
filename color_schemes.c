/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_schemes.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 13:22:51 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/12/05 11:37:49 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_schemes(int key, t_window *w)
{
	if (key == w->keys.col_scheme_1)
	{
		w->color_scheme = color_scheme_zebra;
		w->draw_image(w);
	}
	else if (key == w->keys.col_scheme_2)
	{
		w->color_scheme = color_scheme_orange;
		w->draw_image(w);
	}
	else if (key == w->keys.col_scheme_3)
	{
		w->color_scheme = color_scheme_mix;
		w->draw_image(w);
	}
	return (0);
}

int	change_max_iterations(int key, t_window *w)
{
	if (key == w->keys.decrease_iter)
	{
		w->range.max_iterations -= 1;
		w->draw_image(w);
	}
	else if (key == w->keys.increase_iter)
	{
		w->range.max_iterations += 1;
		w->draw_image(w);
	}
	return (0);
}
