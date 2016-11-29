/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:19 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:03 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_countchars(char const *haystack, char needle
										, size_t length)
{
	size_t			count;
	size_t			i;

	count = 0;
	i = 0;
	while (i < length)
	{
		if (haystack[i] == needle)
			count++;
		i++;
	}
	return (count);
}
