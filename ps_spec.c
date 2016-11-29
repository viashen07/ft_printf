/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:47 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			reached_end_while_parsing(t_format *format)
{
	if (*(format->str - 1) == '%')
		ft_putstr_fd("ft_printf: spurious trailing '%' in format\n", 2);
	else
		ft_putstr_fd("ft_printf: conv lacks type at end of format\n", 2);
	print_format_error(format);
	return (1);
}

static int			invalid_specifier(char c, t_format *format)
{
	ft_putstr_fd("ft_printf: unknown conv type character '", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("' in format\n", 2);
	print_format_error(format);
	return (1);
}

static int			mixed_masquerading_and_length(t_length len, char c
													, t_format *format)
{
	ft_putstr_fd("ft_printf: use of '", 2);
	if (len == HH || len == LL)
		ft_putstrn_fd(get_location(format) - 2, 2, 2);
	else
		ft_putstrn_fd(get_location(format) - 1, 1, 2);
	ft_putstr_fd("' length modifier with '", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("' type character\n", 2);
	print_format_error(format);
	return (1);
}

static t_specifier	get_specifier(char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (S_DECIMAL);
	if (c == 'u' || c == 'U')
		return (U_DECIMAL);
	if (c == 'o' || c == 'O')
		return (OCTAL);
	if (c == 'x')
		return (HEX_LOWER);
	if (c == 'b')
		return (BINARY);
	if (c == 'X')
		return (HEX_UPPER);
	if (c == 'c' || c == 'C')
		return (CHAR);
	if (c == 's' || c == 'S')
		return (STRING);
	if (c == 'p')
		return (POINTER);
	return (INVALID_SPECIFIER);
}

int					ps_spec(t_conversion *conv
									, t_format *format)
{
	char			current;

	if (!((current = *get_location(format))))
		return (reached_end_while_parsing(format));
	conv->spec = get_specifier(current);
	if (conv->spec == INVALID_SPECIFIER)
		return (invalid_specifier(current, format));
	if (current == 'D' || current == 'U' || current == 'O'
		|| current == 'C' || current == 'S')
	{
		if (conv->len != DEFAULT_LENGTH)
			mixed_masquerading_and_length(conv->len
											, current, format);
		conv->len = L;
	}
	format->i++;
	return (0);
}
