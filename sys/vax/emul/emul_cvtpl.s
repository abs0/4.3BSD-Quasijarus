/*
 * VAX CVTPL instruction emulation
 * Ported from DEC Ultrix to 4.3BSD-Quasijarus by Michael Sokolov
 *
 *	@(#)emul_cvtpl.s	7.3 (Berkeley) 2/3/04
 */

#include "../vax/cpucond.h"
#ifdef NEED_SAMEMODE_EMU

#define	LOCORE
#include "assym.s"
#include "syscall.h"
#include "signal.h"
#include "../vax/trap.h"
#include "../vax/psl.h"
#define	PANIC(msg)	pushab 0f; calls $1,_panic; 0: .asciz msg

/************************************************************************
 *									*
 *			Copyright (c) 1984 by				*
 *		Digital Equipment Corporation, Maynard, MA		*
 *			All rights reserved.				*
 *									*
 *   This software is furnished under a license and may be used and	*
 *   copied  only  in accordance with the terms of such license and	*
 *   with the  inclusion  of  the  above  copyright  notice.   This	*
 *   software  or  any  other copies thereof may not be provided or	*
 *   otherwise made available to any other person.  No title to and	*
 *   ownership of the software is hereby transferred.			*
 *									*
 *   The information in this software is subject to change  without	*
 *   notice  and should not be construed as a commitment by Digital	*
 *   Equipment Corporation.						*
 *									*
 *   Digital assumes no responsibility for the use  or  reliability	*
 *   of its software on equipment which is not supplied by Digital.	*
 *									*
 ************************************************************************/

/************************************************************************
 *
 *			Modification History
 *
 *	Stephen Reilly, 20-Mar-84
 * 000- This code is the modification of the VMS emulation codethat 
 *	was written by Larry Kenah.  It has been modified to run
 *	on Ultrix.
 *
 ***********************************************************************/

 #++
 # facility: 
 #
 #	vax-11 instruction emulator
 #
 # abstract:
 #	the routine in this module emulates the vax-11 packed decimal 
 #	cvtpl instruction. this procedure can be a part of an emulator 
 #	package or can be called directly after the input parameters 
 #	have been loaded into the architectural registers.
 #
 #	the input parameters to this routine are the registers that
 #	contain the intermediate instruction state. 
 #
 # environment: 
 #
 #	this routine runs at any access mode, at any ipl, and is ast 
 #	reentrant.
 #
 # author: 
 #
 #	lawrence j. kenah	
 #
 # creation date
 #
 #	18 october 1983
 #
 # modified by:
 #
 #	v01-009 ljk0034		Lawrence j. Kenah	08-Jul--1984
 #		Fix several bugs in restart logic.
 #
 #		Use r4 instead of r7 as dispatch register for restart routine.
 #		there is a single code path where r7 contains useful data.
 #		Insure that the contents of r7 are preserved across the
 #		occurrence of the cvtpl_5 access violation.
 #		Use special restart path for cvtpl_6.
 #		fix recalculation of srcaddr.
 #		Use saved r2 when saving condition codes.
 #
 #	v01-008 ljk0033		lawrence j. kenah	 06-jul-1984
 #		Add r10 to register mask used along error path when the
 #		digit count is larger than 31.
 #
 #	v01-007 ljk0032		Lawrence j. kenah	05-jul-1984
 #		Fix restart routine to take into account the fact that
 #		restart codes are based at one when computing restart PC.
 #
 #	v01-006 ljk0030		lawrence j. kenah	20-jun-1984
 #		Load access violation handler address into r10 before
 #		any useful work (like memory accesses) gets done.
 #
 #	v01-005 ljk0029		lawrence j. kenah	24-may-1984
 #		Fix stack offset calculation in exit code when v-bit is
 #		set to reflect in fact the seven registers (not six) have
 #		been saved on the stack.
 #
 #	v01-004	ljk0024		lawrence j. kenah	22-Feb-1984
 #		Add code to handle access violation. Perform minor cleanup.
 #
 #	v01-003	ljk0023		lawrence j. kenah	10-Feb-1984
 #		Make a write to PC generate a reserved addressing mode fault.
 #		Temporarily do the same thing for a SP destination operand
 #		until a better solution can be figured out.
 #
 #	v01-002	ljk0016		lawrence j. kenah	28-nov-1983
 #		algorithm was revised to work with digit pairs. overflow check
 #		was modified to account for -2,147,483,648.
 #
 #	v01-001	ljk0008		lawrence j. kenah	17-nov-1983
 #		the emulation code for cvtpl was moved into a separate module.
 #--

