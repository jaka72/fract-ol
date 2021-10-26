/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_image.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 16:27:27 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/26 19:10:41 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int draw_image(t_window *w)
{
	int x;
	int y;

	y = 0;
	while (y < w->image.height) // Rows
	{
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
			// ... Map the resulting number to an RGB value
			w->color.r = w->range.nr_iterations % 256;
			w->color.g = w->range.nr_iterations % 256;
			w->color.b = w->range.nr_iterations % 256;
			// calculate hex color
			w->color.color = get_color(w);

//			printf(" n%d ", n);
			if (w->range.nr_iterations == 9)
			{
				w->color.color = 0xf00000;
				my_pixel_put(w, x, y, w->color.color);
			}
			else if (w->range.nr_iterations == 3)
			{
				w->color.color = 0x00ff00;
				my_pixel_put(w, x, y, w->color.color);	
			}
			else if (w->range.nr_iterations == 4)
			{
				w->color.color = 0x0000ff;
				my_pixel_put(w, x, y, w->color.color);
			}
			else if (w->range.nr_iterations == 5)
			{
				w->color.color = 0xff00ff;
				my_pixel_put(w, x, y, w->color.color);
			}
			else if (w->range.nr_iterations == 6)
			{
				w->color.color = 0x00ff0f;
				my_pixel_put(w, x, y, w->color.color);
			}
			else
			{
				w->color.color = 0x909090;
				my_pixel_put(w, x, y, w->color.color);
			}
//				my_pixel_put(&window, x, y, color);
			// ... Output to the image
//			printf(" %x ", color);
//			printf(" %d ", x);

//			w->color.color = get_color(w);
//			printf("       x%d,  color:%x \n", x, w->color.color);
			my_pixel_put(w, x, y, w->color.color);
			x++;
		}
//		printf(" y%d,  color:%x \n", y, w->color.color);
		y++;
//		}

		my_pixel_put(w, 50, 50, 0xffffff);
		mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);

//		usleep(200000);
		w->range.max_iterations++;
//		printf("n%d, color:%x\n", n, color);
	}
	return (0);
}
