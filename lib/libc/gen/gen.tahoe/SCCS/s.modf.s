h24404
s 00013/00008/00059
d D 1.4 88/06/27 17:47:03 bostic 4 3
c install approved copyright notice
e
s 00018/00003/00049
d D 1.3 88/05/23 21:33:33 bostic 3 2
c add Berkeley/CCI specific header; fix sccsid
e
s 00028/00024/00024
d D 1.2 87/02/16 22:27:40 sam 2 1
c from pixar!ph; handle overflow correctly (previous version just  punted 
c causing lots of things to go crazy; e.g. printf)
e
s 00048/00000/00000
d D 1.1 86/08/01 08:49:35 sam 1 0
c date and time created 86/08/01 08:49:35 by sam
e
u
U
t
T
I 1
D 3
#ifdef LIBC_SCCS
	.asciz	"%W% (Berkeley) %G%"
#endif LIBC_SCCS
E 3
I 3
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
I 4
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
E 4
 * This code is derived from software contributed to Berkeley by
 * Computer Consoles Inc.
D 4
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
 */

#if defined(LIBC_SCCS) && !defined(lint)
D 4
_sccsid:.asciz	"%W% (Berkeley) %G%"
E 4
I 4
	.asciz "%W% (Berkeley) %G%"
E 4
#endif /* LIBC_SCCS and not lint */
E 3

/*
 * double modf (value, iptr)
 * double value, *iptr;
 *
 * Modf returns the fractional part of "value",
 * and stores the integer part indirectly through "iptr".
 *
 * This version uses floating point (look in ../fpe for
 * a much slower integer version).
 */

#include "DEFS.h"

ENTRY(modf, 0)
D 2
	movl	12(fp),r3
E 2
I 2
	ldd	4(fp)		# value
	cvdl	r2		# integerize
	bvs	1f		# did integer part overflow?
	cvld	r2		# integer part
	std	r0
	std	*12(fp)		# *iptr = r2
E 2
	ldd	4(fp)
D 2
	tstd		# if (value < 0)
	jgeq	1f
	negd
	cvdl	r2	# ul = -value
	bvs	2f
	mnegl	r2,r0
	cvld	r0
	std	(r3)	# *iptr = -ul
	cvld	r2
	addd	4(fp)
	std	r0	# return (value + ul)
E 2
I 2
	subd	r0		# value-(int)value
	std	r0		# return fraction
E 2
	ret
1:
D 2
	cvdl	r2	# ul = value
	bvs	2f
	cvld	r2
	std	(r3)	# *iptr = ul
	std	r0
E 2
I 2
	/*
	 * If the integer portion overflowed, mask out the fractional
	 * bits in the double word instead of cvdl-ing.
	 */
E 2
	ldd	4(fp)
I 2
	std	r0		# (r0,r1) = value
	shrl	$23,r0,r2	# extract sign,exponent of value
	andl2	$255,r2		# exponent
	subl2	$152,r2		# e-152
	/*
	 * If it overflowed then value>=2^31 and e>=160
	 * so we mask only r1 (low bits of fraction), not r0
	 */
	mnegl	$1,r3
	shrl	r2,r3,r3	# -1>>(e-152) is neg mask to clear fraction
	mcoml	r3,r3		# complement mask
	andl2	r3,r1		# mask off truly fractional bits from fraction
	ldd	r0		# now (r0,r1) = integerized value
	std	*12(fp)		# *iptr = integerized
	ldd	4(fp)
E 2
	subd	r0
D 2
	std	r0
	ret
2:			# integer overflow
	movl	4(fp),(r3)
	movl	8(fp),4(r3)
	clrl	r0
	clrl	r1
E 2
I 2
	std	r0		# return fraction
E 2
	ret
E 1
