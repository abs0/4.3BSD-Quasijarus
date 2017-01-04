h09554
s 00005/00005/00080
d D 7.3 04/02/28 23:38:18 msokolov 11 10
c move to using R5<31:28> instead of <15:12> for partition
e
s 00012/00000/00073
d D 7.2 86/08/28 20:59:13 karels 10 9
c changes for pack labels; use cpp, now are *.c
e
s 00000/00000/00073
d D 7.1 86/06/05 01:52:51 mckusick 9 8
c 4.3BSD release version
e
s 00025/00014/00048
d D 6.4 86/03/17 12:31:00 karels 8 7
c use unit and uba from registers; don't clobber last block of bootra
e
s 00001/00003/00061
d D 6.3 85/06/26 14:02:37 bloom 7 6
c sccsids aren't executable kirk
e
s 00009/00001/00055
d D 6.2 85/06/08 12:20:02 mckusick 6 5
c Add copyright
e
s 00000/00000/00056
d D 6.1 83/07/29 07:43:17 sam 5 4
c 4.2 distribution
e
s 00020/00013/00036
d D 4.3 83/05/03 21:10:58 sam 4 3
c made to work by rws@mit-xx
e
s 00037/00128/00012
d D 4.2 83/02/20 22:22:14 sam 3 1
c coded, now test
e
s 00036/00128/00012
d R 4.2 83/02/20 22:14:30 sam 2 1
c works maybe?
e
s 00140/00000/00000
d D 4.1 83/02/16 22:06:23 sam 1 0
c date and time created 83/02/16 22:06:23 by sam
e
u
U
t
T
I 1
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
/*
D 8
 * Copyright (c) 1980 Regents of the University of California.
E 8
I 8
 * Copyright (c) 1980,1986 Regents of the University of California.
E 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 7
#ifndef lint
_sccsid:.asciz	"%W% (Berkeley) %G%"
#endif not lint
E 7
I 7
/* "%W% (Berkeley) %G%" */
I 10
#include <sys/disklabel.h>
E 10
E 7
E 6

I 8
	.set	MAJOR,9			/* major("/dev/ra0a") */

E 8
/*
D 3
 * From 4.1 boot sector code by Scott Comer (Rice University).
E 3
I 3
D 8
 * UDA50 1st level boot program: loads next 7.5Kbytes from
E 8
I 8
 * 1st level boot program: loads next 7.5Kbytes from
E 8
 * boot sector of file system and sets it up to run.
I 8
 * Except for MAJOR definition above, should work
 * with any disk using 750 boot rom.
E 8
D 4
 *	UNTESTED
E 4
E 3
 */
D 3
	.set	BOOTBASE, 0xfe00	/* relocated home of boot block */
	/*
	 * These three hold the register contents needed by the
	 * ROM driver subroutine to access the boot device.
	 */
	.set	driver_r1, DATA		
	.set	driver_r2, driver_r1+4	
	.set	driver_r3, driver_r2+4	
	.set	driver, driver_r3+4		/* addr of driver routine */
E 3
I 3
	.set	RELOC,0x50000
D 4
	.set	BOOTSIZE,15		/* size of boot in sectors */
E 4
I 4
	.set	BOOTLAST,15		/* last boot sector */
E 4
	.set	RABPSECT,512		/* bytes per sector */
E 3

D 3
	.set	NOT_FIRST_64K, 		0x1001
	.set	UNSUPPORTED_DEVICE, 	0x1002
	.set	RETURN_FROM_BOOT, 	0x1003
	.set	COULD_NOT_FIND_BOOT, 	0x1004
	.set	FILE_TOO_LARGE, 	0x1005
	.set	FILE_READ_ERROR, 	0x1006

E 3
init:
D 3
	.long	0			/* boot block parameters */
	.long	0			/* (all unused, hence 0) */
	.long	0

