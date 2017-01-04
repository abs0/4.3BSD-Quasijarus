h43016
s 00001/00001/02245
d D 7.2 04/02/03 11:12:59 msokolov 2 1
c fix PANIC macro to use 0: instead of 1: to reduce interference
e
s 02246/00000/00000
d D 7.1 04/01/11 11:26:25 msokolov 1 0
c date and time created 04/01/11 11:26:25 by msokolov
e
u
U
t
T
I 1
/*
 * VAX decimal string arithmetic instruction emulation
 * Ported from DEC Ultrix to 4.3BSD-Quasijarus by Michael Sokolov
 *
 *	%W% (Berkeley) %G%
 */

#include "../vax/cpucond.h"
#ifdef NEED_SAMEMODE_EMU

#define	LOCORE
#include "signal.h"
#include "../vax/trap.h"
#include "../vax/psl.h"
D 2
#define	PANIC(msg)	pushab 1f; calls $1,_panic; 1: .asciz msg
E 2
I 2
#define	PANIC(msg)	pushab 0f; calls $1,_panic; 0: .asciz msg
E 2

/************************************************************************
 *									*
 *			Copyright (c) 1985 by				*
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
 *	Stephen Reilly, 23-Dec-85
 * 001- Fixed a constant translation bug that caused the divp instruction
 *	not to work.
 *
 ***********************************************************************/

 #++
 # facility: 
 #
 #	vax-11 instruction emulator
 #
 # abstract:
 #
 #	the routines in this module emulate the vax-11 packed decimal
 #	instructions that perform arithmetic operations. these procedures can
 #	be a part of an emulator package or can be called directly after the
 #	input parameters have been loaded into the architectural registers. 
 #
 #	the input parameters to these routines are the registers that
 #	contain the intermediate instruction state. 
 #
 # environment: 
 #
 #	these routines run at any access mode, at any ipl, and are ast 
 #	reentrant.
 #
 # author: 
 #
 #	lawrence j. kenah	
 #
 # creation date
 #
 #	19 october 1983
 #
 # modified by:
 #
 #	v01-003 ljk0037		Lawrence j. kenah	17-jul-1984
 #		Fix two minor bugs in exceptions handling code that caused
 #		MULP and DIVP tests to generate spurious access violation
 #
 #	v01-002	ljk0024		lawrence j. kenah	21-feb-1984
 #		add code to handle access violations. perform minor cleanup.
 #		eliminate double use of r10 in mulp and divp.
 #
 #	v01-001	ljk0008		lawrence j. kenah	19-oct-1983
 #		the emulation code for addp4, addp6, subp4, subp6, mulp and
 #		divp was moved into a separate module.
 #--



 # symbol definitions

 #	the architecture requires that r4 be zero on completion of an addp6 or 
 #	subp6 instruction. if we did not have to worry about restarting 
 #	instructions after an access violation, we could simply zero the saved 
 #	r4 value on the code path that these two instructions have in common 
 #	before they merge with the addp4 and subp4 routines. the ability to 
 #	restart requires that we keep the original r4 around at least until no 
 #	more access violations are possible. to accomplish this, we store the 
 #	fact that r4 must be cleared on exit in r11, which also contains the 
 #	evolving condition codes. we use bit 31, the compatibility mode bit 
 #	because it is nearly impossible to enter the emulator with cm set.
 #
 #	4.3BSD-Quasijarus note: we do not have special handling of access
 #	violations like in Ultrix, but the above logic has been kept.

# define add_sub_v_zero_r4	31

#define	operand_1	12
#define	operand_2	16
#define	operand_3	20
#define	operand_4	24
#define	operand_5	28
#define	operand_6	32

 #+ SUBP6
 # functional description:
 #
 #	in 6 operand format, the subtrahend string specified by  the  subtrahend
 #	length  and  subtrahend  address operands is subtracted from the minuend
 #	string specified by the minuend length  and  minuend  address  operands.
 #	the  difference string specified by the difference length and difference
 #	address operands is replaced by the result.
 #
 # input parameters:
 #
 #	r0 - sublen.rw		number of digits in subtrahend string
 #	r1 - subaddr.ab		address of subtrahend string
 #	r2 - minlen.rw		number of digits in minuend string
 #	r3 - minaddr.ab		address of minuend string
 #	r4 - diflen.rw		number of digits in difference string
 #	r5 - difaddr.ab		address of difference string
 #
 # output parameters:
 #
 #	r0 = 0
 #	r1 = address of the byte containing the most significant digit of
 #	     the subtrahend string
 #	r2 = 0
 #	r3 = address of the byte containing the most significant digit of
 #	     the minuend string
 #	r4 = 0
 #	r5 = address of the byte containing the most significant digit of
 #	     the string containing the difference
 #
 # condition codes:
 #
 #	n <- difference string lss 0
 #	z <- difference string eql 0
 #	v <- decimal overflow
 #	c <- 0
 #
 # register usage:
 #
 #	this routine uses all of the general registers. the condition codes 
 #	are recorded in r11 as the routine executes.
 #-

	.globl	_EMsubp6
_EMsubp6:
	movzwl	operand_1(sp),r0	# r0<15:0> <- sublen.rw 
	movl	operand_2(sp),r1	# r1       <- subaddr.ab 
	movzwl	operand_3(sp),r2	# r2<15:0> <- minlen.rw 
	movl	operand_4(sp),r3	# r3       <- minaddr.ab 
	movzwl	operand_5(sp),r4	# r4<15:0> <- diflen.rw 
	movl	operand_6(sp),r5	# r5       <- difaddr.ab 
	.globl	_EMLsubp6
_EMLsubp6:
 #	pushr	$^m<r0,r1,r2,r3,r4,r5,r6,r7,r8,r9>	# save the lot
	 pushr	$0x03ff
	movzbl	$1,r9			# indicate that this is subtraction
	brb	L10			# merge with addp6 code

 #
 #+ ADDP6
 # functional description:
 #
 #	in 6 operand format, the addend 1  string  specified  by  the  addend  1
 #	length  and  addend  1  address operands is added to the addend 2 string
 #	specified by the addend 2 length and addend 2 address operands.  the sum
 #	string  specified by the sum length and sum address operands is replaced
 #	by the result.
 #
 # input parameters:
 #
 #	r0 - add1len.rw		number of digits in first addend string
 #	r1 - add1addr.ab	address of first addend string
 #	r2 - add2len.rw		number of digits in second addend string
 #	r3 - add2addr.ab	address of second addend string
 #	r4 - sumlen.rw		number of digits in sum string
 #	r5 - sumaddr.ab		address of sum string
 #
 # output parameters:
 #
 #	r0 = 0
 #	r1 = address of the byte containing the most significant digit of
 #	     the first addend string
 #	r2 = 0
 #	r3 = address of the byte containing the most significant digit of
 #	     the second addend string
 #	r4 = 0
 #	r5 = address of the byte containing the most significant digit of
 #	     the string containing the sum
 #
 # condition codes:
 #
 #	n <- sum string lss 0
 #	z <- sum string eql 0
 #	v <- decimal overflow
 #	c <- 0
 #
 # register usage:
 #
 #	this routine uses all of the general registers. the condition codes 
 #	are recorded in r11 as the routine executes.
 #-

	.globl	_EMaddp6
_EMaddp6:
	movzwl	operand_1(sp),r0	# r0<15:0> <- add1len.rw 
	movl	operand_2(sp),r1	# r1       <- add1addr.ab 
	movzwl	operand_3(sp),r2	# r2<15:0> <- add2len.rw 
	movl	operand_4(sp),r3	# r3       <- add2addr.ab 
	movzwl	operand_5(sp),r4	# r4<15:0> <- sumlen.rw 
	movl	operand_6(sp),r5	# r5       <- sumaddr.ab 
	.globl	_EMLaddp6
_EMLaddp6:
 #	pushr	$^m<r0,r1,r2,r3,r4,r5,r6,r7,r8,r9>	# save the lot
	 pushr	$0x03ff
	clrl	r9			# this is addition
L10:
 #	roprand_check	r4		# insure that r4 is lequ 31
	 cmpl	r4,$31
	 blequ	1f
	 brw	decimal_roprand
1:

	movpsl	r11			# get initial psl

 # indicate that the saved r4 must be cleared on the exit path

	bbcs	$add_sub_v_zero_r4,r11,L30	# set bit and join common code
	brb	L30				# in case we drop through bbcs
 #
 #+ SUBP4
 # functional description:
 #
 #	in 4 operand format,  the  subtrahend  string  specified  by  subtrahend
 #	length and subtrahend address operands is subtracted from the difference
 #	string  specified  by  the  difference  length  and  difference  address
 #	operands and the difference string is replaced by the result.
 #
 # input parameters:
 #
 #	r0 - sublen.rw		number of digits in subtrahend string
 #	r1 - subaddr.ab		address of subtrahend decimal string
 #	r2 - diflen.rw		number of digits in difference string
 #	r3 - difaddr.ab		address of difference decimal string
 #
 # output parameters:
 #
 #	r0 = 0
 #	r1 = address of the byte containing the most significant digit of
 #	     the subtrahend string
 #	r2 = 0
 #	r3 = address of the byte containing the most significant digit of
 #	     the string containing the difference
 #
 # condition codes:
 #
 #	n <- difference string lss 0
 #	z <- difference string eql 0
 #	v <- decimal overflow
 #	c <- 0
 #
 # register usage:
 #
 #	this routine uses all of the general registers. the condition codes 
 #	are recorded in r11 as the routine executes.
 #-

	.globl	_EMsubp4
_EMsubp4:
	movzwl	operand_1(sp),r0	# r0<15:0> <- sublen.rw 
	movl	operand_2(sp),r1	# r1       <- subaddr.ab 
	movzwl	operand_3(sp),r2	# r2<15:0> <- diflen.rw 
	movl	operand_4(sp),r3	# r3       <- difaddr.ab 
	.globl	_EMLsubp4
