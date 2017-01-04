h65237
s 00011/00009/00366
d D 5.9 88/06/30 14:58:58 bostic 64 63
c install approved copyright notice
e
s 00016/00010/00359
d D 5.8 88/03/13 19:52:05 bostic 63 62
c add Berkeley specific header
e
s 00005/00000/00364
d D 5.7 85/11/22 11:29:06 miriam 62 61
m 
c Errstring() now will print out a message for the Name Server error 
c code TRY_AGAIN - "Host Name Lookup Failure".
e
s 00003/00003/00361
d D 5.6 85/10/24 10:35:47 eric 61 60
m 
c don't create a queue name in syserr; permit trailing blanks and quoted
c commas in aliases.
e
s 00006/00007/00358
d D 5.5 85/09/30 21:34:09 eric 60 59
m 
c clean up some aspects of error message display
e
s 00000/00000/00365
d D 5.4 85/09/19 01:25:11 eric 59 57
i 58
m 
c incorporate SMI changes -- still experimental
e
s 00048/00003/00317
d D 5.2.1.1 85/09/19 00:55:18 eric 58 56
m 
c SMI changes (somewhat)
e
s 00001/00001/00319
d D 5.3 85/09/17 19:21:38 eric 57 56
m 
c facilities in syslog
e
s 00000/00002/00320
d D 5.2 85/06/07 22:10:35 miriam 56 55
m 
c Resolve duplicate SccsId
e
s 00014/00000/00308
d D 5.1 85/06/07 15:05:31 dist 55 54
m 
c Add copyright
e
s 00001/00001/00307
d D 4.6 85/04/04 17:41:52 miriam 54 53
m 
c Change LOG_ERR to LOG_MAIL
e
s 00003/00003/00305
d D 4.5 84/08/11 18:07:28 eric 53 52
m 
c fix typo
e
s 00013/00009/00295
d D 4.4 84/08/11 17:55:36 eric 52 51
m 
c changes from Tom Ferrin <ucsfcgl!tef>: don't drop messages on the floor
c if no local mailer available; give real "errno" message in syserr.
e
s 00030/00006/00274
d D 4.3 83/10/01 16:56:52 eric 51 50
m 
c clean up error handling in general; make sure that something gets logged
c in the transcript if the connection cannot be established; clean up Teus
c Hagen's mod to arpadate.c to match the sendmail coding style.
e
s 00003/00003/00277
d D 4.2 83/09/05 14:33:32 eric 50 49
m 
c Cut down the amount of bulk that is sent in SMTP error messages, by
c trying to log only real errors in the transcript.  -v mode is unchanged.
e
s 00000/00000/00280
d D 4.1 83/07/25 19:42:54 eric 49 48
m 
c 4.2 release version
e
s 00001/00001/00279
d D 3.40 83/01/05 10:18:42 eric 48 47
m 
c improve error recovery for bizarre SMTP cases; unfortunately CMU has
c decided to start working again, so the strangest parts are untested.
e
s 00001/00001/00279
d D 3.39 83/01/01 16:02:35 eric 47 46
m 
c tag syserr's specially in the log so they can be grep'ed out easily
e
s 00002/00002/00278
d D 3.38 82/12/05 13:45:37 eric 46 45
m 092
c Clear the envelope in the child in server SMTP to insure that our oh so
c helpful parent doesn't delete our transcript; move the transcript and
c temporary file pointers into the envelope; pass the envelope to other
c routines in the holy war against global variables; split off envelope
c routines from main.c to envelope.c
e
s 00024/00012/00256
d D 3.37 82/11/28 16:00:43 eric 45 44
m 
c implement SMTP auto-shutdown on 421 codes; clean up some error processing
c items, particularly in SMTP; don't reinstantiate error message bodies after
c queueing; other minor changes.  This is all cleanup from 3.253.
e
s 00008/00000/00260
d D 3.36 82/11/28 00:20:29 eric 44 43
m 
c Many changes resulting from a complete code readthrough.  Most of these
c fix minor bugs or change the internal structure for clarity, etc.  There
c should be almost no externally visible changes (other than some cleaner
c error message printouts and the like).
e
s 00001/00001/00259
d D 3.35 82/11/24 18:43:48 eric 43 42
m 
c lint it
e
s 00002/00002/00258
d D 3.34 82/11/24 17:14:55 eric 42 41
m 026
c run SMTP jobs in a subprocess so that multiple jobs will work.  This
c delta also changes the envelope data structure so that flags are in
c a bit map, and adjusts some of the semantics.  The transcript is now
c local to an envelope.  A bunch of old code is deleted.  A serious bug
c was fixed in the "run in background" code.  Etc., etc.
e
s 00002/00002/00258
d D 3.33 82/11/17 09:35:38 eric 41 40
m 060
c split operation mode ("-bx" flag) and delivery mode ("d" option)
c so that operation mode can apply to SMTP/daemon connections also.
e
s 00002/00001/00258
d D 3.32 82/11/13 17:54:17 eric 40 39
m 071
c avoid printing out extra messages when the transcript is not instantiated
e
s 00009/00006/00250
d D 3.31 82/11/07 16:14:35 eric 39 38
m 041
c make all mailer output go to the transcript if running server smtp; this
c has the effect of making some significant changes in the output structure
c to handle such things as -em and -as together
e
s 00040/00006/00216
d D 3.30 82/09/21 10:13:30 eric 38 37
c add nmessage (to not add "to..." tag); improve handling of error
c status setting
e
s 00008/00002/00214
d D 3.29 82/08/29 15:52:11 eric 37 36
c give 554 message on syserr (instead of 451) if errno == 0; as it
c was some permanent errors appeared transient
e
s 00002/00001/00214
d D 3.28 82/08/22 19:02:46 eric 36 35
c assign a unique id to each transaction that can be determined from
c the queue file name.
e
s 00006/00000/00209
d D 3.27 82/08/15 17:33:02 eric 35 34
c make VRFY and EXPN work more correctly (VRFY still gives an OK even
c if the target is a list); this adds the QuickAbort option
e
s 00003/00006/00206
d D 3.26 82/08/08 01:02:15 eric 34 33
c change debug level to a debug vector; add levels on logging (and the
c -L flag); change logging to be by message-id; elevate message-id;
c some lint-type cleanup
e
s 00027/00008/00185
d D 3.25 82/07/31 16:57:08 eric 33 32
c arrange to print errno properly in syserr's
e
s 00013/00025/00180
d D 3.24 82/07/25 13:11:14 eric 32 31
c clean up error handling
e
s 00002/00000/00203
d D 3.23 82/06/25 19:38:19 eric 31 30
c add debugging information to server smtp code: _debug to set
c Debug, _verbose to set verbose, and _showq to show the send queue
c (already existant, just a name change)
e
s 00001/00001/00202
d D 3.22 82/06/07 07:54:39 eric 30 29
c make transcripts verbose always; misc. message cleanup, etc.
e
s 00002/00002/00201
d D 3.21 82/05/31 15:36:03 eric 29 28
c don't output SMTP/FTP error codes in transcript file
e
s 00002/00002/00201
d D 3.20 82/05/22 01:37:13 eric 28 27
c add "envelopes" to contain the basic information needed as control
c info for each message.  currently there is only one envelope -- this
c being the obvious stupid conversion.  later there will be separate
c envelopes for error messages, return receipts, etc.
e
s 00002/00000/00201
d D 3.19 82/03/06 12:08:52 eric 27 26
c clean up error handling in IPC case; fix a minor bug in headers in
c queueing code; make SMTP mail multi user per connect.
e
s 00006/00004/00195
d D 3.18 81/12/06 13:30:17 eric 26 25
c increase buffer sizes (it's so embarrasing when the error routines
c core dump) and strip quote bits from messages.
e
s 00001/00001/00198
d D 3.17 81/12/06 12:38:05 eric 25 24
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00002/00001/00197
d D 3.16 81/11/08 17:26:27 eric 24 23
c LINT
e
s 00001/00001/00197
d D 3.15 81/11/07 15:41:14 eric 23 22
c clean up to compile & work on ARPAVAX; move stat file to
c /usr/lib/sendmail.st; fix bug in syserr with error codes
e
s 00083/00041/00115
d D 3.14 81/10/31 22:12:15 eric 22 21
c drop old NCP stuff for ARPANET handling; fix some bugs in error
c messages with multiple recipients in SMTP; clean up error handling
e
s 00003/00005/00153
d D 3.13 81/10/26 14:21:58 eric 21 20
c Install new experimental queueing facility -- one stage timeout,
c etc.  This version is still quite incomplete.  It needs to reorder
c the queue after some interval, do two-stage timeout, take option
c info from the queue file instead of the command line, read the
c sender's .mailcf file, etc.  Some of this is useful for SMTP also.
e
s 00009/00001/00149
d D 3.12 81/10/22 09:14:25 eric 20 19
c implement HELP and MRSQ -- MRSQ is a partial implementation
c of old MTP -- in particular, To: fields in MAIL commands are not yet
c implemented.  The "message" routine now takes first args of the form
c "999-" to specify continuation.
e
s 00009/00009/00141
d D 3.11 81/10/19 22:26:52 eric 19 18
c implement SMTP mode -- doesn't support source routing or the
c HELP command, and doesn't give the correct code on VRFY or forwarding.
c Maybe someday....
e
s 00001/00001/00149
d D 3.10 81/09/06 19:48:17 eric 18 17
c cleanup, commenting, linting, etc.
e
s 00000/00002/00150
d D 3.9 81/08/20 15:13:48 eric 17 16
c clean up some header information; don't reopen tempfile as
c stdin (to fix some problems with saving mail on interrupts)
e
s 00005/00002/00147
d D 3.8 81/08/18 17:12:44 eric 16 15
c factor out ARPANET FTP reply codes into conf.c
e
s 00005/00003/00144
d D 3.7 81/08/18 16:47:04 eric 15 14
c convert to really do arpanet reply codes right (maybe)
e
s 00015/00014/00132
d D 3.6 81/08/09 15:02:27 eric 14 13
c lint it
e
s 00003/00001/00143
d D 3.5 81/08/09 12:25:53 eric 13 12
c use <crlf> in arpanet mode
e
s 00056/00009/00088
d D 3.4 81/08/08 13:51:35 eric 12 11
c give arpanet-style error messages on -a
e
s 00002/00002/00095
d D 3.3 81/03/20 09:44:56 eric 11 10
c change name (again); from postbox to sendmail
e
s 00002/00001/00095
d D 3.2 81/03/07 15:32:23 eric 10 9
c lint fixes
e
s 00002/00002/00094
d D 3.1 81/03/07 14:26:23 eric 9 8
c ----- delivermail ==> postbox -----
e
s 00002/00002/00094
d D 2.3 81/02/28 11:50:33 eric 8 7
c install VAX mpx file logging
e
s 00002/00000/00094
d D 2.2 81/01/10 12:07:27 eric 7 6
c flush output after printing errors   just   in    case
e
s 00000/00000/00094
d D 2.1 80/11/05 11:00:24 eric 6 5
c release 2
e
s 00001/00001/00093
d D 1.5 80/10/21 22:39:39 eric 5 4
c EX_UNAVAIL => EX_UNAVAILABLE
e
s 00006/00006/00088
d D 1.4 80/10/18 16:48:53 eric 4 3
c cleanup for dbm stuff: Error => Errors; move local host
c detection into parse; misc cleanup
e
s 00000/00014/00094
d D 1.3 80/08/02 13:48:59 eric 3 2
c cleaned up comments
e
s 00002/00000/00106
d D 1.2 80/07/25 22:03:38 eric 2 1
c add ID keywords
e
s 00106/00000/00000
d D 1.1 80/06/23 08:24:06 eric 1 0
e
u
U
f b 
f i 
t
T
I 55
/*
I 64
 * Copyright (c) 1983 Eric P. Allman
E 64
D 63
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 63
I 63
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 64
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 64
I 64
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
E 64
 */
