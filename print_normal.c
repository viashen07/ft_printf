/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:47 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*(*get_string_getter(t_specifier spec))()
{
	if (spec == STRING)
		return (is_str);
	else if (spec == POINTER)
		return (is_ptr);
	else if (spec == OCTAL)
		return (is_octal);
	else if (spec == BINARY)
		return (is_bin);
	else if (spec == HEX_UPPER || spec == HEX_LOWER)
		return (is_hex);
	return (is_dec);
}

void				print_normal(t_conversion *conv
									, va_list ap
									, t_format *format)
{
	char			*string;
	char			*(*getter)();

	getter = get_string_getter(conv->spec);
	string = getter(conv, ap, format);
	total_padding(conv, &string);
	ft_putstr(string);
	format->bytes += ft_strlen(string);
	free(string);
}
