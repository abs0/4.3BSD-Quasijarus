h28840
s 00010/00005/00025
d D 5.3 88/06/18 20:04:38 bostic 3 2
c install approved copyright notice
e
s 00009/00003/00021
d D 5.2 88/03/09 11:18:36 bostic 2 1
c Written by Ken Arnold; add Berkeley specific copyright
e
s 00024/00000/00000
d D 5.1 85/05/30 18:37:23 mckusick 1 0
c date and time created 85/05/30 18:37:23 by mckusick
e
u
U
t
T
I 1
/*
 * Copyright (c) 1980 Regents of the University of California.
D 2
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 2
I 2
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 3
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 3
I 3
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
E 3
E 2
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 2
#endif not lint
E 2
I 2
#endif /* not lint */
E 2

# include	<curses.h>

/*
 * flush_in:
 *	Flush all pending input.
 */
flush_in()
{
# ifdef TIOCFLUSH
	ioctl(fileno(stdin), TIOCFLUSH, NULL);
# else TIOCFLUSH
	crmode();
# endif TIOCFLUSH
}
E 1
