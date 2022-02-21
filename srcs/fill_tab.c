/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:23:01 by maykman           #+#    #+#             */
/*   Updated: 2022/02/21 20:01:04 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	open_file(char *filename)
{
	int	fd;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	return (fd);
}

int	fill_tab(char *filename)
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
		if (!i)
		{
			// Parametres
		}
		else if (i == 1)
		{
			// Count width
			// Malloc tab
			// Check char
			// fill ligne
		}
		else
		{
			// Check width
			// Check char
			// Fill ligne
		}
		i++;
	}
	return (0);
}
