h48191
s 00001/00001/00447
d D 1.10 88/05/15 20:49:22 minshall 10 9
c buffer is signed, but IAC is 0x255 (the twain shall never meet).
e
s 00002/00000/00446
d D 1.9 88/05/15 19:24:37 minshall 9 8
c Include "general.h" to get rid of ansi mem* functions.
e
s 00023/00017/00423
d D 1.8 88/05/15 12:47:15 minshall 8 7
c make it work for tn3270.
e
s 00111/00080/00329
d D 1.7 88/03/27 13:47:44 minshall 7 6
c Make *compiles* with -DTN3270 work.
e
s 00016/00000/00393
d D 1.6 88/03/08 10:31:20 bostic 6 5
c add Berkeley specific copyright
e
s 00002/00000/00391
d D 1.5 87/11/23 11:15:32 minshall 5 4
c Add in some changes from Dave Borman (borman@monet).
e
s 00027/00000/00364
d D 1.4 87/10/27 16:00:44 minshall 4 3
c Pick up some more tn3270-specific function.
e
s 00131/00000/00233
d D 1.3 87/10/23 15:15:43 minshall 3 2
c Try to move system dependent stuff to system dependent files.
e
s 00004/00010/00229
d D 1.2 87/09/25 16:06:51 minshall 2 1
c Cut down on number of extern's.
e
s 00239/00000/00000
d D 1.1 87/09/15 13:45:08 minshall 1 0
c date and time created 87/09/15 13:45:08 by minshall
e
u
U
t
T
I 6
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

I 7
#include <sys/types.h>
#include <arpa/telnet.h>

I 9
#include "general.h"

E 9
#include "defines.h"
#include "ring.h"
#include "externs.h"
E 7
E 6
I 5
#include "fdset.h"

E 5
I 1
D 7
void
tn3270_init()
{
E 7
#if	defined(TN3270)
D 7
    Sent3270TerminalType = 0;
    Ifrontp = Ibackp = Ibuf;
    init_ctlr();		/* Initialize some things */
    init_keyboard();
    init_screen();
    init_system();
#endif	/* defined(TN3270) */
}
E 7

D 7
#if	defined(TN3270)
E 7
I 7
#include "../ctlr/screen.h"
#include "../general/globals.h"
E 7

I 7
#if	defined(unix)
char	tline[200];
char	*transcom = 0;	/* transparent mode command (default: none) */
#endif	/* defined(unix) */
E 7
I 3

D 7
static char	Ibuf[8*BUFSIZ], *Ifrontp, *Ibackp;
E 7
I 7
char	Ibuf[8*BUFSIZ], *Ifrontp, *Ibackp;
E 7

static char	sb_terminal[] = { IAC, SB,
			TELOPT_TTYPE, TELQUAL_IS,
			'I', 'B', 'M', '-', '3', '2', '7', '8', '-', '2',
			IAC, SE };
#define	SBTERMMODEL	13

static int
	Sent3270TerminalType;	/* Have we said we are a 3270? */

I 7
#endif	/* defined(TN3270) */
E 7

