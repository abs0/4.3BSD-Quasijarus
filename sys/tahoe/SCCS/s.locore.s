h51286
s 00002/00000/01776
d D 7.2 88/07/06 17:26:48 bostic 31 30
c bootesym should be #ifdef'd KADB
e
s 00008/00001/01768
d D 7.1 88/05/21 18:35:33 karels 30 29
c bring up to revision 7 for tahoe release
e
s 00002/00002/01767
d D 1.26 88/05/19 15:15:07 karels 29 28
c rename KDB => KADB
e
s 00009/00008/01760
d D 1.25 88/05/06 12:35:03 karels 28 27
c decrease size of kmem map now that autoconf is cleaned up;
c add ADDMAP macro to extend map without adding phony symbols
e
s 00006/00000/01762
d D 1.24 88/02/28 18:42:31 karels 27 25
c add map entries for mp
e
s 00008/00013/01754
d D 1.21.1.2 88/02/24 14:47:09 mckusick 26 23
c add bug fixes for new compiler
e
s 00006/00011/01756
d D 1.23 88/02/08 13:42:05 karels 25 24
c save r3-r5 (for new compiler)
e
s 00002/00002/01765
d D 1.22 88/01/27 23:31:14 mckusick 24 22
c fix broken resume code
e
s 00011/00005/01756
d D 1.21.1.1 87/11/24 15:35:18 karels 23 22
x 18
c branch for tahoe release (no mallo)
e
s 00012/00004/01755
d D 1.21 87/11/03 14:23:17 mckusick 22 21
c put in firewall code to catch EFAULT
e
s 00004/00003/01755
d D 1.20 87/06/26 17:35:30 mckusick 21 20
c cmps3 microcode cannot handle count of zero;
c fix bug in cmps3 workaround for case of last byte on page null
e
s 00006/00005/01752
d D 1.19 87/06/26 16:00:58 karels 20 19
c check for page table faults correctly; fix up vba page table allocations
e
s 00001/00001/01756
d D 1.18 87/06/22 19:43:45 mckusick 19 18
c need more space for autoconf
e
s 00015/00004/01742
d D 1.17 87/06/06 13:24:41 mckusick 18 17
c camap is replaced by kmempt
e
s 00006/00004/01740
d D 1.16 87/06/04 22:25:11 karels 17 16
c enough memory for callocs of intermediate buffers;
c use comments that cpp understands!
e
s 00067/00058/01677
d D 1.15 87/05/31 16:46:34 mckusick 16 15
c rewrite copyinstr, copyoutstr, and copystr to avoid use of movs3
c which zero fills (using cpynstr semantics). cmps3 has same bug as movs3,
c so have to use workaround (but this one is less costly than previously).
e
s 00003/00005/01732
d D 1.14 87/05/29 15:08:39 karels 15 13
c minor cleanups in swtch
e
s 00007/00003/01734
d R 1.14 87/05/27 16:57:01 karels 14 13
c it's faster on a vax, why not try it here?
e
s 00001/00000/01736
d D 1.13 87/02/26 18:08:23 karels 13 12
c print errno when init can't be exec'ed
e
s 00036/00031/01700
d D 1.12 87/02/17 12:23:26 karels 12 11
c rearrange swtch ala vax, cancel runrun; rm old ast grot
e
s 00062/00008/01669
d D 1.11 86/11/25 16:42:55 sam 11 10
c kdb additions and profiling fixes (make masterpaddr aligned and put all routines in .text)
e
s 00006/00004/01671
d D 1.10 86/11/09 17:54:55 sam 10 9
c add FPE for floating point emulation code; change to ALIGN for alignment code
e
s 00099/00000/01576
d D 1.9 86/07/20 11:09:50 sam 9 8
c count stray interrupts, fpe traps; add alignment support code (must 
c go back and correct stack offsets for extra registers saved?)
e
s 00002/00000/01574
d D 1.8 86/07/16 08:26:43 sam 8 7
c save boot device for setroot autoconf
e
s 00003/00005/01571
d D 1.7 86/01/29 23:13:57 sam 7 6
c eliminate use of r3 in swtch; fix r2 possibly getting clobbered 
c by calls to getdatakey and/or getcodekey in resume
e
s 00015/00004/01561
d D 1.6 86/01/23 15:35:40 sam 6 5
c count device interrupts more correctly
e
s 00001/00001/01564
d D 1.5 86/01/23 13:18:34 sam 5 4
c make camap large enough to hold 4 i/o buffers for vd driver
e
s 00006/00010/01559
d D 1.4 86/01/20 23:52:31 sam 4 3
c cleanup some more of the autoconfig stuff: eliminate all page 
c maps defined in locore.s in favor of dynamically allocated entries; rename 
c some of the iospace definitions and move them into ../tahoevba/vbaparam.h 
c (will ease vme support sometime?)
e
s 00088/00063/01481
d D 1.3 86/01/12 15:38:26 sam 3 2
c 4.3- plus start of autoconfig
e
s 00726/00584/00818
d D 1.2 86/01/05 18:42:26 sam 2 1
c 1st working version
e
s 01402/00000/00000
d D 1.1 85/07/24 12:58:34 sam 1 0
c date and time created 85/07/24 12:58:34 by sam
e
u
U
f b 
t
T
I 1
D 2
/*	locore.s	1.7	85/05/15	*/
E 2
I 2
D 30
/*	%M%	%I%	%E%	*/
E 30
I 30
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 30
E 2

#include "../tahoe/mtpr.h"
#include "../tahoe/trap.h"
#include "../tahoe/psl.h"
#include "../tahoe/pte.h"
#include "../tahoe/cp.h"
#include "../tahoe/mem.h"
D 2
#include "../tahoe/fp.h"
E 2
I 2
#include "../tahoe/SYS.h"
I 30

E 30
#include "../tahoemath/fp.h"
E 2

D 2
#include "../h/errno.h"
E 2
I 2
#include "errno.h"
#include "syscall.h"
#include "cmap.h"
E 2

D 3
	.set	HIGH,0x1f	# mask for total disable
	.set	BERVEC,0x80	# offset into scb of the bus error vector 
	.set	RESTVEC,0x8	# offset into scb of the restart vector 
E 3
I 3
	.set	HIGH,0x1f		# mask for total disable
	.set	NISP,3			# number of interrupt stack pages
	.set	SYSTEM,0xC0000000	# virtual address of system start
	.set	PPAGES,0x100000  	# possible pages in P0,P1, etc.
E 3
D 2
	.set	MAXPHYSMEM,8*1024*1024-1 # max physical memory 
					# while we work on CMD/32M !
					# look at vmsched.c to see why.
	.set	MEMUNIT,64*1024 # minimum memory increment
E 2

D 3
	.set	NISP,3		# number of interrupt stack pages
	.set	SYSTEM,0xC0000000 # virtual address of system start
	.set	PPAGES,0x100000  # Number of possible pages in P0,P1, etc.

E 3
/* ACBL for non-negative '_add' */
#define ACBL(_limit,_add,_index,_displ) \
	addl2	_add,_index; \
	cmpl	_index,_limit; \
	bleq	_displ

/* _ACBL for negative '_add' */
#define _ACBL(_limit,_add,_index,_displ) \
	addl2	_add,_index; \
	cmpl	_index,_limit; \
	bgeq	_displ

D 2
#define	MOVC3(_len,_srcaddr,_dstaddr) \
E 2
I 2
#define	MOVC3(_srcaddr,_dstaddr,_len) \
E 2
	movl	_srcaddr,r0; \
	movl	_dstaddr,r1; \
	movl	_len,r2; \
	movblk

D 2
/* Keep address of psl if coming from user mode */
E 2
I 2
/* keep address of psl if coming from user mode */
E 2
#define CHECK_SFE(_delta) \
	bitl	$PSL_CURMOD,_delta(sp); \
	jeql	1f; \
	moval	_delta(sp),_user_psl; \
1:

/*
 * User structure is UPAGES at top of user space.
 */
	.globl	_u
	.set	_u,SYSTEM - UPAGES*NBPG

/*
 * Restart stack. Used on power recovery or panic.
 * Takes a core-dump and then halts.
 */ 
	.globl	_rsstk
D 2

_rsstk: 	.space	1024-8
E 2
	.globl	pwfl_stk	
D 2
pwfl_stk:	.space  4
dumpflag:	.space	4
E 2
I 2
_rsstk:
	.space	1024-8
pwfl_stk:
	.space	4
dumpflag:
	.space	4
E 2

	.globl	_intstack
_intstack:
	.space	NISP*NBPG
eintstack:

I 2
/*
 * Power failure storage block and
 * macros for saving and restoring.
 */
#define	POWERFAIL(id,longs) \
	.globl	pwfl_/**/id \
pwfl_/**/id: .space longs*4
E 2
	.data
D 2
	.globl	pwfl_r0
pwfl_r0:	.space	14*4		# Enough for r0 - r13
	.globl	pwfl_sp
pwfl_sp:	.long	0x12345678	# r14
	.globl	pwfl_SCBB
pwfl_SCBB:	.long	0x12345678
	.globl	pwfl_SBR
pwfl_SBR:	.long	0x12345678
	.globl	pwfl_SLR
pwfl_SLR:	.long	0x12345678
	.globl	pwfl_P0BR
pwfl_P0BR:	.long	0x12345678
	.globl	pwfl_P0LR
pwfl_P0LR:	.long	0x12345678
	.globl	pwfl_P1BR
pwfl_P1BR:	.long	0x12345678
	.globl	pwfl_P1LR
pwfl_P1LR:	.long	0x12345678
	.globl	pwfl_P2BR
pwfl_P2BR:	.long	0x12345678
	.globl	pwfl_P2LR
pwfl_P2LR:	.long	0x12345678
	.globl	pwfl_IPL
pwfl_IPL:	.long	0x12345678
	.globl	pwfl_DCK
pwfl_DCK:	.long	0x12345678
	.globl	pwfl_CCK
pwfl_CCK:	.long	0x12345678
	.globl	pwfl_PCBB
pwfl_PCBB:	.long	0x12345678
	.globl	pwfl_ISP
pwfl_ISP:	.long	0x12345678
	.globl	pwfl_KSP
pwfl_KSP:	.long	0x12345678
	.globl	pwfl_USP
pwfl_USP:	.long	0x12345678
	.globl	pwfl_MME
pwfl_MME:	.long	0x12345678
	.globl	pwfl_PSL
pwfl_PSL:	.long	0x12345678
E 2
I 2
	POWERFAIL(r0,	14)		# r0-r13
	POWERFAIL(sp,	1)		# r14
	POWERFAIL(SCBB,	1)		# system control block base
	POWERFAIL(SBR,	1)		# system pte base
	POWERFAIL(SLR,	1)		# system pte length
	POWERFAIL(P0BR,	1)		# p0 pte base
	POWERFAIL(P0LR,	1)		# p0 pte length
	POWERFAIL(P1BR,	1)		# p1 pte base
	POWERFAIL(P1LR,	1)		# p1 pte length
	POWERFAIL(P2BR,	1)		# p2 pte base
	POWERFAIL(P2LR,	1)		# p2 pte length
	POWERFAIL(IPL,	1)		# interrupt priority level
	POWERFAIL(DCK,	1)		# data cache key
	POWERFAIL(CCK,	1)		# code cache key
	POWERFAIL(PCBB,	1)		# process control block base
	POWERFAIL(ISP,	1)		# interrupt stack pointer
	POWERFAIL(KSP,	1)		# kernel mode stack pointer
	POWERFAIL(USP,	1)		# user mode stack pointer
	POWERFAIL(MME,	1)		# memory management enable
	POWERFAIL(PSL,	1)		# processor status longword
E 2

/*
I 2
 * Save current state in power fail storage block.
 */
#define	SAVEpwfl() \
	movpsl	pwfl_PSL	# Keeps all flags, etc. \
	storer	$0x3fff,pwfl_r0	# Saves r0-r13 \
	moval	0(sp),pwfl_sp	# Saves sp (=r14) \
	mfpr	$SBR,pwfl_SBR	# Save all re_loadable registers \
	mfpr	$SLR,pwfl_SLR \
	mfpr	$P0BR,pwfl_P0BR \
	mfpr	$P0LR,pwfl_P0LR \
	mfpr	$P1BR,pwfl_P1BR \
	mfpr	$P1LR,pwfl_P1LR \
	mfpr	$P2BR,pwfl_P2BR \
	mfpr	$P2LR,pwfl_P2LR \
	mfpr	$IPL,pwfl_IPL \
	mfpr	$MME,pwfl_MME \
	mfpr	$DCK,pwfl_DCK \
	mfpr	$CCK,pwfl_CCK \
	mfpr	$PCBB,pwfl_PCBB \
	mfpr	$ISP,pwfl_ISP \
	mfpr	$SCBB,pwfl_SCBB \
	mfpr	$KSP,pwfl_KSP \
	mfpr	$USP,pwfl_USP

/*
 * Restore state saved in power fail block and
 * jmp to location specified after (possibly)
 * enabling memory management.
 */
#define	RESTOREpwfl(loc) \
	loadr	$0x3fff,pwfl_r0	# Restore r0-r13 \
	movl	pwfl_sp,sp	# Restore sp (=r14) \
	mtpr	pwfl_SCBB,$SCBB \
	mtpr	pwfl_SBR,$SBR	# Restore all re_loadable registers \
	mtpr	pwfl_SLR,$SLR \
	mtpr	pwfl_P0BR,$P0BR \
	mtpr	pwfl_P0LR,$P0LR \
	mtpr	pwfl_P1BR,$P1BR \
	mtpr	pwfl_P1LR,$P1LR \
	mtpr	pwfl_P2BR,$P2BR \
	mtpr	pwfl_P2LR,$P2LR \
	mtpr	pwfl_IPL,$IPL \
	mtpr	pwfl_DCK,$DCK \
	mtpr	pwfl_CCK,$CCK \
	mtpr	pwfl_PCBB,$PCBB \
	mtpr	pwfl_ISP,$ISP \
	mtpr	pwfl_KSP,$KSP \
	mtpr	pwfl_USP,$USP \