E 63

#ifndef lint
D 63
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint
E 63
I 63
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 63

E 55
I 1
D 17
# include <stdio.h>
I 12
# include <ctype.h>
E 17
E 12
D 9
# include "dlvrmail.h"
E 9
I 9
D 11
# include "postbox.h"
E 11
I 11
# include "sendmail.h"
I 58
# include <errno.h>
I 62
# include <netdb.h>
E 62
E 58
E 11
E 9
D 34
# ifdef LOG
D 8
# include <log.h>
E 8
I 8
# include <syslog.h>
E 8
# endif LOG
E 34

I 2
D 25
static char	SccsId[] = "%W%	%G%";
E 25
I 25
D 56
SCCSID(%W%	%Y%	%G%);
E 25

E 56
I 15
D 21
extern bool	HasXscrpt;

E 21
E 15
E 2
/*
D 4
**  ERR -- Print error message.
E 4
I 4
**  SYSERR -- Print error message.
E 4
**
**	Prints an error message via printf to the diagnostic
**	output.  If LOG is defined, it logs it also.
**
**	Parameters:
**		f -- the format string
**		a, b, c, d, e -- parameters
**
**	Returns:
D 14
**		-1 always
E 14
I 14
**		none
I 35
**		Through TopFrame if QuickAbort is set.
E 35
E 14
**
**	Side Effects:
D 4
**		Sets Error.
**		Sets ExitStat.
E 4
I 4
**		increments Errors.
**		sets ExitStat.
E 4
D 3
**
**	Requires:
**		sprintf (sys)
**		printf (sys)
**		logmsg
**
**	History:
**		12/29/79 -- written.
E 3
*/

