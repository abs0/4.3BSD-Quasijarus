h48706
s 00011/00009/00490
d D 5.10 88/06/30 15:00:02 bostic 68 67
c install approved copyright notice
e
s 00024/00020/00475
d D 5.9 88/03/13 19:53:31 bostic 67 66
c add Berkeley specific header
e
s 00000/00001/00495
d D 5.8 86/12/17 16:05:35 eric 66 65
c delete unneeded #include <ctype.h>
e
s 00000/00001/00496
d D 5.7 86/04/02 16:02:02 eric 65 64
c don't run around clearing EF_FATALERRS -- this often applies to another
c address.  Drop uid/gid check in sameaddr -- it causes more problems
c than it fixes.
e
s 00002/00002/00495
d D 5.6 85/09/30 21:34:43 eric 64 63
m 
c clean up some aspects of error message display
e
s 00000/00000/00497
d D 5.5 85/09/19 01:25:57 eric 63 61
i 62
m 
c incorporate SMI changes -- still experimental
e
s 00007/00000/00490
d D 5.3.1.1 85/09/19 00:56:18 eric 62 60
m 
c SMI changes (somewhat)
e
s 00001/00001/00489
d D 5.4 85/09/17 19:24:28 eric 61 60
m 
c facilities in syslog
e
s 00004/00002/00486
d D 5.3 85/06/08 10:31:19 eric 60 59
m 
c lint for 4.3 release
e
s 00002/00003/00486
d D 5.2 85/06/07 22:20:57 miriam 59 58
m 
c Resolve duplicate SccsId
e
s 00014/00000/00475
d D 5.1 85/06/07 15:17:45 dist 58 57
m 
c Add copyright
e
s 00030/00002/00445
d D 4.12 85/05/24 11:01:53 eric 57 56
m 
c Changes from Bill Nowicki <sun!rose!nowicki> and Jay Lepreau <lepreau@utah-cs>:
c Fix "bad file number" problem; improve error reporting; try to keep messages
c closer to their original order.  Also, drop "safe" mode in readcf since we
c never run setuid when -C is specified.
e
s 00001/00001/00446
d D 4.11 85/04/04 17:38:55 miriam 56 55
m 
c Change LOG_ERR to LOG_MAIL
e
s 00001/00000/00446
d D 4.10 84/08/11 16:56:48 eric 55 54
m 
c Changes from Greg Couch <ucsfcgl!gregc> for V7 compatibility and
c miscellaneous bug fixes; "clear" => "bzero" and "bmove" => "bcopy"
c throughout for consistency; bzero is now in bcopy.c (these are
c supplied by libc on 4.2bsd)
e
s 00001/00001/00445
d D 4.9 84/03/11 16:56:13 eric 54 53
m 
c change macro expansion character from $ to \001 so that $'s can be
c used in headers -- the .cf file is unchanged by mapping $ to \001.
c \001 is now a manifest constant.
e
s 00001/00001/00445
d D 4.8 84/03/11 13:38:35 eric 53 52
m 
c fixes from Greg Satz <satz@sri-tsc.ARPA>, mostly for PDP's
e
s 00006/00007/00440
d D 4.7 83/11/13 18:08:34 eric 52 51
m 
c Fixes two nasty problems, both pointed out by Bill Nowicki at Stanford:
c I/O errors on input in collect would cause infinite loops, and a protocol
c error (or other error that would call smtpquit abnormally) would cause
c core dumps
e
s 00001/00001/00446
d D 4.6 83/10/29 12:01:29 eric 51 50
m 
c add newline to "deferred" message in usersmtp.c
e
s 00007/00000/00440
d D 4.5 83/10/01 16:58:10 eric 50 49
m 
c clean up error handling in general; make sure that something gets logged
c in the transcript if the connection cannot be established; clean up Teus
c Hagen's mod to arpadate.c to match the sendmail coding style.
e
s 00025/00011/00415
d D 4.4 83/09/07 09:45:17 eric 49 48
m 
c Increase timeout for greeting message to five minutes; remember to close
c the connection properly if we get a failure during connection establishment.
e
s 00016/00010/00410
d D 4.3 83/09/05 14:33:40 eric 48 47
m 
c Cut down the amount of bulk that is sent in SMTP error messages, by
c trying to log only real errors in the transcript.  -v mode is unchanged.
e
s 00018/00001/00402
d D 4.2 83/08/31 17:42:37 eric 47 46
m 
c fix problem with timeouts caused by change in EINTR semantics in 4.2bsd;
c add a two minute timeout on the greeting message in user smtp to detect
c hung connections
e
s 00000/00000/00403
d D 4.1 83/07/25 19:47:02 eric 46 45
m 
c 4.2 release version
e
s 00001/00001/00402
d D 3.43 83/03/26 14:24:18 eric 45 44
m 213
c increase buffer size in smtpmessage
e
s 00022/00009/00381
d D 3.42 83/02/20 12:28:25 eric 44 43
m 190
c Avoid loops in the auto-closedown code
e
s 00003/00002/00387
d D 3.41 83/02/02 12:54:21 eric 43 42
m 165
c implement classes and mailer flags as a bit map; define new class 'w'
c as the set of all hosts we are known by
e
s 00005/00000/00384
d D 3.40 83/01/18 20:37:57 eric 42 41
m 
c pause() after reply error if 18.100 set -- so that Sam can try to track
c down the state of the connection in the CMU-CS-A problem.
e
s 00002/00002/00382
d D 3.39 83/01/16 13:14:47 eric 41 40
m 152
c Change mailer spec to have labelled fields for future expansion.
c **** This delta invalidates previous configuration files ****
e
s 00004/00005/00380
d D 3.38 83/01/15 17:41:04 eric 40 39
m 149
c be sure everything gets appropriately externalized; canonname goes away,
c since everything is now done by remotename
e
s 00004/00003/00381
d D 3.37 83/01/09 15:43:01 eric 39 38
m 
c fix CRLF problem when sending SMTP commands; make newstr() and crlf()
c into macros
e
s 00052/00038/00332
d D 3.36 83/01/06 10:48:49 eric 38 37
m 
c split up FULLSMTP flag -- now have "X" (M_XDOT, use hidden dot algorithm),
c "p" (M_FROMPATH, use reverse-path in MAIL FROM:<> command), and "L"
c (M_LIMITS, enforce SMTP line limits).  I would like to change the format
c of the mail defn one more time to make named fields so that it would
c be more extensible.
e
s 00002/00000/00368
d D 3.35 83/01/05 17:57:03 eric 37 36
m 
c curiouser and curiouser.....  a read error on the reply from a QUIT will
c cause another QUIT command, and thus an fclose(NULL).  Some sites seem
c to be sending a 421 Shutting down and then closing without waiting for
c the QUIT, so this happens....
e
s 00022/00008/00346
d D 3.34 83/01/05 10:18:55 eric 36 35
m 
c improve error recovery for bizarre SMTP cases; unfortunately CMU has
c decided to start working again, so the strangest parts are untested.
e
s 00005/00002/00349
d D 3.33 83/01/04 17:45:37 eric 35 34
m 
c Ignore SIGPIPE early (in main rather than in deliver) so that rude hosts
c that close the connection early don't cause us to die -- in particular,
c CMU-CS-A (nee CMU-10A) was doing this after the DATA command; the problem
c went away quite mysteriously, so I have no idea why it happened
e
s 00003/00003/00348
d D 3.32 83/01/01 21:26:09 eric 34 33
m 123
c Put CRLF on all lines in user SMTP.  Pass this info down to
c innumerable routines.
e
s 00017/00013/00334
d D 3.31 83/01/01 18:15:07 eric 33 32
m 122
c Use a more resilient algorithm to handle the special case of an SMTP
c connection that is going down spontaneously (with a 421 reply code)
e
s 00007/00007/00340
d D 3.30 82/12/05 13:47:21 eric 32 31
m 092
c Clear the envelope in the child in server SMTP to insure that our oh so
c helpful parent doesn't delete our transcript; move the transcript and
c temporary file pointers into the envelope; pass the envelope to other
c routines in the holy war against global variables; split off envelope
c routines from main.c to envelope.c
e
s 00051/00035/00296
d D 3.29 82/11/28 16:01:24 eric 31 30
m 
c implement SMTP auto-shutdown on 421 codes; clean up some error processing
c items, particularly in SMTP; don't reinstantiate error message bodies after
c queueing; other minor changes.  This is all cleanup from 3.253.
e
s 00001/00002/00330
d D 3.28 82/11/28 00:23:33 eric 30 29
m 
c Many changes resulting from a complete code readthrough.  Most of these
c fix minor bugs or change the internal structure for clarity, etc.  There
c should be almost no externally visible changes (other than some cleaner
c error message printouts and the like).
e
s 00006/00003/00326
d D 3.27 82/11/24 17:16:31 eric 29 28
m 026
c run SMTP jobs in a subprocess so that multiple jobs will work.  This
c delta also changes the envelope data structure so that flags are in
c a bit map, and adjusts some of the semantics.  The transcript is now
c local to an envelope.  A bunch of old code is deleted.  A serious bug
c was fixed in the "run in background" code.  Etc., etc.
e
s 00020/00000/00309
d D 3.26 82/11/21 17:19:26 eric 28 27
m 026
c preliminary hacks for multiple SMTP transactions per connection: make
c assignment of multiple queue id's more efficient, make prefixes two
c characters (e.g., qfAA99999), pass the file name to freeze and thaw,
c add a mailer flag saying we are talking to one of our own kind.
e
s 00010/00001/00299
d D 3.25 82/10/09 19:06:41 eric 27 26
m 002
c Handle Reverse-Path in some reasonable way.  You must put the 'X'
c flag (M_FULLSMTP) in the local mailer's flags to get this line.
e
s 00002/00002/00298
d D 3.24 82/10/07 08:51:10 eric 26 25
c never use ruleset 3 alone -- perhaps the standard use of ruleset
c three should go now, since noone uses it alone.
e
s 00005/00005/00295
d D 3.23 82/09/21 10:12:28 eric 25 24
c put 050 in from of recursive smtp messages
e
s 00002/00002/00298
d D 3.22 82/09/06 17:00:33 eric 24 23
c user SMTP fixes to talk to ISI
e
s 00002/00002/00298
d D 3.21 82/09/05 18:03:51 eric 23 22
c clean up canonname
e
s 00008/00006/00292
d D 3.20 82/08/31 10:06:12 eric 22 21
c clean up reply code processing some more; in particular, give more
c detail in many messages.  process connection failures correctly.
e
s 00008/00006/00290
d D 3.19 82/08/29 17:33:00 eric 21 20
c fix serious botch in SMTP reply code delta; change a bunch of
c "Internal error" codes to a new "Remote protocol error" -- so that
c I don't get blamed for things that other systems do.
e
s 00020/00013/00276
d D 3.18 82/08/29 16:52:37 eric 20 19
c do a better job at interpreting SMTP reply codes
e
s 00000/00002/00289
d D 3.17 82/08/08 21:16:00 eric 19 18
c make "sleep" work correctly even in the face of other events; clean
c up the queue processing: child queue runs now go away when done.  more
c debugging logging is needed to verify that this works right though.
e
s 00006/00011/00285
d D 3.16 82/08/08 17:02:54 eric 18 17
c more general event mechanism
e
s 00004/00004/00292
d D 3.15 82/08/08 01:03:35 eric 17 16
c change debug level to a debug vector; add levels on logging (and the
c -L flag); change logging to be by message-id; elevate message-id;
c some lint-type cleanup
e
s 00001/00000/00295
d D 3.14 82/07/05 20:55:16 eric 16 15
c improve debugging: flush transcript before doing things that might
c take a long time; add some info to debugging output
e
s 00028/00002/00267
d D 3.13 82/07/05 12:03:05 eric 15 13
c put timeouts on net reads
e
s 00008/00000/00269
d D 3.12.1.1 82/07/04 10:28:37 eric 14 13
c do some stuff to add a "HOPS" command -- it seems like it would
c be easier and smarter to count Mail-From: lines.
e
s 00017/00018/00252
d D 3.12 82/06/19 20:47:29 eric 13 12
c improve SMTP error reporting
e
s 00001/00001/00269
d D 3.11 82/05/31 18:50:51 eric 12 11
c pass lint.  notice that definitions in llib-lc have changed for
c alarm() and sleep() calls {arg was unsigned, is now int}.
e
s 00000/00000/00270
d D 3.10 82/05/31 15:33:01 eric 11 9
i 10
c finish implementing envelopes.  it's not completely clear to me that
c this is really the way to go, but it seems clearly better than what
c i had before.  this delta includes many other minor changes, so it
c should probably not be blithely removed.
e
s 00007/00006/00263
d D 3.9.1.1 82/05/29 18:21:17 eric 10 9
c try to install envelopes.  is this really worth it???
e
s 00030/00005/00239
d D 3.9 82/03/06 12:09:46 eric 9 8
c clean up error handling in IPC case; fix a minor bug in headers in
c queueing code; make SMTP mail multi user per connect.
e
s 00000/00001/00244
d D 3.8 82/01/10 21:58:04 eric 8 7
c cleanup from cbosgd (Mark Horton) testing; some internals, mostly
c configuration.  This tries to make the configuration file (cf.m4) be
c much more general, but I fear it is doomed to failure -- it may be
c better to just tell people to roll their own.
e
s 00002/00002/00243
d D 3.7 81/12/06 12:40:43 eric 7 6
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00006/00000/00239
d D 3.6 81/12/05 11:54:15 eric 6 5
c put the SMTP and queueing code on compilation flags so that sendmail
c will fit on non-ID PDP-11's (ugh); put the ugly UUCP hack on a
c compilation flag also to emphasize that it sucks eggs; makefile
c cleanup.
e
s 00017/00014/00222
d D 3.5 81/11/21 09:58:13 eric 5 4
c convert to SMTP draft 3
e
s 00103/00176/00133
d D 3.4 81/11/11 20:24:17 eric 4 3
c integrate user SMTP into sendmail itself.  If there is no $u arg
c in the mailer argument list, SMTP is run.  This can be used directly
c over the Ethernet or to any clever mailer.  We still need to edit
c spooled control files to remove recipients that have been successfully
c sent during queue processing.
e
s 00094/00029/00215
d D 3.3 81/11/08 12:39:25 eric 3 2
c detects errors in a reasonable way.  however, it only works
c with one user at a time, due to the problems of returning separate
c error returns per user.  We should run smtp between sendmail and the
c individual mailers.....
e
s 00096/00035/00148
d D 3.2 81/11/07 22:00:32 eric 2 1
c fix a number of bugs to get the actual case working over the ether.
c this version seems to work correctly if there are no errors, but any
c error sends it into strange places.
e
s 00183/00000/00000
d D 3.1 81/10/31 10:11:38 eric 1 0
c date and time created 81/10/31 10:11:38 by eric
e
u
U
f b 
f i 
t
T
I 58
/*
I 68
 * Copyright (c) 1983 Eric P. Allman
E 68
D 67
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 67
I 67
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 68
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 68
I 68
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 68
 */
