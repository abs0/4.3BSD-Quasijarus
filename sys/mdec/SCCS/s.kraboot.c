h48005
s 00002/00002/00080
d D 7.2 04/02/28 23:38:17 msokolov 2 1
c move to using R5<31:28> instead of <15:12> for partition
e
s 00082/00000/00000
d D 7.1 99/09/05 15:34:05 msokolov 1 0
c date and time created 99/09/05 15:34:05 by msokolov
e
u
U
t
T
I 1
/*
 * Copyright (c) 1980,1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

/* "%W% (Berkeley) %G%" */
#include <sys/disklabel.h>

	.set	MAJOR,16		/* major("/dev/kra0a") */

/*
 * 1st level boot program: loads next 7.5Kbytes from
 * boot sector of file system and sets it up to run.
 * Except for MAJOR definition above, should work
 * with any disk using 750 boot rom.
 */
	.set	RELOC,0x50000
	.set	BOOTLAST,15		/* last boot sector */
	.set	RABPSECT,512		/* bytes per sector */

init:
	.word	0  			/* entry mask for dec monitor */
	nop;nop;nop;nop;nop;nop;nop;nop /* some no-ops for 750 boot to skip */
	nop;nop;
start:
	movl	$MAJOR,r10		/* major("/dev/xx0a") */
	insv	r3,$16,$8,r10		/* drive number */
D 2
	extzv	$12,$4,r5,r4		/* get partition from r5 */
	bicw2	$0xf000,r5		/* remove from r5 */
E 2
I 2
	extzv	$28,$4,r5,r4		/* get partition from r5 */
	bicl2	$0xf0000000,r5		/* remove from r5 */
E 2
	insv	r4,$8,$8,r10		/* set partition */
	movl	r5,r11			/* boot flags */
	movl	r1,r9			/* UNIBUS I/O page address */
	movl	r2,r8			/* boot device CSR */
	movl	r3,r7			/* unit number */
	brw	start0

/*
 * Leave space for pack label.
 */
pad:
	.space	LABELOFFSET - (pad - init)
packlabel:
	.space	d_end_

start0:
	movl	$RELOC,sp
	moval	init,r4
	movc3	$end,(r4),(sp)
	movl	r9,r1			/* UNIBUS I/O page address */
	movl	r8,r2			/* boot device CSR */
	movl	r7,r3			/* unit number */
	jmp	*$RELOC+start2
/* now running relocated */
/* bring in the boot program */
start2:					/* running relocated */
	pushr	$0xffff			/* BEGIN FIREWALL */
	movl	$1,r4			/* first boot sector */
	clrl	r5			/* transfer address */
	clrl	-(sp)			/* transfer address */
1:
	movl	r4,r8			/* requested sector # */
	jsb	(r6)			/* call ROM-based driver */
	blbs	r0,2f
	halt				/* read error */
2:
	addl2	$RABPSECT,r5		/* bump address */
	movl	r5,(sp)
	aobleq	$BOOTLAST,r4,1b

	.set	PROGSIZE,(BOOTLAST*RABPSECT)
done:
	tstl	(sp)+			/* pop address */
	popr	$0xffff			/* END FIREWALL */
	movl	$PROGSIZE,r4
clrcor:
	clrq	(r4)
	acbl	$RELOC,$8,r4,clrcor
/* start loaded program */
	calls	$0,*$0
	brw	start2
end:
E 1
