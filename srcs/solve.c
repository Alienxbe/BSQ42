/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:38:36 by ademurge          #+#    #+#             */
/*   Updated: 2022/02/23 10:43:53 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	check_plague(t_data data, int size, int x, int y)
{
	int	x_tmp;
	int y_tmp;

	y_tmp = y;
	if (!size)
		return (1);
	while ((y_tmp < data.height && y_tmp < y + size))
	{
		x_tmp = x;
		while ((x_tmp < x + size && x_tmp < data.width))
			if (data.tab[y_tmp][x_tmp++])
				return (0);
		if (x_tmp >= data.width)
			return (0);
		y_tmp++;
	}
	if (y >= data.height)
		return(0);
	else
		return (1);
}

t_sqr	plague(t_data *data,t_sqr *max, int x, int y)
{
	int	size_tmp;

	size_tmp = max->size;
	
	if (y + max->size > data->height || x + max->size > data->width)
		return (*max);
	printf("%d\n", size_tmp);
	while (check_plague(*data, ++size_tmp, x, y))
	{
			max->size++;
			max->y = y;
			max->x = x;
	}
	return (*max);
}

t_sqr	solve_tab(t_data *data)
{
	t_sqr	max;
	int y;
	int x;

	max.size = 0;
	max.x = 0;
	max.y = 0;
	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
			if (!data->tab[y][x])
				plague(data, &max, x,y);
	}
	return (max);
} 

