/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:45 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:04 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dest, const void *source
							, int stopper, size_t len)
{
	size_t			i;
	char			curr;

	i = 0;
	while (i < len)
	{
		curr = ((char*)source)[i];
		((char*)dest)[i] = curr;
		i++;
		if (curr == stopper)
			return ((char*)dest + i);
	}
	return (NULL);
}
