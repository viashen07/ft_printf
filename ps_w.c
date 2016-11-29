/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_w.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:47 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			width_too_long(t_conversion *conv, t_format *format)
{
	ft_putstr_fd("ft_printf: suspicious width given by * argument: ", 2);
	ft_putnbr_large_fd(conv->width, 2);
	ft_putstr_fd("\n", 2);
	print_format_error(format);
	return (ERROR);
}

int					ps_w(t_conversion *conv
								, va_list ap, t_format *format)
{
	size_t			i;
	char			current;

	if (*get_location(format) == '*')
	{
		conv->width = va_arg(ap, unsigned int);
		if (conv->width > LARGEST_STAR_ARGUMENT)
		{
			width_too_long(conv, format);
			conv->width = 0;
		}
		format->i++;
	}
	else
	{
		i = 0;
		while (((current = *(get_location(format) + i)))
				&& ft_isdigit(current))
		{
			ft_atoi_add_digit_u(current, &conv->width);
			i++;
		}
		format->i += i;
	}
	return (OKAY);
}
