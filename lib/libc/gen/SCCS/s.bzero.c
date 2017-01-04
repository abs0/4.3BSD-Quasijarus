h46357
s 00024/00000/00000
d D 5.1 87/01/27 16:02:47 mckusick 1 0
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
 * bzero -- vax movc5 instruction
 */
bzero(b, length)
	register char *b;
	register int length;
{

	if (length)
		do
			*b++ = '\0';
		while (--length);
	return(length);
}
E 1
