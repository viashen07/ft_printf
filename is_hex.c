/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:46 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*is_hex(t_conversion *conv
										, va_list ap)
{
	char			*str;
	char			*final;
	uintmax_t		value;
	t_bool			is_zero_value;

	value = guna(conv->len, ap);
	if (!value && conv->precision_set)
		str = ft_strdup("");
	else
		str = ft_basetoa(value, 16);
	if (conv->spec == HEX_LOWER)
		ft_strtolower(str);
	is_zero_value = str[0] == '0' || str[0] == '\0';
	precision_pad(conv, &str);
	if ((conv->flags.hashtag && !is_zero_value)
		&& !(conv->precision_set && conv->precision == 0))
	{
		final = ft_strjoin(conv->spec == HEX_LOWER ? "0x" : "0X"
							, str);
		free(str);
	}
	else
		final = str;
	return (final);
}
