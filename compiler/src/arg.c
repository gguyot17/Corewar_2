/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:56:23 by gguyot            #+#    #+#             */
/*   Updated: 2019/05/19 15:26:44 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int			get_argtype(char *str, int nb)
{
	int		type;

	type = 0;
	if (*str == DIRECT_CHAR)
		type = T_DIR;
	if (*str == 'r')
		type = T_REG;
	if ((*str == '-' && ft_isdigit(str[1])) || ft_isdigit(*str))
		type = T_IND;
	if (*str == DIRECT_CHAR && str[1] == LABEL_CHAR)
		type = 16;
	if (*str == LABEL_CHAR)
		type = 32;
	if (type == 0)
		error_exit("Bad argtype\n");
	if (type < T_LAB && (type & nb) == 0)
		error_exit("Error : argtype\n");
	if (type == 16 && (T_DIR & nb) == 0)
		error_exit("Error : argtype label\n");
	if (type == 32 && (T_IND & nb) == 0)
		error_exit("Error : argtype label\n");
	return (type);
}

char		*str_label(char *str)
{
	int		n;
	int		m;

	n = 0;
	while (str[n] && !ft_strchr(LABEL_CHARS, str[n]))
		n++;
	m = n;
	while (str[m] && ft_strchr(LABEL_CHARS, str[m]))
		m++;
	return (ft_strsub(str, n, m - n));
}

int			str_int(char *str, int inst)
{
	int		n;
	int		m;
	int		nb;

	n = 0;
	while (str[n] && !ft_isdigit(str[n]) && str[n] != '-')
		n++;
	if (!str[n])
		error_exit("Bad argument\n");
	m = n;
	while (str[m] && (str[m] == '-' || ft_isdigit(str[m])))
		m++;
	if (str[m] && str[m] != ',' && !ft_isdigit(str[m]))
		error_exit("Bad argument\n");
	if ((nb = ft_atoi(str + n)) > 16 && inst == T_REG)
		error_exit("Bad argument\n");
	return (nb);
}

void		get_arg_inst(t_op op, char *str, t_inst *inst, int nb)
{
	inst->arg[nb][0] = get_argtype(str, op.arg[nb]);
	if (inst->arg[nb][0] == T_REG)
		inst->arg[nb][1] = 1;
	else if (inst->arg[nb][0] == T_IND || inst->arg[nb][0] == 32)
		inst->arg[nb][1] = 2;
	else
		inst->arg[nb][1] = (op.dir_size) ? 2 : 4;
	if (op.octal)
	{
		inst->arg_code = inst->arg_code << 2;
		if (inst->arg[nb][0] == T_REG)
			inst->arg_code = inst->arg_code | 1;
		if (inst->arg[nb][0] == T_DIR || inst->arg[nb][0] == 16)
			inst->arg_code = inst->arg_code | 2;
		if (inst->arg[nb][0] == T_IND || inst->arg[nb][0] == 32)
			inst->arg_code = inst->arg_code | 3;
	}
	if (inst->arg[nb][0] > T_LAB)
		inst->arg_lab[nb] = str_label(str);
	else if (inst->arg[nb][0] <= T_LAB)
		inst->arg[nb][2] = str_int(str, inst->arg[nb][0]);
}
