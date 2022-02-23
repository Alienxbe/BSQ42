/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:46:24 by maykman           #+#    #+#             */
/*   Updated: 2022/02/23 14:08:32 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_error(int error)
{
	if (error == MAP_ERROR)
		ft_putstr(MAP_ERROR_MSG);
	else if (error == MALLOC_ERROR)
	{
		ft_putstr(MALLOC_ERROR_MSG);
		exit(1);
	}
	else if (error == GNL_ERROR)
	{
		ft_putstr(GNL_ERROR_MSG);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;
	int		out;

	if (argc < 2)
	{
		out = fill_tab(&data, NULL);
		ft_error(out);
		if (out != MAP_ERROR)
		{
			out = fill_with_bsq(&data, solve_tab(&data));
			ft_error(out);
			if (out != MAP_ERROR)
				print_tab(&data);
		}
		ft_free_tab(data.tab, data.height);
	}
	else
	{
		i = 0;
		while (++i < argc)
		{
			out = fill_tab(&data, argv[i]);
			ft_error(out);
			if (out != MAP_ERROR)
			{
				fill_with_bsq(&data, solve_tab(&data));
				print_tab(&data);
			}
			ft_free_tab(data.tab, data.height);
			ft_putchar('\n');
		}
	}
	return (0);
}
