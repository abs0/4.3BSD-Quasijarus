h37041
s 00010/00005/00075
d D 5.2 88/06/19 14:11:29 bostic 4 3
c install approved copyright notice
e
s 00011/00005/00069
d D 5.1 88/05/08 15:49:54 bostic 3 2
c add Berkeley header; yank to 5.1
e
s 00006/00000/00068
d D 1.2 85/04/24 15:32:26 edward 2 1
c copyright messages
e
s 00068/00000/00000
d D 1.1 84/11/18 18:59:17 edward 1 0
c date and time created 84/11/18 18:59:17 by edward
e
u
U
t
T
I 2
/*
D 3
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 3
I 3
 * Copyright (c) 1983 Regents of the University of California.
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

E 2
I 1
#ifndef lint
D 3
static char sccsid[] = "%W% %G%";
#endif
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 3

#include "externs.h"

wordinit()
{
	register struct wlist *w;

	for (w = wlist; w->string; w++)
		install(w);
}

hash(s)
	register char *s;
{
	register hashval = 0;

	while (*s) {
		hashval += *s++;
		hashval *= HASHMUL;
		hashval &= HASHMASK;
	}
	return hashval;
}

struct wlist *
lookup(s)
	char *s;
{
	register struct wlist *wp;

	for (wp = hashtab[hash(s)]; wp != NULL; wp = wp->next)
		if (*s == *wp->string && strcmp(s, wp->string) == 0)
			return wp;
	return NULL;
}

install(wp)
	register struct wlist *wp;
{
	int hashval;

	if (lookup(wp->string) == NULL) {
		hashval = hash(wp->string);
		wp->next = hashtab[hashval];
		hashtab[hashval] = wp;
	} else
		printf("Multiply defined %s.\n", wp->string);
}

parse()
{
	register struct wlist *wp;
	register n;

	wordnumber = 0;           /* for cypher */
	for (n = 0; n <= wordcount; n++) {
		if ((wp = lookup(words[n])) == NULL) {
			wordvalue[n] = -1;
			wordtype[n] = -1;
		} else {
			wordvalue[n] = wp -> value;
			wordtype[n] = wp -> article;
		}
	}
}
E 1
