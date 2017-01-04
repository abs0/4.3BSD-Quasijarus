h17185
s 00004/00002/00722
d D 5.25 04/04/23 16:00:35 msokolov 90 89
c don't needlessly duplicate numeric IP address in the comment if it didn't
c resolve in the first place
e
s 00006/00000/00718
d D 5.24 04/04/23 15:28:59 msokolov 89 88
c add R option to disable relaying service for Internet senders
e
s 00041/00014/00677
d D 5.23 02/05/29 21:58:03 msokolov 88 87
c preserve the numeric IP address of origin in the traces left by a message
c (it would now normally appear as a (comment) in CurHostName and $s)
e
s 00011/00009/00680
d D 5.22 88/06/30 14:59:49 bostic 87 86
c install approved copyright notice
e
s 00024/00018/00665
d D 5.21 88/03/13 19:53:16 bostic 86 85
c add Berkeley specific header
e
s 00004/00006/00679
d D 5.20 88/03/13 18:21:50 bostic 85 84
c replace sameword with strcasecmp
e
s 00006/00003/00679
d D 5.19 87/02/03 20:43:52 eric 84 83
c pass sending hostname correctly back via the $s macro (broken sometime
c earlier); hack around some name server changes
e
s 00004/00000/00678
d D 5.18 86/01/05 18:49:17 eric 83 82
m 
c rewrite reply-to and resent-reply-to; save errorqueueu in qf file;
c some performance hacking; some alias handling cleanup; delete leading
c spaces from SMTP lines
e
s 00001/00001/00677
d D 5.17 85/12/17 21:36:21 eric 82 81
m 
c patch to clearenvelope to avoid dereferencing garbage pointers
e
s 00021/00011/00657
d D 5.16 85/09/30 21:34:35 eric 81 80
m 
c clean up some aspects of error message display
e
s 00001/00000/00667
d D 5.15 85/09/23 21:19:01 eric 80 79
m 
c deliver directly in SMTP if VERB command has been issued; don't
c externalize name using ruleset 4 when defining $f macro: this turns "<>"
c into "", which confuses local mail
e
s 00009/00009/00658
d D 5.14 85/09/21 16:35:30 eric 79 78
m 
c yet more cleanup to the process title code
e
s 00001/00001/00666
d D 5.13 85/09/21 15:01:28 eric 78 77
m 
c fix silly botch in SMTP command decoding
e
s 00016/00017/00651
d D 5.12 85/09/21 14:44:30 eric 77 76
m 
c clean up priority handling, making several of the parameters configurable:
c y - WkRecipFact, z - WkClassFact, Z - WkTimeFact, Y - ForkQueueRuns; improve
c process title labelling; finish "errors to postmaster" option
e
s 00007/00000/00661
d D 5.11 85/09/20 09:43:17 eric 76 75
m 
c print cute labels on programs communicating with SMTP
e
s 00004/00000/00657
d D 5.10 85/09/19 23:16:20 eric 75 74
m 
c label child processes more effectively
e
s 00002/00004/00655
d D 5.9 85/09/19 13:35:58 eric 74 73
m 
c lint
e
s 00000/00000/00659
d D 5.8 85/09/19 01:25:35 eric 73 71
i 72
m 
c incorporate SMI changes -- still experimental
e
s 00019/00003/00633
d D 5.5.1.1 85/09/19 00:55:47 eric 72 69
m 
c SMI changes (somewhat)
e
s 00013/00004/00630
d D 5.7 85/09/03 19:50:02 eric 71 70
m 
c Wander WIZ from weariful DEBUG to wonderful WIZ woption
e
s 00001/00003/00633
d D 5.6 85/07/31 15:51:12 miriam 70 69
m 
c Correct the cleaning up of tmp queue files. - Kirk Smith @ Purdue
e
s 00003/00000/00633
d D 5.5 85/06/17 18:52:21 eric 69 68
m 
c From Bill Nowicki: fixes to the statistics
e
s 00004/00000/00629
d D 5.4 85/06/08 10:30:29 eric 68 67
m 
c lint for 4.3 release
e
s 00001/00001/00628
d D 5.3 85/06/08 00:34:15 eric 67 66
m 
c lint
e
s 00002/00005/00627
d D 5.2 85/06/07 22:18:08 miriam 66 65
m 
c Resolve duplicate SccsId
e
s 00014/00000/00618
d D 5.1 85/06/07 15:14:21 dist 65 64
m 
c Add copyright
e
s 00004/00027/00614
d D 4.11 85/04/28 10:43:10 eric 64 63
m 
c remove #ifdef DEBUG so we can compile without #define DEBUG;
c drop SHELL command
e
s 00000/00002/00641
d D 4.10 84/08/18 10:28:23 eric 63 62
m 
c take WizWord off of compilation flag to avoid undefined refs
e
s 00002/00001/00641
d D 4.9 84/08/11 16:54:29 eric 62 61
m 
c Changes from Greg Couch <ucsfcgl!gregc> for V7 compatibility and
c miscellaneous bug fixes; "clear" => "bzero" and "bmove" => "bcopy"
c throughout for consistency; bzero is now in bcopy.c (these are
c supplied by libc on 4.2bsd)
e
s 00030/00028/00612
d D 4.8 84/03/11 19:40:44 eric 61 60
m 
c Remember to open the alias file if the ONEX command is specified.
e
s 00001/00001/00639
d D 4.7 84/03/11 16:55:05 eric 60 59
m 
c change macro expansion character from $ to \001 so that $'s can be
c used in headers -- the .cf file is unchanged by mapping $ to \001.
c \001 is now a manifest constant.
e
s 00001/00001/00639
d D 4.6 84/03/11 13:38:14 eric 59 58
m 
c fixes from Greg Satz <satz@sri-tsc.ARPA>, mostly for PDP's
e
s 00005/00005/00635
d D 4.5 83/11/26 18:52:35 eric 58 57
m 
c fix SERIOUS bug allowing anyone to be "wiz" without a password
c if the configuration was frozen
e
s 00004/00000/00636
d D 4.4 83/10/16 16:07:52 eric 57 56
m 
c Postpone opening the alias DBM file until after the fork in srvrsmtp so
c that the alias database is as current as possible; thanks to dagobah!efo
c (Eben Ostby) for this one.
e
s 00008/00001/00628
d D 4.3 83/08/28 14:45:21 eric 56 55
m 
c Refuse to talk to yourself (i.e., reject HELO packets with your own name).
c Add two thresholds -- option 'x' is the load average at which messages are
c queued rather than delivered (default 12); option 'X' is the load average
c at which incoming TCP connections are refused (default 25).
e
s 00003/00001/00626
d D 4.2 83/08/21 15:13:19 eric 55 54
m 
c Don't send back a separate error message if we have diagnosed an RCPT.
e
s 00000/00000/00627
d D 4.1 83/07/25 19:45:54 eric 54 53
m 
c 4.2 release version
e
s 00027/00007/00600
d D 3.50 83/05/20 11:48:48 eric 53 52
m 238
m 239
c Don't stack processes when VRFY fails.
c Give an error message on multiple RCPT commands with a bad address.
e
s 00002/00000/00605
d D 3.49 83/04/17 17:12:25 eric 52 51
m 199
m 221
c put true current time on SMTP greeting message; fix bogus errno problems
e
s 00001/00000/00604
d D 3.48 83/03/26 14:27:30 eric 51 50
m 214
c changes from MRH for USG UNIX 5.0
e
s 00005/00000/00599
d D 3.47 83/02/18 14:10:56 eric 50 48
m 183
c improve hostname validation: force it even if no HELO command is given.
e
s 00004/00000/00599
d R 3.47 83/02/18 13:11:44 eric 49 48
m 183
c Improve host verification -- put something in even if no HELO command given
e
s 00011/00001/00588
d D 3.46 83/02/18 12:42:18 eric 48 47
m 183
c Add HELO hostname verification
e
s 00002/00002/00587
d D 3.45 83/02/03 10:29:26 eric 47 46
m 160
c $e macro is now SMTP entry message (so that configuration version can
c be included).
e
s 00004/00001/00585
d D 3.44 83/01/16 22:07:12 eric 46 45
m 
c fix SHELL command; CR's on end of lines are still a problem, but....
e
s 00005/00000/00581
d D 3.43 83/01/08 13:48:57 eric 45 44
m 
c be sure to open a new transcript on every queue run; when returning
c an SMTP transcript, only send the last half (i.e., that part which
c describes the sending half).
e
s 00002/00002/00579
d D 3.42 82/12/13 18:26:01 eric 44 43
m 085
c The routine "sendto" is now a system call (yeuch!); change our sendto
c to "sendtolist"
e
s 00003/00002/00578
d D 3.41 82/12/05 13:46:55 eric 43 42
m 092
c Clear the envelope in the child in server SMTP to insure that our oh so
c helpful parent doesn't delete our transcript; move the transcript and
c temporary file pointers into the envelope; pass the envelope to other
c routines in the holy war against global variables; split off envelope
c routines from main.c to envelope.c
e
s 00002/00003/00578
d D 3.40 82/11/28 16:01:13 eric 42 41
m 
c implement SMTP auto-shutdown on 421 codes; clean up some error processing
c items, particularly in SMTP; don't reinstantiate error message bodies after
c queueing; other minor changes.  This is all cleanup from 3.253.
e
s 00028/00013/00553
d D 3.39 82/11/28 00:22:56 eric 41 40
m 
c Many changes resulting from a complete code readthrough.  Most of these
c fix minor bugs or change the internal structure for clarity, etc.  There
c should be almost no externally visible changes (other than some cleaner
c error message printouts and the like).
e
s 00002/00004/00564
d D 3.38 82/11/24 18:44:50 eric 40 39
m 
c lint it
e
s 00115/00051/00453
d D 3.37 82/11/24 17:16:00 eric 39 38
m 026
c run SMTP jobs in a subprocess so that multiple jobs will work.  This
c delta also changes the envelope data structure so that flags are in
c a bit map, and adjusts some of the semantics.  The transcript is now
c local to an envelope.  A bunch of old code is deleted.  A serious bug
c was fixed in the "run in background" code.  Etc., etc.
e
s 00012/00000/00492
d D 3.36 82/11/21 17:19:16 eric 38 37
m 026
c preliminary hacks for multiple SMTP transactions per connection: make
c assignment of multiple queue id's more efficient, make prefixes two
c characters (e.g., qfAA99999), pass the file name to freeze and thaw,
c add a mailer flag saying we are talking to one of our own kind.
e
s 00002/00002/00490
d D 3.35 82/11/17 09:37:15 eric 37 36
m 060
c split operation mode ("-bx" flag) and delivery mode ("d" option)
c so that operation mode can apply to SMTP/daemon connections also.
e
s 00065/00015/00427
d D 3.34 82/10/16 14:43:55 eric 36 35
m 007
c Arrange for a wizards password (the W option).  The SMTP KILL command
c may only be issued if this option is set.  This delta adds the "WIZ"
c command, and changes _KILL => KILL, _DEBUG => DEBUG, _VERBOSE => VERB,
c and _SHOWQ => SHOWQ.
e
s 00001/00003/00441
d D 3.33 82/09/26 17:04:31 eric 35 34
c Put more configuration into setoption; merge some of the argv processing
c with this; move configuration information out of conf.c into the .cf
c file.  Since a lot of stuff will default to zero, a new .cf file is
c required.
e
s 00022/00006/00422
d D 3.32 82/09/21 10:12:57 eric 34 33
c avoid double error messages (one from each end)
e
s 00002/00002/00426
d D 3.31 82/09/06 16:25:07 eric 33 32
c install new state-driven scanner; make everyone use it, thus fixing
c problems of quoted commas, etc.
e
s 00001/00001/00427
d D 3.30 82/08/22 23:07:19 eric 32 31
c change $i to $j; $i is now queue id; put "Received:" format in .cf
c file; minor cleanup
e
s 00000/00006/00428
d D 3.29 82/08/21 17:54:46 eric 31 30
c move <> and forward path processing to .cf file; increase MAXATOMS
c since some "comment" information may now be part of the address.
c **** this installation requires a new sendmail.cf file ****
e
s 00002/00001/00432
d D 3.28 82/08/20 20:34:34 eric 30 29
c time stamp the greeting message
e
s 00006/00000/00427
d D 3.27 82/08/15 17:33:11 eric 29 28
c make VRFY and EXPN work more correctly (VRFY still gives an OK even
c if the target is a list); this adds the QuickAbort option
e
s 00000/00001/00427
d D 3.26 82/08/08 21:15:52 eric 28 27
c make "sleep" work correctly even in the face of other events; clean
c up the queue processing: child queue runs now go away when done.  more
c debugging logging is needed to verify that this works right though.
e
s 00004/00013/00424
d D 3.25 82/08/08 17:02:45 eric 27 26
c more general event mechanism
e
s 00003/00002/00434
d D 3.24 82/08/08 01:03:12 eric 26 25
c change debug level to a debug vector; add levels on logging (and the
c -L flag); change logging to be by message-id; elevate message-id;
c some lint-type cleanup
e
s 00001/00001/00435
d D 3.23 82/07/27 23:03:14 eric 25 24
c improve verbose information to make it more obvious what is going where
e
s 00006/00002/00430
d D 3.22 82/07/05 13:18:54 eric 24 23
c fix bug in interactive SMTP session (i.e., non-daemon)
e
s 00018/00001/00414
d D 3.21 82/07/05 12:02:58 eric 23 21
c put timeouts on net reads
e
s 00010/00000/00415
d D 3.20.1.1 82/07/04 10:28:28 eric 22 21
c do some stuff to add a "HOPS" command -- it seems like it would
c be easier and smarter to count Mail-From: lines.
e
s 00002/00002/00413
d D 3.20 82/06/26 13:10:47 eric 21 20
c lint
e
s 00009/00000/00406
d D 3.19 82/06/26 11:56:57 eric 20 19
c add _kill command to SMTP.  this is probably dangerous in the
c outside world.
e
s 00019/00002/00387
d D 3.18 82/06/25 19:38:29 eric 19 18
c add debugging information to server smtp code: _debug to set
c Debug, _verbose to set verbose, and _showq to show the send queue
c (already existant, just a name change)
e
s 00002/00001/00387
d D 3.17 82/06/07 23:55:51 eric 18 17
c call the routine putline to output lines to mailers.  this lets us
c implement line length limits, etc. for full SMTP compatibility.
e
s 00001/00001/00387
d D 3.16 82/06/06 23:05:44 eric 17 16
c implement alias owner feature.  this actually works for any user.
c basically, if the alias owner-xxx exists, errors sending to xxx will be
c sent to that alias rather than to the sender.
e
s 00005/00005/00383
d D 3.15 82/05/22 01:38:52 eric 16 15
c add "envelopes" to contain the basic information needed as control
c info for each message.  currently there is only one envelope -- this
c being the obvious stupid conversion.  later there will be separate
c envelopes for error messages, return receipts, etc.
e
s 00001/00001/00387
d D 3.14 82/03/06 14:51:39 eric 15 14
c tell what recipient is ok when you say it is ok.
e
s 00002/00003/00386
d D 3.13 81/12/06 12:39:44 eric 14 13
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00001/00000/00388
d D 3.12 81/12/05 14:14:36 eric 13 12
c insert SMTP "Mail-From:" line.
e
s 00006/00000/00382
d D 3.11 81/12/05 11:54:05 eric 12 11
c put the SMTP and queueing code on compilation flags so that sendmail
c will fit on non-ID PDP-11's (ugh); put the ugly UUCP hack on a
c compilation flag also to emphasize that it sucks eggs; makefile
c cleanup.
e
s 00041/00004/00341
d D 3.10 81/11/21 18:43:21 eric 11 10
c change the send queue to be only one queue instead of one per mailer.
c this is slightly inefficient but simpler.  also, pass this queue
c around so we can have multiple send queues.  this makes VRFY work.
e
s 00003/00004/00342
d D 3.9 81/11/21 16:38:37 eric 10 8
c convert to SMTP draft 3 -- finishing touches.  Punt on the VRFY/
c EXPN commands for now; they aren't required anyhow.  Move the fullname
c into the address structure so it can be inherited.
e
s 00064/00006/00340
d D 3.8.1.1 81/11/21 15:49:43 eric 9 8
c links together aliases into proper trees.  This is in part an
c attempt to do the SMTP VRFY command properly, but there are a number
c of annoying problems that convince me that this is the wrong way to
c do it.  Sigh.
e
s 00035/00025/00311
d D 3.8 81/11/21 09:58:01 eric 8 7
c convert to SMTP draft 3
e
s 00014/00007/00322
d D 3.7 81/10/31 22:13:17 eric 7 6
c drop old NCP stuff for ARPANET handling; fix some bugs in error
c messages with multiple recipients in SMTP; clean up error handling
e
s 00003/00003/00326
d D 3.6 81/10/26 14:23:28 eric 6 5
c Install new experimental queueing facility -- one stage timeout,
c etc.  This version is still quite incomplete.  It needs to reorder
c the queue after some interval, do two-stage timeout, take option
c info from the queue file instead of the command line, read the
c sender's .mailcf file, etc.  Some of this is useful for SMTP also.
e
s 00002/00001/00327
d D 3.5 81/10/22 10:25:34 eric 5 4
c move stats file to /usr/lib; put location of sendmail.hf in conf.c
e
s 00090/00008/00238
d D 3.4 81/10/22 09:14:34 eric 4 3
c implement HELP and MRSQ -- MRSQ is a partial implementation
c of old MTP -- in particular, To: fields in MAIL commands are not yet
c implemented.  The "message" routine now takes first args of the form
c "999-" to specify continuation.
e
s 00014/00014/00232
d D 3.3 81/10/20 11:36:54 eric 3 2
c clean up the SMTP stuff some more
e
s 00002/00000/00244
d D 3.2 81/10/20 00:14:53 eric 2 1
c add id keywords
e
s 00244/00000/00000
d D 3.1 81/10/19 22:24:47 eric 1 0
c date and time created 81/10/19 22:24:47 by eric
e
u
U
f b 
f i 
t
T
I 65
/*
I 87
 * Copyright (c) 1983 Eric P. Allman
E 87
D 86
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 86
I 86
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 87
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 87
I 87
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
E 87
 */