\
	bicpsw	$0xff		# Restore PSW. \
	bispsw	pwfl_PSL+2	# Set original bits back (just in case..) \
# now go to mapped mode \
# Have to change PC to system addresses \
	mtpr	$1,$PACC	# Thoroughly clean up caches. \
	mtpr	$1,$PADC \
	mtpr	$1,$TBIA \
	mtpr	pwfl_MME,$MME  	# Restore MME. Last thing to be done. \
	jmp 	loc

/*
E 2
 * Do a dump.
 * Called by auto-restart.
 * May be called manually.
 */
	.align	2
	.text
	.globl	_Xdoadump
	.globl	_doadump
D 2
_Xdoadump:			# CP brings Tahoe here on power recovery
	loadr	$0x3fff,pwfl_r0	# Restore r0 - r13
	movl	pwfl_sp,sp	# Restore sp ( = r14 )
	mtpr	pwfl_SCBB,$SCBB
	mtpr	pwfl_SBR,$SBR	# Restore all re_loadable registers
	mtpr	pwfl_SLR,$SLR
	mtpr	pwfl_P0BR,$P0BR
	mtpr	pwfl_P0LR,$P0LR
	mtpr	pwfl_P1BR,$P1BR
	mtpr	pwfl_P1LR,$P1LR
	mtpr	pwfl_P2BR,$P2BR
	mtpr	pwfl_P2LR,$P2LR
	mtpr	pwfl_IPL,$IPL
	mtpr	pwfl_DCK,$DCK
	mtpr	pwfl_CCK,$CCK
	mtpr	pwfl_PCBB,$PCBB
	mtpr	pwfl_ISP,$ISP
	mtpr	pwfl_KSP,$KSP
	mtpr	pwfl_USP,$USP

	bicpsw	$0xff		# Restore PSW.
	bispsw	pwfl_PSL+2	# Set original bits back (just in case..)
/* now go to mapped mode */
/* Have to change PC to system addresses */
	mtpr	$1,$PACC	# Thoroughly clean up caches.
	mtpr	$1,$PADC
	mtpr	$1,$TBIA
	mtpr	pwfl_MME,$MME  	# Restore MME. Last thing to be done.
	jmp 	*$0f
E 2
I 2
_Xdoadump:					# CP comes here after power fail
	RESTOREpwfl(*0f)			# restore state
E 2
_doadump:
	.word 0
D 2
#define	_rsstkmap	_Sysmap+12			
			# Tahoe storage, scb, rsstk, interrupt stack
0:
	mtpr	$HIGH,$IPL
	andl2	$0!PG_PROT,_rsstkmap
E 2
I 2
0:	mtpr	$HIGH,$IPL
#define	_rsstkmap _Sysmap+12	# powerfail storage, scb, rsstk, int stack
D 12
	andl2	$~PG_PROT,_rsstkmap
E 2
	orl2	$PG_KW,_rsstkmap		# Make dump stack r/w
E 12
	tstl	dumpflag			# dump only once!
	bneq	1f
D 12
	movl	$1,dumpflag
E 12
I 12
	andl2	$~PG_PROT,_rsstkmap
	orl2	$PG_KW,_rsstkmap		# Make dump stack r/w
E 12
	mtpr	$0,$TBIA
I 12
	movl	$1,dumpflag
E 12
	movab	dumpflag,sp
	callf	$4,_dumpsys
1:
	halt

/*
 * Interrupt vector routines
 */ 
	.globl	_waittime
D 2

E 2
#define	SCBVEC(name) \
	.align 2; \
	.globl _X/**/name; \
_X/**/name
D 2
#define	PANIC(msg)	clrl _waittime; pushab 1f; \
			callf $8,_panic; 1: .asciz msg
#define	PRINTF(n,msg)	pushab 1f; callf $(n+2)*4,_printf; MSG(msg)
#define	MSG(msg)	.data; 1: .asciz msg; .text
E 2
I 2
#define	PANIC(msg) \
	clrl _waittime; pushab 1f; callf $8,_panic; 1: .asciz msg
#define	PRINTF(n,msg) \
	pushab 1f; callf $(n+2)*4,_printf; MSG(msg)
#define	MSG(msg) .data; 1: .asciz msg; .text
/*
D 25
D 26
 * r0-r2 are saved across all faults and interrupts.
E 26
I 26
 * r0-r5 are saved across all faults and interrupts.
E 26
E 25
I 25
 * r0-r5 are saved across all faults and interrupts.
E 25
D 3
 * Routines below and those hidden in ubglue.s (device
E 3
I 3
 * Routines below and those hidden in vbglue.s (device
E 3
 * interrupts) invoke the PUSHR/POPR macros to execute
 * this.  Also, certain stack frame offset calculations
D 25
D 26
 * (such as in hardclock) understand this, using the
 * REGSPC definition (and FPSPC defined below).
 * Finally, many routines, including those expanded
 * inline depend on this!  Should probably save all
 * live C compiler temp registers to eliminate potentially
 * grievous problems caused by incorrect register save masks.
E 26
I 26
 * use this, using the REGSPC definition (and FPSPC defined below).
E 26
E 25
I 25
 * use this, using the REGSPC definition (and FPSPC defined below).
E 25
 */
D 25
D 26
#define	REGSPC	(3*4)
#define	PUSHR	pushl r0; pushl r1; pushl r2;
#define	POPR	movl (sp)+,r2; movl (sp)+,r1; movl (sp)+,r0;
E 26
I 26
#define	REGSPC	6*4
#define	PUSHR	movab -REGSPC(sp),sp; storer $0x3f,(sp)
#define	POPR	loadr $0x3f,(sp); movab REGSPC(sp),sp
E 26
E 25
I 25
#define	REGSPC	6*4
#define	PUSHR	movab -REGSPC(sp),sp; storer $0x3f,(sp)
#define	POPR	loadr $0x3f,(sp); movab REGSPC(sp),sp
E 25
E 2

D 2
			# these registers are not restored by the C-compiler.
#define	PUSHR		pushl r0; pushl r1;
#define	POPR		movl (sp)+, r1; movl (sp)+, r0;
			# mask for error code on stack.
E 2
I 2
/*
 * Floating point state is saved across faults and
 * interrupts.  The state occupies 4 longwords on
 * the stack:
 *	precision indicator (single = 0/double = 1)
 *	double representation of accumulator
 *	save accumulator status flag (pcb_savacc)
 */
#define	FPSPC	(4*4)
E 2

D 2
#define SAVE_FPSTAT(_delta)	bitl	$PSL_DBL,_delta(sp); \
				beql	1f; \
				pushl	$1; \
				pushd; \
				jmp	2f; \
			1:	pushl	$0; \
				pushl	$0; \
				stf	-(sp); \
			2:	tstl	_u+PCB_SAVACC; \
				bneq	3f; \
				moval	0(sp),_u+PCB_SAVACC; \
				orl2	$2,8(sp);\
			3:	pushl	$0;
E 2
I 2
#define SAVE_FPSTAT(_delta) \
	bitl	$PSL_DBL,_delta(sp); \
	beql	1f; \
	pushl	$1; \
	pushd; \
	jmp	2f; \
1:	pushl	$0; \
	pushl	$0; \
	stf	-(sp); \
2:	tstl	_u+PCB_SAVACC; \
	bneq	3f; \
	moval	0(sp),_u+PCB_SAVACC; \
	orl2	$2,8(sp);\
3:	pushl	$0;
E 2

D 2
#define REST_FPSTAT		tstl	(sp)+; \
				bitl	$2,8(sp);\
				beql	1f;\
				movl	$0,_u+PCB_SAVACC; \
			1:	bitl	$1,8(sp); \
				beql	2f; \
				ldd	(sp); \
				jmp	3f; \
			2:	ldf	(sp); \
			3:	moval	12(sp),sp;
E 2
I 2
#define REST_FPSTAT \
	tstl	(sp)+; \
	bitl	$2,8(sp);\
	beql	1f;\
	movl	$0,_u+PCB_SAVACC; \
1:	bitl	$1,8(sp); \
	beql	2f; \
	ldd	(sp); \
	jmp	3f; \
2:	ldf	(sp); \
3:	moval	12(sp),sp;
E 2

D 2
#define REST_ACC		tstl	_u+PCB_SAVACC; \
				beql	2f; \
				movl	_u+PCB_SAVACC,r1; \
				andl3	$(EXPMASK|SIGNBIT),(r1),-(sp); \
				cmpl	$0x80000000,(sp)+; \
				bneq	3f; \
				clrl	(r1); \
			3:	bitl	$1,8(r1); \
				beql	1f; \
				ldd	(r1); \
				jmp	2f; \
			1:	ldf	(r1); \
			2:	;
E 2
I 2
#define REST_ACC \
	tstl	_u+PCB_SAVACC; \
	beql	2f; \
	movl	_u+PCB_SAVACC,r1; \
	andl3	$(EXPMASK|SIGNBIT),(r1),-(sp); \
	cmpl	$0x80000000,(sp)+; \
	bneq	3f; \
	clrl	(r1); \
3:	bitl	$1,8(r1); \
	beql	1f; \
	ldd	(r1); \
	jmp	2f; \
1:	ldf	(r1); \
2:	;
E 2

D 2
#define PUSHBPAR	pushab	6*4(sp) /* Push address of buserr paramters */
#define BPAR1		28		/* Offset to first hardware parameter */
E 2
I 2
	.data
nofault: .space	4			# bus error non-local goto label
E 2

I 2
	.text
E 2
SCBVEC(buserr):
	CHECK_SFE(12)
D 2
	SAVE_FPSTAT(12);
	PUSHR
	andl3	BPAR1(sp),$ERRCD,r0
	jeql	go_on
	cmpl	r0,$APE
E 2
I 2
	SAVE_FPSTAT(12)
I 6
	incl	_intrcnt+I_BUSERR	# keep stats...
E 6
	pushl	r0			# must save
	andl3	24(sp),$ERRCD,r0	# grab pushed MER value
	cmpl	r0,$APE			# address parity error?
E 2
	jneq	1f
D 2
	halt		# Address parity error !!!
1:	cmpl	r0,$VBE
	jneq	go_on
	halt		# Versabus error !!!
go_on:
	PUSHBPAR	# Pointer to parameters
E 2
I 2
	halt	
1:	cmpl	r0,$VBE			# versabus error?
	jneq	2f
	halt
2:
	movl	(sp)+,r0		# restore r0 and...
	bitl	$PSL_CURMOD,4*4+3*4(sp)	# check if happened in user mode?
	jeql	3f			# yes, then shift stack up for trap...
	movl	12(sp),16(sp)		# sorry, no space for which-buss...
	movl	8(sp),12(sp)
	movl	4(sp),8(sp)
	movl	0(sp),4(sp)
	movl	$T_BUSERR,0(sp)		# push trap type code and...
	jbr	alltraps		# ...merge with all other traps
3:					# kernel mode, check to see if...
	tstl	nofault			# ...doing peek/poke?
	jeql	4f			# nofault set? if so, jump to it...
	movl	nofault,4*4+2*4(sp)	# ...setup for non-local goto
	clrl	nofault
	jbr	5f
4:
	PUSHR
D 25
D 26
	pushab	7*4(sp)			# address of bus error parameters
E 26
I 26
	pushab	4*4+REGSPC(sp)		# address of bus error parameters
E 26
E 25
I 25
	pushab	4*4+REGSPC(sp)		# address of bus error parameters
E 25
E 2
	callf	$8,_buserror
	POPR
D 2
	REST_FPSTAT;
	movab	8(sp),sp	# Remove hardware parameters
E 2
I 2
5:
	REST_FPSTAT
	movab	8(sp),sp		# remove bus error parameters
E 2
	rei

D 2
SCBVEC(powfail):		# We should be on interrupt stack now.
	movpsl	pwfl_PSL	# Keeps all flags, etc.
	storer	$0x3fff,pwfl_r0	# Saves r0 - r13
	moval	0(sp),pwfl_sp	# Saves sp ( = r14 )
	mfpr	$SBR,pwfl_SBR	# Save all re_loadable registers
	mfpr	$SLR,pwfl_SLR
	mfpr	$P0BR,pwfl_P0BR
	mfpr	$P0LR,pwfl_P0LR
	mfpr	$P1BR,pwfl_P1BR
	mfpr	$P1LR,pwfl_P1LR
	mfpr	$P2BR,pwfl_P2BR
	mfpr	$P2LR,pwfl_P2LR
	mfpr	$IPL,pwfl_IPL
	mfpr	$MME,pwfl_MME  
	mfpr	$DCK,pwfl_DCK
	mfpr	$CCK,pwfl_CCK
	mfpr	$PCBB,pwfl_PCBB
	mfpr	$ISP,pwfl_ISP
	mfpr	$SCBB,pwfl_SCBB
	mfpr	$KSP,pwfl_KSP
	mfpr	$USP,pwfl_USP
E 2
I 2
SCBVEC(powfail):			# We should be on interrupt stack now.
	SAVEpwfl()			# save machine state
E 2
D 3
	moval	_Xdoadump-SYSTEM,_scb+RESTVEC
E 3
I 3
	moval	_Xdoadump-SYSTEM,_scb+SCB_DOADUMP
E 3
	halt

SCBVEC(stray):
I 9
	incl	_cnt+V_INTR		# add to statistics
E 9
D 2
	PUSHR; PRINTF(0, "******* Undefined interrupt *******\n"); POPR;
E 2
I 2
D 3
	PUSHR; PRINTF(0, "stray interrupt\n"); POPR;
E 3
E 2
	rei

#include "../net/netisr.h"
	.globl	_netisr
SCBVEC(netintr):
	CHECK_SFE(4)
D 3
	SAVE_FPSTAT(4)
	PUSHR
D 2

E 2
	bbc	$NETISR_RAW,_netisr,1f
D 2
	andl2	$(0!(1<<NETISR_RAW)),_netisr	
E 2
I 2
	andl2	$~(1<<NETISR_RAW),_netisr	
E 2
	callf	$4,_rawintr	
E 3
I 3
	SAVE_FPSTAT(4); PUSHR
