/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:38:36 by ademurge          #+#    #+#             */
/*   Updated: 2022/02/22 19:13:18 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	check_plague(t_data data, int size, int x, int y)
{
	int	tmp;

	while (y < data.height && y < y + size)
	{
		tmp = x - 1;
		while (tmp < tmp + size && tmp < data.width)
			if (data.tab[y][tmp++])
				return (1);
		if (tmp >= data.width)
			return  (1);
		y++;
	}
	if (y >= data.height)
		return(1);
	else
		return (0);
}

t_sqr	plague(t_data *data,t_sqr *max, int x, int y)
{
	int	size_tmp;

	if (y + max->size >= data->height || x + max->size >= data->width)
		return (*max);
	while (check_plague(*data, max->size, x, y))
	{
		size_tmp = max->size + 1;
		if (check_plague(*data, size_tmp, x, y))
		{
			max->size++;
			max->y = y;
			max->x = x;
		}
	}
	return (*max);
}

t_sqr	solve_tab(t_data *data)
{
	t_sqr	max;
	int y;
	int x;

	max.size = 0;
	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (!data->tab[y][x])
			{
				max = plague(data, &max, x,y);
			}
		}
	}
	return (max);
} 

// int		fill_with_square