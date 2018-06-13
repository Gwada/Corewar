#!/bin/bash

OUTER=$VM_dir/outer/tests_logs
INNER=$VM_dir/inner/tests_logs

DIFF_T=code_size_differs
HEAD_T=invalid_header
LARGE_T=too_large
SMALL_T=too_small

DIFF=$VM_dir/inner/$DIFF_T
HEAD=$VM_dir/inner/$HEAD_T
LARGE=$VM_dir/inner/$LARGE_T
SMALL=$VM_dir/inner/$SMALL_T

V_KILL="/& sleep $TIMEOUT; pkill corewar"

vm_compile_zaz()
{
	printf "$COLOR\0Compiling Zaz...This will take some time...\n$END"

    rm 2> /dev/null vm_log_zaz.txt

    for file in $VM_dir/valid_champions/*.cor;
        do
			echo $file >> vm_log_zaz.txt
	        ./$VM_dir/corzaz $file >> vm_log_zaz.txt 2>&1 
	        # ./$VM_dir/corzaz $file
			sleep 0.5
			pkill corzaz
			pkill corzaz
			pkill corzaz
			echo "\n" >> vm_log_zaz.txt
        done
}

outer_parsing_tests()
{
	local i=1
	local failed=0

	print_title "VM_TESTS"
	printf "$COLOR\0OUTER PARSING TESTS\n\n$END"

	rm -rf 2> /dev/null $OUTER
	mkdir -p $OUTER
	
	while [ $i -le $N_OUTER_TESTS ]
	do
		# printf "$COLOR\0$ERROR_OUTPUT on TEST $i 🔥\n$END" >> $OUTER/TEST[$i].txt &>/dev/null
		printf "$COLOR\0$ERROR_OUTPUT on TEST $i 🔥\n$END" >> $OUTER/TEST[$i].txt 2>&1
		# printf "./$VM_dir/corewar ${outer_test[$i]}\n" >> $OUTER/TEST[$i].txt &>/dev/null
		printf "./$VM_dir/corewar ${outer_test[$i]}\n" >> $OUTER/TEST[$i].txt 2>&1
		# ./$VM_dir/corewar ${outer_test[$i]} >> $OUTER/TEST[$i].txt &>/dev/null
		./$VM_dir/corewar ${outer_test[$i]} >> $OUTER/TEST[$i].txt 2>&1
		# pkill corewar
		# if grep -r "$USAGE_OUTPUT" $OUTER/TEST[$i].txt > /dev/null;
		if grep -r "ERROR" $OUTER/TEST[$i].txt > /dev/null;
			then
				printf "$COLOR\0.$END"
				rm $OUTER/TEST[$i].txt
			else
				printf "🔥 "
				let "failed++"
		fi
		let "i++"
	done
	printf "\n\n"

	cat $OUTER/* 2>/dev/null

	# printf "$COLOR\n$(expr $N_OUTER_TESTS - $failed)/$N_OUTER_TESTS tests passed\n$END"
	printf "$COLOR\0[OUTER PARSING TESTS DONE]\n$END"
    read -p "Press enter to continue..."
}

inner_parsing_tests()
{
	local i=1

	print_title "VM_TESTS"
	printf "$COLOR\0INNER PARSING TESTS\n$END"
	printf "$COLOR\0[$2]\n\n$END"

	rm -rf 2> /dev/null $1/tests_logs
	mkdir -p $1/tests_logs

	for file in $1/*.cor;
        do
			printf "$COLOR\0$ERROR_OUTPUT on Outer_test[$i] 🔥\n$END" >> $1/tests_logs/TEST[$i].txt 2>&1
			printf "./$VM_dir/corewar $file\n" >> $1/tests_logs/TEST[$i].txt 2>&1
	        ./$VM_dir/corewar $file >> $1/tests_logs/TEST[$i].txt 2>&1
# 			# pkill corewar
			# if grep -r "$USAGE_OUTPUT" $1/tests_logs/TEST[$i].txt > /dev/null;
			if grep -r "$ERROR_OUTPUT" $1/tests_logs/TEST[$i].txt > /dev/null;
			then
				printf "$COLOR\0.$END"
				rm $1/tests_logs/TEST[$i].txt
			else
				printf "🔥 "
		fi
		let "i++"
        done
	printf "\n\n"
	cat $1/tests_logs/* 2>/dev/null

    read -p "Press enter to continue..."
}

run_invalid_inputs()
{
	outer_parsing_tests
	inner_parsing_tests $DIFF $DIFF_T
	inner_parsing_tests $HEAD $HEAD_T
	inner_parsing_tests $LARGE $LARGE_T
	inner_parsing_tests $SMALL $SMALL_T
}

run_num_and_dump()
{
	print_title "VM_TESTS"
	printf "$COLOR\0VALID INPUTS\n\n$END"
	
	local i=1
	local dir=$VM_dir/num_and_dump
	local exec=$VM_dir/natapolcorewar
	failed=0

	rm -rf 2> /dev/null $dir/you
	rm -rf 2> /dev/null $dir/exec
	rm -rf 2> /dev/null $dir/diff
	mkdir -p $dir/you
	mkdir -p $dir/exec
	mkdir -p $dir/diff

	while [ $i -le $N_NUM_AND_DUMP_TESTS ]
	do
	    # ./$VM_dir/corewar ${num_and_dump_test[$i]} > $dir/you/your_output_$i 2>&1 /& sleep 3; pkill corewar
	    ./$VM_dir/corewar ${num_and_dump_test[$i]} > $dir/you/your_output_$i 2>&1
	    ./$exec ${num_and_dump_test[$i]} > $dir/exec/exec_output_$i 2>&1
		echo $(tail -1 $dir/exec/exec_output_$i) > $dir/exec/exec_output_$i
		echo $(tail -1 $dir/you/your_output_$i) > $dir/you/your_output_$i
		diff -u $dir/you/your_output_$i $dir/exec/exec_output_$i > $dir/diff/diff_log_$i.txt
		if [ -s $dir/diff/diff_log_$i.txt ]
		then
			printf "🔥 "
			printf "\nCommands to run:\n" >> $dir/diff/diff_log_$i.txt
			printf "./VM_tests/corewar ${num_and_dump_test[$i]}\n" >> $dir/diff/diff_log_$i.txt
			printf "./VM_tests/corzaz ${num_and_dump_test[$i]}\n" >> $dir/diff/diff_log_$i.txt
			let "failed++"
		else
			printf "$COLOR.$END"
			rm $dir/diff/diff_log_$i.txt
		fi
		let "i++"
	done

	printf "\n\n"

	read_diff $dir/diff

	read -p "Press enter to continue..."
}

run_battle()
{
	print_title "VM_TESTS"
	printf "$COLOR\0VALID INPUTS\n\n$END"
	
	local i=1
	local dir=$VM_dir/battle
	local exec=$VM_dir/corzaz
	failed=0

	rm -rf 2> /dev/null $dir/you
	rm -rf 2> /dev/null $dir/exec
	rm -rf 2> /dev/null $dir/diff
	mkdir -p $dir/you
	mkdir -p $dir/exec
	mkdir -p $dir/diff

	while [ $i -le $N_BATTLE_TESTS ]
	do
	    ./$VM_dir/corewar ${battle_test[$i]} > $dir/you/your_output_$i 2>&1
	    # ./$VM_dir/corewar ${test_set[$i]} > $dir/you/your_output_$i 2>&1 /& sleep 1; pkill corewar
	    ./$exec ${battle_test[$i]} > $dir/exec/exec_output_$i 2>&1
		echo $(tail -1 $dir/exec/exec_output_$i) > $dir/exec/exec_output_$i
		echo $(tail -1 $dir/you/your_output_$i) > $dir/you/your_output_$i
		diff -u $dir/you/your_output_$i $dir/exec/exec_output_$i > $dir/diff/diff_log_$i.txt
		if [ -s $dir/diff/diff_log_$i.txt ]
		then
			printf "🔥 "
			printf "\nCommands to run:\n" >> $dir/diff/diff_log_$i.txt
			printf "./VM_tests/corewar ${battle_test[$i]}\n" >> $dir/diff/diff_log_$i.txt
			printf "./VM_tests/corzaz ${battle_test[$i]}\n" >> $dir/diff/diff_log_$i.txt
			let "failed++"
		else
			printf "$COLOR.$END"
			rm $dir/diff/diff_log_$i.txt
		fi
		let "i++"
	done

	printf "\n\n"

	read_diff $dir/diff

	# read -p "Press enter to continue..."
}

read_diff()
{
	if [ $failed -gt 0 ]
	then
		read -p "Press enter to view diff..."
		for file in $1/*;
		do
			clear
			printf "$COLOR\0ERROR on $END"
			echo "$COLOR${file##*/}$END 🔥"
			cat $file 2>/dev/null
			read -p "Press enter to continue..."
		done
	fi
}

run_vm_tests()
{
	print_title "VM_TESTS"

	if [ $(ls | grep corewar) ]
	then
		cp corewar $VM_dir/
	    # vm_compile_zaz
		run_invalid_inputs
		run_num_and_dump
		run_battle
	else
		printf "$COLOR\0Move your corewar to the current folder, then restart (File must be named corewar).\n$END"
	fi

	printf "$COLOR\0[VM TESTS DONE]\n$END"
}