_EMLsubp4:
 #	pushr	$^m<r0,r1,r2,r3,r4,r5,r6,r7,r8,r9>	# save the lot
	 pushr	$0x03ff
	movzbl	$1,r9			# indicate that this is subtraction
	brb	L20			# merge with addp4 code

 #
 #+ ADDP4
 # functional description:
 #
 #	in 4 operand format, the addend string specified by  the  addend  length
 #	and  addend address operands is added to the sum string specified by the
 #	sum length and sum address operands and the sum string  is  replaced  by
 #	the result.
 #
 # input parameters:
 #
 #	r0 - addlen.rw		number of digits in addend string
 #	r1 - addaddr.ab		address of addend decimal string
 #	r2 - sumlen.rw		number of digits in sum string
 #	r3 - sumaddr.ab		address of sum decimal string
 #
 # output parameters:
 #
 #	r0 = 0
 #	r1 = address of the byte containing the most significant digit of
 #	     the addend string
 #	r2 = 0
 #	r3 = address of the byte containing the most significant digit of
 #	     the string containing the sum
 #
 # condition codes:
 #
 #	n <- sum string lss 0
 #	z <- sum string eql 0
 #	v <- decimal overflow
 #	c <- 0
 #
 # register usage:
 #
 #	this routine uses all of the general registers. the condition codes 
 #	are recorded in r11 as the routine executes.
 #-

	.globl	_EMaddp4
_EMaddp4:
	movzwl	operand_1(sp),r0	# r0<15:0> <- addlen.rw 
	movl	operand_2(sp),r1	# r1       <- addaddr.ab 
	movzwl	operand_3(sp),r2	# r2<15:0> <- sumlen.rw 
	movl	operand_4(sp),r3	# r3       <- sumaddr.ab 
	.globl	_EMLaddp4
_EMLaddp4:
 #	pushr	$^m<r0,r1,r2,r3,r4,r5,r6,r7,r8,r9>	# save the lot
	 pushr	$0x03ff
	clrl	r9			# this is addition

 # the output string, described by r4 and r5, will be the same as the input
 # string for addp4 and subp4. it is necessary to explicitly clear r4<31:16>
 # along this code path so movq r2,r4 will not always work.

L20:	movzwl	r2,r4			# set output size equal to input size
	movl	r3,r5			# ... and ditto for string addresses
	movpsl	r11			# get initial psl

 # indicate that the saved r4 will be restored on the common exit path

	bbcc	$add_sub_v_zero_r4,r11,L30	# clear bit and join common code

 #
 #+
 # all four routines converge at this point and execute common initialization
 # code until a later decision is made to do addition or subtraction.
 #
 #	r4 - number of digits in destination string
 #	r5 - address of destination string
 #
 #	r9 - indicates whether operation is addition or subtraction
 #		0 => addition
 #		1 => subtraction
 #
 #	r11<31> - indicates whether this is a 4-operand or 6-operand instruction
 #		0 => 4-operand (restore saved r4 on exit)
 #		1 => 6-operand (set r4 to zero on exit)
 #-

L30:	insv	$PSL_Z,$0,$4,r11	# set z-bit, clear the rest in saved psw
 #	roprand_check	r2			# insure that r2 is lequ 31
	 cmpl	r2,$31
	 blequ	1f
	 brw	decimal_roprand
1:

Ladd_sub_bsbw_0:

	jsb	_EM_decimal_strip_zeros_r2_r3	# strip high order zeros from r2/r3 string

 #	roprand_check	r0			# insure that r0 is lequ 31
	 cmpl	r2,$31
	 blequ	1f
	 brw	decimal_roprand
1:
Ladd_sub_bsbw_0_a:

	jsb	_EM_decimal_strip_zeros_r0_r1	# strip high order zeros from r0/r1 string

 # rather than totally confuse the already complicated logic dealing with
 # different length strings in the add or subtract loop, we will put the
 # result into an intermediate buffer on the stack. this buffer will be long
 # enough to handle the worst case so that the addition loop need only concern
 # itself with the lengths of the two input loops. the required length is 17
 # bytes, to handle an addition with a carry out of the most significant byte.
 # we will allocate 20 bytes to maintain whatever alignment the stack has.

	clrq	-(sp)			# set aside space for output string
	clrq	-(sp)			# worst case string needs 16 bytes
	clrl	-(sp)			# add slack for a carry
	extzv	$1,$4,r4,r8		# get byte count of destination string
	addl3	r8,r5,-(sp)		# save high address end of destination
	movab	24(sp),r5		# point r5 one byte beyond buffer

 # the number of minus signs will determine whether the real operation that we
 # perform is addition or subtraction. that is, two plus signs or two minus
 # signs will both result in addition, while a plus sign and a minus sign will
 # result in subtraction. the addition and subtraction routines have their own
 # methods for determining the correct sign of the result. 
 # 
 # for the purpose of counting minus signs, we treat subtraction as the
 # addition of the negative of the input operand. that is, subtraction of a
 # positive quantity causes the sign to be remembered as minus and counted as
 # a minus sign while subtraction of a minus quantity stores a plus sign and
 # counts nothing. 
 # 
 # on input to this code sequence, r9 distinguished addition from subtraction.
 # on output, it contains either 0, 1, or 2, indicating the total number of
 # minus signs, real or implied, that we counted. 

	extzv	$1,$4,r0,r6		# get byte count for first input string
	addl2	r6,r1			# point r1 to byte containing sign

 	bicb3	$0x0f0,(r1),r6		# r6 contains the sign "digit"
	blbs	r9,L35			# use second case if subtraction

 # this case statement is used for addition

        caseb   r6,$10,$15-10  		# dispatch on sign digit
L1:
        .word   5f-L1                  # 10 => sign is "+"
        .word   4f-L1                  # 11 => sign is "-"
        .word   5f-L1                  # 12 => sign is "+"
        .word   4f-L1                  # 13 => sign is "-"
        .word   5f-L1                  # 14 => sign is "+"
        .word   5f-L1                  # 15 => sign is "+"

 # this case statement is used for subtraction

L35:    caseb   r6,$10,$15-10		# dispatch on sign digit
L2:
        .word   4f-L2                   # 10 => treat sign as "-"
        .word   5f-L2                   # 11 => treat sign as "+"
        .word   4f-L2                   # 12 => treat sign as "-"
        .word   5f-L2                   # 13 => treat sign as "+"
        .word   4f-L2                   # 14 => treat sign as "-"
        .word   4f-L2                   # 15 => treat sign as "-"

4:	movl	$1,r9			# count a minus sign
	movzbl	$13,r6			# the preferred minus sign is 13
	brb	6f			# now check second input sign

5:	clrl	r9			# no real minus signs so far
	movzbl	$12,r6			# the preferred minus sign is 12

6:	extzv	$1,$4,r2,r7		# get byte count for second input string
	addl2	r7,r3			# point r3 to byte containing sign

	bicb3	$0x0f0,(r3),r7	# r7 contains the sign "digit"

        caseb   r7,$10,$15-10		# dispatch on sign digit
L3:
        .word   8f-L3                   # 10 => sign is "+"
        .word   7f-L3                   # 11 => sign is "-"
        .word   8f-L3                   # 12 => sign is "+"
        .word   7f-L3                   # 13 => sign is "-"
        .word   8f-L3                   # 14 => sign is "+"
        .word   8f-L3                   # 15 => sign is "+"

7:	incl	r9			# remember that sign was minus
	movzbl	$13,r7			# the preferred minus sign is 13
	brb	9f			# now check second input sign

8:	movzbl	$12,r7			# the preferred minus sign is 12

9:	blbc	r9,add_packed		# even parity indicates addition

	brw	subtract_packed		# odd parity calls for subtraction

 #
 #+ add_packed
 # functional description:
 #
 #	this routine adds two packed decimal strings whose descriptors
 #	are passed as input parameters and places their sum into another
 #	(perhaps identical) packed decimal string.
 #
 #	at the present time, the result is placed into a 16-byte storage
 #	area while the sum is being evaluated. this drastically reduces
 #	the number of different cases that must be dealt with as each
 #	pair of bytes in the two input strings is added.
 #
 #	the signs of the two input strings have already been dealt with
 #	so this routine performs addition in all cases, even if the original
 #	entry was at subp4 or subp6. the cases that arrive in this routine
 #	are as follows.
 #
 #                          r2/r3           r0/r1          result
 #                    +---------------+---------------+---------------+
 #                    |               |               |               |
 #      r2/r3 + r0/r1 |     plus      |     plus      |     plus      |
 #                    |               |               |               |
 #                    +---------------+---------------+---------------+
 #                    |               |               |               |
 #      r2/r3 + r0/r1 |     minus     |     minus     |     minus     |
 #                    |               |               |               |
 #                    +---------------+---------------+---------------+
 #                    |               |               |               |
 #      r2/r3 - r0/r1 |     minus     |     plus      |     minus     |
 #                    |               |               |               |
 #                    +---------------+---------------+---------------+
 #                    |               |               |               |
 #      r2/r3 - r0/r1 |     plus      |     minus     |     plus      |
 #                    |               |               |               |
 #                    +---------------+---------------+---------------+
 #
 #	note that the correct choice of sign in all four cases is the sign
 #	of the second input string, the one described by r2 and r3.
 #
 # input parameters:
 #
 #	r0<4:0> - number of digits in first input decimal string
 #	r1      - address of least significant digit of first input 
 #		  decimal string (the byte containing the sign)
 #
 #	r2<4:0> - number of digits in second input decimal string
 #	r3      - address of least significant digit of second input 
 #		  decimal string (the byte containing the sign)
 #
 #	r4<4:0> - number of digits in output decimal string
 #	r5      - address of one byte beyond least significant digit of 
 #		  intermediate string stored on the stack
 #
 #	r6<3:0> - sign of first input string in preferred form
 #	r7<3:0> - sign of second input string in preferred form
 #
 #	r11     - saved psl (z-bit is set, other condition codes are clear)
 #
 #	(sp)	- saved r5, address of least significant digit of ultimate
 #		  destination string.
 #	4(sp)   - beginning of 20-byte buffer to hold intermediate result
 #
 # output parameters:
 #
 #	the particular input operation (addpx or subpx) is completed in
 #	this routine. see the routine headers for the four routines that
 #	request addition or subtraction for a list of output parameters
 #	from this routine.
 #-

add_packed:
	movb	r7,r9			# use sign of second string for output
	blbc	r9,1f			# check if sign is negative
	bisb2	$PSL_N,r11		# ... so the saved n-bit can be set

1:	bicb3	$0x0f,(r1),r6		# get least significant digit to r6

	bicb3	$0x0f,(r3),r7		# get least significant digit to r7
	clrl	r8			# start the add with carry off
	bsbw	add_packed_byte_r6_r7	# add the two low order digits

 # the following set of instructions computes the number of bytes in the two
 # strings and, if necessary, performs a switch so that r0 and r1 always
 # describe the shorter of the two strings.

	extzv	$1,$4,r0,r0		# convert digit count to byte count
	extzv	$1,$4,r2,r2		# do it for both strings
	cmpl	r0,r2			# we want to compare the byte counts
	blequ	2f			# skip the swap if we're already correct
	movq	r0,r6			# save the longer
	movq	r2,r0			# store the shorter on r0 and r1
	movq	r6,r2			# ... and store the longer in r2 and r3
