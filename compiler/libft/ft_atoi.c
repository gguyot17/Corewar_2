/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:44:11 by gguyot            #+#    #+#             */
/*   Updated: 2019/01/07 13:53:09 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		n;
	int		ngt;
	long	nlong;

	nlong = 0;
	n = 0;
	ngt = 1;
	while (str[n] == ' ' || str[n] == '\t' || str[n] == '\n' || str[n] == '\v'
			|| str[n] == '\f' || str[n] == '\r')
		n++;
	if (str[n] == '-')
		ngt = -1;
	if (str[n] == '+' || str[n] == '-')
		n++;
	while (str[n] >= '0' && str[n] <= '9')
	{
		nlong = nlong * 10 + str[n] - 48;
		n++;
	}
	nlong = ngt * nlong;
	return (nlong);
}
