h44179
s 00002/00002/00119
d D 5.2 86/03/09 20:49:59 donn 12 11
c added LIBC_SCCS condition for sccs ids
e
s 00010/00001/00111
d D 5.1 85/05/30 14:27:56 dist 11 10
c Add copyright
e
s 00002/00015/00110
d D 4.9 85/02/13 15:48:52 serge 10 9
c autoconfigure FILE array using getdtablesize() 
c changed all struct _iobuf to FILE 
c many miscellaneous changes
e
s 00002/00001/00123
d D 4.8 84/11/21 12:10:10 ralph 9 8
c fix flsbuf('\377'); make _cnt backward comp. with old putc macro.
e
s 00005/00009/00119
d D 4.7 84/06/06 14:49:45 ralph 8 6
c use malloc instead of static 8K sobuf.
e
s 00002/00009/00119
d R 4.7 84/05/15 16:54:41 ralph 7 6
c use malloc instead of static 8K sibuf and sobuf.
e
s 00001/00001/00127
d D 4.6 83/06/30 15:17:22 sam 6 5
c from sun
e
s 00001/00041/00127
d D 4.5 82/12/16 09:45:01 sam 5 4
c clean up after clem
e
s 00046/00006/00122
d D 4.4 82/12/15 21:34:52 clemc 4 3
c Fixed a bug in fclose as per Dennis Ritchie comments.
c fclose should not have any side effects.  It is supposed to sanitize
c the buffer structure when it exits.  Currently, it left most of the
c fields within the buffer structure Non-Zero.  This normally does not
c matter, BUT if fopen/setbuf/fclose/fopen.. the structure returned by the
c second fopen would already be filled in.  This is a lose!   Clem
e
s 00018/00005/00110
d D 4.3 82/10/05 22:44:00 mckusick 3 2
c utilize st_blksize field to optimize size of reads and writes
e
s 00007/00002/00108
d D 4.2 81/03/09 20:59:12 toy 2 1
c Feldman's stdio changes
e
s 00110/00000/00000
d D 4.1 80/12/21 16:50:14 wnj 1 0
c date and time created 80/12/21 16:50:14 by wnj
e
u
U
t
T
I 1
D 11
/* %W% (Berkeley) %G% */
E 11
I 11
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 12
#ifndef lint
E 12
I 12
#if defined(LIBC_SCCS) && !defined(lint)
E 12
static char sccsid[] = "%W% (Berkeley) %G%";
D 12
#endif not lint
E 12
I 12
#endif LIBC_SCCS and not lint
E 12

E 11
#include	<stdio.h>
I 3
#include	<sys/types.h>
#include	<sys/stat.h>
E 3

char	*malloc();