#define	operand_1	12
#define	operand_2	16
#define	operand_3	20

 #+ CVTPL
 # functional description:
 #
 #	the source string specified by the  source  length  and  source  address
 #	operands  is  converted  to  a  longword  and the destination operand is
 #	replaced by the result.
 #
 # input parameters:
 #
 #	r0 - srclen.rw		length of input decimal string
 #	r1 - srcaddr.ab		address of input packed decimal string
 #	r3 - dst.wl		address of longword to receive converted string
 #
 #	note that the cvtpl instruction is the only instruction in the
 #	emulator package that has an operand type of .wx. this operand type
 #	needs special treatment if the operand is to be written into a general
 #	register. the following convention is established. if the destination
 #	is anything other than a general register (addressing mode 5), then r3
 #	contains the address of the destination. if the destination is a
 #	general register, then r3 contains the ones complement of the register
 #	number. note that if this is interpreted as an address, then r3 points
 #	to the last page of so-called s1 space, the reserved half of system
 #	virtual address space. the algorithmic specification of this
 #	convention is as follows. 
 #
 #		if r3 <31:04> nequ ^xfffffff
 #		  then
 #		    r3 contains the address of the destination operand
 #		  else
 #		    r3 contains the ones complement of the register number
 #		    of the single register to be loaded with the result 
 #		    of the conversion
 #
 #		that is, 
 #
 #			r3 = ffffffff  ==>   r0 <- result
 #			r3 = fffffffe  ==>   r1 <- result
 #				.
 #				.
 #			r3 = fffffff4  ==>  r11 <- result
 #				.
 #				.
 #
 #		note that any "s1 address" in r3 on input other than
 #		ffffffff through fffffff0 will cause a length access
 #		violation. 
 #
 # output parameters:
 #
 #	r0 = 0
 #	r1 = address of byte containing most significant digit of
 #	     the source string
 #	r2 = 0
 #	r3 = 0
 #
 # condition codes:
 #
 #	n <- output longword lss 0
 #	z <- output longword eql 0
 #	v <- integer overflow
 #	c <- 0
 #
 # register usage:
 #
 #	this routine uses r0 through r7. the condition codes are recorded
 #	in r2 as the routine executes. In addition, r10 serves its usual
 #	purpose by pointing to the access violation handler.
 #-

	.globl	_EMcvtpl
_EMcvtpl:
	movzwl	operand_1(sp),r0	# r0<15:0> <- srclen.rw 
	movl	operand_2(sp),r1	# r1       <- srcaddr.ab 
	movl	operand_3(sp),r3	# r3       <- dst.wl 
	.globl	_EMLcvtpl
_EMLcvtpl:
 #	pushr	$^m<r1,r4,r5,r6,r7>	# save some registers
	 pushr	$0x00f2
	clrl	r2			# set initial PSL
	clrl	r6			# assume result is zero
 #	roprand_check	r0		# insure that r0 lequ 31
	 cmpw	r0,$31
	 blequ	1f
	 brw	decimal_roprand
1:
	 movzwl	r0,r0
	beql	6f			# all done if string has zero length
	jsb	_EM_decimal_strip_zeros_r0_r1	# eliminate leading zeros from input
	ashl	$-1,r0,r0		# convert digit count to byte count
	beql	3f			# skip loop if single digit

 # the first digit pair sets up the initial value of the result.

	movzbl	(r1)+,r5		# get first digit pair
	movzbl	_decimal_packed_to_binary_table[r5],r6
					# convert to binary number

 # the sobgtr instruction at the bottom of the loop can be used to decrement
 # the byte count and test whether this is the special case of an initial
 # digit count of two or three. note that this loop does not attempt to
 # optimize the case where the v-bit is already set.

	brb	2f			# join the loop at the bottom

1:	movzbl	(r1)+,r5		# get next digit pair
	movzbl	_decimal_packed_to_binary_table[r5],r5
					# convert to binary number
	emul	$100,r6,r5,r6		# blend this latest with previous result

 # check all of r7 and r6<31> for nonzero. unconditionally clear r6<31>.

	bbsc	$31,r6,L15		# branch if overflow into r6<31>
	tstl	r7			# anything into upper longword
	beql	2f			# branch if ok
