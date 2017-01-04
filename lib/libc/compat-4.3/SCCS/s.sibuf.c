h37623
s 00002/00002/00005
d D 5.2 86/03/09 20:54:01 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00003/00001/00004
d D 5.1 85/06/05 13:42:40 mckusick 2 1
c Add copyright
e
s 00005/00000/00000
d D 4.1 84/05/15 16:45:41 ralph 1 0
c date and time created 84/05/15 16:45:41 by ralph
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

char	_sibuf[BUFSIZ];
E 1