_flsbuf(c, iop)
I 9
unsigned char c;
E 9
register FILE *iop;
{
	register char *base;
	register n, rn;
	char c1;
I 3
	int size;
	struct stat stbuf;
E 3
D 8
	extern char _sobuf[];
E 8

I 2
	if (iop->_flag & _IORW) {
		iop->_flag |= _IOWRT;
D 6
		iop->_flag &= ~_IOEOF;
E 6
I 6
		iop->_flag &= ~(_IOEOF|_IOREAD);
E 6
	}

E 2
	if ((iop->_flag&_IOWRT)==0)
		return(EOF);
tryagain:
	if (iop->_flag&_IOLBF) {
		base = iop->_base;
		*iop->_ptr++ = c;
D 3
		if (iop->_ptr >= base+BUFSIZ || c == '\n') {
E 3
I 3
		if (iop->_ptr >= base+iop->_bufsiz || c == '\n') {
E 3
			n = write(fileno(iop), base, rn = iop->_ptr - base);
			iop->_ptr = base;
I 9
			iop->_cnt = 0;
E 9
		} else
			rn = n = 0;
D 9
		iop->_cnt = 0;
E 9
	} else if (iop->_flag&_IONBF) {
		c1 = c;
		rn = 1;
		n = write(fileno(iop), &c1, rn);
		iop->_cnt = 0;
	} else {
		if ((base=iop->_base)==NULL) {
I 3
			if (fstat(fileno(iop), &stbuf) < 0 ||
			    stbuf.st_blksize <= NULL)
				size = BUFSIZ;
			else
				size = stbuf.st_blksize;
E 3
D 8
			if (iop==stdout) {
				if (isatty(fileno(stdout)))
					iop->_flag |= _IOLBF;
				iop->_base = _sobuf;
				iop->_ptr = _sobuf;
I 3
				iop->_bufsiz = size;
E 3
				goto tryagain;
			}
E 8
D 3
			if ((iop->_base=base=malloc(BUFSIZ)) == NULL) {
E 3
I 3
			if ((iop->_base=base=malloc(size)) == NULL) {
E 3
				iop->_flag |= _IONBF;
				goto tryagain;
			}
			iop->_flag |= _IOMYBUF;
I 3
			iop->_bufsiz = size;
I 8
			if (iop==stdout && isatty(fileno(stdout))) {
				iop->_flag |= _IOLBF;
				iop->_ptr = base;
				goto tryagain;
			}
E 8
E 3
			rn = n = 0;
		} else if ((rn = n = iop->_ptr - base) > 0) {
			iop->_ptr = base;
			n = write(fileno(iop), base, n);
		}
D 3
		iop->_cnt = BUFSIZ-1;
E 3
I 3
		iop->_cnt = iop->_bufsiz-1;
E 3
		*base++ = c;
		iop->_ptr = base;
	}
	if (rn != n) {
		iop->_flag |= _IOERR;
		return(EOF);
	}
	return(c);
}

fflush(iop)
D 10
register struct _iobuf *iop;
E 10
I 10
register FILE *iop;
E 10
{
	register char *base;
	register n;

	if ((iop->_flag&(_IONBF|_IOWRT))==_IOWRT
	 && (base=iop->_base)!=NULL && (n=iop->_ptr-base)>0) {
		iop->_ptr = base;
D 3
		iop->_cnt = (iop->_flag&(_IOLBF|_IONBF)) ? 0 : BUFSIZ;
E 3
I 3
		iop->_cnt = (iop->_flag&(_IOLBF|_IONBF)) ? 0 : iop->_bufsiz;
E 3
		if (write(fileno(iop), base, n)!=n) {
			iop->_flag |= _IOERR;
			return(EOF);
		}
	}
	return(0);
}

D 10
/*
 * Flush buffers on exit
 */

_cleanup()
{
	register struct _iobuf *iop;
	extern struct _iobuf *_lastbuf;

	for (iop = _iob; iop < _lastbuf; iop++)
		fclose(iop);
}

E 10
I 4
D 5
/*
 * fclose(*iop) - Close an open stdio stream without side effects.
 *
 * As per Dennis Ricthie's mail, fclose is defined to leave in a "virgin" state,
 * the structure pointed to by the parameter, *iop.  This means that
 * all flags are cleared, counters set to 0 and Pointers set to NULL.
 *
 * Which implies:
 *		foo = fopen...
 *		setbuf (foo, some_buffer);
 *		.....
 *		fclose(foo);
 *
 *	Will leave the buffer stucture cleared.  If the user wishes to
 * reuse the *iop (foo) when he opens another file he must AGAIN call setbuf(3)
 * if he again wishes to supply his own buffer.
 *
 *	The old method allowed the above case but had a nasty side effect
 * of leaving data around if the phase of the moon was right.  The correct
 * solution is to sanitize everything with the fclose.
 *	Clem Cole 12-15-82
 */

E 5
E 4
fclose(iop)
D 5
register struct _iobuf *iop;
E 5
I 5
D 10
	register struct _iobuf *iop;
E 10
I 10
	register FILE *iop;
E 10
E 5
{
D 4
	register r;
E 4
I 4
	register int r;
E 4

	r = EOF;
I 4
D 5
	/*
	 * Is this an open file structure as opposed to being String.
	 */
E 5
E 4
D 2
	if (iop->_flag&(_IOREAD|_IOWRT) && (iop->_flag&_IOSTRG)==0) {
E 2
I 2
	if (iop->_flag&(_IOREAD|_IOWRT|_IORW) && (iop->_flag&_IOSTRG)==0) {
I 4
D 5
		/*
		 * flush out any pending I/O
		 */
E 5
E 4
E 2
		r = fflush(iop);
I 4
D 5
		/*
		 * tell UNIX that it can free up the file descriptor
		 */
E 5
E 4
		if (close(fileno(iop)) < 0)
			r = EOF;
I 4
D 5
		/*
		 * if we had done a malloc(3) in flsbuf or filbuf we need
		 * to give the buffer back to the system
		 */
E 5
E 4
		if (iop->_flag&_IOMYBUF)
			free(iop->_base);
D 3
		if (iop->_flag&(_IOMYBUF|_IONBF|_IOLBF))
E 3
I 3
D 4
		if (iop->_flag&(_IOMYBUF|_IONBF|_IOLBF)) {
E 3
			iop->_base = NULL;
I 3
			iop->_bufsiz = 0;
		}
E 4
E 3
	}
D 2
	iop->_flag &= ~(_IOREAD|_IOWRT|_IOLBF|_IONBF|_IOMYBUF|_IOERR|_IOEOF|_IOSTRG);
E 2
I 2
D 4
	iop->_flag &= ~(_IOREAD|_IOWRT|_IOLBF|_IONBF|_IOMYBUF|_IOERR|_IOEOF|_IOSTRG|_IORW);
E 4
I 4
D 5
	/*
	 * finially sanitize the buffer structure
	 */
E 5
E 4
E 2
	iop->_cnt = 0;
I 4
	iop->_base = (char *)NULL;
	iop->_ptr = (char *)NULL;
	iop->_bufsiz = 0;
	iop->_flag = 0;
	iop->_file = 0;
D 5

E 5
E 4
	return(r);
}
E 1
