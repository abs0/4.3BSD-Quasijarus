h42280
s 00019/00002/00024
d D 5.4 88/06/27 17:37:49 bostic 6 5
c written by Jeffrey Mogul, Stanford; add Berkeley specific header
e
s 00002/00002/00024
d D 5.3 86/03/09 19:59:03 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00003/00001/00023
d D 5.2 85/06/05 12:39:19 mckusick 4 3
c Add copyright
e
s 00000/00000/00024
d D 5.1 85/05/30 10:51:29 dist 3 2
c Add copyright
e
s 00017/00010/00007
d D 4.2 83/06/27 21:11:37 sam 2 1
c version from mogul with loop unrolled for speed
e
s 00017/00000/00000
d D 4.1 80/12/21 16:40:22 wnj 1 0
c date and time created 80/12/21 16:40:22 by wnj
e
u
U
t
T
I 6
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
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
 */

E 6
I 1
D 2
/* %W% (Berkeley) %G% */
E 2
I 2
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
D 5
#ifndef lint
E 5
I 5
#if defined(LIBC_SCCS) && !defined(lint)
E 5
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif not lint
E 5
I 5
D 6
#endif LIBC_SCCS and not lint
E 6
I 6
#endif /* LIBC_SCCS and not lint */
E 6
E 5
E 4

E 2
/*
D 2
 * Swap bytes in 16-bit [half-]words
 * for going between the 11 and the interdata
E 2
I 2
 * Swab bytes
 * Jeffrey Mogul, Stanford
E 2
 */

D 2
swab(pf, pt, n)
register short *pf, *pt;
register n;
E 2
I 2
swab(from, to, n)
	register char *from, *to;
	register int n;
E 2
{
D 2

	n /= 2;
E 2
I 2
	register unsigned long temp;
D 6
	
E 6
I 6

E 6
	n >>= 1; n++;
#define	STEP	temp = *from++,*to++ = *from++,*to++ = temp
	/* round to multiple of 8 */
	while ((--n) & 07)
		STEP;
	n >>= 3;
E 2
	while (--n >= 0) {
D 2
		*pt++ = (*pf << 8) + ((*pf >> 8) & 0377);
		pf++;
E 2
I 2
		STEP; STEP; STEP; STEP;
		STEP; STEP; STEP; STEP;
E 2
	}
}
E 1
