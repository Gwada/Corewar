#!/bin/bash

#Outer_tests

#Usage: Simply add your test. Must follow the format outline below.

N_OUTER_TESTS=1

#Invalid dump
outer_test[$((N_OUTER_TESTS++))]="-dump" 
outer_test[$((N_OUTER_TESTS++))]="-dump 50"
outer_test[$((N_OUTER_TESTS++))]="-dump dsjfklsj"
outer_test[$((N_OUTER_TESTS++))]="-dump 50 -n"
outer_test[$((N_OUTER_TESTS++))]="-dump 50 5"
outer_test[$((N_OUTER_TESTS++))]="50 5"
outer_test[$((N_OUTER_TESTS++))]="-n -dump"
	
outer_test[$((N_OUTER_TESTS++))]="$VM_dir/valid_champions/Car.cor -dump" 
outer_test[$((N_OUTER_TESTS++))]="$VM_dir/valid_champions/Car.cor -n -dump" 
outer_test[$((N_OUTER_TESTS++))]="$VM_dir/valid_champions/Car.cor -n dump" 
outer_test[$((N_OUTER_TESTS++))]="$VM_dir/valid_champions/Car.cor -n 5" 
outer_test[$((N_OUTER_TESTS++))]="$VM_dir/valid_champions/Car.cor -n sdfsd" 
outer_test[$((N_OUTER_TESTS++))]="-n abc $VM_dir/valid_champions/Car.cor -n sdfsd" 
outer_test[$((N_OUTER_TESTS++))]="-n 1 $VM_dir/valid_champions/Car.cor -n 1 sdfsd" 
outer_test[$((N_OUTER_TESTS++))]="-n 1 -dump $VM_dir/valid_champions/Car.cor -n 1 sdfsd" 
outer_test[$((N_OUTER_TESTS++))]="-n 1 -dump a $VM_dir/valid_champions/Car.cor -n 1 sdfsd" 
outer_test[$((N_OUTER_TESTS++))]="-n -99991 $VM_dir/valid_champions/Car.cor" 
outer_test[$((N_OUTER_TESTS++))]="-n 1 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor" 
outer_test[$((N_OUTER_TESTS++))]="-n 1 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor" 
outer_test[$((N_OUTER_TESTS++))]="-n 1 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor -n 2 $VM_dir/valid_champions/Car.cor -n 3 $VM_dir/valid_champions/Car.cor" 
outer_test[$((N_OUTER_TESTS++))]="-n 2 $VM_dir/valid_champions/Car.cor -n 1 $VM_dir/valid_champions/Car.cor -n 2 $VM_dir/valid_champions/Car.cor -n 3 $VM_dir/valid_champions/Car.cor"
outer_test[$((N_OUTER_TESTS++))]="$VM_dir/valid_champions/Car.cor -n 3 $VM_dir/valid_champions/Car.cor -n 2 $VM_dir/valid_champions/Car.cor -n 3 $VM_dir/valid_champions/Car.cor"

#Invalid files
outer_test[$((N_OUTER_TESTS++))]="$VM_dir/outer/file" 
outer_test[$((N_OUTER_TESTS++))]="$VM_dir/$OUTER" 
	
#No argument
outer_test[$((N_OUTER_TESTS++))]="" 

let "N_OUTER_TESTS--"