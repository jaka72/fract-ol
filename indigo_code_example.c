#include <stdio.h>
#include "fractol.h"

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

double	get_real(int x, int image_width, double min_real, double max_real)
{
	double	range;

	range = max_real - min_real;
	// [0, width]
	// [0, max_real - min_real] - val * range / width
	// [min_real, max_real] - last_step = min_real

	image_width = image_width * 8;

	return (x * (range / image_width) + min_real);
}

double	get_imgn(int y, int image_height, double min_imgn, double max_imgn)
{
	double	range;

	range = max_imgn - min_imgn;

	image_height = image_height * 8;

	return (y * (range / image_height) + min_imgn);
}

int	find_mandelbrot(double c_real, double c_imgn, int max_iterations)
{
	int	i;
	double	z_real;
	double	z_imgn;
	double	x_temp;

	z_real = 0.0;
	z_imgn = 0.0;
	i = 0;
//	printf("Start mandl: i%d\n", i);
	while (i < max_iterations && (z_real * z_real + z_imgn * z_imgn) < 4.0)
	{
		x_temp = z_real * z_real - z_imgn * z_imgn + c_real;
		z_imgn = 2.0 * z_real * z_imgn + c_imgn;
		z_real = x_temp;
		i++;
	}
	return (i);
}

void	get_resol_and_init_mlx(t_window *window)
{
//	window->map.field_width = 1;
	// window->width = window->data.resol_width;
	// window->height = window->data.resol_height;
	window->width = 500;
	window->height = 500;
//	check_screen_resol(window);
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, window->width,
			window->height, "Fractol");
	window->img = mlx_new_image(window->mlx, window->width, window->height);
	window->addr = mlx_get_data_addr(window->img, &window->bits_per_pixel,
			&window->line_length, &window->endian);
}


//int	main(int argc, char *argv[])
int	mainXXX(void)
{
	t_window	window;
	get_resol_and_init_mlx(&window);
	mlx_hook(window.win, RED_CROSS_CODE, 1L << 17, &exit_cross, &window);
	my_pixel_put(&window, 20, 20, 0x00ffffff);
	mlx_put_image_to_window(window.mlx, window.win, window.img, 0, 0);

	mlx_loop(window.mlx);
	return (0);
}


//int	main(int argc, char *argv[])
int	main(void)
{
	t_window	window;
	int		x;
	int		y;
	int		n;
	int		image_width;
	int		image_height;
	int		maxN;
	double	min_real;
	double	max_real;
	double	min_imgn;
	double	max_imgn;
	double	c_real;
	double	c_imgn;
	int		r;
	int		g;
	int		b;
	int		color;
	int		to_delete;

//	if (argc != 2)
//		return (error(-1, "Error\n Number of arguments should be 2\n"));
//	if (read_map_data(argv[1], &window) == -1)
//		exit(0);
	get_resol_and_init_mlx(&window);

	mlx_hook(window.win, 2, (1L << 0), &key_press, &window);
//	mlx_hook(window.win, 3, (1L << 1), &key_release, &window);

//	mlx_hook(window.win, RED_CROSS_CODE, 1L << 17, &exit_cross, &window);
	mlx_hook(window.win,             33, 1L << 17, &exit_cross, &window);

//	mlx_loop_hook(window.mlx, &render, &window);
//	init_keys(&window);
//	choose_keys(&window);
//	print_map_info(&window);
//	mlx_loop(window.mlx);


	// get the required input values
	image_width = 500;
	image_height = 500;
	maxN = 255;
	color = 0x000aaa;
	// min_real = -1.5;
	// max_real = 0.7;
	// min_imgn = -1.0;
	// max_imgn = 1.0;

	// min_real = -0.2;
	// max_real = 0.8;
	// min_imgn = -0.1;
	// max_imgn = 1.0;

	min_real = 0.2;
	max_real = 1.2;
	min_imgn = -0.05;
	max_imgn = 0.95;


	// For each iteration ...
//	while (maxN < 10)
//	{	
		// For every pixel ...
		y = 0;
		while (y < image_height) // Rows
		{
			x = 0;
			while (x < image_width) // Cols
			{
				// ... Find the real and imaginary value for c, corresponding
				//		to that x,y pixel in the image
				c_real = get_real(x, image_width, min_real, max_real);
				c_imgn = get_imgn(y, image_height, min_imgn, max_imgn);
				// ... Find the number of iterations in the Mandelbort formula
				//		using that c.
				n = find_mandelbrot(c_real, c_imgn, maxN);
				// ... Map the resulting number to an RGB value
				r = n % 256;
				g = n % 256;
				b = n % 256;
				// calculate hex color
				color = get_color(r, g, b);

	//			printf(" n%d ", n);
				if (n == 9)
				{
					color = 0xf00000;
					my_pixel_put(&window, x, y, color);
				}
				// else if (n == 3)
				// {
				// 	color = 0x00ff00;
				// 	my_pixel_put(&window, x, y, color);	
				// }
				// else if (n == 4)
				// {
				// 	color = 0x0000ff;
				// 	my_pixel_put(&window, x, y, color);
				// }
				// else if (n == 5)
				// {
				// 	color = 0xff00ff;
				// 	my_pixel_put(&window, x, y, color);
				// }
				// else if (n == 6)
				// {
				// 	color = 0x00ff0f;
				// 	my_pixel_put(&window, x, y, color);
				// }
				// else
				// {
				// 	color = 0x909090;
				// 	my_pixel_put(&window, x, y, color);
				// }
//				my_pixel_put(&window, x, y, color);
				// ... Output to the image
	//			printf(" %x ", color);
	//			printf(" %d ", x);

				color = get_color(r, g, b);
				my_pixel_put(&window, x, y, color);
				x++;
			}
			y++;
//		}
		mlx_put_image_to_window(window.mlx, window.win, window.img, 0, 0);

//		usleep(200000);
		maxN++;
//		printf("n%d, color:%x\n", n, color);
	}
	to_delete = r + g + b;
	to_delete = to_delete + 1 + color;
	
//	mlx_put_image_to_window(window.mlx, window.win, window.img, 0, 0);
	mlx_loop(window.mlx);

	return (0);

}
