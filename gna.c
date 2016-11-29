/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gna.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:46 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		gna(t_length len, va_list ap)
{
	intmax_t	val;

	if (len == L)
		return (va_arg(ap, long));
	if (len == LL)
		return (va_arg(ap, long long));
	if (len == J)
		return (va_arg(ap, intmax_t));
	if (len == Z)
		return (va_arg(ap, size_t));
	val = va_arg(ap, int);
	if (len == HH)
		val = (char)val;
	else if (len == H)
		val = (short)val;
	else if (len == DEFAULT_LENGTH)
		val = (int)val;
	return (val);
}
