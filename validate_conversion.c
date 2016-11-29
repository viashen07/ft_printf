/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:47 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			put_length_string(t_length length)
{
	if (length == HH)
		ft_putstr_fd("hh", 2);
	else if (length == H)
		ft_putstr_fd("hh", 2);
	else if (length == L)
		ft_putstr_fd("l", 2);
	else if (length == LL)
		ft_putstr_fd("ll", 2);
	else if (length == J)
		ft_putstr_fd("j", 2);
	else if (length == Z)
		ft_putstr_fd("z", 2);
	else
		ft_putstr_fd("default", 2);
}

static int			pointer_has_specified_size(t_conversion *conversion
												, t_format *format)
{
	if (conversion->spec == POINTER
		&& conversion->len != DEFAULT_LENGTH)
	{
		ft_putstr_fd("ft_printf: length modifier '", 2);
		put_length_string(conversion->len);
		ft_putstr_fd("' results in undefined behavior or no effect ", 2);
		ft_putendl_fd("with 'p' conversion spec", 2);
		print_format_error(format);
		return (ERROR);
	}
	return (OKAY);
}

static int			precision_settable(t_conversion *conversion
										, t_format *format)
{
	char			spec;

	if (conversion->precision_set
		&& ((conversion->spec == CHAR && conversion->len >= L)
				|| conversion->spec == POINTER))
	{
		spec = *get_location(format);
		ft_putstr_fd("ft_printf: precision used with %", 2);
		ft_putchar_fd(spec, 2);
		if (spec == 'c')
		{
			ft_putstr_fd(" and length modifier '", 2);
			put_length_string(conversion->len);
			ft_putstr_fd("'", 2);
		}
		ft_putchar_fd('\n', 2);
		print_format_error(format);
		return (ERROR);
	}
	return (OKAY);
}

static int			is_it_okay(t_conversion *conversion
										, t_format *format)
{
	if (pointer_has_specified_size(conversion, format) == OKAY
		&& validate_flags(conversion, format) == OKAY
		&& precision_settable(conversion, format) == OKAY)
		return (OKAY);
	return (ERROR);
}

int					validate_conv(t_conversion *conversion
										, t_format *format)
{
	int				returned;

	format->i--;
	returned = is_it_okay(conversion, format);
	format->i++;
	return (returned);
}
