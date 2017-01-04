h20434
s 00017/00020/00371
d D 3.2 88/03/28 12:54:45 bostic 10 9
c add Berkeley specific header
e
s 00000/00000/00391
d D 3.1 87/08/11 10:18:19 minshall 9 8
c New version numbering.
e
s 00002/00002/00389
d D 1.8 87/07/17 10:02:15 minshall 8 7
c Install sccs headers and copyright notices.
e
s 00001/00001/00390
d D 1.7 87/07/15 15:25:05 minshall 7 6
c New directory structure
e
s 00001/00001/00390
d D 1.6 87/06/19 12:50:37 minshall 6 5
c directory changes.
e
s 00017/00004/00374
d D 1.5 87/06/08 09:13:51 minshall 5 4
c Incorporate an old (3.2, 86/12/18) fix from Steve Jacobson.
e
s 00006/00005/00372
d D 1.4 87/05/31 17:09:49 minshall 4 3
c Version without termcodes.m4.
e
s 00004/00004/00373
d D 1.3 87/05/22 09:53:32 minshall 3 2
c New directory structure.
e
s 00007/00002/00370
d D 1.2 87/05/12 14:08:35 minshall 2 1
c Remove curses.h, include strings.h or string.h depending on 
c the environment.
e
s 00372/00000/00000
d D 1.1 87/05/10 11:35:11 minshall 1 0
c date and time created 87/05/10 11:35:11 by minshall
e
u
U
t
T
I 1
/*
D 8
 *	Copyright (c) 1984, 1985, 1986 by the Regents of the
E 8
I 8
D 10
 *	Copyright (c) 1984-1987 by the Regents of the
E 8
 *	University of California and by Gregory Glenn Minshall.
E 10
I 10
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 10
 *
D 10
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
E 10
I 10
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
 */

D 10
#ifndef	lint
D 8
static	char	sccsid[] = "@(#)mset.c	3.1  10/29/86";
E 8
I 8
static	char	sccsid[] = "%W% (Berkeley) %G%";
E 8
#endif	/* ndef lint */
E 10
I 10
#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 10

/*
 * this program outputs the user's 3270 mapping table in a form suitable
 *	for inclusion in the environment.  Typically, this might be used
 *	by:
 *		setenv MAP3270 "`mset`"
 */

D 2
#include <curses.h>
E 2
I 2
#include <stdio.h>
#if	defined(unix)
E 2
#include <strings.h>
I 2
#else	/* defined(unix) */
#include <string.h>
#endif	/* defined(unix) */
I 4
#include "../ctlr/function.h"

E 4
E 2
D 3
#include "keyboard/state.h"
E 3
I 3
#include "state.h"
E 3
D 4
#define LETS_SEE_ASCII
D 3
#include "keyboard/m4.out"
E 3
I 3
#include "m4.out"
E 4
I 4
D 6
#include "astosc.h"
E 6
I 6
D 7
#include "../apilib/astosc.h"
E 7
I 7
#include "../api/astosc.h"
E 7
E 6
E 4
E 3

D 3
#include "../system/globals.h"
#include "keyboard/map3270.ext"
E 3
I 3
#include "../general/globals.h"
#include "map3270.ext"
E 3

struct regstate {
	char *result;
	char *match_start;
	char *match_end;		/* start of NEXT state's match string */
	struct regstate *forward;
	struct regstate *backward;
};

static struct regstate regstates[500], *rptr= 0;	/* for sorting states */
static char array[5000];		/* lot's of room */
static int toshell = 0;			/* export to shell */
static int numbchars = 0;		/* number of chars in envir. var */

I 5
static int
MyStrcmp(str1, str2)
char *str1, *str2;
{
	if (strncmp(str1, "PFK", 3) == 0 && strncmp(str2, "PFK", 3) == 0
	    && strlen(str1) != strlen(str2)) {
	   return(strlen(str1) - strlen(str2));
	}
	return(strcmp(str1, str2));
}

E 5
static void
forwRegister(regptr, sptr)
struct regstate *regptr, *sptr;
{

    regptr->forward = sptr->forward;
    regptr->backward = sptr;
    (sptr->forward)->backward = regptr;
    sptr->forward = regptr;
}