I 14
# ifdef lint
int	sys_nerr;
char	*sys_errlist[];
# endif lint
I 32
D 48
static char	MsgBuf[BUFSIZ*2];	/* text of most recent message */
E 48
I 48
char	MsgBuf[BUFSIZ*2];	/* text of most recent message */
E 48
E 32

E 14
/*VARARGS1*/
syserr(fmt, a, b, c, d, e)
	char *fmt;
{
I 52
	register char *p;
	int olderrno = errno;
E 52
D 14
	extern int errno;
E 14
D 26
	static char errbuf[MAXLINE+1];
E 26
I 26
D 32
	static char errbuf[2*BUFSIZ];
E 32
E 26
D 14
	register char *p;
E 14
D 22
	extern char *sys_errlist[];
	extern int sys_nerr;
I 10
D 14
	extern char *sprintf();
E 14
I 12
	register char *eb = errbuf;
E 22
I 16
D 37
	extern char Arpa_Syserr[];
E 37
I 37
	extern char Arpa_PSyserr[];
	extern char Arpa_TSyserr[];
D 52
	register char *p;
E 52
E 37
I 32
D 34
	char *saveto = CurEnv->e_to;
E 34
E 32
E 16
E 12
E 10

D 12
	sprintf(errbuf, fmt, a, b, c, d, e);
E 12
I 12
D 22
	/* add arpanet error number if not present */
	if (!isdigit(*fmt))
	{
D 14
		strcpy(eb, "455 ");
E 14
I 14
D 16
		(void) strcpy(eb, "455 ");
E 16
I 16
		(void) strcpy(eb, Arpa_Syserr);
		eb[3] = ' ';
E 16
E 14
		eb += 4;
	}
E 22
I 22
D 32
	/* format the error message */
D 23
	fmtmsg(errbuf, Arpa_Syserr, NULL, fmt, a, b, c, d, e);
E 23
I 23
D 24
	fmtmsg(errbuf, NULL, Arpa_Syserr, fmt, a, b, c, d, e);
E 24
I 24
	fmtmsg(errbuf, (char *) NULL, Arpa_Syserr, fmt, a, b, c, d, e);
E 32
I 32
	/* format and output the error message */
D 33
	CurEnv->e_to = NULL;
	message(Arpa_Syserr, fmt, a, b, c, d, e);
	CurEnv->e_to = saveto;
E 33
I 33
D 34
	fmtmsg(MsgBuf, NULL, Arpa_Syserr, fmt, a, b, c, d, e);
E 34
I 34
D 37
	fmtmsg(MsgBuf, (char *) NULL, Arpa_Syserr, fmt, a, b, c, d, e);
E 37
I 37
D 52
	if (errno == 0)
E 52
I 52
	if (olderrno == 0)
E 52
		p = Arpa_PSyserr;
	else
		p = Arpa_TSyserr;
D 52
	fmtmsg(MsgBuf, (char *) NULL, p, fmt, a, b, c, d, e);
E 52
I 52
	fmtmsg(MsgBuf, (char *) NULL, p, olderrno, fmt, a, b, c, d, e);
E 52
E 37
E 34
D 39
	putmsg(MsgBuf);
E 39
I 39
D 45
	putmsg(MsgBuf, HoldErrs);
E 45
I 45
	puterrmsg(MsgBuf);
E 45
E 39
E 33
E 32
E 24
E 23
E 22

D 22
	/* put error message into buffer */
D 14
	sprintf(eb, fmt, a, b, c, d, e);
E 14
I 14
	(void) sprintf(eb, fmt, a, b, c, d, e);
E 14
E 12
	if (errno != 0)
E 22
I 22
D 32
	/* output error message to transcript */
D 29
	fprintf(Xscript, "%s\n", errbuf);
E 29
I 29
	fprintf(Xscript, "%s\n", &errbuf[4]);
E 29

	/* output error message to output channel if appropriate */
	if (!HoldErrs)
E 22
	{
I 31
		(void) fflush(stdout);
E 31
D 12
		p = &errbuf[strlen(errbuf)];
E 12
I 12
D 22
		eb += strlen(eb);
E 12
		if (errno < sys_nerr && errno > 0)
D 12
			sprintf(p, ": %s", sys_errlist[errno]);
E 12
I 12
D 14
			sprintf(eb, ": %s", sys_errlist[errno]);
E 14
I 14
			(void) sprintf(eb, ": %s", sys_errlist[errno]);
E 22
I 22
		if (ArpaMode)
			fprintf(OutChannel, "%s\r\n", errbuf);
E 22
E 14
E 12
		else
D 12
			sprintf(p, ": error %d", errno);
E 12
I 12
D 14
			sprintf(eb, ": error %d", errno);
E 14
I 14
D 22
			(void) sprintf(eb, ": error %d", errno);
E 22
I 22
			fprintf(OutChannel, "sendmail: %s\n", &errbuf[4]);
		(void) fflush(OutChannel);
E 22
E 14
E 12
	}
D 9
	printf("delivermail: %s\n", errbuf);
E 9
I 9
D 11
	printf("postbox: %s\n", errbuf);
E 11
I 11
D 12
	printf("sendmail: %s\n", errbuf);
E 12
I 12

E 32
I 32
D 38
	/* mark the error as having occured */
E 32
D 15
	if (ArpaFmt)
E 15
I 15
D 21
	if (ArpaMode != ARPA_NONE && !HasXscrpt)
E 21
I 21
D 22
	if (ArpaMode != ARPA_NONE && Transcript == NULL)
E 21
E 15
D 13
		printf("%s\n", errbuf);
E 13
I 13
D 19
		printf("%s\r\n", errbuf);
E 19
I 19
		fprintf(OutChannel, "%s\r\n", errbuf);
E 19
E 13
	else
D 19
		printf("sendmail: %s\n", &errbuf[4]);
E 12
E 11
E 9
I 7
D 14
	fflush(stdout);
E 14
I 14
	(void) fflush(stdout);
E 19
I 19
		fprintf(OutChannel, "sendmail: %s\n", &errbuf[4]);
	(void) fflush(OutChannel);
E 22
E 19
E 14
E 7
D 4
	Error++;
E 4
I 4
	Errors++;
I 27
	FatalErrors = TRUE;
E 27
E 4

E 38
	/* determine exit status if not already set */
	if (ExitStat == EX_OK)
	{
D 52
		if (errno == 0)
E 52
I 52
		if (olderrno == 0)
E 52
			ExitStat = EX_SOFTWARE;
		else
D 5
			ExitStat = EX_UNAVAIL;
E 5
I 5
			ExitStat = EX_OSERR;
E 5
	}

I 44
D 61
	/* insure that we have a queue id for logging */
E 44
I 36
	(void) queuename(CurEnv, '\0');
E 61
E 36
# ifdef LOG
D 8
	logmsg(LOG_ERR, "%s->%s: %s", From.q_paddr, To, errbuf);
E 8
I 8
D 18
	syslog(LOG_ERR, "%s->%s: %s", From.q_paddr, To, errbuf);
E 18
I 18
D 28
	syslog(LOG_ERR, "%s->%s: %s", From.q_paddr, To, &errbuf[4]);
E 28
I 28
D 32
	syslog(LOG_ERR, "%s->%s: %s", CurEnv->e_from.q_paddr, CurEnv->e_to, &errbuf[4]);
E 32
I 32
D 34
	syslog(LOG_ERR, "%s->%s: %s", CurEnv->e_from.q_paddr, CurEnv->e_to, &MsgBuf[4]);
E 34
I 34
	if (LogLevel > 0)
D 36
		syslog(LOG_ERR, "%s: %s", MsgId, &MsgBuf[4]);
E 36
I 36
D 47
		syslog(LOG_ERR, "%s: %s", CurEnv->e_id, &MsgBuf[4]);
E 47
I 47
D 54
		syslog(LOG_ERR, "%s: SYSERR: %s", CurEnv->e_id, &MsgBuf[4]);
E 54
I 54
D 57
		syslog(LOG_MAIL, "%s: SYSERR: %s", CurEnv->e_id, &MsgBuf[4]);
E 57
I 57
D 61
		syslog(LOG_CRIT, "%s: SYSERR: %s", CurEnv->e_id, &MsgBuf[4]);
E 61
I 61
		syslog(LOG_CRIT, "%s: SYSERR: %s",
			CurEnv->e_id == NULL ? "NOQUEUE" : CurEnv->e_id,
			&MsgBuf[4]);
E 61
E 57
E 54
E 47
E 36
E 34
E 32
E 28
E 18
E 8
# endif LOG
	errno = 0;
I 35
	if (QuickAbort)
		longjmp(TopFrame, 2);
E 35
D 14
	return (-1);
E 14
}
/*
**  USRERR -- Signal user error.
**
**	This is much like syserr except it is for user errors.
**
**	Parameters:
**		fmt, a, b, c, d -- printf strings
**
**	Returns:
D 14
**		-1
E 14
I 14
**		none
I 35
**		Through TopFrame if QuickAbort is set.
E 35
E 14
**
**	Side Effects:
D 4
**		sets Error.
E 4
I 4
**		increments Errors.
E 4
D 3
**
**	Requires:
**		printf (sys)
**
**	History:
**		1/1/80 -- written.
E 3
*/

