h39335
s 00015/00018/00584
d D 3.3 88/03/28 12:08:27 bostic 11 10
c add Berkeley specific headers
e
s 00005/00005/00597
d D 3.2 87/08/31 15:33:24 minshall 10 9
c Fix bug on non-vaxen (with scanf and %c).
e
s 00000/00000/00602
d D 3.1 87/08/11 10:20:41 minshall 9 8
c New version numbering.
e
s 00023/00003/00579
d D 1.8 87/07/17 10:06:02 minshall 8 7
c Install sccs headers and copyright notices.
e
s 00002/00002/00580
d D 1.7 87/07/15 15:27:15 minshall 7 6
c New directory structure.
e
s 00003/00003/00579
d D 1.6 87/06/19 12:52:46 minshall 6 5
c Directory changes.
e
s 00031/00010/00551
d D 1.5 87/06/08 08:47:53 minshall 5 4
c Convert to work without termcodes.m4 (== m4.out).
e
s 00003/00003/00558
d D 1.4 87/05/22 09:52:05 minshall 4 3
c New directory structure.
e
s 00005/00004/00556
d D 1.3 87/05/12 14:10:40 minshall 3 2
c Various fixes for running under dos.
e
s 00001/00000/00559
d D 1.2 87/04/01 16:13:40 minshall 2 1
c Fix for long lines.
e
s 00559/00000/00000
d D 1.1 86/11/12 16:44:18 minshall 1 0
c date and time created 86/11/12 16:44:18 by minshall
e
u
U
t
T
I 1
D 8
#ifndef	lint
static	char	sccsid[] = "@(#)prt3270.c	3.1  10/29/86";
#endif	/* ndef lint */
E 8
I 8
/*
D 11
 *	Copyright (c) 1984-1987 by the Regents of the
 *	University of California and by Gregory Glenn Minshall.
E 11
I 11
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 11
 *
D 11
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
E 11
I 11
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
 */
E 8

I 8
#ifndef lint
I 11
char copyright[] =
"%Z% Copyright (c) 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
E 11
static char sccsid[] = "%W% (Berkeley) %G%";
D 11
#endif	/* not lint */
E 11
I 11
#endif /* not lint */
E 11
E 8

#if defined(unix)
#endif
#include <stdio.h>
D 3
#include <curses.h>
E 3
#include <ctype.h>

I 3
D 4
#include "../general.h"
E 4
I 4
#include "../general/general.h"
E 4

E 3
D 6
#include "../ascii/ascebc.h"
E 6
I 6
D 7
#include "../apilib/asc_ebc.h"
E 7
I 7
#include "../api/asc_ebc.h"
E 7
E 6
#include "../ctlr/hostctlr.h"
#include "../ctlr/screen.h"
D 5
#define	DEFINEAIDS
#define	LETS_SEE_ASCII
D 4
#include "../keyboard/m4.out"
#include "../system/globals.h"
E 4
I 4
#include "../ascii/m4.out"
E 5
I 5
#include "../ctlr/function.h"
D 6
#include "../ascii/astosc.h"
E 6
I 6
D 7
#include "../apilib/astosc.h"
E 7
I 7
#include "../api/astosc.h"
E 7
E 6
E 5
#include "../general/globals.h"
E 4

I 5
#include "../ctlr/kbd.out"
E 5

I 5

E 5
int NumberColumns = 80;

int direction;

int column = 1;
int indenting = 0;
int direction = '?';

unsigned char printBuffer[200], *print = printBuffer;

#define	ColsLeft()	(79-column)	/* A little room for error */


void
putSpace()
{
    extern void Column1();
    unsigned char *ourPrint = print;

    print = printBuffer;		/* For mutual calls */
    *ourPrint = 0;
    if (ColsLeft() < 0) {
	Column1();
    }
    if (column != (indenting*8+1)) {
	putchar(' ');
    } else {
	int i;

	putchar(direction);
	putchar(' ');
	for (i = 0; i < indenting; i++) {
	    putchar('\t');
	}
    }
    printf("%s", printBuffer);
    column += strlen(printBuffer);
}

void
Column1()
{
    if (print != printBuffer) {
	putSpace();
    }
    if (column != (indenting*8+1)) {
	putchar('\n');
	column = indenting*8+1;
    }
}

