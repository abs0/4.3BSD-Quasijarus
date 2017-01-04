h39841
s 00009/00018/00265
d D 3.2 88/03/28 12:08:08 bostic 12 11
c add Berkeley specific headers
e
s 00000/00000/00283
d D 3.1 87/08/11 10:20:44 minshall 11 10
c New version numbering.
e
s 00025/00000/00258
d D 1.10 87/07/17 10:06:06 minshall 10 9
c Install sccs headers and copyright notices.
e
s 00002/00002/00256
d D 1.9 87/07/15 15:27:18 minshall 9 8
c New directory structure.
e
s 00003/00003/00255
d D 1.8 87/06/19 12:52:48 minshall 8 7
c Directory changes.
e
s 00001/00001/00257
d D 1.7 87/05/22 09:52:08 minshall 7 6
c New directory structure.
e
s 00005/00000/00253
d D 1.6 87/05/12 14:10:42 minshall 6 5
c Various fixes for running under dos.
e
s 00001/00001/00252
d D 1.5 87/05/10 11:41:31 minshall 5 4
c Strings.h (sigh) and a small bug.
e
s 00001/00001/00252
d D 1.4 86/11/16 20:42:30 minshall 4 3
c Fix "- =" (to "-=").
e
s 00049/00010/00204
d D 1.3 86/11/16 15:22:20 minshall 3 2
c Change FCN_... from #define's into enum's.
e
s 00026/00008/00188
d D 1.2 86/11/12 16:45:00 minshall 2 1
c This version of these things seems to work.
e
s 00196/00000/00000
d D 1.1 86/11/11 09:42:16 minshall 1 0
c date and time created 86/11/11 09:42:16 by minshall
e
u
U
t
T
I 1
/*
I 10
D 12
 *	Copyright (c) 1984-1987 by the Regents of the
 *	University of California and by Gregory Glenn Minshall.
E 12
I 12
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 12
 *
D 12
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
E 12
I 12
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 12
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 12
#endif	/* not lint */
E 12
I 12
#endif /* not lint */
E 12

/*
E 10
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
I 6
#if	defined(unix)
E 6
D 5
#include <string.h>
E 5
I 5
#include <strings.h>
I 6
#else	/* defined(unix) */
#include <string.h>
#endif	/* defined(unix) */
E 6
E 5
#include <ctype.h>
I 6
D 7
#include "../general.h"
E 7
I 7
#include "../general/general.h"
E 7
E 6
D 2
#include "../ascebc.h"
#include "../ebc_disp.h"
#include "../kbd3270.h"
E 2
I 2
D 8
#include "../ascii/ascebc.h"
#include "../ctlr/ebc_disp.h"
E 8
I 8
D 9
#include "../apilib/asc_ebc.h"
#include "../apilib/ebc_disp.h"
E 9
I 9
#include "../api/asc_ebc.h"
#include "../api/ebc_disp.h"
E 9
E 8
#include "../ctlr/function.h"
E 2

#include "dohits.h"

struct Hits Hits[256];		/* one for each of 0x00-0xff */

struct thing *table[100];

I 2
extern char *malloc();

E 2
unsigned int
dohash(seed, string)
unsigned int seed;
char *string;
{
    register unsigned int i = seed;
    register unsigned char c;

    while (c = *string++) {
	if (c >= 0x60) {
D 4
	    c - = (0x60+0x20);
E 4
I 4
	    c -= (0x60+0x20);
E 4
	} else {
	    c -= 0x20;
	}
	i = (i>>26) + (i<<6) + (c&0x3f);
    }
    return i;
}

void
add(first, second, value)
I 3
char *first, *second;
int value;
E 3
{
    struct thing **item, *this;

    item = &firstentry(second);
    this = (struct thing *) malloc(sizeof *this);
    this->next = *item;
    *item = this;
    this->value = value;
    strcpy(this->name, first);
    strcpy(this->name+strlen(this->name), second);
}

void
D 3
scan(file, prefix)
char *file,		/* Name of file to scan */
E 3
I 3
scanwhite(file, prefix)
char *file,		/* Name of file to scan for whitespace prefix */
E 3
     *prefix;		/* prefix of what should be picked up */
{
    FILE *ourfile;
    char compare[100];
    char what[100], value[100];
    char line[200];
I 3

    sprintf(compare, " %s%%[^,\t \n]", prefix);
    if ((ourfile = fopen(file, "r")) == NULL) {
	perror("fopen");
	exit(1);
    }
    while (!feof(ourfile)) {
	if (fscanf(ourfile, compare,  what) == 1) {
	    add(prefix, what, 0);
	}
	do {
	    if (fgets(line, sizeof line, ourfile) == NULL) {
		if (!feof(ourfile)) {
		    perror("fgets");
		}
		break;
	    }
	} while (line[strlen(line)-1] != '\n');
    }
}

