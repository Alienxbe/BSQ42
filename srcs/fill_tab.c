/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:23:01 by maykman           #+#    #+#             */
/*   Updated: 2022/02/22 13:01:11 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	open_file(char *filename)
{
	int	fd;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	return (fd);
}

static int	get_params(t_data *data, char *line)
{
	if (ft_strlen(line) != 4)
		return (ERROR);
	if (!ft_isdigit(line[0]) || !ft_str_is(line + 1, &ft_isprint))
		return (ERROR);
	data->height = line[0];
	data->block.empty = line[1];
	data->block.obs = line[2];
	data->block.full = line[3];
	return (0);
}

static int	malloc_tab(t_data data)
{
	
}

int	fill_tab(t_data *data, char *filename)
{
	char	*line;
	int		byte;
	int		fd;
	int		i;

	(void)data;
	fd = open_file(filename);
	if (fd < 0)
		return (OPEN_FILE_ERROR);
	byte = 1;
	i = 0;
	while (byte)
	{
		byte = get_next_line(fd, &line);
		if (byte < 0)
			return (ERROR);
		// Parametres
		if (!i)
			if (get_params(data, line))
				return (ERROR);
		else if (i == 1)
		{
			// Count width
			// Malloc tab
			// Check char
			// fill ligne
			data->width = ft_strlen(line);
			data->tab = malloc_tab(); // Fonction a faire
		}
		else
		{
			// Check width
			// Check char
			// Fill ligne
			if (ft_strlen(line) != data->width)
				return (ERROR);
		}
		i++;
	}
	return (0);
}