2:	subl2	r0,r2			# make r2 a difference (r2 gequ 0)

 # r0 now contains the number of bytes remaining in the shorter string.
 # r2 contains the difference in bytes between the two input strings.

	tstl	r0			# does shorter string have any room?
	beql	4f			# skip loop if no room at all

3:	bsbw	add_packed_byte_string	# add the next two bytes together
	sobgtr	r0,3b			# check for end of loop

4:	tstl	r2			# does longer string have any room?
	beql	7f			# skip next loops if all done

5:	blbc	r8,6f			# life is simple if carry clear

	clrl	r6			# otherwise, carry must propogate

	movzbl	-(r3),r7		# so add carry to single string
	bsbw	add_packed_byte_r6_r7	# use the special entry point
	sobgtr	r2,5b			# check for this string exhausted
	brb	7f			# join common completion code

6:	movb	-(r3),-(r5)		# simply move src to dst if no carry
	sobgtr	r2,6b			# ... until we're all done

7:	movb	r8,-(r5)		# store the final carry

 #+
 # at this point, the result has been computed. that result must be moved to
 # its ultimate destination, noting whether any nonzero digits are stored
 # so that the z-bit will have its correct setting. 
 #
 # input parameters:
 #
 #	r9<7:0>  - sign of result in preferred form
 #	r11<3:0> - saved condition codes
 #	r11<31>  - indicates whether to set saved r4 to zero
 #
 #	(sp)    - saved r5, high address end of destination string
 #-

add_subtract_exit:
	addl3	$1,(sp),r5		# point r5 beyond real destination 
	movab	24(sp),r1		# r1 locates the saved result
	bsbw	store_result		# store the result and record the z-bit
	bbs	$2,r11,0f		# step out of line for minus zero check

8:	insv	r9,$0,$4,*(sp)+		# the sign can finally be stored
	addl2	$20,sp			# get rid of intermediate buffer
	bbc	$add_sub_v_zero_r4,r11,9f	# branch if 4-operand opcode
	clrl	16(sp)			# clear saved r4 to return zero
9:	jmp	_EM_decimal_exit	# exit through common code path

 # if the result is negative zero, then the n-bit is cleared and the sign
 # is changed to a plus sign.

0:	bicb2	$PSL_N,r11		# clear the n-bit unconditionally
	bbs	$1,r11,8b		# do not change the sign on overflow
	movb	$12,r9			# make sure that the sign is plus
	brb	8b			# ... and rejoin the exit code

 #
 #+
 # functional description:
 #
 #	this routine adds together two bytes containing decimal digits and 
 #	produces a byte containing the sum that is stored in the output 
 #	string. each of the input bytes is converted to a binary number
 #	(with a table-driven conversion), the two numbers are added, and
 #	the sum is converted back to two decimal digits stored in a byte.
 #
 #	this routine makes no provisions for bytes that contain illegal
 #	decimal digits. we are using the unpredictable statement in the
 #	architectural description of the decimal instructions to its fullest.
 #
 #	the bytes that contain a pair of packed decimal digits can either
 #	exist in packed decimal strings located by r1 and r3 or they can
 #	be stored directly in registers. in the former case, the digits must
 #	be extracted from registers before they can be used in later operations
 #	because the sum will be used as an index register.
 #
 # for entry at add_packed_byte_string:
 #
 #	input parameters:
 #
 #		r1  - address one byte beyond first byte that is to be added
 #		r3  - address one byte beyond second byte that is to be added
 #		r5  - address one byte beyond location to store sum
 #
 #		r8  - carry from previous byte (r8 is either 0 or 1)
 #
 #	implicit input:
 #
 #		r6 - scratch
 #		r7 - scratch
 #
 #	output parameters:
 #
 #		r1 - decreased by one to point to current byte in first input string
 #		r3 - decreased by one to point to current byte in second input string
 #		r5 - decreased by one to point to current byte in output string
 #
 #		r8 - either 0 or 1, reflecting whether this most recent add resulted
 #		     in a carry to the next byte.
 #
 # for entry at add_packed_byte_r6_r7:
 #
 #	input parameters:
 #
 #		r6  - first byte containing decimal digit pair
 #		r7  - second byte containing decimal digit pair
 #
 #		r5  - address one byte beyond location to store sum
 #
 #		r8  - carry from previous byte (r8 is either 0 or 1)
 #
 #	output parameters:
 #
 #		r5 - decreased by one to point to current byte in output string
 #
 #		r8 - either 0 or 1, reflecting whether this most recent add resulted
 #		     in a carry to the next byte.
 #
 # side effects:
 #
 #	r6 and r7 are modified by this routine
 #
 #	r0, r2, r4, and r9 (and, of course, r10 and r11) are preserved 
 #	by this routine
 #
 # assumptions:
 #
 #	this routine makes two important assumptions.
 #
 #	1.  if both of the input bytes contain only legal decimal digits, then
 #	    it is only necessary to subtract 100 at most once to put all 
 #	    possible sums in the range 0..99. that is,
 #
 #		99 + 99 + 1 = 199 lss 200
 #
 #	2.  the result will be checked in some way to determine whether the
 #	    result is nonzero so that the z-bit can have its correct setting.
 #-

add_packed_byte_string:

	movzbl	-(r1),r6		# get byte from first string
	movzbl	-(r3),r7		# get byte from second string

	.globl	_EM_add_packed_byte_r6_r7
_EM_add_packed_byte_r6_r7:		# ashp also uses this routine
add_packed_byte_r6_r7:
	movb	_decimal_packed_to_binary_table[r6],r6
					# convert digits to binary
	movb	_decimal_packed_to_binary_table[r7],r7
					# convert digits to binary
	addb2	r6,r7			# form their sum
	addb2	r8,r7			# add carry from last step
	clrb	r8			# assume no carry this time
	cmpb	r7,$99			# check for carry
	blequ	1f			# branch if within bounds
	movb	$1,r8			# propogate carry to next step
	subb2	$100,r7			# put r7 into interval 0..99
1:	movb	_decimal_binary_to_packed_table[r7],-(r5)
					# store converted sum byte
	rsb

 #
 #+ subtract_packed
 # functional description:
 #
 #	this routine takes two packed decimal strings whose descriptors
 #	are passed as input parameters, subtracts one string from the
 #	other, and places their sum into another (perhaps identical) 
 #	packed decimal string.
 #
 #	at the present time, the result is placed into a 16-byte storage
 #	area while the difference is being evaluated. this drastically reduces
 #	the number of different cases that must be dealt with as each
 #	pair of bytes in the two input strings is added.
 #
 #	the signs of the two input strings have already been dealt with so
 #	this routine performs subtraction in all cases, even if the original
 #	entry was at addp4 or addp6. 
 #
 # input parameters:
 #
 #	r0<4:0> - number of digits in first input decimal string
 #	r1      - address of least significant digit of first input 
 #		  decimal string (the byte containing the sign)
 #
 #	r2<4:0> - number of digits in second input decimal string
 #	r3      - address of least significant digit of second input 
 #		  decimal string (the byte containing the sign)
 #
 #	r4<4:0> - number of digits in output decimal string
 #	r5      - address of one byte beyond least significant digit of 
 #		  intermediate string stored on the stack
 #
 #	r6<3:0> - sign of first input string in preferred form
 #	r7<3:0> - sign of second input string in preferred form
 #
 #	r11     - saved psl (z-bit is set, other condition codes are clear)
 #
 #	(sp)	- saved r5, address of least significant digit of ultimate
 #		  destination string.
 #	4(sp)   - beginning of 20-byte buffer to hold intermediate result
 #
 # output parameters:
 #
 #	the particular input operation (addpx or subpx) is completed in
 #	this routine. see the routine headers for the four routines that
 #	request addition or subtraction for a list of output parameters
 #	from this routine.
 #
 # algorithm for choice of sign:
 #
 #	the choice of sign for the output string is not nearly so 
 #	straightforward as it is in the case of addition. one approach that is 
 #	often taken is to make a reasonable guess at the sign of the result. 
 #	if the final subtraction causes a borrow, then the choice was incorrect. 
 #	the sign must be changed and the result must be replaced by its tens 
 #	complement.
 #
 #	this routine does not guess. instead, it chooses the input string of 
 #	the larger absolute magnitude as the minuend for this internal 
 #	routine and chooses its sign as the sign of the result.
 #	this algorithm is actually more efficient than the reasonable 
 #	guess method and is probably better than a guess method that is never 
 #	wrong. all complete bytes that are processed in the sign evaluation 
 #	preprocessing loop are eliminated from consideration in the 
 #	subtraction loop, which has a higher cost per byte.
 #
 #	the actual algorithm is as follows. (note that both input strings have 
 #	already had leading zeros stripped so their lengths reflect 
 #	significant digits.)
 #
 #	1.  if the two strings have unequal lengths, then choose the sign of 
 #	    the string that has the longer length.
 #
 #	2.  for strings of equal length, choose the sign of the string whose 
 #	    most significant byte is larger in magnitude.
 #
 #	3.  if the most significant bytes test equal, then decrease the 
 #	    lengths of each string by one byte, drop the previous most 
 #	    significant bytes, and go back to step 2.
 #
 #	4.  if the two strings test equal, it is not necessary to do any 
 #	    subtraction. the result is identically zero.
 #
 #	note that the key to this routine's efficiency is that high order 
 #	bytes that test equal in this loop are dropped from consideration in 
 #	the more complicated subtraction loop.
 #-

subtract_packed:
	extzv	$1,$4,r0,r0		# convert digit count to byte count
	extzv	$1,$4,r2,r2		# do it for both strings
	cmpl	r0,r2			# we want to compare the byte counts
	blssu	4f			# r0/r1 represent the smaller string
	bgtru	3f			# r2/r3 represent the smaller string

 # the two input strings have an equal number of bytes. compare magnitudes to
 # determine which string is really larger. if the two strings test equal, then
 # skip the entire subtraction loop.

	subl3	r0,r1,r8		# point r8 to low address end of r0/r1
	subl3	r2,r3,r9		# point r9 to low address end of r2/r3
	tstl	r0			# see if both strings have zero bytes
	beql	2f			# still need to check low order digit