L15:	bisb2	$PSL_V,r2		# set saved v-bit
2:	sobgtr	r0,1b			# continue for rest of whole digit pairs

 # the final (least significant) digit is handled in a slightly different 
 # fashion. this has an advantage in that the final overflow check is different
 # from the check that is made inside the loop. that check can be made quickly
 # without concern for the final digit special cases.

3:	extzv	$4,$4,(r1),r5		# get least significant digit
	emul	$10,r6,r5,r6		# blend in with previous result

 # this overflow check differs from the one inside the loop in three ways.
 #
 #	the check for nonzero r7 precedes the test of r6<31>. 
 #
 #     o the high order bit of r6 is left alone. (if overflow occurs, the 
 #	complete 32-bit contents of r6 need to be preserved.)
 #
 #     o a special check is made to see if the 64-bit result is identically 
 #	equal to 
 #
 #		r6 = 80000000
 #		r7 = 00000000
 #
 #     o if this is true and the input sign is minus, then the overflow bit 
 #	needs to be turned off. this unusual result is passed to the following
 #	code by means of a zero in r7. all other results cause nonzero r7
 #	(including the case where the v-bit was already set).
 #
 # note that the check for v-bit previously set is the single additional 
 # instruction that must execute in the normal (v-bit clear) case to test
 # for the extraordinarily rare case of -2147483648.

	tstl	r7			# overflow into second longword?
	bneq	L36			# branch if overflow
	bbs	$1,r2,L33		# set r7 to nonzero if v-bit already set
	cmpl	r6,$0x80000000		# peculiar check for r6<31> neq zero
	blssu	4f			# branch if no overflow at all
	beql	L36			# leave r7 alone in special case
L33:	incl	r7			# set r7 to nonzero in all other cases
L36:	bisb2	$PSL_V,r2		# set saved v-bit

 # all of the input digits have been processed, get the sign of the input
 # string and complete the instruction processing.

4:	bicb3	$0x0f0,(r1),r5		# get sign "digit"

	caseb	r5,$10,$15-10		# dispatch on sign 
L1:
	.word	6f-L1			# 10 => +
	.word	5f-L1			# 11 => -
	.word	6f-L1			# 12 => +
	.word	5f-L1			# 13 => -
	.word	6f-L1			# 14 => +
	.word	6f-L1			# 15 => +

 # note that negative zero is not a problem in this instruction because the
 # longword result will simply be zero, independent of the input sign.

5:	mnegl	r6,r6			# change sign on negative input
	tstl	r7			# was input -2,147,483,648?
	bneq	6f			# nope, leave v-bit alone
	bicb2	$PSL_V,r2		# clear saved v-bit
6:	movl	(sp)+,r1		# restore original value of r1
	clrq	-(sp)			# set saved r2 and r3 to zero

 # if r3 contains the ones complement of a number between 0 and 15, then the
 # destination is a general register. special processing is required to 
 # correctly restore registers, store the result in a register, and set the
 # condition codes. 

	mcoml	r3,r7			# set up r7 for limit check with case
	casel	r7,$0,$15 - 0		# see if r7 contains a register number
L2:
	.word	L0-L2			# r0  --  store into reg via popr
	.word	L0-L2			# r1  --  store into reg via popr

	.word	L110-L2			# r2  --  store in saved reg on stack
	.word	L110-L2			# r3  --  store in saved reg on stack
	.word	L110-L2			# r4  --  store in saved reg on stack
	.word	L110-L2			# r5  --  store in saved reg on stack
	.word	L110-L2			# r6  --  store in saved reg on stack
	.word	L110-L2			# r7  --  store in saved reg on stack

	.word	L0-L2			# r8  --  store into reg via popr
	.word	L0-L2			# r9  --  store into reg via popr
	.word	L120-L2			# r10 --  saved by dispatcher
	.word	L121-L2			# r11 --  saved by dispatcher
	.word	L0-L2			# ap  --  store into reg via popr
	.word	L0-L2			# fp  --  store into reg via popr

 # The result of specifying PC as a destination operand is defined to be
 # UNPREDICTABLE in the VAX architecture. In addition, it is difficult (but
 # not impossible) for this emulator to modify SP because it is using the
 # stack for local storage. We will generate a reserved addressing mode fault
 # if PC is specified as the destination operand. If SP is the destination we
 # set the user's SP atomically with the return via sigreturn syscall. Of
 # course no sane code will ever store decimal numbers in SP, but what if
 # someone wants to run a VAX validator?

	.word	cvtpl_destsp-L2		# sp -- set via sigreturn
	.word	cvtpl_radrmod-L2	# pc -- reserved addressing mode

 # if we drop through the case instruction, then r3 contains the address of
 # the destination operand. this includes system space addresses in the range
 # c0000000 to ffffffff other than the ones complements of 0 through 15
 # (fffffff0 to ffffffff). the next instruction will cause an access violation
 # for all such illegal system space addresses. 

	movl	r6,(r3)			# store result and set condition codes

 # This is the exit path for this routine. The result has already been stored.
 # The condition codes are set and the saved registers restored. We take the
 # physical PSL, which has correct N and Z (set based on the result), as our
 # base. We clear C as this instruction is supposed to, and OR in R2 which
 # contains our V.