E 86

I 86
# include "sendmail.h"
E 86
D 66
#ifndef lint
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint
E 66

I 86
#ifndef lint
#ifdef SMTP
static char sccsid[] = "%W% (Berkeley) %G% (with SMTP)";
#else
static char sccsid[] = "%W% (Berkeley) %G% (without SMTP)";
#endif
#endif /* not lint */

E 86
E 65
I 39
# include <errno.h>
E 39
I 1
D 86
# include "sendmail.h"
E 86
I 51
# include <signal.h>
E 51

I 12
D 86
# ifndef SMTP
I 68
# ifndef lint
E 68
D 14
static char	SccsId[] =	"%W%	%G%	(no SMTP)";
E 14
I 14
D 66
SCCSID(%W%	%Y%	%G%	(no SMTP));
E 66
I 66
static char	SccsId[] = "%W% (Berkeley) %G%	(no SMTP)";
I 68
# endif not lint
E 68
E 66
E 14
# else SMTP

I 68
# ifndef lint
E 68
E 12
I 2
D 14
static char	SccsId[] =	"%W%	%G%";
E 14
I 14
D 66
SCCSID(%W%	%Y%	%G%);
E 66
I 66
static char	SccsId[] = "%W% (Berkeley) %G%";
I 68
# endif not lint
E 86
I 86
# ifdef SMTP
E 86
E 68
E 66
E 14

