/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:50:45 by gguyot            #+#    #+#             */
/*   Updated: 2017/11/16 15:52:53 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	n;
	int				len;
	char			*str;

	n = 0;
	if (s && f)
	{
		len = ft_strlen((char *)s);
		if (!(str = (char *)malloc(sizeof(char) * len + 1)))
			return (0);
		while (s[n])
		{
			str[n] = (f)(n, s[n]);
			n++;
		}
		str[n] = '\0';
		return (str);
	}
	return (0);
}
