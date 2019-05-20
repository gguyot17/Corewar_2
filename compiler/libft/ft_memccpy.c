/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:23:57 by gguyot            #+#    #+#             */
/*   Updated: 2017/11/17 15:17:08 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*src1;
	unsigned int	m;

	m = 0;
	if (n == 0 || dest == src)
		return (0);
	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	while (m < n)
	{
		dest1[m] = src1[m];
		if (dest1[m] == (unsigned char)c)
			return (&dest1[m + 1]);
		m++;
	}
	dest1[m] = '\0';
	return (0);
}
