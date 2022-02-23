/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:28:22 by maykman           #+#    #+#             */
/*   Updated: 2022/02/23 11:56:52 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

void	ft_putstr(char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
}

static void	ft_putchar_tab(t_data *data, int n)
{
	if (!n)
		ft_putchar(data->block.empty);
	else if (n == 1)
		ft_putchar(data->block.obs);
	else
		ft_putchar(data->block.full);
}

void	print_tab(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
			ft_putchar_tab(data, data->tab[y][x]);
		ft_putchar('\n');
	}
}
