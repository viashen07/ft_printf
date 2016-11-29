/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:47 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	filler_char(t_conversion *conv)
{
	if (conv->flags.zeros
		&& (conv->spec == HEX_LOWER
			|| conv->spec == HEX_UPPER))
		return ('0');
	return (' ');
}

void	total_padding(t_conversion *conv, char **str)
{
	char			*new;
	char			*padding;
	intmax_t		needs;

	needs = conv->width - ft_strlen(*str);
	if (needs > 0)
	{
		padding = ft_strnew(needs);
		ft_memset(padding, filler_char(conv), needs);
		if (conv->flags.l_justify)
			new = ft_strjoin(*str, padding);
		else
			new = ft_strjoin(padding, *str);
		free(*str);
		free(padding);
		*str = new;
	}
}