/*VARARGS1*/
usrerr(fmt, a, b, c, d, e)
	char *fmt;
{
	extern char SuprErrs;
I 16
	extern char Arpa_Usrerr[];
I 52
	extern int errno;
E 52
E 16

	if (SuprErrs)
D 10
		return;
E 10
I 10
D 14
		return (0);
E 14
I 14
		return;
E 14
E 10
D 12

E 12
D 4
	Error++;
E 4
I 4
D 38
	Errors++;
I 27
	FatalErrors = TRUE;
E 38
E 27
E 4
D 12
	if (To != NULL)
E 12
I 12

D 16
	message("450", fmt, a, b, c, d, e);
E 16
I 16
D 33
	message(Arpa_Usrerr, fmt, a, b, c, d, e);
E 33
I 33
D 52
	fmtmsg(MsgBuf, CurEnv->e_to, Arpa_Usrerr, fmt, a, b, c, d, e);
E 52
I 52
	fmtmsg(MsgBuf, CurEnv->e_to, Arpa_Usrerr, errno, fmt, a, b, c, d, e);
E 52
D 39
	putmsg(MsgBuf);
E 39
I 39
D 45
	putmsg(MsgBuf, HoldErrs);
E 45
I 45
	puterrmsg(MsgBuf);
E 45
E 39
I 38

E 38
I 35
	if (QuickAbort)
		longjmp(TopFrame, 1);
E 35
E 33
E 16
D 14
	return (-1);
E 14
}
/*
**  MESSAGE -- print message (not necessarily an error)
**
**	Parameters:
**		num -- the default ARPANET error number (in ascii)
**		msg -- the message (printf fmt) -- if it begins
**			with a digit, this number overrides num.
**		a, b, c, d, e -- printf arguments
**
**	Returns:
**		none
**
**	Side Effects:
**		none.
*/