#include "imp.h"
#if NIMP > 0
	bbc	$NETISR_IMP,_netisr,1f;
	andl2	$~(1<<NETISR_IMP),_netisr
	callf	$4,_impintr;
E 3
1:
I 3
#endif
E 3
#ifdef INET
D 3
#include "../netinet/in_systm.h"
E 3
	bbc	$NETISR_IP,_netisr,1f	
D 2
	andl2	$(0!(1<<NETISR_IP)),_netisr
E 2
I 2
	andl2	$~(1<<NETISR_IP),_netisr
E 2
	callf	$4,_ipintr	
1:
#endif
#ifdef NS
	bbc	$NETISR_NS,_netisr,1f	
D 2
	andl2	$(0!(1<<NETISR_NS)),_netisr
E 2
I 2
	andl2	$~(1<<NETISR_NS),_netisr
E 2
	callf	$4,_nsintr	
1:
#endif
D 3
	POPR; 
	REST_FPSTAT
E 3
I 3
	bbc	$NETISR_RAW,_netisr,1f
	andl2	$~(1<<NETISR_RAW),_netisr	
	callf	$4,_rawintr	
1:
	incl	_cnt+V_SOFT
	POPR; REST_FPSTAT
E 3
	rei
D 3
SCBVEC(soft15):
SCBVEC(soft14):
SCBVEC(soft13):
SCBVEC(soft11):
SCBVEC(soft10):
#ifndef SIMIO
SCBVEC(soft9):
#endif
SCBVEC(soft7):
SCBVEC(soft6):
SCBVEC(soft5):
SCBVEC(soft4):
#ifndef SIMIO
SCBVEC(soft3):
SCBVEC(soft2):
SCBVEC(soft1):
#endif
D 2
	PUSHR
	PRINTF(0, "******* Undefined software interrupt *******\n")
	POPR;
E 2
I 2
	PUSHR; PRINTF(0, "stray software interrupt\n"); POPR;
E 2
	rei
E 3

D 3
#ifdef SIMIO
SCBVEC(soft2):
#endif
E 3
SCBVEC(cnrint):
	CHECK_SFE(4)
D 2
	SAVE_FPSTAT(4);PUSHR; 
	pushl $CPCONS; callf $8,_cnrint; POPR; incl _cnt+V_INTR;
	REST_FPSTAT; rei
E 2
I 2
	SAVE_FPSTAT(4); PUSHR; 
D 6
	pushl $CPCONS; callf $8,_cnrint; incl _cnt+V_INTR
E 6
I 6
	pushl $CPCONS; callf $8,_cnrint;
	incl	_intrcnt+I_CNR
	incl	_cnt+V_INTR
E 6
	POPR; REST_FPSTAT;
	rei
E 2
D 3
#ifdef SIMIO
SCBVEC(soft3):
#endif
E 3
SCBVEC(cnxint):
	CHECK_SFE(4)
D 2
	SAVE_FPSTAT(4);PUSHR; 
	pushl $CPCONS; callf $8,_cnxint; POPR; REST_FPSTAT;
	incl _cnt+V_INTR; rei
E 2
I 2
	SAVE_FPSTAT(4); PUSHR; 
D 6
	pushl $CPCONS; callf $8,_cnxint; incl _cnt+V_INTR
E 6
I 6
	pushl $CPCONS; callf $8,_cnxint;
	incl	_intrcnt+I_CNX
	incl	_cnt+V_INTR
E 6
	POPR; REST_FPSTAT;
	rei
E 2
SCBVEC(rmtrint):
	CHECK_SFE(4)
	SAVE_FPSTAT(4); PUSHR; 
D 2
	pushl $CPREMOT; callf $8,_cnrint; POPR; REST_FPSTAT;
	incl _cnt+V_INTR; rei
E 2
I 2
D 6
	pushl $CPREMOT; callf $8,_cnrint; incl _cnt+V_INTR
E 6
I 6
	pushl $CPREMOT; callf $8,_cnrint;
	incl	_intrcnt+I_RMTR
	incl	_cnt+V_INTR
E 6
	POPR; REST_FPSTAT;
	rei
E 2
SCBVEC(rmtxint):
	CHECK_SFE(4)
	SAVE_FPSTAT(4); PUSHR; 
D 2
	pushl $CPREMOT; callf $8,_cnxint; POPR; REST_FPSTAT;
	incl _cnt+V_INTR; rei
E 2
I 2
D 6
	pushl $CPREMOT; callf $8,_cnxint; incl _cnt+V_INTR
E 6
I 6
	pushl $CPREMOT; callf $8,_cnxint;
	incl	_intrcnt+I_RMTX
	incl	_cnt+V_INTR
E 6
	POPR; REST_FPSTAT;
	rei
E 2
D 3
#ifdef SIMIO
SCBVEC(soft9):
#endif
E 3

D 2
#define PUSHPCPSL	pushl 5*4+2*4(sp); pushl 5*4+2*4(sp);
E 2
I 2
#define PUSHPCPSL	pushl 4+FPSPC+REGSPC(sp); pushl 4+FPSPC+REGSPC(sp);
E 2

SCBVEC(hardclock):
I 2
	tstl	_clk_enable
	bneq	1f
	rei
1:
E 2
	CHECK_SFE(4)
D 2
	SAVE_FPSTAT(4)
	PUSHR
	PUSHPCPSL				# push pc and psl
	callf $12,_hardclock			# hardclock(pc,psl)
	POPR;
	REST_FPSTAT
E 2
I 2
	SAVE_FPSTAT(4); PUSHR
	PUSHPCPSL			# push pc and psl
	callf	$12,_hardclock		# hardclock(pc,psl)
I 6
	incl	_intrcnt+I_CLOCK
E 6
E 2
	incl	_cnt+V_INTR		## temp so not to break vmstat -= HZ
I 2
	POPR; REST_FPSTAT
E 2
	rei
SCBVEC(softclock):
	CHECK_SFE(4)
D 2
	SAVE_FPSTAT(4)
	PUSHR
E 2
I 2
	SAVE_FPSTAT(4); PUSHR;
E 2
	PUSHPCPSL				# push pc and psl
D 2
	callf $12,_softclock			# softclock(pc,psl)
	POPR; 
	REST_FPSTAT
E 2
I 2
	callf	$12,_softclock			# softclock(pc,psl)
I 6
	incl	_cnt+V_SOFT
E 6
	POPR; REST_FPSTAT
E 2
	rei

/*
I 3
 * Stray VERSAbus interrupt catch routines
 */
	.data
#define	PJ	.align 2; callf $4,_Xvstray
	.globl	_catcher
_catcher:
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ

	.align	2
	.globl	_cold
_cold:	.long	0x3

	.text
SCBVEC(vstray):
	.word	0
	bbc	$0,_cold,2f		# system running?
	bbc	$1,_cold,1f		# doing autoconfig?
	jbr	3f			# random interrupt, ignore
1:
	mfpr	$IPL,r12		# ...setup br and cvec
	subl3	$_catcher+7,-8(fp),r11; shar $3,r11,r11
	addl2	$SCB_DEVBASE,r11
	jbr	3f
2:
	PUSHR
	subl3	$_catcher+7,-8(fp),r0; shar $3,r0,r0
	addl3	$SCB_DEVBASE,r0,-(sp);
	mfpr	$IPL,-(sp)
	PRINTF(2, "stray intr ipl %x vec %x\n")
	POPR
3:	moval	0f,-8(fp); ret		# pop callf frame...
0:	rei				# ...and return

/*
E 3
 * Trap and fault vector routines
 */ 
#define	TRAP(a)	pushl $T_/**/a; jbr alltraps

/*
 * Ast delivery (profiling and/or reschedule)
 */
D 12
/*
D 2
 * When we want to reschedule we will force a memory fault by setting the m.s.b
 *  of P0LR. Then , on memory fault if m.s.b of P0LR is on we will clear it and
 *  TRAP(astflt).
 *
E 2
I 2
 * When we want to reschedule we will force a
 * memory fault by setting the ASTBIT of P0LR.
 * Then, on memory fault if the ASTBIT of the
 * p0lr is set we will clear it and TRAP(astflt).
E 2
 */
D 2
 
					# if this bit is on it is an ast.
#define 	ASTBIT	0x00100000  	
#define		P0MASK	0xc0000000
E 2
I 2
#define ASTBIT	0x00100000  	
#define	P0MASK	0xc0000000
E 12
E 2

SCBVEC(kspnotval):
	CHECK_SFE(4)
	pushl $0;
	SAVE_FPSTAT(8)
	TRAP(KSPNOTVAL)
SCBVEC(privinflt):
	CHECK_SFE(4)
	pushl $0;
	SAVE_FPSTAT(8)
	TRAP(PRIVINFLT)
SCBVEC(resopflt):
	CHECK_SFE(4)
	pushl $0;
	SAVE_FPSTAT(8)
	TRAP(RESOPFLT)
SCBVEC(resadflt):
	CHECK_SFE(4)
	pushl $0;
	SAVE_FPSTAT(8)
	TRAP(RESADFLT)
SCBVEC(bptflt):
	CHECK_SFE(4)
	pushl $0;
	SAVE_FPSTAT(8)
	TRAP(BPTFLT)
I 11
SCBVEC(kdbintr):
	CHECK_SFE(4);
	pushl $0;
	SAVE_FPSTAT(8);
	TRAP(KDBTRAP);
E 11
SCBVEC(tracep):
	CHECK_SFE(4)
	pushl $0;
	SAVE_FPSTAT(8)
	TRAP(TRCTRAP)
I 9
D 10
#include "align.h"
E 10
E 9
SCBVEC(alignflt):
I 9
D 10
#if NALIGN > 0
E 10
I 10
#ifdef ALIGN
E 10
	bitl	$PSL_CURMOD,4(sp)
	jeql	align_excp		# Can't emulate for kernel mode !
	jbr	non_aligned		# Only emulated for user mode.
align_excp:
#else
E 9
	CHECK_SFE(4)
I 9
#endif
E 9
	pushl $0;
	SAVE_FPSTAT(8)
	TRAP(ALIGNFLT)
SCBVEC(arithtrap):
	CHECK_SFE(8)
	SAVE_FPSTAT(8)
	TRAP(ARITHTRAP)

SCBVEC(protflt):
	CHECK_SFE(12)
	bitl	$1,(sp)+
	jneq	segflt
	SAVE_FPSTAT(8)
	TRAP(PROTFLT)
segflt:
	SAVE_FPSTAT(8)
	TRAP(SEGFLT)

D 2
SCBVEC(fpm):			# Floating Point eMulation
	.globl	_fpemulate
E 2
I 2
SCBVEC(fpm):			# Floating Point Emulation
I 10
#ifdef FPE
E 10
E 2
	CHECK_SFE(16)
	SAVE_FPSTAT(16)
I 9
	incl	_cnt+V_FPE	# count emulation traps
E 9
	callf	$4,_fpemulate
	REST_FPSTAT
I 10
#endif
E 10
	moval	8(sp),sp	# Pop operand
	tstl	(sp)		# Stack= PSL, PC, return_code
	jneq	_Xarithtrap	# If not OK, emulate F.P. exception
	movab	4(sp),sp	# Else remove return_code and
	rei

SCBVEC(sfexcep):
	CHECK_SFE(4)
	pushl $0
	SAVE_FPSTAT(8)
	TRAP(ASTFLT)

SCBVEC(transflt):
	CHECK_SFE(12)
D 20
	bitl	$1,(sp)+
E 20
I 20
	bitl	$2,(sp)+
E 20
	bneq	tableflt
pageflt:
	SAVE_FPSTAT(8)
	TRAP(PAGEFLT)
tableflt:
	SAVE_FPSTAT(8)
	TRAP(TABLEFLT)

#define REST_STACK	movab 4(sp), sp; REST_FPSTAT; movab 4(sp), sp

alltraps:
	mfpr	$USP,-(sp); 
D 2
	callf $4,_trap; mtpr (sp)+,$USP
E 2
I 2
	callf	$4,_trap;
	mtpr	(sp)+,$USP
E 2
	incl	_cnt+V_TRAP
D 2
	REST_STACK			# pop type, code, an fp stuff
E 2
I 2
	REST_STACK			# pop type, code, and fp stuff
E 2
	mtpr	$HIGH,$IPL		## dont go to a higher IPL (GROT)
	rei

SCBVEC(syscall):
	CHECK_SFE(8)
	SAVE_FPSTAT(8)
	pushl	$T_SYSCALL
D 2
	mfpr	$USP,-(sp); callf $4,_syscall; mtpr (sp)+,$USP
E 2
I 2
	mfpr	$USP,-(sp);
	callf	$4,_syscall;
	mtpr	(sp)+,$USP
E 2
	incl	_cnt+V_SYSCALL
D 2
	REST_STACK			# pop type, code, an fp stuff
E 2
I 2
	REST_STACK			# pop type, code, and fp stuff
E 2
	mtpr	$HIGH,$IPL		## dont go to a higher IPL (GROT)
	rei

/*
D 4
 * System page table
E 4
I 4
 * System page table.
 *
E 4
I 3
 * Mbmap and Usrptmap are enlarged by CLSIZE entries
 * as they are managed by resource maps starting with index 1 or CLSIZE.
E 3
 */ 
#define	vaddr(x)	((((x)-_Sysmap)/4)*NBPG+SYSTEM)
#define	SYSMAP(mname, vname, npte)			\
_/**/mname:	.globl	_/**/mname;		\
D 3
	.space	npte*4;				\
E 3
I 3
	.space	(npte)*4;			\
E 3
	.globl	_/**/vname;			\
	.set	_/**/vname,vaddr(_/**/mname)
I 28
#define	ADDMAP(npte)	.space	(npte)*4
E 28

	.data
	.align	2
	SYSMAP(Sysmap	,Sysbase	,SYSPTSIZE	)
