h16139
s 00013/00008/00044
d D 1.4 88/06/27 17:47:13 bostic 4 3
c install approved copyright notice
e
s 00018/00003/00034
d D 1.3 88/05/23 21:33:48 bostic 3 2
c add Berkeley/CCI specific header; fix sccsid
e
s 00000/00001/00037
d D 1.2 87/08/25 09:27:51 mckusick 2 1
c return s1 if zero or negative length
e
s 00038/00000/00000
d D 1.1 86/08/01 08:49:39 sam 1 0
c date and time created 86/08/01 08:49:39 by sam
e
u
U
t
T
I 1
D 3
#ifdef LIBC_SCCS
	.asciz	"%W% (Berkeley/CCI) %G%"
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
 * Concatenate s2 on the end of s1.  S1's space must be large enough.
 * At most n characters are moved.
 * Return s1.
 * 
 * char *strncat(s1, s2, n)
 * register char *s1, *s2;
 * register n;
 */
#include "DEFS.h"

ENTRY(strncat, 0)
	tstl	12(fp)
	jgtr	n_ok
	movl	4(fp),r0
D 2
	clrb	r0
E 2
	ret
n_ok:
	movl	8(fp),r0
	movl	r0,r1
	cmps2			# r0 points at null at end of s2
	subl3	8(fp),r0,r2	# r2 = numberof non-null chars in s2
	cmpl	12(fp),r2
	jgeq	r2_ok
	movl	12(fp),r2	# r2 = min (n, length(s2))
r2_ok:
	movl	4(fp),r0
	movl	r0,r1
	cmps2			# r1 points at null at end of s1
	movl	8(fp),r0	# source for copy
	movs3			# actual copy
	clrb	(r1)		# null terminated string !
	movl	4(fp),r0
	ret
E 1
