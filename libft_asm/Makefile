# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 15:01:27 by AleXwern          #+#    #+#              #
#    Updated: 2020/11/16 15:01:27 by AleXwern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
ASMNAME	= libft_asm.a
ifeq ($(OS),Windows_NT)     # is Windows_NT on XP, 2000, 7, Vista, 10...
ELF 	= win64
else
ELF		= elf64
endif
FLAG	= -no-pie
CFILE	= ft_memalloc.c ft_putendl.c ft_strcpy.c ft_strmapi.c ft_strsub.c \
	ft_memccpy.c ft_putendl_fd.c ft_strdel.c ft_strncat.c ft_strtrim.c \
	ft_atoi.c ft_memchr.c ft_putnbr.c ft_strdup.c ft_strncmp.c \
	ft_tolower.c ft_bzero.c ft_memcmp.c ft_putnbr_fd.c ft_strequ.c \
	ft_strncpy.c ft_toupper.c ft_isalnum.c ft_memcpy.c ft_putstr.c \
	ft_striter.c ft_strnequ.c ft_isalpha.c ft_memdel.c ft_putstr_fd.c \
	ft_striteri.c ft_strnew.c ft_isascii.c ft_memmove.c ft_strcat.c \
	ft_strjoin.c ft_strnstr.c ft_isdigit.c ft_memset.c ft_strchr.c \
	ft_strlcat.c ft_strrchr.c ft_isprint.c ft_putchar.c ft_strclr.c \
	ft_strlen.c ft_strsplit.c ft_itoa.c ft_putchar_fd.c ft_strcmp.c \
	ft_strmap.c ft_strstr.c ft_wordlen.c ft_isblank.c ft_isnegative.c \
	ft_intsize.c ft_isextascii.c get_next_line.c ft_puthex.c ft_lcm.c \
	ft_abs.c ft_fabs.c ft_putnbrln.c ft_quadjoin.c ft_splitfree.c \
	ft_strfjoin.c ft_printmem.c ft_atof.c ft_strsjoin.c ft_listlen.c \
	ft_realloc.c
#This is to test spesific functions and removing it will allow entire thing to be used
SRCFILE	= ft_strlen.asm ft_putstr_fd.asm ft_putendl_fd.asm \
		ft_putstr.asm ft_putendl.asm ft_putchar.asm ft_memset.asm \
		ft_atoi.asm ft_strcpy.asm ft_strclr.asm ft_strequ.asm \
		ft_striter.asm ft_striteri.asm ft_atof.asm ft_strlcat.asm \
		ft_strncat.asm ft_strncmp.asm ft_strncpy.asm ft_strnequ.asm \
		ft_strnstr.asm ft_strrchr.asm ft_strstr.asm ft_wordlen.asm \
		ft_memccpy.asm ft_memchr.asm ft_memcmp.asm ft_memcpy.asm \
		ft_memmove.asm ft_strcat.asm ft_strchr.asm ft_strcmp.asm ft_bzero.asm \
		ft_isalpha.asm ft_isascii.asm ft_isblank.asm ft_isdigit.asm ft_isalnum.asm\
		ft_isprint.asm ft_isnegative.asm ft_tolower.asm ft_toupper.asm \
		ft_bswap.asm ft_rotate_left.asm ft_rotate_right.asm \
		ft_intsize.asm ft_putchar_fd.asm ft_puthex.asm ft_puthexln.asm \
		ft_strsub.asm ft_strnew.asm ft_listlen.asm
#		These sources wil not be used until I figure out couple bugs.
CMEM	= ft_memalloc.c ft_memdel.c ft_quadjoin.c ft_realloc.c \
		ft_splitfree.c ft_strdel.c ft_strdup.c ft_strfjoin.c ft_strsjoin.c \
		ft_strjoin.c ft_putnbr.c ft_putnbr_fd.c ft_putnbrln.c \
		ft_putlongln.c get_next_line.c ft_strsplit.c
SRCEXT	= .asm
OBJEXT	= .o
SRC		= $(addprefix ./src/,$(SRCFILE))
OBJ_ASM	= $(addprefix ./obj_asm/,$(SRCFILE:.asm=.o)) $(addprefix ./obj_c/,$(CMEM:.c=.o))
OBJ_C	= $(addprefix ./obj_c/,$(CFILE:.c=.o))
INCLS	= ./
OBJFLD	= ../obj/
GREEN	= \033[0;32m
PURPLE	= \033[0;35m
STOP	= \033[0m

.PHONY: all clean fclean re

all: $(NAME)

./obj_asm/%.o:./src_asm/%.asm
	@echo "Assembling ASM source $<"
	@mkdir -p obj_asm
	@nasm -f $(ELF) $< -o $@

./obj_c/%.o:./src_c/%.c
	@echo "Compiling C source $<"
	@mkdir -p obj_c
	@gcc -I ./ -c $< -o $@ 

$(NAME): $(OBJ_C)
	@echo "Compiling Library"
	@ar rc $(NAME) $(OBJ_C)
	@ranlib $(NAME)
	@echo done

LibftASM: $(OBJ_ASM)
	@echo "Compiling Library"
	@ar rc $(ASMNAME) $(OBJ_ASM)
	@ranlib $(ASMNAME)
	@echo done

clean:
	@/bin/rm -f $(OBJ_C)
	@/bin/rm -f $(OBJ_ASM)
	@/bin/rm -rf ./obj_c
	@/bin/rm -rf ./obj_asm

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(ASMNAME)

re: fclean all
