/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 16:35:36 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/11/30 15:32:14 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overflow(int sign, double num, const char *str, int i)
{
	if (sign == -1 && str[i] > '8')
		return (0);
	if (sign == -1 && num > 922337203685477580)
		return (0);
	if (sign == 1 && str[i] > '7')
		return (-1);
	if (sign == 1 && num > 922337203685477580)
		return (-1);
	else
	{
		num = (num * 10) + (str[i] - '0');
		return (num * sign);
	}
}

void	process_whole_part(int *i, const char *str, double *places_whole_nr,
			double *num)
{	
	*num = 0;
	if (str[*i] == '.')
		*places_whole_nr = 0;
	else
	{
		*places_whole_nr = 1;
		while (str[*i] != '.' && ft_isdigit(str[*i]))
		{
			*num = *num * 10 + str[*i] - '0';
			*places_whole_nr *= 10;
			(*i)++;
		}
	}
}

void	read_until_dec_point(int *i, const char *str, int *sign)
{
	*i = 0;
	*sign = 1;
	while (str[*i] == ' ' || (str[*i] >= '\t' && str[*i] <= '\r'))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	while (str[*i] == '0')
		(*i)++;
}

void	calculate_num(double *num, double places_whole_nr,
double places_decimal_nr, int is_dec_point)
{	
	if (is_dec_point == 0)
		;
	else if (is_dec_point != 0 && places_whole_nr != 0 && places_whole_nr != 10)
		*num = *num / places_whole_nr;
	else
		*num = *num / places_decimal_nr;
}

// NEED TO SAVE ATOF ALSO TO THE ORIGINAL LIBFT
// i AS THE ARG IS ALWAYS ZERO
double	ft_atof(const char *str, int i)
{
	int			sign;
	int			is_dec_point;
	double		num;
	double		places_whole_nr;
	double		places_decimal_nr;

	is_dec_point = 0;
	read_until_dec_point(&i, str, &sign);
	process_whole_part(&i, str, &places_whole_nr, &num);
	if (str[i] == '.')
	{
		i++;
		is_dec_point = 1;
	}
	places_decimal_nr = 1;
	while (str[i] && ft_isdigit(str[i]))
	{
		if (num >= 922337203685477580)
			return (overflow(sign, num, str, i));
		num = num * 10 + str[i] - '0';
		i++;
		places_decimal_nr *= 10;
	}
	calculate_num(&num, places_whole_nr, places_decimal_nr, is_dec_point);
	return (num * sign);
}
