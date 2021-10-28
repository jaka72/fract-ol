/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_image.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 16:27:27 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/28 14:12:40 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int draw_image(t_window *w)
{

	printf("  draw image, height:%d \n", w->image.height);

	int x;
	int y;

	y = 0;
	while (y < w->image.height) // Rows
	{
//		printf("  y \n");

		x = 0;
		while (x < w->image.width) // Cols
		{
			// ... Find the real and imaginary value for c, corresponding
			//		to that x,y pixel in the image
			w->range.c_real = get_real(x, w);
			w->range.c_imgn = get_imgn(y, w);
			// ... Find the number of iterations in the Mandelbort formula
			//		using that c.
			w->range.nr_iterations = find_mandelbrot(w/*w->range.c_real, w->range.c_imgn, w->range.max_iterations*/);
			
			///////////////////////////////////////////
			// ... Map the resulting number to an RGB value
			// w->color.r = w->range.nr_iterations % 256;
			// w->color.g = w->range.nr_iterations % 256;
			// w->color.b = w->range.nr_iterations % 256;
			// calculate hex color
//			calculate_color(w);
			///////////////////////////////////////////

			choose_color(w);

//			printf(" %x ", color);
//			printf(" %d ", x);
//			printf("       x%d,  color:%x \n", x, w->color.color);

			my_pixel_put(w, x, y, w->color.color);
			x++;
		}
//		printf(" y%d,  color:%x \n", y, w->color.color);
		y++;

		mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);

//		usleep(2000);
//		w->range.max_iterations++;
//		printf("n%d, color:%x\n", n, color);
	}
	printf("  end draw image x%d, y%d\n", x , y);

	return (0);
}
