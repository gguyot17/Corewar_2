/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:20:36 by gguyot            #+#    #+#             */
/*   Updated: 2017/11/17 12:25:34 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		m;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 >= n && len2 >= n)
	{
		m = ft_memcmp(s1, s2, n);
		return (m);
	}
	if (len1 >= len2 && len2 <= n)
	{
		m = ft_memcmp(s1, s2, len2 + 1);
		return (m);
	}
	if (len2 >= len1 && len1 <= n)
	{
		m = ft_memcmp(s1, s2, len1 + 1);
		return (m);
	}
	return (0);
}