1:	cmpb	(r8)+,(r9)+		# compare most significant bytes
	blssu	4f			# r0/r1 represent the smaller string
	bgtru	3f			# r2/r3 represent the smaller string
	decl	r2			# keep r2 in step with r0	
	sobgtr	r0,1b			# ... which gets decremented here

 # at this point, we have reduced both input strings to single bytes that
 # contain a sign "digit" and may contain a digit in the high order nibble
 # if the original digit counts were nonzero.

2:	bicb3	$0x0f,(r8),r8		# look only at digit, ignoring sign

	bicb3	$0x0f,(r9),r9		# get the digit from the other string
	cmpb	r8,r9			# compare these digits
	blssu	4f			# r0/r1 represent the smaller string
	bgtru	3f			# r2/r3 represent the smaller string

 # the two strings have identical magnitudes. enter the end processing code
 # with the intermediate result unchanged (that is, zero).

	brw	add_subtract_exit	# join the common completion code

 # the string described by r0 and r1 has the larger magnitude. choose its sign.
 # then swap the two string descriptors so that the main subtraction loops
 # always have r2 and r3 describing the larger string. note that the use of
 # r6 and r7 as scratch leaves r7<31:8> in an unpredictable state. 

3:	movb	r6,r9			# load preferred sign into r9
	movq	r0,r6			# save the longer
	movq	r2,r0			# store the shorter on r0 and r1
	movq	r6,r2			# ... and store the longer in r2 and r3
	clrl	r7			# insure that r7<31:8> is zero
	brb	5f			# continue along common code path

 # the string described by r2 and r3 has the larger magnitude. choose its sign.

4:	movb	r7,r9			# load preferred sign into r9

5:	subl2	r0,r2			# make r2 a difference (r2 gequ 0)
	blbc	r9,6f			# check if sign is negative
	bisb2	$PSL_N,r11		# ... so the saved n-bit can be set

6:	bicb3	$0x0f,(r1),r6		# get least significant digit to r6

	bicb3	$0x0f,(r3),r7		# get least significant digit to r7
	clrl	r8			# start subtracting with borrow off
	bsbw	sub_packed_byte_r6_r7	# subtract the two low order digits

 # r0 contains the number of bytes remaining in the smaller string
 # r2 contains the difference in bytes between the two input strings

	tstl	r0			# does smaller string have any room?
	beql	8f			# skip loop if no room at all

7:	bsbw	sub_packed_byte_string	# subtract the next two bytes 
	sobgtr	r0,7b			# check for end of loop

8:	tstl	r2			# does one of the strings have more?
	beql	L110			# skip next loops if all done

9:	blbc	r8,0f			# life is simple if borrow clear

	clrl	r6			# otherwise, borrow must propogate
	movzbl	-(r3),r7		# so subtract borrow from single string
	bsbw	sub_packed_byte_r6_r7	# use the special entry point
	sobgtr	r2,9b			# check for this string exhausted
	brb	L110			# join common completion code

0:	movb	-(r3),-(r5)		# simply move src to dst if no borrow
	sobgtr	r2,0b			# ... until we're all done

L110:

 ### ********** begin temp ********** 
 ###
 ### The following halt instruction should be replaced with the correct
 ### abort code.
 ###
 ### The halt is similar to the 
 ###
 ###	microcode cannot get here
 ###
 ### errors that other implementations use.
 ###
	tstl	r8			# if borrow is set here, we blew it
	beql	1f			# branch out if ok
	halt				# this will cause an opcdec exception
1:
 ###
 ### *********** end temp ***********

	brw	add_subtract_exit	# join common completion code

 #
 #+
 # functional description:
 #
 #	this routine takes as input two bytes containing decimal digits and
 #	produces a byte containing their difference. this result is stored in
 #	the output string. each of the input bytes is converted to a binary
 #	number (with a table-driven conversion), the first number is
 #	subtracted from the second, and the difference is converted back to
 #	two decimal digits stored in a byte. 
 #
 #	this routine makes no provisions for bytes that contain illegal
 #	decimal digits. we are using the unpredictable statement in the
 #	architectural description of the decimal instructions to its fullest.
 #
 #	the bytes that contain a pair of packed decimal digits can either
 #	exist in packed decimal strings located by r1 and r3 or they can
 #	be stored directly in registers. in the former case, the digits must
 #	be extracted from registers before they can be used in later operations
 #	because the difference will be used as an index register.
 #
 # for entry at sub_packed_byte_string:
 #
 #	input parameters:
 #
 #		r1  - address one byte beyond byte containing subtrahend
 #		r3  - address one byte beyond byte containing minuend
 #		r5  - address one byte beyond location to store difference
 #
 #		r8  - borrow from previous byte (r8 is either 0 or 1)
 #
 #	implicit input:
 #
 #		r6 - scratch
 #		r7 - scratch
 #
 #	output parameters:
 #
 #		r1 - decreased by one to point to current byte 
 #		     in subtrahend string
 #		r3 - decreased by one to point to current byte 
 #		     in minuend string
 #		r5 - decreased by one to point to current byte 
 #		     in difference string
 #
 #		r8 - either 0 or 1, reflecting whether this most recent 
 #		     subtraction resulted in a borrow from the next byte.
 #
 # for entry at sub_packed_byte_r6_r7:
 #
 #	input parameters:
 #
 #		r6<7:0>  - byte containing decimal digit pair for subtrahend 
 #		r6<31:8> - mbz
 #		r7<7:0>  - byte containing decimal digit pair for minuend 
 #		r7<31:8> - mbz
 #
 #		r5 - address one byte beyond location to store difference 
 #
 #		r8 - borrow from subtraction of previous byte 
 #		     (r8 is either 0 or 1)
 #
 #	output parameters:
 #
 #		r5 - decreased by one to point to current byte 
 #		     in difference string
 #
 #		r8 - either 0 or 1, reflecting whether this most recent 
 #		     subtraction resulted in a borrow from the next byte.
 #
 # side effects:
 #
 #	r6 and r7 are modified by this routine
 #
 #	r0, r2, r4, and r9 (and, of course, r10 and r11) are preserved 
 #	by this routine
 #
 # assumptions:
 #
 #	this routine makes two important assumptions.
 #
 #	1.  if both of the input bytes contain only legal decimal digits, then
 #	    it is only necessary to add 100 at most once to put all 
 #	    possible differences in the range 0..99. that is,
 #
 #		0 - 99 - 1 = -100
 #
 #	2.  the result will be checked in some way to determine whether the
 #	    result is nonzero so that the z-bit can have its correct setting.
 #-

sub_packed_byte_string:

	movzbl	-(r1),r6		# get byte from first string
	movzbl	-(r3),r7		# get byte from second string

sub_packed_byte_r6_r7:
	movb	_decimal_packed_to_binary_table[r6],r6
					# convert digits to binary
	movb	_decimal_packed_to_binary_table[r7],r7
					# convert digits to binary
	subb2	r6,r7			# form their difference
	subb2	r8,r7			# include borrow from last step
	blss	1f			# branch if need to borrow
	clrb	r8			# no borrow next time
	brb	2f			# join common exit code

1:	addb2	$100,r7			# put r7 into interval 0..99
	movb	$1,r8			# propogate borrow to next step

2:	movb	_decimal_binary_to_packed_table[r7],-(r5)
					# store converted sum byte
	rsb

 #
 #+ store_result
 # functional description:
 #
 #	this routine takes a packed decimal string that typically contains
 #	the result of an arithmetic operation and stores it in another
 #	decimal string whose descriptor is specified as an input parameter 
 #	to the original arithmetic operation.
 #
 #	the string is stored from the high address end (least significant
 #	digits) to the low address end (most significant digits). this order
 #	allows all of the special cases to be handled in the simplest fashion.
 #
 # input parameters:
 #
 #	r1      - address one byte beyond high address end of input string
 #		  (note that this string must be at least 17 bytes long.)
 #
 #	r4<4:0> - number of digits in ultimate destination
 #	r5      - address one byte beyond destination string
 #
 #       r11     - contains saved condition codes
 #
 # implicit input:
 #
 #	the input string must be at least 17 bytes long to contain a potential
 #	carry out of the highest digit when doing an add of two large numbers. 
 #	this carry out of the last byte will be detected and reported as a 
 #	decimal overflow, either as an exception or simply by setting the v-bit.
 #
 #	the least significant digit (highest addressed byte) cannot contain a
 #	sign digit because that would cause the z-bit to be incorrectly cleared.
 #
 # output parameters:
 #
 #	r11<psl$v_z> - cleared if a nonzero digit is stored in output string
 #	r11<psl$v_v> - set if a nonzero digit is detected after the output
 #		       string is exhausted
 #
 #	a portion of the result (dictated by the size of r4 on input) is
 #	moved to the destination string.
 #-

store_result:
	incl	r4			# want number of "complete" bytes in
	ashl	$-1,r4,r0		#  output string
	beql	3f			# skip first loop if none

1:	movb	-(r1),-(r5)		# move the next complete byte
	beql	2f			# check whether to clear z-bit
	bicb2	$PSL_Z,r11		# clear z-bit if nonzero
2:	sobgtr	r0,1b			# keep going?

3:	blbc	r4,5f			# was original r4 odd? branch if yes

	bicb3	$0x0f0,-(r1),-(r5)	# if r4 was even, store half a byte
	beql	4f			# need to check for zero here, too
	bicb2	$PSL_Z,r11		# clear z-bit if nonzero	

4:	bitb	$0x0f0,(r1)		# if high order nibble is nonzero,
	bneq	7f			# ... then overflow has occurred

 # the entire destination has been stored. we must now check whether any of
 # the remaining input string is nonzero and set the v-bit if nonzero is
 # detected. note that at least one byte of the output string has been examined
 # in all cases already. this makes the next byte count calculation correct.

5:	decl	r4			# restore r4 to its original self
	extzv	$1,$4,r4,r0		# extract a byte count
	subb3	r0,$16,r0		# loop count is 16 minus byte count

 # note that the loop count can never be zero because we are testing a 17-byte
 # string and the largest output string can be 16 bytes long.

6:	tstb	-(r1)			# check next byte for nonzero
	bneq	7f			# nonzero means overflow has occurred
	sobgtr	r0,6b			# check for end of this loop

	rsb				# this is return path for no overflow

