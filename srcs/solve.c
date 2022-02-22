/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:38:36 by ademurge          #+#    #+#             */
/*   Updated: 2022/02/22 23:35:13 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_obs(t_data *data, t_sqr sqr)
{
	int	i;
	int	j;

	if (sqr.x + sqr.size - 1 >= data->width
		|| sqr.y + sqr.size - 1 >= data->height)
		return (ERROR);
	i = -1;
	while (++i < sqr.size)
	{
		j = -1;
		while (++j < sqr.size)
			if (data->tab[sqr.y + i][sqr.x + j])
				return (ERROR);
	}
	return (0);
}

t_sqr	find_biggest_sqr(t_data *data, int x, int y)
{
	t_sqr	sqr;

	sqr.x = x;
	sqr.y = y;
	sqr.size = 1;
	while (!check_obs(data, sqr))
		sqr.size++;
	sqr.size--;
	return (sqr);
}

t_sqr	solve_tab(t_data *data)
{
	t_sqr	sqr;
	t_sqr	tmp;
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
				tmp = find_biggest_sqr(data, x, y);
				if (tmp.size > sqr.size)
					sqr = tmp;
			}
		}
	}
	return (sqr);
}
