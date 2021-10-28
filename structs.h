/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 15:18:07 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/28 12:22:31 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// typedef struct s_texx
// {
// 	void			*mlx;
// 	void			*img;
// 	char			*addr;
// 	int				endian;
// 	int				line_length;
// 	int				bits_per_pixel;
// 	int				x;
// 	int				rows;
// 	int				cols;
// 	int				cpc;
// 	int				i;
// 	unsigned int	*map;
// }	t_texx;

// typedef struct s_textures
// {
// 	t_texx	ea;
// 	t_texx	we;
// 	t_texx	no;
// 	t_texx	so;
// 	t_texx	sky;
// 	t_texx	sprite;
// }	t_textures;

typedef struct s_keys
{
//	int	arrow_right;
//	int	arrow_left;
//	int	w;
//	int	s;
	int	a;
	int	d;
	int	arrow_up;
	int	arrow_down;
	int	esc;
}	t_keys;

typedef struct s_ranges
{
	double	min_real;
	double	max_real;
	double	min_imgn;
	double	max_imgn;
	double	c_real;
	double	c_imgn;
	int		max_iterations;
	int		nr_iterations;
} t_range;


typedef struct s_colors
{
	int		r;
	int		g;
	int		b;
	int		color;
} t_colors;

typedef struct s_image
{
	int	width;
	int	height;
} t_image;


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
}	t_window;

#endif
