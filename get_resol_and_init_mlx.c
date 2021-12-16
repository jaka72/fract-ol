/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_resol_and_init_mlx.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 16:57:25 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/12/01 17:18:02 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//	w->julia_start_c_real = 0; // probably not needed
//	w->julia_start_c_imgn = 0; // probably not needed
void	get_resol_and_init_mlx(t_window *w)
{
	w->width = 500;
	w->height = 500;
	if (w->is_julia == 1)
	{
		w->width = 500;
		w->height = 500;
	}
	w->image.width = w->width;
	w->image.height = w->height;
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, w->width,
			w->height, "Fractol");
	w->img = mlx_new_image(w->mlx, w->width, w->height);
	w->addr = mlx_get_data_addr(w->img, &w->bits_per_pixel,
			&w->line_length, &w->endian);
	w->move_julia_real = 0;
	w->move_julia_imgn = 0;
	w->color_scheme = color_scheme_zebra;
}
