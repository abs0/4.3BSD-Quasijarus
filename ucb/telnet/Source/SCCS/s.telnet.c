h59776
s 00002/00002/01043
d D 5.31 88/05/15 12:47:57 minshall 62 61
c Make it work for tn3270.
e
s 00006/00005/01039
d D 5.30 88/03/27 13:52:19 minshall 61 60
c Make it *compile* with -DTN3270.
e
s 00013/00007/01031
d D 5.29 88/03/08 10:31:04 bostic 60 59
c add Berkeley specific copyright
e
s 00001/00000/01037
d D 5.28 88/02/17 18:50:24 minshall 59 58
c Fix bug when no TERM environment variable set (len not set).
c (Reported by M. Karels.)
e
s 00003/00001/01034
d D 5.27 88/01/07 15:26:42 minshall 58 57
c Make SYNCH work (ie: urgent (ie: ring markers)).
e
s 00001/00003/01034
d D 5.26 88/01/07 11:54:07 minshall 57 56
c Reduce extern's.
e
s 00005/00003/01032
d D 5.25 87/11/23 20:37:58 minshall 56 55
c Fixes from Dave Borman.
e
s 00001/00001/01034
d D 5.24 87/11/23 11:15:34 minshall 55 54
c Add in some changes from Dave Borman (borman@monet).
e
s 00166/00022/00869
d D 5.23 87/10/27 16:03:16 minshall 54 53
c Various changes, moves.
e
s 00038/00420/00853
d D 5.22 87/10/23 15:15:45 minshall 53 52
c Try to move system dependent stuff to system dependent files.
e
s 00020/00019/01253
d D 5.21 87/10/23 11:57:20 minshall 52 51
c Make the ring buffer a two-state buffer (supplier and consumer)
c rather than a three-state buffer (supplier, sender, and acker).
e
s 00148/00118/01124
d D 5.20 87/10/10 17:46:14 minshall 51 50
c Lots of changes.  telsnd() is new; move to ring's for
c input buffers.
e
s 00016/00067/01226
d D 5.19 87/10/10 14:27:22 minshall 50 49
c This is the first version to get near rings.  It compiles,
c but doesn't work.
e
s 00958/02032/00335
d D 5.18 87/10/10 11:47:10 minshall 49 48
c This is the new, restructured version.
e
s 00004/00001/02363
d D 5.17 87/07/07 14:36:09 minshall 48 47
c Fix core dumps on suns (from sun!nowicki, Bill Nowicki).
c bug report 4.2BSD/ucb/237
e
s 00004/00003/02360
d D 5.16 86/05/27 09:46:24 minshall 47 46
c Fixed the mapping of \n to \r\n (from tty to network) whenever 
c CRMOD is true.
e
s 00004/00000/02359
d D 5.15 86/05/13 11:45:58 minshall 46 45
c Add acknowledgement to Dave Borman.
e
s 00002/00002/02357
d D 5.14 86/05/06 21:14:30 minshall 45 44
c Get back the SCCS keywords.
e
s 00178/00045/02181
d D 5.13 86/05/02 11:46:53 minshall 44 43
c This version handles terminal type correctly, and
c responds well to various DONT commands.
e
s 00273/00123/01953
d D 5.12 86/04/22 22:17:27 minshall 43 42
c Various changes, including flushing the network buffer
c before sending TELNET SYNCH.
e
s 00146/00089/01930
d D 5.11 86/04/20 21:27:02 minshall 42 41
c Various fixes, plus adding "autoflush", plus ^O recognition.
e
s 00380/00361/01639
d D 5.10 86/04/19 16:34:48 minshall 41 40
c Minor change to allow for certain hosts whose TCP urgent pointer is off by one.
e
s 00291/00071/01709
d D 5.9 86/04/17 22:41:11 minshall 40 39
c This version is fairly close to a production one.
c We should now send SYNCH in a 4.2/4.3 compatible manner.
c We should now come as close as possible in receiving SYNCH.
c We now implement the "display" command.
e
s 00528/00122/01252
d D 5.8 86/04/16 22:37:11 minshall 39 38
c One more day of hacking.
c Basically, most of Dave Borman's changes are in.  This is by
c no means a finished product.  There are still unanswered questions,
c plus a lot of rough edges.
e
s 00783/00462/00591
d D 5.7 86/04/15 16:12:08 minshall 38 37
c This version is restructured, and includes a
c "send" and "toggle" command.
e
s 00161/00061/00892
d D 5.6 86/04/09 09:25:18 minshall 37 36
c This version handles CR-LF, CR-NULL, CR-whatever correctly.
e
s 00006/00000/00947
d D 5.5 86/03/11 12:00:55 karels 36 34
c can't reconnect after some errors
e
s 00003/00001/00946
d R 5.5 86/03/11 11:34:54 karels 35 34
c can't retry if got too far
e
s 00002/00004/00945
d D 5.4 86/01/10 02:08:13 lepreau 34 33
c In command mode exit on EOF on stdin
e
s 00028/00012/00921
d D 5.3 85/11/08 11:49:22 karels 33 32
c try host numbers before addresses, try multiple addresses in turn
e
s 00020/00010/00913
d D 5.2 85/10/24 21:18:00 karels 32 30
c don't send initial SGA option if not using standard port;
c clean up help a bit
e
s 00022/00010/00913
d R 5.2 85/10/24 21:04:20 karels 31 30
c don't unset local start/stop (won't trash connection info, either);
c don't send initial SGA option if not using standard port; add help as well as ?
e
s 00013/00001/00910
d D 5.1 85/05/31 09:35:02 dist 30 29
c Add copyright
e
s 00047/00007/00864
d D 4.27 85/02/05 08:32:22 ralph 29 28
c added sendesc, ayt, interrupt commands; fix half duplex bugs.
e
s 00002/00000/00869
d D 4.26 84/12/23 17:40:17 sam 28 27
c didn't convert \r to \r\n; from brl
e
s 00010/00005/00859
d D 4.25 84/12/06 18:09:36 leres 27 26
c Use new setsockopt() interface
e
s 00002/00002/00862
d D 4.24 83/07/20 16:09:29 helge 26 25
c fix debug stuff
e
s 00006/00001/00858
d D 4.23 83/07/19 22:33:19 sam 25 22
c handle EOF from tty properly
e
s 00006/00001/00858
d R 4.23 83/07/19 22:28:48 sam 24 22
c handle EOF on tty properly
e
s 00006/00001/00858
d R 4.23 83/07/18 20:31:49 sam 23 22
c handle EOF from tty properly
e
s 00006/00000/00853
d D 4.22 83/06/21 20:43:54 sam 22 21
c fix from jdd@allegra.UUCP
e
s 00025/00019/00828
d D 4.21 83/06/13 02:48:48 sam 21 20
c and another put back to before
e
s 00004/00006/00843
d D 4.20 83/06/10 23:34:19 sam 20 19
c new signals, no libjobs
e
s 00003/00003/00846
d D 4.19 83/05/03 19:57:36 sam 19 18
c move from netser forces telnet.h to <arpa/telnet.h>
e
s 00032/00028/00817
d D 4.18 83/03/29 11:29:11 sam 18 17
c fix shutdown problem; double IAC's on output; misc cleanups
e
s 00001/00001/00844
d D 4.17 83/01/23 13:46:01 sam 17 16
c declare setdebug function
e
s 00016/00000/00829
d D 4.16 83/01/16 16:57:58 sam 16 15
c add debugging
e
s 00060/00034/00769
d D 4.15 82/12/25 22:33:21 sam 15 14
c use new ioctl calls; negate crmod by default and add user
c settable cr mapping on output for multics braindamage (really terminal handler)
e
s 00001/00001/00802
d D 4.14 82/12/25 21:19:35 sam 14 13
c port numbers now byte swapped
e
s 00001/00001/00802
d D 4.13 82/11/17 16:09:14 sam 13 12
c forgot to change socket calls
e
s 00018/00010/00785
d D 4.12 82/11/14 15:19:34 sam 12 11
c convert to 4.1c sys calls and directory layout
e
s 00054/00049/00741
d D 4.11 82/10/07 22:34:27 sam 11 10
c bug with options not being reset/reverse echo option request
e
s 00017/00008/00773
d D 4.10 82/10/07 21:38:59 sam 10 9
c handle . notation for host names
e
s 00032/00034/00749
d D 4.9 82/10/06 18:26:15 sam 9 8
c bugs with error ignored error returns & new net data base library
e
s 00006/00002/00777
d D 4.8 82/07/13 09:49:38 feldman 8 7
c changed escape char, added debug option, byte swap port #
e
s 00009/00001/00770
d D 4.7 82/04/10 18:21:27 sam 7 6
c watch for write failures to the net
e
s 00003/00000/00768
d D 4.6 82/03/31 10:04:47 sam 6 5
c assume initial option state reflects options automatically sent
e
s 00014/00008/00754
d D 4.5 82/03/23 14:35:01 root 5 4
c debugging stuff
e
s 00001/00002/00761
d D 4.4 82/03/16 21:25:18 root 4 3
c set up sccsid's
e
s 00001/00001/00762
d D 4.3 82/03/01 20:49:27 sam 3 2
c s_addr is u_long, so <= is pointless
e
s 00064/00005/00699
d D 4.2 82/03/01 11:52:00 sam 2 1
c bug fix, plus code to view option negotiation
e
s 00704/00000/00000
d D 4.1 82/02/28 10:34:16 root 1 0
c date and time created 82/02/28 10:34:16 by root
e
u
U
t
T
I 30
D 49
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 49
E 30
I 18
D 60
#ifndef lint
I 30
D 49
char copyright[] =
D 44
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 44
I 44
D 45
"@(#) Copyright (c) 1983 Regents of the University of California.\n\
E 45
I 45
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 49
I 49
static char copyright[] =
"@(#) Copyright (c) 1984-1987 Regents of the University of California.\n\
E 49
E 45
E 44
 All rights reserved.\n";
D 49
#endif not lint
E 49
I 49
#endif	/* not lint */
E 60
I 60
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
E 60
E 49

#ifndef lint
E 30
E 18
I 1
D 4
/*	%M%	%I%	%E%	*/

E 4
I 4
D 44
static char sccsid[] = "%W% (Berkeley) %G%";
E 44
I 44
D 45
static char sccsid[] = "@(#)telnet.c	5.12 (Berkeley) 4/22/86";
E 45
I 45
D 49
static char sccsid[] = "%W% (Berkeley) %G%";
E 45
E 44
I 18
D 30
#endif
E 30
I 30
#endif not lint
E 49
I 49
D 60
static char sccsid[] = "@(#)telnet.c	1.2 (Berkeley) 9/25/87";
#endif	/* not lint */
E 60
I 60
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 60
E 49
E 30

E 18
E 4
D 50
/*
D 49
 * User telnet program.
E 49
I 49
 * User telnet program, modified for use by tn3270.c.
E 49
I 46
 *
D 49
 * Many of the FUNCTIONAL changes in this newest version of telnet
E 49
I 49
 * Many of the FUNCTIONAL changes in this newest version of TELNET
E 49
 * were suggested by Dave Borman of Cray Research, Inc.
I 49
 *
 * Other changes in the tn3270 side come from Alan Crosswell (Columbia),
 * Bob Braden (ISI), Steve Jacobson (Berkeley), and Cliff Frost (Berkeley).
 *
 * This code is common between telnet(1c) and tn3270(1c).  There are the
 * following defines used to generate the various versions:
 *
 *	TN3270		- 	This is to be linked with tn3270.
 *
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
 *	MSDOS		-	Compiles in MSDOS specific stuff.
 *
E 49
E 46
 */
I 46

E 50
E 46
I 12
#include <sys/types.h>
D 49
#include <sys/socket.h>
I 15
#include <sys/ioctl.h>
E 49
I 40
D 53
#include <sys/time.h>
I 49
#include <sys/socket.h>
E 53
E 49
E 40
E 15

D 53
#include <netinet/in.h>

E 53
I 19
D 49
#define	TELOPTS
E 49
I 49
#if	defined(unix)
I 61
#include <signal.h>
E 61
/* By the way, we need to include curses.h before telnet.h since,
 * among other things, telnet.h #defines 'DO', which is a variable
 * declared in curses.h.
 */
#include <curses.h>
#endif	/* defined(unix) */

E 49
#include <arpa/telnet.h>
I 49

D 53
#if	!defined(NOT43)
E 49
I 41
#include <arpa/inet.h>
I 49
#else	/* !defined(NOT43) */
extern unsigned long inet_addr();
extern char	*inet_ntoa();
#endif	/* !defined(NOT43) */
E 49
E 41

E 19
E 12
D 49
#include <stdio.h>
E 49
#include <ctype.h>
#include <errno.h>
D 49
#include <signal.h>
D 15
#include <sgtty.h>
E 15
#include <setjmp.h>
E 49
D 12
#include <sys/types.h>
#include <sys/socket.h>
#include <net/in.h>
E 12
I 9
#include <netdb.h>
I 49

E 53
#if	defined(unix)
E 49
I 41
#include <strings.h>
I 49
#else	/* defined(unix) */
#include <string.h>
#endif	/* defined(unix) */
E 49
E 41
I 12
D 19

E 12
E 9
I 2
#define	TELOPTS
E 2
#include "telnet.h"
E 19

I 50
#include "ring.h"

E 50
I 49
#include "defines.h"
#include "externs.h"
#include "types.h"
#include "general.h"
E 49
I 40

D 53

I 49
D 50
#if	!defined(TN3270)
#define	ExitString(f,s,r)	{ fprintf(f, s); exit(r); }
#define	Exit(x)			exit(x)
#define	SetIn3270()

E 50
void	setcommandmode(), command();	/* forward declarations */
D 50
#endif	/* !defined(TN3270) */
E 50

E 49
I 44
#ifndef	FD_SETSIZE
E 44
/*
 * The following is defined just in case someone should want to run
 * this telnet on a 4.2 system.
 *
D 44
 * This has never been tested, so good luck...
E 44
 */
D 44
#ifndef	FD_SETSIZE
E 44

D 44
typedef long	fd_set;
E 44
I 44
#define	FD_SET(n, p)	((p)->fds_bits[0] |= (1<<(n)))
#define	FD_CLR(n, p)	((p)->fds_bits[0] &= ~(1<<(n)))
#define	FD_ISSET(n, p)	((p)->fds_bits[0] & (1<<(n)))
#define FD_ZERO(p)	((p)->fds_bits[0] = 0)
E 44

D 44
#define	FD_SET(n, p)	(*(p) |= (1<<(n)))
#define	FD_CLR(n, p)	(*(p) &= ~(1<<(n)))
#define	FD_ISSET(n, p)	(*(p) & (1<<(n)))
#define FD_ZERO(p)	(*(p) = 0)

E 44
#endif
E 53

E 40
D 15
#define	ctrl(x)		((x) & 037)
E 15
D 41
#define	strip(x)	((x)&0177)
E 41
I 41
D 42
#define	strip(x)	((x)&0x3f)
E 42
I 42
#define	strip(x)	((x)&0x7f)
I 49
D 53
#define min(x,y)	((x<y)? x:y)
E 53
E 49
E 42
E 41
D 12
#define	INFINITY	10000000
E 12
D 9
#define	swab(x)		((((x) >> 8) | ((x) << 8)) & 0xffff)
E 9

D 42
char	ttyobuf[BUFSIZ], *tfrontp = ttyobuf, *tbackp = ttyobuf;
I 38
D 41
#define	TTYADD(c)	{ if (!flushing) { *tfrontp++ = c; } }
E 41
I 41
#define	TTYADD(c)	{ if (!SYNCHing) { *tfrontp++ = c; } }
E 42
I 42
D 49
char	ttyobuf[2*BUFSIZ], *tfrontp = ttyobuf, *tbackp = ttyobuf;
#define	TTYADD(c)	{ if (!(SYNCHing||flushout)) { *tfrontp++ = c; } }
#define	TTYLOC()	(tfrontp)
#define	TTYMAX()	(ttyobuf+sizeof ttyobuf-1)
#define	TTYMIN()	(netobuf)
#define	TTYBYTES()	(tfrontp-tbackp)
#define	TTYROOM()	(TTYMAX()-TTYLOC()+1)
E 49
I 49
D 53
#if	defined(TN3270)
static char	Ibuf[8*BUFSIZ], *Ifrontp, *Ibackp;
#endif	/* defined(TN3270) */
E 53
E 49
E 42
E 41

E 38
D 11
char	netobuf[BUFSIZ] =
	{ IAC, DO, TELOPT_ECHO, IAC, DO, TELOPT_SGA,
	  IAC, WONT, TELOPT_SGA },
	*nfrontp = netobuf + 9, *nbackp = netobuf;
E 11
I 11
D 42
char	netobuf[BUFSIZ], *nfrontp = netobuf, *nbackp = netobuf;
E 42
I 42
D 49
char	netobuf[2*BUFSIZ], *nfrontp = netobuf, *nbackp = netobuf;
E 42
I 38
#define	NETADD(c)	{ *nfrontp++ = c; }
#define	NET2ADD(c1,c2)	{ NETADD(c1); NETADD(c2); }
#define NETLOC()	(nfrontp)
I 42
#define	NETMAX()	(netobuf+sizeof netobuf-1)
#define	NETBYTES()	(nfrontp-nbackp)
#define	NETROOM()	(NETMAX()-NETLOC()+1)
E 42
char	*neturg = 0;		/* one past last byte of urgent data */
E 49
E 38
E 11
D 53

E 53
I 44
D 49
char	subbuffer[100], *subpointer, *subend;	/* buffer for sub-options */
E 49
I 49
static char	subbuffer[SUBBUFSIZE],
		*subpointer, *subend;	 /* buffer for sub-options */
E 49
#define	SB_CLEAR()	subpointer = subbuffer;
#define	SB_TERM()	subend = subpointer;
#define	SB_ACCUM(c)	if (subpointer < (subbuffer+sizeof subbuffer)) { \
				*subpointer++ = (c); \
			}

I 49
D 53
static char	sb_terminal[] = { IAC, SB,
			TELOPT_TTYPE, TELQUAL_IS,
			'I', 'B', 'M', '-', '3', '2', '7', '8', '-', '2',
			IAC, SE };
#define	SBTERMMODEL	13


E 53
E 49
E 44
char	hisopts[256];
char	myopts[256];

char	doopt[] = { IAC, DO, '%', 'c', 0 };
char	dont[] = { IAC, DONT, '%', 'c', 0 };
char	will[] = { IAC, WILL, '%', 'c', 0 };
char	wont[] = { IAC, WONT, '%', 'c', 0 };

I 38
D 49
struct cmd {
	char	*name;		/* command name */
	char	*help;		/* help string */
	int	(*handler)();	/* routine which executes command */
	int	dohelp;		/* Should we give general help information? */
	int	needconnect;	/* Do we need to be connected to execute? */
};
E 49
I 49
D 51
static char	sibuf[BUFSIZ], *sbp;
static char	tibuf[BUFSIZ], *tbp;
E 51
I 51
D 53
static Ring	netiring, ttyiring;
static char	netibuf[BUFSIZ];
static char	ttyibuf[BUFSIZ];
E 51
static fd_set ibits, obits, xbits;
E 49

E 38
D 49
int	connected;
int	net;
I 38
int	tout;
E 38
I 2
D 15
int	showoptions;
E 15
I 15
int	showoptions = 0;
E 15
I 8
D 41
int	options;
E 41
I 16
int	debug = 0;
E 16
I 15
int	crmod = 0;
I 37
D 38
int	printnet = 0;
E 38
I 38
int	netdata = 0;
E 38
static FILE	*NetTrace;
E 37
I 32
int	telnetport = 1;
E 49
I 38

E 53
I 49
int
	connected,
D 53
	net,
E 53
D 51
	scc,
	tcc,
E 51
	showoptions,
	In3270,		/* Are we in 3270 mode? */
	ISend,		/* trying to send network data in */
	debug = 0,
	crmod,
	netdata,	/* Print out network data flow */
	crlf,		/* Should '\r' be mapped to <CR><LF> (or <CR><NUL>)? */
	noasynch = 0,	/* User specified "-noasynch" on command line */
	askedSGA = 0,	/* We have talked about suppress go ahead */
D 53
	telnetport = 1;
E 53
I 53
D 57
	telnetport = 1,
E 57
I 57
	telnetport,
E 57
	SYNCHing,	/* we are in TELNET SYNCH mode */
	flushout,	/* flush output */
	autoflush = 0,	/* flush output when interrupting? */
	autosynch,	/* send interrupt characters with SYNCH? */
	localchars,	/* we recognize interrupt/quit */
	donelclchars,	/* the user has set "localchars" */
	donebinarytoggle,	/* the user has put us in binary */
	dontlecho,	/* do we suppress local echoing right now? */
	globalmode;
E 53
E 49
D 41
int	flushing = 0;		/* are we in TELNET SYNCH mode? */
E 41

E 38
E 32
E 15
E 8
E 2
D 49
char	*prompt;
D 8
char	escape = ctrl('_');
E 8
I 8
D 15
char	escape = ctrl(']');
E 15
I 15
char	escape = CTRL(]);
I 39
char	echoc = CTRL(E);
E 49
I 49
#define	CONTROL(x)	((x)&0x1f)		/* CTRL(x) is not portable */
E 49
D 41
int	flushout = 0;
int	localsigs = 0;
int	donelclsigs = 0;
int	linemode;
int	doechocharrecognition = 0;
int	dontlecho = 0;		/* do we do local echoing right now? */
E 41
E 39
E 15
E 8

I 41
D 49
int	SYNCHing = 0;		/* we are in TELNET SYNCH mode */
int	flushout = 0;		/* flush output */
I 42
int	autoflush = 0;		/* flush output when interrupting? */
E 42
int	autosynch = 0;		/* send interrupt characters with SYNCH? */
D 43
int	localsigs = 0;		/* we recognize interrupt/quit */
int	donelclsigs = 0;	/* the user has set "localsigs" */
int	doechocharrecognition = 1;	/* in line mode recognize echo toggle */
E 43
I 43
int	localchars = 0;		/* we recognize interrupt/quit */
int	donelclchars = 0;	/* the user has set "localchars" */
E 43
int	dontlecho = 0;		/* do we suppress local echoing right now? */
E 49
I 49
char
	*prompt = 0,
	escape,
	echoc;
E 49

