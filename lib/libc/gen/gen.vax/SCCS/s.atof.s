h44325
s 00013/00008/00323
d D 5.5 88/06/27 17:24:59 bostic 8 7
c install approved copyright notice
e
s 00011/00005/00320
d D 5.4 88/05/25 17:13:39 bostic 7 6
c written by Kirk McKusick and Sam Leffler; add Berkeley specific header
e
s 00002/00002/00323
d D 5.3 86/03/09 21:11:15 donn 6 5
c added LIBC_SCCS condition for sccs ids
e
s 00001/00001/00324
d D 5.2 85/06/05 18:57:13 mckusick 5 4
c Fix copyright
e
s 00009/00001/00316
d D 5.1 85/05/30 15:12:26 dist 4 3
c Add copyright
e
s 00007/00016/00310
d D 4.3 84/11/01 23:51:18 sam 3 2
c change ENTRY & ASENTRY to allow setting the register save mask
e
s 00179/00173/00147
d D 4.2 83/06/30 16:27:03 sam 2 1
c .s
e
s 00320/00000/00000
d D 4.1 83/05/03 19:06:33 sam 1 0
c date and time created 83/05/03 19:06:33 by sam
e
u
U
t
T
I 1
D 2
# %W% (Berkeley) %G%
#
#	atof: convert ascii to floating
#
#	C usage:
#
#		double atof (s)
#		char *s;
#
#	Register usage:
#
#		r0-1:	value being developed
#		r2:	first section: pointer to the next character
#			second section: binary exponent
#		r3:	flags
#		r4:	first section: the current character
#			second section: scratch
#		r5:	the decimal exponent
#		r6-7:	scratch
#
#	Flag definitions
#
E 2
I 2
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 8
E 7
 */

D 6
#ifndef lint
E 6
I 6
D 7
#ifdef LIBC_SCCS
E 6
D 5
static char sccsid[] = "%W% (Berkeley) %G%";
E 5
I 5
	.asciz	"%W% (Berkeley) %G%"
E 5
D 6
#endif not lint
E 6
I 6
#endif LIBC_SCCS
E 7
I 7
D 8
#if defined(SYSLIBC_SCCS) && !defined(lint)
_sccsid:.asciz	"%W% (Berkeley) %G%"
#endif /* SYSLIBC_SCCS and not lint */
E 8
I 8
#if defined(LIBC_SCCS) && !defined(lint)
	.asciz "%W% (Berkeley) %G%"
#endif /* LIBC_SCCS and not lint */
E 8
E 7
E 6
E 4

#include "DEFS.h"

/*
 *	atof: convert ascii to floating
 *
 *	C usage:
 *
 *		double atof (s)
 *		char *s;
 *
 *	Register usage:
 *
 *		r0-1:	value being developed
 *		r2:	first section: pointer to the next character
 *			second section: binary exponent
 *		r3:	flags
 *		r4:	first section: the current character
 *			second section: scratch
 *		r5:	the decimal exponent
 *		r6-7:	scratch
D 3
 *
 *	Flag definitions
E 3
 */
E 2
	.set	msign,0		# mantissa has negative sign
	.set	esign,1		# exponent has negative sign
	.set	decpt,2		# decimal point encountered

D 3
	.align	2
two31:	.word	0x5000		# 2 ** 31
	.word	0		# (=2147483648)
	.word	0		# in floating-point
	.word	0		# (so atof doesn't have to convert it)
E 3
I 3
ENTRY(atof, R6|R7)
E 3
D 2
#
#	Entry point
#
	.text
	.align 2
	.globl	_atof
_atof:	.word	0x00c0		# Save r7, r6 (we use r0-r7)
#
#	Initialization
#
E 2
I 2
/*
D 3
 *	Entry point
 */
ENTRY(atof)
	pushl	r6
	pushl	r7
/*
E 3
 *	Initialization
 */
E 2
	clrl	r3		# All flags start out false
	movl	4(ap),r2	# Address the first character
	clrl	r5		# Clear starting exponent
D 2
#
#	Skip leading white space
#
E 2
I 2
/*
 *	Skip leading white space
 */
