h44654
s 00001/00001/00190
d D 7.4 04/02/03 11:13:04 msokolov 4 3
c fix PANIC macro to use 0: instead of 1: to reduce interference
e
s 00008/00003/00183
d D 7.3 04/01/27 21:37:38 msokolov 3 2
c CMPC3, CMPC5, LOCC, SKPC, SCANC, SPANC are now in base subset
c emulation needed only on MV II
e
s 00010/00003/00176
d D 7.2 04/01/12 20:49:41 msokolov 2 1
c faults clear TP per VARM
c correct comment about kernel use of the emulator
e
s 00179/00000/00000
d D 7.1 04/01/11 11:26:30 msokolov 1 0
c date and time created 04/01/11 11:26:30 by msokolov
e
u
U
t
T
I 1
/*
 * Same mode emulator for character string, CRC, decimal string, and EDITPC
 * instructions.  This module contains the same-mode emulation exception vectors
 * and the dispatcher.  Actual instruction emulation is implemented in other
 * modules.
 *
 *	%W% (Berkeley) %G%
 */

#include "../vax/cpucond.h"
#ifdef NEED_SAMEMODE_EMU
#define	LOCORE
#include "assym.s"
#include "syscall.h"
#include "signal.h"
#include "../vax/trap.h"
#include "../vax/psl.h"

/*
 * Design:
 *
 * We do not probe memory operands for accessibility, thus if any of them is an
 * invalid address, faults will occur in the same mode emulator code and will be
 * signaled as such to the process.  All other instruction exceptions prescribed
 * by VARM are properly emulated with the sigemu syscall.  Since we do not
 * emulate access control violation faults, the only time we need to suspend an
 * emulated instruction with FPD is on a reserved operand fault in the middle of
 * EDITPC.  Thus EDITPC is the only instruction for which we provide FPD
 * support.
 *
D 2
 * Kernel code is allowed to use emulated character string and crc instructions
 * (though inline expansion is preferred for performance), but not decimal
 * string instructions or EDITPC.
E 2
I 2
 * Kernel code can use emulated instructions just as well as user code.  SCB is
 * set up very early and this emulator is available from the beginning.  When an
 * emulated instruction in the kernel catches a reserved operand or reserved
 * addressing mode (CVTPL to PC) fault/abort, or when a DIVP divides by zero we
 * panic with an appropriate message.  (For user code these are emulated with
 * sigemu.)  IV and DV are ignored for in-kernel emulation (treated as if they
 * were always zero).  Finally, CVTPL to SP causes a panic in the kernel.  (In
 * user mode it is emulated with sigreturn.)
E 2
 */

/*
 * Emulation OpCode jump table:
 *	ONLY GOES FROM 0xf8 (-8) TO 0x3B (59)
 */
#define EMUTABLE	0x43
#define NOEMULATE	.long noemulate
#define	EMULATE(a)	.long _EM/**/a
I 3
#ifdef NEED_UV2_SUPPORT
#define	EMULUV2(a)	.long _EM/**/a
#else
#define	EMULUV2(a)	.long noemulate
#endif
E 3
	.text
	.globl	_emJUMPtable
_emJUMPtable:
/* f8 */	EMULATE(ashp);	EMULATE(cvtlp);	NOEMULATE;	NOEMULATE
/* fc */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 00 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 04 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 08 */	EMULATE(cvtps);	EMULATE(cvtsp);	NOEMULATE;	EMULATE(crc)
/* 0c */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 10 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 14 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 18 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 1c */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 20 */	EMULATE(addp4);	EMULATE(addp6);	EMULATE(subp4);	EMULATE(subp6)
/* 24 */	EMULATE(cvtpt);	EMULATE(mulp);	EMULATE(cvttp);	EMULATE(divp)
D 3
/* 28 */	NOEMULATE;	EMULATE(cmpc3);	EMULATE(scanc);	EMULATE(spanc)
/* 2c */	NOEMULATE;	EMULATE(cmpc5);	EMULATE(movtc);	EMULATE(movtuc)
E 3
I 3
/* 28 */	NOEMULATE;	EMULUV2(cmpc3);	EMULUV2(scanc);	EMULUV2(spanc)
/* 2c */	NOEMULATE;	EMULUV2(cmpc5);	EMULATE(movtc);	EMULATE(movtuc)
E 3
/* 30 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 34 */	EMULATE(movp);	EMULATE(cmpp3);	EMULATE(cvtpl);	EMULATE(cmpp4)
D 3
/* 38 */	EMULATE(editpc); EMULATE(matchc); EMULATE(locc); EMULATE(skpc)
E 3
I 3
/* 38 */	EMULATE(editpc); EMULATE(matchc); EMULUV2(locc); EMULUV2(skpc)
E 3

#define	SCBVEC(name)	.align 2; .globl _X/**/name; _X/**/name
D 4
#define	PANIC(msg)	pushab 1f; calls $1,_panic; 1: .asciz msg
E 4
I 4
#define	PANIC(msg)	pushab 0f; calls $1,_panic; 0: .asciz msg
E 4

