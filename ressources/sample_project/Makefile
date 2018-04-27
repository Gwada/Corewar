# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brigoux <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/02 07:20:23 by brigoux           #+#    #+#              #
#    Updated: 2016/07/25 17:01:23 by brigoux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, norminette, norme

## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ##

INC_PATH = includes/
OBJ_PATH = objects/
SRC_PATH = sources/

ASM = asm
ASM_SRC_NAME = ../op.c  \
			   check_.c \
			   get_.c   \
			   is_.c    \
			   main.c   \
			   new_.c   \
			   print_.c \
			   parse_.c \
			   read_.c  \
			   store_.c \
			   write_.c
ASM_SRC_PATH = $(SRC_PATH)$(ASM)/
ASM_SRC = $(addprefix $(ASM_SRC_PATH),$(ASM_SRC_NAME))
ASM_OBJ_NAME = $(ASM_SRC_NAME:.c=.o)
ASM_OBJ_PATH = $(OBJ_PATH)$(ASM)/
ASM_OBJ = $(addprefix $(ASM_OBJ_PATH),$(ASM_OBJ_NAME))

COREWAR = corewar
COREWAR_SRC_NAME = ../op.c     \
				   check_.c    \
				   do_.c       \
				   get_1.c     \
				   get_2.c     \
				   init_.c     \
				   main.c      \
				   ncurses.c   \
				   ncurses_1.c \
				   ncurses_2.c \
				   op_1.c      \
				   op_2.c      \
				   op_3.c      \
				   op_4.c      \
				   parse_.c    \
				   print_.c    \
				   run_.c      \
				   set_.c
COREWAR_SRC_PATH = $(SRC_PATH)$(COREWAR)/
COREWAR_SRC = $(addprefix $(COREWAR_SRC_PATH),$(COREWAR_SRC_NAME))
COREWAR_OBJ_NAME = $(COREWAR_SRC_NAME:.c=.o)
COREWAR_OBJ_PATH = $(OBJ_PATH)$(COREWAR)/
COREWAR_OBJ = $(addprefix $(COREWAR_OBJ_PATH),$(COREWAR_OBJ_NAME))

LIBFT_PATH = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)
LIBFT_INC_PATH = $(LIBFT_PATH)includes/
LIB = ft

CC = gcc -g
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I$(INC_PATH) -I$(LIBFT_INC_PATH)
LFLAGS = -l$(LIB) -L$(LIBFT_PATH)

## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ##

all: $(ASM) $(COREWAR)

$(ASM): $(LIBFT) $(ASM_OBJ_PATH) $(ASM_OBJ)
	$(CC) $(CFLAGS) $(LFLAGS) $(ASM_OBJ) -o $@

$(ASM_OBJ_PATH): $(OBJ_PATH)
	@mkdir -p $@

$(ASM_OBJ_PATH)%.o: $(ASM_SRC_PATH)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $? -o $@ -c

$(COREWAR): $(LIBFT) $(COREWAR_OBJ_PATH) $(COREWAR_OBJ)
	$(CC) $(CFLAGS) $(LFLAGS) -lncurses $(COREWAR_OBJ) -o $@

$(COREWAR_OBJ_PATH): $(OBJ_PATH)
	@mkdir -p $@

$(COREWAR_OBJ_PATH)%.o: $(COREWAR_SRC_PATH)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $? -o $@ -c

$(LIBFT):
	make -C $(LIBFT_PATH) re

$(OBJ_PATH):
	@mkdir -p $@

clean:
	make -C $(LIBFT_PATH) fclean
	rm -Rf $(OBJ_PATH)

fclean: clean
	rm -f $(ASM)
	rm -f $(COREWAR)

re: fclean all

n: norminette
norme: norminette
norminette:
	@echo "\nNorminette $(LIBFT_PATH) :\n"
	@make -C $(LIBFT_PATH) $@
	@echo "\nNorminette $(INC_PATH) :\n"
	@$@ $(INC_PATH)
	@echo "\nNorminette $(COREWAR_SRC_PATH) :\n"
	@$@ $(COREWAR_SRC_PATH)
	@echo "\nNorminette $(ASM_SRC_PATH) :\n"
	@$@ $(ASM_SRC_PATH)

## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ##
