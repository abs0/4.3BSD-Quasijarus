h37402
s 00002/00002/00116
d D 7.4 04/02/28 23:38:21 msokolov 9 8
c move to using R5<31:28> instead of <15:12> for partition
e
s 00002/00005/00116
d D 7.3 87/02/21 11:30:42 karels 8 7
c squish
e
s 00013/00001/00108
d D 7.2 86/08/28 20:59:30 karels 7 6
c changes for pack labels; use cpp, now are *.c
e
s 00001/00001/00108
d D 7.1 86/06/05 01:54:13 mckusick 6 5
c 4.3BSD release version
e
s 00045/00054/00064
d D 6.4 86/03/14 16:28:13 karels 5 4
c use unit and uba from registers
e
s 00001/00003/00117
d D 6.3 85/06/26 14:03:07 bloom 4 3
c sccsids aren't executable kirk
e
s 00009/00001/00111
d D 6.2 85/06/08 12:21:57 mckusick 3 2
c Add copyright
e
s 00000/00000/00112
d D 6.1 83/07/29 07:43:38 sam 2 1
c 4.2 distribution
e
s 00112/00000/00000
d D 4.1 83/02/16 22:06:46 sam 1 0
c date and time created 83/02/16 22:06:46 by sam
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
D 6
 * Copyright (c) 1980 Regents of the University of California.
E 6
I 6
 * Copyright (c) 1980, 1986 Regents of the University of California.
E 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 4
#ifndef lint
_sccsid:.asciz	"%W% (Berkeley) %G%"
#endif not lint
E 4
I 4
/* "%W% (Berkeley) %G%" */
I 7
#include <sys/disklabel.h>
E 7
E 4
E 3

I 5
	.set	MAJOR,2			/* major("/dev/up0a") */

E 5
/*
 * UP 1st level boot program: loads next 7.5Kbytes from
 * boot sector of file system and sets it up to run.
 * Always reads from drive 0.
 */
	.set	BOOTSIZE,15 		/* size of boot in sectors */
	.set	RELOC,0x50000
	.set	UPBPSECT,512		/* bytes per sector */
D 5
	.set	SID,62			/* system ID register */
E 5
/* UBA registers */
	.set	UBA_CNFGR,0		/* UBA configuration register */
	.set	UBA_CR,4		/* UBA control register offset */
	.set	UBA_MAP,0x800		/* UBA offset to map reg's */
D 5
	.set	UBAinit,1		/* UBA init bit in UBA control reg */
	.set	pUBIC,16		/* Unibus init complete */
E 5
/* UP registers and bits */
D 5
	.set	UP,0176700-0160000	/* address of UP controller */
	.set	UP_cs1,UP+0		/* control and status */
	.set	UP_wc,UP+2		/* word count */
	.set	UP_ba,UP+4		/* bus address */
	.set	UP_da,UP+6		/* disk address */
	.set	UP_cs2,UP+010		/* cs2 register */
	.set	UP_of,UP+032		/* offset register */
	.set	UP_dc,UP+034		/* desired cylinder */
	.set	UP_hr,UP+036		/* holding register */
E 5
I 5
	.set	UP_cs1,0		/* control and status */
	.set	UP_wc,2			/* word count */
	.set	UP_ba,4			/* bus address */
	.set	UP_da,6			/* disk address */
	.set	UP_cs2,010		/* cs2 register */
	.set	UP_of,032		/* offset register */
	.set	UP_dc,034		/* desired cylinder */
	.set	UP_hr,036		/* holding register */
E 5
	.set	UP_GO,1			/* go bit */
	.set	UP_PACK,022		/* pack acknowledge */
	.set	UP_DCLR,010		/* drive clear */
	.set	UP_PRESET,020		/* read-in-preset */
	.set	UP_RCOM,070		/* read command */
	.set	UPCS2_CLR,040
	.set	UP_pRDY,7		/* position of ready bit */
	.set	UP_pERR,15		/* position of error bit */
	.set	UP_FMT22,010000

init:
I 5
/* r9   UBA address */
/* r8	UP addr */
E 5
	.word	0  			/* entry mask for dec monitor */
	nop;nop;nop;nop;nop;nop;nop;nop /* some no-ops for 750 boot to skip */
	nop;nop;
D 5
/* get cpu type and find the first uba */
	mfpr	$SID,r0
	extzv	$24,$8,r0,r0		/* get cpu type */
	ashl	$2,r0,r1
	movab	physUBA,r2		/* get physUBA[cpu] */
	addl2	r1,r2
	movl	(r2),r9
	movab	physUMEM,r2		/* get physUMEM[cpu] */
	addl2	r1,r2
	movl	(r2),r10
/* if 780, init uba */
	cmpl	r0,$1
	bneq	2f
	movl	$UBAinit,UBA_CR(r9)
