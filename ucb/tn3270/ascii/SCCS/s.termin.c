h40852
s 00011/00020/00246
d D 3.2 88/03/28 12:54:51 bostic 15 14
c add Berkeley specific header
e
s 00000/00000/00266
d D 3.1 87/08/11 10:18:22 minshall 14 13
c New version numbering.
e
s 00001/00001/00265
d D 1.13 87/07/29 15:45:26 minshall 13 12
c Fix bug when transparent input and more than one character in
c an input buffer.
e
s 00002/00002/00264
d D 1.12 87/07/17 10:02:18 minshall 12 11
c Install sccs headers and copyright notices.
e
s 00001/00001/00265
d D 1.11 87/07/15 15:25:07 minshall 11 10
c New directory structure
e
s 00035/00001/00231
d D 1.10 87/07/15 14:13:32 minshall 10 9
c Make transparent input/output work.
e
s 00001/00001/00231
d D 1.9 87/06/19 12:50:39 minshall 9 8
c directory changes.
e
s 00001/00001/00231
d D 1.8 87/06/18 12:32:49 minshall 8 7
c Fix infinite loop when 1 bad character comes in.
e
s 00002/00001/00230
d D 1.7 87/06/08 09:57:15 minshall 7 6
c On unknown input sequence, flush input.
e
s 00008/00006/00223
d D 1.6 87/06/08 09:15:17 minshall 6 5
c Fix a bug when data from terminal not accepted by AcceptKeystroke.
e
s 00037/00058/00192
d D 1.5 87/05/31 17:09:53 minshall 5 4
c Version without termcodes.m4.
e
s 00002/00002/00248
d D 1.4 87/05/22 09:53:35 minshall 4 3
c New directory structure.
e
s 00015/00007/00235
d D 1.3 87/04/01 14:40:01 minshall 3 2
c Make close/open sequences work in a more rational way.
e
s 00081/00020/00161
d D 1.2 86/12/19 17:09:32 minshall 2 1
c Seems to work with 'close' followed by 'open'.
e
s 00181/00000/00000
d D 1.1 86/12/19 17:09:04 minshall 1 0
c date and time created 86/12/19 17:09:04 by minshall
e
u
U
t
T
I 1
/*
D 12
 *	Copyright (c) 1984, 1985, 1986 by the Regents of the
E 12
I 12
D 15
 *	Copyright (c) 1984-1987 by the Regents of the
E 12
 *	University of California and by Gregory Glenn Minshall.
E 15
I 15
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 15
 *
D 15
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
E 15
I 15
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 15
 */

D 15
#ifndef	lint
D 12
static	char	sccsid[] = "@(#)termin.c	3.1  10/29/86";
E 12
I 12
static	char	sccsid[] = "%W% (Berkeley) %G%";
E 12
#endif	/* ndef lint */
E 15
I 15
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 15

/* this takes characters from the keyboard, and produces 3270 keystroke
	codes
 */

I 2
#include <stdio.h>
E 2
#include <ctype.h>

I 2
D 4
#include "../general.h"
E 4
I 4
#include "../general/general.h"
E 4
E 2
D 5
#include "m4.out"		/* output of termcodes.m4 */
#include "state.h"

D 2
#include "globals.h"
#include "inbound.ext"
#include "outbound.ext"
#include "telnet.ext"
E 2
I 2
D 4
#include "../system/globals.h"
E 4
I 4
#include "../general/globals.h"
E 5
E 4
#include "../ctlr/function.h"
#include "../ctlr/inbound.ext"
#include "../ctlr/outbound.ext"
#include "../telnet.ext"
E 2
#include "termin.ext"

I 5
D 9
#include "astosc.h"
E 9
I 9
D 11
#include "../apilib/astosc.h"
E 11
I 11
#include "../api/astosc.h"
E 11
E 9
#include "state.h"

#include "../general/globals.h"

E 5
#define IsControl(c)	(!isprint(c) || (isspace(c) && ((c) != ' ')))

#define NextState(x)	(x->next)

/* XXX temporary - hard code in the state table */

#define MATCH_ANY 0xff			/* actually, match any character */

I 2
D 5
#include "astosc.out"
E 5
E 2

D 5
static char
E 5
I 5
static unsigned char
E 5
	ourBuffer[100],		/* where we store stuff */
	*ourPHead = ourBuffer,	/* first character in buffer */
D 10
	*ourPTail = ourBuffer;	/* where next character goes */
E 10
I 10
	*ourPTail = ourBuffer,	/* where next character goes */
	*TransPointer = 0;	/* For transparent mode data */
