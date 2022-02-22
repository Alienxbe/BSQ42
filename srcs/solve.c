/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:38:36 by ademurge          #+#    #+#             */
/*   Updated: 2022/02/22 22:40:26 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_obs(t_data *data, int size, int x, int y)
{
	int	i;
	int	j;

	i = y - 1;
	if (x + size >= data->height || y + size >= data->width)
		return (ERROR);
	while (++i < size)
	{
		j = x - 1;
		while (++j < size)
		{
			printf("testing [%d][%d]\n", y + i, x + j);
			if (y + i < data->height && x + j < data->width)
			{
				if (data->tab[x + i][x + j])
					return (ERROR);
			}
		}
	}
	return (0);
}

t_sqr	solve_tab(t_data *data)
{
	t_sqr	sqr;
	int		i;
	int		x;
	int		y;

	sqr.size = 0;
	sqr.x = 0;
	sqr.y = 0;
	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (!data->tab[y][x])
			{
				i = 0;
				while (!check_obs(data, sqr.size + i, x, y))
					i++;
				if (i)
				{
					sqr.size = sqr.size + i - 1;
					sqr.x = x;
					sqr.y = y;
				}
			}
		}
	}
	return (sqr);
}