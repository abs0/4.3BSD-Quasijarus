h27575
s 00001/00001/00211
d D 7.8.1.1 04/02/14 19:02:09 msokolov 31 29
c fix 4.3-QJ0b blunder for 4.3-QJ0c
e
s 00024/00116/00096
d D 7.9 04/02/07 11:35:21 msokolov 30 29
c started standalone system revamping
e
s 00005/00002/00207
d D 7.8 03/11/15 17:15:45 msokolov 29 28
c we don't have to force unit 0 on MicroVAXen, we can take the unit from VMB
e
s 00001/00001/00208
d D 7.7 03/05/11 11:03:22 msokolov 28 27
c keep normal standalone programs with their stacks below 0x70000 like in 4.3
c even as RELOC is moved up for boot*
e
s 00001/00001/00208
d D 7.6 88/11/08 17:32:50 tef 27 26
c MCESR register doesn't exist on ka650
e
s 00012/00007/00197
d D 7.5 88/08/27 07:22:39 tef 26 25
c Add support for microvax 3000.
e
s 00082/00007/00122
d D 7.4 88/01/28 20:53:19 karels 25 24
c uvax changes; fix devsw index in confxx; header updates
e
s 00010/00002/00119
d D 7.3 87/04/02 16:38:03 karels 24 23
c save boothowto, bootdev
e
s 00006/00003/00115
d D 7.2 87/02/21 11:41:44 karels 23 22
c pack labels; various cleanups: open returns failure instead of stopping
e
s 00001/00001/00117
d D 7.1 86/06/05 01:45:11 mckusick 22 21
c 4.3BSD release version
e
s 00005/00000/00113
d D 6.4 85/11/08 19:16:01 karels 21 20
c so much cleaning: make skip-sector work in formatter, clean up
c ioctls for formatting options, make boothp small enough to fit,
c configure 9766's properly (sorry, 9300's!), don't use _exit from libc
e
s 00004/00000/00109
d D 6.3 85/08/02 19:04:12 bloom 20 19
c add 8600 support
e
s 00007/00001/00102
d D 6.2 85/06/08 13:12:08 mckusick 19 18
c Add copyright
e
s 00000/00000/00103
d D 6.1 83/07/29 07:47:41 sam 18 17
c 4.2 distribution
e
s 00014/00002/00089
d D 4.11 83/05/11 10:00:41 sam 17 15
c overflowed movc3's capability; plus kludge for ra81 (from rws@mit-xx)
e
s 00011/00002/00089
d R 4.11 83/05/06 10:14:08 sam 16 15
c programs too big to use movc3 to relocate
e
s 00002/00002/00089
d D 4.10 82/11/13 23:15:22 sam 15 14
c move includes for 4.1c directory layout
e
s 00001/00001/00090
d D 4.9 82/07/15 21:31:59 root 14 13
c new boot scheme
e
s 00001/00001/00090
d D 4.8 81/04/03 00:10:40 root 13 12
c s/730/7ZZ
e
s 00060/00003/00031
d D 4.7 81/03/22 20:52:13 wnj 12 11
c fixes
e
s 00001/00002/00033
d D 4.6 81/03/21 17:28:52 wnj 11 10
c dont init SCBB
e
s 00006/00016/00029
d D 4.5 81/03/15 20:46:47 wnj 10 9
c 
e
s 00008/00002/00037
d D 4.4 81/02/15 13:07:08 wnj 9 8
c leave space for scb
e
s 00009/00003/00030
d D 4.3 80/12/17 12:17:22 wnj 8 7
c fix for both 750 and 780
e
s 00001/00001/00032
d D 4.2 80/11/10 01:47:05 bill 7 6
c typo
e
s 00000/00000/00033
d D 4.1 80/11/09 16:29:39 bill 6 5
c stamp for 4bsd
e
s 00007/00005/00026
d D 1.5 80/11/09 16:26:41 bill 5 4
c fixup to wait for UBIC other minor longterm botches (mba access, core clearing)
e
s 00001/00000/00030
d D 1.4 80/07/29 15:09:28 bill 4 3
c work w/o mba's
e
s 00000/00004/00030
d D 1.3 80/07/28 10:05:17 bill 3 2
c mbaact, etc
e
s 00004/00002/00030
d D 1.2 80/07/28 09:40:53 bill 2 1
c fix core clearing
e
s 00032/00000/00000
d D 1.1 80/06/28 10:43:11 bill 1 0
c date and time created 80/06/28 10:43:11 by bill
e
u
U
t
T
I 1
D 8
#	%M%	%I%	%G%
E 8
I 8
D 11
/*	%M%	%I%	%G%	*/
E 11
I 11
D 19
/*	%M%	%I%	%E%	*/
E 19
I 19
/*
D 22
 * Copyright (c) 1982 Regents of the University of California.
E 22
I 22
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 22
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 19
E 11
E 8

I 10
D 15
#include "../h/mtpr.h"
E 15
I 15
#include "../vax/mtpr.h"
E 15
I 12
#define	LOCORE
D 15
#include "../h/cpu.h"
E 15
I 15
#include "../vax/cpu.h"
E 15
E 12

E 10
D 8
# Startup code for standalone system
# Non-relocating version -- for programs which are loaded by boot
E 8
I 8
/*
 * Startup code for standalone system
 * Non-relocating version -- for programs which are loaded by boot
I 21
 * Relocating version for boot*
E 21
 */
