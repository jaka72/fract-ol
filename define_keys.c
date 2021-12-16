/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   define_keys.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 20:18:53 by jaka          #+#    #+#                 */
/*   Updated: 2021/12/01 14:10:47 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// CHANGE KEY NAMES ACCORDINGLY !!!
void	define_keys_linux(t_window *window)
{
	window->keys.arrow_down = 65362;
	window->keys.arrow_up = 65364;
	window->keys.arrow_right = 65363;
	window->keys.arrow_left = 65361;
	window->keys.i = 'i';
	window->keys.o = 'o';
	window->keys.esc = ESC_KEY;
	window->keys.col_scheme_1 = '1';
	window->keys.col_scheme_2 = '2';
	window->keys.col_scheme_3 = '3';
	window->keys.col_scheme_4 = '4';
	window->keys.decrease_iter = 'v';
	window->keys.increase_iter = 'b';
}

void	define_keys_mac(t_window *window)
{
	window->keys.i = 34;
	window->keys.o = 31;
	window->keys.arrow_right = 123;
	window->keys.arrow_left = 124;
	window->keys.arrow_down = 125;
	window->keys.arrow_up = 126;
	window->keys.esc = ESC_KEY;
	window->keys.col_scheme_1 = 18;
	window->keys.col_scheme_2 = 19;
	window->keys.col_scheme_3 = 20;
	window->keys.col_scheme_4 = 21;
	window->keys.decrease_iter = 9;
	window->keys.increase_iter = 11;
}

void	define_keys(t_window *window)
{
	if (SYSTEM == 'l')
		define_keys_linux(window);
	else if (SYSTEM == 'a')
		define_keys_mac(window);
}
