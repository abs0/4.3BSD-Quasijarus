h00875
s 00313/00000/00000
d D 7.1 04/02/03 10:51:28 msokolov 1 0
c kernel builds with F-float emulator
e
u
U
t
T
I 1
/*
 * Floating point instruction emulator
 * Designed and written by Michael Sokolov
 *
 * This module contains the emulator core.
 * Other modules implement F, D, G and H formats and instruction sets.
 *
 *	%W% (Berkeley) %G%
 */

#include "../vax/cpucond.h"
#if EMULFFLT || EMULDFLT || EMULGFLT || EMULHFLT
#define	LOCORE
#include "assym.s"
#include "syscall.h"
#include "signal.h"
#include "../vax/trap.h"
#include "../vax/psl.h"
#define	PANIC(msg)	pushab 0f; calls $1,_panic; 0: .asciz msg

/*
 * Design:
 *
 * We run in the mode of the program we are emulating instructions for, user or
 * kernel.  We do not probe memory operands for accessibility, thus if any of
 * them is an invalid address, faults will occur in the same mode emulator code
 * and will be signaled as such to the process.  The same goes for opcode bytes
 * after the first (operand specifiers) as we decode them ourselves.  All other
 * instruction exceptions prescribed by VARM are properly emulated with the
 * sigemu syscall.  Floating overflow, divide by zero, and underflow are faults
 * like in new VAXen.  On these faults and on the reserved operand fault we back
 * up the instruction and deliver the fault with sigemu.  The only instructions
 * suspended with FPD are POLYx.
 *
 * Kernel code can use emulated instructions just as well as user code.  SCB is
 * set up very early and this emulator is available from the beginning.  When an
 * emulated instruction in the kernel catches a reserved operand or reserved
 * addressing mode fault, on a floating overflow, or when a DIV divides by zero
 * we panic with an appropriate message.  (For user code these are emulated with
 * sigemu.)  IV and FU are ignored for in-kernel emulation (treated as if they
 * were always zero).  Finally, storing to SP causes a panic in the kernel.  (In
 * user mode it is emulated with sigreturn.)
 *
 * We run with the following frame on the stack, and return with RET.  The
 * reason why we return with RET instead of the more usual REI and why the frame
 * looks so unusual is because the emulated instructions can easily change SP,
 * and not because the user is monkeying around by storing floats in SP, but
 * because of perfectly reasonable operands like (SP)+ or -(SP).  And of course
 * the user can decide to store a float in SP too (think VAX validator).  REI in
 * same mode cannot restore SP atomically with PC and PSL.  We can do it with
 * sigreturn, but it is not an acceptable solution since it's too slow for
 * general use and it doesn't work for the kernel, which should be able to use
 * float instructions with operands like (SP)+ and -(SP).  Instead we use RET.
 * We take advantage of the fact that SP autoincrements and autodecrements can
 * change SP only by a small amount.  We leave some slack under the RET frame,
 * and emulated SP changes eat up or grow this slack.  The slack, whether grown,
 * shrunk or unchanged is popped off by the RET as we make it look like a CALLS
 * arglist plus SP alignment.  This mechanism can only make limited adjustments
 * to SP.  If the user stores a number directly into SP with a .wx operand, we
 * flag it and return via sigreturn later.  (In the kernel this is not allowed
 * and produces a panic.)
 *
 *		+---------------------------------------------+
 * FP ->	|  frame word for condition handler (unused)  |
 *		+----------------------+----------------------+
 * FP + 04	|SPA|1|X| mask = 12 1s |       user PSW       |
 *		+----------------------+----------------------+
 * FP + 08	|      AP will be moved here before RET       |
 *		+---------------------------------------------+
 * FP + 0C	|      FP will be moved here before RET       |
 *		+---------------------------------------------+
 * FP + 10	|                  return PC                  |
 *		+---------------------------------------------+
 * FP + 14	|                 regfile R0                  |
 *		|                      .                      |
 *		|                      .                      |
 * FP + 3C	|                 regfile R10                 |
 * FP + 40	|                 regfile R11                 |
 * FP + 44	|                 regfile AP                  |
 * FP + 48	|                 regfile FP                  |
 * FP + 4C	|                 regfile SP                  |
 *		+---------------------------------------------+
 * FP + 50	|               instruction PC                |
 *		+---------------------------------------------+
 * FP + 54	|              struct sigcontext              |
 *		|     in case we need sigreturn or sigemu     |
 *		|                 7 longwords                 |
 *		+---------------------------------------------+
 * FP + 70	|                    slack                    |
 *		|                 8 longwords                 |
 * FP + 90	+---------------------------------------------+
 *		|          0 to 3 bytes of alignment          |
 * original SP->+---------------------------------------------+
 *
 * X bit near the top is set if we need to return via sigreturn instead of RET.
 * It is set by the operand processing code if a .wx or .mx operand writes into
 * SP.  It is an MBZ bit for RET, thus we are not interfering with anything we
 * will ever set for RET, and we are NOT actually violating the MBZ since it's
 * an MBZ for RET and we don't do the RET if it's set.
 *
 * This frame is always addressed relative to FP.  Code can allocate work space
 * on the stack over the frame by subtracting from SP.
 *
 * We operate on floating point data in expanded form taking up 3 registers.
 * One register holds the exponent in bits <7:0> and the sign in bit 8 (the rest
 * are zero).  Two registers hold the expanded 64-bit mantissa (for D-float, the
 * low half is omitted for F-float).  It is expanded into canonical form with
 * the high (hidden) bit in the MSB, followed by 23 or 55 mantissa bits stored
 * in the architectured floating datum and 8 extra precision bits for extensions
 * and guard bits.
 */

	.text
	.globl	_Emulate_instr
	.align	2