E 8

I 12
	.globl	_end
E 12
D 5
	.globl	_end
E 5
I 5
	.globl	_edata
E 5
	.globl	_main
	.globl	__rtt
I 10
	.globl	_configure
D 12
	.set	reloc,RELOC
E 12
I 12
D 30
	.globl	_cpu
E 30
	.globl	_openfirst
I 24
	.globl	_boothowto
	.globl	_bootdev
E 24
E 12
E 10
D 5
	.globl	_edata
E 5

I 30
	.comm	_cpu,4
	.comm	_cpusid,4
	.comm	_cpusie,4
	.comm	_vmb_info,4

E 30
I 8
D 10
#if VAX==780
E 8
	.set	PHYSUBA,0x20006000	# uba 0
I 8
#endif
E 8
D 3
	.set	PHYSMBA0,0x20010000	# mba 0
	.set	PHYSMBA1,0x20012000	# mba 1
E 3
D 5
	.set	PHYSUMEM,0x2013e000	# unibus memory
E 5

E 10
	.set	HIGH,31		# mask for total disable

I 9
entry:	.globl	entry
E 9
D 25
	.word	0x0
E 25
I 25
	nop; nop			# .word	0x0101
E 25
	mtpr	$HIGH,$IPL		# just in case
I 25

E 25
I 5
D 9
	movl	$RELOC-0x2000,sp
E 9
I 9
D 11
	mtpr	$_Scbbase,$SCBB
E 11
D 10
	movl	$RELOC-0x2400,sp
	mtpr	$RELOC-0x2000,$ISP	/* space for interrupts
					/* (in case we are not using that
					/* stack already)
					*/
E 9
I 8
#if VAX==780
E 8
E 5
D 3
	movl	$1,PHYSMBA0+4		# init
	movl	$1,PHYSMBA1+4		# init
E 3
	movl	$1,PHYSUBA+4		# init
I 4
D 5
	movab	_end,r0
E 5
I 5
ubic:
	movl	*$PHYSUBA,r0		# while ((up->uba_cnfgr & UBIC) == 0)
	bitl	$0x10000,r0		# 	continue;
D 7
	jeql	wait
E 7
I 7
	jeql	ubic
I 8
#endif
E 10
I 10
D 12
	movl	$reloc-0x2400,sp
E 12
I 12
#ifdef REL
I 25
D 26
	# we need to do special stuff on microvax II
E 26
I 26
D 30
	# we need to do special stuff on microvaxen