void
scandefine(file, prefix)
char *file,		/* Name of file to scan for #define prefix */
     *prefix;		/* prefix of what should be picked up */
{
    FILE *ourfile;
    char compare[100];
    char what[100], value[100];
    char line[200];
E 3
    int whatitis;

    sprintf(compare, "#define %s%%s %%s", prefix);
    if ((ourfile = fopen(file, "r")) == NULL) {
	perror("fopen");
	exit(1);
    }
    while (!feof(ourfile)) {
	if (fscanf(ourfile, compare,  what, value) == 2) {
	    if (value[0] == '0') {
		if ((value[1] == 'x') || (value[1] == 'X')) {
		    sscanf(value, "0x%x", &whatitis);
		} else {
		    sscanf(value, "0%o", &whatitis);
		}
	    } else {
		sscanf(value, "%d", &whatitis);
	    }
	    add(prefix, what, whatitis);
	}
	do {
	    if (fgets(line, sizeof line, ourfile) == NULL) {
		if (!feof(ourfile)) {
		    perror("fgets");
		}
		break;
	    }
	} while (line[strlen(line)-1] != '\n');
    }
}

I 2
char *savechr(c)
unsigned char c;
{
    char *foo;
E 2

I 2
    foo = malloc(sizeof c);
    if (foo == 0) {
	fprintf(stderr, "No room for ascii characters!\n");
	exit(1);
    }
    *foo = c;
    return foo;
}

E 2
char *
doit(hit, type, hits)
struct hit *hit;
unsigned char *type;
struct Hits *hits;
{
    struct thing *this;

D 3
    hit->type = illegal;
E 3
I 3
    hit->ctlrfcn = FCN_NULL;
E 3
    if (type[0] == 0) {
	return 0;
    }
    if (type[1] == 0) {		/* character */
D 3
	hit->type = character;
E 3
I 3
	hit->ctlrfcn = FCN_CHARACTER;
E 3
D 8
	hit->code = ebc_disp[ascebc[AE_IN][type[0]]];
E 8
I 8
	hit->code = ebc_disp[asc_ebc[type[0]]];
E 8
I 2
	return savechr(*type);		/* The character is the name */
E 2
    } else {
	for (this = firstentry(type); this; this = this->next) {
	    if ((type[0] == this->name[4])
				&& (strcmp(type, this->name+4) == 0)) {
		this->hits = hits;
		if (this->name[0] == 'F') {
D 3
		    hit->type = function;
E 3
I 3
		    hit->ctlrfcn = FCN_NULL;	/* XXX */
E 3
		} else {
D 3
		    hit->type = aid;
E 3
I 3
		    hit->ctlrfcn = FCN_AID;
E 3
		}
		return this->name;
	    }
	}
D 2
	printf("Error: Unknown type %s.\n", type);
E 2
I 2
	fprintf(stderr, "Error: Unknown type %s.\n", type);
E 2
	return 0;
    }
}


void
D 3
dohits()
E 3
I 3
dohits(aidfile, fcnfile)
char	*aidfile, *fcnfile;
E 3
{
    unsigned char plain[100], shifted[100], alted[100], shiftalted[100];
    unsigned char line[200];
    int keynumber, scancode;
    int empty;
    int i;
    struct hit *hit;
    struct hits *ph;
    struct Hits *Ph;

    memset((char *)Hits, 0, sizeof Hits);

    /*
     * First, we read "host3270.h" to find the names/values of
     * various AID; then we read kbd3270.h to find the names/values
     * of various FCNs.
     */

D 2
    scan("host3270.h", "AID_");
    scan("kbd3270.h", "FCN_");
E 2
I 2
D 3
    scan("../ctlr/hostctlr.h", "AID_");
    scan("../ctlr/function.h", "FCN_");
E 3
I 3
    if (aidfile == 0) {
	aidfile = "../ctlr/hostctlr.h";
    }
    scandefine(aidfile, "AID_");
    if (fcnfile == 0) {
        fcnfile = "../ctlr/function.h";
    }
    scanwhite(fcnfile, "FCN_");
E 3
E 2

    while (gets(line) != NULL) {
	if (!isdigit(line[0])) {
	    continue;
	}
	plain[0] = shifted[0] = alted[0] = shiftalted[0] = 0;
	keynumber = -1;
	scancode = -1;
	(void) sscanf(line, "%d %x %s %s %s %s", &keynumber,
		    &scancode, plain, shifted, alted, shiftalted);
	if ((keynumber == -1) || (scancode == -1)
		|| ((plain[0] == 0)
		    && (shifted[0] == 0)
		    && (alted[0] == 0)
		    && (shiftalted[0] == 0))) {
	    continue;
	}
	if (scancode >= 256) {
D 2
	    printf("Error: scancode 0x%02x for keynumber %d\n", scancode,
E 2
I 2
	    fprintf(stderr,
		"Error: scancode 0x%02x for keynumber %d\n", scancode,
E 2
		    keynumber);
	    break;
	}
D 3
	if (Hits[scancode].hits.hit[0].type != undefined) {
E 3
I 3
	if (Hits[scancode].hits.hit[0].ctlrfcn != undefined) {
E 3
D 2
	    printf("Error: duplicate scancode 0x%02x for keynumber %d\n",
E 2
I 2
	    fprintf(stderr,
		"Error: duplicate scancode 0x%02x for keynumber %d\n",
E 2
		    scancode, keynumber);
	    break;
	}
	hit = Hits[scancode].hits.hit;
	Hits[scancode].hits.keynumber = keynumber;
	Hits[scancode].name[0] = doit(hit, plain, &Hits[scancode]);
	Hits[scancode].name[1] = doit(hit+1, shifted, &Hits[scancode]);
	Hits[scancode].name[2] = doit(hit+2, alted, &Hits[scancode]);
	Hits[scancode].name[3] = doit(hit+3, shiftalted, &Hits[scancode]);
    }
}
E 1