D 3
	SYSMAP(VMEMbeg	,vmembeg	,0		)
	SYSMAP(VMEMmap	,vmem		,IOSIZE 	)
	SYSMAP(ACE0map	,ace0utl	,(ACEBPTE+1)	)
	SYSMAP(ACE1map	,ace1utl	,(ACEBPTE+1)	)
	SYSMAP(VMEMend	,vmemend	,0		)
	SYSMAP(Usrptmap	,usrpt		,USRPTSIZE	)
E 3
	SYSMAP(Forkmap	,forkutl	,UPAGES		)
	SYSMAP(Xswapmap	,xswaputl	,UPAGES		)
	SYSMAP(Xswap2map,xswap2utl	,UPAGES		)
	SYSMAP(Swapmap	,swaputl	,UPAGES		)
	SYSMAP(Pushmap	,pushutl	,UPAGES		)
	SYSMAP(Vfmap	,vfutl		,UPAGES		)
D 3
	SYSMAP(VD0map	,vd0utl		,(MAXBPTE+1)	)
	SYSMAP(VD1map	,vd1utl		,(MAXBPTE+1)	)
	SYSMAP(VD2map	,vd2utl		,(MAXBPTE+1)	)
	SYSMAP(VD3map	,vd3utl		,(MAXBPTE+1)	)
D 2
	SYSMAP(CYmap	,cyutl		,(TBUFSIZ+1)	)
E 2
I 2
	SYSMAP(CY0map	,cy0utl		,(TBUFSIZ+1)	)
	SYSMAP(CY1map	,cy1utl		,(TBUFSIZ+1)	)
E 3
E 2
	SYSMAP(CMAP1	,CADDR1		,1		)
	SYSMAP(CMAP2	,CADDR2		,1		)
	SYSMAP(mmap	,vmmap		,1		)
I 3
	SYSMAP(alignmap	,alignutl	,1		)	/* XXX */
E 3
	SYSMAP(msgbufmap,msgbuf		,MSGBUFPTECNT	)
I 3
	SYSMAP(Mbmap	,mbutl		,NMBCLUSTERS*CLSIZE+CLSIZE )
E 3
D 5
	SYSMAP(camap	,cabase		,16*CLSIZE	)
E 5
I 5
D 17
	SYSMAP(camap	,cabase		,(4*32+4)*CLSIZE )
E 17
I 17
D 18
D 23
	SYSMAP(camap	,cabase		,(VBPTSIZE+16)*CLSIZE )
E 18
I 18
D 19
	SYSMAP(kmempt	,kmembase	,100*CLSIZE 	)
E 19
I 19
D 28
	SYSMAP(kmempt	,kmembase	,1024*CLSIZE 	)
E 28
I 28
	SYSMAP(kmempt	,kmembase	,300*CLSIZE 	)
E 28
E 23
I 23
	SYSMAP(camap	,cabase		,16*CLSIZE	 )
E 23
E 19
E 18
E 17
E 5
I 3
#ifdef	GPROF
	SYSMAP(profmap	,profbase	,600*CLSIZE	)
#endif
E 3
D 18
D 23
	SYSMAP(ecamap	,calimit	,0		)
E 23
I 23
	/*
	 * Enlarge camap as needed for bounce buffers allocated
	 * by tahoe controllers.
	 */
#include "dk.h"
E 23
E 18
I 18
	/*
	 * Enlarge kmempt as needed for bounce buffers allocated
	 * by tahoe controllers.
	 */
#include "dk.h"
D 20
	SYSMAP(_vdmap	,_vdbase	,NVD*MAXPHYS/NBPG+CLSIZE )
E 20
I 20
D 28
	SYSMAP(_vdmap	,_vdbase	,NVD*(MAXPHYS/NBPG+CLSIZE) )
E 28
I 28
				ADDMAP(	NVD*(MAXPHYS/NBPG+CLSIZE) )
E 28
I 23
#include "yc.h"
E 23
E 20
#include "yc.h"
D 20
	SYSMAP(_cymap	,_cybase	,NCY*MAXPHYS/NBPG+CLSIZE )
E 20
I 20
D 28
	SYSMAP(_cymap	,_cybase	,NCY*(MAXPHYS/NBPG+CLSIZE) )
E 28
I 28
				ADDMAP(	NCY*(MAXPHYS/NBPG+CLSIZE) )
E 28
I 27
#include "mp.h"
D 28
	SYSMAP(_mpmap	,_mpbase	,NMP*14		)
E 28
I 28
				ADDMAP(	NMP*14		)
E 28
E 27
I 23
	SYSMAP(ecamap	,calimit	,0		)
E 23
E 20
	SYSMAP(ekmempt	,kmemlimit	,0		)
I 27

E 27
E 18
D 3
	SYSMAP(Mbmap	,mbutl		,NMBCLUSTERS*CLSIZE)
E 3
I 3
	SYSMAP(VMEMbeg	,vmembeg	,0		)
D 4
	SYSMAP(VMEMmap	,vmem		,IOSIZE 	)
	SYSMAP(ACE0map	,ace0utl	,ACEBPTE+1	)
	SYSMAP(ACE1map	,ace1utl	,ACEBPTE+1	)
E 4
I 4
	SYSMAP(VMEMmap	,vmem		,VBIOSIZE 	)
D 18
D 23
	SYSMAP(VMEMmap1	,vmem1		,VBMEMSIZE	)
E 23
I 23
	SYSMAP(VMEMmap1	,vmem1		,0		)
#include "ace.h"
	SYSMAP(_acemap1	,_acemem	,NACE*32	)
E 23
E 18
I 18
	SYSMAP(VMEMmap1	,vmem1		,0		)
#include "ace.h"
D 28
	SYSMAP(_acemap1	,_acemem	,NACE*32	)
E 28
I 28
				ADDMAP(	NACE*32	)
E 28
E 18
E 4
	SYSMAP(VMEMend	,vmemend	,0		)
I 27

E 27
D 4
	SYSMAP(VD0map	,vd0utl		,MAXBPTE+1	)
	SYSMAP(VD1map	,vd1utl		,MAXBPTE+1	)
	SYSMAP(VD2map	,vd2utl		,MAXBPTE+1	)
	SYSMAP(VD3map	,vd3utl		,MAXBPTE+1	)
	SYSMAP(CY0map	,cy0utl		,TBUFSIZ+1	)
	SYSMAP(CY1map	,cy1utl		,TBUFSIZ+1	)
E 4
I 4
D 18
D 23
	SYSMAP(VBmap	,vbbase		,VBPTSIZE	)
E 23
E 18
I 18
D 20
	SYSMAP(VBmap	,vbbase		,0		)
	SYSMAP(_vdbmap	,_vdbbase	,NVD*MAXPHYS/NBPG+CLSIZE )
E 20
I 20
	SYSMAP(VBmap	,vbbase		,CLSIZE		)
D 28
	SYSMAP(_vdbmap	,_vdbbase	,NVD*(MAXPHYS/NBPG+CLSIZE) )
	SYSMAP(_cybmap	,_cybbase	,NCY*(MAXPHYS/NBPG+CLSIZE) )
I 27
	SYSMAP(_mpbmap	,_mpbbase	,NMP*14		)
E 28
I 28
				ADDMAP(	NVD*(MAXPHYS/NBPG+CLSIZE) )
				ADDMAP(	NCY*(MAXPHYS/NBPG+CLSIZE) )
				ADDMAP(	NMP*14		)
E 28
E 27
E 20
E 18
	SYSMAP(eVBmap	,vbend		,0		)
I 27

E 27
E 4
	SYSMAP(Usrptmap	,usrpt		,USRPTSIZE+CLSIZE )
E 3
eSysmap:
	.globl	_Syssize
	.set	_Syssize,(eSysmap-_Sysmap)/4

	.text
/*
 * Initialization
 *
 * IPL 0x1f; MME 0; scbb, pcbb, sbr, slr, isp, ksp not set
D 2
 *
E 2
 */
D 2

E 2
	.align	2
	.globl	start
start:
	.word	0
D 2

E 2
/* set system control block base and system page table params */
D 2

E 2
	mtpr	$_scb-SYSTEM,$SCBB
	mtpr	$_Sysmap-SYSTEM,$SBR
	mtpr	$_Syssize,$SLR
D 2

E 2
/* double map the kernel into the virtual user addresses of phys mem */
D 2
/* (to be on the safe side.This is supposed to run in system sace. )  */
E 2
	mtpr	$_Sysmap,$P0BR
	mtpr	$_Syssize,$P0LR
D 2

	mtpr	$_Sysmap,$P1BR		# Against Murphy
E 2
I 2
	mtpr	$_Sysmap,$P1BR			# against Murphy
E 2
	mtpr	$_Syssize,$P1LR
D 2

E 2
/* set ISP */
D 2
	movl	$_intstack-SYSTEM+NISP*NBPG,sp	# Still physical !
E 2
I 2
	movl	$_intstack-SYSTEM+NISP*NBPG,sp	# still physical
E 2
	mtpr	$_intstack+NISP*NBPG,$ISP
D 2

E 2
/* count up memory */
D 2

E 2
	clrl	r7
1:	pushl	$1; pushl r7; callf $12,_badaddr; tstl r0; bneq 9f
D 2
	addl2	$MEMUNIT,r7
	cmpl	r7,$MAXPHYSMEM
	bleq	1b
E 2
I 2
	ACBL($MAXMEM*1024-1,$64*1024,r7,1b)
E 2
9:
/* clear memory from kernel bss and pages for proc 0 u. and page table */
D 11
	movab	_edata,r6
	movab	_end,r5
D 2
	andl2	$0!SYSTEM,r6
	andl2	$0!SYSTEM,r5
E 2
I 2
	andl2	$~SYSTEM,r6
	andl2	$~SYSTEM,r5
E 11
I 11
	movab	_edata,r6; andl2 $~SYSTEM,r6
	movab	_end,r5; andl2 $~SYSTEM,r5
D 29
#ifdef KDB
E 29
I 29
#ifdef KADB
E 29
	subl2	$4,r5
1:	clrl	(r6); ACBL(r5,$4,r6,1b)		# clear just bss
	addl2	$4,r5
	bbc	$6,r11,0f			# check RB_KDB
	andl3	$~SYSTEM,r9,r5			# skip symbol & string tables
	andl3	$~SYSTEM,r9,r6
#endif
0:	orl3	$SYSTEM,r5,r9			# convert to virtual address
	addl2	$NBPG-1,r9			# roundup to next page
E 11
E 2
	addl2	$(UPAGES*NBPG)+NBPG+NBPG,r5
D 2
1:	clrl	(r6); ACBL( r5,$4,r6,1b)

/* trap() and syscall() save r0-r13 in the entry mask (per ../h/reg.h) */
/* For floating point emulation, we do same for 'fpemulate' */
E 2
I 2
1:	clrl	(r6); ACBL(r5,$4,r6,1b)
/* trap(), syscall(), and fpemulate() save r0-r12 in the entry mask */
E 2
	orw2	$0x01fff,_trap
	orw2	$0x01fff,_syscall
I 10
#ifdef FPE
E 10
	orw2	$0x01fff,_fpemulate
I 10
#endif
E 10
D 2

E 2
I 2
	orw2	$0x01ffc,_panic			# for debugging (no r0|r1)
I 3
	callf	$4,_fixctlrmask			# setup for autoconfig
E 3
E 2
/* initialize system page table: scb and int stack writeable */
	clrl	r2
	movab	eintstack,r1 
D 2
	andl2	$0!SYSTEM,r1
	shrl 	$PGSHIFT,r1,r1		# r1-page number of eintstack.

/* Start by making the processor storage read/only */

E 2
I 2
	andl2	$~SYSTEM,r1
	shrl 	$PGSHIFT,r1,r1			# r1-page number of eintstack
D 12
/* make processor storage read/only */
E 12
I 12
/* make 1st page processor storage read/only, 2nd read/write */
E 12
E 2
	orl3	$PG_V|PG_KR,r2,_Sysmap[r2]; incl r2;
D 12
	orl3	$PG_V|PG_KR,r2,_Sysmap[r2]; incl r2;
E 12
I 12
	orl3	$PG_V|PG_KW,r2,_Sysmap[r2]; incl r2;
E 12
D 2

/* Other parts of the system are read/write for kernel */

1:	orl3	$PG_V|PG_KW,r2,_Sysmap[r2]; # data:kernel write + phys=virtual
E 2
I 2
/* other parts of the system are read/write for kernel */
1:	orl3	$PG_V|PG_KW,r2,_Sysmap[r2];	# data:kernel write+phys=virtual
E 2
	aoblss r1,r2,1b
D 2

E 2
/* make rsstk read-only as red zone for interrupt stack */
D 2
	andl2	$0!PG_PROT,_rsstkmap
	orl2	$PG_V|PG_KR,_rsstkmap		# Make dump stack r/w

E 2
I 2
	andl2	$~PG_PROT,_rsstkmap
	orl2	$PG_V|PG_KR,_rsstkmap
E 2
/* make kernel text space read-only */
D 2
/*
 * HAVE TO CHECK ALL THE MAGIC CONSTANTS USED HERE : $xxxxxx */

E 2
	movab	_etext+NBPG-1,r1
D 2
	andl2	$0!SYSTEM,r1
E 2
I 2
	andl2	$~SYSTEM,r1
E 2
	shrl 	$PGSHIFT,r1,r1
1:	orl3	$PG_V|PG_KR,r2,_Sysmap[r2]
	aoblss r1,r2,1b
D 2

E 2
/* make kernel data, bss, read-write */
D 11
	movab	_end+NBPG-1,r1
D 2
	andl2	$0!SYSTEM,r1
E 2
I 2
	andl2	$~SYSTEM,r1
E 11
I 11
	andl3	$~SYSTEM,r9,r1
E 11
E 2
	shrl 	$PGSHIFT,r1,r1
1:	orl3	$PG_V|PG_KW,r2,_Sysmap[r2]
	aoblss r1,r2,1b
D 2

/* now go to mapped mode */
/* Have to change both PC and SP to system addresses */
E 2
I 2
/* go to mapped mode, have to change both pc and sp to system addresses */
E 2
	mtpr	$1,$TBIA
D 2
	mtpr	$1,$PADC	/* needed by HW parity & ECC logic */
	mtpr	$1,$PACC	/* just in case */