E 10

I 2
static int InControl;
static int WaitingForSynch;

I 5
static struct astosc
	*spacePTR = 0;		/* Space is hard to enter */

E 5
E 2
static state
	*headOfControl = 0;	/* where we enter code state table */

D 2
#define FullChar	(ourPTail == ourBuffer+sizeof ourBuffer)
E 2
I 2
#define FullChar	((ourPTail+5) >= ourBuffer+sizeof ourBuffer)
E 2
#define EmptyChar	(ourPTail == ourPHead)


I 2
/*
I 3
 * init_keyboard()
 *
 * Initialize the keyboard variables.
 */

void
init_keyboard()
{
    ourPHead = ourPTail = ourBuffer;
    InControl = 0;
    WaitingForSynch = 0;
}


/*
E 3
 * Initialize the keyboard mapping file.
 */

void
InitMapping()
{
    extern state *InitControl();
I 5
    register struct astosc *ptr;
E 5

    if (!headOfControl) {
	/* need to initialize */
D 5
	headOfControl = InitControl((char *)0, 0);
E 5
I 5
	headOfControl = InitControl((char *)0, 0, ascii_to_index);
E 5
	if (!headOfControl) {		/* should not occur */
	    quit();
	}
I 5
	for (ptr = &astosc[0]; ptr <= &astosc[highestof(astosc)]; ptr++) {
	    if (ptr->function == FCN_SPACE) {
		spacePTR = ptr;
	    }
	}
E 5
    }
}


E 2
D 5
/* AddChar - put a character in our buffer */
E 5
I 5
/* AddChar - put a function index in our buffer */
E 5

static void
AddChar(c)
int	c;
{
    if (!FullChar) {
D 2
	*ourPTail++ = (char) c;
E 2
I 2
D 5
	if ((c >= numberof(asctosc)) || (c < 0)) {
	    ExitString(stderr,
		    "Unable to locate function in termout.c, AddChar()\n", 1);
	    /*NOTREACHED*/
	} else {
	    switch (asctosc[c].shift) {
	    case cantdo:
		if (c == ' ') {
		    *ourPTail++ = asctosc[TC_SPACE].scancode;
		} else {
		    RingBell("Keyboard not capable of function.");
		}
		break;
	    case normal:
		*ourPTail++ = asctosc[c].scancode;
		break;
	    case shifted:
		*ourPTail++ = asctosc[TC_MAKE_SHIFT].scancode;
		*ourPTail++ = asctosc[c].scancode;
		*ourPTail++ = asctosc[TC_BREAK_SHIFT].scancode;
		break;
	    case alted:
		*ourPTail++ = asctosc[TC_MAKE_ALT].scancode;
		*ourPTail++ = asctosc[c].scancode;
		*ourPTail++ = asctosc[TC_BREAK_ALT].scancode;
		break;
	    case shiftalted:
		*ourPTail++ = asctosc[TC_MAKE_SHIFT].scancode;
		*ourPTail++ = asctosc[TC_MAKE_ALT].scancode;
		*ourPTail++ = asctosc[c].scancode;
		*ourPTail++ = asctosc[TC_BREAK_ALT].scancode;
		*ourPTail++ = asctosc[TC_BREAK_SHIFT].scancode;
		break;
	    default:
		ExitString(stderr,
			    "Illegal 'shift' to AddChar() in termin.c\n", 1);
	    }
	}
E 5
I 5
	*ourPTail++ = c;
E 5
E 2
    } else {
D 2
	RingBell();
E 2
I 2
	RingBell("Typeahead buffer full");
E 2
    }
}

/* FlushChar - put everything where it belongs */

static void
FlushChar()
{
    ourPTail = ourBuffer;
    ourPHead = ourBuffer;
}
D 3

I 2
terminit()
{
    FlushChar();
    InControl = WaitingForSynch = 0;
}
E 2

E 3
I 2

I 10
void
TransInput(onoff, mode)
int	mode;			/* Which KIND of transparent input */
int	onoff;			/* Going in, or coming out */
{
    if (onoff) {
	/* Flush pending input */
	FlushChar();
	TransPointer = ourBuffer;
    } else {
    }
}

