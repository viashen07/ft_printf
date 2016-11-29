/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:46 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*is_ptr(t_conversion *conv
											, va_list ap)
{
	char			*before;
	char			*str;
	long			val;

	val = (long)va_arg(ap, void*);
	if (val == 0)
		return (ft_strdup("0x0"));
	before = ft_basetoa(val, 16);
	ft_strtolower(before);
	str = ft_strjoin("0x", before);
	free(before);
	(void)conv;
	(void)ap;
	return (str);
}
