/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:23:01 by maykman           #+#    #+#             */
/*   Updated: 2022/02/23 00:29:25 by maykman          ###   ########.fr       */
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

static int	get_params(t_data *data, char *line, int *i)
{
	int	height;

	height = ft_atoi(line, i);
	if (height <= 0 || ft_index(line, '\n') != 3 || !ft_str_is(line, &ft_isprint))
		return (MAP_ERROR);
	data->height = height;
	data->block.empty = line[0];
	data->block.obs = line[1];
	data->block.full = line[2];
	return (0);
}

int	fill_line(t_data *data, char *line, int y)
{
	int	x;

	if (ft_strlen(line) != data->width)
		return (MAP_ERROR);
	x = -1;
	while (++x < data->width)
	{
		if (line[x] == data->block.empty)
			data->tab[y][x] = 0;
		else if (line[x] == data->block.obs)
			data->tab[y][x] = 1;
		else
			return (MAP_ERROR);
	}
	return (0);
}

int	fill_tab(t_data *data, char *filename)
{
	char	*file;
	int		fd;
	int		i;
	int		j;

	fd = open_file(filename);
	if (fd < 0)
		return (OPEN_FILE_ERROR);
	if (read_file(fd, &file))
		return (MALLOC_ERROR);
	printf("%s\n", file);
	i = 0;
	if (get_params(data, file, &i))
		return (MALLOC_ERROR);
	while (file[i] != '\n')
		i++;
	if (malloc_tab(data, file))
		return (MALLOC_ERROR);
	j = -1;
	while (++j < (data->width + 1) * data->height)
	{
		if (file[i + j] == data->block.empty)
			data->tab[j / data->width][j % data->width] = 0;
		else if (file[i + j] == data->block.obs)
			data->tab[j / data->width][j % data->width] = 1;
		else if (file[i + j] != '\n')
			return (MAP_ERROR);
	}
	close(fd);
	return (0);
}
