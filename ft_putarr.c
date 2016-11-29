/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:45 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:06 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putarr(void const **source, size_t length, t_printer printer)
{
	size_t		i;

	i = 0;
	while (i < length)
	{
		ft_putchar('[');
		ft_putnbr(i);
		ft_putstr("::");
		printer(source[i]);
		ft_putchar(']');
		i++;
	}
}