E 5
I 5
	movl	$MAJOR,r10		/* major("/dev/xx0a") */
	extzv	$18,$1,r1,r9		/* get UBA number from R1 */
	xorb2	$0x01,r9		/* complement bit */
	insv	r9,$24,$8,r10		/* set UBA number */
	insv	r3,$16,$8,r10		/* drive number */
D 9
	extzv	$12,$4,r5,r4		/* get partition from r5 */
	bicw2	$0xf000,r5		/* remove from r5 */
E 9
I 9
	extzv	$28,$4,r5,r4		/* get partition from r5 */
	bicl2	$0xf0000000,r5		/* remove from r5 */
E 9
	insv	r4,$8,$8,r10		/* set partition */
	movl	r5,r11			/* boot flags */
I 7

I 8
	movl	r2,r8			/* boot device CSR */
E 8
	brw	start0

/*
 * Leave space for pack label.
 */
pad:
	.space	LABELOFFSET - (pad - init)
packlabel:
	.space	d_end_

start0:
E 7
	movl	physUBA[r9],r9		/* UNIBUS adaptor address */
D 8
	movl	r2,r8			/* boot device CSR */
E 8
	movl	r3,r7			/* unit number */
D 7

E 7
	movl	$RELOC,sp
	moval	init,r4
	movc3	$end,(r4),(sp)
D 8
	movl	r9,r1			/* UNIBUS I/O page address */
	movl	r8,r2			/* boot device CSR */
	movl	r7,r3			/* unit number */
E 8
/* init up, set vv in drive; if any errors, give up */
I 8
/* probably unneeded: rom should have already done this */
E 8
	bisw3	r7,$UPCS2_CLR,UP_cs2(r8)
	movw	$UP_DCLR+UP_GO,UP_cs1(r8)
	movw	$UP_PRESET+UP_GO,UP_cs1(r8)
	movw	$UP_FMT22,UP_of(r8)
E 5
1:
D 5
	bbc	$pUBIC,UBA_CNFGR(r9),1b
2:
	movl	$5000000,r0
1:
	sobgtr	r0,1b
/* init up, set vv in drive 0; if any errors, give up */
	movw	$UPCS2_CLR,UP_cs2(r10)
	movw	$UP_DCLR+UP_GO,UP_cs1(r10)
	movw	$UP_PRESET+UP_GO,UP_cs1(r10)
	movw	$UP_FMT22,UP_of(r10)
1:
	movw	UP_cs1(r10),r0
E 5
I 5
	movw	UP_cs1(r8),r0
E 5
	bbc	$UP_pRDY,r0,1b
/* relocate to high core */
start:
D 8
	movl	r5,r11			/* boot flags */
E 8
	movl	$RELOC,sp
	moval	init,r6
	movc3	$end,(r6),(sp)
	jmp	*$RELOC+start2
/* now running relocated */
	.set	PROGSIZE,(BOOTSIZE*UPBPSECT)
start2:
D 5
	movw	$0,UP_dc(r10)
	movw	$1,UP_da(r10)
	movw	$-PROGSIZE/2,UP_wc(r10)
E 5
I 5
	movw	$0,UP_dc(r8)
	movw	$1,UP_da(r8)
	movw	$-PROGSIZE/2,UP_wc(r8)
E 5
	clrl	r0
1:
	bisl3	$0x80000000,r0,UBA_MAP(r9)
	addl2	$4,r9
	aobleq	$BOOTSIZE,r0,1b
D 5
	clrw	UP_ba(r10)
	movw	$UP_RCOM+UP_GO,UP_cs1(r10)
E 5
I 5
	clrw	UP_ba(r8)
	movw	$UP_RCOM+UP_GO,UP_cs1(r8)
E 5
uprdy:
D 5
	movw	UP_cs1(r10),r0
E 5
I 5
	movw	UP_cs1(r8),r0
E 5
	bbc	$UP_pRDY,r0,uprdy
clear:
	movl	$PROGSIZE,r3
clrcor:
	clrq	(r3)
	acbl	$RELOC,$8,r3,clrcor
/* run loaded program */
D 5
	movl	$2,r10			/* major("/dev/up0a") */
E 5
	calls	$0,*$0
	brw	start2
physUBA:
D 5
	.long	0
	.long	0x20006000	/* 11/780 */
	.long	0xf30000	/* 11/750 */
	.long	0xf26000	/* 11/730 */
physUMEM:
	.long	0
	.long	0x2013e000	/* 11/780 */
	.long	0xffe000	/* 11/750 */
	.long	0xffe000	/* 11/730 */
E 5
I 5
	.long	0xf30000		/* uba0 */
	.long	0xf32000		/* uba1 */
E 5
end:
E 1
