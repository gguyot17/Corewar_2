/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <gguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:54:44 by gguyot            #+#    #+#             */
/*   Updated: 2019/05/19 17:17:36 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int			gnl_error(int fdasm, char **line, t_inst *first)
{
	int		rt;
	t_inst	*tmp;
	int		len;

	len = 0;
	tmp = first;
	if ((rt = get_next_line(fdasm, line)) == -1)
		error_exit("Bad line\n");
	while (tmp && len < 10000)
	{
		tmp = tmp->next;
		len++;
	}
	if (len >= 10000)
		error_exit("Champion too big\n");
	return (rt);
}

size_t		prog_size(t_inst *inst)
{
	t_inst	*tmp;
	int		prog_size;

	tmp = inst;
	prog_size = 0;
	while (tmp)
	{
		prog_size += tmp->size;
		tmp = tmp->next;
	}
	if (prog_size > 682)
		error_exit("Champion too big\n");
	return (prog_size);
}

void		write_arg(int fdcor, int val2, int size)
{
	if (!size)
		return ;
	write_arg(fdcor, val2 >> 8, size - 1);
	write(fdcor, &val2, 1);
}

void		write_fdcor(int fdcor, t_inst *tmp)
{
	int			n;
	int			m;
	void		*val;

	while (tmp)
	{
		n = 0;
		if (tmp->op_code)
			write(fdcor, ((char*)(&(tmp->op_code))), 1);
		if (tmp->arg_code)
			write(fdcor, ((char*)(&(tmp->arg_code))), 1);
		while (n < tmp->arg_nbr)
		{
			m = 0;
			val = &(tmp->arg[n][2]);
			while (m < tmp->arg[n][1])
			{
				write(fdcor, &(((char *)val)[tmp->arg[n][1] - 1 - m]), 1);
				m++;
			}
			n++;
		}
		tmp = tmp->next;
	}
}

int			check_separator(char *line)
{
	int		n;
	int		count;

	n = 0;
	count = 0;
	while (line[n])
	{
		if (line[n] == SEPARATOR_CHAR)
			count++;
		if ((line[n] == SEPARATOR_CHAR && line[n + 1] == SEPARATOR_CHAR)
				|| count > 2)
			return (-1);
		n++;
	}
	return (0);
}