7:	movpsl	r10
	bicl2	$PSL_C,r10
	bisl2	r2,r10
	movl	r10,28(sp)		# return PSL
	bbs	$1,r2,L75		# step out of line for overflow check
 #	popr	$^m<r2,r3,r4,r5,r6,r7>	# restore saved registers and clear 
L72:	popr	$0x00fc			#  r2 and r3

	rsb

 # if the v-bit is set and decimal traps are enabled (iv-bit is set), then
 # a decimal overflow trap is generated. note that the iv-bit can be set in
 # the current psl or, if this routine was entered as the result of an emulated
 # instruction exception, in the saved psl on the stack.

L75:	movl	72(sp),r10
	bitl	$PSL_DV,r10
	beql	L72
	bitl	$PSL_CURMOD,r10
	beql	L72

L78:
 #	popr	$^m<r2,r3,r4,r5,r6,r7>	# restore the registers
	 popr	$0x00fc
	insv	r10,$0,$4,48(sp)

 # ... drop into integer_overflow

 #+
 # this code path is entered if the result is too large to fit into a longword
 # and integer overflow exceptions are enabled. the final state of the
 # instruction, including the condition codes, is entirely in place. 
 #
 # input parameter:
 #
 #	(sp) - return pc to dispatcher
 #
 # output parameters:
 #
 #	return pc popped off the stack
 #	 8(sp) = SIGFPE (arithmetic exception)
 #	12(sp) - FPE_INTOVF_TRAP (arithmetic trap code for decimal overflow)
 #	40(sp) - points at the next instruction (trap)
 #
 # implicit output:
 #
 #	control passes through this code to _EM_signal_exception.
 #-

integer_overflow:
	addl2	$4,sp			# pop jsb return address
	movl	$SIGFPE,8(sp)
	movl	$FPE_INTOVF_TRAP,12(sp)
	jmp	_EM_signal_exception


 #+
 # the destination address is a general register. r3 contains the ones
 # complement of the register number of the general register that is to be
 # loaded with the result. note that the result must be stored in such a way
 # that restoring the saved registers does not overwrite the destination. 
 #
 # the algorithm that accomplishes a correct store of the result with the
 # accompanying setting of the condition codes is as follows.
 #
 #	if the register is in the range r2 through r7 or r10 or r11
 #	  then
 #	    store the result on the stack over that saved register
 #	    (note that this store sets condition codes, except the c-bit)
 #	  else
 #	    construct a register save mask from the register number
 #	    store result on the top of the stack
 #	    (note that this store sets condition codes, except the c-bit)
 #	    popr the result using the mask in r3
 #	endif
 #	restore saved registers
 #-

 # r7 contains 0, 1, 8, 9, 12, or 13. we will use the bit number 
 # to create a register save mask for the appropriate register. note that $1
 # is the source operand and r7 is the shift count in the next instruction.

L0:	ashl	r7,$1,r3		# r3 contains mask for single register
	pushl	r6			# store result and set condition codes
	popr	r3			# restore result into correct register
	brb	7b			# restore r2 through r7 and return      

 # r7 contains 2, 3, 4, 5, 6, or 7

L110:	movl	r6,-8(sp)[r7]		# store result over saved register
	brb	7b			# restore r2 through r7 and return      

 # r7 contains 10
L120:	movl	r6,64(sp)		# Store result over saved register
	brb	7b

 # r7 contains 11
L121:	movl	r6,60(sp)		# Store result over saved register
	brb	7b

 #-
 # functional description:
 #
 #	this routine receives control when a digit count larger than 31
 #	is detected. the exception is architecturally defined as an
 #	abort so there is no need to store intermediate state. the digit
 #	count is made after registers are saved. these registers must be
 #	restored before reporting the exception.
 #
 # input parameters:
 #
 #	00(sp) - saved r1
 #	04(sp) - saved r4
 #	08(sp) - saved r5
 #	12(sp) - saved r6
 #	16(sp) - saved r7
 #	20(sp) - return pc from vax$cvtpl routine to dispatcher
 #
 # output parameters:
 #
 #	saved registers popped from the stack
 #
 # implicit output:
 #
 #	this routine passes control to _EM_reserved_operand where further
 #	exception processing takes place.
 #-