E 2
/*
**  SMTP -- run the SMTP protocol.
**
**	Parameters:
**		none.
**
**	Returns:
**		never.
**
**	Side Effects:
**		Reads commands from the input channel and processes
**			them.
*/

struct cmd
{
	char	*cmdname;	/* command name */
	int	cmdcode;	/* internal code, see below */
};

/* values for cmdcode */
# define CMDERROR	0	/* bad command */
# define CMDMAIL	1	/* mail -- designate sender */
D 8
# define CMDMRCP	2	/* mrcp -- designate recipient */
E 8
I 8
# define CMDRCPT	2	/* rcpt -- designate recipient */
E 8
# define CMDDATA	3	/* data -- send message text */
I 22
# define CMDHOPS	4	/* hops -- specify hop count */
E 22
D 8
# define CMDDOIT	4	/* doit -- actually do delivery */
E 8
D 39
# define CMDRSET	5	/* rset -- reset state */
# define CMDVRFY	6	/* vrfy -- verify address */
# define CMDHELP	7	/* help -- give usage info */
# define CMDNOOP	8	/* noop -- do nothing */
# define CMDQUIT	9	/* quit -- close connection and die */
I 4
# define CMDMRSQ	10	/* mrsq -- for old mtp compat only */
I 8
# define CMDHELO	11	/* helo -- be polite */
I 11
D 19
# define CMDDBGSHOWQ	12	/* showq -- show send queue (DEBUG) */
E 19
I 19
D 36
# define CMDDBGSHOWQ	12	/* _showq -- show send queue (DEBUG) */
# define CMDDBGDEBUG	13	/* _debug -- set debug mode */
# define CMDDBGVERBOSE	14	/* _verbose -- go into verbose mode */
I 20
# define CMDDBGKILL	15	/* _kill -- kill sendmail */
E 36
I 36
# define CMDDBGSHOWQ	12	/* showq -- show send queue (DEBUG) */
# define CMDDBGDEBUG	13	/* debug -- set debug mode */
# define CMDVERB	14	/* verb -- go into verbose mode */
# define CMDDBGKILL	15	/* kill -- kill sendmail */
# define CMDDBGWIZ	16	/* wiz -- become a wizard */
I 38
# define CMDONEX	17	/* onex -- sending one transaction only */
E 39
I 39
# define CMDRSET	4	/* rset -- reset state */
# define CMDVRFY	5	/* vrfy -- verify address */
# define CMDHELP	6	/* help -- give usage info */
# define CMDNOOP	7	/* noop -- do nothing */
# define CMDQUIT	8	/* quit -- close connection and die */
# define CMDHELO	9	/* helo -- be polite */
# define CMDDBGQSHOW	10	/* showq -- show send queue (DEBUG) */
# define CMDDBGDEBUG	11	/* debug -- set debug mode */
# define CMDVERB	12	/* verb -- go into verbose mode */
# define CMDDBGKILL	13	/* kill -- kill sendmail */
# define CMDDBGWIZ	14	/* wiz -- become a wizard */
# define CMDONEX	15	/* onex -- sending one transaction only */
D 64
# define CMDDBGSHELL	16	/* shell -- give us a shell */
E 64
E 39
E 38
E 36
E 20
E 19
E 11
E 8
E 4

