h41078
s 00010/00021/00065
d D 3.2 88/03/28 13:46:46 bostic 7 6
c add Berkeley specific header
e
s 00000/00000/00086
d D 3.1 87/08/11 10:17:34 minshall 6 5
c New version numbering.
e
s 00025/00000/00061
d D 1.5 87/07/17 10:01:27 minshall 5 4
c Install sccs headers and copyright notices.
e
s 00001/00001/00060
d D 1.4 87/07/09 10:38:28 minshall 4 3
c Keep from dereferencing through a null pointer.
e
s 00003/00004/00058
d D 1.3 87/06/19 12:38:02 minshall 3 2
c Return "-1" on an error.
e
s 00036/00003/00026
d D 1.2 87/05/31 17:09:55 minshall 2 1
c Version without termcodes.m4.
e
s 00029/00000/00000
d D 1.1 87/05/31 14:34:17 minshall 1 0
c date and time created 87/05/31 14:34:17 by minshall
e
u
U
t
T
I 5
/*
D 7
 *	Copyright (c) 1984-1987 by the Regents of the
 *	University of California and by Gregory Glenn Minshall.
E 7
I 7
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 7
 *
D 7
 *	Permission to use, copy, modify, and distribute these
 *	programs and their documentation for any purpose and
 *	without fee is hereby granted, provided that this
 *	copyright and permission appear on all copies and
 *	supporting documentation, the name of the Regents of
 *	the University of California not be used in advertising
 *	or publicity pertaining to distribution of the programs
 *	without specific prior permission, and notice be given in
 *	supporting documentation that copying and distribution is
 *	by permission of the Regents of the University of California
 *	and by Gregory Glenn Minshall.  Neither the Regents of the
 *	University of California nor Gregory Glenn Minshall make
 *	representations about the suitability of this software
 *	for any purpose.  It is provided "as is" without
 *	express or implied warranty.
E 7
I 7
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *	%W% (Berkeley) %G%
E 7
 */
D 7

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif	/* not lint */
E 7

E 5
I 1
D 2
#include "astosc.h"
#include "state.h"
E 2
I 2
#include <ctype.h>
E 2

I 2
#include "../general/general.h"

E 2
#include "../ctlr/function.h"

I 2
#include "astosc.h"
D 3
#include "state.h"
E 3

E 2
struct astosc astosc[256] = {
#include "astosc.out"
};

I 2
/* compare two strings, ignoring case */
E 2

I 2
static
ustrcmp(string1, string2)
register char *string1;
register char *string2;
{
    register int c1, c2;

    while ((c1 = (unsigned char) *string1++) != 0) {
	if (isupper(c1)) {
	    c1 = tolower(c1);
	}
	if (isupper(c2 = (unsigned char) *string2++)) {
	    c2 = tolower(c2);
	}
	if (c1 < c2) {
	    return(-1);
	} else if (c1 > c2) {
	    return(1);
	}
    }
    if (*string2) {
	return(-1);
    } else {
	return(0);
    }
}


E 2
/*
 * This routine takes a string and returns an integer.  It may return
D 3
 * STATE_NULL if there is no other integer which corresponds to the
 * string.  STATE_NULL implies an error.
E 3
I 3
 * -1 if there is no other integer which corresponds to the
 * string.  -1 implies an error.
E 3
 */

int
ascii_to_index(string)
register char *string;
{
    register struct astosc *this;

    for (this = astosc; this <= &astosc[highestof(astosc)]; this++) {
D 2
	if ((this->name[0] == string[0]) && (strcmp(this->name, string) == 0)) {
E 2
I 2
D 4
	if (ustrcmp(this->name, string) == 0) {
E 4
I 4
	if ((this->name != 0) && (ustrcmp(this->name, string) == 0)) {
E 4
E 2
	    return this-astosc;
	}
    }
D 3
    return STATE_NULL;
E 3
I 3
    return -1;
E 3
}
E 1
