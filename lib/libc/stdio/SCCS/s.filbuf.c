h62805
s 00002/00002/00068
d D 5.3 86/03/09 20:49:27 donn 14 13
c added LIBC_SCCS condition for sccs ids
e
s 00002/00007/00068
d D 5.2 86/02/09 16:53:03 karels 13 12
c move dynamic allocations into findiop.c, so can do all at once
e
s 00010/00001/00065
d D 5.1 85/05/30 14:27:20 dist 12 11
c Add copyright
e
s 00010/00002/00056
d D 4.11 85/03/04 14:54:04 serge 11 10
c allow pushback even in unbuffered streams
e
s 00003/00003/00055
d D 4.10 85/02/13 15:48:56 serge 10 9
c autoconfigure FILE array using getdtablesize() 
c changed all struct _iobuf to FILE 
c many miscellaneous changes
e
s 00001/00001/00057
d D 4.9 84/06/21 12:50:27 karels 9 8
c I give up; sticky EOF stays.
e
s 00004/00009/00054
d D 4.8 84/05/15 16:54:46 ralph 8 7
c use malloc instead of static 8K sibuf and sobuf.
e
s 00001/00001/00062
d D 4.7 83/11/01 16:40:55 layer 7 6
c revoke last change
e
s 00001/00001/00062
d D 4.6 83/06/30 15:17:16 sam 6 5
c from sun
e
s 00006/00002/00057
d D 4.5 83/02/27 11:43:48 mckusick 5 4
c check for line buffering of stderr
e
s 00020/00005/00039
d D 4.4 82/10/05 22:43:55 mckusick 4 3
c utilize st_blksize field to optimize size of reads and writes
e
s 00002/00002/00042
d D 4.3 81/05/19 04:10:03 sklower 3 2
c fix bug in reentrant use of same FILE * descrip at interrupt time, per jkf
e
s 00007/00002/00037
d D 4.2 81/03/09 20:59:10 toy 2 1
c Feldman's stdio changes
e
s 00039/00000/00000
d D 4.1 80/12/21 16:50:12 wnj 1 0
c date and time created 80/12/21 16:50:12 by wnj
e
u
U
t
T
I 1
D 12
/* %W% (Berkeley) %G% */
E 12
I 12
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 14
#ifndef lint
E 14
I 14
#if defined(LIBC_SCCS) && !defined(lint)
E 14
static char sccsid[] = "%W% (Berkeley) %G%";
D 14
#endif not lint
E 14
I 14
#endif LIBC_SCCS and not lint
E 14

E 12
#include	<stdio.h>
I 4
#include	<sys/types.h>
#include	<sys/stat.h>
E 4
char	*malloc();

_filbuf(iop)
register FILE *iop;
{
I 4
	int size;
	struct stat stbuf;
E 4
D 10
	static char smallbuf[_NFILE];
E 10
I 10
D 11
	extern char *_smallbuf();
E 11
I 11
D 13
	static char *smallbuf;
	static int nfiles;
E 13
I 13
	extern char *_smallbuf;
E 13
	char c;
E 11
E 10
I 4
D 8
	extern char _sibuf[];
E 8
E 4

I 2
	if (iop->_flag & _IORW)
		iop->_flag |= _IOREAD;

E 2
	if ((iop->_flag&_IOREAD) == 0)
		return(EOF);
D 6
	if (iop->_flag&_IOSTRG)
E 6
I 6
D 7
	if (iop->_flag&(_IOSTRG|_IOEOF))
E 7
I 7
D 9
	if (iop->_flag&_IOSTRG)
E 9
I 9
	if (iop->_flag&(_IOSTRG|_IOEOF))
E 9
E 7
E 6
		return(EOF);
tryagain:
	if (iop->_base==NULL) {
		if (iop->_flag&_IONBF) {
D 10
			iop->_base = &smallbuf[fileno(iop)];
E 10
I 10
D 11
			iop->_base = _smallbuf(iop);
E 11
I 11
D 13
			if (nfiles <= 0)
				nfiles = getdtablesize();
			if (smallbuf == NULL)
				smallbuf = malloc(nfiles * sizeof *smallbuf);
			iop->_base = smallbuf ? &smallbuf[fileno(iop)] : &c;
E 13
I 13
			iop->_base = _smallbuf ? &_smallbuf[fileno(iop)] : &c;
E 13
E 11
E 10
			goto tryagain;
		}
D 4
		if ((iop->_base = malloc(BUFSIZ)) == NULL) {
			iop->_flag |= _IONBF;
			goto tryagain;
E 4
I 4
		if (fstat(fileno(iop), &stbuf) < 0 || stbuf.st_blksize <= NULL)
			size = BUFSIZ;
		else
			size = stbuf.st_blksize;
D 8
		if (iop == stdin)
			iop->_base = _sibuf;
		else {
			if ((iop->_base = malloc(size)) == NULL) {
				iop->_flag |= _IONBF;
				goto tryagain;
			}
			iop->_flag |= _IOMYBUF;
E 8
I 8
		if ((iop->_base = malloc(size)) == NULL) {
			iop->_flag |= _IONBF;
			goto tryagain;
E 8
E 4
		}
I 8
		iop->_flag |= _IOMYBUF;
E 8
D 4
		iop->_flag |= _IOMYBUF;
E 4
I 4
		iop->_bufsiz = size;
E 4
	}
D 3
	iop->_ptr = iop->_base;
E 3
D 5
	if (iop == stdin && (stdout->_flag&_IOLBF))
		fflush(stdout);
E 5
I 5
	if (iop == stdin) {
		if (stdout->_flag&_IOLBF)
			fflush(stdout);
		if (stderr->_flag&_IOLBF)
			fflush(stderr);
	}
E 5
D 3
	iop->_cnt = read(fileno(iop), iop->_ptr, iop->_flag&_IONBF?1:BUFSIZ);
E 3
I 3
D 4
	iop->_cnt = read(fileno(iop), iop->_base, iop->_flag&_IONBF?1:BUFSIZ);
E 4
I 4
	iop->_cnt = read(fileno(iop), iop->_base,
		iop->_flag & _IONBF ? 1 : iop->_bufsiz);
E 4
	iop->_ptr = iop->_base;
I 11
	if (iop->_flag & _IONBF && iop->_base == &c)
		iop->_base = NULL;
E 11
E 3
	if (--iop->_cnt < 0) {
D 2
		if (iop->_cnt == -1)
E 2
I 2
		if (iop->_cnt == -1) {
E 2
			iop->_flag |= _IOEOF;
D 2
		else
E 2
I 2
			if (iop->_flag & _IORW)
				iop->_flag &= ~_IOREAD;
		} else
E 2
			iop->_flag |= _IOERR;
		iop->_cnt = 0;
D 10
		return(-1);
E 10
I 10
		return(EOF);
E 10
	}
	return(*iop->_ptr++&0377);
}
E 1