decimal_roprand:
 #	popr	#^m<r1,r4,r5,r6,r7>	# restore saved registers
	 popr	$0x00f2
	jmp	_EM_reserved_operand	# pass control along

 #-
 # functional description:
 #
 #	this routine receives control when pc is used as the destination
 #	of a cvtpl instruction. the reaction to this is not architecturally
 #	defined so we are somewhat free in how we handle it. we currently
 #	generate a radrmod abort with r0 containing the correct 32-bit result.
 #	in the future, we may make this instruction restartable following this
 #	exception. 
 #
 #	Technically the VAX architecture does not define a reserved addressing
 #	mode abort, it defines a reserved addressing mode fault. But since in
 #	this case the operation of the instruction (writing into PC) is
 #	UNPREDICTABLE, I interpret this as meaning it's OK for us to create a
 #	reserved addressing mode abort. We set sc_pc to the instruction PC.
 #
 # input parameters:
 #
 #	r0 - zero
 #	r1 - address of source decimal string
 #	r2 - contains overflow indication in r2<psl$v_v>
 #	r3 - register number in ones complement form
 #		r3 = 0xFFFFFFF0 => pc was destination operand
 #	r4 - scratch
 #	r5 - scratch
 #	r6 - correct 32-bit result
 #	r7 - scratch
 #
 #	00(sp) - saved r2 (contains zero)
 #	04(sp) - saved r3 (contains zero)
 #	08(sp) - saved r4
 #	12(sp) - saved r5
 #	16(sp) - saved r6
 #	20(sp) - saved r7
 #	24(sp) - return pc from vax$xxxxxx routine
 #
 # output parameters:
 #
 #	r0 - correct 32-bit result
 #
 #	r1, r2, and r3 are unchanged from their input values.
 #
 #	r4 through r7 are restored from the stack.
 #
 #	 8(sp) - SIGILL
 #	12(sp) - T_RESADFLT
 #	40(sp) - sc_pc reset from 4(sp) to point as instruction
 #
 # implicit output:
 #
 #	this routine passes control to _EM_signal_exception where further
 #	exception processing takes place.
 #-

cvtpl_radrmod:
	addl2	$8,sp			# discard "saved" r2 and r3
	movl	r6,r0			# remember final result
 #	popr	#^m<r4,r5,r6,r7>	# restore saved registers
	 popr	$0x0f0
	addl2	$4,sp			# pop jsb return address
	movpsl	r10
	bitl	$PSL_CURMOD,r10
	beql	1f
	movl	4(sp),40(sp)		# fault
	bicl2	$PSL_TP,44(sp)		# faults clear TP per VARM
	movl	$SIGILL,8(sp)
	movl	$T_RESADFLT,12(sp)
	jmp	_EM_signal_exception
1:	PANIC("CVTPL to PC in kernel")

cvtpl_destsp:
	movpsl	r10
	bitl	$PSL_CURMOD,r10
	bneq	1f
	PANIC("CVTPL to SP in kernel")
1:	movl	r6,52(sp)		# store result in sigcontext.sc_sp
	bicl2	$PSL_C,r10		# massage PSL like on normal return
	bisl2	r2,r10
	popr	$0x00fc			# r2 through r7
	insv	r10,$0,$4,44(sp)
	movl	32(sp),r11		# restore r11
	movl	36(sp),r10		# restore r10
	movl	r0,16(sp)		# r0 will be our scratch reg now
	movl	ap,36(sp)		# sigcontext.sc_ap
	movl	fp,32(sp)		# sigcontext.sc_fp
	moval	sigblock_arglist,ap	# sigblock(0) to get current mask
	chmk	$SYS_sigblock
	movl	r0,24(sp)		# sigcontext.sc_mask
	movl	_u+U_ONSTACK,20(sp)	# sigcontext.sc_onstack
	movl	16(sp),r0
	movl	$1,(sp)			# arglist for sigreturn
	moval	20(sp),4(sp)
	movl	sp,ap
	chmk	$SYS_sigreturn
	halt				# in case sigreturn failed
sigblock_arglist:
	.long	1,0

#endif NEED_SAMEMODE_EMU
