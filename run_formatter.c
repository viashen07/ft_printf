/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_formatter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:47 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			check_percent_percent(t_format *format)
{
	if (*get_location(format) == '%')
	{
		ft_putchar('%');
		format->i++;
		format->bytes++;
		return (1);
	}
	else
		return (0);
}

static void			handle_conv(t_format *format, va_list ap)
{
	t_conversion	conv;

	if (check_percent_percent(format))
		return ;
	ft_bzero(&conv, sizeof(conv));
	if (ps_conv(&conv, ap, format) == OKAY
		&& validate_conv(&conv, format) == OKAY)
		print_conversion(&conv, ap, format);
	else if (*get_location(format) == '%')
	{
		ft_putchar('%');
		format->i++;
		format->bytes++;
	}
}

void				run_formatter(t_format *format, va_list ap)
{
	char			current;

	while ((current = *get_location(format)))
	{
		if (current == '%')
		{
			format->i++;
			handle_conv(format, ap);
		}
		else
		{
			ft_putchar(current);
			format->bytes++;
			format->i++;
		}
	}
}
