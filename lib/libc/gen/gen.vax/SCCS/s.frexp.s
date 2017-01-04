h22718
s 00013/00008/00020
d D 5.5 88/06/27 17:25:08 bostic 7 6
c install approved copyright notice
e
s 00011/00005/00017
d D 5.4 88/05/25 17:13:48 bostic 6 5
c written by Kirk McKusick and Sam Leffler; add Berkeley specific header
e
s 00002/00002/00020
d D 5.3 86/03/09 21:12:37 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00001/00001/00021
d D 5.2 85/06/05 18:58:38 mckusick 4 3
c Fix copyright
e
s 00009/00001/00013
d D 5.1 85/05/30 15:14:13 dist 3 2
c Add copyright
e
s 00001/00001/00013
d D 4.2 84/11/01 23:51:41 sam 2 1
c change ENTRY & ASENTRY to allow setting the register save mask
e
s 00014/00000/00000
d D 4.1 84/08/22 11:18:03 ralph 1 0
c date and time created 84/08/22 11:18:03 by ralph
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
/*
 * Copyright (c) 1980 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
E 6
 */

D 5
#ifndef lint
E 5
I 5
D 6
#ifdef LIBC_SCCS
E 5
D 4
static char sccsid[] = "%W% (Berkeley) %G%";
E 4
I 4
	.asciz	"%W% (Berkeley) %G%"
E 4
D 5
#endif not lint
E 5
I 5
#endif LIBC_SCCS
E 6
I 6
D 7
#if defined(SYSLIBC_SCCS) && !defined(lint)
_sccsid:.asciz	"%W% (Berkeley) %G%"
#endif /* SYSLIBC_SCCS and not lint */
E 7
I 7
#if defined(LIBC_SCCS) && !defined(lint)
	.asciz "%W% (Berkeley) %G%"
#endif /* LIBC_SCCS and not lint */
E 7
E 6
E 5
E 3

/* C library -- frexp(value, eptr) */

#include "DEFS.h"

D 2
ENTRY(frexp)
E 2
I 2
ENTRY(frexp, 0)
E 2
	movd	4(ap),r0		# (r0,r1) := value
	extzv	$7,$8,r0,*12(ap)	# Fetch exponent
	jeql	1f			# If exponent zero, we're done
	subl2	$128,*12(ap)		# Bias the exponent appropriately
	insv	$128,$7,$8,r0		# Force result exponent to biased 0
1:
	ret
E 1
