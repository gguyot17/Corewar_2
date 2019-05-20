/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:42:46 by gguyot            #+#    #+#             */
/*   Updated: 2017/11/17 14:13:52 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		n;
	int		m;
	char	copy;

	n = 0;
	m = 0;
	while (str[m])
		m++;
	m = m - 1;
	while (n < m)
	{
		copy = str[n];
		str[n] = str[m];
		str[m] = copy;
		n++;
		m--;
	}
	return (str);
}
