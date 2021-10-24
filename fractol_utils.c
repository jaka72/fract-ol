/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/03 12:39:00 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/22 17:51:26 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	error(int n, char *msg)
{
	printf("%s\n", msg);
	return (n);
}

int	error_close_fd(int n, int fd, char *msg)
{
	close(fd);
	printf("%s\n", msg);
	return (n);
}

//int	exit_cross(t_window *window)
int	exit_cross(t_window *window)
{
	close_and_free(window);
	return (0);
}


int	close_and_free(t_window *window)
{
	mlx_destroy_image(window->mlx, window->img);
	exit(0);
}
