/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:47 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_length		get_length(char curr, char next)
{
	if (curr == 'h')
		return (next == 'h' ? HH : H);
	if (curr == 'l')
		return (next == 'l' ? LL : L);
	if (curr == 'j')
		return (J);
	if (curr == 'z')
		return (Z);
	return (DEFAULT_LENGTH);
}

int					ps_len(t_conversion *conv, t_format *format)
{
	char			curr;
	char			next;

	if (!((curr = *get_location(format)))
			|| !((next = *(get_location(format) + 1))))
		return (OKAY);
	conv->len = get_length(curr, next);
	if (conv->len != DEFAULT_LENGTH)
		format->i++;
	if (conv->len == HH || conv->len == LL)
		format->i++;
	return (OKAY);
}
