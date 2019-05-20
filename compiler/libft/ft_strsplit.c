/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:13:43 by gguyot            #+#    #+#             */
/*   Updated: 2017/11/15 16:09:52 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_word(char const *s, char c)
{
	int		n;
	int		m;
	int		counter;

	n = 0;
	m = 0;
	counter = 0;
	if (!s)
		return (0);
	while (s[n])
	{
		if (m == 1 && s[n] == c)
			m = 0;
		if (m == 0 && s[n] != c)
		{
			counter++;
			m = 1;
		}
		n++;
	}
	return (counter);
}

static size_t	sp(char const *s, char c, int n)
{
	size_t	counter;

	counter = 0;
	while (s[n] != c && s[n])
	{
		counter++;
		n++;
	}
	return (counter);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	t_var	v;

	v.l = 0;
	v.n = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char*) * (ft_word(s, c) + 1))))
		return (0);
	while (s[v.l])
	{
		while (s[v.l] == c && s[v.l])
			v.l++;
		if (s[v.l])
		{
			v.m = 0;
			if (!(tab[v.n] = (char*)malloc(sizeof(char) * sp(s, c, v.l) + 1)))
				return (0);
			while (s[v.l] != c && s[v.l])
				tab[v.n][v.m++] = s[v.l++];
			tab[v.n++][v.m] = '\0';
		}
	}
	tab[v.n] = 0;
	return (tab);
}
