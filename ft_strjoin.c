/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:46 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:07 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *first, char const *second)
{
	char	*both;
	size_t	first_len;
	size_t	second_len;

	first_len = ft_strlen(first);
	second_len = ft_strlen(second);
	both = malloc(sizeof(char) * (first_len + 1 + second_len + 1));
	if (!both)
		return (NULL);
	ft_strncpy(both, first, first_len);
	ft_strcpy(both + first_len, second);
	return (both);
}
