/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guna.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:46 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		guna(t_length len, va_list ap)
{
	uintmax_t	val;

	if (len == L)
		return (va_arg(ap, unsigned long));
	if (len == LL)
		return (va_arg(ap, unsigned long long));
	if (len == J)
		return (va_arg(ap, uintmax_t));
	if (len == Z)
		return (va_arg(ap, size_t));
	val = va_arg(ap, unsigned int);
	if (len == HH)
		val = (unsigned char)val;
	else if (len == H)
		val = (unsigned short)val;
	else if (len == DEFAULT_LENGTH)
		val = (unsigned int)val;
	return (val);
}
