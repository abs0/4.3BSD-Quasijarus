h25569
s 00011/00009/00519
d D 5.9 88/06/30 14:59:38 bostic 83 82
c install approved copyright notice
e
s 00016/00010/00512
d D 5.8 88/03/13 19:53:02 bostic 82 81
c add Berkeley specific header
e
s 00005/00000/00517
d D 5.7 85/12/07 08:17:41 eric 81 80
m 
c several small bugs: don't die if no environment, don't look in
c ESM_DEADLETTER state in savemail; lowercase before getpwnam to
c allow upper case regular names in alias file
e
s 00006/00000/00511
d D 5.6 85/09/21 14:44:27 eric 80 79
m 
c clean up priority handling, making several of the parameters configurable:
c y - WkRecipFact, z - WkClassFact, Z - WkTimeFact, Y - ForkQueueRuns; improve
c process title labelling; finish "errors to postmaster" option
e
s 00019/00001/00492
d D 5.5 85/09/21 10:31:23 eric 79 78
m 
c add -v mode to mailq to print priorities as well (this should be extended
c in the future); fix some problems in the savemail state machine.
e
s 00001/00001/00492
d D 5.4 85/09/19 13:35:53 eric 78 77
m 
c lint
e
s 00194/00093/00299
d D 5.3 85/09/19 00:45:30 eric 77 76
m 
c SMI changes (somewhat)
e
s 00000/00002/00392
d D 5.2 85/06/07 22:23:55 miriam 76 75
m 
c Resolve duplicate SccsId
e
s 00014/00000/00380
d D 5.1 85/06/07 15:13:01 dist 75 74
m 
c Add copyright
e
s 00000/00000/00380
d D 4.6 85/05/24 11:00:14 eric 74 73
m 
c Changes from Bill Nowicki <sun!rose!nowicki> and Jay Lepreau <lepreau@utah-cs>:
c Fix "bad file number" problem; improve error reporting; try to keep messages
c closer to their original order.  Also, drop "safe" mode in readcf since we
c never run setuid when -C is specified.
e
s 00007/00007/00373
d D 4.5 84/05/13 14:02:48 eric 73 72
m 
c change "returnto" to "returnq" for PDP-11 compilers
e
s 00001/00000/00379
d D 4.4 84/03/11 19:57:54 eric 72 71
m 
c disable UPPER->lower case mapping in RHS's of aliases so that upper
c case letters can be used in file names and as args to programs.
e
s 00005/00005/00374
d D 4.3 84/03/11 16:54:51 eric 71 70
m 
c change macro expansion character from $ to \001 so that $'s can be
c used in headers -- the .cf file is unchanged by mapping $ to \001.
c \001 is now a manifest constant.
e
s 00001/00001/00378
d D 4.2 83/08/28 14:45:08 eric 70 69
m 
c Refuse to talk to yourself (i.e., reject HELO packets with your own name).
c Add two thresholds -- option 'x' is the load average at which messages are
c queued rather than delivered (default 12); option 'X' is the load average
c at which incoming TCP connections are refused (default 25).
e
s 00000/00000/00379
d D 4.1 83/07/25 19:45:45 eric 69 68
m 
c 4.2 release version
e
s 00002/00002/00377
d D 3.60 83/03/08 19:22:35 eric 68 67
m 205
c Pass the delimiter character to parseaddr so that we can correctly
c decide between comma and space
e
s 00001/00000/00378
d D 3.59 83/02/26 11:51:30 eric 67 66
m 193
c log queueid <=> message-id correspondence
e
s 00001/00001/00377
d D 3.58 83/02/10 10:00:37 eric 66 65
m 176
c avoid core dump on return receipt processing; clean up return receipt
c message.
e
s 00001/00001/00377
d D 3.57 83/02/02 12:52:56 eric 65 64
m 165
c implement classes and mailer flags as a bit map; define new class 'w'
c as the set of all hosts we are known by
e
s 00016/00015/00362
d D 3.56 83/01/06 10:45:55 eric 64 63
m 
c split up FULLSMTP flag -- now have "X" (M_XDOT, use hidden dot algorithm),
c "p" (M_FROMPATH, use reverse-path in MAIL FROM:<> command), and "L"
c (M_LIMITS, enforce SMTP line limits).  I would like to change the format
c of the mail defn one more time to make named fields so that it would
c be more extensible.
e
s 00004/00002/00373
d D 3.55 83/01/03 18:01:23 eric 63 62
m 
c give more useful error messages (including the errno that caused
c a temporary failure); reflect these messages out to mailq
e
s 00007/00005/00368
d D 3.54 83/01/01 21:25:26 eric 62 61
m 123
c Put CRLF on all lines in user SMTP.  Pass this info down to
c innumerable routines.
e
s 00002/00002/00371
d D 3.53 82/12/24 08:14:41 eric 61 60
m 108
c Change parse to parseaddr for BB&N TCP/IP implementation; clean up
c comments in daemon.c to simplify the poor alternate protocol type.
e
s 00002/00002/00371
d D 3.52 82/12/13 18:24:59 eric 60 59
m 085
c The routine "sendto" is now a system call (yeuch!); change our sendto
c to "sendtolist"
e
s 00014/00012/00359
d D 3.51 82/12/05 13:46:18 eric 59 58
m 092
c Clear the envelope in the child in server SMTP to insure that our oh so
c helpful parent doesn't delete our transcript; move the transcript and
c temporary file pointers into the envelope; pass the envelope to other
c routines in the holy war against global variables; split off envelope
c routines from main.c to envelope.c
e
s 00047/00040/00324
d D 3.50 82/11/28 00:22:07 eric 58 57
m 
c Many changes resulting from a complete code readthrough.  Most of these
c fix minor bugs or change the internal structure for clarity, etc.  There
c should be almost no externally visible changes (other than some cleaner
c error message printouts and the like).
e
s 00001/00001/00363
d D 3.49 82/11/24 18:44:20 eric 57 56
m 
c lint it
e
s 00031/00026/00333
d D 3.48 82/11/24 17:15:19 eric 56 55
m 026
c run SMTP jobs in a subprocess so that multiple jobs will work.  This
c delta also changes the envelope data structure so that flags are in
c a bit map, and adjusts some of the semantics.  The transcript is now
c local to an envelope.  A bunch of old code is deleted.  A serious bug
c was fixed in the "run in background" code.  Etc., etc.
e
s 00002/00002/00357
d D 3.47 82/11/17 09:36:35 eric 55 54
m 060
c split operation mode ("-bx" flag) and delivery mode ("d" option)
c so that operation mode can apply to SMTP/daemon connections also.
e
s 00015/00012/00344
d D 3.46 82/11/04 13:27:16 eric 54 53
m 037
c put header conditionals into the .cf file
e
s 00001/00000/00355
d D 3.45 82/10/09 21:02:17 eric 53 52
m 005
c force a queuename in returntosender to insure that everyone has a
c queue name.
e
s 00001/00001/00354
d D 3.44 82/09/24 09:38:26 eric 52 51
c arrange to be able to define options; put precedences in .cf file;
c send errors to an Errors-To: field; fix a serious bug causing mail
c to not be delivered to anyone if there were any errors.
e
s 00001/00000/00354
d D 3.43 82/09/08 21:19:52 eric 51 50
c try to avoid "Interrupted system call" on wait in deliver and on
c writes; fix returned message to have proper sender; handle extra
c mailer output more cleverly.
e
s 00005/00003/00349
d D 3.42 82/09/06 16:24:40 eric 50 49
c install new state-driven scanner; make everyone use it, thus fixing
c problems of quoted commas, etc.
e
s 00001/00001/00351
d D 3.41 82/08/22 19:03:03 eric 49 48
c assign a unique id to each transaction that can be determined from
c the queue file name.
e
s 00002/00002/00350
d D 3.40 82/08/08 01:02:57 eric 48 47
c change debug level to a debug vector; add levels on logging (and the
c -L flag); change logging to be by message-id; elevate message-id;
c some lint-type cleanup
e
s 00001/00000/00351
d D 3.39 82/07/05 20:53:43 eric 47 46
c flush fatal errors when returning error messages to avoid error
c message loops
e
s 00008/00002/00343
d D 3.38 82/07/05 13:17:16 eric 46 45
c add debugging info & comments
e
s 00010/00000/00335
d D 3.37 82/06/26 13:53:28 eric 45 44
c more debug information; fix dependencies in makefile
e
s 00001/00002/00334
d D 3.36 82/06/26 13:10:27 eric 44 43
c lint
e
s 00002/00000/00334
d D 3.35 82/06/16 14:48:13 eric 43 42
c make sure there is always someone to return the message to
e
s 00002/00001/00332
d D 3.34 82/06/07 23:55:40 eric 42 41
c call the routine putline to output lines to mailers.  this lets us
c implement line length limits, etc. for full SMTP compatibility.
e
s 00005/00003/00328
d D 3.33 82/06/07 07:54:45 eric 41 40
c make transcripts verbose always; misc. message cleanup, etc.
e
s 00022/00016/00309
d D 3.32 82/06/06 23:05:08 eric 40 38
c implement alias owner feature.  this actually works for any user.
c basically, if the alias owner-xxx exists, errors sending to xxx will be
c sent to that alias rather than to the sender.
e
s 00010/00009/00316
d D 3.31.1.1 82/06/06 20:13:06 eric 39 38
c first cut at putting mailing list maintainers in -- there is a
c much better way though.
e
s 00004/00031/00321
d D 3.31 82/05/31 18:49:30 eric 38 37
c pass lint.  notice that definitions in llib-lc have changed for
c alarm() and sleep() calls {arg was unsigned, is now int}.
e
s 00006/00003/00346
d D 3.30 82/05/31 15:32:07 eric 37 35
i 36
c finish implementing envelopes.  it's not completely clear to me that
c this is really the way to go, but it seems clearly better than what
c i had before.  this delta includes many other minor changes, so it
c should probably not be blithely removed.
e
s 00082/00073/00267
d D 3.29.1.1 82/05/29 18:20:16 eric 36 35
c try to install envelopes.  is this really worth it???
e
s 00001/00001/00339
d D 3.29 82/05/22 02:05:38 eric 35 34
c add "junk mail" -- error responses are never returned.
e
s 00018/00018/00322
d D 3.28 82/05/22 01:37:56 eric 34 33
c add "envelopes" to contain the basic information needed as control
c info for each message.  currently there is only one envelope -- this
c being the obvious stupid conversion.  later there will be separate
c envelopes for error messages, return receipts, etc.
e
s 00028/00006/00312
d D 3.27 82/02/27 11:37:31 eric 33 32
c implement "return receipt requested".
e
s 00003/00003/00315
d D 3.26 82/02/15 09:39:40 eric 32 31
c pass lint
e
s 00006/00003/00312
d D 3.25 82/01/01 18:27:07 eric 31 30
c send to dead.letter using sendto/recipient/deliver mechanism rather
c than mailfile; this fixes a bug with the "from" name and seems like
c a better abstraction.
e
s 00001/00001/00314
d D 3.24 81/12/06 12:38:49 eric 30 29
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00004/00002/00311
d D 3.23 81/11/11 20:24:01 eric 29 28
c integrate user SMTP into sendmail itself.  If there is no $u arg
c in the mailer argument list, SMTP is run.  This can be used directly
c over the Ethernet or to any clever mailer.  We still need to edit
c spooled control files to remove recipients that have been successfully
c sent during queue processing.
e
s 00004/00001/00309
d D 3.22 81/10/31 22:12:38 eric 28 27
c drop old NCP stuff for ARPANET handling; fix some bugs in error
c messages with multiple recipients in SMTP; clean up error handling
e
s 00053/00033/00257
d D 3.21 81/10/27 10:50:43 eric 27 26
c More queueing cleanup: implement timeouts (still one-stage),
c properly implement priorities (didn't work before), and miscellaneous
c cleanup.
e
s 00002/00002/00288
d D 3.20 81/10/23 19:38:02 eric 26 25
c Eliminate magic MN_LOCAL and MN_PROG; change q_mailer item in ADDRESS
c to be pointer to mailer rather than index.
e
s 00025/00000/00265
d D 3.19 81/10/02 11:05:15 eric 25 24
c arrange to give the correct "from" person on error messages.
e
s 00001/00001/00264
d D 3.18 81/09/16 16:08:01 eric 24 23
c run as the user forwarding mail after a .forward operation;
c fix a bug in .forwarding that caused recursive expansion;
c restrict mail to programs, files, and with :include: for security
c reasons.
e
s 00034/00004/00231
d D 3.17 81/09/06 19:48:51 eric 23 22
c cleanup, commenting, linting, etc.
e
s 00003/00001/00232
d D 3.16 81/09/01 11:43:33 eric 22 21
c add "suppress return-to-sender" function
e
s 00010/00005/00223
d D 3.15 81/08/21 18:51:22 eric 21 20
c return transcript even if no message was collected
e
s 00002/00002/00226
d D 3.14 81/08/21 18:18:34 eric 20 19
c drop M_FINAL, change some other defined constant names
e
s 00001/00002/00227
d D 3.13 81/08/20 15:14:20 eric 19 18
c clean up some header information; don't reopen tempfile as
c stdin (to fix some problems with saving mail on interrupts)
e
s 00001/00001/00228
d D 3.12 81/08/18 17:12:57 eric 18 17
c factor out ARPANET FTP reply codes into conf.c
e
s 00003/00004/00226
d D 3.11 81/08/18 16:47:19 eric 17 16
c convert to really do arpanet reply codes right (maybe)
e
s 00015/00019/00215
d D 3.10 81/08/09 15:03:04 eric 16 15
c lint it
e
s 00013/00008/00221
d D 3.9 81/08/09 12:34:41 eric 15 14
c add private incoming mailers; add q_home field to ADDRESS struct;
c some general cleanup
e
s 00003/00006/00226
d D 3.8 81/08/08 16:06:55 eric 14 13
c fix up response printing
e
s 00003/00002/00229
d D 3.7 81/08/08 13:51:40 eric 13 12
c give arpanet-style error messages on -a
e
s 00001/00001/00230
d D 3.6 81/03/20 09:45:37 eric 12 11
c change name (again); from postbox to sendmail
e
s 00011/00030/00220
d D 3.5 81/03/11 10:46:06 eric 11 10
c general cleanup, esp. macro processor
e
s 00003/00003/00247
d D 3.4 81/03/09 13:22:29 eric 10 9
c first step at rewriting rules, etc.
e
s 00002/00002/00248
d D 3.3 81/03/07 16:59:39 eric 9 8
c change q_mailer to be index, not pointer
e
s 00002/00000/00248
d D 3.2 81/03/07 15:32:58 eric 8 7
c lint fixes
e
s 00003/00003/00245
d D 3.1 81/03/07 14:26:59 eric 7 6
c ----- delivermail ==> postbox -----
e
s 00003/00004/00245
d D 2.2 81/01/10 12:19:34 eric 6 5
c have name of mailer daemon be a configuration parameter
e
s 00000/00000/00249
d D 2.1 80/11/05 11:01:03 eric 5 4
c release 2
e
s 00000/00045/00249
d D 1.4 80/08/02 13:49:50 eric 4 3
c cleaned up comments
e
s 00002/00000/00292
d D 1.3 80/07/25 22:04:16 eric 3 2
c add ID keywords
e
s 00010/00021/00282
d D 1.2 80/07/25 21:40:17 eric 2 1
c changed "-ee" flag to work with BerkNet better
e
s 00303/00000/00000
d D 1.1 80/06/23 08:24:35 eric 1 0
e
u
U
f b 
f i 
t
T
I 75
/*
I 83
 * Copyright (c) 1983 Eric P. Allman
E 83
D 82
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 82
I 82
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 83
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 83
I 83
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
E 83
 */
E 82

#ifndef lint
D 82
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint
E 82
I 82
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 82

E 75
I 1
D 19
# include <stdio.h>
E 19
# include <pwd.h>
D 7
# include "dlvrmail.h"
E 7
I 7
D 12
# include "postbox.h"
E 12
I 12
# include "sendmail.h"
E 12
E 7

I 3
D 30
static char	SccsId[] = "%W%	%G%";
E 30
I 30
D 76
SCCSID(%W%	%Y%	%G%);
E 30

E 76
E 3
/*
**  SAVEMAIL -- Save mail on error
**
D 58
**	If the MailBack flag is set, mail it back to the originator
E 58
I 58
**	If mailing back errors, mail it back to the originator
E 58
**	together with an error message; otherwise, just put it in
**	dead.letter in the user's home directory (if he exists on
**	this machine).
**
**	Parameters:
D 56
**		none
E 56
I 56
**		e -- the envelope containing the message in error.
E 56
**
**	Returns:
**		none
**
**	Side Effects:
**		Saves the letter, by writing or mailing it back to the
**		sender, or by putting it in dead.letter in her home
**		directory.
D 23
**
**		WARNING: the user id is reset to the original user.
E 23
D 4
**
**	Requires:
**		fopen (sys)
**		bmove
**		parse
**		deliver
**		strcpy (sys)
**		strcat (sys)
**		fclose (sys)
**		fgets (sys)
**		fputs (sys)
**		setpwent (sys)
**		getuid (sys)
**		setuid (sys)
**		getgid (sys)
**		setgid (sys)
**		getpwnam (sys)
**		fprintf (sys)
**		ttypath
**		freopen (sys)
**		printf (sys)
**		syserr
**		rewind (sys)
**		time (sys)
**		ferror (sys)
**
**	Called By:
**		finis
**
**	History:
**		12/30/79 -- written.
E 4
*/

I 77
/* defines for state machine */
# define ESM_REPORT	0	/* report to sender's terminal */
# define ESM_MAIL	1	/* mail back to sender */
# define ESM_QUIET	2	/* messages have already been returned */
# define ESM_DEADLETTER	3	/* save in ~/dead.letter */
# define ESM_POSTMASTER	4	/* return to postmaster */
# define ESM_USRTMP	5	/* save in /usr/tmp/dead.letter */
# define ESM_PANIC	6	/* leave the locked queue/transcript files */
# define ESM_DONE	7	/* the message is successfully delivered */


E 77
D 6
# define MY_NAME	"~MAILER~DAEMON~"

E 6
D 56
savemail()
E 56
I 56
savemail(e)
	register ENVELOPE *e;
E 56
{
	register struct passwd *pw;
D 77
	register FILE *xfile;
E 77
I 77
	register FILE *fp;
	int state;
	auto ADDRESS *q;
E 77
	char buf[MAXLINE+1];
D 27
	extern errhdr();
D 7
	auto addrq to_addr;
E 7
I 7
	auto ADDRESS to_addr;
E 27
E 7
	extern struct passwd *getpwnam();
	register char *p;
D 32
	register int i;
E 32
D 16
	auto long tim;
	extern int errno;
E 16
	extern char *ttypath();
D 11
	extern char *ctime();
E 11
D 7
	extern addrq *parse();
E 7
I 7
D 16
	extern ADDRESS *parse();
E 16
E 7
D 58
	static int exclusive;
E 58
I 32
	typedef int (*fnptr)();
I 36
D 38
	ENVELOPE errenvelope;
	register ENVELOPE *ee;
E 38
D 49
	extern ENVELOPE *newenvelope();
E 49
E 36
E 32
I 6
D 10
	extern char *DaemonName;
E 10
I 8
D 16
	extern char *strcpy(), *strcat();
D 11
	extern long time();
I 10
	extern char *Macro[];
E 11
I 11
	extern char *expand();
E 16
E 11
E 10
E 8
E 6

I 46
# ifdef DEBUG
D 48
	if (Debug)
E 48
I 48
	if (tTd(6, 1))
E 48
D 58
		printf("\nsavemail: exclusive %d\n", exclusive);
E 58
I 58
D 79
		printf("\nsavemail\n");
E 79
I 79
		printf("\nsavemail, ErrorMode = %c\n", ErrorMode);
E 79
E 58
# endif DEBUG

E 46
D 19
	if (exclusive++)
E 19
I 19
D 21
	if (exclusive++ || TempFile == NULL)
E 21
I 21
D 35
	if (exclusive++)
E 35
I 35
D 36
	if (exclusive++ || CurEnv->e_class <= PRI_JUNK)
E 36
I 36
D 58
	if (exclusive++)
E 58
I 58
	if (bitset(EF_RESPONSE, e->e_flags))
E 58
E 36
E 35
E 21
E 19
		return;
I 36
D 52
	if (CurEnv->e_class <= PRI_JUNK)
E 52
I 52
D 56
	if (CurEnv->e_class < 0)
E 56
I 56
	if (e->e_class < 0)
E 56
E 52
	{
D 41
		if (Verbose)
			message(Arpa_Info, "Dumping junk mail");
E 41
I 41
		message(Arpa_Info, "Dumping junk mail");
E 41
		return;
	}
E 36
I 31
D 40
	ForceMail = TRUE;
E 40
I 40
D 41
	/* ForceMail = TRUE; */
E 41
I 41
	ForceMail = TRUE;
I 47
D 56
	FatalErrors = FALSE;
E 56
I 56
	e->e_flags &= ~EF_FATALERRS;
E 56
E 47
E 41
E 40
E 31

	/*
	**  In the unhappy event we don't know who to return the mail
	**  to, make someone up.
	*/

D 34
	if (From.q_paddr == NULL)
E 34
I 34
D 39
D 56
	if (CurEnv->e_from.q_paddr == NULL)
E 56
I 56
	if (e->e_from.q_paddr == NULL)
E 56
E 39
I 39
	if (CurEnv->e_returnto == NULL)
E 39
E 34
	{
D 34
		if (parse("root", &From, 0) == NULL)
E 34
I 34
D 39
D 56
		if (parse("root", &CurEnv->e_from, 0) == NULL)
E 56
I 56
D 61
		if (parse("root", &e->e_from, 0) == NULL)
E 61
I 61
D 68
		if (parseaddr("root", &e->e_from, 0) == NULL)
E 68
I 68
		if (parseaddr("root", &e->e_from, 0, '\0') == NULL)
E 68
E 61
E 56
E 39
I 39
		CurEnv->e_returnto = parse("root", (ADDRESS *) NULL, 0);
		if (CurEnv->e_returnto == NULL)
E 39
E 34
		{
			syserr("Cannot parse root!");
			ExitStat = EX_SOFTWARE;
			finis();
		}
	}
I 15
D 34
	To = NULL;
E 34
I 34
D 56
	CurEnv->e_to = NULL;
E 56
I 56
	e->e_to = NULL;
E 56
E 34
E 15

	/*
D 2
	**  If echoing the bad mail, do it.
	**	Output the transcript and a message saying that the
	**	message will be mailed back; then fall through to
	**	the MailBack case.
E 2
I 2
D 77
	**  If called from Eric Schmidt's network, do special mailback.
	**	Fundamentally, this is the mailback case except that
	**	it returns an OK exit status (assuming the return
	**	worked).
I 37
	**  Also, if the from address is not local, mail it back.
E 77
I 77
	**  Basic state machine.
	**
	**	This machine runs through the following states:
	**
	**	ESM_QUIET	Errors have already been printed iff the
	**			sender is local.
	**	ESM_REPORT	Report directly to the sender's terminal.
	**	ESM_MAIL	Mail response to the sender.
	**	ESM_DEADLETTER	Save response in ~/dead.letter.
	**	ESM_POSTMASTER	Mail response to the postmaster.
	**	ESM_PANIC	Save response anywhere possible.
E 77
E 37
E 2
	*/

D 2
	if (EchoBack || WriteBack)
E 2
I 2
D 58
	if (BerkNet)
E 58
I 58
D 77
	if (ErrorMode == EM_BERKNET)
E 77
I 77
	/* determine starting state */
	switch (ErrorMode)
E 77
E 58
E 2
	{
I 77
	  case EM_WRITE:
		state = ESM_REPORT;
		break;

	  case EM_BERKNET:
		/* mail back, but return o.k. exit status */
E 77
D 2
		xfile = fopen(Transcript, "r");
		if (xfile == NULL)
			syserr("Cannot open %s", Transcript);
		fflush(stdout);
	}
	else
		xfile = NULL;

	if (EchoBack)
	{
		while (fgets(buf, sizeof buf, xfile) != NULL)
			fputs(buf, stderr);
		fprintf(stderr, "\nThe unsent mail will be returned to you\n");
E 2
I 2
		ExitStat = EX_OK;
E 2
D 37
		MailBack++;
E 37
I 37
D 58
		MailBack = TRUE;
E 58
I 58
D 77
		ErrorMode = EM_MAIL;
E 58
E 37
	}
I 37
D 39
D 56
	if (!bitset(M_LOCAL, CurEnv->e_from.q_mailer->m_flags))
E 56
I 56
D 65
	if (!bitset(M_LOCAL, e->e_from.q_mailer->m_flags))
E 65
I 65
	if (!bitnset(M_LOCAL, e->e_from.q_mailer->m_flags))
E 65
E 56
E 39
I 39
	if (!bitset(M_LOCAL, CurEnv->e_returnto->q_mailer->m_flags))
E 39
D 58
		MailBack = TRUE;
E 58
I 58
		ErrorMode = EM_MAIL;
E 77
E 58
E 37

D 77
	/*
	**  If writing back, do it.
	**	If the user is still logged in on the same terminal,
	**	then write the error messages back to hir (sic).
D 58
	**	If not, set the MailBack flag so that it will get
	**	mailed back instead.
E 58
I 58
	**	If not, mail back instead.
E 58
	*/
E 77
I 77
		/* fall through.... */
E 77

D 58
	if (WriteBack)
E 58
I 58
D 77
	if (ErrorMode == EM_WRITE)
E 77
I 77
	  case EM_MAIL:
		state = ESM_MAIL;
		break;

	  case EM_PRINT:
I 79
	  case '\0':
E 79
		state = ESM_QUIET;
		break;

	  case EM_QUIET:
		/* no need to return anything at all */
		return;
I 79

	  default:
		syserr("savemail: ErrorMode x%x\n");
		state = ESM_MAIL;
		break;
E 79
	}

	while (state != ESM_DONE)
E 77
E 58
	{
I 79
# ifdef DEBUG
		if (tTd(6, 5))
			printf("  state %d\n", state);
# endif DEBUG

E 79
D 77
		p = ttypath();
		if (p == NULL || freopen(p, "w", stdout) == NULL)
E 77
I 77
		switch (state)
E 77
		{
I 79
		  case ESM_QUIET:
			if (e->e_from.q_mailer == LocalMailer)
				state = ESM_DEADLETTER;
			else
				state = ESM_MAIL;
			break;

E 79
D 37
			MailBack++;
E 37
I 37
D 58
			MailBack = TRUE;
E 58
I 58
D 77
			ErrorMode = EM_MAIL;
E 58
E 37
			errno = 0;
		}
		else
		{
E 77
I 77
		  case ESM_REPORT:

			/*
			**  If the user is still logged in on the same terminal,
			**  then write the error messages back to hir (sic).
			*/

			p = ttypath();
			if (p == NULL || freopen(p, "w", stdout) == NULL)
			{
				state = ESM_MAIL;
				break;
			}

E 77
I 58
D 71
			expand("$n", buf, &buf[sizeof buf - 1], e);
E 71
I 71
			expand("\001n", buf, &buf[sizeof buf - 1], e);
E 71
			printf("\r\nMessage from %s...\r\n", buf);
			printf("Errors occurred while sending mail.\r\n");
E 58
I 28
D 56
			(void) fflush(Xscript);
E 28
I 2
			xfile = fopen(Transcript, "r");
E 56
I 56
D 59
			if (Xscript != NULL)
E 59
I 59
			if (e->e_xfp != NULL)
E 59
I 58
			{
E 58
D 59
				(void) fflush(Xscript);
E 59
I 59
				(void) fflush(e->e_xfp);
E 59
D 58
			xfile = fopen(queuename(e, 'x'), "r");
E 58
I 58
D 77
				xfile = fopen(queuename(e, 'x'), "r");
E 77
I 77
				fp = fopen(queuename(e, 'x'), "r");
E 77
			}
			else
D 77
				xfile = NULL;
E 58
E 56
			if (xfile == NULL)
E 77
I 77
				fp = NULL;
			if (fp == NULL)
E 77
I 58
			{
E 58
D 56
				syserr("Cannot open %s", Transcript);
E 2
D 6
			printf("\r\nMessage from %s\r\n", MY_NAME);
E 6
I 6
D 10
			printf("\r\nMessage from %s\r\n", DaemonName);
E 10
I 10
D 11
			printf("\r\nMessage from %s\r\n", Macro['d']);
E 11
I 11
D 16
			printf("\r\nMessage from %s\r\n", expand("$n", buf, &buf[sizeof buf - 1]));
E 16
I 16
D 36
			(void) expand("$n", buf, &buf[sizeof buf - 1]);
E 36
I 36
			expand("$n", buf, &buf[sizeof buf - 1], CurEnv);
E 56
I 56
				syserr("Cannot open %s", queuename(e, 'x'));
D 58
			expand("$n", buf, &buf[sizeof buf - 1], e);
E 56
E 36
D 17
			printf("\r\nMessage from %s\r\n", buf);
E 17
I 17
			printf("\r\nMessage from %s...\r\n", buf);
E 17
E 16
E 11
E 10
E 6
D 23
			printf("Errors occurred while sending mail, transcript follows:\r\n");
E 23
I 23
			printf("Errors occurred while sending mail; transcript follows:\r\n");
E 23
D 16
			while (fgets(buf, sizeof buf, xfile) && !ferror(stdout))
E 16
I 16
			while (fgets(buf, sizeof buf, xfile) != NULL && !ferror(stdout))
E 16
				fputs(buf, stdout);
E 58
I 58
				printf("Transcript of session is unavailable.\r\n");
			}
			else
			{
				printf("Transcript follows:\r\n");
D 77
				while (fgets(buf, sizeof buf, xfile) != NULL &&
E 77
I 77
				while (fgets(buf, sizeof buf, fp) != NULL &&
E 77
				       !ferror(stdout))
					fputs(buf, stdout);
D 77
				(void) fclose(xfile);
E 77
I 77
				(void) fclose(fp);
E 77
			}
I 77
			printf("Original message will be saved in dead.letter.\r\n");
E 77
E 58
			if (ferror(stdout))
D 16
				syserr("savemail: stdout: write err");
I 2
			fclose(xfile);
E 16
I 16
				(void) syserr("savemail: stdout: write err");
D 58
			(void) fclose(xfile);
E 58
E 16
E 2
D 77
		}
	}
E 77
I 77
			state = ESM_DEADLETTER;
			break;
E 77

D 2
	if (xfile != NULL)
		fclose(xfile);

E 2
D 77
	/*
	**  If mailing back, do it.
	**	Throw away all further output.  Don't do aliases, since
	**	this could cause loops, e.g., if joe mails to x:joe,
	**	and for some reason the network for x: is down, then
	**	the response gets sent to x:joe, which gives a
	**	response, etc.  Also force the mail to be delivered
	**	even if a version of it has already been sent to the
	**	sender.
	*/
E 77
I 77
		  case ESM_MAIL:
		  case ESM_POSTMASTER:
			/*
			**  If mailing back, do it.
			**	Throw away all further output.  Don't alias,
			**	since this could cause loops, e.g., if joe
			**	mails to joe@x, and for some reason the network
			**	for @x is down, then the response gets sent to
			**	joe@x, which gives a response, etc.  Also force
			**	the mail to be delivered even if a version of
			**	it has already been sent to the sender.
			*/
E 77

D 9
	if (MailBack || From.q_mailer != &Mailer[0])
E 9
I 9
D 58
	if (MailBack)
E 58
I 58
D 77
	if (ErrorMode == EM_MAIL)
E 58
E 9
	{
I 43
D 56
		if (CurEnv->e_errorqueue == NULL)
D 44
			sendto(CurEnv->e_from.q_paddr, 1, NULL, &CurEnv->e_errorqueue);
E 44
I 44
D 50
			sendto(CurEnv->e_from.q_paddr, 1, (ADDRESS *) NULL, &CurEnv->e_errorqueue);
E 44
E 43
D 16
		freopen("/dev/null", "w", stdout);
E 16
I 16
D 27
		(void) freopen("/dev/null", "w", stdout);
E 16
		NoAlias++;
		ForceMail++;

		/* fake up an address header for the from person */
		bmove((char *) &From, (char *) &to_addr, sizeof to_addr);
D 6
		if (parse(MY_NAME, &From, -1) == NULL)
E 6
I 6
D 10
		if (parse(DaemonName, &From, -1) == NULL)
E 10
I 10
D 11
		if (parse(Macro['d'], &From, -1) == NULL)
E 11
I 11
D 16
		if (parse(expand("$n", buf, &buf[sizeof buf - 1]), &From, -1) == NULL)
E 16
I 16
		(void) expand("$n", buf, &buf[sizeof buf - 1]);
		if (parse(buf, &From, -1) == NULL)
E 16
E 11
E 10
E 6
		{
			syserr("Can't parse myself!");
			ExitStat = EX_SOFTWARE;
			finis();
		}
I 23
		to_addr.q_next = NULL;
E 23
		i = deliver(&to_addr, errhdr);
		bmove((char *) &to_addr, (char *) &From, sizeof From);
		if (i != 0)
			syserr("Can't return mail to %s", p);
		else
E 27
I 27
D 33
		if (returntosender("Unable to deliver mail") == 0)
E 33
I 33
D 36
		if (returntosender("Unable to deliver mail", TRUE) == 0)
E 36
I 36
D 39
D 40
		if (returntosender("Unable to deliver mail", &CurEnv->e_from, TRUE) == 0)
E 40
I 40
		if (returntosender("Unable to deliver mail", CurEnv->e_errorqueue, TRUE) == 0)
E 50
I 50
			sendto(CurEnv->e_from.q_paddr, (ADDRESS *) NULL,
			       &CurEnv->e_errorqueue);
E 56
I 56
		if (e->e_errorqueue == NULL)
D 60
			sendto(e->e_from.q_paddr, (ADDRESS *) NULL,
E 60
I 60
			sendtolist(e->e_from.q_paddr, (ADDRESS *) NULL,
E 60
			       &e->e_errorqueue);
E 56
D 63
		if (returntosender("Unable to deliver mail",
E 63
I 63
		if (returntosender(e->e_message != NULL ? e->e_message :
				   "Unable to deliver mail",
E 63
D 56
				   CurEnv->e_errorqueue, TRUE) == 0)
E 56
I 56
				   e->e_errorqueue, TRUE) == 0)
E 56
E 50
E 40
E 39
I 39
		if (returntosender("Unable to deliver mail", CurEnv->e_returnto, TRUE) == 0)
E 39
E 36
E 33
E 27
			return;
	}
E 77
I 77
			if (state == ESM_MAIL)
			{
				if (e->e_errorqueue == NULL)
					sendtolist(e->e_from.q_paddr,
						(ADDRESS *) NULL,
						&e->e_errorqueue);
I 80

				/* deliver a cc: to the postmaster if desired */
				if (PostMasterCopy != NULL)
					sendtolist(PostMasterCopy,
						(ADDRESS *) NULL,
						&e->e_errorqueue);
E 80
				q = e->e_errorqueue;
			}
			else
			{
D 78
				if (parseaddr("postmaster", &q, 0, '\0') == NULL)
E 78
I 78
				if (parseaddr("postmaster", q, 0, '\0') == NULL)
E 78
				{
					syserr("cannot parse postmaster!");
					ExitStat = EX_SOFTWARE;
					state = ESM_USRTMP;
					break;
				}
			}
			if (returntosender(e->e_message != NULL ? e->e_message :
					   "Unable to deliver mail",
					   q, TRUE) == 0)
			{
				state = ESM_DONE;
				break;
			}
E 77

D 77
	/*
	**  Save the message in dead.letter.
	**	If we weren't mailing back, and the user is local, we
	**	should save the message in dead.letter so that the
	**	poor person doesn't have to type it over again --
	**	and we all know what poor typists programmers are.
I 46
D 58
	**	However, if we are running a "smart" protocol, we don't
	**	bother to return the message, since the other end is
	**	expected to handle that.
E 58
E 46
	*/
E 77
I 77
			state = state == ESM_MAIL ? ESM_POSTMASTER : ESM_USRTMP;
			break;
E 77

I 13
D 14
	To = NULL;
E 14
E 13
D 16
	setuid(getuid());
	setgid(getgid());
E 16
I 16
D 17
	(void) setuid(getuid());
	(void) setgid(getgid());
E 16
	setpwent();
E 17
I 17
D 28
	if (ArpaMode != ARPA_NONE)
E 28
I 28
D 55
	if (ArpaMode)
E 55
I 55
D 58
	if (OpMode == MD_ARPAFTP || OpMode == MD_SMTP)
E 55
E 28
		return;
E 58
E 17
D 9
	if (From.q_mailer == &Mailer[0] && (pw = getpwnam(From.q_user)) != NULL)
E 9
I 9
D 15
	if (From.q_mailer == 0 && (pw = getpwnam(From.q_user)) != NULL)
E 15
I 15
D 77
	p = NULL;
D 20
	if (From.q_mailer == M_LOCAL)
E 20
I 20
D 26
	if (From.q_mailer == MN_LOCAL)
E 26
I 26
D 34
	if (From.q_mailer == LocalMailer)
E 34
I 34
D 39
D 56
	if (CurEnv->e_from.q_mailer == LocalMailer)
E 56
I 56
	if (e->e_from.q_mailer == LocalMailer)
E 56
E 39
I 39
	if (CurEnv->e_returnto->q_mailer == LocalMailer)
E 39
E 34
E 26
E 20
E 15
E 9
	{
D 15
		/* user has a home directory */
		p = pw->pw_dir;
E 15
I 15
D 34
		if (From.q_home != NULL)
			p = From.q_home;
		else if ((pw = getpwnam(From.q_user)) != NULL)
E 34
I 34
D 39
D 56
		if (CurEnv->e_from.q_home != NULL)
			p = CurEnv->e_from.q_home;
		else if ((pw = getpwnam(CurEnv->e_from.q_user)) != NULL)
E 56
I 56
		if (e->e_from.q_home != NULL)
			p = e->e_from.q_home;
		else if ((pw = getpwnam(e->e_from.q_user)) != NULL)
E 56
E 39
I 39
		if (CurEnv->e_returnto->q_home != NULL)
			p = CurEnv->e_returnto->q_home;
		else if ((pw = getpwnam(CurEnv->e_returnto->q_user)) != NULL)
E 39
E 34
			p = pw->pw_dir;
E 15
	}
D 15
	else
E 15
I 15
	if (p == NULL)
E 15
	{
D 15
		syserr("Can't return mail to %s (pw=%u)", From.q_paddr, pw);
E 15
I 15
D 34
		syserr("Can't return mail to %s", From.q_paddr);
E 34
I 34
D 39
D 56
		syserr("Can't return mail to %s", CurEnv->e_from.q_paddr);
E 56
I 56
		syserr("Can't return mail to %s", e->e_from.q_paddr);
E 56
E 39
I 39
		syserr("Can't return mail to %s", CurEnv->e_returnto->q_paddr);
E 39
E 34
E 15
# ifdef DEBUG
		p = "/usr/tmp";
D 46
# else
		p = NULL;
E 46
# endif
	}
D 21
	if (p != NULL)
E 21
I 21
D 59
	if (p != NULL && TempFile != NULL)
E 59
I 59
	if (p != NULL && e->e_dfp != NULL)
E 59
E 21
	{
I 31
		auto ADDRESS *q;
I 41
		bool oldverb = Verbose;
E 77
I 77
		  case ESM_DEADLETTER:
			/*
			**  Save the message in dead.letter.
			**	If we weren't mailing back, and the user is
			**	local, we should save the message in
			**	~/dead.letter so that the poor person doesn't
			**	have to type it over again -- and we all know
			**	what poor typists UNIX users are.
			*/
E 77
E 41

E 31
D 77
		/* we have a home directory; open dead.letter */
I 58
		define('z', p, e);
D 71
		expand("$z/dead.letter", buf, &buf[sizeof buf - 1], e);
E 71
I 71
		expand("\001z/dead.letter", buf, &buf[sizeof buf - 1], e);
E 71
E 58
I 41
		Verbose = TRUE;
E 41
D 15
		strcpy(buf, p);
		strcat(buf, "/dead.letter");
E 15
I 15
D 18
		message("050", "Saving message in dead.letter");
E 18
I 18
D 58
		message(Arpa_Info, "Saving message in dead.letter");
E 58
I 58
		message(Arpa_Info, "Saving message in %s", buf);
E 58
I 41
		Verbose = oldverb;
E 41
E 18
D 58
		define('z', p);
D 16
		expand("$z/dead.letter", buf, &buf[sizeof buf - 1]);
E 16
I 16
D 36
		(void) expand("$z/dead.letter", buf, &buf[sizeof buf - 1]);
E 36
I 36
D 56
		expand("$z/dead.letter", buf, &buf[sizeof buf - 1], CurEnv);
E 36
E 16
E 15
D 11
		xfile = fopen(buf, "a");
		if (xfile == NULL)
E 11
I 11
D 14
		if (mailfile(buf) != EX_OK)
E 11
D 13
			printf("Cannot save mail, sorry\n");
E 13
I 13
			message("050", "Cannot save mail, sorry");
E 13
		else
D 11
		{
			rewind(stdin);
			errno = 0;
			time(&tim);
			fprintf(xfile, "----- Mail saved at %s", ctime(&tim));
			while (fgets(buf, sizeof buf, stdin) && !ferror(xfile))
				fputs(buf, xfile);
			fputs("\n", xfile);
			if (ferror(xfile))
				syserr("savemail: dead.letter: write err");
			fclose(xfile);
E 11
D 13
			printf("Letter saved in dead.letter\n");
E 13
I 13
			message("050", "Letter saved in dead.letter");
E 14
I 14
D 34
		To = buf;
E 34
I 34
		CurEnv->e_to = buf;
E 56
I 56
		expand("$z/dead.letter", buf, &buf[sizeof buf - 1], e);
E 58
		e->e_to = buf;
E 56
E 34
D 24
		i = mailfile(buf);
E 24
I 24
D 31
		i = mailfile(buf, &From);
E 24
D 15
		giveresponse(i, TRUE, Mailer[0]);
E 15
I 15
D 20
		giveresponse(i, TRUE, Mailer[M_LOCAL]);
E 20
I 20
D 26
		giveresponse(i, TRUE, Mailer[MN_LOCAL]);
E 26
I 26
		giveresponse(i, TRUE, LocalMailer);
E 31
I 31
		q = NULL;
D 32
		sendto(buf, -1, NULL, &q);
		(void) deliver(q, NULL);
E 32
I 32
D 50
		sendto(buf, -1, (ADDRESS *) NULL, &q);
E 50
I 50
D 60
		sendto(buf, (ADDRESS *) NULL, &q);
E 60
I 60
		sendtolist(buf, (ADDRESS *) NULL, &q);
E 60
E 50
D 36
		(void) deliver(q, (fnptr) NULL);
E 36
I 36
D 58
		(void) deliver(q);
E 58
I 58
		(void) deliver(e, q);
E 58
E 36
E 32
E 31
E 26
E 20
E 15
E 14
E 13
D 11
		}
E 11
	}
E 77
I 77
			p = NULL;
			if (e->e_from.q_mailer == LocalMailer)
			{
				if (e->e_from.q_home != NULL)
					p = e->e_from.q_home;
				else if ((pw = getpwnam(e->e_from.q_user)) != NULL)
					p = pw->pw_dir;
			}
			if (p == NULL)
			{
				syserr("Can't return mail to %s", e->e_from.q_paddr);
				state = ESM_MAIL;
				break;
			}
			if (e->e_dfp != NULL)
			{
				auto ADDRESS *q;
				bool oldverb = Verbose;
E 77
D 14
	else
E 14

D 77
	/* add terminator to writeback message */
D 58
	if (WriteBack)
E 58
I 58
	if (ErrorMode == EM_WRITE)
E 58
		printf("-----\r\n");
E 77
I 77
				/* we have a home directory; open dead.letter */
				define('z', p, e);
				expand("\001z/dead.letter", buf, &buf[sizeof buf - 1], e);
				Verbose = TRUE;
				message(Arpa_Info, "Saving message in %s", buf);
				Verbose = oldverb;
				e->e_to = buf;
				q = NULL;
				sendtolist(buf, (ADDRESS *) NULL, &q);
				if (deliver(e, q) == 0)
					state = ESM_DONE;
				else
					state = ESM_MAIL;
			}
I 81
			else
			{
				/* no data file -- try mailing back */
				state = ESM_MAIL;
			}
E 81
			break;

		  case ESM_USRTMP:
			/*
			**  Log the mail in /usr/tmp/dead.letter.
			*/

			fp = dfopen("/usr/tmp/dead.letter", "a");
			if (fp == NULL)
			{
				state = ESM_PANIC;
				break;
			}

			putfromline(fp, ProgMailer);
			(*e->e_puthdr)(fp, ProgMailer, e);
			putline("\n", fp, ProgMailer);
			(*e->e_putbody)(fp, ProgMailer, e);
			putline("\n", fp, ProgMailer);
			(void) fflush(fp);
			state = ferror(fp) ? ESM_PANIC : ESM_DONE;
			(void) fclose(fp);
			break;

		  default:
			syserr("savemail: unknown state %d", state);

			/* fall through ... */

		  case ESM_PANIC:
			syserr("savemail: HELP!!!!");
# ifdef LOG
			if (LogLevel >= 1)
				syslog(LOG_ALERT, "savemail: HELP!!!!");
# endif LOG

			/* leave the locked queue & transcript files around */
			exit(EX_SOFTWARE);
		}
	}
E 77
}
/*
I 27
**  RETURNTOSENDER -- return a message to the sender with an error.
**
**	Parameters:
**		msg -- the explanatory message.
I 40
D 73
**		returnto -- the queue of people to send the message to.
E 73
I 73
**		returnq -- the queue of people to send the message to.
E 73
E 40
I 33
**		sendbody -- if TRUE, also send back the body of the
**			message; otherwise just send the header.
E 33
**
**	Returns:
**		zero -- if everything went ok.
**		else -- some error.
**
**	Side Effects:
**		Returns the current message to the sender via
**		mail.
*/

