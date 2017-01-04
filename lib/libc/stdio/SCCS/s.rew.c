h12726
s 00010/00005/00028
d D 5.4 88/06/27 17:50:05 bostic 7 6
c install approved copyright notice
e
s 00021/00005/00012
d D 5.3 87/12/02 14:04:48 bostic 6 5
c add header; use correct #defines; make lint happy
e
s 00002/00002/00015
d D 5.2 86/03/09 20:53:21 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00004/00001/00013
d D 5.1 85/06/05 13:41:16 mckusick 4 3
c Add copyright
e
s 00001/00001/00013
d D 4.3 85/02/13 15:49:05 serge 3 2
c autoconfigure FILE array using getdtablesize() 
c changed all struct _iobuf to FILE 
c many miscellaneous changes
e
s 00002/00000/00012
d D 4.2 81/03/09 20:59:27 toy 2 1
c Feldman's stdio changes
e
s 00012/00000/00000
d D 4.1 80/12/21 16:50:53 wnj 1 0
c date and time created 80/12/21 16:50:53 by wnj
e
u
U
t
T
I 6
/*
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 7
 */

E 6
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
D 6
#endif LIBC_SCCS and not lint
E 6
I 6
#endif /* LIBC_SCCS and not lint */
E 6
E 5

E 4
D 6
#include	<stdio.h>
E 6
I 6
#include <sys/types.h>
#include <sys/file.h>
#include <stdio.h>
E 6

rewind(iop)
D 3
register struct _iobuf *iop;
E 3
I 3
D 6
register FILE *iop;
E 6
I 6
	register FILE *iop;
E 6
E 3
{
D 6
	fflush(iop);
	lseek(fileno(iop), 0L, 0);
E 6
I 6
	off_t lseek();

	(void)fflush(iop);
	(void)lseek(fileno(iop), 0L, L_SET);
E 6
	iop->_cnt = 0;
	iop->_ptr = iop->_base;
	iop->_flag &= ~(_IOERR|_IOEOF);
I 2
	if (iop->_flag & _IORW)
		iop->_flag &= ~(_IOREAD|_IOWRT);
E 2
}
E 1