E 2
sk0:	movzbl	(r2)+,r4	# Fetch the next (first) character
	cmpb	$' ,r4		# Is it blank?
	jeql	sk0		#   ...yes
	cmpb	r4,$8		# 8 is lowest of white-space group
	jlss	sk1		# Jump if char too low to be white space
	cmpb	r4,$13		# 13 is highest of white-space group
	jleq	sk0		# Jump if character is white space
sk1:
D 2
#
#	Check for a sign
#
E 2
I 2
/*
 *	Check for a sign
 */
E 2
	cmpb	$'+,r4		# Positive sign?
	jeql	cs1		#   ... yes
	cmpb	$'-,r4		# Negative sign?
	jneq	cs2		#   ... no
	bisb2	$1<msign,r3	# Indicate a negative mantissa
cs1:	movzbl	(r2)+,r4	# Skip the character
cs2:
D 2
#
#	Accumulate digits, keeping track of the exponent
#
E 2
I 2
/*
 *	Accumulate digits, keeping track of the exponent
 */
E 2
	clrq	r0		# Clear the accumulator
ad0:	cmpb	r4,$'0		# Do we have a digit?
	jlss	ad4		#   ... no, too small
	cmpb	r4,$'9
	jgtr	ad4		#   ... no, too large
D 2
#
#	We got a digit.  Accumulate it
#
E 2
I 2
/*
 *	We got a digit.  Accumulate it
 */
E 2
	cmpl	r1,$214748364	# Would this digit cause overflow?
	jgeq	ad1		#   ... yes
D 2
#
#	Multiply (r0,r1) by 10.  This is done by developing
#	(r0,r1)*2 in (r6,r7), shifting (r0,r1) left three bits,
#	and adding the two quadwords.
#
E 2
I 2
/*
 *	Multiply (r0,r1) by 10.  This is done by developing
 *	(r0,r1)*2 in (r6,r7), shifting (r0,r1) left three bits,
 *	and adding the two quadwords.
 */
E 2
	ashq	$1,r0,r6	# (r6,r7)=(r0,r1)*2
	ashq	$3,r0,r0	# (r0,r1)=(r0,r1)*8
	addl2	r6,r0		# Add low halves
	adwc	r7,r1		# Add high halves
D 2
#
#	Add in the digit
#
E 2
I 2
/*
 *	Add in the digit
 */
E 2
	subl2	$'0,r4		# Get the digit value
	addl2	r4,r0		# Add it into the accumulator
	adwc	$0,r1		# Possible carry into high half
	jbr	ad2		# Join common code
D 2
#
#	Here when the digit won't fit in the accumulator
#
E 2
I 2
/*
 *	Here when the digit won't fit in the accumulator
 */
E 2
ad1:	incl	r5		# Ignore the digit, bump exponent
D 2
#
#	If we have seen a decimal point, decrease the exponent by 1
#
E 2
I 2
/*
 *	If we have seen a decimal point, decrease the exponent by 1
 */
E 2
ad2:	jbc	$decpt,r3,ad3	# Jump if decimal point not seen
	decl	r5		# Decrease exponent
ad3:
D 2
#
#	Fetch the next character, back for more
#
E 2
I 2
/*
 *	Fetch the next character, back for more
 */
E 2
	movzbl	(r2)+,r4	# Fetch
	jbr	ad0		# Try again
D 2
#
#	Not a digit.  Could it be a decimal point?
#
E 2
I 2
/*
 *	Not a digit.  Could it be a decimal point?
 */
E 2
ad4:	cmpb	r4,$'.		# If it's not a decimal point, either it's
	jneq	ad5		#   the end of the number or the start of
				#   the exponent.
	jbcs	$decpt,r3,ad3	# If it IS a decimal point, we record that
				#   we've seen one, and keep collecting
				#   digits if it is the first one.
D 2
#
#	Check for an exponent
#
E 2
I 2
/*
 *	Check for an exponent
 */
E 2
ad5:	clrl	r6		# Initialize the exponent accumulator

	cmpb	r4,$'e		# We allow both lower case e
	jeql	ex1		#   ... and ...
	cmpb	r4,$'E		#   upper-case E
	jneq	ex7
D 2
#
#	Does the exponent have a sign?
#
E 2
I 2
/*
 *	Does the exponent have a sign?
 */
