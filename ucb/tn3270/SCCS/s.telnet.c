h53229
s 00021/00030/04066
d D 6.9 88/03/28 12:19:27 bostic 28 27
c add Berkeley specific header
e
s 00002/00002/04094
d D 6.8 88/03/27 09:45:33 minshall 27 26
c Make suboption trace work correctly.
e
s 00003/00000/04093
d D 6.7 88/03/06 17:38:26 minshall 26 25
c Fix for coming OUT of 3270 mode then back in again
c (from Tony Li <tli%sargas.usc.edu@oberon.usc.edu>).
e
s 00010/00005/04083
d D 6.6 88/01/05 14:59:57 minshall 25 24
c Changes for pyramid from sbanner1@cheops (S. John Banner).
e
s 00047/00000/04041
d D 6.5 87/09/25 13:17:44 minshall 24 23
c Fix to make standard output (at least) go into a proper binary
c more (showed up with tab character being expanded to blanks by DOS).
e
s 00055/00030/03986
d D 6.4 87/08/17 11:12:02 minshall 23 22
c add "toggle crlf" for <CR><LF> on carriage return.
e
s 00037/00021/03979
d D 6.3 87/08/17 10:47:21 minshall 22 21
c Fix bugs with binary mode.
e
s 00014/00005/03986
d D 6.2 87/08/17 09:57:04 minshall 21 20
c Fix bug when operating in LOCAL_CHARS mode and
c <CR><LF> combinations were being sent to the screen as just '\n'.
e
s 00000/00000/03991
d D 6.1 87/08/11 10:16:35 minshall 20 19
c New version numbering.
e
s 00016/00002/03975
d D 1.18 87/07/31 12:51:11 minshall 19 18
c Make some fixes (bugs from Alex Liu).
e
s 00068/00036/03909
d D 1.17 87/07/31 10:27:56 minshall 18 17
c Various fixes.
e
s 00004/00001/03941
d D 1.16 87/07/07 15:02:53 minshall 17 16
c Changes from Bill Nowicki at sun (for telnet.c).
e
s 00060/00040/03882
d D 1.15 87/07/07 14:21:24 minshall 16 15
c Various fixes for msdos and non-vax unices.
e
s 00003/00000/03919
d D 1.14 87/06/19 09:20:21 minshall 15 14
c Fix bad bug.  When HaveInput = 1, and we are terminating, we
c never quit.
e
s 00002/00002/03917
d D 1.13 87/06/16 17:15:55 minshall 14 13
c Recover the "-n" option.
e
s 00093/00084/03826
d D 1.12 87/06/15 09:31:28 minshall 13 12
c Make work with Unix "shell" command.  Delete "-DDEBUG".  Add
c "-noasynch" runtime option.
e
s 00112/00064/03798
d D 1.11 87/05/25 16:43:27 minshall 12 11
c Various changes.  Handle 'shell_active'.  Call 'Stop3270()'.
c An initial '!' (exclamation mark) is to be treated as a delimiter in
c a command.
e
s 00003/00003/03859
d D 1.10 87/05/22 15:08:01 minshall 11 10
c New directory structure.
e
s 00026/00010/03836
d D 1.9 87/05/21 21:34:09 minshall 10 9
c kbhit(), etc., work OK (was a bug in outbound.c; not calling 
c TerminalInput, or whatever).  Also, move 'shell()' to api.c in dos_screen.
e
s 00666/00332/03180
d D 1.8 87/05/15 16:06:58 minshall 9 8
c This version compiles and minimally works for the PC.
e
s 00434/00239/03078
d D 1.7 87/05/13 15:34:14 minshall 8 7
c This version is a bit better partitioned vis-a-vis "unix"
c and "MSDOS" (and, it compiles and works).
e
s 00057/00038/03260
d D 1.6 87/04/01 13:56:41 minshall 7 6
c Fix close/open sequences in a rational way.
e
s 00007/00007/03291
d D 1.5 87/01/21 14:17:18 minshall 6 4
c Fix bug when we have data in network input buffer, and more 
c data arrives (used to get garbage data).
e
s 00000/00353/02945
d R 1.5 87/01/21 14:05:51 minshall 5 4
c Fix bug when network input buffer has data and we read more 
c (we used to lose data).
e
s 00029/00001/03269
d D 1.4 87/01/11 16:12:22 minshall 4 3
c Fix problem with ^C in msdos environment.  Fix to allow us to 
c prompt other side for SGA if they don't volunteer (for telnet mode).
e
s 00087/00063/03183
d D 1.3 86/12/19 17:06:00 minshall 3 2
c seems to work with 'close' then 'open'.
e
s 00014/00014/03232
d D 1.2 86/12/19 11:07:46 minshall 2 1
c Various fixes.
e
s 03246/00000/00000
d D 1.1 86/11/16 20:44:49 minshall 1 0
c date and time created 86/11/16 20:44:49 by minshall
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
D 28
 *	Copyright (c) 1984-1987 by the Regents of the
E 18
 *	University of California and by Gregory Glenn Minshall.
E 28
I 28
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 28
 *
D 28
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
E 28
I 28
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 28
 */

#ifndef lint
D 28
static char copyright[] =
D 18
"@(#) Copyright (c) 1984, 1985, 1986 Regents of the University of California.\n\
E 18
I 18
"%Z% Copyright (c) 1984-1987 Regents of the University of California.\n\
E 28
I 28
char copyright[] =
"%Z% Copyright (c) 1988 Regents of the University of California.\n\
E 28
E 18
 All rights reserved.\n";
D 2
#endif not lint
E 2
I 2
D 28
#endif	/* not lint */
E 28
I 28
#endif /* not lint */
E 28
E 2

#ifndef lint
D 18
static char sccsid[] = "@(#)telnet.c	3.1  10/29/86";
E 18
I 18
static char sccsid[] = "%W% (Berkeley) %G%";
E 18
D 2
#endif not lint
E 2
I 2
D 28
#endif	/* not lint */
E 28
I 28
#endif /* not lint */
E 28
E 2

/*
 * User telnet program, modified for use by tn3270.c.
 *
 * Many of the FUNCTIONAL changes in this newest version of TELNET
 * were suggested by Dave Borman of Cray Research, Inc.
 *
 * Other changes in the tn3270 side come from Alan Crosswell (Columbia),
 * Bob Braden (ISI), Steve Jacobson (Berkeley), and Cliff Frost (Berkeley).
 *
 * This code is common between telnet(1c) and tn3270(1c).  There are the
 * following defines used to generate the various versions:
 *
 *	TN3270		- 	This is to be linked with tn3270.
 *
D 13
 *	DEBUG		-	Allow for some extra debugging operations.
 *
E 13
 *	NOT43		-	Allows the program to compile and run on
 *				a 4.2BSD system.
 *
 *	PUTCHAR		-	Within tn3270, on a NOT43 system,
 *				allows the use of the 4.3 curses
 *				(greater speed updating the screen).
 *				You need the 4.3 curses for this to work.
 *
 *	FD_SETSIZE	-	On whichever system, if this isn't defined,
 *				we patch over the FD_SET, etc., macros with
 *				some homebrewed ones.
 *
 *	SO_OOBINLINE	-	This is a socket option which we would like
 *				to set to allow TCP urgent data to come
 *				to us "inline".  This is NECESSARY for
 *				CORRECT operation, and desireable for
 *				simpler operation.
 *
 *	LNOFLSH		-	Detects the presence of the LNOFLSH bit
 *				in the tty structure.
 *
 *	unix		-	Compiles in unix specific stuff.
 *
D 9
 *	msdos		-	Compiles in msdos specific stuff.
E 9
I 9
 *	MSDOS		-	Compiles in MSDOS specific stuff.
E 9
 *
 */

#if	!defined(TN3270)
#define	ExitString(f,s,r)	{ fprintf(f, s); exit(r); }
#define	Exit(x)			exit(x)
#define	SetIn3270()

void	setcommandmode(), command();	/* forward declarations */
#endif	/* !defined(TN3270) */

#include <sys/types.h>
I 25

#if     defined(pyr)
#define fd_set fdset_t
#endif  /* defined(pyr) */
 
E 25
#include <sys/socket.h>
D 8
#include <sys/ioctl.h>
#include <sys/time.h>
E 8

#include <netinet/in.h>

I 8
#if	defined(unix)
/* By the way, we need to include curses.h before telnet.h since,
 * among other things, telnet.h #defines 'DO', which is a variable
 * declared in curses.h.
 */
E 8
#include <curses.h>
I 8
#endif	/* defined(unix) */
E 8

#define	TELOPTS
#include <arpa/telnet.h>

#if	!defined(NOT43)
#include <arpa/inet.h>
#else	/* !defined(NOT43) */
extern unsigned long inet_addr();
extern char	*inet_ntoa();
#endif	/* !defined(NOT43) */

#include <stdio.h>
#include <ctype.h>
#include <errno.h>
D 8
#include <signal.h>
E 8
#include <setjmp.h>
#include <netdb.h>
I 8

#if	defined(unix)
E 8
#include <strings.h>
I 8
#else	/* defined(unix) */
#include <string.h>
#endif	/* defined(unix) */
E 8

#if	defined(TN3270)
I 12
#include "ascii/termin.ext"
E 12
#include "ctlr/screen.h"
D 11
#include "system/globals.h"
E 11
I 11
D 12
#include "general/globals.h"
E 11
#include "telnet.ext"
E 12
I 12
#include "ctlr/oia.h"
E 12
#include "ctlr/options.ext"
#include "ctlr/outbound.ext"
D 11
#include "keyboard/termin.ext"
E 11
I 11
D 12
#include "ascii/termin.ext"
E 12
I 12
#include "general/globals.h"
#include "telnet.ext"
E 12
E 11
I 7
D 9
#include "general.h"
E 9
E 7
#endif	/* defined(TN3270) */
I 12

E 12
I 9
D 11
#include "general.h"
E 11
I 11
#include "general/general.h"
E 11
E 9



#ifndef	FD_SETSIZE
/*
 * The following is defined just in case someone should want to run
 * this telnet on a 4.2 system.
 *
 */

#define	FD_SET(n, p)	((p)->fds_bits[0] |= (1<<(n)))
#define	FD_CLR(n, p)	((p)->fds_bits[0] &= ~(1<<(n)))
#define	FD_ISSET(n, p)	((p)->fds_bits[0] & (1<<(n)))
#define FD_ZERO(p)	((p)->fds_bits[0] = 0)

#endif

#define	strip(x)	((x)&0x7f)
#define min(x,y)	((x<y)? x:y)

#if	defined(TN3270)
D 3
static char	Ibuf[8*BUFSIZ], *Ifrontp = Ibuf, *Ibackp = Ibuf;
E 3
I 3
static char	Ibuf[8*BUFSIZ], *Ifrontp, *Ibackp;
E 3
#endif	/* defined(TN3270) */

D 3
static char	ttyobuf[2*BUFSIZ], *tfrontp = ttyobuf, *tbackp = ttyobuf;
E 3
I 3
static char	ttyobuf[2*BUFSIZ], *tfrontp, *tbackp;
E 3
#define	TTYADD(c)	{ if (!(SYNCHing||flushout)) { *tfrontp++ = c; } }
#define	TTYLOC()	(tfrontp)
#define	TTYMAX()	(ttyobuf+sizeof ttyobuf-1)
#define	TTYMIN()	(netobuf)
#define	TTYBYTES()	(tfrontp-tbackp)
#define	TTYROOM()	(TTYMAX()-TTYLOC()+1)

D 3
static char	netobuf[2*BUFSIZ], *nfrontp = netobuf, *nbackp = netobuf;
E 3
I 3
static char	netobuf[2*BUFSIZ], *nfrontp, *nbackp;
E 3
#define	NETADD(c)	{ *nfrontp++ = c; }
#define	NET2ADD(c1,c2)	{ NETADD(c1); NETADD(c2); }
#define NETLOC()	(nfrontp)
#define	NETMAX()	(netobuf+sizeof netobuf-1)
#define	NETBYTES()	(nfrontp-nbackp)
#define	NETROOM()	(NETMAX()-NETLOC()+1)
D 3
static char	*neturg = 0;		/* one past last byte of urgent data */
E 3
I 3
static char	*neturg;		/* one past last byte of urgent data */
E 3

D 2
static char	subbuffer[100] = 0,
E 2
I 2
D 3
static char	subbuffer[100] = { 0 },
E 2
		*subpointer, *subend = 0;	 /* buffer for sub-options */
E 3
I 3
static char	subbuffer[100],
		*subpointer, *subend;	 /* buffer for sub-options */
E 3
#define	SB_CLEAR()	subpointer = subbuffer;
#define	SB_TERM()	subend = subpointer;
#define	SB_ACCUM(c)	if (subpointer < (subbuffer+sizeof subbuffer)) { \
				*subpointer++ = (c); \
			}

static char	sb_terminal[] = { IAC, SB,
			TELOPT_TTYPE, TELQUAL_IS,
			'I', 'B', 'M', '-', '3', '2', '7', '8', '-', '2',
			IAC, SE };
#define	SBTERMMODEL	13


D 2
static char	hisopts[256] = 0;
static char	myopts[256] = 0;
E 2
I 2
D 3
static char	hisopts[256] = { 0 };
static char	myopts[256] = { 0 };
E 3
I 3
static char	hisopts[256];
static char	myopts[256];
E 3
E 2

static char	doopt[] = { IAC, DO, '%', 'c', 0 };
static char	dont[] = { IAC, DONT, '%', 'c', 0 };
static char	will[] = { IAC, WILL, '%', 'c', 0 };
static char	wont[] = { IAC, WONT, '%', 'c', 0 };

struct cmd {
	char	*name;		/* command name */
	char	*help;		/* help string */
	int	(*handler)();	/* routine which executes command */
	int	dohelp;		/* Should we give general help information? */
	int	needconnect;	/* Do we need to be connected to execute? */
};

D 3
static char	sibuf[BUFSIZ], *sbp = 0;
E 3
I 3
static char	sibuf[BUFSIZ], *sbp;
E 3
static char	tibuf[BUFSIZ], *tbp;
static fd_set ibits, obits, xbits;


static int
D 3
	connected = 0,
	net = 0,
	scc = 0,
	tcc = 0,
	showoptions = 0,
	In3270 = 0,		/* Are we in 3270 mode? */
	ISend = 0,		/* trying to send network data in */
E 3
I 3
	connected,
	net,
	scc,
	tcc,
	showoptions,
	In3270,		/* Are we in 3270 mode? */
	ISend,		/* trying to send network data in */
E 3
	debug = 0,
D 3
	crmod = 0,
	netdata = 0,
E 3
I 3
	crmod,
D 23
	netdata,
E 23
I 23
	netdata,	/* Print out network data flow */
	crlf,		/* Should '\r' be mapped to <CR><LF> (or <CR><NUL>)? */
E 23
I 13
	noasynch = 0,	/* User specified "-noasynch" on command line */
E 13
I 7
	askedSGA = 0,	/* We have talked about suppress go ahead */
E 7
E 3
	telnetport = 1;

D 3
static FILE	*NetTrace = 0;
E 3
I 3
static FILE	*NetTrace = 0;		/* Not in bss, since needs to stay */
E 3

#define	CONTROL(x)	((x)&0x1f)		/* CTRL(x) is not portable */

static char
	*prompt = 0,
D 3
	escape = CONTROL(']'),
	echoc = CONTROL('E');
E 3
I 3
	escape,
	echoc;
E 3

static int
D 3
	SYNCHing = 0,		/* we are in TELNET SYNCH mode */
	flushout = 0,		/* flush output */
E 3
I 3
	SYNCHing,		/* we are in TELNET SYNCH mode */
	flushout,		/* flush output */
E 3
	autoflush = 0,		/* flush output when interrupting? */
D 3
	autosynch = 0,		/* send interrupt characters with SYNCH? */
	localchars = 0,		/* we recognize interrupt/quit */
	donelclchars = 0,	/* the user has set "localchars" */
	dontlecho = 0;		/* do we suppress local echoing right now? */
E 3
I 3
	autosynch,		/* send interrupt characters with SYNCH? */
	localchars,		/* we recognize interrupt/quit */
D 16
	donelclchars,	/* the user has set "localchars" */
E 16
I 16
	donelclchars,		/* the user has set "localchars" */
	donebinarytoggle,	/* the user has put us in binary */
E 16
D 8
	dontlecho;		/* do we suppress local echoing right now? */
E 8
I 8
	dontlecho,		/* do we suppress local echoing right now? */
	globalmode;
E 8
E 3

/*	The following are some tn3270 specific flags */
#if	defined(TN3270)

static int
D 3
	Sent3270TerminalType = 0;	/* Have we said we are a 3270? */
E 3
I 3
	Sent3270TerminalType;	/* Have we said we are a 3270? */
E 3

I 9
/* Some real, live, globals. */
int
	tout,			/* Output file descriptor */
	tin;			/* Input file descriptor */

#else	/* defined(TN3270) */
static int tin, tout;		/* file descriptors */
#endif	/* defined(TN3270) */


E 9
I 7
/*
 * Telnet receiver states for fsm
 */
#define	TS_DATA		0
#define	TS_IAC		1
#define	TS_WILL		2
#define	TS_WONT		3
#define	TS_DO		4
#define	TS_DONT		5
#define	TS_CR		6
#define	TS_SB		7		/* sub-option collection */
#define	TS_SE		8		/* looking for sub-option end */

static int	telrcv_state = TS_DATA;
E 7
D 9
/* Some real, live, globals. */
int
D 8
#if	defined(unix)
D 3
	HaveInput = 0,		/* There is input available to scan */
E 3
I 3
	HaveInput,		/* There is input available to scan */
E 3
#endif	/* defined(unix) */
E 8
D 3
	tout = 0,			/* Output file descriptor */
	tin = 0;			/* Input file descriptor */
E 3
I 3
	tout,			/* Output file descriptor */
	tin;			/* Input file descriptor */
E 9
E 3
D 8
#if	defined(unix)
char	*transcom = 0;	/* transparent mode command (default: none) */
#endif	/* defined(unix) */
E 8

D 9
#else	/* defined(TN3270) */
D 3
static int tin = 0, tout = 0;		/* file descriptors */
E 3
I 3
static int tin, tout;		/* file descriptors */
E 3
#endif	/* defined(TN3270) */

E 9
static char	line[200];
D 8
#if	defined(TN3270) && defined(unix)
static char	tline[200];
#endif	/* defined(TN3270) && defined(unix) */
E 8
D 3
static int	margc = 0;
E 3
I 3
static int	margc;
E 3
static char	*margv[20];

