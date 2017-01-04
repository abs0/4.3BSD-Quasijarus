h38218
s 00002/00002/00033
d D 5.2 86/03/09 20:51:51 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00004/00001/00031
d D 5.1 85/06/05 13:36:39 mckusick 4 3
c Add copyright
e
s 00002/00002/00030
d D 4.3 85/02/13 15:48:49 serge 3 2
c autoconfigure FILE array using getdtablesize() 
c changed all struct _iobuf to FILE 
c many miscellaneous changes
e
s 00002/00002/00030
d D 4.2 81/03/09 20:59:24 toy 2 1
c Feldman's stdio changes
e
s 00032/00000/00000
d D 4.1 80/12/21 16:50:28 wnj 1 0
c date and time created 80/12/21 16:50:28 by wnj
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
/*
 * Return file offset.
 * Coordinates with buffering.
 */

#include	<stdio.h>
long	lseek();


long ftell(iop)
D 3
FILE *iop;
E 3
I 3
register FILE *iop;
E 3
{
D 3
	long tres;
E 3
I 3
	register long tres;
E 3
	register adjust;

	if (iop->_cnt < 0)
		iop->_cnt = 0;
	if (iop->_flag&_IOREAD)
		adjust = - iop->_cnt;
D 2
	else if (iop->_flag&_IOWRT) {
E 2
I 2
	else if (iop->_flag&(_IOWRT|_IORW)) {
E 2
		adjust = 0;
D 2
		if (iop->_base && (iop->_flag&_IONBF)==0)
E 2
I 2
		if (iop->_flag&_IOWRT && iop->_base && (iop->_flag&_IONBF)==0)
E 2
			adjust = iop->_ptr - iop->_base;
	} else
		return(-1);
	tres = lseek(fileno(iop), 0L, 1);
	if (tres<0)
		return(tres);
	tres += adjust;
	return(tres);
}
E 1
