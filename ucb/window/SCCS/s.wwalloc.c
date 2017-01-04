h10889
s 00010/00005/00042
d D 3.9 88/06/29 21:37:20 bostic 9 8
c install approved copyright notice
e
s 00013/00007/00034
d D 3.8 88/02/21 13:37:59 bostic 8 7
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00035
d D 3.7 85/04/24 16:15:58 edward 7 6
c copyright messages
e
s 00001/00001/00034
d D 3.6 84/05/23 01:58:29 edward 6 5
c new sccs id
e
s 00006/00006/00029
d D 3.5 83/09/15 10:09:32 edward 5 4
c Now uses screen address for all buffers.
e
s 00003/00001/00032
d D 3.4 83/08/26 16:26:32 edward 4 3
c error reporting
e
s 00013/00016/00020
d D 3.3 83/08/19 12:21:37 edward 3 2
c call malloc only once per wwalloc
c and wwfree doesn't need the nrow argument anymore.
e
s 00000/00000/00036
d D 3.2 83/08/11 17:23:52 edward 2 1
i
c last few day's work
e
s 00036/00000/00000
d D 3.1 83/08/09 18:37:46 edward 1 0
c date and time created 83/08/09 18:37:46 by edward
e
u
U
t
T
I 1
D 8
#ifndef lint
D 6
static	char *sccsid = "%W% %E%";
E 6
I 6
static char sccsid[] = "%W% %G%";
E 6
#endif

E 8
I 7
/*
D 8
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 8
I 8
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 8
 */
I 8

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 8

E 7
#include "ww.h"

char **
D 5
wwalloc(nrow, ncol, size)
I 3
int nrow, ncol, size;
E 5
I 5
wwalloc(row, col, nrow, ncol, size)
E 5
E 3
{
D 3
	register char **p;
E 3
I 3
	register char *p, **pp;
E 3
	register int i;

D 3
	p = (char **) malloc((unsigned) nrow * sizeof (char *));
	if (p == 0)
E 3
I 3
	/* fast, call malloc only once */
	pp = (char **)
		malloc((unsigned) sizeof (char **) * nrow + size * nrow * ncol);
D 4
	if (pp == 0)
E 4
I 4
	if (pp == 0) {
		wwerrno = WWE_NOMEM;
E 4
E 3
		return 0;
I 4
	}
E 4
I 3
	p = (char *)&pp[nrow];
I 5
	col *= size;
E 5
	size /= sizeof (char);		/* paranoid */
	size *= ncol;
E 3
	for (i = 0; i < nrow; i++) {
D 3
		p[i] = malloc((unsigned) ncol * size);
		if (p[i] == 0) {
			wwfree(p, i);
			return 0;
		}
E 3
I 3
D 5
		pp[i] = p;
E 5
I 5
		pp[i] = p - col;
E 5
		p += size;
E 3
	}
D 3
	return p;
E 3
I 3
D 5
	return pp;
E 5
I 5
	return pp - row;
E 5
E 3
}

D 3
wwfree(p, nrow)
E 3
I 3
D 5
wwfree(p)
E 5
I 5
wwfree(p, row)
E 5
E 3
register char **p;
{
D 3
	register int i;

	if (p == 0)
		return;
	for (i = 0; i < nrow; i++)
		free(p[i]);
E 3
D 5
	free((char *)p);
E 5
I 5
	free((char *)(p + row));
E 5
}
E 1