E 41
D 49
char	line[200];
int	margc;
char	*margv[20];
E 49
I 49
D 53
int
	SYNCHing,		/* we are in TELNET SYNCH mode */
	flushout,		/* flush output */
	autoflush = 0,		/* flush output when interrupting? */
	autosynch,		/* send interrupt characters with SYNCH? */
	localchars,		/* we recognize interrupt/quit */
	donelclchars,		/* the user has set "localchars" */
	donebinarytoggle,	/* the user has put us in binary */
	dontlecho,		/* do we suppress local echoing right now? */
	globalmode;
E 49

D 49
jmp_buf	toplevel;
jmp_buf	peerdied;
E 49
I 49
/*	The following are some tn3270 specific flags */
#if	defined(TN3270)
E 49

D 49
extern	int errno;
E 49
I 49
static int
	Sent3270TerminalType;	/* Have we said we are a 3270? */
E 49

D 38
int	tn(), quit(), suspend(), bye(), help();
D 2
int	setescape(), status(), toggle();
E 2
I 2
int	setescape(), status(), toggle(), setoptions();
I 15
D 17
int	setcrmod();
E 17
I 17
D 29
int	setcrmod(), setdebug();
E 29
I 29
int	setcrmod(), setdebug(), sendesc(), ayt(), intp();
I 37
int	setprintnet();
E 38
E 37
E 29
E 17
E 15
E 2
D 49

D 11
#define HELPINDENT (sizeof("connect"))
E 11
I 11
D 38
#define HELPINDENT (sizeof ("connect"))
E 11

struct cmd {
D 18
	char	*name;
	char	*help;
	int	(*handler)();
E 18
I 18
	char	*name;		/* command name */
	char	*help;		/* help string */
	int	(*handler)();	/* routine which executes command */
I 37
	int	dohelp;		/* Should we give general help information? */
E 37
E 18
};

D 18
char	ohelp[] = "connect to a site";
char	chelp[] = "close current connection";
char	qhelp[] = "exit telnet";
char	zhelp[] = "suspend telnet";
I 16
char	dhelp[] = "toggle debugging";
E 16
char	ehelp[] = "set escape character";
char	shelp[] = "print status information";
char	hhelp[] = "print help information";
I 2
char	phelp[] = "toggle viewing of options processing";
I 15
char	rhelp[] = "toggle mapping of received carriage returns";
E 18
I 18
char	openhelp[] =	"connect to a site";
char	closehelp[] =	"close current connection";
char	quithelp[] =	"exit telnet";
char	zhelp[] =	"suspend telnet";
char	debughelp[] =	"toggle debugging";
char	escapehelp[] =	"set escape character";
char	statushelp[] =	"print status information";
char	helphelp[] =	"print help information";
char	optionshelp[] =	"toggle viewing of options processing";
char	crmodhelp[] =	"toggle mapping of received carriage returns";
I 29
char	sendeschelp[] =	"send escape character";
D 32
char	aythelp[] =	"send Are You There";
char	intphelp[] =	"send Interrupt Process";
E 32
I 32
char	aythelp[] =	"send \"Are You There\"";
char	intphelp[] =	"send \"Interrupt Process\"";
I 37
char	printnethelp[] ="toggle printing of raw network data";
E 37
E 32
E 29
E 18
E 15
E 2

struct cmd cmdtab[] = {
D 18
	{ "open",	ohelp,		tn },
	{ "close",	chelp,		bye },
	{ "quit",	qhelp,		quit },
E 18
I 18
D 37
	{ "open",	openhelp,	tn },
	{ "close",	closehelp,	bye },
	{ "quit",	quithelp,	quit },
E 18
	{ "z",		zhelp,		suspend },
D 18
	{ "escape",	ehelp,		setescape },
	{ "status",	shelp,		status },
I 2
	{ "options",	phelp,		setoptions },
I 15
	{ "crmod",	rhelp,		setcrmod },
I 16
	{ "debug",	dhelp,		setdebug },
E 16
E 15
E 2
	{ "?",		hhelp,		help },
E 18
I 18
	{ "escape",	escapehelp,	setescape },
	{ "status",	statushelp,	status },
	{ "options",	optionshelp,	setoptions },
	{ "crmod",	crmodhelp,	setcrmod },
	{ "debug",	debughelp,	setdebug },
I 29
	{ "ayt",	aythelp,	ayt },
	{ "interrupt",	intphelp,	intp },
	{ "passthru",	sendeschelp,	sendesc },
I 32
	{ "help",	helphelp,	help },
E 32
E 29
	{ "?",		helphelp,	help },
E 37
I 37
	{ "open",	openhelp,	tn, 1 },
	{ "close",	closehelp,	bye, 1 },
	{ "quit",	quithelp,	quit, 1 },
	{ "z",		zhelp,		suspend, 1 },
	{ "escape",	escapehelp,	setescape, 1 },
	{ "status",	statushelp,	status, 1 },
	{ "crmod",	crmodhelp,	setcrmod, 1 },
	{ "ayt",	aythelp,	ayt, 1 },
	{ "interrupt",	intphelp,	intp, 1 },
	{ "passthru",	sendeschelp,	sendesc, 1 },
	{ "help",	helphelp,	help, 1 },
	{ "?",		helphelp,	help, 0 },
	{ "options",	optionshelp,	setoptions, 0 },
	{ "debug",	debughelp,	setdebug, 0 },
	{ "printnet",	printnethelp,	setprintnet, 0 },
E 37
E 18
	0
};

E 38
D 9
struct	sockaddr_in sin = { AF_INET, swab(IPPORT_TELNET) };
E 9
I 9
D 15
struct sockaddr_in sin = { AF_INET };
E 15
I 15
struct sockaddr_in sin;
E 15
E 9

D 39
int	intr(), deadpeer();
E 39
I 39
D 41
int	intr(), deadpeer(), doescape();
E 39
char	*control();
E 41
struct	cmd *getcmd();
I 9
struct	servent *sp;
E 9

I 11
D 15
struct	sgttyb ostbuf;
struct	tchars otchars;
int	odisc;
E 15
I 15
D 21
struct	ttychars otc;
int	oflags;
E 21
I 21
D 39
struct	tchars otc;
E 39
I 39
struct	tchars otc, ntc;
E 39
D 42
struct	ltchars oltc;
E 42
I 42
struct	ltchars oltc, nltc;
E 42
D 39
struct	sgttyb ottyb;
E 39
I 39
struct	sgttyb ottyb, nttyb;
int	globalmode = 0;
int	flushline = 1;
E 39
E 21
E 15

I 39
char	*hostname;
char	hnamebuf[32];

/*
 * The following are some clocks used to decide how to interpret
D 40
 * the relationship between various varibles.
E 40
I 40
 * the relationship between various variables.
E 40
 */

struct {
    int
	system,			/* what the current time is */
	echotoggle,		/* last time user entered echo character */
D 40
	modenegotiated;		/* last time operating mode negotiated */
E 40
I 40
	modenegotiated,		/* last time operating mode negotiated */
	didnetreceive,		/* last time we read data from network */
	gotDM;			/* when did we last see a data mark */
E 40
D 41
} times;
E 41
I 41
} clocks;
E 41

D 41
#define	settimer(x)	times.x = times.system++


E 39
E 11
main(argc, argv)
	int argc;
	char *argv[];
{
I 9
	sp = getservbyname("telnet", "tcp");
	if (sp == 0) {
		fprintf(stderr, "telnet: tcp/telnet: unknown service\n");
		exit(1);
	}
I 37
	NetTrace = stdout;
E 37
I 11
D 15
	ioctl(0, TIOCGETP, (char *)&ostbuf);
	ioctl(0, TIOCGETC, (char *)&otchars);
	ioctl(0, TIOCGETD, (char *)&odisc);
E 15
I 15
D 21
	ioctl(0, TIOCGET, (char *)&oflags);
	ioctl(0, TIOCCGET, (char *)&otc);
E 21
I 21
	ioctl(0, TIOCGETP, (char *)&ottyb);
	ioctl(0, TIOCGETC, (char *)&otc);
	ioctl(0, TIOCGLTC, (char *)&oltc);
I 39
	ntc = otc;
	ntc.t_eofc = -1;		/* we don't want to use EOF */
	nttyb = ottyb;
E 39
E 21
E 15
E 11
E 9
	setbuf(stdin, 0);
	setbuf(stdout, 0);
	prompt = argv[0];
I 8
D 27
	if (argc > 1 && !strcmp(argv[1], "-d"))
D 26
		options = SO_DEBUG, argv++, argc--;
E 26
I 26
		debug = SO_DEBUG, argv++, argc--;
E 27
I 27
	if (argc > 1 && !strcmp(argv[1], "-d")) {
		debug = 1;
		argv++;
		argc--;
	}
I 37
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
E 37
E 27
E 26
E 8
	if (argc != 1) {
		if (setjmp(toplevel) != 0)
			exit(0);
		tn(argc, argv);
	}
	setjmp(toplevel);
	for (;;)
		command(1);
}
E 41
I 41
#define	settimer(x)	clocks.x = clocks.system++
E 41
I 39

/*
 * Various utility routines.
 */
E 39

I 41
char *ambiguous;		/* special return value */
#define Ambiguous(t)	((t)&ambiguous)


E 41
D 9
char host_name[100];
E 9
I 9
D 10
struct	hostent *host;
E 10
I 10
D 39
char	*hostname;
char	hnamebuf[32];
E 10
E 9

D 38
tn(argc, argv)
	int argc;
	char *argv[];
E 38
I 38

