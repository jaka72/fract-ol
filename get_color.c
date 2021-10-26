/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/22 17:43:06 by jaka          #+#    #+#                 */
/*   Updated: 2021/10/26 16:40:50 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(t_window *w)
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