7:	bisb2	$PSL_V,r11		# indicate that overflow has occurred
	rsb				# ... and return to the caller

 #
 #+ MULP
 # functional description:
 #
 #	the  multiplicand  string  specified  by  the  multiplicand  length  and
 #	multiplicand  address  operands  is  multiplied by the multiplier string
 #	specified by the multiplier length and multiplier address operands.  the
 #	product  string  specified  by  the  product  length and product address
 #	operands is replaced by the result.
 #
 # input parameters:
 #
 #	r0 - mulrlen.rw		number of digits in multiplier string
 #	r1 - mulraddr.ab	address of multiplier string
 #	r2 - muldlen.rw		number of digits in multiplicand string
 #	r3 - muldaddr.ab	address of multiplicand string
 #	r4 - prodlen.rw		number of digits in product string
 #	r5 - prodaddr.ab	address of product string
 #
 # output parameters:
 #
 #	r0 = 0
 #	r1 = address of the byte containing the most significant digit of
 #	     the multiplier string
 #	r2 = 0
 #	r3 = address of the byte containing the most significant digit of
 #	     the multiplicand string
 #	r4 = 0
 #	r5 = address of the byte containing the most significant digit of
 #	     the string containing the product
 #
 # condition codes:
 #
 #	n <- product string lss 0
 #	z <- product string eql 0
 #	v <- decimal overflow
 #	c <- 0
 #
 # register usage:
 #
 #	this routine uses all of the general registers. the condition codes
 #	are computed at the end of the instruction as the final result is
 #	stored in the product string. r11 is used to record the condition
 #	codes.
 #
 # notes:
 #
 #    1.this routine uses a large amount of stack space to allow storage of
 #	intermediate results in a convenient form. specifically, each digit
 #	pair of the longer input string is stored in binary in a longword on
 #	the stack. in addition, 32 longwords are set aside to hold the product
 #	intermediate result. each longword contains a binary number between 0
 #	and 99. 
 #
 #	after the multiplication is complete. each longword is removed from
 #	the stack, converted to a packed decimal pair, and stored in the
 #	output string. any nonzero cells remaining on the stack after the
 #	output string has been completely filled are the indication of decimal
 #	overflow. 
 #
 #	the purpose of this method of storage is to avoid decimal/binary or
 #	even byte/longword conversions during the calculation of intermediate
 #	results. 
 #
 #    2.trailing zeros are removed from the larger string. all zeros in
 #	the shorter string are eliminated in the sense that no arithmetic
 #	is performed. the output array pointer is simply advanced to point
 #	to the next higher array element.
 #-

	.globl	_EMmulp
_EMmulp:
	movzwl	operand_1(sp),r0	# r0<15:0> <- mulrlen.rw 
	movl	operand_2(sp),r1	# r1       <- mulraddr.ab 
	movzwl	operand_3(sp),r2	# r2<15:0> <- muldlen.rw 
	movl	operand_4(sp),r3	# r3       <- muldaddr.ab 
	movzwl	operand_5(sp),r4	# r4<15:0> <- prodlen.rw 
	movl	operand_6(sp),r5	# r5       <- prodaddr.ab 
	.globl	_EMLmulp
_EMLmulp:
 #	pushr	$^m<r0,r1,r2,r3,r4,r5,r6,r7,r8,r9>	# save the lot
	 pushr	$0x03ff

 #	roprand_check	r4			# insure that r4 is lequ 31
	 cmpl	r4,$31
	 blequ	1f
	 brw	decimal_roprand
1:

 #	roprand_check	r2			# insure that r2 is lequ 31
	 cmpl	r2,$31
	 blequ	1f
	 brw	decimal_roprand
1:

	jsb	_EM_decimal_strip_zeros_r2_r3	# strip high order zeros from r2/r3 string

 #	roprand_check	r0			# insure that r0 is lequ 31
	 cmpl	r0,$31
	 blequ	1f
	 brw	decimal_roprand
1:

	jsb	_EM_decimal_strip_zeros_r0_r1	# strip high order zeros from r0/r1 string

	extzv	$1,$4,r0,r0		# convert digit count to byte count
	incl	r0			# include least significant digit

	extzv	$1,$4,r2,r2		# convert digit count to byte count
	incl	r2			# include least significant digit

	cmpl	r0,r2			# see which string is larger
	bgtru	3f			# r2/r3 describes the longer string
	movq	r2,r8			# r8 and r9 describe the longer string
	movq	r0,-(sp)		# shorter string descriptor also saved
	brb	6f

3:	movq	r0,r8			# r8 and r9 describe the longer string
	movq	r2,-(sp)		# shorter string descriptor also saved

 # create space for the output array on the stack (32 longwords of zeros)

6:	movl	$8,r0			# eight pairs of quadwords

0:	clrq	-(sp)			# clear one pair
	clrq	-(sp)			# ... and another
	sobgtr	r0,0b			# do all eight pairs

	movl	sp,r7			# store beginning of output array in r7

 # the longer input array will be stored on the stack as an array of 
 # longwords. each array element contains a number between 0 and 99, 
 # representing a pair of digits in the original packed decimal string. 
 # because the units digit is stored with the sign in packed decimal format, 
 # it is necessary to shift the number as we store it. this is accomplished by 
 # multiplying the number by ten.
 #
 # the longer array is described by r8 (byte count) and r9 (address of most
 # significant digit pair).

	addl3	r9,r8,r5		# point r5 beyond sign digit
	movl	r8,r4			# r4 contains the loop count

 # an array of longwords is allocated on the stack. r3 starts out pointing
 # at the longword beyond the top of the stack. the first remainder, guaranteed
 # to be zero, is "stored" here. the rest of the digit pairs are stored safely
 # below the top of the stack.

	mnegl	r8,r3			# stack grows toward lower addresses
	moval	(sp)[r3],sp		# allocate the space
	subl3	$4,sp,r3		# point r3 at next lower longword

2:	movzbl	-(r5),r1		# get next digit pair
	movzbl	_decimal_packed_to_binary_table[r1],r1
					# convert digits to binary
	emul	$10,r1,r2,r0		# multiply by 10
	ediv	$100,r0,r2,(r3)+	# divide by 100
	sobgtr	r4,2b	

	movl	r2,(r3)			# store final quotient
	movl	sp,r9			# remember array address in r9
	pushal	(sp)[r8]		# store start of fixed size area

 # check for trailing zeros in the input array stored on the stack. if any are 
 # present, they are removed and the product array is adjusted accordingly.

3:	tstl	(r9)+			# is next number zero?
	bneq	4f			# leave loop if nonzero
	addl2	$4,r7			# advance output pointer to next element
	sobgtr	r8,3b			# keep going

 # if we drop through the loop, then the entire input array is zero. there is
 # no need to perform any arithmetic because the product will be zero (and the
 # output array on the stack starts out as zero). the only remaining work is
 # to store the result in the output string and set the condition codes.

	brb	7f			# exit to end processing

 # now multiply the input array by each successive digit pair. in order to
 # allow r10 to continue to locate arith_accvio while we execute this loop, it
 # is necessary to perform a small amount of register juggling. in essence,
 # r8 and r9 switch the identity of the string that they describe.

4:	subl2	$4,r9			# readjust input array pointer
	movq	r8,-(sp)		# save r8/r9 descriptor on stack
	movl	8(sp),r8		# point r8 at start of 32-longword array
	movq	(32*4)(r8),r8		# get descriptor that follows that array
	addl2	r8,r9			# point r9 beyond sign byte

5:	moval	(r7)+,r3		# output array address to r3 

	movzbl	-(r9),r1		# next digit pair to r1
	movzbl	_decimal_packed_to_binary_table[r1],r6
					# convert digits to binary
	beql	6f			# skip the work if zero
	movq	(sp),r4			# input array descriptor to r4/r5
	bsbw	extend_string_multiply	# do the work
6:	sobgtr	r8,5b			# any more multiplier digits?

	addl2	$8,sp			# discard saved long string descriptor

7:	movl	(sp),sp			# remove input array from stack

 # at this point, the product string is located in a 32-longword array on
 # the top of the stack. each longword corresponds to a pair of digits in
 # the output string. as digits are removed from the stack, they are checked
 # for nonzero to obtain the correct setting of the z-bit. after the output
 # string has been filled, the remainder of the product string is removed from
 # the stack. if a nonzero result is detected at this stage, the v-bit is set.

	movl	$32,r9			# set up array counter
 #	movq	< <32*4> + -		# skip over 32-longword array
 #		  <2*4>  + -		#  and saved string descriptor
 #		  <4*4> >(sp),r4	#  to retrieve original r4 and r5
	 movq	( (32*4) + (2*4) + (4*4) )(sp),r4

 #
 #+
 # the code for vax$mulp and vax$divp merges at this point. the result is stored
 # in an array of longwords at the top of the stack. the size of this array is
 # stored in r9. the original r4 and r5 heve been retrieved from the stack. 
 #
 # input parameters:
 #
 #	r4 - contains byte count of destination string in r4 <1:4>
 #	r5 - address of most significant digit of destination string
 #	r9 - count of longwords in result array on stack
 #
 #	contents of result array
 #
 # implicit input:
 #
 #	signs of two input factors (multiplier and multiplicand or
 #		divisor and dividend)
 #-

multiply_divide_exit:
	movpsl	r11			# get current psl
	insv	$PSL_Z,$0,$4,r11	# clear all codes except z-bit

	extzv	$1,$4,r4,r3		# excess byte count to r3
	beql	L125			# skip to single digit code
	addl3	r3,r5,r7		# remember address of sign byte
	addl3	$1,r7,r5		# point r5 beyond end of product string

8:	movl	(sp)+,r1		# remove next value from stack
	beql	9f			# do not clear z-bit if zero
	bicb2	$PSL_Z,r11		# clear z-bit

9:	movb	_decimal_binary_to_packed_table[r1],-(r5)
					# store converted sum byte
	decl	r9			# one less element on the stack
	bleq	L116			# exit loop if result array exhausted
	sobgtr	r3,8b			# keep going?

L200:	blbc	r4,L220			# different for even digit count

 # the output string consists of an odd number of digits. a complete digit
 # pair can be stored in the most significant (lowest addressed) byte of
 # the product string.

	movl	(sp)+,r1		# remove next value from stack
	beql	L210			# do not clear z-bit if zero
	bicb2	$PSL_Z,r11		# clear z-bit

L210:	movb	_decimal_binary_to_packed_table[r1],-(r5)
					# store converted sum byte
	decl	r9			# one less element on the stack
	bleq	L116			# exit loop if result array exhausted
	brb	L140			# perform overflow check

 # this loop executes if the result array has fewer elements than the output
 # string. the remaining bytes in the output string are filled with zeros.
 # there is no need for an overflow check.

