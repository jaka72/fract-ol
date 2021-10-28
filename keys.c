/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 15:16:11 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/28 12:22:38 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 0-right 1-left 2-forward 3-backwards 4-rotleft 5-rotright
void	init_keys(t_window *window)
{
	// window->key[0] = FALSE;
	// window->key[1] = FALSE;
	//window->key[2] = FALSE;		// forward
	//window->key[3] = FALSE;		// backward
	window->key[4] = FALSE;
	window->key[5] = FALSE;
}

void	define_keys(t_window *window)
{
	if (SYSTEM == 'l')
	{
//		window->keys.s = 's';
//		window->keys.w = 'w';
//		window->keys.d = 'd';
//		window->keys.a = 'a';
		window->keys.arrow_up = 126;  // ??
		window->keys.arrow_down = 125; // ??
		window->keys.esc = ESC_KEY; // can replace ESC_KEY , 65307
	}
	else if (SYSTEM == 'a')
	{
		window->keys.arrow_up = 126;
		window->keys.arrow_down = 125;
		window->keys.d = 2;
		window->keys.a = 0;
//		window->keys.arrow_left = 123;
//		window->keys.arrow_right = 124;
		window->keys.esc = ESC_KEY;  // can replace ESC_KEY 
	}
}


// arrow up 126, arrow down 125
int	key_press(int key, t_window *window)
{
	printf("key_press: [%d] \n", key);

	if (key == window->keys.arrow_up) // 126
	{
		printf("   from key_press arrow_up: [%d] \n\n", key);
//		window->key[ZOOM_IN] = TRUE;
		zoom_in(window);
	}

	if (key == window->keys.arrow_down)  // 125
	{
		printf("    from key_press arrow_down: [%d] \n\n", key);
		zoom_out(window);
	}

	if (key == window->keys.a)  // 'a'
	{
		printf("    from key_press arrow_down: [%d] \n\n", key);
		move_left(window);
	}
	if (key == window->keys.d)  // 'a'
	{
		printf("    from key_press arrow_down: [%d] \n\n", key);
		move_right(window);
	}



	if (key == ESC_KEY)  // ESC
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
	if (key == window->keys.arrow_up)
	 	window->key[ZOOM_IN] = FALSE;
	if (key == window->keys.arrow_down)
	 	window->key[ZOOM_OUT] = FALSE;
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
