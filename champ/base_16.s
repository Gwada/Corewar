.name "base_16"
.comment "this is a comment"

init_player:	sti r1, %:live, %1

init_carry:		add r2, r3, r4

dup:			live %1
				fork %0

live:			live %1
				zjmp %:live
