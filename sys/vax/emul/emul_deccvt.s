/*
 * VAX decimal string conversion instruction emulation
 * Ported from DEC Ultrix to 4.3BSD-Quasijarus by Michael Sokolov
 *
 *	@(#)emul_deccvt.s	7.1 (Berkeley) 1/11/04
 */

#include "../vax/cpucond.h"
#ifdef NEED_SAMEMODE_EMU

#include "../vax/psl.h"


/************************************************************************
 *									*
 *			Copyright (c) 1985, 1986 by			*
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
 *	Stephen Reilly, 17-Jul-86
 * 002- Fixed the problem which caused the cvtpt instruction not to work
 *	at all.  The cause of the problem was a bad expansion of a
 *	macro.
 *
 *	Stephen Reilly, 14-Nov-85
 * 001- Fixed a bad case statement that causes the cvtsp instruction
 *	to fail.
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
 #
 #	the routines in this module emulate the vax-11 instructions that
 #	convert between packed decimal strings and the various forms of
 #	numeric string. these procedures can be a part of an emulator package
 #	or can be called directly after the input parameters have been loaded
 #	into the architectural registers. 
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
 #	v01-003 ljk0040		Lawrence J. Kenah	24-Jul-84
 #		Longword context instructions (INCL and DECL) cannot be used
 #		to modify the sign byte the destination string for CVTSP.
 #
 #	v01-002 ljk0024		Lawrence J. Kenah	20-Feb-84
 #		Add code that handles access violation. Perform minor cleanup.
 #
 #	v01-001	ljk0008		lawrence j. kenah	19-oct-1983
 #		the emulation code for cvtps, cvtpt, cvtsp, and cvttp
 #		was moved into a separate module.
 #
 #--

#define	operand_1	12
#define	operand_2	16
#define	operand_3	20
#define	operand_4	24
#define	operand_5	28
#define	operand_6	32

 #+
 # functional description:
 #
 #	the conversion from a packed decimal string to a numeric string
 #	(cvtps and cvtpt instructions) consists of much common code and
 #	two small pieces of code that are instruction specific, the
 #	beginning and a portion of the end processing. the actual routine
 #	exit path is the common exit path from the decimal instruction
 #	emulator, vax$decimal_exit.
 #
 #	the two routines perform instruction-specific operations on the
 #	first byte in the stream. the bulk of the work is done by a common
 #	subroutine. some instruction-specific end processing is done before
 #	final control is passed to vax$decimal_exit.
 #
 #	the structure is something like the following.
 #
 #		cvtps					cvtpt
 #		-----					-----
 #
 #	store sign character			store table address
 #
 #			|			unpack registers
 #			|
 #			|				|
 #			 \			       /
 #			  \			      /
 #			   \			     /
 #			    |			    |
 #			    v			    v
 #
 #			handle unequal srclen and dstlen
 #
 #			move all digits except last digit
 #
 #			    |			    |
 #			   /			     \
 #			  /			      \
 #			 /			       \
 #			|				|
 #			v				v
 #
 #	move last digit to output		use table to move last digit
 #						and sign to output string
 #			|
 #			|				|
 #			 \			       /
 #			  \			      /
 #			   \			     /
 #			    |			    |
 #			    v			    v
 #
 #                               vax$decimal_exit
 #			set condition codes and registers
 #			to their final values
 #
 # input parameters:
 #
 #	see instruction-specific entry points
 #
 # output parameters:
 #
 #	r0 = 0
 #	r1 = address of byte containing most significant digit of
 #	     the source string
 #	r2 = 0
 #	r3 = address of lowest addressed byte of destination string
 #	     (see instruction-specific header for details)
 #
 # condition codes:
 #
 #	n <- source string lss 0
 #	z <- source string eql 0
 #	v <- decimal overflow
 #	c <- 0
 #-


 #+
 # the following table makes a correspondence between the sixteen possible
 # packed decimal "digits" and their ascii representation. it is used to
 # generate the sign character for leading separate numeric strings and
 # to generate all character output for the cvtpx common code.
 #-

	.text
cvtpx_table:
	.ascii		"0123456789+-+-++"

 #+ CVTPS
 # functional description:
 #
 #	the source packed decimal string specified  by  the  source  length  and
 #	source  address  operands  is  converted  to  a leading separate numeric
 #	string.  the destination string specified by the destination length  and
 #	destination address operands is replaced by the result.
 #
 #	conversion is effected by replacing the lowest  addressed  byte  of  the
 #	destination  string  with  the ascii character '+' or '-', determined by
 #	the sign of the source string.  the remaining bytes of  the  destination
 #	string  are  replaced  by the ascii representations of the values of the
 #	corresponding packed decimal digits of the source string.
 #
 # input parameters:
 #
 #	r0 = srclen.rw		length in digits of input decimal string
 #	r1 = srcaddr.ab		address of input packed decimal string
 #	r2 = dstlen.rw		number of digits in destination character string
 #	r3 = dstaddr.ab 	address of destination character string
 #
 # output parameters:
 #
 #	r0 = 0
 #	r1 = address of byte containing most significant digit of
 #	     the source string
 #	r2 = 0
 #	r3 = address of the sign byte of the destination string
 #
 # condition codes:
 #
 #	n <- source string lss 0
 #	z <- source string eql 0
 #	v <- decimal overflow
 #	c <- 0
 #-

 # note that the two entry points vax$cvtps and vax$cvtpt must save the
 # exact same set of registers because the two routines use a common exit
 # path that includes a popr instruction that restores registers. in fact, by 
 # saving all registers, even if one or two of them are not needed, we can use 
 # the common exit path from this module.

# define cvtps_s_cvtps 16
# define cvtps_w_srclen 0
# define cvtps_s_srclen 5
# define cvtps_v_srclen 0
# define cvtps_b_delta_pc 3
# define cvtps_a_srcaddr 4                 
					#  srcaddr.ab
# define cvtps_w_dstlen 8
# define cvtps_s_dstlen 5
# define cvtps_v_dstlen 0
# define cvtps_a_dstaddr 12                
					#  dstaddr.ab

	.globl	_EMcvtps
_EMcvtps:
	movzwl	operand_1(sp),r0	# r0<15:0> <- srclen.rw 
	movl	operand_2(sp),r1	# r1       <- srcaddr.ab 
	movzwl	operand_3(sp),r2	# r2<15:0> <- dstlen.rw 
	movl	operand_4(sp),r3	# r3       <- dstaddr.ab 
	.globl	_EMLcvtps
_EMLcvtps:
 #	pushr	$^m<r0,r1,r2,r3,r4,r5,r6,r7,r8,r9>	# save the lot
	 pushr	$0x03ff
	extzv	$1,$4,r0,r6		# r6 is byte offset to sign "digit"

	bicb3	$0x0f0,(r1)[r6],r6	# r6 now contains sign "digit"
	movb	cvtpx_table[r6],(r3)+	# store sign character in output string
	bsbw	cvtpx_common		# execute bulk as common code

 #+
 # the common code routine returns here with the following relevant input.
 #
 #	r0	number of digits remaining in source and destination strings
 #	r1	address of least significant digit and sign of input string
 #	r3	address of last byte in destination to be loaded
 #	r8	Sign "digit" from input string
 #	r11	saved psw with condition codes to date (n=0,z,v,c=0)
 #
 #	cvtps_a_dstaddr(sp)	saved r3 at input, address of sign character
 #
 #	r4 is a scratch register
 #
 # if the input string was negative zero, the sign of the output string must
 # be changed from "-" to "+". in addition, a check is required to insure that
 # the z-bit has its correct setting if this digit is the first nonzero digit
 # encountered in the input string. 
 #-

	tstl	r0			# check for no remaining input
	beql	2f			# skip storing digit if nothing there

	extzv	$4,$4,(r1),r4		# get least significant digit	
	beql	1f			# skip clearing z-bit if zero
	bicb2	$PSL_Z,r11		# clear saved z-bit

1:	movb	cvtpx_table[r4],(r3)	# store final output digit

 ### i shouldn't have to fetch the sign twice.

2:	bicb3	$0x0f0,(r1),r6		# sign "digit" to r6

	caseb	r6,$10,$15-10		# dispatch on sign 
L1:
	.word	4f-L1			# 10 => +
	.word	3f-L1			# 11 => -
	.word	4f-L1			# 12 => +
	.word	3f-L1			# 13 => -
	.word	4f-L1			# 14 => +
	.word	4f-L1			# 15 => +

3:	bisb2	$PSL_N,r11		# set n-bit because sign is "-"
	bbc	$2,r11,4f		# skip if n-bit set but z-bit clear
	bicb2	$PSL_N,r11		# turn off n-bit if negative zero
	bbs	$1,r11,4f		# leave sign alone if overflow occurred
	movb	$0x2B,*cvtps_a_dstaddr(sp)	# make output sign "+"
4:	jmp	_EM_decimal_exit	# exit through common code

 #+ CVTPT
 # functional description:
 #
 #	the source packed decimal string specified  by  the  source  length  and
 #	source  address operands is converted to a trailing numeric string.  the
 #	destination string specified by the destination length  and  destination
 #	address  operands is replaced by the result.  the condition code n and z
 #	bits are affected by the value of the source packed decimal string.
 #
 #	conversion is effected by using the highest addressed byte (even if  the
 #	source  string  value  is  -0)  of  the  source  string  (i.e., the byte
 #	containing the sign and the least  significant  digit)  as  an  unsigned
 #	index  into  a 256 byte table whose zeroth entry address is specified by
 #	the table address operand.  the byte read out of the table replaces  the
 #	least  significant  byte of the destination string.  the remaining bytes
 #	of the destination string are replaced by the ascii  representations  of
 #	the  values  of  the  corresponding  packed decimal digits of the source
 #	string.
 #
 # input parameters:
 #
 #	r0 <15:0>  = srclen.rw	length in digits of input decimal string
 #	r0 <31:16> = dstlen.rw	number of digits in destination character string
 #	r1         = srcaddr.ab	address of input packed decimal string
 #	r2         = tbladdr.ab	address of 256-byte table used for sign conversion
 #	r3         = dstaddr.ab address of destination character string
 #
 # output parameters:
 #
 #	r0 = 0
 #	r3 = address of byte containing most significant digit of
 #	     the source string
 #	r2 = 0
 #	r3 = address of most significant digit of the destination string
 #
 # condition codes:
 #
 #	n <- source string lss 0
 #	z <- source string eql 0
 #	v <- decimal overflow
 #	c <- 0
 #-
 # notes:
 #
 #   1.	note that the two entry points vax$cvtps and vax$cvtpt must save the
 #	exact same set of registers because the two routines use a common exit
 #	path that includes a popr instruction that restores registers. in
 #	fact, by saving all registers, even if one or two of them are not
 #	needed, we can use the common exit path from this module. 
 #
 #   2.	this routine and vax$cvttp must have a separate jsb entry point.
 #	(several other routines could use one but it is not required.) code
 #	that uses the emulator through its jsb entry points cannot be
 #	redirected to a different entry point when the instruction is
 #	restarted after an access violation. the only way that a restart can
 #	be distinguished from a first pass is through an internal fpd bit. the
 #	original sizes for the five operands for cvtpt and cvttp require all
 #	the bits in the four general registers. 
 #	
 #	the fpd bit is stored in bit<15> of the "srclen" operand. in order to
 #	insure that instructions that enter the emulator through the
 #	vax$_opcdec exception, rather than through its jsb entry points,
 #	correctly generate reserved operands for lengths in the range 32768 to
 #	65535, the internal fpd bit cannot be tested at the vax$ entry point.
 #	thus, the extra entry point is required. 
 #
 #	note that this implementation has the peculiar effect that a reserved
 #	operand exception will not be generated if r0<15:0> contains a number
 #	in the range 32768 and 32768+31 inclusive. 
 #
 #   3.	the restart entry point is needed because information is saved in
 #	r0<31:24> if the instruction is interrupted by an access violation.
 #	this information must be cleared out before the length checks are made
 #	or a spurious reserved operand exception would result. 
 #-

	.globl	_EMcvtpt
_EMcvtpt:
	rotl	$16,operand_4(sp),r0	# r0<31:16> <- dstlen.rw 
	movw	operand_1(sp),r0	# r0<15:0>  <- srclen.rw 
	movl	operand_2(sp),r1	# r1        <- srcaddr.ab 
	movl	operand_3(sp),r2	# r2        <- tbladdr.ab 
	movl	operand_5(sp),r3	# r3        <- dstaddr.ab 
	.globl	_EMLcvtpt
_EMLcvtpt:
L700:
 #	pushr	$^m<r0,r1,r2,r3,r4,r5,r6,r7,r8,r9>	# save the lot
	 pushr	$0x03ff
	movl	r2,r9			# store table address away
	rotl	$16,r0,r2		# store "dstlen" in r2
	bsbw	cvtpx_common		# execute bulk as common code

 #+
 # the common code routine returns here with the following relevant input.
 #
 #	r1	address of least significant digit and sign of input string
 #	r2	number of digits in destination string (preserved across call)
 #	r3	address of last byte in destination to be loaded
 #	r9	address of 256-byte table (preserved across call)
 #	r11	saved psw with condition codes to date (n=0,z,v,c=0)
 #
 #	r4 is a scratch register
 #
 # the cvtps instruction loads r8 in its initialization code. this instruction
 # does not need r8 except at this time to determine the setting of the n-bit
 # so r8 is loaded here. in addition, a check is required to insure that the
 # z-bit has its correct setting if the least significant digit is the first
 # nonzero digit encountered in the input string. 
 #-

	tstl	r2			# check for no remaining input
	beql	1f			# skip storing digit if nothing there
	movzbl	(r1),r4			# get last input digit
	movb	(r9)[r4],(r3)		# store associated destination byte
	extzv	$4,$4,(r1),r4		# get least significant digit	
	beql	1f			# skip clearing z-bit if zero
	bicb2	$PSL_Z,r11		# clear saved z-bit
1:	bicb3	$0x0f0,(r1),r8		# sign "digit" to r6

	caseb	r8,$10,$15-10		# dispatch on sign 
L2:
	.word	3f-L2			# 10 => +
	.word	2f-L2			# 11 => -
	.word	3f-L2			# 12 => +
	.word	2f-L2			# 13 => -
	.word	3f-L2			# 14 => +
	.word	3f-L2			# 15 => +

2:	bbs	$2,r11,3f		# skip if z-bit set (negative zero)
	bisb2	$PSL_N,r11		# set n-bit because sign is "-"
3:	jmp	_EM_decimal_exit	# exit through common code

 #+ cvtpx_common
 # functional description:
 #
 #	This routine is used by both CVTPS and CVTPT to translate a packed
 #	decimal string of digits into its ASCII equivalent.
 #
 # input parameters:
 #
 #	r0 = srclen.rw		length in digits of input decimal string
 #	r1 = srcaddr.ab		address of input packed decimal string
 #	r2 = dstlen.rw		number of digits in destination character string
 #	r3 = dstaddr.ab 	address of destination character string
 #
 #	(sp)	address of instruction-specific completion code in cvtps
 #		or cvtpt routine
 #
 # Implicit input:
 #
 #	R10 must contain the address of an access violation  handler in the
 #	event that any strings touched by this routine are not accessible.
 #
 # output parameters:
 #
 #	r0 = Size in digits of shorter of source and destination
 #	r1 = Address of least significant digit and sign of input string
 #	r2 = Number of digits in destination character string (unchanged)
 #	r3 = Address of last byte in destination to be load
 #
 #	R11 contains the partial condition codes accumulated by converting
 #	    all but the least significant input digit
 # condition codes:
 #
 #	R4, R5, and R6 are used as scratch register by this routine.
 #
 #	R7 through R10 are not used.
 #-


cvtpx_common:
 #	roprand_check	r0		# insure that r0 lequ 31
	 cmpw	r0,$31
	 blequ	1f
	 brw	decimal_roprand
1:
	 movzwl	r0,r0

 #	roprand_check	r2		# insure that r2 lequ 31
	 cmpw	r2,$31
	 blequ	1f
	 brw	decimal_roprand
1:
	 movzwl	r2,r2			# 002 Fix bad expansion of a macro
	movpsl	r11			# get initial psl
	insv	$PSL_Z,$0,$4,r11	# set z-bit, clear the rest
	subl3	r2,r0,r5		# r5 is length difference
	beql	cvtpx_equal		# life is easy if they're the same
	blss	cvtpx_zero_fill		# fill output with zeros if too large

 #+
 # **********		srclen gtru dstlen			**********
 #
 # the following code executes if the source string is larger than the 
 # destination string. excess high order input digits must be discarded. if
 # any of the input digits is not zero, then the v-bit is set in the saved
 # psw (stored in r11). the low order digits will be moved as in the normal
 # case. a test for whether decimal overflow exceptions are to be generated
 # is made as part of final instruction processing.
 #
 #	r5 = r0 - r2  (r5 gtru 0)
 #-

cvtpx_overflow_check:
	pushl	r1			# save initial input address
	blbs	r0,1f			# skip single digit test for odd length
	extzv	$0,$4,(r1),r4		# first digit to r4 (set r4<31:8> to 0)
	bneq	4f			# skip rest if nonzero. nothing to be
	decl	r5			#  gained by hanging around.
					# one less digit to check
	incl	r1			# point r1 to next byte in input string
1:	ashl	$-1,r5,r5		# convert digit count to byte count
	beql	3f			# skip loop if no more double digits

2:	tstb	(r1)+			# do rest two digits at a time
	bneq	4f			# exit loop is nonzero digit
	sobgtr	r5,2b			# check for end of loop

3:	blbs	r2,5f			# no lone digit if r2 odd
	bitb	$0x0f0,(r1)		# does upper nibble contain nonzero
	beql	5f			# no, so we're all done

 # the following code executes if any of the discarded digits is nonzero.
 # the v-bit is set in the saved psw, the saved z-bit is cleared, and r1 is 
 # updated to point to the remaining input string. the large comment at the
 # beginning of the module explains why the incl r5 instruction is necessary
 # when r0, the length of the shorter string, is odd.

4:	bicb2	$PSL_Z,r11		# clear saved z-bit
	bisb2	$PSL_V,r11		# set saved v-bit
5:	subl3	r2,r0,r5		# recompute difference (r5 gtru 0)

 # the long comment at the beginning of the module explains the reason why
 # we increment r5 when r2, the length of the shorter string, is odd.

	blbc	r2,6f			# need adjustment if odd output string
	incl	r5			# adjust difference
6:	ashl	$-1,r5,r5		# convert digit count to byte count
	addl3	(sp)+,r5,r1		# "restore" an updated input pointer
	movl	r2,r0			# enter common code with updated
					#  "srclen" equal to "dstlen"
	brb	cvtpx_equal		# join common code

 #+
 # **********		srclen lssu dstlen			**********
 #
 # the following code executes if the destination string is longer than the
 # source string. all excess digits in the destination string are filled
 # with zero.
 #-

cvtpx_zero_fill:
	mnegl	r5,r5			# make digit count positive

7:	movb	$0x030,(r3)+		# store a "0" in the output
	sobgtr	r5,7b			# check for end of loop

 #+
 #**********	 updated srclen eql updated dstlen		**********
 #
 # the following code is a common meeting point for the three different input
 # cases relating source length and destination length. excess source or
 # destination digits have already been dealt with. we are effectively
 # dealing with input and output strings of equal length (as measured by
 # number of digits).
 #-

cvtpx_equal:
	blbs	r0,9f			# no special first digit if r0 odd
	tstl	r0			# also skip if no remaining digits
	beql	5f
	extzv	$0,$4,(r1),r4		# first digit to r4 (set r4<31:8> to 0)
	beql	8f			# leave z-bit alone if zero
	bicb2	$PSL_Z,r11		# otherwise, clear z-bit
8:	movb	cvtpx_table[r4],(r3)+	# move digit to output string
	incl	r1			# advance input string pointer
	decl	r0			# one less digit to process

9:	ashl	$-1,r0,r5		# convert digit count to byte count
	beql	2f			# all done if zero

0:	movzbl	(r1)+,r4		# get next two input digits
	beql	3f			# step out of line if both are zero
	bicb2	$PSL_Z,r11		# clear saved z-bit
	extzv	$4,$4,r4,r7		# get high-order digit
	movb	cvtpx_table[r7],(r3)+	# move associated character to output
	bicb3	$0x0f0,r4,r7		# get low-order digit
	movb	cvtpx_table[r7],(r3)+	# move associated character to output
1:	sobgtr	r5,0b			# test for end of loop

2:	rsb				# perform instruction-specific
					#  end processing



 # this code is part of the main loop that moves input digits to the output
 # string. This code only executes when a digit pair consisting of two zeros
 # detected. Note that this is an optimization that recognizes that the
 # individual digits do not have to be translated in order to load the
 # destination string.

3:	movw	$0x03030,(r3)+		# move the pair to the output "00"
	brb	1b			# rejoin at the end of the loop

 # We have advanced too far in the destination string. Back up by one byte
 # and let the caller correctly load the final output byte.	

5:	decl	r3
	rsb
 #+
 # functional description:
 #
 #	the conversion from a numeric string to a packed decimal string
 #	(cvtsp and cvttp instructions) consists of much common code and
 #	two small pieces of code that are instruction specific, the
 #	beginning and a portion of the end processing. the actual routine
 #	exit path is the common exit path from this module, vax$decimal_exit.
 #
 #	the two routines perform instruction-specific operations on the
 #	first byte in the stream. the bulk of the work is done by a common
 #	subroutine. some instruction-specific end processing is done before
 #	final control is passed to vax$decimal_exit.
 #
 #	the structure is something like the following.
 #
 #		cvtsp					cvttp
 #		-----					-----
 #
 #	skip over sign character		store table address
 #
 #			|			unpack registers
 #			|
 #			|				|
 #			 \			       /
 #			  \			      /
 #			   \			     /
 #			    |			    |
 #			    v			    v
 #
 #			handle unequal srclen and dstlen
 #
 #			move all digits except last digit
 #
 #			    |			    |
 #			   /			     \
 #			  /			      \
 #			 /			       \
 #			|				|
 #			v				v
 #
 #	move last digit to output		use table to move last digit
 #	move sign to output			and sign to output string
 #
 #			|				|
 #			 \			       /
 #			  \			      /
 #			   \			     /
 #			    |			    |
 #			    v			    v
 #
 #                               vax$decimal_exit
 #			set condition codes and registers
 #			to their final values
 #
 # input parameters:
 #
 #	see instruction-specific entry points
 #
 # output parameters:
 #
 #	r0 = 0
 #	r1 = address of lowest addressed byte of destination string
 #	     (see instruction-specific header for details)
 #	r2 = 0
 #	r3 = address of byte containing most significant digit of
 #	     the source string
 #
 # condition codes:
 #
 #	n <- destination string lss 0
 #	z <- destination string eql 0
 #	v <- decimal overflow
 #	c <- 0
 #
 # notes:
 #
 #	both of these instructions check the input strings for legal decimal 
 #	digits. if a character other than the ascii representation of a 
 #	decimal digit is detected in the input string, a reserved operand 
 #	abort is generated. this exception is not restartable.
 #
 #	in addition, the cvtsp instruction insures that the sign character is 
 #	one of "+", " ", or "-". 
 #
 #	the cvttp instruction uses the highest addressed byte as an offset 
 #	into a 256-byte table. the byte that is retrieved from this table is 
 #	checked to determine that its high nibble contains a legal decimal 
 #	digit and its low nibble contains a legal sign.
 #-


 #+
 # the following tables contains the decimal equivalents of the ten decimal
 # digits. one table is used if the low nibble of a byte is being loaded 
 # (an even numbered digit). the other table is used when the high nibble 
 # of a byte is being loaded (odd numbered digit).
 #-

 # table for entry into low order nibble

cvtxp_table_low:
	.byte	0x00 , 0x01 , 0x02 , 0x03 , 0x04 
	.byte	0x05 , 0x06 , 0x07 , 0x08 , 0x09 

 # table for entry into high order nibble

cvtxp_table_high:
	.byte	0x00 , 0x10 , 0x20 , 0x30 , 0x40 
	.byte	0x50 , 0x60 , 0x70 , 0x80 , 0x90 


 #+ CVTSP
 # functional description:
 #
 #	the source numeric string specified by  the  source  length  and  source
 #	address  operands  is  converted  to  a  packed  decimal  string and the
 #	destination string specified by the destination address and  destination
 #	length operands is replaced by the result.
 #
 # input parameters:
 #
 #	r0 = srclen.rw		number of digits in source character string
 #	r1 = srcaddr.ab		address of input character string
 #	r2 = dstlen.rw		length in digits of output decimal string
 #	r3 = dstaddr.ab 	address of destination packed decimal string
 #
 # output parameters:
 #
 #	r0 = 0
 #	r1 = address of the sign byte of the source string
 #	r2 = 0
 #	r3 = address of byte containing most significant digit of
 #	     the destination string
 #
 # condition codes:
 #
 #	n <- destination string lss 0
 #	z <- destination string eql 0
 #	v <- decimal overflow
 #	c <- 0
 #
 # Notes:
 #-


 # note that the two entry points vax$cvtsp and vax$cvttp must save the
 # exact same set of registers because the two routines use a common exit
 # path that includes a popr instruction that restores registers. in fact, by 
 # saving all registers, even if one or two of them are not needed, we can use 
 # the common exit path from this module.

# define cvtsp_s_cvtsp 16
# define cvtsp_w_srclen 0
# define cvtsp_s_srclen 5
# define cvtsp_v_srclen 0
# define cvtsp_b_delta_pc 3
# define cvtsp_a_srcaddr 4                 
					#  srcaddr.ab
# define cvtsp_w_dstlen 8
# define cvtsp_s_dstlen 5
# define cvtsp_v_dstlen 0
# define cvtsp_a_dstaddr 12                
					#  dstaddr.ab

	.globl	_EMcvtsp
_EMcvtsp:
	movzwl	operand_1(sp),r0	# r0<15:0> <- srclen.rw 
	movl	operand_2(sp),r1	# r1       <- srcaddr.ab 
	movzwl	operand_3(sp),r2	# r2<15:0> <- dstlen.rw 
	movl	operand_4(sp),r3	# r3       <- dstaddr.ab 
	.globl	_EMLcvtsp
_EMLcvtsp:
 #	pushr	$^m<r0,r1,r2,r3,r4,r5,r6,r7,r8,r9>	# save the lot
	 pushr	$0x03ff
	incl	r1			# skip byte containing sign for now
	bsbw	cvtxp_common		# execute bulk as common code

 #+
 # the common code routine returns here with the following relevant input.
 #
 #	r0	number of digits remaining in source and destination strings
 #	r1	address of last (highest addressed) byte in source string
 #	r3	address of least significant digit and sign of output string
 #	r4	r4<31:8> must be zero on input to this routine
 #	r11	saved psw with condition codes to date (n=0,z,v,c=0)
 #
 #	cvtsp_a_srcaddr(sp)	saved r1 at input, address of sign character
 #
 #	r4 is a scratch register
 #
 # the last input digit is moved to the output stream, after a check that it
 # represents a legal decimal digit. a check is also required to insure that
 # the z-bit has its correct setting if this digit is the first nonzero digit
 # encountered in the input string. the sign of the input string is checked
 # for a legal value and transformed into one of two legal output signs, 12 
 # for "+" and 13 for "-".
 #-

	movb	$12,(r3)		# assume that sign is plus
	tstl	r0			# check for zero length input string
	beql	2f			# skip storing digit if nothing there
	subb3	$0x030,(r1),r4		# get least significant digit "0"
	blssu	3f			# reserved operand if not a digit
	beql	1f			# skip clearing z-bit if zero
	bicb2	$PSL_Z,r11		# clear saved z-bit
1:	cmpb	r4,$9			# check digit against top of range
	bgtru	3f			# reserved operand if over the top
	addb2	cvtxp_table_high[r4],(r3)	# store final output digit
2:	movzbl	*cvtsp_a_srcaddr(sp),r4	# get sign character from input string

	caseb	r4,$0x2b,$0x2d - 0x2b	# 001 dispatch on sign character
L3:
	.word	5f-L3			# character is "+"
	.word	3f-L3			# sign character is "," (illegal input)
	.word	4f-L3			# character is "-"

	cmpb	r4,$0x20		# blank is also legal "plus sign"
	beql	5f

 # error path for all code paths that detect an illegal character in
 # the input stream

3:	brw	decimal_roprand_no_pc	# reserved operand abort on illegal input

 # the sign of the input stream was "-". if something other than negative
 # zero, set the n-bit and adjust the sign.

4:	bisb2	$PSL_N,r11		# set n-bit because sign is "-"
	incb	(r3)			# change sign from "+" (12) to "-" (13)
	bbc	$2,r11,5f		# all done unless negative zero
	bicb2	$PSL_N,r11		# clear the saved n-bit
	bbs	$1,r11,5f		# the output sign is ignored if overflow
	decb	(r3)			# change sign back so -0 becomes +0
5:	jmp	_EM_decimal_exit	# exit through common code

 #+ CVTTP
 # functional description:
 #
 #	the source trailing numeric string specified by the  source  length  and
 #	source  address operands is converted to a packed decimal string and the
 #	destination packed decimal string specified by the  destination  address
 #	and destination length operands is replaced by the result.
 #
 #	conversion is effected by using the highest addressed (trailing) byte of
 #	the  source  string  as  an  unsigned  index into a 256 byte table whose
 #	zeroth entry is specified by the table address operand.  the  byte  read
 #	out  of the table replaces the highest addressed byte of the destination
 #	string (i.e.  the byte containing the sign  and  the  least  significant
 #	digit).   the  remaining  packed  digits  of  the destination string are
 #	replaced by the low order 4 bits  of  the  corresponding  bytes  in  the
 #	source string.
 #
 # input parameters:
 #
 #	r0 <15:0>  = srclen.rw	number of digits in source character string
 #	r0 <31:16> = dstlen.rw	length in digits of output decimal string
 #	r1         = srcaddr.ab	address of input character string
 #	r2         = tbladdr.ab	address of 256-byte table used for sign conversion
 #	r3         = dstaddr.ab address of destination packed decimal string
 #
 # output parameters:
 #
 #	r0 = 0
 #	r1 = address of most significant digit of the source string
 #	r2 = 0
 #	r3 = address of byte containing most significant digit of
 #	     the destination string
 #
 # condition codes:
 #
 #	n <- destination string lss 0
 #	z <- destination string eql 0
 #	v <- decimal overflow
 #	c <- 0
 #-


 # note that the two entry points vax$cvtsp and vax$cvttp must save the
 # exact same set of registers because the two routines use a common exit
 # path that includes a popr instruction that restores registers. in fact, by 
 # saving all registers, even if one or two of them are not needed, we can use 
 # the common exit path from this module.
 #
 # See the rotine header for CVTPT for an explanation of the _JSB and _RESTART
 # entry points.

 # there is a single case where the common subroutine cannot be used. if the
 # output length is zero, then the final character in the input string would
 # be subjected to the rather stringent legality test that it lie between
 # ascii 0 and ascii 9. in fact, it is the translated character that must be
 # tested. there are three cases. 
 #
 #	the input length is also zero. in this case, the common code path can
 #	be used because the input and output length are equal. (in fact, the
 #	subroutine does little more than set the condition codes and load
 #	registers. 
 #
 #	the input consists of a single character. in this case, this single
 #	character is translated and tested for legality. note that the 
 #	subroutine is also called here to set condition codes and the like.
 #
 #	the input size is larger than one. in this case, the common subroutine
 #	is called with the input size reduced by one. the leading characters
 #	are tested by the subroutine which returns here to allow the final
 #	character to be tested. 
 #
 # note that this is not a commonly travelled code path so that the seemingly
 # excessive amount of code necessary to achieve accuracy is not a performance
 # problem. 

8:
 #	roprand_check	r0		# insure that r0 lequ 31
	 cmpl	r0,$31
	 blequ	1f
	 brw	decimal_roprand_no_pc
1:

	beql	0f			# back in line if source length zero
	decl	r0			# reduce input length by one
	bsbw	cvtxp_common		# check leading digits for legality
9:	movzbl	(r1),r4			# get last input byte
	movzbl	(r9)[r4],r4		# get associated output byte from table
	bicb3	$0x0f0,r4,(r3)		# only store sign in output string
	extzv	$4,$4,r4,r0		# get low-order digit
	beql	1f			# join exit code if zero
	bisb2	$PSL_V,r11		# set v-bit in saved psw
	cmpl	r0,$9			# is the digit within range?
	blequ	1f			# yes, join the exit code
	brw	decimal_roprand_no_pc	# otherwise, report exception

	.globl	_EMcvttp
_EMcvttp:
	rotl	$16,operand_4(sp),r0	# r0<31:16> <- dstlen.rw 
	movw	operand_1(sp),r0	# r0<15:0>  <- srclen.rw 
	movl	operand_2(sp),r1	# r1        <- srcaddr.ab 
	movl	operand_3(sp),r2	# r2        <- tbladdr.ab 
	movl	operand_5(sp),r3	# r3        <- dstaddr.ab 
	.globl	_EMLcvttp
_EMLcvttp:
L600:
 #	pushr	$^m<r0,r1,r2,r3,r4,r5,r6,r7,r8,r9>	# save the lot
	 pushr	$0x03ff
	movl	r2,r9			# store table address away
	extzv	$16,$16,r0,r2		# store "dstlen" in r2
	beql	8b			# perform extraordinary check if zero
0:	bsbw	cvtxp_common		# execute bulk as common code

 #+
 # the common code routine returns here with the following relevant input.
 #
 #	r0	number of digits remaining in source and destination strings
 #	r1	address of last (highest addressed) byte in source string
 #	r3	address of least significant digit and sign of output string
 #	r9	address of 256-byte table (preserved across call)
 #	r11	saved psw with condition codes to date (n=0,z,v,c=0)
 #
 #	r4 is a scratch register
 #
 # the last byte of the input string is used as an index into the 256-byte
 # table that contains the last output byte. the contents of this byte are
 # tested for a legal decimal digit in its upper nibble and a legal sign
 # representation (10 through 15) in its low nibble. the z-bit is cleared
 # if the digit is 1 through 9 to cover the case that this is the first 
 # nonzero digit in the input string.
 #-

	tstl	r0			# check for no remaining input
	beql	7f			# special case if zero length input
	movzbl	(r1),r4			# get last input byte
	movzbl	(r9)[r4],r4		# get associated output byte from table
	movb	r4,(r3)			# store in destination string
	extzv	$4,$4,r4,r0		# get least significant digit	
	beql	1f			# skip clearing z-bit if zero
	cmpb	r0,$9			# check for legal range
	bgtr	2f			# reserved operand if 10 through 15
	bicb2	$PSL_Z,r11		# clear saved z-bit
1:	bicb3	$0x0f0,r4,r0		# sign "digit" to r0

	caseb	r0,$10,$15-10		# dispatch on sign 
L4:
	.word	5f-L4			# 10 => +
	.word	3f-L4			# 11 => -
	.word	6f-L4			# 12 => +
	.word	4f-L4			# 13 => -
	.word	5f-L4			# 14 => +
	.word	5f-L4			# 15 => +

2:	brw	decimal_roprand_no_pc	# reserved operand if sign is 0 to 9

 # a minus sign of 11 must be changed to 13, the preferred minus representation

3:	addb2	$2,(r3)			# change 11 to 13, preferred minus sign
4:	bisb2	$PSL_N,r11		# set n-bit because sign is "-"
	bbc	$2,r11,6f		# all done unless negative zero
	bicb2	$PSL_N,r11		# clear the saved n-bit
	bbs	$1,r11,6f		# the output sign is ignored if overflow

 # if the sign character is a 10, 14, or 15, it must be changed to a 12, the
 # preferred plus sign before joining the exit code.

5:	insv	$12,$0,$4,(r3)		# store a 12 as the output sign
6:	jmp	_EM_decimal_exit	# exit through common code

 # if the source string has zero length, the destination is set identically
 # to zero. the following instruction sequence assumes that the z-bit was
 # set in the initialization code for this routine.

7:	movb	$12,(r3)		# store "+" in output string
	jmp	_EM_decimal_exit	# exit through common code

 #+ cvtxp_common
 # functional description:
 #
 #	This routine is shared by both CVTPS and CVTPT to translate an ASCII
 #	string that contains only the characters "0" to "9" into an equivalent
 #	packed decimal string. A check is made for legal input digits and a
 #	reserved operand generated if an illegal digit is encountered.
 #
 # input parameters:
 #
 #	r0 = srclen.rw		number of digits in source character string
 #	r1 = srcaddr.ab		address of first digiyt in input character
 #				string
 #	r2 = dstlen.rw		length in digits of output decimal string
 #	r3 = dstaddr.ab 	address of destination packed decimal string
 #
 #	(sp)	address of instruction-specific completion code in cvtsp
 #		or cvtpt routine
 #
 # output parameters:
 #
 #	r0 = Size in digits of shorter of source and dest. strings
 #	r1 = address of lowest addressed byte of source string
 #	     (see instruction-specific header for details)
 #	r2 = Number of digits in dest. packed decimal string
 #	r3 = address of byte containing most significant digit of
 #	     the destination string
 #
 #	R11 contains the partial condition codes accumlated by converting
 #	    all but the least significant input digit
 #
 # condition codes:
 #
 # implicit output:
 #
 # 	r4<31:8> is zero to insure that cvtsp works correctly
 #
 #	r10 is loaded with the address of an access violation handler in the
 #	event that any strings touched by this routine are not accessible.
 #
 # side effects:
 #
 #	r4 and r5 are used as scratch registers by this routine.
 #
 #	r6 through r9 are not used.
 #-


cvtxp_common:
 #	roprand_check	r0		# insure that r0 lequ 31
	 cmpw	r0,$31
	 blequ	1f
	 brw	decimal_roprand
1:
	 movzwl	r0,r0
 #	roprand_check	r2		# insure that r2 lequ 31
	 cmpw	r2,$31
	 blequ	1f
	 brw	decimal_roprand
1:
	 movzwl	r2,r2
	movpsl	r11			# get initial psl
	insv	$PSL_Z,$0,$4,r11	# set z-bit, clear the rest
	subl3	r2,r0,r5		# r5 is length difference
	beql	cvtxp_equal		# life is easy if they're the same
	blss	cvtxp_zero_fill		# fill output with zeros if its too large

 #+
 # **********		srclen gtru dstlen			**********
 #
 # the following code executes if the source string is larger than the
 # destination string. excess high order input digits must be discarded. if
 # any of the input digits is not zero, then the v-bit is set in the saved psw
 # (stored in r11). in addition, digits must be checked for legal values
 # (ascii 0 through ascii 9) before they are discarded in order to determine
 # whether to generate a reserved operand abort. the low order digits will be
 # moved as in the normal case. a test for whether decimal overflow exceptions
 # are to be generated is made as part of final instruction processing. 
 #
 #	r5 = r0 - r2  (r5 gtru 0)
 #-

cvtxp_overflow_check:
1:	cmpb	(r1)+,$0x30		# is digit ascii zero?
	bneq	3f			# exit loop if other than zero
2:	sobgtr	r5,1b			# test for more excess digits

	movl	r2,r0			# update input length for skipped digits
	brb	cvtxp_equal		# join common code

 # the following code executes if any of the discarded digits is nonzero.
 # if the digit is the ascii representation of a decimal digit, then the
 # v-bit is set in the saved psw and the saved z-bit is cleared. the loop
 # is reentered where we left it to continue the search for legal input
 # digits. (note that this is different from the cvtpx case where, once an
 # overflow was detected, the remaining excess input digits could be skipped.)

3:	blssu	4f			# reserved operand if outside range
	bisb2	$PSL_V,r11		# set saved v-bit
	cmpb	-1(r1),$0x039		# compare digit to ascii "9"
	blequ	2b			# back in loop if inside range
4:	brw	decimal_roprand		# signal illegal digit abort

 #+
 # **********		srclen lssu dstlen			**********
 #
 # the following code executes if the destination string is longer than the
 # source string. all excess digits in the destination string are filled
 # with zero.
 #-

cvtxp_zero_fill:
	mnegl	r5,r5			# make digit count positive

	blbc	r0,5f			# different code paths for even and odd
					#  input string sizes (the shorter one)

 # shorter string has odd number of digits. note that the divide by two can 
 # never produce zero because r5 is always nonzero before the incl so that r5
 # is always at least two before the divide takes place. the comment at the 
 # beginning of the module explains the two different code paths based on the
 # parity of the input (shorter) string.

	incl	r5			# adjust before divide by two
	extzv	$1,$4,r5,r5		# convert digit count to byte count
	brb	6f			# join common loop

 # shorter string has an even number of digits.

5:	extzv	$1,$4,r5,r5		# convert digit count to byte count
	beql	cvtxp_equal		# no loop if byte count is zero
	
6:	clrb	(r3)+			# store a pair of zeros in output string
	sobgtr	r5,6b			# test for more bytes to clear

 #+
 #**********	 updated srclen eql updated dstlen		**********
 #
 # the following code is a common meeting point for the three different input
 # cases relating source length and destination length. excess source or
 # destination digits have already been dealt with. we are effectively
 # dealing with input and output strings of equal length (as measured by
 # number of digits).
 #-

cvtxp_equal:
	clrl	r4			# insure that r4<31:8> is zero
	extzv	$1,$4,r0,r5		# convert digit count to byte count
	beql	L110			# down to last digit if zero

 # if the count of remaining digits is even, we need to jump into the middle
 # of the loop. but the store operation in the second half of the loop uses a
 # bisb2, assuming that the high order nibble is already cleared (which it is if
 # we also execute the first half of the loop). in order to insure that the high
 # order nibble has a zero stored in it, we jump to the last instruction of the
 # first half of the loop. because we just cleared r4, the movb instruction at
 # 90$ stores a zero in the appropriate byte of the output string. 

	blbc	r0,9f			# to middle of loop if digit count even

7:	subb3	$0x30,(r1)+,r4		# convert ascii to digit
	blssu	4b			# abort instruction if out of range
	beql	8f			# do not clear z-bit if digit is zero
	bicb2	$PSL_Z,r11		# clear z-bit when digit is 1 to 9
8:	cmpb	r4,$9			# check for other end of range
	bgtru	4b			# abort if outside the other end, too
9:	movb	cvtxp_table_high[r4],(r3)	# store digit in high nibble

 # note that the above instruction also clears out the low order four bits in
 # the currently addressed byte in the output packed decimal string.

	subb3	$0x030,(r1)+,r4		# convert ascii to digit "0"
	blssu	4b			# abort instruction if out of range
	beql	0f			# do not clear z-bit if digit is zero
	bicb2	$PSL_Z,r11		# clear z-bit when digit is 1 to 9
0:	cmpb	r4,$9			# check for other end of range
	bgtru	4b			# abort if outside the other end, too
	bisb2	cvtxp_table_low[r4],(r3)+	# store digit in low nibble

	sobgtr	r5,7b			# test for end of loop

L110:	rsb				# perform instruction-specific
					#  end processing

 #- decimal_roprand
 # functional description:
 #
 #	this routine receives control when a digit count larger than 31
 #	is detected. the exception is architecturally defined as an
 #	abort so there is no need to store intermediate state. all of the
 #	routines in this module save all registers r0 through r9 before
 #	performing the digit check. these registers must be restored
 #	before control is passed to vax$roprand.
 #
 # input parameters:
 #
 #	entry at decimal_roprand
 #
 #		00(sp) - return pc from common subroutine (discarded)
 #		04(sp) - saved r0	\
 #		  .			 \
 #		  .			  >  restored
 #		  .			 /
 #		40(sp) - saved r9	/
 #		44(sp) - return pc from same-mode emulator dispatcher
 #
 #	entry at decimal_roprand_no_pc
 #
 #		00(sp) - saved r0	\
 #		  .			 \
 #		  .			  >  restored
 #		  .			 /
 #		36(sp) - saved r9	/
 #		40(sp) - return pc from same-mode emulator dispatcher
 #
 # output parameters:
 #
 #	00(sp) - return pc from same-mode emulator dispatcher
 #
 # implicit output:
 #
 #	this routine passes control to _EM_reserved_operand where further
 #	exception processing takes place.
 #
 # note:
 #
 #	this routine can be entered either from internal subroutines or from
 #	the callers of these subroutines. the decimal_roprand entry point is
 #	used when the return pc is on the stack because that is the name of
 #	the routine that is qutomatically invoked by the roprand_check macro
 #	when an illegal digit count is detected. the other name is arbitrary. 
 #-


decimal_roprand:
	addl2	$4,sp			# discard return pc from common routine
decimal_roprand_no_pc:
 #	popr	$^m<r0,r1,r2,r3,r4,r5,r6,r7,r8,r9>
	 popr	$0x03ff
	jmp	_EM_reserved_operand	# pass control along

#endif NEED_SAMEMODE_EMU
