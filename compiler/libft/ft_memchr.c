/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:45:15 by gguyot            #+#    #+#             */
/*   Updated: 2017/11/13 15:42:02 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned int	m;

	m = 0;
	str = (unsigned char *)s;
	while (m < n)
	{
		if (str[m] == (unsigned char)c)
			return (&str[m]);
		m++;
	}
	return (0);
}
