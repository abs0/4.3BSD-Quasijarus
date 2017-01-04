h16459
s 00011/00005/00084
d D 5.5 88/02/18 17:04:26 bostic 9 8
c written by Kurt Shoens; added Berkeley specific header
e
s 00000/00000/00089
d D 5.4 87/05/18 12:28:49 edward 8 7
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00002/00002/00087
d D 5.3 86/12/12 12:41:55 bostic 7 5
c fixed allocation alignment for Power 6.
e
s 00001/00001/00088
d D 5.2 85/06/21 17:14:19 mckusick 5 4
c botched copyright
e
s 00007/00001/00082
d D 5.1 85/06/06 10:44:00 dist 4 3
c Add copyright
e
s 00003/00003/00080
d D 2.2 83/08/11 22:20:12 sam 3 2
c standardize sccs keyword lines
e
s 00000/00000/00083
d D 2.1 81/07/01 11:10:29 kurt 2 1
c Release to Heidi Stettner
e
s 00083/00000/00000
d D 1.1 80/10/08 09:51:24 kas 1 0
c date and time created 80/10/08 09:51:24 by kas
e
u
U
f b 
t
T
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
D 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 9
I 9
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
 */

E 4
I 1
D 3
#
E 3
I 3
D 9
#ifndef lint
D 5
static char sccsid[] = "%W% (Berkeley) %G%";
E 5
I 5
static char *sccsid = "%W% (Berkeley) %G%";
E 5
D 4
#endif
E 4
I 4
#endif not lint
E 9
I 9
#ifdef notdef
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* notdef */
E 9
E 4
E 3

/*
 * Mail -- a mail program
 *
 * String allocation routines.
 * Strings handed out here are reclaimed at the top of the command
 * loop each time, so they need not be freed.
 */

#include "rcv.h"
D 3

static char *SccsId = "%W% %G%";
E 3

/*
 * Allocate size more bytes of space and return the address of the
 * first byte to the caller.  An even number of bytes are always
 * allocated so that the space will always be on a word boundary.
 * The string spaces are of exponentially increasing size, to satisfy
 * the occasional user with enormous string size requests.
 */

char *
salloc(size)
{
	register char *t;
	register int s;
	register struct strings *sp;
	int index;

	s = size;
D 7
	s++;
	s &= ~01;
E 7
I 7
	s += 3;
	s &= ~03;
E 7
	index = 0;
	for (sp = &stringdope[0]; sp < &stringdope[NSPACE]; sp++) {
		if (sp->s_topFree == NOSTR && (STRINGSIZE << index) >= s)
			break;
		if (sp->s_nleft >= s)
			break;
		index++;
	}
	if (sp >= &stringdope[NSPACE])
		panic("String too large");
	if (sp->s_topFree == NOSTR) {
		index = sp - &stringdope[0];
		sp->s_topFree = (char *) calloc(STRINGSIZE << index,
		    (unsigned) 1);
		if (sp->s_topFree == NOSTR) {
			fprintf(stderr, "No room for space %d\n", index);
			panic("Internal error");
		}
		sp->s_nextFree = sp->s_topFree;
		sp->s_nleft = STRINGSIZE << index;
	}
	sp->s_nleft -= s;
	t = sp->s_nextFree;
	sp->s_nextFree += s;
	return(t);
}

/*
 * Reset the string area to be empty.
 * Called to free all strings allocated
 * since last reset.
 */

sreset()
{
	register struct strings *sp;
	register int index;

	if (noreset)
		return;
	minit();
	index = 0;
	for (sp = &stringdope[0]; sp < &stringdope[NSPACE]; sp++) {
		if (sp->s_topFree == NOSTR)
			continue;
		sp->s_nextFree = sp->s_topFree;
		sp->s_nleft = STRINGSIZE << index;
		index++;
	}
}
E 1