E 26
	mfpr	$SID,r0
	cmpzv	$24,$8,r0,$VAX_630
D 26
	bneq	1f
E 26
I 26
	beql	1f
	cmpzv	$24,$8,r0,$VAX_650
	bneq	2f
E 26

	/*
	 * Were we booted by VMB?  If so, r11 is not boothowto,
	 * but rather the address of the `Extended RPB' (see KA630
	 * User's Manual, pp 3-21).  These tests were devised by
	 * richl@tektronix, 11/10/87.
	 */
I 26
1:
E 26
	cmpl	(r11),r11		# if boothowto, r11 will be small
D 26
	bneq	1f			# and these will not fault
E 26
I 26
	bneq	2f			# and these will not fault
E 26
	cmpl	4(r11),$0
D 26
	bneq	1f
E 26
I 26
	bneq	2f
E 26
	cmpl	8(r11),$-1
D 26
	bneq	1f
E 26
I 26
	bneq	2f
E 26
	tstl	0xc(r11)
D 26
	bneq	1f
E 26
I 26
	bneq	2f
E 26

	/*
	 * Booted by VMB: get flags from extended rpb.
D 29
	 * We can only guess at the boot device (here ra(0,0)).
E 29
I 29
	 * The only boot device on MicroVAXen is ra (major 9).
	 * VMB gives us the unit number, but controller has to be 0,
	 * since stand uda driver doesn't support CSRs other than 0172150.
E 29
	 */
I 29
	movl	$9,r10			# device = ra(n,0)
	insv	0x64(r11),$16,$4,r10
E 29
	movl	0x30(r11),r11
D 29
	movl	$9,r10			# device = ra(0,0)
E 29
D 26
1:
E 26
I 26
2:
E 30
E 26
E 25
	movl	$RELOC,sp
#else
D 28
	movl	$RELOC-0x2400,sp
E 28
I 28
D 30
D 31
	movl	0x6DC00,sp		# keep it below 0x70000 like in 4.3
E 31
I 31
	movl	$0x6DC00,sp		# keep it below 0x70000 like in 4.3
E 31
E 30
I 30
	movl	$0x6DC00,sp		# keep it below 0x70000 like in 4.3
E 30
E 28
#endif
E 12
E 10
I 9
start:
I 25
#ifndef REL
	/*
	 * Clear bss segment
	 */
E 25
E 9
E 8
E 7
D 12
	movab	_edata,r0
E 12
I 12
	movl	aedata,r0
E 12
E 5
E 4
D 2
	subl3	$_edata,$RELOC-0x2000,r0
	movc5	$0,(sp),$0,r0,_edata
E 2
I 2
clr:
	clrl	(r0)+
	cmpl	r0,sp
	jlss	clr
I 12
D 25
#ifdef REL
D 17
	movc3	aend,*$0,(sp)
E 17
I 17
	movc3	aedata,*$0,(sp)
/*
 * Reclear bss segment separately from text and data
 * since movc3 can't move more than 64K bytes
 */
E 25
I 25
#else
	/*
	 * `entry' below generates a pc-relative reference to the
	 * code, so this works no matter where we are now.
	 * Clear bss segment *after* moving text and data.
	 */
	movc3	aedata,entry,(sp)
E 25
dclr:
	clrl	(r3)+
	cmpl	r3,$_end
	jlss	dclr
/* this loop shouldn't be necessary, but is when booting from an ra81 */
xclr:	
	clrl	(r3)+
	cmpl	r3,$0x100000
	jlss	xclr
E 17
	jmp	*abegin
begin:
I 30
	addl3	$_end,$0x1FF,r0
	bicl2	$0x1FF,r0
	pushl	r0
	calls	$1,_setupscb
E 30
#endif
I 24
	movl	r11,_boothowto
	movl	r10,_bootdev
I 30
	tstl	ap
	jeql	1f
	tstb	(ap)
	jeql	1f
	movl	4(ap),_vmb_info
1:
#ifndef OLD750BOOT
	calls	$0,_cpuid
