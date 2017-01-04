h65370
s 00015/00018/00111
d D 3.2 88/03/28 12:08:22 bostic 9 8
c add Berkeley specific headers
e
s 00000/00000/00129
d D 3.1 87/08/11 10:20:48 minshall 8 7
c New version numbering.
e
s 00025/00000/00104
d D 1.7 87/07/17 10:06:11 minshall 7 6
c Install sccs headers and copyright notices.
e
s 00000/00002/00104
d D 1.6 87/06/19 12:52:51 minshall 6 5
c Directory changes.
e
s 00006/00001/00100
d D 1.5 87/05/12 14:10:47 minshall 5 4
c Various fixes for running under dos.
e
s 00001/00001/00100
d D 1.4 87/05/10 11:41:35 minshall 4 3
c Strings.h (sigh) and a small bug.
e
s 00036/00017/00065
d D 1.3 86/11/16 15:22:22 minshall 3 2
c Change FCN_... from #define's into enum's.
e
s 00003/00003/00079
d D 1.2 86/11/12 16:45:02 minshall 2 1
c This version of these things seems to work.
e
s 00082/00000/00000
d D 1.1 86/11/11 09:42:19 minshall 1 0
c date and time created 86/11/11 09:42:19 by minshall
e
u
U
t
T
I 1
/*
I 7
D 9
 *	Copyright (c) 1984-1987 by the Regents of the
 *	University of California and by Gregory Glenn Minshall.
E 9
I 9
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 9
 *
D 9
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
E 9
I 9
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
 */

#ifndef lint
I 9
char copyright[] =
"%Z% Copyright (c) 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
E 9
static char sccsid[] = "%W% (Berkeley) %G%";
D 9
#endif	/* not lint */
E 9
I 9
#endif /* not lint */
E 9

/*
E 7
 * This program scans a file which describes a keyboard.  The output
 * of the program is a series of 'C' declarations which describe a
 * mapping between (scancode, shiftstate, altstate) and 3270 functions,
 * characters, and AIDs.
 *
 * The format of the input file is as follows:
 *
 * keynumber [ scancode [ unshifted [ shifted [ alted [ shiftalted ] ] ] ] ]
 *
 * keynumber is in decimal, and starts in column 1.
 * scancode is hexadecimal.
 * unshifted, etc. - these are either a single ascii character,
 *			or the name of a function or an AID-generating key.
 *
 * all fields are separated by a single space.
 */

#include <stdio.h>
I 5
#if	defined(unix)
E 5
D 4
#include <string.h>
E 4
I 4
#include <strings.h>
I 5
#else	/* defined(unix) */
#include <string.h>
#endif	/* defined(unix) */
E 5
E 4
#include <ctype.h>
D 2
#include "../ascebc.h"
#include "../ebc_disp.h"
#include "../kbd3270.h"
E 2
I 2
D 6
#include "../ascii/ascebc.h"
#include "../ctlr/ebc_disp.h"
E 6
#include "../ctlr/function.h"
E 2

#include "dohits.h"


D 5
void
E 5
I 5
int
E 5
D 3
main()
E 3
I 3
main(argc, argv)
int	argc;
char	*argv[];
E 3
{
    int scancode;
    int empty;
    int i;
    struct hits *ph;
    struct Hits *Ph;
I 3
    char *aidfile = 0, *fcnfile = 0;
E 3

D 3
    dohits();		/* Set up "Hits" */
E 3
I 3
    if (argc > 1) {
	if (argv[1][0] != '-') {
	    aidfile = argv[1];
	}
    }
    if (argc > 2) {
	if (argv[2][0] != '-') {
	    fcnfile = argv[2];
	}
    }
E 3

I 3
    dohits(aidfile, fcnfile);		/* Set up "Hits" */

E 3
    printf("struct hits hits[] = {\n");
    empty = 0;
    scancode = -1;
    for (Ph = Hits; Ph < Hits+(sizeof Hits/sizeof Hits[0]); Ph++) {
	ph = &Ph->hits;
	scancode++;
D 3
	if ((ph->hit[0].type == undefined)
		&& (ph->hit[1].type == undefined)
		&& (ph->hit[2].type == undefined)
		&& (ph->hit[3].type == undefined)) {
E 3
I 3
	if ((ph->hit[0].ctlrfcn == undefined)
		&& (ph->hit[1].ctlrfcn == undefined)
		&& (ph->hit[2].ctlrfcn == undefined)
		&& (ph->hit[3].ctlrfcn == undefined)) {
E 3
	    empty++;
	    continue;
	} else {
	    while (empty) {
D 3
		printf("\t{ 0, {\t{ illegal },\t{ illegal }");
		printf(",\t{ illegal },\t{ illegal } } },\n");
E 3
I 3
		printf("\t{ 0, {  {undefined}, {undefined}");
		printf(", {undefined}, {undefined}  } },\n");
E 3
		empty--;
	    }
	}
	printf("\t{ %d, {\t/* 0x%02x */\n\t", ph->keynumber, scancode);
	for (i = 0; i < 4; i++) {
	    printf("\t{ ");
D 3
	    switch (ph->hit[i].type) {
E 3
I 3
	    switch (ph->hit[i].ctlrfcn) {
E 3
	    case undefined:
D 3
	    case illegal:
		printf("illegal");
E 3
I 3
		printf("undefined");
E 3
		break;
D 3
	    case character:
		printf("character, 0x%02x", ph->hit[i].code);
E 3
I 3
	    case FCN_CHARACTER:
		printf("FCN_CHARACTER, 0x%02x", ph->hit[i].code);
E 3
		break;
D 3
	    case function:
		printf("function, %s", Ph->name[i]);
E 3
I 3
	    case FCN_AID:
		printf("FCN_AID, %s", Ph->name[i]);
E 3
		break;
D 3
	    case aid:
		printf("aid, %s", Ph->name[i]);
E 3
I 3
	    case FCN_NULL:
	    default:
		if ((Ph->name[i] != 0)
				    && (strcmp(Ph->name[i], "FCN_NULL") != 0)) {
		    printf("%s", Ph->name[i]);
		} else {
		    printf("undefined");
		}
E 3
		break;
	    }
	    printf(" },\n\t");
	}
	printf("} },\n");
    }
    printf("};\n");
I 5
    return 0;
E 5
}
E 1
