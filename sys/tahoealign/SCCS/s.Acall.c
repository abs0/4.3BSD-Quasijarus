h14858
s 00033/00000/00000
d D 1.1 86/07/20 11:13:59 sam 1 0
c date and time created 86/07/20 11:13:59 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h" 
call(infop)
process_info *infop;
/*
/*	Call a procedure with argument list on stack.
/*
/******************************************************/
{

	register long removed, mask, new_address, i, next, temp_fp;

	printf("entering call\n");
	removed = operand(infop, 0)->data & 0xffff ;
	printf("after first call to operand\n");
	new_address = operand(infop, 1)->address;
	printf("in call, removed = 0x%x , new_address=0x%x \n",removed, new_address);
	push (infop, fp);
	temp_fp = sp;
	mask = get_word (infop, new_address) & 0x1fff;  /* Only bits 12-0 */
	printf("in call, mask = 0x%x , pc=0x%x \n",mask,pc);
	push (infop, mask << 16 | removed);
	push (infop, pc);				/* Next opcode address */
	next = 12;				/* Register # to save */
	for (i = 0x1000; i != 0; i = i >> 1)
	{ 
		if ( i & mask ) push (infop,  Register (infop, next));
		next--; 
	}
	fp = temp_fp;
	pc = new_address + 2;			/* Transfer control */
}  
E 1