E 2
ex1:	movzbl	(r2)+,r4	# Get next character
	cmpb	r4,$'+		# Positive sign?
	jeql	ex2		#   ... yes ...
	cmpb	r4,$'-		# Negative sign?
	jneq	ex3		#   ... no ...
	bisb2	$1<esign,r3	# Indicate exponent is negative
ex2:	movzbl	(r2)+,r4	# Grab the next character
D 2
#
#	Accumulate exponent digits in r6
#
E 2
I 2
/*
 *	Accumulate exponent digits in r6
 */
E 2
ex3:	cmpb	r4,$'0		# A digit is within the range
	jlss	ex4		# '0' through
	cmpb	r4,$'9		# '9',
	jgtr	ex4		# inclusive.
	cmpl	r6,$214748364	# Exponent outrageously large already?
	jgeq	ex2		#   ... yes
	moval	(r6)[r6],r6	# r6 *= 5
	movaw	-'0(r4)[r6],r6	# r6 = r6 * 2 + r4 - '0'
	jbr	ex2		# Go 'round again
ex4:
D 2
#
#	Now get the final exponent and force it within a reasonable
#	range so our scaling loops don't take forever for values
#	that will ultimately cause overflow or underflow anyway.
#	A tight check on over/underflow will be done by ldexp.
#
E 2
I 2
/*
 *	Now get the final exponent and force it within a reasonable
 *	range so our scaling loops don't take forever for values
 *	that will ultimately cause overflow or underflow anyway.
 *	A tight check on over/underflow will be done by ldexp.
 */
E 2
	jbc	$esign,r3,ex5	# Jump if exponent not negative
	mnegl	r6,r6		# If sign, negate exponent
ex5:	addl2	r6,r5		# Add given exponent to calculated exponent
	cmpl	r5,$-100	# Absurdly small?
	jgtr	ex6		#   ... no
	movl	$-100,r5	#   ... yes, force within limit
ex6:	cmpl	r5,$100		# Absurdly large?
	jlss	ex7		#   ... no
	movl	$100,r5		#   ... yes, force within bounds
ex7:
D 2
#
#	Our number has now been reduced to a mantissa and an exponent.
#	The mantissa is a 63-bit positive binary integer in r0,r1,
#	and the exponent is a signed power of 10 in r5.  The msign
#	bit in r3 will be on if the mantissa should ultimately be
#	considered negative.
#
#	We now have to convert it to a standard format floating point
#	number.  This will be done by accumulating a binary exponent
#	in r2, as we progressively get r5 closer to zero.
#
#	Don't bother scaling if the mantissa is zero
#
E 2
I 2
/*
 *	Our number has now been reduced to a mantissa and an exponent.
 *	The mantissa is a 63-bit positive binary integer in r0,r1,
 *	and the exponent is a signed power of 10 in r5.  The msign
 *	bit in r3 will be on if the mantissa should ultimately be
 *	considered negative.
 *
 *	We now have to convert it to a standard format floating point
 *	number.  This will be done by accumulating a binary exponent
 *	in r2, as we progressively get r5 closer to zero.
 *
 *	Don't bother scaling if the mantissa is zero
 */
E 2
	movq	r0,r0		# Mantissa zero?
	jeql	exit		#   ... yes

	clrl	r2		# Initialize binary exponent
	tstl	r5		# Which way to scale?
	jleq	sd0		# Scale down if decimal exponent <= 0
D 2
#
#	Scale up by "multiplying" r0,r1 by 10 as many times as necessary,
#	as follows:
#
#	Step 1: Shift r0,r1 right as necessary to ensure that no
#	overflow can occur when multiplying.
#
E 2
I 2
/*
 *	Scale up by "multiplying" r0,r1 by 10 as many times as necessary,
 *	as follows:
 *
 *	Step 1: Shift r0,r1 right as necessary to ensure that no
 *	overflow can occur when multiplying.
 */
E 2
su0:	cmpl	r1,$429496729	# Compare high word to (2**31)/5
	jlss	su1		# Jump out if guaranteed safe
	ashq	$-1,r0,r0	# Else shift right one bit
	incl	r2		#    bump exponent to compensate
	jbr	su0		#    and go back to test again.