E 67

I 67
# include "sendmail.h"
E 67
D 60
#ifndef lint
D 59
static char	SccsId[] = "%W% (Berkeley) %G%";
E 59
#endif not lint
E 60

I 67
#ifndef lint
#ifdef SMTP
static char sccsid[] = "%W% (Berkeley) %G% (with SMTP)";
#else
static char sccsid[] = "%W% (Berkeley) %G% (without SMTP)";
#endif
#endif /* not lint */

E 67
E 58
I 2
D 66
# include <ctype.h>
E 66
I 15
D 19
# include <signal.h>
E 19
E 15
E 2
I 1
D 8
# include <wellknown.h>
E 8
# include <sysexits.h>
I 57
# include <errno.h>
E 57
D 4
# include <stdio.h>
# include <useful.h>
E 4
I 4
D 67
# include "sendmail.h"
E 67
E 4

I 6
D 67
# ifndef SMTP
I 60
# ifndef lint
E 60
D 7
static char	SccsId[] =	"%W%	%G%	(no SMTP)";
E 7
I 7
D 59
SCCSID(%W%	%Y%	%G%	(no SMTP));
E 59
I 59
static char	SccsId[] = "%W% (Berkeley) %G%	(no SMTP)";
I 60
# endif not lint
E 60
E 59
E 7
# else SMTP