I 14
/*VARARGS2*/
E 14
message(num, msg, a, b, c, d, e)
	register char *num;
	register char *msg;
{
D 22
	/* compute error number */
	if (isdigit(*msg))
E 22
I 22
D 26
	char errbuf[MAXLINE];
E 26
I 26
D 32
	char errbuf[2*BUFSIZ];
E 26

E 32
	errno = 0;
D 28
	fmtmsg(errbuf, To, num, msg, a, b, c, d, e);
E 28
I 28
D 32
	fmtmsg(errbuf, CurEnv->e_to, num, msg, a, b, c, d, e);
E 32
I 32
D 52
	fmtmsg(MsgBuf, CurEnv->e_to, num, msg, a, b, c, d, e);
E 52
I 52
	fmtmsg(MsgBuf, CurEnv->e_to, num, 0, msg, a, b, c, d, e);
E 52
I 33
D 39
	putmsg(MsgBuf);
E 39
I 39
	putmsg(MsgBuf, FALSE);
E 39
}
/*
I 38
**  NMESSAGE -- print message (not necessarily an error)
**
**	Just like "message" except it never puts the to... tag on.
**
**	Parameters:
**		num -- the default ARPANET error number (in ascii)
**		msg -- the message (printf fmt) -- if it begins
D 58
**			with a digit, this number overrides num.
E 58
I 58
**			with three digits, this number overrides num.
E 58
**		a, b, c, d, e -- printf arguments
**
**	Returns:
**		none
**
**	Side Effects:
**		none.
*/