/*
 * The registers are set by the console subsystem as follows.
 * Those marked with stars are saved by the driver subroutine.
 * Those marked with a "d" are used by the driver subroutine,
 * and must contain the indicated values before calling the driver.
 * 
 *    r0  = type of boot device (see 750 hardware reference, console)
 * ds r1  = address of the unibus i/o page
 * ds r2  = boot device CSR address
 * ds r3  = boot device unit number
 *  s r4  = 
 * ds r5  = software boot flags (driver: offset to buffer for read)
 *  s r6  = driver subroutine address
 *    r7  = 
 * d  r8  = LBN of block to read from disk
 *    r9  = 
 *  s r10 = 
 *  s r11 = 
 *  s ap  = 
 *    fp  = 
 *  s sp  = 
 * 
 * Memory is mapped as follows:
 * 
 * 0000 to 01ff	Boot block program
 * 0200 to f9ff	Available
 * fa00 to fdff	Drivers and control routines
 * fe00 to ffff	Available
 */
E 3
I 3
	.word	0  			/* entry mask for dec monitor */
	nop;nop;nop;nop;nop;nop;nop;nop /* some no-ops for 750 boot to skip */
	nop;nop;
E 3
start:
I 4
D 8
	movl	r1,r7			/* UNIBUS I/O page address */
	movl	r2,r8			/* boot device CSR */
	movl	r3,r9			/* unit number */
E 8
I 8
	movl	$MAJOR,r10		/* major("/dev/xx0a") */
	extzv	$18,$1,r1,r4		/* get UBA number from R1 */
	xorb2	$0x01,r4		/* complement bit */
	insv	r4,$24,$8,r10		/* set UBA number */
	insv	r3,$16,$8,r10		/* drive number */
D 11
	extzv	$12,$4,r5,r4		/* get partition from r5 */
	bicw2	$0xf000,r5		/* remove from r5 */
E 11
I 11
	extzv	$28,$4,r5,r4		/* get partition from r5 */
	bicl2	$0xf0000000,r5		/* remove from r5 */
E 11
	insv	r4,$8,$8,r10		/* set partition */
E 8
E 4
D 3
	clrl	r7
	movl	r0, r10			/* save the device type */
	moval	init, r11		/* base address of good memory */
	movl	r5, ap			/* save the boot flags */
	tstl	r11			/* see if it is zero */
	beql	1f
	movzwl	$NOT_FIRST_64K, r7
	halt				/* not in first 64k of memory */
1:	moval	STACK(r11), sp		/* put the stack somewhere good */
	/* save the register contents needed by the boot driver */
	movl	r1, driver_r1(r11)
	movl	r2, driver_r2(r11)
	movl	r3, driver_r3(r11)
	movl	r6, driver(r11)
	/* relocate the boot program */
	movc3	$end, (r11), BOOTBASE(r11)
	jmp	BOOTBASE+start2(r11)
E 3
I 3
	movl	r5,r11			/* boot flags */
I 8
D 11
	movl	r1,r9			/* UNIBUS I/O page address */
	movl	r2,r8			/* boot device CSR */
	movl	r3,r7			/* unit number */
E 11
I 10
	brw	start0

/*
 * Leave space for pack label.
 */
pad:
	.space	LABELOFFSET - (pad - init)
packlabel:
	.space	d_end_

start0:
I 11
	movl	r1,r9			/* UNIBUS I/O page address */
	movl	r2,r8			/* boot device CSR */
	movl	r3,r7			/* unit number */
E 11
E 10
E 8
	movl	$RELOC,sp
D 4
	moval	init,r9
	movc3	$end,(r9),(sp)
E 4
I 4
D 8
	moval	init,r10
	movc3	$end,(r10),(sp)
	movl	r7,r1			/* UNIBUS I/O page address */
E 8
I 8
	moval	init,r4
	movc3	$end,(r4),(sp)
	movl	r9,r1			/* UNIBUS I/O page address */
E 8
	movl	r8,r2			/* boot device CSR */
D 8
	movl	r9,r3			/* unit number */
E 8
I 8
	movl	r7,r3			/* unit number */
E 8
E 4
	jmp	*$RELOC+start2
/* now running relocated */
/* bring in the boot program */
E 3
start2:					/* running relocated */
D 3
	calls	$0, BOOTBASE+read_file(r11)
	movl	r11, r9				/* save the base pointer */
	/* boot strap device codes from microcode routines */
	.set	AnyMassBus, 0
	.set	RK07, 1
	.set	RL02, 2
	.set	UDA50, 17
	.set	TU58, 64

	cmpb	r10, $AnyMassBus
	bneq	1f
	movzbl	$0, r10				/* massbus disk */
	brb	2f
