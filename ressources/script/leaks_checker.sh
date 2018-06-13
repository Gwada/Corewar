#dir=/Users/dlavaury/C/Github/Corewar/ressources/champs
#dir=~/ASM_Corewar_tests
dir=./2BIG_/ASM_tests/all_champs/

rm $dir/*.cor
for file in $dir/*.s;
do
	echo "==> $file <=="
	valgrind --leak-check=full ./asm $file 2>> leaks.txt
	echo ""
	echo ""
done