I 60
# ifndef lint
E 60
E 6
D 7
static char	SccsId[] =	"%W%	%G%";
E 7
I 7
D 59
SCCSID(%W%	%Y%	%G%);
E 59
I 59
static char	SccsId[] = "%W% (Berkeley) %G%";
I 60
# endif not lint
E 60
E 59
E 7

I 31

E 67
I 67
# ifdef SMTP
E 67

E 31
/*
I 31
**  USERSMTP -- run SMTP protocol from the user end.
**
**	This protocol is described in RFC821.
*/

#define REPLYTYPE(r)	((r) / 100)		/* first digit of reply code */
#define REPLYCLASS(r)	(((r) / 10) % 10)	/* second digit of reply code */
#define SMTPCLOSING	421			/* "Service Shutting Down" */

I 48
char	SmtpMsgBuffer[MAXLINE];		/* buffer for commands */
E 48
D 33
static char	SmtpReplyBuffer[MAXLINE];	/* buffer for replies */
static FILE	*SmtpOut;			/* output file */
static FILE	*SmtpIn;			/* input file */
static int	SmtpPid;			/* pid of mailer */
static bool	SmtpClosing;			/* set on a forced close */
E 33
I 33
char	SmtpReplyBuffer[MAXLINE];	/* buffer for replies */
I 57
char	SmtpError[MAXLINE] = "";	/* save failure error messages */
E 57
FILE	*SmtpOut;			/* output file */
FILE	*SmtpIn;			/* input file */
int	SmtpPid;			/* pid of mailer */
D 44
bool	SmtpClosing;			/* set on a forced close */
E 44
I 44

/* following represents the state of the SMTP connection */
int	SmtpState;			/* connection state, see below */

#define SMTP_CLOSED	0		/* connection is closed */
#define SMTP_OPEN	1		/* connection is open for business */
#define SMTP_SSD	2		/* service shutting down */
E 44
E 33
/*
E 31
D 4
**  TCP -- TCP/Ethernet/ARPAnet mailer
E 4
I 4
**  SMTPINIT -- initialize SMTP.
E 4
**
D 4
**	This arranges to send a message over the TCP connection.
*/

# define MAXLINE	200

char	*MailCommand =	"/usr/lib/sendmail";
char	*MailUser =	"network";
D 2
char	*MailPassword =	NULL;
FILE	*MailFile;
E 2
I 2
char	*MailPassword =	"mailhack";
FILE	*InConnection;
FILE	*OutConnection;
E 2
bool	Verbose;
I 2
bool	Debug;
I 3
int	Status;			/* exit status */
E 3
E 2

main(argc, argv)
	int argc;
	char **argv;
{
D 2
	extern FILE *openconnection();
E 2
D 3
	register int stat;

E 3
I 2
	while (argc > 1 && argv[1][0] == '-')
	{
		register char *p = *++argv;

		argc--;
		switch (p[1])
		{
		  case 'v':
			Verbose = TRUE;
			break;

		  case 'd':
			Debug = TRUE;
			break;
		}
	}

E 2
	if (argc < 4)
I 2
	{
		if (Debug)
			printf("Usage\n");
E 2
		exit(EX_USAGE);
I 2
	}
E 2

D 2
	MailFile = openconnection(argv[2]);
	if (MailFile == NULL)
E 2
I 2
	if (openconnection(argv[2]) < 0)
E 2
D 3
		exit(EX_TEMPFAIL);
E 3
I 3
		exit(Status);
E 3

D 3
	stat = runsmtp(argv[1], &argv[3]);
E 3
I 3
	Status = runsmtp(argv[1], &argv[3]);
E 3

I 3
	closeconnection();

E 3
I 2
	if (Debug)
D 3
		printf("Finishing with stat %d\n", stat);
E 3
I 3
		printf("Finishing with stat %d\n", Status);
E 3

E 2
D 3
	exit(stat);
E 3
I 3
	exit(Status);
E 3
}
/*
**  OPENCONNECTION -- open connection to SMTP socket
E 4
I 4
**	Opens the connection and sends the initial protocol.
E 4
**
**	Parameters:
D 3
**		none.
E 3
I 3
D 4
**		host -- the name of the host to connect to.  This
**			will be replaced by the canonical name of
**			the host.
E 4
I 4
**		m -- mailer to create connection to.
**		pvp -- pointer to parameter vector to pass to
**			the mailer.
D 38
**		ctladdr -- controlling address for this mailer.
E 38
E 4
E 3
**
**	Returns:
D 3
**		file pointer of connection.
**		NULL on error.
E 3
I 3
D 4
**		File descriptor of connection.
**		-1 on error.
E 4
I 4
**		appropriate exit status -- EX_OK on success.
I 49
**		If not EX_OK, it should close the connection.
E 49
E 4
E 3
**
**	Side Effects:
D 3
**		none.
E 3
I 3
D 4
**		sets 'Status' to represent the problem on error.
E 4
I 4
**		creates connection and sends initial protocol.
E 4
E 3
*/

I 47
jmp_buf	CtxGreeting;

E 47
D 2
FILE *
E 2
D 4
openconnection(host)
	char *host;
E 4
I 4
D 31
# define REPLYTYPE(r)	((r) / 100)
I 20
# define REPLYCLASS(r)	(((r) / 10) % 10)
E 20

static FILE	*SmtpOut;	/* output file */
static FILE	*SmtpIn;	/* input file */
static int	SmtpPid;	/* pid of mailer */
I 9
static int	SmtpErrstat;	/* error status if open fails */
E 9

E 31
D 38
smtpinit(m, pvp, ctladdr)
E 38
I 38
smtpinit(m, pvp)
E 38
	struct mailer *m;
	char **pvp;
D 38
	ADDRESS *ctladdr;
