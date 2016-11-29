/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:26 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:03 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_large(intmax_t number)
{
	char	*new;
	int		length;

	if (number == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (number == 0)
		return (ft_strdup("0"));
	length = ft_count_digits_ularge(ft_abs_large(number));
	new = malloc(sizeof(char) * (length + (number < 0) + 1));
	if (number < 0)
	{
		new[0] = '-';
		ft_itoa_write(new + length, (uintmax_t) - number);
		new[length + 1] = '\0';
	}
	else
	{
		ft_itoa_write(new + length - 1, number);
		new[length] = '\0';
	}
	return (new);
}