E 2
I 2
	mtpr	$1,$PADC			# needed by HW parity&ECC logic
	mtpr	$1,$PACC			# just in case
E 2
	mtpr 	$1,$MME
	movab	SYSTEM(sp),sp
D 2
	.globl	go_virt
go_virt:	
E 2
	jmp 	*$0f
0:
D 2

E 2
/* disable any interrupts */
	movl	$0,_intenable
/* init mem sizes */
	shrl	$PGSHIFT,r7,_maxmem
	movl	_maxmem,_physmem
	movl	_maxmem,_freemem
D 2

/* setup context for proc[0] == Scheduler */
E 2
I 2
/* setup context for proc[0] == scheduler */
E 2
D 11
	movab	_end-SYSTEM+NBPG-1,r6
E 11
I 11
	andl3	$~SYSTEM,r9,r6			# convert to physical
E 11
D 2
	andl2	$0!(NBPG-1),r6		# make page boundary

E 2
I 2
	andl2	$~(NBPG-1),r6			# make page boundary
E 2
/* setup page table for proc[0] */
	shrl	$PGSHIFT,r6,r3			# r3 = btoc(r6)
	orl3	$PG_V|PG_KW,r3,_Usrptmap	# init first upt entry
	incl	r3				# r3 - next page
	movab	_usrpt,r0			# r0 - first user page
	mtpr	r0,$TBIS
D 2

E 2
/* init p0br, p0lr */
D 2
	mtpr	r0,$P0BR	# No P0 for proc[0]
E 2
I 2
	mtpr	r0,$P0BR			# no p0 for proc[0]
E 2
	mtpr	$0,$P0LR
D 2

	mtpr	r0,$P1BR	# No P1 either
E 2
I 2
	mtpr	r0,$P1BR			# no p1 either
E 2
	mtpr	$0,$P1LR
D 2


E 2
/* init p2br, p2lr */
	movab	NBPG(r0),r0
	movl	$PPAGES-UPAGES,r1
	mtpr	r1,$P2LR
	moval	-4*PPAGES(r0),r2
	mtpr	r2,$P2BR
D 2

E 2
/* setup mapping for UPAGES of _u */
D 2
	clrl	r2; 
E 2
I 2
	clrl	r2
E 2
	movl 	$SYSTEM,r1
	addl2 	$UPAGES,r3
	jbr 2f
1:	decl	r3
D 2
	moval	-NBPG(r1),r1;	# r1 = virtual add of next (downward) _u page
E 2
I 2
	moval	-NBPG(r1),r1	# r1 = virtual add of next (downward) _u page
E 2
	subl2	$4,r0		# r0 = pte address
	orl3	$PG_V|PG_URKW,r3,(r0)
	mtpr	r1,$TBIS
2:	aobleq	$UPAGES,r2,1b
D 2

E 2
/* initialize (slightly) the pcb */
	movab	UPAGES*NBPG(r1),PCB_KSP(r1)	# KSP starts at end of _u
	movl	r1,PCB_USP(r1)			# USP starts just below _u
	mfpr	$P0BR,PCB_P0BR(r1)
	mfpr	$P0LR,PCB_P0LR(r1)
	mfpr	$P1BR,PCB_P1BR(r1)
	mfpr	$P1LR,PCB_P1LR(r1)
	mfpr	$P2BR,PCB_P2BR(r1)
	mfpr	$P2LR,PCB_P2LR(r1)
	movl	$CLSIZE,PCB_SZPT(r1)		# init u.u_pcb.pcb_szpt
I 11
	movl	r9,PCB_R9(r1)			# r9 obtained from boot
	movl	r10,PCB_R10(r1)			# r10 obtained from boot
E 11
	movl	r11,PCB_R11(r1)			# r11 obtained from CP on boot
	movab	1f,PCB_PC(r1)			# initial pc
	clrl	PCB_PSL(r1)			# kernel mode, ipl=0
D 2
	movw	$0xff,PCB_CKEY(r1)	# give him a code key
	movw	$0xff,PCB_DKEY(r1)	# give him a data key
E 2
	shll	$PGSHIFT,r3,r3
D 2
	mtpr	r3,$PCBB			# first pcbb (physical ! )

/* Go to a 'normal' process mode (kernel) */

E 2
I 2
	mtpr	r3,$PCBB			# first pcbb (physical)
/* go to kernel mode */
E 2
	ldpctx
D 2
	rei		# Actually 'returns' to the next instruction:

E 2
I 2
	rei					# Actually next instruction:
E 2
/* put signal trampoline code in u. area */
D 2
1:	movab	_u,r0
	movl	sigcode+0,PCB_SIGC+0(r0)
	movl	sigcode+4,PCB_SIGC+4(r0)
	movl	sigcode+8,PCB_SIGC+8(r0)
	movl	sigcode+12,PCB_SIGC+12(r0)

E 2
I 2
1:	movab	sigcode,r0
	movab	_u+PCB_SIGC,r1
	movl	$19,r2
	movblk
I 8
/* save boot device in global _bootdev */
	movl	r10,_bootdev
E 8
E 2
/* save reboot flags in global _boothowto */
	movl	r11,_boothowto
I 31
#ifdef KADB
E 31
I 11
/* save end of symbol & string table in global _bootesym */
	subl3	$NBPG-1,r9,_bootesym
I 31
#endif
E 31
E 11
D 2

E 2
/* calculate firstaddr, and call main() */
D 11
	movab	_end-SYSTEM+NBPG-1,r0
E 11
I 11
	andl3	$~SYSTEM,r9,r0
E 11
	shrl	$PGSHIFT,r0,-(sp)
D 2
	addl2	$UPAGES+1,(sp)		# First physical unused page number
E 2
I 2
	addl2	$UPAGES+1,(sp)			# first physical unused page
E 2
	callf 	$8,_main
D 2

E 2
/* proc[1] == /etc/init now running here in kernel mode; run icode */
D 2
	pushl	$PSL_CURMOD		# User mode PSL
	pushl $0			# PC = 0 (virtual now)
E 2
I 2
	pushl	$PSL_CURMOD			# User mode PSL
	pushl $0				# PC = 0 (virtual now)
E 2
	rei

D 2
/* signal trampoline code: it is known that this code takes up to 16    */
/* bytes in pcb.h and in the code above 				*/
/*  The following user stack layout was set up by machdep.c/sendsig 	*/
/*	routine:							*/
/*									*/
/*	+---------------+						*/
/*	|  Last PSL	|\						*/
/*	+---------------+ > for rei					*/
/*  :-->|  Last PC	|/						*/
/*  |	+---------------+						*/
/*  :___|__*   SP	|\						*/
/*	+---------------+ |						*/
/*	|  sigmask	| |						*/
/*	+---------------+  > cleaned by kcall $139 (sigcleanup)		*/
/*  :-->|  u.u_onstack	| |						*/
/*  |	+---------------+ |						*/
/*  :___|_* copy of SCP	|/						*/
/*  |	+---------------+						*/
/*  |	|  Process' r0	| 						*/
/*  |	+---------------+						*/
/*  |	|  Process' r1	|						*/
/*  |	+---------------+						*/
/*  |	| Handler addr. |\						*/
/*  |	+---------------+ |						*/
/*  :___|_*   SCP	| |						*/
/*	+---------------+  > cleaned by ret from calls			*/
/*	|  u.u_code	| |						*/
/*	+---------------+ |						*/
/*	|  signal number|/						*/
/*	+---------------+						*/
/*									*/
/*   * Stack when entering sigcode; setup by sendsig();			*/
/*									*/
E 2
I 2
/*
 * Mask for saving/restoring registers on entry to
 * a user signal handler.  Space for the registers
 * is reserved in sendsig, so beware if you want
 * to change the mask.
 */
#define	SIGREGS	(R0|R1|R2|R3|R4|R5)
E 2
	.align	2
D 2
sigcode:			# When the process executes this code
				#  (located in its u. structure), it
				#  is in user mode !
	calls	$4*4+4,*12(sp)	# 4 words popped from stack when this call returns
	movl	(sp)+,r1
	movl	(sp)+,r0
	kcall	$139		# Signal cleanup
	rei			# From user mode to user mode !
E 2
I 2
	.globl	sigcode
sigcode:
	storer	$SIGREGS,16(sp)	# save volatile registers
	calls	$4*3+4,*12(sp)	# params pushed by sendsig for handler
	loadr	$SIGREGS,4(sp)	# restore volatile registers
	movab	24(sp),fp	# use parameter list set up in sendsig
	kcall	$SYS_sigreturn	# cleanup mask and onsigstack
	halt			# sigreturn does not return!
E 2

I 2
	.globl	_icode
	.globl	_initflags
	.globl	_szicode
E 2
/*
I 2
 * Icode is copied out to process 1 to exec /etc/init.
 * If the exec fails, process 1 exits.
 */
	.align	2
_icode:
	pushab	b`argv-l0(pc)
l0:	pushab	b`init-l1(pc)
l1:	pushl	$2
	movab	(sp),fp
	kcall	$SYS_execv
I 13
	pushl	r0
E 13
	kcall	$SYS_exit

init:	.asciz	"/etc/init"
	.align	2
_initflags:
	.long	0
argv:	.long	init+5-_icode
	.long	_initflags-_icode
	.long	0
_szicode:
	.long	_szicode-_icode

/*
E 2
 * Primitives
 */ 

/*
 * badaddr(addr, len)
 *	see if access addr with a len type instruction causes a machine check
 *	len is length of access (1=byte, 2=short, 4=long)
 *	r0 = 0 means good(exists); r0 =1 means does not exist.
 */
D 2
	.globl	_badaddr
_badaddr:
	.word	0x1c	# Keep r4,r3,r2
E 2
I 2
ENTRY(badaddr, R3|R4)
E 2
	mfpr	$IPL,r1
	mtpr	$HIGH,$IPL
D 3
	movl	_scb+BERVEC,r2
E 3
I 3
	movl	_scb+SCB_BUSERR,r2
E 3
	movl	4(fp),r3
	movl	8(fp),r4
D 3
	movab	9f,_scb+BERVEC
E 3
I 3
	movab	9f,_scb+SCB_BUSERR
E 3
	bbc	$0,r4,1f; tstb	(r3)
1:	bbc	$1,r4,1f; tstw	(r3)
1:	bbc	$2,r4,1f; tstl	(r3)
D 2
1:	clrl	r0			# made it w/o machine checks
E 2
I 2
1:	clrl	r0
E 2
D 3
2:	movl	r2,_scb+BERVEC
E 3
I 3
2:	movl	r2,_scb+SCB_BUSERR
E 3
	mtpr	r1,$IPL
	ret

	.align	2
D 2
9:			# Here we catch buss error (if it comes)
E 2
I 2
9:				# catch buss error (if it comes)
E 2
	andl3	4(sp),$ERRCD,r0
	cmpl	r0,$APE
	jneq	1f
D 2
	halt			# Address parity error !!!
E 2
I 2
	halt			# address parity error
E 2
1:	cmpl	r0,$VBE
	jneq	1f
	halt			# Versabus error
1:
	movl	$1,r0		# Anything else = bad address
	movab	8(sp),sp	# discard buss error trash
	movab	2b,(sp)		# new program counter on stack.
	rei

D 2

E 2
/*
 * badcyaddr(addr)
 *	see if access tape master controller addr causes a bus error
 *	r0 = 0: no error; r0 = 1: timeout error.
 */
D 2
	.globl	_badcyaddr
_badcyaddr:
	.word	0x0c	# Keep r3,r2
E 2
I 2
ENTRY(badcyaddr, 0)
E 2
	mfpr	$IPL,r1
	mtpr	$HIGH,$IPL
D 2
	movl	_scb+BERVEC,r2
	clrl	r3
	movab	9f,_scb+BERVEC
E 2
I 2
	clrl	r2
	movab	2f,nofault
E 2
	movob	$-1, *4(fp)
D 2
1:	aobleq	$1000, r3, 1b
	clrl	r0			# made it w/o machine checks
2:	movl	r2,_scb+BERVEC
	mtpr	r1,$IPL
E 2
I 2
1:	aobleq	$1000, r2, 1b
	clrl	nofault			# made it w/o bus error
	clrl	r0
	jbr	3f
2:	movl	$1,r0
3:	mtpr	r1,$IPL
E 2
	ret

D 2
	.align	2
9:			# Here we catch buss error (if it comes)
	andl3	4(sp),$ERRCD,r0
	cmpl	r0,$APE
	jneq	1f
	halt			# Address parity error !!!
1:	cmpl	r0,$VBE
	jneq	1f
	halt			# Versabus error
1:
	movl	$1,r0		# Anything else = timeout
	movab	8(sp),sp	# discard buss error trash
	movab	2b,(sp)		# new program counter on stack.
	rei
E 2
I 2
/*
 * peek(addr)
 *	fetch word and catch any bus error
 */
ENTRY(peek, 0)
	mfpr	$IPL,r1
	mtpr	$0x18,$IPL	# not reentrant
	movl	4(fp),r2
	movab	1f,nofault
	movw	(r2),r0
	clrl	nofault
	andl2	$0xffff,r0
	jbr	2f
1:	movl	$-1,r0		# bus error
2:	mtpr	r1,$IPL
	ret
E 2

D 2
_bcopy:	.globl	_bcopy
	.word	0x4		# save r2
				# Called by ovbcopy(from,dst,len)
	movl	4(fp),r0
	movl	8(fp),r1
	movl	12(fp),r2
	movblk
E 2
I 2
/*
 * poke(addr, val)
 *	write word and catch any bus error
 */
ENTRY(poke, R3)
	mfpr	$IPL,r1
	mtpr	$0x18,$IPL	# not reentrant
	movl	4(fp),r2
	movl	8(fp),r3
	clrl	r0
	movab	1f,nofault
	movw	r3,(r2)
	clrl	nofault
	jbr	2f
1:	movl	$-1,r0		# bus error
2:	mtpr	r1,$IPL
E 2
	ret

D 2
_ovbcopy:	.globl	_ovbcopy
	.word	0x001c
