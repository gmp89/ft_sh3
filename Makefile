#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/24 15:49:32 by gpetrov           #+#    #+#              #
#    Updated: 2014/02/06 19:20:41 by gpetrov          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= ft_minishell3
FILES	= main.c list.c tools2.c arrow.c path.c tools.c env.c
SRCS	= $(addprefix src/, $(FILES))
OBJS	= $(SRCS:src/%.c=.obj/%.o)
INC		= -I includes -I libft/includes
FLAGS	= -Wall -Wextra -Werror
LIB		= -L libft -lft

all: $(NAME)
$(NAME): $(OBJS)
	make -C libft
	cc $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB) -L /usr/lib -ltermcap
.obj/%.o: src/%.c
	mkdir -p .obj
	cc -c $< -o $@ $(FLAGS) $(INC)
gdb:
	make -C libft
	cc -g $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB) -L /usr/lib -ltermcap
	gdb $(NAME)
clean:
	rm -rf .obj
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all gdb clean fclean re