_Emulate_instr:
/*
 * The emulator is entered with:
 *
 *	  (sp) - saved user's R0
 *	 4(sp) - saved user's R1
 *	 8(sp) - free longword
 *	12(sp) - exception PC
 *	16(sp) - exception PSL
 *	20(sp) - top of user's stack at the instruction
 *
 * R0 = pointer to the instruction specific emulation routine
 * R1 = SP
 *
 * All other registers are user's.
 *
 * We need to first convert this into the frame described above.  We first
 * longword-align SP.  Then we subtract 10 longwords.  In the desired frame
 * there are 15 reserved longwords (8 for slack + 7 for possible sigcontext)
 * under the first pushed longword (instruction PC).  In the frame we started
 * with there are 5 longwords on the stack.  Thus we need subtract 10 longwords
 * (40 bytes) from SP.  Then we push the rest of the frame.
 */
	bicl2	$3,sp				/* longword alignment */
	subl2	$40,sp
	movl	12(r1),-(sp)			/* instruction PC */
	addl3	r1,$20,-(sp)			/* user SP, init regfile SP */
	pushr	0x3FFC				/* bulk of regfile, but... */
	movq	(r1),-(sp)			/* R0 and R1 special */
	subl2	$20,sp				/* top 5 longs of frame */
	movl	sp,fp
	movw	16(r1),4(fp)			/* PSW */
	movw	$0x2FFF,6(fp)
/* frame is complete */
	jmp	(r0)				/* jump to emulation routine */

/* Various exit paths */

	.globl	_EMF_normal_return
	.align	2
_EMF_normal_return:
	bitl	$0x10000000|PSL_T,4(fp)
	jneq	_EMF_sigreturn
	movq	0x44(fp),0x08(fp)
	moval	0x48(fp),r0
	subl3	r0,0x4C(fp),r1
	extzv	$0,$2,r1,r2
	insv	r2,$30,$2,4(fp)
	moval	0x44(fp),r0
	addl2	r2,r0
	ashl	$-2,r1,(r0)
	ret

	.globl	_EMF_sigreturn
_EMF_sigreturn:
	jsb	_EMF_prep_sigcontext
	movl	0x10(fp),0x68(fp)
	bitw	$PSL_T,4(fp)
	beql	1f
	bisl2	$PSL_TP,0x6C(fp)
1:	movl	$1,0x44(fp)		# arglist for sigreturn
	moval	0x54(fp),0x48(fp)
	moval	0x14(fp),sp
	popr	$0x0FFF
	movl	sp,ap
	chmk	$SYS_sigreturn
	halt				# in case sigreturn failed

	.globl	_EMF_check_integer_overflow
	.globl	_EMF_integer_overflow_return
	.align	2
_EMF_check_integer_overflow:
	bitw	$PSL_V,4(fp)
	jeql	_EMF_normal_return
_EMF_integer_overflow_return:
	bitw	$PSL_IV,4(fp)
	jeql	_EMF_normal_return
	movpsl	r0
	bitl	$PSL_CURMOD,r0
	jeql	_EMF_normal_return
	jsb	_EMF_prep_sigcontext
	movl	0x10(fp),0x68(fp)
	bitw	$PSL_T,4(fp)
	beql	1f
	bisl2	$PSL_TP,0x6C(fp)
1:	movl	$SIGFPE,0x4C(fp)
	movl	$FPE_INTOVF_TRAP,0x50(fp)
	jbr	_EMF_sigemu

	.globl	_EMF_reserved_operand_fault
