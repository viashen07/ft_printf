/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:08 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:03 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		numbers_part(const char *str, long long number, int negative)
{
	while (*str <= '9' && *str >= '0')
	{
		number = number * 10 + *str - '0';
		str++;
		if (number < 0)
		{
			if (negative == 1)
				return (0);
			return (-1);
		}
	}
	if (negative)
		number = -number;
	return (number);
}

int				ft_atoi(const char *str)
{
	long long	number;
	int			negative;

	negative = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' && str++)
		negative = 1;
	else if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	number = 0;
	return (numbers_part(str, number, negative));
}
