/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_flg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:47 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool		*get_flag(char c, t_flags *flags)
{
	if (c == '-')
		return (&flags->l_justify);
	if (c == '0')
		return (&flags->zeros);
	if (c == '+')
		return (&flags->sign);
	if (c == ' ')
		return (&flags->begin_blank);
	if (c == '#')
		return (&flags->hashtag);
	return (NULL);
}

static int			repeated_flag(char offending_flag, t_format *format)
{
	ft_putstr_fd("ft_printf: repeated flag '", 2);
	ft_putchar_fd(offending_flag, 2);
	ft_putstr_fd("' in format\n", 2);
	print_format_error(format);
	return (1);
}

int					ps_flg(t_conversion *conv, t_format *format)
{
	t_bool			*flag;
	char			curr;

	while (((curr = *get_location(format)))
			&& ((flag = get_flag(curr, &conv->flags))))
	{
		if (*flag)
			return (repeated_flag(curr, format));
		*flag = 1;
		format->i++;
	}
	return (0);
}
