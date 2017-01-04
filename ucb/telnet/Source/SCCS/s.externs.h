h29300
s 00007/00000/00108
d D 1.9 88/05/15 21:17:37 minshall 9 8
c For NOT43 systems, get correct definition for dosynch().
e
s 00065/00038/00043
d D 1.8 88/03/27 13:49:03 minshall 8 7
c Make it *compile* with -DTN3270.
e
s 00014/00000/00067
d D 1.7 88/03/08 10:30:46 bostic 7 6
c add Berkeley specific copyright
e
s 00000/00006/00067
d D 1.6 88/01/07 11:54:00 minshall 6 5
c Reduce extern's.
e
s 00000/00001/00073
d D 1.5 87/10/27 15:59:12 minshall 5 4
c Remove an unused extern.
e
s 00001/00000/00073
d D 1.4 87/10/23 15:15:35 minshall 4 3
c Try to move system dependent stuff to system dependent files.
e
s 00009/00007/00064
d D 1.3 87/10/10 14:27:11 minshall 3 2
c This is the first version to get near rings.  It compiles,
c but doesn't work.
e
s 00000/00002/00071
d D 1.2 87/09/25 16:06:40 minshall 2 1
c Cut down on number of extern's.
e
s 00073/00000/00000
d D 1.1 87/09/11 15:40:31 minshall 1 0
c date and time created 87/09/11 15:40:31 by minshall
e
u
U
t
T
I 7
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
 *
 *	%W% (Berkeley) %G%
 */

E 7
I 1
#include <stdio.h>
#include <setjmp.h>

#define	SUBBUFSIZE	100

extern int errno;		/* outside this world */

I 8
extern char
    *strcat(),
    *strcpy();			/* outside this world */

E 8
extern int
D 2
	SYNCHing,		/* we are in TELNET SYNCH mode */
E 2
D 8
	flushout,		/* flush output */
	connected,		/* Are we connected to the other side? */
	globalmode,		/* Mode tty should be in */
	In3270,			/* Are we in 3270 mode? */
	telnetport,		/* Are we connected to the telnet port? */
	localchars,		/* we recognize interrupt/quit */
	donelclchars,		/* the user has set "localchars" */
	showoptions,
D 2
	flushline,
E 2
	net,
D 6
	tin,
	tout,
E 6
	crlf,		/* Should '\r' be mapped to <CR><LF> (or <CR><NUL>)? */
	autoflush,		/* flush output when interrupting? */
	autosynch,		/* send interrupt characters with SYNCH? */
I 4
	SYNCHing,		/* Is the stream in telnet SYNCH mode? */
E 4
	donebinarytoggle,	/* the user has put us in binary */
	dontlecho,		/* do we suppress local echoing right now? */
	crmod,
	netdata,		/* Print out network data flow */
	debug;			/* Debug level */
E 8
I 8
    flushout,		/* flush output */
    connected,		/* Are we connected to the other side? */
    globalmode,		/* Mode tty should be in */
    In3270,			/* Are we in 3270 mode? */
    telnetport,		/* Are we connected to the telnet port? */
    localchars,		/* we recognize interrupt/quit */
    donelclchars,		/* the user has set "localchars" */
    showoptions,
    net,
    tout,		/* Terminal output file descriptor */
    crlf,		/* Should '\r' be mapped to <CR><LF> (or <CR><NUL>)? */
    autoflush,		/* flush output when interrupting? */
    autosynch,		/* send interrupt characters with SYNCH? */
    SYNCHing,		/* Is the stream in telnet SYNCH mode? */
    donebinarytoggle,	/* the user has put us in binary */
    dontlecho,		/* do we suppress local echoing right now? */
    crmod,
    netdata,		/* Print out network data flow */
    debug;			/* Debug level */
E 8

extern char
D 8
	echoc,			/* Toggle local echoing */
	escape,			/* Escape to command mode */
	doopt[],
	dont[],
	will[],
	wont[],
	hisopts[],
	myopts[],
D 6
	subbuffer[SUBBUFSIZE],
E 6
	*hostname,		/* Who are we connected to? */
D 3
	*prompt,		/* Prompt for command. */
	*nfrontp,
	*nbackp,
	netobuf[2*BUFSIZ],
	ttyobuf[2*BUFSIZ],
	*tfrontp,
	*tbackp;
E 3
I 3
	*prompt;		/* Prompt for command. */
E 8
I 8
    echoc,			/* Toggle local echoing */
    escape,			/* Escape to command mode */
    doopt[],
    dont[],
    will[],
    wont[],
    hisopts[],
    myopts[],
    *hostname,		/* Who are we connected to? */
    *prompt;		/* Prompt for command. */
E 8
E 3

extern FILE
D 8
	*NetTrace;		/* Where debugging output goes */
E 8
I 8
    *NetTrace;		/* Where debugging output goes */
E 8

extern jmp_buf
D 8
	peerdied,
	toplevel;		/* For error conditions. */
E 8
I 8
    peerdied,
    toplevel;		/* For error conditions. */
E 8

extern void
I 9
#if	!defined(NOT43)
E 9
D 6
	intr(),
	intr2(),
	deadpeer(),
E 6
D 8
	dosynch(),
D 5
	doflush(),
E 5
	setconnmode(),
	setcommandmode();
E 8
I 8
    dosynch(),
I 9
#endif	/* !defined(NOT43) */
E 9
    setconnmode(),
    setcommandmode();
I 9

#if	defined(NOT43)
extern int
    dosynch();
#endif	/* defined(NOT43) */
E 9
E 8

extern char
    termEofChar,
    termEraseChar,
    termFlushChar,
    termIntChar,
    termKillChar,
    termLiteralNextChar,
    termQuitChar;
I 3

/* Ring buffer structures which are shared */

extern Ring
D 8
	netoring,
	netiring,
	ttyoring,
	ttyiring;
E 8
I 8
    netoring,
    netiring,
    ttyoring,
    ttyiring;

/* Tn3270 section */
#if	defined(TN3270)

extern int
    HaveInput,		/* Whether an asynchronous I/O indication came in */
    noasynch,		/* Don't do signals on I/O (SIGURG, SIGIO) */
    shell_active;	/* Subshell is active */

extern char
    *Ibackp,		/* Oldest byte of 3270 data */
    Ibuf[],		/* 3270 buffer */
    *Ifrontp,		/* Where next 3270 byte goes */
    tline[],
    *transcom;		/* Transparent command */

extern int
    settranscom();

extern void
    inputAvailable();
#endif	/* defined(TN3270) */
E 8
E 3
E 1
