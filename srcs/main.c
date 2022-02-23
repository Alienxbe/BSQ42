/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:46:24 by maykman           #+#    #+#             */
/*   Updated: 2022/02/23 16:59:15 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_error(int error)
{
	if (error == MAP_ERROR || error == GNL_ERROR)
		ft_putstr(MAP_ERROR_MSG);
	else if (error == MALLOC_ERROR)
	{
		ft_putstr(MALLOC_ERROR_MSG);
		exit(1);
	}
}

void	ft_solve_map(char *filename)
{
	t_data	data;
	int		out;

	data.tab = NULL;
	out = fill_tab(&data, filename);
	ft_error(out);
	if (out != MAP_ERROR && data.tab)
	{
		fill_with_bsq(&data, solve_tab(&data));
		print_tab(&data);
	}
	ft_free_tab(data.tab, data.height);
}

int	main(int argc, char **argv)
{
	int		i;

	if (argc < 2)
		ft_solve_map(NULL);
	else
	{
		i = 0;
		while (++i < argc)
		{
			ft_solve_map(argv[i]);
			if (i != argc - 1)
				ft_putchar('\n');
		}
	}
	return (0);
}
