#################################################
###                  Settings                 ###
#################################################

EXEC	= corewar
CC		= clang
FLAGS	= -Wall -Wextra -Werror -g3
HEADER	= -I $(INC_DIR) -I ../../libft/includes/
SRC_DIR	= ./srcs/
INC_DIR	= ./includes/

#################################################
###                 Sources                   ###
#################################################

SRC		= vm_main.c \
		  corewar.c \
		  display.c

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

$(EXEC): $(OBJ) $(INC_DIR)/$(EXEC).h
	@$(CC) $(FLAGS) $(HEADER) -o $(EXEC) $(OBJ) ../../libft/libft.a
	@echo "$(_CYAN)$(EXEC)$(_END)		: $(_GREEN)compiled$(_end)"
	@echo "$(_END)"

%.o: %.c
	@printf "%-60b\r" "$(ECHO)"
	@$(CC) $(FLAGS) -c $< -o $@ $(HEADER)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(EXEC)

re: fclean
	@make all

.PHONY: all clean fclean re
