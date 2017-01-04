h57716
s 00014/00003/00021
d D 5.2 88/06/27 18:03:48 bostic 2 1
c written by Kirk McKusick; add Berkeley specific copyright
e
s 00024/00000/00000
d D 5.1 87/01/27 16:02:48 mckusick 1 0
c new addition for portability
e
u
U
t
T
I 1
/*
 * Copyright (c) 1987 Regents of the University of California.
D 2
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 2
I 2
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
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
E 2
 */

#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "%W% (Berkeley) %G%";
D 2
#endif LIBC_SCCS and not lint
E 2
I 2
#endif /* LIBC_SCCS and not lint */
E 2

/*
 * ffs -- vax ffs instruction
 */
ffs(mask)
	register long mask;
{
	register int cnt;

	if (mask == 0)
		return(0);
	for (cnt = 1; !(mask & 1); cnt++)
		mask >>= 1;
	return(cnt);
}
E 1
