/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:47 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t				count_specials(char const *haystack, size_t length)
{
	size_t			blah;

	blah = ft_countchars(haystack, '\t', length)
			+ ft_countchars(haystack, '\n', length);
	return (blah);
}

void				print_format_error(t_format *format)
{
	intmax_t		tildes_before;
	intmax_t		tildes_after;

	ft_putstr_fd("(\"", 2);
	ft_putstr_literal_fd(format->str, 2);
	ft_putstr_fd("\")\n", 2);
	tildes_before = format->i
		+ count_specials(format->str, format->i);
	if (tildes_before > 0)
		ft_putcharn_fd('~', tildes_before, 2);
	ft_putchar_fd('^', 2);
	tildes_after = ft_strlen(format->str) - tildes_before - 1;
	tildes_after += count_specials(format->str + format->i
									, tildes_after + 1);
	if (tildes_after > 0)
		ft_putcharn_fd('~', tildes_after, 2);
	ft_putchar_fd('\n', 2);
}