_EMF_reserved_operand_fault:
	movpsl	r0
	bitl	$PSL_CURMOD,r0
	jneq	1f
	PANIC("floating point reserved operand in kernel")
1:	jsb	_EMF_operand_backup
	jsb	_EMF_prep_sigcontext
	movl	0x50(fp),0x68(fp)
	movl	$SIGILL,0x4C(fp)
	movl	$T_RESOPFLT,0x50(fp)
	jbr	_EMF_sigemu

	.globl	_EMF_reserved_operand_fpd
_EMF_reserved_operand_fpd:
	movpsl	r0
	bitl	$PSL_CURMOD,r0
	jneq	1f
	PANIC("POLYx reserved operand in kernel")
1:	jsb	_EMF_prep_sigcontext
	movl	0x50(fp),0x68(fp)
	bisl2	$PSL_FPD,0x6C(fp)
	movl	$SIGILL,0x4C(fp)
	movl	$T_RESOPFLT,0x50(fp)
	jbr	_EMF_sigemu

	.globl	_EMF_floating_overflow_fault
_EMF_floating_overflow_fault:
	movpsl	r0
	bitl	$PSL_CURMOD,r0
	jneq	1f
	PANIC("emulated floating overflow fault in kernel")
1:	jsb	_EMF_operand_backup
	jsb	_EMF_prep_sigcontext
	movl	0x50(fp),0x68(fp)
	movl	$SIGFPE,0x4C(fp)
	movl	$FPE_FLTOVF_FAULT,0x50(fp)
	jbr	_EMF_sigemu

	.globl	_EMF_floating_overflow_fpd
_EMF_floating_overflow_fpd:
	movpsl	r0
	bitl	$PSL_CURMOD,r0
	jneq	1f
	PANIC("emulated POLYx floating overflow fault in kernel")
1:	jsb	_EMF_prep_sigcontext
	movl	0x50(fp),0x68(fp)
	bisl2	$PSL_FPD,0x6C(fp)
	movl	$SIGFPE,0x4C(fp)
	movl	$FPE_FLTOVF_FAULT,0x50(fp)
	jbr	_EMF_sigemu

	.globl	_EMF_floating_divby0_fault
_EMF_floating_divby0_fault:
	movpsl	r0
	bitl	$PSL_CURMOD,r0
	jneq	1f
	PANIC("emulated floating divide by 0 fault in kernel")
1:	jsb	_EMF_operand_backup
	jsb	_EMF_prep_sigcontext
	movl	0x50(fp),0x68(fp)
	movl	$SIGFPE,0x4C(fp)
	movl	$FPE_FLTDIV_FAULT,0x50(fp)
	jbr	_EMF_sigemu

	.globl	_EMF_floating_underflow_fault
_EMF_floating_underflow_fault:
	jsb	_EMF_operand_backup
	jsb	_EMF_prep_sigcontext
	movl	0x50(fp),0x68(fp)
	movl	$SIGFPE,0x4C(fp)
	movl	$FPE_FLTUND_FAULT,0x50(fp)
	jbr	_EMF_sigemu

	.globl	_EMF_floating_underflow_fpd
_EMF_floating_underflow_fpd:
	jsb	_EMF_prep_sigcontext
	movl	0x50(fp),0x68(fp)
	bisl2	$PSL_FPD,0x6C(fp)
	movl	$SIGFPE,0x4C(fp)
	movl	$FPE_FLTUND_FAULT,0x50(fp)
	jbr	_EMF_sigemu

	.globl	_EMF_sigemu
_EMF_sigemu:
	movl	$3,0x44(fp)		# arglist for sigemu
	moval	0x54(fp),0x48(fp)
	moval	0x14(fp),sp
	popr	$0x0FFF
	movl	sp,ap
	chmk	$SYS_sigemu
	halt				# in case sigemu failed

	.globl	_EMF_prep_sigcontext
_EMF_prep_sigcontext:
	movl	0x4C(fp),0x5C(fp)	# SP
	movl	0x48(fp),0x60(fp)	# FP
	movl	0x44(fp),0x64(fp)	# AP
	movzwl	4(fp),0x6C(fp)		# PSW -> PSL
	bisl2	$PSL_USERSET,0x6C(fp)
	moval	sigblock_arglist,ap	# sigblock(0) to get current mask
	chmk	$SYS_sigblock
	movl	r0,0x58(fp)		# sigcontext.sc_mask
	movl	_u+U_ONSTACK,0x54(fp)	# sigcontext.sc_onstack
	rsb
sigblock_arglist:
	.long	1,0

#endif
E 1