L114:	clrb	-(r5)			# store another zero byte
L116:	sobgeq	r3,L114			# any more room in output string

	brb	L150			# determine sign of result

 # this code path is used in the case where the output digit count is 0 or 1.
 # r5 must be advanced 

L125:	movl	r5,r7			# remember address of output sign byte
	incl	r5			# advance r5 so common code can be used
	brb	L200			# join common code path

 # the output string consists of an even number of digits. only the low order 
 # nibble is stored in the most significant (lowest addresses) byte. a zero is 
 # stored in the high order nibble. if the high order digit would have been 
 # nonzero, the v-bit is set and the overflow check is bypassed because there 
 # are faster ways to clean the stack if we do not have to check for nonzero 
 # at the same time.

L220:	movl	(sp)+,r1		# remove next value from stack
	movb	_decimal_binary_to_packed_table[r1],r1
					# obtain converted sum byte

	bicb3	$0x0f0,r1,-(r5)		# store byte, clearing high order nibble
	beql	L130			# do not clear z-bit if zero
	bicb2	$PSL_Z,r11		# clear z-bit
L130:	bitb	$0x0f0,r1		# is high order nibble nonzero?
	bneq	L133			# yes, go set overflow bit
	decl	r9			# one less element on the stack
	bleq	L116			# exit loop if result array exhausted
	brb	L140			# check rest of result array for nonzero

 # if we detect overflow, we need to adjust r9 to reflect the nonzero longword
 # removed from the stack before we enter the next code block that sets the
 # v-bit and cleans off the stack based on the contents of r9. 

L133:	decl	r9			# one more longword removed from stack

 # a nonzero digit has been discovered in a position that cannot be stored in 
 # the output string. set the v-bit, remove the rest of the product array from
 # the stack, and join the exit processing in the code that determines the sign
 # of the product.

L135:	bisb2	$PSL_V,r11		# set the overflow bit 
	moval	(sp)[r9],sp		# clean off remaining product string
	brb	L150			# go to code that determines the sign

 # the remainder of the product array must be removed from the stack. a nonzero
 # result causes the v-bit to be set and the rest of the loop to be skipped.
 # note that there is always a nonzero loop count remaining at this point.

L140:	tstl	(sp)+			# is next longword zero?
	bneq	L133			# no, leave loop
	sobgtr	r9,L140

 # the final product string has been stored and the v- and z-bits have their
 # correct settings. the sign of the product must be determined from the
 # signs of the two input strings. opposite signs produce a negative product.
 # same signs (in any representation) produce a plus sign in the output string.

L150:	addl2	$8,sp			# discard saved string descriptor
	movl	$12,r6			# assume final result is positive
	movq	(sp),r0			# retrieve original r0/r1 pair
	extzv	$1,$4,r0,r0		# get byte count for first input string
	addl2	r0,r1			# point r1 to byte containing sign

	bicb3	$0x0f0,(r1),r0		# r0 contains the sign "digit"

        caseb   r0,$10,$15-10		# dispatch on sign digit
L5:
        .word   2f-L5                  # 10 => sign is "+"
        .word   1f-L5                  # 11 => sign is "-"
        .word   2f-L5                 # 12 => sign is "+"
        .word   1f-L5                  # 13 => sign is "-"
        .word   2f-L5                  # 14 => sign is "+"
        .word   2f-L5                  # 15 => sign is "+"

1:	movl	$1,r4			# count a minus sign
	brb	L230			# now check second input sign

2:	clrl	r4			# no real minus signs so far

L230:	movq	8(sp),r2		# retrieve original r2/r3 pair
	extzv	$1,$4,r2,r2		# get byte count for second input string
	addl2	r2,r3			# point r3 to byte containing sign

	bicb3	$0x0f0,(r3),r2		# r2 contains the sign "digit"

        caseb   r2,$10,$15-10           # dispatch on sign digit
L6:
        .word   5f-L6                  # 10 => sign is "+"
        .word   4f-L6                  # 11 => sign is "-"
        .word   5f-L6                  # 12 => sign is "+"
        .word   4f-L6                  # 13 => sign is "-"
        .word   5f-L6                  # 14 => sign is "+"
        .word   5f-L6                  # 15 => sign is "+"

4:	incl	r4			# remember that sign was minus
5:	blbc	r4,L260			# even parity indicates positive result
	bbs	$2,r11,L270		# step out of line for minus zero check
	bisb2	$PSL_N,r11		# set n-bit in saved psw
L255:	incl	r6			# change sign to minus

L260:	insv	r6,$0,$4,(r7)		# store sign in result string
	clrl	16(sp)			# set saved r4 to zero
	jmp	_EM_decimal_exit	# join common exit code

 # if the result is negative zero, then it must be changed to positive zero
 # unless overflow has occurred, in which case, the sign is left as negative
 # but the n-bit is clear.

L270:	bbs	$1,r11,L255		# make sign negative if overflow
	brb	L260			# sign will be positive

 #
 #+ extend_string_multiply
 # functional description:
 #
 #	this routine multiplies an array of numbers (each array element lequ 
 #	99) by a number (also lequ 99). the resulting product array is added 
 #	to another array, each of whose elements is also lequ 99.
 #
 # input parameters:
 #
 #	r3 - pointer to output array
 #	r4 - input array size
 #	r5 - input array address
 #	r6 - multiplier 
 #
 # output parameters:
 #
 #	none
 #
 # implicit output:
 #
 #	the output array is altered.
 #
 #	an intermediate product array is produced by multiplying each input
 #	array element by the multiplier. each product array element is then
 #	added to the corresponding output array element. 
 #
 # side effects:
 #
 #	r3, r4, and r5 are modified by this routine.
 #
 #	r6 is preserved.
 #
 #	r0, r1, and r2 are used as scratch registers. r0 and r1 contain the
 #	quadword result of emul that is then passed into ediv.
 #
 # assumptions:
 #
 #	this routine assumes that all array elements lie in the range from 0 
 #	to 99 inclusive. (this is true if all input strings contain only legal 
 #	decimal digits.) the arithmetic performed by this routine will 
 #	maintain this assumption. that is, 
 #
 #		             input array element    lequ 99
 #		times                 multiplier    lequ 99
 #		        ------------------------
 #		                         product              lequ 99*99
 #		plus                       carry    lequ 99
 #		        ------------------------
 #		                modified product              lequ 99*100
 #		plus    old output array element    lequ 99
 #		        ------------------------
 #		        new output array element              lequ 99*101 = 9999
 #
 #	a number lequ 9999, when divided by 100, is guaranteed to produce both 
 #	a quotient and a remainder lequ 99.
 #-

extend_string_multiply:
	clrl	r2			# initial carry is zero

1:	emul	r6,(r5)+,r2,r0		# form modified product (r0 lequ 9900)
	addl2	(r3),r0			# add old output array element
	ediv	$100,r0,r2,(r3)+	# remainder to output array
					# quotient becomes carry
	sobgtr	r4,1b			# keep going?

 # this remaining code looks more complicated than it actually is. in the 
 # usual case, the routine exits immediately. in the event that a carry 
 # occurs, one additional entry in the output array will be modified. only in 
 # the rare case of an output array consisting of a string of 99s will any 
 # significant looping occur.

	addl2	r2,(r3)			# add final carry
2:	cmpl	(r3),$100		# do we overflow into next digit pair?
	bgequ	3f			# branch if carry
	rsb				# otherwise, all done

3:	subl2	$100,(r3)+		# readjust entry and advance pointer
	incl	(r3)			# propogate carry
	brb	2b			# ... and test this entry for overflow

 #
 #+ DIVP
 # functional description:
 #
 #	the dividend string  specified  by  the  dividend  length  and  dividend
 #	address  operands  is  divided  by  the  divisor string specified by the
 #	divisor length  and  divisor  address  operands.   the  quotient  string
 #	specified  by  the  quotient  length  and  quotient  address operands is
 #	replaced by the result.
 #
 # input parameters:
 #
 #	r0 - divrlen.rw		number of digits in divisor string
 #	r1 - divraddr.ab	address of divisor string
 #	r2 - divdlen.rw		number of digits in dividend string
 #	r3 - divdaddr.ab	address of dividend string
 #	r4 - quolen.rw		number of digits in quotient string
 #	r5 - quoaddr.ab		address of quotient string
 #
 # output parameters:
 #
 #	r0 = 0
 #	r1 = address of the byte containing the most significant digit of
 #	     the divisor string
 #	r2 = 0
 #	r3 = address of the byte containing the most significant digit of
 #	     the dividend string
 #	r4 = 0
 #	r5 = address of the byte containing the most significant digit of
 #	     the string containing the quotient
 #
 # condition codes:
 #
 #	n <- quotient string lss 0
 #	z <- quotient string eql 0
 #	v <- decimal overflow
 #	c <- 0
 #
 # register usage:
 #
 #	this routine uses all of the general registers. the condition codes
 #	are computed at the end of the instruction as the final result is
 #	stored in the quotient string. r11 is used to record the condition
 #	codes.
 #
 # algorithm:
 #
 #	this algorithm is the straightforward approach described in
 #
 #		the art of computer programming
 #		second edition
 #
 #		volume 2 / seminumerical algorithms
 #		donald e. knuth
 #
 #		1981
 #		addison-wesley publishing company
 #		reading, massachusetts
 #
 # notes:
 #
 #	the choice of a longword array to store the auotient deserves a 
 #	comment. in vax$mulp, a longword array was used because its elements 
 #	were used directly by mulp and divp instructions. the use of longwords 
 #	eliminated the need to convert back and forth between longwords and 
 #	bytes. in this routine, the quotient_digit routine returns its result 
 #	in a register, which result can easily be stored in whatever way is 
 #	convenient. by using longwords instead of bytes, this routine can use 
 #	the same end processing code as mulp, a sizeable savings in code.
 #-


 #+
 # this code path is entered if the divisor is zero.
 #
 # input parameters:
 #
 #	  (sp) - saved R0..R9
 #	40(sp) - return pc to same-mode emulator dispatcher
 #
 # output parameters:
 #
 #	saved regs and return PC popped off the stack
 #	 8(sp) = SIGFPE (arithmetic exception)
 #	12(sp) - FPE_FLTDIV_TRAP (arithmetic trap code for decimal divide by 0)
 #	40(sp) - points at the next instruction (trap)
 #
 # implicit output:
 #
 #	control passes through this code to _EM_signal_exception.
 #
 # note:
 #
 #	R0-R5 and condition codes are UNPREDICTABLE per VARM on this exception,
 #	so we don't bother to set output registers or save condition codes.
 #-

