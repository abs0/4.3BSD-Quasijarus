h45825
s 00002/00002/00062
d D 5.3 86/03/09 20:51:40 donn 10 9
c added LIBC_SCCS condition for sccs ids
e
s 00010/00011/00054
d D 5.2 86/03/01 04:52:20 lepreau 9 8
c back out portion of last rev that make it return the offset;
c (for Sys V compat);  more error checking
e
s 00004/00001/00061
d D 5.1 85/06/05 13:36:05 mckusick 8 7
c Add copyright
e
s 00016/00010/00046
d D 4.4 85/02/13 17:12:05 serge 7 3
c autoconfigure FILE array using getdtablesize() 
c changed all struct _iobuf to FILE 
c many miscellaneous changes
e
s 00016/00010/00046
d R 4.4 85/02/13 17:11:01 serge 6 3
c autoconfigure FILE array using getdtablesize() 
c changed all struct _iobuf to FILE 
c many miscellaneous changes
e
s 00016/00010/00046
d R 4.4 85/02/13 17:09:40 serge 5 3
c autoconfigure FILE array using getdtablesize() \ 
e
s 00014/00008/00048
d R 4.4 85/02/13 15:48:46 serge 4 3
c autoconfigure FILE array using getdtablesize() 
c changed all struct _iobuf to FILE 
c many miscellaneous changes
e
s 00001/00000/00055
d D 4.3 83/09/25 11:48:07 karels 3 2
c fix seek on IORW streams
e
s 00012/00002/00043
d D 4.2 81/03/09 20:59:21 toy 2 1
c Feldman's stdio changes
e
s 00045/00000/00000
d D 4.1 80/12/21 16:50:25 wnj 1 0
c date and time created 80/12/21 16:50:25 by wnj
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
D 10
#ifndef lint
E 10
I 10
#if defined(LIBC_SCCS) && !defined(lint)
E 10
static char sccsid[] = "%W% (Berkeley) %G%";
D 10
#endif not lint
E 10
I 10
#endif LIBC_SCCS and not lint
E 10

E 8
/*
 * Seek for standard library.  Coordinates with buffering.
 */

#include	<stdio.h>

long lseek();

I 7
D 9
long
E 9
E 7
fseek(iop, offset, ptrname)
D 7
FILE *iop;
long offset;
E 7
I 7
	register FILE *iop;
	long offset;
E 7
{
	register resync, c;
D 7
	long p;
E 7
I 7
D 9
	long p, curpos = -1;
E 9
I 9
	long p = -1;			/* can't happen? */
E 9
E 7

	iop->_flag &= ~_IOEOF;
	if (iop->_flag&_IOREAD) {
		if (ptrname<2 && iop->_base &&
			!(iop->_flag&_IONBF)) {
			c = iop->_cnt;
			p = offset;
D 7
			if (ptrname==0)
				p += c - lseek(fileno(iop),0L,1);
			else
E 7
I 7
			if (ptrname==0) {
D 9
				curpos = lseek(fileno(iop), 0L, 1);
E 9
I 9
				long curpos = lseek(fileno(iop), 0L, 1);
E 9
				if (curpos == -1)
					return (-1);
				p += c - curpos;
			} else
E 7
				offset -= c;
D 2
			if(c>0&&p<=c&&p>=iop->_base-iop->_ptr){
E 2
I 2
			if(!(iop->_flag&_IORW) && c>0&&p<=c
			    && p>=iop->_base-iop->_ptr){
E 2
				iop->_ptr += (int)p;
				iop->_cnt -= (int)p;
D 7
				return(0);
E 7
I 7
D 9
				if (curpos == -1)
					curpos = lseek(fileno(iop), 0L, 1);
				return (curpos == -1? -1: curpos - iop->_cnt);
E 9
I 9
				return(0);
E 9
E 7
			}
			resync = offset&01;
		} else 
			resync = 0;
I 2
		if (iop->_flag & _IORW) {
			iop->_ptr = iop->_base;
			iop->_flag &= ~_IOREAD;
I 3
			resync = 0;
E 3
		}
E 2
		p = lseek(fileno(iop), offset-resync, ptrname);
		iop->_cnt = 0;
D 7
		if (resync)
			getc(iop);
E 7
I 7
D 9
		if (resync && getc(iop) != EOF && p != -1)
			p++;
E 9
I 9
		if (resync && p != -1)
			if (getc(iop) == EOF)
				p = -1;
E 9
E 7
	}
D 2
	else if (iop->_flag&_IOWRT) {
E 2
I 2
	else if (iop->_flag & (_IOWRT|_IORW)) {
E 2
D 9
		fflush(iop);
E 9
I 9
		p = fflush(iop);
E 9
I 2
		if (iop->_flag & _IORW) {
			iop->_cnt = 0;
			iop->_flag &= ~_IOWRT;
			iop->_ptr = iop->_base;
		}
E 2
D 9
		p = lseek(fileno(iop), offset, ptrname);
E 9
I 9
		return(lseek(fileno(iop), offset, ptrname) == -1 || p == EOF ?
		    -1 : 0);
E 9
	}
D 7
	return(p==-1?-1:0);
E 7
I 7
D 9
	return(p);
E 9
I 9
	return(p==-1?-1:0);
E 9
E 7
}
E 1
