h02797
s 00013/00008/00026
d D 5.4 88/06/27 17:25:13 bostic 6 5
c install approved copyright notice
e
s 00015/00003/00019
d D 5.3 88/05/25 17:13:52 bostic 5 4
c written by Kirk McKusick and Sam Leffler; add Berkeley specific header
e
s 00002/00002/00020
d D 5.2 86/03/09 21:13:19 donn 4 3
c added LIBC_SCCS condition for sccs ids
e
s 00003/00001/00019
d D 5.1 85/06/05 18:53:40 mckusick 3 2
c Add copyright
e
s 00001/00001/00019
d D 4.2 84/11/01 23:51:52 sam 2 1
c change ENTRY & ASENTRY to allow setting the register save mask
e
s 00020/00000/00000
d D 4.1 83/06/27 15:42:02 root 1 0
c date and time created 83/06/27 15:42:02 by root
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
D 4
#ifndef lint
E 4
I 4
D 5
#ifdef LIBC_SCCS
E 4
	.asciz	"%W% (Berkeley) %G%"
D 4
#endif not lint
E 4
I 4
#endif LIBC_SCCS
E 5
I 5
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
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
E 6
 */

D 6
#if defined(SYSLIBC_SCCS) && !defined(lint)
_sccsid:.asciz	"%W% (Berkeley) %G%"
#endif /* SYSLIBC_SCCS and not lint */
E 6
I 6
#if defined(LIBC_SCCS) && !defined(lint)
	.asciz "%W% (Berkeley) %G%"
#endif /* LIBC_SCCS and not lint */
E 6
E 5
E 4
E 3

/*
 * double modf (value, iptr)
 * double value, *iptr;
 *
 * Modf returns the fractional part of "value",
 * and stores the integer part indirectly through "iptr".
 */

#include "DEFS.h"

D 2
ENTRY(modf)
E 2
I 2
ENTRY(modf, 0)
E 2
	emodd	4(ap),$0,$0f1.0,r2,r0
	jvs	1f			# integer overflow
	cvtld	r2,*12(ap)
	ret
1:
	subd3	r0,4(ap),*12(ap)
	ret
E 1
