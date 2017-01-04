h00629
s 00013/00008/00125
d D 5.5 88/06/27 17:51:54 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00124
d D 5.4 88/05/23 20:26:12 bostic 4 3
c add Berkeley specific header
e
s 00002/00002/00125
d D 5.3 86/03/09 21:29:54 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00006/00002/00121
d D 5.2 85/10/30 15:43:21 mckusick 2 1
c check for overrun count (from donn@utah-cs)
e
s 00123/00000/00000
d D 5.1 85/08/23 18:57:22 mckusick 1 0
c date and time created 85/08/23 18:57:22 by mckusick
e
u
U
t
T
I 1
/*
 * Copyright (c) 1985 Regents of the University of California.
D 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
I 4
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
I 5
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
E 5
E 4
 */

D 3
#ifndef lint
E 3
I 3
D 5
#ifdef LIBC_SCCS
E 3
_sccsid:.asciz	"%W% (Berkeley) %G%"
D 3
#endif not lint
E 3
I 3
D 4
#endif LIBC_SCCS
E 4
I 4
#endif /* LIBC_SCCS */
E 5
I 5
#if defined(LIBC_SCCS) && !defined(lint)
	.asciz "%W% (Berkeley) %G%"
#endif /* LIBC_SCCS and not lint */
E 5
E 4
E 3

/*
 * char *fgets(s, n, iptr);
 * char *s;
 * int n;
 * FILE *iptr;
 *
 * arguments: a target string, a length, and a file pointer.
 * side effects: reads up to and including a newline, or up to n-1 bytes,
 *	whichever is less, from the file indicated by iptr into the target
 *	string and null terminates.
 * result: the target string if successful, 0 otherwise.
 */

#include "DEFS.h"

#define		NL	0xa

ENTRY(fgets, R11|R10|R9)

#define		OLD_S	4(ap)
#define		S	r11
	movl	OLD_S,S

#define		N	8(ap)

#define		IPTR	r10
#define		_CNT
#define		_PTR	4
#define		_BASE	8
	movl	12(ap),IPTR

#define		COUNT	r9

	/*
	 * Sanity check -- is the buffer big enough?
	 */
	cmpl	N,$1
	jleq	Lerror

	subl3	$1,N,COUNT		/* We scan at most COUNT chars */

	/*
	 * If no characters, call _filbuf() to get some.
	 */
	tstl	_CNT(IPTR)
	jgtr	Lscan

Lloop:
	pushl	IPTR
	calls	$1,__filbuf
	tstl	r0
	jlss	Leof
	movb	r0,(S)+			/* Save the returned character */
I 2
	decl	N
	decl	COUNT
	jleq	1f
E 2
	cmpb	r0,$NL			/* If it was a newline, we're done */
D 2
	jneq	1f
E 2
I 2
	jneq	2f
1:
E 2
	clrb	(S)
	jbr	Lret
D 2
1:
E 2
I 2
2:
E 2
	tstl	_BASE(IPTR)		/* Is the input buffered? */
	jeql	Lloop			/* If not, loop inefficiently */

	/*
	 * Look for a newline in the buffer.
	 */
Lscan:
	cmpl	_CNT(IPTR),COUNT	/* Is buffer bigger than N-1? */
	jgeq	1f
	movl	_CNT(IPTR),COUNT	/* If not, don't read off the end */
1:
	locc	$NL,COUNT,*_PTR(IPTR)	/* Scan the buffer */
	jeql	Lagain

	/*
	 * Success -- copy the data and return.
	 */
	decl	r0			/* How many characters did we read? */
	subl2	r0,COUNT
	movc3	COUNT,*_PTR(IPTR),(S)	/* Copy the data */
	clrb	(r3)
	subl2	COUNT,_CNT(IPTR)	/* Fix up the I/O buffer */
	movl	r1,_PTR(IPTR)

Lret:
	movl	OLD_S,r0
	ret

	/*
	 * If we run out of characters, copy the buffer and loop if needed.
	 */
Lagain:
	movc3	COUNT,*_PTR(IPTR),(S)	/* Copy the data */
	subl2	COUNT,_CNT(IPTR)	/* Adjust the buffers and counts */
	movl	r1,_PTR(IPTR)
	subl2	COUNT,N
	movl	r3,S
	subl3	$1,N,COUNT
	jgtr	Lloop

	/*
	 * End of file?  Check to see if we copied any data.
	 */
Leof:
	cmpl	S,OLD_S
	jeql	Lerror
	clrb	(S)
	jbr	Lret

	/*
	 * Error return -- null pointer.
	 */
Lerror:
	clrl	r0
	ret
E 1
