h56409
s 00010/00005/00034
d D 5.3 88/06/18 15:08:20 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00030
d D 5.2 88/05/05 18:34:44 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00026
d D 5.1 85/05/30 09:04:09 dist 3 2
c Add copyright
e
s 00002/00002/00025
d D 4.2 83/05/09 21:57:59 layer 2 1
c use /bin/csh instead of /bin/sh
e
s 00027/00000/00000
d D 4.1 83/03/23 15:01:28 mckusick 1 0
c date and time created 83/03/23 15:01:28 by mckusick
e
u
U
t
T
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
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

E 3
I 1
#ifndef lint
D 3
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
E 3
D 4
#endif not lint
E 4
I 4
#endif /* not lint */
E 4

/*
**  CALL THE SHELL
*/

shell()
{
	int		i;
	register int	pid;
	register int	sav2, sav3;

	if (!(pid = fork()))
	{
		setuid(getuid());
		nice(0);
D 2
		execl("/bin/sh", "-", 0);
		syserr("cannot execute /bin/sh");
E 2
I 2
		execl("/bin/csh", "-", 0);
		syserr("cannot execute /bin/csh");
E 2
	}
	sav2 = signal(2, 1);
	sav3 = signal(3, 1);
	while (wait(&i) != pid) ;
	signal(2, sav2);
	signal(3, sav3);
}
E 1
