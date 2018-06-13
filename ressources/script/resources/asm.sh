#!/bin/bash

A_KILL=" /& sleep 1; pkill asm"

asm_compile_zaz()
{
	# printf "$COLOR\0Compiling Zaz...This can take up to 6 minutes...\n$END"
	printf "$COLOR\0Compiling Zaz...\n$END"

    rm -rf $ASM_dir/zaz_cor
    mkdir -p $ASM_dir/zaz_cor
    printf "$COLOR\0[$END"
    for file in $ASM_dir/s_files/*.s;
        do
	        ./$ASM_dir/zaz $file > /dev/null 2>&1
	        # ./$ASM_dir/zaz $file
            printf "$COLOR\0■$END"
        done
    printf "$COLOR\0]$END"
    for file in $ASM_dir/s_files/*.cor;
        do
            mv $file $ASM_dir/zaz_cor/
        done
}

asm_compile_you()
{
	printf "$COLOR\nCompiling you...\n$END"

    ASM_TEST_COUNT=0

    rm 2> /dev/null your_prog_log.txt
    rm -rf $ASM_dir/your_cor
    mkdir -p $ASM_dir/your_cor
    printf "$COLOR\0[$END"
        for file in $ASM_dir/s_files/*.s;
            do
	            ./$ASM_dir/asm $file >> $ASM_dir/your_asm_log.txt 2>&1
                printf "$COLOR\0■$END"
                let "ASM_TEST_COUNT++"
                # echo $file
            done
    printf "$COLOR\0]$END"
        for file in $ASM_dir/s_files/*.cor;
            do
                mv $file $ASM_dir/your_cor/
            done
}

asm_make_a_difference()
{
    rm 2> /dev/null $ASM_dir/diff_log.txt

	printf "$COLOR\n\nWill you make a difference ?\n\n$END"

    diff -bur $ASM_dir/your_cor $ASM_dir/zaz_cor >> $ASM_dir/diff_log.txt
    cat $ASM_dir/diff_log.txt

    local failed=$(cat $ASM_dir/diff_log.txt | wc -l)
   	printf "$COLOR\n$(expr $ASM_TEST_COUNT - $failed)/$ASM_TEST_COUNT tests passed\n$END"
}

asm_valid_champs()
{
    print_title "ASM TESTS"
	printf "$COLOR\0VALID CHAMPS\n$END"

   	printf "\n"
    asm_compile_zaz
    asm_compile_you
    asm_make_a_difference

    read -p "Press enter to continue..."    
}


asm_invalid_champs()
{
    print_title "ASM TESTS"
	printf "$COLOR\0INVALID CHAMPS\n$END"
    
    local dir=$ASM_dir/your_invalid_cor

    rm -rf 2> /dev/null $dir/
    mkdir $dir

    printf "$COLOR\n[$END"
    for file in $ASM_dir/invalid_champions/*.s;
        do
	        ./$ASM_dir/asm $file > /dev/null 2>&1
            printf "$COLOR\0■$END"
			# echo $file
        done
    printf "$COLOR]$END\n"

    mv $ASM_dir/invalid_champions/*.cor $dir
    if [ "$(ls -A $dir)" ]; then
        printf "$COLOR\n\n\t<< I never asked for this. >>\n\n\t\t\t\tAdam Jensen\n\n$END"
        ls -1 $dir/*.cor
        printf "$COLOR\n(Your ASM should not compile these files...That's what ZAZ said)\n\n$END"
    else
        printf "$COLOR\n\n\t<< Your ASM is augmented. >>\n\n\t\t\t\tvtennero\n\n$END"
    fi
}

run_asm_tests()
{
    print_title "ASM TESTS"

    if [ $(ls | grep asm) ]
	then
		cp asm $ASM_dir/

        #COMMENT THE FOLLOWING LINE TO SKIP VALID CHAMP CHECKS
        asm_valid_champs

        #COMMENT THE FOLLOWING LINE TO SKIP INVALID CHAMP CHECKS
        asm_invalid_champs
	else
		printf "$COLOR\0Move your asm to the current folder, then restart (File must be named asm).\n$END"
	fi
	printf "$COLOR\0[ASM TESTS DONE]\n$END"
}