D 3
static jmp_buf	toplevel;
E 3
I 3
D 8
static jmp_buf	toplevel = 0;
E 8
I 8
static jmp_buf	toplevel = { 0 };
E 8
E 3
static jmp_buf	peerdied;

extern	int errno;


static struct sockaddr_in sin;

static struct	servent *sp = 0;

D 8
static struct	tchars otc = { 0 }, ntc = { 0 };
static struct	ltchars oltc = { 0 }, nltc = { 0 };
static struct	sgttyb ottyb = { 0 }, nttyb = { 0 };
E 8
D 3
static int	flushline = 1;
E 3
I 3
static int	flushline;
E 3

D 3
static char	*hostname = 0;
E 3
I 3
static char	*hostname;
E 3
static char	hnamebuf[32];

/*
 * The following are some clocks used to decide how to interpret
 * the relationship between various variables.
 */

static struct {
    int
	system,			/* what the current time is */
	echotoggle,		/* last time user entered echo character */
	modenegotiated,		/* last time operating mode negotiated */
	didnetreceive,		/* last time we read data from network */
	gotDM;			/* when did we last see a data mark */
D 3
} clocks = { 0 };
E 3
I 3
} clocks;
E 3

#define	settimer(x)	clocks.x = clocks.system++

I 8
/*	Various modes */
#define	MODE_LINE(m)	(modelist[m].modetype & LINE)
#define	MODE_LOCAL_CHARS(m)	(modelist[m].modetype &  LOCAL_CHARS)
I 9
#define	MODE_LOCAL_ECHO(m)	(modelist[m].modetype & LOCAL_ECHO)
#define	MODE_COMMAND_LINE(m)	(modelist[m].modetype & COMMAND_LINE)
E 9

#define	LOCAL_CHARS	0x01		/* Characters processed locally */
#define	LINE		0x02		/* Line-by-line mode of operation */
I 9
#define	LOCAL_ECHO	0x04		/* Echoing locally */
#define	COMMAND_LINE	0x08		/* Command line mode */
E 9

static struct {
    char *modedescriptions;
    char modetype;
} modelist[] = {
D 9
	{ "telnet command mode", 0 },
E 9
I 9
	{ "telnet command mode", COMMAND_LINE },
E 9
	{ "character-at-a-time mode", 0 },
D 9
	{ "character-at-a-time mode (local echo)", LOCAL_CHARS },
E 9
I 9
	{ "character-at-a-time mode (local echo)", LOCAL_ECHO|LOCAL_CHARS },
E 9
	{ "line-by-line mode (remote echo)", LINE | LOCAL_CHARS },
D 9
	{ "line-by-line mode", LINE | LOCAL_CHARS },
E 9
I 9
	{ "line-by-line mode", LINE | LOCAL_ECHO | LOCAL_CHARS },
E 9
	{ "line-by-line mode (local echoing suppressed)", LINE | LOCAL_CHARS },
	{ "3270 mode", 0 },
};


E 8
/*
I 8
 * The following routines try to encapsulate what is system dependent
 * (at least between 4.x and dos) which is used in telnet.c.
 */

#if	defined(unix)
#include <sys/ioctl.h>
#include <sys/time.h>
#include <signal.h>

int
	HaveInput;		/* There is input available to scan */

#if	defined(TN3270)
static char	tline[200];
char	*transcom = 0;	/* transparent mode command (default: none) */
#endif	/* defined(TN3270) */

static struct	tchars otc = { 0 }, ntc = { 0 };
static struct	ltchars oltc = { 0 }, nltc = { 0 };
static struct	sgttyb ottyb = { 0 }, nttyb = { 0 };


I 9
#define	TerminalWrite(fd,buf,n)	write(fd,buf,n)
#define	TerminalRead(fd,buf,n)	read(fd,buf,n)

E 9
/*
 *
 */

static int
D 9
TerminalAutoFlush()
E 9
I 9
TerminalAutoFlush()					/* unix */
E 9
{
#if	defined(LNOFLSH)
    ioctl(0, TIOCLGET, (char *)&autoflush);
    return !(autoflush&LNOFLSH);	/* if LNOFLSH, no autoflush */
#else	/* LNOFLSH */
    return 1;
#endif	/* LNOFLSH */
}

/*
D 9
 * TerminalEditLine()
E 9
I 9
 * TerminalSpecialChars()
E 9
 *
D 9
 * Look at an input character, and decide what to do.
E 9
I 9
 * Look at an input character to see if it is a special character
 * and decide what to do.
E 9
 *
 * Output:
 *
 *	0	Don't add this character.
 *	1	Do add this character
 */

int
D 9
TerminalEditLine(c)			/* unix */
E 9
I 9
TerminalSpecialChars(c)			/* unix */
E 9
int	c;
{
    void doflush(), intp(), sendbrk();

    if (c == ntc.t_intrc) {
	intp();
	return 0;
    } else if (c == ntc.t_quitc) {
	sendbrk();
	return 0;
    } else if (c == nltc.t_flushc) {
	NET2ADD(IAC, AO);
	if (autoflush) {
	    doflush();
	}
	return 0;
    } else if (!MODE_LOCAL_CHARS(globalmode)) {
	if (c == nttyb.sg_kill) {
	    NET2ADD(IAC, EL);
	    return 0;
	} else if (c == nttyb.sg_erase) {
	    NET2ADD(IAC, EC);
	    return 0;
	}
    }
    return 1;
}


/*
 * Flush output to the terminal
 */
 
static void
TerminalFlushOutput()				/* unix */
{
    (void) ioctl(fileno(stdout), TIOCFLUSH, (char *) 0);
}

static void
TerminalSaveState()				/* unix */
{
    ioctl(0, TIOCGETP, (char *)&ottyb);
    ioctl(0, TIOCGETC, (char *)&otc);
    ioctl(0, TIOCGLTC, (char *)&oltc);

    ntc = otc;
    nltc = oltc;
    nttyb = ottyb;
}

static void
TerminalRestoreState()				/* unix */
{
}

/*
 * TerminalNewMode - set up terminal to a specific mode.
 */


static void
D 9
TerminalNewMode(f)
E 9
I 9
TerminalNewMode(f)					/* unix */
E 9
register int f;
{
    static int prevmode = 0;
    struct tchars *tc;
    struct tchars tc3;
    struct ltchars *ltc;
    struct sgttyb sb;
    int onoff;
    int old;
    struct	tchars notc2;
    struct	ltchars noltc2;
    static struct	tchars notc =	{ -1, -1, -1, -1, -1, -1 };
    static struct	ltchars noltc =	{ -1, -1, -1, -1, -1, -1 };

    globalmode = f;
    if (prevmode == f)
	return;
    old = prevmode;
    prevmode = f;
    sb = nttyb;

    switch (f) {

    case 0:
	onoff = 0;
	tc = &otc;
	ltc = &oltc;
	break;

    case 1:		/* remote character processing, remote echo */
    case 2:		/* remote character processing, local echo */
    case 6:		/* 3270 mode - like 1, but with xon/xoff local */
		    /* (might be nice to have "6" in telnet also...) */
	    sb.sg_flags |= CBREAK;
	    if ((f == 1) || (f == 6)) {
		sb.sg_flags &= ~(ECHO|CRMOD);
	    } else {
		sb.sg_flags |= ECHO|CRMOD;
	    }
	    sb.sg_erase = sb.sg_kill = -1;
	    if (f == 6) {
		tc = &tc3;
		tc3 = notc;
		    /* get XON, XOFF characters */
		tc3.t_startc = otc.t_startc;
		tc3.t_stopc = otc.t_stopc;
	    } else {
		/*
		 * If user hasn't specified one way or the other,
		 * then default to not trapping signals.
		 */
		if (!donelclchars) {
		    localchars = 0;
		}
		if (localchars) {
		    notc2 = notc;
		    notc2.t_intrc = ntc.t_intrc;
		    notc2.t_quitc = ntc.t_quitc;
		    tc = &notc2;
		} else {
		    tc = &notc;
		}
	    }
	    ltc = &noltc;
	    onoff = 1;
	    break;
    case 3:		/* local character processing, remote echo */
    case 4:		/* local character processing, local echo */
    case 5:		/* local character processing, no echo */
	    sb.sg_flags &= ~CBREAK;
	    sb.sg_flags |= CRMOD;
	    if (f == 4)
		sb.sg_flags |= ECHO;
	    else
		sb.sg_flags &= ~ECHO;
	    notc2 = ntc;
	    tc = &notc2;
	    noltc2 = oltc;
	    ltc = &noltc2;
	    /*
	     * If user hasn't specified one way or the other,
	     * then default to trapping signals.
	     */
	    if (!donelclchars) {
		localchars = 1;
	    }
	    if (localchars) {
		notc2.t_brkc = nltc.t_flushc;
		noltc2.t_flushc = -1;
	    } else {
		notc2.t_intrc = notc2.t_quitc = -1;
	    }
	    noltc2.t_suspc = escape;
	    noltc2.t_dsuspc = -1;
	    onoff = 1;
	    break;

    default:
	    return;
    }
    ioctl(tin, TIOCSLTC, (char *)ltc);
    ioctl(tin, TIOCSETC, (char *)tc);
    ioctl(tin, TIOCSETP, (char *)&sb);
#if	(!defined(TN3270)) || ((!defined(NOT43)) || defined(PUTCHAR))
    ioctl(tin, FIONBIO, (char *)&onoff);
    ioctl(tout, FIONBIO, (char *)&onoff);
#endif	/* (!defined(TN3270)) || ((!defined(NOT43)) || defined(PUTCHAR)) */
D 13
#if	defined(TN3270) && !defined(DEBUG)
    ioctl(tin, FIOASYNC, (char *)&onoff);
#endif	/* defined(TN3270) && !defined(DEBUG) */
E 13
I 13
#if	defined(TN3270)
    if (noasynch == 0) {
	ioctl(tin, FIOASYNC, (char *)&onoff);
    }
#endif	/* defined(TN3270) */
E 13

    if (MODE_LINE(f)) {
	void doescape();

	signal(SIGTSTP, doescape);
    } else if (MODE_LINE(old)) {
	signal(SIGTSTP, SIG_DFL);
	sigsetmask(sigblock(0) & ~(1<<(SIGTSTP-1)));
    }
}


I 9
int
NetClose(net)
int	net;
{
    return close(net);
}


E 9
static void
NetNonblockingIO(fd, onoff)				/* unix */
int
	fd,
	onoff;
{
    ioctl(net, FIONBIO, (char *)&onoff);
}

static void
NetSigIO(fd, onoff)				/* unix */
int
	fd,
	onoff;
{
    ioctl(net, FIOASYNC, (char *)&onoff);	/* hear about input */
}

static void
NetSetPgrp(fd)				/* unix */
int fd;
{
    int myPid;

    myPid = getpid();
#if	defined(NOT43)
    myPid = -myPid;
#endif	/* defined(NOT43) */
    ioctl(net, SIOCSPGRP, (char *)&myPid);	/* set my pid */
}


#endif	/* defined(unix) */

#if	defined(MSDOS)
#include <time.h>
I 9
#include <signal.h>
I 10
#include <process.h>
E 10
E 9
D 19

E 19
I 19
#include <fcntl.h>
#include <io.h>
E 19
I 18
#include <dos.h>

E 18
#if	!defined(SO_OOBINLINE)
#define	SO_OOBINLINE
#endif	/* !defined(SO_OOBINLINE) */


static char
I 9
    termEofChar,
E 9
    termEraseChar,
    termFlushChar,
    termIntChar,
    termKillChar,
D 9
    termQuitChar,
    termEofChar;
E 9
I 9
    termLiteralNextChar,
    termQuitChar;
E 9

I 24
static char
    savedInState, savedOutState;
E 24
I 9

/*
 * MSDOS doesn't have anyway of deciding whether a full-edited line
 * is ready to be read in, so we need to do character-by-character
 * reads, and then do the editing in the program (in the case where
 * we are supporting line-by-line mode).
 *
 * The following routines, which are internal to the MSDOS-specific
 * code, accomplish this miracle.
 */
E 9

I 9
#define Hex(c)	HEX[(c)&0xff]

static survivorSetup = 0;		/* Do we have ^C hooks in? */

static int
	lineend = 0,		/* There is a line terminator */
	ctrlCCount = 0;

static char	linein[200],		/* Where input line is assembled */
		*nextin = linein,	/* Next input character */
		*nextout = linein;	/* Next character to be consumed */

#define consumechar() \
    if ((++nextout) >= nextin) { \
	nextout = nextin = linein; \
	lineend = 0; \
    }

#define	characteratatime()	(!MODE_LINE(globalmode))	/* one by one */


E 9
/*
I 9
 * killone()
 *
 *  Erase the last character on the line.
 */

static void
killone()
{
    if (lineend) {
	return;			/* ??? XXX */
    }
    if (nextin == linein) {
	return;			/* Nothing to do */
    }
    nextin--;
    if (!(isspace(*nextin) || isprint(*nextin))) {
	putchar('\b');
	putchar(' ');
	putchar('\b');
    }
    putchar('\b');
    putchar(' ');
    putchar('\b');
}


/*
 * setlineend()
 *
 *  Decide if it's time to send the current line up to the user
 * process.
 */

static void
setlineend()
{
    if (nextin == nextout) {
	return;
    }
    if (characteratatime()) {
	lineend = 1;
    } else if (nextin >= (linein+sizeof linein)) {
	lineend = 1;
    } else {
	int c = *(nextin-1);
	if ((c == termIntChar)
		|| (c == termQuitChar)
		|| (c == termEofChar)) {
	    lineend = 1;
	} else if (c == termFlushChar) {
	    lineend = 1;
	} else if ((c == '\n') || (c == '\r')) {
	    lineend = 1;
	}
    }
    /* Otherwise, leave it alone (reset by 'consumechar') */
}

/*
 * OK, what we do here is:
 *
 *   o  If we are echoing, then
 *	o  Look for character erase, line kill characters
 *	o  Echo the character (using '^' if a control character)
 *   o  Put the character in the input buffer
 *   o  Set 'lineend' as necessary
 */

static void
DoNextChar(c)
int	c;			/* Character to process */
{
    static char literalnextcharacter = 0;

    if (nextin >= (linein+sizeof linein)) {
	putchar('\7');		/* Ring bell */
	setlineend();
	return;
    }
    if (MODE_LOCAL_CHARS(globalmode)) {
	/* Look for some special character */
	if (!literalnextcharacter) {
	    if (c == termEraseChar) {
		killone();
		setlineend();
		return;
	    } else if (c == termKillChar) {
		while (nextin != linein) {
		    killone();
		}
		setlineend();
		return;
	    } else if (c == termLiteralNextChar) {
		literalnextcharacter = 1;
		return;
	    }
	}

	if (MODE_LOCAL_ECHO(globalmode)) {
	    if ((literalnextcharacter == 0) && ((c == '\r') || (c == '\n'))) {
		putchar('\r');
		putchar('\n');
		c = '\n';
	    } else if (!isprint(c) && !isspace(c)) {
		putchar('^');
		putchar(c^0x40);
	    } else {
		putchar(c);
	    }
	}
	literalnextcharacter = 0;
    }
    *nextin++ = c;
    setlineend();
}

