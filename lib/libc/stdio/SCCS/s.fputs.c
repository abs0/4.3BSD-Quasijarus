h43574
s 00002/00002/00039
d D 5.2 86/03/09 20:50:56 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00010/00001/00031
d D 5.1 85/06/05 13:34:46 mckusick 4 3
c Add copyright
e
s 00018/00000/00014
d D 4.3 85/02/13 15:48:40 serge 3 2
c autoconfigure FILE array using getdtablesize() 
c changed all struct _iobuf to FILE 
c many miscellaneous changes
e
s 00001/00001/00013
d D 4.2 84/09/20 06:01:24 lepreau 2 1
c fix return value on null string
e
s 00014/00000/00000
d D 4.1 80/12/21 16:50:22 wnj 1 0
c date and time created 80/12/21 16:50:22 by wnj
e
u
U
t
T
I 1
D 4
/* %W% (Berkeley) %G% */
E 4
I 4
/*
 * Copyright (c) 1984 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

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
#endif LIBC_SCCS and not lint
E 5

E 4
#include	<stdio.h>

fputs(s, iop)
register char *s;
register FILE *iop;
{
D 2
	register r;
E 2
I 2
	register r = 0;
E 2
	register c;
I 3
	int unbuffered;
	char localbuf[BUFSIZ];
E 3

I 3
	unbuffered = iop->_flag & _IONBF;
	if (unbuffered) {
		iop->_flag &= ~_IONBF;
		iop->_ptr = iop->_base = localbuf;
		iop->_bufsiz = BUFSIZ;
	}

E 3
	while (c = *s++)
		r = putc(c, iop);
I 3

	if (unbuffered) {
		fflush(iop);
		iop->_flag |= _IONBF;
		iop->_base = NULL;
		iop->_bufsiz = NULL;
		iop->_cnt = 0;
	}

E 3
	return(r);
}
E 1
