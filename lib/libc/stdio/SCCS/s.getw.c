h49165
s 00002/00002/00018
d D 5.2 86/03/09 20:52:34 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00004/00001/00016
d D 5.1 85/06/05 13:37:50 mckusick 2 1
c Add copyright
e
s 00017/00000/00000
d D 4.1 80/12/21 16:50:42 wnj 1 0
c date and time created 80/12/21 16:50:42 by wnj
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
D 3
#ifndef lint
E 3
I 3
#if defined(LIBC_SCCS) && !defined(lint)
E 3
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
#endif LIBC_SCCS and not lint
E 3

E 2
#include <stdio.h>

getw(iop)
register FILE *iop;
{
	register i;
	register char *p;
	int w;

	p = (char *)&w;
	for (i=sizeof(int); --i>=0;)
		*p++ = getc(iop);
	if (feof(iop))
		return(EOF);
	return(w);
}
E 1
