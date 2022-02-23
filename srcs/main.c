/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:46:24 by maykman           #+#    #+#             */
/*   Updated: 2022/02/23 11:31:55 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	fill_with_bsq(t_data *data, t_sqr sqr)
{
	int	y;
	int	x;
	
	y = sqr.y - 1;
	while (++y < sqr.y + sqr.size )
	{
		x = sqr.x - 1;
		while (++x < sqr.x + sqr.size)
			data->tab[y][x] = 2;
	}
	return (1);
}

int	main(void)
{
	t_data	data;
	t_sqr	sqr;
	int	o;

	o = fill_tab(&data, "map.test");
	printf("%d\n", o);
	print_tab(&data);
	sqr = solve_tab(&data);
	printf("\n");
	fill_with_bsq(&data, sqr);
	print_tab(&data);
	ft_free_tab(data.tab, data.height);
	return (0);
}
