h42494
s 00010/00005/00065
d D 5.4 88/06/29 19:23:24 bostic 6 5
c install approved copyright notice
e
s 00009/00003/00061
d D 5.3 88/05/05 17:50:24 bostic 5 4
c add Berkeley specific header; written by K. McKusick and P. Kessler
e
s 00004/00000/00060
d D 5.2 87/04/27 17:30:45 mckusick 4 3
c add -k to allow selective deletion of arcs
e
s 00008/00002/00052
d D 5.1 85/06/04 13:30:33 dist 3 2
c Add copyright
e
s 00023/00047/00031
d D 1.2 82/06/18 20:21:37 peter 2 1
c -e -E -f and -F flags, this time for sure.
e
s 00078/00000/00000
d D 1.1 82/06/14 18:09:52 peter 1 0
c date and time created 82/06/14 18:09:52 by peter
e
u
U
t
T
I 3
/*
 * Copyright (c) 1983 Regents of the University of California.
D 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
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
E 6
E 5
 */

E 3
I 1
#ifndef lint
D 3
    static	char *sccsid = "%W% (Berkeley) %G%";
#endif lint
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5
E 3

#include "gprof.h"

D 2
struct stringlist {
    struct stringlist	*next;
    char		*string;
};
E 2
I 2
    /*
     *	these are the lists of names:
     *	there is the list head and then the listname
     *	is a pointer to the list head
     *	(for ease of passing to stringlist functions).
     */
I 4
struct stringlist	kfromhead = { 0 , 0 };
struct stringlist	*kfromlist = &kfromhead;
struct stringlist	ktohead = { 0 , 0 };
struct stringlist	*ktolist = &ktohead;
E 4
struct stringlist	fhead = { 0 , 0 };
struct stringlist	*flist = &fhead;
struct stringlist	Fhead = { 0 , 0 };
struct stringlist	*Flist = &Fhead;
struct stringlist	ehead = { 0 , 0 };
struct stringlist	*elist = &ehead;
struct stringlist	Ehead = { 0 , 0 };
struct stringlist	*Elist = &Ehead;
E 2

D 2
struct stringlist	fflaglist = { 0 , 0 };

addflist( funcname )
    char	*funcname;
E 2
I 2
addlist( listp , funcname )
    struct stringlist	*listp;
    char		*funcname;
E 2
{
    struct stringlist	*slp;

    slp = (struct stringlist *) malloc( sizeof(struct stringlist));
    if ( slp == (struct stringlist *) 0 ) {
	fprintf( stderr, "gprof: ran out room for printlist\n" );
	done();
    }
D 2
    slp -> next = fflaglist.next;
E 2
I 2
    slp -> next = listp -> next;
E 2
    slp -> string = funcname;
D 2
    fflaglist.next = slp;
E 2
I 2
    listp -> next = slp;
E 2
}

bool
D 2
onflist( funcname )
    char	*funcname;
E 2
I 2
onlist( listp , funcname )
    struct stringlist	*listp;
    char		*funcname;
E 2
{
    struct stringlist	*slp;

D 2
    for ( slp = fflaglist.next ; slp ; slp = slp -> next ) {
	if ( ! strcmp( slp -> string , funcname ) ) {
	    return TRUE;
	}
	if ( funcname[0] == '_' && ! strcmp( slp -> string , &funcname[1] ) ) {
	    return TRUE;
	}
    }
    return FALSE;
}

struct stringlist	eflaglist = { 0 , 0 };

addelist( funcname )
    char	*funcname;
{
    struct stringlist	*slp;

    slp = (struct stringlist *) malloc( sizeof(struct stringlist));
    if ( slp == (struct stringlist *) 0 ) {
	fprintf( stderr, "gprof: ran out room for printlist\n" );
	done();
    }
    slp -> next = eflaglist.next;
    slp -> string = funcname;
    eflaglist.next = slp;
}

bool
onelist( funcname )
    char	*funcname;
{
    struct stringlist	*slp;

    for ( slp = eflaglist.next ; slp ; slp = slp -> next ) {
E 2
I 2
    for ( slp = listp -> next ; slp ; slp = slp -> next ) {
E 2
	if ( ! strcmp( slp -> string , funcname ) ) {
	    return TRUE;
	}
	if ( funcname[0] == '_' && ! strcmp( slp -> string , &funcname[1] ) ) {
	    return TRUE;
	}
    }
    return FALSE;
}
E 1
