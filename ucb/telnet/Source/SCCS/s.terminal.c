h08808
s 00016/00000/00113
d D 1.11 88/03/08 10:31:18 bostic 11 10
c add Berkeley specific copyright
e
s 00004/00004/00109
d D 1.10 88/01/07 11:54:04 minshall 10 9
c Reduce extern's.
e
s 00015/00003/00098
d D 1.9 87/11/23 20:37:56 minshall 9 8
c Fixes from Dave Borman.
e
s 00000/00039/00101
d D 1.8 87/10/27 16:00:14 minshall 8 7
c Remove some unix specific things.
e
s 00003/00002/00137
d D 1.7 87/10/23 15:15:41 minshall 7 6
c Try to move system dependent stuff to system dependent files.
e
s 00003/00003/00136
d D 1.6 87/10/23 11:57:19 minshall 6 5
c Make the ring buffer a two-state buffer (supplier and consumer)
c rather than a three-state buffer (supplier, sender, and acker).
e
s 00001/00001/00138
d D 1.5 87/10/10 17:45:46 minshall 5 4
c sending is also acking.
e
s 00009/00008/00130
d D 1.4 87/10/10 14:27:20 minshall 4 3
c This is the first version to get near rings.  It compiles,
c but doesn't work.
e
s 00005/00004/00133
d D 1.3 87/09/25 16:06:49 minshall 3 2
c Cut down on number of extern's.
e
s 00000/00227/00137
d D 1.2 87/09/25 14:49:49 minshall 2 1
c Move a number of tn3270-items to tn3270.c
e
s 00364/00000/00000
d D 1.1 87/09/11 15:40:50 minshall 1 0
c date and time created 87/09/11 15:40:50 by minshall
e
u
U
t
T
I 11
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

E 11
I 1
#include <arpa/telnet.h>
I 4
#include <sys/types.h>
E 4

I 4
#include "ring.h"

E 4
#include "externs.h"
#include "types.h"

D 4
char	ttyobuf[2*BUFSIZ], *tfrontp, *tbackp;
E 4
I 4
D 7
Ring	ttyoring;
char	ttyobuf[2*BUFSIZ];
E 7
I 7
Ring	ttyoring, ttyiring;
char	ttyobuf[2*BUFSIZ], ttyibuf[BUFSIZ];
E 7
E 4

char
    termEofChar,
    termEraseChar,
    termFlushChar,
    termIntChar,
    termKillChar,
    termLiteralNextChar,
    termQuitChar;

/*
 * initialize the terminal data structures.
 */

init_terminal()
{
D 4
    tfrontp = tbackp = ttyobuf;
E 4
I 4
    ring_init(&ttyoring, ttyobuf, sizeof ttyobuf);
I 7
    ring_init(&ttyiring, ttyibuf, sizeof ttyibuf);
E 7
E 4
    autoflush = TerminalAutoFlush();
}


/*
 *		Send as much data as possible to the terminal.
 *
 *		The return value indicates whether we did any
 *	useful work.
 */


