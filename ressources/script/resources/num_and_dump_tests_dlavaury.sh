#!/bin/bash

#Dump_tests

#Usage: Simply add your test. Must follow the format outline below.

N_DUMP_TESTS=1
N_NUM_TESTS=1
N_NUM_AND_DUMP_TESTS=1

#Dump only tests
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump1 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump10 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump100 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump1000 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump2147483647 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump2147483648 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump9223372036854775807 $VM_dir/valid_champions/Car.cor"

#2P -ptests
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-p1 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-p2 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-p3 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-p4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-p1 $VM_dir/valid_champions/Car.cor -p2 $VM_dir/valid_champions/Car.cor" 

#3P -ptests
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-p1 $VM_dir/valid_champions/Car.cor -p2 $VM_dir/valid_champions/Car.cor -p3 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-p1 $VM_dir/valid_champions/Car.cor -p2 $VM_dir/valid_champions/Car.cor -p4 $VM_dir/valid_champions/Car.cor" 

#4P -ptests
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-p1 $VM_dir/valid_champions/Car.cor -p2 $VM_dir/valid_champions/Car.cor -p3 $VM_dir/valid_champions/Car.cor -p4 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-p4 $VM_dir/valid_champions/Car.cor -p2 $VM_dir/valid_champions/Car.cor -p3 $VM_dir/valid_champions/Car.cor"

#Dump and -ptests
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump1 -p4 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump10 -p4 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump100 -p4 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump1000 -p4 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump2147483647 -p4 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump2147483648 -p4 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump9223372036854775807 -p4 $VM_dir/valid_champions/Car.cor" 

num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump1 -p4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump10 -p4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump100 -p4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump1000 -p4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump2147483647 -p4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump2147483648 -p4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump9223372036854775807 -p4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 

num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump1 -p4 $VM_dir/valid_champions/Car.cor -p1 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump10 -p4 $VM_dir/valid_champions/Car.cor -p1 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump100 -p4 $VM_dir/valid_champions/Car.cor -p1 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump1000 -p4 $VM_dir/valid_champions/Car.cor -p1 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump2147483647 -p4 $VM_dir/valid_champions/Car.cor -p1 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump2147483648 -p4 $VM_dir/valid_champions/Car.cor -p1 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump9223372036854775807 -p4 $VM_dir/valid_champions/Car.cor -p1 $VM_dir/valid_champions/Car.cor"

let "N_NUM_AND_DUMP_TESTS--"