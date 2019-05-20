/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <gguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 18:42:26 by gguyot            #+#    #+#             */
/*   Updated: 2019/05/19 17:18:07 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

char		*get_name_cor(char *name)
{
	char	*str;
	char	*tmp;

	if (!(str = ft_strrchr(name, '.')))
		return (0);
	if (*str && ft_strcmp(str, ".s") == 0)
	{
		str = 0;
		str = ft_strnew(ft_strlen(name) - 2);
		str = ft_strncpy(str, name, ft_strlen(name) - 2);
		tmp = ft_strjoin(str, ".cor");
		free(str);
		return (tmp);
	}
	return (0);
}

void		error_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(0);
}

void		free_split(char **split)
{
	int		n;

	n = 0;
	while (split[n])
	{
		free(split[n]);
		n++;
	}
	free(split);
}

void		free_inst(t_inst *inst)
{
	t_inst	*tmp;

	tmp = inst;
	if (tmp)
	{
		free_inst(tmp->next);
		if (tmp->label)
			free(tmp->label);
		if (tmp->arg_lab[0])
			free(tmp->arg_lab[0]);
		if (tmp->arg_lab[1])
			free(tmp->arg_lab[1]);
		if (tmp->arg_lab[2])
			free(tmp->arg_lab[2]);
		free(tmp);
	}
}

int			main(int argc, char **argv)
{
	int			fdasm;
	t_inst		*inst;
	int			fdcor;
	t_header	header;
	char		*name;

	if (argc != 2)
		error_exit("Usage : ./asm mychampion.s\n");
	fdasm = open(argv[1], O_RDONLY);
	if ((name = get_name_cor(argv[1])) == 0)
		error_exit("Usage : ./asm mychampion.s\n");
	ft_bzero(&header, sizeof(t_header));
	copy_exec_magic(&header);
	copy_name_comment(fdasm, &header);
	inst = begin_inst(fdasm);
	header.prog_size = (unsigned int)prog_size(inst);
	fdcor = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	dec_hexa(&header.prog_size);
	write(fdcor, &header, sizeof(t_header));
	write_fdcor(fdcor, inst);
	free_inst(inst);
	free(name);
	exit(0);
	return (0);
}
