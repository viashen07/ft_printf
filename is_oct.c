/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_oct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:46 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*is_octal(t_conversion *conv
										, va_list ap)
{
	char			*str;
	char			*final;
	uintmax_t		value;

	value = guna(conv->len, ap);
	if (!value && conv->precision_set)
		str = ft_strdup("");
	else
		str = ft_basetoa(value, 8);
	precision_pad(conv, &str);
	if (conv->flags.hashtag && str[0] != '0')
	{
		final = ft_strjoin("0", str);
		free(str);
	}
	else
		final = str;
	return (final);
}
