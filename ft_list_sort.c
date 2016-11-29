/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:45 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:04 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_list_sort(t_list **first, int (*compare)(void*, void*))
{
	int		changed;
	t_list	*current;

	changed = 1;
	while (changed)
	{
		changed = 0;
		current = *first;
		while (current->next)
		{
			if (compare(current->data, current->next->data) > 0)
			{
				ft_ptrswp(&current->data, &current->next->data);
				changed = 1;
			}
			current = current->next;
		}
	}
}
