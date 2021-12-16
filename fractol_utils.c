/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/03 12:39:00 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/12/05 11:33:24 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage_and_exit(void)
{
	printf(BLU"Usage example:"RES"\n     ./fract-ol  m\n");
	printf("      Mandelbrot = m,  Julia = j, Burning Ship = b\n");
	printf("      (for Julia, one or both params:  real = 0.285 imgn = 0.01)\n");
	printf(BLU"\nKeys:\n"RES);
	printf("       i = Zoom IN,  o = Zoom OUT\n");
	printf("       Arrows = Move left, right, up, down\n");
	printf(BLU"\nTo change color scheme press:\n"RES);
	printf("      1 = Zebra, 2 = Sunrise, 3 = Mix\n");
	printf(BLU"\nTo change number of iterations:\n"RES);
	printf("      v = increase,  b = decrease\n\n");
	exit(0);
}

int	free_all(t_window *w)
{
	free(w->color.arr_colors);
	return (0);
}

int	error(int n, char *msg)
{
	printf("%s\n", msg);
	return (n);
}

int	exit_cross(t_window *window)
{
	close_and_free(window);
	free_all(window);
	return (0);
}

int	close_and_free(t_window *window)
{
	mlx_destroy_image(window->mlx, window->img);
	free_all(window);
	exit(0);
}
