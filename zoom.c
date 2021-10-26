/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zoom.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 16:19:00 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/26 18:44:51 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

int	zoom_in(t_window *w)
{
	w->temp = 1;
//	if (w->key[FORW] == TRUE)
		printf(" zoom in...  \n");
	return (0);
}

int	zoom_out(t_window *w)
{

//	if (w->key[BACKW] == TRUE)
		w->temp = 1;
	printf("zoom out... \n");
	return (0);
}

