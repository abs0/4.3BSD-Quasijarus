h20277
s 00002/00002/00047
d D 5.2 86/03/09 20:52:02 donn 7 6
c added LIBC_SCCS condition for sccs ids
e
s 00010/00001/00039
d D 5.1 85/05/30 14:29:29 dist 6 5
c Add copyright
e
s 00001/00001/00039
d D 4.5 85/05/14 21:16:21 sam 5 4
c beware of divide by 0
e
s 00002/00001/00038
d D 4.4 85/01/23 16:58:33 ralph 4 3
c get return value right.
e
s 00009/00002/00030
d D 4.3 84/11/29 11:02:59 ralph 3 2
c don't call flsbuf for every char if line buffering.
e
s 00001/00001/00031
d D 4.2 84/08/03 16:48:18 ralph 2 1
c don't sign extend character otherwise flsbuf can return EOF falsely
e
s 00032/00000/00000
d D 4.1 84/05/29 13:51:09 karels 1 0
c date and time created 84/05/29 13:51:09 by karels
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
#include	<stdio.h>

fwrite(ptr, size, count, iop)
	register char *ptr;
	unsigned size, count;
	register FILE *iop;
{
	register int s;

	s = size * count;
D 3
	while (s > 0) {
E 3
I 3
	if (iop->_flag & _IOLBF)
D 4
		while (--s >= 0) {
E 4
I 4
		while (s > 0) {
E 4
			if (--iop->_cnt > -iop->_bufsiz && *ptr != '\n')
				*iop->_ptr++ = *ptr++;
			else if (_flsbuf(*(unsigned char *)ptr++, iop) == EOF)
				break;
I 4
			s--;
E 4
		}
	else while (s > 0) {
E 3
		if (iop->_cnt < s) {
			if (iop->_cnt > 0) {
				bcopy(ptr, iop->_ptr, iop->_cnt);
				ptr += iop->_cnt;
				iop->_ptr += iop->_cnt;
				s -= iop->_cnt;
			}
D 2
			if (_flsbuf((unsigned)*ptr++, iop) == EOF)
E 2
I 2
D 3
			if (_flsbuf((unsigned)*ptr++ & 0377, iop) == EOF)
E 3
I 3
			if (_flsbuf(*(unsigned char *)ptr++, iop) == EOF)
E 3
E 2
				break;
			s--;
		}
		if (iop->_cnt >= s) {
			bcopy(ptr, iop->_ptr, s);
			iop->_ptr += s;
			iop->_cnt -= s;
			return (count);
		}
	}
D 5
	return (count - ((s + size - 1) / size));
E 5
I 5
	return (size != 0 ? count - ((s + size - 1) / size) : 0);
E 5
}
E 1
