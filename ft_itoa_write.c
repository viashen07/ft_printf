/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:28 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:03 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			write_digits(char *current, uintmax_t number)
{
	while (number)
	{
		*current = number % 10 + '0';
		number /= 10;
		current--;
	}
}

void				ft_itoa_write(char *last_digit, uintmax_t number)
{
	if (number == 0)
		*last_digit = '0';
	else
		write_digits(last_digit, number);
}
