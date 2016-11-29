/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:42 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:04 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_list_size(t_list *begin_list)
{
	if (begin_list->next == NULL)
		return (1);
	return (1 + ft_list_size(begin_list->next));
}
