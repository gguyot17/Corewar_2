/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:29:19 by gguyot            #+#    #+#             */
/*   Updated: 2019/05/02 14:38:53 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

size_t		get_lab_pos(t_inst *first, char *name)
{
	t_inst		*tmp;
	int			size;
	int			good;

	tmp = first;
	good = 0;
	size = 0;
	while (tmp)
	{
		if (tmp->label && ft_strcmp(tmp->label, name) == 0)
		{
			good = 1;
			break ;
		}
		size = size + tmp->size;
		tmp = tmp->next;
	}
	if (good == 0)
		error_exit("Bad label\n");
	return (size);
}

size_t		get_request(t_inst *first, t_inst *lab)
{
	t_inst		*tmp;
	int			size;
	int			good;

	tmp = first;
	good = 0;
	size = 0;
	while (tmp)
	{
		if (tmp && lab && tmp == lab)
		{
			good = 1;
			break ;
		}
		size = size + tmp->size;
		tmp = tmp->next;
	}
	if (good == 0)
		error_exit("Bad label\n");
	return (size);
}

size_t		get_distance(t_inst *first, t_inst *lab, char *name)
{
	int	nbr;

	nbr = get_lab_pos(first, name) - get_request(first, lab);
	return (nbr);
}

void		get_position_lab(t_inst *first)
{
	t_inst		*tmp;
	int			n;

	tmp = first;
	while (tmp)
	{
		n = 0;
		while (n < 3)
		{
			if (tmp->arg_lab[n])
			{
				tmp->arg[n][2] = get_distance(first, tmp, tmp->arg_lab[n]);
			}
			n++;
		}
		tmp = tmp->next;
	}
}

void		add_inst(t_inst **first, t_inst *inst)
{
	t_inst		*tmp;

	tmp = *first;
	if (!tmp)
	{
		*first = inst;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = inst;
	tmp = *first;
}