D 38
static char	*ErrorMessage;
E 38
I 33
static bool	SendBody;
E 33

I 40
#define MAXRETURNS	6	/* max depth of returning messages */

E 40
D 33
returntosender(msg)
E 33
I 33
D 36
returntosender(msg, sendbody)
E 36
I 36
D 73
returntosender(msg, returnto, sendbody)
E 73
I 73
returntosender(msg, returnq, sendbody)
E 73
E 36
E 33
	char *msg;
I 36
D 73
	ADDRESS *returnto;
E 73
I 73
	ADDRESS *returnq;
E 73
E 36
I 33
	bool sendbody;
E 33
{
D 40
	ADDRESS to_addr;
E 40
	char buf[MAXNAME];
D 44
	register int i;
E 44
D 36
	extern errhdr();
E 36
I 36
	extern putheader(), errbody();
	register ENVELOPE *ee;
	extern ENVELOPE *newenvelope();
	ENVELOPE errenvelope;
I 40
	static int returndepth;
I 58
	register ADDRESS *q;
E 58
E 40
E 36

I 45
# ifdef DEBUG
D 48
	if (Debug > 0)
E 48
I 48
	if (tTd(6, 1))
E 48
	{
		printf("Return To Sender: msg=\"%s\", depth=%d, CurEnv=%x,\n",
		       msg, returndepth, CurEnv);
D 77
		printf("\treturnto=");
E 77
I 77
		printf("\treturnq=");
E 77
D 58
		printaddr(returnto, FALSE);
E 58
I 58
D 73
		printaddr(returnto, TRUE);
E 73
I 73
		printaddr(returnq, TRUE);
E 73
E 58
	}
# endif DEBUG

E 45
I 40
	if (++returndepth >= MAXRETURNS)
	{
		if (returndepth != MAXRETURNS)
D 73
			syserr("returntosender: infinite recursion on %s", returnto->q_paddr);
E 73
I 73
			syserr("returntosender: infinite recursion on %s", returnq->q_paddr);
E 73
		/* don't "unrecurse" and fake a clean exit */
		/* returndepth--; */
		return (0);
	}

E 40
D 33
	(void) freopen("/dev/null", "w", stdout);
E 33
D 37
	NoAlias++;
E 37
I 37
D 58
	NoAlias = TRUE;
E 58
E 37
D 31
	ForceMail++;
E 31
D 36
	ErrorMessage = msg;
E 36
I 33
	SendBody = sendbody;
I 51
D 58
	define('g', "$f");
E 58
I 58
D 71
	define('g', "$f", CurEnv);
E 71
I 71
	define('g', "\001f", CurEnv);
E 71
E 58
E 51
I 36
	ee = newenvelope(&errenvelope);
I 77
	define('a', "\001b", ee);
E 77
	ee->e_puthdr = putheader;
	ee->e_putbody = errbody;
I 58
	ee->e_flags |= EF_RESPONSE;
D 73
	ee->e_sendqueue = returnto;
E 73
I 73
	ee->e_sendqueue = returnq;
E 73
E 58
I 53
D 57
	queuename(ee, '\0');
E 57
I 57
D 59
	(void) queuename(ee, '\0');
E 59
I 59
	openxscript(ee);
E 59
E 57
E 53
D 54
	addheader("date", "$b", ee);
	addheader("from", "$g (Mail Delivery Subsystem)", ee);
E 54
D 58
	addheader("to", returnto->q_paddr, ee);
E 58
I 58
D 73
	for (q = returnto; q != NULL; q = q->q_next)
E 73
I 73
	for (q = returnq; q != NULL; q = q->q_next)
E 73
	{
		if (q->q_alias == NULL)
			addheader("to", q->q_paddr, ee);
	}
I 77

E 77
E 58
D 63
	addheader("subject", msg, ee);
E 63
I 63
D 66
	(void) sprintf(buf, "MAIL FAILURE: %s", msg);
E 66
I 66
	(void) sprintf(buf, "Returned mail: %s", msg);
E 66
	addheader("subject", buf, ee);
E 63
E 36
E 33

	/* fake up an address header for the from person */
D 34
	bmove((char *) &From, (char *) &to_addr, sizeof to_addr);
E 34
I 34
D 36
	bmove((char *) &CurEnv->e_from, (char *) &to_addr, sizeof to_addr);
E 34
	(void) expand("$n", buf, &buf[sizeof buf - 1]);
D 34
	if (parse(buf, &From, -1) == NULL)
E 34
I 34
	if (parse(buf, &CurEnv->e_from, -1) == NULL)
E 36
I 36
D 40
	bmove((char *) returnto, (char *) &to_addr, sizeof to_addr);
E 40
D 71
	expand("$n", buf, &buf[sizeof buf - 1], CurEnv);
E 71
I 71
	expand("\001n", buf, &buf[sizeof buf - 1], CurEnv);
E 71
D 61
	if (parse(buf, &ee->e_from, -1) == NULL)
E 61
I 61
D 68
	if (parseaddr(buf, &ee->e_from, -1) == NULL)
E 68
I 68
	if (parseaddr(buf, &ee->e_from, -1, '\0') == NULL)
E 68
E 61
E 36
E 34
	{
		syserr("Can't parse myself!");
		ExitStat = EX_SOFTWARE;
I 40
		returndepth--;
E 40
		return (-1);
	}
I 72
	loweraddr(&ee->e_from);
E 72
D 40
	to_addr.q_next = NULL;
I 33
	to_addr.q_flags &= ~QDONTSEND;
E 33
D 36
	i = deliver(&to_addr, errhdr);
D 34
	bmove((char *) &to_addr, (char *) &From, sizeof From);
E 34
I 34
	bmove((char *) &to_addr, (char *) &CurEnv->e_from, sizeof CurEnv->e_from);
E 36
I 36
	ee->e_sendqueue = &to_addr;
E 40
I 40
D 58
	ee->e_sendqueue = returnto;
E 58
E 40
E 36
E 34
I 33

D 34
	/* if From was queued up, put in on SendQueue */
	if (bitset(QQUEUEUP, From.q_flags))
E 34
I 34
D 36
	/* if CurEnv->e_from was queued up, put in on CurEnv->e_sendqueue */
	if (bitset(QQUEUEUP, CurEnv->e_from.q_flags))
E 34
	{
D 34
		From.q_next = SendQueue;
		SendQueue = &From;
E 34
I 34
		CurEnv->e_from.q_next = CurEnv->e_sendqueue;
		CurEnv->e_sendqueue = &CurEnv->e_from;
E 34
	}
E 36
I 36
	/* push state into submessage */
	CurEnv = ee;
D 58
	define('f', "$n");
	define('x', "Mail Delivery Subsystem");
E 58
I 58
D 71
	define('f', "$n", ee);
E 71
I 71
	define('f', "\001n", ee);
E 71
	define('x', "Mail Delivery Subsystem", ee);
I 67
	eatheader(ee);
E 67
E 58
E 36

I 36
	/* actually deliver the error message */
D 40
	i = deliver(&to_addr);
E 40
I 40
D 55
	sendall(ee, FALSE);
E 55
I 55
D 70
	sendall(ee, SendMode);
E 70
I 70
	sendall(ee, SM_DEFAULT);
E 70
E 55
E 40

D 40
	/* if the error message was "queued", make that happen */
	if (bitset(QQUEUEUP, to_addr.q_flags))
D 38
		queueup(ee);
E 38
I 38
		queueup(ee, FALSE);
E 40
I 40
D 58
	/* do any closing error processing */
	checkerrors(ee);
E 40
E 38

E 58
	/* restore state */
I 49
	dropenvelope(ee);
E 49
	CurEnv = CurEnv->e_parent;
I 40
	returndepth--;
E 40

E 36
E 33
D 40
	if (i != 0)
	{
D 34
		syserr("Can't return mail to %s", From.q_paddr);
E 34
I 34
D 36
		syserr("Can't return mail to %s", CurEnv->e_from.q_paddr);
E 36
I 36
		syserr("Can't return mail to %s", to_addr.q_paddr);
E 36
E 34
		return (-1);
	}
E 40
I 40
	/* should check for delivery errors here */
E 40
	return (0);
}
/*
E 27
D 36
**  ERRHDR -- Output the header for error mail.
E 36
I 36
D 38
**  ERRHEADER -- Output the header for error mail.
E 36
**
D 36
**	This is the edit filter to error mailbacks.
E 36
I 36
**	Parameters:
**		xfile -- the transcript file.
**		fp -- the output file.
E 36
**
I 36
**	Returns:
**		none
**
**	Side Effects:
**		Outputs the header for an error message.
*/

