/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:46 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:07 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *first, const char *second, size_t size)
{
	size_t		end;
	size_t		i;

	if (size == 0)
		return (ft_strlen(second));
	end = ft_strlen(first);
	if (end > size - 1)
		return (size + ft_strlen(second));
	i = 0;
	while (second[i] && end + i < size - 1)
	{
		first[i + end] = second[i];
		i++;
	}
	first[i + end] = '\0';
	return (end + ft_strlen(second));
}
