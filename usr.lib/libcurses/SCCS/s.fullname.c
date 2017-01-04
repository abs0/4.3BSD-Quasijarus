h63467
s 00010/00005/00039
d D 5.3 88/06/30 17:21:35 bostic 4 3
c install approved copyright notice
e
s 00010/00004/00034
d D 5.2 88/06/08 13:57:08 bostic 3 2
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00001/00028
d D 5.1 85/06/07 11:31:49 dist 2 1
c Add copyright
e
s 00029/00000/00000
d D 1.1 85/05/01 18:17:37 bloom 1 0
c date and time created 85/05/01 18:17:37 by bloom
e
u
U
t
T
I 2
/*
D 3
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
I 3
 * Copyright (c) 1981 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 4
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
I 4
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
E 4
E 3
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
#endif /* not lint */
E 3

E 2
I 1
# define	reg	register

/*
 *	This routine fills in "def" with the full name of the terminal.
 * This is assumed to be the last name in the list of aliases.
 *
D 2
 * %W% (Berkeley) %G%
E 2
 */
char *
fullname(bp, def)
reg char	*bp, *def;
{

	reg char	*cp;

	*def = 0;			/* in case no name */

	while (*bp && *bp != ':') {
		cp = def;		/* start of answer */
		while (*bp && *bp != ':' && *bp != '|') {
			*cp++ = *bp++;	/* copy name over */
		}
		*cp = 0;		/* zero end of name */
		if (*bp == '|') {
			bp++;		/* skip over '|' if that is case */
		}
	}
	return(def);
}
E 1
