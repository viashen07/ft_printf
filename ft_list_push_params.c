/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:39 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:04 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_push_params(int ac, char **av)
{
	int			i;
	t_list		*first_elem;

	if (ac == 0)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		ft_list_push_front(&first_elem, av[i]);
		i++;
	}
	return (first_elem);
}
