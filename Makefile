# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gguyot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/02 14:53:24 by gguyot            #+#    #+#              #
#    Updated: 2019/05/19 16:17:28 by gguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = asm
NAME2 = corewar

DIR_ASM = compiler

DIR_VM = vm

all: $(NAME1) $(NAME2)

$(NAME1):
	make -C $(DIR_ASM)
$(NAME2):
	make -C $(DIR_VM)

clean:
	make -C $(DIR_ASM) clean
	make -C $(DIR_VM) clean

fclean: clean
	make -C $(DIR_ASM) fclean
	make -C $(DIR_VM) fclean

re: fclean all

.PHONY: all clean fclean re
