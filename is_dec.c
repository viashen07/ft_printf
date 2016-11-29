/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:46 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			add_pre(t_conversion *conv, char **str)
{
	char			*pre;
	char			*new;

	if (ft_isdigit((*str)[0]))
	{
		pre = NULL;
		if (conv->flags.begin_blank)
			pre = ft_strdup(" ");
		else if (conv->flags.sign)
			pre = ft_strdup("+");
		if (pre)
		{
			new = ft_strjoin(pre, *str);
			free(pre);
			free(*str);
			*str = new;
		}
	}
}

char				*is_dec(t_conversion *conv
										, va_list ap)
{
	char			*str;
	intmax_t		value;
	uintmax_t		unsigned_value;

	if (conv->spec == U_DECIMAL)
		unsigned_value = guna(conv->len, ap);
	else
		value = gna(conv->len, ap);
	if ((conv->spec == U_DECIMAL ? unsigned_value == 0 : value == 0)
		&& conv->precision_set && conv->precision == 0)
		str = ft_strdup("");
	else if (conv->spec == S_DECIMAL)
		str = ft_itoa_large(value);
	else
		str = ft_itoa_ularge(unsigned_value);
	add_pre(conv, &str);
	precision_pad(conv, &str);
	return (str);
}
