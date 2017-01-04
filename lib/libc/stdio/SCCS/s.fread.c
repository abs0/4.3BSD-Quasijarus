h52197
s 00002/00002/00044
d D 5.2 86/03/09 20:51:12 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00010/00001/00036
d D 5.1 85/05/30 14:28:48 dist 4 3
c Add copyright
e
s 00001/00001/00036
d D 4.3 85/05/14 21:16:18 sam 3 2
c beware of divide by 0
e
s 00003/00001/00034
d D 4.2 84/09/05 14:17:37 ralph 2 1
c don't save EOF in buffer, don't sign-extend 0xff to match EOF.
e
s 00035/00000/00000
d D 4.1 84/05/29 13:51:03 karels 1 0
c date and time created 84/05/29 13:51:03 by karels
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
#include	<stdio.h>

fread(ptr, size, count, iop)
	register char *ptr;
	unsigned size, count;
	register FILE *iop;
{
	register int s;
I 2
	int c;
E 2

	s = size * count;
	while (s > 0) {
		if (iop->_cnt < s) {
			if (iop->_cnt > 0) {
				bcopy(iop->_ptr, ptr, iop->_cnt);
				ptr += iop->_cnt;
				s -= iop->_cnt;
			}
			/*
			 * filbuf clobbers _cnt & _ptr,
			 * so don't waste time setting them.
			 */
D 2
			if ((*ptr++ = _filbuf(iop)) == EOF)
E 2
I 2
			if ((c = _filbuf(iop)) == EOF)
E 2
				break;
I 2
			*ptr++ = c;
E 2
			s--;
		}
		if (iop->_cnt >= s) {
			bcopy(iop->_ptr, ptr, s);
			iop->_ptr += s;
			iop->_cnt -= s;
			return (count);
		}
	}
D 3
	return (count - ((s + size - 1) / size));
E 3
I 3
	return (size != 0 ? count - ((s + size - 1) / size) : 0);
E 3
}
E 1