1:	PANIC("decimal divide by zero in kernel")
divide_by_zero:
 #	popr	$^m<r0,r1,r2,r3,r4,r5,r6,r7,r8,r9>	
	 popr	$0x03ff
					# restore registers and reset sp
	addl2	$4,sp			# pop jsb return address
	movpsl	r10
	bitl	$PSL_CURMOD,r10
	beql	1b
	movl	$SIGFPE,8(sp)
	movl	$FPE_FLTDIV_TRAP,12(sp)
	jmp	_EM_signal_exception

 # if the divisor contains more nonzero digits than the dividend, then the
 # quotient will be identically zero. set up the stack and the registers (r4,
 # r5, and r9)  so that the exit code will be entered to produce this result.

L301:	clrl	-(sp)			# fake a quotient digit
	movl	$1,r9			# count that digit
	brw	multiply_divide_exit	# store the zero in the output string

	.globl	_EMdivp
_EMdivp:
	movzwl	operand_1(sp),r0	# r0<15:0> <- divrlen.rw 
	movl	operand_2(sp),r1	# r1       <- divraddr.ab 
	movzwl	operand_3(sp),r2	# r2<15:0> <- divdlen.rw 
	movl	operand_4(sp),r3	# r3       <- divdaddr.ab 
	movzwl	operand_5(sp),r4	# r4<15:0> <- quolen.rw 
	movl	operand_6(sp),r5	# r5       <- quoaddr.ab 
	.globl	_EMLdivp
_EMLdivp:
 #	pushr	$^m<r0,r1,r2,r3,r4,r5,r6,r7,r8,r9>	# save the lot
	 pushr	$0x03ff

 #	roprand_check	r4			# insure that r4 is lequ 31
	 cmpl	r4,$31
	 blequ	1f
	 brw	decimal_roprand
1:

 #	roprand_check	r2			# insure that r2 is lequ 31
	 cmpl	r2,$31
	 blequ	1f
	 brw	decimal_roprand
1:
	jsb	_EM_decimal_strip_zeros_r2_r3	# strip high order zeros from r2/r3 string

 #	roprand_check	r0			# insure that r0 is lequ 31
	 cmpl	r0,$31
	 blequ	1f
	 brw	decimal_roprand
1:
	jsb	_EM_decimal_strip_zeros_r0_r1	# strip high order zeros from r0/r1 string

 # insure that the divisor is not zero. because leading zeros have already
 # been eliminated, the divisor can only be zero if r0 is 0 (zero length
 # strings are identically zero) or 1 (r1 contains a sign digit in the low
 # order nibble and zero in the high order nibble). note that an exception
 # will not be generated if an even length string has an illegal nonzero digit
 # stored in its most significant nibble (including an illegal form of a zero
 # length string. 

	extzv	$1,$4,r0,r0		# convert divisor digit count to bytes
	bneq	1f			# skip zero divisor check unless zero

	bitb	$0x0f0,(r1)		# check for zero in ones digit
	beql	divide_by_zero		# generate exception if zero

 # this routine chooses to do its work with a fair amount of internal storage,
 # all of it allocated on the stack. the quotient is stored as it is computed,
 # in a 16-longword array. the dividend and divisor are stored as longword arrays,
 # with each array element storing a digit pair from the original packed 
 # decimal string. the numerator digits are shifted by one digit (multiplied
 # by ten) so that the quotient has its digits correctly placed, leaving room
 # for a sign in the low order nibble of the least significant byte. a scratch
 # array is also allocated on the stack to accommodate intermediate results
 # of the quotient_digit routine.

1:	incl	r0			# include least significant digit
	movq	r0,r8			# let r8 and r9 describe the divisor

	extzv	$1,$4,r2,r2		# convert dividend digit count to bytes
	incl	r2			# include least significant digit
	movq	r2,-(sp)		# save dividend descriptor on stack

	subl3	r0,r2,r6		# calculate main loop count
	blssu	L301			# quotient will be zero
	incl	r6			# one extra digit is always there
	
 # allocate r6 longwords of zero on the stack

	movl	r6,r0			# let r0 be the loop counter
5:	clrl	-(sp)			# set aside another quotient digit
	sobgtr	r0,5b			# keep going 

	movl	sp,r7			# remember where this array starts

 # the divisor will be stored on the stack as an array of 
 # longwords. each array element contains a number between 0 and 99, 
 # representing a pair of digits in the original packed decimal string. 
 # because the units digit is stored with the sign in packed decimal format, 
 # it is necessary to shift the number as we store it. this is accomplished by 
 # multiplying the number by ten.
 #
 # the divisor string is described by r8 (byte count) and r9 (address of most
 # significant digit pair).

	addl3	r9,r8,r5		# point r5 beyond sign digit
	movl	r8,r4			# r4 contains the loop count

 # put in an extra digit place for the divisor. this allows several common
 # subroutines to be used when operating on the divisor string.

	clrl	-(sp)			# set aside a place holder

 # an array of longwords is allocated on the stack. r3 starts out pointing
 # at the longword beyond the top of the stack. the first remainder, guaranteed
 # to be zero, is "stored" here. the rest of the digit pairs are stored safely
 # below the top of the stack.

	mnegl	r8,r3			# stack grows toward lower addresses
	moval	(sp)[r3],sp		# allocate the space
	subl3	$4,sp,r3		# point r3 at next lower longword

2:	movzbl	-(r5),r1		# get next digit pair
	movzbl	_decimal_packed_to_binary_table[r1],r1
					# convert digits to binary
	emul	$10,r1,r2,r0		# multiply by 10
	ediv	$100,r0,r2,(r3)+	# divide by 100
	sobgtr	r4,2b	

 # there are two cases where the final quotient (contents of r2) is zero.
 # in these cases, the number of nonzero digit pairs in the divisor array is
 # smaller by one than the number of bytes containing the original packed decimal
 # string. one case is a divisor string with an even number of digits. the
 # second case is a divisor string with an odd number of digits but the most
 # significant digit is zero (essentially a variant of the first case). the
 # simplest way to handle all of these cases is to decrement r8, the divisor 
 # counter, if r2 is zero. note that previous checks for a zero divisor
 # prevent r8 from going to zero.

	movl	r2,(r3)			# store final quotient
	bneq	L425			# leave well enough alone if nonzero
	incl	r6			# one more quotient digit
	subl2	$4,r7			# make room for it
	decl	r8			# count one less divisor "digit"
	bneq	L425

 ### ************* Begin Temp ************
 ### the following halt instruction should be replaced with the correct
 ### abort code.
 ###
 ### the halt is similar to the
 ###
 ###	Microcode cannot get here
 ###
 ### Errors that other implementations use.
 ###
	halt				# This will cause an opcdec exception
 ###
 ### ********** End Temp ********

L425:	movl	sp,r9			# r9 locates low order divisor digit 

 # the dividend is stored on the stack as an array of longwords. it does not
 # have its digit pairs shifted so that this storage loop is simpler. an extra
 # place is set aside in the event that it is necessary to normalize the
 # dividend and divisor before division is attempted.

	clrl	-(sp)			# set aside space for u[0]
	moval	(r7)[r6],r2		# retrieve dividend descriptor
	movq	(r2),r2			# ... in two steps

3:	movzbl	(r3)+,r1		# get next decimal digit pair
	movzbl	_decimal_packed_to_binary_table[r1],-(sp)
					# convert digits to binary
	sobgtr	r2,3b			# loop through entire input string

 # from this point until the common exit path for mulp and divp is entered, 
 # no access violations that need to be backed out can occur. we do not need 
 # to keep the address of arith_accvio in r10 for this stretch of code. note 
 # that r10 must be reloaded before the exit code executes because the 
 # destination string is written and may cause access violations.

	movl	(r7)[r6],r10		# retrieve size of dividend array
	movl	sp,r11			# r11 locates low order dividend digit 

 # allocate a scratch array on the stack the same size as the divisor array 
 # (which is one larger than the number of digit pairs)

	mnegl	r8,r2			# need a negative index
	moval	-4(sp)[r2],sp		# adjust stack pointer

 #+
 # at this point, the stack and relevant general registers contain the
 # following information. in this description, n represents the number
 # of digit pairs in the divisor and m represents the number of digit
 # pairs in the dividend.
 #
 #                   +------------------------------+ <-- sp
 #     scratch       |        n+1 longwords         |
 #                   +------------------------------+ <-- r11
 #     dividend      |        m+1 longwords         |
 #                   +------------------------------+ <-- r9
 #     divisor       |        n+1 longwords         |
 #                   +------------------------------+ <-- r7
 #     quotient      |       m+1-n longwords        |
 #                   +------------------------------+
 #                   |           r0..r11            |
 #                   +------------------------------+
 #
 #	r6  - number of longwords in quotient array (m+1-n)
 #	r7  - address of beginning of quotient array
 #	r8  - number of digit pairs in divisor (called n)
 #	r9  - address of low order digits in divisor
 #	r10 - number of digit pairs in dividend (called m)
 #	r11 - address of low order digits in dividend
 #-

	pushal	(sp)			# store address of scratch array
	movq	r8,-(sp)		# remember divisor descriptor
	movq	r10,-(sp)		# remember dividend descriptor

 # the algorithm that guesses the quotient digit can be guaranteed to be off
 # by no more than two if the high order digit of the divisor (called v[1]) is
 # at least as large as 50 (our radix divided by 2). if the high order digit
 # is too small, we "normalize" the numerator and denomonator by multiplying
 # them by the same number, namely 100/(v[1]+1). 

	addl3	$1,-4(r9)[r8],r0	# compute v[1] + 1
	cmpl	r0,$51			# compare to 50 + 1
	bgeq	L440			# skip normalization if v[1] big enough
	divl3	r0,$100,r3		# compute normalization factor
	movq	r8,r4			# get descriptor of divisor
	bsbw	multiply_string		# normalize divisor
	movq	r10,r4			# get descriptor of dividend
	bsbw	multiply_string		# normalize dividend

 # we have now reached the point where we can start calculating quotient digits.
 # in the following loop, r5 and r6 are loop invariants. r5 contains the number
 # of digit pairs in the divisor. r6 always points to the longword beyond the
 # most significant digit in the dividend string. r7 and r8 must be loaded on
 # each pass through because these two pointers are modified. notice that the
 # address of the divisor array is exactly what we want to store in r6.

