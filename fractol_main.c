/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_main.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 16:27:38 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/28 14:12:34 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// THIS EXAMPLE IS FROM "CODE INDIGO C++"


/*
image width		image height
512			512

255	max value of N in z_n (Mandelbrot formula)

min_real	max_real
-1,5		0,7    

min_imaginary	mx_imaginary
-1.0			1.0    


while (x*x + y*y < 2*2)  AND  iteration < max_iteration)
{
	xtemp = x*x - y*y + x0
	y = 2*x*y + y0
	x = xtemp
	iteration = iteration + 1
}
*/



//int	main(int argc, char *argv[])
// int	mainXXX(void)
// {
// 	t_window	window;
// 	get_resol_and_init_mlx(&window);
// 	mlx_hook(window.win, RED_CROSS_CODE, 1L << 17, &exit_cross, &window);
// 	my_pixel_put(&window, 20, 20, 0x00ffffff);
// 	mlx_put_image_to_window(window.mlx, window.win, window.img, 0, 0);

// 	mlx_loop(window.mlx);
// 	return (0);
// }


//int	main(int argc, char *argv[])
int	main(void)
{
	t_window	window;
//	int		x;
//	int		y;

//	if (argc != 2)
//		return (error(-1, "Error\n Number of arguments should be 2\n"));
//	if (read_map_data(argv[1], &window) == -1)
//		exit(0);
	get_resol_and_init_mlx(&window);
	init_keys(&window);
	define_keys(&window);

	mlx_hook(window.win, 2, (1L << 0), &key_press, &window);
//	mlx_hook(window.win, 3, (1L << 1), &key_release, &window);

//	mlx_key_hook(window.win, key_forward, &window.mlx);

	mlx_hook(window.win, RED_CROSS_CODE, 1L << 17, &exit_cross, &window);


	// get the required input values
	
	window.range.max_iterations = 100;
	window.color.color = 0x000aaa;
	// min_real = -1.5;
	// max_real = 0.7;
	// min_imgn = -1.0;
	// max_imgn = 1.0;

	// min_real = -0.2;
	// max_real = 0.8;
	// min_imgn = -0.1;
	// max_imgn = 1.0;

	// min_real = 0.2;
	// max_real = 1.2;
	// min_imgn = -0.05;
	// max_imgn = 0.95;

	window.range.min_real = -2.8;
	window.range.max_real = 2.5;
	window.range.min_imgn = -2.5;
	window.range.max_imgn = 2.5;


	// window.range.min_real = 0.2;
	// window.range.max_real = 1.2;
	// window.range.min_imgn = -0.05;
	// window.range.max_imgn = 0.95;

	printf("main, height %d\n", window.image.height);
	draw_image(&window);

	
	mlx_loop(window.mlx);

	return (0);

}
