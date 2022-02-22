/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:23:23 by maykman           #+#    #+#             */
/*   Updated: 2022/02/22 17:20:32 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	malloc_tab(t_data *data, char *line)
{
	int	y;

	data->width = ft_strlen(line);
	if (!data->width)
		return (ERROR);
	data->tab = (t_tab)malloc(sizeof(*data->tab) * data->height);
	if (!data->tab)
		return (MALLOC_ERROR);
	y = -1;
	while (++y < data->height)
	{
		data->tab[y] = malloc(sizeof(**data->tab) * data->width);
		if (!data->tab[y])
			return (ft_free_tab(data->tab, y));
	}
	return (0);
}

int	ft_free_tab(t_tab tab, int y)
{
	while (--y)
		free(tab[y]);
	free(tab);
	return (MALLOC_ERROR);
}
