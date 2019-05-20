/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:40:18 by gguyot            #+#    #+#             */
/*   Updated: 2017/11/16 12:49:51 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*list;
	t_list		*nxtlist;

	list = *alst;
	while (list)
	{
		nxtlist = list->next;
		del(list->content, list->content_size);
		free(list);
		list = nxtlist;
	}
	*alst = 0;
}