E 10
E 2
int
TerminalIn()
{
    /* send data from us to next link in stream */
D 5
    int count;
E 5
I 5
    int work = 0;
    register struct astosc *ptr;
E 5

D 5
    count = 0;
E 5
I 5
D 6
    if (*ourPHead == ' ') {
	ptr = spacePTR;
    } else {
	ptr = &astosc[*ourPHead];
    }
E 5

E 6
D 5
    if (!EmptyChar) {			/* send up the link */
	count += DataFrom3270(ourPHead, ourPTail-ourPHead);
	ourPHead += count;
	if (EmptyChar) {
	    FlushChar();
E 5
I 5
    while (!EmptyChar) {			/* send up the link */
I 6
	if (*ourPHead == ' ') {
	    ptr = spacePTR;
	} else {
	    ptr = &astosc[*ourPHead];
	}
E 6
	if (AcceptKeystroke(ptr->scancode, ptr->shiftstate) == 1) {
	    ourPHead++;
	    work = 1;
I 6
	} else {
	    break;
E 6
E 5
	}
    }
I 6

E 6
I 5
    if (EmptyChar) {
	FlushChar();
    }
E 5
	/* return value answers question: "did we do anything useful?" */
D 5
    return(count? 1:0);
E 5
I 5
    return work;
E 5
}

int
DataFromTerminal(buffer, count)
register char	*buffer;		/* the data read in */
register int	count;			/* how many bytes in this buffer */
{
    register state *regControlPointer;
    register char c;
    register int result;
    int origCount;
D 2

    static int InControl = 0;
    static int WaitingForSynch = 0;
E 2
I 2
    extern int bellwinup;
E 2
    static state *controlPointer;
I 10

    if (TransPointer) {
	int i;

	if ((count+TransPointer) >= (ourBuffer+sizeof ourBuffer)) {
	    i = ourBuffer+sizeof ourBuffer-TransPointer;
	} else {
	    i = count;
	}
	while (i--) {
D 13
	    c = (*buffer)&0x7f;
E 13
I 13
	    c = (*buffer++)&0x7f;
E 13
	    *TransPointer++ = c|0x80;
	    if (c == '\r') {
		SendTransparent(ourBuffer, TransPointer-ourBuffer);
		TransPointer = 0;		/* Done */
		break;
	    }
	}
	return count;
    }
E 10
D 2
    extern state *InitControl();
E 2

D 2
    if (!headOfControl) {
	/* need to initialize */
	headOfControl = InitControl((char *)0, 0);
	if (!headOfControl) {		/* should not occur */
	    quit();
	}
E 2
I 2
    if (bellwinup) {
	BellOff();
E 2
    }

D 2

E 2
    origCount = count;

    while (count) {
	c = *buffer++&0x7f;
	count--;

	if (!InControl && !IsControl(c)) {
	    AddChar(c);			/* add ascii character */
	} else {
	    if (!InControl) {		/* first character of sequence */
		InControl = 1;
		controlPointer = headOfControl;
	    }
	    /* control pointer points to current position in state table */
	    for (regControlPointer = controlPointer; ;
			regControlPointer = NextState(regControlPointer)) {
		if (!regControlPointer) {	/* ran off end */
D 2
		    RingBell();
E 2
I 2
		    RingBell("Invalid control sequence");
E 2
		    regControlPointer = headOfControl;
		    InControl = 0;
D 7
		    break;
E 7
I 7
		    count = 0;		/* Flush current input */
D 8
		    continue;
E 8
I 8
		    break;
E 8
E 7
		}
		if ((regControlPointer->match == c) /* hit this character */
			|| (regControlPointer->match == MATCH_ANY)) {
		    result = regControlPointer->result;
D 5
		    if (result == TC_GOTO) {
E 5
I 5
		    if (result == STATE_GOTO) {
E 5
			regControlPointer = regControlPointer->address;
			break;			/* go to next character */
		    }
		    if (WaitingForSynch) {
D 5
			if (result == TC_SYNCH) {
E 5
I 5
			if (astosc[result].function == FCN_SYNCH) {
E 5
			    WaitingForSynch = 0;
			} else {
D 2
			    RingBell();
E 2
I 2
			    RingBell("Need to type synch character");
E 2
			}
		    }
D 5
		    else if (result == TC_FLINP) {
E 5
I 5
		    else if (astosc[result].function == FCN_FLINP) {
E 5
			FlushChar();		/* Don't add FLINP */
		    } else {
D 5
			if (result == TC_MASTER_RESET) {
E 5
I 5
			if (astosc[result].function == FCN_MASTER_RESET) {
E 5
			    FlushChar();
			}
			AddChar(result);		/* add this code */
		    }
		    InControl = 0;	/* out of control now */
		    break;
		}
	    }
	    controlPointer = regControlPointer;		/* save state */
	}
    }
    (void) TerminalIn();			/* try to send data */
    return(origCount-count);
}
E 1
