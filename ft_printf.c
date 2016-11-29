/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:45 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:06 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf(const char *format_str, ...)
{
	va_list			ap;
	t_format		format;

	if (!format_str)
	{
		ft_putendl_fd("ft_printf: format string must be valid", 2);
		exit(1);
	}
	ft_bzero(&format, sizeof(t_format));
	format.str = format_str;
	va_start(ap, format_str);
	run_formatter(&format, ap);
	va_end(ap);
	return (format.bytes);
}
