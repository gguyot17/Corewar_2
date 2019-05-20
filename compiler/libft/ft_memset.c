/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:18:15 by gguyot            #+#    #+#             */
/*   Updated: 2017/11/13 15:43:00 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned int	m;

	m = 0;
	if (n == 0)
		return (s);
	str = (unsigned char *)s;
	while (n--)
	{
		str[m] = (unsigned char)c;
		if (n)
			m++;
	}
	return (s);
}
