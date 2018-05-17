dir=cc/poub/champs
#dir=~/ASM_Corewar_tests

rm $dir/*.cor
for file in $dir/*.s;
do
	echo "==> $file <=="
	valgrind --leak-check=full ./asm $file 2>> leaks2.txt
	echo ""
	echo ""
done
