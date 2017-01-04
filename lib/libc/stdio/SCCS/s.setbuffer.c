h43825
s 00002/00002/00045
d D 5.2 86/03/09 20:53:51 donn 7 6
c added LIBC_SCCS condition for sccs ids
e
s 00010/00001/00037
d D 5.1 85/05/30 14:30:21 dist 6 5
c Add copyright
e
s 00002/00002/00036
d D 4.5 85/02/13 15:49:19 serge 5 4
c autoconfigure FILE array using getdtablesize() 
c changed all struct _iobuf to FILE 
c many miscellaneous changes
e
s 00007/00002/00031
d D 4.4 84/05/22 10:44:17 karels 4 3
c be careful of malloc return; free old buffer before allocating new
c in setlinebuf
e
s 00003/00007/00030
d D 4.3 84/05/15 16:54:50 ralph 3 2
c use malloc instead of static 8K sibuf and sobuf.
e
s 00017/00000/00020
d D 4.2 83/02/27 12:01:01 mckusick 2 1
c add "setlinebuf" to request line buffering of stdout or stderr
e
s 00020/00000/00000
d D 4.1 82/10/05 22:47:01 mckusick 1 0
c date and time created 82/10/05 22:47:01 by mckusick
e
u
U
t
T
I 1
D 6
/* %W% (Berkeley) %G% */
E 6
I 6
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 7
#ifndef lint
E 7
I 7
#if defined(LIBC_SCCS) && !defined(lint)
E 7
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif not lint
E 7
I 7
#endif LIBC_SCCS and not lint
E 7

E 6
#include	<stdio.h>

setbuffer(iop, buf, size)
D 5
	register struct _iobuf *iop;
E 5
I 5
	register FILE *iop;
E 5
	char *buf;
	int size;
{
	if (iop->_base != NULL && iop->_flag&_IOMYBUF)
		free(iop->_base);
	iop->_flag &= ~(_IOMYBUF|_IONBF|_IOLBF);
	if ((iop->_base = buf) == NULL) {
		iop->_flag |= _IONBF;
		iop->_bufsiz = NULL;
	} else {
		iop->_ptr = iop->_base;
		iop->_bufsiz = size;
	}
	iop->_cnt = 0;
}
I 2

/*
 * set line buffering for either stdout or stderr
 */
setlinebuf(iop)
D 5
	register struct _iobuf *iop;
E 5
I 5
	register FILE *iop;
E 5
{
I 4
	char *buf;
E 4
D 3
	static char _sebuf[BUFSIZ];
	extern char _sobuf[];
E 3
I 3
	extern char *malloc();
E 3

D 3
	if (iop != stdout && iop != stderr)
		return;
E 3
	fflush(iop);
D 3
	setbuffer(iop, NULL, 0);
	setbuffer(iop, iop == stderr ? _sebuf : _sobuf, BUFSIZ);
	iop->_flag |= _IOLBF;
E 3
I 3
D 4
	setbuffer(iop, malloc(BUFSIZ), BUFSIZ);
	iop->_flag |= _IOLBF|_IOMYBUF;
E 4
I 4
	setbuffer(iop, NULL, 0);
	buf = malloc(BUFSIZ);
	if (buf != NULL) {
		setbuffer(iop, buf, BUFSIZ);
		iop->_flag |= _IOLBF|_IOMYBUF;
	}
E 4
E 3
}
E 2
E 1
