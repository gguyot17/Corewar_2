/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguyot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:44:37 by gguyot            #+#    #+#             */
/*   Updated: 2019/05/19 16:43:20 by gguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void		dec_hexa(unsigned int *magic)
{
	int				n;
	unsigned int	hexa;
	unsigned int	nbr;

	n = 3;
	nbr = *magic;
	while (n >= 0)
	{
		((char*)(&hexa))[n] = ((char*)(&nbr))[0];
		nbr = nbr >> 8;
		n--;
	}
	*magic = hexa;
}

void		copy_exec_magic(t_header *header)
{
	header->magic = COREWAR_EXEC_MAGIC;
	dec_hexa(&(header->magic));
}

char		*copy_check_name_comment(char *line, int *name, int *comment)
{
	if (!*name && ft_strncmp(line, NAME_CMD_STRING,
			ft_strlen(NAME_CMD_STRING)) == 0)
	{
		*name = 1;
		return (ft_strdup(NAME_CMD_STRING));
	}
	if (!*comment && ft_strncmp(line, COMMENT_CMD_STRING,
			ft_strlen(COMMENT_CMD_STRING)) == 0)
	{
		*comment = 1;
		return (ft_strdup(COMMENT_CMD_STRING));
	}
	return (0);
}

void		copy_comment_name_header(t_header *header, char *line, char *tmp)
{
	char	*str;
	int		len;

	str = ft_strtrim(line + ft_strlen(tmp));
	len = ft_strlen(str);
	if (str[0] != '"' || str[len - 1] != '"' || len - 1 == 0)
	{
		free(str);
		error_exit("Bad command\n");
	}
	if (ft_strcmp(tmp, NAME_CMD_STRING) == 0)
	{
		if (len > PROG_NAME_LENGTH + 2)
			error_exit("Bad name\n");
		ft_bzero(&(header->prog_name), PROG_NAME_LENGTH + 1);
		ft_memcpy(&(header->prog_name), str + 1, len - 2);
	}
	else if (ft_strcmp(tmp, COMMENT_CMD_STRING) == 0)
	{
		if (len > COMMENT_LENGTH + 2)
			error_exit("Bad comment\n");
		ft_bzero(&(header->comment), COMMENT_LENGTH + 1);
		ft_memcpy(&(header->comment), str + 1, len - 2);
	}
	free(str);
}

void		copy_name_comment(int fdasm, t_header *header)
{
	int		nc[3];
	char	*line;
	char	*str;

	nc[0] = 0;
	str = 0;
	nc[1] = 0;
	line = 0;
	while ((nc[2] = get_next_line(fdasm, &line)) > 0)
	{
		if (!(line = ft_strtrim_free(&line)))
			error_exit("Can't read source file\n");
		if ((str = copy_check_name_comment(line, &nc[0], &nc[1])))
		{
			copy_comment_name_header(header, line, str);
			free(str);
			(nc[0] && nc[1]) ? free(line) : 0;
			if (nc[0] && nc[1])
				break ;
		}
		else if (*line != '\0' && *line != COMMENT_CHAR)
			error_exit("Error header\n");
		free(line);
	}
	(!nc[0] || !nc[1] || nc[2] == -1) ? error_exit("Error header\n") : 0;
}
