h32773
s 00002/00002/00060
d D 5.2 86/03/09 20:50:13 donn 7 6
c added LIBC_SCCS condition for sccs ids
e
s 00010/00001/00052
d D 5.1 85/05/30 14:28:15 dist 6 5
c Add copyright
e
s 00038/00037/00015
d D 4.4 85/02/13 15:48:32 serge 5 4
c autoconfigure FILE array using getdtablesize() 
c changed all struct _iobuf to FILE 
c many miscellaneous changes
e
s 00002/00002/00050
d D 4.3 83/09/12 16:23:47 karels 4 2
c don't allow file pointer to fall off file table
e
s 00005/00003/00049
d R 4.3 83/05/26 14:33:12 ralph 3 2
c fixed case where loop exits with iop == _lastbuf.
e
s 00022/00008/00030
d D 4.2 81/03/09 20:59:16 toy 2 1
c Feldman's stdio changes
e
s 00038/00000/00000
d D 4.1 80/12/21 16:50:18 wnj 1 0
c date and time created 80/12/21 16:50:18 by wnj
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
 * Copyright (c) 1980 Regents of the University of California.
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
D 5
#include	<stdio.h>
#include	<errno.h>
E 5
I 5
#include <sys/types.h>
#include <sys/file.h>
#include <stdio.h>
E 5

FILE *
fopen(file, mode)
D 5
char *file;
register char *mode;
E 5
I 5
	char *file;
	register char *mode;
E 5
{
D 5
	extern int errno;
D 2
	register f;
E 2
I 2
	register f, rw;
E 5
E 2
	register FILE *iop;
D 5
	extern FILE *_lastbuf;
E 5
I 5
	register f, rw, oflags;
	extern FILE *_findiop();
E 5

D 2
	for (iop = _iob; iop->_flag&(_IOREAD|_IOWRT); iop++)
E 2
I 2
D 4
	for (iop = _iob; iop->_flag&(_IOREAD|_IOWRT|_IORW); iop++)
E 2
		if (iop >= _lastbuf)
E 4
I 4
D 5
	for (iop = _iob; iop->_flag&(_IOREAD|_IOWRT|_IORW); )
		if (++iop >= _lastbuf)
E 4
			return(NULL);
E 5
I 5
	iop = _findiop();
	if (iop == NULL)
		return (NULL);
E 5
D 2
	if (*mode=='w')
E 2
I 2

D 5
	rw = mode[1] == '+';
E 5
I 5
	rw = (mode[1] == '+');
E 5

D 5
	if (*mode=='w') {
E 2
		f = creat(file, 0666);
D 2
	else if (*mode=='a') {
		if ((f = open(file, 1)) < 0) {
			if (errno == ENOENT)
E 2
I 2
		if (rw && f>=0) {
			close(f);
			f = open(file, 2);
		}
	} else if (*mode=='a') {
		if ((f = open(file, rw? 2: 1)) < 0) {
			if (errno == ENOENT) {
E 2
				f = creat(file, 0666);
I 2
				if (rw && f>=0) {
					close(f);
					f = open(file, 2);
				}
			}
E 2
		}
		if (f >= 0)
			lseek(f, 0L, 2);
	} else
D 2
		f = open(file, 0);
E 2
I 2
		f = open(file, rw? 2: 0);
E 5
I 5
	switch (*mode) {
	case 'a':
		oflags = O_CREAT | (rw ? O_RDWR : O_WRONLY);
		break;
	case 'r':
		oflags = rw ? O_RDWR : O_RDONLY;
		break;
	case 'w':
		oflags = O_TRUNC | O_CREAT | (rw ? O_RDWR : O_WRONLY);
		break;
	default:
		return (NULL);
	}

	f = open(file, oflags, 0666);
E 5
E 2
	if (f < 0)
D 5
		return(NULL);
E 5
I 5
		return (NULL);

	if (*mode == 'a')
		lseek(f, (off_t)0, L_XTND);

E 5
	iop->_cnt = 0;
	iop->_file = f;
I 5
	iop->_bufsiz = 0;
E 5
D 2
	if (*mode != 'r')
E 2
I 2
	if (rw)
D 5
		iop->_flag |= _IORW;
	else if (*mode != 'r')
E 2
		iop->_flag |= _IOWRT;
E 5
I 5
		iop->_flag = _IORW;
	else if (*mode == 'r')
		iop->_flag = _IOREAD;
E 5
	else
D 5
		iop->_flag |= _IOREAD;
	return(iop);
E 5
I 5
		iop->_flag = _IOWRT;
	iop->_base = iop->_ptr = NULL;
	return (iop);
E 5
}
E 1
