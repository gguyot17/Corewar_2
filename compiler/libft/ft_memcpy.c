/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:13:49 by gguyot            #+#    #+#             */
/*   Updated: 2017/11/17 16:36:30 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest1;
	char	*src1;
	size_t	m;

	m = 0;
	dest1 = (char *)dest;
	src1 = (char *)src;
	if (n == 0 || dest == src)
		return (dest);
	while (m < n)
	{
		dest1[m] = src1[m];
		m++;
	}
	return (dest);
}
