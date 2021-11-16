# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 13:36:39 by AleXwern          #+#    #+#              #
#    Updated: 2021/11/16 15:31:48 by AleXwern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= timeliner.exe
FLAG	= -no-pie
SRCFILE	= main.cpp timeliner.cpp config.cpp
SRC		= $(addprefix ./srcpp/,$(SRCFILE))
OBJ		= $(addprefix ./objpp/,$(SRCFILE:.cpp=.o))
LIBFT	= libft_asm/libft_asm.a
INCLS	= -I ./includes -I ./libft_asm
GREEN	= \033[0;32m
PURPLE	= \033[0;35m
STOP	= \033[0m

.PHONY: all clean fclean re

all: $(NAME)

./objpp/%.o:./srcpp/%.cpp
	@mkdir -p objpp
	g++ $(FLAG) -c $< -o $@ $(INCLS)

$(LIBFT):
	@echo Compiling Libft libraries.
	@make -C libft_asm LibftASM

$(NAME): $(LIBFT) $(OBJ)
	g++ $(FLAG) -o $(NAME) $(INCLS) $(OBJ) $(LIBFT)

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -rf ./obj

fclean: clean
	make -C ./libft_asm fclean
	/bin/rm -f $(NAME)

re: fclean all