E 38
E 4
{
D 4
	char cmdbuf[100];
D 2
	extern FILE *rexec();
	register FILE *f;
E 2
I 2
	register int fd;
E 4
I 4
	register int r;
I 47
	EVENT *gte;
E 47
	char buf[MAXNAME];
I 47
	extern greettimeout();
E 47
I 15
D 30
	extern tick();
E 30
I 18
D 40
	extern char *canonname();
E 40
E 18
E 15
E 4
E 2

D 4
	/* create the command name */
D 2
	sprintf(cmdbuf, "%s -p", MailCommand);
E 2
I 2
	sprintf(cmdbuf, "%s -as%s%s", MailCommand,
					Verbose ? " -v" : "",
					Debug ? " -d" : "");
E 4
I 4
	/*
	**  Open the connection to the mailer.
	*/
E 4
E 2

I 44
#ifdef DEBUG
	if (SmtpState == SMTP_OPEN)
		syserr("smtpinit: already open");
#endif DEBUG

E 44
I 9
	SmtpIn = SmtpOut = NULL;
I 36
D 44
	SmtpClosing = FALSE;
E 44
I 44
	SmtpState = SMTP_CLOSED;
I 57
	SmtpError[0] = '\0';
I 62
	SmtpPhase = "user open";
E 62
E 57
E 44
E 36
E 9
I 2
D 4
	if (Debug)
		printf("Creating connection to \"%s\" on %s\n", cmdbuf, host);
E 4
I 4
D 38
	SmtpPid = openmailer(m, pvp, ctladdr, TRUE, &SmtpOut, &SmtpIn);
E 38
I 38
	SmtpPid = openmailer(m, pvp, (ADDRESS *) NULL, TRUE, &SmtpOut, &SmtpIn);
E 38
I 9
	if (SmtpPid < 0)
	{
D 31
		SmtpErrstat = ExitStat;
E 31
# ifdef DEBUG
D 17
		if (Debug > 0)
E 17
I 17
		if (tTd(18, 1))
E 17
D 31
			printf("smtpinit: cannot open: Errstat %d errno %d\n",
			   SmtpErrstat, errno);
E 31
I 31
			printf("smtpinit: cannot open %s: stat %d errno %d\n",
			   pvp[0], ExitStat, errno);
E 31
# endif DEBUG
I 50
		if (CurEnv->e_xfp != NULL)
		{
I 57
			register char *p;
E 57
			extern char *errstring();
I 57
			extern char *statstring();
E 57

D 51
			fprintf(CurEnv->e_xfp, "421 %s.%s... Deferred: %s",
E 51
I 51
D 57
			fprintf(CurEnv->e_xfp, "421 %s.%s... Deferred: %s\n",
E 51
				pvp[1], m->m_name, errstring(errno));
E 57
I 57
			if (errno == 0)
			{
				p = statstring(ExitStat);
				fprintf(CurEnv->e_xfp,
					"%.3s %s.%s... %s\n",
					p, pvp[1], m->m_name, p);
			}
			else
			{
				fprintf(CurEnv->e_xfp,
					"421 %s.%s... Deferred: %s\n",
					pvp[1], m->m_name, errstring(errno));
			}
E 57
		}
E 50
		return (ExitStat);
	}
I 44
	SmtpState = SMTP_OPEN;
E 44
I 15
D 19
	(void) signal(SIGALRM, tick);
E 19
E 15
E 9
E 4

I 3
D 4
	/* verify host name */
	if (rhost(&host) < 0)
	{
		if (Debug)
			printf("Unknown host %s\n", host);
		Status = EX_NOHOST;
		return (-1);
	}
E 4
I 4
	/*
	**  Get the greeting message.
D 47
	**	This should appear spontaneously.
E 47
I 47
D 49
	**	This should appear spontaneously.  Give it two minutes to
E 49
I 49
	**	This should appear spontaneously.  Give it five minutes to
E 49
	**	happen.
E 47
	*/
E 4

I 47
	if (setjmp(CtxGreeting) != 0)
D 49
		return (EX_TEMPFAIL);
	gte = setevent(120, greettimeout, 0);
E 49
I 49
		goto tempfail;
D 53
	gte = setevent(300, greettimeout, 0);
E 53
I 53
	gte = setevent((time_t) 300, greettimeout, 0);
I 62
	SmtpPhase = "greeting wait";
E 62
E 53
E 49
E 47
E 3
E 2
D 4
	/* create connection (we hope) */
D 2
	f = rexec(&host, SHELLSERVER, cmdbuf, &MailUser, NULL);
E 2
I 2
	fd = rexec(&host, SHELLSERVER, cmdbuf, MailUser, MailPassword);
	if (fd < 0)
I 3
	{
		Status = EX_TEMPFAIL;
E 3
		return (-1);
I 3
	}
E 3
	InConnection = fdopen(fd, "r");
	OutConnection = fdopen(fd, "w");
	if (InConnection == NULL || OutConnection == NULL)
I 3
	{
		Status = EX_SOFTWARE;
E 3
		return (-1);
I 3
	}
E 4
I 4
D 38
	r = reply();
E 38
I 38
	r = reply(m);
I 47
	clrevent(gte);
E 47
E 38
D 22
	if (REPLYTYPE(r) != 2)
E 22
I 22
	if (r < 0 || REPLYTYPE(r) != 2)
E 22
D 49
		return (EX_TEMPFAIL);
E 49
I 49
		goto tempfail;
E 49
E 4
E 3
E 2

D 2
	return (f);
E 2
I 2
D 4
	if (Debug)
		printf("Connection open to %s\n", host);
E 4
I 4
	/*
I 5
	**  Send the HELO command.
D 20
	**	My mother taught me to always introduce myself, even
	**	if it is useless.
E 20
I 20
	**	My mother taught me to always introduce myself.
E 20
	*/

D 38
	smtpmessage("HELO %s", HostName);
	r = reply();
E 38
I 38
D 64
	smtpmessage("HELO %s", m, HostName);
E 64
I 64
	smtpmessage("HELO %s", m, MyHostName);
E 64
I 62
	SmtpPhase = "HELO wait";
E 62
	r = reply(m);
E 38
D 22
	if (REPLYTYPE(r) == 5)
E 22
I 22
	if (r < 0)
D 49
		return (EX_TEMPFAIL);
E 49
I 49
		goto tempfail;
E 49
	else if (REPLYTYPE(r) == 5)
E 22
D 49
		return (EX_UNAVAILABLE);
E 49
I 49
		goto unavailable;
E 49
D 20
	if (REPLYTYPE(r) != 2)
E 20
I 20
	else if (REPLYTYPE(r) != 2)
E 20
D 49
		return (EX_TEMPFAIL);
E 49
I 49
		goto tempfail;
E 49

	/*
I 28
	**  If this is expected to be another sendmail, send some internal
	**  commands.
	*/

D 43
	if (bitset(M_INTERNAL, m->m_flags))
E 43
I 43
	if (bitnset(M_INTERNAL, m->m_flags))
E 43
	{
		/* tell it to be verbose */
D 38
		smtpmessage("VERB");
		r = reply();
E 38
I 38
		smtpmessage("VERB", m);
		r = reply(m);
E 38
		if (r < 0)
D 49
			return (EX_TEMPFAIL);
E 49
I 49
			goto tempfail;
E 49

		/* tell it we will be sending one transaction only */
D 38
		smtpmessage("ONEX");
		r = reply();
E 38
I 38
		smtpmessage("ONEX", m);
		r = reply(m);
E 38
		if (r < 0)
D 49
			return (EX_TEMPFAIL);
E 49
I 49
			goto tempfail;
E 49
	}

	/*
E 28
I 14
	**  Send the HOPS command.
	**	This is non-standard and may give an "unknown command".
	**		This is not an error.
	**	It can give a "bad hop count" error if the hop
	**		count is exceeded.
	*/

	/*
E 14
E 5
	**  Send the MAIL command.
	**	Designates the sender.
	*/
E 4

D 4
	return (0);
E 4
I 4
D 10
	(void) expand("$g", buf, &buf[sizeof buf - 1]);
E 10
I 10
D 54
	expand("$g", buf, &buf[sizeof buf - 1], CurEnv);
E 54
I 54
	expand("\001g", buf, &buf[sizeof buf - 1], CurEnv);
E 54
E 10
D 18
	smtpmessage("MAIL From:<%s>", buf);
E 18
I 18
D 23
	smtpmessage("MAIL From: %s", canonname(buf));
E 23
I 23
D 24
	smtpmessage("MAIL From: <%s>", canonname(buf));
E 24
I 24
D 26
	smtpmessage("MAIL From:<%s>", canonname(buf));
E 26
I 26
D 27
	smtpmessage("MAIL From:<%s>", canonname(buf, 1));
E 27
I 27
	if (CurEnv->e_from.q_mailer == LocalMailer ||
D 38
	    !bitset(M_FULLSMTP, m->m_flags))
E 38
I 38
D 43
	    !bitset(M_FROMPATH, m->m_flags))
E 43
I 43
	    !bitnset(M_FROMPATH, m->m_flags))