/*VARARGS2*/
nmessage(num, msg, a, b, c, d, e)
	register char *num;
	register char *msg;
{
	errno = 0;
D 43
	fmtmsg(MsgBuf, NULL, num, msg, a, b, c, d, e);
E 43
I 43
D 52
	fmtmsg(MsgBuf, (char *) NULL, num, msg, a, b, c, d, e);
E 52
I 52
	fmtmsg(MsgBuf, (char *) NULL, num, 0, msg, a, b, c, d, e);
E 52
E 43
D 39
	putmsg(MsgBuf);
E 39
I 39
	putmsg(MsgBuf, FALSE);
E 39
}
/*
E 38
**  PUTMSG -- output error message to transcript and channel
**
**	Parameters:
**		msg -- message to output (in SMTP format).
I 39
**		holdmsg -- if TRUE, don't output a copy of the message to
**			our output channel.
E 39
**
**	Returns:
**		none.
**
**	Side Effects:
**		Outputs msg to the transcript.
**		If appropriate, outputs it to the channel.
**		Deletes SMTP reply code number as appropriate.
*/
E 33
E 32
E 28

I 33
D 39
putmsg(msg)
E 39
I 39
putmsg(msg, holdmsg)
E 39
	char *msg;
I 39
	bool holdmsg;
