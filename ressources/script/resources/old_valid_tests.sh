#!/bin/bash

#Valid_tests

#Usage: Simply add your test. Must follow the format outline below.

N_VALID_TESTS=1

#Valid dump
valid_test[$((N_VALID_TESTS++))]="-dump 1 $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 10 $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 100 $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 1000 $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 2147483647 $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 2147483648 $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 9223372036854775807 $VM_dir/valid_champions/Car.cor" 

valid_test[$((N_VALID_TESTS++))]="-dump 1 -n 4 $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 10 -n 4 $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 100 -n 4 $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 1000 -n 4 $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 2147483647 -n 4 $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 2147483648 -n 4 $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 9223372036854775807 -n 4 $VM_dir/valid_champions/Car.cor" 

valid_test[$((N_VALID_TESTS++))]="-dump 1 -n 4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 10 -n 4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 100 -n 4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 1000 -n 4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 2147483647 -n 4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 2147483648 -n 4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 9223372036854775807 -n 4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 

valid_test[$((N_VALID_TESTS++))]="-dump 1 -n 4 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 10 -n 4 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 100 -n 4 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 1000 -n 4 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 2147483647 -n 4 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 2147483648 -n 4 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-dump 9223372036854775807 -n 4 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor"

#Valid game 1P
valid_test[$((N_VALID_TESTS++))]="$VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="$VM_dir/valid_champions/Misaka_Mikoto.cor" 
valid_test[$((N_VALID_TESTS++))]="$VM_dir/valid_champions/zork.cor" 
valid_test[$((N_VALID_TESTS++))]="$VM_dir/valid_champions/zork.cor" 
valid_test[$((N_VALID_TESTS++))]="$VM_dir/valid_champions/add.cor" 
valid_test[$((N_VALID_TESTS++))]="$VM_dir/valid_champions/perso5.cor" 

#Valid game 2P
valid_test[$((N_VALID_TESTS++))]="-n 1 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-n 2 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-n 3 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-n 4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-n 1 $VM_dir/valid_champions/Car.cor -n 2 $VM_dir/valid_champions/Car.cor" 

#Valid game 3P
valid_test[$((N_VALID_TESTS++))]="-n 1 $VM_dir/valid_champions/Car.cor -n 2 $VM_dir/valid_champions/Car.cor -n 3 $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-n 1 $VM_dir/valid_champions/Car.cor -n 2 $VM_dir/valid_champions/Car.cor -n 4 $VM_dir/valid_champions/Car.cor" 

#Valid game 4P
valid_test[$((N_VALID_TESTS++))]="-n 1 $VM_dir/valid_champions/Car.cor -n 2 $VM_dir/valid_champions/Car.cor -n 3 $VM_dir/valid_champions/Car.cor -n 4 $VM_dir/valid_champions/Car.cor" 
valid_test[$((N_VALID_TESTS++))]="-n 4 $VM_dir/valid_champions/Car.cor -n 2 $VM_dir/valid_champions/Car.cor -n 3 $VM_dir/valid_champions/Car.cor" 

let "N_VALID_TESTS--"

#Invalid

# valid_test[$((N_VALID_TESTS++))]="$VM_dir/valid_champions/Car.cor -dump" 
# valid_test[$((N_VALID_TESTS++))]="$VM_dir/valid_champions/Car.cor -n -dump" 
# valid_test[$((N_VALID_TESTS++))]="$VM_dir/valid_champions/Car.cor -n dump" 
# valid_test[$((N_VALID_TESTS++))]="$VM_dir/valid_champions/Car.cor -n 5" 
# valid_test[$((N_VALID_TESTS++))]="$VM_dir/valid_champions/Car.cor -n sdfsd" 
# valid_test[$((N_VALID_TESTS++))]="-n abc $VM_dir/valid_champions/Car.cor -n sdfsd" 
# valid_test[$((N_VALID_TESTS++))]="-n 1 $VM_dir/valid_champions/Car.cor -n 1 sdfsd" 
# valid_test[$((N_VALID_TESTS++))]="-n 1 -dump $VM_dir/valid_champions/Car.cor -n 1 sdfsd" 
# valid_test[$((N_VALID_TESTS++))]="-n 1 -dump a $VM_dir/valid_champions/Car.cor -n 1 sdfsd" 
# valid_test[$((N_VALID_TESTS++))]="-n -99991 $VM_dir/valid_champions/Car.cor" 
# valid_test[$((N_VALID_TESTS++))]="-n 1 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor" 
# valid_test[$((N_VALID_TESTS++))]="-n 1 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor" 
# valid_test[$((N_VALID_TESTS++))]="-n 1 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor -n 2 $VM_dir/valid_champions/Car.cor -n 3 $VM_dir/valid_champions/Car.cor" 
# valid_test[$((N_VALID_TESTS++))]="-n 2 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor -n 2 $VM_dir/valid_champions/Car.cor -n 3 $VM_dir/valid_champions/Car.cor"
# valid_test[$((N_VALID_TESTS++))]="$VM_dir/valid_champions/Car.cor -n 3 $VM_dir/valid_champions/Car.cor -n 2 $VM_dir/valid_champions/Car.cor -n 3 $VM_dir/valid_champions/Car.cor"