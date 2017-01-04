h43235
s 00010/00005/00050
d D 6.3 88/06/27 17:13:06 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00046
d D 6.2 88/03/07 21:17:14 bostic 4 3
c added Berkeley specific header
e
s 00002/00008/00047
d D 6.1 87/12/04 09:43:14 karels 3 1
c can't use copyright string in libc, use std. LIBC_SCCS
e
s 00000/00006/00049
d R 1.2 87/12/04 09:41:08 karels 2 1
c can't have copyright var in libc!
e
s 00055/00000/00000
d D 1.1 87/11/17 19:18:49 bostic 1 0
c date and time created 87/11/17 19:18:49 by bostic
e
u
U
t
T
I 1
/*
 * Copyright (c) 1987 Regents of the University of California.
D 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
I 4
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
I 5
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
E 5
E 4
 */

D 3
#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* !lint */

#ifndef lint
E 3
I 3
#if defined(LIBC_SCCS) && !defined(lint)
E 3
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif /* !lint */
E 3
I 3
D 4
#endif LIBC_SCCS and not lint
E 4
I 4
#endif /* LIBC_SCCS and not lint */
E 4
E 3

#include <sys/types.h>
#include <sys/uio.h>

char	*h_errlist[] = {
	"Error 0",
	"Unknown host",				/* 1 HOST_NOT_FOUND */
	"Host name lookup failure",		/* 2 TRY_AGAIN */
	"Unknown server error",			/* 3 NO_RECOVERY */
	"No address associated with name",	/* 4 NO_ADDRESS */
};
int	h_nerr = { sizeof(h_errlist)/sizeof(h_errlist[0]) };

extern int	h_errno;

/*
 * herror --
 *	print the error indicated by the h_errno value.
 */
herror(s)
	char *s;
{
	struct iovec iov[4];
	register struct iovec *v = iov;

	if (s && *s) {
		v->iov_base = s;
		v->iov_len = strlen(s);
		v++;
		v->iov_base = ": ";
		v->iov_len = 2;
		v++;
	}
	v->iov_base = h_errno < h_nerr ? h_errlist[h_errno] : "Unknown error";
	v->iov_len = strlen(v->iov_base);
	v++;
	v->iov_base = "\n";
	v->iov_len = 1;
	writev(2, iov, (v - iov) + 1);
}
E 1
