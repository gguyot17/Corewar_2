/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:38:58 by gguyot            #+#    #+#             */
/*   Updated: 2017/11/14 17:29:46 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		n;
	size_t		m;
	size_t		l;

	n = 0;
	m = 0;
	if (little[n] == '\0')
		return ((char *)(&big[n]));
	while (big[n] && m < len)
	{
		m = n;
		l = 0;
		while (big[m] == little[l] && m < len)
		{
			m++;
			l++;
			if (little[l] == '\0')
				return ((char *)(&big[n]));
		}
		n++;
	}
	return (0);
}