#else
	/* For old 750/8200 bootxx's don't need cpuid, save ~200 bytes */
	mfpr	$SID,r1
	movl	r1,_cpusid
	extzv	$24,$8,r1,_cpu
#endif
E 30
again:
E 24
D 30
	mtpr	$0,$SCBB
E 30
E 12
I 10
	calls	$0,_configure
I 12
	movl	$1,_openfirst
E 12
E 10
E 2
D 9
start:
E 9
D 5
	movl	$RELOC-0x2000,sp
E 5
	calls	$0,_main
I 12
D 24
#ifndef TP
E 12
	jmp	start
E 24
I 24
#ifdef REL
	jmp	again
E 24
I 12
#else
	ret
#endif
E 12

I 12
	.data
#ifdef REL
abegin:	.long	begin
D 17
aend:	.long	_end-RELOC
E 17
aedata:	.long	_edata-RELOC
#else
aedata:	.long	_edata
#endif
I 24
_bootdev:	.long	0
_boothowto:	.long	0
	.text
E 24

E 12
__rtt:
	.word	0x0
I 21
#ifdef	REL
	halt
#else
E 21
	jmp	start
I 21
#endif
E 21
I 12
D 30

D 23
	.globl	_badloc
_badloc:
E 23
I 23
	.globl	_badaddr
_badaddr:
E 23
	.word	0
	movl	$1,r0
	movl	4(ap),r3
I 23
	movl	8(ap),r4
E 23
	movl	$4,r2
	movab	9f,(r2)
D 23
	tstl	(r3)
E 23
I 23
	bbc	$0,r4,1f; tstb	(r3)
1:	bbc	$1,r4,1f; tstw	(r3)
1:	bbc	$2,r4,1f; tstl	(r3)
E 23
1:	clrl	r0			# made it w/o machine checks
2:	movl	$4,r2
	clrl	(r2)
	ret
	.align	2
9:
	casel	_cpu,$1,$VAX_MAX
0:
	.word	8f-0b		# 1 is 780
	.word	5f-0b		# 2 is 750
D 13
	.word	5f-0b		# 3 is 730
E 13
I 13
D 14
	.word	5f-0b		# 3 is 7ZZ
E 14
I 14
	.word	5f-0b		# 3 is 730
I 20
	.word	6f-0b		# 4 is 8600
I 25
	.word	5f-0b		# 5 is 8200
	.word	1f-0b		# 6 is 8800
	.word	1f-0b		# 7 is 610
	.word	5f-0b		# 8 is 630
I 26
	.word	1f-0b		# 9 is ???
D 27
	.word	5f-0b		# 10 is 650
E 27
I 27
	.word	1f-0b		# 10 is 650
E 27
E 26
E 25
E 20
E 14
E 13
5:
	mtpr	$0xf,$MCESR
I 20
	brb	1f
6:
	mtpr	$0,$EHSR
E 20
	brb	1f
8:
	mtpr	$0,$SBIFS
1:
	addl2	(sp)+,sp		# discard mchchk trash
	movab	2b,(sp)
	rei
I 25

/*
 * Short assembly versions of strcmp, strcpy, and strlen
 * that do not use special instructions.
 */
	.globl	_strcmp
_strcmp:
	.word	0
	movq	4(ap),r0
0:	cmpb	(r0),(r1)+
	bneq	1f
	tstb	(r0)+
	bneq	0b
	clrl	r0
	ret
1:	cvtbl	(r0),r0
	cvtbl	-(r1),r1
	subl2	r1,r0
	ret

	.globl	_strcpy
_strcpy:
	.word	0
	movq	4(ap),r0
0:	movb	(r1)+,(r0)+
	bneq	0b
	movl	4(ap),r0
	ret

	.globl	_strlen
_strlen:
	.word	0
	movl	4(ap),r0
0:	tstb	(r0)+
	bneq	0b
	decl	r0
	subl2	4(ap),r0
	ret
E 30
E 25
E 12
E 1