E 43
E 38
	{
D 38
		smtpmessage("MAIL From:<%s>", canonname(buf, 1));
E 38
I 38
D 40
		smtpmessage("MAIL From:<%s>", m, canonname(buf, 1));
E 40
I 40
		smtpmessage("MAIL From:<%s>", m, buf);
E 40
E 38
	}
	else
	{
D 38
		smtpmessage("MAIL From:<@%s%c%s>", HostName,
			    buf[0] == '@' ? ',' : ':', canonname(buf, 1));
E 38
I 38
D 64
		smtpmessage("MAIL From:<@%s%c%s>", m, HostName,
E 64
I 64
		smtpmessage("MAIL From:<@%s%c%s>", m, MyHostName,
E 64
D 40
			buf[0] == '@' ? ',' : ':', canonname(buf, 1));
E 40
I 40
			buf[0] == '@' ? ',' : ':', buf);
E 40
E 38
	}
I 62
	SmtpPhase = "MAIL wait";
E 62
E 27
E 26
E 24
E 23
E 18
D 38
	r = reply();
E 38
I 38
	r = reply(m);
E 38
D 22
	if (REPLYTYPE(r) == 4)
E 22
I 22
	if (r < 0 || REPLYTYPE(r) == 4)
E 22
D 49
		return (EX_TEMPFAIL);
E 49
I 49
		goto tempfail;
E 49
D 20
	if (r != 250)
		return (EX_SOFTWARE);
	return (EX_OK);
E 20
I 20
	else if (r == 250)
		return (EX_OK);
	else if (r == 552)
D 49
		return (EX_UNAVAILABLE);
E 49
I 49
		goto unavailable;

	/* protocol error -- close up */
	smtpquit(m);
E 49
D 21
	return (EX_SOFTWARE);
E 21
I 21
	return (EX_PROTOCOL);
I 49

	/* signal a temporary failure */
  tempfail:
	smtpquit(m);
I 55
D 65
	CurEnv->e_flags &= ~EF_FATALERRS;
E 65
E 55
	return (EX_TEMPFAIL);

	/* signal service unavailable */
  unavailable:
	smtpquit(m);
	return (EX_UNAVAILABLE);
E 49
I 47
}


static
greettimeout()
{
	/* timeout reading the greeting message */
	longjmp(CtxGreeting, 1);
E 47
E 21
E 20
E 4
E 2
}
/*
I 3
D 4
**	CLOSECONNECTION -- close the connection to the SMTP server.
E 4
I 4
D 5
**  SMTPMRCP -- designate recipient.
E 5
I 5
**  SMTPRCPT -- designate recipient.
E 5
E 4
**
D 4
**	This routine also sends a handshake.
**
E 4
**	Parameters:
D 4
**		none.
E 4
I 4
**		to -- address of recipient.
I 38
**		m -- the mailer we are sending to.
E 38
E 4
**
**	Returns:
D 4
**		none.
E 4
I 4
**		exit status corresponding to recipient status.
E 4
**
**	Side Effects:
D 4
**		Closes the connection.
E 4
I 4
**		Sends the mail via SMTP.
E 4
*/

D 4
closeconnection()
E 4
I 4
D 5
smtpmrcp(to)
E 5
I 5
D 38
smtprcpt(to)
E 38
I 38
smtprcpt(to, m)
E 38
E 5
	ADDRESS *to;
I 38
	register MAILER *m;
E 38
E 4
{
	register int r;
I 18
D 40
	extern char *canonname();
E 40
I 40
	extern char *remotename();
E 40
E 18

I 9
D 31
	if (SmtpPid < 0)
		return (SmtpErrstat);

E 31
E 9
D 4
	message("QUIT");
E 4
I 4
D 5
	smtpmessage("MRCP To:<%s>", to->q_user);
E 5
I 5
D 18
	smtpmessage("RCPT To:<%s>", to->q_user);
E 18
I 18
D 23
	smtpmessage("RCPT To: %s", canonname(to->q_user));
E 23
I 23
D 24
	smtpmessage("RCPT To: <%s>", canonname(to->q_user));
E 24
I 24
D 26
	smtpmessage("RCPT To:<%s>", canonname(to->q_user));
E 26
I 26
D 38
	smtpmessage("RCPT To:<%s>", canonname(to->q_user, 2));
E 38
I 38
D 40
	smtpmessage("RCPT To:<%s>", m, canonname(to->q_user, 2));
E 40
I 40
	smtpmessage("RCPT To:<%s>", m, remotename(to->q_user, m, FALSE, TRUE));
E 40
E 38
E 26
E 24
E 23
E 18
E 5

I 62
	SmtpPhase = "RCPT wait";
E 62
E 4
D 38
	r = reply();
E 38
I 38
	r = reply(m);
E 38
I 4
D 22
	if (REPLYTYPE(r) == 4)
E 22
I 22
	if (r < 0 || REPLYTYPE(r) == 4)
E 22
		return (EX_TEMPFAIL);
D 20
	if (r != 250)
E 20
I 20
D 21
	else if (REPLYCLASS(r) == 5)
E 20
		return (EX_NOUSER);
E 21
E 4
D 20

D 4
	if (Debug)
		printf("Closing connection, reply = %d\n", r);
E 4
I 4
	return (EX_OK);
E 20
I 20
	else if (REPLYTYPE(r) == 2)
		return (EX_OK);
D 21
	return (EX_SOFTWARE);
E 21
I 21
	else if (r == 550 || r == 551 || r == 553)
		return (EX_NOUSER);
	else if (r == 552 || r == 554)
		return (EX_UNAVAILABLE);
	return (EX_PROTOCOL);
E 21
E 20
E 4
}
/*
E 3
D 4
**  RUNSMTP -- run the SMTP protocol over connection.
E 4
I 4
D 38
**  SMTPFINISH -- finish up sending all the SMTP protocol.
E 38
I 38
**  SMTPDATA -- send the data and clean up the transaction.
E 38
E 4
**
**	Parameters:
D 4
**		fr -- from person.
**		tolist -- list of recipients.
E 4
I 4
**		m -- mailer being sent to.
D 10
**		editfcn -- a function to call to output the
**			text of the message with.
E 10
I 10
**		e -- the envelope for this message.
E 10
E 4
D 2
**		mf -- mail connection file.
E 2
**
**	Returns:
D 4
**		none.
E 4
I 4
D 5
**		exit status corresponding to DOIT command.
E 5
I 5
**		exit status corresponding to DATA command.
E 5
E 4
**
**	Side Effects:
D 4
**		Sends the mail via SMTP.
E 4
I 4
**		none.
E 4
*/

