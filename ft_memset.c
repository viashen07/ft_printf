/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:45 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:06 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *destination, int int_value, size_t len)
{
	size_t			i;
	unsigned char	*location;
	unsigned char	value;

	value = (unsigned char)int_value;
	location = (unsigned char*)destination;
	i = 0;
	while (i < len)
	{
		location[i] = value;
		i++;
	}
	return (destination);
}