static struct cmd	CmdTab[] =
{
	"mail",		CMDMAIL,
D 8
	"mrcp",		CMDMRCP,
E 8
I 8
	"rcpt",		CMDRCPT,
D 39
	"mrcp",		CMDRCPT,	/* for old MTP compatability */
E 39
E 8
	"data",		CMDDATA,
D 8
	"doit",		CMDDOIT,
E 8
	"rset",		CMDRSET,
	"vrfy",		CMDVRFY,
I 29
	"expn",		CMDVRFY,
E 29
I 9
	"expn",		CMDVRFY,
E 9
	"help",		CMDHELP,
	"noop",		CMDNOOP,
	"quit",		CMDQUIT,
I 4
D 39
	"mrsq",		CMDMRSQ,
E 39
I 8
	"helo",		CMDHELO,
I 36
	"verb",		CMDVERB,
I 38
	"onex",		CMDONEX,
E 38
E 36
I 22
	"hops",		CMDHOPS,
E 22
I 11
# ifdef DEBUG
D 19
	"showq",	CMDDBGSHOWQ,
E 19
I 19
D 36
	"_showq",	CMDDBGSHOWQ,
	"_debug",	CMDDBGDEBUG,
	"_verbose",	CMDDBGVERBOSE,
I 20
	"_kill",	CMDDBGKILL,
E 36
I 36
D 39
	"showq",	CMDDBGSHOWQ,
E 39
I 39
	"showq",	CMDDBGQSHOW,
E 39
	"debug",	CMDDBGDEBUG,
I 71
# endif DEBUG
# ifdef WIZ
E 71
	"kill",		CMDDBGKILL,
I 71
# endif WIZ
E 71
	"wiz",		CMDDBGWIZ,
I 39
D 64
	"shell",	CMDDBGSHELL,
E 64
E 39
E 36
E 20
E 19
D 71
# endif DEBUG
E 71
E 11
E 8
E 4
	NULL,		CMDERROR,
};

I 74
# ifdef WIZ
E 74
I 36
D 63
# ifdef DEBUG
E 63
bool	IsWiz = FALSE;			/* set if we are a wizard */
I 74
# endif WIZ
E 74
D 58
char	*WizWord = NULL;		/* the wizard word to compare against */
E 58
I 58
char	*WizWord;			/* the wizard word to compare against */
E 58
D 63
# endif DEBUG
E 63
I 39
bool	InChild = FALSE;		/* true if running in a subprocess */
I 41
bool	OneXact = FALSE;		/* one xaction only this run */
I 48
D 72
char	*RealHostName = NULL;		/* verified hostname, set in daemon.c */
E 72

E 48
E 41
#define EX_QUIT		22		/* special code for QUIT command */
E 39

