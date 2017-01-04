h18113
s 00002/00002/00060
d D 5.2 86/03/09 20:48:53 donn 9 8
c added LIBC_SCCS condition for sccs ids
e
s 00010/00001/00052
d D 5.1 85/05/30 14:26:53 dist 8 7
c Add copyright
e
s 00035/00019/00018
d D 4.5 85/02/13 15:56:11 serge 7 5
c autoconfigure FILE array using getdtablesize() 
c changed all struct _iobuf to FILE 
c many miscellaneous changes
e
s 00035/00019/00018
d R 4.5 85/02/13 15:48:26 serge 6 5
c autoconfigure FILE array using getdtablesize() 
c changed all struct _iobuf to FILE 
c many miscellaneous changes
e
s 00002/00002/00035
d D 4.4 83/09/12 16:23:52 karels 5 4
c don't allow file pointer to fall off file table
e
s 00002/00000/00035
d D 4.3 83/06/30 15:39:00 sam 4 2
c bounds check
e
s 00006/00003/00032
d R 4.3 83/05/26 14:33:16 ralph 3 2
c fixed case where loop exits with iop == _lastbuf.
e
s 00005/00001/00030
d D 4.2 81/03/09 20:59:07 toy 2 1
c Feldman's stdio changes
e
s 00031/00000/00000
d D 4.1 80/12/21 16:50:07 wnj 1 0
c date and time created 80/12/21 16:50:07 by wnj
e
u
U
t
T
I 1
D 8
/* %W% (Berkeley) %G% */
E 8
I 8
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 9
#ifndef lint
E 9
I 9
#if defined(LIBC_SCCS) && !defined(lint)
E 9
static char sccsid[] = "%W% (Berkeley) %G%";
D 9
#endif not lint
E 9
I 9
#endif LIBC_SCCS and not lint
E 9

E 8
/*
 * Unix routine to do an "fopen" on file descriptor
 * The mode has to be repeated because you can't query its
 * status
 */

D 7
#include	<stdio.h>
#include	<errno.h>
E 7
I 7
#include <sys/types.h>
#include <sys/file.h>
#include <stdio.h>
E 7

FILE *
fdopen(fd, mode)
D 7
register char *mode;
E 7
I 7
	register char *mode;
E 7
{
D 7
	extern int errno;
E 7
I 7
	extern FILE *_findiop();
	static int nofile = -1;
E 7
	register FILE *iop;
D 7
	extern FILE *_lastbuf;
E 7

I 4
D 7
	if ((unsigned)fd >= getdtablesize())
E 7
I 7
	if (nofile < 0)
		nofile = getdtablesize();

	if (fd < 0 || fd >= nofile)
E 7
		return (NULL);
E 4
D 2
	for (iop = _iob; iop->_flag&(_IOREAD|_IOWRT); iop++)
E 2
I 2
D 5
	for (iop = _iob; iop->_flag&(_IOREAD|_IOWRT|_IORW); iop++)
E 2
		if (iop >= _lastbuf)
E 5
I 5
D 7
	for (iop = _iob; iop->_flag&(_IOREAD|_IOWRT|_IORW); )
		if (++iop >= _lastbuf)
E 5
			return(NULL);
E 7
I 7

	iop = _findiop();
	if (iop == NULL)
		return (NULL);

E 7
	iop->_cnt = 0;
	iop->_file = fd;
D 7
	if (*mode != 'r') {
		iop->_flag |= _IOWRT;
		if (*mode == 'a')
			lseek(fd, 0L, 2);
	} else
		iop->_flag |= _IOREAD;
I 2
	if (mode[1] == '+') {
		iop->_flag &= ~(_IOREAD|_IOWRT);
		iop->_flag |= _IORW;
E 7
I 7
	iop->_bufsiz = 0;
	iop->_base = iop->_ptr = NULL;

	switch (*mode) {
	case 'r':
		iop->_flag = _IOREAD;
		break;
	case 'a':
		lseek(fd, (off_t)0, L_XTND);
		/* fall into ... */
	case 'w':
		iop->_flag = _IOWRT;
		break;
	default:
		return (NULL);
E 7
	}
E 2
D 7
	return(iop);
E 7
I 7

	if (mode[1] == '+')
		iop->_flag = _IORW;

	return (iop);
E 7
}
E 1
