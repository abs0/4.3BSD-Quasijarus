h53564
s 00004/00001/00020
d D 5.3 86/03/26 18:08:36 bloom 6 5
c avoid possible problem from too many calls to ungetc
e
s 00002/00002/00019
d D 5.2 86/03/09 20:54:42 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00003/00001/00018
d D 5.1 85/06/05 13:44:40 mckusick 4 3
c Add copyright
e
s 00008/00007/00011
d D 4.3 85/02/13 15:49:01 serge 3 2
c autoconfigure FILE array using getdtablesize() 
c changed all struct _iobuf to FILE 
c many miscellaneous changes
e
s 00008/00007/00010
d D 4.2 83/09/25 12:58:05 sam 2 1
c make return values correspond to man page; from lepreau@utah-cs
e
s 00017/00000/00000
d D 4.1 80/12/21 16:51:04 wnj 1 0
c date and time created 80/12/21 16:51:04 by wnj
e
u
U
t
T
I 1
D 2
/* %W% (Berkeley) %G% */
E 2
I 2
D 4
/*	%M%	%I%	%E%	*/
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

E 2
#include <stdio.h>

ungetc(c, iop)
D 2
register FILE *iop;
E 2
I 2
	register FILE *iop;
E 2
{
D 3
	if (c == EOF)
D 2
		return(-1);
	if ((iop->_flag&_IOREAD)==0 || iop->_ptr <= iop->_base)
		if (iop->_ptr == iop->_base && iop->_cnt==0)
E 2
I 2
		return (-1);
	if ((iop->_flag&_IOREAD) == 0 || iop->_ptr <= iop->_base)
		if (iop->_ptr == iop->_base && iop->_cnt == 0)
E 2
			*iop->_ptr++;
		else
D 2
			return(-1);
E 2
I 2
			return (EOF);
E 3
I 3
	if (c == EOF || (iop->_flag & (_IOREAD|_IORW)) == 0 ||
	    iop->_ptr == NULL || iop->_base == NULL)
		return (EOF);

	if (iop->_ptr == iop->_base)
D 6
		iop->_ptr++;
E 6
I 6
		if (iop->_cnt == 0)
			iop->_ptr++;
		else
			return (EOF);
E 6

E 3
E 2
	iop->_cnt++;
	*--iop->_ptr = c;
I 3

E 3
D 2
	return(0);
E 2
I 2
	return (c);
E 2
}
E 1
