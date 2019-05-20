# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gguyot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 13:35:24 by gguyot            #+#    #+#              #
#    Updated: 2019/05/19 16:17:51 by gguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

HEADER = include/asm.h

LIBFT = libft

SRC = src/main.c src/copy_header.c src/instruct.c src/op.c src/arg.c src/struct.c\
	src/prog_size.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT) re
			gcc -L $(LIBFT) -lft -o $(NAME) $(OBJ)

%.o: %.c
		gcc -I $(HEADER) -c -Wall -Werror -Wextra $< -o $@

clean:
		make -C $(LIBFT) clean
			@rm -rf $(OBJ)

fclean: clean
		make -C $(LIBFT) fclean
			@rm -rf $(NAME)

re: fclean all
