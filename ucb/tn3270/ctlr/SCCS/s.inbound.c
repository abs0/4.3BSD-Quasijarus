h19296
s 00010/00021/01153
d D 3.3 88/03/28 12:34:17 bostic 21 20
c add Berkeley specific header
e
s 00029/00000/01145
d D 3.2 88/03/17 21:17:32 minshall 20 19
c Fix bug where, on an unformatted screen, we were changing the
c character at location zero on the screen.  Reported by Ed Jankawski at
c Boston U. and by Greg Small and Mike Friedman at UC Berkeley - both
c groups bitten because of CICS using unformatted screens!
e
s 00000/00000/01145
d D 3.1 87/08/11 10:18:38 minshall 19 18
c New version numbering.
e
s 00002/00003/01143
d D 1.18 87/07/17 10:03:10 minshall 18 17
c Install sccs headers and copyright notices.
e
s 00002/00002/01144
d D 1.17 87/07/15 15:25:35 minshall 17 16
c New directory structure.
e
s 00024/00002/01122
d D 1.16 87/07/15 14:12:43 minshall 16 15
c Make transparent input/output work.
e
s 00002/00002/01122
d D 1.15 87/06/19 12:51:08 minshall 15 14
c Directory changes.
e
s 00006/00002/01118
d D 1.14 87/06/15 09:27:27 minshall 14 13
c Don't do ConnectScreen if shell is active.
e
s 00462/00450/00658
d D 1.13 87/05/24 16:50:02 minshall 13 12
c AcceptKeyboard, and globally known bits for shiftstate 
c (and a 'make depend').
e
s 00021/00011/01087
d D 1.12 87/05/24 14:35:18 minshall 12 11
c New OIA.
e
s 00002/00002/01096
d D 1.11 87/05/22 11:18:09 minshall 11 10
c New directory structure.
e
s 00018/00003/01080
d D 1.10 87/05/12 14:05:40 minshall 10 9
c Add support for OIA.
e
s 00011/00006/01072
d D 1.9 87/05/11 11:08:44 minshall 9 8
c 1.  Make ExitString parameters conform.  2.  Support GE order.
e
s 00002/00002/01076
d D 1.8 87/05/10 15:26:04 minshall 8 7
c Fix bug (jbvb) in EINP (supposed to turn OFF MDT bits).
e
s 00017/00000/01061
d D 1.7 87/04/01 14:38:52 minshall 7 6
c Make close/open sequences work in a more rational way.
e
s 00007/00003/01054
d D 1.6 87/01/09 16:36:52 minshall 6 5
c Fix problem where WORDTAB, WORDBACKTAB, and WORDEND take N! time.
e
s 00013/00051/01044
d D 1.5 86/12/19 17:07:31 minshall 5 4
c Seems to work with 'close' then 'open'
e
s 00001/00000/01094
d D 1.4 86/12/19 11:06:30 minshall 4 3
c Fix bug in DISC logic.
e
s 00025/00019/01069
d D 1.3 86/11/16 15:21:21 minshall 3 2
c Turn FCN_... into enum, rather than  #define's.
e
s 00053/00018/01035
d D 1.2 86/11/16 11:00:31 minshall 2 1
c Get rid of bellWinup (or whatever).  It belongs in the system 
c dependent part.  Change interface for ExitString so we don't need 
c stdio.h.
e
s 01053/00000/00000
d D 1.1 86/11/11 22:54:04 minshall 1 0
c date and time created 86/11/11 22:54:04 by minshall
e
u
U
t
T
I 1
/*
D 18
 *	Copyright (c) 1984, 1985, 1986 by the Regents of the
E 18
I 18
D 21
 *	Copyright (c) 1984-1987 by the Regents of the
E 18
 *	University of California and by Gregory Glenn Minshall.
E 21
I 21
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 21
 *
D 21
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
E 21
I 21
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 21
 */

D 18

E 18
D 21
#ifndef	lint
E 21
I 21
#ifndef lint
E 21
D 18
static	char	sccsid[] = "@(#)inbound.c	3.1  10/29/86";
E 18
I 18
static char sccsid[] = "%W% (Berkeley) %G%";
E 18
D 21
#endif	/* ndef lint */


E 21
I 21
#endif /* not lint */
E 21
I 9
#include <stdio.h>

E 9
D 2
#include <stdio.h>

E 2
D 11
#include "../general.h"
E 11
I 11
#include "../general/general.h"
E 11
#include "function.h"
#include "hostctlr.h"
I 12
#include "oia.h"
E 12
#include "scrnctlr.h"
#include "screen.h"
#include "options.h"
D 15
#include "dctype.h"
#include "ebc_disp.h"
E 15
I 15
D 17
#include "../apilib/dctype.h"
#include "../apilib/ebc_disp.h"
E 17
I 17
#include "../api/dctype.h"
#include "../api/ebc_disp.h"
E 17
E 15

D 11
#include "../system/globals.h"
E 11
I 11
#include "../general/globals.h"
E 11
#include "inbound.ext"
#include "outbound.ext"
#include "../telnet.ext"

#define EmptyChar()	(ourPTail == ourPHead)
#define FullChar()	(ourPHead == ourBuffer+sizeof ourBuffer)


/*
 * We define something to allow us to to IsProtected() quickly
 * on unformatted screens (with the current algorithm for fields,
 * unprotected takes exponential time...).
 *
 *	The idea is to call SetXIsProtected() BEFORE the
 * loop, then use XIsProtected().
 */

D 6
#define	SetXIsProtected()	XFormattedScreen = FormattedScreen()
#define	XIsProtected(p)		(XFormattedScreen && IsProtected(p))
E 6
I 6
#define	SetXIsProtected()	(XWasSF = 1)
#define	XIsProtected(p)	(IsStartField(p)? \
			    XWasSF = 1 : \
			    (XWasSF? \
				(XWasSF = 0, XProtected = IsProtected(p))  : \
				XProtected))
E 6

static char	ourBuffer[400];

static char	*ourPHead = ourBuffer,
		*ourPTail = ourBuffer;

D 5
static int	HadAid = 0;		/* Had an AID haven't sent */
E 5
I 5
static int	HadAid;			/* Had an AID haven't sent */
E 5

D 5
static int	XFormattedScreen = 0;	/* For optimizations */
E 5
I 5
D 13
static int shifted,			/* Shift state of terminal */
	alted;				/* Alt state of terminal */
E 5

E 13
I 5
static int InsertMode;			/* is the terminal in insert mode? */

I 13
static int rememberedshiftstate;	/* Shift (alt) state of terminal */
#   define HITNUM(s) ((((s)&(SHIFT_CAPS|SHIFT_UPSHIFT))? 1:0) \
			+ ((((s)&SHIFT_ALT)? 1:0)<<1))

E 13
D 6
static int	XFormattedScreen;	/* For optimizations */
E 6
I 6
static int	XWasSF, XProtected;	/* For optimizations */
E 6
E 5
I 3
#if	!defined(PURE3274)
extern int TransparentClock, OutputClock;
#endif	/* !defined(PURE3274) */

E 3
D 5
#include "3270pc.out"
E 5
I 5
#include "kbd.out"		/* Get keyboard mapping function */
E 5

/* the following are global variables */

extern int UnLocked;		/* keyboard is UnLocked? */

I 7

/*
 * init_inbound :
 *
 * Reset variables to initial state.
 */

void
init_inbound()
{
    ourPHead = ourPTail = ourBuffer;
    HadAid = 0;
D 13
    shifted = alted = 0;
E 13
I 13
    rememberedshiftstate = 0;
E 13
    InsertMode = 0;
}