E 36
smtp()
{
D 36
	char inp[MAXLINE];
E 36
	register char *p;
D 36
	struct cmd *c;
E 36
I 36
	register struct cmd *c;
E 36
	char *cmd;
	extern char *skipword();
D 85
	extern bool sameword();
E 85
	bool hasmail;			/* mail command received */
D 7
	bool hasmrcp;			/* has a recipient */
E 7
I 7
D 74
	int rcps;			/* number of recipients */
E 74
E 7
D 9
D 11
	bool hasdata;			/* has mail data */
E 11
I 11
	auto ADDRESS *vrfyqueue;
I 53
	ADDRESS *a;
I 84
D 88
	char *sendinghost;
E 88
I 88
	char *sendinghost, *hellohost;
E 88
E 84
I 75
D 77
	char state[100];
E 77
E 75
E 53
I 38
D 41
	bool onexact = FALSE;		/* one transaction this connection */
E 41
D 40
	bool firsttime = TRUE;		/* this is the first transaction */
E 40
E 38
I 36
	char inp[MAXLINE];
I 77
	char cmdbuf[100];
E 77
E 36
I 18
	extern char Version[];
I 23
	extern tick();
I 36
	extern bool iswiz();
I 40
	extern char *arpadate();
I 50
	extern char *macvalue();
I 53
	extern ADDRESS *recipient();
I 72
	extern ENVELOPE BlankEnvelope;
	extern ENVELOPE *newenvelope();
E 72
E 53
E 50
E 40
E 36
E 23
E 18
D 14
	ADDRESS *prev;
E 14
E 11
E 9
I 9
	extern ADDRESS *sendto();
	ADDRESS *a;
E 9
I 3
D 4
	int baseerrs;
E 4
E 3

D 3
	/*%%%*/	HostName = "XYZZY";
E 3
D 7
	hasmail = hasmrcp = hasdata = FALSE;
E 7
I 7
D 9
D 11
	hasmail = hasdata = FALSE;
E 11
I 11
	hasmail = FALSE;
E 11
E 9
I 9
	hasmail = FALSE;
E 9
D 74
	rcps = 0;
E 74
I 19
D 21
	close(1);
	dup(fileno(OutChannel));
E 21
I 21
D 24
	(void) close(1);
	(void) dup(fileno(OutChannel));
E 24
I 24
	if (OutChannel != stdout)
	{
		/* arrange for debugging output to go to remote host */
		(void) close(1);
		(void) dup(fileno(OutChannel));
	}
I 52
	settime();
I 76
	if (RealHostName != NULL)
D 77
	{
		static char status[100];

		(void) sprintf(status, "talking to %s", RealHostName);
		setproctitle(status);
	}
E 77
I 77
D 79
		setproctitle("talking to %s", RealHostName);
E 79
I 79
D 81
		setproctitle("srvrsmtp %s", RealHostName);
E 81
I 81
	{
D 88
		CurHostName = RealHostName;
E 88
I 88
		if (RealHostName[0] != '[' && RealHostAddr != NULL)
		{
			CurHostName = xalloc(strlen(RealHostName) +
						strlen(RealHostAddr) + 4);
			sprintf(CurHostName, "%s (%s)", RealHostName,
				RealHostAddr);
		}
		else
			CurHostName = RealHostName;
E 88
		setproctitle("srvrsmtp %s", CurHostName);
	}
	else
	{
		/* this must be us!! */
		CurHostName = MyHostName;
	}
E 81
E 79
E 77
E 76
E 52
E 24
E 21
E 19
E 7
D 18
	message("220", "%s Sendmail at your service", HostName);
E 18
I 18
D 30
	message("220", "%s Sendmail version %s at your service", HostName, Version);
E 30
I 30
D 32
	message("220", "%s Sendmail v%s ready at %s", HostName,
E 32
I 32
D 47
	message("220", "%s Sendmail %s ready at %s", HostName,
E 32
D 40
			Version, arpadate(NULL));
E 40
I 40
			Version, arpadate((char *) NULL));
E 47
I 47
D 60
	expand("$e", inp, &inp[sizeof inp], CurEnv);
E 60
I 60
	expand("\001e", inp, &inp[sizeof inp], CurEnv);
E 60
	message("220", inp);
I 72
	SmtpPhase = "startup";
I 84
D 88
	sendinghost = NULL;
E 88
I 88
	sendinghost = hellohost = NULL;
E 88
E 84
E 72
E 47
E 40
E 30
I 29
D 53
	(void) setjmp(TopFrame);
	QuickAbort = FALSE;
I 42
	HoldErrs = FALSE;
E 53
E 42
E 29
I 23
D 28
	(void) signal(SIGALRM, tick);
E 28
E 23
E 18
	for (;;)
	{
I 53
		/* arrange for backout */
		if (setjmp(TopFrame) > 0 && InChild)
			finis();
		QuickAbort = FALSE;
		HoldErrs = FALSE;

E 53
I 23
		/* setup for the read */
E 23
D 16
		To = NULL;
E 16
I 16
		CurEnv->e_to = NULL;
E 16
D 3
		Errors = 0;
E 3
I 3
D 4
		baseerrs = Errors;
E 4
I 4
		Errors = 0;
I 19
		(void) fflush(stdout);
E 19
E 4
E 3
D 23
		if (fgets(inp, sizeof inp, InChannel) == NULL)
E 23
I 23

D 27
		/* arrange a timeout */
		if (setjmp(TickFrame) != 0)
		{
			message("421", "%s timed out", HostName);
			finis();
		}
		(void) alarm(ReadTimeout);

E 27
		/* read the input line */
D 27
		p = fgets(inp, sizeof inp, InChannel);
E 27
I 27
		p = sfgets(inp, sizeof inp, InChannel);
E 27

D 27
		/* clear the timeout and handle errors */
		(void) alarm(0);
E 27
I 27
		/* handle errors */
E 27
		if (p == NULL)
E 23
		{
			/* end of file, just die */
D 3
			message("421", "Lost input channel");
E 3
I 3
D 81
			message("421", "%s Lost input channel", HostName);
E 81
I 81
			message("421", "%s Lost input channel to %s",
				MyHostName, CurHostName);
E 81
E 3
			finis();
		}

		/* clean up end of line */
D 3
		p = index(inp, '\n');
		if (p != NULL)
			*p = '\0';
		p = index(inp, '\r');
		if (p != NULL)
			*p = '\0';
E 3
I 3
		fixcrlf(inp, TRUE);
E 3

I 7
		/* echo command to transcript */
D 25
		fprintf(Xscript, "*** %s\n", inp);
E 25
I 25
D 39
		fprintf(Xscript, "<<< %s\n", inp);
E 39
I 39
D 43
		if (Xscript != NULL)
			fprintf(Xscript, "<<< %s\n", inp);
E 43
I 43
		if (CurEnv->e_xfp != NULL)
			fprintf(CurEnv->e_xfp, "<<< %s\n", inp);
E 43
E 39
E 25

E 7
		/* break off command */
		for (p = inp; isspace(*p); p++)
			continue;
		cmd = p;
D 77
		while (*++p != '\0' && !isspace(*p))
			continue;
		if (*p != '\0')
			*p++ = '\0';
E 77
I 77
		for (cmd = cmdbuf; *p != '\0' && !isspace(*p); )
			*cmd++ = *p++;
		*cmd = '\0';
E 77

I 83
		/* throw away leading whitespace */
		while (isspace(*p))
			p++;

E 83
		/* decode command */
		for (c = CmdTab; c->cmdname != NULL; c++)
		{
D 78
			if (sameword(c->cmdname, cmd))
E 78
I 78
D 85
			if (sameword(c->cmdname, cmdbuf))
E 85
I 85
			if (!strcasecmp(c->cmdname, cmdbuf))
E 85
E 78
				break;
		}

		/* process command */
		switch (c->cmdcode)
		{
I 8
		  case CMDHELO:		/* hello -- introduce yourself */
I 72
			SmtpPhase = "HELO";
I 77
D 79
			setproctitle("talking to %s (%s)", RealHostName, inp);
E 79
I 79
D 81
			setproctitle("%s: %s", RealHostName, inp);
E 79
E 77
E 72
I 56
			if (sameword(p, HostName))
E 81
I 81
			setproctitle("%s: %s", CurHostName, inp);
D 85
			if (sameword(p, MyHostName))
E 85
I 85
			if (!strcasecmp(p, MyHostName))
E 85
E 81
			{
				/* connected to an echo server */
				message("553", "%s I refuse to talk to myself",
D 81
					HostName);
E 81
I 81
					MyHostName);
E 81
				break;
			}
E 56
I 13
D 41
			define('s', newstr(p));
E 41
I 41
D 48
			define('s', newstr(p), CurEnv);
E 48
I 48
D 85
			if (RealHostName != NULL && !sameword(p, RealHostName))
E 85
I 85
D 88
			if (RealHostName != NULL && strcasecmp(p, RealHostName))
E 85
			{
D 77
				char buf[MAXNAME];
E 77
I 77
				char hostbuf[MAXNAME];
E 77

D 77
				(void) sprintf(buf, "%s (%s)", p, RealHostName);
				define('s', newstr(buf), CurEnv);
E 77
I 77
				(void) sprintf(hostbuf, "%s (%s)", p, RealHostName);
D 84
				define('s', newstr(hostbuf), CurEnv);
E 84
I 84
				sendinghost = newstr(hostbuf);
E 84
E 77
			}
			else
D 84
				define('s', newstr(p), CurEnv);
E 84
I 84
				sendinghost = newstr(p);
E 88
I 88
			if (RealHostName == NULL || strcasecmp(p, RealHostName))
				hellohost = newstr(p);
E 88
E 84
E 48
E 41
E 13
D 9
D 10
			message("250", "%s Pleased to meet you", HostName);
E 10
I 10
			message("250", "%s Hello %s, pleased to meet you",
D 81
				HostName, p);
E 81
I 81
				MyHostName, p);
E 81
E 10
E 9
I 9
			message("250", "%s Hello %s, pleased to meet you", HostName, p);
E 9
			break;

E 8
		  case CMDMAIL:		/* mail -- designate sender */
I 72
			SmtpPhase = "MAIL";

E 72
I 50
			/* force a sending host even if no HELO given */
D 88
			if (RealHostName != NULL && macvalue('s', CurEnv) == NULL)
D 84
				define('s', RealHostName, CurEnv);
E 84
I 84
				sendinghost = RealHostName;
E 88
I 88
			if (RealHostName != NULL)
			{
				int c;

				c = strlen(RealHostName) + 1;
				if (hellohost != NULL)
					c += strlen(hellohost) + 8;
D 90
				if (RealHostAddr != NULL)
E 90
I 90
				if (RealHostAddr != NULL &&
				    RealHostName[0] != '[')
E 90
					c += strlen(RealHostAddr) + 3;
				sendinghost = xalloc(c);
				strcpy(sendinghost, RealHostName);
				if (hellohost != NULL)
				{
					strcat(sendinghost, " (HELO ");
					strcat(sendinghost, hellohost);
					strcat(sendinghost, ")");
				}
D 90
				if (RealHostAddr != NULL)
E 90
I 90
				if (RealHostAddr != NULL &&
				    RealHostName[0] != '[')
E 90
				{
					strcat(sendinghost, " (");
					strcat(sendinghost, RealHostAddr);
					strcat(sendinghost, ")");
				}
			}
			else if (hellohost != NULL)
				sendinghost = hellohost;
			else
				sendinghost = macvalue('s', CurEnv);
E 88
E 84

E 50
I 38
D 40
			firsttime = FALSE;

E 40
			/* check for validity of this command */
E 38
I 3
			if (hasmail)
			{
				message("503", "Sender already specified");
				break;
			}
I 39
			if (InChild)
			{
				syserr("Nested MAIL command");
				exit(0);
			}

			/* fork a subprocess to process this command */
			if (runinchild("SMTP-MAIL") > 0)
				break;
I 84
			define('s', sendinghost, CurEnv);
E 84
			initsys();
I 75
D 77
			(void) sprintf(state, "srvrsmtp %s", CurEnv->e_id);
			setproctitle(state);
E 77
I 77
D 79
			setproctitle("talking to %s (%s - %s)", RealHostName,
				CurEnv->e_id, inp);
E 79
I 79
			setproctitle("%s %s: %s", CurEnv->e_id,
D 81
				RealHostName, inp);
E 81
I 81
				CurHostName, inp);
E 81
E 79
E 77
E 75

			/* child -- go do the processing */
E 39
E 3
			p = skipword(p, "from");
			if (p == NULL)
				break;
D 39
			if (index(p, ',') != NULL)
			{
				message("501", "Source routing not implemented");
				Errors++;
				break;
			}
E 39
			setsender(p);
D 3
			if (Errors == 0)
E 3
I 3
D 4
			if (Errors == baseerrs)
E 4
I 4
			if (Errors == 0)
E 4
E 3
			{
				message("250", "Sender ok");
				hasmail = TRUE;
			}
I 39
			else if (InChild)
				finis();
E 39
			break;

D 8
		  case CMDMRCP:		/* mrcp -- designate recipient */
E 8
I 8
		  case CMDRCPT:		/* rcpt -- designate recipient */
I 72
			SmtpPhase = "RCPT";
I 77
D 79
			setproctitle("talking to %s (%s - %s)", RealHostName,
				CurEnv->e_id, inp);
