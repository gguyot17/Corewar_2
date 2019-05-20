/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:44:23 by gguyot            #+#    #+#             */
/*   Updated: 2017/11/14 16:55:35 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	n;
	unsigned char	m;

	m = (unsigned char)c;
	n = 0;
	while (s[n])
	{
		if (s[n] == c)
			return ((char *)&s[n]);
		n++;
	}
	if (c == '\0')
		return ((char *)&s[n]);
	return (0);
}
