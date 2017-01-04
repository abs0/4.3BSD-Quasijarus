h03069
s 00004/00001/00044
d D 5.1 85/06/05 13:40:47 mckusick 2 1
c Add copyright
e
s 00045/00000/00000
d D 4.1 80/12/21 16:50:52 wnj 1 0
c date and time created 80/12/21 16:50:52 by wnj
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
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 2
#include	<stdio.h>

fread(ptr, size, count, iop)
unsigned size, count;
register char *ptr;
register FILE *iop;
{
	register c;
	unsigned ndone, s;

	ndone = 0;
	if (size)
	for (; ndone<count; ndone++) {
		s = size;
		do {
			if ((c = getc(iop)) >= 0)
				*ptr++ = c;
			else
				return(ndone);
		} while (--s);
	}
	return(ndone);
}

fwrite(ptr, size, count, iop)
unsigned size, count;
register char *ptr;
register FILE *iop;
{
	register unsigned s;
	unsigned ndone;

	ndone = 0;
	if (size)
	for (; ndone<count; ndone++) {
		s = size;
		do {
			putc(*ptr++, iop);
		} while (--s);
		if (ferror(iop))
			break;
	}
	return(ndone);
}
E 1
