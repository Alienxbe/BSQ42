/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:46:24 by maykman           #+#    #+#             */
/*   Updated: 2022/02/22 18:52:17 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(void)
{
	t_data	data;
	t_sqr	sqr;
	int	o;

	o = fill_tab(&data, "map.test");
	printf("%d\n", o);
	sqr = solve_tab(&data);
	printf("%d | %d | size : %d\n", sqr.x, sqr.y, sqr.size);
	ft_free_tab(data.tab, data.height);
	return (0);
}
