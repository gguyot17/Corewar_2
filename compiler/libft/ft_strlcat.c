/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:38:51 by gguyot            #+#    #+#             */
/*   Updated: 2017/11/16 14:51:15 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		dlen;
	size_t		n;
	size_t		m;
	size_t		slen;

	n = 0;
	m = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dest);
	if (dlen >= size)
		return (size + slen);
	while (dest[n] && n < size - 1)
		n++;
	while (n < size - 1 && src[m])
	{
		dest[n] = src[m];
		n++;
		m++;
	}
	dest[n] = '\0';
	return (slen + dlen);
}
