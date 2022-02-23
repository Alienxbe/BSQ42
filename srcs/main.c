/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:46:24 by maykman           #+#    #+#             */
/*   Updated: 2022/02/23 10:43:58 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_grid(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
			ft_putchar(data->tab[y][x] + '0');
		ft_putchar('\n');
	}
}

int	fill_with_square(t_data *data, t_sqr sqr)
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
	print_grid(&data);
	sqr.size = 4;
	sqr.x = 0;
	sqr.y = 3;
	//sqr = solve_tab(&data);
	printf("\n");
	//printf("hauteur = %d | largeur = %d | size : %d\n\n", sqr.y, sqr.x, sqr.size - 1);
	fill_with_square(&data, sqr);
	print_grid(&data);
	//ft_free_tab(data.tab, data.height);
	return (0);
}
