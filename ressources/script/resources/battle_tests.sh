#!/bin/bash

#Dump_tests

#Usage: Simply add your test. Must follow the format outline below.

N_BATTLE_TESTS=1

#Valid game 1P
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/Car.cor" 
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/Misaka_Mikoto.cor" 
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/Rainbow_dash.cor" 
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/Varimathras.cor" 
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/casimir.cor" 
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/perso5.cor"

#Valid game 2P
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Octobre_Rouge_V4.2.cor" 
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/Misaka_Mikoto.cor $VM_dir/valid_champions/Octobre_Rouge_V4.2.cor" 
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/Rainbow_dash.cor $VM_dir/valid_champions/Octobre_Rouge_V4.2.cor" 
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/Varimathras.cor $VM_dir/valid_champions/Octobre_Rouge_V4.2.cor" 
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/casimir.cor $VM_dir/valid_champions/Octobre_Rouge_V4.2.cor" 
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/perso5.cor $VM_dir/valid_champions/Octobre_Rouge_V4.2.cor"

battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/skynet.cor $VM_dir/valid_champions/Octobre_Rouge_V4.2.cor"

#Valid game 4P
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/skynet.cor $VM_dir/valid_champions/Octobre_Rouge_V4.2.cor $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/zork.cor " 
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/skynet.cor $VM_dir/valid_champions/Octobre_Rouge_V4.2.cor $VM_dir/valid_champions/terminator.cor $VM_dir/valid_champions/zork.cor " 
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/skynet.cor $VM_dir/valid_champions/Octobre_Rouge_V4.2.cor $VM_dir/valid_champions/youforkmytralala.cor $VM_dir/valid_champions/zork.cor " 
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/skynet.cor $VM_dir/valid_champions/Octobre_Rouge_V4.2.cor $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/THUNDER.cor " 
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/Octobre_Rouge_V4.2.cor $VM_dir/valid_champions/skynet.cor $VM_dir/valid_champions/THUNDER.cor " 
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/skynet.cor $VM_dir/valid_champions/Octobre_Rouge_V4.2.cor $VM_dir/valid_champions/Wall.cor $VM_dir/valid_champions/zork.cor " 
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/skynet.cor $VM_dir/valid_champions/Octobre_Rouge_V4.2.cor $VM_dir/valid_champions/champ.cor $VM_dir/valid_champions/zork.cor " 
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/skynet.cor $VM_dir/valid_champions/Octobre_Rouge_V4.2.cor $VM_dir/valid_champions/Varimathras.cor $VM_dir/valid_champions/zork.cor " 
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/skynet.cor $VM_dir/valid_champions/Octobre_Rouge_V4.2.cor $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/bigzork.cor " 
battle_test[$((N_BATTLE_TESTS++))]="$VM_dir/valid_champions/skynet.cor $VM_dir/valid_champions/Octobre_Rouge_V4.2.cor $VM_dir/valid_champions/Car.cor $VM_dir/valid_champions/darksasuke.cor " 

let "N_BATTLE_TESTS--"