int
D 3
ttyflush()
E 3
I 3
ttyflush(drop)
int drop;
E 3
{
D 9
    int n;
E 9
I 9
    register int n, n0, n1;
E 9

D 4
    if ((n = tfrontp - tbackp) > 0) {
E 4
I 4
D 6
    if ((n = ring_unsent_consecutive(&ttyoring)) > 0) {
E 6
I 6
D 9
    if ((n = ring_full_consecutive(&ttyoring)) > 0) {
E 9
I 9
    n0 = ring_full_count(&ttyoring);
    if ((n1 = n = ring_full_consecutive(&ttyoring)) > 0) {
E 9
E 6
E 4
D 3
	if (!(SYNCHing||flushout)) {
	    n = TerminalWrite(tout, tbackp, n);
	} else {
E 3
I 3
	if (drop) {
E 3
	    TerminalFlushOutput();
	    /* we leave 'n' alone! */
I 3
	} else {
D 4
	    n = TerminalWrite(tout, tbackp, n);
E 4
I 4
D 6
	    n = TerminalWrite(tout, ttyoring.send, n);
E 6
I 6
D 10
	    n = TerminalWrite(tout, ttyoring.consume, n);
E 10
I 10
	    n = TerminalWrite(ttyoring.consume, n);
E 10
E 6
E 4
E 3
	}
    }
D 9
    if (n >= 0) {
E 9
I 9
    if (n > 0) {
	/*
	 * If we wrote everything, and the full count is
	 * larger than what we wrote, then write the
	 * rest of the buffer.
	 */
	if (n1 == n && n0 > n) {
		n1 = n0 - n;
		if (!drop)
D 10
			n1 = TerminalWrite(tout, ttyoring.bottom, n1);
E 10
I 10
			n1 = TerminalWrite(ttyoring.bottom, n1);
E 10
		n += n1;
	}
E 9
D 4
	tbackp += n;
	if (tbackp == tfrontp) {
	    tbackp = tfrontp = ttyobuf;
	}
E 4
I 4
D 5
	ring_sent(&ttyoring, n);
E 5
I 5
D 6
	ring_sent_acked(&ttyoring, n);
E 6
I 6
	ring_consumed(&ttyoring, n);
E 6
E 5
E 4
    }
    return n > 0;
}

D 2
#if	defined(TN3270)

#if	defined(unix)
static void
inputAvailable()
{
    HaveInput = 1;
}
#endif	/* defined(unix) */

void
outputPurge()
{
    int tmp = flushout;

    flushout = 1;

    ttyflush();

    flushout = tmp;
}

#endif	/* defined(TN3270) */
E 2

D 8
#if	defined(unix)
/*
 * Various signal handling routines.
 */

void
deadpeer()
{
	setcommandmode();
	longjmp(peerdied, -1);
}

void
intr()
{
    if (localchars) {
	intp();
	return;
    }
    setcommandmode();
    longjmp(toplevel, -1);
}

void
intr2()
{
    if (localchars) {
	sendbrk();
	return;
    }
}

void
doescape()
{
    command(0);
}
#endif	/* defined(unix) */

E 8
/*
 * These routines decides on what the mode should be (based on the values
 * of various global variables).
 */


int
getconnmode()
{
    static char newmode[16] =
			{ 4, 5, 3, 3, 2, 2, 1, 1, 6, 6, 6, 6, 6, 6, 6, 6 };
    int modeindex = 0;

    if (dontlecho && (clocks.echotoggle > clocks.modenegotiated)) {
	modeindex += 1;
    }
    if (hisopts[TELOPT_ECHO]) {
	modeindex += 2;
    }
    if (hisopts[TELOPT_SGA]) {
	modeindex += 4;
    }
    if (In3270) {
	modeindex += 8;
    }
    return newmode[modeindex];
}

void
setconnmode()
{
D 10
    TerminalNewMode(tin, tout, getconnmode());
E 10
I 10
    TerminalNewMode(getconnmode());
E 10
}


void
setcommandmode()
{
D 10
    TerminalNewMode(tin, tout, 0);
E 10
I 10
    TerminalNewMode(0);
E 10
}
D 2

#if	defined(TN3270)

/*
 * The following routines are places where the various tn3270
 * routines make calls into telnet.c.
 */

/* TtyChars() - returns the number of characters in the TTY buffer */
TtyChars()
{
    return(tfrontp-tbackp);
}

/*
 * DataToNetwork - queue up some data to go to network.  If "done" is set,
 * then when last byte is queued, we add on an IAC EOR sequence (so,
 * don't call us with "done" until you want that done...)
 *
 * We actually do send all the data to the network buffer, since our
 * only client needs for us to do that.
 */

int
DataToNetwork(buffer, count, done)
register char	*buffer;	/* where the data is */
register int	count;		/* how much to send */
int		done;		/* is this the last of a logical block */
{
    register int c;
    int origCount;
    fd_set o;

    origCount = count;
    FD_ZERO(&o);

    while (count) {
	if ((netobuf+sizeof netobuf - nfrontp) < 6) {
	    netflush();
	    while ((netobuf+sizeof netobuf - nfrontp) < 6) {
		FD_SET(net, &o);
		(void) select(net+1, (fd_set *) 0, &o, (fd_set *) 0,
						(struct timeval *) 0);
		netflush();
	    }
	}
	c = *buffer++;
	count--;
	if (c == IAC) {
	    *nfrontp++ = IAC;
	    *nfrontp++ = IAC;
	} else {
	    *nfrontp++ = c;
	}
    }

    if (done && !count) {
	*nfrontp++ = IAC;
	*nfrontp++ = EOR;
	netflush();		/* try to move along as quickly as ... */
    }
    return(origCount - count);
}

/* DataToTerminal - queue up some data to go to terminal. */

int
DataToTerminal(buffer, count)
register char	*buffer;		/* where the data is */
register int	count;			/* how much to send */
{
    int origCount;
#if	defined(unix)
    fd_set	o;

    FD_ZERO(&o);
#endif	/* defined(unix) */
    origCount = count;

    while (count) {
	if (tfrontp >= ttyobuf+sizeof ttyobuf) {
	    ttyflush();
	    while (tfrontp >= ttyobuf+sizeof ttyobuf) {
#if	defined(unix)
		FD_SET(tout, &o);
		(void) select(tout+1, (fd_set *) 0, &o, (fd_set *) 0,
						(struct timeval *) 0);
#endif	/* defined(unix) */
		ttyflush();
	    }
	}
	*tfrontp++ = *buffer++;
	count--;
    }
    return(origCount - count);
}

/* EmptyTerminal - called to make sure that the terminal buffer is empty.
 *			Note that we consider the buffer to run all the
 *			way to the kernel (thus the select).
 */

void
EmptyTerminal()
{
#if	defined(unix)
    fd_set	o;

    FD_ZERO(&o);
#endif	/* defined(unix) */

    if (tfrontp == tbackp) {
#if	defined(unix)
	FD_SET(tout, &o);
	(void) select(tout+1, (int *) 0, &o, (int *) 0,
			(struct timeval *) 0);	/* wait for TTLOWAT */
#endif	/* defined(unix) */
    } else {
	while (tfrontp != tbackp) {
	    ttyflush();
#if	defined(unix)
	    FD_SET(tout, &o);
	    (void) select(tout+1, (int *) 0, &o, (int *) 0,
				(struct timeval *) 0);	/* wait for TTLOWAT */
#endif	/* defined(unix) */
	}
    }
}


/*
 * Push3270 - Try to send data along the 3270 output (to screen) direction.
 */

static int
Push3270()
{
    int save = scc;

    if (scc) {
	if (Ifrontp+scc > Ibuf+sizeof Ibuf) {
	    if (Ibackp != Ibuf) {
		memcpy(Ibuf, Ibackp, Ifrontp-Ibackp);
		Ifrontp -= (Ibackp-Ibuf);
		Ibackp = Ibuf;
	    }
	}
	if (Ifrontp+scc < Ibuf+sizeof Ibuf) {
	    telrcv();
	}
    }
    return save != scc;
}


/*
 * Finish3270 - get the last dregs of 3270 data out to the terminal
 *		before quitting.
 */

static void
Finish3270()
{
    while (Push3270() || !DoTerminalOutput()) {
#if	defined(unix)
	HaveInput = 0;
#endif	/* defined(unix) */
	;
    }
}


/* StringToTerminal - output a null terminated string to the terminal */

void
StringToTerminal(s)
char *s;
{
    int count;

    count = strlen(s);
    if (count) {
	(void) DataToTerminal(s, count);	/* we know it always goes... */
    }
}


#if	((!defined(NOT43)) || defined(PUTCHAR))
/* _putchar - output a single character to the terminal.  This name is so that
 *	curses(3x) can call us to send out data.
 */

void
_putchar(c)
char c;
{
    if (tfrontp >= ttyobuf+sizeof ttyobuf) {
	(void) DataToTerminal(&c, 1);
    } else {
	*tfrontp++ = c;		/* optimize if possible. */
    }
}
#endif	/* ((!defined(NOT43)) || defined(PUTCHAR)) */
#endif	/* defined(TN3270) */
E 2
E 1
