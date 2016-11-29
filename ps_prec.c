/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:47 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			precision_too_long(t_conversion *conv
											, t_format *format)
{
	ft_putstr_fd("ft_printf: suspicious precision given by * argument: ", 2);
	ft_putnbr_large_fd(conv->precision, 2);
	ft_putstr_fd("\n", 2);
	print_format_error(format);
	return (ERROR);
}

static size_t		from_star(t_conversion *conv, va_list ap)
{
	conv->precision = va_arg(ap, unsigned int);
	conv->precision_set = 1;
	return (1);
}

static size_t		written_numbers(t_conversion *conv, t_format *format)
{
	size_t			i;
	char			curr;

	if (*get_location(format) == '-')
		i = 1;
	else
		i = 0;
	while (((curr = *(get_location(format) + i)))
			&& ft_isdigit(curr))
	{
		ft_atoi_add_digit_u(curr, &conv->precision);
		i++;
	}
	if (*get_location(format) == '-' && conv->precision == 0)
		return (0);
	else
	{
		conv->precision_set = 1;
		return (i);
	}
}

int					ps_prec(t_conversion *conv
									, va_list ap, t_format *format)
{
	size_t			length;

	if (*get_location(format) == '.')
	{
		format->i++;
		if (*get_location(format) == '*')
			length = from_star(conv, ap);
		else
			length = written_numbers(conv, format);
		if (conv->precision > LARGEST_STAR_ARGUMENT)
		{
			precision_too_long(conv, format);
			conv->precision = 0;
		}
		format->i += length;
	}
	return (OKAY);
}
