/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:56:26 by gguyot            #+#    #+#             */
/*   Updated: 2017/11/17 15:11:34 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	m;
	size_t	l;
	char	*src1;

	src1 = (char *)src;
	m = 0;
	l = 0;
	while (dest[l])
		l++;
	while (m < n && src1[m])
	{
		dest[l] = src1[m];
		l++;
		m++;
	}
	dest[l] = '\0';
	return (dest);
}
