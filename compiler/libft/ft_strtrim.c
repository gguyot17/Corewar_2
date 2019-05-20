/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:48:44 by gguyot            #+#    #+#             */
/*   Updated: 2019/01/31 16:10:09 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		dlen;
	int		alen;
	char	*str;

	dlen = 0;
	if (s == 0)
		return (0);
	alen = ft_strlen(s);
	while (s[dlen] == ' ' || s[dlen] == '\n' || s[dlen] == '\t')
		dlen++;
	if (s[dlen] == '\0')
		return (ft_strnew(0));
	while (s[alen - 1] == ' ' || s[alen - 1] == '\n' || s[alen - 1] == '\t')
		alen--;
	if (!(str = (char *)malloc(sizeof(char) * (alen - dlen + 1))))
		return (0);
	free(str);
	str = ft_strsub(s, dlen, (alen - dlen));
	str[alen + 1] = '\0';
	return (str);
}

char	*ft_strtrim_free(char **s)
{
	char	*tmp;

	tmp = ft_strtrim(*s);
	free(*s);
	return (tmp);
}
