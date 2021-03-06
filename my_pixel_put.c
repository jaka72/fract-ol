/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_pixel_put.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/03 12:21:29 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/11/15 17:19:23 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_window *window, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * window->line_length + x * (window->bits_per_pixel / 8);
	dst = window->addr + offset;
	*(unsigned int *)dst = color;
}
