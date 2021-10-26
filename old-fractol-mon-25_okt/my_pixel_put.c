/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_pixel_put.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/03 12:21:29 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/22 17:25:05 by jaka          ########   odam.nl         */
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

// void	my_pixel_put(t_window *window, float x, float y, int color)
// {
// 	char	*dst;
// 	int		offset;

// 	x = (int)(x * window->map.field_size);
// 	y = (int)(y * window->map.field_size);
// 	offset = y * window->line_length + x * (window->bits_per_pixel / 8);
// 	dst = window->addr02 + offset;
// 	*(unsigned int *)dst = color;
// }
