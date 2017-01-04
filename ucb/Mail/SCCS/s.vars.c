h26664
s 00011/00005/00157
d D 5.4 88/02/18 17:04:33 bostic 10 9
c written by Kurt Shoens; added Berkeley specific header
e
s 00027/00033/00135
d D 5.3 87/05/18 12:28:41 edward 9 8
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00001/00001/00167
d D 5.2 85/06/21 17:14:47 mckusick 8 7
c botched copyright
e
s 00007/00001/00161
d D 5.1 85/06/06 10:45:40 dist 7 6
c Add copyright
e
s 00003/00003/00159
d D 2.5 83/08/11 22:20:36 sam 6 5
c standardize sccs keyword lines
e
s 00001/00001/00161
d D 2.4 83/05/26 10:47:15 ralph 5 4
c hash() could return negative values.
e
s 00002/00001/00160
d D 2.3 82/10/21 04:41:22 carl 4 3
c In vcopy(), check the return value of calloc() and panic when
c one runs out of core.
e
s 00004/00001/00157
d D 2.2 81/09/08 17:01:36 kurt 3 2
c fixed hashing algorithm to more machine independent
e
s 00000/00000/00158
d D 2.1 81/07/01 11:10:54 kurt 2 1
c Release to Heidi Stettner
e
s 00158/00000/00000
d D 1.1 80/10/08 09:52:24 kas 1 0
c date and time created 80/10/08 09:52:24 by kas
e
u
U
f b 
t
T
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
D 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
 */

E 7
I 1
D 6
#
E 6
I 6
D 10
#ifndef lint
D 8
static char sccsid[] = "%W% (Berkeley) %G%";
E 8
I 8
static char *sccsid = "%W% (Berkeley) %G%";
E 8
D 7
#endif
E 7
I 7
#endif not lint
E 10
I 10
#ifdef notdef
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* notdef */
E 10
E 7
E 6

#include "rcv.h"

/*
 * Mail -- a mail program
 *
 * Variable handling stuff.
 */
D 6

static char *SccsId = "%W% %G%";
E 6

/*
 * Assign a value to a variable.
 */

assign(name, value)
	char name[], value[];
{
	register struct var *vp;
	register int h;

	h = hash(name);
	vp = lookup(name);
	if (vp == NOVAR) {
		vp = (struct var *) calloc(sizeof *vp, 1);
		vp->v_name = vcopy(name);
		vp->v_link = variables[h];
		variables[h] = vp;
	}
	else
		vfree(vp->v_value);
	vp->v_value = vcopy(value);
}

/*
 * Free up a variable string.  We do not bother to allocate
 * strings whose value is "" since they are expected to be frequent.
 * Thus, we cannot free same!
 */

vfree(cp)
D 9
	register char *cp;
E 9
I 9
	char *cp;
E 9
{
D 9
	if (!equal(cp, ""))
		cfree(cp);
E 9
I 9
	if (*cp)
		free(cp);
E 9
}

/*
 * Copy a variable value into permanent (ie, not collected after each
 * command) space.  Do not bother to alloc space for ""
 */

char *
vcopy(str)
	char str[];
{
D 9
	register char *top, *cp, *cp2;
E 9
I 9
	char *new;
	unsigned len;
E 9

D 9
	if (equal(str, ""))
		return("");
D 4
	top = calloc(strlen(str)+1, 1);
E 4
I 4
	if ((top = calloc(strlen(str)+1, 1)) == NULL)
		panic ("Out of memory");
E 4
	cp = top;
	cp2 = str;
	while (*cp++ = *cp2++)
		;
	return(top);
E 9
I 9
	if (*str == '\0')
		return "";
	len = strlen(str) + 1;
	if ((new = malloc(len)) == NULL)
		panic("Out of memory");
	bcopy(str, new, (int) len);
	return new;
E 9
}

/*
 * Get the value of a variable and return it.
 * Look in the environment if its not available locally.
 */

char *
value(name)
	char name[];
{
	register struct var *vp;

	if ((vp = lookup(name)) == NOVAR)
		return(getenv(name));
	return(vp->v_value);
}

/*
 * Locate a variable and return its variable
 * node.
 */

struct var *
lookup(name)
D 9
	char name[];
E 9
I 9
	register char name[];
E 9
{
	register struct var *vp;
D 9
	register int h;
E 9

D 9
	h = hash(name);
	for (vp = variables[h]; vp != NOVAR; vp = vp->v_link)
		if (equal(vp->v_name, name))
E 9
I 9
	for (vp = variables[hash(name)]; vp != NOVAR; vp = vp->v_link)
		if (*vp->v_name == *name && equal(vp->v_name, name))
E 9
			return(vp);
	return(NOVAR);
}

/*
 * Locate a group name and return it.
 */

struct grouphead *
findgroup(name)
D 9
	char name[];
E 9
I 9
	register char name[];
E 9
{
	register struct grouphead *gh;
D 9
	register int h;
E 9

D 9
	h = hash(name);
	for (gh = groups[h]; gh != NOGRP; gh = gh->g_link)
		if (equal(gh->g_name, name))
E 9
I 9
	for (gh = groups[hash(name)]; gh != NOGRP; gh = gh->g_link)
		if (*gh->g_name == *name && equal(gh->g_name, name))
E 9
			return(gh);
	return(NOGRP);
}

/*
 * Print a group out on stdout
 */

printgroup(name)
	char name[];
{
	register struct grouphead *gh;
	register struct group *gp;

	if ((gh = findgroup(name)) == NOGRP) {
		printf("\"%s\": not a group\n", name);
		return;
	}
	printf("%s\t", gh->g_name);
	for (gp = gh->g_list; gp != NOGE; gp = gp->ge_link)
		printf(" %s", gp->ge_name);
D 9
	printf("\n");
E 9
I 9
	putchar('\n');
E 9
}

/*
 * Hash the passed string and return an index into
 * the variable or group hash table.
 */

hash(name)
D 9
	char name[];
E 9
I 9
	register char *name;
E 9
{
D 5
	register int h;
E 5
I 5
D 9
	register unsigned h;
E 5
	register char *cp;
E 9
I 9
	register h = 0;
E 9

D 9
	for (cp = name, h = 0; *cp; h = (h << 2) + *cp++)
		;
D 3
	h &= ~0100000;
E 3
I 3
	if (h < 0)
		h = -h;
	if (h < 0)
E 9
I 9
	while (*name) {
		h <<= 2;
		h += *name++;
	}
	if (h < 0 && (h = -h) < 0)
E 9
		h = 0;
E 3
D 9
	return(h % HSHSIZE);
E 9
I 9
	return (h % HSHSIZE);
E 9
}
E 1
