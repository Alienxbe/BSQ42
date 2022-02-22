/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:38:36 by ademurge          #+#    #+#             */
/*   Updated: 2022/02/22 17:42:43 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_plague(t_data data, int size, int x, int y)
{
	int	i;
	int	x_tmp;
	i = 0;
	while (check_if_in_tab(data, x, y))
	{
		while (y < data.height)
			{
				
				while ()
				
			}
			return (1);
		if (data.tab[y][x + i] == data.block.obs)
			return (1);
		
	}
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

int solve_tab(t_data *data)
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
				max = plague(&data, &max, x,y);
			}
		}
	}

}