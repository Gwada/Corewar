.name "champion"
.comment "A basic champion"

start:
	sti r1, %:life, %0
	st r16, -5
	and %0, %0, r2
	zjmp %:init

alive:
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	st r16, 6
	live %42
	and %0, %0, r1
	zjmp %:alive

more:
	st r16, 6
	live %42
	fork %:more
	fork %:alive
	zjmp %:more

life:
	st r1, r1

init:
	ldi %0, %:life, r16
	st r16, 6
	live %42
	ld %167771649, r2
	ld %167771649, r3
	ld %167771649, r4
	ld %167771649, r5
	ld %167771649, r6
	ld %167771649, r7
	ld %167771649, r8
	ld %167771649, r9
	ld %167771649, r10
	ld %167771649, r11
	ld %167771649, r12
	ld %167771649, r13
	ld %167771649, r14
	ld %167771649, r15
	st r16, 6
	live %42
	and %0, %0, r15
	zjmp %:more

end:
