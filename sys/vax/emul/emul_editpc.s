/*
 * VAX EDITPC instruction emulation
 * Ported from DEC Ultrix to 4.3BSD-Quasijarus by Michael Sokolov
 *
 *	@(#)emul_editpc.s	7.1 (Berkeley) 1/11/04
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
 #	vax-11 instruction emulator
 #
 # abstract:
 #
 #	the routines in this module emulate the vax-11 editpc instruction.
 #	these routines can be a part of an emulator package or can be
 #	called directly after the input parameters have been loaded into
 #	the architectural registers.
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
 #	20 september 1982
 #
 # modified by:
 #
 #	v01-008 ljk0035		lawrence j. kenah	16-jul-1984
 #		Fix bugs in restart logic.
 #
 #		R6 cannot be used as both the exception dispatch register and
 #		a scratch register in the main editpc routine.  Use r7 as the
 #		scratch register.
 #		Add code to the editpc_1 restart routine to restore r7 as the
 #		address of the sign byte.
 #		clear c-bit in saved psw in end_float_1 routine.
 #		restore r9 (count of zeros) with cvtwl instruction.
 #		fix calculation of initial srcaddr parameter.
 #		preserve r8 in read_1 and read_2 routines.
 #		preserve r7 in float_2 routine.
 #
 #	v01-007 ljk0032		lawrence j. kenah	 5-jul-1984
 #		fix restart routine to take into account the fact that
 #		restart codes are based at one when computing restart pc.
 #		Load state cell with nonzero restart code in roprand_fault
 #		routine.
 #
 #	v01-006	ljk0026		lawrence j. kenah	19-mar-1984
 #		final cleanup, especially in access violation handling. make
 #		all of the comments in exception handling accurately describe
 #		what the code is really doing.
 #
 #	v01-005	ljk0018		lawrence j. kenah	23-jan-1984
 #		add restart logic for illegal pattern operator. add access
 #		violation handling.
 #
 #	v01-004	ljk0014		lawrence j. kenah	21-nov-1983
 #		clean up rest of exception handling. remove reference
 #		to lib$signal.
 #
 #	v01-003	ljk0012		lawrence j. kenah	8-nov-1983
 #		start out with r9 containing zero so that pattern streams
 #		that do not contain eo$adjust_input will work correctly.
 #
 #	v01-002	ljk0009		lawrence j. kenah	20-oct-1983
 #		add exception handling. fix bug in size of count field.
 #
 #	v01-001	original	lawrence j. kenah	20-sep-1982
 #--

#define	operand_1	12
#define	operand_2	16
#define	operand_3	20
#define	operand_4	24

 # equated symbols

# define blank 0x20
# define minus 0x2d
# define zero  0x30

 #+ EDITPC
 # functional description:
 #
 #	the destination  string  specified  by  the  pattern  and  destination
 #	address  operands  is  replaced  by  the editted version of the source
 #	string specified by the source length  and  source  address  operands.
 #	the  editing  is performed according to the pattern string starting at
 #	the address pattern and extending until a pattern end (eo$end) pattern
 #	operator  is  encountered.   the  pattern  string consists of one byte
 #	pattern operators.  some pattern operators  take  no  operands.   some
 #	take  a repeat count which is contained in the rightmost nibble of the
 #	pattern operator itself.  the rest  take  a  one  byte  operand  which
 #	follows  the  pattern operator immediately.  this operand is either an
 #	unsigned integer length or a byte character.  the  individual  pattern
 #	operators are described on the following pages.
 #
 # input parameters:
 #
 #	r0 - srclen.rw		length of input packed decimal string
 #	r1 - srcaddr.ab		address of input packed decimal string
 #	r3 - pattern.ab		address of table of editing pattern operators
 #	r5 - dstaddr.ab		address of output character string
 #
 # intermediate state:
 #
 #     31               23               15               07            00
 #    +----------------+----------------+----------------+----------------+
 #    |           zero count            |             srclen              | : r0
 #    +----------------+----------------+----------------+----------------+
 #    |                              srcaddr                              | : r1
 #    +----------------+----------------+----------------+----------------+
 #    | delta-srcaddr  |    delta-pc    |      sign      |      fill      | : r2
 #    +----------------+----------------+----------------+----------------+
 #    |                              pattern                              | : r3
 #    +----------------+----------------+----------------+----------------+
 #    |   loop-count   |      state     |   saved-PSW    |   inisrclen    | : r4
 #    +----------------+----------------+----------------+----------------+
 #    |                              dstaddr                              | : r5
 #    +----------------+----------------+----------------+----------------+
 #
 # output parameters:
 #
 #	r0 - length of input decimal string
 #	r1 - address of most significant byte of input decimal string
 #	r2 - 0
 #	r3 - address of byte containing eo$end pattern operator
 #	r4 - 0
 #	r5 - address of one byte beyond destination character string
 #
 # condition codes:
 #
 #	n <- source string lss 0	(src = -0 => n = 0)
 #	z <- source string eql 0
 #	v <- decimal overflow		(nonzero digits lost)
 #	c <- significance
 #-

# define editpc_m_state 15
# define editpc_m_fpd 16
# define editpc_s_editpc 24
# define editpc_w_srclen 0
# define editpc_b_srclen 0
# define editpc_s_srclen 5
# define editpc_v_srclen 0
# define editpc_b_eo_read_char 1
# define editpc_w_zero_count 2
# define editpc_a_srcaddr 4                
					#  srcaddr.ab
# define editpc_b_fill 8
# define editpc_b_sign 9
# define editpc_b_delta_pc 10
# define editpc_b_delta_srcaddr 11         
					#  current srcaddr minus initial srcaddr
# define editpc_a_pattern 12               
					#  pattern.ab
# define editpc_b_inisrclen 16
# define editpc_b_saved_psw 17
# define editpc_b_state 18
# define editpc_s_state 4
# define editpc_v_state 1
# define editpc_v_fpd 4
# define editpc_b_loop_count 19
# define editpc_a_dstaddr 20               
					#  dstaddr.ab
# define editpc_l_saved_r0 16              
					#  initial srclen.rw
# define editpc_l_saved_r1 20              
					#  initial srcaddr.ab

L5:	brw	editpc_roprand_abort	# time to quit if illegal length
	.globl	_EMeditpc
_EMeditpc:
	movzwl	operand_1(sp),r0	# r0<15:0> <- srclen.rw 
	movl	operand_2(sp),r1	# r1       <- srcaddr.ab 
	clrl	r2			# r2	   <- 0
	movl	operand_3(sp),r3	# r3       <- pattern.ab 
	clrl	r4			# r4	   <- 0
	movl	operand_4(sp),r5	# r5       <- dstaddr.ab 
	.globl	_EMLeditpc
_EMLeditpc:
 #	pushr	$^m<r0,r1,r6,r7,r8,r9>	# save lots of registers
	 pushr	$0x03c3
	cmpl	r0,$31			# check for r0 gtru 31
	bgtru	L5			# signal roprand if r0 gtru 31
	movzbl	$blank,r2		# set fill to blank, stored in r2
	clrl	r9			# start with "zero count" of zero
	movpsl	r11			# get current psl
	bicb2	$(PSL_N|PSL_V|PSL_C),r11 # clear n-, v-, and c-bits
	bisb2	$PSL_Z,r11		# set z-bit. 

 # we need to determine the sign in the input decimal string to choose
 # the initial setting of the n-bit in the saved psw.

	extzv	$1,$4,r0,r7		# get byte offset to end of string
	addl2	r1,r7			# get address of byte containing sign
	extzv	$0,$4,(r7),r7		# get sign "digit" into r6

	caseb	r7,$10,$15-10		# dispatch on sign 
L1:
	.word	2f-L1			# 10 => +
	.word	1f-L1			# 11 => -
	.word	2f-L1			# 12 => +
	.word	1f-L1			# 13 => -
	.word	2f-L1			# 14 => +
	.word	2f-L1			# 15 => +

 # sign is minus

1:	bisb2	$PSL_N,r11		# set n-bit in saved psw
	movzbl	$minus,r4		# set sign to minus, stored in r4
	brb	top_of_loop		# join common code

 # sign is plus (but initial content of sign register is blank)

2:	movzbl	$blank,r4		# set sign to blank, stored in r4

 # the architectural description of the editpc instruction uses an exit flag
 # to determine whether to continue reading edit operators from the input
 # stream. this implementation does not use an explicit exit flag. rather, all
 # of the end processing is contained in the routine that handles the eo$end
 # operator.

 # the next several instructions are the main routine in this module. each
 # pattern is used to dispatch to a pattern-specific routine that performs
 # its designated action. these routines (except for eo$end) return control
 # to top_of_loop to allow the next pattern operator to be processed.

top_of_loop:
	pushab	top_of_loop			# store "return pc"

 # the following instructions pick up the next byte in the pattern stream and
 # dispatch to a pattern specific subroutine that performs the designated
 # action. control is passed back to the main editpc loop by the rsb
 # instructions located in each pattern-specific subroutine. 

 # note that the seemingly infinite loop actually terminates when the eo$end
 # pattern operator is detected. that routine insures that we do not return
 # to this loop but rather to the caller of vax$editpc.

	caseb	(r3)+,$0,$4-0
L2:
	.word	eo_end_routine-L2		# 00 - eo$end
	.word	eo_end_float_routine-L2		# 01 - eo$end_float
	.word	eo_clear_signif_routine-L2	# 02 - eo$clear_signif
	.word	eo_set_signif_routine-L2	# 03 - eo$set_signif
	.word	eo_store_sign_routine-L2	# 04 - eo$store_sign

	caseb	-1(r3 ),$0x40,$0x47-0x40
L3:
	.word	eo_load_fill_routine-L3		# 40 - eo$load_fill
	.word	eo_load_sign_routine-L3		# 41 - eo$load_sign
	.word	eo_load_plus_routine-L3		# 42 - eo$load_plus
	.word	eo_load_minus_routine-L3	# 43 - eo$load_minus
	.word	eo_insert_routine-L3		# 44 - eo$insert
	.word	eo_blank_zero_routine-L3	# 45 - eo$blank_zero
	.word	eo_replace_sign_routine-L3	# 46 - eo$replace_sign
	.word	eo_adjust_input_routine-L3	# 47 - eo$adjust_input

 #	bitb	$^b1111,-1(r3)		# check for 80, 90, or a0
	 bitb	$0x0f,-1(r3)
	beql	3f			# reserved operand on repeat of zero
	extzv	$4,$4,-1(r3 ),r7		# ignore repeat count in dispatch

	caseb	r7,$8,$10-8
L4:
	.word	eo_fill_routine-L4		# 81 to 8f - eo$fill
	.word	eo_move_routine-L4		# 91 to 9f - eo$move
	.word	eo_float_routine-L4		# a1 to af - eo$float

 # if we drop through all three case instructions, the pattern operator is
 # unimplemented or reserved. r3 is backed up to point to the illegal
 # pattern operator and a reserved operand fault is signalled.

3:	decl	r3			# point r3 to illegal operator
	addl2	$4,sp			# discard return pc
	brw	editpc_roprand_fault	# initiate exception processing

 #+
 # functional description:
 #
 #	there is a separate action routine for each pattern operator. these 
 #	routines are entered with specific register contents and several 
 #	scratch registers at their disposal. they perform their designated 
 #	action and return to the main vax$editpc routine.
 #
 #	there are several words used in the architectural description of this
 #	instruction that are carried over into comments in this module. these
 #	words are briefly mentioned here.
 #
 #	char	character in byte following pattern operator (used by
 #		eo$load_fill, eo$load_sign, eo$load_plus, eo$load_minus,
 #		and eo$insert)
 #
 #	length	length in byte following pattern operator (used by
 #		eo$blank_zero, eo$replace_sign, and eo$adjust_input)
 #
 #	repeat	repeat count in bits <3:0> of pattern operator (used by
 #		eo$fill, eo$move, and eo$float)
 #
 #	the architecture makes use of two character registers, described
 #	as appearing in different bytes of r2. for simplicity, we use an
 #	additional register.
 #
 #	fill	stored in r2<7:0>
 #
 #	sign	stored in r4<7:0> 
 #
 #	finally, the architecture describes two subroutines, one that obtains
 #	the next digit from the input string and the other that stores a 
 #	character in the output string. 
 #
 #	read	subroutine eo_read provides this functionality
 #
 #	store	a single instruction of the form
 #
 #			movb	xxx,(r5)+
 #
 #		or
 #
 #			addb3	$zero,r7,(r5)+
 #
 #		stores a single character and advances the pointer.
 #
 # input parameters:
 #
 #	r0 - updated length of input decimal string
 #	r1 - address of next byte of input decimal string
 #	r2 - fill character
 #	r3 - address of one byte beyond current pattern operator
 #	r4 - sign character 
 #	r5 - address of next character to be stored in output character string
 #
 # implicit input:
 #
 #	several registers are used to contain intermediate state, passed
 #	from one action routine to the next.
 #
 #	r7  - contains lastest digit from input stream (output from eo_read)
 #	r11 - pseudo-psw that contains the saved condition codes
 #
 # side effects:
 #
 #	the remaining registers are used as scratch by the action routines.
 #	
 #	r6 - scratch register used only by access violation handler
 #	r7 - output parameter of eo_read routine
 #	r8 - scratch register used by pattern-specific routines
 #
 # output parameters:
 #
 #	the actual output depends on the pattern operator that is currently
 #	executing. the routine headers for each routine will describe the
 #	specific output parameters.
 #-


 #+
 # functional description:
 #
 #	this routine reads the next digit from the input packed decimal
 #	string and passes it back to the caller.
 #
 # input parameters:
 #
 #	r0 - updated length of input decimal string
 #	r1 - address of next byte of input decimal string
 #	r9 - count of extra zeros (see eo$adjust_input)
 #
 #	(sp) - return address to caller of this routine
 #
 #	note that r9<15:0> contains the data described by the architecture as
 #	appearing in r0<31:16>. in the event of an restartable exception
 #	(access violation or reserved operand fault due to an illegal pattern
 #	operator), the contents of r9<15:0> will be stored in r0<31:16>. in
 #	order for the instruction to be restarted, the "zero count" (the
 #	contents of r9) must be preserved. while any available field will do
 #	in the event of an access violation, the use of r0<31:16> is clearly
 #	specified for a reserved operand fault. 
 #
 # output parameters:
 #
 #	The behavior of this routine depends on the contents of r9
 #
 #	r9 is zero on input
 #
 #		r0 - updated by one 
 #		r1 - updated by one if r0<0> is clear on input
 #		r7 - next decimal digit in input string
 #		r9 - unchanged
 #
 #		psw<z> is set if the digit is zero, clear otherwise
 #
 #	r9 is nonzero (lss 0) on input
 #
 #		r0 - unchanged
 #		r1 - unchanged
 #		r7 - zero
 #		r9 - incremented by one (toward zero)
 #
 #		psw<z> is set
 #
 # notes:
 #
 #-

eo_read:
	tstl	r9			# check for "r0" lss 0
	bneq	2f			# special code if nonzero
	decl	r0			# insure that digits still remain
	blss	3f			# reserved operand if none
	blbc	r0,1f			# next code path is flip flop

 # r0 was even on input (and is now odd), indicating that we want the low
 # order nibble in the input stream. the input pointer r1 must be advanced 
 # to point to the next byte. 

	extzv	$0,$4,(r1)+,r7		# load low order nibble into r7
	rsb				# Return with information in Z-bit

 # r0 was odd on input (and is now even), indicating that we want the high
 # order nibble in the input stream. the next pass through this routine will
 # pick up the low order nibble of the same input byte. 

1:	extzv	$4,$4,(r1 ),r7		# load high order nibble into r7
	rsb				# return with information in z-bit

 # r9 was nonzero on input, indicating that zeros should replace the original
 # input digits.

2:	incl	r9			# advance r9 toward zero
	clrl	r7			# behave as if we read a zero digit
	rsb				# return with z-bit set

 # the input decimal string ran out of digits before its time. the architecture
 # dictates that r3 points to the pattern operator that requested the input
 # digit and r0 contains a -1 when the reserved operand abort is reported.
 # it is not necessary to load r0 here. r0 already contains -1 because it
 # just turned negative

3:	decl	r3			# back up r3 to current pattern operator
	addl2	$8,sp			# discard two return pcs
	movl	r0,r9			# it'll stuff R9 into R0<31:16>
	brw	editpc_roprand_fault	# branch aid for reserved operand abort

 #+
 # functional description:
 #
 #	insert a fixed character, substituting the fill character if
 #	not significant.
 #
 # input parameters:
 #
 #	r2 - fill character
 #	r3 - address of character to be inserted if significance is set
 #	r5 - address of next character to be stored in output character string
 #	r11<c> - current setting of significance
 #
 # output parameters:
 #
 #	character in pattern stream (or fill character if no significance)
 #	is stored in the the output string.
 #
 #	r3 - advanced beyond character in pattern stream
 #	r5 - advanced one byte as a result of the store operation
 #-

eo_insert_routine:
	bbc	$0,r11,1f		# skip next if no significance
	movb	(r3)+,(r5)+		# store "ch" in output string
	rsb

1:	movb	r2,(r5)+		# store fill character
	incl	r3			# skip over unused character
	rsb
 #+
 # functional description:
 #
 #	the contents of the sign register are placed into the output string.
 #
 # input parameters:
 #
 #	r4 - sign character
 #	r5 - address of next character to be stored in output character string
 #
 # output parameters:
 #
 #	sign character is stored in the the output string.
 #
 #	r5 - advanced one byte as a result of the store operation
 #-

eo_store_sign_routine:
	movb	r4,(r5)+		# store sign character
	rsb


 #+
 # functional description:
 #
 #	the contents of the fill register are placed into the output string
 #	a total of "repeat" times. 
 #
 # input parameters:
 #
 #	r2 - fill character
 #	r5 - address of next character to be stored in output character string
 #
 #	-1(r3)<3:0> - repeat count is stored in right nibble of pattern operator
 #
 # output parameters:
 #
 #	fill character is stored in the output string "repeat" times
 #
 #	r5 - advanced "repeat" bytes as a result of the store operations
 #-

eo_fill_routine:
	extzv	$0,$4,-1(r3 ),r8	# get repeat count from pattern operator
1:	movb	r2,(r5)+		# store fill character
	sobgtr	r8,1b			# test for end of loop
	rsb

 #+
 # functional description:
 #
 #	the right nibble of the pattern operator is  the  repeat  count.   for
 #	repeat  times, the following algorithm is executed.  the next digit is
 #	moved from the source to the destination.  if the digit  is  non-zero,
 #	significance  is  set  and  zero  is  cleared.   if  the  digit is not
 #	significant (i.e., is a leading zero) it is replaced by  the  contents
 #	of the fill register in the destination.
 #-

eo_move_routine:
	extzv	$0,$4,-1(r3 ),r8		# get repeat count

1:
0:  	 bsbw	eo_read			# get next input digit

 #	cmpb	$zero,r7		# is this digit zero?
	beql	3f			# branch if yes
	bisb2	$PSL_C,r11		# indicate significance 
	bicb2	$PSL_Z,r11		# also indicate nonzero

2:	addb3	$zero,r7,(r5)+		# store digit in output stream
	sobgtr	r8,1b			# test for end of loop
	rsb

3:	bbs	$0,r11,2b		# if significance, then store digit

	movb	r2,(r5)+		# otherwise, store fill character
	sobgtr	r8,1b			# test for end of loop
	rsb

 #+
 # functional description:
 #
 #	the right nibble of the pattern operator is  the  repeat  count.   for
 #	repeat  times,  the  following  algorithm is executed.  the next digit
 #	from the source is examined.  if it is non-zero  and  significance  is
 #	not  yet  set, then the contents of the sign register is stored in the
 #	destination, significance is set, and zero is cleared.  if  the  digit
 #	is  significant,  it  is  stored  in  the  destination,  otherwise the
 #	contents of the fill register is stored in the destination.
 #-

eo_float_routine:
	extzv	$0,$4,-1(r3 ),r8		# get repeat count

1:
0:  	 bsbw	eo_read			# get next input digit
	bbs	$0,r11,2f		# if significance, then store digit
 #	cmpb	$zero,r7		# is this digit zero?
	beql	3f			# branch if yes. store fill character.
	movb	r4,(r5)+		# store sign
	bisb2	$PSL_C,r11		# indicate significance 
	bicb2	$PSL_Z,r11		# also indicate nonzero

2:	addb3	$zero,r7,(r5)+		# store digit in output stream
	sobgtr	r8,1b			# test for end of loop
	rsb

3:
	movb	r2,(r5)+		# otherwise, store fill character
	sobgtr	r8,1b			# test for end of loop
	rsb

 #+
 # functional description:
 #
 #	if the floating sign has not yet been placed into the destination
 #	string (that is, if significance is not yet set ), then the contents
 #	of the sign register are stored in the output string and significance 
 #	is set.
 #
 # input parameters:
 #
 #	r4 - sign character
 #	r5 - address of next character to be stored in output character string
 #	r11<c> - current setting of significance
 #
 # output parameters:
 #
 #	sign character is optionally stored in the output string (if 
 #	significance was not yet set).
 #
 #	r5 - optionally advanced one byte as a result of the store operation
 #	r11<c> - (significance) is unconditionally set
 #-

eo_end_float_routine:
	bbss	$0,r11,1f		# test and set significance
	movb	r4,(r5)+		# store sign character
1:	rsb

 #+
 # functional description:
 #
 #	the pattern operator is followed by an unsigned byte  integer  length.
 #	if  the  value  of the source string is zero, then the contents of the
 #	fill register are stored into the last length bytes of the destination
 #	string.
 #
 # input parameters:
 #
 #	r2 - fill character
 #	r3 - address of "length", number of characters to blank
 #	r5 - address of next character to be stored in output character string
 #	r11<z> - set if input string is zero
 #
 # output parameters:
 #
 #	contents of fill register are stored in last "length" characters
 #	of output string if input string is zero.
 #
 #	r3 - advanced one byte over "length"
 #	r5 - unchanged
 #
 # side effects:
 #
 #	r8 is destroyed
 #-

eo_blank_zero_routine:
	movzbl	(r3)+,r8		# get length
	bbc	$2,r11,2f		# skip rest if source string is zero
	subl2	r8,r5			# back up destination pointer
1:	movb	r2,(r5)+		# store fill character
	sobgtr	r8,1b			# check for end of loop
2:	rsb

 #+
 # functional description:
 #
 #	if the value of the source string is zero, then the contents of the
 #	fill register are stored into the byte of the destination string
 #	that is "length" bytes before the current position.
 #
 # input parameters:
 #
 #	r2 - fill character
 #	r3 - address of "length", number of characters to blank
 #	r5 - address of next character to be stored in output character string
 #	r11<z> - set if input string is zero
 #
 # output parameters:
 #
 #	contents of fill register are stored in byte of output string
 #	"length" bytes before current position if input string is zero.
 #
 #	r3 - advanced one byte over "length"
 #	r5 - unchanged
 #
 # side effects:
 #
 #	r8 is destroyed
 #-

eo_replace_sign_routine:
	movzbl	(r3)+,r8		# get length
	bbc	$2,r11,1f		# skip rest if source string is zero
	subl3	r8,r5,r8		# get address of indicated byte
	movb	r2,(r8)			# store fill character
1:	rsb

 #+
 # functional description:
 #
 #	the contents of the fill or sign register are replaced with the
 #	character that follows the pattern operator in the pattern stream.
 #
 #	eo$load_fill	load fill register
 #
 #	eo$load_sign	load sign register
 #
 #	eo$load_plus	load sign register if source string is positive (or zero)
 #
 #	eo$load_minus	load sign register if source string is negative
 #
 # input parameters:
 #
 #	r3 - address of character to be loaded
 #	r11<n> - set if input string is lss zero (negative)
 #
 # output parameters:
 #
 #	if entry is at eo$load_fill, the fill register contents (r2<7:0>) are 
 #	replaced with the next character in the pattern stream. 
 # 
 #	if one of the other entry points is used (and the appropriate conditions
 #	obtain ), the contents of the sign register are replaced with the next
 #	character in the pattern stream. for simplicity of implementation, the
 #	sign character is stored in r4<7:0> while this routine executes. 
 #
 #	in the event of an exception, the contents of r4<7:0> will be stored
 #	in r2<15:8>, either to conform to the architectural specification of
 #	register contents in the event of a reserved operand fault, or to
 #	allow the instruction to be restarted in the event of an access
 #	violation. 
 #
 #	r3 - advanced one byte over new fill or sign character
 #-

eo_load_fill_routine:
	movb	(r3)+,r2		# load new fill character
	rsb

eo_load_sign_routine:
	movb	(r3)+,r4		# load new sign character into r4
	rsb

eo_load_plus_routine:
 	bbc	$3,r11,eo_load_sign_routine # use common code if plus
	incl	r3			# otherwise, skip unused character
	rsb

eo_load_minus_routine:
	bbs	$3,r11,eo_load_sign_routine # use common code if minus
	incl	r3			# otherwise, skip unused character
	rsb

 #+
 # functional description:
 #
 #	the significance indicator (c-bit in auxiliary psw) is set or
 #	cleared according to the entry point.
 #
 # input parameters:
 #
 #	none
 #
 # output parameters:
 #
 #	eo$clear_signif		r11<c> is cleared
 #
 #	eo$set_signif		r11<c> is set 
 #-

eo_clear_signif_routine:
	bicb2	$PSL_C,r11		# clear significance
	rsb

eo_set_signif_routine:
	bisb2	$PSL_C,r11		# set significance
	rsb

 #+
 # functional description:
 #
 #	the pattern operator is followed by an unsigned byte integer length in
 #	the  range  1  through  31.  if the source string has more digits than
 #	this length, the excess leading digits are read and discarded.  if any
 #	discarded  digits  are  non-zero then overflow is set, significance is
 #	set, and zero is cleared.  if the source string has fewer digits  than
 #	this  length,  a  counter  is  set  of  the number of leading zeros to
 #	supply.  this counter is stored as a negative number in r0<31:16>.
 #-

eo_adjust_input_routine:
	movzbl	(r3)+,r8		# get "length" from pattern stream
	subl3	r8,r0,r8		# is length larger than input length?
	blequ	3f			# branch if yes
	clrl	r9			# clear count of zeros ("r0<31:16>")

1:
0:  	 bsbw	eo_read			# get next input digit
 #	cmpb	$zero,r7		# is it zero?
	beql	2f			# skip to end of loop if zero
	bicb2	$PSL_Z,r11		# otherwise, indicate nonzero
	bisb2	$(PSL_C|PSL_V),r11	# indicate significance and overflow
2:	sobgtr	r8,1b			# test for end of loop
	rsb

3:	movl	r8,r9			# store difference into "r0<31:16>"
	rsb

 #+
 # functional description:
 #
 #	the edit operation is terminated.
 #
 #	the architectural description of editpc divides end processing between
 #	the eo$end routine and code at the end of the main loop. this 
 #	implementation performs all of the work in a single place.
 #
 #	the edit operation is terminated. there are several details that this
 #	routine must take care of.
 #
 #	1.  the return pc to the main dispatch loop is discarded.
 #
 #	2.  r3 is backed up to point to the eo$end pattern operator.
 #
 #	3.  a special check must be made for negative zero to insure that
 #	    the n-bit is cleared.
 #
 #	4.  if any digits still remain in the input string, a reserved
 #	    operand abort is taken.
 #
 #	5.  r2 and r4 are set to zero according to the architecture.
 #
 # input parameters:
 #
 #	r0 - number of digits remaining in input string
 #	r3 - address of one byte beyond the eo$end operator
 #
 #	00(sp)  - return address in dispatch loop in this module (discarded)
 #	04(sp) - saved r0
 #	08(sp) - saved r1
 #	12(sp) - saved r6
 #	16(sp) - saved r7
 #	20(sp) - saved r8
 #	24(sp) - saved r9
 #	28(sp) - saved r10
 #	32(sp) - saved r11
 #	36(sp) - return pc to caller of vax$editpc
 #
 # output parameters:
 #
 #	these register contents are dictated by the vax architecture
 #
 #	if no overflow has occured, then this routine exits through the rsb
 #	instruction with the following output parameters:
 #
 #	r0 - length in digits of input decimal string
 #	r1 - address of most significant byte of input decimal string
 #	r2 - set to zero to conform to architecture
 #	r3 - backed up one byte to point to eo$end operator
 #	r4 - set to zero to conform to architecture
 #	r5 - address of one byte beyond destination character string
 #
 #	psl<v> is clear
 #
 #	if the v-bit is set, then control is transferred to vax$editpc_overflow
 #	where a check for decimal overflow exceptions is made
 #
 #	the registers are loaded with their correct contents and then saved on
 #	the stack as follows:
 #
 #
 #	00(sp) - saved r0
 #	04(sp) - saved r1
 #	08(sp) - saved r2
 #	12(sp) - saved r3
 #	16(sp) - saved r4
 #	20(sp) - saved r5
 #	24(sp) - saved r6
 #	28(sp) - saved r7
 #	32(sp) - saved r8
 #	36(sp) - saved r9
 #	40(sp) - saved r10
 #	44(sp) - saved r11
 #	48(sp) - return pc to caller of vax$editpc
 #
 #	psl<v> is set
 #-

eo_end_routine:
	addl2	$4,sp			# discard return pc to main loop
	decl	r3			# back up pattern pointer one byte
	bbc	$2,r11,1f		# check for negative zero
	bicb2	$PSL_N,r11		# turn off n-bit if zero
1:	tstl	r0			# any digits remaining?
	bneq	editpc_roprand_fault	# error if yes
	tstl	r9			# any zeros (r0<31:16>) remaining?
	bneq	editpc_roprand_fault	# error if yes
	clrl	r2			# architecture specifies that r2
	clrl	r4			#  and r4 are zero on exit
	bbs	$1,r11,2f		# get out of line if overflow
 #	popr	$^m<r0,r1,r6,r7,r8,r9>	# restore saved registers
	 popr	$0x03c3
	movl	r11,4(sp)		# set return cc
	rsb				# return to caller's caller

 # at this point, we must determine whether the dv bit is set. the tests that 
 # must be performed are identical to the tests performed by the overflow
 # checking code for the packed decimal routines. in order to make use of
 # that code, we need to set up the saved registers on the stack to match
 # the input to that routine. note also that the decimal routines specify
 # that r0 is zero on completion while editpc dictates that r0 contains the
 # initial value of "srclen". for this reason, we cannot simply branch to
 # vax$decimal_exit but must use a special entry point.

2:
 #	popr	$^m<r0,r1>		# restore r0 and r1
	 popr	$0x03			#  but preserve condition codes
 #	pushr	$^m<r0,r1,r2,r3,r4,r5>	# ... only to save them again
	 pushr	$0x03f

 # the condition codes were not changed by the previous two instructions.

	jmp	_EM_editpc_overflow	# join exit code

 #+
 # functional description:
 #
 #	this routine stores the intermediate state of an editpc instruction
 #	that has been prematurely terminated by an illegal pattern operator.
 #	these exceptions and access violations are the only exceptions from
 #	which execution can continue after the exceptional condition has been
 #	cleared up. after the state is stored in the registers r0 through r5,
 #	control is transferred through vax$roprand to vax$reflect_fault, where
 #	the appropriate backup method is determined, based on the return pc
 #	from the vax$editpc routine. 
 #
 # input parameters:
 #
 #	r0  - current digit count in input string
 #	r1  - address of next digit in input string
 #	r2  - fill character
 #	r3  - address of illegal pattern operator
 #	r4  - sign character (stored in r2<15:8>)
 #	r5  - address of next character to be stored in output character string
 #	r9  - zero count (stored in r0<31:16>)
 #	r11 - condition codes
 #
 #	00(sp) - saved r0
 #	04(sp) - saved r1
 #	08(sp) - saved r6
 #	12(sp) - saved r7
 #	16(sp) - saved r8
 #	20(sp) - saved r9
 #	24(sp) - saved r10
 #	28(sp) - saved r11
 #	32(sp) - return pc from vax$editpc routine
 #
 # output parameters:
 #
 #	00(sp) - offset in packed register array to delta pc byte
 #	04(sp) - return pc from vax$editpc routine
 #
 #	some of the register contents are dictated by the vax architecture.
 #	other register contents are architecturally described as "implementation
 #	dependent" and are used to store the instruction state that enables it
 #	to be restarted successfully and complete according to specifications.
 #
 #	the following register contents are architecturally specified
 #
 #		r0<15:00> - current digit count in input string
 #		r0<31:16> - current zero count (from r9)
 #		r1        - address of next digit in input string
 #		r2<07:00> - fill character
 #		r2<15:08> - sign character (from r4)
 #		r3        - address of next pattern operator
 #		r5        - address of next character in output character string
 #
 #	the following register contents are peculiar to this implementation
 #
 #		r2<23:16> - delta-pc (if initiated by exception)
 #		r2<31:24> - delta srcaddr (current srcaddr minus initial srcaddr)
 #		r4<07:00> - initial digit count (from saved r0)
 #		r4<15:08> - saved condition codes (for easy retrieval)
 #		r4<23:16> - state flags
 #				state = editpc_2_restart
 #				fpd bit is set
 #				accvio bit is clear
 #		r4<31:24> - unused for this exception (see access violations)
 #
 #		editpc_2_restart is the restart code that causes the 
 #		instruction to be restarted at the top of the main loop.
 #		It is the simplest point at which to resume execution after
 #		an illegal pattern operator fault.
 #
 #	the condition codes reported in the exception psl are also defined
 #	by the vax architecture.
 #
 #		psl<n> - source string has a minus sign
 #		psl<z> - all digits are zero so far
 #		psl<v> - nonzero digits have been lost
 #		psl<c> - significance
 #-

 #	assume editpc_l_saved_r1 eq <editpc_l_saved_r0 + 4>

editpc_roprand_fault:
 #	pushr	$^m<r0,r1,r2,r3>		# save current r0..r3
	 pushr	$0x0f
	movq	editpc_l_saved_r0(sp),r0	# retrieve original r0 and r1
	movq	r4,16(sp)			# save r4 and r5 in right placeon stack

 # now start stuffing the various registers 

	movw	r9,editpc_w_zero_count(sp)	# save r9 in r0<31:16>
	movb	r4,editpc_b_sign(sp)		# save r4 in r2<15:8>
	movb	r0,editpc_b_inisrclen(sp)	# save initial value of r0
	subl3	r1,editpc_a_srcaddr(sp),r1	# calculate srcaddr difference
	movb	r1,editpc_b_delta_srcaddr(sp)	# store it in r4<15:8>
	movb	r11,editpc_b_saved_psw(sp)	# save condition codes
 #	movb	$(editpc_m_fpd|editpc_2_restart),editpc_b_state(sp)
						# set the fpd bit
	subl3	48(sp),84(sp),r0
	movb	r0,editpc_b_delta_pc(sp)
 #	popr	$^m<r0,r1,r2,r3,r4,r5,r6,r7,r8,r9> # load registers
 	 popr	$0x03ff
 #	pushl	$<editpc_b_delta_pc!-	# store delta-pc offset
 #		pack_m_fpd>		# indicate that fpd should be set
 #	 pushl	$(editpc_b_delta_pc|pack_m_fpd)

	insv	r11,$0,$4,48(sp)
	bisl2	$PSL_FPD,48(sp)
	jmp	_EM_reserved_operand	# continue exception handling


 #-
 # functional description:
 #
 #	this routine reports a reserved operand abort back to the caller.
 #
 #	reserved operand aborts are trivial to handle because they cannot be
 #	continued. there is no need to pack intermediate state into the
 #	general registers. those registers that should not be modified by the
 #	editpc instruction have their contents restored. control is then
 #	passed to vax$roprand, which takes the necessary steps to eventually
 #	reflect the exception back to the caller. 
 #
 #	the following conditions cause a reserved operand abort
 #
 #	    1.	input digit count gtru 31
 #		(this condition is detected by the editpc initialization code.)
 #
 #	    2.	not enough digits in source string to satisfy pattern operators
 #		(this condition is detected by the eo_read routine.)
 #
 #	    3.	too many digits in source string (digits left over)
 #		(this condition is detected by the eo$end routine.)
 #
 #	    4.	an eo$end operator was encountered while zero count was nonzero
 #		(this condition is also detected by the eo$end routine.)
 #
 #	Quasijarus note: we go through this code path only for case 1 above.
 #	My reading of VARM tells me that in the other three cases we must still
 #	set the registers and FPD even though it's an abort.  Therefore I have
 #	changed the code to jump to editpc_roprand_fault instead in these cases.
 #
 # input parameters:
 #
 #	00(sp) - saved r0
 #	04(sp) - saved r1
 #	08(sp) - saved r6
 #	12(sp) - saved r7
 #	16(sp) - saved r8
 #	20(sp) - saved r9
 #	24(sp) - saved r10
 #	28(sp) - saved r11
 #	32(sp) - return pc from vax$editpc routine
 #
 # output parameters:
 #
 #	the contents of r0 through r5 are not important because the 
 #	architecture states that they are unpredictable if a reserved
 #	operand abort occurs. no effort is made to put these registers
 #	into a consistent state.
 #
 #	r6 through r11 are restored to their values when the editpc 
 #	instruction began executing.
 #
 #	00(sp) - offset in packed register array to delta pc byte
 #	04(sp) - return pc from vax$editpc routine
 #
 # implicit output:
 #
 #	this routine passes control to vax$roprand where further
 #	exception processing takes place.
 #-

editpc_roprand_abort:
 #	popr	$^m<r0,r1,r6,r7,r8,r9>		# restore saved registers
	 popr	$0x03c3
	jmp	_EM_reserved_operand		# continue exception handling






 #+
 # functional description:
 #
 #	this routine receives control when an editpc instruction is restarted. 
 #	the instruction state (stack and general registers) is restored to the 
 #	point where it was when the instruction (routine) was interrupted and 
 #	control is passed back to the top of the control loop or to another
 #	restart point.
 #
 # input parameters:
 #
 #	 31		  23 		   15		    07		  00
 #	+----------------+----------------+----------------+----------------+
 #	|       zero count		  |		srclen		    |
 #	+----------------+----------------+----------------+----------------+
 #	| delta-srcaddr  |  delta-pc      |    sign        |      fill      |
 #	+----------------+----------------+----------------+----------------+
 #      | loop-count     |   state        |   saved-psw    |     inisrclen  |
 #	+----------------+----------------+----------------+----------------+
 #	|			       dstaddr				    |
 #      +----------------+----------------+----------------+----------------+
 #
 #	depending on where the exception occurred, some of these parameters 
 #	may not be relevant. they are nevertheless stored as if they were 
 #	valid to make this restart code as simple as possible.
 #
 #	these register fields are more or less architecturally defined. they 
 #	are strictly specified for a reserved operand fault (illegal pattern 
 #	operator) and it makes sense to use the same register fields for 
 #	access violations as well.
 #
 #		r0<07:00> - current digit count in input string 
 #			(see eo_read_char below)
 #		r0<31:16> - current zero count (loaded into r9)
 #		r1        - address of next digit in input string
 #		r2<07:00> - fill character
 #		r2<15:08> - sign character (loaded into r4)
 #		r3        - address of next pattern operator
 #		r5        - address of next character in output character string
 #
 #	these register fields are specific to this implementation. 
 #
 #		r0<15:08> - latest digit from input string (loaded into r7)
 #		r2<23:16> - size of instruction (unused by this routine)
 #		r2<31:24> - delta srcaddr (used to compute saved r1)
 #		r4<07:00> - initial digit count (stored in saved r0)
 #		r4<15:08> - saved condition codes (stored in r11)
 #			psl<n> - source string has a minus sign
 #			psl<z> - all digits are zero so far
 #			psl<v> - nonzero digits have been lost
 #			psl<c> - significance
 #		r4<23:16> - state flags
 #			state field determines the restart point
 #		r4<31:24> - loop count (loaded into r8)
 #
 #	00(sp) - return pc from vax$editpc routine
 #
 # implicit input:
 #
 #	note that the initial "srclen" is checked for legality before any
 #	restartable exception can occur. this means that r0 lequ 31, which
 #	leaves bits <15:5> free for storing intermediate state. in the case of
 #	an access violation, r0<15:8> is used to store the latest digit read
 #	from the input stream. in the case of an illegal pattern operator,
 #	r0<15:5> are not used so that the architectural requirement that
 #	r0<15:0> contain the current byte count is adhered to. 
 #
 # output parameters:
 #
 #	all of the registers are loaded, even if some of their contents are 
 #	not relevant to the particular point at which the instruction will be 
 #	restarted. this makes the output of this routine conditional on a 
 #	single thing, namely on whether the restart point is in one of the 
 #	pattern-specific routines or in the outer vax$editpc routine. this
 #	comment applies especially to r7 and r8.
 #
 #	r0  - current digit count in input string
 #	r1  - address of next digit in input string
 #	r2  - fill character
 #	r3  - address of next pattern operator
 #	r4  - sign character (stored in r2<15:8>)
 #	r5  - address of next character to be stored in output character string
 #	r6  - scratch
 #	r7  - latest digit read from input packed decimal string
 #	r8  - loop count
 #	r9  - zero count (stored in r0<31:16>)
 #	r10 - address of editpc_accvio, this module's "condition handler"
 #	r11 - condition codes
 #
 #	00(sp) - saved r0
 #	04(sp) - saved r1
 #	08(sp) - saved r6
 #	12(sp) - saved r7
 #	16(sp) - saved r8
 #	20(sp) - saved r9
 #	24(sp) - saved r10
 #	28(sp) - saved r11
 #	32(sp) - return pc from vax$editpc routine
 #
 # side effects:
 #
 #	r6 is assumed unimportant and is used as a scratch register by this 
 #	routine as soon as it is saved.
 #-

	.globl	_EM_editpc_restart
_EM_editpc_restart:
 #	pushr	$^m<r0,r1,r2,r3,r4,r5,r6,r7,r8,r9>	# save them all
	 pushr	$0x03ff
	movzbl	r0,r0				# clear out r0<31:8>
	movzbl	editpc_b_sign(sp),r4		# put "sign" back into r4
 #	extzv	$editpc_v_state,-
 #		$editpc_s_state,-
 #		editpc_b_state(sp),r6		# put restart code into r6
 #	 extzv	$editpc_v_state,$editpc_s_state,editpc_b_state(sp),r6

 # the following two values are not used on all restart paths but r7 and r8
 # are loaded unconditionally to make this routine simpler. The most extreme
 # example is that r7 gets recalculated below for the editpc_1 restart point.

	movzbl	editpc_b_eo_read_char(sp),r7	# get latest input digit
	movzbl	editpc_b_loop_count(sp),r8	# restore loop count
	cvtwl	editpc_w_zero_count(sp),r9	# reset zero count (r9 lss 0)
	movzbl	editpc_b_saved_psw(sp),r11	# restore saved condition codes

 # the next three instructions reconstruct the initial values of "srclen" and
 # "srcaddr" and store them on the stack just above the saved r6. these values
 # will be loaded into r0 and r1 when the instruction completes execution.
 # note that these two instructions destroy information in the saved copy of
 # r4 so all of that information must be removed before these instructions
 # execute. 

	movzbl	editpc_b_delta_srcaddr(sp),editpc_l_saved_r1(sp)
	subl3	editpc_l_saved_r1(sp),editpc_a_srcaddr(sp),editpc_l_saved_r1(sp)
	movzbl	editpc_b_inisrclen(sp),editpc_l_saved_r0(sp)

 # the top four longwords are discarded and control is passed to the restart
 # point obtained from the restart pc table. note that there is an assumption
 # here that the first two restart points are different from the others in that
 # they do not have an additional return pc (top_of_loop) on the stack.

	addl2	$editpc_l_saved_r0,sp	# make saved registers r0, r1, r6, ...
	jbr	top_of_loop		# restart the main loop

#endif NEED_SAMEMODE_EMU