static int
inputExists()
{
    int input;
    static state = 0;

    while (ctrlCCount) {
	DoNextChar(0x03);
	ctrlCCount--;
    }
    if (lineend) {
	return 1;
    }
D 10
    if (!kbhit()) {
E 10
I 10
#if	1	/* For BIOS variety of calls */
    if (kbhit() == 0) {
E 10
	return lineend;
    }
    input = getch();			/* MSC - get console character */
D 10
#if	0	/* For BIOS variety of calls */
E 10
    if ((input&0xff) == 0) {
I 10
	DoNextChar(0x01);		/* ^A */
    } else {
	DoNextChar(input&0xff);
    }
#else	/* 0 */
    if ((input = dirconio()) == -1) {
	return lineend;
    }
    if ((input&0xff) == 0) {
E 10
	if ((input&0xff00) == 0x0300) {		/* Null */
	    DoNextChar(0);
	} else {
	    DoNextChar(0x01);
	    if (input&0x8000) {
		DoNextChar(0x01);
		DoNextChar((input>>8)&0x7f);
	    } else {
		DoNextChar((input>>8)&0xff);
	    }
	}
    } else {
	DoNextChar(input&0xff);
    }
#endif	/* 0 */
D 10
    if ((input&0xff) == 0) {
	DoNextChar(0x01);		/* ^A */
    } else {
	DoNextChar(input&0xff);
    }
E 10
    return lineend;
}


void
CtrlCInterrupt()
{
    if (!MODE_COMMAND_LINE(globalmode)) {
I 24
	char far *Bios_Break = (char far *) (((long)0x40<<16)|0x71);

	*Bios_Break = 0;
E 24
	ctrlCCount++;		/* XXX */
	signal(SIGINT, CtrlCInterrupt);
    } else {
	closeallsockets();
D 10
	exit();
E 10
I 10
	exit(1);
E 10
    }
}
I 24

int
dosbinary(fd, onoff)
int	fd;
int	onoff;
{
    union REGS regs;
    int oldstate;

    /* Get old stuff */
    regs.h.ah = 0x44;
    regs.h.al = 0;
    regs.x.bx = fd;
    intdos(&regs, &regs);
    oldstate = regs.h.dl&(1<<5);		/* Save state */

    /* Set correct bits in new mode */
    regs.h.dh = 0;
    if (onoff) {
	regs.h.dl |= 1<<5;
    } else {
	regs.h.dl &= ~(1<<5);
    }

    /* Set in new mode */
    regs.h.ah = 0x44;
    regs.h.al = 1;
    regs.x.bx = fd;
    intdos(&regs, &regs);

    return oldstate;
}
E 24

/*
 * The MSDOS routines, called from elsewhere.
 */


static int
TerminalAutoFlush()				/* MSDOS */
{
    return 1;
}

static int
TerminalCanRead()
{
    return inputExists();
}


/*
E 9
 * Flush output to the terminal
 */
 
static void
TerminalFlushOutput()				/* MSDOS */
{
}

I 9

E 9
static void
I 9
TerminalNewMode(f)				/* MSDOS */
register int f;
{
I 18
    union REGS inregs;
    struct SREGS segregs;
    static old_1b_offset = 0, old_1b_segment = 0;

E 18
    globalmode = f;
D 19
    signal(SIGINT, CtrlCInterrupt);
E 19
I 18
    if (MODE_COMMAND_LINE(f)) {
I 19
	signal(SIGINT, SIG_DFL);
E 19
	if (old_1b_segment|old_1b_offset) {
	    inregs.h.ah = 0x25;
	    inregs.h.al = 0x1b;
	    inregs.x.dx = old_1b_offset;
	    segregs.ds = old_1b_segment;
	    intdosx(&inregs, &inregs, &segregs);
	    old_1b_segment = old_1b_offset = 0;
	}
I 19
	if (setmode(fileno(stdout), O_TEXT) == -1) {
	    ExitPerror("setmode (text)", 1);
	}
I 24
	(void) dosbinary(fileno(stdout), 0);
E 24
	if (setmode(fileno(stdin), O_TEXT) == -1) {
	    ExitPerror("setmode (text)", 1);
	}
I 24
	(void) dosbinary(fileno(stdin), 0);
E 24
E 19
    } else {
I 19
	signal(SIGINT, CtrlCInterrupt);
E 19
	if ((old_1b_segment|old_1b_offset) == 0) {
	    extern void iret_subr();
	    void (far *foo_subr)() = iret_subr;

	    inregs.h.ah = 0x35;
	    inregs.h.al = 0x1b;
	    intdosx(&inregs, &inregs, &segregs);
	    old_1b_segment = segregs.es;
	    old_1b_offset = inregs.x.bx;
	    inregs.h.ah = 0x25;
	    inregs.h.al = 0x1b;
	    inregs.x.dx = FP_OFF(foo_subr);
	    segregs.ds = FP_SEG(foo_subr);
	    intdosx(&inregs, &inregs, &segregs);
I 19
	}
D 21
	if (setmode(fileno(stdout), O_BINARY) == -1) {
	    ExitPerror("setmode (binary)", 1);
	}
	if (setmode(fileno(stdin), O_BINARY) == -1) {
	    ExitPerror("setmode (binary)", 1);
E 21
I 21
	if (MODE_LOCAL_CHARS(f)) {
	    if (setmode(fileno(stdout), O_TEXT) == -1) {
		ExitPerror("setmode (text)", 1);
	    }
I 24
	    (void) dosbinary(fileno(stdout), 0);
E 24
	    if (setmode(fileno(stdin), O_TEXT) == -1) {
		ExitPerror("setmode (text)", 1);
	    }
I 24
	    (void) dosbinary(fileno(stdin), 0);
E 24
	} else {
	    if (setmode(fileno(stdout), O_BINARY) == -1) {
		ExitPerror("setmode (binary)", 1);
	    }
I 24
	    (void) dosbinary(fileno(stdout), 1);
E 24
	    if (setmode(fileno(stdin), O_BINARY) == -1) {
		ExitPerror("setmode (binary)", 1);
	    }
I 24
	    (void) dosbinary(fileno(stdin), 1);
E 24
E 21
E 19
	}
    }
E 18
}


int
TerminalRead(fd, buffer, count)
int	fd;
char	*buffer;
int	count;
{
    int done = 0;

    for (;;) {
	while (inputExists() && (done < count)) {
	    *buffer++ = *nextout;
	    consumechar();
	    done++;
	}
	if (done) {
	    return(done);
	} else {
	    return 0;
	}
    }
}


static void
E 9
TerminalSaveState()				/* MSDOS */
{
I 24
    savedInState = dosbinary(fileno(stdin), 0);
    savedOutState = dosbinary(fileno(stdout), 0);
E 24
}

I 9
int
TerminalSpecialChars(c)			/* MSDOS */
{
    return 1;
}


E 9
static void
TerminalRestoreState()				/* MSDOS */
{
I 24
    (void) dosbinary(fileno(stdin), savedInState);
    (void) dosbinary(fileno(stdout), savedOutState);
E 24
}

I 9

static int
TerminalWrite(fd, buffer, count)		/* MSDOS */
int	fd;
char	*buffer;
int	count;
{
    return fwrite(buffer, sizeof (char), count, stdout);
}


static int
NetClose(fd)
{
    return closesocket(fd);
}

E 9
static void
NetNonblockingIO(fd, onoff)				/* MSDOS */
int
	fd,
	onoff;
{
    if (SetSockOpt(net, SOL_SOCKET, SO_NONBLOCKING, onoff)) {
	perror("setsockop (SO_NONBLOCKING) ");
D 9
	XXX();
E 9
I 9
	ExitString(stderr, "exiting\n", 1);
E 9
    }
}

static void
NetSigIO(fd)				/* MSDOS */
int fd;
{
}

static void
NetSetPgrp(fd)				/* MSDOS */
int fd;
{
}


#endif	/* defined(MSDOS) */

/*
E 8
I 3
 * Initialize variables.
 */

static void
tninit()
{
I 9
#if	defined(TN3270)
    Sent3270TerminalType = 0;
E 9
D 7
    extern char edata, end;

    bzero(&edata, &end - &edata);
E 7
    Ifrontp = Ibackp = Ibuf;
I 9
#endif	/* defined(TN3270) */

E 9
    tfrontp = tbackp = ttyobuf;
    nfrontp = nbackp = netobuf;
    
    /* Don't change telnetport */
I 7
    SB_CLEAR();
    ClearArray(hisopts);
    ClearArray(myopts);
    sbp = sibuf;
    tbp = tibuf;
E 7

I 7
D 16
    connected = net = scc = tcc = In3270 = ISend = 0;
E 16
I 16
    connected = net = scc = tcc = In3270 = ISend = donebinarytoggle = 0;
E 16
    telnetport = 0;
I 8
#if	defined(unix)
    HaveInput = 0;
#endif	/* defined(unix) */
E 8

    SYNCHing = 0;
D 9
    Sent3270TerminalType = 0;
E 9

D 8
#if	defined(unix)
    HaveInput = 0;
#endif	/* defined(unix) */
E 8
    errno = 0;

    flushline = 0;

E 7
    /* Don't change NetTrace */

    escape = CONTROL(']');
    echoc = CONTROL('E');

    flushline = 1;
    sp = getservbyname("telnet", "tcp");
    if (sp == 0) {
	ExitString(stderr, "telnet: tcp/telnet: unknown service\n",1);
	/*NOTREACHED*/
    }

#if	defined(TN3270)
D 7
    terminit();
    ctlrinit();
E 7
I 7
    init_ctlr();		/* Initialize some things */
    init_keyboard();
    init_screen();
    init_system();
E 7
#endif	/* defined(TN3270) */
}

/*
E 3
 * Various utility routines.
 */

static void
makeargv()
{
D 12
	register char *cp;
	register char **argp = margv;
E 12
I 12
    register char *cp;
    register char **argp = margv;
E 12

D 12
	margc = 0;
	for (cp = line; *cp;) {
		while (isspace(*cp))
			cp++;
		if (*cp == '\0')
			break;
		*argp++ = cp;
		margc += 1;
		while (*cp != '\0' && !isspace(*cp))
			cp++;
		if (*cp == '\0')
			break;
		*cp++ = '\0';
	}
	*argp++ = 0;
E 12
I 12
    margc = 0;
    cp = line;
    if (*cp == '!') {		/* Special case shell escape */
	*argp++ = "!";		/* No room in string to get this */
	margc++;
	cp++;
    }
    while (*cp) {
	while (isspace(*cp))
	    cp++;
	if (*cp == '\0')
	    break;
	*argp++ = cp;
	margc += 1;
	while (*cp != '\0' && !isspace(*cp))
	    cp++;
	if (*cp == '\0')
	    break;
	*cp++ = '\0';
    }
    *argp++ = 0;
E 12
}

static char *ambiguous;		/* special return value */
#define Ambiguous(t)	((t)&ambiguous)


static char **
genget(name, table, next)
char	*name;		/* name to match */
char	**table;		/* name entry in table */
char	**(*next)();	/* routine to return next entry in table */
{
	register char *p, *q;
	register char **c, **found;
	register int nmatches, longest;

I 17
	if (name == 0) {
	    return 0;
	}
E 17
	longest = 0;
	nmatches = 0;
	found = 0;
	for (c = table; (p = *c) != 0; c = (*next)(c)) {
		for (q = name;
		    (*q == *p) || (isupper(*q) && tolower(*q) == *p); p++, q++)
			if (*q == 0)		/* exact match? */
				return (c);
		if (!*q) {			/* the name was a prefix */
			if (q - name > longest) {
				longest = q - name;
				nmatches = 1;
				found = c;
			} else if (q - name == longest)
				nmatches++;
		}
	}
	if (nmatches > 1)
		return Ambiguous(char **);
	return (found);
}

/*
 * Make a character string into a number.
 *
 * Todo:  1.  Could take random integers (12, 0x12, 012, 0b1).
 */

static
special(s)
register char *s;
{
	register char c;
	char b;

	switch (*s) {
	case '^':
		b = *++s;
		if (b == '?') {
		    c = b | 0x40;		/* DEL */
		} else {
		    c = b & 0x1f;
		}
		break;
	default:
		c = *s;
		break;
	}
	return c;
}

/*
 * Construct a control character sequence
 * for a special character.
 */
static char *
control(c)
	register int c;
{
	static char buf[3];

	if (c == 0x7f)
		return ("^?");
	if (c == '\377') {
		return "off";
	}
	if (c >= 0x20) {
		buf[0] = c;
		buf[1] = 0;
	} else {
		buf[0] = '^';
		buf[1] = '@'+c;
		buf[2] = 0;
	}
	return (buf);
}


/*
 * upcase()
 *
 *	Upcase (in place) the argument.
 */

static void
upcase(argument)
register char *argument;
{
    register int c;

    while ((c = *argument) != 0) {
	if (islower(c)) {
	    *argument = toupper(c);
	}
	argument++;
    }
}
I 8

/*
 * SetSockOpt()
 *
 * Compensate for differences in 4.2 and 4.3 systems.
 */

static int
SetSockOpt(fd, level, option, yesno)
int
	fd,
	level,
	option,
	yesno;
{
#ifndef	NOT43
    return setsockopt(fd, level, option,
				(char *)&yesno, sizeof yesno);
#else	/* NOT43 */
    if (yesno == 0) {		/* Can't do that in 4.2! */
	fprintf(stderr, "Error: attempt to turn off an option 0x%x.\n",
				option);
	return -1;
    }
    return setsockopt(fd, level, option, 0, 0);
#endif	/* NOT43 */
}
E 8

/*
 * The following are routines used to print out debugging information.
 */


static void
Dump(direction, buffer, length)
char	direction;
char	*buffer;
int	length;
{
#   define BYTES_PER_LINE	32
#   define min(x,y)	((x<y)? x:y)
    char *pThis;
    int offset;

    offset = 0;

    while (length) {
	/* print one line */
	fprintf(NetTrace, "%c 0x%x\t", direction, offset);
	pThis = buffer;
	buffer = buffer+min(length, BYTES_PER_LINE);
	while (pThis < buffer) {
	    fprintf(NetTrace, "%.2x", (*pThis)&0xff);
	    pThis++;
	}
	fprintf(NetTrace, "\n");
	length -= BYTES_PER_LINE;
	offset += BYTES_PER_LINE;
	if (length < 0) {
	    return;
	}
	/* find next unique line */
    }
}


/*VARARGS*/
static void
printoption(direction, fmt, option, what)
	char *direction, *fmt;
	int option, what;
{
	if (!showoptions)
		return;
	fprintf(NetTrace, "%s ", direction+1);
	if (fmt == doopt)
		fmt = "do";
	else if (fmt == dont)
		fmt = "dont";
	else if (fmt == will)
		fmt = "will";
	else if (fmt == wont)
		fmt = "wont";
	else
		fmt = "???";
	if (option < (sizeof telopts/sizeof telopts[0]))
		fprintf(NetTrace, "%s %s", fmt, telopts[option]);
	else
		fprintf(NetTrace, "%s %d", fmt, option);
	if (*direction == '<') {
		fprintf(NetTrace, "\r\n");
		return;
	}
	fprintf(NetTrace, " (%s)\r\n", what ? "reply" : "don't reply");
}

static void
printsub(direction, pointer, length)
char	*direction,		/* "<" or ">" */
	*pointer;		/* where suboption data sits */
int	length;			/* length of suboption data */
{
    if (showoptions) {
	fprintf(NetTrace, "%s suboption ",
				(direction[0] == '<')? "Received":"Sent");
	switch (pointer[0]) {
	case TELOPT_TTYPE:
	    fprintf(NetTrace, "Terminal type ");
	    switch (pointer[1]) {
	    case TELQUAL_IS:
		{
		    char tmpbuf[sizeof subbuffer];
D 27
		    int minlen = min(length, sizeof tmpbuf);
E 27
I 27
		    int minlen = min(length-4, sizeof tmpbuf-1);
E 27

D 9
		    bcopy(pointer+2, tmpbuf, minlen);
E 9
I 9
		    memcpy(tmpbuf, pointer+2, minlen);
E 9
D 27
		    tmpbuf[minlen-1] = 0;
E 27
I 27
		    tmpbuf[minlen] = 0;
E 27
		    fprintf(NetTrace, "is %s.\n", tmpbuf);
		}
		break;
	    case TELQUAL_SEND:
		fprintf(NetTrace, "- request to send.\n");
		break;
	    default:
		fprintf(NetTrace,
				"- unknown qualifier %d (0x%x).\n", pointer[1]);
	    }
	    break;
	default:
	    fprintf(NetTrace, "Unknown option %d (0x%x)\n",
					pointer[0], pointer[0]);
	}
    }
}

/*
 * Check to see if any out-of-band data exists on a socket (for
 * Telnet "synch" processing).
 */

static int
stilloob(s)
int	s;		/* socket number */
{
    static struct timeval timeout = { 0 };
    fd_set	excepts;
    int value;

    do {
	FD_ZERO(&excepts);
	FD_SET(s, &excepts);
	value = select(s+1, (fd_set *)0, (fd_set *)0, &excepts, &timeout);
    } while ((value == -1) && (errno == EINTR));

    if (value < 0) {
	perror("select");
	quit();
    }
    if (FD_ISSET(s, &excepts)) {
	return 1;
    } else {
	return 0;
    }
}


/*
 *  netflush
 *		Send as much data as possible to the network,
 *	handling requests for urgent data.
 *
 *		The return value indicates whether we did any
 *	useful work.
 */


int
netflush()
{
    int n;

    if ((n = nfrontp - nbackp) > 0) {
	if (!neturg) {
D 9
	    n = write(net, nbackp, n);	/* normal write */
E 9
I 9
	    n = send(net, nbackp, n, 0);	/* normal write */
E 9
	} else {
	    n = neturg - nbackp;
	    /*
	     * In 4.2 (and 4.3) systems, there is some question about
	     * what byte in a sendOOB operation is the "OOB" data.
	     * To make ourselves compatible, we only send ONE byte
	     * out of band, the one WE THINK should be OOB (though
	     * we really have more the TCP philosophy of urgent data
	     * rather than the Unix philosophy of OOB data).
	     */
	    if (n > 1) {
		n = send(net, nbackp, n-1, 0);	/* send URGENT all by itself */
	    } else {
		n = send(net, nbackp, n, MSG_OOB);	/* URGENT data */
	    }
	}
    }
    if (n < 0) {
	if (errno != ENOBUFS && errno != EWOULDBLOCK) {
	    setcommandmode();
	    perror(hostname);
D 9
	    close(net);
E 9
I 9
	    NetClose(net);
E 9
	    neturg = 0;
	    longjmp(peerdied, -1);
	    /*NOTREACHED*/
	}
	n = 0;
    }
    if (netdata && n) {
	Dump('>', nbackp, n);
    }
    nbackp += n;
    if (nbackp >= neturg) {
	neturg = 0;
    }
    if (nbackp == nfrontp) {
	nbackp = nfrontp = netobuf;
    }
    return n > 0;
}

/*
 * nextitem()
 *
 *	Return the address of the next "item" in the TELNET data
 * stream.  This will be the address of the next character if
 * the current address is a user data character, or it will
 * be the address of the character following the TELNET command
 * if the current address is a TELNET IAC ("I Am a Command")
 * character.
 */

static char *
nextitem(current)
char	*current;
{
    if ((*current&0xff) != IAC) {
	return current+1;
    }
    switch (*(current+1)&0xff) {
    case DO:
    case DONT:
    case WILL:
    case WONT:
	return current+3;
    case SB:		/* loop forever looking for the SE */
	{
	    register char *look = current+2;

	    for (;;) {
		if ((*look++&0xff) == IAC) {
		    if ((*look++&0xff) == SE) {
			return look;
		    }
		}
	    }
	}
    default:
	return current+2;
    }
}
/*
 * netclear()
 *
 *	We are about to do a TELNET SYNCH operation.  Clear
 * the path to the network.
 *
 *	Things are a bit tricky since we may have sent the first
 * byte or so of a previous TELNET command into the network.
 * So, we have to scan the network buffer from the beginning
 * until we are up to where we want to be.
 *
 *	A side effect of what we do, just to keep things
 * simple, is to clear the urgent data pointer.  The principal
 * caller should be setting the urgent data pointer AFTER calling
 * us in any case.
 */

static void
netclear()
{
    register char *thisitem, *next;
    char *good;
#define	wewant(p)	((nfrontp > p) && ((*p&0xff) == IAC) && \
				((*(p+1)&0xff) != EC) && ((*(p+1)&0xff) != EL))

    thisitem = netobuf;

    while ((next = nextitem(thisitem)) <= nbackp) {
	thisitem = next;
    }

    /* Now, thisitem is first before/at boundary. */

    good = netobuf;	/* where the good bytes go */

    while (nfrontp > thisitem) {
	if (wewant(thisitem)) {
	    int length;

	    next = thisitem;
	    do {
		next = nextitem(next);
	    } while (wewant(next) && (nfrontp > next));
	    length = next-thisitem;
D 9
	    bcopy(thisitem, good, length);
E 9
I 9
	    memcpy(good, thisitem, length);
E 9
	    good += length;
	    thisitem = next;
	} else {
	    thisitem = nextitem(thisitem);
	}
    }

    nbackp = netobuf;
    nfrontp = good;		/* next byte to be sent */
    neturg = 0;
}

/*
 * These routines add various telnet commands to the data stream.
 */

#if	defined(NOT43)
static int
#else	/* defined(NOT43) */
static void
#endif	/* defined(NOT43) */
dosynch()
{
    netclear();			/* clear the path to the network */
    NET2ADD(IAC, DM);
    neturg = NETLOC()-1;	/* Some systems are off by one XXX */

#if	defined(NOT43)
    return 0;
#endif	/* defined(NOT43) */
}

static void
doflush()
{
    NET2ADD(IAC, DO);
    NETADD(TELOPT_TM);
    flushline = 1;
    flushout = 1;
    ttyflush();
    /* do printoption AFTER flush, otherwise the output gets tossed... */
    printoption("<SENT", doopt, TELOPT_TM, 0);
}

static void
intp()
{
    NET2ADD(IAC, IP);
    if (autoflush) {
	doflush();
    }
    if (autosynch) {
	dosynch();
    }
}

static void
sendbrk()
{
    NET2ADD(IAC, BREAK);
    if (autoflush) {
	doflush();
    }
    if (autosynch) {
	dosynch();
    }
}

/*
 *		Send as much data as possible to the terminal.
 *
 *		The return value indicates whether we did any
 *	useful work.
 */


static int
ttyflush()
{
    int n;

    if ((n = tfrontp - tbackp) > 0) {
	if (!(SYNCHing||flushout)) {
D 9
	    n = write(tout, tbackp, n);
E 9
I 9
	    n = TerminalWrite(tout, tbackp, n);
E 9
	} else {
D 8
	    ioctl(fileno(stdout), TIOCFLUSH, (char *) 0);
E 8
I 8
	    TerminalFlushOutput();
E 8
	    /* we leave 'n' alone! */
	}
    }
    if (n >= 0) {
	tbackp += n;
	if (tbackp == tfrontp) {
	    tbackp = tfrontp = ttyobuf;
	}
    }
    return n > 0;
}

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

#if	defined(unix)
/*
 * Various signal handling routines.
 */

static void
deadpeer()
{
	setcommandmode();
	longjmp(peerdied, -1);
}

static void
intr()
{
    if (localchars) {
	intp();
	return;
    }
    setcommandmode();
    longjmp(toplevel, -1);
}

static void
intr2()
{
    if (localchars) {
	sendbrk();
	return;
    }
}

static void
doescape()
{
    command(0);
}
#endif	/* defined(unix) */

D 8
static int	globalmode = 0;
/*	Various modes */
#define	MODE_LINE(m)	(modelist[m].modetype & LINE)
#define	MODE_LOCAL_CHARS(m)	(modelist[m].modetype &  LOCAL_CHARS)

#define	LOCAL_CHARS	0x01		/* Characters processed locally */
#define	LINE		0x02		/* Line-by-line mode of operation */

static struct {
    char *modedescriptions;
    char modetype;
} modelist[] = {
	{ "telnet command mode", 0 },
	{ "character-at-a-time mode", 0 },
	{ "character-at-a-time mode (local echo)", LOCAL_CHARS },
	{ "line-by-line mode (remote echo)", LINE | LOCAL_CHARS },
	{ "line-by-line mode", LINE | LOCAL_CHARS },
	{ "line-by-line mode (local echoing suppressed)", LINE | LOCAL_CHARS },
	{ "3270 mode", 0 },
};
E 8
/*
D 8
 * Mode - set up terminal to a specific mode.
 */


static void
mode(f)
	register int f;
{
    static int prevmode = 0;
    struct tchars *tc;
    struct tchars tc3;
    struct ltchars *ltc;
    struct sgttyb sb;
    int onoff;
#if	defined(unix)
    int old;
#endif	/* defined(unix) */
    struct	tchars notc2;
    struct	ltchars noltc2;
    static struct	tchars notc =	{ -1, -1, -1, -1, -1, -1 };
    static struct	ltchars noltc =	{ -1, -1, -1, -1, -1, -1 };

    globalmode = f;
    if (prevmode == f)
	return;
#if	defined(unix)
    old = prevmode;
#endif	/* defined(unix) */
    prevmode = f;
    sb = nttyb;

    switch (f) {

    case 0:
	onoff = 0;
	tc = &otc;
	ltc = &oltc;
	break;

    case 1:		/* remote character processing, remote echo */
    case 2:		/* remote character processing, local echo */
    case 6:		/* 3270 mode - like 1, but with xon/xoff local */
		    /* (might be nice to have "6" in telnet also...) */
	    sb.sg_flags |= CBREAK;
	    if ((f == 1) || (f == 6)) {
		sb.sg_flags &= ~(ECHO|CRMOD);
	    } else {
		sb.sg_flags |= ECHO|CRMOD;
	    }
	    sb.sg_erase = sb.sg_kill = -1;
	    if (f == 6) {
		tc = &tc3;
		tc3 = notc;
		    /* get XON, XOFF characters */
		tc3.t_startc = otc.t_startc;
		tc3.t_stopc = otc.t_stopc;
	    } else {
		/*
		 * If user hasn't specified one way or the other,
		 * then default to not trapping signals.
		 */
		if (!donelclchars) {
		    localchars = 0;
		}
		if (localchars) {
		    notc2 = notc;
		    notc2.t_intrc = ntc.t_intrc;
		    notc2.t_quitc = ntc.t_quitc;
		    tc = &notc2;
		} else {
		    tc = &notc;
		}
	    }
	    ltc = &noltc;
	    onoff = 1;
	    break;
    case 3:		/* local character processing, remote echo */
    case 4:		/* local character processing, local echo */
    case 5:		/* local character processing, no echo */
	    sb.sg_flags &= ~CBREAK;
	    sb.sg_flags |= CRMOD;
	    if (f == 4)
		sb.sg_flags |= ECHO;
	    else
		sb.sg_flags &= ~ECHO;
	    notc2 = ntc;
	    tc = &notc2;
	    noltc2 = oltc;
	    ltc = &noltc2;
I 4
#if defined(unix)
E 4
	    /*
	     * If user hasn't specified one way or the other,
	     * then default to trapping signals.
	     */
	    if (!donelclchars) {
		localchars = 1;
	    }
	    if (localchars) {
		notc2.t_brkc = nltc.t_flushc;
		noltc2.t_flushc = -1;
	    } else {
		notc2.t_intrc = notc2.t_quitc = -1;
	    }
I 4
#else	/* defined(unix) */
	    notc2.t_intrc = -1;
#endif	/* defined(unix) */
E 4
	    noltc2.t_suspc = escape;
	    noltc2.t_dsuspc = -1;
	    onoff = 1;
	    break;

    default:
	    return;
    }
    ioctl(tin, TIOCSLTC, (char *)ltc);
    ioctl(tin, TIOCSETC, (char *)tc);
    ioctl(tin, TIOCSETP, (char *)&sb);
#if	(!defined(TN3270)) || ((!defined(NOT43)) || defined(PUTCHAR))
    ioctl(tin, FIONBIO, (char *)&onoff);
    ioctl(tout, FIONBIO, (char *)&onoff);
#endif	/* (!defined(TN3270)) || ((!defined(NOT43)) || defined(PUTCHAR)) */
#if	defined(TN3270) && !defined(DEBUG)
    ioctl(tin, FIOASYNC, (char *)&onoff);
#endif	/* defined(TN3270) && !defined(DEBUG) */

#if	defined(unix)
    if (MODE_LINE(f)) {
	signal(SIGTSTP, doescape);
    } else if (MODE_LINE(old)) {
	signal(SIGTSTP, SIG_DFL);
	sigsetmask(sigblock(0) & ~(1<<(SIGTSTP-1)));
    }
#endif	/* defined(unix) */
}

/*
E 8
 * These routines decides on what the mode should be (based on the values
 * of various global variables).
 */


static
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
D 8
    mode(getconnmode());
E 8
I 8
    TerminalNewMode(getconnmode());
E 8
}


