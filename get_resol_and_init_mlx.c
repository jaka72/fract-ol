/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_resol_and_init_mlx.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 16:57:25 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/27 17:28:53 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_resol_and_init_mlx(t_window *window)
{
//	window->map.field_width = 1;
	// window->width = window->data.resol_width;
	// window->height = window->data.resol_height;
	window->width = 500;
	window->height = 500;
    window->image.width = window->width;
	window->image.height = window->height;
//	check_screen_resol(window);
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, window->width,
			window->height, "Fractol");
	window->img = mlx_new_image(window->mlx, window->width, window->height);
	window->addr = mlx_get_data_addr(window->img, &window->bits_per_pixel,
			&window->line_length, &window->endian);


	printf("get_resol, height %d\n", window->image.height);

}