E 39
char **
genget(name, table, next)
char	*name;		/* name to match */
char	**table;		/* name entry in table */
char	**(*next)();	/* routine to return next entry in table */
E 38
{
D 38
	register int c;
I 10
D 33
	register struct hostent *host;
E 33
I 33
	register struct hostent *host = 0;
E 38
I 38
	register char *p, *q;
	register char **c, **found;
	register int nmatches, longest;
E 38
E 33
E 10

I 48
	if (name == 0) {
	    return 0;
	}
E 48
D 38
	if (connected) {
D 9
		printf("?Already connected to %s\n", host_name);
E 9
I 9
D 10
		printf("?Already connected to %s\n", host->h_name);
E 10
I 10
		printf("?Already connected to %s\n", hostname);
E 10
E 9
		return;
	}
	if (argc < 2) {
		strcpy(line, "Connect ");
		printf("(to) ");
		gets(&line[strlen(line)]);
		makeargv();
		argc = margc;
		argv = margv;
	}
	if (argc > 3) {
		printf("usage: %s host-name [port]\n", argv[0]);
		return;
	}
D 9
	sin.sin_addr.s_addr = rhost(&argv[1]);
D 2
	if (sin.sin_addr.s_addr == 0) {
E 2
I 2
D 3
	if (sin.sin_addr.s_addr <= 0) {
E 3
I 3
	if (sin.sin_addr.s_addr == (u_long)-1) {
E 9
I 9
D 33
	host = gethostbyname(argv[1]);
D 10
	if (host == 0) {
E 9
E 3
E 2
		printf("%s: unknown host\n", argv[1]);
		return;
E 10
I 10
	if (host) {
D 12
		bcopy(host->h_addr, &sin.sin_addr, host->h_length);
E 12
I 12
		sin.sin_family = host->h_addrtype;
		bcopy(host->h_addr, (caddr_t)&sin.sin_addr, host->h_length);
E 12
		hostname = host->h_name;
	} else {
E 33
I 33
	sin.sin_addr.s_addr = inet_addr(argv[1]);
	if (sin.sin_addr.s_addr != -1) {
E 33
I 12
		sin.sin_family = AF_INET;
E 12
D 33
		sin.sin_addr.s_addr = inet_addr(argv[1]);
		if (sin.sin_addr.s_addr == -1) {
E 33
I 33
		strcpy(hnamebuf, argv[1]);
		hostname = hnamebuf;
	} else {
		host = gethostbyname(argv[1]);
		if (host) {
			sin.sin_family = host->h_addrtype;
			bcopy(host->h_addr_list[0], (caddr_t)&sin.sin_addr,
				host->h_length);
			hostname = host->h_name;
		} else {
E 33
			printf("%s: unknown host\n", argv[1]);
			return;
E 38
I 38
	longest = 0;
	nmatches = 0;
	found = 0;
	for (c = table; p = *c; c = (*next)(c)) {
		for (q = name; *q == *p++; q++)
			if (*q == 0)		/* exact match? */
				return (c);
		if (!*q) {			/* the name was a prefix */
			if (q - name > longest) {
				longest = q - name;
				nmatches = 1;
				found = c;
			} else if (q - name == longest)
				nmatches++;
E 38
		}
D 33
		strcpy(hnamebuf, argv[1]);
		hostname = hnamebuf;
E 33
E 10
	}
I 9
D 10
	bcopy(host->h_addr, &sin.sin_addr, host->h_length);
E 10
D 38
	sin.sin_port = sp->s_port;
E 9
I 2
	if (argc == 3) {
		sin.sin_port = atoi(argv[2]);
D 32
		if (sin.sin_port < 0) {
			printf("%s: bad port number\n", argv[2]);
			return;
E 32
I 32
		if (sin.sin_port <= 0) {
			sp = getservbyname(argv[2], "tcp");
			if (sp)
				sin.sin_port = sp->s_port;
			else {
				printf("%s: bad port number\n", argv[2]);
				return;
			}
		} else {
			sin.sin_port = atoi(argv[2]);
			sin.sin_port = htons(sin.sin_port);
E 32
		}
I 14
D 32
		sin.sin_port = htons(sin.sin_port);
E 32
I 32
		telnetport = 0;
E 32
E 14
I 8
D 9
		sin.sin_port = swab(sin.sin_port);
E 9
E 8
	}
I 9
D 14
	sin.sin_port = htons(sin.sin_port);
E 14
E 9
E 2
D 8
	if ((net = socket(SOCK_STREAM, 0, 0, 0)) < 0) {
E 8
I 8
D 12
	if ((net = socket(SOCK_STREAM, 0, 0, options)) < 0) {
E 8
		perror("socket");
E 12
I 12
D 13
	net = socket(0, SOCK_STREAM, 0, 0);
E 13
I 13
D 29
	net = socket(AF_INET, SOCK_STREAM, 0, 0);
E 29
I 29
D 37
	net = socket(AF_INET, SOCK_STREAM, 0);
E 29
E 13
	if (net < 0) {
		perror("telnet: socket");
E 12
		return;
	}
I 16
D 18
	if (debug)
		if (setsockopt(net, SOL_SOCKET, SO_DEBUG, 0, 0) < 0)
			perror("telnet: setsockopt");
E 18
I 18
D 27
	if (debug && setsockopt(net, SOL_SOCKET, SO_DEBUG, 0, 0) < 0)
E 27
I 27
	if (debug &&
	    setsockopt(net, SOL_SOCKET, SO_DEBUG, &debug, sizeof(debug)) < 0)
E 27
		perror("setsockopt (SO_DEBUG)");
E 37
E 18
E 16
D 2
	if (argc == 3)
		sin.sin_port = atoi(argv[2]);
E 2
D 20
	sigset(SIGINT, intr);
	sigset(SIGPIPE, deadpeer);
E 20
I 20
	signal(SIGINT, intr);
	signal(SIGPIPE, deadpeer);
E 20
	printf("Trying...\n");
D 12
	if (connect(net, &sin)) {
		perror("connect");
E 12
I 12
D 29
	if (connect(net, (caddr_t)&sin, sizeof (sin), 0) < 0) {
E 29
I 29
D 33
	if (connect(net, (caddr_t)&sin, sizeof (sin)) < 0) {
E 33
I 33
D 37
	while (connect(net, (caddr_t)&sin, sizeof (sin)) < 0) {
		if (host && host->h_addr_list[1]) {
			int oerrno = errno;
E 37
I 37
	do {
		net = socket(AF_INET, SOCK_STREAM, 0);
		if (net < 0) {
			perror("telnet: socket");
			return;
		}
		if (debug && setsockopt(net, SOL_SOCKET, SO_DEBUG, &debug,
		    sizeof(debug)) < 0)
			perror("setsockopt (SO_DEBUG)");
		if (connect(net, (caddr_t)&sin, sizeof (sin)) < 0) {
			if (host && host->h_addr_list[1]) {
				int oerrno = errno;
E 37

D 37
			fprintf(stderr, "telnet: connect to address %s: ",
				inet_ntoa(sin.sin_addr));
			errno = oerrno;
			perror(0);
			host->h_addr_list++;
			bcopy(host->h_addr_list[0], (caddr_t)&sin.sin_addr,
				host->h_length);
			fprintf(stderr, "Trying %s...\n",
				inet_ntoa(sin.sin_addr));
I 36
			(void) close(net);
			net = socket(AF_INET, SOCK_STREAM, 0);
			if (net < 0) {
				perror("telnet: socket");
				return;
E 37
I 37
				fprintf(stderr,
				    "telnet: connect to address %s: ",
				    inet_ntoa(sin.sin_addr));
				errno = oerrno;
				perror(0);
				host->h_addr_list++;
				bcopy(host->h_addr_list[0],
				    (caddr_t)&sin.sin_addr, host->h_length);
				fprintf(stderr, "Trying %s...\n",
					inet_ntoa(sin.sin_addr));
				(void) close(net);
				continue;
E 37
			}
E 36
D 37
			continue;
E 37
I 37
			perror("telnet: connect");
			signal(SIGINT, SIG_DFL);
			return;
E 37
		}
E 33
E 29
D 37
		perror("telnet: connect");
E 12
D 20
		sigset(SIGINT, SIG_DFL);
E 20
I 20
		signal(SIGINT, SIG_DFL);
E 20
		return;
	}
D 9
	strcpy(host_name, argv[1]);
E 9
	connected++;
E 37
I 37
		connected++;
	} while (connected == 0);
E 37
	call(status, "status", 0);
	if (setjmp(peerdied) == 0)
		telnet(net);
	fprintf(stderr, "Connection closed by foreign host.\n");
	exit(1);
E 38
I 38
	if (nmatches > 1)
D 41
		return ((char **)-1);
E 41
I 41
		return Ambiguous(char **);
E 41
	return (found);
E 38
}

I 39
/*
 * Make a character string into a number.
 *
D 41
 * Todo:  1.  Could take random integers (123, 0x123, 0123, 0b123).
E 41
I 41
 * Todo:  1.  Could take random integers (12, 0x12, 012, 0b1).
E 41
 */
E 39
D 38
/*
 * Print status about the connection.
 */
/*VARARGS*/
status()
{
	if (connected)
D 9
		printf("Connected to %s.\n", host_name);
E 9
I 9
D 10
		printf("Connected to %s.\n", host->h_name);
E 10
I 10
		printf("Connected to %s.\n", hostname);
E 10
E 9
	else
		printf("No connection.\n");
	printf("Escape character is '%s'.\n", control(escape));
I 15
	fflush(stdout);
E 15
}
E 38

I 39
special(s)
register char *s;
{
	register char c;
	char b;

	switch (*s) {
	case '^':
		b = *++s;
		if (b == '?') {
D 42
		    c = b | 0x80;		/* DEL */
E 42
I 42
		    c = b | 0x40;		/* DEL */
E 42
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
I 41

/*
 * Construct a control character sequence
 * for a special character.
 */
char *
control(c)
	register int c;
{
	static char buf[3];

D 42
	if (c == 0x3f)
E 42
I 42
	if (c == 0x7f)
E 42
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
I 44


/*
 * upcase()
 *
 *	Upcase (in place) the argument.
 */

void
upcase(argument)
register char *argument;
{
    register int c;

    while (c = *argument) {
	if (islower(c)) {
	    *argument = toupper(c);
	}
	argument++;
    }
}
E 44
E 41

/*
I 41
 * Check to see if any out-of-band data exists on a socket (for
 * Telnet "synch" processing).
 */

E 49
I 49
#endif	/* defined(TN3270) */
E 49
int
D 49
stilloob(s)
int	s;		/* socket number */
{
    static struct timeval timeout = { 0 };
    fd_set	excepts;
    int value;
E 49

D 49
    do {
	FD_ZERO(&excepts);
	FD_SET(s, &excepts);
	value = select(s+1, (fd_set *)0, (fd_set *)0, &excepts, &timeout);
    } while ((value == -1) && (errno = EINTR));
E 49
I 49
	tout,			/* Output file descriptor */
	tin;			/* Input file descriptor */
E 49

D 49
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
E 49


E 53
/*
D 49
 *  netflush
 *		Send as much data as possible to the network,
 *	handling requests for urgent data.
 */


netflush(fd)
{
    int n;

    if ((n = nfrontp - nbackp) > 0) {
	if (!neturg) {
	    n = write(fd, nbackp, n);	/* normal write */
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
		n = send(fd, nbackp, n-1, 0);	/* send URGENT all by itself */
	    } else {
		n = send(fd, nbackp, n, MSG_OOB);	/* URGENT data */
	    }
	}
    }
    if (n < 0) {
	if (errno != ENOBUFS && errno != EWOULDBLOCK) {
	    setcommandmode();
	    perror(hostname);
	    close(fd);
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
}
I 43

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
E 43

I 43
char *
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
E 43
/*
I 43
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
	    bcopy(thisitem, good, length);
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
E 43
 * Send as much data as possible to the terminal.
 */


ttyflush()
{
    int n;

    if ((n = tfrontp - tbackp) > 0) {
D 42
	if (!SYNCHing) {
E 42
I 42
	if (!(SYNCHing||flushout)) {
E 42
	    n = write(tout, tbackp, n);
	} else {
	    ioctl(fileno(stdout), TIOCFLUSH, (char *) 0);
I 42
	    /* we leave 'n' alone! */
E 42
	}
    }
    if (n < 0) {
	return;
    }
    tbackp += n;
    if (tbackp == tfrontp) {
	tbackp = tfrontp = ttyobuf;
    }
}

/*
E 41
 * Various signal handling routines.
 */

deadpeer()
{
	setcommandmode();
	longjmp(peerdied, -1);
}

intr()
{
D 43
    if (localsigs) {
E 43
I 43
    if (localchars) {
E 43
	intp();
I 41
D 42
	if (autosynch) {
	    dosynch();
	}
E 42
E 41
	return;
    }
    setcommandmode();
    longjmp(toplevel, -1);
}

intr2()
{
D 43
    if (localsigs) {
E 43
I 43
    if (localchars) {
E 43
	sendbrk();
I 41
D 42
	if (autosynch) {
	    dosynch();
	}
E 42
E 41
	return;
    }
}

doescape()
{
    command(0);
}

/*
I 41
 * The following are routines used to print out debugging information.
 */


static
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
printoption(direction, fmt, option, what)
	char *direction, *fmt;
	int option, what;
{
	if (!showoptions)
		return;
D 44
	printf("%s ", direction);
E 44
I 44
	printf("%s ", direction+1);
E 44
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
D 44
	if (option < TELOPT_SUPDUP)
E 44
I 44
	if (option < (sizeof telopts/sizeof telopts[0]))
E 44
		printf("%s %s", fmt, telopts[option]);
	else
		printf("%s %d", fmt, option);
	if (*direction == '<') {
		printf("\r\n");
		return;
	}
	printf(" (%s)\r\n", what ? "reply" : "don't reply");
}

/*
E 41
 * Mode - set up terminal to a specific mode.
 */

E 39
D 38
makeargv()
{
	register char *cp;
	register char **argp = margv;

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
}

/*VARARGS*/
suspend()
{
	register int save;

	save = mode(0);
D 11
	kill(0, SIGTSTP);	/* get whole process group */
	mode(save);
E 11
I 11
	kill(0, SIGTSTP);
	/* reget parameters in case they were changed */
D 15
	ioctl(0, TIOCGETP, (char *)&ostbuf);
	ioctl(0, TIOCGETC, (char *)&otchars);
	ioctl(0, TIOCGETD, (char *)&odisc);
E 15
I 15
D 21
	ioctl(0, TIOCGET, (char *)&oflags);
	ioctl(0, TIOCCGET, (char *)&otc);
E 21
I 21
	ioctl(0, TIOCGETP, (char *)&ottyb);
	ioctl(0, TIOCGETC, (char *)&otc);
	ioctl(0, TIOCGLTC, (char *)&oltc);
E 21
E 15
	(void) mode(save);
E 11
}

/*VARARGS*/
bye()
{
D 18
	int how = 2;
E 18
I 11
	register char *op;
E 11

D 11
	mode(0);
E 11
I 11
	(void) mode(0);
E 11
	if (connected) {
I 12
D 15
#ifndef notdef
E 15
E 12
D 18
		ioctl(net, SIOCDONE, &how);
E 18
I 18
		shutdown(net, 2);
E 18
I 12
D 15
#endif
E 15
E 12
		printf("Connection closed.\n");
		close(net);
		connected = 0;
I 11
		/* reset his options */
		for (op = hisopts; op < &hisopts[256]; op++)
			*op = 0;
E 11
	}
}

/*VARARGS*/
quit()
{
	call(bye, "bye", 0);
	exit(0);
}

/*
 * Help command.
D 18
 * Call each command handler with argc == 0 and argv[0] == name.
E 18
 */
help(argc, argv)
	int argc;
	char *argv[];
{
	register struct cmd *c;

	if (argc == 1) {
		printf("Commands may be abbreviated.  Commands are:\n\n");
		for (c = cmdtab; c->name; c++)
D 37
			printf("%-*s\t%s\n", HELPINDENT, c->name, c->help);
E 37
I 37
			if (c->dohelp) {
				printf("%-*s\t%s\n", HELPINDENT, c->name,
								    c->help);
			}
E 37
		return;
	}
	while (--argc > 0) {
		register char *arg;
		arg = *++argv;
		c = getcmd(arg);
		if (c == (struct cmd *)-1)
			printf("?Ambiguous help command %s\n", arg);
		else if (c == (struct cmd *)0)
			printf("?Invalid help command %s\n", arg);
		else
			printf("%s\n", c->help);
	}
}

/*
 * Call routine with argc, argv set from args (terminated by 0).
 * VARARGS2
 */
call(routine, args)
	int (*routine)();
	int args;
{
	register int *argp;
	register int argc;

	for (argc = 0, argp = &args; *argp++ != 0; argc++)
		;
	(*routine)(argc, &args);
}

E 38
I 15
D 21
struct	ttychars notc = {
	-1,	-1,	-1,	-1,	-1,
	-1,	-1,	-1,	-1,	-1,
	-1,	-1,	-1,	-1
};
E 21
I 21
D 42
struct	tchars notc =	{ -1, -1, -1, -1, -1, -1 };
I 39
struct	tchars notc2;
E 39
struct	ltchars noltc =	{ -1, -1, -1, -1, -1, -1 };
I 39
struct	ltchars noltc2;
E 42
E 39
E 21

E 15
mode(f)
	register int f;
{
D 11
	register int old;
E 11
D 15
	struct sgttyb stbuf;
E 15
D 11
	static int ttymode = 0;
	int onoff;
E 11
I 11
	static int prevmode = 0;
D 15
	struct tchars tchars;
	int onoff, disc, old;
E 15
I 15
D 21
	struct ttychars *tc;
	int onoff, old, flags;
E 21
I 21
	struct tchars *tc;
	struct ltchars *ltc;
	struct sgttyb sb;
	int onoff, old;
I 42
	struct	tchars notc2;
	struct	ltchars noltc2;
	static struct	tchars notc =	{ -1, -1, -1, -1, -1, -1 };
	static struct	ltchars noltc =	{ -1, -1, -1, -1, -1, -1 };
E 42
E 21
E 15
E 11

I 39
	globalmode = f;
E 39
D 11
	ioctl(fileno(stdin), TIOCGETP, &stbuf);
	old = ttymode;
	ttymode = f;
E 11
I 11
	if (prevmode == f)
D 41
		return (f);
E 41
I 41
		return;
E 41
	old = prevmode;
	prevmode = f;
D 15
	stbuf = ostbuf;
	tchars = otchars;
E 15
I 15
D 21
	flags = oflags;
E 21
I 21
D 39
	sb = ottyb;
E 39
I 39
	sb = nttyb;
E 39
E 21
E 15
E 11
	switch (f) {
I 11

E 11
	case 0:
D 11
		stbuf.sg_flags &= ~RAW;
		stbuf.sg_flags |= ECHO|CRMOD;
E 11
I 11
D 15
		disc = odisc;
E 15
E 11
		onoff = 0;
I 15
		tc = &otc;
I 21
		ltc = &oltc;
E 21
E 15
		break;

D 39
	case 1:
D 11
		stbuf.sg_flags |= RAW;
		stbuf.sg_flags &= ~(ECHO|CRMOD);
		onoff = 1;
		break;

E 11
	case 2:
E 39
I 39
	case 1:		/* remote character processing, remote echo */
	case 2:		/* remote character processing, local echo */
E 39
D 11
		stbuf.sg_flags |= RAW;
		stbuf.sg_flags |= ECHO|CRMOD;
E 11
I 11
D 15
		stbuf.sg_flags |= CBREAK;
E 15
I 15
D 21
		flags |= CBREAK;
E 21
I 21
		sb.sg_flags |= CBREAK;
E 21
E 15
		if (f == 1)
D 15
			stbuf.sg_flags &= ~ECHO;
E 15
I 15
D 21
			flags &= ~(ECHO|CRMOD);
E 21
I 21
			sb.sg_flags &= ~(ECHO|CRMOD);
E 21
E 15
		else
D 15
			stbuf.sg_flags |= ECHO;
		tchars.t_intrc = tchars.t_quitc = -1;
I 12
		tchars.t_stopc = tchars.t_startc = -1;
E 12
		disc = OTTYDISC;
E 15
I 15
D 21
			flags |= ECHO|CRMOD;
E 21
I 21
			sb.sg_flags |= ECHO|CRMOD;
		sb.sg_erase = sb.sg_kill = -1;
E 21
		tc = &notc;
I 39
		/*
		 * If user hasn't specified one way or the other,
		 * then default to not trapping signals.
		 */
D 42
		if (!donelclsigs)
E 42
I 42
D 43
		if (!donelclsigs) {
E 42
			localsigs = 0;
E 43
I 43
		if (!donelclchars) {
			localchars = 0;
E 43
I 42
		}
E 42
D 43
		if (localsigs) {
E 43
I 43
		if (localchars) {
E 43
			notc2 = notc;
			notc2.t_intrc = ntc.t_intrc;
			notc2.t_quitc = ntc.t_quitc;
D 42
			notc2.t_eofc = ntc.t_eofc;
E 42
			tc = &notc2;
		} else
			tc = &notc;
E 39
I 21
		ltc = &noltc;
E 21
E 15
E 11
		onoff = 1;
I 39
D 41
		linemode = 0;
E 41
E 39
I 15
		break;
I 39
	case 3:		/* local character processing, remote echo */
	case 4:		/* local character processing, local echo */
	case 5:		/* local character processing, no echo */
		sb.sg_flags &= ~CBREAK;
		sb.sg_flags |= CRMOD;
		if (f == 4)
			sb.sg_flags |= ECHO;
		else
			sb.sg_flags &= ~ECHO;
I 42
		notc2 = ntc;
		tc = &notc2;
		noltc2 = oltc;
		ltc = &noltc2;
E 42
		/*
		 * If user hasn't specified one way or the other,
		 * then default to trapping signals.
		 */
D 42
		if (!donelclsigs)
E 42
I 42
D 43
		if (!donelclsigs) {
E 42
			localsigs = 1;
E 43
I 43
		if (!donelclchars) {
			localchars = 1;
E 43
D 42
		if (localsigs)
			tc = &ntc;
		else {
			notc2 = ntc;
E 42
I 42
		}
D 43
		if (localsigs) {
E 43
I 43
		if (localchars) {
E 43
			notc2.t_brkc = nltc.t_flushc;
			noltc2.t_flushc = -1;
		} else {
E 42
			notc2.t_intrc = notc2.t_quitc = -1;
D 42
			tc = &notc2;
E 42
		}
D 42
		noltc2 = oltc;
E 42
		noltc2.t_suspc = escape;
		noltc2.t_dsuspc = -1;
D 42
		ltc = &noltc2;
E 42
		onoff = 1;
D 41
		linemode = 1;
E 41
		break;
E 39

	default:
		return;
E 15
	}
I 11
D 15
	ioctl(fileno(stdin), TIOCSETD, &disc);
	ioctl(fileno(stdin), TIOCSETC, &tchars);
E 11
	ioctl(fileno(stdin), TIOCSETN, &stbuf);
E 15
I 15
D 21
	ioctl(fileno(stdin), TIOCCSET, (char *)tc);
	ioctl(fileno(stdin), TIOCSET, (char *)&flags);
E 21
I 21
	ioctl(fileno(stdin), TIOCSLTC, (char *)ltc);
	ioctl(fileno(stdin), TIOCSETC, (char *)tc);
	ioctl(fileno(stdin), TIOCSETP, (char *)&sb);
E 21
E 15
D 41
	ioctl(fileno(stdin), FIONBIO, &onoff);
	ioctl(fileno(stdout), FIONBIO, &onoff);
E 41
I 41
	ioctl(fileno(stdin), FIONBIO, (char *)&onoff);
	ioctl(fileno(stdout), FIONBIO, (char *)&onoff);
E 41
I 39
	if (f >= 3)
		signal(SIGTSTP, doescape);
	else if (old >= 3) {
		signal(SIGTSTP, SIG_DFL);
		sigsetmask(sigblock(0) & ~(1<<(SIGTSTP-1)));
	}
E 39
D 41
	return (old);
E 41
}
D 41

E 41
I 41

E 41
I 39
/*
 * These routines decides on what the mode should be (based on the values
 * of various global variables).
 */

D 40
setconnmode()
E 40
I 40
char *modedescriptions[] = {
	"telnet command mode",					/* 0 */
	"character-at-a-time mode",				/* 1 */
	"character-at-a-time mode (local echo)",		/* 2 */
	"line-by-line mode (remote echo)",			/* 3 */
	"line-by-line mode",					/* 4 */
	"line-by-line mode (local echoing suppressed)",		/* 5 */
};

getconnmode()
E 40
{
    static char newmode[8] = { 4, 5, 3, 3, 2, 2, 1, 1 };
D 41
    int index = 0;
E 41
I 41
    int modeindex = 0;
E 41

    if (hisopts[TELOPT_ECHO]) {
D 41
	index += 2;
E 41
I 41
	modeindex += 2;
E 41
    }
    if (hisopts[TELOPT_SGA]) {
D 41
	index += 4;
E 41
I 41
	modeindex += 4;
E 41
    }
D 41
    if (dontlecho && (times.echotoggle > times.modenegotiated)) {
	index += 1;
E 41
I 41
    if (dontlecho && (clocks.echotoggle > clocks.modenegotiated)) {
	modeindex += 1;
E 41
    }
D 40
    mode(newmode[index]);
E 40
I 40
D 41
    return newmode[index];
E 41
I 41
    return newmode[modeindex];
E 41
E 40
}

I 40
setconnmode()
{
    mode(getconnmode());
}
E 40

I 40

E 40
setcommandmode()
{
    mode(0);
}

E 39
char	sibuf[BUFSIZ], *sbp;
char	tibuf[BUFSIZ], *tbp;
int	scc, tcc;

I 42

E 42
/*
 * Select from tty and network...
 */
D 38
telnet(s)
	int s;
E 38
I 38
telnet()
E 38
{
	register int c;
D 38
	int tin = fileno(stdin), tout = fileno(stdout);
E 38
I 38
	int tin = fileno(stdin);
E 38
	int on = 1;
I 43
	fd_set ibits, obits, xbits;
E 43

I 38
	tout = fileno(stdout);
E 38
D 11
	mode(1);
I 2
D 9
	if (showoptions)
		printoption("<--", doopt, TELOPT_ECHO);
E 9
I 9
	printoption("SENT", doopt, TELOPT_ECHO);
E 9
E 2
	sprintf(nfrontp, doopt, TELOPT_ECHO);
	nfrontp += sizeof(doopt) - 2;
I 6
	hisopts[TELOPT_ECHO] = 1;
E 6
I 2
D 9
	if (showoptions)
		printoption("<--", doopt, TELOPT_SGA);
E 9
I 9
	printoption("SENT", doopt, TELOPT_SGA);
E 9
E 2
	sprintf(nfrontp, doopt, TELOPT_SGA);
	nfrontp += sizeof(doopt) - 2;
I 6
	hisopts[TELOPT_SGA] = 1;
E 6
I 2
D 9
	if (showoptions)
		printoption("<--", will, TELOPT_SGA);
E 9
I 9
	printoption("SENT", will, TELOPT_SGA);
E 9
E 2
	sprintf(nfrontp, will, TELOPT_SGA);
	nfrontp += sizeof(doopt) - 2;
I 6
	myopts[TELOPT_SGA] = 1;
E 11
I 11
D 39
	(void) mode(2);
E 39
I 39
	setconnmode();
I 42
	scc = 0;
	tcc = 0;
I 43
	FD_ZERO(&ibits);
	FD_ZERO(&obits);
	FD_ZERO(&xbits);

E 43
E 42
E 39
E 11
E 6
D 38
	ioctl(s, FIONBIO, &on);
I 29
D 32
	if (!hisopts[TELOPT_SGA])
E 32
I 32
	if (telnetport && !hisopts[TELOPT_SGA])
E 38
I 38
D 41
	ioctl(net, FIONBIO, &on);
E 41
I 41
	ioctl(net, FIONBIO, (char *)&on);
E 41
I 40
D 42
#if	defined(IOCTL_TO_DO_UNIX_OOB_IN_TCP_WAY)
	ioctl(net, asdf, asdf);		/* handle urgent data in band */
#endif	/* defined(IOCTL_TO_DO_UNIX_OOB_IN_TCP_WAY) */
E 42
I 42
D 44
#if	defined(xxxSO_OOBINLINE)
	setsockopt(net, SOL_SOCKET, SO_OOBINLINE, on, sizeof on);
#endif	/* defined(xxxSO_OOBINLINE) */
E 42
E 40
	if (telnetport && !hisopts[TELOPT_SGA]) {
E 38
E 32
		willoption(TELOPT_SGA);
E 44
I 44
#if	defined(SO_OOBINLINE)
	setsockopt(net, SOL_SOCKET, SO_OOBINLINE, &on, sizeof on);
#endif	/* defined(SO_OOBINLINE) */
	if (telnetport) {
	    if (!hisopts[TELOPT_SGA]) {
		willoption(TELOPT_SGA, 0);
	    }
	    if (!myopts[TELOPT_TTYPE]) {
		dooption(TELOPT_TTYPE, 0);
	    }
E 44
I 38
	}
E 38
E 29
	for (;;) {
D 38
		int ibits = 0, obits = 0;
E 38
I 38
D 39
		long ibits = 0, obits = 0, xbits = 0;
E 39
I 39
D 43
		fd_set ibits, obits, xbits;
E 39
E 38

E 43
D 39
		if (nfrontp - nbackp)
D 38
			obits |= (1 << s);
E 38
I 38
			obits |= (1 << net);
E 38
		else
			ibits |= (1 << tin);
		if (tfrontp - tbackp)
			obits |= (1 << tout);
		else
D 38
			ibits |= (1 << s);
E 38
I 38
			ibits |= (1 << net);
E 38
		if (scc < 0 && tcc < 0)
E 39
I 39
		if (scc < 0 && tcc < 0) {
E 39
			break;
D 12
		select(32, &ibits, &obits, INFINITY);
E 12
I 12
D 38
		select(16, &ibits, &obits, 0, 0);
E 12
		if (ibits == 0 && obits == 0) {
E 38
I 38
D 39
		if (flushing) {
			xbits = 0;
E 39
I 39
		}

D 43
		FD_ZERO(&ibits);
		FD_ZERO(&obits);
		FD_ZERO(&xbits);

E 43
D 42
		if (((globalmode < 4) || flushline) && (nfrontp - nbackp)) {
E 42
I 42
		if (((globalmode < 4) || flushline) && NETBYTES()) {
E 42
			FD_SET(net, &obits);
E 39
		} else {
D 39
			xbits = (1 << net);
E 39
I 39
			FD_SET(tin, &ibits);
E 39
		}
D 39
		select(16, &ibits, &obits, &xbits, 0);
		if (ibits == 0 && obits == 0 && xbits == 0) {
E 39
I 39
D 42
		if (tfrontp - tbackp) {
E 42
I 42
		if (TTYBYTES()) {
E 42
			FD_SET(tout, &obits);
		} else {
			FD_SET(net, &ibits);
		}
D 41
		if (!flushing) {
E 41
I 41
		if (!SYNCHing) {
E 41
			FD_SET(net, &xbits);
		}
D 41
		if ((c = select(16, &ibits, &obits, &xbits, 0)) < 1) {
E 41
I 41
		if ((c = select(16, &ibits, &obits, &xbits,
						(struct timeval *)0)) < 1) {
E 41
			if (c == -1) {
				/*
				 * we can get EINTR if we are in line mode,
				 * and the user does an escape (TSTP), or
				 * some other signal generator.
				 */
				if (errno == EINTR) {
					continue;
				}
			}
E 39
E 38
			sleep(5);
			continue;
		}

		/*
I 38
		 * Any urgent data?
		 */
D 39
		if (xbits) {
E 39
I 39
		if (FD_ISSET(net, &xbits)) {
I 43
		    FD_CLR(net, &xbits);
E 43
E 39
D 41
		    flushing = 1;
E 41
I 41
		    SYNCHing = 1;
E 41
		    ttyflush();	/* flush already enqueued data */
		}

		/*
E 38
		 * Something to read from the network...
		 */
D 38
		if (ibits & (1 << s)) {
D 11
			scc = read(s, sibuf, sizeof(sibuf));
E 11
I 11
			scc = read(s, sibuf, sizeof (sibuf));
E 38
I 38
D 39
		if (ibits & (1 << net)) {
E 39
I 39
		if (FD_ISSET(net, &ibits)) {
E 39
D 40
			scc = read(net, sibuf, sizeof (sibuf));
E 38
E 11
			if (scc < 0 && errno == EWOULDBLOCK)
				scc = 0;
			else {
				if (scc <= 0)
					break;
				sbp = sibuf;
I 37
D 38
				if (printnet) {
E 38
I 38
				if (netdata) {
E 38
					Dump('<', sbp, scc);
E 40
I 40
D 42
#if	!defined(IOCTL_TO_DO_UNIX_OOB_IN_TCP_WAY)
E 42
I 42
			int canread;

I 43
			FD_CLR(net, &ibits);
E 43
			if (scc == 0) {
			    sbp = sibuf;
			}
			canread = sibuf + sizeof sibuf - sbp;
D 44
#if	!defined(xxxSO_OOBINLINE)
E 44
I 44
#if	!defined(SO_OOBINLINE)
E 44
E 42
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
D 41
			 * stay in the TELNET SYNCH (flushing) state.
E 41
I 41
			 * stay in the TELNET SYNCH (SYNCHing) state.
E 41
			 * So, clocks to the rescue.  If we've "just"
			 * received a DM, then we test for the
			 * presence of OOB data when the receive OOB
			 * fails (and AFTER we did the normal mode read
			 * to clear "at the mark").
			 */
D 41
		    if (flushing) {
E 41
I 41
		    if (SYNCHing) {
E 41
			int atmark;

D 41
			ioctl(net, SIOCATMARK, &atmark);
E 41
I 41
			ioctl(net, SIOCATMARK, (char *)&atmark);
E 41
			if (atmark) {
D 42
			    scc = recv(net, sibuf, sizeof (sibuf), MSG_OOB);
			    if ((scc == -1) && (errno == EINVAL)) {
				scc = read(net, sibuf, sizeof (sibuf));
E 42
I 42
			    c = recv(net, sibuf, canread, MSG_OOB);
			    if ((c == -1) && (errno == EINVAL)) {
				c = read(net, sibuf, canread);
E 42
D 41
				if (times.didnetreceive < times.gotDM) {
				    flushing = stilloob();
E 41
I 41
				if (clocks.didnetreceive < clocks.gotDM) {
				    SYNCHing = stilloob(net);
E 41
E 40
				}
I 40
			    }
			} else {
D 42
			    scc = read(net, sibuf, sizeof (sibuf));
E 42
I 42
			    c = read(net, sibuf, canread);
E 42
E 40
E 37
			}
I 40
		    } else {
D 42
			scc = read(net, sibuf, sizeof (sibuf));
E 42
I 42
			c = read(net, sibuf, canread);
E 42
		    }
		    settimer(didnetreceive);
D 42
#else	/* !defined(IOCTL_TO_DO_UNIX_OOB_IN_TCP_WAY) */
		    scc = read(net, sibuf, sizeof (sibuf));
#endif	/* !defined(IOCTL_TO_DO_UNIX_OOB_IN_TCP_WAY) */
		    if (scc < 0 && errno == EWOULDBLOCK)
			scc = 0;
		    else {
			if (scc <= 0) {
			    break;
			}
			sbp = sibuf;
			if (netdata) {
			    Dump('<', sbp, scc);
			}
E 42
I 42
D 44
#else	/* !defined(xxxSO_OOBINLINE) */
E 44
I 44
#else	/* !defined(SO_OOBINLINE) */
E 44
		    c = read(net, sbp, canread);
D 44
#endif	/* !defined(xxxSO_OOBINLINE) */
E 44
I 44
#endif	/* !defined(SO_OOBINLINE) */
E 44
		    if (c < 0 && errno == EWOULDBLOCK) {
			c = 0;
		    } else if (c <= 0) {
			break;
E 42
		    }
I 42
		    if (netdata) {
			Dump('<', sbp, c);
		    }
		    scc += c;
E 42
E 40
		}

		/*
		 * Something to read from the tty...
		 */
D 39
		if (ibits & (1 << tin)) {
E 39
I 39
		if (FD_ISSET(tin, &ibits)) {
I 43
			FD_CLR(tin, &ibits);
E 43
E 39
D 11
			tcc = read(tin, tibuf, sizeof(tibuf));
E 11
I 11
D 42
			tcc = read(tin, tibuf, sizeof (tibuf));
E 11
			if (tcc < 0 && errno == EWOULDBLOCK)
				tcc = 0;
			else {
				if (tcc <= 0)
					break;
				tbp = tibuf;
E 42
I 42
			if (tcc == 0) {
			    tbp = tibuf;	/* nothing left, reset */
E 42
			}
I 42
			c = read(tin, tbp, tibuf+sizeof tibuf - tbp);
			if (c < 0 && errno == EWOULDBLOCK) {
				c = 0;
D 44
			} else if (c <= 0) {
				tcc = c;
				break;
E 44
I 44
			} else {
				/* EOF detection for line mode!!!! */
				if (c == 0 && globalmode >= 3) {
					/* must be an EOF... */
					*tbp = ntc.t_eofc;
					c = 1;
				}
				if (c <= 0) {
					tcc = c;
					break;
				}
E 44
			}
			tcc += c;
E 42
		}

		while (tcc > 0) {
D 41
			register int c;
E 41
I 41
			register int sc;
E 41

D 39
			if ((&netobuf[BUFSIZ] - nfrontp) < 2)
E 39
I 39
D 42
			if ((&netobuf[BUFSIZ] - nfrontp) < 2) {
E 42
I 42
			if (NETROOM() < 2) {
E 42
				flushline = 1;
E 39
				break;
I 39
			}
E 39
D 41
			c = *tbp++ & 0377, tcc--;
			if (strip(c) == escape) {
E 41
I 41
			c = *tbp++ & 0xff, sc = strip(c), tcc--;
			if (sc == escape) {
E 41
				command(0);
				tcc = 0;
I 39
				flushline = 1;
E 39
				break;
I 39
D 43
			} else if ((globalmode >= 4) && doechocharrecognition &&
D 41
							(strip(c) == echoc)) {
E 41
I 41
							(sc == echoc)) {
E 43
I 43
			} else if ((globalmode >= 4) && (sc == echoc)) {
E 43
E 41
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
E 39
			}
I 39
D 43
			if (localsigs) {
E 43
I 43
			if (localchars) {
E 43
D 41
				if (c == ntc.t_intrc) {
E 41
I 41
				if (sc == ntc.t_intrc) {
E 41
					intp();
					break;
D 41
				} else if (c == ntc.t_quitc) {
E 41
I 41
				} else if (sc == ntc.t_quitc) {
E 41
					sendbrk();
					break;
I 42
				} else if (sc == nltc.t_flushc) {
					NET2ADD(IAC, AO);
					if (autoflush) {
					    doflush();
					}
					break;
E 42
				} else if (globalmode > 2) {
					;
D 41
				} else if (c == nttyb.sg_kill) {
E 41
I 41
				} else if (sc == nttyb.sg_kill) {
E 41
					NET2ADD(IAC, EL);
					break;
D 41
				} else if (c == nttyb.sg_erase) {
E 41
I 41
				} else if (sc == nttyb.sg_erase) {
E 41
					NET2ADD(IAC, EC);
					break;
				}
			}
E 39
I 18
D 29
			if (c == IAC)
				*nfrontp++ = c;
E 18
			*nfrontp++ = c;
I 28
			if (c == '\r')
E 29
I 29
			switch (c) {
I 37
D 39
			case '\n'|0x80:
E 39
E 37
			case '\n':
I 37
				/*
D 47
				 * If echoing is happening locally,
				 * then a newline (unix) is CRLF (TELNET).
E 47
I 47
				 * If we are in CRMOD mode (\r ==> \n)
				 * on our local machine, then probably
				 * a newline (unix) is CRLF (TELNET).
E 47
				 */
E 37
D 38
				if (!hisopts[TELOPT_ECHO])
					*nfrontp++ = '\r';
E 29
				*nfrontp++ = '\n';
E 38
I 38
D 47
				if (!hisopts[TELOPT_ECHO]) {
E 47
I 47
				if (globalmode >= 3) {
E 47
					NETADD('\r');
				}
				NETADD('\n');
I 39
				flushline = 1;
E 39
E 38
I 29
				break;
I 37
D 39
			case '\r'|0x80:
E 39
E 37
			case '\r':
D 38
				*nfrontp++ = '\r';
D 37
				if (hisopts[TELOPT_ECHO])
					*nfrontp++ = '\n';
				else
					*nfrontp++ = '\0';
E 37
I 37
				*nfrontp++ = '\0';
E 38
I 38
				NET2ADD('\r', '\0');
I 39
				flushline = 1;
E 39
E 38
E 37
				break;
			case IAC:
D 38
				*nfrontp++ = IAC;
D 37
				/* fall into ... */
E 37
I 37
				*nfrontp++ = IAC;
E 38
I 38
				NET2ADD(IAC, IAC);
E 38
				break;
E 37
			default:
D 38
				*nfrontp++ = c;
E 38
I 38
				NETADD(c);
E 38
				break;
			}
E 29
E 28
		}
D 38
		if ((obits & (1 << s)) && (nfrontp - nbackp) > 0)
			netflush(s);
E 38
I 38
D 39
		if ((obits & (1 << net)) && (nfrontp - nbackp) > 0)
E 39
I 39
		if (((globalmode < 4) || flushline) &&
D 42
		    (FD_ISSET(net, &obits) && (nfrontp - nbackp) > 0)) {
E 42
I 42
		    FD_ISSET(net, &obits) && (NETBYTES() > 0)) {
I 43
			FD_CLR(net, &obits);
E 43
E 42
E 39
			netflush(net);
I 39
		}
E 39
E 38
		if (scc > 0)
			telrcv();
D 39
		if ((obits & (1 << tout)) && (tfrontp - tbackp) > 0)
E 39
I 39
D 42
		if (FD_ISSET(tout, &obits) && (tfrontp - tbackp) > 0)
E 42
I 42
D 43
		if (FD_ISSET(tout, &obits) && (TTYBYTES() > 0))
E 43
I 43
		if (FD_ISSET(tout, &obits) && (TTYBYTES() > 0)) {
			FD_CLR(tout, &obits);
E 43
E 42
E 39
D 38
			ttyflush(tout);
E 38
I 38
			ttyflush();
I 43
		}
E 43
E 38
	}
D 11
	mode(0);
E 11
I 11
D 39
	(void) mode(0);
E 39
I 39
	setcommandmode();
E 39
E 11
}
D 39

E 39
I 39

E 39
D 38
command(top)
	int top;
{
	register struct cmd *c;
	int oldmode, wasopen;

	oldmode = mode(0);
	if (!top)
		putchar('\n');
	else
D 20
		sigset(SIGINT, SIG_DFL);
E 20
I 20
		signal(SIGINT, SIG_DFL);
E 20
	for (;;) {
		printf("%s> ", prompt);
D 25
		if (gets(line) == 0)
E 25
I 25
		if (gets(line) == 0) {
D 34
			if (feof(stdin)) {
				clearerr(stdin);
				putchar('\n');
			}
E 34
I 34
			if (feof(stdin))
				quit();
E 34
E 25
			break;
I 25
		}
E 25
		if (line[0] == 0)
			break;
		makeargv();
		c = getcmd(margv[0]);
		if (c == (struct cmd *)-1) {
			printf("?Ambiguous command\n");
			continue;
		}
		if (c == 0) {
			printf("?Invalid command\n");
			continue;
		}
		(*c->handler)(margc, margv);
		if (c->handler != help)
			break;
	}
	if (!top) {
		if (!connected)
			longjmp(toplevel, 1);
D 11
		mode(oldmode);
E 11
I 11
		(void) mode(oldmode);
E 11
	}
}

E 38
/*
E 49
 * Telnet receiver states for fsm
 */
#define	TS_DATA		0
#define	TS_IAC		1
#define	TS_WILL		2
#define	TS_WONT		3
#define	TS_DO		4
#define	TS_DONT		5
I 37
#define	TS_CR		6
I 44
#define	TS_SB		7		/* sub-option collection */
#define	TS_SE		8		/* looking for sub-option end */
E 44
E 37

D 49
telrcv()
{
	register int c;
	static int state = TS_DATA;
E 49
I 49
static int	telrcv_state;
E 49

D 42
	while (scc > 0) {
E 42
I 42
D 49
	while ((scc > 0) && (TTYROOM() > 2)) {
E 42
D 41
		c = *sbp++ & 0377, scc--;
E 41
I 41
		c = *sbp++ & 0xff, scc--;
E 41
		switch (state) {
E 49
I 49
jmp_buf	toplevel = { 0 };
jmp_buf	peerdied;
E 49

I 37
D 49
		case TS_CR:
			state = TS_DATA;
D 42
			if ((c == '\0') || (c == '\n')) {
			    break;	/* by now, we ignore \n */
E 42
I 42
			if (c == '\0') {
			    break;	/* Ignore \0 after CR */
			} else if (c == '\n') {
			    if (hisopts[TELOPT_ECHO] && !crmod) {
				TTYADD(c);
			    }
			    break;
E 42
			}
I 42
			/* Else, fall through */
E 49
I 49
int	flushline;
E 49
E 42

E 37
D 49
		case TS_DATA:
D 15
			if (c == IAC)
E 15
I 15
			if (c == IAC) {
E 15
				state = TS_IAC;
D 15
			else
				*tfrontp++ = c;
E 15
I 15
				continue;
			}
I 42
			    /*
			     * The 'crmod' hack (see following) is needed
			     * since we can't * set CRMOD on output only.
			     * Machines like MULTICS like to send \r without
			     * \n; since we must turn off CRMOD to get proper
			     * input, the mapping is done here (sigh).
			     */
E 42
D 37
			*tfrontp++ = c;
			/*
			 * This hack is needed since we can't set
			 * CRMOD on output only.  Machines like MULTICS
			 * like to send \r without \n; since we must
			 * turn off CRMOD to get proper input, the mapping
			 * is done here (sigh).
			 */
			if (c == '\r' && crmod)
				*tfrontp++ = '\n';
E 37
I 37
			if (c == '\r') {
				if (scc > 0) {
D 41
					c = *sbp&0377;
E 41
I 41
					c = *sbp&0xff;
E 41
					if (c == 0) {
						sbp++, scc--;
I 42
						/* a "true" CR */
E 42
D 38
						*tfrontp++ = '\r';
E 38
I 38
						TTYADD('\r');
E 38
D 42
				/*
				 * The following hack is needed since we can't
				 * set CRMOD on output only.  Machines like
				 * MULTICS like to send \r without \n; since
				 * we must turn off CRMOD to get proper input,
				 * the mapping is done here (sigh).
				 */
						if (crmod) {
D 38
							*tfrontp++ = '\n';
E 38
I 38
							TTYADD('\n');
E 38
						}
E 42
					} else if (!hisopts[TELOPT_ECHO] &&
								(c == '\n')) {
						sbp++, scc--;
D 38
						*tfrontp++ = '\n';
E 38
I 38
						TTYADD('\n');
E 38
					} else {
D 38
						*tfrontp++ = '\r';
E 38
I 38
						TTYADD('\r');
I 42
						if (crmod) {
							TTYADD('\n');
						}
E 42
E 38
					}
				} else {
					state = TS_CR;
D 38
					*tfrontp++ = '\r';
E 38
I 38
					TTYADD('\r');
I 42
					if (crmod) {
						TTYADD('\n');
					}
E 42
E 38
				}
			} else {
D 38
				*tfrontp++ = c;
E 38
I 38
				TTYADD(c);
E 38
			}
E 37
E 15
			continue;
E 49
I 49
/*
 * The following are some clocks used to decide how to interpret
 * the relationship between various variables.
 */
E 49

D 49
		case TS_IAC:
			switch (c) {
			
			case WILL:
				state = TS_WILL;
				continue;
E 49
I 49
Clocks clocks;

Modelist modelist[] = {
	{ "telnet command mode", COMMAND_LINE },
	{ "character-at-a-time mode", 0 },
	{ "character-at-a-time mode (local echo)", LOCAL_ECHO|LOCAL_CHARS },
	{ "line-by-line mode (remote echo)", LINE | LOCAL_CHARS },
	{ "line-by-line mode", LINE | LOCAL_ECHO | LOCAL_CHARS },
	{ "line-by-line mode (local echoing suppressed)", LINE | LOCAL_CHARS },
	{ "3270 mode", 0 },
};
E 49

D 49
			case WONT:
				state = TS_WONT;
				continue;
E 49
I 49

/*
 * Initialize telnet environment.
 */
E 49

D 49
			case DO:
				state = TS_DO;
				continue;
E 49
I 49
init_telnet()
{
D 57
    /* Don't change telnetport */
E 57
    SB_CLEAR();
    ClearArray(hisopts);
    ClearArray(myopts);
D 51
    sbp = sibuf;
    tbp = tibuf;
E 51
I 51
D 53
    ring_init(&netiring, netibuf, sizeof netibuf);
    ring_init(&ttyiring, ttyibuf, sizeof ttyibuf);
E 53
E 51
E 49

D 49
			case DONT:
				state = TS_DONT;
				continue;
E 49
I 49
D 51
    connected = net = scc = tcc = In3270 = ISend = donebinarytoggle = 0;
E 51
I 51
D 54
    connected = net = In3270 = ISend = donebinarytoggle = 0;
E 54
I 54
    connected = In3270 = ISend = donebinarytoggle = 0;
E 54
E 51
D 57
    telnetport = 0;
E 57
E 49

D 49
			case DM:
D 38
				ioctl(fileno(stdout), TIOCFLUSH, 0);
E 38
I 38
				/*
				 * We may have missed an urgent notification,
				 * so make sure we flush whatever is in the
				 * buffer currently.
				 */
D 41
				flushing = 1;
E 41
I 41
				SYNCHing = 1;
E 41
				ttyflush();
D 41
				flushing = stilloob(net);
E 41
I 41
				SYNCHing = stilloob(net);
E 41
I 40
				settimer(gotDM);
E 40
E 38
				break;
E 49
I 49
#if	defined(unix) && defined(TN3270)
    HaveInput = 0;
#endif	/* defined(unix) && defined(TN3270) */
E 49

D 49
			case NOP:
			case GA:
				break;
E 49
I 49
    SYNCHing = 0;
E 49

I 44
D 49
			case SB:
				SB_CLEAR();
				state = TS_SB;
				continue;
E 49
I 49
D 53
    errno = 0;
E 49

E 53
E 44
D 49
			default:
				break;
			}
			state = TS_DATA;
			continue;
E 49
I 49
    /* Don't change NetTrace */
E 49

D 49
		case TS_WILL:
I 2
D 9
			if (showoptions)
D 5
				printoption("-->", will, c);
E 5
I 5
				printoption("-->", will, c, !hisopts[c]);
E 9
I 9
D 44
			printoption("RCVD", will, c, !hisopts[c]);
E 44
I 44
			printoption(">RCVD", will, c, !hisopts[c]);
E 44
E 9
E 5
E 2
D 39
			if (!hisopts[c])
E 39
I 39
			if (c == TELOPT_TM) {
				if (flushout) {
D 41
					flushout = 1;
E 41
I 41
					flushout = 0;
E 41
				}
			} else if (!hisopts[c]) {
E 39
D 44
				willoption(c);
E 44
I 44
				willoption(c, 1);
E 44
I 39
			}
E 39
			state = TS_DATA;
			continue;
E 49
I 49
    escape = CONTROL(']');
    echoc = CONTROL('E');
E 49

D 49
		case TS_WONT:
I 2
D 9
			if (showoptions)
D 5
				printoption("-->", wont, c);
E 5
I 5
				printoption("-->", wont, c, hisopts[c]);
E 9
I 9
D 44
			printoption("RCVD", wont, c, hisopts[c]);
E 44
I 44
			printoption(">RCVD", wont, c, hisopts[c]);
E 44
E 9
E 5
E 2
D 39
			if (hisopts[c])
E 39
I 39
			if (c == TELOPT_TM) {
				if (flushout) {
D 41
					flushout = 1;
E 41
I 41
					flushout = 0;
E 41
				}
			} else if (hisopts[c]) {
E 39
D 44
				wontoption(c);
E 44
I 44
				wontoption(c, 1);
E 44
I 39
			}
E 39
			state = TS_DATA;
			continue;
E 49
I 49
    flushline = 1;
    telrcv_state = TS_DATA;
}
I 54

E 54
E 49

I 54
#include <varargs.h>
E 54
D 49
		case TS_DO:
I 2
D 9
			if (showoptions)
D 5
				printoption("-->", doopt, c);
E 5
I 5
				printoption("-->", doopt, c, !myopts[c]);
E 9
I 9
D 44
			printoption("RCVD", doopt, c, !myopts[c]);
E 44
I 44
			printoption(">RCVD", doopt, c, !myopts[c]);
E 44
E 9
E 5
E 2
			if (!myopts[c])
				dooption(c);
			state = TS_DATA;
			continue;
E 49

I 54
static void
printring(va_alist)
va_dcl
{
    va_list ap;
    char buffer[100];		/* where things go */
    char *ptr;
    char *format;
    char *string;
    Ring *ring;
    int i;

    va_start(ap);

    ring = va_arg(ap, Ring *);
    format = va_arg(ap, char *);
    ptr = buffer;

    while ((i = *format++) != 0) {
	if (i == '%') {
	    i = *format++;
	    switch (i) {
	    case 'c':
		*ptr++ = va_arg(ap, int);
		break;
	    case 's':
		string = va_arg(ap, char *);
		ring_supply_data(ring, buffer, ptr-buffer);
		ring_supply_data(ring, string, strlen(string));
		ptr = buffer;
		break;
	    case 0:
		ExitString("printring: trailing %%.\n", 1);
		/*NOTREACHED*/
	    default:
		ExitString("printring: unknown format character.\n", 1);
		/*NOTREACHED*/
	    }
	} else {
	    *ptr++ = i;
	}
    }
    ring_supply_data(ring, buffer, ptr-buffer);
}


E 54
D 49
		case TS_DONT:
I 2
D 9
			if (showoptions)
D 5
				printoption("-->", dont, c);
E 5
I 5
				printoption("-->", dont, c, myopts[c]);
E 9
I 9
D 44
			printoption("RCVD", dont, c, myopts[c]);
E 44
I 44
			printoption(">RCVD", dont, c, myopts[c]);
E 44
E 9
E 5
E 2
			if (myopts[c]) {
				myopts[c] = 0;
				sprintf(nfrontp, wont, c);
D 11
				nfrontp += sizeof(wont) - 2;
E 11
I 11
				nfrontp += sizeof (wont) - 2;
I 39
				flushline = 1;
				setconnmode();	/* set new tty mode (maybe) */
E 39
E 11
I 2
D 9
				if (showoptions)
					printoption("<--", wont, c);
E 9
I 9
D 44
				printoption("SENT", wont, c);
E 44
I 44
				printoption(">SENT", wont, c);
E 44
E 9
E 2
			}
			state = TS_DATA;
			continue;
I 44
		case TS_SB:
			if (c == IAC) {
				state = TS_SE;
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
				state = TS_SB;
			} else {
				SB_TERM();
				suboption();	/* handle sub-option */
				state = TS_DATA;
			}
E 44
		}
	}
}
D 39

E 39
I 39

E 49
I 49
void
E 49
E 39
D 44
willoption(option)
	int option;
E 44
I 44
willoption(option, reply)
	int option, reply;
E 44
{
	char *fmt;

	switch (option) {

	case TELOPT_ECHO:
I 49
#	if defined(TN3270)
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
		if (askedSGA == 0) {
		    askedSGA = 1;
		    if (!hisopts[TELOPT_SGA]) {
			willoption(TELOPT_SGA, 0);
		    }
		}
	    }
		/* Fall through */
	case TELOPT_EOR:
	case TELOPT_BINARY:
#endif	/* defined(TN3270) */
E 49
D 11
		mode(1);
E 11
I 11
D 39
		(void) mode(1);
E 11

E 39
	case TELOPT_SGA:
I 39
		settimer(modenegotiated);
E 39
		hisopts[option] = 1;
		fmt = doopt;
I 39
		setconnmode();		/* possibly set new tty mode */
E 39
		break;

	case TELOPT_TM:
D 39
		fmt = dont;
		break;
E 39
I 39
		return;			/* Never reply to TM will's/wont's */
E 39

	default:
		fmt = dont;
		break;
	}
D 2
	sprintf(nfrontp, dont, option);
E 2
I 2
D 50
	sprintf(nfrontp, fmt, option);
E 2
D 11
	nfrontp += sizeof(dont) - 2;
E 11
I 11
	nfrontp += sizeof (dont) - 2;
E 50
I 50
D 54
	netoprint(fmt, option);
E 54
I 54
	printring(&netoring, fmt, option);
E 54
E 50
E 11
I 2
D 9
	if (showoptions)
		printoption("<--", fmt, option);
E 9
I 9
D 44
	printoption("SENT", fmt, option);
E 44
I 44
	if (reply)
D 49
		printoption(">SENT", fmt, option);
E 49
I 49
		printoption(">SENT", fmt, option, reply);
E 49
	else
D 49
		printoption("<SENT", fmt, option);
E 49
I 49
		printoption("<SENT", fmt, option, reply);
E 49
E 44
E 9
E 2
}

I 49
void
E 49
D 44
wontoption(option)
	int option;
E 44
I 44
wontoption(option, reply)
	int option, reply;
E 44
{
	char *fmt;

	switch (option) {

	case TELOPT_ECHO:
D 11
		mode(2);
E 11
I 11
D 39
		(void) mode(2);
E 11

E 39
	case TELOPT_SGA:
I 39
		settimer(modenegotiated);
E 39
		hisopts[option] = 0;
		fmt = dont;
I 39
		setconnmode();			/* Set new tty mode */
E 39
		break;

I 39
	case TELOPT_TM:
		return;		/* Never reply to TM will's/wont's */

E 39
	default:
		fmt = dont;
	}
D 50
	sprintf(nfrontp, fmt, option);
D 11
	nfrontp += sizeof(doopt) - 2;
E 11
I 11
	nfrontp += sizeof (doopt) - 2;
E 50
I 50
D 54
	netoprint(fmt, option);
E 54
I 54
	printring(&netoring, fmt, option);
E 54
E 50
E 11
I 2
D 9
	if (showoptions)
		printoption("<--", fmt, option);
E 9
I 9
D 44
	printoption("SENT", fmt, option);
E 44
I 44
	if (reply)
D 49
		printoption(">SENT", fmt, option);
E 49
I 49
		printoption(">SENT", fmt, option, reply);
E 49
	else
D 49
		printoption("<SENT", fmt, option);
E 49
I 49
		printoption("<SENT", fmt, option, reply);
E 49
E 44
E 9
E 2
}

I 49
static void
E 49
dooption(option)
	int option;
{
	char *fmt;

	switch (option) {

	case TELOPT_TM:
D 39
		fmt = wont;
		break;

I 22
	case TELOPT_ECHO:
		(void) mode(2);
E 39
		fmt = will;
D 39
		hisopts[option] = 0;
E 39
		break;

I 49
#	if defined(TN3270)
	case TELOPT_EOR:
	case TELOPT_BINARY:
#	endif	/* defined(TN3270) */
E 49
I 44
	case TELOPT_TTYPE:		/* terminal type option */
E 44
E 22
D 39
	case TELOPT_SGA:
E 39
I 39
	case TELOPT_SGA:		/* no big deal */
E 39
		fmt = will;
I 39
		myopts[option] = 1;
E 39
		break;

I 39
	case TELOPT_ECHO:		/* We're never going to echo... */
E 39
	default:
		fmt = wont;
		break;
	}
D 50
	sprintf(nfrontp, fmt, option);
D 11
	nfrontp += sizeof(doopt) - 2;
E 11
I 11
	nfrontp += sizeof (doopt) - 2;
E 50
I 50
D 54
	netoprint(fmt, option);
E 54
I 54
	printring(&netoring, fmt, option);
E 54
E 50
E 11
I 2
D 9
	if (showoptions)
		printoption("<--", fmt, option);
E 9
I 9
D 44
	printoption("SENT", fmt, option);
E 44
I 44
D 49
	printoption(">SENT", fmt, option);
E 49
I 49
	printoption(">SENT", fmt, option, 0);
E 49
E 44
E 9
E 2
}
I 44

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

I 49
static void
E 49
suboption()
{
I 49
    printsub("<", subbuffer, subend-subbuffer+1);
E 49
    switch (subbuffer[0]&0xff) {
    case TELOPT_TTYPE:
	if ((subbuffer[1]&0xff) != TELQUAL_SEND) {
	    ;
	} else {
	    char *name;
	    char namebuf[41];
D 49
	    char *getenv();
E 49
I 49
	    extern char *getenv();
E 49
	    int len;

I 49
#if	defined(TN3270)
D 53
	    /*
	     * Try to send a 3270 type terminal name.  Decide which one based
	     * on the format of our screen, and (in the future) color
	     * capaiblities.
	     */
#if	defined(unix)
	    if (initscr() != ERR) {	/* Initialize curses to get line size */
		MaxNumberLines = LINES;
		MaxNumberColumns = COLS;
	    }
#else	/* defined(unix) */
	    InitTerminal();
#endif	/* defined(unix) */
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
D 50
		    ExitString(stderr,
			"Programming error:  MAXSCREENSIZE too small.\n", 1);
E 50
I 50
		    ExitString("Programming error:  MAXSCREENSIZE too small.\n",
									1);
E 50
		    /*NOTREACHED*/
		}
D 50
		memcpy(nfrontp, sb_terminal, sizeof sb_terminal);
		printsub(">", nfrontp+2, sizeof sb_terminal-2);
		nfrontp += sizeof sb_terminal;
E 50
I 50
		printsub(">", sb_terminal+2, sizeof sb_terminal-2);
D 52
		ring_add_data(&netoring, sb_terminal, sizeof sb_terminal);
E 52
I 52
		ring_supply_data(&netoring, sb_terminal, sizeof sb_terminal);
E 53
I 53
	    if (tn3270_ttype()) {
E 53
E 52
E 50
		return;
	    }
#endif	/* defined(TN3270) */
D 53

E 53
E 49
	    name = getenv("TERM");
	    if ((name == 0) || ((len = strlen(name)) > 40)) {
		name = "UNKNOWN";
I 59
		len = strlen(name);
E 59
	    }
	    if ((len + 4+2) < NETROOM()) {
		strcpy(namebuf, name);
		upcase(namebuf);
D 50
		sprintf(nfrontp, "%c%c%c%c%s%c%c", IAC, SB, TELOPT_TTYPE,
E 50
I 50
D 54
		netoprint("%c%c%c%c%s%c%c", IAC, SB, TELOPT_TTYPE,
E 54
I 54
		printring(&netoring, "%c%c%c%c%s%c%c", IAC, SB, TELOPT_TTYPE,
E 54
E 50
				    TELQUAL_IS, namebuf, IAC, SE);
I 49
D 50
		printsub(">", nfrontp+2, 4+strlen(namebuf)+2-2-2);
E 49
		nfrontp += 4+strlen(namebuf)+2;
E 50
I 50
		/* XXX */
		/* printsub(">", nfrontp+2, 4+strlen(namebuf)+2-2-2); */
E 50
I 49
	    } else {
D 50
		ExitString(stderr, "No room in buffer for terminal type.\n",
E 50
I 50
		ExitString("No room in buffer for terminal type.\n",
E 50
							1);
		/*NOTREACHED*/
E 49
	    }
	}

    default:
	break;
    }
}
E 44
D 39

E 39
I 39
D 49

E 39
/*
D 38
 * Set the escape character.
E 38
I 38
D 41
 * Check to see if any out-of-band data exists on a socket (for
 * Telnet "synch" processing).
E 38
 */
D 38
setescape(argc, argv)
	int argc;
	char *argv[];
{
	register char *arg;
	char buf[50];
E 38

D 38
	if (argc > 2)
		arg = argv[1];
	else {
		printf("new escape character: ");
		gets(buf);
		arg = buf;
	}
	if (arg[0] != '\0')
		escape = arg[0];
	printf("Escape character is '%s'.\n", control(escape));
I 15
	fflush(stdout);
E 15
}

I 2
/*VARARGS*/
setoptions()
E 38
I 38
int
stilloob(s)
int	s;		/* socket number */
E 38
{
I 38
D 40
    struct timeval *timeout = { 0 };
    long	excepts = (1<<s);
E 40
I 40
    static struct timeval timeout = { 0 };
    fd_set	excepts;
    int value;
E 40
E 38
I 15

E 15
D 38
	showoptions = !showoptions;
D 32
	printf("%s show option processing.\n", showoptions ? "Will" : "Wont");
E 32
I 32
	printf("%s show option processing.\n", showoptions ? "Will" : "Won't");
E 32
I 15
	fflush(stdout);
E 38
I 38
D 40
    if (select(s+1, 0, 0, &excepts, timeout) < 0) {
E 40
I 40
    do {
	FD_ZERO(&excepts);
	FD_SET(s, &excepts);
	value = select(s+1, 0, 0, &excepts, &timeout);
    } while ((value >= 0) || ((value == -1) && (errno = EINTR)));

    if (value < 0) {
E 40
	perror("select");
	quit();
    }
D 40
    if (excepts) {
E 40
I 40
    if (FD_ISSET(s, &excepts)) {
E 40
	return 1;
    } else {
	return 0;
    }
E 38
}

D 38
/*VARARGS*/
setcrmod()
{

	crmod = !crmod;
D 32
	printf("%s map carriage return on output.\n", crmod ? "Will" : "Wont");
E 32
I 32
	printf("%s map carriage return on output.\n", crmod ? "Will" : "Won't");
E 32
I 16
	fflush(stdout);
}

/*VARARGS*/
setdebug()
{

D 27
	debug = !debug;
E 27
I 27
	debug = debug ? 0 : 1;
E 27
	printf("%s turn on socket level debugging.\n",
D 32
		debug ? "Will" : "Wont");
E 32
I 32
		debug ? "Will" : "Won't");
E 32
E 16
	fflush(stdout);
I 18
D 26
	if (debug && setsockopt(net, SOL_SOCKET, SO_DEBUG, 0, 0) < 0)
E 26
I 26
D 27
	if (debug && net > 0 && setsockopt(net, SOL_SOCKET, SO_DEBUG, 0, 0) < 0)
E 27
I 27
	if (net > 0 &&
	    setsockopt(net, SOL_SOCKET, SO_DEBUG, &debug, sizeof(debug)) < 0)
E 27
E 26
		perror("setsockopt (SO_DEBUG)");
I 29
}

I 37
/*VARARGS*/
static
setprintnet()
{

	printnet = !printnet;
	printf("%s turn on printing of raw network traffic.\n",
		printnet ? "Will" : "Wont");
}

E 37
sendesc()
{
	*nfrontp++ = escape;
}

ayt()
{
	*nfrontp++ = IAC;
	*nfrontp++ = AYT;
}

intp()
{
	*nfrontp++ = IAC;
	*nfrontp++ = IP;
E 29
E 18
E 15
}

E 38
E 2
/*
 * Construct a control character sequence
 * for a special character.
 */
char *
control(c)
	register int c;
{
	static char buf[3];

	if (c == 0177)
		return ("^?");
	if (c >= 040) {
		buf[0] = c;
		buf[1] = 0;
	} else {
		buf[0] = '^';
		buf[1] = '@'+c;
		buf[2] = 0;
	}
	return (buf);
}

D 38
struct cmd *
getcmd(name)
	register char *name;
{
	register char *p, *q;
	register struct cmd *c, *found;
	register int nmatches, longest;

	longest = 0;
	nmatches = 0;
	found = 0;
	for (c = cmdtab; p = c->name; c++) {
		for (q = name; *q == *p++; q++)
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
		return ((struct cmd *)-1);
	return (found);
}

E 38
D 39
deadpeer()
{
D 20
	sigset(SIGPIPE, deadpeer);
E 20
D 11
	mode(0);
E 11
I 11
	(void) mode(0);
E 11
	longjmp(peerdied, -1);
}

intr()
{
D 20
	sigset(SIGINT, intr);
E 20
D 11
	mode(0);
E 11
I 11
	(void) mode(0);
E 11
	longjmp(toplevel, -1);
}

E 39
D 38
ttyflush(fd)
E 38
I 38
ttyflush()
E 38
{
D 38
	int n;
E 38
I 38
    int n;
E 38

D 38
	if ((n = tfrontp - tbackp) > 0)
		n = write(fd, tbackp, n);
D 9
	if (n < 0 && errno == EWOULDBLOCK)
		n = 0;
E 9
I 9
	if (n < 0)
		return;
E 9
	tbackp += n;
	if (tbackp == tfrontp)
		tbackp = tfrontp = ttyobuf;
E 38
I 38
    if ((n = tfrontp - tbackp) > 0) {
	if (!flushing) {
	    n = write(tout, tbackp, n);
	} else {
	    ioctl(fileno(stdout), TIOCFLUSH, 0);
	}
    }
    if (n < 0) {
	return;
    }
    tbackp += n;
    if (tbackp == tfrontp) {
	tbackp = tfrontp = ttyobuf;
    }
E 38
}

netflush(fd)
{
D 38
	int n;
E 38
I 38
    int n;
E 38

D 38
	if ((n = nfrontp - nbackp) > 0)
		n = write(fd, nbackp, n);
D 7
	if (n < 0 && errno == EWOULDBLOCK)
E 7
I 7
	if (n < 0) {
		if (errno != ENOBUFS && errno != EWOULDBLOCK) {
D 11
			mode(0);
E 11
I 11
			(void) mode(0);
E 11
D 9
			perror(host_name);
E 9
I 9
D 10
			perror(host->h_name);
E 10
I 10
			perror(hostname);
E 10
E 9
			close(fd);
			longjmp(peerdied, -1);
			/*NOTREACHED*/
		}
E 7
		n = 0;
E 38
I 38
    if ((n = nfrontp - nbackp) > 0) {
	if (!neturg) {
	    n = write(fd, nbackp, n);	/* normal write */
	} else {
	    n = neturg - nbackp;
D 40
	    n = send(fd, nbackp, n, MSG_OOB);	/* URGENT data (SYNCH) */
E 40
I 40
	    /*
	     * In 4.2 (and 4.3) systems, there is some question about
	     * what byte in a sendOOB operation is the "OOB" data.
	     * To make ourselves compatible, we only send ONE byte
	     * out of band, the one WE THINK should be OOB (though
	     * we really have more the TCP philosophy of urgent data
	     * rather than the Unix philosophy of OOB data).
	     */
	    if (n > 1) {
		n = send(fd, nbackp, n-1, 0);	/* send URGENT all by itself */
	    } else {
		n = send(fd, nbackp, n, MSG_OOB);	/* URGENT data */
	    }
E 40
E 38
I 7
	}
I 37
D 38
	if (printnet) {
		Dump('>', nbackp, n);
E 38
I 38
    }
    if (n < 0) {
	if (errno != ENOBUFS && errno != EWOULDBLOCK) {
D 39
	    (void) mode(0);
E 39
I 39
	    setcommandmode();
E 39
	    perror(hostname);
	    close(fd);
	    neturg = 0;
	    longjmp(peerdied, -1);
	    /*NOTREACHED*/
E 38
	}
E 37
E 7
D 38
	nbackp += n;
	if (nbackp == nfrontp)
		nbackp = nfrontp = netobuf;
E 38
I 38
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
E 38
I 2
}
I 37

static
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

E 37

D 5
printoption(direction, fmt, option)
E 5
I 5
/*VARARGS*/
printoption(direction, fmt, option, what)
E 5
	char *direction, *fmt;
D 5
	int option;
E 5
I 5
	int option, what;
E 5
{
I 9
	if (!showoptions)
		return;
E 9
	printf("%s ", direction);
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
	if (option < TELOPT_SUPDUP)
D 5
		printf("%s %s\r\n", fmt, telopts[option]);
E 5
I 5
		printf("%s %s", fmt, telopts[option]);
E 5
	else
D 5
		printf("%s %d\r\n", fmt, option);
E 5
I 5
		printf("%s %d", fmt, option);
	if (*direction == '<') {
		printf("\r\n");
		return;
	}
	printf(" (%s)\r\n", what ? "reply" : "don't reply");
I 38
}

/*
E 41
 *	The following are data structures and routines for
 *	the "send" command.
 *
 */
 
struct sendlist {
    char	*name;		/* How user refers to it (case independent) */
    int		what;		/* Character to be sent (<0 ==> special) */
    char	*help;		/* Help information (0 ==> no help) */
    int		(*routine)();	/* Routine to perform (for special ops) */
};
E 49
D 53

I 41
D 49
/*ARGSUSED*/
E 41
dosynch(s)
struct sendlist *s;
E 49
I 49
#if	defined(TN3270)
static void
SetIn3270()
E 49
{
D 43
    /* XXX We really should purge the buffer to the network */
E 43
I 43
D 49
    netclear();			/* clear the path to the network */
E 43
    NET2ADD(IAC, DM);
D 41
    neturg = NETLOC();
E 41
I 41
    neturg = NETLOC()-1;	/* Some systems are off by one XXX */
E 41
}

I 42
doflush()
{
D 43
    /* This shouldn't really be here... */
E 43
    NET2ADD(IAC, DO);
    NETADD(TELOPT_TM);
D 44
    printoption("SENT", doopt, TELOPT_TM);
E 44
    flushline = 1;
    flushout = 1;
    ttyflush();
I 44
    /* do printoption AFTER flush, otherwise the output gets tossed... */
    printoption("<SENT", doopt, TELOPT_TM);
E 44
}

E 42
D 41
sendesc()
{
D 39
	NETADD(escape);
E 39
I 39
    NETADD(escape);
E 39
}

ayt()
{
D 39
	NET2ADD(IAC, AYT);
E 39
I 39
    NET2ADD(IAC, AYT);
E 39
}

E 41
intp()
{
D 39
	NET2ADD(IAC, IP);
E 39
I 39
    NET2ADD(IAC, IP);
I 42
    if (autoflush) {
	doflush();
E 49
I 49
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
E 49
    }
D 49
    if (autosynch) {
	dosynch();
    }
E 49
E 42
E 39
}
I 49
#endif	/* defined(TN3270) */
E 53

E 49

I 39
D 49
sendbrk()
E 49
I 49
D 51
static void
E 51
I 51
D 61
static int
E 61
I 61
int
E 61
E 51
telrcv()
E 49
{
I 41
D 42
#if	0
    /*
     * There is a question here.  Should we send a TM to flush the stream?
     * Should we also send a TELNET SYNCH also?
     */
E 41
    *nfrontp++ = IAC;
    *nfrontp++ = DO;
    *nfrontp++ = TELOPT_TM;
    flushout = 1;
D 41
    *nfrontp++ = IAC;
    *nfrontp++ = BREAK;
    flushline = 1;
E 41
    printoption("SENT", doopt, TELOPT_TM);
I 41
#endif	/* 0 */
E 42
D 49
    NET2ADD(IAC, BREAK);
D 42
    flushline = 1;
E 42
I 42
    if (autoflush) {
	doflush();
    }
    if (autosynch) {
	dosynch();
    }
E 42
E 41
}
E 49
I 49
    register int c;
D 51
    static int telrcv_state = TS_DATA;
#   if defined(TN3270)
    register int Scc;
    register char *Sbp;
#   endif /* defined(TN3270) */
E 51
I 51
    register int scc;
    register char *sbp;
    int count;
    int returnValue = 0;
E 51
E 49
E 39

I 49
D 51
    while ((scc > 0) && (TTYROOM() > 2)) {
	c = *sbp++ & 0xff, scc--;
E 51
I 51
    scc = 0;
    count = 0;
    while (TTYROOM() > 2) {
	if (scc == 0) {
	    if (count) {
D 52
		ring_sent_acked(&netiring, count);
E 52
I 52
		ring_consumed(&netiring, count);
E 52
		returnValue = 1;
		count = 0;
	    }
D 52
	    sbp = netiring.send;
	    scc = ring_unsent_consecutive(&netiring);
E 52
I 52
	    sbp = netiring.consume;
	    scc = ring_full_consecutive(&netiring);
E 52
	    if (scc == 0) {
		/* No more data coming in */
		break;
	    }
	}

	c = *sbp++ & 0xff, scc--; count++;

E 51
	switch (telrcv_state) {
E 49
I 39

E 39
D 49
#define	SENDQUESTION	-1
D 43
#define	SEND2QUESTION	-2
E 43
#define	SENDESCAPE	-3
E 49
I 49
	case TS_CR:
	    telrcv_state = TS_DATA;
	    if (c == '\0') {
		break;	/* Ignore \0 after CR */
	    } else if (c == '\n') {
D 55
		if (hisopts[TELOPT_ECHO] && !crmod) {
E 55
I 55
		if ((!hisopts[TELOPT_ECHO]) && !crmod) {
E 55
		    TTYADD(c);
		}
		break;
	    }
	    /* Else, fall through */
E 49

D 49
struct sendlist Sendlist[] = {
D 43
    { "synch", SYNCH, "Perform Telnet 'Synch operation'", dosynch },
    { "brk", BREAK, "Send Telnet Break" },
	{ "break", BREAK, 0 },
    { "ip", IP, "Send Telnet Interrupt Process" },
	{ "intp", IP, 0 },
	{ "interrupt", IP, 0 },
	{ "intr", IP, 0 },
E 43
    { "ao", AO, "Send Telnet Abort output" },
D 43
	{ "abort", AO, 0 },
E 43
    { "ayt", AYT, "Send Telnet 'Are You There'" },
D 43
	{ "are", AYT, 0 },
	{ "hello", AYT, 0 },
E 43
I 43
    { "brk", BREAK, "Send Telnet Break" },
E 43
    { "ec", EC, "Send Telnet Erase Character" },
    { "el", EL, "Send Telnet Erase Line" },
I 43
    { "escape", SENDESCAPE, "Send current escape character" },
E 43
    { "ga", GA, "Send Telnet 'Go Ahead' sequence" },
D 43
	{ "go", GA, 0 },
E 43
I 43
    { "ip", IP, "Send Telnet Interrupt Process" },
E 43
    { "nop", NOP, "Send Telnet 'No operation'" },
D 43
    { "escape", SENDESCAPE, "Send current escape character" },
E 43
I 43
    { "synch", SYNCH, "Perform Telnet 'Synch operation'", dosynch },
E 43
    { "?", SENDQUESTION, "Display send options" },
D 43
	{ "help", SENDQUESTION, 0 },
    { "??", SEND2QUESTION, "Display all send options (including aliases)" },
E 43
    { 0 }
};
E 49
I 49
	case TS_DATA:
	    if (c == IAC) {
		telrcv_state = TS_IAC;
D 61
		continue;
E 61
I 61
		break;
E 61
	    }
#	    if defined(TN3270)
	    if (In3270) {
		*Ifrontp++ = c;
D 51
		Sbp = sbp;
		Scc = scc;
		while (Scc > 0) {
		    c = *Sbp++ & 0377, Scc--;
E 51
I 51
		while (scc > 0) {
		    c = *sbp++ & 0377, scc--; count++;
E 51
		    if (c == IAC) {
			telrcv_state = TS_IAC;
D 61
			break;
E 61
I 61
D 62
			continue;
E 62
I 62
			break;
E 62
E 61
		    }
		    *Ifrontp++ = c;
		}
D 51
		sbp = Sbp;
		scc = Scc;
E 51
	    } else
#	    endif /* defined(TN3270) */
		    /*
		     * The 'crmod' hack (see following) is needed
		     * since we can't * set CRMOD on output only.
		     * Machines like MULTICS like to send \r without
		     * \n; since we must turn off CRMOD to get proper
		     * input, the mapping is done here (sigh).
		     */
	    if ((c == '\r') && !hisopts[TELOPT_BINARY]) {
		if (scc > 0) {
		    c = *sbp&0xff;
		    if (c == 0) {
D 51
			sbp++, scc--;
E 51
I 51
			sbp++, scc--; count++;
E 51
			/* a "true" CR */
			TTYADD('\r');
		    } else if (!hisopts[TELOPT_ECHO] &&
					(c == '\n')) {
D 51
			sbp++, scc--;
E 51
I 51
			sbp++, scc--; count++;
E 51
			TTYADD('\n');
		    } else {
			TTYADD('\r');
			if (crmod) {
				TTYADD('\n');
			}
		    }
		} else {
		    telrcv_state = TS_CR;
		    TTYADD('\r');
		    if (crmod) {
			    TTYADD('\n');
		    }
		}
	    } else {
		TTYADD(c);
	    }
	    continue;
E 49

I 43
D 49
struct sendlist Sendlist2[] = {		/* some synonyms */
	{ "break", BREAK, 0 },
E 49
I 49
	case TS_IAC:
	    switch (c) {
	    
	    case WILL:
		telrcv_state = TS_WILL;
		continue;
E 49

D 49
	{ "intp", IP, 0 },
	{ "interrupt", IP, 0 },
	{ "intr", IP, 0 },
E 49
I 49
	    case WONT:
		telrcv_state = TS_WONT;
		continue;
E 49

D 49
	{ "help", SENDQUESTION, 0 },
E 49
I 49
	    case DO:
		telrcv_state = TS_DO;
		continue;
E 49

D 49
	{ 0 }
};
E 49
I 49
	    case DONT:
		telrcv_state = TS_DONT;
		continue;
E 49

E 43
D 49
char **
getnextsend(name)
char *name;
{
    struct sendlist *c = (struct sendlist *) name;
E 49
I 49
	    case DM:
		    /*
		     * We may have missed an urgent notification,
		     * so make sure we flush whatever is in the
		     * buffer currently.
		     */
		SYNCHing = 1;
		ttyflush(1);
D 54
		SYNCHing = stilloob(net);
E 54
I 54
		SYNCHing = stilloob();
E 54
		settimer(gotDM);
		break;
E 49

D 49
    return (char **) (c+1);
}
E 49
I 49
	    case NOP:
	    case GA:
		break;
E 49

D 49
struct sendlist *
getsend(name)
char *name;
{
D 43
    return (struct sendlist *) genget(name, (char **) Sendlist, getnextsend);
E 43
I 43
    struct sendlist *sl;
E 49
I 49
	    case SB:
		SB_CLEAR();
		telrcv_state = TS_SB;
		continue;
E 49

D 49
    if (sl = (struct sendlist *)
				genget(name, (char **) Sendlist, getnextsend)) {
	return sl;
    } else {
	return (struct sendlist *)
				genget(name, (char **) Sendlist2, getnextsend);
    }
E 43
}

sendcmd(argc, argv)
int	argc;
char	**argv;
{
    int what;		/* what we are sending this time */
    int count;		/* how many bytes we are going to need to send */
    int hadsynch;	/* are we going to process a "synch"? */
    int i;
I 43
    int question = 0;	/* was at least one argument a question */
E 43
    struct sendlist *s;	/* pointer to current command */

    if (argc < 2) {
	printf("need at least one argument for 'send' command\n");
	printf("'send ?' for help\n");
D 43
	return;
E 43
I 43
	return 0;
E 43
    }
    /*
     * First, validate all the send arguments.
     * In addition, we see how much space we are going to need, and
     * whether or not we will be doing a "SYNCH" operation (which
     * flushes the network queue).
     */
    count = 0;
    hadsynch = 0;
    for (i = 1; i < argc; i++) {
	s = getsend(argv[i]);
	if (s == 0) {
	    printf("Unknown send argument '%s'\n'send ?' for help.\n",
			argv[i]);
D 43
	    return;
E 43
I 43
	    return 0;
E 43
D 41
	} else if (s == (struct sendlist *) -1) {
E 41
I 41
	} else if (s == Ambiguous(struct sendlist *)) {
E 41
	    printf("Ambiguous send argument '%s'\n'send ?' for help.\n",
			argv[i]);
D 43
	    return;
E 43
I 43
	    return 0;
E 43
	}
	switch (s->what) {
	case SENDQUESTION:
D 43
	case SEND2QUESTION:
E 43
	    break;
	case SENDESCAPE:
	    count += 1;
	    break;
	case SYNCH:
	    hadsynch = 1;
	    count += 2;
	    break;
	default:
	    count += 2;
	    break;
	}
    }
    /* Now, do we have enough room? */
D 42
    if (netobuf+sizeof netobuf-nfrontp-1 < count) {
E 42
I 42
    if (NETROOM() < count) {
E 42
	printf("There is not enough room in the buffer TO the network\n");
	printf("to process your request.  Nothing will be done.\n");
	printf("('send synch' will throw away most data in the network\n");
	printf("buffer, if this might help.)\n");
D 43
	return;
E 43
I 43
	return 0;
E 43
    }
    /* OK, they are all OK, now go through again and actually send */
    for (i = 1; i < argc; i++) {
	if (!(s = getsend(argv[i]))) {
	    fprintf(stderr, "Telnet 'send' error - argument disappeared!\n");
	    quit();
	    /*NOTREACHED*/
	}
	if (s->routine) {
	    (*s->routine)(s);
	} else {
	    switch (what = s->what) {
I 43
	    case SYNCH:
		dosynch();
		break;
E 43
	    case SENDQUESTION:
D 43
	    case SEND2QUESTION:
E 43
		for (s = Sendlist; s->name; s++) {
D 43
		    if (s->help || (what == SEND2QUESTION)) {
E 43
I 43
		    if (s->help) {
E 43
			printf(s->name);
			if (s->help) {
			    printf("\t%s", s->help);
			}
			printf("\n");
E 49
I 49
#	    if defined(TN3270)
	    case EOR:
		if (In3270) {
		    Ibackp += DataFromNetwork(Ibackp, Ifrontp-Ibackp, 1);
		    if (Ibackp == Ifrontp) {
			Ibackp = Ifrontp = Ibuf;
			ISend = 0;	/* should have been! */
		    } else {
			ISend = 1;
E 49
		    }
		}
I 43
D 49
		question = 1;
E 49
E 43
		break;
D 49
	    case SENDESCAPE:
		NETADD(escape);
E 49
I 49
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
E 49
		break;
I 49

E 49
	    default:
D 49
		NET2ADD(IAC, what);
E 49
		break;
	    }
D 49
	}
    }
I 43
    return !question;
E 43
}

/*
 * The following are the routines and data structures referred
 * to by the arguments to the "toggle" command.
 */
E 49
I 49
	    telrcv_state = TS_DATA;
	    continue;
E 49

I 39
D 43
lclsigs()
E 43
I 43
D 49
lclchars()
E 43
{
D 41
    localsigs = !localsigs;
    printf("%s recognize interrupt/quit characters.\n",
					localsigs ? "Will" : "Won't");
E 41
D 43
    donelclsigs = 1;
E 43
I 43
    donelclchars = 1;
    return 1;
E 43
D 41
    fflush(stdout);
E 41
}
E 49
I 49
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
	    telrcv_state = TS_DATA;
	    continue;
E 49

D 41
localecho()
{
    doechocharrecognition = !doechocharrecognition;
    printf("%s recognize echo toggle character.\n",
				doechocharrecognition ? "Will" : "Won't");
    fflush(stdout);
}

E 41
D 43
/*VARARGS*/
D 40
setcrmod()
E 40
I 40
togcrmod()
E 40
{
D 41

E 41
    crmod = !crmod;
I 41
    printf("Deprecated usage - please use 'toggle crmod' in the future.\n");
E 41
    printf("%s map carriage return on output.\n", crmod ? "Will" : "Won't");
    fflush(stdout);
}

E 43
E 39
D 40
setdebug()
E 40
I 40
D 49
togdebug()
E 40
{
I 44
#ifndef	NOT43
E 44
D 41

D 39
	debug = debug ? 0 : 1;
	printf("%s turn on socket level debugging.\n",
		debug ? "Will" : "Won't");
	fflush(stdout);
	if (net > 0 &&
	    setsockopt(net, SOL_SOCKET, SO_DEBUG, &debug, sizeof(debug)) < 0)
		perror("setsockopt (SO_DEBUG)");
E 39
I 39
    debug = debug ? 0 : 1;
    printf("%s turn on socket level debugging.\n",
	    debug ? "Will" : "Won't");
    fflush(stdout);
E 41
    if (net > 0 &&
D 41
	setsockopt(net, SOL_SOCKET, SO_DEBUG, &debug, sizeof(debug)) < 0)
E 41
I 41
	setsockopt(net, SOL_SOCKET, SO_DEBUG, (char *)&debug, sizeof(debug))
									< 0) {
E 41
	    perror("setsockopt (SO_DEBUG)");
I 41
    }
I 44
#else	NOT43
    if (debug) {
	if (net > 0 && setsockopt(net, SOL_SOCKET, SO_DEBUG, 0, 0) < 0)
	    perror("setsockopt (SO_DEBUG)");
    } else
	printf("Cannot turn off socket debugging\n");
#endif	NOT43
E 44
I 43
    return 1;
E 43
E 41
E 39
}
E 49
I 49
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
	    telrcv_state = TS_DATA;
	    continue;
E 49

I 49
	case TS_DO:
	    printoption(">RCVD", doopt, c, !myopts[c]);
	    if (!myopts[c])
		dooption(c);
	    SetIn3270();
	    telrcv_state = TS_DATA;
	    continue;
E 49
D 41
static
D 40
setnetdata()
E 40
I 40
tognetdata()
E 40
{
E 41

I 49
	case TS_DONT:
	    printoption(">RCVD", dont, c, myopts[c]);
	    if (myopts[c]) {
		myopts[c] = 0;
D 50
		sprintf(nfrontp, wont, c);
		nfrontp += sizeof (wont) - 2;
E 50
I 50
D 54
		netoprint(wont, c);
E 54
I 54
		printring(&netoring, wont, c);
E 54
E 50
		flushline = 1;
		setconnmode();	/* set new tty mode (maybe) */
		printoption(">SENT", wont, c, 0);
	    }
	    SetIn3270();
	    telrcv_state = TS_DATA;
	    continue;
E 49
D 39
	netdata = !netdata;
	printf("%s turn on printing of raw network traffic.\n",
		netdata ? "Will" : "Wont");
E 39
I 39
D 41
    netdata = !netdata;
    printf("%s turn on printing of raw network traffic.\n",
	    netdata ? "Will" : "Wont");
E 39
}
E 41

D 40
setoptions()
E 40
I 40
D 41
togoptions()
E 40
{

D 39
	showoptions = !showoptions;
	printf("%s show option processing.\n", showoptions ? "Will" : "Won't");
	fflush(stdout);
E 39
I 39
    showoptions = !showoptions;
    printf("%s show option processing.\n", showoptions ? "Will" : "Won't");
    fflush(stdout);
E 39
}

E 41
D 49
int togglehelp();
E 49
I 49
	case TS_SB:
	    if (c == IAC) {
		telrcv_state = TS_SE;
	    } else {
		SB_ACCUM(c);
	    }
	    continue;
E 49

I 39
D 43
char	crmodhelp[] =	"toggle mapping of received carriage returns";

E 43
E 39
D 40
struct cmd togglelist[] = {
D 39
    { "debug", "toggle debugging", setdebug, 1 },
    { "options", "toggle viewing of options processing", setoptions, 1 },
    { "netdata", "toggle printing of hexadecimal network data",
							setnetdata, 1 },
E 39
I 39
    { "localchars", "toggle local recognition of control characters",
								lclsigs, 1 },
    { "echochar", "toggle recognition of echo toggle character", localecho, 1 },
    { "crmod",	crmodhelp,	setcrmod, 1, 0 },
E 40
I 40
D 49
struct togglelist {
    char	*name;		/* name of toggle */
    char	*help;		/* help message */
D 41
    int	(*handler)();	/* routine to do actual setting */
E 41
I 41
    int		(*handler)();	/* routine to do actual setting */
E 41
    int		dohelp;		/* should we display help information */
    int		*variable;
    char	*actionexplanation;
};

struct togglelist Togglelist[] = {
D 43
    { "localchars",
	"toggle local recognition of control characters",
	    lclsigs,
		1,
		    &localsigs,
			"recognize interrupt/quit characters" },
    { "echochar",
	"toggle recognition of echo toggle character",
E 43
I 43
    { "autoflush",
	"toggle flushing of output when sending interrupt characters",
E 43
D 41
	    localecho,
E 41
I 41
	    0,
E 41
		1,
D 43
		    &doechocharrecognition,
			"recognize echo toggle character" },
E 43
I 43
		    &autoflush,
			"flush output when sending interrupt characters" },
E 43
I 41
    { "autosynch",
	"toggle automatic sending of interrupt characters in urgent mode",
	    0,
		1,
		    &autosynch,
			"send interrupt characters in urgent mode" },
I 42
D 43
    { "autoflush",
	"toggle automatic flushing of output when sending interrupt characters",
	    0,
		1,
		    &autoflush,
			"flush output when sending interrupt characters" },
E 43
E 42
E 41
    { "crmod",
D 43
	crmodhelp,
E 43
I 43
	"toggle mapping of received carriage returns",
E 43
D 41
	    togcrmod,
E 41
I 41
	    0,
E 41
		1,
		    &crmod,
			"map carriage return on output" },
I 43
    { "localchars",
	"toggle local recognition of certain control characters",
	    lclchars,
		1,
		    &localchars,
			"recognize certain control characters" },
E 43
E 40
    { " ", "", 0, 1 },		/* empty line */
D 40
    { "debug", "(debugging) toggle debugging", setdebug, 1 },
    { "options", "(debugging) toggle viewing of options processing",
								setoptions, 1 },
    { "netdata", "(debugging) toggle printing of hexadecimal network data",
								setnetdata, 1 },
E 39
    { "?", "display help information", togglehelp, 1 },
    { "help", "display help information", togglehelp, 0 },
E 40
I 40
    { "debug",
	"(debugging) toggle debugging",
	    togdebug,
		1,
		    &debug,
			"turn on socket level debugging" },
D 43
    { "options",
	"(debugging) toggle viewing of options processing",
D 41
	    togoptions,
E 41
I 41
	    0,
E 41
		1,
		    &showoptions,
			"show option processing" },
E 43
    { "netdata",
	"(debugging) toggle printing of hexadecimal network data",
D 41
	    tognetdata,
E 41
I 41
	    0,
E 41
		1,
		    &netdata,
			"print hexadecimal representation of network traffic" },
I 43
    { "options",
	"(debugging) toggle viewing of options processing",
	    0,
		1,
		    &showoptions,
			"show option processing" },
    { " ", "", 0, 1 },		/* empty line */
E 43
    { "?",
	"display help information",
	    togglehelp,
		1 },
    { "help",
	"display help information",
	    togglehelp,
		0 },
E 40
    { 0 }
};

togglehelp()
{
D 40
    struct cmd *c;
E 40
I 40
    struct togglelist *c;
E 40

D 40
    for (c = togglelist; c->name; c++) {
E 40
I 40
    for (c = Togglelist; c->name; c++) {
E 40
	if (c->dohelp) {
	    printf("%s\t%s\n", c->name, c->help);
E 49
I 49
	case TS_SE:
	    if (c != SE) {
		if (c != IAC) {
		    SB_ACCUM(IAC);
		}
		SB_ACCUM(c);
		telrcv_state = TS_SB;
	    } else {
		SB_TERM();
		suboption();	/* handle sub-option */
		SetIn3270();
		telrcv_state = TS_DATA;
	    }
E 49
	}
    }
I 51
D 52
    ring_sent_acked(&netiring, count);
E 52
I 52
D 56
    ring_consumed(&netiring, count);
E 56
I 56
    if (count)
	ring_consumed(&netiring, count);
E 56
E 52
    return returnValue||count;
E 51
I 43
D 49
    return 0;
E 49
E 43
}
I 51

static int
D 54
telsnd(ring)
Ring	*ring;			/* Input ring */
E 54
I 54
telsnd()
E 54
{
    int tcc;
    int count;
    int returnValue = 0;
    char *tbp;

    tcc = 0;
    count = 0;
    while (NETROOM() > 2) {
	register int sc;
	register int c;

	if (tcc == 0) {
	    if (count) {
D 52
		ring_sent_acked(&ttyiring, count);
E 52
I 52
		ring_consumed(&ttyiring, count);
E 52
		returnValue = 1;
		count = 0;
	    }
D 52
	    tbp = ttyiring.send;
	    tcc = ring_unsent_consecutive(&ttyiring);
E 52
I 52
	    tbp = ttyiring.consume;
	    tcc = ring_full_consecutive(&ttyiring);
E 52
	    if (tcc == 0) {
		break;
	    }
	}
	c = *tbp++ & 0xff, sc = strip(c), tcc--; count++;
	if (sc == escape) {
	    command(0);
	    tcc = 0;
	    flushline = 1;
	    break;
	} else if (MODE_LINE(globalmode) && (sc == echoc)) {
	    if (tcc > 0 && strip(*tbp) == echoc) {
		tcc--; tbp++; count++;
	    } else {
		dontlecho = !dontlecho;
		settimer(echotoggle);
		setconnmode();
		flushline = 1;
		break;
	    }
	}
	if (localchars) {
	    if (TerminalSpecialChars(sc) == 0) {
		break;
	    }
	}
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
		if (!crlf) {
		    NET2ADD('\r', '\0');
		} else {
		    NET2ADD('\r', '\n');
		}
		flushline = 1;
		break;
	    case IAC:
		NET2ADD(IAC, IAC);
		break;
	    default:
		NETADD(c);
		break;
	    }
	} else if (c == IAC) {
	    NET2ADD(IAC, IAC);
	} else {
	    NETADD(c);
	}
    }
D 52
    ring_sent_acked(&ttyiring, count);
E 52
I 52
D 56
    ring_consumed(&ttyiring, count);
E 56
I 56
    if (count)
	ring_consumed(&ttyiring, count);
E 56
E 52
    return returnValue||count;		/* Non-zero if we did anything */
}
E 51
D 49

char **
getnexttoggle(name)
char *name;
E 49
I 49

D 53
#if	defined(TN3270)
static void
SetForExit()
E 49
{
D 40
    struct cmd *c = (struct cmd *) name;
E 40
I 40
D 49
    struct togglelist *c = (struct togglelist *) name;
E 40

    return (char **) (c+1);
E 49
I 49
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
E 49
}

D 40
struct cmd *
E 40
I 40
D 49
struct togglelist *
E 40
gettoggle(name)
char *name;
E 49
I 49
static void
Exit(returnCode)
int returnCode;
E 49
{
D 40
    return (struct cmd *) genget(name, (char **) togglelist, getnexttoggle);
E 40
I 40
D 49
    return (struct togglelist *)
			genget(name, (char **) Togglelist, getnexttoggle);
E 49
I 49
    SetForExit();
    exit(returnCode);
E 49
E 40
}

D 49
toggle(argc, argv)
int	argc;
char	*argv[];
E 49
I 49
void
D 50
ExitString(file, string, returnCode)
FILE *file;
E 50
I 50
ExitString(string, returnCode)
E 50
char *string;
int returnCode;
E 49
{
I 43
D 49
    int retval = 1;
E 43
    char *name;
D 40
    struct cmd *c;
E 40
I 40
    struct togglelist *c;
E 49
I 49
    SetForExit();
D 50
    fwrite(string, 1, strlen(string), file);
E 50
I 50
    fwrite(string, 1, strlen(string), stderr);
E 50
    exit(returnCode);
}
E 49
E 40

D 49
    if (argc < 2) {
	fprintf(stderr,
	    "Need an argument to 'toggle' command.  'toggle ?' for help.\n");
D 43
	return;
E 43
I 43
	return 0;
E 43
    }
    argc--;
    argv++;
    while (argc--) {
	name = *argv++;
	c = gettoggle(name);
D 40
	if (c == (struct cmd *) -1) {
E 40
I 40
D 41
	if (c == (struct togglelist *) -1) {
E 41
I 41
	if (c == Ambiguous(struct togglelist *)) {
E 41
E 40
	    fprintf(stderr, "'%s': ambiguous argument ('toggle ?' for help).\n",
					name);
I 43
	    return 0;
E 43
	} else if (c == 0) {
	    fprintf(stderr, "'%s': unknown argument ('toggle ?' for help).\n",
					name);
I 43
	    return 0;
E 43
	} else {
D 41
	    (*c->handler)(c);
E 41
I 41
	    if (c->variable) {
		*c->variable = !*c->variable;		/* invert it */
		printf("%s %s.\n", *c->variable? "Will" : "Won't",
							c->actionexplanation);
	    }
	    if (c->handler) {
D 43
		(*c->handler)(c);
E 43
I 43
		retval &= (*c->handler)(c);
E 43
	    }
E 41
	}
    }
I 43
    return retval;
E 49
I 49
void
ExitPerror(string, returnCode)
char *string;
int returnCode;
{
    SetForExit();
    perror(string);
    exit(returnCode);
E 49
E 43
}
I 49
#endif	/* defined(TN3270) */

E 49

E 53
/*
I 39
D 49
 * The following perform the "set" command.
E 49
I 49
 * Scheduler()
 *
 * Try to do something.
 *
 * If we do something useful, return 1; else return 0.
 *
E 49
 */

D 40
struct chartab {
    char *label;			/* name */
E 40
I 40
D 49
struct setlist {
    char *name;				/* name */
E 40
    char *help;				/* help information */
    char *charp;			/* where it is located at */
};
E 49

D 40
struct chartab Chartab[] = {
E 40
I 40
D 49
struct setlist Setlist[] = {
E 40
    { "echo", 	"character to toggle local echoing on/off", &echoc },
    { "escape",	"character to escape back to telnet command mode", &escape },
I 42
D 43
    { "\200", "" },
    { "\200", "The following need 'localsigs' to be toggled true", 0 },
E 42
    { "interrupt", "character to cause an Interrupt Process", &ntc.t_intrc },
    { "quit",	"character to cause a Break", &ntc.t_quitc },
I 42
    { "flush output", "character to cause an Abort Oubput", &nltc.t_flushc },
E 43
I 43
    { " ", "" },
    { " ", "The following need 'localchars' to be toggled true", 0 },
E 43
E 42
    { "erase",	"character to cause an Erase Character", &nttyb.sg_erase },
I 43
    { "flushoutput", "character to cause an Abort Oubput", &nltc.t_flushc },
    { "interrupt", "character to cause an Interrupt Process", &ntc.t_intrc },
E 43
    { "kill",	"character to cause an Erase Line", &nttyb.sg_kill },
I 43
    { "quit",	"character to cause a Break", &ntc.t_quitc },
I 44
    { "eof",	"character to cause an EOF ", &ntc.t_eofc },
E 44
E 43
    { 0 }
};

char **
D 40
getnextchar(name)
E 40
I 40
getnextset(name)
E 40
char *name;
E 49
I 49
int
Scheduler(block)
int	block;			/* should we block in the select ? */
E 49
{
D 40
    struct chartab *c = (struct chartab *)name;
E 40
I 40
D 49
    struct setlist *c = (struct setlist *)name;
E 49
I 49
    register int c;
		/* One wants to be a bit careful about setting returnValue
		 * to one, since a one implies we did some useful work,
		 * and therefore probably won't be called to block next
		 * time (TN3270 mode only).
		 */
D 53
    int returnValue = 0;
    static struct timeval TimeValue = { 0 };
E 53
I 53
    int returnValue;
    int netin, netout, netex, ttyin, ttyout;
E 53
E 49
E 40

D 49
    return (char **) (c+1);
}

D 40
struct chartab *
getchartab(name)
E 40
I 40
struct setlist *
getset(name)
E 40
char *name;
{
D 40
    return (struct chartab *) genget(name, (char **) Chartab, getnextchar);
E 40
I 40
    return (struct setlist *) genget(name, (char **) Setlist, getnextset);
E 40
}

setcmd(argc, argv)
int	argc;
char	*argv[];
{
    int value;
D 40
    struct chartab *ct;
E 40
I 40
    struct setlist *ct;
E 40

    /* XXX back we go... sigh */
    if (argc != 3) {
D 43
	printf("Format is 'set Name Value', where 'Name' is one of:\n\n");
D 40
	for (ct = Chartab; ct->label; ct++) {
	    printf("%s\t%s\n", ct->label, ct->help);
E 40
I 40
	for (ct = Setlist; ct->name; ct++) {
	    printf("%s\t%s\n", ct->name, ct->help);
E 43
I 43
	if ((argc == 2) &&
		    ((!strcmp(argv[1], "?")) || (!strcmp(argv[1], "help")))) {
	    for (ct = Setlist; ct->name; ct++) {
		printf("%s\t%s\n", ct->name, ct->help);
	    }
	    printf("?\tdisplay help information\n");
	} else {
	    printf("Format is 'set Name Value'\n'set ?' for help.\n");
E 43
E 40
	}
D 43
	return;
E 43
I 43
	return 0;
E 49
I 49
D 51
    if (scc < 0 && tcc < 0) {
	return -1;
E 49
E 43
    }

E 51
D 40
    ct = getchartab(argv[1]);
E 40
I 40
D 49
    ct = getset(argv[1]);
E 40
    if (ct == 0) {
	fprintf(stderr, "'%s': unknown argument ('set ?' for help).\n",
			argv[1]);
I 43
	return 0;
E 43
D 40
    } else if (ct == (struct chartab *) -1) {
E 40
I 40
D 41
    } else if (ct == (struct setlist *) -1) {
E 41
I 41
    } else if (ct == Ambiguous(struct setlist *)) {
E 41
E 40
	fprintf(stderr, "'%s': ambiguous argument ('set ?' for help).\n",
			argv[1]);
I 43
	return 0;
E 43
    } else {
	if (strcmp("off", argv[2])) {
	    value = special(argv[2]);
	} else {
	    value = -1;
	}
	*(ct->charp) = value;
D 40
	printf("%s character is '%s'.\n", ct->label, control(*(ct->charp)));
E 40
I 40
	printf("%s character is '%s'.\n", ct->name, control(*(ct->charp)));
E 49
I 49
D 53
    if ((!MODE_LINE(globalmode) || flushline) && NETBYTES()) {
	FD_SET(net, &obits);
    } 
#if	!defined(MSDOS)
    if (TTYBYTES()) {
	FD_SET(tout, &obits);
E 49
E 40
    }
E 53
I 53
    /* Decide which rings should be processed */

    netout = ring_full_count(&netoring) &&
	    (!MODE_LINE(globalmode) || flushline || myopts[TELOPT_BINARY]);
    ttyout = ring_full_count(&ttyoring);

E 53
I 43
D 49
    return 1;
E 43
}

/*
 * The following are the data structures and routines for the
 * 'mode' command.
 */

dolinemode()
{
    if (hisopts[TELOPT_SGA]) {
D 41
	wontoption(TELOPT_SGA, 0);
E 41
I 41
D 44
	wontoption(TELOPT_SGA);
E 44
I 44
	wontoption(TELOPT_SGA, 0);
E 49
I 49
#if	defined(TN3270)
D 53
    if ((tcc == 0) && NETROOM() && (shell_active == 0)) {
	FD_SET(tin, &ibits);
E 49
E 44
E 41
    }
E 53
I 53
    ttyin = ring_empty_count(&ttyiring) && (shell_active == 0);
E 53
D 49
    if (hisopts[TELOPT_ECHO]) {
D 41
	wontoption(TELOPT_ECHO, 0);
E 41
I 41
D 44
	wontoption(TELOPT_ECHO);
E 44
I 44
	wontoption(TELOPT_ECHO, 0);
E 49
I 49
#else	/* defined(TN3270) */
D 51
    if ((tcc == 0) && NETROOM()) {
E 51
I 51
D 53
    if (ring_empty_count(&netiring) && NETROOM()) {
E 51
	FD_SET(tin, &ibits);
E 49
E 44
E 41
    }
E 53
I 53
    ttyin = ring_empty_count(&ttyiring);
E 53
D 49
}

docharmode()
{
    if (!hisopts[TELOPT_SGA]) {
D 41
	willoption(TELOPT_SGA, 0);
E 41
I 41
D 44
	willoption(TELOPT_SGA);
E 44
I 44
	willoption(TELOPT_SGA, 0);
E 49
I 49
#endif	/* defined(TN3270) */
D 53
#endif	/* !defined(MSDOS) */
#   if !defined(TN3270)
    if (TTYROOM()) {
	FD_SET(net, &ibits);
E 49
E 44
E 41
    }
E 53
I 53

#if	defined(TN3270)
    netin = ring_empty_count(&netiring);
E 53
D 49
    if (!hisopts[TELOPT_ECHO]) {
D 41
	willoption(TELOPT_ECHO, 0);
E 41
I 41
D 44
	willoption(TELOPT_ECHO);
E 44
I 44
	willoption(TELOPT_ECHO, 0);
E 49
I 49
#   else /* !defined(TN3270) */
D 53
    if (!ISend && TTYROOM()) {
	FD_SET(net, &ibits);
E 49
E 44
E 41
    }
E 53
I 53
    netin = !ISend && ring_empty_count(&netiring);
E 53
D 49
}

struct cmd Modelist[] = {
D 43
    { "line",		"line-by-line mode",		dolinemode, 1, 1 },
E 43
    { "character",	"character-at-a-time mode",	docharmode, 1, 1 },
I 43
    { "line",		"line-by-line mode",		dolinemode, 1, 1 },
E 43
    { 0 },
};

char **
getnextmode(name)
char *name;
{
    struct cmd *c = (struct cmd *) name;

    return (char **) (c+1);
}

struct cmd *
getmodecmd(name)
char *name;
{
    return (struct cmd *) genget(name, (char **) Modelist, getnextmode);
}

modecmd(argc, argv)
int	argc;
char	*argv[];
{
    struct cmd *mt;

    if ((argc != 2) || !strcmp(argv[1], "?") || !strcmp(argv[1], "help")) {
	printf("format is:  'mode Mode', where 'Mode' is one of:\n\n");
	for (mt = Modelist; mt->name; mt++) {
	    printf("%s\t%s\n", mt->name, mt->help);
E 49
I 49
#   endif /* !defined(TN3270) */
D 53
    if (!SYNCHing) {
	FD_SET(net, &xbits);
    }
E 53
I 53

    netex = !SYNCHing;

    /* If we have seen a signal recently, reset things */
E 53
#   if defined(TN3270) && defined(unix)
    if (HaveInput) {
	HaveInput = 0;
	signal(SIGIO, inputAvailable);
    }
#endif	/* defined(TN3270) && defined(unix) */
D 53
    if ((c = select(16, &ibits, &obits, &xbits,
			block? (struct timeval *)0 : &TimeValue)) < 0) {
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
E 49
	}
D 43
	return;
E 43
I 43
	return 0;
E 43
    }
E 53
D 49
    mt = getmodecmd(argv[1]);
    if (mt == 0) {
	fprintf(stderr, "Unknown mode '%s' ('mode ?' for help).\n", argv[1]);
I 43
	return 0;
E 43
D 41
    } else if (mt == (struct cmd *) -1) {
E 41
I 41
    } else if (mt == Ambiguous(struct cmd *)) {
E 41
	fprintf(stderr, "Ambiguous mode '%s' ('mode ?' for help).\n", argv[1]);
I 43
	return 0;
E 43
    } else {
	(*mt->handler)();
E 49
I 49

D 53
    /*
     * Any urgent data?
     */
    if (FD_ISSET(net, &xbits)) {
	FD_CLR(net, &xbits);
	SYNCHing = 1;
	ttyflush(1);	/* flush already enqueued data */
E 49
    }
E 53
I 53
    /* Call to system code to process rings */
E 53
I 43
D 49
    return 1;
E 43
}

/*
I 40
 * The following data structures and routines implement the
 * "display" command.
 */
E 49

D 49
display(argc, argv)
int	argc;
char	*argv[];
{
#define	dotog(tl)	if (tl->variable && tl->actionexplanation) { \
			    if (*tl->variable) { \
				printf("will"); \
			    } else { \
				printf("won't"); \
			    } \
			    printf(" %s.\n", tl->actionexplanation); \
			}
E 49
I 49
D 53
    /*
     * Something to read from the network...
     */
    if (FD_ISSET(net, &ibits)) {
	int canread;
E 53
I 53
    returnValue = process_rings(netin, netout, netex, ttyin, ttyout, !block);
E 53
E 49

D 43
#define	doset(sl)	printf("[%s]\t%s.\n", control(*sl->charp), sl->name);
E 43
I 43
D 49
#define	doset(sl)   if (sl->name && *sl->name != ' ') { \
			printf("[%s]\t%s.\n", control(*sl->charp), sl->name); \
E 49
I 49
D 53
	FD_CLR(net, &ibits);
D 51
	if (scc == 0) {
	    sbp = sibuf;
	}
	canread = sibuf + sizeof sibuf - (sbp+scc);
E 51
I 51
	canread = ring_empty_consecutive(&netiring);
E 51
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
E 53
I 53
    /* Now, look at the input rings, looking for work to do. */
E 53

D 53
	    ioctl(net, SIOCATMARK, (char *)&atmark);
	    if (atmark) {
		c = recv(net, sbp+scc, canread, MSG_OOB);
		if ((c == -1) && (errno == EINVAL)) {
		    c = recv(net, sbp+scc, canread, 0);
		    if (clocks.didnetreceive < clocks.gotDM) {
			SYNCHing = stilloob(net);
E 49
		    }
I 49
		}
	    } else {
		c = recv(net, sbp+scc, canread, 0);
	    }
	} else {
	    c = recv(net, sbp+scc, canread, 0);
	}
	settimer(didnetreceive);
#else	/* !defined(SO_OOBINLINE) */
D 51
	c = recv(net, sbp+scc, canread, 0);
E 51
I 51
D 52
	c = recv(net, netiring.add, canread, 0);
E 52
I 52
	c = recv(net, netiring.supply, canread, 0);
E 52
E 51
#endif	/* !defined(SO_OOBINLINE) */
	if (c < 0 && errno == EWOULDBLOCK) {
	    c = 0;
	} else if (c <= 0) {
	    return -1;
	}
	if (netdata) {
D 51
	    Dump('<', sbp+scc, c);
E 51
I 51
D 52
	    Dump('<', netiring.add, c);
E 52
I 52
	    Dump('<', netiring.supply, c);
E 52
E 51
	}
D 51
	scc += c;
E 51
I 51
D 52
	ring_added(&netiring, c);
E 52
I 52
	ring_supplied(&netiring, c);
E 52
E 51
	returnValue = 1;
    }
E 49
E 43

D 49
    struct togglelist *tl;
    struct setlist *sl;

    if (argc == 1) {
	for (tl = Togglelist; tl->name; tl++) {
	    dotog(tl);
E 49
I 49
    /*
     * Something to read from the tty...
     */
#if	defined(MSDOS)
    if ((tcc == 0) && NETROOM() && (shell_active == 0) && TerminalCanRead())
#else	/* defined(MSDOS) */
    if (FD_ISSET(tin, &ibits))
#endif	/* defined(MSDOS) */
				    {
	FD_CLR(tin, &ibits);
D 51
	if (tcc == 0) {
	    tbp = tibuf;	/* nothing left, reset */
E 49
	}
I 43
D 49
	printf("\n");
E 43
	for (sl = Setlist; sl->name; sl++) {
	    doset(sl);
E 49
I 49
	c = TerminalRead(tin, tbp, tibuf+sizeof tibuf - tbp);
E 51
I 51
D 52
	c = TerminalRead(tin, ttyiring.add, ring_empty_consecutive(&ttyiring));
E 52
I 52
	c = TerminalRead(tin, ttyiring.supply,
			ring_empty_consecutive(&ttyiring));
E 52
E 51
	if (c < 0 && errno == EWOULDBLOCK) {
	    c = 0;
	} else {
#if	defined(unix)
	    /* EOF detection for line mode!!!! */
	    if (c == 0 && MODE_LOCAL_CHARS(globalmode)) {
			/* must be an EOF... */
D 51
		*tbp = termEofChar;
E 51
I 51
D 52
		*ttyiring.add = termEofChar;
E 52
I 52
		*ttyiring.supply = termEofChar;
E 52
E 51
		c = 1;
	    }
#endif	/* defined(unix) */
	    if (c <= 0) {
D 51
		tcc = c;
E 51
		return -1;
	    }
E 49
	}
D 49
    } else {
	int i;
E 49
I 49
D 51
	tcc += c;
E 51
I 51
D 52
	ring_added(&ttyiring, c);
E 52
I 52
	ring_supplied(&ttyiring, c);
E 52
E 51
	returnValue = 1;		/* did something useful */
    }
E 49

D 49
	for (i = 1; i < argc; i++) {
	    sl = getset(argv[i]);
	    tl = gettoggle(argv[i]);
D 41
	    if ((tl && sl) || (sl == (struct setlist *) -1) ||
				(tl == (struct togglelist *) -1)) {
E 41
I 41
	    if ((sl == Ambiguous(struct setlist *)) ||
				(tl == Ambiguous(struct togglelist *))) {
E 41
		printf("?Ambiguous argument '%s'.\n", argv[i]);
I 43
		return 0;
E 43
	    } else if (!sl && !tl) {
		printf("?Unknown argument '%s'.\n", argv[i]);
I 43
		return 0;
E 43
D 41
	    } else if (tl) {
		dotog(tl);
E 41
	    } else {
D 41
		doset(sl);
E 41
I 41
		if (tl) {
		    dotog(tl);
E 49
I 49
#   if defined(TN3270)
E 53
D 51
    if (tcc > 0) {
E 51
I 51
D 52
    if (ring_unsent_count(&ttyiring)) {
E 52
I 52
    if (ring_full_count(&ttyiring)) {
I 53
#   if defined(TN3270)
E 53
E 52
E 51
	if (In3270) {
D 51
	    c = DataFromTerminal(tbp, tcc);
E 51
I 51
D 61
	    c = DataFromTerminal(ttyiring.send,
E 61
I 61
	    c = DataFromTerminal(ttyiring.consume,
E 61
D 52
					ring_unsent_consecutive(&ttyiring));
E 52
I 52
					ring_full_consecutive(&ttyiring));
E 52
E 51
	    if (c) {
		returnValue = 1;
I 56
	        ring_consumed(&ttyiring, c);
E 56
	    }
D 51
	    tcc -= c;
	    tbp += c;
E 51
I 51
D 52
	    ring_sent_acked(&ttyiring, c);
E 52
I 52
D 56
	    ring_consumed(&ttyiring, c);
E 56
E 52
E 51
	} else {
#   endif /* defined(TN3270) */
D 51
	    returnValue = 1;
	    while (tcc > 0) {
		register int sc;

		if (NETROOM() < 2) {
		    flushline = 1;
		    break;
E 49
		}
D 49
		if (sl) {
		    doset(sl);
E 49
I 49
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
E 49
		}
I 49
		if (localchars) {
		    if (TerminalSpecialChars(sc) == 0) {
			break;
		    }
		}
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
			if (!crlf) {
			    NET2ADD('\r', '\0');
			} else {
			    NET2ADD('\r', '\n');
			}
			flushline = 1;
			break;
		    case IAC:
			NET2ADD(IAC, IAC);
			break;
		    default:
			NETADD(c);
			break;
		    }
		} else if (c == IAC) {
		    NET2ADD(IAC, IAC);
		} else {
		    NETADD(c);
		}
E 49
E 41
	    }
E 51
I 51
D 54
	    returnValue |= telsnd(&ttyiring);
E 54
I 54
	    returnValue |= telsnd();
E 54
E 51
I 49
#   if defined(TN3270)
E 49
	}
D 53
    }
E 53
I 43
D 49
    return 1;
E 43
#undef	doset(sl)
#undef	dotog(tl)
E 49
I 49
#   endif /* defined(TN3270) */
D 53

    if ((!MODE_LINE(globalmode) || flushline || myopts[TELOPT_BINARY]) &&
	FD_ISSET(net, &obits) && (NETBYTES() > 0)) {
	FD_CLR(net, &obits);
	returnValue = netflush();
E 53
    }
I 53

E 53
D 51
    if (scc > 0) {
E 51
I 51
D 52
    if (ring_unsent_count(&netiring)) {
E 52
I 52
    if (ring_full_count(&netiring)) {
E 52
E 51
#	if !defined(TN3270)
D 51
	telrcv();
	returnValue = 1;
E 51
I 51
	returnValue |= telrcv();
E 51
#	else /* !defined(TN3270) */
	returnValue = Push3270();
#	endif /* !defined(TN3270) */
    }
D 53
#if	defined(MSDOS)
    if (TTYBYTES())
#else	/* defined(MSDOS) */
    if (FD_ISSET(tout, &obits) && (TTYBYTES() > 0))
#endif	/* defined(MSDOS) */
						    {
	FD_CLR(tout, &obits);
	returnValue = ttyflush(SYNCHing|flushout);
    }
E 53
    return returnValue;
E 49
}

/*
E 40
E 39
D 49
 * The following are the data structures, and many of the routines,
 * relating to command processing.
E 49
I 49
 * Select from tty and network...
E 49
 */
D 49

/*
 * Set the escape character.
 */
setescape(argc, argv)
	int argc;
	char *argv[];
E 49
I 49
void
telnet()
E 49
{
D 49
	register char *arg;
	char buf[50];
E 49
I 49
D 53
#if	defined(MSDOS)
#define	SCHED_BLOCK	0		/* Don't block in MSDOS */
#else	/* defined(MSDOS) */
#define	SCHED_BLOCK	1
#endif	/* defined(MSDOS) */
E 53
I 53
    sys_telnet_init();
E 53
E 49

I 41
D 49
	printf(
	    "Deprecated usage - please use 'set escape%s%s' in the future.\n",
				(argc > 2)? " ":"", (argc > 2)? argv[1]: "");
E 41
	if (argc > 2)
		arg = argv[1];
	else {
		printf("new escape character: ");
		gets(buf);
		arg = buf;
	}
	if (arg[0] != '\0')
		escape = arg[0];
	printf("Escape character is '%s'.\n", control(escape));
	fflush(stdout);
I 43
	return 1;
E 43
}
E 49
I 49
D 53
#if	defined(TN3270) && defined(unix)
    int myPid;
#endif	/* defined(TN3270) */
E 49

D 49
/*VARARGS*/
I 43
togcrmod()
{
    crmod = !crmod;
    printf("Deprecated usage - please use 'toggle crmod' in the future.\n");
    printf("%s map carriage return on output.\n", crmod ? "Will" : "Won't");
    fflush(stdout);
    return 1;
}
E 49
I 49
    tout = fileno(stdout);
    tin = fileno(stdin);
    setconnmode();
D 51
    scc = 0;
    tcc = 0;
E 51
    FD_ZERO(&ibits);
    FD_ZERO(&obits);
    FD_ZERO(&xbits);
E 49

D 49
/*VARARGS*/
E 43
D 39
setcrmod()
{

	crmod = !crmod;
	printf("%s map carriage return on output.\n", crmod ? "Will" : "Won't");
	fflush(stdout);
}

/*VARARGS*/
E 39
suspend()
{
D 39
	register int save;

	save = mode(0);
E 39
I 39
	setcommandmode();
E 39
	kill(0, SIGTSTP);
	/* reget parameters in case they were changed */
	ioctl(0, TIOCGETP, (char *)&ottyb);
	ioctl(0, TIOCGETC, (char *)&otc);
	ioctl(0, TIOCGLTC, (char *)&oltc);
I 43
	return 1;
E 43
D 39
	(void) mode(save);
E 39
}
E 49
I 49
    NetNonblockingIO(net, 1);
E 49

D 49
/*VARARGS*/
bye()
{
	register char *op;
E 49
I 49
#if	defined(TN3270)
    if (noasynch == 0) {			/* DBX can't handle! */
	NetSigIO(net, 1);
    }
    NetSetPgrp(net);
#endif	/* defined(TN3270) */
E 49

D 39
	(void) mode(0);
E 39
D 49
	if (connected) {
		shutdown(net, 2);
		printf("Connection closed.\n");
		close(net);
		connected = 0;
		/* reset his options */
		for (op = hisopts; op < &hisopts[256]; op++)
			*op = 0;
	}
I 43
	return 1;
E 43
}
E 49

D 49
/*VARARGS*/
quit()
{
D 43
	call(bye, "bye", 0);
E 43
I 43
	(void) call(bye, "bye", 0);
E 43
	exit(0);
I 43
	/*NOTREACHED*/
E 43
}
E 49
I 49
#if	defined(SO_OOBINLINE) && !defined(MSDOS)
    SetSockOpt(net, SOL_SOCKET, SO_OOBINLINE, 1);
#endif	/* defined(SO_OOBINLINE) && !defined(MSDOS) */
E 49

E 53
D 49
/*
 * Print status about the connection.
 */
I 41
/*ARGSUSED*/
E 41
D 40
/*VARARGS*/
status()
E 40
I 40
status(argc, argv)
int	argc;
char	*argv[];
E 40
{
D 39
	if (connected)
E 39
I 39
D 40
	if (connected) {
E 39
		printf("Connected to %s.\n", hostname);
D 39
	else
E 39
I 39
		/* XXX should print out line modes, etc. */
	} else {
E 39
		printf("No connection.\n");
E 40
I 40
    if (connected) {
	printf("Connected to %s.\n", hostname);
	if (argc < 2) {
	    printf("Operating in %s.\n", modedescriptions[getconnmode()]);
D 42
	    if (localsigs || ((!donelclsigs) && (getconnmode() >= 3))) {
E 42
I 42
D 43
	    if (localsigs) {
E 43
I 43
	    if (localchars) {
E 43
E 42
		printf("Catching signals locally.\n");
	    }
E 49
I 49
#   if !defined(TN3270)
    if (telnetport) {
	if (!hisopts[TELOPT_SGA]) {
	    willoption(TELOPT_SGA, 0);
E 49
E 40
I 39
	}
E 39
D 40
	printf("Escape character is '%s'.\n", control(escape));
	fflush(stdout);
E 40
I 40
D 49
    } else {
	printf("No connection.\n");
E 49
I 49
	if (!myopts[TELOPT_TTYPE]) {
	    dooption(TELOPT_TTYPE, 0);
	}
E 49
    }
D 49
    printf("Escape character is '%s'.\n", control(escape));
    fflush(stdout);
I 43
    return 1;
E 43
E 40
}
E 49
I 49
#   endif /* !defined(TN3270) */
E 49

D 49
tn(argc, argv)
	int argc;
	char *argv[];
{
D 41
	register int c;
E 41
	register struct hostent *host = 0;
E 49
I 49
#   if !defined(TN3270)
    for (;;) {
I 51
	int schedValue;

	while ((schedValue = Scheduler(0)) != 0) {
	    if (schedValue == -1) {
		setcommandmode();
		return;
	    }
	}

E 51
D 53
	if (Scheduler(SCHED_BLOCK) == -1) {
E 53
I 53
	if (Scheduler(1) == -1) {
E 53
	    setcommandmode();
	    return;
	}
    }
#   else /* !defined(TN3270) */
    for (;;) {
	int schedValue;
E 49

D 49
	if (connected) {
		printf("?Already connected to %s\n", hostname);
D 43
		return;
E 43
I 43
		return 0;
E 49
I 49
	while (!In3270 && !shell_active) {
D 53
	    if (Scheduler(SCHED_BLOCK) == -1) {
E 53
I 53
	    if (Scheduler(1) == -1) {
E 53
		setcommandmode();
		return;
	    }
E 49
E 43
	}
D 49
	if (argc < 2) {
D 41
		strcpy(line, "Connect ");
E 41
I 41
		(void) strcpy(line, "Connect ");
E 41
		printf("(to) ");
		gets(&line[strlen(line)]);
		makeargv();
		argc = margc;
		argv = margv;
E 49
I 49

	while ((schedValue = Scheduler(0)) != 0) {
	    if (schedValue == -1) {
		setcommandmode();
		return;
	    }
E 49
	}
D 48
	if (argc > 3) {
E 48
I 48
D 49
	if ((argc < 2) || (argc > 3)) {
E 48
		printf("usage: %s host-name [port]\n", argv[0]);
D 43
		return;
E 43
I 43
		return 0;
E 43
	}
	sin.sin_addr.s_addr = inet_addr(argv[1]);
	if (sin.sin_addr.s_addr != -1) {
		sin.sin_family = AF_INET;
D 41
		strcpy(hnamebuf, argv[1]);
E 41
I 41
		(void) strcpy(hnamebuf, argv[1]);
E 41
		hostname = hnamebuf;
E 49
I 49
		/* If there is data waiting to go out to terminal, don't
		 * schedule any more data for the terminal.
		 */
D 61
	if (tfrontp-tbackp) {
E 61
I 61
D 62
	if (ring_full_count(ttyoring)) {
E 62
I 62
	if (ring_full_count(&ttyoring)) {
E 62
E 61
	    schedValue = 1;
E 49
	} else {
D 49
		host = gethostbyname(argv[1]);
		if (host) {
			sin.sin_family = host->h_addrtype;
I 44
#ifndef	NOT43
E 44
			bcopy(host->h_addr_list[0], (caddr_t)&sin.sin_addr,
				host->h_length);
I 44
#else	NOT43
			bcopy(host->h_addr, (caddr_t)&sin.sin_addr,
				host->h_length);
#endif	NOT43
E 44
			hostname = host->h_name;
		} else {
			printf("%s: unknown host\n", argv[1]);
D 43
			return;
E 43
I 43
			return 0;
E 49
I 49
	    if (shell_active) {
		if (shell_continue() == 0) {
		    ConnectScreen();
E 49
E 43
		}
I 49
	    } else if (In3270) {
		schedValue = DoTerminalOutput();
	    }
E 49
	}
D 49
	sin.sin_port = sp->s_port;
	if (argc == 3) {
		sin.sin_port = atoi(argv[2]);
D 41
		if (sin.sin_port <= 0) {
E 41
I 41
		if (sin.sin_port == 0) {
E 41
			sp = getservbyname(argv[2], "tcp");
			if (sp)
				sin.sin_port = sp->s_port;
			else {
				printf("%s: bad port number\n", argv[2]);
D 43
				return;
E 43
I 43
				return 0;
E 43
			}
		} else {
			sin.sin_port = atoi(argv[2]);
			sin.sin_port = htons(sin.sin_port);
		}
		telnetport = 0;
I 39
	} else {
		telnetport = 1;
E 49
I 49
	if (schedValue && (shell_active == 0)) {
D 53
	    if (Scheduler(SCHED_BLOCK) == -1) {
E 53
I 53
	    if (Scheduler(1) == -1) {
E 53
		setcommandmode();
		return;
	    }
E 49
E 39
	}
D 49
	signal(SIGINT, intr);
I 39
	signal(SIGQUIT, intr2);
E 39
	signal(SIGPIPE, deadpeer);
	printf("Trying...\n");
	do {
		net = socket(AF_INET, SOCK_STREAM, 0);
		if (net < 0) {
			perror("telnet: socket");
D 43
			return;
E 43
I 43
			return 0;
E 43
		}
I 44
#ifndef	NOT43
E 44
D 41
		if (debug && setsockopt(net, SOL_SOCKET, SO_DEBUG, &debug,
		    sizeof(debug)) < 0)
E 41
I 41
		if (debug &&
				setsockopt(net, SOL_SOCKET, SO_DEBUG,
D 44
					(char *)&debug, sizeof(debug)) < 0) {
E 44
I 44
					(char *)&debug, sizeof(debug)) < 0)
#else	NOT43
		if (debug && setsockopt(net, SOL_SOCKET, SO_DEBUG, 0, 0) < 0)
#endif	NOT43
E 44
E 41
			perror("setsockopt (SO_DEBUG)");
D 41
		if (connect(net, (caddr_t)&sin, sizeof (sin)) < 0) {
E 41
I 41
D 44
		}
E 44
I 44

E 44
		if (connect(net, (struct sockaddr *)&sin, sizeof (sin)) < 0) {
I 44
#ifndef	NOT43
E 44
E 41
			if (host && host->h_addr_list[1]) {
				int oerrno = errno;

				fprintf(stderr,
				    "telnet: connect to address %s: ",
				    inet_ntoa(sin.sin_addr));
				errno = oerrno;
D 41
				perror(0);
E 41
I 41
				perror((char *)0);
E 41
				host->h_addr_list++;
				bcopy(host->h_addr_list[0],
				    (caddr_t)&sin.sin_addr, host->h_length);
				fprintf(stderr, "Trying %s...\n",
					inet_ntoa(sin.sin_addr));
				(void) close(net);
				continue;
			}
I 44
#endif	NOT43
E 44
			perror("telnet: connect");
			signal(SIGINT, SIG_DFL);
D 43
			return;
E 43
I 43
			signal(SIGQUIT, SIG_DFL);
			return 0;
E 43
		}
		connected++;
	} while (connected == 0);
D 40
	call(status, "status", 0);
E 40
I 40
	call(status, "status", "notmuch", 0);
E 40
	if (setjmp(peerdied) == 0)
		telnet();
	fprintf(stderr, "Connection closed by foreign host.\n");
	exit(1);
I 43
	/*NOTREACHED*/
E 49
I 49
    }
#   endif /* !defined(TN3270) */
E 49
E 43
}
D 49


#define HELPINDENT (sizeof ("connect"))

char	openhelp[] =	"connect to a site";
char	closehelp[] =	"close current connection";
char	quithelp[] =	"exit telnet";
char	zhelp[] =	"suspend telnet";
D 43
char	escapehelp[] =	"set escape character";
E 43
char	statushelp[] =	"print status information";
char	helphelp[] =	"print help information";
D 39
char	crmodhelp[] =	"toggle mapping of received carriage returns";
char	togglestring[] = "toggle various (debugging) options";
char	sendhelp[] =	"transmit special characters";
E 39
I 39
D 40
char	togglestring[] = "toggle various options ('toggle ?' for more)";
E 40
char	sendhelp[] =	"transmit special characters ('send ?' for more)";
D 40
char	sethelp[] = 	"set various special characters ('set ?' for more)";
char	modehelp[] =	"change operating mode ('mode ?' for more)";
E 40
I 40
char	sethelp[] = 	"set operating parameters ('set ?' for more)";
char	togglestring[] ="toggle operating parameters ('toggle ?' for more)";
char	displayhelp[] =	"display operating parameters";
char	modehelp[] =
		"try to enter line-by-line or character-at-a-time mode";
E 40
E 39

int	help();

struct cmd cmdtab[] = {
D 39
	{ "open",	openhelp,	tn, 1, 0 },
	{ "close",	closehelp,	bye, 1, 1 },
	{ "quit",	quithelp,	quit, 1, 0 },
	{ "z",		zhelp,		suspend, 1, 0 },
	{ "escape",	escapehelp,	setescape, 1, 0 },
	{ "status",	statushelp,	status, 1, 0 },
	{ "crmod",	crmodhelp,	setcrmod, 1, 0 },
	{ "send",	sendhelp,	sendcmd, 1, 1 },
	    { "transmit",	sendhelp,	sendcmd, 0, 1 },
	    { "xmit",		sendhelp,	sendcmd, 0, 1 },
	{ "toggle",	togglestring,	toggle, 1, 0 },
	{ "?",		helphelp,	help, 1, 0 },
	{ "help",	helphelp,	help, 0, 0 },
E 39
I 39
D 43
	{ "open",	openhelp,	tn,		1, 0 },
E 43
	{ "close",	closehelp,	bye,		1, 1 },
I 43
	{ "display",	displayhelp,	display,	1, 0 },
	{ "mode",	modehelp,	modecmd,	1, 1 },
	{ "open",	openhelp,	tn,		1, 0 },
E 43
	{ "quit",	quithelp,	quit,		1, 0 },
D 43
	{ "z",		zhelp,		suspend,	1, 0 },
	{ "escape",	escapehelp,	setescape,	1, 0 },
	{ "status",	statushelp,	status,		1, 0 },
D 40
	{ "crmod",	crmodhelp,	setcrmod,	1, 0 },
E 40
I 40
	{ "crmod",	crmodhelp,	togcrmod,	1, 0 },
E 43
E 40
	{ "send",	sendhelp,	sendcmd,	1, 1 },
D 40
	{ "set",	sethelp,	setcmd,		1, 0 },
	{ "mode",	modehelp,	modecmd,	1, 1 },
E 40
D 43
	{ "transmit",	sendhelp,	sendcmd,	0, 1 },
	{ "xmit",	sendhelp,	sendcmd,	0, 1 },
E 43
I 40
	{ "set",	sethelp,	setcmd,		1, 0 },
I 43
	{ "status",	statushelp,	status,		1, 0 },
E 43
E 40
	{ "toggle",	togglestring,	toggle,		1, 0 },
I 40
D 43
	{ "display",	displayhelp,	display,	1, 0 },
	{ "mode",	modehelp,	modecmd,	1, 1 },
E 43
I 43
	{ "z",		zhelp,		suspend,	1, 0 },
E 43
E 40
	{ "?",		helphelp,	help,		1, 0 },
D 43
	{ "help",	helphelp,	help,		0, 0 },
E 43
E 39
	0
};

I 43
char	crmodhelp[] =	"deprecated command -- use 'toggle crmod' instead";
char	escapehelp[] =	"deprecated command -- use 'set escape' instead";
E 43

I 43
struct cmd cmdtab2[] = {
	{ "help",	helphelp,	help,		0, 0 },
	{ "escape",	escapehelp,	setescape,	1, 0 },
	{ "crmod",	crmodhelp,	togcrmod,	1, 0 },
	0
};

E 49
I 49

E 49
E 43
/*
I 54
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
#if	0	/* XXX */
    register char *thisitem, *next;
    char *good;
#define	wewant(p)	((nfrontp > p) && ((*p&0xff) == IAC) && \
				((*(p+1)&0xff) != EC) && ((*(p+1)&0xff) != EL))

    thisitem = netobuf;

    while ((next = nextitem(thisitem)) <= netobuf.send) {
	thisitem = next;
    }

    /* Now, thisitem is first before/at boundary. */

    good = netobuf;	/* where the good bytes go */

    while (netoring.add > thisitem) {
	if (wewant(thisitem)) {
	    int length;

	    next = thisitem;
	    do {
		next = nextitem(next);
	    } while (wewant(next) && (nfrontp > next));
	    length = next-thisitem;
	    memcpy(good, thisitem, length);
	    good += length;
	    thisitem = next;
	} else {
	    thisitem = nextitem(thisitem);
	}
    }

#endif	/* 0 */
}

/*
E 54
D 49
 * Help command.
E 49
I 49
 * These routines add various telnet commands to the data stream.
E 49
 */
D 49
help(argc, argv)
	int argc;
	char *argv[];
{
	register struct cmd *c;
E 49

I 54
static void
doflush()
{
    NET2ADD(IAC, DO);
    NETADD(TELOPT_TM);
    flushline = 1;
    flushout = 1;
    ttyflush(1);			/* Flush/drop output */
    /* do printoption AFTER flush, otherwise the output gets tossed... */
    printoption("<SENT", doopt, TELOPT_TM, 0);
}

E 54
D 49
	if (argc == 1) {
		printf("Commands may be abbreviated.  Commands are:\n\n");
		for (c = cmdtab; c->name; c++)
			if (c->dohelp) {
				printf("%-*s\t%s\n", HELPINDENT, c->name,
								    c->help);
			}
D 43
		return;
E 43
I 43
		return 0;
E 43
	}
	while (--argc > 0) {
		register char *arg;
		arg = *++argv;
		c = getcmd(arg);
D 41
		if (c == (struct cmd *)-1)
E 41
I 41
		if (c == Ambiguous(struct cmd *))
E 41
			printf("?Ambiguous help command %s\n", arg);
		else if (c == (struct cmd *)0)
			printf("?Invalid help command %s\n", arg);
		else
			printf("%s\n", c->help);
	}
I 43
	return 0;
E 43
}
/*
 * Call routine with argc, argv set from args (terminated by 0).
 * VARARGS2
 */
call(routine, args)
	int (*routine)();
D 41
	int args;
E 41
I 41
	char *args;
E 49
I 49
void
xmitAO()
E 49
E 41
{
D 41
	register int *argp;
E 41
I 41
D 49
	register char **argp;
E 41
	register int argc;

	for (argc = 0, argp = &args; *argp++ != 0; argc++)
		;
D 43
	(*routine)(argc, &args);
E 43
I 43
	return (*routine)(argc, &args);
E 49
I 49
    NET2ADD(IAC, AO);
    if (autoflush) {
	doflush();
    }
E 49
E 43
}

D 49
makeargv()
{
	register char *cp;
	register char **argp = margv;
E 49

D 49
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
E 49
I 49
void
xmitEL()
{
    NET2ADD(IAC, EL);
E 49
}

D 49
char **
getnextcmd(name)
char *name;
E 49
I 49
void
xmitEC()
E 49
{
D 49
    struct cmd *c = (struct cmd *) name;

    return (char **) (c+1);
E 49
I 49
    NET2ADD(IAC, EC);
E 49
}

D 49
struct cmd *
getcmd(name)
char *name;
E 49
I 49

#if	defined(NOT43)
int
#else	/* defined(NOT43) */
void
#endif	/* defined(NOT43) */
dosynch()
E 49
{
D 43
    return (struct cmd *) genget(name, (char **) cmdtab, getnextcmd);
E 43
I 43
D 49
    struct cmd *cm;
E 49
I 49
    netclear();			/* clear the path to the network */
D 58
    NET2ADD(IAC, DM);
E 58
I 58
    NETADD(IAC);
    setneturg();
    NETADD(DM);
E 58
E 49

D 49
    if (cm = (struct cmd *) genget(name, (char **) cmdtab, getnextcmd)) {
	return cm;
    } else {
	return (struct cmd *) genget(name, (char **) cmdtab2, getnextcmd);
    }
E 49
I 49
#if	defined(NOT43)
    return 0;
#endif	/* defined(NOT43) */
E 49
E 43
D 54
}

D 49
command(top)
	int top;
E 49
I 49
void
doflush()
E 49
{
D 49
	register struct cmd *c;
E 49
I 49
    NET2ADD(IAC, DO);
    NETADD(TELOPT_TM);
    flushline = 1;
    flushout = 1;
    ttyflush(1);			/* Flush/drop output */
    /* do printoption AFTER flush, otherwise the output gets tossed... */
    printoption("<SENT", doopt, TELOPT_TM, 0);
E 54
}
E 49
D 39
	int oldmode, wasopen;
E 39
I 39
D 41
	int wasopen;
E 41
E 39

D 39
	oldmode = mode(0);
E 39
I 39
D 49
	setcommandmode();
E 39
D 43
	if (!top)
E 43
I 43
	if (!top) {
E 43
		putchar('\n');
D 43
	else
E 43
I 43
	} else {
E 43
		signal(SIGINT, SIG_DFL);
I 43
		signal(SIGQUIT, SIG_DFL);
	}
E 43
	for (;;) {
		printf("%s> ", prompt);
		if (gets(line) == 0) {
			if (feof(stdin))
				quit();
			break;
		}
		if (line[0] == 0)
			break;
		makeargv();
		c = getcmd(margv[0]);
D 41
		if (c == (struct cmd *)-1) {
E 41
I 41
		if (c == Ambiguous(struct cmd *)) {
E 41
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
D 43
		(*c->handler)(margc, margv);
		if (c->handler != help)
E 43
I 43
		if ((*c->handler)(margc, margv)) {
E 43
			break;
I 43
		}
E 43
	}
	if (!top) {
D 39
		if (!connected)
E 39
I 39
		if (!connected) {
E 39
			longjmp(toplevel, 1);
D 39
		(void) mode(oldmode);
E 39
I 39
			/*NOTREACHED*/
		}
		setconnmode();
E 39
	}
E 49
I 49
void
intp()
{
    NET2ADD(IAC, IP);
    flushline = 1;
    if (autoflush) {
	doflush();
    }
    if (autosynch) {
	dosynch();
    }
E 49
I 41
}
D 49

/*
 * main.  Parse arguments, invoke the protocol or command parser.
 */
E 49

D 49

main(argc, argv)
	int argc;
	char *argv[];
E 49
I 49
void
sendbrk()
E 49
{
D 49
	sp = getservbyname("telnet", "tcp");
	if (sp == 0) {
		fprintf(stderr, "telnet: tcp/telnet: unknown service\n");
		exit(1);
	}
	NetTrace = stdout;
	ioctl(0, TIOCGETP, (char *)&ottyb);
	ioctl(0, TIOCGETC, (char *)&otc);
	ioctl(0, TIOCGLTC, (char *)&oltc);
I 42
#if	defined(LNOFLSH)
	ioctl(0, TIOCLGET, (char *)&autoflush);
D 43
	autoflush &= LNOFLSH;
E 43
I 43
	autoflush = !(autoflush&LNOFLSH);	/* if LNOFLSH, no autoflush */
#else	/* LNOFLSH */
	autoflush = 1;
E 43
#endif	/* LNOFLSH */
E 42
	ntc = otc;
D 44
	ntc.t_eofc = -1;		/* we don't want to use EOF */
E 44
I 42
	nltc = oltc;
E 42
	nttyb = ottyb;
	setbuf(stdin, (char *)0);
	setbuf(stdout, (char *)0);
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
	if (argc != 1) {
		if (setjmp(toplevel) != 0)
			exit(0);
		tn(argc, argv);
	}
	setjmp(toplevel);
	for (;;)
		command(1);
E 49
I 49
    NET2ADD(IAC, BREAK);
    flushline = 1;
    if (autoflush) {
	doflush();
    }
    if (autosynch) {
	dosynch();
    }
E 49
E 41
E 38
E 5
E 2
}
E 1
