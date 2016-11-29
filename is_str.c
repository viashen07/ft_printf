/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:46 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			add_precision(t_conversion *conv, char **str)
{
	char			*new;

	if (ft_strlen(*str) > conv->precision && conv->precision_set)
	{
		new = ft_strnew(conv->precision);
		ft_strncpy(*str, new, conv->precision);
		free(*str);
		*str = new;
	}
}

char				*is_str(t_conversion *conv
										, va_list ap)
{
	char			*str;

	if (!(str = va_arg(ap, char*)))
		return (ft_strdup("(null)"));
	str = ft_strdup(str);
	add_precision(conv, &str);
	return (str);
}