E 79
I 79
			setproctitle("%s %s: %s", CurEnv->e_id,
D 81
				RealHostName, inp);
E 81
I 81
				CurHostName, inp);
E 81
E 79
E 77
E 72
I 53
			if (setjmp(TopFrame) > 0)
I 55
			{
				CurEnv->e_flags &= ~EF_FATALERRS;
E 55
				break;
I 55
			}
E 55
			QuickAbort = TRUE;
E 53
E 8
			p = skipword(p, "to");
			if (p == NULL)
				break;
D 31
			if (index(p, ',') != NULL)
			{
				message("501", "Source routing not implemented");
				Errors++;
				break;
			}
E 31
D 6
			sendto(p, 1, NULL);
E 6
I 6
D 9
D 11
			sendto(p, 1, (ADDRESS *) NULL);
E 11
I 11
D 16
			sendto(p, 1, (ADDRESS *) NULL, &SendQueue);
E 16
I 16
D 33
			sendto(p, 1, (ADDRESS *) NULL, &CurEnv->e_sendqueue);
E 33
I 33
D 44
			sendto(p, (ADDRESS *) NULL, &CurEnv->e_sendqueue);
E 44
I 44
D 53
			sendtolist(p, (ADDRESS *) NULL, &CurEnv->e_sendqueue);
E 53
I 53
D 59
			a = parseaddr(p, (ADDRESS *) NULL, 1);
E 59
I 59
			a = parseaddr(p, (ADDRESS *) NULL, 1, '\0');
E 59
			if (a == NULL)
				break;
I 62
			a->q_flags |= QPRIMARY;
I 89
			if (FromInet && NoInetRelay &&
			    !bitnset(M_LOCAL, a->q_mailer->m_flags)) {
				message("551",
					"No relaying for Internet senders");
				break;
			}
E 89
E 62
			a = recipient(a, &CurEnv->e_sendqueue);
E 53
E 44
I 42
D 55
			CurEnv->e_flags &= ~EF_FATALERRS;
E 55
E 42
E 33
E 16
E 11
E 9
I 9
			a = sendto(p, 1, (ADDRESS *) NULL, 0);
# ifdef DEBUG
			if (Debug > 1)
				printaddr(a, TRUE);
# endif DEBUG
E 9
E 6
D 3
			if (Errors == 0)
E 3
I 3
D 4
			if (Errors == baseerrs)
E 4
I 4
D 53
			if (Errors == 0)
E 53
I 53
			if (Errors != 0)
				break;

			/* no errors during parsing, but might be a duplicate */
			CurEnv->e_to = p;
			if (!bitset(QBADADDR, a->q_flags))
				message("250", "Recipient ok");
			else
E 53
E 4
E 3
			{
D 15
				message("250", "Recipient ok");
E 15
I 15
D 53
				message("250", "%s... Recipient ok", p);
E 15
D 7
				hasmrcp = TRUE;
E 7
I 7
				rcps++;
E 53
I 53
				/* punt -- should keep message in ADDRESS.... */
				message("550", "Addressee unknown");
E 53
E 7
			}
I 53
			CurEnv->e_to = NULL;
D 74
			rcps++;
E 74
E 53
			break;

		  case CMDDATA:		/* data -- text of mail */
I 72
			SmtpPhase = "DATA";
E 72
D 7
			message("354", "Enter mail, end with dot");
			collect();
E 7
I 7
D 8
			collect(TRUE);
E 7
D 3
			if (Errors == 0)
E 3
I 3
D 4
			if (Errors == baseerrs)
E 4
I 4
			if (Errors == 0)
E 4
E 3
			{
				message("250", "Message stored");
				hasdata = TRUE;
			}
			break;

		  case CMDDOIT:		/* doit -- actually send everything */
E 8
			if (!hasmail)
I 8
			{
E 8
				message("503", "Need MAIL command");
I 8
				break;
			}
E 8
D 7
			else if (!hasmrcp)
E 7
I 7
D 72
			else if (rcps <= 0)
E 72
I 72
			else if (CurEnv->e_nrcpts <= 0)
E 72
E 7
D 8
				message("503", "Need MRCP (recipient)");
			else if (!hasdata)
				message("503", "No message, use DATA");
			else
E 8
			{
I 7
D 8
				if (rcps != 1)
					HoldErrs = MailBack = TRUE;
E 7
				sendall(FALSE);
D 3
				if (Errors == 0)
E 3
I 3
D 4
				if (Errors == baseerrs)
E 4
I 4
D 7
				if (Errors == 0)
E 7
I 7
				HoldErrs = FALSE;
				To = NULL;
				if (Errors == 0 || rcps != 1)
E 7
E 4
E 3
					message("250", "Sent");
E 8
I 8
				message("503", "Need RCPT (recipient)");
				break;
E 8
			}
I 8

			/* collect the text of the message */
I 72
			SmtpPhase = "collect";
I 77
D 79
			setproctitle("talking to %s (%s - %s)", RealHostName,
				CurEnv->e_id, inp);
E 79
I 79
			setproctitle("%s %s: %s", CurEnv->e_id,
D 81
				RealHostName, inp);
E 81
I 81
				CurHostName, inp);
E 81
E 79
E 77
E 72
			collect(TRUE);
			if (Errors != 0)
				break;

D 34
			/* if sending to multiple people, mail back errors */
E 34
I 34
			/*
			**  Arrange to send to everyone.
			**	If sending to multiple people, mail back
			**		errors rather than reporting directly.
			**	In any case, don't mail back errors for
			**		anything that has happened up to
			**		now (the other end will do this).
I 45
			**	Truncate our transcript -- the mail has gotten
			**		to us successfully, and if we have
			**		to mail this back, it will be easier
			**		on the reader.
E 45
			**	Then send to everyone.
			**	Finally give a reply code.  If an error has
			**		already been given, don't mail a
			**		message back.
D 39
			**	We goose error returns by clearing FatalErrors.
E 39
I 39
			**	We goose error returns by clearing error bit.
E 39
			*/

E 34
D 72
			if (rcps != 1)
E 72
I 72
			SmtpPhase = "delivery";
			if (CurEnv->e_nrcpts != 1)
E 72
D 41
				HoldErrs = MailBack = TRUE;
E 41
I 41
			{
				HoldErrs = TRUE;
D 62
				ErrorMode == EM_MAIL;
E 62
I 62
				ErrorMode = EM_MAIL;
E 62
			}
E 41
I 34
D 39
			FatalErrors = FALSE;
E 39
I 39
			CurEnv->e_flags &= ~EF_FATALERRS;
I 45
			CurEnv->e_xfp = freopen(queuename(CurEnv, 'x'), "w", CurEnv->e_xfp);
E 45
E 39
E 34

			/* send to all recipients */
D 17
			sendall(FALSE);
E 17
I 17
D 37
			sendall(CurEnv, FALSE);
E 37
I 37
D 56
			sendall(CurEnv, SendMode);
E 56
I 56
			sendall(CurEnv, SM_DEFAULT);
E 56
E 37
E 17
D 34

			/* reset strange modes */
			HoldErrs = FALSE;
E 34
D 16
			To = NULL;
E 16
I 16
			CurEnv->e_to = NULL;
E 16

I 69
			/* save statistics */
			markstats(CurEnv, (ADDRESS *) NULL);

E 69
D 34
			/* issue success if appropriate */
			if (Errors == 0 || rcps != 1)
E 34
I 34
			/* issue success if appropriate and reset */
			if (Errors == 0 || HoldErrs)
D 42
			{
				HoldErrs = FALSE;
E 42
E 34
D 37
				message("250", "Sent");
E 37
I 37
				message("250", "Ok");
E 37
I 34
D 42
			}
E 42
			else
D 39
				FatalErrors = FALSE;
