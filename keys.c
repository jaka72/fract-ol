/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 15:16:11 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/26 18:47:30 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 0-right 1-left 2-forward 3-backwards 4-rotleft 5-rotright
void	init_keys(t_window *window)
{
	// window->key[0] = FALSE;
	// window->key[1] = FALSE;
	window->key[2] = FALSE;		// forward
	window->key[3] = FALSE;		// backward
	// window->key[4] = FALSE;
	// window->key[5] = FALSE;
}

 void	choose_keys(t_window *window)
{
	if (SYSTEM == 'l')
	{
		window->keys.s = 's';
		window->keys.w = 'w';
//		window->keys.d = 'd';
//		window->keys.a = 'a';
//		window->keys.arrow_left = 65361;
//		window->keys.arrow_right = 65363;
		window->keys.esc = 65307; // can replace ESC_KEY 
	}
	else if (SYSTEM == 'a')
	{
		window->keys.w = 13;
		window->keys.s = 1;
//		window->keys.d = 2;
//		window->keys.a = 0;
//		window->keys.arrow_left = 123;
//		window->keys.arrow_right = 124;
		window->keys.esc = 53;  // can replace ESC_KEY 
	}
}

int	key_press(int key, t_window *window)
{
	printf("key_press: [%d] \n", key);
	// if (key == window->keys.d)
	// 	window->key[RIGHT] = TRUE;
	// if (key == window->keys.a)
	// 	window->key[LEFT] = TRUE;
	if (key == window->keys.w) // 13
	{
		printf("   from key_press w: [%d] \n", key);
		window->key[FORW] = TRUE;
		zoom_in(window);
	}
	if (key == window->keys.s)  // 1
	{
		printf("    from key_press s: [%d] \n", key);
		window->key[BACKW] = TRUE;
		zoom_out(window);
	}
	// if (key == window->keys.arrow_left)
	// 	window->key[ROT_LEFT] = TRUE;
	// if (key == window->keys.arrow_right)
	// 	window->key[ROT_RIGHT] = TRUE;
//	if (key == window->keys.esc)		NOT WORKING !!!!
	if (key == ESC_KEY)  //ESC
	{
		printf("From key_press ESC\n");
		close_and_free(window);
	}
	return (0);
}

int	key_release(int key, t_window *window)
{
	// if (key == window->keys.d)
	// 	window->key[RIGHT] = FALSE;
	// if (key == window->keys.a)
	// 	window->key[LEFT] = FALSE;
	if (key == window->keys.w)
	 	window->key[FORW] = FALSE;
	if (key == window->keys.s)
	 	window->key[BACKW] = FALSE;
	// if (key == window->keys.arrow_left)
	// 	window->key[ROT_LEFT] = FALSE;
	// if (key == window->keys.arrow_right)
	// 	window->key[ROT_RIGHT] = FALSE;
	return (0);
}


int	key_forward(int keycode, t_window *w)
{
	if (keycode == 13)
		printf("From key_forward: %d  \n", keycode);
	if (keycode == ESC_KEY)
		close_and_free(w);
	w->temp = 1;
	return (0);
}
