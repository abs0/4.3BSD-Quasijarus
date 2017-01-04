h35264
s 00001/00035/00018
d D 1.3 86/02/24 22:27:13 sam 3 2
c update from monet: check number of arguments in pattern calls
e
s 00006/00006/00047
d D 1.2 86/01/05 18:49:59 sam 2 1
c 1st working version (mostly)
e
s 00053/00000/00000
d D 1.1 85/07/25 17:44:08 sam 1 0
c date and time created 85/07/25 17:44:08 by sam
e
u
U
t
T
I 1
/*
 * Copyright (c) 1984 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 2
static char sccsid[] = "@(#)libcpats.c	1.3 (Berkeley) 6/8/85";
#endif not lint
E 2
I 2
static char sccsid[] = "%W% (Berkeley) %G%";
#endif
E 2

#include "inline.h"

/*
 * Pattern table for the C library.
 */
struct pats libc_ptab[] = {

D 2
#ifdef vax
E 2
I 2
D 3
#if defined(vax)
E 2
	{ "1,_fgetc\n",
"	sobgeq	*(sp),1f\n\
	calls	$1,__filbuf\n\
	jbr     2f\n\
1:\n\
	addl3	$4,(sp)+,r1\n\
	movzbl	*(r1),r0\n\
	incl	(r1)\n\
2:\n" },

	{ "2,_fputc\n",
"	sobgeq	*4(sp),1f\n\
	calls	$2,__flsbuf\n\
	jbr	2f\n\
1:\n\
	movq	(sp)+,r0\n\
	movb	r0,*4(r1)\n\
	incl	4(r1)\n\
2:\n" },

	{ "1,_strlen\n",
"	movl	(sp)+,r5\n\
	movl	r5,r1\n\
1:\n\
	locc	$0,$65535,(r1)\n\
	jeql	1b\n\
	subl3	r5,r1,r0\n" },
D 2
#endif vax
E 2
I 2
#endif
E 2

D 2
#ifdef mc68000
E 2
I 2
#if defined(mc68000)
E 2
/* someday... */
D 2
#endif mc68000
E 2
I 2
#endif
E 2

	{ "", "" }
E 3
I 3
	{ 0, "", "" }
E 3
};
E 1
