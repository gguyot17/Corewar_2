/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 09:12:22 by gguyot            #+#    #+#             */
/*   Updated: 2019/02/21 17:19:19 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (size <= 1000)
		size = 1000;
	mem = malloc(size);
	if (mem == 0)
		return (0);
	ft_memset(mem, 0, size);
	return (mem);
}