I 3
D 4
# define REPLYTYPE(r)	((r) / 100)

E 3
D 2
runsmtp(fr, tolist, mf)
E 2
I 2
runsmtp(fr, tolist)
E 2
	char *fr;
	char **tolist;
E 4
I 4
D 10
smtpfinish(m, editfcn)
E 10
I 10
D 38
smtpfinish(m, e)
E 38
I 38
smtpdata(m, e)
E 38
E 10
	struct mailer *m;
D 10
	int (*editfcn)();
E 10
I 10
	register ENVELOPE *e;
E 10
E 4
D 2
	FILE *mf;
E 2
{
	register int r;
D 4
	register char **t;
	char buf[MAXLINE];
E 4

I 9
D 31
	if (SmtpPid < 0)
		return (SmtpErrstat);

E 31
E 9
D 3
	/* get greeting message */
E 3
I 3
	/*
D 4
	**  Get the greeting message.
	**	This should appear spontaneously.
	*/

E 3
D 2
	r = reply(mf);
E 2
I 2
	r = reply();
E 2
D 3
	if (r / 100 != 2)
E 3
I 3
	if (REPLYTYPE(r) != 2)
E 3
		return (EX_TEMPFAIL);

D 3
	/* send the mail command */
D 2
	fprintf(mf, "MAIL From:<%s>\r\n", fr);
	r = reply(mf);
E 2
I 2
	message("MAIL From:<%s>\r\n", fr);
E 3
I 3
	/*
	**  Send the MAIL command.
	**	Designates the sender.
	*/

	message("MAIL From:<%s>", fr);
E 3
	r = reply();
I 3
	if (REPLYTYPE(r) == 4)
		return (EX_TEMPFAIL);
E 3
E 2
	if (r != 250)
		return (EX_SOFTWARE);

D 3
	/* send the recipients */
E 3
I 3
	/*
	**  Send the recipients.
	*/

E 3
	for (t = tolist; *t != NULL; t++)
	{
D 2
		fprintf(mf, "MRCP To:<%s>\r\n", *t);
		r = reply(mf);
E 2
I 2
D 3
		message("MRCP To:<%s>\r\n", *t);
E 3
I 3
		message("MRCP To:<%s>", *t);
E 3
		r = reply();
I 3
		if (REPLYTYPE(r) == 4)
			return (EX_TEMPFAIL);
E 3
E 2
		if (r != 250)
			return (EX_NOUSER);
	}

D 3
	/* send the data */
D 2
	fprintf(mf, "DATA\r\n");
	r = reply(mf);
E 2
I 2
	message("DATA\r\n");
E 3
I 3
	/*
E 4
	**  Send the data.
D 38
	**	Dot hiding is done here.
E 38
I 38
	**	First send the command and check that it is ok.
	**	Then send the data.
	**	Follow it up with a dot to terminate.
	**	Finally get the results of the transaction.
E 38
	*/

D 4
	message("DATA");
E 4
I 4
D 38
	smtpmessage("DATA");
E 4
E 3
	r = reply();
E 38
I 38
	/* send the command and check ok to proceed */
	smtpmessage("DATA", m);
I 62
	SmtpPhase = "DATA wait";
E 62
	r = reply(m);
E 38
I 3
D 22
	if (REPLYTYPE(r) == 4)
E 22
I 22
	if (r < 0 || REPLYTYPE(r) == 4)
E 22
		return (EX_TEMPFAIL);
E 3
E 2
D 20
	if (r != 354)
E 20
I 20
	else if (r == 554)
		return (EX_UNAVAILABLE);
	else if (r != 354)
E 20
D 21
		return (EX_SOFTWARE);
E 21
I 21
		return (EX_PROTOCOL);
E 21
D 4
	while (fgets(buf, sizeof buf, stdin) != NULL)
	{
		/* change trailing newline to crlf */
		register char *p = index(buf, '\n');

		if (p != NULL)
			*p = '\0';
D 3
		if (buf[0] == '.')
D 2
			fprintf(mf, ".");
		fprintf(mf, "%s\r\n", buf);
E 2
I 2
			message(".");
		message("%s\r\n", buf);
E 3
I 3
		message("%s%s", buf[0] == '.' ? "." : "", buf);
E 3
E 2
	}
D 2
	fprintf(mf, ".\r\n");
	r = reply(mf);
E 2
I 2
D 3
	message(".\r\n");
E 3
I 3
	message(".");
E 4
I 4
D 10
	(*editfcn)(SmtpOut, m, TRUE);
E 10
I 10
D 34
	(*e->e_puthdr)(SmtpOut, m, CurEnv);
	fprintf(SmtpOut, "\n");
D 32
	(*e->e_putbody)(SmtpOut, m, TRUE);
E 32
I 32
	(*e->e_putbody)(SmtpOut, m, TRUE, CurEnv);
E 34
I 34
D 38
	(*e->e_puthdr)(SmtpOut, m, CurEnv, TRUE);
	fprintf(SmtpOut, "\r\n");
	(*e->e_putbody)(SmtpOut, m, TRUE, CurEnv, TRUE);
E 34
E 32
E 10
	smtpmessage(".");
E 4
E 3
	r = reply();
E 38
I 38

	/* now output the actual message */
	(*e->e_puthdr)(SmtpOut, m, CurEnv);
	putline("\n", SmtpOut, m);
	(*e->e_putbody)(SmtpOut, m, CurEnv);

	/* terminate the message */
D 39
	fprintf(SmtpOut, ".%s\n", bitset(M_CRLF, m->m_flags) ? "\r" : "");
	nmessage(Arpa_Info, ">>> .");
E 39
I 39
D 41
	fprintf(SmtpOut, ".%s", crlf(m));
E 41
I 41
	fprintf(SmtpOut, ".%s", m->m_eol);
E 41
	if (Verbose && !HoldErrs)
		nmessage(Arpa_Info, ">>> .");
E 39

	/* check for the results of the transaction */
I 62
	SmtpPhase = "result wait";
E 62
	r = reply(m);
E 38
I 3
D 22
	if (REPLYTYPE(r) == 4)
E 22
I 22
	if (r < 0 || REPLYTYPE(r) == 4)
E 22
		return (EX_TEMPFAIL);
E 3
E 2
D 20
	if (r != 250)
		return (EX_SOFTWARE);
D 5

D 3
	/* force delivery */
D 2
	fprintf(mf, "DOIT\r\n");
	r = reply(mf);
E 2
I 2
	message("DOIT\r\n");
E 3
I 3
	/*
	**  Make the actual delivery happen.
	*/

D 4
	message("DOIT");
E 4
I 4
	smtpmessage("DOIT");
E 4
E 3
	r = reply();
E 2
	if (r != 250)
		return (EX_TEMPFAIL);

E 5
D 2
	fprintf(mf, "QUIT\r\n");
	r = reply(mf);
E 2
I 2
D 3
	message("QUIT\r\n");
	r = reply();
E 2
	if (r != 221)
		return (EX_SOFTWARE);

E 3
	return (EX_OK);
E 20
I 20
	else if (r == 250)
		return (EX_OK);
	else if (r == 552 || r == 554)
		return (EX_UNAVAILABLE);
D 21
	return (EX_SOFTWARE);
E 21
I 21
	return (EX_PROTOCOL);
E 21
E 20
}
/*
I 4
**  SMTPQUIT -- close the SMTP connection.
**
**	Parameters:
D 52
**		name -- name of mailer we are quitting.
E 52
I 52
**		m -- a pointer to the mailer.
E 52
I 13
D 31
**		showresp -- if set, give a response message.
E 31
E 13
**
**	Returns:
**		none.
**
**	Side Effects:
**		sends the final protocol and closes the connection.
*/