static void
backRegister(regptr, sptr)
struct regstate *regptr, *sptr;
{

    regptr->forward = sptr;
    regptr->backward = sptr->backward;
    (sptr->backward)->forward = regptr;
    sptr->backward = regptr;
}

static struct regstate *
doRegister(regptr)
register struct regstate *regptr;
{
    static struct regstate *pivot = regstates;
    register struct regstate *sptr = pivot;
    int check;

    if (pivot == regstates) {		/* first time called */
	pivot->forward = regptr;
	regptr->backward = pivot++;
	pivot->backward = regptr;
	regptr->forward = pivot++;
	return(++regptr);
    }
D 5
    if ((check = strcmp(regptr->result, pivot->result)) < 0) {
E 5
I 5
    if ((check = MyStrcmp(regptr->result, pivot->result)) < 0) {
E 5
	while (check < 0) {
	    if (sptr->backward == regstates) {
		backRegister(regptr, sptr);
		pivot = pivot->backward;
		return(++regptr);
	     }
	     sptr = sptr->backward;
D 5
	     check = strcmp(regptr->result, sptr->result);
E 5
I 5
	     check = MyStrcmp(regptr->result, sptr->result);
E 5
	}
	forwRegister(regptr, sptr);
	pivot = pivot->backward;
	return(++regptr);
    }
    while (check > 0) {
	if ((sptr->forward)->result == 0) {
	    forwRegister(regptr, sptr);
    	    pivot = pivot->forward;
	    return(++regptr);
	}
	sptr = sptr->forward;
D 5
	check = strcmp(regptr->result, sptr->result);
E 5
I 5
	check = MyStrcmp(regptr->result, sptr->result);
E 5
    }
    backRegister(regptr, sptr);
D 5
    pivot = pivot->forward;
E 5
I 5
    if (pivot->forward->result) {
	pivot = pivot->forward;
    }
E 5
    return(++regptr);
}

static char *
addString(strcount, character)
int strcount;
char character;
{
    static char *string = array;
    int i;

    if (rptr->match_start == 0) {
	rptr->match_start = string;
	for (i=0; i < strcount; i++) {
	    *string++ = *((rptr-1)->match_start+i);
	}
    }
    *string++ = character;
    return(string);
}

static char savename[20] = " ";  /* for deciding if name is new */

static void
printString(string, begin, tc_name)
register char *string;
char *begin, *tc_name;
{
    register char *st1, *st2;
    register int pchar;
    static char suffix = 'A';
    int new = strcmp(savename, tc_name);
    char delim = new ? ';' : '|';
I 2
    char *uncontrol();
E 2

    st1 = begin;

    numbchars += 5 + (new ? strlen(tc_name) : -1);
    if (toshell && numbchars > 1011) {
        new = 1;
	delim = ';';
        numbchars = 5 + strlen(tc_name);
        printf(";\nsetenv MAP3270%c ", suffix++);
    }
    if (strcmp(" ", savename)) {
	if (toshell) {
	   printf("%c%c", '\\', delim);
	}
	else {
	   printf("%c", delim);
	}
    }
    else {
	numbchars -= 2;
    }
    if (toshell && new) {
        printf("%s=%c'", tc_name,'\\');
    }
    else if (new) {
        printf("%s='", tc_name);
    }
    else if (toshell) {
	printf("%c'", '\\');
    }
    else {
	printf("'");
    }
    (void) strcpy(savename, tc_name);
    while (st1 != string) {
	if (toshell && numbchars >= 1016) { /* leave room for ctrl and delim */
	   numbchars = 0;
           printf(";\nsetenv MAP3270%c ", suffix++);
	}
	pchar = 0xff&(*st1++);
	switch (pchar) {
	case '"':
	case '!':
	case '$':
	case '(':
	case ')':
	case ' ':
	case ';':
	case '&':
	case '|':
	case '>':
	case '<':
	case '`':
	case '#':
	    numbchars += 2;
	    if (toshell) {
	       printf("%c%c", '\\', pchar);
	    }
	    else {
	       printf("%c", pchar);
	    }
	    break;
	case '\\':
	case '\'':
	    numbchars += 4;
	    if (toshell) {
	       printf("%c%c%c%c", '\\', '\\', '\\', pchar);
	    }
	    else {
	       printf("%c%c", '\\', pchar);
	    }
	    break;
	case '^':
	    numbchars += 3;
	    if (toshell) {
	       printf("%c%c%c", '\\', '\\', pchar);
	    }
	    else {
	       printf("%c%c", '\\', pchar);
	    }
	    break;
	default:
D 2
	    st2 = unctrl(pchar);
E 2
I 2
	    st2 = uncontrol(pchar);
E 2
	    while ((pchar = *st2++) != 0) {
		switch (pchar) {
		case '"':
		case '!':
		case '$':
		case '(':
		case ')':
		case ' ':
		case ';':
		case '&':
		case '|':
		case '>':
		case '<':
		case '`':
		case '#':
		case '\\':
		case '\'':
		   if (toshell) {
	    	      numbchars += 2; 
	    	      printf("%c%c", '\\', pchar);
		   }
		   else {
		      printf("%c", pchar);
		   }
		   break;
		default:
		   numbchars++;
	    	   printf("%c", pchar);
		   break;
		}
	    }
	    break;
	}
    }
    numbchars += 2;
    if (toshell) {
       printf("%c'", '\\');
    }
    else {
       printf("'");
    }
}

static void
recurse(strcount, head)
state *head;
int strcount;
{
		/*	if there is a left,
		 *	    recurse on left,
		 *	if there is no down,
		 *	    print the string to here
		 *	else,
		 *	     add the current match to the string,
		 *	     recurse.
		 *	exit.
		 */

    if (head->next) {
	recurse(strcount, head->next);
    }
D 4
    if (head->result != TC_GOTO) {
E 4
I 4
    if (head->result != STATE_GOTO) {
E 4
	rptr->match_end = addString(strcount, head->match);
D 4
	rptr->result = TC_Ascii[head->result - TC_LOWEST].tc_name;
E 4
I 4
	rptr->result = astosc[head->result].name;
E 4
	rptr = doRegister(rptr);
    } else {
	(void) addString(strcount, head->match);
	recurse(strcount+1, head->address);
	strcount--;
    }
    return;
}


main(argc, argv)
int argc;
char *argv[];
{
    state *head;
    char *keybdPointer = (char *) 0;
    char *commandName = argv[0];
    extern char *getenv();
    int picky = 0;

    while ((argc > 1) && (argv[1][0] == '-')) {
	if (!strcmp(argv[1], "-picky")) {
	    picky++;
	} else if (!strcmp(argv[1], "-shell")) {
	    toshell++;
	} else {
	    fprintf(stderr, "usage: %s [-picky] [-shell] [keyboardname]\n",
		commandName);
	    exit(1);
	    /*NOTREACHED*/
	}
	argv++;
	argc--;
    }
    if (argc == 2) {
        keybdPointer = argv[1];
    } else if (argc > 2) {
	fprintf(stderr, "usage: %s [-picky] [-shell] [keyboardname]\n",
		commandName);
	exit(1);
	/*NOTREACHED*/
    }
D 4
    head = InitControl(keybdPointer, picky);
E 4
I 4
    head = InitControl(keybdPointer, picky, ascii_to_index);
E 4
    if (!head) {
	return(1);
    }
    if (keybdPointer == 0) {
        keybdPointer = getenv("KEYBD");
    }
    if (keybdPointer == 0) {
	keybdPointer = getenv("TERM");
    }
    if (keybdPointer == 0) {
	keybdPointer = "3a";	/* use 3a as the terminal */
    }
    if (toshell) {
       printf("set noglob;\nsetenv MAP3270 ");
    }
    printf("%s{", keybdPointer);
    numbchars = 2 + strlen(keybdPointer);
    /* now, run through the table registering entries */
    rptr = regstates + 2;
    recurse(0, head);
    /* now print them out */
    for (rptr = regstates[0].forward; rptr->result != 0;
	 rptr = rptr->forward) { 
	printString(rptr->match_end, rptr->match_start, rptr->result);
    }
    if (toshell) {
       printf("%c;};\nunset noglob;\n", '\\');
    }
    else {
      printf(";}\n");
    }
    return(0);
}
E 1
