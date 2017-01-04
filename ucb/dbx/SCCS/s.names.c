h59844
s 00024/00029/00131
d D 5.2 88/01/12 00:58:11 donn 8 7
c merge in latest Linton version
e
s 00008/00002/00152
d D 5.1 85/05/31 10:07:40 dist 7 6
c Add copyright
e
s 00010/00022/00144
d D 1.5 85/03/01 20:26:00 linton 6 5
c update to version 3.0
e
s 00001/00003/00165
d D 1.4 84/06/23 11:41:56 sam 5 3
i 4
c merge linton branch delta trail
e
s 00003/00001/00165
d D 1.3.1.1 84/06/23 10:47:53 sam 4 3
c branch delta of linton changes from net.sources
e
s 00002/00003/00164
d D 1.3 83/02/16 23:07:34 linton 3 2
c changed allocation stuff to use bzero rather than have static 
c zero-filled structure around
e
s 00001/00001/00166
d D 1.2 82/12/15 04:21:04 linton 2 1
c fixed @(#) stuff
e
s 00167/00000/00000
d D 1.1 82/12/15 04:08:07 linton 1 0
c date and time created 82/12/15 04:08:07 by linton
e
u
U
f b 
t
T
I 1
D 7
/* Copyright (c) 1982 Regents of the University of California */
E 7
I 7
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 7

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 4
static char sccsid[] = "%Z%%M% %I% %G%";
E 4
I 4
D 5
static char sccsid[] = "@(#)names.c 1.3 2/16/83";

static char rcsid[] = "$Header: names.c,v 1.3 84/03/27 10:22:19 linton Exp $";
E 5
I 5
D 7
static	char sccsid[] = "%W% (Berkeley) %G%";
E 7
I 7
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 7
E 5
E 4
E 2

I 6
D 8
static char rcsid[] = "$Header: names.c,v 1.4 84/12/26 10:40:47 linton Exp $";
E 8
I 8
static char rcsid[] = "$Header: names.c,v 1.2 87/03/26 20:16:59 donn Exp $";
E 8

E 6
/*
 * Name are the internal representation for identifiers.
 *
 * A hash table is used to map identifiers to names.
 */

#include "defs.h"
#include "names.h"

#ifndef public
typedef struct Name *Name;

/*
 * Inline (for speed) function to return the identifier (string)
 * associated with a name.  Because C cannot support both inlines
 * and data hiding at the same time, the Name structure must be
 * publicly visible.  It is not used explicitly, however, outside of this file.
 */

struct Name {
    char *identifier;
    Name chain;
};

#define ident(n) ((n == nil) ? "(noname)" : n->identifier)
#endif

D 8
#define HASHTABLESIZE 2997
E 8
I 8
/*
 * The hash table is a power of two, in order to make hashing faster.
 * Using a non-prime is ok since we use chaining instead of re-hashing.
 */
E 8

I 8
#define HASHTABLESIZE 8192

E 8
private Name nametable[HASHTABLESIZE];

/*
 * Names are allocated in large chunks to avoid calls to malloc
 * and to cluster names in memory so that tracing hash chains
 * doesn't cause many a page fault.
 */

D 3
#define CHUNKSIZE 1000
E 3
I 3
D 8
#define CHUNKSIZE 200
E 8
I 8
#define CHUNKSIZE 1000
E 8
E 3

typedef struct Namepool {
    struct Name name[CHUNKSIZE];
    struct Namepool *prevpool;
} *Namepool;

private Namepool namepool = nil;
private Integer nleft = 0;
D 3
private struct Namepool zeropool;
E 3

/*
 * Given an identifier, convert it to a name.
 * If it's not in the hash table, then put it there.
 *
 * The second argument specifies whether the string should be copied
 * into newly allocated space if not found.
 *
D 8
 * Pardon my use of goto's, but it seemed more efficient and less convoluted
 * than adding a collection of boolean variables.  This routine is time
 * critical when starting up the debugger on large programs.
E 8
I 8
 * This routine is time critical when starting up the debugger
 * on large programs.
E 8
 */

public Name identname(s, isallocated)
String s;
Boolean isallocated;
{
    register unsigned h;
D 8
    register Char *p, *q;
    register Name n;
    register Integer len;
E 8
I 8
    register char *p, *q;
    register Name n, *np;
E 8
    Namepool newpool;

    h = 0;
    for (p = s; *p != '\0'; p++) {
	h = (h << 1) ^ (*p);
    }
D 8
    h = h mod HASHTABLESIZE;
    len = p - s;
    n = nametable[h];
E 8
I 8
    h &= (HASHTABLESIZE-1);
    np = &nametable[h];
    n = *np;
E 8
    while (n != nil) {
	p = s;
	q = n->identifier;
D 8
	for (;;) {
	    if (*p != *q) {
		goto nomatch;
	    } else if (*p == '\0') {
		goto match;
E 8
I 8
	while (*p == *q) {
	    if (*p == '\0') {
		return n;
E 8
	    }
	    ++p;
	    ++q;
	}
D 8
    nomatch:
E 8
	n = n->chain;
    }

    /*
D 8
     * Now we know that name hasn't been found (otherwise we'd have jumped
     * down to match), so we allocate a name, store the identifier, and
E 8
I 8
     * Now we know that name hasn't been found,
     * so we allocate a name, store the identifier, and
E 8
     * enter it in the hash table.
     */
    if (nleft <= 0) {
	newpool = new(Namepool);
D 3
	*newpool = zeropool;
E 3
I 3
D 8
	bzero(newpool, sizeof(newpool));
E 8
E 3
	newpool->prevpool = namepool;
	namepool = newpool;
	nleft = CHUNKSIZE;
    }
    --nleft;
    n = &(namepool->name[nleft]);
    if (isallocated) {
	n->identifier = s;
    } else {
D 8
	n->identifier = newarr(char, len + 1);
E 8
I 8
	/* this case doesn't happen very often */
	n->identifier = newarr(char, strlen(s) + 1);
E 8
	p = s;
	q = n->identifier;
	while (*p != '\0') {
	    *q++ = *p++;
	}
	*q = '\0';
    }
D 8
    n->chain = nametable[h];
    nametable[h] = n;

    /*
     * The two possibilities (name known versus unknown) rejoin.
     */
match:
E 8
I 8
    n->chain = *np;
    *np = n;
E 8
    return n;
}

/*
D 6
 * Return the identifier associated with a name.
 *
 * Currently compiled inline.
 *
 *
 * public String ident(n)
Name n;
{
    return (n == nil) ? "(noname)" : n->identifier;
}
 *
 */

/*
E 6
 * Deallocate the name table.
 */

public names_free()
{
D 6
    register int i;
    register Name n, next;
E 6
I 6
    Namepool n, m;
    register integer i;
E 6

I 6
    n = namepool;
    while (n != nil) {
	m = n->prevpool;
	dispose(n);
	n = m;
    }
E 6
    for (i = 0; i < HASHTABLESIZE; i++) {
D 6
	n = nametable[i];
	while (n != nil) {
	    next = n->chain;
	    dispose(n);
	    n = next;
	}
E 6
	nametable[i] = nil;
    }
    namepool = nil;
    nleft = 0;
}
E 1
