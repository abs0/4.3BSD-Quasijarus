h61962
s 00000/00000/00040
d D 7.1 86/06/05 00:58:13 mckusick 6 5
c 4.3BSD release version
e
s 00002/00001/00038
d D 6.3 85/06/08 14:00:20 mckusick 5 4
c Add copyright
e
s 00020/00019/00019
d D 6.2 84/08/01 17:48:48 mckusick 4 2
c add provision for profiling
e
s 00003/00000/00038
d R 6.2 84/08/01 16:57:59 mckusick 3 2
c add provision for profiling
e
s 00000/00000/00038
d D 6.1 83/07/29 07:21:42 sam 2 1
c 4.2 distribution
e
s 00038/00000/00000
d D 5.1 82/07/15 20:36:14 root 1 0
c date and time created 82/07/15 20:36:14 by root
e
u
U
t
T
I 1
D 4
#	%M%	%I%	%E%
#
#	urem - unsigned remainder for vax-11
#
#	arguments: dividend, divisor
#	result: remainder
#	uses r0-r2
#
#	if 1 < divisor <= 2147483647, zero-extend the dividend
#	to 64 bits and let ediv do the work.  If the divisor is 1,
#	ediv will overflow if bit 31 of the dividend is on, so
#	just return 0.  If the divisor is 0, do the ediv also,
#	so it will generate the proper exception.  All other values
#	of the divisor have bit 31 on: in this case the remainder
#	must be the dividend if divisor > dividend, and the dividend
#	minus the divisor otherwise.  The comparison must be unsigned.
#
E 4
I 4
D 5
/*	%M%	%I%	%E%
E 5
I 5
/*
 *	%W% (Berkeley) %G%
E 5
 *
 *	urem - unsigned remainder for vax-11
 *
 *	arguments: dividend, divisor
 *	result: remainder
 *	uses r0-r2
 *
 *	if 1 < divisor <= 2147483647, zero-extend the dividend
 *	to 64 bits and let ediv do the work.  If the divisor is 1,
 *	ediv will overflow if bit 31 of the dividend is on, so
 *	just return 0.  If the divisor is 0, do the ediv also,
 *	so it will generate the proper exception.  All other values
 *	of the divisor have bit 31 on: in this case the remainder
 *	must be the dividend if divisor > dividend, and the dividend
 *	minus the divisor otherwise.  The comparison must be unsigned.
 */
E 4
	.text
	.align	1
	.globl	urem
urem:	.word	0x0000
I 4
#ifdef GPROF
	jsb	mcount
#endif GPROF
E 4
	movl	4(ap),r0	# Dividend
	movl	8(ap),r2	# Divisor
	jeql	div		# If divisor=0, force exception
	cmpl	r2,$1		# If divisor <= 1 (signed),
	jleq	nodiv		#  no division is necessary
div:	clrl	r1		# Zero-extend the dividend
	ediv	r2,r0,r2,r0	# Divide.  q->r2 (discarded), r->r0
	ret
nodiv:	jneq	nzero		# If divisor=1, return 0
	clrl	r0		#  (because doing the divide will overflow
	ret			#  if the dividend has its high bit on)
nzero:	cmpl	r0,r2		# If dividend < divisor (unsigned)
	jlssu	retn		#  remainder is dividend
	subl2	r2,r0		#  else remainder is dividend - divisor
retn:	ret
D 4


E 4
E 1