E 7
/* Tab() - sets cursor to the start of the next unprotected field */
static void
Tab()
{
    register int i, j;

    i = CursorAddress;
    j = WhereAttrByte(CursorAddress);
    do {
	if (IsStartField(i) && IsUnProtected(ScreenInc(i))) {
	    break;
	}
	i = FieldInc(i);
    } while (i != j);
    if (IsStartField(i) && IsUnProtected(ScreenInc(i))) {
	CursorAddress = ScreenInc(i);
    } else {
	CursorAddress = SetBufferAddress(0,0);
    }
}


/* BackTab() - sets cursor to the start of the most recent field */

static void
BackTab()
{
    register int i;

    i = ScreenDec(CursorAddress);
    for (;;) {
	if (IsStartField(ScreenDec(i)) && IsUnProtected(i)) {
	    CursorAddress = i;
	    break;
	}
	if (i == CursorAddress) {
	    CursorAddress = SetBufferAddress(0,0);
	    break;
	}
	i = ScreenDec(i);
    }
}

I 20
/*
 * ModifyMdt() - Turn a modified data tag bit on or off (watch
 * out for unformatted screens).
 */

ModifyMdt(x,on)
int x;
int on;
{
    int i = x;

    if (IsStartField(i)) {	/* If we are at a start field position... */
	if (on) {
	    ModifyHost(i, |= ATTR_MDT);		/* Turn it on */
	} else {
	    ModifyHost(i, &= ~ATTR_MDT);	/* Turn it off */
	}
    } else {
	i = WhereAttrByte(i);	/* Find beginning of field */
	if (IsStartField(i)) {	/* Is there one? */
	    if (on) {
		ModifyHost(i, |= ATTR_MDT);	/* Turn it on */
	    } else {
		ModifyHost(i, &= ~ATTR_MDT);	/* Turn it off */
	    }
	} /* else, don't modify - this is an unformatted screen */
    }
}

E 20

/* EraseEndOfField - erase all characters to the end of a field */

static void
EraseEndOfField()
{
    register int i;

    if (IsProtected(CursorAddress)) {
	RingBell("Protected Field");
    } else {
	TurnOnMdt(CursorAddress);
	if (FormattedScreen()) {
	    i = CursorAddress;
	    do {
		AddHost(i, 0);
		i = ScreenInc(i);
	    } while ((i != CursorAddress) && !IsStartField(i));
	} else {                            /* Screen is Unformatted */
	    i = CursorAddress;
	    do {
		AddHost(i, 0);
		i = ScreenInc(i);
	    } while (i != HighestScreen());
       } 
    }
}

/* Delete() - deletes a character from the screen
 *
 *	What we want to do is delete the section
 *	[where, from-1] from the screen,
 *	filling in with what comes at from.
 *
 *	The deleting continues to the end of the field (or
 *	until the cursor wraps).
 *
 *	From can be a start of a field.  We
 *	check for that.  However, there can't be any
 *	fields that start between where and from.
 *	We don't check for that.
 *
 *	Also, we assume that the protection status of
 *	everything has been checked by the caller.
 *
 */

static void
Delete(where, from)
register int	where,		/* Where to start deleting from */
		from;		/* Where to pull back from */
{
    register int i;

    TurnOnMdt(where);			/* Only do this once in this field */
    i = where;
    do {
	if (IsStartField(from)) {
	    AddHost(i, 0);		/* Stick the edge at the start field */
	} else {
	    AddHost(i, GetHost(from));
	    from = ScreenInc(from);		/* Move the edge */
	}
	i = ScreenInc(i);
    } while ((!IsStartField(i)) && (i != where));
}

static void
ColBak()
{
    register int i;

    i = ScreenLineOffset(CursorAddress);
    for (i = i-1; i >= 0; i--) {
	if (OptColTabs[i]) {
	    break;
	}
    }
    if (i < 0) {
	i = 0;
    }
    CursorAddress = SetBufferAddress(ScreenLine(CursorAddress), i);
}

static void
ColTab()
{
    register int i;

    i = ScreenLineOffset(CursorAddress);
    for (i = i+1; i < NumberColumns; i++) {
	if (OptColTabs[i]) {
	    break;
	}
    }
    if (i >= NumberColumns) {
	i = NumberColumns-1;
    }
    CursorAddress = SetBufferAddress(ScreenLine(CursorAddress), i);
}

static void
Home()
{
    register int i;
    register int j;

    i = SetBufferAddress(OptHome, 0);
    j = WhereLowByte(i);
    do {
	if (IsUnProtected(i)) {
	    CursorAddress = i;
	    return;
	}
	    /* the following could be a problem if we got here with an
	     * unformatted screen.  However, this is "impossible", since
	     * with an unformatted screen, the IsUnProtected(i) above
	     * should be true.
	     */
	i = ScreenInc(FieldInc(i));
    } while (i != j);
    CursorAddress = LowestScreen();
}

static
LastOfField(i)
register int	i;	/* position to start from */
{
    register int j;
    register int k;

    k = j = i;
    SetXIsProtected();
    while (XIsProtected(i) || Disspace(GetHost(i))) {
	i = ScreenInc(i);
	if (i == j) {
	    break;
	}
    }
	    /* We are now IN a word IN an unprotected field (or wrapped) */
    while (!XIsProtected(i)) {
	if (!Disspace(GetHost(i))) {
	    k = i;
	}
	i = ScreenInc(i);
	if (i == j) {
	    break;
	}
    }
    return(k);
}


static void
FlushChar()
{
    ourPTail = ourPHead = ourBuffer;
}


/*
 * Add one EBCDIC (NOT display code) character to the buffer.
 */

