h36391
s 00015/00019/00130
d D 3.2 88/03/28 12:08:17 bostic 13 12
c add Berkeley specific headers
e
s 00000/00000/00149
d D 3.1 87/08/11 10:20:45 minshall 12 11
c New version numbering.
e
s 00025/00000/00124
d D 1.11 87/07/17 10:06:08 minshall 11 10
c Install sccs headers and copyright notices.
e
s 00000/00002/00124
d D 1.10 87/06/19 12:52:49 minshall 10 9
c Directory changes.
e
s 00002/00002/00124
d D 1.9 87/05/31 17:58:04 minshall 9 8
c Change 'bcmp' to 'memcmp'.
e
s 00037/00090/00089
d D 1.8 87/05/31 17:10:24 minshall 8 7
c Version without termcodes.m4.
e
s 00001/00001/00178
d D 1.7 87/05/31 10:53:05 minshall 7 6
c Fix dereference through null pointer problem.
e
s 00002/00002/00177
d D 1.6 87/05/22 09:52:09 minshall 6 5
c New directory structure.
e
s 00013/00005/00166
d D 1.5 87/05/12 14:10:44 minshall 5 4
c Various fixes for running under dos.
e
s 00002/00002/00169
d D 1.4 87/05/10 11:41:33 minshall 4 3
c Strings.h (sigh) and a small bug.
e
s 00017/00003/00154
d D 1.3 86/11/16 15:22:23 minshall 3 2
c Change FCN_... from #define's into enum's.
e
s 00063/00009/00094
d D 1.2 86/11/12 16:45:04 minshall 2 1
c This version of these things seems to work.
e
s 00103/00000/00000
d D 1.1 86/11/11 09:42:21 minshall 1 0
c date and time created 86/11/11 09:42:21 by minshall
e
u
U
t
T
I 11
/*
D 13
 *	Copyright (c) 1984-1987 by the Regents of the
 *	University of California and by Gregory Glenn Minshall.
E 13
I 13
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 13
 *
D 13
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
E 13
I 13
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 13
 */

#ifndef lint
D 13
static char sccsid[] = "%W% (Berkeley) %G%";
#endif	/* not lint */
E 13
I 13
char copyright[] =
"%Z% Copyright (c) 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */
E 13

I 13
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 13
E 11
I 1
D 8
/*
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
E 8

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

I 5
D 6
#include "../general.h"
E 6
I 6
#include "../general/general.h"
E 6
E 5
D 8
#define	LETS_SEE_ASCII
D 2
#include "../m4.out"
E 2
I 2
D 6
#include "../keyboard/m4.out"
E 6
I 6
#include "../ascii/m4.out"
E 6
E 2
#undef	LETS_SEE_ASCII

E 8
D 2
#include "../ascebc.h"
#include "../ebc_disp.h"
#include "../kbd3270.h"
E 2
I 2
D 10
#include "../ascii/ascebc.h"
#include "../ctlr/ebc_disp.h"
E 10
#include "../ctlr/function.h"
E 2

#include "dohits.h"

I 5
static struct tbl {
D 8
    char *shift;
    int	scancode;
E 8
I 8
    unsigned char
	scancode,
	used;
    char
	*shiftstate;
E 8
} tbl[128];
E 5

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
I 2
    int asciicode;
E 2
    int empty;
    int i;
I 2
    int c;
E 2
    int found;
    struct hits *ph;
    struct Hits *Ph;
D 8
    TC_Ascii_t *TC;
E 8
    struct thing *this;
I 8
    struct thing **attable;
E 8
I 2
D 5
    struct {
	char *shift;
	int	scancode;
    } tbl[128], *Pt;
E 5
I 5
    struct tbl *Pt;
E 5
D 8
    static char *shiftof[] = { "normal", "shifted", "alted", "shiftalted" };
E 8
I 8
    static char *shiftof[] =
	    { "0", "SHIFT_UPSHIFT", "SHIFT_ALT", "SHIFT_ALT|SHIFT_UPSHIFT" };
E 8
I 3
    char *aidfile = 0, *fcnfile = 0;
E 3
E 2

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
D 2
    printf("struct tctokbd {\n\tenum { cantdo, normal, shifted, alted,");
E 2
I 2
    printf("/*\n");
    printf(" * Ascii to scancode conversion table.  First\n");
    printf(" * 128 bytes (0-127) correspond with actual Ascii\n");
D 8
    printf(" * characters; the rest are TC types from termcodes.m4\n");
    printf(" * (actually, from m4.out).\n");
E 8
I 8
    printf(" * characters; the rest are functions from ctrl/function.h\n");
E 8
    printf(" */\n");
D 8
    printf("struct asctosc {\n");
    printf("\tenum shiftvalue { cantdo, normal, shifted, alted,");
E 2
    printf(" shiftalted } shift;\n\tunsigned char scancode;");
D 2
    printf("\n} tctokbd[] = {\n");
E 2
I 2
    printf("\n} asctosc[] = {\n");
