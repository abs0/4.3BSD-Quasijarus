h55405
s 00002/00002/00016
d D 5.2 86/03/09 19:50:04 donn 4 3
c added LIBC_SCCS condition for sccs ids
e
s 00004/00001/00014
d D 5.1 85/06/05 12:26:43 mckusick 3 2
c Add copyright
e
s 00001/00001/00014
d D 4.2 84/05/16 10:50:36 ralph 2 1
c inline expand gtty (i.e. change gtty to ioctl).
e
s 00015/00000/00000
d D 4.1 80/12/21 16:39:45 wnj 1 0
c date and time created 80/12/21 16:39:45 by wnj
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
/*
 * Returns 1 iff file is a tty
 */

#include <sgtty.h>

isatty(f)
{
	struct sgttyb ttyb;

D 2
	if (gtty(f, &ttyb) < 0)
E 2
I 2
	if (ioctl(f, TIOCGETP, &ttyb) < 0)
E 2
		return(0);
	return(1);
}
E 1