void
Indent()
{
    if ((column != (indenting*8+1)) || (print != printBuffer)) {
	Column1();
    }
    indenting++;
    column = indenting*8+1;
}

void
Undent()
{
    if ((column != (indenting*8+1)) || (print != printBuffer)) {
	Column1();
    }
    indenting--;
    if (indenting < 0) {
	fflush(stdout);
	fprintf(stderr, "INTERNAL ERROR: indenting < 0.\n");
	fflush(stderr);
    } else {
	column = indenting*8+1;
    }
}

void
putChar(character)
int	character;
{
    *print++ = character;
I 2
    column++;
E 2
}

void
putstr(s)
char *s;
{
    while (*s) {
	putChar(*s++);
    }
}

void
put2hex(i)
int i;
{
    char place[40];

    sprintf(place, "%02x", i);
    putstr(place);
}


void
putdecimal(i)
int i;
{
    char place[40];

    sprintf(place, "%d", i);
    putstr(place);
}

void
puthex(i)
int i;
{
    char place[40];

    sprintf(place, "%x", i);
    putstr(place);
}

void
putEChar(character)
int character;
{
D 6
    putChar(ebcasc[0][character]);
E 6
I 6
    putChar(ebc_asc[character]);
E 6
    if (ColsLeft() < 10) {
	Column1();
    }
}