E 2
I 2
/*
 * Copy a potentially overlapping block of memory.
 *
 * ovbcopy(src, dst, count)
 *	caddr_t src, dst; unsigned count;
 */
ENTRY(ovbcopy, R3|R4)
E 2
	movl	4(fp),r0
	movl	8(fp),r1
	movl	12(fp),r2
	cmpl	r0,r1
D 2
	bgtru	1f		# normal forward case
	beql	2f		# equal, nothing to do
	addl2	r2,r0		# may be overlapping
E 2
I 2
	bgtru	1f			# normal forward case
	beql	2f			# equal, nothing to do
	addl2	r2,r0			# may be overlapping
E 2
	cmpl	r0,r1
	bgtru	3f
D 2
	subl2	r2,r0		# normal forward case
E 2
I 2
	subl2	r2,r0			# normal forward case
E 2
1:
	movblk
2:
	ret
3:
D 2
	addl2	r2,r1		# overlapping, must do backwards
E 2
I 2
	addl2	r2,r1			# overlapping, must do backwards
E 2
	subl3	r0,r1,r3
	movl	r2,r4
	jbr	5f
4:
	subl2	r3,r0
	subl2	r3,r1
	movl	r3,r2
	movblk
	subl2	r3,r0
	subl2	r3,r1
	subl2	r3,r4
5:
	cmpl	r4,r3
	jgtr	4b
	movl	r4,r2
	subl2	r2,r0
	subl2	r2,r1
	movblk
	ret

/*
D 2
 * bzero (base, count)
 * zero out a block starting at 'base', size 'count'.
E 2
I 2
 * Copy a null terminated string from the user address space into
 * the kernel address space.
 *
 * copyinstr(fromaddr, toaddr, maxlength, &lencopied)
E 2
 */
D 2
_bzero:	
	.globl	_bzero
	.word	0x4
	movl	$1f,r0				# r0 = null source string
	movl	4(fp),r1			# r1 = destination address
	movl	8(fp),r2			# r2 = count
	movs3
E 2
I 2
D 16
ENTRY(copyinstr, R3|R4|R5)
E 16
I 16
ENTRY(copyinstr, 0)
E 16
	movl	12(fp),r5		# r5 = max length
D 16
	jlss	8f
E 16
I 16
	jlss	5f
	movl	8(fp),r4		# r4 = kernel address
E 16
	movl	4(fp),r0		# r0 = user address
D 16
	movl	r0,r3			# r3 = copy of src for null byte test
E 16
	andl3	$(NBPG*CLSIZE-1),r0,r2	# r2 = bytes on first page
	subl3	r2,$(NBPG*CLSIZE),r2
D 16
	movl	8(fp),r1		# r1 = kernel address
E 16
1:
	cmpl	r5,r2			# r2 = min(bytes on page, length left);
	jgeq	2f
	movl	r5,r2
2:
	prober	$1,(r0),r2		# bytes accessible?
D 16
	jeql	8f
E 16
I 16
	jeql	5f
E 16
	subl2	r2,r5			# update bytes left count
D 16
	addl2	r2,r3			# calculate src+count
	movs3				# copy in next piece
	subl3	r0,r3,r2		# null byte found?
E 16
I 16
	movl	r2,r3			# r3 = saved count
	movl	r0,r1
	cmps3				# check for null
	tstl	r2
E 16
	jneq	3f
I 16
	subl2	r3,r0			# back up r0
	movl	r4,r1
	movl	r3,r2
	movblk				# copy in next piece
	movl	r1,r4
E 16
	movl	$(NBPG*CLSIZE),r2	# check next page
	tstl	r5			# run out of space?
	jneq	1b
	movl	$ENOENT,r0		# set error code and return
D 16
	jbr	9f
E 16
I 16
	jbr	6f
E 16
3:
	tstl	16(fp)			# return length?
	beql	4f
	subl3	r5,12(fp),r5		# actual len = maxlen - unused pages
	subl2	r2,r5			#	- unused on this page
	addl3	$1,r5,*16(fp)		#	+ the null byte
4:
I 16
	movl	r4,r1
	subl3	r2,r3,r2		# calc char cnt
	subl2	r2,r0			# back up r0
	incl	r2			# add on null byte
	movblk				# copy last piece
E 16
	clrl	r0
E 2
	ret
I 2
D 16
8:
E 16
I 16
5:
E 16
	movl	$EFAULT,r0
D 16
9:
E 16
I 16
6:
E 16
	tstl	16(fp)
D 16
	beql	1f
E 16
I 16
	beql	7f
E 16
	subl3	r5,12(fp),*16(fp)
E 2
D 16
1:
E 16
I 16
7:
E 16
D 2
	.byte 0
E 2
I 2
	ret
E 2

I 2
/*
 * Copy a null terminated string from the kernel
 * address space to the user address space.
 *
 * copyoutstr(fromaddr, toaddr, maxlength, &lencopied)
 */
D 16
ENTRY(copyoutstr, R3|R4|R5)
E 16
I 16
ENTRY(copyoutstr, 0)
E 16
	movl	12(fp),r5		# r5 = max length
D 16
	jlss	8b
E 16
I 16
D 22
	jlss	5b
E 22
I 22
	jlss	5f
E 22
E 16
	movl	4(fp),r0		# r0 = kernel address
D 16
	movl	r0,r3			# r3 = copy of src for null byte test
	movl	8(fp),r1		# r1 = user address
	andl3	$(NBPG*CLSIZE-1),r1,r2	# r2 = bytes on first page
E 16
I 16
	movl	8(fp),r4		# r4 = user address
	andl3	$(NBPG*CLSIZE-1),r4,r2	# r2 = bytes on first page
E 16
	subl3	r2,$(NBPG*CLSIZE),r2
1:
	cmpl	r5,r2			# r2 = min(bytes on page, length left);
	jgeq	2f
	movl	r5,r2
2:
D 16
	probew	$1,(r1),r2		# bytes accessible?
	jeql	8b
E 16
I 16
	probew	$1,(r4),r2		# bytes accessible?
D 22
	jeql	5b
E 22
I 22
	jeql	5f
E 22
E 16
	subl2	r2,r5			# update bytes left count
D 16
	addl2	r2,r3			# calculate src+count
#ifdef notdef
	movs3				# copy out next piece
#else
E 16
I 16
	movl	r2,r3			# r3 = saved count
	movl	r0,r1
D 17
# This is a workaround for a microcode bug that causes
# a trap type 9 when cmps3/movs3 touches the last byte
# on a valid page immediately followed by an invalid page.
E 17
I 17
/*
 * This is a workaround for a microcode bug that causes
 * a trap type 9 when cmps3/movs3 touches the last byte
 * on a valid page immediately followed by an invalid page.
 */
E 17
#ifdef good_cmps3
	cmps3				# check for null
E 16
	tstl	r2
D 16
	beql	6f
4:
	movb	(r0),(r1)
	beql	5f
	incl	r0
	incl	r1
	decl	r2
	bneq	4b
	jbr	6f
5:
	incl	r1
E 16
I 16
	jneq	3b
#else
E 16
	decl	r2
I 21
	beql	9f			# cannot handle case of r2 == 0!
E 21
D 16
6:
#endif
	subl3	r0,r3,r2		# null byte found?
	jneq	3b
E 16
I 16
	cmps3				# check for null up to last byte
I 21
9:
E 21
	incl	r2
	cmpl	$1,r2			# get to last byte on page?
	bneq	3b
	tstb	(r0)			# last byte on page null?
D 21
	beql	9f
E 21
I 21
	beql	3b
E 21
	incl	r0			# not null, so bump pointer
D 21
9:
#endif notdef
E 21
I 21
#endif not good_cmps3
E 21
	subl2	r3,r0			# back up r0
	movl	r4,r1
	movl	r3,r2
	movblk				# copy out next piece
	movl	r1,r4
E 16
	movl	$(NBPG*CLSIZE),r2	# check next page
	tstl	r5			# run out of space?
	jneq	1b
	movl	$ENOENT,r0		# set error code and return
D 16
	jbr	9b
E 16
I 16
	jbr	6b
I 22
5:
	clrl	*$0		# this should never execute, if it does
	movl	$EFAULT,r0	#  save me a core dump (mkm - 9/87)
6:
	tstl	16(fp)
	beql	7f
	subl3	r5,12(fp),*16(fp)
7:
	ret
E 22
E 16
E 2

I 22

E 22
D 2
_copyin:	.globl	_copyin		# the _Copyin subroutine in VAX
					# became _copyin procedure for TAHOE
	.word	0x0004
E 2
I 2
/*
 * Copy a null terminated string from one point to another in
 * the kernel address space.
 *
 * copystr(fromaddr, toaddr, maxlength, &lencopied)
 */
D 16
ENTRY(copystr, R3|R4|R5)
	movl	12(fp),r5		# r5 = max length
	jlss	8b
E 16
I 16
ENTRY(copystr, 0)
	movl	12(fp),r3		# r3 = max length
	jlss	5b
E 16
	movl	4(fp),r0		# r0 = src address
D 16
	movl	r0,r3			# r3 = copy of src for null byte test
	movl	8(fp),r1		# r1 = dest address
1:
	movzwl	$65535,r2		# r2 = bytes in first chunk
	cmpl	r5,r2			# r2 = min(bytes in chunk, length left);
	jgeq	2f
	movl	r5,r2
2:
	subl2	r2,r5			# update bytes left count
	addl2	r2,r3			# calculate src+count
	movs3				# copy next piece
	subl3	r0,r3,r2		# null byte found?
E 16
I 16
	movl	8(fp),r4		# r4 = dest address
	clrl	r5			# r5 = bytes left
	movl	r3,r2			# r2 = max bytes to copy
	movl	r0,r1
	cmps3				# check for null
	tstl	r2
E 16
	jneq	3b
D 16
	tstl	r5			# run out of space?
	jneq	1b
E 16
I 16
	subl2	r3,r0			# back up r0
	movl	r4,r1
	movl	r3,r2
	movblk				# copy next piece
E 16
	movl	$ENOENT,r0		# set error code and return
D 16
	jbr	9b
E 16
I 16
	jbr	6b
E 16

/*
 * Copy a block of data from the user address space into
 * the kernel address space.
 *
 * copyin(fromaddr, toaddr, count)
 */
ENTRY(copyin, 0)
E 2
	movl	12(fp),r0		# copy length
D 2
	blss	ersb
E 2
I 2
	blss	9f
E 2
	movl	4(fp),r1		# copy user address
D 2
	cmpl	$NBPG,r0		# probing one page or less ?
	bgeq	cishort			# yes
ciloop:
	prober	$1,(r1),$NBPG		# bytes accessible ?
	beql	ersb			# no
	addl2	$NBPG,r1		# incr user address ptr
	_ACBL	($NBPG+1,$-NBPG,r0,ciloop)	# reduce count and loop
cishort:
E 2
I 2
	cmpl	$(CLSIZE*NBPG),r0	# probing one page or less ?
	bgeq	2f			# yes
1:
	prober	$1,(r1),$(CLSIZE*NBPG)	# bytes accessible ?
	beql	9f			# no
	addl2	$(CLSIZE*NBPG),r1	# incr user address ptr
	_ACBL($(CLSIZE*NBPG+1),$(-CLSIZE*NBPG),r0,1b)	# reduce count and loop
2:
E 2
	prober	$1,(r1),r0		# bytes accessible ?
D 2
	beql	ersb			# no
	MOVC3	(12(fp),4(fp),8(fp))
E 2
I 2
	beql	9f			# no
	MOVC3(4(fp),8(fp),12(fp))
E 2
	clrl	r0
	ret
D 2

ersb:
E 2
I 2
9:
E 2
	movl	$EFAULT,r0
	ret

D 2
_copyout:	.globl	_copyout	# the _Copyout subroutine in VAX
					# became _copyout procedure for TAHOE
	.word	0x04
E 2
I 2
/*
 * Copy a block of data from the kernel 
 * address space to the user address space.
 *
 * copyout(fromaddr, toaddr, count)
 */
ENTRY(copyout, 0)
E 2
	movl	12(fp),r0		# get count
D 2
	blss	ersb
E 2
I 2
	blss	9b
E 2
	movl	8(fp),r1		# get user address
D 2
	cmpl	$NBPG,r0		# can do in one probew?
	bgeq	coshort			# yes
coloop:
	probew	$1,(r1),$NBPG		# bytes accessible?
	beql	ersb			# no 
	addl2	$NBPG,r1		# increment user address
	_ACBL	($NBPG+1,$-NBPG,r0,coloop)	# reduce count and loop
coshort:
E 2
I 2
	cmpl	$(CLSIZE*NBPG),r0	# can do in one probew?
	bgeq	2f			# yes
1:
	probew	$1,(r1),$(CLSIZE*NBPG)	# bytes accessible?
	beql	9b			# no 
	addl2	$(CLSIZE*NBPG),r1	# increment user address
	_ACBL($(CLSIZE*NBPG+1),$(-CLSIZE*NBPG),r0,1b)	# reduce count and loop
2:
E 2
	probew	$1,(r1),r0		# bytes accessible?
D 2
	beql	ersb			# no
	MOVC3	(12(fp),4(fp),8(fp))
E 2
I 2
	beql	9b			# no
	MOVC3(4(fp),8(fp),12(fp))
E 2
	clrl	r0
	ret

/*
 * non-local goto's
 */
D 2
	.globl	_setjmp			# the _Setjmp subroutine in VAX
					# became _setjmp procedure for TAHOE
_setjmp:
	.word	0x0
	movl	4(fp),r2
	storer	$0x1ff8,(r2)
	addl2	$40,r2
	movl	(fp),(r2)
	addl2	$4,r2
	movab	8(fp),(r2)
	addl2	$4,r2
	movl	-8(fp),(r2)
E 2
I 2
#ifdef notdef
ENTRY(setjmp, 0)
	movl	4(fp),r0
	movl	(fp),(r0); addl2 $4,r0		# save fp
	movl	-8(fp),(r0)			# save pc
E 2
	clrl	r0
	ret
I 2
#endif
E 2

