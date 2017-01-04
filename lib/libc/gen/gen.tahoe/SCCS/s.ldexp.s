h35519
s 00013/00008/00074
d D 1.3 88/06/27 17:47:02 bostic 3 2
c install approved copyright notice
e
s 00018/00003/00064
d D 1.2 88/05/23 21:33:31 bostic 2 1
c add Berkeley/CCI specific header; fix sccsid
e
s 00067/00000/00000
d D 1.1 86/08/01 08:49:35 sam 1 0
c date and time created 86/08/01 08:49:35 by sam
e
u
U
t
T
I 1
D 2
#ifdef LIBC_SCCS
	.asciz	"%W% (Berkeley/CCI) %G%"
#endif LIBC_SCCS
E 2
I 2
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
I 3
 * Redistribution and use in source and binary forms are permitted
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
 *
E 3
 * This code is derived from software contributed to Berkeley by
 * Computer Consoles Inc.
D 3
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 3
 */

#if defined(LIBC_SCCS) && !defined(lint)
D 3
_sccsid:.asciz	"%W% (Berkeley) %G%"
E 3
I 3
	.asciz "%W% (Berkeley) %G%"
E 3
#endif /* LIBC_SCCS and not lint */
E 2

/*
 * double ldexp (value, exp)
 *	double value;
 *	int exp;
 *
 * Ldexp returns value*2**exp, if that result is in range.
 * If underflow occurs, it returns zero.  If overflow occurs,
 * it returns a value of appropriate sign and largest
 * possible magnitude.  In case of either overflow or underflow,
 * the external int "errno" is set to ERANGE.  Note that errno is
 * not modified if no error occurs, so if you intend to test it
 * after you use ldexp, you had better set it to something
 * other than ERANGE first (zero is a reasonable value to use).
 *
 * Constants
 */
#include <errno.h>
#include <tahoemath/fp.h>

#include "DEFS.h"

ENTRY(ldexp, 0)
	movl	4(fp),r0	/* Fetch "value" */
	movl	8(fp),r1	

	andl3	$EXPMASK,r0,r2	/* r2 := shifted biased exponent */
	jeql	ld1		/* If it's zero, we're done */
	shar	$EXPSHIFT,r2,r2	/* shift to get value of exponent  */

	addl2	12(fp),r2	/* r2 := new biased exponent */
	jleq	under		/* if it's <= 0, we have an underflow */
	cmpl	r2,$256		/* Otherwise check if it's too big */
	jgeq	over		/* jump if overflow */
/*
*	Construct the result and return
*/
	andl2	$0!EXPMASK,r0	/* clear old exponent */
	shal 	$EXPSHIFT,r2,r2	/* Put the exponent back in the result */
	orl2	r2,r0
ld1:	ret
/*
*	Underflow
*/
under:	clrl	r0		/* Result is zero */
	clrl	r1
	jbr	err		/* Join general error code */
/*
*	Overflow
*/
over:	movl	huge0,r0	/* Largest possible floating magnitude */
	movl	huge1,r1
	jbc	$31,4(fp),err	/* Jump if argument was positive */
	orl2	$SIGNBIT,r0	/* If arg < 0, make result negative */

err:	movl	$ERANGE,_errno	/* Indicate range error */
	ret

	.data
	.globl	_errno		/* error flag */
huge0:	.word	0x7fff		/* The largest number that can */
	.word	0xffff		/*   be represented in a long floating */
huge1:	.word	0xffff		/*   number.  */
	.word	0xffff		
E 1
