/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 00:44:37 by maykman           #+#    #+#             */
/*   Updated: 2022/02/22 17:20:30 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isprint(char c)
{
	return (c >= 32 && c <= 126);
}

int	ft_str_is(char *str, int (*f)(char))
{
	if (!str || !f)
		return (0);
	while (*str)
		if (!f(*str++))
			return (0);
	return (1);
}
