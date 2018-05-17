#################################################
###                  Settings                 ###
#################################################

EXEC	= asm
CC		= clang
FLAGS	= -Wall -Wextra -Werror -g3
HEADER	= -I $(INC_DIR) -I ./libft/includes/
SRC_DIR	= ./srcs/
INC_DIR	= ./includes/

#################################################
###                 Sources                   ###
#################################################

SRC		= m_asm.c\
		  f_tool.c\
		  s_tool.c\
		  f_rdwr.c\
		  g_data.c\
		  s_init.c\
		  p_type.c\
		  s_free.c\
		  op.c\

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

<<<<<<< HEAD
all: lib $(EXEC)
=======
all:
	@make lib
	@make $(EXEC)
>>>>>>> e50bab15643a600707bf17376c0db53b21a4f54c

$(EXEC): $(OBJ) $(INC_DIR)/$(EXEC).h
	@$(CC) $(FLAGS) $(HEADER) -o $(EXEC) $(OBJ) ./libft/libft.a
	@echo "$(_CYAN)Assembleur$(_END)	: $(_GREEN)compiled$(_end)"

%.o: %.c
	@printf "%-60b\r" "$(ECHO)"
	@$(CC) $(FLAGS) -c $< -o $@ $(HEADER)

lib:
	@make -C ./libft/

clean:
	@make -C ./libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C ./libft/ fclean
	@rm -f $(EXEC)

re: fclean
	@make all

.PHONY: all clean fclean re libft
