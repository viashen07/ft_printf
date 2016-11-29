/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:46 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *haystack, const char *needle)
{
	size_t		inner;

	if (needle[0] == '\0')
		return ((char*)haystack);
	while (*haystack)
	{
		inner = 0;
		while (haystack[inner] == needle[inner])
		{
			if (needle[inner + 1] == '\0')
				return ((char*)haystack);
			inner++;
		}
		haystack++;
	}
	return (NULL);
}
