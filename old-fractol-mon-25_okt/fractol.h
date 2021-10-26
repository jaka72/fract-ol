/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/17 13:44:49 by jaka          #+#    #+#                 */
/*   Updated: 2021/10/22 18:23:15 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "./mlx_linux/mlx.h"

# include "./structs.h"
# include "./libft/libft.h"


# ifdef __linux__
#  define SYSTEM 'l'
#  define RED_CROSS_CODE 33
#  include <X11/Xlib.h>
# endif
# ifdef __APPLE__
#  define SYSTEM 'a'
#  define RED_CROSS_CODE 17
#  include <CoreGraphics/CGDisplayConfiguration.h>
# endif


# define TRUE 1
# define FALSE 0



// hit.wall_side
# define HOR 1
# define VER 2


int		key_press(int key, t_window *window);
int		exit_cross(t_window *window);
int		error(int n, char *msg);
int		error_close_fd(int n, int fd, char *msg);
int		close_and_free(t_window *window);

int		get_color(int r, int g, int b);
void	my_pixel_put(t_window *window, int x, int y, int color);


//void	print_map_info(t_window *window);

# define BLKB  "\e[40m"
# define HYEL  "\e[0;93m"
# define HGRN  "\e[0;92m"
# define HWHT  "\e[0;97m"
# define YEL   "\e[0;33m"
# define RED   "\x1B[31m"
# define REDB  "\e[41m"
# define GRN   "\x1B[32m"
# define LGRN  "\e[0;92m"
# define BLUBH "\e[44m"
# define BLUB  "\e[1;36m"
# define BLU   "\e[0;34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RES   "\x1B[0m"

#endif