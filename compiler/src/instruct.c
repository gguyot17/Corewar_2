/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:56:36 by gguyot            #+#    #+#             */
/*   Updated: 2019/05/19 16:50:41 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int			get_label_name(char *line)
{
	int		n;

	n = 0;
	while (ft_strchr(LABEL_CHARS, line[n]))
		n++;
	if (line[n] == LABEL_CHAR)
		return (n);
	return (0);
}

t_op		get_op(char *arg_inst, t_inst *inst, char ***arg_split)
{
	char	*tmp;
	char	*str;
	int		n;
	t_op	op;

	n = 0;
	tmp = ft_strtrim(arg_inst);
	while (tmp[n] && tmp[n] != COMMENT_CHAR)
		n++;
	if (tmp[n] == COMMENT_CHAR)
		tmp = ft_strsub_free(&tmp, 0, n);
	str = tmp;
	n = 0;
	while (str[n] != ' ' && str[n] != '\t' && str[n])
		n++;
	tmp = ft_strsub(str, 0, n);
	op = config_op(tmp);
	free(tmp);
	tmp = ft_strtrim(str + n);
	free(str);
	inst->op_code = op.op_code;
	inst->arg_nbr = op.nb_arg;
	(op.op_code) ? *arg_split = ft_strsplit(tmp, SEPARATOR_CHAR) : 0;
	free(tmp);
	return (op);
}

void		get_inst_suite(char *arg_inst, t_inst *inst)
{
	int		n;
	t_op	op;
	char	**arg_split;
	char	*str;

	arg_split = 0;
	op = get_op(arg_inst, inst, &arg_split);
	if (op.op_code == 0)
		return ;
	n = 0;
	while (arg_split[n] && n < op.nb_arg)
	{
		str = ft_strtrim(arg_split[n]);
		get_arg_inst(op, str, inst, n);
		free(str);
		n++;
	}
	if (n != op.nb_arg || arg_split[n])
		error_exit("Incorrect arguments number\n");
	while (n++ < 4)
		inst->arg_code = inst->arg_code << 2;
	free_split(arg_split);
	inst->size = inst->arg[0][1] + inst->arg[1][1] + inst->arg[2][1] + 1;
	inst->size = (inst->arg_code) ? inst->size + 1 : inst->size;
}

void		get_inst(char *line, t_inst **first)
{
	t_inst	*inst;
	int		endl;
	char	*arg_inst;

	if (!(inst = (t_inst*)malloc(sizeof(t_inst))))
		error_exit("Error_malloc\n");
	ft_bzero(inst, sizeof(*inst));
	(check_separator(line) == -1) ? error_exit("Error separator\n") : 0;
	endl = get_label_name(line);
	if (endl != 0)
	{
		inst->label = ft_strsub(line, 0, endl);
	}
	if (endl != 0)
		arg_inst = ft_strtrim(line + endl + 1);
	else
	{
		arg_inst = ft_strtrim(line);
	}
	if (*arg_inst)
		get_inst_suite(arg_inst, inst);
	free(arg_inst);
	add_inst(first, inst);
}

t_inst		*begin_inst(int fdasm)
{
	char	*line;
	char	*tmp;
	t_inst	*first;

	first = 0;
	tmp = 0;
	line = 0;
	while (gnl_error(fdasm, &line, first) > 0)
	{
		tmp = ft_strtrim(line);
		if (!(*tmp) || *tmp == COMMENT_CHAR)
		{
			free(line);
			free(tmp);
			continue;
		}
		get_inst(tmp, &first);
		free(tmp);
		free(line);
	}
	if (line)
		free(line);
	get_position_lab(first);
	return (first);
}
