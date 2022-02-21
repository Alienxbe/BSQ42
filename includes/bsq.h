/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:43:52 by maykman           #+#    #+#             */
/*   Updated: 2022/02/22 00:29:01 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

// TO REMOVE !!!!!
# include <stdio.h>

typedef int **t_tab;

typedef struct s_data
{
	t_block	block;
	int		height;
	int		width;
}	t_data;

typedef struct s_block
{
	char	empty;
	char	obs;
	char	full;
}	t_block;

typedef struct s_sqr
{
	int	size;
	int	x;
	int	y;
}	t_sqr;

# define BUFFER_SIZE		10
# define OPEN_FILE_ERROR	1

/*
** Functions
*/

// GNL
int	get_next_line(int fd, char **line);

char	*gnl_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len, int s_free);
void	*ft_memcpy(void *dest, void *src, int n);
int		ft_strlen(char *s);
int		ft_index(char *s, char c);
int		free_return(char **str, int ret_value);

#endif