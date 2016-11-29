/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_flags_ignored.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:47 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:13 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				begin_blank_show_sign(t_conversion *conversion
											, t_format *format)
{
	if (conversion->flags.begin_blank
		&& conversion->flags.sign)
	{
		ft_putendl_fd("flag ' ' is ignored when flag '+' is present", 2);
		print_format_error(format);
		conversion->flags.begin_blank = 0;
	}
}

void				pad_zeros_general(t_conversion *conversion
											, t_format *format)
{
	if (conversion->flags.zeros)
	{
		if (conversion->flags.l_justify)
		{
			ft_putendl_fd("flag '0' is ignored when flag '-' is present", 2);
			print_format_error(format);
			conversion->flags.zeros = 0;
		}
		else if (conversion->precision_set)
		{
			ft_putstr_fd("flag '0' is ignored with precision and %", 2);
			ft_putchar_fd(*get_location(format), 2);
			ft_putchar_fd('\n', 2);
			print_format_error(format);
			conversion->flags.zeros = 0;
		}
	}
}

void				validate_flags_ignored(t_conversion *conversion
											, t_format *format)
{
	begin_blank_show_sign(conversion, format);
	pad_zeros_general(conversion, format);
}
