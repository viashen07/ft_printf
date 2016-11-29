/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:47 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ps_conv(t_conversion *conv
										, va_list arguments
										, t_format *format)
{
	if (ps_flg(conv, format) == OKAY
		&& ps_w(conv, arguments, format) == OKAY
		&& ps_prec(conv, arguments, format) == OKAY
		&& ps_len(conv, format) == OKAY
		&& ps_spec(conv, format) == OKAY)
		return (OKAY);
	return (ERROR);
}