I 4
D 7
#if	defined(unix)
static
settranscom(argc, argv)
	int argc;
	char *argv[];
{
	int i, len = 0;
	char *strcpy(), *strcat();
E 7

D 7
	if (argc == 1 && transcom) {
	   transcom = 0;
	}
	if (argc == 1) {
	   return;
	}
	for (i = 1; i < argc; ++i) {
	    len += 1 + strlen(argv[1]);
	}
	transcom = tline;
	(void) strcpy(transcom, argv[1]);
	for (i = 2; i < argc; ++i) {
	    (void) strcat(transcom, " ");
	    (void) strcat(transcom, argv[i]);
	}
E 7
I 7
void
D 8
tn3270_init()
E 8
I 8
init_3270()
E 8
{
#if	defined(TN3270)
    Sent3270TerminalType = 0;
    Ifrontp = Ibackp = Ibuf;
    init_ctlr();		/* Initialize some things */
    init_keyboard();
    init_screen();
    init_system();
#endif	/* defined(TN3270) */
E 7
}
D 7
#endif	/* defined(unix) */
E 7

I 7

#if	defined(TN3270)

E 7
E 4
E 3
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
D 7
    register int c;
E 7
I 7
    register int loop, c;
E 7
    int origCount;
D 7
    fd_set o;
E 7

    origCount = count;
D 7
    FD_ZERO(&o);
E 7

    while (count) {
I 8
	/* If not enough room for EORs, IACs, etc., wait */
E 8
D 7
	if ((netobuf+sizeof netobuf - nfrontp) < 6) {
E 7
I 7
	if (NETROOM() < 6) {
	    fd_set o;

	    FD_ZERO(&o);
E 7
	    netflush();
D 7
	    while ((netobuf+sizeof netobuf - nfrontp) < 6) {
E 7
I 7
	    while (NETROOM() < 6) {
E 7
		FD_SET(net, &o);
		(void) select(net+1, (fd_set *) 0, &o, (fd_set *) 0,
						(struct timeval *) 0);
		netflush();
	    }
	}
D 7
	c = *buffer++;
	count--;
	if (c == IAC) {
	    *nfrontp++ = IAC;
	    *nfrontp++ = IAC;
	} else {
	    *nfrontp++ = c;
E 7
I 7
D 8
	c = loop = ring_empty_consecutive(&netoring);
E 8
I 8
	c = ring_empty_count(&netoring);
	if (c > count) {
	    c = count;
	}
	loop = c;
E 8
	while (loop) {
D 10
	    if (*buffer == IAC) {
E 10
I 10
	    if (((unsigned char)*buffer) == IAC) {
E 10
		break;
	    }
	    buffer++;
	    loop--;
E 7
	}
I 7
	if ((c = c-loop)) {
	    ring_supply_data(&netoring, buffer-c, c);
	    count -= c;
	}
	if (loop) {
	    NET2ADD(IAC, IAC);
	    count--;
I 8
	    buffer++;
E 8
	}
E 7
    }

D 7
    if (done && !count) {
	*nfrontp++ = IAC;
	*nfrontp++ = EOR;
E 7
I 7
    if (done) {
D 8
	NET2ADD(IAC, IAC);
E 8
I 8
	NET2ADD(IAC, EOR);
E 8
E 7
	netflush();		/* try to move along as quickly as ... */
    }
    return(origCount - count);
}


#if	defined(unix)
D 7
static void
E 7
I 7
void
E 7
inputAvailable()
{
    HaveInput = 1;
}
#endif	/* defined(unix) */

void
outputPurge()
{
D 2
    int tmp = flushout;

    flushout = 1;

    ttyflush();

    flushout = tmp;
E 2
I 2
    ttyflush(1);
E 2
}


/*
 * The following routines are places where the various tn3270
 * routines make calls into telnet.c.
 */

D 7
/* TtyChars() - returns the number of characters in the TTY buffer */
TtyChars()
{
    return(tfrontp-tbackp);
}

E 7
D 8
/* DataToTerminal - queue up some data to go to terminal. */
E 8
I 8
/*
 * DataToTerminal - queue up some data to go to terminal.
 *
 * Note: there are people who call us and depend on our processing
 * *all* the data at one time (thus the select).
 */
E 8

int
DataToTerminal(buffer, count)
register char	*buffer;		/* where the data is */
register int	count;			/* how much to send */
{
I 7
    register int loop, c;
E 7
    int origCount;
D 7
#if	defined(unix)
    fd_set	o;
E 7

D 7
    FD_ZERO(&o);
#endif	/* defined(unix) */
E 7
    origCount = count;

    while (count) {
D 7
	if (tfrontp >= ttyobuf+sizeof ttyobuf) {
D 2
	    ttyflush();
E 2
I 2
	    ttyflush(0);
E 2
	    while (tfrontp >= ttyobuf+sizeof ttyobuf) {
E 7
I 7
	if (TTYROOM() == 0) {
E 7
#if	defined(unix)
I 7
	    fd_set o;

	    FD_ZERO(&o);
#endif	/* defined(unix) */
	    ttyflush();
	    while (TTYROOM() == 0) {
#if	defined(unix)
E 7
		FD_SET(tout, &o);
		(void) select(tout+1, (fd_set *) 0, &o, (fd_set *) 0,
						(struct timeval *) 0);
#endif	/* defined(unix) */
D 2
		ttyflush();
E 2
I 2
D 7
		ttyflush(0);
E 7
I 7
		ttyflush();
E 7
E 2
	    }
	}
D 7
	*tfrontp++ = *buffer++;
	count--;
E 7
I 7
D 8
	c = loop = ring_empty_consecutive(&ttyoring);
	while (loop) {
	    if (*buffer == IAC) {
		break;
	    }
	    buffer++;
	    loop--;
E 8
I 8
	c = TTYROOM();
	if (c > count) {
	    c = count;
E 8
	}
D 8
	if ((c = c-loop)) {
	    ring_supply_data(&ttyoring, buffer-c, c);
	    count -= c;
	}
E 8
I 8
	ring_supply_data(&ttyoring, buffer, c);
	count -= c;
	buffer += c;
E 8
E 7
    }
D 8
    return(origCount - count);
E 8
I 8
    return(origCount);
E 8
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

D 7
    if (tfrontp == tbackp) {
E 7
I 7
D 8
    if (TTYBYTES()) {
E 8
I 8
    if (TTYBYTES() == 0) {
E 8
E 7
#if	defined(unix)
	FD_SET(tout, &o);
	(void) select(tout+1, (int *) 0, &o, (int *) 0,
			(struct timeval *) 0);	/* wait for TTLOWAT */
#endif	/* defined(unix) */
    } else {
D 7
	while (tfrontp != tbackp) {
E 7
I 7
	while (TTYBYTES()) {
E 7
D 2
	    ttyflush();
E 2
I 2
	    ttyflush(0);
E 2
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

D 7
static int
E 7
I 7
int
E 7
Push3270()
{
D 7
    int save = scc;
E 7
I 7
    int save = ring_full_count(&netiring);
E 7

D 7
    if (scc) {
	if (Ifrontp+scc > Ibuf+sizeof Ibuf) {
E 7
I 7
    if (save) {
	if (Ifrontp+save > Ibuf+sizeof Ibuf) {
E 7
	    if (Ibackp != Ibuf) {
		memcpy(Ibuf, Ibackp, Ifrontp-Ibackp);
		Ifrontp -= (Ibackp-Ibuf);
		Ibackp = Ibuf;
	    }
	}
D 7
	if (Ifrontp+scc < Ibuf+sizeof Ibuf) {
E 7
I 7
	if (Ifrontp+save < Ibuf+sizeof Ibuf) {
E 7
	    telrcv();
	}
    }
D 7
    return save != scc;
E 7
I 7
    return save != ring_full_count(&netiring);
E 7
}


/*
 * Finish3270 - get the last dregs of 3270 data out to the terminal
 *		before quitting.
 */

D 7
static void
E 7
I 7
void
E 7
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
D 7
    if (tfrontp >= ttyobuf+sizeof ttyobuf) {
E 7
I 7
    if (TTYBYTES()) {
E 7
	(void) DataToTerminal(&c, 1);
    } else {
D 7
	*tfrontp++ = c;		/* optimize if possible. */
E 7
I 7
	TTYADD(c);
E 7
    }
}
#endif	/* ((!defined(NOT43)) || defined(PUTCHAR)) */

I 3
void
SetForExit()
{
    setconnmode();
    if (In3270) {
	Finish3270();
    }
    setcommandmode();
    fflush(stdout);
    fflush(stderr);
    if (In3270) {
	StopScreen(1);
    }
    setconnmode();
    setcommandmode();
}

void
Exit(returnCode)
int returnCode;
{
    SetForExit();
    exit(returnCode);
}

void
ExitString(string, returnCode)
char *string;
int returnCode;
{
    SetForExit();
    fwrite(string, 1, strlen(string), stderr);
    exit(returnCode);
}

void
ExitPerror(string, returnCode)
char *string;
int returnCode;
{
    SetForExit();
    perror(string);
    exit(returnCode);
}

void
SetIn3270()
{
    if (Sent3270TerminalType && myopts[TELOPT_BINARY]
			    && hisopts[TELOPT_BINARY] && !donebinarytoggle) {
	if (!In3270) {
	    In3270 = 1;
	    Init3270();		/* Initialize 3270 functions */
	    /* initialize terminal key mapping */
	    InitTerminal();	/* Start terminal going */
	    setconnmode();
	}
    } else {
	if (In3270) {
	    StopScreen(1);
	    In3270 = 0;
	    Stop3270();		/* Tell 3270 we aren't here anymore */
	    setconnmode();
	}
    }
}

/*
 * tn3270_ttype()
 *
 *	Send a response to a terminal type negotiation.
 *
 *	Return '0' if no more responses to send; '1' if a response sent.
 */

int
tn3270_ttype()
{
    /*
     * Try to send a 3270 type terminal name.  Decide which one based
     * on the format of our screen, and (in the future) color
     * capaiblities.
     */
    InitTerminal();		/* Sets MaxNumberColumns, MaxNumberLines */
    if ((MaxNumberLines >= 24) && (MaxNumberColumns >= 80)) {
	Sent3270TerminalType = 1;
	if ((MaxNumberLines >= 27) && (MaxNumberColumns >= 132)) {
	    MaxNumberLines = 27;
	    MaxNumberColumns = 132;
	    sb_terminal[SBTERMMODEL] = '5';
	} else if (MaxNumberLines >= 43) {
	    MaxNumberLines = 43;
	    MaxNumberColumns = 80;
	    sb_terminal[SBTERMMODEL] = '4';
	} else if (MaxNumberLines >= 32) {
	    MaxNumberLines = 32;
	    MaxNumberColumns = 80;
	    sb_terminal[SBTERMMODEL] = '3';
	} else {
	    MaxNumberLines = 24;
	    MaxNumberColumns = 80;
	    sb_terminal[SBTERMMODEL] = '2';
	}
	NumberLines = 24;		/* before we start out... */
	NumberColumns = 80;
	ScreenSize = NumberLines*NumberColumns;
	if ((MaxNumberLines*MaxNumberColumns) > MAXSCREENSIZE) {
	    ExitString("Programming error:  MAXSCREENSIZE too small.\n",
								1);
	    /*NOTREACHED*/
	}
	printsub(">", sb_terminal+2, sizeof sb_terminal-2);
	ring_supply_data(&netoring, sb_terminal, sizeof sb_terminal);
	return 1;
    } else {
	return 0;
    }
}
I 7

#if	defined(unix)
settranscom(argc, argv)
	int argc;
	char *argv[];
{
	int i, len = 0;

	if (argc == 1 && transcom) {
	   transcom = 0;
	}
	if (argc == 1) {
	   return;
	}
	for (i = 1; i < argc; ++i) {
	    len += 1 + strlen(argv[1]);
	}
	transcom = tline;
	(void) strcpy(transcom, argv[1]);
	for (i = 2; i < argc; ++i) {
	    (void) strcat(transcom, " ");
	    (void) strcat(transcom, argv[i]);
	}
}
#endif	/* defined(unix) */

E 7
E 3
#endif	/* defined(TN3270) */
E 1
