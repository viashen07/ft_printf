/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:47 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			print_wide_str(t_conversion *conv
										, wchar_t *str
										, size_t *written)
{
	if (str)
		print_wide_chars(conv, str, ft_strlen_wide(str), written);
	else
	{
		ft_putstr("(null)");
		*written += 6;
	}
}

static void			print_wide_char(t_conversion *conv, wint_t wint
									, t_format *format)
{
	wchar_t	wchar;

	if (wint > 0x10FFFF)
	{
		ft_putstr_fd("ft_printf: invalid wide character encountered", 2);
		print_format_error(format);
	}
	else
	{
		wchar = (wchar_t)wint;
		print_wide_chars(conv, &wchar, 1, &format->bytes);
	}
}

void				print_conversion(t_conversion *conv, va_list ap
										, t_format *format)
{
	if (conv->len >= L && conv->spec == STRING)
		print_wide_str(conv, va_arg(ap, wchar_t*)
							, &format->bytes);
	else if (conv->spec == CHAR)
	{
		if (conv->len >= L)
			print_wide_char(conv, va_arg(ap, wchar_t), format);
		else
			print_char(conv, (char)va_arg(ap, int), format);
	}
	else
		print_normal(conv, ap, format);
}