E 8
    /* Build the ascii part of the table. */
    for (Ph = Hits, scancode = 0; Ph <= Hits+highestof(Hits);
							Ph++, scancode++) {
	ph = &Ph->hits;
	for (i = 0; i < 4; i++) {
D 3
	    if (ph->hit[i].type == character) {
E 3
I 3
	    if (ph->hit[i].ctlrfcn == FCN_CHARACTER) {
E 3
		c = Ph->name[i][0];	/* "name" of this one */
D 4
		if (tbl[c].shift[0] == 0) {
E 4
I 4
D 8
		if ((tbl[c].shift == 0) || (tbl[c].shift[0] == 0)) {
E 4
		    tbl[c].shift = shiftof[i];
E 8
I 8
		if (tbl[c].used == 0) {
		    tbl[c].used = 1;
		    tbl[c].shiftstate = shiftof[i];
E 8
		    tbl[c].scancode = scancode;
		}
	    }
	}
    }
    /* Now, output the table */
    for (Pt = tbl, asciicode = 0; Pt <= tbl+highestof(tbl); Pt++, asciicode++) {
D 7
	if (Pt->shift[0] == 0) {
E 7
I 7
D 8
	if ((Pt->shift == 0) || (Pt->shift[0] == 0)) {
E 8
I 8
	if (Pt->used == 0) {
E 8
E 7
	    if (isprint(asciicode) && (asciicode != ' ')) {
		fprintf(stderr, "Unable to produce scancode sequence for");
		fprintf(stderr, " ASCII character [%c]!\n", asciicode);
	    }
D 8
	    printf("\t{ cantdo, 0 },\t");
E 8
I 8
	    printf("\t{ 0, 0, undefined, 0 },\t");
E 8
	} else {
D 8
	    printf("\t{ %s, 0x%x },", Pt->shift, Pt->scancode);
E 8
I 8
	    printf("\t{ 0x%02x, %s, FCN_CHARACTER, 0 },",
					Pt->scancode, Pt->shiftstate);
E 8
	}
	printf("\t/* 0x%x", asciicode);
	if (isprint(asciicode)) {
	    printf(" [%c]", asciicode);
	}
	printf(" */\n");
    }
		

D 8
    for (TC = &TC_Ascii[TC_LOWEST-TC_LOWEST];
		TC < &TC_Ascii[TC_LOWEST_USER-TC_LOWEST]; TC++, asciicode++) {
	printf("\t{ cantdo, 0 },\t");
	printf("\t/* 0x%x */\n", asciicode);
    }
E 2
    for (TC = &TC_Ascii[TC_LOWEST_USER-TC_LOWEST];
D 2
		TC <= &TC_Ascii[TC_HIGHEST-TC_LOWEST]; TC++) {
E 2
I 2
		TC <= &TC_Ascii[TC_HIGHEST-TC_LOWEST]; TC++, asciicode++) {
E 2
	/* Hack for "PFK" names (which should be "PF") */
	if (memcmp(TC->tc_name, "PFK", 3) == 0) {
	    static char PFonly[100] = "PF";

	    strcpy(PFonly+2, TC->tc_name+3);
	    TC->tc_name = PFonly;
	}
	found = 0;
	for (this = firstentry(TC->tc_name); (!found) && this;
							this = this->next) {
	    if ((this->name[4] == TC->tc_name[0])
			&& (strcmp(this->name+4, TC->tc_name) == 0)) {
		/* this is the entry */
		/* What we have is a TC entry matching a scancode entry */
		Ph = this->hits;		/* now, get hits */
		if (Ph == 0) {
		    continue;
		}
		for (i = 0; i < 4; i++) {
		    if ((Ph->name[i][4] == TC->tc_name[0])
			    && (strcmp(Ph->name[i]+4, TC->tc_name) == 0)) {
			/* This is THE hit! */
			found = 1;
			printf("\t{ ");
			switch (i) {
			case 0:
			    printf("normal, ");
			    break;
			case 1:
			    printf("shifted, ");
			    break;
			case 2:
			    printf("alted, ");
			    break;
			case 3:
			    printf("shitfalted, ");
			    break;
			}
D 2
			printf("0x%x },\n", Ph-Hits);
E 2
I 2
			printf("0x%02x },", Ph-Hits);
			break;
E 8
I 8
    for (attable = &table[0]; attable <= &table[highestof(table)]; attable++) {
	for (this = *attable; this; this = this->next) {
	    Ph = this->hits;
	    if (Ph == 0) {
		continue;
	    }
	    for (i = 0; i < 4; i++) {
		if ((Ph->name[i] != 0) &&
			(Ph->name[i][0] == this->name[0]) &&
			(strcmp(Ph->name[i], this->name) == 0)) {
		    printf("\t{ 0x%02x, %s, ",
				Ph-Hits, shiftof[i]);
D 9
		    if (bcmp("AID_", this->name, 4) == 0) {	/* AID key */
E 9
I 9
		    if (memcmp("AID_", this->name, 4) == 0) {	/* AID key */
E 9
			printf("FCN_AID, ");
		    } else {
			printf("%s, ", Ph->name[i]);
E 8
E 2
		    }
I 8
D 9
		    if (bcmp("PF", this->name+4, 2) == 0) {
E 9
I 9
		    if (memcmp("PF", this->name+4, 2) == 0) {
E 9
			printf("\"PFK%s\" },\n", Ph->name[i]+4+2);
		    } else {
			printf("\"%s\" },\n", Ph->name[i]+4);
		    }
E 8
		}
	    }
	}
D 8
	if (!found) {
D 2
	    printf("\t{ cantdo, 0 },\n");
E 2
I 2
	    printf("\t{ cantdo, 0 },\t");
E 2
	    fprintf(stderr, "Unable to produce TC_%s with scan codes!\n",
				TC->tc_name);
	}
I 2
	printf("\t/* 0x%x - %s */\n", asciicode, TC->tc_name);
E 8
E 2
    }
D 8
    printf("};\n");
E 8
I 5

    return 0;
E 5
}
E 1