L440:	movq	r6,r10			# let r10/r11 describe quotient and loop
	pushl	r11			# save quotient address for exit code
	moval	(r11)[r10],r11		# store quotient digits from high end

 # this rather harmless looking loop is where the work is done

	movq	r8,r5			# initialize count and dividend address
	movl	r10,r9			# remember the loop count in r9

L450:	movq	16(sp),r7		# load divisor and scratch addresses
	bsbw	quotient_digit		# get the next quotient digit
	movl	r3,-(r11)		# store it
	subl2	$4,r6			# "advance" dividend pointer
	sobgtr	r10,L450			# ... and go gack for more

 # the quotient digits have been stored on the stack. eliminate the rest of the
 # stack storage and enter the completion code that this routine shares with
 # vax$mulp. note that r9 is already set up with the longword count used by 
 # the exit code. note also that r11 is pointing to the saved dividend descriptor
 # that sits on top of the saved register array.

	movl	(sp),sp			# reset stack pointer
 #	moval	< <4*2> + -		# skip over saved dividend descriptor
 #		  <4*4> >(r11)[r9],r4	#  and retrieve original r4 and r5
	 moval	( (4*2) + (4*4) )(r11)[r9],r4	# 001
	movq	(r4),r4			# ... in two steps

 # the following is a hack.
 #
 # the method used to obtain quotient digits generally leaves garbage (nonzero)
 # in what will become the sign digit. (in fact, this is the tenths digit of a
 # decimal expansion of the remainder.) we need to make the least significant
 # digit a multiple of ten. 

	divl3	$10,(sp),r0		# divide by ten, losing remainder
	mull3	$10,r0,(sp)		# store only tens digit

	brw	multiply_divide_exit	# join common exit code

 #
 #+ quotient_digit
 # functional description:
 #
 #	this routine divides an (n+1)-element array of longwords by an n-element 
 #	array, producing a single quotient digit in the range of 0 to 99 
 #	inclusive. the dividend array is modified by subtracting the product 
 #	of the divisor array and the quotient digit. 
 #
 #	the "numbers" that this array operates on multiple precision numbers 
 #	in radix 100. each digit (a number between 0 and 99) is stored in a 
 #	longword array element with more significant digits stored at higher 
 #	addresses. the dividend string and the scratch string (also called the
 #	product string) contain one more element than the divisor string. 
 #
 # input parameters:
 #
 #	r5 - number of "digits" (array elements) in divisor array (preserved)
 #	r6 - address of longword immediately following most significant
 #		digit of dividend string (preserved)
 #	r7 - address of least significant digit in divisor string (modified)
 #	r8 - address of least significant digit in product string (modified)
 #
 # output parameters:
 #
 #	r3 - the quotient that results from dividing the dividend string
 #		by the divisor string.
 #
 #	the final states of the three pointer registers are listed here
 #	for completeness.
 #
 #	r6 - address of longword immediately following most significant
 #		digit of dividend string
 #
 #	r7 - address of longword immediately following most significant digit 
 #		of divisor string. this longword must always contain zero.
 #
 #	r8 - address of longword immediately following most significant
 #		digit of product string
 #
 # implicit output:
 #
 #	the contents of the dividend array are modified to reflect the 
 #	subtraction of the product string. the result of this subtraction 
 #	could be stored elsewhere. it is a convenience to store it in the 
 #	dividend array on top of those array elements that are no longer 
 #	needed.
 #
 #	the contents of the divisor array are preserved.
 #
 # side effects:
 #
 #	r7 and r8 are modified by this routine. (see implicit output list.)
 #
 #	r5 and r6 are preserved.
 #
 #	r0, r1, r2, and r4 are used as scratch registers. r0 and r1 contain the
 #	quadword result of emul that is then passed into ediv. r2 is the
 #	carry from one step to the next. r4 is the loop counter.
 #-

quotient_digit:
	emul	$100,-4(r6),-8(r6),r0	# r0 <- 100 * u[j] + u[j+1]
	divl2	-4(r7)[r5],r0		# r0 <- r0 / v[1]
	movl	r0,r3			# store quotient "digit" in r3
	beql	L545			# nothing to do if quotient is zero
	cmpl	r3,$100			# is quotient lequ 99?
	blssu	L505			# branch if quotient ok
	movl	$99,r3			# otherwise start with 99

 # we will now multiply the divisor array by the quotient digit, storing the     
 # product in the scratch array.

L505:	clrl	r2			# start out with a carry of zero
	movl	r5,r4			# r4 will be the loop counter

1:	emul	r3,(r7)+,r2,r0		# multiply next divisor digit
	ediv	$100,r0,r2,(r8)+	# remainder to input array
					# quotient becomes carry
	sobgtr	r4,1b			# more divisor digits?

	movl	r2,(r8)+		# store final carry

 # if the product array is larger than the dividend array, then the quotient is
 # too large. to avoid a second trip through the rather costly emul/ediv loop,
 # and also to avoid array subtraction that produces a negative result, we will
 # first compare the product and dividend arrays. if the product is smaller, we
 # can safely subtract. if the product is larger, we decrease the quotient by 
 # one and subtract the divisor array from the product array.

L515:	movl	r6,r0			# point r0 and r1 to high address ends
	movl	r8,r1			# ... of dividend and scratch strings
	movl	r5,r4			# initialize the loop counter

 # the comparison is done from most to least significant digits

L520:	cmpl	-(r1),-(r0)		# compare next pair of digits
	blssu	L530			# leave loop if product is smaller
	bgtru	L550			# also leave if product is larger
	sobgeq	r4,L520			# more to test?

 # if we drop through the loop, then the dividend and product are equal. we
 # simply store zeros in the dividend array (the equivalent of subtraction
 # of equal arrays) and return. note that r0 is already pointing to the
 # least significant dividend array element.

	movl	r5,r4			# initialize still another loop counter

2:	clrl	(r0)+			# store another zero
	sobgeq	r4,2b			# keep going?

	rsb				# return to caller

 # if we drop through the loop, then the quotient that is stored in r3 is good.
 # we need to subtract the product array from the dividend array. note that r0
 # and r1 need to be adjusted to point to the least significant array elements
 # before the subtraction can begin.

L530:	mnegl	r4,r4			# we need a negative index
	moval	(r0)[r4],r0		# adjust dividend pointer
	moval	(r1)[r4],r1		# ... and product pointer
	movl	r5,r4			# r4 will count still another loop 

L535:	subl2	(r1)+,(r0)+		# subtract next digits
	bgeq	L540			# skip to end of loop if no borrow
	addl2	$100,-4(r0)		# add borrow back to this digit
	decl	(r0)			# ... and borrow from next highest digit
L540:	sobgeq	r4,L535			# keep going?

 # this is the exit path. r3 contains the quotient digit. the pointers to the
 # various input and scratch arrays are in an indeterminate state.

L545:	rsb				# return to caller

 # the first guess at the quotient digit is too large. the brute force
 # approach is to decrement the quotient by one and execute the emul/ediv loop
 # again. note, however, that we can evaluate the modified product by
 # subtracting the divisor from the initial product. note also that, because
 # the leading digit in the divisor is "large enough", we can only end up in
 # this code path twice. (that is, the initial guess at the quotient will
 # never be off by more than two.) 

L550:	decl	r3			# try quotient smaller by one
	beql	L545			# all done if zero

 # point r1 and r2 at the least significant digits of the scratch and product
 # strings respectively.

	mnegl	r5,r0			# need a negative index
	moval	-4(r8)[r0],r1		# scratch array contains n+1 elements
	moval	(r7)[r0],r2		# product array contains n elements
	movl	r5,r4			# r4 will count still another loop

L560:	subl2	(r2)+,(r1)+		# subtract next digits
	bgeq	L570			# skip to end of loop if no borrow
	addl2	$100,-4(r1)		# add borrow back to this digit
	decl	(r1)			# ... and borrow from next highest digit
L570:	sobgeq	r4,L560			# keep going?

	addl2	$4,r1			# point r1 at most significant digit
	brb	L515			# make another comparison

 #
 #+ multiply_string
 # functional description:
 #
 #	this routine multiplies an array of numbers (each array element lequ 
 #	99) by a number (also lequ 99). each array element in the input array
 #	is replaced with the modified product, with the carry propogated to
 #	the next array element.
 #
 # input parameters:
 #
 #	r3 - multiplier 
 #	r4 - input array size
 #	r5 - input array address
 #
 # output parameters:
 #
 #	none
 #
 # implicit output:
 #
 #	the input array elements are altered.
 #
 # side effects:
 #
 #	r4 and r5 are modified by this routine.
 #
 #	r3 is preserved.
 #
 #	r0, r1, and r2 are used as scratch registers. r0 and r1 contain the
 #	quadword result of emul that is then passed into ediv. r2 is the
 #	carry from one step to the next.
 #
 # assumptions:
 #
 #	this routine assumes that all array elements lie in the range from 0
 #	to 99 inclusive. (this is true if all input strings contain only legal
 #	decimal digits.) the arithmetic performed by this routine will
 #	maintain this assumption. the details of this argument can be found in
 #	the routine header for extended_multiply_string. this routine performs
 #	less work so that those arguments also apply here. 
 #-

multiply_string:
	clrl	r2			# initial carry is zero

1:	emul	r3,(r5),r2,r0		# form modified product (r0 lequ 9900)
	ediv	$100,r0,r2,(r5)+	# remainder to input array
					# quotient becomes carry
	sobgtr	r4,1b			# keep going?

	movl	r2,(r5)			# store final carry
	rsb


 #
 #-
 # functional description:
 #
 #	this routine receives control when a digit count larger than 31
 #	is detected. the exception is architecturally defined as an
 #	abort so there is no need to store intermediate state. all of the
 #	routines in this module save all registers r0 through r9 before
 #	performing the digit check. these registers must be restored
 #	before control is passed to _EM_reserved_operand.
 #
 # input parameters:
 #
 #	00(sp) - saved r0
 #	  .
 #	  .
 #	36(sp) - saved r9
 #	40(sp) - return pc from dispatcher
 #
 # output parameters:
 #
 #	saved r0..r9 popped from the stack
 #
 # implicit output:
 #
 #	this routine passes control to _EM_reserved_operand where further
 #	exception processing takes place.
 #-


decimal_roprand:
 #	popr	$^m<r0,r1,r2,r3,r4,r5,r6,r7,r8,r9>
	 popr	$0x03ff
	jmp	_EM_reserved_operand		# pass control along

#endif NEED_SAMEMODE_EMU
E 1
