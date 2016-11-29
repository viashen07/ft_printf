/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ularge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:27 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:03 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		write_chars(char *first, char *now, uintmax_t number)
{
	while (now >= first)
	{
		*now = number % 10 + '0';
		number /= 10;
		now--;
	}
}

char			*ft_itoa_ularge(uintmax_t number)
{
	char	*new;
	int		length;

	if (number == 0)
		return (ft_strdup("0"));
	length = ft_count_digits_ularge(number);
	new = malloc(sizeof(char) * (length + 1));
	write_chars(new, new + length - 1, number);
	new[length] = '\0';
	return (new);
}
