h36134
s 00002/00002/00130
d D 7.3 04/02/28 23:38:16 msokolov 9 8
c move to using R5<31:28> instead of <15:12> for partition
e
s 00012/00004/00120
d D 7.2 86/08/28 20:59:09 karels 8 7
c changes for pack labels; use cpp, now are *.c
e
s 00000/00000/00124
d D 7.1 86/06/05 01:51:53 mckusick 7 6
c 4.3BSD release version
e
s 00046/00032/00078
d D 6.4 86/03/13 20:45:38 karels 6 5
c use boot device from console boot command
e
s 00001/00003/00109
d D 6.3 85/06/26 14:02:21 bloom 5 4
c sccsids aren't executable kirk
e
s 00010/00001/00102
d D 6.2 85/06/08 12:19:04 mckusick 4 3
c Add copyright
e
s 00000/00000/00103
d D 6.1 83/07/29 07:43:06 sam 3 2
c 4.2 distribution
e
s 00003/00000/00100
d D 4.2 83/02/27 19:18:10 sam 2 1
c fix from Heidi for Eagles
e
s 00100/00000/00000
d D 4.1 83/02/16 22:06:26 sam 1 0
c date and time created 83/02/16 22:06:26 by sam
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
D 6
 * Copyright (c) 1980 Regents of the University of California.
E 6
I 6
 * Copyright (c) 1980,1986 Regents of the University of California.
E 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 5
#ifndef lint
_sccsid:.asciz	"%W% (Berkeley) %G%"
#endif not lint
E 5
I 5
/* "%W% (Berkeley) %G%" */
I 8
#include <sys/disklabel.h>
E 8
E 5

E 4

I 6
D 8
#define PARTITION		/* Partition is in bits 12 to 15 of R5

E 8
E 6
/*
 * RP??/RM?? 1st level boot program: loads next 7.5Kbytes from
D 6
 * boot sector of file system and sets it up to run.
 * Always reads from drive 0.
E 6
I 6
 * boot sectors of file system and sets it up to run.
 * Reads from the controller and drive passed in from the boot
 * rom.
 *   R1:  address of the boot device's adapter
 *   R2:  controller number of the boot device
 *   R3:  unit number of the boot device
 *   R5:  software boot control flags
 *   R6:  address of driver subroutine from ROM
 *   SP:  base address of usable memory + 0x200
E 6
 */
	.set	BOOTSIZE,15		/* size of boot in sectors */
	.set	RELOC,0x70000
/* MBA registers */
	.set	M_cr,4			/* MBA control reg */
I 6
	.set	M_sr,8			/* MBA status reg */
E 6
	.set	M_var,12		/* MBA virt addr reg */
	.set	M_bc,16			/* MBA byte count reg */
	.set	M_map,0x800		/* start of MBA map reg's */
	.set	MBAinit,1		/* MBA init bit in MBA control reg */
I 6
	.set	MBABUSY,0x80000000	/* MBA SR: data transfer busy */
	.set	pMBABUSY,31		/* bit position of  MBABUSY */
E 6
/* Drive information */
	.set	RP,0x400		/* start of drive registers */
D 6
	.set	RP_cr,RP+0		/* control status register */
	.set	RP_sr,RP+4		/* drive status reg */
	.set	RP_stk,RP+0x14		/* desired track/sector reg */
	.set	RP_dt,RP+0x18		/* drive type reg */
	.set	RP_off,RP+0x24		/* RP offset reg */
	.set	RP_cyl,RP+0x28		/* desired cyl reg */
E 6
I 6
	.set	RPDR,0x80		/* offset per drive unit */
	.set	RP_cr,0			/* control status register */
	.set	RP_sr,4			/* drive status reg */
	.set	RP_stk,0x14		/* desired track/sector reg */
	.set	RP_dt,0x18		/* drive type reg */
	.set	RP_off,0x24		/* RP offset reg */
	.set	RP_cyl,0x28		/* desired cyl reg */
E 6
	.set	RPBPSECT,512		/* bytes per sector */
/* RP?? function codes, status bits  */
	.set	RP_GO,1			/* go */
	.set	RP_RED,070		/* read */
	.set	RP_DC,010		/* drive clear */
	.set	RP_RIP,020		/* read in preset */
	.set	RP_FMT,0x1000		/* format 22 */
	.set	RP_MOL,0x1000		/* medium on line */
	.set	RP_DRY,0200		/* drive ready */
	.set	RP_ERR,040000		/* composite error */
	.set	RP_pDRY,7		/* bit position of RP_DRY */
	.set	RP_pERR,14		/* bit position of RP_ERR */

