h48810
s 00026/00000/00000
d D 5.1 87/01/27 16:02:45 mckusick 1 0
c new addition for portability
e
u
U
t
T
I 1
/*
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "%W% (Berkeley) %G%";
#endif LIBC_SCCS and not lint

/*
 * bcmp -- vax cmpc3 instruction
 */
bcmp(b1, b2, length)
	register char *b1, *b2;
	register int length;
{

	if (length == 0)
		return (0);
	do
		if (*b1++ != *b2++)
			break;
	while (--length);
	return(length);
}
E 1