void
PrintAid(i)
int	i;
{
D 5
    TC_AsciiAids_t *TC;
E 5
I 5
    struct astosc *this;
E 5

D 5
    for (TC = &TC_AsciiAids[TC_LOWEST_AID-TC_LOWEST];
		TC <= &TC_AsciiAids[TC_HIGHEST_AID-TC_LOWEST]; TC++) {
	if ((TC->tc_aid&0xff) == i) {
	    putstr(TC->tc_name);
	    return;
E 5
I 5
    for (this = &astosc[0]; this <= &astosc[highestof(astosc)]; this++) {
	if (this->function == FCN_AID) {
	    int j;

	    switch (this->shiftstate) {
	    case 0:
		j = 0;
		break;
	    case SHIFT_UPSHIFT:
		j = 1;
		break;
	    case SHIFT_ALT:
		j = 2;
		break;
	    case (SHIFT_UPSHIFT|SHIFT_ALT):
		j = 3;
		break;
	    default:
		fprintf(stderr, "Bad shiftstate 0x%x.\n", this->shiftstate);
		exit(1);
	    }
	    if (hits[this->scancode].hit[j].code == i) {
		putstr(this->name);
		return;
	    }
E 5
	}
    }

    putstr("Unknown AID 0x");
    put2hex(i);
}

void
PrintAddr(i)
int	i;
{
    if (ColsLeft() < 9) {
	Column1();
    }
    putChar('(');
    putdecimal(ScreenLine(i));
    putChar(',');
    putdecimal(ScreenLineOffset(i));
    putChar(')');
}


/* returns the number of characters consumed */
int
DataFromNetwork(buffer, count, control)
register unsigned char	*buffer;		/* what the data is */
register int	count;				/* and how much there is */
int	control;				/* this buffer ended block? */
{
    int origCount;
    register int c;
    register int i;
    static int Command;
    static int Wcc;
    static int	LastWasTerminated = 1;	/* was "control" = 1 last time? */

    if (count == 0) {
	Column1();
	return 0;
    }

    origCount = count;

    if (LastWasTerminated) {

	if (count < 2) {
	    if (count == 0) {
		fflush(stdout);
		fprintf(stderr, "Short count received from host!\n");
		fflush(stderr);
		return(count);
	    }
	    Command = buffer[0];
	    switch (Command) {		/* This had better be a read command */
	    case CMD_READ_MODIFIED:
		putstr("read_modified command\n");
		break;
	    case CMD_SNA_READ_MODIFIED:
D 10
		putstr("read_modified command\n");
E 10
I 10
		putstr("sna_read_modified command\n");
E 10
		break;
	    case CMD_SNA_READ_MODIFIED_ALL:
D 10
		putstr("read_modified command\n");
E 10
I 10
		putstr("sna_read_modified_all command\n");
E 10
		break;
	    case CMD_READ_BUFFER:
D 10
		putstr("read_modified command\n");
E 10
I 10
		putstr("read_buffer command\n");
E 10
		break;
	    case CMD_SNA_READ_BUFFER:
D 10
		putstr("read_modified command\n");
E 10
I 10
		putstr("sna_read_buffer command\n");
E 10
		break;
	    default:
		break;
	    }
	    return(1);			/* We consumed everything */
	}
	Command = buffer[0];
	Wcc = buffer[1];
	switch (Command) {
	case CMD_ERASE_WRITE:
	    putstr("erase write command ");
	    break;
	case CMD_ERASE_WRITE_ALTERNATE:
	    putstr("erase write alternate command ");
	    break;
	case CMD_SNA_ERASE_WRITE:
	    putstr("sna erase write command ");
	    break;
	case CMD_SNA_ERASE_WRITE_ALTERNATE:
	    putstr("erase write alternate command ");
	    break;
	case CMD_ERASE_ALL_UNPROTECTED:
	    putstr("erase all unprotected command ");
	    break;
	case CMD_SNA_ERASE_ALL_UNPROTECTED:
	    putstr("sna erase write command ");
	    break;
	case CMD_WRITE:
	    putstr("write command ");
	    break;
	case CMD_SNA_WRITE:
	    putstr("sna write command ");
	    break;
	default:
	    putstr("Unexpected command code 0x");
	    puthex(Command);
	    putstr(" received.");
	    Column1();
	    break;
	}
	putstr("WCC is 0x");
	puthex(Wcc);
	Column1();

	count -= 2;			/* strip off command and wcc */
	buffer += 2;

    }
    LastWasTerminated = 0;		/* then, reset at end... */

    while (count) {
	count--;
	c = *buffer++;
	if (IsOrder(c)) {
	    /* handle an order */
	    switch (c) {
#		define Ensure(x)	if (count < x) { \
					    if (!control) { \
						return(origCount-(count+1)); \
					    } else { \
						/* XXX - should not occur */ \
						count = 0; \
						break; \
					    } \
					}
	    case ORDER_SF:
		Ensure(1);
		c = *buffer++;
		count--;
		putstr("SF (0x");
		put2hex(c);
		putstr(") ");
		break;
	    case ORDER_SBA:
		Ensure(2);
		i = buffer[0];
		c = buffer[1];
		buffer += 2;
		count -= 2;
		putstr("SBA to ");
		PrintAddr(Addr3270(i,c));
		putSpace();
		break;
	    case ORDER_IC:
		putstr("IC");
		putSpace();
		break;
	    case ORDER_PT:
		putstr("PT");
		putSpace();
		break;
	    case ORDER_RA:
		Ensure(3);
		i = Addr3270(buffer[0], buffer[1]);
		c = buffer[2];
		buffer += 3;
		count -= 3;
		putstr("RA to ");
		PrintAddr(i);
		putstr(" of 0x");
		put2hex(c);
		putSpace();
		break;
	    case ORDER_EUA:    /* (from [here,there), ie: half open interval] */
		Ensure(2);
		putstr("EUA to ");
		PrintAddr(Addr3270(buffer[0], buffer[1]));
		putSpace();
		buffer += 2;
		count -= 2;
		break;
	    case ORDER_YALE:		/* special YALE defined order */
		Ensure(2);	/* need at least two characters */
		putstr("YALE order");
		putSpace();
		break;
	    default:
		putstr("UNKNOWN ORDER: 0x");
		put2hex(c);
		putSpace();
		break;
	    }
	    if (count < 0) {
		count = 0;
	    }
	} else {
	    /* Data comes in large clumps - take it all */
	    putstr("DATA:");
	    Indent();
	    putEChar(c);
	    c = *buffer;
	    while (count && !IsOrder(c)) {
		putEChar(c);
		count--;
		buffer++;
		c = *buffer;
	    }
	    Undent();
	}
    }
    LastWasTerminated = control;
    return origCount - count;
}

int
DataToNetwork(buffer, count, control)
unsigned char *buffer;
int count;
int control;
{
#define	NEED_AID	0
#define	JUST_GOT_AID	1
#define	DATA		2
#define	DATA_CONTINUE	3
    static int state = NEED_AID;
    static int aid;
    int origCount = count;

    if (count == 0) {
	if (control) {
	    state = NEED_AID;
	}
	Column1();
	return 0;
    }

    switch (state) {
    case NEED_AID:
	aid = buffer[0];
	buffer++;
	count--;
	PrintAid(aid);
	putSpace();
D 5
	if (aid == TCtoAid(TC_TREQ)) {
E 5
I 5
	if (aid == AID_TREQ) {
E 5
	    state = DATA;
	} else {
	    state = JUST_GOT_AID;
	}
	return origCount - count + DataToNetwork(buffer, count, control);
    case JUST_GOT_AID:
	Ensure(2);
	PrintAddr(Addr3270(buffer[0], buffer[1]));
	putSpace();
	buffer += 2;
	count -= 2;
	state = DATA;
	return origCount - count + DataToNetwork(buffer, count, control);
    case DATA:
    case DATA_CONTINUE:
	while (count) {
	    if (*buffer == ORDER_SBA) {
		if (state == DATA_CONTINUE) {
		    Undent();
		    state = DATA;
		}
		putstr("SBA ");
		PrintAddr(Addr3270(buffer[1], buffer[2]));
		putSpace();
		buffer += 3;
		count -= 3;
	    } else {
		if (state == DATA) {
		    putstr("DATA:");
		    Indent();
		    state = DATA_CONTINUE;
		}
		putEChar(*buffer);
		buffer++;
		count--;
	    }
	}
	if (control) {
	    if (state == DATA_CONTINUE) {
		Undent();
	    }
	    state = NEED_AID;
	}
	return origCount-count;
    }
}

int
GetXValue(c)
int	c;
{
    if (!isascii(c)) {
	fflush(stdout);
	fprintf(stderr, "Non-hex digit 0x%x.\n");
	fflush(stderr);
	return 0;
    } else {
	if (islower(c)) {
	    return (c-'a')+10;
	} else if (isupper(c)) {
	    return (c-'A')+10;
	} else {
	    return c-'0';
	}
    }
}

unsigned char outbound[8192], inbound[8192],
	*outnext = outbound, *innext = inbound, *p = 0;

void
termblock(old, new, control)
int old,
	new;		/* old and new directions */
{
    int count;

    if (p) {
	if (old == '<') {
	    outnext = p;
	    count = DataFromNetwork(outbound, outnext-outbound, control);
	    if (outbound+count == outnext) {
		outnext = outbound;
	    } else {
D 3
		bcopy(outbound+count, outbound, outnext-(outbound+count));
E 3
I 3
		memcpy(outbound, outbound+count, outnext-(outbound+count));
E 3
		outnext = outbound+count;
	    }
	} else {
	    innext = p;
	    count = DataToNetwork(inbound, innext-inbound, control);
	    if (inbound+count == innext) {
		innext = inbound;
	    } else {
D 3
		bcopy(inbound+count, inbound, innext-(inbound+count));
E 3
I 3
		memcpy(inbound, inbound+count, innext-(inbound+count));
E 3
		innext = inbound+count;
	    }
	}
    }
    if (new == '<') {
	p = outnext;
    } else if (new == '>') {
	p = innext;
    } else {
	fprintf(stderr, "Bad direction character '%c'.\n", new);
	exit(1);
    }
}

main()
{
    int location;
D 10
    int new;
E 10
I 10
    char new;
E 10
    int c, c1;

D 3
    bzero(Orders, sizeof Orders);
E 3
I 3
    memset(Orders, 0, sizeof Orders);
E 3
    Orders[ORDER_SF] = Orders[ORDER_SBA] = Orders[ORDER_IC]
	    = Orders[ORDER_PT] = Orders[ORDER_RA] = Orders[ORDER_EUA]
	    = Orders[ORDER_YALE] = 1;

    while (scanf("%c 0x%x\t", &new, &location) != EOF) {
	if (new != direction) {
	    termblock(direction, new, 0);
	    direction = new;
	}
	while (((c = getchar()) != EOF) && (c != '\n') && (isxdigit(c))) {
#define	NORMAL	0
#define	GOT0XFF	0xff
	    static int state = NORMAL;

	    c1 = getchar();
	    c = (GetXValue(c) << 4) + GetXValue(c1);
	    switch (state) {
	    case NORMAL:
		if (c == 0xff) {
		    state = GOT0XFF;
		} else {
		    *p++ = c;
		}
		break;
	    case GOT0XFF:
		if (c == 0xef) {
		    termblock(direction, direction, 1);
		} else {
		    *p++ = 0xff;
		    *p++ = c;
		}
		state = NORMAL;
	    }
	}
    }
    return 0;
}
E 1
