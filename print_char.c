/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:46 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			print_char_and_padding(t_conversion *conv
											, char arg, char *str
											, t_format *format)
{
	if (arg)
		ft_putstr(str);
	else
	{
		if (conv->flags.l_justify)
			ft_putchar('\0');
		ft_putstr(str);
		if (!conv->flags.l_justify)
			ft_putchar('\0');
		format->bytes++;
	}
	format->bytes += ft_strlen(str);
}

void				print_char(t_conversion *conv, char arg
								, t_format *format)
{
	char			*str;

	str = ft_strnew(1);
	str[0] = arg;
	if (!arg && conv->width)
		conv->width--;
	total_padding(conv, &str);
	print_char_and_padding(conv, arg, str, format);
}
