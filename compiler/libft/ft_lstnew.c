/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:45:56 by gguyot            #+#    #+#             */
/*   Updated: 2017/11/17 16:35:32 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*newlist;

	newlist = (t_list*)malloc(sizeof(t_list));
	if (newlist == 0)
		return (0);
	if (content == 0)
	{
		newlist->content = 0;
		newlist->content_size = 0;
	}
	else
	{
		newlist->content = malloc(sizeof(content));
		if (newlist->content == 0)
			return (0);
		ft_memcpy((newlist->content), content, content_size);
		newlist->content_size = content_size;
	}
	newlist->next = 0;
	return (newlist);
}
