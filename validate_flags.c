/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:47 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			show_positive_flags(t_conversion *conversion
											, t_format *format)
{
	if (conversion->flags.begin_blank
		|| conversion->flags.sign)
	{
		if (conversion->spec != S_DECIMAL)
		{
			ft_putstr_fd("ft_printf: flag '", 2);
			ft_putchar_fd(conversion->flags.sign ? '+' : ' ', 2);
			ft_putstr_fd("' results in undefined behavior with '", 2);
			ft_putchar_fd(*get_location(format), 2);
			ft_putendl_fd("' conversion specifier", 2);
			print_format_error(format);
			return (ERROR);
		}
	}
	return (OKAY);
}

static int			zero_flag(t_conversion *conversion
									, t_format *format)
{
	if (conversion->flags.zeros)
	{
		if (conversion->spec == CHAR
			|| conversion->spec == STRING
			|| conversion->spec == POINTER)
		{
			ft_putstr_fd("ft_printf: flag '0' results in undefined ", 2);
			ft_putstr_fd("behaviour with '", 2);
			ft_putchar_fd(*get_location(format), 2);
			ft_putendl_fd("' conversion specifier", 2);
			print_format_error(format);
			return (ERROR);
		}
	}
	return (OKAY);
}

static int			hashtag_flag(t_conversion *conversion
									, t_format *format)
{
	if (conversion->flags.hashtag)
	{
		if (!(conversion->spec == HEX_LOWER
				|| conversion->spec == HEX_UPPER
				|| conversion->spec == OCTAL))
		{
			ft_putstr_fd("ft_printf: flag '#' results in undefined ", 2);
			ft_putstr_fd("behaviour with ' ", 2);
			ft_putchar_fd(*get_location(format), 2);
			ft_putendl_fd("' conversion specifier", 2);
			print_format_error(format);
			return (ERROR);
		}
	}
	return (OKAY);
}

int					validate_flags(t_conversion *conversion
									, t_format *format)
{
	if (show_positive_flags(conversion, format) == OKAY
		&& zero_flag(conversion, format) == OKAY
		&& hashtag_flag(conversion, format) == OKAY)
	{
		validate_flags_ignored(conversion, format);
		return (OKAY);
	}
	return (ERROR);
}