E 39
{
E 33
D 50
	/* output to transcript */
D 29
	fprintf(Xscript, "%s\n", errbuf);
E 29
I 29
D 32
	fprintf(Xscript, "%s\n", &errbuf[4]);
E 32
I 32
D 33
	fprintf(Xscript, "%s\n", Smtp ? MsgBuf : &MsgBuf[4]);
E 33
I 33
D 40
	fprintf(Xscript, "%s\n", Smtp ? msg : &msg[4]);
E 40
I 40
D 42
	if (Xscript != OutChannel)
E 42
I 42
D 46
	if (Xscript != NULL)
E 42
D 41
		fprintf(Xscript, "%s\n", Smtp ? msg : &msg[4]);
E 41
I 41
		fprintf(Xscript, "%s\n", OpMode == MD_SMTP ? msg : &msg[4]);
E 46
I 46
	if (CurEnv->e_xfp != NULL)
		fprintf(CurEnv->e_xfp, "%s\n", OpMode == MD_SMTP ? msg : &msg[4]);
E 50
I 50
	/* output to transcript if serious */
	if (CurEnv->e_xfp != NULL && (msg[0] == '4' || msg[0] == '5'))
		fprintf(CurEnv->e_xfp, "%s\n", msg);
E 50
E 46
E 41
E 40
E 33
E 32
E 29

	/* output to channel if appropriate */
D 30
	if (!HoldErrs)
E 30
I 30
D 32
	if (!HoldErrs && (Verbose || errbuf[0] != '0'))
E 32
I 32
D 33
	if (!HoldErrs && (Verbose || MsgBuf[0] != '0'))
E 33
I 33
D 39
	if (!HoldErrs && (Verbose || msg[0] != '0'))
E 39
I 39
	if (!holdmsg && (Verbose || msg[0] != '0'))
E 39
E 33
E 32
E 30
E 22
	{
I 31
		(void) fflush(stdout);
E 31
D 22
		num = msg;
		msg += 4;
E 22
I 22
D 41
		if (ArpaMode)
E 41
I 41
		if (OpMode == MD_SMTP || OpMode == MD_ARPAFTP)
E 41
D 32
			fprintf(OutChannel, "%s\r\n", errbuf);
E 32
I 32
D 33
			fprintf(OutChannel, "%s\r\n", MsgBuf);
E 33
I 33
			fprintf(OutChannel, "%s\r\n", msg);
E 33
E 32
		else
D 32
			fprintf(OutChannel, "%s\n", &errbuf[4]);
E 32
I 32
D 33
			fprintf(OutChannel, "%s\n", &MsgBuf[4]);
E 33
I 33
			fprintf(OutChannel, "%s\n", &msg[4]);
E 33
E 32
		(void) fflush(OutChannel);
I 38
	}
I 45
}
/*
**  PUTERRMSG -- like putmsg, but does special processing for error messages
**
**	Parameters:
**		msg -- the message to output.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Sets the fatal error bit in the envelope as appropriate.
*/
E 45

D 45
	/* determine error status */
	switch (msg[0])
	{
	  case '5':
D 42
		FatalErrors = TRUE;
E 42
I 42
		CurEnv->e_flags |= EF_FATALERRS;
E 42
		/* fall through.... */
E 45
I 45
puterrmsg(msg)
	char *msg;
{
	/* output the message as usual */
	putmsg(msg, HoldErrs);
E 45

D 45
	  case '4':
		Errors++;
		break;
E 38
E 22
	}
E 45
I 45
	/* signal the error */
	Errors++;
	if (msg[0] == '5')
		CurEnv->e_flags |= EF_FATALERRS;
E 45
I 22
}
/*
**  FMTMSG -- format a message into buffer.
**
**	Parameters:
**		eb -- error buffer to get result.
**		to -- the recipient tag for this message.
**		num -- arpanet error number.
I 52
**		en -- the error number to display.
E 52
**		fmt -- format of string.
**		a, b, c, d, e -- arguments.
**
**	Returns:
**		none.
**
**	Side Effects:
**		none.
*/
E 22

I 24
D 52
/*VARARGS4*/
E 52
I 52
/*VARARGS5*/
E 52
E 24
D 22
	/* print arpa format header if needed */
D 15
	if (ArpaFmt)
E 15
I 15
D 21
	if (ArpaMode != ARPA_NONE && !HasXscrpt)
E 21
I 21
	if (ArpaMode != ARPA_NONE && Transcript == NULL)
E 22
I 22
static
D 52
fmtmsg(eb, to, num, fmt, a, b, c, d, e)
E 52
I 52
fmtmsg(eb, to, num, eno, fmt, a, b, c, d, e)
E 52
	register char *eb;
	char *to;
	char *num;
I 52
D 53
	int en;
E 53
I 53
	int eno;
