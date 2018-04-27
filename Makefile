#################################################
###                  Settings                 ###
#################################################

ASM_EXEC_NAME = asm
VM_EXEC_NAME = corewar
ASM_SRCS = ./srcs/asm/
VM_SRCS = ./srcs/vm/

#################################################
###                   Rules                   ###
#################################################

.SILENT:
.PHONY: all clean fclean re

all: asm corewar

asm:
	$(MAKE) -C $(ASM_SRCS)
	mv -i $(ASM_SRCS)$(ASM_EXEC_NAME) ./

corewar:
	$(MAKE) -C $(VM_SRCS)
	mv -i $(VM_SRCS)$(VM_EXEC_NAME) ./

clean:
	$(MAKE) -C $(VM_SRCS) clean
	$(MAKE) -C $(ASM_SRCS) clean

fclean: clean
	rm -rf $(ASM_EXEC_NAME) $(VM_EXEC_NAME)
	$(MAKE) -C $(VM_SRCS) fclean
	$(MAKE) -C $(ASM_SRCS) fclean

re: fclean all
