h20969
s 00002/00002/00073
d D 5.2 86/03/09 21:15:48 donn 6 5
c added LIBC_SCCS condition for sccs ids
e
s 00003/00001/00072
d D 5.1 85/06/05 18:54:28 mckusick 5 4
c Add copyright
e
s 00033/00000/00040
d D 4.4 85/01/16 11:27:03 ralph 4 3
c added aurem() to handle %= properly.
e
s 00001/00001/00039
d D 4.3 84/11/01 23:52:36 sam 3 2
c change ENTRY & ASENTRY to allow setting the register save mask
e
s 00001/00001/00039
d D 4.2 83/06/27 19:52:34 root 2 1
c need assembler entry point
e
s 00040/00000/00000
d D 4.1 83/06/27 15:42:11 root 1 0
c date and time created 83/06/27 15:42:11 by root
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
 * urem - unsigned remainder for vax-11
 *
 * arguments: dividend, divisor
 * result: remainder
 * uses r0-r2
 *
 * if 1 < divisor <= 2147483647, zero-extend the dividend
 * to 64 bits and let ediv do the work.  If the divisor is 1,
 * ediv will overflow if bit 31 of the dividend is on, so
 * just return 0.  If the divisor is 0, do the ediv also,
 * so it will generate the proper exception.  All other values
 * of the divisor have bit 31 on: in this case the remainder
 * must be the dividend if divisor > dividend, and the dividend
 * minus the divisor otherwise.  The comparison must be unsigned.
 */
#include "DEFS.h"

D 2
ENTRY(urem)
E 2
I 2
D 3
ASENTRY(urem)
E 3
I 3
ASENTRY(urem, 0)
E 3
E 2
	movl	4(ap),r0	/* dividend */
	movl	8(ap),r2	/* divisor */
	jeql	1f		/* if divisor=0, force exception */
	cmpl	r2,$1		/* if divisor <= 1 (signed), */
	jleq	2f		/*  no division is necessary */
1:
	clrl	r1		/* zero-extend the dividend */
	ediv	r2,r0,r2,r0	/* divide.  q->r2 (discarded), r->r0 */
	ret
2:
	jneq	1f		/* if divisor=1, return 0 */
	clrl	r0		/*  (because doing the divide will overflow */
	ret			/*  if the dividend has its high bit on) */
1:
	cmpl	r0,r2		/* if dividend < divisor (unsigned) */
	jlssu	1f		/*  remainder is dividend */
	subl2	r2,r0		/*  else remainder is dividend - divisor */
1:
	ret
I 4

/*
 * aurem - unsigned remainder for vax-11
 *
 * arguments: *dividend, divisor
 * result: remainder in r0 and *dividend
 * uses r0-r2
 */
#include "DEFS.h"

ASENTRY(aurem, 0)
	movl	*4(ap),r0	/* dividend */
	movl	8(ap),r2	/* divisor */
	jeql	1f		/* if divisor=0, force exception */
	cmpl	r2,$1		/* if divisor <= 1 (signed), */
	jleq	2f		/*  no division is necessary */
1:
	clrl	r1		/* zero-extend the dividend */
	ediv	r2,r0,r2,r0	/* divide.  q->r2 (discarded), r->r0 */
	movl	r0,*4(ap)	/* save result */
	ret
2:
	jneq	1f		/* if divisor=1, return 0 */
	clrl	r0		/*  (because doing the divide will overflow */
	clrl	*4(ap)		/*  if the dividend has its high bit on) */
	ret	
1:
	cmpl	r0,r2		/* if dividend < divisor (unsigned) */
	jlssu	1f		/*  remainder is dividend */
	subl2	r2,r0		/*  else remainder is dividend - divisor */
1:
	movl	r0,*4(ap)	/* save result */
	ret
E 4
E 1
