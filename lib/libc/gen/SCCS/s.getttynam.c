h02485
s 00002/00002/00024
d D 5.2 86/03/09 19:49:04 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00017
d D 5.1 85/05/30 10:43:16 dist 2 1
c Add copyright
e
s 00018/00000/00000
d D 4.1 84/04/27 10:25:55 ralph 1 0
c date and time created 84/04/27 10:25:55 by ralph
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
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

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

#include <ttyent.h>

struct ttyent *
getttynam(tty)
	char *tty;
{
	register struct ttyent *t;

	setttyent();
	while (t = getttyent()) {
		if (strcmp(tty, t->ty_name) == 0)
			break;
	}
	endttyent();
	return (t);
}
E 1
