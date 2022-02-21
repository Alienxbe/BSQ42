/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:46:24 by maykman           #+#    #+#             */
/*   Updated: 2022/02/21 19:32:16 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int main(void)
{
	char	*line;
	char	*map;
	int		bytes;

	map = NULL;
	printf("%d\n", open(map, O_RDONLY));
	while ((bytes = get_next_line(0, &line)))
	{
		map = gnl_strjoin(map, line);
		free(line);
	}
	printf("%s", map);
	return (0);
}