errheader(fp, m)
	register FILE *fp;
	register struct mailer *m;
{
	/*
	**  Output header of error message.
	*/

	putheader(fp, m);
}
/*
E 38
**  ERRBODY -- output the body of an error message.
**
**	Typically this is a copy of the transcript plus a copy of the
**	original offending message.
**
E 36
D 27
**	Algorithm:
**		Output fixed header.
**		Output the transcript part.
**		Output the original message.
**
E 27
**	Parameters:
D 64
**		xfile -- the transcript file.
E 64
**		fp -- the output file.
I 29
D 36
**		xdot -- if set, use smtp hidden dot algorithm.
E 36
I 36
D 64
**		xdot -- if set, use the SMTP hidden dot algorithm.
E 64
I 64
**		m -- the mailer to output to.
E 64
I 59
**		e -- the envelope we are working in.
I 62
D 64
**		crlf -- set if we want CRLF's at the end of lines.
E 64
E 62
E 59
E 36
E 29
**
**	Returns:
**		none
**
**	Side Effects:
D 27
**		input from xfile
**		output to fp
**
D 4
**	Requires:
**		read (sys)
**		write (sys)
**		open (sys)
**		close (sys)
**		syserr
**		rewind (sys)
**		fflush (sys)
**		fprintf (sys)
**		fileno (sys)
**
E 4
**	Called By:
**		deliver
E 27
I 27
D 36
**		Outputs the current message with an appropriate
**		error header.
E 36
I 36
**		Outputs the body of an error message.
E 36
E 27
D 4
**
**	History:
**		12/28/79 -- written.
E 4
*/

