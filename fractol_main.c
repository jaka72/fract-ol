/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_main.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 16:27:38 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/12/05 11:29:27 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// x and y start as 0 at the top left corner fo the image
// mouse x and y are points in the plane range (cca -2 to 2)
// Divider is to adjust the start of drawing Julia from the distance
// of the corner
// MAYBE THE dividers CAN BE MOVED TO THE STRUCT TO SPEED UP THE PROCESS !!!!
int	get_mouse_position(int x, int y, t_window *w)
{
	int	divider_width;
	int	divider_height;

	divider_width = w->image.width / 4;
	divider_height = w->image.height / 4;
	if (x < w->image.width && y < w->image.height)
	{
		t_mouse_temp.x = ((float)w->image.width / 2 * -1 + (float)x)
			/ divider_width;
		t_mouse_temp.y = ((float)w->image.height / 2 - (float)y)
			/ divider_width;
		w->draw_image(w);
	}
	return (0);
}

int	check_if_float(char *str)
{
	int	i;
	int	is_point;

	i = 0;
	is_point = 0;
	if (str[i] != '-' && str[i] != '+' && !ft_isdigit(str[i]))
		return (-1);
	i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else if (str[i] == '.')
		{
			is_point++;
			i++;
		}
		else
			return (-1);
	}
	if (is_point > 1)
		return (-1);
	return (0);
}

int	check_args_for_julia(int argc, char *argv[], t_window *w)
{
	if (argc == 3 && check_if_float(argv[2]) == 0)
	{
		t_mouse_temp.x = ft_atof(argv[2], 0);
		t_mouse_temp.y = -0.01;
		return (0);
	}
	if (argc == 4 && check_if_float(argv[3]) == 0)
	{
		w->julia_start_c_real = ft_atof(argv[2], 0);
		w->julia_start_c_imgn = ft_atof(argv[3], 0);
		t_mouse_temp.x = w->julia_start_c_real;
		t_mouse_temp.y = w->julia_start_c_imgn;
		return (0);
	}
	else
		return (-1);
}

int	check_arguments(int argc, char *argv[], t_window *w)
{
	if (argc < 2 || (ft_strcmp(argv[1], "m") && ft_strcmp(argv[1], "j")
			&& ft_strcmp(argv[1], "b")))
		print_usage_and_exit();
	w->is_julia = 0;
	if (ft_strcmp(argv[1], "m") == 0)
		w->draw_image = draw_image_mandelbrot;
	else if (ft_strcmp(argv[1], "b") == 0)
		w->draw_image = draw_image_burningship;
	else if (ft_strcmp(argv[1], "j") == 0)
	{
		t_mouse_temp.x = -0.4;
		t_mouse_temp.y = +0.6;
		if (argc > 2)
			if (check_args_for_julia(argc, argv, w) < 0)
				print_usage_and_exit();
		w->is_julia = 1;
		w->draw_image = draw_image_julia;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_window	window;

	check_arguments(argc, argv, &window);
	get_resol_and_init_mlx(&window);
	window.range.max_iterations = 50;
	window.range.min_real = -2.8;
	window.range.max_real = 2.8;
	window.range.min_imgn = -2.6;
	window.range.max_imgn = 2.6;
	define_keys(&window);
	init_keys(&window);
	mlx_mouse_hook(window.win, mouse, &window);
	mlx_hook(window.win, 2, (1L << 0), key_press, &window);
	mlx_hook(window.win, 3, (1L << 1), key_release, &window);
	mlx_hook(window.win, RED_CROSS_CODE, 1L << 17, exit_cross, &window);
	if (window.is_julia == 1)
		mlx_hook(window.win, 06, 1L << 6, get_mouse_position, &window);
	mlx_loop_hook(window.mlx, render, &window);
	window.draw_image(&window);
	mlx_loop(window.mlx);
	return (0);
}
