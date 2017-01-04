h51566
s 00013/00006/00071
d D 7.3 87/12/03 19:32:50 marc 8 7
c oops - expand ENTRY() macro
e
s 00070/00033/00007
d D 7.2 87/12/03 16:40:09 marc 7 6
c Grab newer version of udiv of libc/vax. This one was missing audiv().
e
s 00000/00000/00040
d D 7.1 86/06/05 00:58:08 mckusick 6 5
c 4.3BSD release version
e
s 00002/00001/00038
d D 6.3 85/06/08 13:59:41 mckusick 5 4
c Add copyright
e
s 00020/00019/00019
d D 6.2 84/08/01 17:48:41 mckusick 4 2
c add provision for profiling
e
s 00003/00000/00038
d R 6.2 84/08/01 16:57:54 mckusick 3 2
c add provision for profiling
e
s 00000/00000/00038
d D 6.1 83/07/29 07:21:38 sam 2 1
c 4.2 distribution
e
s 00038/00000/00000
d D 5.1 82/07/15 20:36:11 root 1 0
c date and time created 82/07/15 20:36:11 by root
e
u
U
t
T
I 7
#ifdef LIBC_SCCS
	.asciz	"%W% (Berkeley) %G%"
#endif /*LIBC_SCCS*/

E 7
I 1
D 4
#	%M%	%I%	%E%
#
#	udiv - unsigned division for vax-11
#
#	arguments: dividend, divisor.
#	result: quotient.
#	uses r0-r2
#
#	If 1 < divisor <= 2147483647, zero-extend the dividend
#	to 64 bits and let ediv do the work.  If the divisor is 1,
#	ediv will overflow if bit 31 of the dividend is on, so
#	just return the dividend unchanged.  If the divisor is 0,
#	do the ediv also, so it will generate the proper exception.
#	All other values of the divisor have bit 31 on: in this case
#	the quotient must be 0 if divisor > dividend, and 1 otherwise,
#	provided that the comparison is made as unsigned.
#
E 4
I 4
D 5
/*	%M%	%I%	%E%
E 5
I 5
/*
D 7
 *	%W% (Berkeley) %G%
E 7
I 7
 * udiv - unsigned division for vax-11
E 7
E 5
 *
D 7
 *	udiv - unsigned division for vax-11
E 7
I 7
 * arguments: dividend, divisor.
 * result: quotient.
 * uses r0-r2
E 7
 *
D 7
 *	arguments: dividend, divisor.
 *	result: quotient.
 *	uses r0-r2
E 7
I 7
 * If 1 < divisor <= 2147483647, zero-extend the dividend
 * to 64 bits and let ediv do the work.  If the divisor is 1,
 * ediv will overflow if bit 31 of the dividend is on, so
 * just return the dividend unchanged.  If the divisor is 0,
 * do the ediv also, so it will generate the proper exception.
 * All other values of the divisor have bit 31 on: in this case
 * the quotient must be 0 if divisor > dividend, and 1 otherwise,
 * provided that the comparison is made as unsigned.
 */

D 8
#include "DEFS.h"

ASENTRY(udiv, 0)
E 8
I 8
	.text
	.align	2
	.globl	udiv
udiv:	.word	0x0000
#ifdef	GPROF
	jsb	mcount
#endif	/*GPROF*/
E 8
	movl	4(ap),r0	/* dividend */
	movl	8(ap),r2	/* divisor */
	jeql	1f		/* if divisor=0, force exception */
	cmpl	r2,$1		/* if divisor <= 1 (signed), */
	jleq	2f		/*  no division is necessary */
1:
	clrl	r1		/* zero-extend the dividend */
	ediv	r2,r0,r0,r2	/* divide.  q->r0, r->r2 (discarded) */
	ret
2:	
	jeql	1f		/* if divisor=1, return dividend */
	cmpl	r0,r2		/* unsigned comparison between */
	jgequ	2f		/*  dividend and divisor */
	clrl	r0		/* dividend < divisor, return 0 */
	ret
2:	
	movl	$1,r0		/* dividend >= divisor, return 1 */
1:	
	ret

/*
 * audiv - unsigned division for vax-11
E 7
 *
D 7
 *	If 1 < divisor <= 2147483647, zero-extend the dividend
 *	to 64 bits and let ediv do the work.  If the divisor is 1,
 *	ediv will overflow if bit 31 of the dividend is on, so
 *	just return the dividend unchanged.  If the divisor is 0,
 *	do the ediv also, so it will generate the proper exception.
 *	All other values of the divisor have bit 31 on: in this case
 *	the quotient must be 0 if divisor > dividend, and 1 otherwise,
 *	provided that the comparison is made as unsigned.
E 7
I 7
 * arguments: *dividend, divisor.
 * result: quotient in r0 and *dividend.
 * uses r0-r2
E 7
 */
E 4
D 7
	.text
	.align	1
	.globl	udiv
udiv:	.word	0x0000
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
	ediv	r2,r0,r0,r2	# Divide.  q->r0, r->r2 (discarded)
E 7
I 7

D 8
#include "DEFS.h"

ASENTRY(audiv, 0)
E 8
I 8
	.align	2
	.globl	audiv
audiv:	.word	0x0000
#ifdef GPROF
	jsb	mcount
#endif /*GPROF*/
E 8
	movl	*4(ap),r0	/* dividend */
	movl	8(ap),r2	/* divisor */
	jeql	1f		/* if divisor=0, force exception */
	cmpl	r2,$1		/* if divisor <= 1 (signed), */
	jleq	2f		/*  no division is necessary */
1:
	clrl	r1		/* zero-extend the dividend */
	ediv	r2,r0,r0,r2	/* divide.  q->r0, r->r2 (discarded) */
	movl	r0,*4(ap)	/* save result */
E 7
	ret
D 7
nodiv:	jeql	retn		# If divisor=1, return dividend
	cmpl	r0,r2		# Unsigned comparison between
	jgequ	one		#  dividend and divisor
	clrl	r0		# Dividend < divisor, return 0
E 7
I 7
2:
	jeql	1f		/* if divisor=1, return dividend */
	cmpl	r0,r2		/* unsigned comparison between */
	jgequ	2f		/*  dividend and divisor */
	clrl	r0		/* dividend < divisor, return 0 */
	clrl	*4(ap)		/* save result */
E 7
	ret
D 7
one:	movl	$1,r0		# Dividend >= divisor, return 1
retn:	ret
E 7
I 7
2:
	movl	$1,r0		/* dividend >= divisor, return 1 */
1:
	movl	r0,*4(ap)	/* save result */
	ret
E 7
D 4


E 4
E 1
