h14562
s 00002/00002/00118
d D 7.3 04/02/28 23:38:15 msokolov 8 7
c move to using R5<31:28> instead of <15:12> for partition
e
s 00015/00003/00105
d D 7.2 86/08/28 20:59:05 karels 7 6
c changes for pack labels; use cpp, now are *.c
e
s 00001/00001/00107
d D 7.1 86/06/05 01:51:41 mckusick 6 5
c 4.3BSD release version
e
s 00039/00052/00069
d D 6.4 86/03/14 16:28:01 karels 5 4
c use unit and uba from registers
e
s 00001/00004/00120
d D 6.3 85/06/26 14:02:15 bloom 4 3
c sccsids aren't executable kirk
e
s 00010/00001/00114
d D 6.2 85/06/08 12:18:53 mckusick 3 2
c Add copyright
e
s 00000/00000/00115
d D 6.1 83/07/29 07:43:03 sam 2 1
c 4.2 distribution
e
s 00115/00000/00000
d D 4.1 83/02/16 22:06:25 sam 1 0
c date and time created 83/02/16 22:06:25 by sam
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
/* %W% (Berkeley) %G% */
I 7
#include <sys/disklabel.h>
E 7
E 4
E 3

I 5
	.set	MAJOR,3		/* major("/dev/hk0a") */

E 5
/*
 * RK07 1st level boot program: loads next 7.5Kbytes from
 * boot sector of file system and sets it up to run.
D 5
 * Always reads from drive 0.
E 5
 */
	.set	RELOC,0x50000
	.set	BOOTSIZE,15		/* size of boot in sectors */
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
/* RK611 registers and bits */
D 5
	.set	HK,0177440-0160000	/* address of RK611 */
	.set	HK_cs1,HK+0		/* control and status */
	.set	HK_wc,HK+2		/* word count */
	.set	HK_ba,HK+4		/* bus address */
	.set	HK_da,HK+6		/* disk address */
	.set	HK_dc,HK+020		/* desired cylinder */
E 5
I 5
	.set	HK_cs1,0		/* control and status */
	.set	HK_wc,2			/* word count */
	.set	HK_ba,4			/* bus address */
	.set	HK_da,6			/* disk address */
	.set	HK_cs2,8		/* control and status */
	.set	HK_dc,020		/* desired cylinder */
E 5
	.set	HKBPSECT,512		/* bytes per sector */
	.set	HK_GO,1			/* go bit */
	.set	HK_PACK,2		/* pack acknowledge */
	.set	HK_RCOM,020		/* read command */
	.set	HK_SEL7,02000		/* select RK07 disk */
	.set	HK_pRDY,7		/* position of ready bit */
	.set	HK_pERR,15		/* position of error bit */

init:
/* r9	UBA address */
D 5
/* r10	umem addr */
E 5
I 5
/* r8	HK addr */
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
D 8
	extzv	$12,$4,r5,r4		/* get partition from r5 */
	bicw2	$0xf000,r5		/* remove from r5 */
E 8
I 8
	extzv	$28,$4,r5,r4		/* get partition from r5 */
	bicl2	$0xf0000000,r5		/* remove from r5 */
E 8
	insv	r4,$8,$8,r10		/* set partition */
	movl	r5,r11			/* boot flags */
I 7
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
	movl	r2,r8			/* boot device CSR */
	movl	r3,r7			/* unit number */

/* select unit, init rk611, set vv in drive; if any errors, give up */
	movw	r7,HK_cs2(r8)
	movw	$HK_SEL7+HK_GO,HK_cs1(r8)
E 5
1:
D 5
	bbc	$pUBIC,UBA_CNFGR(r9),1b
2:
/* init rk611, set vv in drive 0; if any errors, give up */
	movw	$HK_SEL7+HK_GO,HK_cs1(r10)
1:
	movw	HK_cs1(r10),r0
E 5
I 5
	movw	HK_cs1(r8),r0
E 5
	bbc	$HK_pRDY,r0,1b
	bbs	$HK_pERR,r0,9f
D 5
	movw	$HK_SEL7+HK_PACK+HK_GO,HK_cs1(r10)
E 5
I 5
	movw	$HK_SEL7+HK_PACK+HK_GO,HK_cs1(r8)
E 5
1:
D 5
	movw	HK_cs1(r10),r0
E 5
I 5
	movw	HK_cs1(r8),r0
E 5
	bbc	$HK_pRDY,r0,1b
	bbc	$HK_pERR,r0,start
9:
	halt
/* relocate to high core */
start:
	movl	r5,r11			/* boot flags */
	movl	$RELOC,sp
	moval	init,r6
	movc3	$end,(r6),(sp)
	jmp	*$RELOC+start2
/* now running relocated */
/* bring in the boot program */
	.set	PROGSIZE,(BOOTSIZE*HKBPSECT)
start2:
D 5
	movw	$0,HK_dc(r10)
	movw	$1,HK_da(r10)
	movw	$-PROGSIZE/2,HK_wc(r10)
E 5
I 5
	movw	$0,HK_dc(r8)
	movw	$1,HK_da(r8)
	movw	$-PROGSIZE/2,HK_wc(r8)
E 5
	clrl	r0
1:
D 5
	bisl3	$0x80000000,r0,UBA_MAP(r9)
	addl2	$4,r9
	aobleq	$BOOTSIZE,r0,1b
	clrw	HK_ba(r10)
	movw	$HK_SEL7+HK_RCOM+HK_GO,HK_cs1(r10)
E 5
I 5
D 7
#	bisl3	$0x80000000,r0,UBA_MAP(r9)
#	addl2	$4,r9
#	aobleq	$BOOTSIZE,r0,1b
E 7
I 7
/*	bisl3	$0x80000000,r0,UBA_MAP(r9) */
/*	addl2	$4,r9 */
/*	aobleq	$BOOTSIZE,r0,1b */
E 7
	clrw	HK_ba(r8)
	movw	$HK_SEL7+HK_RCOM+HK_GO,HK_cs1(r8)
E 5
hkrdy:
D 5
	movw	HK_cs1(r10),r0
E 5
I 5
	movw	HK_cs1(r8),r0
E 5
	bbc	$HK_pRDY,r0,hkrdy
	bbs	$HK_pERR,r0,hkerr
	brw	done
hkerr:
	halt			/* ungraceful */
done:
	movl	$PROGSIZE,r3
clrcor:
	clrq	(r3)
	acbl	$RELOC,$8,r3,clrcor
/* start loaded program */
D 5
	movl	$3,r10			/* major("/dev/hk0a") */
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
