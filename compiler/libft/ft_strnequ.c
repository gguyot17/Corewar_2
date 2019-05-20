/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:19:35 by gguyot            #+#    #+#             */
/*   Updated: 2017/11/17 14:34:23 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		m;

	m = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	if (n == 0 || (!*s1 && !*s2))
		return (1);
	if (!*s1 || !*s2)
		return (0);
	while (s1[m] && m < n)
	{
		if (s1[m] != s2[m])
			return (0);
		m++;
	}
	if (s1[m] != s2[m] && m < n)
		return (0);
	return (1);
}