E 3
I 3
D 4
	clrl	r9			/* transfer counter */
E 4
I 4
	pushr	$0xffff			/* BEGIN FIREWALL */
	movl	$1,r4			/* first boot sector */
E 4
	clrl	r5			/* transfer address */
D 4
	movl	$1,r8			/* requested sector # */
E 4
I 4
	clrl	-(sp)			/* transfer address */
E 4
E 3
1:
D 3
	cmpb	r10, $RK07
	bneq	1f
	movzbl	$3, r10				/* rk07 disk */
	brb	2f
1:
	cmpb	r10, $UDA50
	bneq	1f
	movzbl	$9, r10				/* uda50 */
	brb	2f
1:
	movzwl	$UNSUPPORTED_DEVICE, r7
	halt					/* unsupported device */
E 3
I 3
D 4
	pushr	$0xffff			/* BEGIN FIREWALL */
	calls	$0,(r6)			/* call ROM-based driver */
E 4
I 4
	movl	r4,r8			/* requested sector # */
	jsb	(r6)			/* call ROM-based driver */
E 4
	blbs	r0,2f
	halt				/* read error */
E 3
2:
D 3
	movl	ap, r11				/* software boot flags */
	addl3	di_size(r9), r9, r2		/* address to start clear */
	moval	BOOTBASE(r9), r1		/* address to stop clearing */
1:
E 3
I 3
D 4
	popr	$0xffff			/* END FIREWALL */
	incl	r8			/* bump sector */
	addl2	$RABPSECT,r5		/* bump memory location */
	aobleq	BOOTSIZE,r9,1b
E 4
I 4
	addl2	$RABPSECT,r5		/* bump address */
	movl	r5,(sp)
	aobleq	$BOOTLAST,r4,1b
E 4
E 3

D 3
	cmpl	r2, r1
	bgeq	2f
	clrb	(r2)+
	brb	1b
2:
	calls	$0, (r9)
	movzwl	$RETURN_FROM_BOOT, r7
	halt					/* end of program */
read_block:
	.word	0xffc			/* r11-r2 */
	clrq	-(sp)			/* make room for the buf addr */
	movl	driver_r1(r11), r1
	movl	driver_r2(r11), r2
	movl	driver_r3(r11), r3
	mull3	$2, 4(ap), r4		/* mult by 2 to get lbn */
	movl	r4, r8
	movl	8(ap), r5
	addl3	r5, r11, (sp)		/* for massbus babies */
	jsb	*driver(r11)		/* read the first block */
	blbs	r0, 1f
	movzwl	$FILE_READ_ERROR, r7
	halt				/* error reading file */
1:
	addl3	$1, r4, r8
	addl2	$512, r5
	addl3	r5, r11, (sp)		/* for massbus babies */
	jsb	*driver(r11)		/* read the second block */
	blbs	r0, 1f
	movzwl	$FILE_READ_ERROR, r7
	halt				/* error reading file */
1:
	ret
E 3
I 3
D 4
	.set	PROGSIZE,(BOOTSIZE*RABPSECT)
E 4
I 4
D 8
	.set	PROGSIZE,((BOOTLAST-1)*RABPSECT)
E 8
I 8
	.set	PROGSIZE,(BOOTLAST*RABPSECT)
E 8
E 4
done:
I 4
	tstl	(sp)+			/* pop address */
	popr	$0xffff			/* END FIREWALL */
E 4
D 8
	movl	$PROGSIZE,r3
E 8
I 8
	movl	$PROGSIZE,r4
E 8
clrcor:
D 8
	clrq	(r3)
	acbl	$RELOC,$8,r3,clrcor
E 8
I 8
	clrq	(r4)
	acbl	$RELOC,$8,r4,clrcor
E 8
/* start loaded program */
D 8
	movl	$9,r10			/* major("/dev/ra0a") */
E 8
	calls	$0,*$0
	brw	start2
E 3
end:
E 1
