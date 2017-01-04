h61464
s 00010/00005/00034
d D 5.3 88/06/30 17:21:46 bostic 5 4
c install approved copyright notice
e
s 00010/00004/00029
d D 5.2 88/06/08 13:57:22 bostic 4 3
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00001/00023
d D 5.1 85/06/07 11:35:29 dist 3 2
c Add copyright
e
s 00004/00005/00020
d D 1.2 85/05/01 17:18:19 bloom 2 1
c new version from arnold
e
s 00025/00000/00000
d D 1.1 81/01/26 17:02:59 arnold 1 0
c date and time created 81/01/26 17:02:59 by arnold
e
u
U
t
T
I 3
/*
D 4
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
I 4
 * Copyright (c) 1981 Regents of the University of California.
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

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif not lint
E 4
I 4
#endif /* not lint */
E 4

E 3
I 1
# define	reg	register

/*
 *	This routine fills in "def" with the long name of the terminal.
 *
D 2
 * %G% (Berkeley) %W%
E 2
I 2
D 3
 * %W% (Berkeley) %G%
E 3
E 2
 */
char *
longname(bp, def)
reg char	*bp, *def; {

	reg char	*cp;

	while (*bp && *bp != ':' && *bp != '|')
		bp++;
	if (*bp == '|') {
		bp++;
D 2
		cp = bp;
		while (*cp && *cp != ':' && *cp != '|')
			cp++;
E 2
I 2
		cp = def;
		while (*bp && *bp != ':' && *bp != '|')
			*cp++ = *bp++;
E 2
		*cp = 0;
D 2
		return bp;
E 2
	}
	return def;
}
E 1
