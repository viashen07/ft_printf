/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_pad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:46 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			precision_padding_decimal(t_conversion *conv, char **str)
{
	intmax_t		len;
	intmax_t		needs;
	char			*new;
	int				offset;

	len = ft_strlen(*str);
	offset = ft_isdigit(**str) ? 0 : 1;
	needs = (conv->flags.zeros ?
				conv->width : conv->precision + offset) - len;
	if (needs > 0)
	{
		new = ft_strnew(len + needs + offset);
		if (offset)
			new[0] = **str;
		ft_memset(new + offset, '0', needs);
		ft_strcpy(new + needs + offset, *str + offset);
		free(*str);
		*str = new;
	}
}

static void			precision_padding_regular(t_conversion *conv, char **str)
{
	char			*new;
	intmax_t		needs;
	intmax_t		len;

	len = ft_strlen(*str);
	needs = (conv->flags.zeros ?
				conv->width : conv->precision) - len;
	if (needs > 0)
	{
		new = ft_strnew(len + needs);
		ft_memset(new, '0', needs);
		ft_strcpy(new + needs, *str);
		free(*str);
		*str = new;
	}
}

void				precision_pad(t_conversion *conv
											, char **str)
{
	if (conv->spec == S_DECIMAL
			|| conv->spec == U_DECIMAL)
		precision_padding_decimal(conv, str);
	else
		precision_padding_regular(conv, str);
}
