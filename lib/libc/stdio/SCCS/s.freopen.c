h61902
s 00002/00002/00057
d D 5.2 86/03/09 20:51:24 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00010/00001/00049
d D 5.1 85/05/30 14:29:05 dist 4 3
c Add copyright
e
s 00036/00034/00014
d D 4.3 85/02/13 15:48:43 serge 3 2
c autoconfigure FILE array using getdtablesize() 
c changed all struct _iobuf to FILE 
c many miscellaneous changes
e
s 00028/00009/00020
d D 4.2 81/03/09 20:59:18 toy 2 1
c Feldman's stdio changes
e
s 00029/00000/00000
d D 4.1 80/12/21 16:50:24 wnj 1 0
c date and time created 80/12/21 16:50:24 by wnj
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
 * Copyright (c) 1980 Regents of the University of California.
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
D 2
#include <stdio.h>
E 2
I 2
D 3
#include	<stdio.h>
#include	<errno.h>
E 3
I 3
#include <sys/types.h>
#include <sys/file.h>
#include <stdio.h>
E 3
E 2

FILE *
freopen(file, mode, iop)
D 3
char *file;
register char *mode;
register FILE *iop;
E 3
I 3
	char *file;
	register char *mode;
	register FILE *iop;
E 3
{
D 2
	register f;
E 2
I 2
D 3
	extern int errno;
	register f, rw;
E 3
I 3
	register f, rw, oflags;
E 3
E 2

I 2
D 3
	rw = mode[1] == '+';
E 3
I 3
	rw = (mode[1] == '+');
E 3

E 2
	fclose(iop);
D 2
	if (*mode=='w')
E 2
I 2
D 3
	if (*mode=='w') {
E 2
		f = creat(file, 0666);
D 2
	else if (*mode=='a') {
		if ((f = open(file, 1)) < 0)
			f = creat(file, 0666);
		lseek(f, 0L, 2);
E 2
I 2
		if (rw && f>=0) {
			close(f);
			f = open(file, 2);
		}
	} else if (*mode=='a') {
		if ((f = open(file, rw? 2: 1)) < 0) {
			if (errno == ENOENT) {
				f = creat(file, 0666);
				if (rw && f>=0) {
					close(f);
					f = open(file, 2);
				}
			}
		}
		if (f >= 0)
			lseek(f, 0L, 2);
E 2
	} else
D 2
		f = open(file, 0);
E 2
I 2
		f = open(file, rw? 2: 0);
E 3
I 3

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
E 3
E 2
	if (f < 0)
D 3
		return(NULL);
E 3
I 3
		return (NULL);

	if (*mode == 'a')
		lseek(f, (off_t)0, L_XTND);

E 3
I 2
	iop->_cnt = 0;
E 2
	iop->_file = f;
I 3
	iop->_bufsiz = 0;
E 3
D 2
	if (*mode != 'r')
E 2
I 2
	if (rw)
D 3
		iop->_flag |= _IORW;
	else if (*mode != 'r')
E 2
		iop->_flag |= _IOWRT;
E 3
I 3
		iop->_flag = _IORW;
	else if (*mode == 'r')
		iop->_flag = _IOREAD;
E 3
	else
D 3
		iop->_flag |= _IOREAD;
	return(iop);
E 3
I 3
		iop->_flag = _IOWRT;
	iop->_base = iop->_ptr = NULL;
	return (iop);
E 3
}
E 1
