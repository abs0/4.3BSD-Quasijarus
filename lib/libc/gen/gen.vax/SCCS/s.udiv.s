h11438
s 00002/00002/00075
d D 5.2 86/03/09 21:15:37 donn 6 5
c added LIBC_SCCS condition for sccs ids
e
s 00003/00001/00074
d D 5.1 85/06/05 18:54:04 mckusick 5 4
c Add copyright
e
s 00034/00000/00041
d D 4.4 85/01/16 11:27:33 ralph 4 3
c added audiv() to handle /= properly.
e
s 00001/00001/00040
d D 4.3 84/11/01 23:52:33 sam 3 2
c change ENTRY & ASENTRY to allow setting the register save mask
e
s 00001/00001/00040
d D 4.2 83/06/27 19:52:30 root 2 1
c need assembler entry point
e
s 00041/00000/00000
d D 4.1 83/06/27 15:42:09 root 1 0
c date and time created 83/06/27 15:42:09 by root
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
D 6
#ifndef lint
E 6
I 6
#ifdef LIBC_SCCS
E 6
	.asciz	"%W% (Berkeley) %G%"
D 6
#endif not lint
E 6
I 6
#endif LIBC_SCCS
E 6
E 5

/*
 * udiv - unsigned division for vax-11
 *
 * arguments: dividend, divisor.
 * result: quotient.
 * uses r0-r2
 *
 * If 1 < divisor <= 2147483647, zero-extend the dividend
 * to 64 bits and let ediv do the work.  If the divisor is 1,
 * ediv will overflow if bit 31 of the dividend is on, so
 * just return the dividend unchanged.  If the divisor is 0,
 * do the ediv also, so it will generate the proper exception.
 * All other values of the divisor have bit 31 on: in this case
 * the quotient must be 0 if divisor > dividend, and 1 otherwise,
 * provided that the comparison is made as unsigned.
 */

#include "DEFS.h"

D 2
ENTRY(udiv)
E 2
I 2
D 3
ASENTRY(udiv)
E 3
I 3
ASENTRY(udiv, 0)
E 3
E 2
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
I 4

/*
 * audiv - unsigned division for vax-11
 *
 * arguments: *dividend, divisor.
 * result: quotient in r0 and *dividend.
 * uses r0-r2
 */

#include "DEFS.h"

ASENTRY(audiv, 0)
	movl	*4(ap),r0	/* dividend */
	movl	8(ap),r2	/* divisor */
	jeql	1f		/* if divisor=0, force exception */
	cmpl	r2,$1		/* if divisor <= 1 (signed), */
	jleq	2f		/*  no division is necessary */
1:
	clrl	r1		/* zero-extend the dividend */
	ediv	r2,r0,r0,r2	/* divide.  q->r0, r->r2 (discarded) */
	movl	r0,*4(ap)	/* save result */
	ret
2:
	jeql	1f		/* if divisor=1, return dividend */
	cmpl	r0,r2		/* unsigned comparison between */
	jgequ	2f		/*  dividend and divisor */
	clrl	r0		/* dividend < divisor, return 0 */
	clrl	*4(ap)		/* save result */
	ret
2:
	movl	$1,r0		/* dividend >= divisor, return 1 */
1:
	movl	r0,*4(ap)	/* save result */
	ret
E 4
E 1
