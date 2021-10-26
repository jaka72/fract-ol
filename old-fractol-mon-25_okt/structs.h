/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 15:18:07 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/22 17:23:27 by jaka          ########   odam.nl         */
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

typedef struct s_windows
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
//	t_textures		tex;
}	t_window;

#endif
