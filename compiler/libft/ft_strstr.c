/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:47:20 by gguyot            #+#    #+#             */
/*   Updated: 2017/11/14 17:21:38 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int		n;
	int		m;
	int		l;

	n = 0;
	m = 0;
	if (*s2 == '\0')
		return ((char *)(&s1[n]));
	while (s1[n])
	{
		m = n;
		l = 0;
		while (s1[m] == s2[l])
		{
			m++;
			l++;
			if (s2[l] == '\0')
				return ((char *)(&s1[n]));
		}
		n++;
	}
	return (0);
}
