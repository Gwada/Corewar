#################################################
###                  Settings                 ###
#################################################

EXEC = asm
CC = clang
FLAGS = -Wall -Wextra -Werror
SRC_DIR = ./srcs/
INC_DIR = ./includes/
OBJ_DIR = ./objs/

#################################################
###                 Sources                   ###
#################################################

SRC =\
	 asm_main.c

#################################################
###                   Format                  ###
#################################################

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJ = $(notdir $(SRC:.c=.o))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

#################################################
###                   Rules                   ###
#################################################

.SILENT:
.PHONY: all clean fclean re

all: $(EXEC)

$(OBJS): $(SRCS)
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(FLAGS) -I$(INC_DIR) $^
	mv -f $(OBJ) $(OBJ_DIR)

$(EXEC): $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(EXEC)

re: fclean all