init:
	.word	0			/* entry mask for DEC monitor */
	nop;nop;nop;nop;nop;nop;nop;nop	/* some no-ops for 750 boot to skip */
	nop;nop;
start:
I 6
	clrl	r10			/* major("/dev/hp0a") */
	extzv	$13,$2,r1,r4		/* get MBA number from R1 */
	insv	r4,$24,$8,r10		/* set MBA number */
	insv	r3,$16,$8,r10		/* drive number */
D 8
#ifdef PARTITION
E 8
D 9
	extzv	$12,$4,r5,r4		/* get partition from r5 */
	bicw2	$0xf000,r5		/* remove from r5 */
E 9
I 9
	extzv	$28,$4,r5,r4		/* get partition from r5 */
	bicl2	$0xf0000000,r5		/* remove from r5 */
E 9
	insv	r4,$8,$4,r10		/* set partition */
D 8
#endif
E 8
E 6
	movl	r5,r11
I 6
	movl	r1,r9			/* save adaptor address */
	movl	r3,r8			/* and unit number */
I 8
	brw	start0

/*
 * Leave space for pack label.
 */
pad:
	.space	LABELOFFSET - (pad - init)
packlabel:
	.space	d_end_

start0:
E 8
E 6
	movl	$RELOC,sp
	moval	init,r6
	movc3	$end,(r6),(sp)
	jmp	*$RELOC+start1
/* running relocated */
start1:
D 6
/* get cpu type */
	.set	SID,0x3e
	mfpr	$SID,r0
	extzv	$24,$8,r0,r0
	ashl	$2,r0,r1
/* get mba location and init it */
	moval	physMBA,r2
	addl3	r1,r2,r3
	movl	(r3),r9
E 6
	movl	$MBAinit,M_cr(r9)
/* read-in-preset the drive and set format */
D 6
	movl	$RP_RIP+RP_GO,RP_cr(r9)
	movl	$RP_FMT,RP_off(r9) 
E 6
I 6
	mull2	$RPDR,r8
	movab	RP(r9)[r8],r8
	movl	$RP_RIP+RP_GO,RP_cr(r8)
	movl	$RP_FMT,RP_off(r8) 
E 6

	.set	PROGSIZE,(BOOTSIZE*RPBPSECT)
start2:
D 6
	movl	$0,RP_cyl(r9)
	movl	$1,RP_stk(r9)
E 6
I 6
	movl	$0,RP_cyl(r8)
	movl	$1,RP_stk(r8)
E 6
	movl	$-PROGSIZE,M_bc(r9)
/* set up MASSBUS map for DMA */
	clrl	r0
1:
	bisl3	$0x80000000,r0,M_map(r9)[r0]
	aobleq	$BOOTSIZE,r0,1b
	clrl	M_var(r9)
D 6
	movl	$RP_RED+RP_GO,RP_cr(r9)
E 6
I 6
	movl	$RP_RED+RP_GO,RP_cr(r8)
E 6
rprdy:
D 6
	movl	RP_sr(r9),r0
E 6
I 6
	movl	RP_sr(r8),r0
E 6
	bbc	$RP_pDRY,r0,rprdy
	bbs	$RP_pERR,r0,rperr
I 6
rprdy2:
	bbs	$pMBABUSY,M_sr(r9),rprdy2

/* Eagles are too fast for the controller. Slow the thing down. */
/* (May not be needed with wait for mba above.) */
E 6
I 2
	clrl	r3
D 6
/* Eagle's are too fast for the controller. Slow the thing down. */
E 6
buzz:	acbl	$2000,$1,r3,buzz
E 2
	bicpsw	$2
	jbr	clear
rperr:
	halt
/* clear core and execute program */
clear:
	movl	$PROGSIZE,r3
clrcor:
	clrq	(r3)
	acbl	$RELOC,$8,r3,clrcor
/* run loaded program */
D 6
	clrl	r10			/* major("/dev/hp0a") */
E 6
	calls	$0,*$0
	brw	start2
D 6

	.align	2
physMBA:
	.long	0
	.long	0x20010000
	.long	0xf28000
E 6

end:
E 1