D 13
smtpquit(name)
E 13
I 13
D 31
smtpquit(name, showresp)
E 31
I 31
D 38
smtpquit(name)
E 38
I 38
D 52
smtpquit(name, m)
E 38
E 31
E 13
	char *name;
E 52
I 52
smtpquit(m)
E 52
I 38
	register MAILER *m;
E 38
I 13
D 31
	bool showresp;
E 31
E 13
{
D 31
	register int i;
E 31
I 31
	int i;
E 31

D 9
	smtpmessage("QUIT");
	(void) reply();
	(void) fclose(SmtpIn);
	(void) fclose(SmtpOut);
	i = endmailer(SmtpPid, name);
E 9
I 9
D 31
	if (SmtpPid < 0)
E 31
I 31
D 36
	if (SmtpClosing)
	{
		SmtpClosing = FALSE;
E 36
I 36
	/* if the connection is already closed, don't bother */
	if (SmtpIn == NULL)
E 36
E 31
D 13
	{
		i = SmtpErrstat;
	}
	else
	{
		smtpmessage("QUIT");
		(void) reply();
		(void) fclose(SmtpIn);
		(void) fclose(SmtpOut);
		i = endmailer(SmtpPid, name);
	}
E 9
	giveresponse(i, TRUE, LocalMailer);
E 13
I 13
		return;
I 36

	/* send the quit message if not a forced quit */
D 44
	if (!SmtpClosing)
E 44
I 44
	if (SmtpState == SMTP_OPEN || SmtpState == SMTP_SSD)
E 44
	{
D 38
		smtpmessage("QUIT");
		(void) reply();
E 38
I 38
		smtpmessage("QUIT", m);
		(void) reply(m);
E 38
I 37
D 44
		if (SmtpClosing)
E 44
I 44
		if (SmtpState == SMTP_CLOSED)
E 44
			return;
E 37
E 36
I 31
	}

E 31
D 36
	smtpmessage("QUIT");
D 31
	(void) reply();
E 31
I 31
	i = reply();
	if (i != 221)
		syserr("smtpquit %s: reply %d", name, i);
E 36
I 36
	/* now actually close the connection */
E 36
E 31
	(void) fclose(SmtpIn);
	(void) fclose(SmtpOut);
I 36
	SmtpIn = SmtpOut = NULL;
I 44
	SmtpState = SMTP_CLOSED;
E 44

	/* and pick up the zombie */
E 36
D 52
	i = endmailer(SmtpPid, name);
E 52
I 52
	i = endmailer(SmtpPid, m->m_argv[0]);
E 52
D 31
	if (showresp)
D 30
		giveresponse(i, TRUE, LocalMailer);
E 30
I 30
		giveresponse(i, LocalMailer);
E 31
I 31
	if (i != EX_OK)
D 52
		syserr("smtpquit %s: stat %d", name, i);
E 52
I 52
		syserr("smtpquit %s: stat %d", m->m_argv[0], i);
E 52
E 31
E 30
E 13
}
/*
E 4
**  REPLY -- read arpanet reply
**
**	Parameters:
D 2
**		mf -- mail file.
E 2
I 2
D 38
**		none.
E 38
I 38
**		m -- the mailer we are reading the reply from.
E 38
E 2
**
**	Returns:
**		reply code it reads.
**
**	Side Effects:
**		flushes the mail file.
*/

D 2
reply(mf)
	FILE *mf;
E 2
I 2
D 38
reply()
E 38
I 38
reply(m)
I 43
	MAILER *m;
E 43
E 38
E 2
{
D 2
	fflush(mf);
E 2
I 2
D 4
	fflush(OutConnection);
E 4
I 4
	(void) fflush(SmtpOut);
E 4
E 2

I 2
D 17
	if (Debug)
E 17
I 17
	if (tTd(18, 1))
E 17
		printf("reply\n");

E 2
D 15
	/* read the input line */
E 15
I 15
	/*
	**  Read the input line, being careful not to hang.
	*/

E 15
	for (;;)
	{
D 31
		char buf[MAXLINE];
E 31
		register int r;
I 15
		register char *p;
E 15

D 2
		if (fgets(buf, sizeof buf, mf) == NULL)
E 2
I 2
D 4
		if (fgets(buf, sizeof buf, InConnection) == NULL)
E 4
I 4
D 15
		if (fgets(buf, sizeof buf, SmtpIn) == NULL)
E 15
I 15
D 18
		/* arrange to time out the read */
E 18
I 18
		/* actually do the read */
E 18
I 16
D 17
		fflush(Xscript);			/* for debugging */
E 17
I 17
D 29
		(void) fflush(Xscript);			/* for debugging */
E 29
I 29
D 32
		if (Xscript != NULL)
			(void) fflush(Xscript);		/* for debugging */
E 32
I 32
		if (CurEnv->e_xfp != NULL)
			(void) fflush(CurEnv->e_xfp);	/* for debugging */
E 32
E 29
E 17
E 16
D 18
		if (setjmp(TickFrame) != 0)
E 15
E 4
E 2
			return (-1);
I 15
		(void) alarm(ReadTimeout);
E 18
I 18
D 31
		p = sfgets(buf, sizeof buf, SmtpIn);
E 18
D 25

E 25
D 18
		/* actually do the read */
		p = fgets(buf, sizeof buf, SmtpIn);

		/* clean up timeout and check for errors */
		(void) alarm(0);
E 18
		if (p == NULL)
			return (-1);
I 25
		fixcrlf(buf, TRUE);
E 31
I 31
D 33
		if (!SmtpClosing)
		{
			p = sfgets(SmtpReplyBuffer, sizeof SmtpReplyBuffer, SmtpIn);
			if (p == NULL)
				return (-1);
			fixcrlf(SmtpReplyBuffer, TRUE);
		}
E 33
E 31
E 25

I 33
		/* if we are in the process of closing just give the code */
D 44
		if (SmtpClosing)
E 44
I 44
		if (SmtpState == SMTP_CLOSED)
E 44
			return (SMTPCLOSING);

		/* get the line from the other side */
		p = sfgets(SmtpReplyBuffer, sizeof SmtpReplyBuffer, SmtpIn);
		if (p == NULL)
I 35
		{
D 36
			syserr("reply: read error");
E 36
I 36
			extern char MsgBuf[];		/* err.c */
			extern char Arpa_TSyserr[];	/* conf.c */

I 57
			/* if the remote end closed early, fake an error */
			if (errno == 0)
# ifdef ECONNRESET
				errno = ECONNRESET;
# else ECONNRESET
				errno = EPIPE;
# endif ECONNRESET

E 57
			message(Arpa_TSyserr, "reply: read error");
I 42
# ifdef DEBUG
			/* if debugging, pause so we can see state */
			if (tTd(18, 100))
				pause();
# endif DEBUG
E 42
# ifdef LOG
D 56
			syslog(LOG_ERR, "%s", &MsgBuf[4]);
E 56
I 56
D 61
			syslog(LOG_MAIL, "%s", &MsgBuf[4]);
E 61
I 61
			syslog(LOG_ERR, "%s", &MsgBuf[4]);
E 61
E 56
# endif LOG
D 44
			SmtpClosing = TRUE;
E 44
I 44
			SmtpState = SMTP_CLOSED;
E 44
D 38
			smtpquit("reply error");
E 38
I 38
D 52
			smtpquit("reply error", m);
E 52
I 52
			smtpquit(m);
E 52
E 38
E 36
E 35
			return (-1);
I 35
		}
E 35
		fixcrlf(SmtpReplyBuffer, TRUE);

E 33
D 48
		/* log the input in the transcript for future error returns */
E 48
I 48
		if (CurEnv->e_xfp != NULL && index("45", SmtpReplyBuffer[0]) != NULL)
		{
			/* serious error -- log the previous command */
			if (SmtpMsgBuffer[0] != '\0')
				fprintf(CurEnv->e_xfp, ">>> %s\n", SmtpMsgBuffer);
			SmtpMsgBuffer[0] = '\0';

			/* now log the message as from the other side */
			fprintf(CurEnv->e_xfp, "<<< %s\n", SmtpReplyBuffer);
		}

		/* display the input for verbose mode */
E 48
E 15
D 13
		if (Verbose)
E 13
I 13
		if (Verbose && !HoldErrs)
E 13
D 25
			fputs(buf, stdout);
I 13
		fputs(buf, Xscript);
E 25
I 25
D 31
			nmessage(Arpa_Info, "%s", buf);
E 31
I 31
			nmessage(Arpa_Info, "%s", SmtpReplyBuffer);
E 31
D 29
		fprintf(Xscript, "%s\n", buf);
E 29
I 29
D 32
		if (Xscript != NULL)
D 31
			fprintf(Xscript, "%s\n", buf);
E 31
I 31
			fprintf(Xscript, "%s\n", SmtpReplyBuffer);
E 32
I 32
D 35
		if (CurEnv->e_xfp != NULL)
E 35
I 35
D 48
		else if (CurEnv->e_xfp != NULL)
E 35
			fprintf(CurEnv->e_xfp, "%s\n", SmtpReplyBuffer);
E 48
E 32
E 31
E 29
E 25
I 15

		/* if continuation is required, we can go on */
E 15
E 13
D 2
		if (buf[3] == '-')
E 2
I 2
D 31
		if (buf[3] == '-' || !isdigit(buf[0]))
E 31
I 31
		if (SmtpReplyBuffer[3] == '-' || !isdigit(SmtpReplyBuffer[0]))
E 31
E 2
			continue;
I 15

		/* decode the reply code */
E 15
D 31
		r = atoi(buf);
E 31
I 31
		r = atoi(SmtpReplyBuffer);
E 31
I 15

		/* extra semantics: 0xx codes are "informational" */
E 15
		if (r < 100)
			continue;
I 15

I 31
		/* reply code 421 is "Service Shutting Down" */
D 33
		if (r == SMTPCLOSING && !SmtpClosing)
E 33
I 33
D 44
		if (r == SMTPCLOSING)
E 44
I 44
		if (r == SMTPCLOSING && SmtpState != SMTP_SSD)
E 44
E 33
		{
I 33
			/* send the quit protocol */
I 44
			SmtpState = SMTP_SSD;
E 44
E 33
D 38
			smtpquit("SMTP Shutdown");
E 38
I 38
D 52
			smtpquit("SMTP Shutdown", m);
E 52
I 52
			smtpquit(m);
E 52
E 38
D 44
			SmtpClosing = TRUE;
E 44
		}
I 57

		/* save temporary failure messages for posterity */
		if (SmtpReplyBuffer[0] == '4' && SmtpError[0] == '\0')
			(void) strcpy(SmtpError, &SmtpReplyBuffer[4]);
E 57

E 31
E 15
		return (r);
	}
I 2
}
/*
D 4
**  MESSAGE -- send message to server
E 4
I 4
**  SMTPMESSAGE -- send message to server
E 4
**
**	Parameters:
**		f -- format
I 38
**		m -- the mailer to control formatting.
E 38
**		a, b, c -- parameters
**
**	Returns:
**		none.
**
**	Side Effects:
D 4
**		writes message to OutChannel.
E 4
I 4
**		writes message to SmtpOut.
E 4
*/

D 4
message(f, a, b, c)
E 4
I 4
/*VARARGS1*/
D 38
smtpmessage(f, a, b, c)
E 38
I 38
smtpmessage(f, m, a, b, c)
E 38
E 4
	char *f;
I 38
	MAILER *m;
E 38
{
D 45
	char buf[100];
E 45
I 45
D 48
	char buf[MAXLINE];
E 45

D 4
	sprintf(buf, f, a, b, c);
E 4
I 4
	(void) sprintf(buf, f, a, b, c);
E 48
I 48
	(void) sprintf(SmtpMsgBuffer, f, a, b, c);
E 48
E 4
I 3
D 12
	strcat(buf, "\r\n");
E 12
I 12
D 13
	(void) strcat(buf, "\r\n");
E 12
E 3
	if (Debug)
		fputs(buf, stdout);
D 4
	fputs(buf, OutConnection);
E 4
I 4
	fputs(buf, SmtpOut);
E 13
I 13
D 17
	if (Debug || (Verbose && !HoldErrs))
E 17
I 17
	if (tTd(18, 1) || (Verbose && !HoldErrs))
E 17
D 25
		printf(">>> %s\n", buf);
	fprintf(Xscript, ">>> %s\n", buf);
E 25
I 25
D 48
		nmessage(Arpa_Info, ">>> %s", buf);
D 29
	fprintf(Xscript, " >>> %s\n", buf);
E 29
I 29
D 32
	if (Xscript != NULL)
		fprintf(Xscript, ">>> %s\n", buf);
E 32
I 32
D 35
	if (CurEnv->e_xfp != NULL)
E 35
I 35
	else if (CurEnv->e_xfp != NULL)
E 35
		fprintf(CurEnv->e_xfp, ">>> %s\n", buf);
E 48
I 48
		nmessage(Arpa_Info, ">>> %s", SmtpMsgBuffer);
E 48
E 32
E 29
E 25
D 31
	fprintf(SmtpOut, "%s\r\n", buf);
E 31
I 31
D 44
	if (!SmtpClosing)
E 44
I 44
	if (SmtpOut != NULL)
E 44
D 38
		fprintf(SmtpOut, "%s\r\n", buf);
E 38
I 38
D 39
		fprintf(SmtpOut, "%s%s\n", bitset(M_CRLF, m->m_flags) ? "\r" : "", buf);
E 39
I 39
D 41
		fprintf(SmtpOut, "%s%s", buf, crlf(m));
E 41
I 41
D 48
		fprintf(SmtpOut, "%s%s", buf, m->m_eol);
E 48
I 48
		fprintf(SmtpOut, "%s%s", SmtpMsgBuffer, m->m_eol);
E 48
E 41
E 39
E 38
E 31
E 13
E 4
E 2
}
I 6

# endif SMTP
E 6
E 1
