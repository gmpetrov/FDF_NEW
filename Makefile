# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/20 09:56:28 by gmp               #+#    #+#              #
#    Updated: 2015/02/20 15:51:57 by gmp              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
SRCS	= $(shell find srcs -type f -print | grep "\.c")
OBJS	= $(SRCS:srcs/%.c=.obj/%.o)
INC		= -I includes -I libft/includes
FLAGS	= -Wall -Wextra -Werror
LIB		= -L libft -lft -L /usr/X11/lib -lmlx -lXext -lX11
CC		= gcc -g
OBJ_DIR = srcs/.obj

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(INC) $(INC) $(LIB)
	@echo "\n=> Compiling $(NAME) [\033[32mDONE\033[m]"

.obj/%.o: srcs/%.c
	@mkdir -p .obj
	@$(CC) -c $< -o $@ $(FLAGS) $(INC)
	@echo -n .

gdb:
	make -C libft
	cc -g $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(INC) $(LIB)
	gdb $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all gdb clean fclean re