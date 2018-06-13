#!/bin/bash

#Dump_tests

#Usage: Simply add your test. Must follow the format outline below.

N_DUMP_TESTS=1
N_NUM_TESTS=1
N_NUM_AND_DUMP_TESTS=1

#Dump only tests
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 1 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 10 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 100 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 1000 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 2147483647 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 2147483648 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 9223372036854775807 $VM_dir/valid_champions/Car.cor"

#2P -n tests
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-n 1 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-n 2 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-n 3 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-n 4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-n 1 $VM_dir/valid_champions/Car.cor -n 2 $VM_dir/valid_champions/Car.cor" 

#3P -n tests
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-n 1 $VM_dir/valid_champions/Car.cor -n 2 $VM_dir/valid_champions/Car.cor -n 3 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-n 1 $VM_dir/valid_champions/Car.cor -n 2 $VM_dir/valid_champions/Car.cor -n 4 $VM_dir/valid_champions/Car.cor" 

#4P -n tests
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-n 1 $VM_dir/valid_champions/Car.cor -n 2 $VM_dir/valid_champions/Car.cor -n 3 $VM_dir/valid_champions/Car.cor -n 4 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-n 4 $VM_dir/valid_champions/Car.cor -n 2 $VM_dir/valid_champions/Car.cor -n 3 $VM_dir/valid_champions/Car.cor"

#Dump and -n tests
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 1 -n 4 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 10 -n 4 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 100 -n 4 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 1000 -n 4 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 2147483647 -n 4 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 2147483648 -n 4 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 9223372036854775807 -n 4 $VM_dir/valid_champions/Car.cor" 

num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 1 -n 4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 10 -n 4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 100 -n 4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 1000 -n 4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 2147483647 -n 4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 2147483648 -n 4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 9223372036854775807 -n 4 $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Car.cor" 

num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 1 -n 4 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 10 -n 4 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 100 -n 4 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 1000 -n 4 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 2147483647 -n 4 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 2147483648 -n 4 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor" 
num_and_dump_test[$((N_NUM_AND_DUMP_TESTS++))]="-dump 9223372036854775807 -n 4 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor"

let "N_NUM_AND_DUMP_TESTS--"