/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 18:45:05 by gguyot            #+#    #+#             */
/*   Updated: 2019/05/19 16:54:48 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/libft.h"
# include "op.h"
# include <fcntl.h>

typedef struct		s_inst
{
	char			*label;
	size_t			size;
	int				op_code;
	int				arg_code;
	int				arg_nbr;
	int				arg[3][3];
	char			*arg_lab[3];
	struct s_inst	*next;
}					t_inst;

typedef struct		s_op
{
	const char		*name;
	int				nb_arg;
	int				arg[3];
	int				op_code;
	int				cycle;
	const char		*des;
	int				octal;
	int				dir_size;
}					t_op;

int					main(int argc, char **argv);
void				copy_exec_magic(t_header *header);
void				copy_name_comment(int fdasm, t_header *header);
void				error_exit(char *str);
t_op				config_op(char *name);
t_inst				*begin_inst(int fdasm);
void				free_split(char **split);
void				get_position_lab(t_inst *first);
void				add_inst(t_inst **first, t_inst *inst);
void				get_arg_inst(t_op op, char *str, t_inst *inst, int nb);
void				free_inst(t_inst *inst);
size_t				prog_size(t_inst *inst);
void				write_fdcor(int fdcor, t_inst *tmp);
void				dec_hexa(unsigned int *magic);
void				init_inst(t_inst *inst);
int					check_separator(char *line);
int					gnl_error(int fd, char **line, t_inst *first);

#endif
