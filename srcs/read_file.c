/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:48:36 by maykman           #+#    #+#             */
/*   Updated: 2022/02/23 00:40:17 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		size;
	char	*ptr;

	size = ft_strlen(s1) + ft_strlen(s2);
	printf("Pre copy\n");
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, ft_strlen(s1));
	ft_memcpy(ptr + ft_strlen(s1), s2, ft_strlen(s2));
	ptr[size] = 0;
	if (s1)
		free(s1);
	return (ptr);
}

int	read_file(int fd, char **line)
{
	char	*buff;
	int		byte;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	byte = 1;
	while (byte)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		buff[byte] = 0;
		printf("%s | %p\n", buff, line);
		*line = ft_strjoin(*line, buff);
		printf("%s\n", *line);
		if (!line)
			return (gnl_free_return(&buff, MALLOC_ERROR));
	}
	free(buff);
	return (0);
}
