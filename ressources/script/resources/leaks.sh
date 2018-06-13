#!/bin/bash

DIFF_T=code_size_differs
HEAD_T=invalid_header
LARGE_T=too_large
SMALL_T=too_small
VALID_T=valid_champions

DIFF=$VM_dir/inner/$DIFF_T
HEAD=$VM_dir/inner/$HEAD_T
LARGE=$VM_dir/inner/$LARGE_T
SMALL=$VM_dir/inner/$SMALL_T
VALID=$VM_dir/$VALID_T

VALGRIND_LOGS_DIR="valgrind_logs"
VALGRIND_LOGS_FILENAME="vlg_"

V_KILL="/& sleep 3; pkill valgrind"

valgrind_by_set_outer()
{
	local c=1
	local i=1

	rm -rf 2> /dev/null $VM_dir/outer/outer_leaks_log.txt $VM_dir/outer/$VALGRIND_LOGS_DIR
	mkdir -p $VM_dir/outer/$VALGRIND_LOGS_DIR

	printf "$COLOR\0[outer invalid arguments]\n$END"

	while [ $i -le $N_OUTER_TESTS ]
		do
			local STORAGE_PATH=$VM_dir/outer/$VALGRIND_LOGS_DIR"/"$VALGRIND_LOGS_FILENAME"outer_$i"
			$HOME/.brew/Cellar/valgrind/3.13.0/bin/valgrind --leak-check=full --log-file="$STORAGE_PATH" ./$VM_dir/corewar ${outer_test[$i]} > /dev/null 2>&1
			local definitely_lb=$(cat $STORAGE_PATH | grep "definitely lost: " | cut -d " " -f7)
			local indirectly_lb=$(cat $STORAGE_PATH | grep "indirectly lost: " | cut -d " " -f7)
			if [ "$definitely_lb" != "0" ] || [ "$indirectly_lb" != "0" ]
			then
				printf "outer_test[$i]:\t\t\t$definitely_lb bytes definitely lost, $indirectly_lb bytes indirectly lost\n" >> $VM_dir/outer/outer_leaks_log.txt
				printf "💦 "
			else
				printf "$COLOR.$END"
			fi
			let "i++";
		done
		printf "\n"

		printf "$COLOR\0Logs in: $VM_dir/outer/$VALGRIND_LOGS_DIR\n\n$END"
		cat $VM_dir/outer/outer_leaks_log.txt 2>/dev/null
	    # read -p "Press enter to continue..."
}

valgrind_by_set_battle()
{
	local c=1
	local i=1

	rm -rf 2> /dev/null $VM_dir/battle/battle_leaks_log.txt $VM_dir/battle/$VALGRIND_LOGS_DIR
	mkdir -p $VM_dir/battle/$VALGRIND_LOGS_DIR

	printf "$COLOR\0[normal games (multiple players)]\n$END"

	while [ $i -le $N_BATTLE_TESTS ]
		do
			local STORAGE_PATH=$VM_dir/battle/$VALGRIND_LOGS_DIR"/"$VALGRIND_LOGS_FILENAME"battle_$i"
			$HOME/.brew/Cellar/valgrind/3.13.0/bin/valgrind --leak-check=full --log-file="$STORAGE_PATH" ./$VM_dir/corewar ${battle_test[$i]} > /dev/null 2>&1
			local definitely_lb=$(cat $STORAGE_PATH | grep "definitely lost: " | cut -d " " -f7)
			local indirectly_lb=$(cat $STORAGE_PATH | grep "indirectly lost: " | cut -d " " -f7)
			if [ "$definitely_lb" != "0" ] || [ "$indirectly_lb" != "0" ]
			then
				printf "battle_test[$i]:\t\t\t$definitely_lb bytes definitely lost, $indirectly_lb bytes indirectly lost\n" >> $VM_dir/battle/battle_leaks_log.txt
				printf "💦 "
			else
				printf "$COLOR.$END"
			fi
			let "i++";
		done
		printf "\n"

		printf "$COLOR\0Logs in: $VM_dir/$VALGRIND_LOGS_DIR\n\n$END"
		cat $VM_dir/battle/battle_leaks_log.txt 2>/dev/null
	    # read -p "Press enter to continue..."
}

