/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)srt0.c	7.9 (Berkeley) 2/7/04
 */

#include "../vax/mtpr.h"
#define	LOCORE
#include "../vax/cpu.h"

/*
 * Startup code for standalone system
 * Non-relocating version -- for programs which are loaded by boot
 * Relocating version for boot*
 */

	.globl	_end
	.globl	_edata
	.globl	_main
	.globl	__rtt
	.globl	_configure
	.globl	_openfirst
	.globl	_boothowto
	.globl	_bootdev

	.comm	_cpu,4
	.comm	_cpusid,4
	.comm	_cpusie,4
	.comm	_vmb_info,4

	.set	HIGH,31		# mask for total disable

entry:	.globl	entry
	nop; nop			# .word	0x0101
	mtpr	$HIGH,$IPL		# just in case

#ifdef REL
	movl	$RELOC,sp
#else
	movl	$0x6DC00,sp		# keep it below 0x70000 like in 4.3
#endif
start:
#ifndef REL
	/*
	 * Clear bss segment
	 */
	movl	aedata,r0
clr:
	clrl	(r0)+
	cmpl	r0,sp
	jlss	clr
#else
	/*
	 * `entry' below generates a pc-relative reference to the
	 * code, so this works no matter where we are now.
	 * Clear bss segment *after* moving text and data.
	 */
	movc3	aedata,entry,(sp)
dclr:
	clrl	(r3)+
	cmpl	r3,$_end
	jlss	dclr
/* this loop shouldn't be necessary, but is when booting from an ra81 */
xclr:	
	clrl	(r3)+
	cmpl	r3,$0x100000
	jlss	xclr
	jmp	*abegin
begin:
	addl3	$_end,$0x1FF,r0
	bicl2	$0x1FF,r0
	pushl	r0
	calls	$1,_setupscb
#endif
	movl	r11,_boothowto
	movl	r10,_bootdev
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
again:
	calls	$0,_configure
	movl	$1,_openfirst
	calls	$0,_main
#ifdef REL
	jmp	again
#else
	ret
#endif

	.data
#ifdef REL
abegin:	.long	begin
aedata:	.long	_edata-RELOC
#else
aedata:	.long	_edata
#endif
_bootdev:	.long	0
_boothowto:	.long	0
	.text

__rtt:
	.word	0x0
#ifdef	REL
	halt
#else
	jmp	start
#endif