void
setcommandmode()
{
D 8
    mode(0);
E 8
I 8
    TerminalNewMode(0);
E 8
}

static void
willoption(option, reply)
	int option, reply;
{
	char *fmt;

	switch (option) {

I 4
	case TELOPT_ECHO:
E 4
#	if defined(TN3270)
I 4
	    /*
	     * The following is a pain in the rear-end.
	     * Various IBM servers (some versions of Wiscnet,
	     * possibly Fibronics/Spartacus, and who knows who
	     * else) will NOT allow us to send "DO SGA" too early
	     * in the setup proceedings.  On the other hand,
	     * 4.2 servers (telnetd) won't set SGA correctly.
	     * So, we are stuck.  Empirically (but, based on
	     * a VERY small sample), the IBM servers don't send
	     * out anything about ECHO, so we postpone our sending
	     * "DO SGA" until we see "WILL ECHO" (which 4.2 servers
	     * DO send).
	     */
	    {
D 7
		static int askedSGA = 0;

E 7
		if (askedSGA == 0) {
		    askedSGA = 1;
		    if (!hisopts[TELOPT_SGA]) {
			willoption(TELOPT_SGA, 0);
		    }
		}
	    }
		/* Fall through */
E 4
	case TELOPT_EOR:
	case TELOPT_BINARY:
#endif	/* defined(TN3270) */
D 4
	case TELOPT_ECHO:
E 4
	case TELOPT_SGA:
		settimer(modenegotiated);
		hisopts[option] = 1;
		fmt = doopt;
		setconnmode();		/* possibly set new tty mode */
		break;

	case TELOPT_TM:
		return;			/* Never reply to TM will's/wont's */

	default:
		fmt = dont;
		break;
	}
	sprintf(nfrontp, fmt, option);
	nfrontp += sizeof (dont) - 2;
	if (reply)
		printoption(">SENT", fmt, option, reply);
	else
		printoption("<SENT", fmt, option, reply);
}

static void
wontoption(option, reply)
	int option, reply;
{
	char *fmt;

	switch (option) {

	case TELOPT_ECHO:
	case TELOPT_SGA:
		settimer(modenegotiated);
		hisopts[option] = 0;
		fmt = dont;
		setconnmode();			/* Set new tty mode */
		break;

	case TELOPT_TM:
		return;		/* Never reply to TM will's/wont's */

	default:
		fmt = dont;
I 26
		hisopts[option] = 0;
		break;
E 26
	}
	sprintf(nfrontp, fmt, option);
	nfrontp += sizeof (doopt) - 2;
	if (reply)
		printoption(">SENT", fmt, option, reply);
	else
		printoption("<SENT", fmt, option, reply);
}

static void
dooption(option)
	int option;
{
	char *fmt;

	switch (option) {

	case TELOPT_TM:
		fmt = will;
		break;

#	if defined(TN3270)
	case TELOPT_EOR:
	case TELOPT_BINARY:
#	endif	/* defined(TN3270) */
	case TELOPT_TTYPE:		/* terminal type option */
	case TELOPT_SGA:		/* no big deal */
		fmt = will;
		myopts[option] = 1;
		break;

	case TELOPT_ECHO:		/* We're never going to echo... */
	default:
		fmt = wont;
		break;
	}
	sprintf(nfrontp, fmt, option);
	nfrontp += sizeof (doopt) - 2;
	printoption(">SENT", fmt, option, 0);
}

/*
 * suboption()
 *
 *	Look at the sub-option buffer, and try to be helpful to the other
 * side.
 *
 *	Currently we recognize:
 *
 *		Terminal type, send request.
 */

