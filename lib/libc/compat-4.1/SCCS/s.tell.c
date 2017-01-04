h57012
s 00002/00002/00018
d D 5.2 86/03/09 19:24:04 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00010/00001/00010
d D 5.1 85/05/30 10:29:09 dist 2 1
c Add copyright
e
s 00011/00000/00000
d D 4.1 80/12/21 16:40:24 wnj 1 0
c date and time created 80/12/21 16:40:24 by wnj
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
 * Copyright (c) 1980 Regents of the University of California.
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
/*
 * return offset in file.
 */

long	lseek();

long tell(f)
{
	return(lseek(f, 0L, 1));
}
E 1
