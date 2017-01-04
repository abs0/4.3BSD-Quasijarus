h19682
s 00009/00019/00549
d D 3.3 88/03/28 12:34:29 bostic 25 24
c add Berkeley specific header
e
s 00004/00003/00564
d D 3.2 88/03/13 22:24:46 minshall 24 23
c Fix EUA order for case where "stop address" is equal to current
c buffer address.
e
s 00000/00000/00567
d D 3.1 87/08/11 10:18:48 minshall 23 22
c New version numbering.
e
s 00002/00002/00565
d D 1.22 87/07/17 10:03:17 minshall 22 21
c Install sccs headers and copyright notices.
e
s 00001/00001/00566
d D 1.21 87/07/15 15:25:52 minshall 21 20
c New directory structure.
e
s 00021/00016/00546
d D 1.20 87/07/15 14:12:49 minshall 20 19
c Make transparent input/output work.
e
s 00001/00001/00561
d D 1.19 87/06/19 12:51:03 minshall 19 18
c Directory changes.
e
s 00000/00027/00562
d D 1.18 87/06/18 16:10:01 minshall 18 17
c Remove #ifdef's for SLOWSCREEN (since they weren't really part
c of SLOWSCREEN, they just happened at the same time).
e
s 00001/00000/00588
d D 1.17 87/06/16 17:19:17 minshall 17 16
c Add SetPsModified().
e
s 00008/00000/00580
d D 1.16 87/05/25 16:30:27 minshall 16 15
c Keep controller ready status up-to-date.
e
s 00019/00010/00561
d D 1.15 87/05/24 14:35:14 minshall 15 14
c New OIA.
e
s 00003/00003/00568
d D 1.14 87/05/22 11:18:07 minshall 14 13
c New directory structure.
e
s 00003/00000/00568
d D 1.13 87/05/18 16:05:02 minshall 13 12
c Fix to keep queued keystrokes flowing when keyboard unlocked.
e
s 00023/00005/00545
d D 1.12 87/05/12 14:06:53 minshall 12 11
c 1) OIA support 2) Remove "bzero" calls 3) Better error diagnostics.
e
s 00047/00009/00503
d D 1.11 87/05/11 11:08:39 minshall 11 10
c 1.  Make ExitString parameters conform.  2.  Support GE order.
e
s 00001/00001/00511
d D 1.10 87/05/10 16:38:59 minshall 10 9
c Fix semantics of FieldDec() to return LowestScreen() on failure.
e
s 00012/00009/00500
d D 1.9 87/05/10 15:51:30 minshall 9 8
c From jbvb, fixes for BufferAddress in PT and fixes to EUA.
c From me, first cut fixes for PT.
e
s 00028/00016/00481
d D 1.8 87/05/10 13:01:07 minshall 8 7
c Get rid of FieldForward, FieldReverse.
e
s 00006/00002/00491
d D 1.7 87/04/01 14:38:46 minshall 7 6
c Make close/open sequences work in a more rational way.
e
s 00044/00003/00449
d D 1.6 86/12/19 17:07:35 minshall 6 5
c Seems to work with 'close' then 'open'
e
s 00007/00004/00445
d D 1.5 86/11/16 20:43:58 minshall 5 4
c 1) Complete move of bsubs to ../system.  2) Deal with an 
c inadequacy in msc compiler.
e
s 00016/00004/00433
d D 1.4 86/11/16 15:21:25 minshall 4 3
c Turn FCN_... into enum, rather than  #define's.
e
s 00006/00101/00431
d D 1.3 86/11/16 10:58:34 minshall 3 2
c More all the transparent (or most) to the system dependent files. 
c Change the interface for ExitString (so that we don't need to include 
c stdio.h).
e
s 00000/00001/00532
d D 1.2 86/11/12 17:16:27 minshall 2 1
c This version has the attribute bytes inline (3278 style).
e
s 00533/00000/00000
d D 1.1 86/11/11 22:54:07 minshall 1 0
c date and time created 86/11/11 22:54:07 by minshall
e
u
U
t
T
I 1
/*
D 22
 *	Copyright (c) 1984, 1985, 1986 by the Regents of the
E 22
I 22
D 25
 *	Copyright (c) 1984-1987 by the Regents of the
E 22
 *	University of California and by Gregory Glenn Minshall.
E 25
I 25
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 25
 *
D 25
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
E 25
I 25
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 25
 */