E 39
I 39
				CurEnv->e_flags &= ~EF_FATALERRS;

			/* if in a child, pop back to our parent */
			if (InChild)
				finis();
I 72

			/* clean up a bit */
			hasmail = 0;
D 74
			rcps = 0;
E 74
			dropenvelope(CurEnv);
			CurEnv = newenvelope(CurEnv);
			CurEnv->e_flags = BlankEnvelope.e_flags;
E 72
E 39
E 34
E 8
			break;

		  case CMDRSET:		/* rset -- reset state */
			message("250", "Reset state");
D 39
			finis();
E 39
I 39
			if (InChild)
				finis();
			break;
E 39

		  case CMDVRFY:		/* vrfy -- verify address */
I 39
			if (runinchild("SMTP-VRFY") > 0)
				break;
I 75
D 77
			setproctitle("SMTP-VRFY");
E 77
I 77
D 79
			setproctitle("talking to %s (%s)", RealHostName, inp);
E 79
I 79
D 81
			setproctitle("%s: %s", RealHostName, inp);
E 81
I 81
			setproctitle("%s: %s", CurHostName, inp);
E 81
E 79
E 77
E 75
E 39
D 6
			sendto(p, 1, NULL);
E 6
I 6
D 9
D 10
			sendto(p, 1, (ADDRESS *) NULL);
E 9
I 9
			a = sendto(p, 1, (ADDRESS *) NULL, QPSEUDO);
E 9
E 6
D 3
			if (Errors == 0)
E 3
I 3
D 4
			if (Errors == baseerrs)
E 4
I 4
			if (Errors == 0)
E 4
E 3
D 9
				message("250", "user ok");
E 10
I 10
D 11
			message("502", "Command not implemented");
E 11
I 11
			vrfyqueue = NULL;
I 29
			QuickAbort = TRUE;
E 29
D 33
			sendto(p, 1, (ADDRESS *) NULL, &vrfyqueue);
E 33
I 33
D 44
			sendto(p, (ADDRESS *) NULL, &vrfyqueue);
E 44
I 44
			sendtolist(p, (ADDRESS *) NULL, &vrfyqueue);
E 44
E 33
I 29
			if (Errors != 0)
I 39
			{
				if (InChild)
					finis();
E 39
				break;
I 39
			}
E 39
E 29
			while (vrfyqueue != NULL)
			{
				register ADDRESS *a = vrfyqueue->q_next;
				char *code;

D 27
				while (a != NULL && bitset(QDONTSEND, a->q_flags))
E 27
I 27
				while (a != NULL && bitset(QDONTSEND|QBADADDR, a->q_flags))
E 27
					a = a->q_next;

D 27
				if (!bitset(QDONTSEND, vrfyqueue->q_flags))
E 27
I 27
				if (!bitset(QDONTSEND|QBADADDR, vrfyqueue->q_flags))
E 27
				{
					if (a != NULL)
						code = "250-";
					else
						code = "250";
					if (vrfyqueue->q_fullname == NULL)
						message(code, "<%s>", vrfyqueue->q_paddr);
					else
						message(code, "%s <%s>",
						    vrfyqueue->q_fullname, vrfyqueue->q_paddr);
				}
				else if (a == NULL)
					message("554", "Self destructive alias loop");
				vrfyqueue = a;
			}
I 39
			if (InChild)
				finis();
E 39
E 11
E 10
E 9
I 9
				paddrtree(a);
E 9
			break;

		  case CMDHELP:		/* help -- give user info */
D 4
			message("502", "HELP not implemented");
E 4
I 4
			if (*p == '\0')
				p = "SMTP";
			help(p);
E 4
			break;

		  case CMDNOOP:		/* noop -- do nothing */
			message("200", "OK");
			break;

		  case CMDQUIT:		/* quit -- leave mail */
D 81
			message("221", "%s closing connection", HostName);
E 81
I 81
			message("221", "%s closing connection", MyHostName);
E 81
I 39
			if (InChild)
				ExitStat = EX_QUIT;
E 39
			finis();

I 4
D 39
		  case CMDMRSQ:		/* mrsq -- negotiate protocol */
			if (*p == 'R' || *p == 'T')
			{
				/* recipients first or text first */
				message("200", "%c ok, please continue", *p);
			}
			else if (*p == '?')
			{
				/* what do I prefer?  anything, anytime */
				message("215", "R Recipients first is my choice");
			}
			else if (*p == '\0')
			{
				/* no meaningful scheme */
				message("200", "okey dokie boobie");
			}
			else
			{
				/* bad argument */
				message("504", "Scheme unknown");
			}
I 22
			break;

		  case CMDHOPS:		/* specify hop count */
			HopCount = atoi(p);
			if (++HopCount > MAXHOP)
				message("501", "Hop count exceeded");
			else
				message("200", "Hop count ok");
E 22
			break;
I 11

E 39
I 36
		  case CMDVERB:		/* set verbose mode */
			Verbose = TRUE;
I 80
			SendMode = SM_DELIVER;
E 80
			message("200", "Verbose mode");
I 38
			break;

		  case CMDONEX:		/* doing one transaction only */
D 41
			onexact = TRUE;
E 41
I 41
			OneXact = TRUE;
E 41
			message("200", "Only one transaction");
E 38
			break;

E 36
# ifdef DEBUG
D 39
		  case CMDDBGSHOWQ:	/* show queues */
E 39
I 39
		  case CMDDBGQSHOW:	/* show queues */
E 39
D 16
			printf("SendQueue=");
			printaddr(SendQueue, TRUE);
E 16
I 16
			printf("Send Queue=");
			printaddr(CurEnv->e_sendqueue, TRUE);
I 19
			break;

		  case CMDDBGDEBUG:	/* set debug mode */
D 26
			Debug = atoi(p);
			message("200", "Debug = %d", Debug);
E 26
I 26
			tTsetup(tTdvect, sizeof tTdvect, "0-99.1");
			tTflag(p);
			message("200", "Debug set");
E 26
			break;
I 71
# endif DEBUG
E 71

I 71
# ifdef WIZ
E 71
D 36
		  case CMDDBGVERBOSE:	/* set verbose mode */
			Verbose = TRUE;
			message("200", "Verbose mode");
I 20
			break;

E 36
		  case CMDDBGKILL:	/* kill the parent */
I 36
			if (!iswiz())
				break;
E 36
			if (kill(MotherPid, SIGTERM) >= 0)
				message("200", "Mother is dead");
			else
				message("500", "Can't kill Mom");
E 20
E 19
E 16
			break;
I 36

I 39
D 64
		  case CMDDBGSHELL:	/* give us an interactive shell */
			if (!iswiz())
				break;
I 41
			if (fileno(InChannel) != 0)
			{
				(void) close(0);
				(void) dup(fileno(InChannel));
D 46
				(void) fclose(InChannel);
E 46
I 46
				if (fileno(InChannel) != fileno(OutChannel))
					(void) fclose(InChannel);
E 46
				InChannel = stdin;
			}
			if (fileno(OutChannel) != 1)
			{
				(void) close(1);
				(void) dup(fileno(OutChannel));
				(void) fclose(OutChannel);
				OutChannel = stdout;
			}
I 46
			(void) close(2);
			(void) dup(1);
E 46
E 41
			execl("/bin/csh", "sendmail", 0);
			execl("/bin/sh", "sendmail", 0);
			message("500", "Can't");
D 41
			break;
E 41
I 41
			exit(EX_UNAVAILABLE);
E 41

E 64
E 39
		  case CMDDBGWIZ:	/* become a wizard */
			if (WizWord != NULL)
			{
				char seed[3];
				extern char *crypt();

D 67
				strncpy(seed, WizWord, 2);
E 67
I 67
				(void) strncpy(seed, WizWord, 2);
E 67
D 58
				if (strcmp(WizWord, crypt(p, seed)) != 0)
E 58
I 58
				if (strcmp(WizWord, crypt(p, seed)) == 0)
E 58
				{
D 58
					message("500", "You are no wizard!");
E 58
I 58
					IsWiz = TRUE;
					message("200", "Please pass, oh mighty wizard");
E 58
					break;
				}
			}
