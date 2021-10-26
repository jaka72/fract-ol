/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/22 17:43:06 by jaka          #+#    #+#                 */
/*   Updated: 2021/10/22 17:47:47 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int r, int g, int b)
{
	int color;
	if (r < 0)
		r = (r - 0xffffff00) * 0x10000;
	else
		r = r * 0x10000;
	if (g < 0)
		g = (g - 0xffffff00) * 0x100;
	else
		g = g * 0x100;
	if (b < 0)
		b = b - 0xffffff00;
	color = r + b + g;
	return (color);
}
