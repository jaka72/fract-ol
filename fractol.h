/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/17 13:44:49 by jaka          #+#    #+#                 */
/*   Updated: 2021/10/28 12:23:32 by jmurovec      ########   odam.nl         */
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
#  define ESC_KEY 65307
#  include <X11/Xlib.h>
# endif
# ifdef __APPLE__
#  define SYSTEM 'a'
#  define RED_CROSS_CODE 17
#  define ESC_KEY 53

#  include <CoreGraphics/CGDisplayConfiguration.h>
# endif


# define TRUE 1
# define FALSE 0



// 0[d], 1[a], 2[w], 3[s], 4[<--], 5[-->]
//# define RIGHT 0
# define LEFT 1
//# define FORW 2
//# define BACKW 3
# define ZOOM_IN 4
# define ZOOM_OUT 5


void	init_keys(t_window *window);
void	define_keys(t_window *window);
int		key_press(int key, t_window *window);
int		key_release(int key, t_window *window);
int		exit_cross(t_window *window);
int		error(int n, char *msg);
int		error_close_fd(int n, int fd, char *msg);
int		close_and_free(t_window *window);

double	get_real(int x, t_window *w);
double	get_imgn(int y, t_window *w);
int     draw_image(t_window *w);
int     find_mandelbrot(t_window *w/*double c_real, double c_imgn, int max_iterations*/);
int	    zoom_in(t_window *w);
int	    zoom_out(t_window *w);
int     move_left(t_window *w);
int	    move_right(t_window *w);


int     key_forward(int keycode, t_window *w);

void	get_resol_and_init_mlx(t_window *window);
int		choose_color(t_window *window);
int		calculate_color(t_window *window);
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