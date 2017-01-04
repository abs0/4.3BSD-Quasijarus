h05953
s 00002/00002/00150
d D 5.4 87/12/04 19:07:01 bostic 9 8
c old assignment operator
e
s 00002/00001/00150
d D 5.3 87/04/07 15:46:20 mckusick 8 7
c must allocate with proper alignment
e
s 00000/00006/00151
d D 5.2 86/11/11 18:32:22 mckusick 7 6
c delete unused function
e
s 00007/00003/00150
d D 5.1 85/06/05 14:59:33 dist 6 5
c Add copyright
e
s 00000/00000/00153
d D 2.1 84/02/08 20:43:16 aoki 5 4
c synchronize to version 2
e
s 00000/00000/00153
d D 1.4 83/09/19 07:01:14 thien 4 3
c Restoring to unlinted version
e
s 00004/00001/00149
d D 1.3 83/08/19 05:03:07 thien 3 2
c The changes were made to allow successful linting
e
s 00001/00001/00149
d D 1.2 80/11/24 18:59:45 peter 2 1
c malloc returns 0 on out of memory, not -1 as in version 6.
e
s 00150/00000/00000
d D 1.1 80/08/27 19:56:39 peter 1 0
c date and time created 80/08/27 19:56:39 by peter
e
u
U
t
T
I 1
D 6
/* Copyright (c) 1979 Regents of the University of California */
E 6
I 6
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 6

I 3
#ifndef lint
E 3
D 6
static	char sccsid[] = "%Z%%M% %I% %G%";
I 3
#endif
E 6
I 6
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 6
E 3

#include "whoami.h"
I 8
#include "align.h"
E 8
#include "0.h"
#ifndef PI01
#ifndef PXP
#include "send.h"
#endif
#endif

/*
 * STRING SPACE DECLARATIONS
 *
 * Strng is the base of the current
 * string space and strngp the
 * base of the free area therein.
 * Strp is the array of descriptors.
 */
#ifndef PI0
STATIC	char strings[STRINC];
STATIC	char *strng = strings;
STATIC	char *strngp = strings;
#else
char	*strng, *strngp;
#endif
#ifndef PI01
#ifndef PXP
STATIC	char *strp[20];
STATIC	char **stract strp;
int	strmax;
#endif
#endif

#ifndef PI01
#ifndef PXP
#ifndef PI0
initstring()
#else
initstring(strings)
	char *strings;
#endif
{

	*stract++ = strings;
#ifdef PI0
	strng = strngp = strings;
#endif
	strmax = STRINC * 2;
}
#endif
#endif

/*
 * Copy a string into the string area.
 */
char *
savestr(cp)
	register char *cp;
{
	register int i;

	i = strlen(cp) + 1;
	if (strngp + i >= strng + STRINC) {
		strngp = malloc(STRINC);
D 2
		if (strngp == -1) {
E 2
I 2
		if (strngp == 0) {
E 2
			yerror("Ran out of memory (string)");
			pexit(DIED);
		}
#ifndef PI01
#ifndef PXP
		*stract++ = strngp;
D 9
		strmax =+ STRINC;
E 9
I 9
		strmax += STRINC;
E 9
#endif
#endif
		strng = strngp;
	}
D 3
	strcpy(strngp, cp);
E 3
I 3
	(void) pstrcpy(strngp, cp);
E 3
	cp = strngp;
	strngp = cp + i;
#ifdef PI0
	send(RSTRING, cp);
#endif
	return (cp);
}

#ifndef PI1
#ifndef PXP
I 3
char *
E 3
esavestr(cp)
	char *cp;
{

#ifdef PI0
	send(REVENIT);
#endif
D 8
	strngp = ( (char *) ( ( (int) (strngp + 1) ) &~ 1 ) );
E 8
I 8
	strngp = ( (char *) roundup( strngp, A_LONG ) );
E 8
	return (savestr(cp));
}
#endif
#endif

#ifndef PI01
#ifndef PXP
soffset(cp)
	register char *cp;
{
	register char **sp;
	register int i;

	if (cp == NIL || cp == OCT || cp == HEX)
		return (-cp);
	for (i = STRINC, sp = strp; sp < stract; sp++) {
		if (cp >= *sp && cp < (*sp + STRINC))
			return (i + (cp - *sp));
D 9
		i =+ STRINC;
E 9
I 9
		i += STRINC;
E 9
	}
	i = nlfund(cp);
	if (i != 0)
		return (i);
	panic("soffset");
}
#ifdef PI1
sreloc(i)
	register int i;
{

	if (i == 0 || i == -OCT || i == -HEX)
		return (-i);
	if (i < STRINC) {
		if (i >= INL)
			panic("sreloc INL");
		i = nl[i].symbol;
		if (i == 0)
			panic("sreloc nl[i]");
		return (i);
	}
	if (i > strmax || i < 0)
		panic("sreloc");
	return (strp[(i / STRINC) - 1] + (i % STRINC));
}
D 7

evenit()
{

	strngp = (strngp + 1) &~ 1;
}
E 7
#endif
#endif
#endif
E 1