static void
suboption()
{
    printsub("<", subbuffer, subend-subbuffer+1);
    switch (subbuffer[0]&0xff) {
    case TELOPT_TTYPE:
	if ((subbuffer[1]&0xff) != TELQUAL_SEND) {
	    ;
	} else {
	    char *name;
	    char namebuf[41];
	    extern char *getenv();
	    int len;

#if	defined(TN3270)
	    /*
D 3
	     * Try to send a 3270 type terminal name.  Decide which one base
E 3
I 3
	     * Try to send a 3270 type terminal name.  Decide which one based
E 3
	     * on the format of our screen, and (in the future) color
	     * capaiblities.
	     */
I 8
#if	defined(unix)
E 8
D 9
	    if ((initscr() != ERR) &&	/* Initialize curses to get line size */
		(LINES >= 24) && (COLS >= 80)) {
E 9
I 9
	    if (initscr() != ERR) {	/* Initialize curses to get line size */
		MaxNumberLines = LINES;
		MaxNumberColumns = COLS;
	    }
#else	/* defined(unix) */
	    InitTerminal();
#endif	/* defined(unix) */
	    if ((MaxNumberLines >= 24) && (MaxNumberColumns >= 80)) {
E 9
		Sent3270TerminalType = 1;
D 9
		if ((LINES >= 27) && (COLS >= 132)) {
E 9
I 9
		if ((MaxNumberLines >= 27) && (MaxNumberColumns >= 132)) {
E 9
		    MaxNumberLines = 27;
		    MaxNumberColumns = 132;
		    sb_terminal[SBTERMMODEL] = '5';
D 9
		} else if (LINES >= 43) {
E 9
I 9
		} else if (MaxNumberLines >= 43) {
E 9
		    MaxNumberLines = 43;
		    MaxNumberColumns = 80;
		    sb_terminal[SBTERMMODEL] = '4';
D 9
		} else if (LINES >= 32) {
E 9
I 9
		} else if (MaxNumberLines >= 32) {
E 9
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
		    ExitString(stderr,
			"Programming error:  MAXSCREENSIZE too small.\n", 1);
		    /*NOTREACHED*/
		}
D 9
		bcopy(sb_terminal, nfrontp, sizeof sb_terminal);
E 9
I 9
		memcpy(nfrontp, sb_terminal, sizeof sb_terminal);
E 9
		printsub(">", nfrontp+2, sizeof sb_terminal-2);
		nfrontp += sizeof sb_terminal;
		return;
	    }
I 8
D 9
#else	/* defined(unix) */
	    XXX();
#endif	/* defined(unix) */
E 9
E 8
#endif	/* defined(TN3270) */

	    name = getenv("TERM");
	    if ((name == 0) || ((len = strlen(name)) > 40)) {
		name = "UNKNOWN";
	    }
	    if ((len + 4+2) < NETROOM()) {
		strcpy(namebuf, name);
		upcase(namebuf);
		sprintf(nfrontp, "%c%c%c%c%s%c%c", IAC, SB, TELOPT_TTYPE,
				    TELQUAL_IS, namebuf, IAC, SE);
		printsub(">", nfrontp+2, 4+strlen(namebuf)+2-2-2);
		nfrontp += 4+strlen(namebuf)+2;
	    } else {
		ExitString(stderr, "No room in buffer for terminal type.\n",
							1);
		/*NOTREACHED*/
	    }
	}

    default:
	break;
    }
}

#if	defined(TN3270)
static void
SetIn3270()
{
    if (Sent3270TerminalType && myopts[TELOPT_BINARY]
D 16
					&& hisopts[TELOPT_BINARY]) {
E 16
I 16
			    && hisopts[TELOPT_BINARY] && !donebinarytoggle) {
E 16
	if (!In3270) {
	    In3270 = 1;
D 3
	    OptInit();		/* initialize mappings */
E 3
I 3
	    Init3270();		/* Initialize 3270 functions */
E 3
	    /* initialize terminal key mapping */
D 3
	    (void) DataFromTerminal(ttyobuf, 0);
	    StartScreen();	/* Start terminal going */
E 3
I 3
	    InitTerminal();	/* Start terminal going */
I 26
	    LocalClearScreen();	/* Make sure the screen is clear */
E 26
E 3
	    setconnmode();
	}
    } else {
	if (In3270) {
	    StopScreen(1);
	    In3270 = 0;
I 12
	    Stop3270();		/* Tell 3270 we aren't here anymore */
E 12
	    setconnmode();
	}
    }
}
#endif	/* defined(TN3270) */

D 7
/*
 * Telnet receiver states for fsm
 */
#define	TS_DATA		0
#define	TS_IAC		1
#define	TS_WILL		2
#define	TS_WONT		3
#define	TS_DO		4
#define	TS_DONT		5
#define	TS_CR		6
#define	TS_SB		7		/* sub-option collection */
#define	TS_SE		8		/* looking for sub-option end */
E 7

static void
telrcv()
{
    register int c;
D 7
    static int state = TS_DATA;
E 7
I 7
    static int telrcv_state = TS_DATA;
E 7
#   if defined(TN3270)
    register int Scc;
    register char *Sbp;
#   endif /* defined(TN3270) */

    while ((scc > 0) && (TTYROOM() > 2)) {
	c = *sbp++ & 0xff, scc--;
D 7
	switch (state) {
E 7
I 7
	switch (telrcv_state) {
E 7

	case TS_CR:
D 7
	    state = TS_DATA;
E 7
I 7
	    telrcv_state = TS_DATA;
E 7
	    if (c == '\0') {
		break;	/* Ignore \0 after CR */
	    } else if (c == '\n') {
		if (hisopts[TELOPT_ECHO] && !crmod) {
		    TTYADD(c);
		}
		break;
	    }
	    /* Else, fall through */

	case TS_DATA:
	    if (c == IAC) {
D 7
		state = TS_IAC;
E 7
I 7
		telrcv_state = TS_IAC;
E 7
		continue;
	    }
#	    if defined(TN3270)
	    if (In3270) {
		*Ifrontp++ = c;
		Sbp = sbp;
		Scc = scc;
		while (Scc > 0) {
		    c = *Sbp++ & 0377, Scc--;
		    if (c == IAC) {
D 7
			state = TS_IAC;
E 7
I 7
			telrcv_state = TS_IAC;
E 7
			break;
		    }
		    *Ifrontp++ = c;
		}
		sbp = Sbp;
		scc = Scc;
	    } else
#	    endif /* defined(TN3270) */
		    /*
		     * The 'crmod' hack (see following) is needed
		     * since we can't * set CRMOD on output only.
		     * Machines like MULTICS like to send \r without
		     * \n; since we must turn off CRMOD to get proper
		     * input, the mapping is done here (sigh).
		     */
D 22
	    if (c == '\r') {
E 22
I 22
	    if ((c == '\r') && !hisopts[TELOPT_BINARY]) {
E 22
		if (scc > 0) {
		    c = *sbp&0xff;
		    if (c == 0) {
			sbp++, scc--;
			/* a "true" CR */
			TTYADD('\r');
		    } else if (!hisopts[TELOPT_ECHO] &&
					(c == '\n')) {
			sbp++, scc--;
			TTYADD('\n');
		    } else {
			TTYADD('\r');
			if (crmod) {
				TTYADD('\n');
			}
		    }
		} else {
D 7
		    state = TS_CR;
E 7
I 7
		    telrcv_state = TS_CR;
E 7
		    TTYADD('\r');
		    if (crmod) {
			    TTYADD('\n');
		    }
		}
	    } else {
		TTYADD(c);
	    }
	    continue;

	case TS_IAC:
	    switch (c) {
	    
	    case WILL:
D 7
		state = TS_WILL;
E 7
I 7
		telrcv_state = TS_WILL;
E 7
		continue;

	    case WONT:
D 7
		state = TS_WONT;
E 7
I 7
		telrcv_state = TS_WONT;
E 7
		continue;

	    case DO:
D 7
		state = TS_DO;
E 7
I 7
		telrcv_state = TS_DO;
E 7
		continue;

	    case DONT:
D 7
		state = TS_DONT;
E 7
I 7
		telrcv_state = TS_DONT;
E 7
		continue;

	    case DM:
		    /*
		     * We may have missed an urgent notification,
		     * so make sure we flush whatever is in the
		     * buffer currently.
		     */
		SYNCHing = 1;
		ttyflush();
		SYNCHing = stilloob(net);
		settimer(gotDM);
		break;

	    case NOP:
	    case GA:
		break;

	    case SB:
		SB_CLEAR();
D 7
		state = TS_SB;
E 7
I 7
		telrcv_state = TS_SB;
E 7
		continue;

#	    if defined(TN3270)
	    case EOR:
		if (In3270) {
		    Ibackp += DataFromNetwork(Ibackp, Ifrontp-Ibackp, 1);
		    if (Ibackp == Ifrontp) {
			Ibackp = Ifrontp = Ibuf;
			ISend = 0;	/* should have been! */
		    } else {
			ISend = 1;
		    }
		}
		break;
#	    endif /* defined(TN3270) */

	    case IAC:
#	    if !defined(TN3270)
		TTYADD(IAC);
#	    else /* !defined(TN3270) */
		if (In3270) {
		    *Ifrontp++ = IAC;
		} else {
		    TTYADD(IAC);
		}
#	    endif /* !defined(TN3270) */
		break;

	    default:
		break;
	    }
D 7
	    state = TS_DATA;
E 7
I 7
	    telrcv_state = TS_DATA;
E 7
	    continue;

	case TS_WILL:
	    printoption(">RCVD", will, c, !hisopts[c]);
	    if (c == TELOPT_TM) {
		if (flushout) {
		    flushout = 0;
		}
	    } else if (!hisopts[c]) {
		willoption(c, 1);
	    }
	    SetIn3270();
D 7
	    state = TS_DATA;
E 7
I 7
	    telrcv_state = TS_DATA;
E 7
	    continue;

	case TS_WONT:
	    printoption(">RCVD", wont, c, hisopts[c]);
	    if (c == TELOPT_TM) {
		if (flushout) {
		    flushout = 0;
		}
	    } else if (hisopts[c]) {
		wontoption(c, 1);
	    }
	    SetIn3270();
D 7
	    state = TS_DATA;
E 7
I 7
	    telrcv_state = TS_DATA;
E 7
	    continue;

	case TS_DO:
	    printoption(">RCVD", doopt, c, !myopts[c]);
	    if (!myopts[c])
		dooption(c);
	    SetIn3270();
D 7
	    state = TS_DATA;
E 7
I 7
	    telrcv_state = TS_DATA;
E 7
	    continue;

	case TS_DONT:
	    printoption(">RCVD", dont, c, myopts[c]);
	    if (myopts[c]) {
		myopts[c] = 0;
		sprintf(nfrontp, wont, c);
		nfrontp += sizeof (wont) - 2;
		flushline = 1;
		setconnmode();	/* set new tty mode (maybe) */
		printoption(">SENT", wont, c, 0);
	    }
	    SetIn3270();
D 7
	    state = TS_DATA;
E 7
I 7
	    telrcv_state = TS_DATA;
E 7
	    continue;

	case TS_SB:
	    if (c == IAC) {
D 7
		state = TS_SE;
E 7
I 7
		telrcv_state = TS_SE;
E 7
	    } else {
		SB_ACCUM(c);
	    }
	    continue;

	case TS_SE:
	    if (c != SE) {
		if (c != IAC) {
		    SB_ACCUM(IAC);
		}
		SB_ACCUM(c);
D 7
		state = TS_SB;
E 7
I 7
		telrcv_state = TS_SB;
E 7
	    } else {
		SB_TERM();
		suboption();	/* handle sub-option */
		SetIn3270();
D 7
		state = TS_DATA;
E 7
I 7
		telrcv_state = TS_DATA;
E 7
	    }
	}
    }
}

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
I 9
#if	defined(unix)
E 9
    fd_set	o;

D 9
    origCount = count;
E 9
    FD_ZERO(&o);
I 9
#endif	/* defined(unix) */
    origCount = count;
E 9

    while (count) {
	if (tfrontp >= ttyobuf+sizeof ttyobuf) {
	    ttyflush();
	    while (tfrontp >= ttyobuf+sizeof ttyobuf) {
I 9
#if	defined(unix)
E 9
		FD_SET(tout, &o);
		(void) select(tout+1, (fd_set *) 0, &o, (fd_set *) 0,
						(struct timeval *) 0);
I 9
#endif	/* defined(unix) */
E 9
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
I 9
#if	defined(unix)
E 9
    fd_set	o;

    FD_ZERO(&o);
I 9
#endif	/* defined(unix) */
E 9

    if (tfrontp == tbackp) {
I 9
#if	defined(unix)
E 9
	FD_SET(tout, &o);
	(void) select(tout+1, (int *) 0, &o, (int *) 0,
			(struct timeval *) 0);	/* wait for TTLOWAT */
I 9
#endif	/* defined(unix) */
E 9
    } else {
	while (tfrontp != tbackp) {
	    ttyflush();
I 9
#if	defined(unix)
E 9
	    FD_SET(tout, &o);
	    (void) select(tout+1, (int *) 0, &o, (int *) 0,
				(struct timeval *) 0);	/* wait for TTLOWAT */
I 9
#endif	/* defined(unix) */
E 9
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
D 9
		bcopy(Ibackp, Ibuf, Ifrontp-Ibackp);
E 9
I 9
		memcpy(Ibuf, Ibackp, Ifrontp-Ibackp);
E 9
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
I 15
#if	defined(unix)
	HaveInput = 0;
#endif	/* defined(unix) */
E 15
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


#if	defined(TN3270) && ((!defined(NOT43)) || defined(PUTCHAR))
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
#endif	/* defined(TN3270) && ((!defined(NOT43)) || defined(PUTCHAR)) */

static void
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

static void
Exit(returnCode)
int returnCode;
{
    SetForExit();
    exit(returnCode);
}

void
ExitString(file, string, returnCode)
FILE *file;
char *string;
int returnCode;
{
    SetForExit();
    fwrite(string, 1, strlen(string), file);
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

#endif	/* defined(TN3270) */

D 12
static
E 12
I 12
/*
 * Scheduler()
 *
 * Try to do something.
 *
 * If we do something useful, return 1; else return 0.
 *
 */


int
E 12
Scheduler(block)
int	block;			/* should we block in the select ? */
{
    register int c;
		/* One wants to be a bit careful about setting returnValue
		 * to one, since a one implies we did some useful work,
		 * and therefore probably won't be called to block next
		 * time (TN3270 mode only).
		 */
    int returnValue = 0;
    static struct timeval TimeValue = { 0 };

    if (scc < 0 && tcc < 0) {
	return -1;
    }

    if ((!MODE_LINE(globalmode) || flushline) && NETBYTES()) {
	FD_SET(net, &obits);
    } 
I 9
#if	!defined(MSDOS)
E 9
    if (TTYBYTES()) {
	FD_SET(tout, &obits);
    }
I 22
#if	defined(TN3270)
E 22
D 12
    if ((tcc == 0) && NETROOM()) {
E 12
I 12
    if ((tcc == 0) && NETROOM() && (shell_active == 0)) {
E 12
	FD_SET(tin, &ibits);
    }
I 22
#else	/* defined(TN3270) */
    if ((tcc == 0) && NETROOM()) {
	FD_SET(tin, &ibits);
    }
#endif	/* defined(TN3270) */
E 22
I 9
#endif	/* !defined(MSDOS) */
E 9
#   if !defined(TN3270)
    if (TTYROOM()) {
	FD_SET(net, &ibits);
    }
#   else /* !defined(TN3270) */
    if (!ISend && TTYROOM()) {
	FD_SET(net, &ibits);
    }
#   endif /* !defined(TN3270) */
    if (!SYNCHing) {
	FD_SET(net, &xbits);
    }
#   if defined(TN3270) && defined(unix)
    if (HaveInput) {
	HaveInput = 0;
	signal(SIGIO, inputAvailable);
    }
#endif	/* defined(TN3270) && defined(unix) */
    if ((c = select(16, &ibits, &obits, &xbits,
D 9
			block? (struct timeval *)0 : &TimeValue)) < 1) {
E 9
I 9
			block? (struct timeval *)0 : &TimeValue)) < 0) {
E 9
	if (c == -1) {
		    /*
		     * we can get EINTR if we are in line mode,
		     * and the user does an escape (TSTP), or
		     * some other signal generator.
		     */
	    if (errno == EINTR) {
		return 0;
	    }
#	    if defined(TN3270)
		    /*
		     * we can get EBADF if we were in transparent
		     * mode, and the transcom process died.
		    */
	    if (errno == EBADF) {
			/*
			 * zero the bits (even though kernel does it)
			 * to make sure we are selecting on the right
			 * ones.
			*/
		FD_ZERO(&ibits);
		FD_ZERO(&obits);
		FD_ZERO(&xbits);
		return 0;
	    }
#	    endif /* defined(TN3270) */
		    /* I don't like this, does it ever happen? */
	    printf("sleep(5) from telnet, after select\r\n");
#if	defined(unix)
	    sleep(5);
#endif	/* defined(unix) */
	}
	return 0;
    }

    /*
     * Any urgent data?
     */
    if (FD_ISSET(net, &xbits)) {
	FD_CLR(net, &xbits);
	SYNCHing = 1;
	ttyflush();	/* flush already enqueued data */
    }

    /*
     * Something to read from the network...
     */
    if (FD_ISSET(net, &ibits)) {
	int canread;

	FD_CLR(net, &ibits);
	if (scc == 0) {
	    sbp = sibuf;
	}
D 6
	canread = sibuf + sizeof sibuf - sbp;
E 6
I 6
	canread = sibuf + sizeof sibuf - (sbp+scc);
E 6
#if	!defined(SO_OOBINLINE)
	    /*
	     * In 4.2 (and some early 4.3) systems, the
	     * OOB indication and data handling in the kernel
	     * is such that if two separate TCP Urgent requests
	     * come in, one byte of TCP data will be overlaid.
	     * This is fatal for Telnet, but we try to live
	     * with it.
	     *
	     * In addition, in 4.2 (and...), a special protocol
	     * is needed to pick up the TCP Urgent data in
	     * the correct sequence.
	     *
	     * What we do is:  if we think we are in urgent
	     * mode, we look to see if we are "at the mark".
	     * If we are, we do an OOB receive.  If we run
	     * this twice, we will do the OOB receive twice,
	     * but the second will fail, since the second
	     * time we were "at the mark", but there wasn't
	     * any data there (the kernel doesn't reset
	     * "at the mark" until we do a normal read).
	     * Once we've read the OOB data, we go ahead
	     * and do normal reads.
	     *
	     * There is also another problem, which is that
	     * since the OOB byte we read doesn't put us
	     * out of OOB state, and since that byte is most
	     * likely the TELNET DM (data mark), we would
	     * stay in the TELNET SYNCH (SYNCHing) state.
	     * So, clocks to the rescue.  If we've "just"
	     * received a DM, then we test for the
	     * presence of OOB data when the receive OOB
	     * fails (and AFTER we did the normal mode read
	     * to clear "at the mark").
	     */
	if (SYNCHing) {
	    int atmark;

	    ioctl(net, SIOCATMARK, (char *)&atmark);
	    if (atmark) {
D 6
		c = recv(net, sibuf, canread, MSG_OOB);
E 6
I 6
		c = recv(net, sbp+scc, canread, MSG_OOB);
E 6
		if ((c == -1) && (errno == EINVAL)) {
D 6
		    c = read(net, sibuf, canread);
E 6
I 6
D 9
		    c = read(net, sbp+scc, canread);
E 9
I 9
		    c = recv(net, sbp+scc, canread, 0);
E 9
E 6
		    if (clocks.didnetreceive < clocks.gotDM) {
			SYNCHing = stilloob(net);
		    }
		}
	    } else {
D 6
		c = read(net, sibuf, canread);
E 6
I 6
D 9
		c = read(net, sbp+scc, canread);
E 9
I 9
		c = recv(net, sbp+scc, canread, 0);
E 9
E 6
	    }
	} else {
D 6
	    c = read(net, sibuf, canread);
E 6
I 6
D 9
	    c = read(net, sbp+scc, canread);
E 9
I 9
	    c = recv(net, sbp+scc, canread, 0);
E 9
E 6
	}
	settimer(didnetreceive);
#else	/* !defined(SO_OOBINLINE) */
D 6
	c = read(net, sbp, canread);
E 6
I 6
D 9
	c = read(net, sbp+scc, canread);
E 9
I 9
	c = recv(net, sbp+scc, canread, 0);
E 9
E 6
#endif	/* !defined(SO_OOBINLINE) */
	if (c < 0 && errno == EWOULDBLOCK) {
	    c = 0;
	} else if (c <= 0) {
	    return -1;
	}
	if (netdata) {
D 6
	    Dump('<', sbp, c);
E 6
I 6
	    Dump('<', sbp+scc, c);
E 6
	}
	scc += c;
	returnValue = 1;
    }

    /*
     * Something to read from the tty...
     */
D 9
    if (FD_ISSET(tin, &ibits)) {
E 9
I 9
#if	defined(MSDOS)
D 12
    if ((tcc == 0) && NETROOM() && TerminalCanRead())
E 12
I 12
    if ((tcc == 0) && NETROOM() && (shell_active == 0) && TerminalCanRead())
E 12
#else	/* defined(MSDOS) */
    if (FD_ISSET(tin, &ibits))
#endif	/* defined(MSDOS) */
				    {
E 9
	FD_CLR(tin, &ibits);
	if (tcc == 0) {
	    tbp = tibuf;	/* nothing left, reset */
	}
D 9
	c = read(tin, tbp, tibuf+sizeof tibuf - tbp);
E 9
I 9
	c = TerminalRead(tin, tbp, tibuf+sizeof tibuf - tbp);
E 9
	if (c < 0 && errno == EWOULDBLOCK) {
	    c = 0;
	} else {
I 8
#if	defined(unix)
E 8
	    /* EOF detection for line mode!!!! */
	    if (c == 0 && MODE_LOCAL_CHARS(globalmode)) {
			/* must be an EOF... */
		*tbp = ntc.t_eofc;
		c = 1;
	    }
I 8
#endif	/* defined(unix) */
E 8
	    if (c <= 0) {
		tcc = c;
		return -1;
	    }
	}
	tcc += c;
	returnValue = 1;		/* did something useful */
    }

#   if defined(TN3270)
    if (tcc > 0) {
	if (In3270) {
	    c = DataFromTerminal(tbp, tcc);
	    if (c) {
		returnValue = 1;
	    }
	    tcc -= c;
	    tbp += c;
	} else {
D 2
#   endif defined(TN3270)
E 2
I 2
#   endif /* defined(TN3270) */
E 2
	    returnValue = 1;
	    while (tcc > 0) {
		register int sc;

		if (NETROOM() < 2) {
		    flushline = 1;
		    break;
		}
		c = *tbp++ & 0xff, sc = strip(c), tcc--;
		if (sc == escape) {
		    command(0);
		    tcc = 0;
		    flushline = 1;
		    break;
		} else if (MODE_LINE(globalmode) && (sc == echoc)) {
		    if (tcc > 0 && strip(*tbp) == echoc) {
			tbp++;
			tcc--;
		    } else {
			dontlecho = !dontlecho;
			settimer(echotoggle);
			setconnmode();
			tcc = 0;
			flushline = 1;
			break;
		    }
		}
		if (localchars) {
D 8
		    if (sc == ntc.t_intrc) {
			intp();
E 8
I 8
D 9
		    if (TerminalEditLine(sc) == 0) {
E 9
I 9
		    if (TerminalSpecialChars(sc) == 0) {
E 9
E 8
			break;
D 8
		    } else if (sc == ntc.t_quitc) {
			sendbrk();
			break;
		    } else if (sc == nltc.t_flushc) {
			NET2ADD(IAC, AO);
			if (autoflush) {
			    doflush();
			}
			break;
		    } else if (MODE_LOCAL_CHARS(globalmode)) {
			;
		    } else if (sc == nttyb.sg_kill) {
			NET2ADD(IAC, EL);
			break;
		    } else if (sc == nttyb.sg_erase) {
			NET2ADD(IAC, EC);
			break;
E 8
		    }
		}
D 22
		switch (c) {
		case '\n':
			/*
			 * If we are in CRMOD mode (\r ==> \n)
			 * on our local machine, then probably
			 * a newline (unix) is CRLF (TELNET).
			 */
		    if (MODE_LOCAL_CHARS(globalmode)) {
			NETADD('\r');
E 22
I 22
		if (!myopts[TELOPT_BINARY]) {
		    switch (c) {
		    case '\n':
			    /*
			     * If we are in CRMOD mode (\r ==> \n)
			     * on our local machine, then probably
			     * a newline (unix) is CRLF (TELNET).
			     */
			if (MODE_LOCAL_CHARS(globalmode)) {
			    NETADD('\r');
			}
			NETADD('\n');
			flushline = 1;
			break;
		    case '\r':
D 23
			NET2ADD('\r', '\0');
E 23
I 23
			if (!crlf) {
			    NET2ADD('\r', '\0');
			} else {
			    NET2ADD('\r', '\n');
			}
E 23
			flushline = 1;
			break;
		    case IAC:
			NET2ADD(IAC, IAC);
			break;
		    default:
			NETADD(c);
			break;
E 22
		    }
D 22
		    NETADD('\n');
		    flushline = 1;
		    break;
		case '\r':
		    NET2ADD('\r', '\0');
		    flushline = 1;
		    break;
		case IAC:
E 22
I 22
		} else if (c == IAC) {
E 22
		    NET2ADD(IAC, IAC);
D 22
		    break;
		default:
E 22
I 22
		} else {
E 22
		    NETADD(c);
D 22
		    break;
E 22
		}
	    }
#   if defined(TN3270)
	}
    }
#   endif /* defined(TN3270) */

D 23
    if ((!MODE_LINE(globalmode) || flushline) &&
E 23
I 23
    if ((!MODE_LINE(globalmode) || flushline || myopts[TELOPT_BINARY]) &&
E 23
	FD_ISSET(net, &obits) && (NETBYTES() > 0)) {
	FD_CLR(net, &obits);
	returnValue = netflush();
    }
    if (scc > 0) {
#	if !defined(TN3270)
	telrcv();
	returnValue = 1;
#	else /* !defined(TN3270) */
	returnValue = Push3270();
#	endif /* !defined(TN3270) */
    }
D 9
    if (FD_ISSET(tout, &obits) && (TTYBYTES() > 0)) {
E 9
I 9
#if	defined(MSDOS)
    if (TTYBYTES())
#else	/* defined(MSDOS) */
    if (FD_ISSET(tout, &obits) && (TTYBYTES() > 0))
#endif	/* defined(MSDOS) */
						    {
E 9
	FD_CLR(tout, &obits);
	returnValue = ttyflush();
    }
    return returnValue;
}

/*
 * Select from tty and network...
 */
static void
telnet()
{
I 9
#if	defined(MSDOS)
#define	SCHED_BLOCK	0		/* Don't block in MSDOS */
#else	/* defined(MSDOS) */
#define	SCHED_BLOCK	1
#endif	/* defined(MSDOS) */

E 9
D 8
    int on = 1;
E 8
#if	defined(TN3270) && defined(unix)
    int myPid;
#endif	/* defined(TN3270) */

    tout = fileno(stdout);
    tin = fileno(stdin);
    setconnmode();
    scc = 0;
    tcc = 0;
    FD_ZERO(&ibits);
    FD_ZERO(&obits);
    FD_ZERO(&xbits);

D 8
    ioctl(net, FIONBIO, (char *)&on);
E 8
I 8
    NetNonblockingIO(net, 1);
E 8

#if	defined(TN3270)
D 13
#if	!defined(DEBUG)		/* DBX can't handle! */
D 8
    ioctl(net, FIOASYNC, (char *)&on);	/* hear about input */
E 8
I 8
    NetSigIO(net, 1);
E 8
#endif	/* !defined(DEBUG) */

E 13
I 13
    if (noasynch == 0) {			/* DBX can't handle! */
	NetSigIO(net, 1);
    }
E 13
D 8
#if	defined(unix)
    myPid = getpid();
#if	defined(NOT43)
    myPid = -myPid;
#endif	/* defined(NOT43) */
    ioctl(net, SIOCSPGRP, (char *)&myPid);	/* set my pid */
#endif	/* defined(unix) */

E 8
I 8
    NetSetPgrp(net);
E 8
#endif	/* defined(TN3270) */

D 8
#if	defined(SO_OOBINLINE)
    setsockopt(net, SOL_SOCKET, SO_OOBINLINE, &on, sizeof on);
#endif	/* defined(SO_OOBINLINE) */
E 8

I 8
#if	defined(SO_OOBINLINE) && !defined(MSDOS)
    SetSockOpt(net, SOL_SOCKET, SO_OOBINLINE, 1);
#endif	/* defined(SO_OOBINLINE) && !defined(MSDOS) */

E 8
I 2
#   if !defined(TN3270)
E 2
    if (telnetport) {
	if (!hisopts[TELOPT_SGA]) {
	    willoption(TELOPT_SGA, 0);
	}
D 2
#   if !defined(TN3270)
E 2
	if (!myopts[TELOPT_TTYPE]) {
	    dooption(TELOPT_TTYPE, 0);
	}
D 2
#   endif !defined(TN3270)
E 2
    }
I 2
#   endif /* !defined(TN3270) */
E 2

#   if !defined(TN3270)
    for (;;) {
D 9
	if (Scheduler(1) == -1) {
E 9
I 9
	if (Scheduler(SCHED_BLOCK) == -1) {
E 9
	    setcommandmode();
	    return;
	}
    }
#   else /* !defined(TN3270) */
    for (;;) {
	int schedValue;

D 16
	while (!In3270) {
E 16
I 16
	while (!In3270 && !shell_active) {
E 16
D 9
	    if (Scheduler(1) == -1) {
E 9
I 9
	    if (Scheduler(SCHED_BLOCK) == -1) {
E 9
		setcommandmode();
		return;
	    }
	}

	while ((schedValue = Scheduler(0)) != 0) {
	    if (schedValue == -1) {
		setcommandmode();
		return;
	    }
	}
		/* If there is data waiting to go out to terminal, don't
		 * schedule any more data for the terminal.
		 */
	if (tfrontp-tbackp) {
	    schedValue = 1;
	} else {
D 12
	    schedValue = DoTerminalOutput();
E 12
I 12
	    if (shell_active) {
D 16
#if	defined(MSDOS)
		static int haventstopped = 1;

		setcommandmode();
		if (haventstopped) {
		    StopScreen(1);
		    haventstopped = 0;
		}
I 13
#endif	/* defined(MSDOS) */
E 16
E 13
		if (shell_continue() == 0) {
		    ConnectScreen();
I 13
D 16
#if	defined(MSDOS)
E 13
		    haventstopped = 1;
I 13
#endif	/* defined(MSDOS) */
E 16
E 13
		}
I 13
D 16
#if	defined(MSDOS)
E 13
		setconnmode();
#endif	/* defined(MSDOS) */
	    } else {
E 16
I 16
	    } else if (In3270) {
E 16
		schedValue = DoTerminalOutput();
	    }
E 12
	}
D 12
	if (schedValue) {
E 12
I 12
	if (schedValue && (shell_active == 0)) {
E 12
D 9
	    if (Scheduler(1) == -1) {
E 9
I 9
	    if (Scheduler(SCHED_BLOCK) == -1) {
E 9
		setcommandmode();
		return;
	    }
	}
    }
#   endif /* !defined(TN3270) */
}

/*
 *	The following are data structures and routines for
 *	the "send" command.
 *
 */
 
struct sendlist {
    char	*name;		/* How user refers to it (case independent) */
    int		what;		/* Character to be sent (<0 ==> special) */
    char	*help;		/* Help information (0 ==> no help) */
#if	defined(NOT43)
    int		(*routine)();	/* Routine to perform (for special ops) */
#else	/* defined(NOT43) */
    void	(*routine)();	/* Routine to perform (for special ops) */
#endif	/* defined(NOT43) */
};

#define	SENDQUESTION	-1
#define	SENDESCAPE	-3

static struct sendlist Sendlist[] = {
    { "ao", AO, "Send Telnet Abort output" },
    { "ayt", AYT, "Send Telnet 'Are You There'" },
    { "brk", BREAK, "Send Telnet Break" },
    { "ec", EC, "Send Telnet Erase Character" },
    { "el", EL, "Send Telnet Erase Line" },
    { "escape", SENDESCAPE, "Send current escape character" },
    { "ga", GA, "Send Telnet 'Go Ahead' sequence" },
    { "ip", IP, "Send Telnet Interrupt Process" },
    { "nop", NOP, "Send Telnet 'No operation'" },
    { "synch", SYNCH, "Perform Telnet 'Synch operation'", dosynch },
    { "?", SENDQUESTION, "Display send options" },
    { 0 }
};

static struct sendlist Sendlist2[] = {		/* some synonyms */
	{ "break", BREAK, 0 },

	{ "intp", IP, 0 },
	{ "interrupt", IP, 0 },
	{ "intr", IP, 0 },

	{ "help", SENDQUESTION, 0 },

	{ 0 }
};

static char **
getnextsend(name)
char *name;
{
    struct sendlist *c = (struct sendlist *) name;

    return (char **) (c+1);
}

static struct sendlist *
getsend(name)
char *name;
{
    struct sendlist *sl;

    if ((sl = (struct sendlist *)
			genget(name, (char **) Sendlist, getnextsend)) != 0) {
	return sl;
    } else {
	return (struct sendlist *)
				genget(name, (char **) Sendlist2, getnextsend);
    }
}

static
sendcmd(argc, argv)
int	argc;
char	**argv;
{
    int what;		/* what we are sending this time */
    int count;		/* how many bytes we are going to need to send */
    int i;
    int question = 0;	/* was at least one argument a question */
    struct sendlist *s;	/* pointer to current command */

    if (argc < 2) {
	printf("need at least one argument for 'send' command\n");
	printf("'send ?' for help\n");
	return 0;
    }
    /*
     * First, validate all the send arguments.
     * In addition, we see how much space we are going to need, and
     * whether or not we will be doing a "SYNCH" operation (which
     * flushes the network queue).
     */
    count = 0;
    for (i = 1; i < argc; i++) {
	s = getsend(argv[i]);
	if (s == 0) {
	    printf("Unknown send argument '%s'\n'send ?' for help.\n",
			argv[i]);
	    return 0;
	} else if (s == Ambiguous(struct sendlist *)) {
	    printf("Ambiguous send argument '%s'\n'send ?' for help.\n",
			argv[i]);
	    return 0;
	}
	switch (s->what) {
	case SENDQUESTION:
	    break;
	case SENDESCAPE:
	    count += 1;
	    break;
	case SYNCH:
	    count += 2;
	    break;
	default:
	    count += 2;
	    break;
	}
    }
    /* Now, do we have enough room? */
    if (NETROOM() < count) {
	printf("There is not enough room in the buffer TO the network\n");
	printf("to process your request.  Nothing will be done.\n");
	printf("('send synch' will throw away most data in the network\n");
	printf("buffer, if this might help.)\n");
	return 0;
    }
    /* OK, they are all OK, now go through again and actually send */
    for (i = 1; i < argc; i++) {
	if ((s = getsend(argv[i])) == 0) {
	    fprintf(stderr, "Telnet 'send' error - argument disappeared!\n");
	    quit();
	    /*NOTREACHED*/
	}
	if (s->routine) {
	    (*s->routine)(s);
	} else {
	    switch (what = s->what) {
	    case SYNCH:
		dosynch();
		break;
	    case SENDQUESTION:
		for (s = Sendlist; s->name; s++) {
		    if (s->help) {
			printf(s->name);
			if (s->help) {
			    printf("\t%s", s->help);
			}
			printf("\n");
		    }
		}
		question = 1;
		break;
	    case SENDESCAPE:
		NETADD(escape);
		break;
	    default:
		NET2ADD(IAC, what);
		break;
	    }
	}
    }
    return !question;
}

/*
 * The following are the routines and data structures referred
 * to by the arguments to the "toggle" command.
 */

static
lclchars()
{
    donelclchars = 1;
    return 1;
}

static
togdebug()
{
#ifndef	NOT43
    if (net > 0 &&
D 8
	setsockopt(net, SOL_SOCKET, SO_DEBUG, (char *)&debug, sizeof(debug))
									< 0) {
E 8
I 8
	(SetSockOpt(net, SOL_SOCKET, SO_DEBUG, debug)) < 0) {
E 8
	    perror("setsockopt (SO_DEBUG)");
    }
D 2
#else	NOT43
E 2
I 2
#else	/* NOT43 */
E 2
    if (debug) {
D 8
	if (net > 0 && setsockopt(net, SOL_SOCKET, SO_DEBUG, 0, 0) < 0)
E 8
I 8
	if (net > 0 && SetSockOpt(net, SOL_SOCKET, SO_DEBUG, 0, 0) < 0)
E 8
	    perror("setsockopt (SO_DEBUG)");
    } else
	printf("Cannot turn off socket debugging\n");
D 2
#endif	NOT43
E 2
I 2
#endif	/* NOT43 */
E 2
    return 1;
}


I 16
static int
I 23
togcrlf()
{
    if (crlf) {
	printf("Will send carriage returns as telnet <CR><LF>.\n");
    } else {
	printf("Will send carriage returns as telnet <CR><NUL>.\n");
    }
    return 1;
}


static int
E 23
togbinary()
{
    donebinarytoggle = 1;
E 16

I 16
    if (myopts[TELOPT_BINARY] == 0) {	/* Go into binary mode */
	NET2ADD(IAC, DO);
	NETADD(TELOPT_BINARY);
	printoption("<SENT", doopt, TELOPT_BINARY, 0);
	NET2ADD(IAC, WILL);
	NETADD(TELOPT_BINARY);
	printoption("<SENT", doopt, TELOPT_BINARY, 0);
	hisopts[TELOPT_BINARY] = myopts[TELOPT_BINARY] = 1;
	printf("Negotiating binary mode with remote host.\n");
    } else {				/* Turn off binary mode */
	NET2ADD(IAC, DONT);
	NETADD(TELOPT_BINARY);
	printoption("<SENT", dont, TELOPT_BINARY, 0);
	NET2ADD(IAC, DONT);
	NETADD(TELOPT_BINARY);
	printoption("<SENT", dont, TELOPT_BINARY, 0);
	hisopts[TELOPT_BINARY] = myopts[TELOPT_BINARY] = 0;
	printf("Negotiating network ascii mode with remote host.\n");
    }
    return 1;
}



E 16
extern int togglehelp();

struct togglelist {
    char	*name;		/* name of toggle */
    char	*help;		/* help message */
    int		(*handler)();	/* routine to do actual setting */
    int		dohelp;		/* should we display help information */
    int		*variable;
    char	*actionexplanation;
};

static struct togglelist Togglelist[] = {
    { "autoflush",
	"toggle flushing of output when sending interrupt characters",
	    0,
		1,
		    &autoflush,
			"flush output when sending interrupt characters" },
    { "autosynch",
	"toggle automatic sending of interrupt characters in urgent mode",
	    0,
		1,
		    &autosynch,
			"send interrupt characters in urgent mode" },
I 16
    { "binary",
	"toggle sending and receiving of binary data",
	    togbinary,
		1,
		    0,
D 23
			"send and receive network data in binary mode" },
E 23
I 23
			0 },
    { "crlf",
	"toggle sending carriage returns as telnet <CR><LF>",
	    togcrlf,
		1,
		    &crlf,
			0 },
E 23
E 16
    { "crmod",
	"toggle mapping of received carriage returns",
	    0,
		1,
		    &crmod,
			"map carriage return on output" },
    { "localchars",
	"toggle local recognition of certain control characters",
	    lclchars,
		1,
		    &localchars,
			"recognize certain control characters" },
    { " ", "", 0, 1 },		/* empty line */
    { "debug",
	"(debugging) toggle debugging",
	    togdebug,
		1,
		    &debug,
			"turn on socket level debugging" },
    { "netdata",
	"(debugging) toggle printing of hexadecimal network data",
	    0,
		1,
		    &netdata,
			"print hexadecimal representation of network traffic" },
    { "options",
	"(debugging) toggle viewing of options processing",
	    0,
		1,
		    &showoptions,
			"show option processing" },
    { " ", "", 0, 1 },		/* empty line */
    { "?",
	"display help information",
	    togglehelp,
		1 },
    { "help",
	"display help information",
	    togglehelp,
		0 },
    { 0 }
};

static
togglehelp()
{
    struct togglelist *c;

    for (c = Togglelist; c->name; c++) {
	if (c->dohelp) {
	    printf("%s\t%s\n", c->name, c->help);
	}
    }
    return 0;
}

static char **
getnexttoggle(name)
char *name;
{
    struct togglelist *c = (struct togglelist *) name;

    return (char **) (c+1);
}

static struct togglelist *
gettoggle(name)
char *name;
{
    return (struct togglelist *)
			genget(name, (char **) Togglelist, getnexttoggle);
}

static
toggle(argc, argv)
int	argc;
char	*argv[];
{
    int retval = 1;
    char *name;
    struct togglelist *c;

    if (argc < 2) {
	fprintf(stderr,
	    "Need an argument to 'toggle' command.  'toggle ?' for help.\n");
	return 0;
    }
    argc--;
    argv++;
    while (argc--) {
	name = *argv++;
	c = gettoggle(name);
	if (c == Ambiguous(struct togglelist *)) {
	    fprintf(stderr, "'%s': ambiguous argument ('toggle ?' for help).\n",
					name);
	    return 0;
	} else if (c == 0) {
	    fprintf(stderr, "'%s': unknown argument ('toggle ?' for help).\n",
					name);
	    return 0;
	} else {
	    if (c->variable) {
		*c->variable = !*c->variable;		/* invert it */
D 23
		printf("%s %s.\n", *c->variable? "Will" : "Won't",
E 23
I 23
		if (c->actionexplanation) {
		    printf("%s %s.\n", *c->variable? "Will" : "Won't",
E 23
							c->actionexplanation);
I 23
		}
E 23
	    }
	    if (c->handler) {
		retval &= (*c->handler)(c);
	    }
	}
    }
    return retval;
}

/*
 * The following perform the "set" command.
 */

struct setlist {
    char *name;				/* name */
    char *help;				/* help information */
    char *charp;			/* where it is located at */
};

static struct setlist Setlist[] = {
    { "echo", 	"character to toggle local echoing on/off", &echoc },
    { "escape",	"character to escape back to telnet command mode", &escape },
    { " ", "" },
    { " ", "The following need 'localchars' to be toggled true", 0 },
I 8
#if	defined(unix)
E 8
    { "erase",	"character to cause an Erase Character", &nttyb.sg_erase },
    { "flushoutput", "character to cause an Abort Oubput", &nltc.t_flushc },
    { "interrupt", "character to cause an Interrupt Process", &ntc.t_intrc },
    { "kill",	"character to cause an Erase Line", &nttyb.sg_kill },
    { "quit",	"character to cause a Break", &ntc.t_quitc },
    { "eof",	"character to cause an EOF ", &ntc.t_eofc },
I 8
#endif	/* defined(unix) */
#if	defined(MSDOS)
    { "erase",	"character to cause an Erase Character", &termEraseChar },
    { "flushoutput", "character to cause an Abort Oubput", &termFlushChar },
    { "interrupt", "character to cause an Interrupt Process", &termIntChar },
    { "kill",	"character to cause an Erase Line", &termKillChar },
    { "quit",	"character to cause a Break", &termQuitChar },
    { "eof",	"character to cause an EOF ", &termEofChar },
#endif	/* defined(MSDOS) */
E 8
    { 0 }
};

static char **
getnextset(name)
char *name;
{
    struct setlist *c = (struct setlist *)name;

    return (char **) (c+1);
}

static struct setlist *
getset(name)
char *name;
{
    return (struct setlist *) genget(name, (char **) Setlist, getnextset);
}

static
setcmd(argc, argv)
int	argc;
char	*argv[];
{
    int value;
    struct setlist *ct;

    /* XXX back we go... sigh */
    if (argc != 3) {
	if ((argc == 2) &&
		    ((!strcmp(argv[1], "?")) || (!strcmp(argv[1], "help")))) {
	    for (ct = Setlist; ct->name; ct++) {
		printf("%s\t%s\n", ct->name, ct->help);
	    }
	    printf("?\tdisplay help information\n");
	} else {
	    printf("Format is 'set Name Value'\n'set ?' for help.\n");
	}
	return 0;
    }

    ct = getset(argv[1]);
    if (ct == 0) {
	fprintf(stderr, "'%s': unknown argument ('set ?' for help).\n",
			argv[1]);
	return 0;
    } else if (ct == Ambiguous(struct setlist *)) {
	fprintf(stderr, "'%s': ambiguous argument ('set ?' for help).\n",
			argv[1]);
	return 0;
    } else {
	if (strcmp("off", argv[2])) {
	    value = special(argv[2]);
	} else {
	    value = -1;
	}
	*(ct->charp) = value;
	printf("%s character is '%s'.\n", ct->name, control(*(ct->charp)));
    }
    return 1;
}

/*
 * The following are the data structures and routines for the
 * 'mode' command.
 */

static
dolinemode()
{
    if (hisopts[TELOPT_SGA]) {
	wontoption(TELOPT_SGA, 0);
    }
    if (hisopts[TELOPT_ECHO]) {
	wontoption(TELOPT_ECHO, 0);
    }
    return 1;
}

static
docharmode()
{
    if (!hisopts[TELOPT_SGA]) {
	willoption(TELOPT_SGA, 0);
    }
    if (!hisopts[TELOPT_ECHO]) {
	willoption(TELOPT_ECHO, 0);
    }
    return 1;
}

static struct cmd Modelist[] = {
    { "character",	"character-at-a-time mode",	docharmode, 1, 1 },
    { "line",		"line-by-line mode",		dolinemode, 1, 1 },
    { 0 },
};

static char **
getnextmode(name)
char *name;
{
    struct cmd *c = (struct cmd *) name;

    return (char **) (c+1);
}

static struct cmd *
getmodecmd(name)
char *name;
{
    return (struct cmd *) genget(name, (char **) Modelist, getnextmode);
}

static
modecmd(argc, argv)
int	argc;
char	*argv[];
{
    struct cmd *mt;

    if ((argc != 2) || !strcmp(argv[1], "?") || !strcmp(argv[1], "help")) {
	printf("format is:  'mode Mode', where 'Mode' is one of:\n\n");
	for (mt = Modelist; mt->name; mt++) {
	    printf("%s\t%s\n", mt->name, mt->help);
	}
	return 0;
    }
    mt = getmodecmd(argv[1]);
    if (mt == 0) {
	fprintf(stderr, "Unknown mode '%s' ('mode ?' for help).\n", argv[1]);
	return 0;
    } else if (mt == Ambiguous(struct cmd *)) {
	fprintf(stderr, "Ambiguous mode '%s' ('mode ?' for help).\n", argv[1]);
	return 0;
    } else {
	(*mt->handler)();
    }
    return 1;
}

/*
 * The following data structures and routines implement the
 * "display" command.
 */

static
display(argc, argv)
int	argc;
char	*argv[];
I 28
{
#define	dotog(tl)	if (tl->variable && tl->actionexplanation) { \
			    if (*tl->variable) { \
				printf("will"); \
			    } else { \
				printf("won't"); \
			    } \
			    printf(" %s.\n", tl->actionexplanation); \
			}
E 28
D 28
{
#define	dotog(tl)	if (tl->variable && tl->actionexplanation) { \
			    if (*tl->variable) { \
				printf("will"); \
			    } else { \
				printf("won't"); \
			    } \
			    printf(" %s.\n", tl->actionexplanation); \
			}
E 28

#define	doset(sl)   if (sl->name && *sl->name != ' ') { \
			printf("[%s]\t%s.\n", control(*sl->charp), sl->name); \
		    }

    struct togglelist *tl;
    struct setlist *sl;

    if (argc == 1) {
	for (tl = Togglelist; tl->name; tl++) {
	    dotog(tl);
	}
	printf("\n");
	for (sl = Setlist; sl->name; sl++) {
	    doset(sl);
	}
    } else {
	int i;

	for (i = 1; i < argc; i++) {
	    sl = getset(argv[i]);
	    tl = gettoggle(argv[i]);
	    if ((sl == Ambiguous(struct setlist *)) ||
				(tl == Ambiguous(struct togglelist *))) {
		printf("?Ambiguous argument '%s'.\n", argv[i]);
		return 0;
	    } else if (!sl && !tl) {
		printf("?Unknown argument '%s'.\n", argv[i]);
		return 0;
	    } else {
		if (tl) {
		    dotog(tl);
		}
		if (sl) {
		    doset(sl);
		}
	    }
	}
    }
    return 1;
#undef	doset
#undef	dotog
}

/*
 * The following are the data structures, and many of the routines,
 * relating to command processing.
 */

/*
 * Set the escape character.
 */
static
setescape(argc, argv)
	int argc;
	char *argv[];
{
	register char *arg;
	char buf[50];

	printf(
	    "Deprecated usage - please use 'set escape%s%s' in the future.\n",
				(argc > 2)? " ":"", (argc > 2)? argv[1]: "");
	if (argc > 2)
		arg = argv[1];
	else {
		printf("new escape character: ");
		gets(buf);
		arg = buf;
	}
	if (arg[0] != '\0')
		escape = arg[0];
	if (!In3270) {
		printf("Escape character is '%s'.\n", control(escape));
D 25
	}
	fflush(stdout);
	return 1;
}

E 25
I 25
	}
	fflush(stdout);
	return 1;
}

E 25
/*VARARGS*/
static
togcrmod()
{
    crmod = !crmod;
    printf("Deprecated usage - please use 'toggle crmod' in the future.\n");
    printf("%s map carriage return on output.\n", crmod ? "Will" : "Won't");
    fflush(stdout);
    return 1;
}

/*VARARGS*/
suspend()
{
	setcommandmode();
#if	defined(unix)
	kill(0, SIGTSTP);
I 12
#endif	/* defined(unix) */
E 12
D 8
#endif	/* defined(unix) */
E 8
	/* reget parameters in case they were changed */
D 8
	ioctl(0, TIOCGETP, (char *)&ottyb);
	ioctl(0, TIOCGETC, (char *)&otc);
	ioctl(0, TIOCGLTC, (char *)&oltc);
E 8
I 8
	TerminalSaveState();
D 12
#endif	/* defined(unix) */
E 12
I 12
	setconnmode();
E 12
E 8
	return 1;
}

/*VARARGS*/
static
D 3
bye()
E 3
I 3
bye(argc, argv)
D 18
int	argc;		/* Number of arguments */
char	*argv[];	/* arguments */
E 3
{
    if (connected) {
	shutdown(net, 2);
	printf("Connection closed.\n");
D 9
	close(net);
E 9
I 9
	NetClose(net);
E 9
	connected = 0;
	/* reset options */
D 3
	bzero((char *)hisopts, sizeof hisopts);
	bzero((char *)myopts, sizeof myopts);
	SYNCHing = flushout = 0;
	flushline = 1;
E 3
I 3
	tninit();
E 3
#if	defined(TN3270)
D 3
		/*
		 * The problem is that we were called from command() which
		 * was called from DataFrom3270() which was called from
		 * DataFromTerminal() which was called from...
		 *
		 * So, just quit.
		 */
	if (In3270) {
	    Exit(0);
	}
E 3
I 3
	SetIn3270();		/* Get out of 3270 mode */
E 3
#endif	/* defined(TN3270) */
    }
D 3
    return 1;
E 3
I 3
    if ((argc != 2) || (strcmp(argv[1], "fromquit") != 0)) {
	longjmp(toplevel, 1);
	/* NOTREACHED */
    }
    return 1;			/* Keep lint, etc., happy */
E 3
}

/*VARARGS*/
quit()
{
D 3
	(void) call(bye, "bye", 0);
E 3
I 3
	(void) call(bye, "bye", "fromquit", 0);
E 3
	Exit(0);
	/*NOTREACHED*/
	return 1;			/* just to keep lint happy */
}

/*
 * Print status about the connection.
E 18
I 18
int	argc;		/* Number of arguments */
char	*argv[];	/* arguments */
{
    if (connected) {
	shutdown(net, 2);
	printf("Connection closed.\n");
	NetClose(net);
	connected = 0;
	/* reset options */
	tninit();
#if	defined(TN3270)
	SetIn3270();		/* Get out of 3270 mode */
#endif	/* defined(TN3270) */
    }
    if ((argc != 2) || (strcmp(argv[1], "fromquit") != 0)) {
	longjmp(toplevel, 1);
	/* NOTREACHED */
    }
    return 1;			/* Keep lint, etc., happy */
}

/*VARARGS*/
quit()
{
	(void) call(bye, "bye", "fromquit", 0);
	Exit(0);
	/*NOTREACHED*/
	return 1;			/* just to keep lint happy */
}

/*
 * Print status about the connection.
E 18
 */
static
status(argc, argv)
int	argc;
char	*argv[];
{
    if (connected) {
	printf("Connected to %s.\n", hostname);
	if (argc < 2) {
	    printf("Operating in %s.\n",
				modelist[getconnmode()].modedescriptions);
	    if (localchars) {
		printf("Catching signals locally.\n");
	    }
	}
    } else {
	printf("No connection.\n");
    }
#   if !defined(TN3270)
    printf("Escape character is '%s'.\n", control(escape));
    fflush(stdout);
#   else /* !defined(TN3270) */
    if ((!In3270) && ((argc < 2) || strcmp(argv[1], "notmuch"))) {
	printf("Escape character is '%s'.\n", control(escape));
    }
#   if defined(unix)
    if (In3270 && transcom) {
       printf("Transparent mode command is '%s'.\n", transcom);
    }
#   endif /* defined(unix) */
    fflush(stdout);
    if (In3270) {
	return 0;
    }
#   endif /* defined(TN3270) */
    return 1;
}

#if	defined(TN3270) && defined(unix)
static
settranscom(argc, argv)
	int argc;
	char *argv[];
{
	int i, len = 0;
	char *strcpy(), *strcat();

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
#endif	/* defined(TN3270) && defined(unix) */


I 10

E 10
static
tn(argc, argv)
	int argc;
D 13
	char *argv[];
{
    register struct hostent *host = 0;
D 9
#if defined(msdos)
E 9
I 9
#if defined(MSDOS)
E 13
I 13
	char *argv[];
{
    register struct hostent *host = 0;
#if defined(MSDOS)
E 13
E 9
    char *cp;
D 2
#endif /* defined(msdos) */
E 2
I 2
D 9
#endif	/* defined(msdos) */
E 9
I 9
#endif	/* defined(MSDOS) */
E 9
E 2

    if (connected) {
	printf("?Already connected to %s\n", hostname);
	return 0;
    }
    if (argc < 2) {
	(void) strcpy(line, "Connect ");
	printf("(to) ");
	gets(&line[strlen(line)]);
	makeargv();
	argc = margc;
	argv = margv;
    }
D 17
    if (argc > 3) {
E 17
I 17
    if ((argc < 2) || (argc > 3)) {
E 17
	printf("usage: %s host-name [port]\n", argv[0]);
	return 0;
    }
D 9
#if	defined(msdos)
E 9
I 9
#if	defined(MSDOS)
E 9
    for (cp = argv[1]; *cp; cp++) {
	if (isupper(*cp)) {
	    *cp = tolower(*cp);
	}
    }
D 9
#endif	/* defined(msdos) */
E 9
I 9
#endif	/* defined(MSDOS) */
E 9
    sin.sin_addr.s_addr = inet_addr(argv[1]);
    if (sin.sin_addr.s_addr != -1) {
	sin.sin_family = AF_INET;
	(void) strcpy(hnamebuf, argv[1]);
	hostname = hnamebuf;
    } else {
	host = gethostbyname(argv[1]);
	if (host) {
	    sin.sin_family = host->h_addrtype;
#if	defined(h_addr)		/* In 4.3, this is a #define */
D 9
	    bcopy(host->h_addr_list[0], (caddr_t)&sin.sin_addr, host->h_length);
E 9
I 9
	    memcpy((caddr_t)&sin.sin_addr,
				host->h_addr_list[0], host->h_length);
E 9
#else	/* defined(h_addr) */
D 9
	    bcopy(host->h_addr, (caddr_t)&sin.sin_addr, host->h_length);
E 9
I 9
	    memcpy((caddr_t)&sin.sin_addr, host->h_addr, host->h_length);
E 9
#endif	/* defined(h_addr) */
	    hostname = host->h_name;
	} else {
	    printf("%s: unknown host\n", argv[1]);
	    return 0;
	}
D 23
    }
    sin.sin_port = sp->s_port;
    if (argc == 3) {
	sin.sin_port = atoi(argv[2]);
	if (sin.sin_port == 0) {
	    sp = getservbyname(argv[2], "tcp");
	    if (sp)
		sin.sin_port = sp->s_port;
	    else {
		printf("%s: bad port number\n", argv[2]);
		return 0;
	    }
	} else {
	    sin.sin_port = atoi(argv[2]);
	    sin.sin_port = htons(sin.sin_port);
	}
	telnetport = 0;
    } else {
	telnetport = 1;
    }
#if	defined(unix)
    signal(SIGINT, intr);
D 9
    signal(SIGQUIT, intr2);
    signal(SIGPIPE, deadpeer);
#endif	/* defined(unix) */
    printf("Trying...\n");
    do {
	net = socket(AF_INET, SOCK_STREAM, 0);
	if (net < 0) {
	    perror("telnet: socket");
	    return 0;
	}
D 8
#ifndef	NOT43
	if (debug && setsockopt(net, SOL_SOCKET, SO_DEBUG,
				(char *)&debug, sizeof(debug)) < 0)
D 2
#else	NOT43
E 2
I 2
#else	/* NOT43 */
E 2
	if (debug && setsockopt(net, SOL_SOCKET, SO_DEBUG, 0, 0) < 0)
D 2
#endif	NOT43
E 2
I 2
#endif	/* NOT43 */
E 8
I 8
	if (debug && SetSockOpt(net, SOL_SOCKET, SO_DEBUG, 1) < 0) {
E 8
E 2
		perror("setsockopt (SO_DEBUG)");
I 8
	}
E 8

	if (connect(net, (struct sockaddr *)&sin, sizeof (sin)) < 0) {
#if	defined(h_addr)		/* In 4.3, this is a #define */
	    if (host && host->h_addr_list[1]) {
		int oerrno = errno;

		fprintf(stderr, "telnet: connect to address %s: ",
						inet_ntoa(sin.sin_addr));
		errno = oerrno;
		perror((char *)0);
		host->h_addr_list++;
		bcopy(host->h_addr_list[0],
		    (caddr_t)&sin.sin_addr, host->h_length);
		fprintf(stderr, "Trying %s...\n",
			inet_ntoa(sin.sin_addr));
		(void) close(net);
		continue;
	    }
#endif	/* defined(h_addr) */
	    perror("telnet: Unable to connect to remote host");
#if defined(unix)
	    signal(SIGINT, SIG_DFL);
	    signal(SIGQUIT, SIG_DFL);
D 2
#endif /* defined(unix) */
E 2
I 2
#endif	/* defined(unix) */
E 2
	    return 0;
	    }
	connected++;
    } while (connected == 0);
    call(status, "status", "notmuch", 0);
    if (setjmp(peerdied) == 0)
	telnet();
    ExitString(stderr, "Connection closed by foreign host.\n",1);
    /*NOTREACHED*/
}


#define HELPINDENT (sizeof ("connect"))

static char
	openhelp[] =	"connect to a site",
	closehelp[] =	"close current connection",
	quithelp[] =	"exit telnet",
	zhelp[] =	"suspend telnet",
	statushelp[] =	"print status information",
	helphelp[] =	"print help information",
	sendhelp[] =	"transmit special characters ('send ?' for more)",
	sethelp[] = 	"set operating parameters ('set ?' for more)",
	togglestring[] ="toggle operating parameters ('toggle ?' for more)",
	displayhelp[] =	"display operating parameters",
#if	defined(TN3270) && defined(unix)
	transcomhelp[] = "specify Unix command for transparent mode pipe",
#endif	/* defined(TN3270) && defined(unix) */
	modehelp[] = "try to enter line-by-line or character-at-a-time mode";

extern int	help();

static struct cmd cmdtab[] = {
	{ "close",	closehelp,	bye,		1, 1 },
	{ "display",	displayhelp,	display,	1, 0 },
	{ "mode",	modehelp,	modecmd,	1, 1 },
	{ "open",	openhelp,	tn,		1, 0 },
	{ "quit",	quithelp,	quit,		1, 0 },
	{ "send",	sendhelp,	sendcmd,	1, 1 },
	{ "set",	sethelp,	setcmd,		1, 0 },
	{ "status",	statushelp,	status,		1, 0 },
	{ "toggle",	togglestring,	toggle,		1, 0 },
#if	defined(TN3270) && defined(unix)
	{ "transcom",	transcomhelp,	settranscom,	1, 0 },
#endif	/* defined(TN3270) && defined(unix) */
	{ "z",		zhelp,		suspend,	1, 0 },
	{ "?",		helphelp,	help,		1, 0 },
	0
};

static char	crmodhelp[] =	"deprecated command -- use 'toggle crmod' instead";
static char	escapehelp[] =	"deprecated command -- use 'set escape' instead";

static struct cmd cmdtab2[] = {
	{ "help",	helphelp,	help,		0, 0 },
	{ "escape",	escapehelp,	setescape,	1, 0 },
	{ "crmod",	crmodhelp,	togcrmod,	1, 0 },
	0
};

/*
 * Call routine with argc, argv set from args (terminated by 0).
 * VARARGS2
 */
static
call(routine, args)
	int (*routine)();
	char *args;
{
	register char **argp;
	register int argc;

	for (argc = 0, argp = &args; *argp++ != 0; argc++)
		;
	return (*routine)(argc, &args);
}

static char **
getnextcmd(name)
char *name;
{
    struct cmd *c = (struct cmd *) name;

    return (char **) (c+1);
}

static struct cmd *
getcmd(name)
char *name;
{
    struct cmd *cm;

    if ((cm = (struct cmd *) genget(name, (char **) cmdtab, getnextcmd)) != 0) {
	return cm;
    } else {
	return (struct cmd *) genget(name, (char **) cmdtab2, getnextcmd);
    }
}

void
command(top)
	int top;
{
	register struct cmd *c;

	setcommandmode();
	if (!top) {
		putchar('\n');
	} else {
#if	defined(unix)
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
#endif	/* defined(unix) */
	}
	for (;;) {
		printf("%s> ", prompt);
		if (gets(line) == NULL) {
			if (feof(stdin) || ferror(stdin))
				quit();
			break;
		}
		if (line[0] == 0)
			break;
		makeargv();
		c = getcmd(margv[0]);
		if (c == Ambiguous(struct cmd *)) {
			printf("?Ambiguous command\n");
			continue;
		}
		if (c == 0) {
			printf("?Invalid command\n");
			continue;
		}
		if (c->needconnect && !connected) {
			printf("?Need to be connected first.\n");
			continue;
		}
		if ((*c->handler)(margc, margv)) {
			break;
		}
	}
	if (!top) {
		if (!connected) {
			longjmp(toplevel, 1);
			/*NOTREACHED*/
		}
		setconnmode();
	}
}

/*
 * Help command.
 */
static
help(argc, argv)
	int argc;
	char *argv[];
{
	register struct cmd *c;

	if (argc == 1) {
		printf("Commands may be abbreviated.  Commands are:\n\n");
		for (c = cmdtab; c->name; c++)
			if (c->dohelp) {
				printf("%-*s\t%s\n", HELPINDENT, c->name,
								    c->help);
			}
		return 0;
	}
	while (--argc > 0) {
		register char *arg;
		arg = *++argv;
		c = getcmd(arg);
		if (c == Ambiguous(struct cmd *))
			printf("?Ambiguous help command %s\n", arg);
		else if (c == (struct cmd *)0)
			printf("?Invalid help command %s\n", arg);
		else
			printf("%s\n", c->help);
	}
	return 0;
}

/*
 * main.  Parse arguments, invoke the protocol or command parser.
 */


void
main(argc, argv)
	int argc;
	char *argv[];
{
D 3
    sp = getservbyname("telnet", "tcp");
    if (sp == 0) {
	ExitString(stderr, "telnet: tcp/telnet: unknown service\n",1);
	/*NOTREACHED*/
    }
E 3
I 3
    tninit();		/* Clear out things */

E 3
    NetTrace = stdout;
D 8
    ioctl(0, TIOCGETP, (char *)&ottyb);
    ioctl(0, TIOCGETC, (char *)&otc);
    ioctl(0, TIOCGLTC, (char *)&oltc);
#if	defined(LNOFLSH)
    ioctl(0, TIOCLGET, (char *)&autoflush);
    autoflush = !(autoflush&LNOFLSH);	/* if LNOFLSH, no autoflush */
#else	/* LNOFLSH */
    autoflush = 1;
#endif	/* LNOFLSH */
    ntc = otc;
    nltc = oltc;
    nttyb = ottyb;
    setbuf(stdin, (char *)0);
    setbuf(stdout, (char *)0);
E 8
I 8
    TerminalSaveState();
    autoflush = TerminalAutoFlush();

E 8
    prompt = argv[0];
    if (argc > 1 && !strcmp(argv[1], "-d")) {
	debug = 1;
	argv++;
	argc--;
    }
    if (argc > 1 && !strcmp(argv[1], "-n")) {
	argv++;
	argc--;
	if (argc > 1) {		/* get file name */
	    NetTrace = fopen(argv[1], "w");
	    argv++;
	    argc--;
	    if (NetTrace == NULL) {
		NetTrace = stdout;
	    }
	}
    }
#if	defined(TN3270) && defined(unix)
    if (argc > 1 && !strcmp(argv[1], "-t")) {
	argv++;
	argc--;
	if (argc > 1) {		/* get command name */
	    transcom = tline;
	    (void) strcpy(transcom, argv[1]);
	    argv++;
	    argc--;
	}
    }
#endif	/* defined(TN3270) && defined(unix) */
    if (argc != 1) {
	if (setjmp(toplevel) != 0)
	    Exit(0);
	tn(argc, argv);
    }
    setjmp(toplevel);
    for (;;)
	command(1);
}
E 9
E 1
I 9
    signal(SIGQUIT, intr2);
    signal(SIGPIPE, deadpeer);
#endif	/* defined(unix) */
E 23
I 23
    }
    sin.sin_port = sp->s_port;
    if (argc == 3) {
	sin.sin_port = atoi(argv[2]);
	if (sin.sin_port == 0) {
	    sp = getservbyname(argv[2], "tcp");
	    if (sp)
		sin.sin_port = sp->s_port;
	    else {
		printf("%s: bad port number\n", argv[2]);
		return 0;
	    }
	} else {
	    sin.sin_port = atoi(argv[2]);
	    sin.sin_port = htons(sin.sin_port);
	}
	telnetport = 0;
    } else {
	telnetport = 1;
    }
#if	defined(unix)
    signal(SIGINT, intr);
    signal(SIGQUIT, intr2);
    signal(SIGPIPE, deadpeer);
#endif	/* defined(unix) */
E 23
    printf("Trying...\n");
    do {
D 12
	net = socket(AF_INET, SOCK_STREAM, 0);
	if (net < 0) {
	    perror("telnet: socket");
	    return 0;
	}
	if (debug && SetSockOpt(net, SOL_SOCKET, SO_DEBUG, 1) < 0) {
		perror("setsockopt (SO_DEBUG)");
	}

	if (connect(net, (struct sockaddr *)&sin, sizeof (sin)) < 0) {
#if	defined(h_addr)		/* In 4.3, this is a #define */
	    if (host && host->h_addr_list[1]) {
		int oerrno = errno;

		fprintf(stderr, "telnet: connect to address %s: ",
						inet_ntoa(sin.sin_addr));
		errno = oerrno;
		perror((char *)0);
		host->h_addr_list++;
		memcpy((caddr_t)&sin.sin_addr, 
			host->h_addr_list[0], host->h_length);
		fprintf(stderr, "Trying %s...\n",
			inet_ntoa(sin.sin_addr));
		(void) NetClose(net);
		continue;
	    }
#endif	/* defined(h_addr) */
	    perror("telnet: Unable to connect to remote host");
#if defined(unix)
	    signal(SIGINT, SIG_DFL);
	    signal(SIGQUIT, SIG_DFL);
#endif	/* defined(unix) */
	    return 0;
	    }
	connected++;
    } while (connected == 0);
    call(status, "status", "notmuch", 0);
E 12
I 12
	net = socket(AF_INET, SOCK_STREAM, 0);
	if (net < 0) {
	    perror("telnet: socket");
	    return 0;
	}
	if (debug && SetSockOpt(net, SOL_SOCKET, SO_DEBUG, 1) < 0) {
		perror("setsockopt (SO_DEBUG)");
	}

	if (connect(net, (struct sockaddr *)&sin, sizeof (sin)) < 0) {
#if	defined(h_addr)		/* In 4.3, this is a #define */
	    if (host && host->h_addr_list[1]) {
		int oerrno = errno;

		fprintf(stderr, "telnet: connect to address %s: ",
						inet_ntoa(sin.sin_addr));
		errno = oerrno;
		perror((char *)0);
		host->h_addr_list++;
		memcpy((caddr_t)&sin.sin_addr, 
			host->h_addr_list[0], host->h_length);
		fprintf(stderr, "Trying %s...\n",
			inet_ntoa(sin.sin_addr));
		(void) NetClose(net);
		continue;
	    }
#endif	/* defined(h_addr) */
	    perror("telnet: Unable to connect to remote host");
#if defined(unix)
	    signal(SIGINT, SIG_DFL);
	    signal(SIGQUIT, SIG_DFL);
#endif	/* defined(unix) */
	    return 0;
	    }
	connected++;
    } while (connected == 0);
    call(status, "status", "notmuch", 0);
E 12
    if (setjmp(peerdied) == 0)
	telnet();
    NetClose(net);
    ExitString(stderr, "Connection closed by foreign host.\n",1);
    /*NOTREACHED*/
}


#define HELPINDENT (sizeof ("connect"))

static char
	openhelp[] =	"connect to a site",
	closehelp[] =	"close current connection",
	quithelp[] =	"exit telnet",
D 10
	zhelp[] =	"suspend telnet",
E 10
	statushelp[] =	"print status information",
	helphelp[] =	"print help information",
	sendhelp[] =	"transmit special characters ('send ?' for more)",
	sethelp[] = 	"set operating parameters ('set ?' for more)",
	togglestring[] ="toggle operating parameters ('toggle ?' for more)",
	displayhelp[] =	"display operating parameters",
#if	defined(TN3270) && defined(unix)
	transcomhelp[] = "specify Unix command for transparent mode pipe",
#endif	/* defined(TN3270) && defined(unix) */
I 10
#if	defined(unix)
	zhelp[] =	"suspend telnet",
#endif	/* defined(unix */
D 13
#if	defined(MSDOS)
E 13
I 13
#if	defined(TN3270)
E 13
	shellhelp[] =	"invoke a subshell",
D 13
#endif	/* defined(MSDOS) */
E 13
I 13
#endif	/* defined(TN3270) */
E 13
E 10
	modehelp[] = "try to enter line-by-line or character-at-a-time mode";

D 10
extern int	help();
E 10
I 10
extern int	help(), shell();
E 10

static struct cmd cmdtab[] = {
	{ "close",	closehelp,	bye,		1, 1 },
	{ "display",	displayhelp,	display,	1, 0 },
	{ "mode",	modehelp,	modecmd,	1, 1 },
	{ "open",	openhelp,	tn,		1, 0 },
	{ "quit",	quithelp,	quit,		1, 0 },
	{ "send",	sendhelp,	sendcmd,	1, 1 },
	{ "set",	sethelp,	setcmd,		1, 0 },
	{ "status",	statushelp,	status,		1, 0 },
	{ "toggle",	togglestring,	toggle,		1, 0 },
#if	defined(TN3270) && defined(unix)
	{ "transcom",	transcomhelp,	settranscom,	1, 0 },
#endif	/* defined(TN3270) && defined(unix) */
I 10
#if	defined(unix)
E 10
	{ "z",		zhelp,		suspend,	1, 0 },
I 10
#endif	/* defined(unix) */
D 13
#if	defined(MSDOS)
	{ "!",		shellhelp,	shell,		1, 0 },
#endif	/* defined(MSDOS) */
E 13
I 13
#if	defined(TN3270)
	{ "!",		shellhelp,	shell,		1, 1 },
D 16
#endif	/* defined(TN3270) */
E 13
E 10
	{ "?",		helphelp,	help,		1, 0 },
	0
};

static char	crmodhelp[] =	"deprecated command -- use 'toggle crmod' instead";
static char	escapehelp[] =	"deprecated command -- use 'set escape' instead";

static struct cmd cmdtab2[] = {
	{ "help",	helphelp,	help,		0, 0 },
	{ "escape",	escapehelp,	setescape,	1, 0 },
	{ "crmod",	crmodhelp,	togcrmod,	1, 0 },
	0
};

/*
 * Call routine with argc, argv set from args (terminated by 0).
 * VARARGS2
 */
static
E 16
I 16
#endif	/* defined(TN3270) */
	{ "?",		helphelp,	help,		1, 0 },
	0
};

static char	crmodhelp[] =	"deprecated command -- use 'toggle crmod' instead";
static char	escapehelp[] =	"deprecated command -- use 'set escape' instead";

static struct cmd cmdtab2[] = {
	{ "help",	helphelp,	help,		0, 0 },
	{ "escape",	escapehelp,	setescape,	1, 0 },
	{ "crmod",	crmodhelp,	togcrmod,	1, 0 },
	0
};

/*
 * Call routine with argc, argv set from args (terminated by 0).
 * VARARGS2
 */
static
E 16
call(routine, args)
	int (*routine)();
	char *args;
{
	register char **argp;
	register int argc;

	for (argc = 0, argp = &args; *argp++ != 0; argc++)
		;
	return (*routine)(argc, &args);
}

static char **
getnextcmd(name)
char *name;
{
    struct cmd *c = (struct cmd *) name;

    return (char **) (c+1);
}

static struct cmd *
getcmd(name)
char *name;
{
    struct cmd *cm;

    if ((cm = (struct cmd *) genget(name, (char **) cmdtab, getnextcmd)) != 0) {
	return cm;
    } else {
	return (struct cmd *) genget(name, (char **) cmdtab2, getnextcmd);
    }
}

void
command(top)
	int top;
{
D 13
	register struct cmd *c;
E 13
I 13
    register struct cmd *c;
E 13

D 13
	setcommandmode();
	if (!top) {
		putchar('\n');
	} else {
E 13
I 13
    setcommandmode();
    if (!top) {
	putchar('\n');
    } else {
E 13
#if	defined(unix)
D 13
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
E 13
I 13
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
E 13
#endif	/* defined(unix) */
I 13
    }
    for (;;) {
	printf("%s> ", prompt);
	if (gets(line) == NULL) {
	    if (feof(stdin) || ferror(stdin))
		quit();
	    break;
E 13
	}
D 13
	for (;;) {
		printf("%s> ", prompt);
		if (gets(line) == NULL) {
			if (feof(stdin) || ferror(stdin))
				quit();
			break;
		}
		if (line[0] == 0)
			break;
		makeargv();
		c = getcmd(margv[0]);
		if (c == Ambiguous(struct cmd *)) {
			printf("?Ambiguous command\n");
			continue;
		}
		if (c == 0) {
			printf("?Invalid command\n");
			continue;
		}
		if (c->needconnect && !connected) {
			printf("?Need to be connected first.\n");
			continue;
		}
		if ((*c->handler)(margc, margv)) {
			break;
		}
E 13
I 13
	if (line[0] == 0)
	    break;
	makeargv();
	c = getcmd(margv[0]);
	if (c == Ambiguous(struct cmd *)) {
	    printf("?Ambiguous command\n");
	    continue;
E 13
	}
D 13
	if (!top) {
		if (!connected) {
			longjmp(toplevel, 1);
			/*NOTREACHED*/
		}
		setconnmode();
E 13
I 13
	if (c == 0) {
	    printf("?Invalid command\n");
	    continue;
E 13
	}
I 13
	if (c->needconnect && !connected) {
	    printf("?Need to be connected first.\n");
	    continue;
	}
	if ((*c->handler)(margc, margv)) {
	    break;
	}
    }
    if (!top) {
	if (!connected) {
	    longjmp(toplevel, 1);
	    /*NOTREACHED*/
	}
I 22
#if	defined(TN3270)
E 22
	if (shell_active == 0) {
	    setconnmode();
	}
I 22
#else	/* defined(TN3270) */
	setconnmode();
#endif	/* defined(TN3270) */
E 22
    }
E 13
}

/*
 * Help command.
 */
static
help(argc, argv)
	int argc;
	char *argv[];
{
	register struct cmd *c;

	if (argc == 1) {
		printf("Commands may be abbreviated.  Commands are:\n\n");
		for (c = cmdtab; c->name; c++)
			if (c->dohelp) {
				printf("%-*s\t%s\n", HELPINDENT, c->name,
								    c->help);
			}
		return 0;
	}
	while (--argc > 0) {
		register char *arg;
		arg = *++argv;
		c = getcmd(arg);
		if (c == Ambiguous(struct cmd *))
			printf("?Ambiguous help command %s\n", arg);
		else if (c == (struct cmd *)0)
			printf("?Invalid help command %s\n", arg);
		else
			printf("%s\n", c->help);
	}
	return 0;
}

/*
 * main.  Parse arguments, invoke the protocol or command parser.
 */


void
main(argc, argv)
	int argc;
	char *argv[];
{
    tninit();		/* Clear out things */

    NetTrace = stdout;
    TerminalSaveState();
    autoflush = TerminalAutoFlush();

    prompt = argv[0];
D 13
    if (argc > 1 && !strcmp(argv[1], "-d")) {
	debug = 1;
	argv++;
	argc--;
    }
    if (argc > 1 && !strcmp(argv[1], "-n")) {
	argv++;
	argc--;
	if (argc > 1) {		/* get file name */
	    NetTrace = fopen(argv[1], "w");
	    argv++;
	    argc--;
	    if (NetTrace == NULL) {
		NetTrace = stdout;
E 13
I 13
    while ((argc > 1) && (argv[1][0] == '-')) {
	if (!strcmp(argv[1], "-d")) {
	    debug = 1;
	} else if (!strcmp(argv[1], "-n")) {
D 14
	    if ((argc > 1) && (argv[1][0] != '-')) {	/* get file name */
		NetTrace = fopen(argv[1], "w");
E 14
I 14
	    if ((argc > 1) && (argv[2][0] != '-')) {	/* get file name */
		NetTrace = fopen(argv[2], "w");
E 14
		argv++;
		argc--;
		if (NetTrace == NULL) {
		    NetTrace = stdout;
		}
E 13
	    }
D 13
	}
    }
E 13
I 13
	} else {
E 13
#if	defined(TN3270) && defined(unix)
D 13
    if (argc > 1 && !strcmp(argv[1], "-t")) {
	argv++;
	argc--;
	if (argc > 1) {		/* get command name */
	    transcom = tline;
	    (void) strcpy(transcom, argv[1]);
	    argv++;
	    argc--;
E 13
I 13
	    if (!strcmp(argv[1], "-t")) {
D 18
		if ((argc > 1) && (argv[1][0] != '-')) { /* get file name */
E 18
I 18
		if ((argc > 1) && (argv[2][0] != '-')) { /* get file name */
E 18
		    transcom = tline;
		    (void) strcpy(transcom, argv[1]);
		    argv++;
		    argc--;
		}
	    } else if (!strcmp(argv[1], "-noasynch")) {
		noasynch = 1;
	    } else
#endif	/* defined(TN3270) && defined(unix) */
	    if (argv[1][1] != '\0') {
		fprintf(stderr, "Unknown option *%s*.\n", argv[1]);
	    }
E 13
	}
I 13
	argc--;
	argv++;
E 13
    }
D 13
#endif	/* defined(TN3270) && defined(unix) */
E 13
    if (argc != 1) {
	if (setjmp(toplevel) != 0)
	    Exit(0);
	tn(argc, argv);
    }
    setjmp(toplevel);
D 12
    for (;;)
E 12
I 12
    for (;;) {
#if	!defined(TN3270)
E 12
	command(1);
I 12
#else	/* !defined(TN3270) */
	if (!shell_active) {
	    command(1);
	} else {
D 13
#if	defined(MSDOS)
E 13
I 13
#if	defined(TN3270)
E 13
	    shell_continue();
D 13
#endif	/* defined(MSDOS) */
E 13
I 13
#endif	/* defined(TN3270) */
E 13
	}
#endif	/* !defined(TN3270) */
    }
E 12
}
E 9