D 2
	.globl	_longjmp		# the _Longjmp subroutine in VAX
					# became _longjmp procedure for TAHOE
_longjmp:
	.word	0x0000
	movl	4(fp),r2
_Longjmp:			# called from swtch
	loadr	$0x3ff8,(r2)
	addl2	$44,r2
	movl	(r2),r1
	addl2	$4,r2
	movab	(sp),r0
	cmpl	r1,r0				# must be a pop
	bgequ	lj2
	pushab	lj1
E 2
I 2
ENTRY(longjmp, 0)
	movl	4(fp),r0
	movl	(r0),newfp; addl2 $4,r0		# must save parameters in memory
	movl	(r0),newpc			# as all regs may be clobbered.
1:
	cmpl	fp,newfp			# are we there yet?
	bgequ	2f				# yes
	moval	1b,-8(fp)			# redirect return pc to us!
	ret					# pop next frame
2:
	beql	3f				# did we miss our frame?
	pushab	4f				# yep ?!?
E 2
	callf	$8,_panic
D 2
lj2:
	movl	r1,sp
	jmp	*(r2)
E 2
I 2
3:
	movl	newpc,r0			# all done, just return
	jmp	(r0)				# to setjmp `ret'
E 2

D 2
lj1:	.asciz	"longjmp"
E 2
I 2
	.data
newpc:	.space	4
newfp:	.space	4
4:	.asciz	"longjmp"
I 11
	.text
E 11
E 2

I 2
/*
 * setjmp that saves all registers as the call frame may not
 * be available to recover them in the usual manner by longjmp.
 * Called before swapping out the u. area, restored by resume()
 * below.
 */
ENTRY(savectx, 0)
	movl	4(fp),r2
	storer	$0x1ff8,(r2); addl2 $40,r2	# r3-r12
	movl	(fp),(r2); addl2 $4,r2		# fp
	movab	8(fp),(r2); addl2 $4,r2		# sp
	movl	-8(fp),(r2)			# pc
	clrl	r0
	ret
E 2

I 11
D 29
#ifdef KDB
E 29
I 29
#ifdef KADB
E 29
/*
 * C library -- reset, setexit
 *
 *	reset(x)
 * will generate a "return" from
 * the last call to
 *	setexit()
 * by restoring r2 - r12, fp
 * and doing a return.
 * The returned value is x; on the original
 * call the returned value is 0.
 */
ENTRY(setexit, 0)
	movab	setsav,r0
	storer	$0x1ffc, (r0)
	movl	(fp),44(r0)		# fp
	moval	4(fp),48(r0)		# sp
	movl	-8(fp),52(r0)		# pc
	clrl	r0
	ret

ENTRY(reset, 0)
	movl	4(fp),r0	# returned value
	movab	setsav,r1
	loadr	$0x1ffc,(r1)
	movl	44(r1),fp
	movl	48(r1),sp
	jmp 	*52(r1)

	.data
	.align	2
setsav:	.space	14*4
	.text
#endif

E 11
	.globl	_whichqs
	.globl	_qs
	.globl	_cnt

	.globl	_noproc
	.comm	_noproc,4
	.globl	_runrun
	.comm	_runrun,4
D 2

E 2
/*
 * The following primitives use the fancy TAHOE instructions.
 * _whichqs tells which of the 32 queues _qs
 * have processes in them.  setrq puts processes into queues, remrq
 * removes them from queues.  The running process is on no queue,
 * other processes are on a queue related to p->p_pri, divided by 4
 * actually to shrink the 0-127 range of priorities into the 32 available
 * queues.
 */

/*
 * setrq(p), using fancy TAHOE instructions.
 *
 * Call should be made at spl8(), and p->p_stat should be SRUN
 */
D 2
	.globl	_setrq
_setrq:
	.word	0x4
E 2
I 2
ENTRY(setrq, 0)
E 2
	movl	4(fp),r0
	tstl	P_RLINK(r0)		## firewall: p->p_rlink must be 0
	beql	set1			##
	pushab	set3			##
	callf	$8,_panic		##
set1:
	movzbl	P_PRI(r0),r1		# put on queue which is p->p_pri / 4
	shar	$2,r1,r1
	shal	$1,r1,r2
	moval	_qs[r2],r2
	insque	(r0),*4(r2)		# at end of queue
	shal	r1,$1,r1
	orl2	r1,_whichqs		# mark queue non-empty
	ret

set3:	.asciz	"setrq"

/*
 * remrq(p), using fancy TAHOE instructions
 *
 * Call should be made at spl8().
 */
D 2
	.globl	_remrq
_remrq:
	.word	0x0
E 2
I 2
ENTRY(remrq, 0)
E 2
	movl	4(fp),r0
	movzbl	P_PRI(r0),r1
	shar	$2,r1,r1
	bbs	r1,_whichqs,rem1
	pushab	rem3			# it wasn't recorded to be on its q
	callf	$8,_panic
rem1:
	remque	(r0)
	bneq	rem2			# q not empty yet
	shal	r1,$1,r1
	mcoml	r1,r1
	andl2	r1,_whichqs		# mark queue empty
rem2:
	clrl	P_RLINK(r0)		## for firewall checking
	ret

rem3:	.asciz	"remrq"

D 2
	.globl __insque
__insque:
	.word 0
	insque	*4(fp), *8(fp)
	ret


	.globl __remque
__remque:
	.word 0
	remque	*4(fp)
	ret

E 2
/*
 * Masterpaddr is the p->p_addr of the running process on the master
 * processor.  When a multiprocessor system, the slave processors will have
 * an array of slavepaddr's.
 */
	.globl	_masterpaddr
	.data
I 11
	.align	2
E 11
D 2
_masterpaddr:
	.long	0
E 2
I 2
_masterpaddr: .long	0
E 2

	.text
sw0:	.asciz	"swtch"
I 12

E 12
/*
I 12
 * When no processes are on the runq, swtch branches to idle
 * to wait for something to come ready.
 */
	.globl  Idle
Idle: idle:
I 15
	movl	$1,_noproc
E 15
	mtpr	$0,$IPL			# must allow interrupts here
1:
	tstl	_whichqs		# look for non-empty queue
	bneq	sw1
	brb	1b

badsw:	pushab	sw0
	callf	$8,_panic
	/* NOTREACHED */

	.align	2
/*
E 12
D 2
 * swtch(), using fancy TAHOE instructions
E 2
I 2
 * swtch(), using fancy tahoe instructions
E 2
 */
D 2
	.globl	_swtch
_swtch:
	.word	0x0
E 2
I 2
ENTRY(swtch, 0)
E 2
	movl	(fp),fp			# prepare for rei
	movl	(sp),4(sp)		# saved pc
	tstl	(sp)+
	movpsl	4(sp)
D 15
	movl	$1,_noproc
E 15
D 12
	clrl	_runrun
mtpr0:	mtpr	$0,$IPL			# must allow interrupts here
E 12
I 12
	incl	_cnt+V_SWTCH
E 12
sw1:	ffs	_whichqs,r0		# look for non-empty queue
D 12
	bgeq	sw1a
	brb	sw1			# this is an idle loop!
sw1a:	mtpr	$0x18,$IPL		# lock out all so _whichqs==_qs
	bbc	r0,_whichqs,mtpr0	# proc moved via lbolt interrupt
E 12
I 12
	blss	idle			# if none, idle
	mtpr	$0x18,$IPL		# lock out all so _whichqs==_qs
	bbc	r0,_whichqs,sw1		# proc moved via interrupt
E 12
	shal	$1,r0,r1
	moval	_qs[r1],r1
	movl	(r1),r2			# r2 = p = highest pri process
	remque	*(r1)
D 12
	bvc	sw2			# make sure something was there
sw1b:	pushab	sw0
	callf	$8,_panic
sw2:	bneq	sw3
E 12
I 12
	bvs	badsw			# make sure something was there
	bneq	sw2
E 12
	shal	r0,$1,r1
	mcoml	r1,r1
	andl2	r1,_whichqs		# no more procs in this queue
D 12
sw3:
E 12
I 12
sw2:
E 12
	clrl	_noproc
I 12
	clrl	_runrun
I 15
#ifdef notdef
E 15
E 12
	tstl	P_WCHAN(r2)		## firewalls
D 12
	bneq	sw1b			##
E 12
I 12
	bneq	badsw			##
E 12
D 7
	movzbl	P_STAT(r2),r3		##
	cmpl	$SRUN,r3		##
E 7
I 7
	cmpb	P_STAT(r2),$SRUN	##
E 7
D 12
	bneq	sw1b			##
E 12
I 12
	bneq	badsw			##
I 15
#endif
E 15
E 12
	clrl	P_RLINK(r2)		##
	movl	*P_ADDR(r2),r0
D 12
	movl	r0,_masterpaddr
	shal	$PGSHIFT,r0,r0		# r0 = pcbb(p)
E 12
D 2
/*	mfpr	$PCBB,r1		# resume of current proc is easy
 *	cmpl	r0,r1
 */	beql	res0
E 2
I 2
#ifdef notdef
D 12
	mfpr	$PCBB,r1		# resume of current proc is easy
	cmpl	r0,r1
E 12
I 12
	cmpl	r0,_masterpaddr		# resume of current proc is easy
E 12
	beql	res0
#endif
E 2
D 12
	incl	_cnt+V_SWTCH
E 12
I 12
	movl	r0,_masterpaddr
	shal	$PGSHIFT,r0,r0		# r0 = pcbb(p)
E 12
	brb	swresume
D 2
/* fall into... */
E 2
I 2
D 15
	/* fall into... */
E 15
E 2

D 2
/*
 * global cache key used if cant use proc index as key
 * (e.g. NPROC>=255)
 * otherwise used for temporary storage of key
 */
	.data
	.globl	_globkey
_globkey:
	.long	0
E 2
D 15
	.globl	_prevpcb
D 2
_prevpcb:
	.long	0
E 2
I 2
_prevpcb: .long	0
E 2
	.text
E 15
/*
 * resume(pf)
 */
D 2
	.globl	_resume
_resume:
	.word	0x0
	shal	$PGSHIFT,4(fp),r0	# r0 = pcbb(p)
E 2
I 2
ENTRY(resume, 0)
	shal	$PGSHIFT,4(fp),r0	# r0 = pcbb(pf)
E 2
	movl	(fp),fp			# prepare for rei
	movl	(sp)+,4(sp)		# saved pc
	tstl	(sp)+
	movpsl	4(sp)
swresume:
D 2
	mtpr	$0x18,$IPL			# no interrupts, please
E 2
I 2
	mtpr	$0x18,$IPL		# no interrupts, please
E 2
	movl	_CMAP2,_u+PCB_CMAP2	# yech
	REST_ACC			# restore original accumulator
	svpctx
	mtpr	r0,$PCBB
	ldpctx
	movl	_u+PCB_CMAP2,_CMAP2	# yech
	mtpr	$_CADDR2,$TBIS
res0:
I 2
D 7
	PUSHR;
E 7
	movl	_u+U_PROCP,r2		# r2 = u.u_procp
	tstl	P_CKEY(r2)		# does proc have code key?
	bneq	1f
	callf	$4,_getcodekey		# no, give him one
I 7
	movl	_u+U_PROCP,r2		# r2 = u.u_procp
E 7
	movl	r0,P_CKEY(r2)
1:
D 7
	movl	_u+U_PROCP,r2		# r2 = u.u_procp
E 7
	tstl	P_DKEY(r2)		# does proc have data key?
	bneq	1f
	callf	$4,_getdatakey		# no, give him one
I 7
	movl	_u+U_PROCP,r2		# r2 = u.u_procp
E 7
	movl	r0,P_DKEY(r2)
1:
	mtpr	P_CKEY(r2),$CCK		# set code cache key
	mtpr	P_DKEY(r2),$DCK		# set data cache key
D 7
	POPR
E 7
E 2
	tstl	_u+PCB_SSWAP
D 2
	beql	res1
E 2
I 2
	bneq	res1
	rei
res1:					# longjmp to saved context
E 2
	movl	_u+PCB_SSWAP,r2
	clrl	_u+PCB_SSWAP
D 2
	movab	_Longjmp,(sp)
	clrl	4(sp)			# PSL = kernel mode, IPL=0
res1:
#ifdef GLOBKEY
	aoblss	$256,_globkey,res2	# define new cache key
	mtpr	$0,$PACC		# out of keys, purge all
	mtpr	$0,$PADC
	movl	$1,_globkey
res2:
	mtpr	_globkey,$CCK
#else
res3:
	movzwl	_u+PCB_CKEY,_globkey
	mtpr	_globkey,$CCK
res4:
	movzwl	_u+PCB_DKEY,_globkey
#endif
	mtpr	_globkey,$DCK
E 2
I 2
	loadr	$0x3ff8,(r2); addl2 $44,r2	# restore r3-r13 (r13=fp)
	movl	(r2),r1; addl2 $4,r2	# fetch previous sp ...
	movab	(sp),r0			# ... and current sp and
	cmpl	r1,r0			# check for credibility,
	bgequ	1f			# if further up stack ...
	pushab 2f; callf $8,_panic	# ... panic
	/*NOTREACHED*/
1:					# sp ok, complete return
	movl	r1,sp			# restore sp
D 24
D 26
	movl	(r2),(sp)		# return address
	movl	$PSL_PRVMOD,4(sp)	# kernel mode, ipl 0
E 26
I 26
	pushl	$PSL_PRVMOD		# kernel mode, ipl 0
	pushl	(r2)			# return address
E 26
E 24
I 24
	pushl	$PSL_PRVMOD		# kernel mode, ipl 0
	pushl	(r2)			# return address
E 24
E 2
	rei
I 2
2:	.asciz	"ldctx"
E 2

/*
 * {fu,su},{byte,word}
 */
D 2
	.globl	_fuiword
	.globl	_fuword
_fuiword:
_fuword:
	.word	0x0
