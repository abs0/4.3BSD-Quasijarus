h14682
s 00002/00002/00031
d D 5.2 86/03/09 20:53:31 donn 4 3
c added LIBC_SCCS condition for sccs ids
e
s 00004/00001/00029
d D 5.1 85/06/05 13:42:06 mckusick 3 2
c Add copyright
e
s 00001/00000/00029
d D 4.2 82/10/05 22:44:05 mckusick 2 1
c utilize st_blksize field to optimize size of reads and writes
e
s 00029/00000/00000
d D 4.1 80/12/21 16:50:54 wnj 1 0
c date and time created 80/12/21 16:50:54 by wnj
e
u
U
t
T
I 1
D 3
/* %W% (Berkeley) %G% */
E 3
I 3
D 4
#ifndef lint
E 4
I 4
#if defined(LIBC_SCCS) && !defined(lint)
E 4
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif not lint
E 4
I 4
#endif LIBC_SCCS and not lint
E 4

E 3
#include	<stdio.h>

scanf(fmt, args)
char *fmt;
{
	return(_doscan(stdin, fmt, &args));
}

fscanf(iop, fmt, args)
FILE *iop;
char *fmt;
{
	return(_doscan(iop, fmt, &args));
}

sscanf(str, fmt, args)
register char *str;
char *fmt;
{
	FILE _strbuf;

	_strbuf._flag = _IOREAD|_IOSTRG;
	_strbuf._ptr = _strbuf._base = str;
	_strbuf._cnt = 0;
	while (*str++)
		_strbuf._cnt++;
I 2
	_strbuf._bufsiz = _strbuf._cnt;
E 2
	return(_doscan(&_strbuf, fmt, &args));
}
E 1
