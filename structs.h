/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 15:18:07 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/12/01 14:49:58 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

struct s_mouse_temp
{
	float	x;
	float	y;
} t_mouse_temp;

typedef struct s_keys
{
	int	arrow_up;
	int	arrow_down;
	int	arrow_left;
	int	arrow_right;
	int	i;
	int	o;
	int	esc;
	int	col_scheme_1;
	int	col_scheme_2;
	int	col_scheme_3;
	int	col_scheme_4;
	int	increase_iter;
	int	decrease_iter;
}	t_keys;

typedef struct s_ranges
{
	double	min_real;
	double	max_real;
	double	min_imgn;
	double	max_imgn;
	double	step_real;
	double	step_imgn;
	double	c_real;
	double	c_imgn;
	int		max_iterations;
	int		nr_iterations;
}	t_range;

typedef struct s_colors
{
	int		r;
	int		g;
	int		b;
	int		color;
	int		*arr_colors;
}	t_colors;

typedef struct s_image
{
	int	width;
	int	height;
}	t_image;

typedef struct s_windows
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
	int			key[6];
	t_keys		keys;
	t_range		range;
	t_colors	color;
	t_image		image;
	int			temp;
	int			is_julia;
	double		julia_real;
	double		julia_start_c_real;
	double		julia_start_c_imgn;
	double		julia_imgn;
	double		move_julia_real;
	double		move_julia_imgn;
	void		(*draw_image)();
	int			(*color_scheme)();
}	t_window;

#endif