E 2
I 2
ENTRY(fuword, 0)
E 2
	movl	4(fp), r1
	prober	$1,(r1),$4		# check access
	beql	fserr			# page unreadable
	bitl	$1,r1			# check byte alignment
	bneq	2f			# odd, do byte-word-byte
	bitl	$2,r1			# check word alignment
	bneq	1f			# odd, do in 2 words
	movl	(r1),r0			# move longword
	ret
1:
	movw	(r1),r0			# move two words
	shal	$16,r0,r0
	movzwl	2(r1),r1		# orw2 sign extends
	orl2	r1,r0
	ret
2:
	movb	(r1),r0			# move byte-word-byte
	shal	$24,r0,r0
	movzwl	1(r1),r2		# orw2 sign extends
	shal	$8,r2,r2
	movzbl	3(r1),r1		# orb2 sign extends
	orl2	r2,r1
	orl2	r1,r0
	ret
fserr:
	mnegl	$1,r0
	ret

D 2
	.globl	_fuibyte
	.globl	_fubyte
_fuibyte:
_fubyte:
	.word	0x0
E 2
I 2
ENTRY(fubyte, 0)
E 2
	prober	$1,*4(fp),$1
	beql	fserr
	movzbl	*4(fp),r0
	ret

D 2
	.globl	_suiword
	.globl	_suword
_suiword:
_suword:
	.word	0x0
E 2
I 2
ENTRY(suword, 0)
E 2
	movl	4(fp), r0
	probew	$1,(r0),$4		# check access
	beql	fserr			# page unwritable
	bitl	$1,r0			# check byte alignment
	bneq	1f			# odd byte boundary
	bitl	$2,r0			# check word alignment
	beql	2f			# longword aligned
	movw	8(fp),(r0)		# move two words
	movw	10(fp),2(r0)
	jbr	3f
1:
	movb	8(fp),(r0)
	movb	9(fp),1(r0)
	movb	10(fp),2(r0)
	movb	11(fp),3(r0)
	jbr	3f
2:
	movl	8(fp),(r0)
3:
	clrl	r0
	ret

D 2
	.globl	_suibyte
	.globl	_subyte
_suibyte:
_subyte:
	.word	0x0
E 2
I 2
ENTRY(subyte, 0)
E 2
	probew	$1,*4(fp),$1
	beql	fserr
	movb	11(fp),*4(fp)
	clrl	r0
	ret

/*
 * Copy 1 relocation unit (NBPG bytes)
 * from user virtual address to physical address
 */
D 2
_copyseg: 	.globl	_copyseg
	.word	0x4
E 2
I 2
ENTRY(copyseg, 0)
E 2
	orl3	$PG_V|PG_KW,8(fp),_CMAP2
	mtpr	$_CADDR2,$TBIS	# invalidate entry for copy 
D 2
	MOVC3	($NBPG,4(fp),$_CADDR2)
E 2
I 2
	MOVC3(4(fp),$_CADDR2,$NBPG)
E 2
	ret

/*
D 2
 * clearseg(physical_page_number);
E 2
I 2
 * Clear a page of memory.  The page frame is specified.
E 2
 *
D 2
 * zero out physical memory
 * specified in relocation units (NBPG bytes)
 * This routine was optimized for speed on Tahoe.
E 2
I 2
 * clearseg(pf);
E 2
 */
D 2
_clearseg: 	.globl	_clearseg
	.word	0
E 2
I 2
ENTRY(clearseg, 0)
E 2
	orl3	$PG_V|PG_KW,4(fp),_CMAP1	# Maps to virtual addr CADDR1
	mtpr	$_CADDR1,$TBIS
	movl	$255,r0				# r0 = limit
	clrl	r1				# r1 = index of cleared long
1:
	clrl	_CADDR1[r1]
	aobleq	r0,r1,1b
	ret

/*
D 2
 * if ( useracc(address, count, mode) ) ....
 * Check address.
 * Given virtual address, byte count, and rw flag
 * returns 0 on no access.
 * Note : it is assumed that on all calls to this routine,
 *  mode=0 means write access, mode=1 means read access.
E 2
I 2
 * Check user mode read/write access.
 *
 * useracc(addr, count, mode)
 *	caddr_t addr; int count, mode;
 * mode = 0	write access
 * mode = 1	read access
E 2
 */
D 2
_useracc:	.globl	_useracc
	.word	0x4
E 2
I 2
ENTRY(useracc, 0)
E 2
	movl	$1,r2			# r2 = 'user mode' for probew/probew
probes:
	movl	4(fp),r0		# get va
	movl	8(fp),r1		# count
	tstl	12(fp)			# test for read access ?
	bneq	userar			# yes
D 2
	cmpl	$NBPG,r1			# can we do it in one probe ?
E 2
I 2
	cmpl	$(CLSIZE*NBPG),r1	# can we do it in one probe ?
E 2
	bgeq	uaw2			# yes
uaw1:
D 2
	probew	r2,(r0),$NBPG
E 2
I 2
	probew	r2,(r0),$(CLSIZE*NBPG)
E 2
	beql	uaerr			# no access
D 2
	addl2	$NBPG,r0
	_ACBL($NBPG+1,$-NBPG,r1,uaw1)
E 2
I 2
	addl2	$(CLSIZE*NBPG),r0
	_ACBL($(CLSIZE*NBPG+1),$(-CLSIZE*NBPG),r1,uaw1)
E 2
uaw2:
	probew	r2,(r0),r1
	beql	uaerr
	movl	$1,r0
	ret
D 2

E 2
userar:
D 2
	cmpl	$NBPG,r1
E 2
I 2
	cmpl	$(CLSIZE*NBPG),r1
E 2
	bgeq	uar2
uar1:
D 2
	prober	r2,(r0),$NBPG
E 2
I 2
	prober	r2,(r0),$(CLSIZE*NBPG)
E 2
	beql	uaerr
D 2
	addl2	$NBPG,r0
	_ACBL($NBPG+1,$-NBPG,r1,uar1)
E 2
I 2
	addl2	$(CLSIZE*NBPG),r0
	_ACBL($(CLSIZE*NBPG+1),$(-CLSIZE*NBPG),r1,uar1)
E 2
uar2:
	prober	r2,(r0),r1
	beql	uaerr
	movl	$1,r0
	ret
uaerr:
	clrl	r0
	ret

/*
D 2
 * if ( kernacc(address, count, mode) ) ....
 * Check address.
 * Given virtual address, byte count, and rw flag
 * returns 0 on no access.
 * Same as useracc routine but checks for kernel access rights.
E 2
I 2
 * Check kernel mode read/write access.
 *
 * kernacc(addr, count, mode)
 *	caddr_t addr; int count, mode;
 * mode = 0	write access
 * mode = 1	read access
E 2
 */
D 2

_kernacc:	.globl	_kernacc
	.word	0x4
E 2
I 2
ENTRY(kernacc, 0)
E 2
	clrl	r2		# r2 = 0 means kernel mode probe.
	jbr	probes		# Dijkstra would get gastric distress here.

/*
 * addupc - increment some histogram counter
 *	in the profiling buffer
 *
D 2
 * addupc(pc, prof, counts)
 * long	pc , counts;	Only least significant word of 'counts' is added.
 * struct	uprof *prof;
E 2
I 2
 * addupc(pc, prof, delta)
 *	long pc; short delta; struct uprof *prof;
E 2
 * 
 * struct uprof {		# profile arguments 
 * 	short	*r_base;	# buffer base 
 * 	unsigned pr_size;	# buffer size 
 * 	unsigned pr_off;	# pc offset 
 * 	unsigned pr_scale;	# pc scaling 
 * }
 */
D 2
	.globl	_addupc
_addupc:
	.word	4
	movl	8(fp),r2	# r2 points to structure
	subl3	8(r2),4(fp),r0	# r0 = PC - lowpc
	jlss	9f		# PC < lowpc , out of range !
	shrl	$1,r0,r0	# the unit is words
	shrl	$1,12(r2),r1	# ditto for scale
E 2
I 2
ENTRY(addupc, 0)
	movl	8(fp),r2		# r2 points to structure
	subl3	8(r2),4(fp),r0		# r0 = PC - lowpc
	jlss	9f			# PC < lowpc , out of range !
	shrl	$1,r0,r0		# the unit is words
	shrl	$1,12(r2),r1		# ditto for scale
E 2
	emul	r1,r0,$0,r0
	shrq	$14,r0,r0
D 2
	tstl	r0		# too big
E 2
I 2
	tstl	r0			# too big
E 2
	jneq	9f
D 2
	cmpl	r1,4(r2)	# Check buffer overflow
E 2
I 2
	cmpl	r1,4(r2)		# Check buffer overflow
E 2
	jgequ	9f
	probew	$1,*0(r2)[r1],$2	# counter accessible?
	jeql	9f
D 2
	shrl	$1,r1,r1	# make r1 word index
E 2
I 2
	shrl	$1,r1,r1		# make r1 word index
E 2
	addw2	14(fp),*0(r2)[r1]
9:	ret
I 2

/*
 * scanc(size, cp, table, mask)
 */
ENTRY(scanc, R3|R4)
	movl	8(fp),r0		# r0 = cp
	addl3	4(fp),r0,r2		# end = &cp[size]
	movl	12(fp),r1		# r1 = table
	movb	19(fp),r4		# r4 = mask
	decl	r0			# --cp
	jbr	0f			# just like Fortran...
1:					# do {
	movzbl	(r0),r3	
	bitb	r4,(r1)[r3]		#	if (table[*cp] & mask)
	jneq	2f			#		break;
0:	aoblss	r2,r0,1b		# } while (++cp < end);
2:
	subl3	r0,r2,r0; ret		# return (end - cp);

/*
 * skpc(mask, size, cp)
 */
ENTRY(skpc, 0)
	movl	12(fp),r0		# r0 = cp
	addl3	8(fp),r0,r1		# r1 = end = &cp[size];
	movb	7(fp),r2		# r2 = mask
	decl	r0			# --cp;
	jbr	0f
1:					# do
	cmpb	(r0),r2			#	if (*cp != mask)
	jneq	2f			#		break;
0:	aoblss	r1,r0,1b		# while (++cp < end);
2:
	subl3	r0,r1,r0; ret		# return (end - cp);

D 22
#ifdef notdef
E 22
/*
 * locc(mask, size, cp)
 */
ENTRY(locc, 0)
	movl	12(fp),r0		# r0 = cp
	addl3	8(fp),r0,r1		# r1 = end = &cp[size]
	movb	7(fp),r2		# r2 = mask
	decl	r0			# --cp;
	jbr	0f
1:					# do
	cmpb	(r0),r2			#	if (*cp == mask)
	jeql	2f			#		break;
0:	aoblss	r1,r0,1b		# while (++cp < end);
2:
	subl3	r0,r1,r0; ret		# return (end - cp);
I 9
D 22
#endif
E 22

D 10
#if NALIGN > 0

E 10
I 10
#ifdef ALIGN
E 10
#include "../tahoealign/align.h"

	.globl	_alignment
/*
 * There's an intimate relationship between this piece of code
 * and the alignment emulation code (especially the layout
 * of local variables in alignment.c! Don't change unless
 * you update both this, alignment.h and alignment.c !!
 */
non_aligned:
	orb2	$EMULATEALIGN,_u+U_EOSYS
	incl	_cnt+V_TRAP
	incl	_cnt+V_ALIGN		# count emulated alignment traps
	moval	4(sp),_user_psl
	SAVE_FPSTAT(4)			# Also zeroes out ret_exception !
	pushl	$0			# ret_addr
	pushl	$0			# ret_code
	mfpr	$USP,-(sp)		# user sp
	callf	$4,_alignment		# call w/o parms so regs may be modified
	/*
	 * We return here after a successful emulation or an exception.
	 * The registers have been restored and we must not alter them
	 * before returning to the user.
	 */
2:	mtpr	(sp)+,$USP		# restore user sp
	tstl	8(sp)			# Any exception ?
	bneq	got_excp		# Yes, reflect it back to user.
	moval	8(sp),sp		# pop 2 zeroes pushed above
	REST_FPSTAT
	xorb2	$EMULATEALIGN,_u+U_EOSYS

	bitl	$PSL_T,4(sp)		# check for trace bit set
	beql	9f
	CHECK_SFE(4)
	pushl $0
	SAVE_FPSTAT(8)
	TRAP(TRCTRAP)
9:	rei

got_excp:				# decode exception
	casel	8(sp),$ILL_ADDRMOD,$ALIGNMENT
	.align	1
L1:
	.word	ill_addrmod-L1
	.word	ill_access-L1
	.word	ill_oprnd-L1
	.word	arithmetic-L1
	.word	alignment-L1
	brw	alignment		# default - shouldn't come here at all !

ill_addrmod:				# No other parameters. Set up stack as
	moval	8(sp),sp		# the HW would do it in a real case.
	REST_FPSTAT
	jbr	_Xresadflt
ill_oprnd:
	moval	8(sp),sp
	REST_FPSTAT
	jbr	_Xresopflt
alignment:
	moval	8(sp),sp
	REST_FPSTAT
	jbr	align_excp	# NB: going to _Xalignflt would cause loop
ill_access:
	/*
	 * Must restore accumulator w/o modifying sp and w/o using
	 * registers.  Solution: copy things needed by REST_FPSTAT.
	 */
	pushl	20(sp)			# The flags longword
	pushl	20(sp)			# acc_low
	pushl	20(sp)			# acc_high
	pushl	20(sp)			# ret_exception ignored by REST_FPSTAT 
	REST_FPSTAT			# Back where we were with the sp !
	movl	(sp),16(sp)		# code for illegal access
	movl	4(sp),20(sp)		# original virtual address
	moval	16(sp),sp		# Just like the HW would set it up
	jbr	_Xprotflt
arithmetic:				# same trickery as above
	pushl	20(sp)			# The flags longword
	pushl	20(sp)			# acc_low
	pushl	20(sp)			# acc_high
	pushl	20(sp)			# ret_exception ignored by REST_FPSTAT 
	REST_FPSTAT			# Back where we were with the sp !
	movl	(sp),20(sp)		# code for arithmetic exception
	moval	20(sp),sp		# Just like the HW would set it up
	jbr	_Xarithtrap
E 9
#endif
E 2
E 1