#ifndef lint
D 22
static	char	sccsid[] = "@(#)outbound.c	3.1  10/29/86";
E 22
I 22
static char sccsid[] = "%W% (Berkeley) %G%";
E 22
D 25
#endif	/* lint */

E 25
I 25
#endif /* not lint */
E 25

I 11
#include <stdio.h>

D 14
#include "../general.h"
E 14
I 14
#include "../general/general.h"
E 14

E 11
D 3
#if	defined(unix)
#include <signal.h>
#endif	/* defined(unix) */
E 3
D 5
#include <stdio.h>

E 5
#include "hostctlr.h"
I 15
#include "oia.h"
E 15
#include "screen.h"
D 19
#include "ebc_disp.h"
E 19
I 19
D 21
#include "../apilib/ebc_disp.h"
E 21
I 21
#include "../api/ebc_disp.h"
E 21
E 19

D 14
#include "../system/globals.h"
E 14
I 14
#include "../general/globals.h"
E 14
#include "options.ext"
#include "../telnet.ext"
#include "inbound.ext"
#include "outbound.ext"
D 5
#include "bsubs.ext"
E 5
I 5
D 14
#include "../system/bsubs.ext"
E 14
I 14
#include "../general/bsubs.ext"
E 14
E 5

#define SetHighestLowest(position) { \
					if (position < Lowest) { \
					    Lowest = position; \
					} \
					if (position > Highest) { \
					    Highest = position; \
					} \
				    }

D 3
#if	defined(unix)
extern int	tin, tout;		/* file descriptors */
#endif	/* defined(unix) */
E 3

I 6
static int	LastWasTerminated = 1;	/* was "control" = 1 last time? */

E 6
D 3

#if	defined(unix)
static int tcflag = -1;			/* transparent mode command flag */
static int savefd[2];			/* for storing fds during transcom */
#endif	/* defined(unix) */

E 3
/* some globals */

I 4
#if	!defined(PURE3274)
E 4
D 6
int	OutputClock = 0;		/* what time it is */
int	TransparentClock = 0;		/* time we were last in transparent */
E 6
I 6
int	OutputClock;		/* what time it is */
int	TransparentClock;		/* time we were last in transparent */
E 6
I 4
#endif	/* !defined(PURE3274) */
E 4
D 11

E 11

char CIABuffer[64] = {
    0x40, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7,
    0xc8, 0xc9, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
    0x50, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7,
    0xd8, 0xd9, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
    0x60, 0x61, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7,
    0xe8, 0xe9, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f,
    0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7,
    0xf8, 0xf9, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f
};
I 11

static struct orders_def orders_def[] = ORDERS_DEF;
E 11

I 6
/*
D 7
 * ctlrinit()
E 7
I 7
 * init_ctlr()
E 7
 *
 *	Initialize all data from the 'data' portion to their startup values.
 */

void
D 7
ctlrinit()
E 7
I 7
init_ctlr()
E 7
{
    LastWasTerminated = 1;
I 7
D 20
#if	!defined(PURE3274)
    OutputClock = TransparentClock = 0;
#endif	/* !defined(PURE3274) */
E 20
    init_inbound();
I 15
    init_oia();
E 15
E 7
}

E 6
D 8
/* What we know is that table is of size ScreenSize */
E 8