/*
 * The following is called with the stack set up as follows:
 *
 *	  (sp):	Opcode
 *	 4(sp):	Instruction PC
 *	 8(sp):	Operand 1
 *	12(sp):	Operand 2
 *	16(sp):	Operand 3
 *	20(sp):	Operand 4
 *	24(sp):	Operand 5
 *	28(sp):	Operand 6
 *	32(sp):	Operand 7 (unused)
 *	36(sp):	Operand 8 (unused)
 *	40(sp):	Return PC
 *	44(sp):	Return PSL
 *	48(sp): TOS before instruction
 *
 * Each individual routine is called with the stack set up as follows:
 *
 *	  (sp):	Return address of trap handler
 *	 4(sp):	Opcode (will get return PSL)
 *	 8(sp):	Instruction PC
 *	12(sp):	Operand 1
 *	16(sp):	Operand 2
 *	20(sp):	Operand 3
 *	24(sp):	Operand 4
 *	28(sp):	Operand 5
 *	32(sp):	Operand 6
 *	36(sp):	saved register 11
 *	40(sp):	saved register 10
 *	44(sp):	Return PC
 *	48(sp):	Return PSL
 *	52(sp): TOS before instruction
 */

SCBVEC(emulate):
	movl	r11,32(sp)		# save register r11 in unused operand
	movl	r10,36(sp)		# save register r10 in unused operand
	cvtbl	(sp),r10		# get opcode
	addl2	$8,r10			# shift negative opcodes
	subl3	r10,$EMUTABLE,r11	# forget it if opcode is out of range
	bcs	1f
	movl	_emJUMPtable[r10],r10	# call appropriate emulation routine
	jsb	(r10)		# routines put return values into regs 0-5
emreturn:
	movl	32(sp),r11		# restore register r11
	movl	36(sp),r10		# restore register r10
	insv	(sp),$0,$4,44(sp)	# and condition codes in Opcode spot
	addl2	$40,sp			# adjust stack for return
	rei
noemulate:
	addl2	$4,sp			# pop return address from jsb
1:	movpsl	r10
	bitl	$PSL_CURMOD,r10
	bneq	signal_reserved_instr
	PANIC("emulate");
/* turn it into a reserved instruction fault (SIGILL) */
signal_reserved_instr:
	movl	4(sp),40(sp)		# fault
I 2
	bicl2	$PSL_TP,44(sp)		# faults clear TP per VARM
E 2
	movl	$SIGILL,8(sp)
	movl	$T_PRIVINFLT,12(sp)
	jbr	_EM_signal_exception

SCBVEC(emulateFPD):
	bitl	$PSL_CURMOD,4(sp)
	bneq	1f
	PANIC("emulateFPD");
1:	subl2	$48,sp
	movl	r11,32(sp)		# save register r11 in unused operand
	movl	r10,36(sp)		# save register r10 in unused operand
	movl	40(sp),r10
	movl	r10,4(sp)
	cmpb	$0x38,(r10)		# EDITPC is the only instruction we FPD
	bneq	signal_reserved_instr
	extzv	$16,$8,r2,r11
	addl3	r11,r10,40(sp)
	bicl2	$PSL_FPD,44(sp)
	pushab	emreturn
	jmp	_EM_editpc_restart

	.globl	_EM_signal_exception
_EM_signal_exception:
	movl	32(sp),r11		# restore r11
	movl	36(sp),r10		# restore r10
	movl	r0,16(sp)		# r0 will be our scratch reg now
	movl	ap,36(sp)		# sigcontext.sc_ap
	movl	fp,32(sp)		# sigcontext.sc_fp
	addl3	$48,sp,28(sp)		# sigcontext.sc_sp
	moval	sigblock_arglist,ap	# sigblock(0) to get current mask
	chmk	$SYS_sigblock
	movl	r0,24(sp)		# sigcontext.sc_mask
	movl	_u+U_ONSTACK,20(sp)	# sigcontext.sc_onstack
	movl	16(sp),r0
	movl	$3,(sp)			# arglist for sigemu
	moval	20(sp),4(sp)
	movl	sp,ap
	chmk	$SYS_sigemu
	halt				# in case sigemu failed
sigblock_arglist:
	.long	1,0

	.globl	_EM_reserved_operand
_EM_reserved_operand:
	addl2	$4,sp			# pop jsb return address
	movpsl	r10
	bitl	$PSL_CURMOD,r10
	beql	1f
	movl	4(sp),40(sp)		# fault
I 2
	bicl2	$PSL_TP,44(sp)		# faults clear TP per VARM
E 2
	movl	$SIGILL,8(sp)
	movl	$T_RESOPFLT,12(sp)
	jbr	_EM_signal_exception
1:	PANIC("decimal instruction in kernel reserved operand")
#endif
E 1
