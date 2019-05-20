/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:15:18 by gguyot            #+#    #+#             */
/*   Updated: 2017/11/16 15:50:52 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		n;
	int		len;
	char	*str;

	n = 0;
	if (s && f)
	{
		len = ft_strlen((char *)s);
		if (!(str = (char *)malloc(sizeof(char) * len + 1)))
			return (0);
		while (s[n])
		{
			str[n] = (f)(s[n]);
			n++;
		}
		str[n] = '\0';
		return (str);
	}
	return (0);
}
