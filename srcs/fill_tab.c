/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:23:01 by maykman           #+#    #+#             */
/*   Updated: 2022/02/22 17:42:18 by maykman          ###   ########.fr       */
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
	if (ft_strlen(line) != 4 || !ft_isdigit(line[0])
		|| !ft_str_is(line + 1, &ft_isprint))
		return (MAP_ERROR);
	data->height = line[0];
	data->block.empty = line[1];
	data->block.obs = line[2];
	data->block.full = line[3];
	return (0);
}

static int	fill_line(t_data *data, char *line, int y)
{
	int	x;

	if (ft_strlen(line) != data->width)
		return (MAP_ERROR);
	x = -1;
	while (++x < data->width)
	{
		if (!(line[x] == data->block.empty || line[x] == data->block.obs))
			return (MAP_ERROR);
		data->tab[y][x] = line[x];
	}
	return (0);
}

int	fill_tab(t_data *data, char *filename)
{
	char	*line;
	int		byte;
	int		fd;
	int		i;

	fd = open_file(filename);
	if (fd < 0)
		return (OPEN_FILE_ERROR);
	byte = 1;
	i = 0;
	while (byte)
	{
		byte = get_next_line(fd, &line);
		if (byte < 0)
			return (GNL_ERROR);
		if (byte && !++i && get_params(data, line)) // First line read
			return (MAP_ERROR);
		if (byte && i == 1 && malloc_tab(data, line)) // First map line
			return (MALLOC_ERROR);
		if (byte && i > 0 && fill_line(data, line, i - 1)) // Read line
			return (MAP_ERROR);
	}
	if (i - 1 != data->height)
		return (MAP_ERROR);
	return (0);
}