static void
AddChar(character)
char	character;
{
    if (FullChar()) {
	ourPTail += DataToNetwork(ourPTail, ourPHead-ourPTail, 0);
	if (EmptyChar()) {
	    FlushChar();
	} else {
D 2
	    fprintf(stderr, "File %s, line %d:  No room in network buffer!\n",
E 2
I 2
	    char buffer[100];

	    sprintf(buffer, "File %s, line %d:  No room in network buffer!\n",
E 2
				__FILE__, __LINE__);
D 2
	    return;
E 2
I 2
D 9
	    ExitString(buffer, 1);
E 9
I 9
	    ExitString(stderr, buffer, 1);
E 9
	    /*NOTREACHED*/
E 2
	}
    }
    *ourPHead++ = character;
}


static void
SendUnformatted()
{
    register int i, j;
    register int Nulls;
    register int c;

			/* look for start of field */
    Nulls = 0;
    i = j = LowestScreen();
    do {
	c = GetHost(i);
	if (c == 0) {
	    Nulls++;
	} else {
	    while (Nulls) {
		Nulls--;
		AddChar(EBCDIC_BLANK);		/* put in blanks */
	    }
	    AddChar(disp_ebc[c]);
	}
	i = ScreenInc(i);
    } while (i != j);
}

static
SendField(i, command)
register int i;			/* where we saw MDT bit */
int	command;		/* The command code (type of read) */
{
    register int j;
    register int k;
    register int Nulls;
    register int c;

			/* look for start of field */
    i = j = WhereLowByte(i);

		/* On a test_request_read, don't send sba and address */
    if ((AidByte != AID_TREQ)
			|| (command == CMD_SNA_READ_MODIFIED_ALL)) {
	AddChar(ORDER_SBA);		/* set start field */
	AddChar(BufferTo3270_0(j));	/* set address of this field */
	AddChar(BufferTo3270_1(j));
    }
		/*
		 * Only on read_modified_all do we return the contents
		 * of the field when the attention was caused by a
		 * selector pen.
		 */
    if ((AidByte != AID_SELPEN)
			|| (command == CMD_SNA_READ_MODIFIED_ALL)) {
	if (!IsStartField(j)) {
	    Nulls = 0;
	    k = ScreenInc(WhereHighByte(j));
	    do {
		c = GetHost(j);
		if (c == 0) {
		    Nulls++;
		} else {
		    while (Nulls) {
			Nulls--;
			AddChar(EBCDIC_BLANK);		/* put in blanks */
		    }
		    AddChar(disp_ebc[c]);
		}
		j = ScreenInc(j);
	    } while ((j != k) && (j != i));
	}
    } else {
	j = FieldInc(j);
    }
    return(j);
}

/* Various types of reads... */
void
DoReadModified(command)
int	command;			/* The command sent */
{
    register int i, j;

    if (AidByte) {
	if (AidByte != AID_TREQ) {
	    AddChar(AidByte);
	} else {
		/* Test Request Read header */
	    AddChar(EBCDIC_SOH);
	    AddChar(EBCDIC_PERCENT);
	    AddChar(EBCDIC_SLASH);
	    AddChar(EBCDIC_STX);
	}
    } else {
	AddChar(AID_NONE);
    }
    if (((AidByte != AID_PA1) && (AidByte != AID_PA2)
	    && (AidByte != AID_PA3) && (AidByte != AID_CLEAR))
	    || (command == CMD_SNA_READ_MODIFIED_ALL)) {
	if ((AidByte != AID_TREQ)
	    || (command == CMD_SNA_READ_MODIFIED_ALL)) {
		/* Test request read_modified doesn't give cursor address */
	    AddChar(BufferTo3270_0(CursorAddress));
	    AddChar(BufferTo3270_1(CursorAddress));
	}
	i = j = WhereAttrByte(LowestScreen());
	/* Is this an unformatted screen? */
	if (!IsStartField(i)) {		/* yes, handle separate */
	    SendUnformatted();
	} else {
	    do {
		if (HasMdt(i)) {
		    i = SendField(i, command);
		} else {
		    i = FieldInc(i);
		}
	    } while (i != j);
	}
    }
    ourPTail += DataToNetwork(ourPTail, ourPHead-ourPTail, 1);
    if (EmptyChar()) {
	FlushChar();
	HadAid = 0;			/* killed that buffer */
    }
}

/* A read buffer operation... */

void
DoReadBuffer()
{
    register int i, j;

    if (AidByte) {
	AddChar(AidByte);
    } else {
	AddChar(AID_NONE);
    }
    AddChar(BufferTo3270_0(CursorAddress));
    AddChar(BufferTo3270_1(CursorAddress));
    i = j = LowestScreen();
    do {
	if (IsStartField(i)) {
	    AddChar(ORDER_SF);
	    AddChar(BufferTo3270_1(FieldAttributes(i)));
	} else {
	    AddChar(disp_ebc[GetHost(i)]);
	}
	i = ScreenInc(i);
    } while (i != j);
    ourPTail += DataToNetwork(ourPTail, ourPHead-ourPTail, 1);
    if (EmptyChar()) {
	FlushChar();
	HadAid = 0;			/* killed that buffer */
    }
}
I 16

/* Send some transparent data to the host */

void
SendTransparent(buffer, count)
char *buffer;
int count;
{
    char stuff[3];

    stuff[0] = AID_NONE_PRINTER;
    stuff[1] = BufferTo3270_0(count);
    stuff[2] = BufferTo3270_1(count);
    DataToNetwork(stuff, sizeof stuff, 0);
    DataToNetwork(buffer, count, 1);
}


E 16
/* Try to send some data to host */

void
SendToIBM()
{
D 3
    extern int TransparentClock, OutputClock;

E 3
I 3
#if	!defined(PURE3274)
E 3
D 16
    if (TransparentClock == OutputClock) {
E 16
I 16
    if (TransparentClock >= OutputClock) {
E 16
	if (HadAid) {
	    AddChar(AidByte);
	    HadAid = 0;
	} else {
	    AddChar(AID_NONE_PRINTER);
	}
	do {
	    ourPTail += DataToNetwork(ourPTail, ourPHead-ourPTail, 1);
	} while (!EmptyChar());
	FlushChar();
    } else if (HadAid) {
	DoReadModified(CMD_READ_MODIFIED);
    }
D 3
    netflush();
E 3
I 3
#else	/* !defined(PURE3274) */
    if (HadAid) {
	DoReadModified(CMD_READ_MODIFIED);
    }
#endif	/* !defined(PURE3274) */
E 3
}

/* This takes in one character from the keyboard and places it on the
 * screen.
 */

static void
OneCharacter(c, insert)
int c;			/* character (Ebcdic) to be shoved in */
int insert;		/* are we in insert mode? */
{
    register int i, j;

    if (IsProtected(CursorAddress)) {
	RingBell("Protected Field");
	return;
    }
    if (insert) {
	/* is the last character in the field a blank or null? */
	i = ScreenDec(FieldInc(CursorAddress));
	j = GetHost(i);
	if (!Disspace(j)) {
	    RingBell("No more room for insert");
	    return;
	} else {
	    for (j = ScreenDec(i); i != CursorAddress;
			    j = ScreenDec(j), i = ScreenDec(i)) {
		AddHost(i, GetHost(j));
	    }
	}
    }
    AddHost(CursorAddress, c);
    TurnOnMdt(CursorAddress);
    CursorAddress = ScreenInc(CursorAddress);
    if (IsStartField(CursorAddress) &&
		((FieldAttributes(CursorAddress)&ATTR_AUTO_SKIP_MASK) ==
							ATTR_AUTO_SKIP_VALUE)) {
	Tab();
    }
}

D 13
/* go through data until an AID character is hit, then generate an interrupt */
E 13
I 13
/*
 * AcceptKeystroke()
 *
 * Processes one keystroke.
 *
 * Returns:
 *
 *	0	if this keystroke was NOT processed.
 *	1	if everything went OK.
 */
E 13

int
D 13
DataFrom3270(buffer, count)
unsigned char	*buffer;		/* where the data is */
int	count;				/* how much data there is */
E 13
I 13
AcceptKeystroke(scancode, shiftstate)
int
    scancode,			/* 3270 scancode */
    shiftstate;			/* The shift state */
E 13
{
D 13
    int origCount;
E 13
    register int c;
    register int i;
    register int j;
D 5
    static int InsertMode = 0;	/* is the terminal in insert mode? */
E 5
D 3
    enum type type;
    extern int OutputClock, TransparentClock;
E 3
I 3
    enum ctlrfcn ctlrfcn;
E 3
D 2
    extern int bellwinup;
E 2
D 5
    static int shifted = 0, alted = 0;
E 5
D 13
#   define HITNUM() ((shifted? 1:0) + ((alted?1:0)<<1))
E 13

D 2
    if (bellwinup) {
	BellOff();
    }

E 2
D 13
    if (*buffer >= numberof(hits)) {
E 13
I 13
    if (scancode >= numberof(hits)) {
E 13
D 2
	ExitString(stderr,
			"Unknown scancode encountered in DataFrom3270.\n", 1);
E 2
I 2
D 9
	ExitString("Unknown scancode encountered in DataFrom3270.\n", 1);
E 9
I 9
	ExitString(stderr,
D 13
		"Unknown scancode encountered in DataFrom3270.\n", 1);
E 13
I 13
		"Unknown scancode encountered in AcceptKeystroke.\n", 1);
E 13
E 9
E 2
	/*NOTREACHED*/
    }
D 3
    type = hits[*buffer].hit[HITNUM()].type;
E 3
I 3
D 13
    ctlrfcn = hits[*buffer].hit[HITNUM()].ctlrfcn;
E 3
    c = hits[*buffer].hit[HITNUM()].code;
E 13
I 13
    ctlrfcn = hits[scancode].hit[HITNUM(shiftstate)].ctlrfcn;
    c = hits[scancode].hit[HITNUM(shiftstate)].code;
E 13

    if (!UnLocked || HadAid) {
	if (HadAid) {
	    SendToIBM();
	    if (!EmptyChar()) {
D 13
		return(0);			/* nothing to do */
E 13
I 13
		return 0;			/* nothing to do */
E 13
	    }
	}
I 3
D 5
#if	defined(FCN_RESET) && defined(FCN_MASTER_RESET)
E 5
I 5
#if	!defined(PURE3274)
E 5
E 3
	if (!HadAid && EmptyChar()) {
D 3
	    if ((type == function) && ((c == FCN_RESET) ||
			(c == FCN_MASTER_RESET))) {
E 3
I 3
	    if ((ctlrfcn == FCN_RESET) || (ctlrfcn == FCN_MASTER_RESET)) {
E 3
		UnLocked = 1;
	    }
	}
I 3
D 5
#endif	/* defined(FCN_RESET) && defined(FCN_MASTER_RESET) */
E 5
I 5
#endif	/* !defined(PURE3274) */
E 5
E 3
	if (!UnLocked) {
D 13
	    return(0);
E 13
I 13
	    return 0;
E 13
	}
    }
I 16

E 16
    /* now, either empty, or haven't seen aid yet */

D 13
    origCount = count;
E 13
D 16

E 16
I 3
#if	!defined(PURE3274)
I 16
    /*
     * If we are in transparent (output) mode, do something special
     * with keystrokes.
     */
E 16
E 3
    if (TransparentClock == OutputClock) {
D 13
	while (count) {
	    if (*buffer >= numberof(hits)) {
D 2
		ExitString(stderr,
E 2
I 2
D 9
		ExitString(
E 9
I 9
		ExitString(stderr,
E 9
E 2
			"Unknown scancode encountered in DataFrom3270.\n", 1);
		/*NOTREACHED*/
	    }
D 3
	    type = hits[*buffer].hit[HITNUM()].type;
E 3
I 3
	    ctlrfcn = hits[*buffer].hit[HITNUM()].ctlrfcn;
E 3
	    c = hits[*buffer].hit[HITNUM()].code;
	    buffer++;
	    count--;
D 3
	    if (type == aid) {
E 3
I 3
	    if (ctlrfcn == FCN_AID) {
E 3
		UnLocked = 0;
		InsertMode = 0;
		AidByte = (c);
		HadAid = 1;
D 3
	    } else if (type == function) {
		switch (c) {
E 3
I 3
	    } else {
		switch (ctlrfcn) {
E 3
		case FCN_ESCAPE:
		    StopScreen(1);
		    command(0);
		    ConnectScreen();
		    break;
E 13
I 13
	if (ctlrfcn == FCN_AID) {
	    UnLocked = 0;
	    InsertMode = 0;
	    AidByte = (c);
	    HadAid = 1;
	} else {
	    switch (ctlrfcn) {
	    case FCN_ESCAPE:
		StopScreen(1);
		command(0);
D 14
		ConnectScreen();
E 14
I 14
		if (shell_active == 0) {
		    ConnectScreen();
		}
E 14
		break;
E 13

D 13
		case FCN_RESET:
		case FCN_MASTER_RESET:
		    UnLocked = 1;
		    break;
E 13
I 13
	    case FCN_RESET:
	    case FCN_MASTER_RESET:
		UnLocked = 1;
		break;
E 13

D 13
		default:
		    return(origCount-(count+1));
		}
E 13
I 13
	    default:
		return 0;
E 13
	    }
	}
    }
I 3
#endif	/* !defined(PURE3274) */
E 3

D 13
    while (count) {
	if (*buffer >= numberof(hits)) {
D 2
	    ExitString(stderr,
			"Unknown scancode encountered in DataFrom3270.\n", 1);
E 2
I 2
D 9
	    ExitString("Unknown scancode encountered in DataFrom3270.\n", 1);
E 9
I 9
	    ExitString(stderr,
			"Unknown scancode encountered in DataFrom3270.\n", 1);
E 9
E 2
	    /*NOTREACHED*/
E 13
I 13
    if (ctlrfcn == FCN_CHARACTER) {
		    /* Add the character to the buffer */
	OneCharacter(c, InsertMode);
    } else if (ctlrfcn == FCN_AID) {		/* got Aid */
	if (c == AID_CLEAR) {
	    LocalClearScreen();	/* Side effect is to clear 3270 */
E 13
	}
D 3
	type = hits[*buffer].hit[HITNUM()].type;
E 3
I 3
D 13
	ctlrfcn = hits[*buffer].hit[HITNUM()].ctlrfcn;
E 3
	c = hits[*buffer].hit[HITNUM()].code;
	buffer++;
	count--;
E 13
I 13
	ResetOiaOnlineA(&OperatorInformationArea);
	SetOiaTWait(&OperatorInformationArea);
	ResetOiaInsert(&OperatorInformationArea);
	InsertMode = 0;		/* just like a 3278 */
	SetOiaSystemLocked(&OperatorInformationArea);
	SetOiaModified();
	UnLocked = 0;
	AidByte = c;
	HadAid = 1;
	SendToIBM();
    } else {
	switch (ctlrfcn) {
E 13

D 3
	if (type == character) {
E 3
I 3
D 13
	if (ctlrfcn == FCN_CHARACTER) {
E 3
			/* Add the character to the buffer */
	    OneCharacter(c, InsertMode);
D 3
	} else if (type == aid) {		/* got Aid */
E 3
I 3
	} else if (ctlrfcn == FCN_AID) {		/* got Aid */
E 3
	    if (c == AID_CLEAR) {
		LocalClearScreen();	/* Side effect is to clear 3270 */
	    }
D 10
	    UnLocked = 0;
E 10
I 10
D 12
	    OiaOnlineA(0);
	    OiaTWait(1);
	    OiaInsert(0);
E 12
I 12
	    ResetOiaOnlineA(&OperatorInformationArea);
	    SetOiaTWait(&OperatorInformationArea);
	    ResetOiaInsert(&OperatorInformationArea);
E 12
E 10
	    InsertMode = 0;		/* just like a 3278 */
I 10
D 12
	    OiaSystemLocked(1);
E 12
I 12
	    SetOiaSystemLocked(&OperatorInformationArea);
	    SetOiaModified();
E 12
	    UnLocked = 0;
E 10
	    AidByte = c;
	    HadAid = 1;
	    SendToIBM();
	    return(origCount-count);
D 3
	} else if (type != function) {
D 2
	    ExitString(stderr, "Illegal or undefined scancode!\n", 1);
E 2
I 2
	    ExitString("Illegal or undefined scancode!\n", 1);
E 2
	    /*NOTREACHED*/
E 3
	} else {
D 3
	    switch (c) {
E 3
I 3
	    switch (ctlrfcn) {
E 3

	    case FCN_MAKE_SHIFT:
		shifted++;
		break;
	    case FCN_BREAK_SHIFT:
		shifted--;
		if (shifted < 0) {
D 2
		    ExitString(stderr,
				"More BREAK_SHIFT than MAKE_SHIFT.\n", 1);
E 2
I 2
D 9
		    ExitString("More BREAK_SHIFT than MAKE_SHIFT.\n", 1);
E 9
I 9
		    ExitString(stderr,
				"More BREAK_SHIFT than MAKE_SHIFT.\n", 1);
E 9
E 2
		    /*NOTREACHED*/
		}
		break;
	    case FCN_MAKE_ALT:
		alted++;
		break;
	    case FCN_BREAK_ALT:
		alted--;
		if (alted < 0) {
D 2
		    ExitString(stderr, "More BREAK_ALT than MAKE_ALT.\n", 1);
E 2
I 2
D 9
		    ExitString("More BREAK_ALT than MAKE_ALT.\n", 1);
E 9
I 9
		    ExitString(stderr, "More BREAK_ALT than MAKE_ALT.\n", 1);
E 9
E 2
		    /*NOTREACHED*/
		}
		break;
	    case FCN_CURSEL:
		c = FieldAttributes(CursorAddress)&ATTR_DSPD_MASK;
		if (!FormattedScreen()
			|| ((c != ATTR_DSPD_DSPD) && (c != ATTR_DSPD_HIGH))) {
		    RingBell("Cursor not in selectable field");
		} else {
		    i = ScreenInc(WhereAttrByte(CursorAddress));
		    c = GetHost(i);
		    if (c == DISP_QUESTION) {
			AddHost(i, DISP_GREATER_THAN);
			TurnOnMdt(i);
		    } else if (c == DISP_GREATER_THAN) {
			AddHost(i, DISP_QUESTION);
			TurnOffMdt(i);
		    } else if (c == DISP_BLANK || c == DISP_NULL
						|| c == DISP_AMPERSAND) {
			UnLocked = 0;
			InsertMode = 0;
I 10
D 12
			OiaOnlineA(0);
			OiaTWait(1);
			OiaSystemLocked(1);
			OiaInsert(0);
E 12
I 12
			ResetOiaOnlineA(&OperatorInformationArea);
			SetOiaTWait(&OperatorInformationArea);
			SetOiaSystemLocked(&OperatorInformationArea);
			ResetOiaInsert(&OperatorInformationArea);
			SetOiaModified();
E 12
E 10
			if (c == DISP_AMPERSAND) {
			    TurnOnMdt(i);	/* Only for & type */
			    AidByte = AID_ENTER;
			} else {
			    AidByte = AID_SELPEN;
			}
			HadAid = 1;
			SendToIBM();
E 13
I 13
	case FCN_CURSEL:
	    c = FieldAttributes(CursorAddress)&ATTR_DSPD_MASK;
	    if (!FormattedScreen()
		    || ((c != ATTR_DSPD_DSPD) && (c != ATTR_DSPD_HIGH))) {
		RingBell("Cursor not in selectable field");
	    } else {
		i = ScreenInc(WhereAttrByte(CursorAddress));
		c = GetHost(i);
		if (c == DISP_QUESTION) {
		    AddHost(i, DISP_GREATER_THAN);
		    TurnOnMdt(i);
		} else if (c == DISP_GREATER_THAN) {
		    AddHost(i, DISP_QUESTION);
		    TurnOffMdt(i);
		} else if (c == DISP_BLANK || c == DISP_NULL
					    || c == DISP_AMPERSAND) {
		    UnLocked = 0;
		    InsertMode = 0;
		    ResetOiaOnlineA(&OperatorInformationArea);
		    SetOiaTWait(&OperatorInformationArea);
		    SetOiaSystemLocked(&OperatorInformationArea);
		    ResetOiaInsert(&OperatorInformationArea);
		    SetOiaModified();
		    if (c == DISP_AMPERSAND) {
			TurnOnMdt(i);	/* Only for & type */
			AidByte = AID_ENTER;
E 13
		    } else {
D 13
			RingBell(
			    "Cursor not in a selectable field (designator)");
E 13
I 13
			AidByte = AID_SELPEN;
E 13
		    }
I 13
		    HadAid = 1;
		    SendToIBM();
		} else {
		    RingBell(
			"Cursor not in a selectable field (designator)");
E 13
		}
D 13
		break;
E 13
I 13
	    }
	    break;
E 13

I 2
D 5
#if	defined(FCN_ERASE)
E 5
I 5
#if	!defined(PURE3274)
E 5
E 2
D 13
	    case FCN_ERASE:
		if (IsProtected(ScreenDec(CursorAddress))) {
		    RingBell("Protected Field");
		} else {
		    CursorAddress = ScreenDec(CursorAddress);
		    Delete(CursorAddress, ScreenInc(CursorAddress));
E 13
I 13
	case FCN_ERASE:
	    if (IsProtected(ScreenDec(CursorAddress))) {
		RingBell("Protected Field");
	    } else {
		CursorAddress = ScreenDec(CursorAddress);
		Delete(CursorAddress, ScreenInc(CursorAddress));
	    }
	    break;
	case FCN_WERASE:
	    j = CursorAddress;
	    i = ScreenDec(j);
	    if (IsProtected(i)) {
		RingBell("Protected Field");
	    } else {
		SetXIsProtected();
		while ((!XIsProtected(i) && Disspace(GetHost(i)))
						    && (i != j)) {
		    i = ScreenDec(i);
E 13
		}
D 13
		break;
I 2
D 5
#endif	/* defined(FCN_ERASE) */
E 2

I 2
#if	defined(FCN_WERASE)
E 5
E 2
	    case FCN_WERASE:
		j = CursorAddress;
		i = ScreenDec(j);
		if (IsProtected(i)) {
		    RingBell("Protected Field");
		} else {
		    SetXIsProtected();
		    while ((!XIsProtected(i) && Disspace(GetHost(i)))
							&& (i != j)) {
			i = ScreenDec(i);
		    }
		    /* we are pointing at a character in a word, or
		     * at a protected position
		     */
		    while ((!XIsProtected(i) && !Disspace(GetHost(i)))
							&& (i != j)) {
			i = ScreenDec(i);
		    }
		    /* we are pointing at a space, or at a protected
		     * position
		     */
		    CursorAddress = ScreenInc(i);
		    Delete(CursorAddress, j);
E 13
I 13
		/* we are pointing at a character in a word, or
		 * at a protected position
		 */
		while ((!XIsProtected(i) && !Disspace(GetHost(i)))
						    && (i != j)) {
		    i = ScreenDec(i);
E 13
		}
D 13
		break;
E 13
I 13
		/* we are pointing at a space, or at a protected
		 * position
		 */
		CursorAddress = ScreenInc(i);
		Delete(CursorAddress, j);
	    }
	    break;
E 13
I 2
D 5
#endif	/* defined(WERASE) */
E 5
E 2

I 2
D 5
#if	defined(FCN_FERASE)
E 5
E 2
D 13
	    case FCN_FERASE:
		if (IsProtected(CursorAddress)) {
		    RingBell("Protected Field");
		} else {
		    CursorAddress = ScreenInc(CursorAddress);	/* for btab */
		    BackTab();
		    EraseEndOfField();
		}
		break;
E 13
I 13
	case FCN_FERASE:
	    if (IsProtected(CursorAddress)) {
		RingBell("Protected Field");
	    } else {
		CursorAddress = ScreenInc(CursorAddress);	/* for btab */
		BackTab();
		EraseEndOfField();
	    }
	    break;
E 13
I 2
D 5
#endif	/* defined(FCN_FERASE) */
E 5
E 2

I 2
D 5
#if	defined(FCN_RESET)
E 5
E 2
D 13
	    case FCN_RESET:
D 10
		InsertMode = 0;
E 10
I 10
		if (InsertMode) {
		    InsertMode = 0;
D 12
		    OiaInsert(0);
E 12
I 12
		    ResetOiaInsert(&OperatorInformationArea);
		    SetOiaModified();
E 12
		}
E 10
		break;
I 2
D 5
#endif	/* defined(FCN_RESET) */
E 2

I 2
#if	defined(FCN_MASTER_RESET)
E 5
E 2
	    case FCN_MASTER_RESET:
D 10
		InsertMode = 0;
E 10
I 10
		if (InsertMode) {
		    InsertMode = 0;
D 12
		    OiaInsert(0);
E 12
I 12
		    ResetOiaInsert(&OperatorInformationArea);
		    SetOiaModified();
E 12
		}
E 10
		RefreshScreen();
		break;
E 13
I 13
	case FCN_RESET:
	    if (InsertMode) {
		InsertMode = 0;
		ResetOiaInsert(&OperatorInformationArea);
		SetOiaModified();
	    }
	    break;
	case FCN_MASTER_RESET:
	    if (InsertMode) {
		InsertMode = 0;
		ResetOiaInsert(&OperatorInformationArea);
		SetOiaModified();
	    }
	    RefreshScreen();
	    break;
E 13
I 2
D 5
#endif	/* defined(FCN_MASTER_RESET) */
E 5
I 5
#endif	/* !defined(PURE3274) */
E 5
E 2

D 13
	    case FCN_UP:
		CursorAddress = ScreenUp(CursorAddress);
		break;
E 13
I 13
	case FCN_UP:
	    CursorAddress = ScreenUp(CursorAddress);
	    break;
E 13

D 13
	    case FCN_LEFT:
		CursorAddress = ScreenDec(CursorAddress);
		break;
E 13
I 13
	case FCN_LEFT:
	    CursorAddress = ScreenDec(CursorAddress);
	    break;
E 13

D 13
	    case FCN_RIGHT:
		CursorAddress = ScreenInc(CursorAddress);
		break;
E 13
I 13
	case FCN_RIGHT:
	    CursorAddress = ScreenInc(CursorAddress);
	    break;
E 13

D 13
	    case FCN_DOWN:
		CursorAddress = ScreenDown(CursorAddress);
		break;
E 13
I 13
	case FCN_DOWN:
	    CursorAddress = ScreenDown(CursorAddress);
	    break;
E 13

D 13
	    case FCN_DELETE:
		if (IsProtected(CursorAddress)) {
		    RingBell("Protected Field");
		} else {
		    Delete(CursorAddress, ScreenInc(CursorAddress));
		}
		break;
E 13
I 13
	case FCN_DELETE:
	    if (IsProtected(CursorAddress)) {
		RingBell("Protected Field");
	    } else {
		Delete(CursorAddress, ScreenInc(CursorAddress));
	    }
	    break;
E 13

D 13
	    case FCN_INSRT:
		InsertMode = !InsertMode;
I 10
D 12
		OiaInsert(InsertMode);
E 12
I 12
		if (InsertMode) {
		    SetOiaInsert(&OperatorInformationArea);
		} else {
		    ResetOiaInsert(&OperatorInformationArea);
		}
		SetOiaModified();
E 12
E 10
		break;
E 13
I 13
	case FCN_INSRT:
	    InsertMode = !InsertMode;
	    if (InsertMode) {
		SetOiaInsert(&OperatorInformationArea);
	    } else {
		ResetOiaInsert(&OperatorInformationArea);
	    }
	    SetOiaModified();
	    break;
E 13

D 13
	    case FCN_HOME:
		Home();
		break;
E 13
I 13
	case FCN_HOME:
	    Home();
	    break;
E 13

D 13
	    case FCN_NL:
		/* The algorithm is to look for the first unprotected
		 * column after column 0 of the following line.  Having
		 * found that unprotected column, we check whether the
		 * cursor-address-at-entry is at or to the right of the
		 * LeftMargin AND the LeftMargin column of the found line
		 * is unprotected.  If this conjunction is true, then
		 * we set the found pointer to the address of the LeftMargin
		 * column in the found line.
		 * Then, we set the cursor address to the found address.
E 13
I 13
	case FCN_NL:
	    /* The algorithm is to look for the first unprotected
	     * column after column 0 of the following line.  Having
	     * found that unprotected column, we check whether the
	     * cursor-address-at-entry is at or to the right of the
	     * LeftMargin AND the LeftMargin column of the found line
	     * is unprotected.  If this conjunction is true, then
	     * we set the found pointer to the address of the LeftMargin
	     * column in the found line.
	     * Then, we set the cursor address to the found address.
	     */
	    i = SetBufferAddress(ScreenLine(ScreenDown(CursorAddress)), 0);
	    j = ScreenInc(WhereAttrByte(CursorAddress));
	    do {
		if (IsUnProtected(i)) {
		    break;
		}
		/* Again (see comment in Home()), this COULD be a problem
		 * with an unformatted screen.
E 13
		 */
D 13
		i = SetBufferAddress(ScreenLine(ScreenDown(CursorAddress)), 0);
		j = ScreenInc(WhereAttrByte(CursorAddress));
E 13
I 13
		/* If there was a field with only an attribute byte,
		 * we may be pointing to the attribute byte of the NEXT
		 * field, so just look at the next byte.
		 */
		if (IsStartField(i)) {
		    i = ScreenInc(i);
		} else {
		    i = ScreenInc(FieldInc(i));
		}
	    } while (i != j);
	    if (!IsUnProtected(i)) {	/* couldn't find unprotected */
		i = SetBufferAddress(0,0);
	    }
	    if (OptLeftMargin <= ScreenLineOffset(CursorAddress)) {
		if (IsUnProtected(SetBufferAddress(ScreenLine(i),
							OptLeftMargin))) {
		    i = SetBufferAddress(ScreenLine(i), OptLeftMargin);
		}
	    }
	    CursorAddress = i;
	    break;

	case FCN_EINP:
	    if (!FormattedScreen()) {
		i = CursorAddress;
		TurnOffMdt(i);
E 13
		do {
D 13
		    if (IsUnProtected(i)) {
			break;
		    }
		    /* Again (see comment in Home()), this COULD be a problem
		     * with an unformatted screen.
E 13
I 13
		    AddHost(i, 0);
		    i = ScreenInc(i);
		} while (i != CursorAddress);
	    } else {
		    /*
		     * The algorithm is:  go through each unprotected
		     * field on the screen, clearing it out.  When
		     * we are at the start of a field, skip that field
		     * if its contents are protected.
E 13
		     */
D 13
		    /* If there was a field with only an attribute byte,
		     * we may be pointing to the attribute byte of the NEXT
		     * field, so just look at the next byte.
		     */
		    if (IsStartField(i)) {
E 13
I 13
		i = j = FieldInc(CursorAddress);
		do {
		    if (IsUnProtected(ScreenInc(i))) {
E 13
			i = ScreenInc(i);
I 13
			TurnOffMdt(i);
			do {
			   AddHost(i, 0);
			   i = ScreenInc(i);
			} while (!IsStartField(i));
E 13
		    } else {
D 13
			i = ScreenInc(FieldInc(i));
E 13
I 13
			i = FieldInc(i);
E 13
		    }
		} while (i != j);
D 13
		if (!IsUnProtected(i)) {	/* couldn't find unprotected */
		    i = SetBufferAddress(0,0);
		}
		if (OptLeftMargin <= ScreenLineOffset(CursorAddress)) {
		    if (IsUnProtected(SetBufferAddress(ScreenLine(i),
							    OptLeftMargin))) {
			i = SetBufferAddress(ScreenLine(i), OptLeftMargin);
		    }
		}
		CursorAddress = i;
		break;
E 13
I 13
	    }
	    Home();
	    break;
E 13

D 13
	    case FCN_EINP:
		if (!FormattedScreen()) {
		    i = CursorAddress;
D 8
		    TurnOnMdt(i);
E 8
I 8
		    TurnOffMdt(i);
E 8
		    do {
			AddHost(i, 0);
			i = ScreenInc(i);
		    } while (i != CursorAddress);
		} else {
			/*
			 * The algorithm is:  go through each unprotected
			 * field on the screen, clearing it out.  When
			 * we are at the start of a field, skip that field
			 * if its contents are protected.
			 */
		    i = j = FieldInc(CursorAddress);
		    do {
			if (IsUnProtected(ScreenInc(i))) {
			    i = ScreenInc(i);
D 8
			    TurnOnMdt(i);
E 8
I 8
			    TurnOffMdt(i);
E 8
			    do {
			       AddHost(i, 0);
			       i = ScreenInc(i);
			    } while (!IsStartField(i));
			} else {
			    i = FieldInc(i);
			}
		    } while (i != j);
		}
		Home();
		break;
E 13
I 13
	case FCN_EEOF:
	    EraseEndOfField();
	    break;
E 13

D 13
	    case FCN_EEOF:
		EraseEndOfField();
		break;
E 13
I 13
	case FCN_SPACE:
	    OneCharacter(DISP_BLANK, InsertMode);  /* Add cent */
	    break;
E 13

D 13
	    case FCN_SPACE:
		OneCharacter(DISP_BLANK, InsertMode);  /* Add cent */
		break;
E 13
I 13
	case FCN_CENTSIGN:
	    OneCharacter(DISP_CENTSIGN, InsertMode);  /* Add cent */
	    break;
E 13

D 13
	    case FCN_CENTSIGN:
		OneCharacter(DISP_CENTSIGN, InsertMode);  /* Add cent */
		break;
E 13
I 13
	case FCN_FM:
	    OneCharacter(DISP_FM, InsertMode);  /* Add field mark */
	    break;
E 13

D 13
	    case FCN_FM:
		OneCharacter(DISP_FM, InsertMode);  /* Add field mark */
		break;

	    case FCN_DP:
		if (IsProtected(CursorAddress)) {
		    RingBell("Protected Field");
		} else {
		    OneCharacter(DISP_DUP, InsertMode);/* Add dup character */
		    Tab();
		}
		break;

	    case FCN_TAB:
E 13
I 13
	case FCN_DP:
	    if (IsProtected(CursorAddress)) {
		RingBell("Protected Field");
	    } else {
		OneCharacter(DISP_DUP, InsertMode);/* Add dup character */
E 13
		Tab();
D 13
		break;
E 13
I 13
	    }
	    break;
E 13

D 13
	    case FCN_BTAB:
		BackTab();
		break;
E 13
I 13
	case FCN_TAB:
	    Tab();
	    break;
E 13

I 13
	case FCN_BTAB:
	    BackTab();
	    break;

E 13
#ifdef	NOTUSED			/* Actually, this is superseded by unix flow
D 13
				 * control.
				 */
	    case FCN_XOFF:
		Flow = 0;			/* stop output */
		break;
E 13
I 13
			     * control.
			     */
	case FCN_XOFF:
	    Flow = 0;			/* stop output */
	    break;
E 13

D 13
	    case FCN_XON:
		if (!Flow) {
		    Flow = 1;			/* turn it back on */
		    DoTerminalOutput();
		}
		break;
E 13
I 13
	case FCN_XON:
	    if (!Flow) {
		Flow = 1;			/* turn it back on */
		DoTerminalOutput();
	    }
	    break;
E 13
#endif	/* NOTUSED */

I 2
D 5
#if	defined(FCN_ESCAPE)
E 5
I 5
#if	!defined(PURE3274)
E 5
E 2
D 13
	    case FCN_ESCAPE:
		/* FlushChar(); do we want to flush characters from before? */
		StopScreen(1);
		command(0);
		ConnectScreen();
		break;
E 13
I 13
	case FCN_ESCAPE:
	    /* FlushChar(); do we want to flush characters from before? */
	    StopScreen(1);
	    command(0);
D 14
	    ConnectScreen();
E 14
I 14
	    if (shell_active == 0) {
		ConnectScreen();
	    }
E 14
	    break;
E 13
I 2
D 5
#endif	/* defined(FCN_ESCAPE)
E 5
E 2

I 2
D 5
#if	defined(FCN_DISC)
E 5
E 2
D 13
	    case FCN_DISC:
		StopScreen(1);
		suspend();
I 4
		setconnmode();
E 4
		ConnectScreen();
		break;
E 13
I 13
	case FCN_DISC:
	    StopScreen(1);
	    suspend();
	    setconnmode();
	    ConnectScreen();
	    break;
E 13
I 2
D 5
#endif	/* defined(FCN_DISC) */
E 5
E 2

I 2
D 5
#if	defined(FCN_RESHOW)
E 5
E 2
D 13
	    case FCN_RESHOW:
		RefreshScreen();
		break;
E 13
I 13
	case FCN_RESHOW:
	    RefreshScreen();
	    break;
E 13
I 2
D 5
#endif	/* defined(FCN_RESHOW) */
E 5
E 2

I 2
D 5
#if	defined(FCN_SETTAB)
E 5
E 2
D 13
	    case FCN_SETTAB:
		OptColTabs[ScreenLineOffset(CursorAddress)] = 1;
		break;
E 13
I 13
	case FCN_SETTAB:
	    OptColTabs[ScreenLineOffset(CursorAddress)] = 1;
	    break;
E 13
I 2
D 5
#endif	/* defined(FCN_SETTAB) */
E 5
E 2

I 2
D 5
#if	defined(FCN_DELTAB)
E 5
E 2
D 13
	    case FCN_DELTAB:
		OptColTabs[ScreenLineOffset(CursorAddress)] = 0;
		break;
E 13
I 13
	case FCN_DELTAB:
	    OptColTabs[ScreenLineOffset(CursorAddress)] = 0;
	    break;
E 13
I 2
D 5
#endif	/* defined(FCN_DELTAB) */
E 5
E 2

I 2
D 5
#if	defined(FCN_CLRTAB)
E 5
E 2
D 13
		/*
		 * Clear all tabs, home line, and left margin.
		 */
	    case FCN_CLRTAB:
		for (i = 0; i < sizeof OptColTabs; i++) {
		    OptColTabs[i] = 0;
		}
		OptHome = 0;
		OptLeftMargin = 0;
		break;
E 13
I 13
	    /*
	     * Clear all tabs, home line, and left margin.
	     */
	case FCN_CLRTAB:
	    for (i = 0; i < sizeof OptColTabs; i++) {
		OptColTabs[i] = 0;
	    }
	    OptHome = 0;
	    OptLeftMargin = 0;
	    break;
E 13
I 2
D 5
#endif	/* defined(FCN_CLRTAB) */
E 5
E 2

I 2
D 5
#if	defined(FCN_COLTAB)
E 5
E 2
D 13
	    case FCN_COLTAB:
		ColTab();
		break;
E 13
I 13
	case FCN_COLTAB:
	    ColTab();
	    break;
E 13
I 2
D 5
#endif	/* defined(FCN_COLTAB) */
E 5
E 2

I 2
D 5
#if	defined(FCN_COLBAK)
E 5
E 2
D 13
	    case FCN_COLBAK:
		ColBak();
		break;
E 13
I 13
	case FCN_COLBAK:
	    ColBak();
	    break;
E 13
I 2
D 5
#endif	/* defined(FCN_COLBAK) */
E 5
E 2

I 2
D 5
#if	defined(FCN_INDENT)
E 5
E 2
D 13
	    case FCN_INDENT:
		ColTab();
		OptLeftMargin = ScreenLineOffset(CursorAddress);
		break;
E 13
I 13
	case FCN_INDENT:
	    ColTab();
	    OptLeftMargin = ScreenLineOffset(CursorAddress);
	    break;
E 13
I 2
D 5
#endif	/* defined(FCN_INDENT) */
E 5
E 2

I 2
D 5
#if	defined(FCN_UNDENT)
E 5
E 2
D 13
	    case FCN_UNDENT:
		ColBak();
		OptLeftMargin = ScreenLineOffset(CursorAddress);
		break;
E 13
I 13
	case FCN_UNDENT:
	    ColBak();
	    OptLeftMargin = ScreenLineOffset(CursorAddress);
	    break;
E 13
I 2
D 5
#endif	/* defined(FCN_UNDENT) */
E 5
E 2

I 2
D 5
#if	defined(FCN_SETMRG)
E 5
E 2
D 13
	    case FCN_SETMRG:
		OptLeftMargin = ScreenLineOffset(CursorAddress);
		break;
E 13
I 13
	case FCN_SETMRG:
	    OptLeftMargin = ScreenLineOffset(CursorAddress);
	    break;
E 13
I 2
D 5
#endif	/* defined(FCN_SETMRG) */
E 5
E 2

I 2
D 5
#if	defined(FCN_SETHOM)
E 5
E 2
D 13
	    case FCN_SETHOM:
		OptHome = ScreenLine(CursorAddress);
		break;
E 13
I 13
	case FCN_SETHOM:
	    OptHome = ScreenLine(CursorAddress);
	    break;
E 13
I 2
D 5
#endif	/* defined(FCN_SETHOM) */
E 5
E 2

I 2
D 5
#if	defined(FCN_WORDTAB)
E 5
E 2
D 13
		/*
		 * Point to first character of next unprotected word on
		 * screen.
		 */
	    case FCN_WORDTAB:
		i = CursorAddress;
		SetXIsProtected();
		while (!XIsProtected(i) && !Disspace(GetHost(i))) {
		    i = ScreenInc(i);
		    if (i == CursorAddress) {
			break;
		    }
E 13
I 13
	    /*
	     * Point to first character of next unprotected word on
	     * screen.
	     */
	case FCN_WORDTAB:
	    i = CursorAddress;
	    SetXIsProtected();
	    while (!XIsProtected(i) && !Disspace(GetHost(i))) {
		i = ScreenInc(i);
		if (i == CursorAddress) {
		    break;
E 13
		}
D 13
		/* i is either protected, a space (blank or null),
		 * or wrapped
		 */
		while (XIsProtected(i) || Disspace(GetHost(i))) {
		    i =  ScreenInc(i);
		    if (i == CursorAddress) {
			break;
		    }
E 13
I 13
	    }
	    /* i is either protected, a space (blank or null),
	     * or wrapped
	     */
	    while (XIsProtected(i) || Disspace(GetHost(i))) {
		i =  ScreenInc(i);
		if (i == CursorAddress) {
		    break;
E 13
		}
D 13
		CursorAddress = i;
		break;
E 13
I 13
	    }
	    CursorAddress = i;
	    break;
E 13
I 2
D 5
#endif	/* defined(FCN_WORDTAB) */
E 5
E 2

I 2
D 5
#if	defined(FCN_WORDBACKTAB)
E 5
E 2
D 13
	    case FCN_WORDBACKTAB:
		i = ScreenDec(CursorAddress);
		SetXIsProtected();
		while (XIsProtected(i) || Disspace(GetHost(i))) {
		    i = ScreenDec(i);
		    if (i == CursorAddress) {
			break;
		    }
E 13
I 13
	case FCN_WORDBACKTAB:
	    i = ScreenDec(CursorAddress);
	    SetXIsProtected();
	    while (XIsProtected(i) || Disspace(GetHost(i))) {
		i = ScreenDec(i);
		if (i == CursorAddress) {
		    break;
E 13
		}
D 13
		    /* i is pointing to a character IN an unprotected word
		     * (or i wrapped)
		     */
		while (!Disspace(GetHost(i))) {
		    i = ScreenDec(i);
		    if (i == CursorAddress) {
			break;
		    }
E 13
I 13
	    }
		/* i is pointing to a character IN an unprotected word
		 * (or i wrapped)
		 */
	    while (!Disspace(GetHost(i))) {
		i = ScreenDec(i);
		if (i == CursorAddress) {
		    break;
E 13
		}
D 13
		CursorAddress = ScreenInc(i);
		break;
E 13
I 13
	    }
	    CursorAddress = ScreenInc(i);
	    break;
E 13
I 2
D 5
#endif	/* defined(FCN_WORDBACKTAB) */
E 5
E 2

I 2
D 5
#if	defined(FCN_WORDEND)
E 5
E 2
D 13
			/* Point to last non-blank character of this/next
			 * unprotected word.
			 */
	    case FCN_WORDEND:
		i = ScreenInc(CursorAddress);
		SetXIsProtected();
		while (XIsProtected(i) || Disspace(GetHost(i))) {
		    i = ScreenInc(i);
		    if (i == CursorAddress) {
			break;
		    }
E 13
I 13
		    /* Point to last non-blank character of this/next
		     * unprotected word.
		     */
	case FCN_WORDEND:
	    i = ScreenInc(CursorAddress);
	    SetXIsProtected();
	    while (XIsProtected(i) || Disspace(GetHost(i))) {
		i = ScreenInc(i);
		if (i == CursorAddress) {
		    break;
E 13
		}
D 13
			/* we are pointing at a character IN an
			 * unprotected word (or we wrapped)
			 */
		while (!Disspace(GetHost(i))) {
		    i = ScreenInc(i);
		    if (i == CursorAddress) {
			break;
		    }
E 13
I 13
	    }
		    /* we are pointing at a character IN an
		     * unprotected word (or we wrapped)
		     */
	    while (!Disspace(GetHost(i))) {
		i = ScreenInc(i);
		if (i == CursorAddress) {
		    break;
E 13
		}
D 13
		CursorAddress = ScreenDec(i);
		break;
E 13
I 13
	    }
	    CursorAddress = ScreenDec(i);
	    break;
E 13
I 2
D 5
#endif	/* defined(WORDEND) */
E 5
E 2

I 2
D 5
#if	defined(FCN_FIELDEND)
E 5
E 2
D 13
			/* Get to last non-blank of this/next unprotected
			 * field.
			 */
	    case FCN_FIELDEND:
		i = LastOfField(CursorAddress);
		if (i != CursorAddress) {
		    CursorAddress = i;		/* We moved; take this */
		} else {
		    j = FieldInc(CursorAddress);	/* Move to next field */
		    i = LastOfField(j);
		    if (i != j) {
			CursorAddress = i;	/* We moved; take this */
		    }
			/* else - nowhere else on screen to be; stay here */
E 13
I 13
		    /* Get to last non-blank of this/next unprotected
		     * field.
		     */
	case FCN_FIELDEND:
	    i = LastOfField(CursorAddress);
	    if (i != CursorAddress) {
		CursorAddress = i;		/* We moved; take this */
	    } else {
		j = FieldInc(CursorAddress);	/* Move to next field */
		i = LastOfField(j);
		if (i != j) {
		    CursorAddress = i;	/* We moved; take this */
E 13
		}
D 13
		break;
E 13
I 13
		    /* else - nowhere else on screen to be; stay here */
	    }
	    break;
E 13
I 2
D 5
#endif	/* defined(FCN_FIELDEND) */
E 5
I 5
#endif	/* !defined(PURE3274) */
E 5
E 2

D 13
	    default:
				    /* We don't handle this yet */
		RingBell("Function not implemented");
E 13
I 13
	default:
				/* We don't handle this yet */
	    RingBell("Function not implemented");
	}
    }
    return 1;				/* We did something! */
}


/*
 * We get data from the terminal.  We keep track of the shift state
 * (including ALT, CONTROL), and then call AcceptKeystroke to actually
 * process any non-shift keys.
 */

int
DataFrom3270(buffer, count)
unsigned char	*buffer;		/* where the data is */
int		count;			/* how much data there is */
{
    int origCount;

    origCount = count;

    while (count) {
	if (*buffer >= numberof(hits)) {
	    ExitString(stderr,
			"Unknown scancode encountered in DataFrom3270.\n", 1);
	    /*NOTREACHED*/
	}

	switch (hits[*buffer].hit[HITNUM(rememberedshiftstate)].ctlrfcn) {

	case FCN_MAKE_SHIFT:
	    rememberedshiftstate |= (SHIFT_RIGHT|SHIFT_UPSHIFT);
	    break;
	case FCN_BREAK_SHIFT:
	    rememberedshiftstate &= ~(SHIFT_RIGHT|SHIFT_UPSHIFT);
	    break;
	case FCN_MAKE_ALT:
	    rememberedshiftstate |= SHIFT_ALT;
	    break;
	case FCN_BREAK_ALT:
	    rememberedshiftstate &= ~SHIFT_ALT;
	    break;
	default:
	    if (AcceptKeystroke(*buffer, rememberedshiftstate) == 0) {
		return(origCount-count);
E 13
	    }
I 13
	    break;
E 13
	}
I 13
	buffer++;
	count--;
E 13
    }
    return(origCount-count);
}
E 1
