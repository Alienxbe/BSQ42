/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:23:01 by maykman           #+#    #+#             */
/*   Updated: 2022/02/23 14:29:16 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	open_file(char *filename)
{
	int	fd;

	if (!filename)
		return (STDIN_FILENO);
	fd = open(filename, O_RDONLY);
	return (fd);
}

static int	get_params(t_data *data, char *line)
{
	int	height;

	height = ft_atoi(&line);
	if (height <= 0 || ft_strlen(line) != 3 || !ft_str_is(line, &ft_isprint))
		return (MAP_ERROR);
	data->height = height;
	data->block.empty = line[0];
	data->block.obs = line[1];
	data->block.full = line[2];
	return (0);
}

static int	fill_line(t_data *data, char *line, int y, int *obs)
{
	int	x;

	if (ft_strlen(line) != data->width || y >= data->height)
		return (MAP_ERROR);
	x = -1;
	while (++x < data->width)
	{
		if (line[x] == data->block.empty)
			data->tab[y][x] = 0;
		else if (line[x] == data->block.obs)
		{
			data->tab[y][x] = 1;
			(*obs)++;
		}
		else
			return (MAP_ERROR);
	}
	return (0);
}

static int	parse_file(t_data *data, int fd)
{
	char	*line;
	int		obs;
	int		i;
	int		byte;

	obs = 0;
	byte = 1;
	i = 0;
	while (byte)
	{
		byte = get_next_line(fd, &line);
		if (byte < 0)
			return (GNL_ERROR);
		if (byte && !i && get_params(data, line))
			return (MAP_ERROR);
		if (byte && i == 1 && malloc_tab(data, line))
			return (MALLOC_ERROR);
		if (byte && i > 0 && fill_line(data, line, i - 1, &obs))
			return (MAP_ERROR);
		i++;
	}
	if (i - 2 != data->height || !obs)
		return (MAP_ERROR);
	return (0);
}

int	fill_tab(t_data *data, char *filename)
{
	int	fd;
	int	out;

	fd = open_file(filename);
	if (fd < 0)
		return (OPEN_FILE_ERROR);
	out = parse_file(data, fd);
	if (out)
		return (out);
	return (0);
}
