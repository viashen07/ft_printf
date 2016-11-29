/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:38:46 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:39:08 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		end_of_line(t_stock *stock)
{
	while (stock->lu > stock->line_end - stock->spill
			&& *(stock->line_end) != '\n')
		stock->line_end++;
	if (*(stock->line_end) == '\n')
		return (stock->lu > stock->line_end - stock->spill);
	return (0);
}

static int		increase_spill_size(t_stock *stock)
{
	char		*new_spill;
	long		new_size;

	new_size = stock->length * SPILL_MULT;
	if (new_size < stock->length + BUF_SIZE)
		new_size += BUF_SIZE;
	new_spill = malloc((new_size + 1) * sizeof(char));
	if (!new_spill)
		return (1);
	ft_strcpy(new_spill, stock->spill);
	new_spill[new_size] = '\0';
	stock->line_end = new_spill + (stock->line_end - stock->spill);
	free(stock->spill);
	stock->spill = new_spill;
	stock->length = new_size;
	return (0);
}

static int		setup(t_stock **stock)
{
	*stock = malloc(sizeof(t_stock));
	if (!*stock)
		return (1);
	(*stock)->length = BUF_SIZE;
	(*stock)->spill = malloc(((*stock)->length + 1) * sizeof(char));
	if (!(*stock)->spill)
		return (1);
	(*stock)->spill[(*stock)->length] = '\0';
	(*stock)->lu = 0;
	(*stock)->line_end = (*stock)->spill;
	(*stock)->read_ret = 1;
	return (0);
}

static int		deal_with_returns(t_stock **pointer_to_stock
									, t_stock *stock, char **line)
{
	if (stock->read_ret < 0)
		return (-1);
	*line = ft_strsub(stock->spill, 0, stock->line_end - stock->spill);
	if ((stock->read_ret <= 0 || stock->lu <= 0))
	{
		if (stock->spill)
			free(stock->spill);
		free(stock);
		*pointer_to_stock = NULL;
		return (0);
	}
	stock->lu += stock->spill - stock->line_end
		- (stock->read_ret > 0
			&& *(stock->line_end) == '\n'
			&& stock->lu != stock->line_end - stock->spill);
	ft_memcpy(stock->spill, stock->line_end + 1, stock->lu);
	stock->line_end = stock->spill;
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_stock	*stocks[MAX_FD];

	if (fd >= MAX_FD || fd < 0 || line == NULL)
		return (-1);
	if (stocks[fd] && stocks[fd]->read_ret == 0)
		return (0);
	if (!stocks[fd] && setup(&stocks[fd]))
		return (-1);
	while (stocks[fd]->read_ret > 0 && !((end_of_line(stocks[fd]))))
	{
		while (stocks[fd]->lu + BUF_SIZE > stocks[fd]->length)
			if (increase_spill_size(stocks[fd]))
				return (-1);
		stocks[fd]->read_ret = read(fd, stocks[fd]->spill + stocks[fd]->lu
									, stocks[fd]->length - stocks[fd]->lu);
		stocks[fd]->lu += stocks[fd]->read_ret;
	}
	return (deal_with_returns(&stocks[fd], stocks[fd], line));
}
