.comment "I'M ALIIIIVE"
.name "zork"

l2:		sti r1, %:live, r1
		and r1, %0, r1

live:	live %1
		zjmp %:live
