/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_literal_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:46 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:07 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			print_literal(char c, int fd)
{
	if (c == '\n')
		ft_putstr_fd("\\n", fd);
	else if (c == '\t')
		ft_putstr_fd("\\t", fd);
	else
		ft_putchar_fd(c, fd);
}

void				ft_putstr_literal_fd(char const *source
											, int file_descriptor)
{
	while (*source)
	{
		print_literal(*source, file_descriptor);
		source++;
	}
}
