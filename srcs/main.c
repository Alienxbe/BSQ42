/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:46:24 by maykman           #+#    #+#             */
/*   Updated: 2022/02/22 17:26:40 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(void)
{
	t_data	data;
	int	o;

	o = fill_tab(&data, "map.test");
	printf("%d\n", o);
	ft_free_tab(data.tab, data.height);
	return (0);
}