D 8
FieldFind(table, position, failure)
register char *table;		/* which table of bytes to use */
register int position;		/* what position to start from */
int failure;			/* if unformatted, what value to return */
E 8
I 8
FieldInc(position)
register int	position;		/* Position in previous field */
E 8
{
D 8
    register int ourp;
E 8
I 8
    register ScreenImage *ptr;
E 8

D 8
    ourp = position + 1 + bskip(table+position+1, ScreenSize-position-1, 0);
    if (ourp < ScreenSize) {
	return(ourp);
E 8
I 8
    ptr = (ScreenImage *)memNSchr((char *)Host+position+1, ATTR_MASK,
			HighestScreen()-position, ATTR_MASK, sizeof Host[0]);
    if (ptr == 0) {
	ptr = (ScreenImage *)memNSchr((char *)Host+LowestScreen(), ATTR_MASK,
			position-LowestScreen(), ATTR_MASK, sizeof Host[0]);
	if (ptr == 0) {
	    return LowestScreen();
	}
E 8
    }
D 8
    /* No fields in table after position.  Look for fields from beginning
     * of table.
     */
    ourp = bskip(table, position+1, 0);
    if (ourp <= position) {
	return(ourp);
E 8
I 8
    return ptr-Host;
}

FieldDec(position)
int	position;
{
    register ScreenImage *ptr;

    ptr = (ScreenImage *)memNSchr((char *)(Host+position)-1, ATTR_MASK,
			position-LowestScreen(), ATTR_MASK, -sizeof Host[0]);
    if (ptr == 0) {
	ptr = (ScreenImage *)memNSchr((char *)Host+HighestScreen(), ATTR_MASK,
			HighestScreen()-position, ATTR_MASK, -sizeof Host[0]);
	if (ptr == 0) {
D 10
	    return HighestScreen();
E 10
I 10
	    return LowestScreen();
E 10
	}
E 8
    }
D 8
    return(failure);
E 8
I 8
    return ptr-Host;
E 8
}

/* Clear3270 - called to clear the screen */

void
Clear3270()
{
D 12
    bzero((char *)Host, sizeof(Host));
E 12
I 12
    ClearArray(Host);
E 12
    DeleteAllFields();		/* get rid of all fields */
    BufferAddress = SetBufferAddress(0,0);
    CursorAddress = SetBufferAddress(0,0);
    Lowest = LowestScreen();
    Highest = HighestScreen();
}

/* AddHost - called to add a character to the buffer.
 *	We use a macro in this module, since we call it so
 *	often from loops.
 *
 *	NOTE: It is a macro, so don't go around using AddHost(p, *c++), or
 *	anything similar.  (I don't define any temporary variables, again
 *	just for the speed.)
 */
void
AddHost(position, character)
int	position;
char	character;
{
D 18
#if	defined(SLOWSCREEN)
E 18
#   define	AddHostA(p,c)					\
    {								\
	if (IsStartField(p)) {					\
	    DeleteField(p);					\
	    Highest = HighestScreen();				\
	    Lowest = LowestScreen();				\
	    SetHighestLowest(p);				\
	}							\
	SetHost(p, c);						\
    }
#   define	AddHost(p,c)					\
    {								\
	if (c != GetHost(p)) {					\
	    SetHighestLowest(p);				\
	}							\
	AddHostA(p,c);						\
    }	/* end of macro of AddHost */
D 18
#else	/* defined(SLOWSCREEN) */
#   define	AddHost(p,c)					\
    {								\
	if (IsStartField(p)) {					\
	    DeleteField(p);					\
	    Highest = HighestScreen();				\
	    Lowest = LowestScreen();				\
	    SetHost(p, c);					\
	} else {						\
	    SetHost(p, c);					\
	    SetHighestLowest(p);				\
	}							\
    }	/* end of macro of AddHost */
#endif	/* defined(SLOWSCREEN) */
E 18

    AddHost(position, character);
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
D 6
    static int	LastWasTerminated = 1;	/* was "control" = 1 last time? */
E 6
D 3
#if	defined(unix)
    extern char *transcom;
    int inpipefd[2], outpipefd[2], savemode, aborttc();
#endif	/* defined(unix) */
E 3

    origCount = count;

I 20
    /*
     * If this is the start of a new data stream, then look
     * for an op-code and (possibly) a WCC.
     */
E 20
    if (LastWasTerminated) {

	if (count < 2) {
	    if (count == 0) {
D 3
		StringToTerminal("Short count received from host!\n");
E 3
I 3
D 11
		ExitString("Short count received from host!\n", 1);
E 11
I 11
		ExitString(stderr, "Short count received from host!\n", 1);
E 11
E 3
		return(count);
	    }
	    Command = buffer[0];
	    switch (Command) {		/* This had better be a read command */
	    case CMD_READ_MODIFIED:
	    case CMD_SNA_READ_MODIFIED:
	    case CMD_SNA_READ_MODIFIED_ALL:
I 12
D 15
		OiaOnlineA(1);
E 15
I 15
		SetOiaOnlineA(&OperatorInformationArea);
		SetOiaModified();
E 15
E 12
		DoReadModified(Command);
		break;
	    case CMD_READ_BUFFER:
	    case CMD_SNA_READ_BUFFER:
I 12
D 15
		OiaOnlineA(1);
E 15
I 15
		SetOiaOnlineA(&OperatorInformationArea);
		SetOiaModified();
E 15
E 12
		DoReadBuffer();
		break;
	    default:
D 12
		break;
E 12
I 12
		{
		    char buffer[100];

		    sprintf(buffer,
			"Unexpected read command code 0x%x received.\n",
								    Command);
		    ExitString(stderr, buffer, 1);
		    break;
		}
E 12
	    }
	    return(1);			/* We consumed everything */
	}
	Command = buffer[0];
	Wcc = buffer[1];
	if (Wcc & WCC_RESET_MDT) {
	    i = c = WhereAttrByte(LowestScreen());
	    do {
		if (HasMdt(i)) {
		    TurnOffMdt(i);
		}
		i = FieldInc(i);
	    } while (i != c);
	}

	switch (Command) {
	case CMD_ERASE_WRITE:
	case CMD_ERASE_WRITE_ALTERNATE:
	case CMD_SNA_ERASE_WRITE:
	case CMD_SNA_ERASE_WRITE_ALTERNATE:
	    {
		int newlines, newcolumns;

I 12
D 15
		OiaOnlineA(1);
		OiaTWait(0);
E 15
I 15
		SetOiaOnlineA(&OperatorInformationArea);
		ResetOiaTWait(&OperatorInformationArea);
		SetOiaModified();
E 15
E 12
D 3
#if	defined(unix)
		if (tcflag == 0) {
		   tcflag = -1;
		   (void) signal(SIGCHLD, SIG_DFL);
		} else if (tcflag > 0) {
		   setcommandmode();
		   (void) close(tin);
		   (void) close(tout);
		   tin = savefd[0];
		   tout = savefd[1];
		   setconnmode();
		   tcflag = -1;
		   (void) signal(SIGCHLD, SIG_DFL);
		}
#endif	/* defined(unix) */
E 3
		if ((Command == CMD_ERASE_WRITE)
				|| (Command == CMD_SNA_ERASE_WRITE)) {
		    newlines = 24;
		    newcolumns = 80;
		} else {
		    newlines = MaxNumberLines;
		    newcolumns = MaxNumberColumns;
		}
		if ((newlines != NumberLines)
				|| (newcolumns != NumberColumns)) {
			/*
			 * The LocalClearScreen() is really for when we
			 * are going from a larger screen to a smaller
			 * screen, and we need to clear off the stuff
			 * at the end of the lines, or the lines at
			 * the end of the screen.
			 */
		    LocalClearScreen();
		    NumberLines = newlines;
		    NumberColumns = newcolumns;
		    ScreenSize = NumberLines * NumberColumns;
		}
		Clear3270();
I 4
#if	!defined(PURE3274)
E 4
		if (TransparentClock == OutputClock) {
D 3
		    RefreshScreen();
E 3
I 3
		    TransStop();
E 3
		}
I 4
#endif	/* !defined(PURE3274) */
E 4
		break;
	    }

	case CMD_ERASE_ALL_UNPROTECTED:
	case CMD_SNA_ERASE_ALL_UNPROTECTED:
I 12
D 15
	    OiaOnlineA(1);
	    OiaTWait(0);
E 15
I 15
	    SetOiaOnlineA(&OperatorInformationArea);
	    ResetOiaTWait(&OperatorInformationArea);
	    SetOiaModified();
E 15
E 12
	    CursorAddress = HighestScreen()+1;
	    for (i = LowestScreen(); i <= HighestScreen(); i = ScreenInc(i)) {
		if (IsUnProtected(i)) {
		    if (CursorAddress > i) {
			CursorAddress = i;
		    }
		    AddHost(i, '\0');
		}
		if (HasMdt(i)) {
		    TurnOffMdt(i);
		}
	    }
	    if (CursorAddress == HighestScreen()+1) {
		CursorAddress = SetBufferAddress(0,0);
	    }
	    UnLocked = 1;
	    AidByte = 0;
I 13
D 15
	    OiaSystemLocked(0);
E 15
I 15
	    ResetOiaSystemLocked(&OperatorInformationArea);
	    SetOiaModified();
E 15
	    TerminalIn();
E 13
	    break;
	case CMD_WRITE:
	case CMD_SNA_WRITE:
I 12
D 15
	    OiaOnlineA(1);
	    OiaTWait(0);
E 15
I 15
	    SetOiaOnlineA(&OperatorInformationArea);
	    ResetOiaTWait(&OperatorInformationArea);
	    SetOiaModified();
E 15
E 12
	    break;
	default:
	    {
		char buffer[100];

D 12
		sprintf(buffer, "Unexpected command code 0x%x received.\n",
E 12
I 12
		sprintf(buffer,
			"Unexpected write command code 0x%x received.\n",
E 12
								Command);
D 3
		ExitString(stderr, buffer, 1);
E 3
I 3
D 11
		ExitString(buffer, 1);
E 11
I 11
		ExitString(stderr, buffer, 1);
E 11
E 3
		break;
	    }
	}

	count -= 2;			/* strip off command and wcc */
	buffer += 2;

I 20
    } else {
#if	!defined(PURE3274)
	if (TransparentClock == OutputClock) {
	    TransOut(buffer, count, -1, control);
	    count = 0;
	}
#endif	/* !defined(PURE3274) */
E 20
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
		if ( ! (IsStartField(BufferAddress) &&
					FieldAttributes(BufferAddress) == c)) {
		    SetHighestLowest(BufferAddress);
		    NewField(BufferAddress,c);
		}
D 2
		SetHost(BufferAddress, 0);
E 2
		BufferAddress = ScreenInc(BufferAddress);
		break;
	    case ORDER_SBA:
		Ensure(2);
		i = buffer[0];
		c = buffer[1];
I 4
#if	!defined(PURE3274)
E 4
D 20
		if (!i && !c) { /* transparent write */
		    if (!control) {
			return(origCount-(count+1));
		    } else {
D 3
			while (DoTerminalOutput() == 0) {
#if defined(unix)
			    HaveInput = 0;
#endif /* defined(unix) */
			}
			TransparentClock = OutputClock; 	/* this clock */
#if	defined(unix)
			if (transcom && tcflag == -1) {
			   while (1) {			  /* go thru once */
				 if (pipe(outpipefd) < 0) {
				    break;
				 }
				 if (pipe(inpipefd) < 0) {
				    break;
				 }
			         if ((tcflag = fork()) == 0) {
				    (void) close(outpipefd[1]);
				    (void) close(0);
				    if (dup(outpipefd[0]) < 0) {
				       exit(1);
				    }
				    (void) close(outpipefd[0]);
				    (void) close(inpipefd[0]);
				    (void) close(1);
				    if (dup(inpipefd[1]) < 0) {
				       exit(1);
				    }
				    (void) close(inpipefd[1]);
				    if (execl("/bin/csh", "csh", "-c", transcom, (char *) 0)) {
					exit(1);
				    }
				 }
				 (void) close(inpipefd[1]);
				 (void) close(outpipefd[0]);
				 savefd[0] = tin;
				 savefd[1] = tout;
				 setcommandmode();
				 tin = inpipefd[0];
				 tout = outpipefd[1];
				 (void) signal(SIGCHLD, aborttc);
				 setconnmode();
				 tcflag = 1;
				 break;
			   }
			   if (tcflag < 1) {
			      tcflag = 0;
			   }
			}
#endif	/* defined(unix) */
			(void) DataToTerminal(buffer+2, count-2);
			SendToIBM();
E 3
I 3
			TransparentClock = OutputClock;		/* clock next */
			TransOut(buffer+2, count-2);		/* output */
			SendToIBM();				/* ack block */
E 3
			TransparentClock = OutputClock+1;	/* clock next */
			buffer += count;
			count -= count;
		    }
E 20
I 20
		/* Check for transparent write */
		if ((i == 0) && ((c == 0) || (c == 1) || (c == 5))) {
		    TransparentClock = OutputClock+1;
		    TransOut(buffer+2, count-2, c, control);
		    buffer += count;
		    count -= count;
E 20
D 4
		} else {
		    BufferAddress = Addr3270(i, c);
		    buffer += 2;
		    count -= 2;
E 4
I 4
		    break;
E 4
		}
I 4
#endif	/* !defined(PURE3274) */
		BufferAddress = Addr3270(i, c);
		buffer += 2;
		count -= 2;
E 4
		break;
	    case ORDER_IC:
		CursorAddress = BufferAddress;
		break;
I 9
	    /*
	     * XXX - PT is supposed to null fill the screen buffer
	     * under certain draconian conditions.
	     */
E 9
	    case ORDER_PT:
D 9
		for (i = ScreenInc(BufferAddress); (i != HighestScreen());
				i = ScreenInc(i)) {
E 9
I 9
		i = BufferAddress;
		do {
E 9
		    if (IsStartField(i)) {
D 9
			i = ScreenInc(i);
E 9
			if (!IsProtected(ScreenInc(i))) {
			    break;
			}
D 9
			if (i == HighestScreen()) {
			    break;
			}
E 9
		    }
D 9
		}
		CursorAddress = i;
E 9
I 9
		    i = ScreenInc(i);
		} while (i != HighestScreen());
		BufferAddress = ScreenInc(i);
E 9
		break;
	    case ORDER_RA:
		Ensure(3);
		i = Addr3270(buffer[0], buffer[1]);
		c = buffer[2];
I 11
		if (c == ORDER_GE) {
		    Ensure(4);
		    c = buffer[3];
		    buffer += 4;
		    count -= 4;
		} else {
		    buffer += 3;
		    count -= 3;
		}
E 11
		do {
		    AddHost(BufferAddress, ebc_disp[c]);
		    BufferAddress = ScreenInc(BufferAddress);
		} while (BufferAddress != i);
D 11
		buffer += 3;
		count -= 3;
E 11
		break;
	    case ORDER_EUA:    /* (from [here,there), ie: half open interval] */
		Ensure(2);
D 5
		c = FieldAttributes(WhereAttrByte(BufferAddress));
E 5
I 5
		/*
		 * Compiler error - msc version 4.0:
		 *			"expression too complicated".
		 */
		i = WhereAttrByte(BufferAddress);
		c = FieldAttributes(i);
E 5
D 24
		for (i = Addr3270(buffer[0], buffer[1]); i != BufferAddress;
				BufferAddress = ScreenInc(BufferAddress)) {
E 24
I 24
		i = Addr3270(buffer[0], buffer[1]);
		do {
E 24
D 9
		    if (!IsProtectedAttr(BufferAddress, c)) {
E 9
I 9
		    if (IsStartField(BufferAddress)) {
			c = FieldAttributes(BufferAddress);
		    } else if (!IsProtectedAttr(BufferAddress, c)) {
E 9
			AddHost(BufferAddress, 0);
		    }
D 24
		}
E 24
I 24
		    BufferAddress = ScreenInc(BufferAddress);
		} while (i != BufferAddress);
E 24
		buffer += 2;
		count -= 2;
		break;
I 11
	    case ORDER_GE:
		Ensure(2);
		/* XXX Should do SOMETHING! */
		buffer += 0;
		count -= 0;		/* For now, just use this character */
		break;
E 11
	    case ORDER_YALE:		/* special YALE defined order */
		Ensure(2);	/* need at least two characters */
		if (*buffer == 0x5b) {
		    i = OptOrder(buffer+1, count-1, control);
		    if (i == 0) {
			return(origCount-(count+1));	/* come here again */
		    } else {
			buffer += 1 + i;
			count  -= (1 + i);
		    }
		}
		break;
	    default:
D 11
		break;				/* XXX ? */
E 11
I 11
		{
		    char buffer[100];
		    static struct orders_def unk_order
						= { 0, "??", "(unknown)" };
		    struct orders_def *porder = &unk_order;
		    int i;

		    for (i = 0; i <= highestof(orders_def); i++) {
			if (orders_def[i].code == c) {
			    porder = &orders_def[i];
			    break;
			}
		    }
		    sprintf(buffer,
			"Unsupported order '%s' (%s, 0x%x) received.\n",
			porder->long_name, porder->short_name, c);
		    ExitString(stderr, buffer, 1);
		    /*NOTREACHED*/
		}
E 11
	    }
	    if (count < 0) {
		count = 0;
	    }
	} else {
	    /* Data comes in large clumps - take it all */
	    i = BufferAddress;
D 18
#if	!defined(SLOWSCREEN)
	    AddHost(i, ebc_disp[c]);
#else	/* !defined(SLOWSCREEN) */
E 18
	    AddHostA(i, ebc_disp[c]);
	    SetHighestLowest(i);
D 18
#endif	/* !defined(SLOWSCREEN) */
E 18
	    i = ScreenInc(i);
	    c = *buffer;
	    while (count && !IsOrder(c)) {
D 18
#if	!defined(SLOWSCREEN)
		AddHost(i, ebc_disp[c]);
#else	/* !defined(SLOWSCREEN) */
E 18
		AddHostA(i, ebc_disp[c]);
D 18
#endif	/* !defined(SLOWSCREEN) */
E 18
		i = ScreenInc(i);
D 18
#if	defined(SLOWSCREEN)
E 18
		if (i == LowestScreen()) {
		    SetHighestLowest(HighestScreen());
		}
D 18
#endif	/* defined(SLOWSCREEN) */
E 18
		count--;
		buffer++;
		c = *buffer;
	    }
D 18
#if	defined(SLOWSCREEN)
E 18
	    SetHighestLowest(i);
D 18
#endif	/* defined(SLOWSCREEN) */
E 18
	    BufferAddress = i;
	}
    }
    if (count == 0) {
I 20
	if (control) {
E 20
I 4
#if	!defined(PURE3274)
E 4
D 20
	OutputClock++;		/* time rolls on */
E 20
I 20
	    OutputClock++;		/* time rolls on */
E 20
I 4
#endif	/* !defined(PURE3274) */
E 4
D 20
	if (control) {
E 20
	    if (Wcc & WCC_RESTORE) {
I 4
#if	!defined(PURE3274)
E 4
		if (TransparentClock != OutputClock) {
		    AidByte = 0;
		}
I 4
#else	/* !defined(PURE3274) */
		AidByte = 0;
#endif	/* !defined(PURE3274) */
E 4
		UnLocked = 1;
I 12
D 15
		OiaSystemLocked(0);
E 15
I 15
		ResetOiaSystemLocked(&OperatorInformationArea);
		SetOiaModified();
I 17
		SetPsModified();
E 17
E 15
I 13
		TerminalIn();
E 13
E 12
	    }
	    if (Wcc & WCC_ALARM) {
		RingBell(0);
	    }
	}
	LastWasTerminated = control;	/* state for next time */
	return(origCount);
    } else {
	return(origCount-count);
    }
I 6
}

/*
 * Init3270()
 *
 * Initialize any 3270 (controller) variables to an initial state
 * in preparation for accepting a connection.
 */

void
Init3270()
{
I 11
    int i;

E 11
    OptInit();		/* initialize mappings */

D 12
    bzero((char *)Host, sizeof Host);	/* Clear host */
E 12
I 12
    ClearArray(Host);
E 12

D 12
    bzero(Orders, sizeof Orders);
E 12
I 12
    ClearArray(Orders);
E 12
D 11
    Orders[ORDER_SF] = Orders[ORDER_SBA] = Orders[ORDER_IC]
	    = Orders[ORDER_PT] = Orders[ORDER_RA] = Orders[ORDER_EUA]
	    = Orders[ORDER_YALE] = 1;	/* What is an order */
E 11
I 11
    for (i = 0; i <= highestof(orders_def); i++) {
	Orders[orders_def[i].code] = 1;
    }
E 11

    DeleteAllFields();		/* Clear screen */
    Lowest = HighestScreen()+1;
    Highest = LowestScreen()-1;
    CursorAddress = BufferAddress = SetBufferAddress(0,0);
    UnLocked = 1;
I 20
#if	!defined(PURE3274)
E 20
    OutputClock = 1;
    TransparentClock = -1;
I 20
#endif	/* !defined(PURE3274) */
E 20
I 16
    SetOiaReady3274(&OperatorInformationArea);
}


void
Stop3270()
{
    ResetOiaReady3274(&OperatorInformationArea);
E 16
E 6
}
D 3


#if	defined(unix)
aborttc()
{
	int savemode;

	setcommandmode();
	(void) close(tin);
	(void) close(tout);
	tin = savefd[0];
	tout = savefd[1];
	setconnmode();
	tcflag = 0;
}
#endif	/* defined(unix) */
E 3
E 1
