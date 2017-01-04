h64459
s 00002/00002/00039
d D 5.3 87/09/30 10:04:44 bostic 5 4
c sys_nerr and sys_errlist are externs
e
s 00002/00002/00039
d D 5.2 86/03/09 19:52:09 donn 4 3
c added LIBC_SCCS condition for sccs ids
e
s 00010/00001/00031
d D 5.1 85/05/30 10:47:20 dist 3 2
c Add copyright
e
s 00018/00012/00014
d D 4.2 83/06/30 14:46:40 sam 2 1
c use writev to avoid small net writes
e
s 00026/00000/00000
d D 4.1 80/12/21 16:39:58 wnj 1 0
c date and time created 80/12/21 16:39:58 by wnj
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
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

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
/*
 * Print the error indicated
 * in the cerror cell.
 */
I 2
#include <sys/types.h>
#include <sys/uio.h>
E 2

int	errno;
D 5
int	sys_nerr;
char	*sys_errlist[];
E 5
I 5
extern int	sys_nerr;
extern char	*sys_errlist[];
E 5
perror(s)
D 2
char *s;
E 2
I 2
	char *s;
E 2
{
D 2
	register char *c;
	register n;
E 2
I 2
	struct iovec iov[4];
	register struct iovec *v = iov;
E 2

D 2
	c = "Unknown error";
	if(errno < sys_nerr)
		c = sys_errlist[errno];
	n = strlen(s);
	if(n) {
		write(2, s, n);
		write(2, ": ", 2);
E 2
I 2
	if (s && *s) {
		v->iov_base = s;
		v->iov_len = strlen(s);
		v++;
		v->iov_base = ": ";
		v->iov_len = 2;
		v++;
E 2
	}
D 2
	write(2, c, strlen(c));
	write(2, "\n", 1);
E 2
I 2
	v->iov_base = errno < sys_nerr ? sys_errlist[errno] : "Unknown error";
	v->iov_len = strlen(v->iov_base);
	v++;
	v->iov_base = "\n";
	v->iov_len = 1;
	writev(2, iov, (v - iov) + 1);
E 2
}
E 1
