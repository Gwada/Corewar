#################################################
###                  Settings                 ###
#################################################

LIB = ./srcs/libft
ASM_EXEC_NAME = asm
VM_EXEC_NAME = corewar
ASM_SRCS = ./srcs/asm/
VM_SRCS = ./srcs/vm/

#Color
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

all: lib asm corewar

lib:
	@make -j3 -C $(LIB)

asm:
	@$(MAKE) -j3 -C $(ASM_SRCS)
	@mv -i $(ASM_SRCS)$(ASM_EXEC_NAME) ./

corewar:
	@$(MAKE) -j3 -C $(VM_SRCS)
	@mv -i $(VM_SRCS)$(VM_EXEC_NAME) ./

clean:
	@clear
	@make -C $(LIB) clean
	@$(MAKE) -C $(VM_SRCS) clean
	@$(MAKE) -C $(ASM_SRCS) clean
	@echo "$(_RED)clean$(_END)		: $(_GREEN)done$(_END)"

fclean: clean
	@make -C $(LIB) fclean
	@rm -f $(ASM_EXEC_NAME) $(VM_EXEC_NAME)
	@$(MAKE) -C $(VM_SRCS) fclean
	@$(MAKE) -C $(ASM_SRCS) fclean
	@echo "$(_RED)fclean$(_END)		: $(_GREEN)done$(_END)"

re: fclean
	@make all

.PHONY: all clean fclean re
