/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:02:10 by gguyot            #+#    #+#             */
/*   Updated: 2017/11/15 16:33:36 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)(&s[len]));
	while (len)
	{
		len--;
		if (s[len] == (char)c)
			return ((char *)(&s[len]));
	}
	return (0);
}
