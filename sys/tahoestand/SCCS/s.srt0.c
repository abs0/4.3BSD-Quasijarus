h42305
s 00006/00000/00083
d D 1.6 87/04/02 16:29:32 karels 6 5
c save boothowto, bootdev
e
s 00007/00010/00076
d D 1.5 87/02/17 10:52:45 karels 5 4
c let's really zero bss
e
s 00014/00004/00072
d D 1.4 86/12/19 08:42:17 sam 4 3
c move relocation past cypher control block; purge data cache for good 
c measure (shouldn't be needed)
e
s 00029/00007/00047
d D 1.3 86/11/03 12:37:56 karels 3 2
c clean up, don't relocate unless told to
c fix rtt to return from prog, not restartclear bss if REL
e
s 00010/00024/00044
d D 1.2 86/07/13 20:03:08 root 2 1
c for sam
e
s 00068/00000/00000
d D 1.1 86/01/12 18:05:01 sam 1 0
c date and time created 86/01/12 18:05:01 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/
D 2
/*	srt0.c	4.8	81/04/03	*/
/*  Tahoe version.	82/11/09	*/
E 2

#include "../machine/mtpr.h"
#define	LOCORE

/*
 * Startup code for standalone system
 */

	.globl	_end
D 2
	.globl	_edata
E 2
	.globl	_main
	.globl	__rtt
	.globl	_openfirst
	.globl	_start
I 6
	.globl	_boothowto
	.globl	_bootdev
E 6

	.set	HIGH,31		# mask for total disable

I 4
#ifndef	REL
	.globl	_device_space
_device_space:			# Tapemaster config block, etc.
	.space	0x1000-RELOC

E 4
I 3
	.globl	_entry
_entry:
E 3
D 4
#ifndef	REL
E 4
	.word	0x00			# 'call' by relsrt0.
#endif
_start:
	mtpr	$HIGH,$IPL		# just in case
I 3
#ifdef REL
E 3
D 2
	movl	$(RELOC),sp
	movl	$RELOC,r0
	subl2	aedata,r0
	shar	$2,r0,r0
	clrl	r1		/* used to clear the memory */
clr:
	pushl	r1
	decl	r0		/* decrement counter */
	jgeq	clr		/* more to clear */

E 2
D 4
	movl	$RELOC,sp
E 4
I 4
	movl	$BOOTRELOC,sp
E 4
I 2

E 2
D 4
	movl	$0x800,r0	/* source address to copy from */
	movl	$RELOC,r1	/* destination address */
E 4
I 4
	movl	$RELOC,r0	/* source address to copy from */
	movl	$BOOTRELOC,r1	/* destination address */
E 4
D 3
	movl	aend,r2		/* length */
E 3
I 3
D 5
	movl	aedata,r2	/* length to copy */
E 5
I 5
	movl	tdlen,r2	/* length to copy */
E 5
E 3
D 2
	subl2	$0x800,r2
 #	movblk
 # simple loop replaces movblk - until hardware people are ready
E 2
I 2
	addl2	r2,r0
	addl2	r2,r1
E 2
mvloop:
I 2
	decl	r0
	decl	r1
E 2
	movb	(r0),(r1)
D 2
	incl	r0
	incl	r1
E 2
	decl	r2
D 2
	bneq	mvloop
	.globl	goup
E 2
I 2
	bgeq	mvloop

I 3
/*
 * zero bss
 */
D 5
	movab	_edata,r1	/* destination address */
	subl3	aend,aedata,r2	/* length to zero */
E 5
I 5
	movl	aedata,r1		/* destination address */
	subl3	$_edata,$_end,r2	/* length to zero */
E 5
zloop:
	movb	$0,(r1)
	incl	r1
	decl	r2
	bgeq	zloop

E 3
E 2
D 5
	mtpr	$0,$PACC
I 4
	mtpr	$0,$PADC
E 5
I 5
	mtpr	$1,$PACC
	mtpr	$1,$PADC
E 5
E 4
D 2
jumphigh:
	.set	goup,jumphigh+0x800-RELOC
E 2
	jmp	*abegin
I 3
#endif
E 3
I 2

E 2
begin:
I 3
	movl	fp,ofp
I 6
	movl	r11,_boothowto
	movl	r10,_bootdev
E 6
E 3
	movl	$1,_openfirst
	callf	$4,_main
D 3
	jmp	begin
E 3
I 3
#ifdef REL
	halt
#endif
	ret
E 3

__rtt:
	.word	0x0
D 3
	jmp	begin
E 3
I 3
#ifdef REL
	halt
#endif
	movl	ofp,fp
	ret
E 3

	.data
abegin:	.long	begin
I 4
#ifdef REL
D 5
aend:	.long	_end-BOOTRELOC
aedata:	.long	_edata-BOOTRELOC
#else
E 4
D 2
aend:	.long	_end-RELOC+0x800
aedata:	.long	_edata-RELOC+0x800
E 2
I 2
D 3
aend:	.long	_end-RELOC-0x800
aedata:	.long	_edata-RELOC-0x800
E 2
	.globl	_entry
	.set	_entry,0x800
E 3
I 3
aend:	.long	_end-RELOC
aedata:	.long	_edata-RELOC
E 5
I 5
aedata:	.long	_edata
tdlen:	.long	_edata-BOOTRELOC
E 5
I 4
#endif
E 4
ofp:	.long	0
I 6
_boothowto:	.long	0
_bootdev:	.long	0
E 6
E 3
E 1