D 2
#
#	Step 2: Multiply r0,r1 by 5, by appropriate shifting and
#	double-precision addition
#
E 2
I 2
/*
 *	Step 2: Multiply r0,r1 by 5, by appropriate shifting and
 *	double-precision addition
 */
E 2
su1:	ashq	$2,r0,r6	# (r6,r7) := (r0,r1) * 4
	addl2	r6,r0		# Add low-order halves
	adwc	r7,r1		#   and high-order halves
D 2
#
#	Step 3: Increment the binary exponent to take care of the final
#	factor of 2, and go back if we still need to scale more.
#
E 2
I 2
/*
 *	Step 3: Increment the binary exponent to take care of the final
 *	factor of 2, and go back if we still need to scale more.
 */
E 2
	incl	r2		# Increment the exponent
	sobgtr	r5,su0		#    and back for more (maybe)

	jbr	cm0		# Merge to build final value

D 2
#
#	Scale down.  We must "divide" r0,r1 by 10 as many times
#	as needed, as follows:
#
#	Step 0: Right now, the condition codes reflect the state
#	of r5.  If it's zero, we are done.
#
E 2
I 2
/*
 *	Scale down.  We must "divide" r0,r1 by 10 as many times
 *	as needed, as follows:
 *
 *	Step 0: Right now, the condition codes reflect the state
 *	of r5.  If it's zero, we are done.
 */
E 2
sd0:	jeql	cm0		# If finished, build final number
D 2
#
#	Step 1: Shift r0,r1 left until the high-order bit (not counting
#	the sign bit) is nonzero, so that the division will preserve
#	as much precision as possible.
#
E 2
I 2
/*
 *	Step 1: Shift r0,r1 left until the high-order bit (not counting
 *	the sign bit) is nonzero, so that the division will preserve
 *	as much precision as possible.
 */
E 2
	tstl	r1		# Is the entire high-order half zero?
	jneq	sd2		#   ...no, go shift one bit at a time
	ashq	$30,r0,r0	#   ...yes, shift left 30,
	subl2	$30,r2		#   decrement the exponent to compensate,
				#   and now it's known to be safe to shift
				#   at least once more.
sd1:	ashq	$1,r0,r0	# Shift (r0,r1) left one, and
	decl	r2		#   decrement the exponent to compensate
sd2:	jbc	$30,r1,sd1	# If the high-order bit is off, go shift
D 2
#
#	Step 2: Divide the high-order part of (r0,r1) by 5,
#	giving a quotient in r1 and a remainder in r7.
#
E 2
I 2
/*
 *	Step 2: Divide the high-order part of (r0,r1) by 5,
 *	giving a quotient in r1 and a remainder in r7.
 */
E 2
sd3:	movl	r1,r6		# Copy the high-order part
	clrl	r7		# Zero-extend to 64 bits
	ediv	$5,r6,r1,r7	# Divide (cannot overflow)
D 2
#
#	Step 3: Divide the low-order part of (r0,r1) by 5,
#	using the remainder from step 2 for rounding.
#	Note that the result of this computation is unsigned,
#	so we have to allow for the fact that an ordinary division
#	by 5 could overflow.  We make allowance by dividing by 10,
#	multiplying the quotient by 2, and using the remainder
#	to adjust the modified quotient.
#
E 2
I 2
/*
 *	Step 3: Divide the low-order part of (r0,r1) by 5,
 *	using the remainder from step 2 for rounding.
 *	Note that the result of this computation is unsigned,
 *	so we have to allow for the fact that an ordinary division
 *	by 5 could overflow.  We make allowance by dividing by 10,
 *	multiplying the quotient by 2, and using the remainder
 *	to adjust the modified quotient.
 */
E 2
	addl3	$2,r0,r6	# Dividend is low part of (r0,r1) plus
	adwc	$0,r7		#  2 for rounding plus
				#  (2**32) * previous remainder
	ediv	$10,r6,r0,r6	# r0 := quotient, r6 := remainder.
	addl2	r0,r0		# Make r0 result of dividing by 5
	cmpl	r6,$5		# If remainder is 5 or greater,
	jlss	sd4		#   increment the adjustted quotient.
	incl	r0
