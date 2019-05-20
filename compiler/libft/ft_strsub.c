/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:54:41 by gguyot            #+#    #+#             */
/*   Updated: 2019/02/13 17:21:36 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	n;
	char			*cpy;
	int				len2;

	n = 0;
	len2 = len;
	if (s == 0)
		return (0);
	if (start > (unsigned int)ft_strlen(s))
		return (0);
	if (len < 500)
		len2 = 500;
	if ((cpy = (char *)malloc(sizeof(char) * (len2 + 1))) == 0)
		return (0);
	while (n < len && s[start])
	{
		cpy[n] = s[start];
		n++;
		start++;
	}
	cpy[n] = '\0';
	return (cpy);
}

char	*ft_strsub_free(char **str, unsigned int start, size_t len)
{
	char	*tmp;

	tmp = ft_strsub(*str, start, len);
	free(*str);
	return (tmp);
}
