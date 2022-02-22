/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:51:30 by maykman           #+#    #+#             */
/*   Updated: 2022/02/22 23:50:47 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	gnl_free_return(char **str, int ret_value)
{
	if (*str)
		free(*str);
	*str = NULL;
	return (ret_value);
}

int	ft_index(char *s, char c)
{
	int	i;

	if (!s)
		return (-1);
	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (i);
	if (s[i] == c)
		return (i);
	return (-1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, void *src, int n)
{
	if (!dest && !src)
		return (0);
	while (n--)
		*((unsigned char *)dest + n) = *((unsigned char *)src + n);
	return (dest);
}