valgrind_by_file()
{
	local i=1

	printf "$COLOR\0[$2]\n$END"

	rm -rf 2> /dev/null $1/$VALGRIND_LOGS_DIR $1/$2_leaks_log.txt
	mkdir -p $1/$VALGRIND_LOGS_DIR

	for file in $1/*$4;
		do
			# echo $file
			local STORAGE_PATH=$1/$VALGRIND_LOGS_DIR"/"$VALGRIND_LOGS_FILENAME"$2_$i"
			$HOME/.brew/Cellar/valgrind/3.13.0/bin/valgrind --leak-check=full --log-file="$STORAGE_PATH" $3 $file > /dev/null 2>&1
			local definitely_lb=$(cat $STORAGE_PATH | grep "definitely lost: " | cut -d " " -f7)
			local indirectly_lb=$(cat $STORAGE_PATH | grep "indirectly lost: " | cut -d " " -f7)
			if [ "$definitely_lb" != "0" ] || [ "$indirectly_lb" != "0" ]
			then
				printf "$file:\t\t\t$definitely_lb bytes definitely lost, $indirectly_lb bytes indirectly lost\n" >> $1/$2_leaks_log.txt
				printf "💦 "
			else
				printf "$COLOR.$END"
			fi
			let "i++";
		done
		printf "\n"

	printf "$COLOR\0Logs in: $1/$VALGRIND_LOGS_DIR\n\n$END"
	cat $1/$2_leaks_log.txt 2>/dev/null
}

valgrind_asm()
{
	print_title "LEAK TESTS"
	printf "$COLOR\0ASM\n$END"
	printf "$COLOR\0Warning /!\\ Launching valgrind with fsanitize will result in session crash! Ctrl+C to stop now!\n$END"

	cp asm $ASM_dir/
	
	rm -rf 2> /dev/null $ASM_dir/all_champs/*.cor

	valgrind_by_file $ASM_dir/all_champs ALL_CHAMPS ./$ASM_dir/asm .s

	mv $ASM_dir/all_champs/ALL_CHAMPS_leaks_log.txt ../ 2> /dev/null

	rm -rf 2> /dev/null $ASM_dir/all_champs/*.cor
	
    read -p "Press enter to continue..."
}

valgrind_vm()
{
	print_title "LEAK TESTS"
	printf "$COLOR\0VM\n$END"
	printf "$COLOR\0Warning /!\\ Launching valgrind with fsanitize will result in session crash! Ctrl+C to stop now!\n\n$END"

	cp corewar $VM_dir/

	#COMMENT THE FOLLOWING LINES TO SKIP SOME OF THE LEAK CHECKS (CAN TAKE A WHILE...)
	valgrind_by_set_outer
	valgrind_by_file $DIFF $DIFF_T ./$VM_dir/corewar .cor
	valgrind_by_file $HEAD $HEAD_T ./$VM_dir/corewar .cor
	valgrind_by_file $LARGE $LARGE_T ./$VM_dir/corewar .cor
	valgrind_by_file $SMALL $SMALL_T ./$VM_dir/corewar .cor
	valgrind_by_set_battle

    # read -p "Press enter to continue..."
	
}

run_leaks_tests()
{
	local VERSION=$(ls $HOME/.brew/Cellar | grep valgrind)

	print_title "LEAK TESTS"

	if [ $VERSION ]
	then
		#COMMENT THE FOLLOWING LINE TO SKIP *ALL* ASM LEAK CHECKS
		# valgrind_asm

		#COMMENT THE FOLLOWING LINE TO SKIP *ALL* VM LEAK CHECKS
		valgrind_vm
	else
		printf "$COLOR\0Valgrind is not installed on this machine.\n
		Installing it now...$END"
		brew update && brew install valgrind && alias valgrind="~/.brew/bin/valgrind"
	fi
	
	rm -rf 2> /dev/null $ASM_dir/asm.dSYM asm.dSYM $VM_dir/corewar.dSYM
	
	printf "$COLOR\n[LEAKS DONE]\n$END"
}
