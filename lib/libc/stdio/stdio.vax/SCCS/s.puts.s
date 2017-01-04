h49277
s 00013/00008/00135
d D 5.6 88/06/27 17:51:59 bostic 6 5
c install approved copyright notice
e
s 00009/00003/00134
d D 5.5 88/05/23 20:26:19 bostic 5 4
c add Berkeley specific header
e
s 00002/00000/00135
d D 5.4 86/04/01 17:49:51 bloom 4 3
c unbuffered output lost end of buffer if over 1K
e
s 00002/00002/00133
d D 5.3 86/03/09 21:30:29 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00002/00002/00133
d D 5.2 86/01/30 22:07:21 donn 2 1
c Check the _cnt field of the _iob struct for initialization rather than the
c _base field -- this allows us to handle _iob structs that are set to _IORW
c and are switching from reading to writing, as well as new _iob structs.
e
s 00135/00000/00000
d D 5.1 85/08/23 18:57:32 mckusick 1 0
c date and time created 85/08/23 18:57:32 by mckusick
e
u
U
t
T
I 1
/*
 * Copyright (c) 1985 Regents of the University of California.
D 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
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
E 5
 */

D 3
#ifndef lint
E 3
I 3
D 6
#ifdef LIBC_SCCS
E 3
_sccsid:.asciz	"%W% (Berkeley) %G%"
D 3
#endif not lint
E 3
I 3
D 5
#endif LIBC_SCCS
E 5
I 5
#endif /* LIBC_SCCS */
E 6
I 6
#if defined(LIBC_SCCS) && !defined(lint)
	.asciz "%W% (Berkeley) %G%"
#endif /* LIBC_SCCS and not lint */
E 6
E 5
E 3

/*
 * puts(s);
 * char *s;
 *
 * argument: a source string.
 * side effects: writes to the standard output using the data in
 *	the null-terminated source string; a newline is appended.
 * result: technically void; for compatibility we return 0 for the null
 *	string, non-zero otherwise.  We return zero for errors too.
 */

#include "DEFS.h"

#define		NBF	04
#define		LBF	0200

#define		NL	012

ENTRY(puts, R11|R10|R9)

#define		S	r11
	movl	4(ap),S
#define		IOP	r10
#define		_CNT
#define		_PTR	4
#define		_BASE	8
#define		_BUFSIZ	12
#define		_FLAG	16
	movab	__iob+20,IOP

#define		UNBUF	-4(fp)

#define		COUNT	r9

	/*
	 * For unbuffered I/O, line buffer the output line.
	 * Ugly but fast -- and doesn't CURRENTLY break anything (sigh).
	 */
	movab	-1028(sp),sp
	bicw3	$~NBF,_FLAG(IOP),UNBUF
	jeql	1f

	bicw2	$NBF,_FLAG(IOP)		/* Clear no-buffering flag */
	movl	sp,_BASE(IOP)		/* Create a buffer */
	movl	sp,_PTR(IOP)
	cvtwl	$1024,_BUFSIZ(IOP)
	jbr	2f

1:
D 2
	tstl	_BASE(IOP)		/* Has a buffer been allocated? */
	jneq	2f
E 2
I 2
	tstl	_CNT(IOP)		/* Has a buffer been allocated? */
	jgtr	2f
E 2
	pushl	IOP			/* Get _flsbuf() to make one */
	pushl	$0
	calls	$2,__flsbuf
	tstl	r0
	jlss	Lerror
	incl	_CNT(IOP)		/* Unput the char we sent */
	decl	_PTR(IOP)
2:

	/*
	 * Search for the terminating null.
	 */
Lloop:
	addl3	_BASE(IOP),_BUFSIZ(IOP),COUNT	/* How many bytes? */
	subl2	_PTR(IOP),COUNT
	locc	$0,COUNT,(S)		/* Look for a null */
	jeql	Lagain

	subl2	r0,COUNT		/* Copy the data */
	movc3	COUNT,(S),*_PTR(IOP)
	movl	r3,_PTR(IOP)		/* Fix up IOP */
	subl2	COUNT,_CNT(IOP)

Lnl:
	movb	$NL,*_PTR(IOP)		/* Append a newline */
	incl	_PTR(IOP)
	decl	_CNT(IOP)

	bitw	$LBF,_FLAG(IOP)		/* If line buffered... */
	jneq	1f
I 4
	tstw	UNBUF			/* or unbuffered... */
	jneq	1f
E 4
	tstl	_CNT(IOP)		/* or a full buffer... */
	jgtr	2f
1:
	pushl	IOP			/* ... flush the buffer */
	calls	$1,_fflush
	tstl	r0
	jlss	Lerror
2:

	/*
	 * Fix up buffering again.
	 */
	tstw	UNBUF
	jeql	1f
	bisw2	$NBF,_FLAG(IOP)		/* Reset flag */
	clrl	_BASE(IOP)		/* Clear data structure */
	clrl	_BUFSIZ(IOP)
	clrl	_CNT(IOP)
1:
	cvtbl	$NL,r0			/* Compatibility hack */
	ret

	/*
	 * We didn't find the null -- loop.
	 */
Lagain:
	movc3	COUNT,(S),*_PTR(IOP)	/* Copy the data */
	movl	r1,S
	movl	r3,_PTR(IOP)		/* Fix up IOP */
	subl2	COUNT,_CNT(IOP)
	pushl	IOP			/* The buffer is full -- flush it */
	calls	$1,_fflush
	tstl	r0
	jlss	Lerror
	tstb	(S)			/* More data? */
	jneq	Lloop
	jbr	Lnl

	/*
	 * Bomb out.  Return 0 (why not? that's what the old one did).
	 */
Lerror:
	clrl	r0
	ret
E 1
