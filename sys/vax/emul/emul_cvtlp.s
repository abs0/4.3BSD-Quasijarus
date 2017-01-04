/*
 * VAX CVTLP instruction emulation
 * Ported from DEC Ultrix to 4.3BSD-Quasijarus by Michael Sokolov
 *
 *	@(#)emul_cvtlp.s	7.1 (Berkeley) 1/11/04
 */

#include "../vax/cpucond.h"
#ifdef NEED_SAMEMODE_EMU

#include "../vax/psl.h"


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
 #       vax-11 instruction emulator
 #
 # abstract:
 #       the routine in this module emulates the vax-11 packed decimal 
 #       cvtlp instruction. this procedure can be a part of an emulator 
 #       package or can be called directly after the input parameters 
 #       have been loaded into the architectural registers.
 #
 #       the input parameters to this routine are the registers that
 #       contain the intermediate instruction state. 
 #
 # environment: 
 #
 #       this routine runs at any access mode, at any ipl, and is ast 
 #       reentrant.
 #
 # author: 
 #
 #       lawrence j. kenah       
 #
 # creation date
 #
 #       18 october 1983
 #
 # modified by:
 #
 #	 v01-004 ljk0040	 Lawrence j. Kenah	 24-jul-1984
 #		 Do not use INCL instruction to modify the contents of
 #		 the sign byte of the output string.
 #
 #	 v01-003 ljk0032	 Lawrence j. Kenah	  5-jul-1984
 #		 Fix restart routine to take into account the fact that
 #		 restart codes are based at one when computing restart PC.
 #
 # 	 v01-002 ljk0024	 lawrence j. kenah	 22-Feb-1984
 #		 Add code to handle access violation. Perform minor cleanup.
 #
 #       v01-001 ljk0008         lawrence j. kenah       18-oct-1983
 #               the emulation code for cvtlp was moved into a separate module.
 #--

#define	operand_1	12
#define	operand_2	16
#define	operand_3	20
#define	operand_4	24
#define	operand_5	28
#define	operand_6	32

 #+ CVTLP
 # functional description:
 #
 #     the source operand is converted to  a  packed  decimal  string  and  the
 #     destination  string  operand  specified  by  the  destination length and
 #     destination address operands is replaced by the result.
 #
 # input parameters:
 #
 #       r0 - src.rl             input longword to be converted
 #       r2 - dstlen.rw          length of output decimal string
 #       r3 - dstaddr.ab         address of output packed decimal string
 #
 # output parameters:
 #
 #       r0 = 0
 #       r1 = 0
 #       r2 = 0
 #       r3 = address of byte containing most significant digit of
 #            the destination string
 #
 # condition codes:
 #
 #       n <- destination string lss 0
 #       z <- destination string eql 0
 #       v <- decimal overflow
 #       c <- 0
 #
 # register usage:
 #
 #       this routine uses r0 through r5 and r11 as scratch registers. r10
 #	 serves its usual function as an access violation routine pointer. the
 #	 condition codes are stored in r11 as the routine executes.
 #
 # notes:
 #
 ###     the following comment needs to be updated to reflect the revised
 ###     algorithm.
 #
 #       the algorithm used in this routine builds the packed decimal from 
 #	least significant digit to most significant digit. the least
 #	significant digit is obtained by dividing the input longword by 10 and
 #	storing the remainder as the least significant digit. the rest of the
 # 	result is obtained by taking the quotient from the first step,
 #	repeatedly dividing by 100, and converting the resulting remainder
 #	into a pair of packed decimal digits. this process continues until the
 #	quotient goes to zero. 
 #
 #	no special processing is observed for an input longword of zero. the
 #	correct results for this case drops out of normal processing. 
 #-

	.globl	_EMcvtlp
_EMcvtlp:
	movl	operand_1(sp),r0	# r0       <- src.rl 
	movzwl	operand_2(sp),r2	# r2<15:0> <- dstlen.rw 
	movl	operand_3(sp),r3	# r3       <- dstaddr.ab 
	.globl	_EMLcvtlp
_EMLcvtlp:
 #      pushr   $^m<r4,r5>		# save some registers
	 pushr	$0x0030

 # get initial settings for condition codes. the initial settings for v and c
 # will be zero. the initial setting of n depends on the sign of the source
 # operand. the z-bit starts off set and remains set until a nonzero digit is
 # stored in the output string. note that the final z-bit may be set for
 # nonzero input if the output string is not large enough. (the v-bit is set
 # in this case.) in this case, the saved dv bit will determine whether to
 # reflect an exception or merely report the result to the caller. 

        movpsl  r11                     # get dv bit from psl on input
        insv    $PSL_Z,$0,$4,r11	# start with z-bit set, others clear
 #      roprand_check   r2              # insure that r2 lequ 31
	 cmpl	r2,$31
	 blequ	1f
	 brw	decimal_roprand
1:
        ashl    $-1,r2,r1               # convert digit count to byte count
        addl2   r1,r3                   # get address of sign byte
        movb    $12,(r3)                # assume that sign is plus
 #	clrl     r1                      # prepare r1 for input to ediv
        tstl    r0                      # check sign of source operand
        bgeq    1f                      # start getting digits if not negative

 # source operand is minus. we remember that by setting the saved n-bit but work
 # with the absolute value of the input operand from this point on.

        incb    (r3)                    # convert "+" to "-" (12 -> 13)
        mnegl   r0,r0                   # normalize source operand
        bisb2   $PSL_N,r11		# set n-bit in saved psw

 #+ 
 # the first (least significant) digit is obtained by dividing the source 
 # longword by ten and storing the remainder in the high order nibble of the
 # sign byte. note that at this point, the upper four bits of the sign byte
 # contain zero.
 #-

