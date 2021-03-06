# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/03 09:33:12 by dlavaury          #+#    #+#              #
#    Updated: 2018/06/13 17:40:46 by fchanal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################################
###                  Settings                 ###
#################################################

EXEC	= corewar
CC		= clang
FLAGS	= -g3
HEADER	= -I $(INC_DIR) -I ../../libft/includes/
SRC_DIR	= ./srcs/
INC_DIR	= ./includes/

#################################################
###                 Sources                   ###
#################################################

SRC		= vm_main.c \
		  op.c \
		  init.c \
		  ocp_checker.c \
		  functions_1.c \
		  functions_2.c \
		  functions_3.c \
		  functions_4.c \
		  ex_functions_1.c \
		  ex_functions_2.c \
		  ex_functions_3.c \
		  ex_functions_4.c \
		  get_options.c \
		  corewar.c \
		  display_corewar.c \
		  process.c \
		  instruct.c \
		  cycle.c \
		  display.c \
		  visu.c \
		  visu_color.c \
		  visu_fill_wins.c \
		  visu_fill_wins_2.c \
		  visu_utilities.c \
		  visu_draw_basics.c \
		  visu_update_arena.c

#################################################
###                   Format                  ###
#################################################

OBJ		= $(addprefix $(SRC_DIR),$(SRC:.c=.o))

T		= $(words $(SRC))
N		= 0
C		= $(words $N)$(eval N := x $N)
ECHO	= "[`expr $C '*' 100 / $T`%]"

#COLOR
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

#################################################
###                   Rules                   ###
#################################################

.SILENT:

all: $(EXEC)

$(EXEC): $(OBJ) $(INC_DIR)/$(EXEC).h $(INC_DIR)/op.h
	@$(CC) $(FLAGS) $(HEADER) -o $(EXEC) $(OBJ) ../../libft/libft.a -lncurses
	@echo "$(_CYAN)$(EXEC)$(_END)		: $(_GREEN)compiled$(_END)"

%.o: %.c
	@printf "%-60b\r" "$(ECHO)"
	@$(CC) $(FLAGS) -c $< -o $@ $(HEADER)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(EXEC)

re: fclean
	@clear
	@make all

.PHONY: all clean fclean re