E 53
E 52
	char *fmt;
{
	char del;

	/* output the reply code */
D 58
	if (isdigit(*fmt))
E 58
I 58
	if (isdigit(fmt[0]) && isdigit(fmt[1]) && isdigit(fmt[2]))
E 58
E 22
E 21
E 15
D 19
		printf("%.3s ", num);
E 19
I 19
D 20
		fprintf(OutChannel, "%.3s ", num);
E 20
I 20
	{
D 22
		register char del;
E 22
I 22
		num = fmt;
		fmt += 4;
	}
	if (num[3] == '-')
		del = '-';
	else
		del = ' ';
	(void) sprintf(eb, "%3.3s%c", num, del);
	eb += 4;
I 44

	/* output the file name and line number */
	if (FileName != NULL)
	{
		(void) sprintf(eb, "%s: line %d: ", FileName, LineNumber);
		eb += strlen(eb);
	}
E 44
E 22

D 22
		if (num[3] == '-')
			del = '-';
		else
			del = ' ';
		fprintf(OutChannel, "%3.3s%c", num, del);
E 22
I 22
	/* output the "to" person */
	if (to != NULL && to[0] != '\0')
	{
		(void) sprintf(eb, "%s... ", to);
D 26
		eb += strlen(eb);
E 26
I 26
		while (*eb != '\0')
			*eb++ &= 0177;
E 26
E 22
	}
E 20
E 19

D 22
	if (To != NULL && To[0] != '\0')
E 12
D 19
		printf("%s... ", To);
D 12
	printf(fmt, a, b, c, d, e);
E 12
I 12
	printf(msg, a, b, c, d, e);
E 19
I 19
		fprintf(OutChannel, "%s... ", To);
	fprintf(OutChannel, msg, a, b, c, d, e);
E 19
I 13
D 15
	if (ArpaFmt)
E 15
I 15
D 21
	if (ArpaMode != ARPA_NONE && !HasXscrpt)
E 21
I 21
	if (ArpaMode != ARPA_NONE && Transcript == NULL)
E 21
E 15
D 19
		printf("\r");
E 13
E 12
	printf("\n");
I 7
D 14
	fflush(stdout);
E 14
I 14
	(void) fflush(stdout);
E 19
I 19
		fprintf(OutChannel, "\r");
	fprintf(OutChannel, "\n");
	(void) fflush(OutChannel);
E 22
I 22
	/* output the message */
	(void) sprintf(eb, fmt, a, b, c, d, e);
D 26
	eb += strlen(eb);
E 26
I 26
	while (*eb != '\0')
		*eb++ &= 0177;
E 26

	/* output the error code, if any */
D 53
	if (errno != 0)
E 53
I 53
	if (eno != 0)
E 53
	{
D 51
		extern int sys_nerr;
		extern char *sys_errlist[];
		if (errno < sys_nerr && errno > 0)
			(void) sprintf(eb, ": %s", sys_errlist[errno]);
		else
			(void) sprintf(eb, ": error %d", errno);
E 51
I 51
		extern char *errstring();

D 53
		(void) sprintf(eb, ": %s", errstring(errno));
E 53
I 53
		(void) sprintf(eb, ": %s", errstring(eno));
E 53
E 51
		eb += strlen(eb);
	}
I 51
}
/*
**  ERRSTRING -- return string description of error code
**
**	Parameters:
**		errno -- the error number to translate
**
**	Returns:
**		A string description of errno.
**
**	Side Effects:
**		none.
*/

char *
errstring(errno)
	int errno;
{
	extern char *sys_errlist[];
	extern int sys_nerr;
D 58
	static char buf[50];
E 58
I 58
	static char buf[100];
# ifdef SMTP
	extern char *SmtpPhase;
D 60
	extern char *RealHostName;
E 60
# endif SMTP

# ifdef DAEMON
# ifdef VMUNIX
	/*
	**  Handle special network error codes.
	**
	**	These are 4.2/4.3bsd specific; they should be in daemon.c.
	*/

	switch (errno)
	{
	  case ETIMEDOUT:
	  case ECONNRESET:
		(void) strcpy(buf, sys_errlist[errno]);
		if (SmtpPhase != NULL)
		{
			(void) strcat(buf, " during ");
			(void) strcat(buf, SmtpPhase);
		}
D 60
		if (RealHostName != NULL)
E 60
I 60
		if (CurHostName != NULL)
E 60
		{
			(void) strcat(buf, " with ");
D 60
			(void) strcat(buf, RealHostName);
E 60
I 60
			(void) strcat(buf, CurHostName);
E 60
		}
		return (buf);

	  case EHOSTDOWN:
D 60
		if (RealHostName == NULL)
E 60
I 60
		if (CurHostName == NULL)
E 60
			break;
D 60
		(void) sprintf(buf, "Host %s is down", RealHostName);
E 60
I 60
		(void) sprintf(buf, "Host %s is down", CurHostName);
E 60
		return (buf);

	  case ECONNREFUSED:
D 60
		if (RealHostName == NULL)
E 60
I 60
		if (CurHostName == NULL)
E 60
			break;
D 60
		(void) sprintf(buf, "Connection refused by %s", RealHostName);
E 60
I 60
		(void) sprintf(buf, "Connection refused by %s", CurHostName);
I 62
		return (buf);

	  case (TRY_AGAIN+MAX_ERRNO):
		(void) sprintf(buf, "Host Name Lookup Failure");
E 62
E 60
		return (buf);
	}
# endif VMUNIX
# endif DAEMON
E 58

	if (errno > 0 && errno < sys_nerr)
		return (sys_errlist[errno]);

	(void) sprintf(buf, "Error %d", errno);
	return (buf);
E 51
E 22
E 19
E 14
E 7
D 12
	return (-1);
E 12
}
E 1