D 27

E 27
D 23
errhdr(fp)
E 23
I 23
D 29
errhdr(fp, m)
E 29
I 29
D 36
errhdr(fp, m, xdot)
E 36
I 36
D 59
errbody(fp, m, xdot)
E 59
I 59
D 62
errbody(fp, m, xdot, e)
E 62
I 62
D 64
errbody(fp, m, xdot, e, crlf)
E 64
I 64
errbody(fp, m, e)
E 64
E 62
E 59
E 36
E 29
E 23
	register FILE *fp;
I 23
	register struct mailer *m;
I 29
D 64
	bool xdot;
E 64
I 59
	register ENVELOPE *e;
I 62
D 64
	bool crlf;
E 64
E 62
E 59
E 29
E 23
{
D 11
	char copybuf[512];
	register int i;
	register int xfile;
E 11
I 11
D 36
	char buf[MAXLINE];
E 36
	register FILE *xfile;
I 25
D 36
	extern char *macvalue();
	char *oldfmac;
	char *oldgmac;
E 36
I 36
	char buf[MAXLINE];
I 42
D 64
	bool fullsmtp = bitset(M_FULLSMTP, m->m_flags);
E 64
I 56
	char *p;
E 56
E 42
E 36
E 25
E 11
D 16
	extern int errno;
E 16

I 54
	/*
	**  Output transcript of errors
	*/

E 54
I 25
D 36
	oldfmac = macvalue('f');
	define('f', "$n");
	oldgmac = macvalue('g');
	define('g', m->m_from);

E 36
E 25
D 11
	if ((xfile = open(Transcript, 0)) < 0)
		syserr("Cannot open %s", Transcript);
E 11
D 16
	fflush(stdout);
E 16
I 16
	(void) fflush(stdout);
I 28
D 36
	(void) fflush(Xscript);
E 36
E 28
E 16
I 11
D 56
	if ((xfile = fopen(Transcript, "r")) == NULL)
E 56
I 56
D 59
	p = queuename(CurEnv->e_parent, 'x');
E 59
I 59
	p = queuename(e->e_parent, 'x');
E 59
	if ((xfile = fopen(p, "r")) == NULL)
E 56
I 54
	{
E 54
D 56
		syserr("Cannot open %s", Transcript);
E 56
I 56
		syserr("Cannot open %s", p);
E 56
I 54
		fprintf(fp, "  ----- Transcript of session is unavailable -----\n");
	}
	else
	{
		fprintf(fp, "   ----- Transcript of session follows -----\n");
D 56
		(void) fflush(Xscript);
E 56
I 56
D 59
		if (Xscript != NULL)
			(void) fflush(Xscript);
E 59
I 59
		if (e->e_xfp != NULL)
			(void) fflush(e->e_xfp);
E 59
E 56
		while (fgets(buf, sizeof buf, xfile) != NULL)
D 62
			putline(buf, fp, fullsmtp);
E 62
I 62
D 64
			putline(buf, fp, crlf, fullsmtp);
E 64
I 64
			putline(buf, fp, m);
E 64
E 62
		(void) fclose(xfile);
	}
E 54
E 11
	errno = 0;
I 23

	/*
I 25
D 36
	**  Output "From" line unless supressed
	*/

	if (!bitset(M_NHDR, m->m_flags))
	{
		(void) expand("$l", buf, &buf[sizeof buf - 1]);
		fprintf(fp, "%s\n", buf);
	}

	/*
E 25
	**  Output header of error message.
	*/

	if (bitset(M_NEEDDATE, m->m_flags))
	{
		(void) expand("$b", buf, &buf[sizeof buf - 1]);
		fprintf(fp, "Date: %s\n", buf);
	}
	if (bitset(M_NEEDFROM, m->m_flags))
	{
		(void) expand("$g", buf, &buf[sizeof buf - 1]);
		fprintf(fp, "From: %s (Mail Delivery Subsystem)\n", buf);
	}
E 23
D 34
	fprintf(fp, "To: %s\n", To);
E 34
I 34
	fprintf(fp, "To: %s\n", CurEnv->e_to);
E 34
D 27
	fprintf(fp, "Subject: Unable to deliver mail\n");
E 27
I 27
	fprintf(fp, "Subject: %s\n", ErrorMessage);
E 27
I 25

	/*
	**  End of error message header
	*/

	define('f', oldfmac);
	define('g', oldgmac);
E 25
I 23

	/*
E 36
D 54
	**  Output transcript of errors
	*/

E 23
D 36
	fprintf(fp, "\n   ----- Transcript of session follows -----\n");
E 36
I 36
	fprintf(fp, "   ----- Transcript of session follows -----\n");
E 36
I 28
	(void) fflush(Xscript);
E 28
D 11
	fflush(fp);
	while ((i = read(xfile, copybuf, sizeof copybuf)) > 0)
		write(fileno(fp), copybuf, i);
E 11
I 11
D 16
	while (fgets(xfile, buf, sizeof buf) != NULL)
E 16
I 16
	while (fgets(buf, sizeof buf, xfile) != NULL)
E 16
D 42
		fputs(buf, fp);
E 42
I 42
		putline(buf, fp, fullsmtp);
E 42
I 23

	/*
E 54
	**  Output text of original message
	*/

E 23
E 11
D 21
	fprintf(fp, "\n   ----- Unsent message follows -----\n");
D 16
	fflush(fp);
E 16
I 16
	(void) fflush(fp);
E 16
D 11
	rewind(stdin);
	while ((i = read(fileno(stdin), copybuf, sizeof copybuf)) > 0)
		write(fileno(fp), copybuf, i);
E 11
I 11
	putmessage(fp, Mailer[1]);
E 21
I 21
D 22
	if (TempFile != NULL)
E 22
I 22
	if (NoReturn)
		fprintf(fp, "\n   ----- Return message suppressed -----\n\n");
D 59
	else if (TempFile != NULL)
E 59
I 59
	else if (e->e_parent->e_dfp != NULL)
E 59
E 22
	{
D 33
		fprintf(fp, "\n   ----- Unsent message follows -----\n");
		(void) fflush(fp);
D 29
		putmessage(fp, Mailer[1]);
E 29
I 29
		putmessage(fp, Mailer[1], xdot);
E 33
I 33
		if (SendBody)
		{
D 64
			fprintf(fp, "\n   ----- Unsent message follows -----\n");
E 64
I 64
			putline("\n", fp, m);
			putline("   ----- Unsent message follows -----\n", fp, m);
E 64
			(void) fflush(fp);
D 36
			putmessage(fp, Mailer[1], xdot);
E 36
I 36
D 38
			putheader(fp, Mailer[1], CurEnv->e_parent);
E 38
I 38
D 59
			putheader(fp, m, CurEnv->e_parent);
E 59
I 59
D 62
			putheader(fp, m, e->e_parent);
E 62
I 62
D 64
			putheader(fp, m, e->e_parent, crlf);
E 62
E 59
E 38
			fprintf(fp, "\n");
D 38
			putbody(fp, Mailer[1], xdot);
E 38
I 38
D 59
			putbody(fp, m, xdot);
E 59
I 59
D 62
			putbody(fp, m, xdot, e->e_parent);
E 62
I 62
			putbody(fp, m, xdot, e->e_parent, crlf);
E 64
I 64
			putheader(fp, m, e->e_parent);
			putline("\n", fp, m);
			putbody(fp, m, e->e_parent);
E 64
E 62
E 59
E 38
E 36
		}
		else
		{
D 64
			fprintf(fp, "\n  ----- Message header follows -----\n");
E 64
I 64
			putline("\n", fp, m);
			putline("  ----- Message header follows -----\n", fp, m);
E 64
			(void) fflush(fp);
D 38
			putheader(fp, Mailer[1]);
E 38
I 38
D 58
			putheader(fp, m, CurEnv);
E 58
I 58
D 59
			putheader(fp, m, CurEnv->e_parent);
E 59
I 59
D 62
			putheader(fp, m, e->e_parent);
E 62
I 62
D 64
			putheader(fp, m, e->e_parent, crlf);
E 64
I 64
			putheader(fp, m, e->e_parent);
E 64
E 62
E 59
E 58
E 38
		}
E 33
E 29
	}
	else
D 64
		fprintf(fp, "\n  ----- No message was collected -----\n\n");
E 64
I 64
	{
		putline("\n", fp, m);
		putline("  ----- No message was collected -----\n", fp, m);
		putline("\n", fp, m);
	}
E 64
I 23

	/*
	**  Cleanup and exit
	*/

E 23
E 21
E 11
D 16
	close(xfile);
E 16
I 16
D 54
	(void) fclose(xfile);
E 54
E 16
	if (errno != 0)
D 36
		syserr("errhdr: I/O error");
E 36
I 36
		syserr("errbody: I/O error");
E 36
}
E 1
