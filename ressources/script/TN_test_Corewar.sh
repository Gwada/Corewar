#!/bin/bash

ASM_dir=ASM_tests
#VM_dir=VM_tests

ERROR_OUTPUT="ERROR"
USAGE_OUTPUT="Usage:"
TIMEOUT=15

source resources/asm.sh
source resources/vm.sh
source resources/leaks.sh
source resources/assets_interface.sh
source resources/outer_tests.sh
source resources/num_and_dump_tests_dlavaury.sh
# source resources/num_and_dump_tests.sh
source resources/battle_tests.sh

# run_animation
print_start_title

#MODIFY THE FOLLOWING VARIABLES TO MATCH YOUR OUTPUT FORMAT (FOR GREP PURPOSES)
ERROR_OUTPUT="ERROR"
USAGE_OUTPUT="Usage:"

if [ $# -eq 0 ] || [ $1 == "all" ] ;
then
	run_asm_tests
#	run_vm_tests
#	run_leaks_tests
	printf "$COLOR\0[ALL DONE]\n$END"
elif [ $1 == "asm" ] ;
then
	run_asm_tests
elif [ $1 == "vm" ] ;
then
	run_vm_tests
elif [ $1 == "leaks" ] ;
then
	run_leaks_tests
else
	print_usage
fi