D 58
			IsWiz = TRUE;
			message("200", "Please pass, oh mighty wizard");
E 58
I 58
			message("500", "You are no wizard!");
E 58
			break;
E 36
D 71
# endif DEBUG
E 71
E 11

I 71
# else WIZ
		  case CMDDBGWIZ:	/* try to become a wizard */
			message("500", "You wascal wabbit!  Wandering wizards won't win!");
			break;
# endif WIZ

E 71
E 4
		  case CMDERROR:	/* unknown command */
			message("500", "Command unrecognized");
			break;

		  default:
			syserr("smtp: unknown code %d", c->cmdcode);
			break;
		}
	}
}
/*
**  SKIPWORD -- skip a fixed word.
**
**	Parameters:
**		p -- place to start looking.
**		w -- word to skip.
**
**	Returns:
**		p following w.
**		NULL on error.
**
**	Side Effects:
**		clobbers the p data area.
*/

static char *
skipword(p, w)
	register char *p;
	char *w;
{
	register char *q;
D 85
	extern bool sameword();
E 85

	/* find beginning of word */
	while (isspace(*p))
		p++;
	q = p;

	/* find end of word */
	while (*p != '\0' && *p != ':' && !isspace(*p))
		p++;
	while (isspace(*p))
		*p++ = '\0';
	if (*p != ':')
	{
	  syntax:
		message("501", "Syntax error");
		Errors++;
		return (NULL);
	}
	*p++ = '\0';
	while (isspace(*p))
		p++;

	/* see if the input word matches desired word */
D 85
	if (!sameword(q, w))
E 85
I 85
	if (strcasecmp(q, w))
E 85
		goto syntax;

	return (p);
I 4
}
/*
**  HELP -- implement the HELP command.
**
**	Parameters:
**		topic -- the topic we want help for.
**
**	Returns:
**		none.
**
**	Side Effects:
**		outputs the help file to message output.
*/

help(topic)
	char *topic;
{
	register FILE *hf;
	int len;
	char buf[MAXLINE];
	bool noinfo;
I 5
D 35
	extern char *HelpFile;
E 35
E 5

D 5
	hf = fopen("/usr/lib/sendmail.hf", "r");
E 5
I 5
D 35
	hf = fopen(HelpFile, "r");
E 5
	if (hf == NULL)
E 35
I 35
	if (HelpFile == NULL || (hf = fopen(HelpFile, "r")) == NULL)
E 35
	{
		/* no help */
I 52
		errno = 0;
E 52
		message("502", "HELP not implemented");
		return;
	}

	len = strlen(topic);
	makelower(topic);
	noinfo = TRUE;

	while (fgets(buf, sizeof buf, hf) != NULL)
	{
		if (strncmp(buf, topic, len) == 0)
		{
			register char *p;

			p = index(buf, '\t');
			if (p == NULL)
				p = buf;
			else
				p++;
			fixcrlf(p, TRUE);
			message("214-", p);
			noinfo = FALSE;
		}
	}

	if (noinfo)
		message("504", "HELP topic unknown");
	else
		message("214", "End of HELP info");
D 6
	fclose(hf);
E 6
I 6
	(void) fclose(hf);
I 36
}
/*
**  ISWIZ -- tell us if we are a wizard
**
**	If not, print a nasty message.
**
**	Parameters:
**		none.
**
**	Returns:
**		TRUE if we are a wizard.
**		FALSE if we are not a wizard.
**
**	Side Effects:
**		Prints a 500 exit stat if we are not a wizard.
*/

I 64
D 71
#ifdef DEBUG
E 71
I 71
#ifdef WIZ
E 71

E 64
bool
iswiz()
{
	if (!IsWiz)
		message("500", "Mere mortals musn't mutter that mantra");
	return (IsWiz);
I 39
}
I 64

D 71
#endif DEBUG
E 71
I 71
#endif WIZ
E 71
E 64
/*
**  RUNINCHILD -- return twice -- once in the child, then in the parent again
**
**	Parameters:
**		label -- a string used in error messages
**
**	Returns:
**		zero in the child
**		one in the parent
**
**	Side Effects:
**		none.
*/

runinchild(label)
	char *label;
{
	int childpid;

I 41
D 61
	if (OneXact)
		return (0);

E 41
	childpid = dofork();
	if (childpid < 0)
E 61
I 61
	if (!OneXact)
E 61
	{
D 61
		syserr("%s: cannot fork", label);
		return (1);
	}
	if (childpid > 0)
	{
D 41
		/* parent -- wait for child to complete */
E 41
		auto int st;
E 61
I 61
		childpid = dofork();
		if (childpid < 0)
		{
			syserr("%s: cannot fork", label);
			return (1);
		}
		if (childpid > 0)
		{
			auto int st;
E 61
D 41
		int i;
E 41

D 41
		while ((i = wait(&st)) != childpid)
		{
			if (i < 0 && errno != EINTR)
				break;
		}
		if (i < 0)
E 41
I 41
D 61
		/* parent -- wait for child to complete */
		st = waitfor(childpid);
		if (st == -1)
E 41
			syserr("%s: lost child", label);
E 61
I 61
			/* parent -- wait for child to complete */
			st = waitfor(childpid);
			if (st == -1)
				syserr("%s: lost child", label);
E 61

D 61
		/* if we exited on a QUIT command, complete the process */
		if (st == (EX_QUIT << 8))
			finis();
E 61
I 61
			/* if we exited on a QUIT command, complete the process */
			if (st == (EX_QUIT << 8))
				finis();
E 61

D 61
		return (1);
E 61
I 61
			return (1);
		}
		else
		{
			/* child */
			InChild = TRUE;
I 81
			QuickAbort = FALSE;
E 81
I 70
D 82
			clearenvelope(CurEnv);
E 82
I 82
			clearenvelope(CurEnv, FALSE);
E 82
E 70
		}
E 61
	}
D 61
	else
	{
		/* child */
		InChild = TRUE;
I 43
		clearenvelope(CurEnv);
E 61
I 57
D 70

D 61
		/* open alias database */
		initaliases(AliasFile, FALSE);
E 61
I 61
	/* child (or ONEX command specified) */
	clearenvelope(CurEnv);
E 70
E 61

E 57
E 43
D 61
		return (0);
	}
E 61
I 61
	/* open alias database */
	initaliases(AliasFile, FALSE);

	return (0);
E 61
E 39
E 36
I 9
}
/*
**  PADDRTREE -- print address tree
**
**	Used by VRFY and EXPD to dump the tree of addresses produced.
**
**	Parameters:
**		a -- address of root.
**
**	Returns:
**		none.
**
**	Side Effects:
**		prints the tree in a nice order.
*/

paddrtree(a)
	register ADDRESS *a;
{
	static ADDRESS *prev;
	static int lev;

	if (a == NULL)
		return;
	lev++;
	if (!bitset(QDONTSEND, a->q_flags))
	{
		if (prev != NULL)
		{
			if (prev->q_fullname != NULL)
				message("250-", "%s <%s>", prev->q_fullname, prev->q_paddr);
			else
				message("250-", "<%s>", prev->q_paddr);
		}
		prev = a;
	}
	paddrtree(a->q_child);
	paddrtree(a->q_sibling);
	if (--lev <= 0)
	{
		if (prev != NULL)
		{
			/* last one */
			if (prev->q_fullname != NULL)
				message("250", "%s <%s>", prev->q_fullname, prev->q_paddr);
			else
				message("250", "<%s>", prev->q_paddr);
			prev = NULL;
		}
		else
			message("550", "User unknown");
	}
E 9
E 6
E 4
}
I 12

# endif SMTP
E 12
E 1