D 2
#
#	Step 4: Increment the decimal exponent, decrement the binary
#	exponent (to make the division by 5 into a division by 10),
#	and back for another iteration.
#
E 2
I 2
/*
 *	Step 4: Increment the decimal exponent, decrement the binary
 *	exponent (to make the division by 5 into a division by 10),
 *	and back for another iteration.
 */
E 2
sd4:	decl	r2		# Binary exponent
	aoblss	$0,r5,sd2
D 2
#
#	We now have the following:
#
#	r0:	low-order half of a 64-bit integer
#	r1:	high-order half of the same 64-bit integer
#	r2:	a binary exponent
#
#	Our final result is the integer represented by (r0,r1)
#	multiplied by 2 to the power contained in r2.
#	We will transform (r0,r1) into a floating-point value,
#	set the sign appropriately, and let ldexp do the
#	rest of the work.
#
#	Step 1: if the high-order bit (excluding the sign) of
#	the high-order half (r1) is 1, then we have 63 bits of
#	fraction, too many to convert easily.  However, we also
#	know we won't need them all, so we will just throw the
#	low-order bit away (and adjust the exponent appropriately).
#
E 2
I 2
/*
 *	We now have the following:
 *
 *	r0:	low-order half of a 64-bit integer
 *	r1:	high-order half of the same 64-bit integer
 *	r2:	a binary exponent
 *
 *	Our final result is the integer represented by (r0,r1)
 *	multiplied by 2 to the power contained in r2.
 *	We will transform (r0,r1) into a floating-point value,
 *	set the sign appropriately, and let ldexp do the
 *	rest of the work.
 *
 *	Step 1: if the high-order bit (excluding the sign) of
 *	the high-order half (r1) is 1, then we have 63 bits of
 *	fraction, too many to convert easily.  However, we also
 *	know we won't need them all, so we will just throw the
 *	low-order bit away (and adjust the exponent appropriately).
 */
E 2
cm0:	jbc	$30,r1,cm1	# jump if no adjustment needed
	ashq	$-1,r0,r0	# lose the low-order bit
	incl	r2		# increase the exponent to compensate
D 2
#
#	Step 2: split the 62-bit number in (r0,r1) into two
#	31-bit positive quantities
#
E 2
I 2
/*
 *	Step 2: split the 62-bit number in (r0,r1) into two
 *	31-bit positive quantities
 */
E 2
cm1:	ashq	$1,r0,r0	# put the high-order bits in r1
				#   and a 0 in the bottom of r0
	rotl	$-1,r0,r0	# right-justify the bits in r0
				#   moving the 0 from the ashq
				#   into the sign bit.
D 2
#
#	Step 3: convert both halves to floating point
#
E 2
I 2
/*
 *	Step 3: convert both halves to floating point
 */
E 2
	cvtld	r0,r6		# low-order part in r6-r7
	cvtld	r1,r0		# high-order part in r0-r1
D 2
#
#	Step 4: multiply the high order part by 2**31 and combine them
#
E 2
I 2
/*
 *	Step 4: multiply the high order part by 2**31 and combine them
 */
E 2
	muld2	two31,r0	# multiply
	addd2	r6,r0		# combine
D 2
#
#	Step 5: if appropriate, negate the floating value
#
E 2
I 2
/*
 *	Step 5: if appropriate, negate the floating value
 */
E 2
	jbc	$msign,r3,cm2	# Jump if mantissa not signed
	mnegd	r0,r0		# If negative, make it so
D 2
#
#	Step 6: call ldexp to complete the job
#
E 2
I 2
/*
 *	Step 6: call ldexp to complete the job
 */
E 2
cm2:	pushl	r2		# Put exponent in parameter list
	movd	r0,-(sp)	#    and also mantissa
	calls	$3,_ldexp	# go combine them

D 2
exit:	ret
E 2
I 2
D 3

E 3
exit:
D 3
	movl	(sp)+,r7
	movl	(sp)+,r6
E 3
	ret
I 3

	.align	2
two31:	.word	0x5000		# 2 ** 31
	.word	0		# (=2147483648)
	.word	0		# in floating-point
	.word	0		# (so atof doesn't have to convert it)
E 3
E 2
E 1