1:	clrl	r1			# prepare r1 for input to ediv
        movl    r2,r4                   # special exit if zero source length
        beql    9f                      # only overflow check remains
        ediv    $10,r0,r0,r5            # r5 gets remainder, first digit
        ashl    $4,r5,r5                # shift digit to high nibble position
        beql    2f                      # leave z-bit alone if digit is zero
        bicb2   $PSL_Z,r11		# turn off z-bit if nonzero
        addb2   r5,(r3)                 # merge this digit with low nibble
2:      decl    r4                      # one less output digit
        beql    9f                      # no more room in output string
        ashl    $-1,r4,r4               # number of complete bytes remaining
        beql    8f                      # check for last digit if none
        tstl    r0                      # is source exhausted?
        bneq    3f                      # go get next digits if not
        clrb    -(r3)                   # store a pair of zeros
        brb     5f                      # fill rest of output with zeros

 #+
 # the following loop obtains two digits at a time from the source longword. it
 # accomplishes this by dividing the current value of r0 by 100 and converting
 # the remainder to a pair of decimal digits using the table that converts
 # binary numbers in the range from 0 to 99 to their packed decimal equivalents.
 # note that this technique may cause nonzero to be stored in the upper nibble
 # of the most significant byte of an even length string. this condition will
 # be tested for at the end of the loop.
 #-

3:      ediv    $100,r0,r0,r5           # r5 gets remainder, next digit
        movb    _decimal_binary_to_packed_table[r5],-(r3)
                                        # store converted remainder
        beql    4f                      # leave z-bit alone if digit is zero
        bicb2   $PSL_Z,r11		# turn off z-bit if nonzero
4:      tstl    r0                      # is source exhausted?
        beql    5f                      # exit loop is no more source
        sobgtr  r4,3b                   # check for end of loop
        
        brb     8f                      # check for remaining digit

 # the following code executes if the source longword is exhausted. if there
 # are any remaining digits in the destination string, they must be filled
 # with zeros. note that one more byte is cleared if the original input length
 # was odd. this includes the most significant digit and the unused nibble.

5:      blbs    r2,L65                  # one less byte to zero if odd input length

6:      clrb    -(r3)                  # set a pair of digits to zero
L65:    sobgtr  r4,6b                  # any more digits to zero?

 # the following code is the exit path for this routine. note that all code
 # paths that arrive here do so with r0 containing zero. r1 and r2, however,
 # must be cleared on exit. 

7:      clrq    r1                      # comform to architecture
	movl	r11,12(sp)		# set return cc
 #      popr    $^m<r4,r5>		# restore registers, preserving psw
	 popr	$0x0030
        rsb

 #+
 # the following code executes when there is no more room in the destination
 # string. we first test for the parity of the output length and, if even, 
 # determine whether a nonzero digit was stored in the upper nibble of the 
 # most significant byte. such a nonzero store causes an overflow condition.
 #
 # if the source operand is not yet exhausted, then decimal overflow occurs.
 # if decimal overflow exceptions are enabled, an exception is signalled.
 # otherwise, the v-bit in the psw is set and a normal exit is issued. note
 # that negative zero is only an issue for this instruction when overflow
 # occurs. in the no overflow case, the entire converted longword is stored in
 # the output string and there is only one form of binary zero. 
 #-

8:      blbs    r2,9f                   # no last digit if odd output length
        ediv    $10,r0,r0,r5            # get next input digit
        movb    r5,-(r3)                # store in last output byte
        beql    9f                      # leave z-bit alone if zero
        bicb2   $PSL_Z,r11

9:      tstl    r0                      # is source also all used up?
        beql    7b                     # yes, continue with exit processing

 # an overflow has occurred. if the z-bit is still set, then the n-bit is cleared. 
 # note that, because all negative zero situations occur simultaneously with
 # overflow, the output sign is left as minus. 

0:      clrl    r0                      # r0 must be zero on exit
        bbc     $2,r11,L110		# z-bit and n-bit cannot both be set
        bicb2   $PSL_N,r11		# clear n-bit if z-bit still set
L110:   bisb2   $PSL_V,r11		# set v-bit in saved psw

 # if the v-bit is set and decimal traps are enabled (dv-bit is set), then
 # a decimal overflow trap is generated. note that the dv-bit can be set in
 # the current psl or, if this routine was entered as the result of an emulated
 # instruction exception, in the saved psl on the stack.

	movl	88(sp),r10
	bitl	$PSL_DV,r10
	beql	7b
	bitl	$PSL_CURMOD,r10
	beql	7b

 # restore the saved registers and transfer control to decimal_overflow

L120:   clrq    r1                      # comform to architecture
 #      popr    $^m<r4,r5>		# restore registers
	 popr	$0x0030
	insv	r11,$0,$4,48(sp)	# set condition codes on trap
        jmp     _EM_decimal_overflow    # report overflow exception


 #-
 # functional description:
 #
 #       this routine receives control when a digit count larger than 31
 #       is detected. the exception is architecturally defined as an
 #       abort so there is no need to store intermediate state. the digit
 #       count is made after registers are saved. these registers must be
 #       restored before reporting the exception.
 #
 # input parameters:
 #
 #       00(sp) - saved r4
 #       04(sp) - saved r5
 #       08(sp) - return pc to same-mode emulator dispatcher
 #
 # output parameters:
 #
 #       00(sp) - return pc to same-mode emulator dispatcher
 #
 # implicit output:
 #
 #       this routine passes control to _EM_reserved_operand where further
 #       exception processing takes place.
 #-

decimal_roprand:
 #      popr    $^m<r4,r5>		# restore registers
	 popr	$0x0030
	jmp	_EM_reserved_operand	# pass control along

#endif NEED_SAMEMODE_EMU
