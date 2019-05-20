/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:26:09 by gguyot            #+#    #+#             */
/*   Updated: 2018/09/20 16:52:48 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		n;
	int		m;
	char	*copy;

	n = 0;
	m = 0;
	while (src[m])
		m++;
	if ((copy = (char *)malloc(sizeof(char) * (m + 1))) == 0)
		return (0);
	while (n < m)
	{
		copy[n] = src[n];
		n++;
	}
	copy[n] = '\0';
	return (copy);
}
