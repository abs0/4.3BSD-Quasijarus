h44196
s 00014/00006/00349
d D 5.6 07/09/19 19:59:18 msokolov 85 84
c change to oversize handling strategy:
c trim at limit and silently discard the rest instead of error in mid-message
e
s 00016/00000/00339
d D 5.5 04/11/21 08:41:34 msokolov 84 83
c implement ability to globally limit message size in collect phase (l option)
e
s 00011/00009/00328
d D 5.4 88/06/30 14:58:23 bostic 83 82
c install approved copyright notice
e
s 00016/00010/00321
d D 5.3 88/03/13 19:51:34 bostic 82 81
c add Berkeley specific header
e
s 00001/00001/00330
d D 5.2 85/06/08 00:26:29 eric 81 80
m 
c lint
e
s 00014/00002/00317
d D 5.1 85/06/07 14:30:12 dist 80 79
m 
c Add copyright
e
s 00006/00002/00313
d D 4.5 85/04/28 10:42:13 eric 79 78
m 
c add iferror to loop termination conditions to avoid loops from
c peer resets
e
s 00002/00002/00313
d D 4.4 84/08/11 17:48:50 eric 78 77
m 
c Assorted changes from Guy Harris <rlgvax!guy>: mostly lint & USG
e
s 00010/00001/00305
d D 4.3 84/03/11 13:20:55 eric 77 76
m 
c fix from Bill Nowicki -- don't return an error if the connection times
c out, since we haven't accepted responsibility yet.
e
s 00007/00013/00299
d D 4.2 83/11/13 18:07:52 eric 76 75
m 
c Fixes two nasty problems, both pointed out by Bill Nowicki at Stanford:
c I/O errors on input in collect would cause infinite loops, and a protocol
c error (or other error that would call smtpquit abnormally) would cause
c core dumps
e
s 00000/00000/00312
d D 4.1 83/07/25 19:45:05 eric 75 74
m 
c 4.2 release version
e
s 00009/00010/00303
d D 3.61 83/07/13 10:37:51 eric 74 73
m 
c Delete "load limiting" for SMTP connections (a bad ethernet board can
c hang up all incoming mail); use sfgets in collect (same reason); check
c for I/O error in collect (from Bill Nowicki); switch date format to
c RFC822 style.
e
s 00000/00009/00313
d D 3.60 83/04/17 17:13:40 eric 73 72
m 218
c remove >From hack
e
s 00030/00011/00292
d D 3.59 83/03/12 17:41:40 eric 72 71
m 208
c Check for I/O error on close of temp file -- i.e., last buffer flush
e
s 00000/00012/00303
d D 3.58 83/02/26 11:51:03 eric 71 70
m 193
c log queueid <=> message-id correspondence
e
s 00004/00000/00311
d D 3.57 83/02/18 12:41:52 eric 70 69
m 185
c Give an error if the message is terminated with an EOF and we are
c running SMTP (it must be terminated with a dot).
e
s 00001/00001/00310
d D 3.56 82/12/05 13:45:26 eric 69 68
m 092
c Clear the envelope in the child in server SMTP to insure that our oh so
c helpful parent doesn't delete our transcript; move the transcript and
c temporary file pointers into the envelope; pass the envelope to other
c routines in the holy war against global variables; split off envelope
c routines from main.c to envelope.c
e
s 00011/00023/00300
d D 3.55 82/11/28 00:20:13 eric 68 67
m 
c Many changes resulting from a complete code readthrough.  Most of these
c fix minor bugs or change the internal structure for clarity, etc.  There
c should be almost no externally visible changes (other than some cleaner
c error message printouts and the like).
e
s 00001/00001/00322
d D 3.54 82/11/17 09:35:20 eric 67 66
m 060
c split operation mode ("-bx" flag) and delivery mode ("d" option)
c so that operation mode can apply to SMTP/daemon connections also.
e
s 00001/00001/00322
d D 3.53 82/11/03 10:29:11 eric 66 65
m 058
c Put temporary file mode on the F option
e
s 00000/00001/00323
d D 3.52 82/09/12 16:43:10 eric 65 64
c change inheritance for macros in envelopes; be able to canonicalize
c non-domained names by appending domain from sender; call ruleset 3
c explicitly before doing other rulesets; some general cleanup.
e
s 00012/00012/00312
d D 3.51 82/08/23 09:23:38 eric 64 63
c allow continuation lines in .cf file (particularly in headers)
e
s 00000/00014/00324
d D 3.50 82/08/22 23:06:54 eric 63 62
c change $i to $j; $i is now queue id; put "Received:" format in .cf
c file; minor cleanup
e
s 00006/00011/00332
d D 3.49 82/08/22 19:02:36 eric 62 61
c assign a unique id to each transaction that can be determined from
c the queue file name.
e
s 00003/00003/00340
d D 3.48 82/08/17 20:44:47 eric 61 60
c Mail-From: ==> Received: for new SMTP spec (RFC821)
e
s 00005/00211/00338
d D 3.47 82/08/17 16:17:17 eric 60 59
c rework header processing: do special purpose header munging in a
c separate routine so that the queue run can do it also.  Also, parse
c From: lines in a fancy way, extracting the address part and turning
c it into a $g macro.
e
s 00001/00001/00548
d D 3.46 82/08/15 11:56:21 eric 59 58
c output message class rather than priority in log
e
s 00008/00000/00541
d D 3.45 82/08/08 16:55:17 eric 58 57
c truncate excessively long header lines
e
s 00034/00005/00507
d D 3.44 82/08/08 01:02:00 eric 57 56
c change debug level to a debug vector; add levels on logging (and the
c -L flag); change logging to be by message-id; elevate message-id;
c some lint-type cleanup
e
s 00002/00000/00510
d D 3.43 82/07/14 09:22:30 eric 56 55
c fix bug in Apparently-To:, outputing too many lines
e
s 00017/00000/00493
d D 3.42 82/07/05 18:49:39 eric 55 54
c add "Apparently-To:" field if no recipients are in the header.
e
s 00004/00000/00489
d D 3.41 82/07/05 13:19:45 eric 54 53
c count Mail-From: lines to avoid loops (simulates hop counts)
e
s 00003/00003/00486
d D 3.40 82/05/31 18:48:55 eric 53 52
c pass lint.  notice that definitions in llib-lc have changed for
c alarm() and sleep() calls {arg was unsigned, is now int}.
e
s 00005/00005/00484
d D 3.39 82/05/31 15:31:25 eric 52 50
i 51
c finish implementing envelopes.  it's not completely clear to me that
c this is really the way to go, but it seems clearly better than what
c i had before.  this delta includes many other minor changes, so it
c should probably not be blithely removed.
e
s 00002/00002/00487
d D 3.38.1.1 82/05/29 18:19:33 eric 51 50
c try to install envelopes.  is this really worth it???
e
s 00005/00001/00484
d D 3.38 82/05/22 02:05:07 eric 50 49
c add "junk mail" -- error responses are never returned.
e
s 00009/00011/00476
d D 3.37 82/05/22 01:36:57 eric 49 48
c add "envelopes" to contain the basic information needed as control
c info for each message.  currently there is only one envelope -- this
c being the obvious stupid conversion.  later there will be separate
c envelopes for error messages, return receipts, etc.
e
s 00002/00002/00485
d D 3.36 82/05/20 17:45:29 eric 48 47
c add dfopen as a "determined fopen" -- it retries if it gets recoverable
c errors.  we use it for returning mail (to dead.letter) and creating the
c temp file.  the whole idea is to avoid dropping things on the floor on
c heavily loaded systems.  this is untested, since it seems impossible to
c fill up the inode or file tables on this VAX (but it works if the open
c succeeds).
e
s 00079/00000/00408
d D 3.35 82/02/27 11:37:10 eric 47 46
c implement "return receipt requested".
e
s 00010/00010/00398
d D 3.34 82/02/26 21:55:49 eric 46 45
c implement daemon mode
e
s 00004/00035/00404
d D 3.33 82/02/20 19:15:51 eric 45 44
c make rewriting of addresses in headers really work.  This adds the $q
c macro.  The rewriting of the From: address is still ad hoc and should
c be integrated into this format.
c Note:  old .cf files will not work with this version.
e
s 00006/00003/00433
d D 3.32 82/01/10 21:57:22 eric 44 43
c cleanup from cbosgd (Mark Horton) testing; some internals, mostly
c configuration.  This tries to make the configuration file (cf.m4) be
c much more general, but I fear it is doomed to failure -- it may be
c better to just tell people to roll their own.
e
s 00004/00003/00432
d D 3.31 81/12/06 12:37:54 eric 43 42
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00015/00001/00420
d D 3.30 81/12/05 14:13:51 eric 42 41
c insert SMTP "Mail-From:" line.
e
s 00008/00004/00413
d D 3.29 81/11/22 19:16:58 eric 41 40
c Edit queue control files when running queue (assuming there are still
c recipients left).  Also, modify the MsgPriority to be the absolute
c number (not the Priority: value); this allows us to include aging into
c the priority algorithm.
e
s 00007/00009/00410
d D 3.28 81/10/31 22:12:03 eric 40 39
c drop old NCP stuff for ARPANET handling; fix some bugs in error
c messages with multiple recipients in SMTP; clean up error handling
e
s 00005/00004/00414
d D 3.27 81/10/27 10:50:26 eric 39 38
c More queueing cleanup: implement timeouts (still one-stage),
c properly implement priorities (didn't work before), and miscellaneous
c cleanup.
e
s 00057/00006/00361
d D 3.26 81/10/26 14:21:47 eric 38 37
c Install new experimental queueing facility -- one stage timeout,
c etc.  This version is still quite incomplete.  It needs to reorder
c the queue after some interval, do two-stage timeout, take option
c info from the queue file instead of the command line, read the
c sender's .mailcf file, etc.  Some of this is useful for SMTP also.
e
s 00011/00001/00356
d D 3.25 81/10/20 11:36:10 eric 37 36
c clean up the SMTP stuff some more
e
s 00009/00004/00348
d D 3.24 81/10/19 22:26:41 eric 36 35
c implement SMTP mode -- doesn't support source routing or the
c HELP command, and doesn't give the correct code on VRFY or forwarding.
c Maybe someday....
e
s 00002/00002/00350
d D 3.23 81/10/02 10:07:29 eric 35 34
c use ruleset 2 to rewrite names after the $g translate (to fix some
c forwarding problems; do a read check in putmessage (just in case
c the temp file disappeared); some general cleanup.
e
s 00003/00001/00349
d D 3.22 81/09/12 15:48:40 eric 34 33
c change From: processing to reduce the number of Original-From:
c lines; change allocation of global variables.
e
s 00012/00001/00338
d D 3.21 81/09/07 12:33:23 eric 33 32
c add auto-rebuild on alias database; fix some aliasing bugs;
c add statistics to rebuild; slight code restructuring; change
c version handling one last (?) time
e
s 00008/00000/00331
d D 3.20 81/09/07 10:22:55 eric 32 31
c add NOTUNIX compile flag to turn off UNIX "From " line processing
e
s 00011/00008/00320
d D 3.19 81/09/06 19:48:09 eric 31 30
c cleanup, commenting, linting, etc.
e
s 00051/00001/00277
d D 3.18 81/08/22 17:51:59 eric 30 29
c Arrange to pull full name out of From line if found; includes
c Original-From: hacking (oh so ugly).  There's got to be a better way
c to do this...
e
s 00016/00001/00262
d D 3.17 81/08/22 14:31:52 eric 29 28
c fix improper UNIX From line crunching
e
s 00002/00003/00261
d D 3.16 81/08/20 15:13:38 eric 28 27
c clean up some header information; don't reopen tempfile as
c stdin (to fix some problems with saving mail on interrupts)
e
s 00007/00012/00257
d D 3.15 81/08/18 16:46:56 eric 27 26
c convert to really do arpanet reply codes right (maybe)
e
s 00012/00001/00257
d D 3.14 81/08/18 10:00:19 eric 26 25
c insert missing newlines (since a blank line must preceed a message)
e
s 00003/00001/00255
d D 3.13 81/08/17 09:37:35 eric 25 24
c add header fields from new BB&N proposal ICST/CBOS - 80-2,
c "Specification of a Draft Message Format Standard" for NBS.
e
s 00000/00144/00256
d D 3.12 81/08/09 16:39:40 eric 24 23
c arrange for newaliases to work
e
s 00013/00019/00387
d D 3.11 81/08/09 15:02:17 eric 23 22
c lint it
e
s 00008/00006/00398
d D 3.10 81/03/28 14:18:15 eric 22 21
c don't throw away some headers
e
s 00005/00000/00399
d D 3.9 81/03/28 13:36:43 eric 21 20
c pass Full-Name field internally to do forwards correctly
e
s 00106/00104/00293
d D 3.8 81/03/28 12:02:33 eric 20 19
c put much more info in cf file (e.g., headers)
e
s 00001/00001/00396
d D 3.7 81/03/20 09:44:25 eric 19 18
c change name (again); from postbox to sendmail
e
s 00003/00024/00394
d D 3.6 81/03/11 10:45:36 eric 18 17
c general cleanup, esp. macro processor
e
s 00017/00003/00401
d D 3.5 81/03/09 13:21:39 eric 17 16
c first step at rewriting rules, etc.
e
s 00022/00042/00382
d D 3.4 81/03/07 17:45:34 eric 16 15
c drop stupid concatenation stuff; add hi_pptr
e
s 00004/00001/00420
d D 3.3 81/03/07 15:32:06 eric 15 14
c lint fixes
e
s 00005/00023/00416
d D 3.2 81/03/07 14:26:08 eric 14 13
c ----- delivermail ==> postbox -----
e
s 00301/00084/00138
d D 3.1 81/03/04 09:34:30 eric 13 12
c install fancy header stuff
e
s 00001/00001/00221
d D 2.3 80/12/06 17:31:22 eric 12 10
c fix botch with ^D from terminal
e
s 00024/00003/00219
d D 2.2.1.1 80/11/21 12:34:39 eric 11 10
c abortive attempt to make headers to (e.g.) msgs work
e
s 00009/00006/00213
d D 2.2 80/11/20 19:58:00 eric 10 8
c make dates be taken as date sent rather than date delivered
e
s 00048/00002/00217
d D 2.1.1.1 80/11/20 09:54:10 eric 9 8
c experimental save date technique
e
s 00000/00000/00219
d D 2.1 80/11/05 11:00:52 eric 8 7
c release 2
e
s 00004/00001/00215
d D 1.6 80/10/27 19:27:15 eric 7 6
c count & record message size
e
s 00002/00001/00214
d D 1.5 80/10/21 12:57:24 eric 6 5
c avoid bug in ungetc
e
s 00011/00003/00204
d D 1.4 80/10/15 10:19:45 eric 5 3
c try to handle out of disk space problem effectively
e
s 00010/00003/00204
d R 1.4 80/10/15 10:14:33 eric 4 3
c Try to clean up disk space problems
e
s 00002/00000/00205
d D 1.3 80/10/11 20:05:11 eric 3 2
c fix MsgId so that sizeof returns > 0
e
s 00205/00000/00000
d D 1.2 80/10/11 18:12:35 eric 2 1
c cleanup to simplify configuration & fix minor bugs
e
s 00000/00000/00000
d D 1.1 80/10/11 18:10:12 eric 1 0
e
u
U
f b 
t
T
I 80
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

E 80
I 2
D 28
# include <stdio.h>
# include <ctype.h>
E 28
I 5
# include <errno.h>
E 5
D 14
# include "dlvrmail.h"
E 14
I 14
D 19
# include "postbox.h"
E 19
I 19
# include "sendmail.h"
E 19
E 14
D 80

D 43
static char	SccsId[] = "%W%	%G%";
E 43
I 43
SCCSID(%W%	%Y%	%G%);
E 80
E 43

/*
D 14
**  MAKETEMP -- read & parse message header & make temp file.
E 14
I 14
**  COLLECT -- read & parse message header & make temp file.
E 14
**
**	Creates a temporary file name and copies the standard
D 68
**	input to that file.  While it is doing it, it looks for
**	"From:" and "Sender:" fields to use as the from-person
**	(but only if the -a flag is specified).  It prefers to
**	to use the "Sender:" field.
E 68
I 68
**	input to that file.  Leading UNIX-style "From" lines are
**	stripped off (after important information is extracted).
E 68
**
D 68
**	MIT seems to like to produce "Sent-By:" fields instead
**	of "Sender:" fields.  We used to catch this, but it turns
**	out that the "Sent-By:" field doesn't always correspond
**	to someone real ("___057", for instance), as required by
**	the protocol.  So we limp by.....
**
E 68
**	Parameters:
D 11
D 40
**		none
E 40
I 40
**		sayok -- if set, give an ARPANET style message
**			to say we are ready to collect input.
E 40
E 11
I 11
**		from -- the person we think it may be from.  If
**			there is a "From" line, we will replace
**			the name of the person by this.  If NULL,
**			do no such replacement.
E 11
**
**	Returns:
D 11
D 27
**		Name of temp file.
E 27
I 27
**		none.
E 27
E 11
I 11
**		Name of the "from" person extracted from the
**		arpanet header.
E 11
**
**	Side Effects:
**		Temp file is created and filled.
D 27
**
**	Called By:
**		main
**
**	Notes:
**		This is broken off from main largely so that the
**		temp buffer can be deallocated.
E 27
I 27
**		The from person may be set.
E 27
*/

I 3
D 7
char	MsgId[MAXNAME];
E 7
I 7
D 13
char	MsgId[MAXNAME];		/* message-id, determined or created */
E 13
I 13
D 20
char	*MsgId;			/* message-id, determined or created */
E 20
E 13
D 49
long	MsgSize;		/* size of message in bytes */
I 28
D 38
FILE	*TempFile;		/* the tempfile (after creation) */
E 38
E 28
I 10
D 13
bool	GotHdr;			/* if set, "From ..." line exists */
E 13
I 13
D 20
char	*Date;			/* UNIX-style origination date */
E 20
E 13
E 10
E 7

E 49
E 3
D 27
char *
E 27
D 11
D 14
maketemp()
E 14
I 14
D 40
collect()
E 40
I 40
collect(sayok)
	bool sayok;
E 40
E 14
E 11
I 11
maketemp(from)
	char *from;
E 11
{
	register FILE *tf;
D 64
	char buf[MAXFIELD+1];
E 64
I 64
	char buf[MAXFIELD+2];
E 64
D 13
	static char fbuf[sizeof buf];
	extern char *prescan();
	extern char *matchhdr();
E 13
	register char *p;
D 13
	register bool inheader;
	bool firstline;
E 13
D 31
	char c;
I 5
D 23
	extern int errno;
E 23
I 13
D 20
	register HDR *h;
	HDR **hp;
E 20
	extern bool isheader();
E 31
D 23
	extern char *newstr();
	extern char *xalloc();
D 20
	char *fname;
	char *fvalue;
E 20
	extern char *index(), *rindex();
E 23
D 60
	char *xfrom;
E 60
	extern char *hvalue();
I 85
	bool oversize = FALSE;
E 85
D 16
	extern char *makemsgid();
E 16
D 20
	struct hdrinfo *hi;
E 20
I 15
D 23
	extern char *strcpy(), *strcat(), *mktemp();
E 23
I 23
D 62
	extern char *mktemp();
I 38
D 60
	static char tempfname[40];
E 60
I 60
	static char tempfname[60];
E 62
E 60
D 44
	extern char *QueueDir;
E 44
I 43
D 65
	extern char *macvalue();
E 65
I 57
D 60
	register HDR *h;
	extern HDR *hrvalue();
E 60
E 57
E 43
E 38
D 31
	extern char *capitalize();
# ifdef DEBUG
E 23
I 20
	HDR *h;
I 23
# endif
E 31
E 23
E 20
E 15
E 13
I 11
	extern char *index();
E 11
E 5

	/*
	**  Create the temp file name and create the file.
	*/

D 23
	mktemp(InFileName);
	close(creat(InFileName, 0600));
E 23
I 23
D 38
	(void) mktemp(InFileName);
	(void) close(creat(InFileName, 0600));
E 23
	if ((tf = fopen(InFileName, "w")) == NULL)
E 38
I 38
D 53
	strcpy(tempfname, QueueDir);
D 51
	strcat(tempfname, "/dfaXXXXXX");
E 51
I 51
	strcat(tempfname, "/dfXXXXXX");
E 53
I 53
D 62
	(void) strcpy(tempfname, QueueDir);
	(void) strcat(tempfname, "/dfXXXXXX");
E 53
E 51
	(void) mktemp(tempfname);
D 48
	(void) close(creat(tempfname, 0600));
	if ((tf = fopen(tempfname, "w")) == NULL)
E 48
I 48
	if ((tf = dfopen(tempfname, "w")) == NULL)
E 62
I 62
	CurEnv->e_df = newstr(queuename(CurEnv, 'd'));
	if ((tf = dfopen(CurEnv->e_df, "w")) == NULL)
E 62
E 48
E 38
	{
D 38
		syserr("Cannot create %s", InFileName);
E 38
I 38
D 62
		syserr("Cannot create %s", tempfname);
E 62
I 62
		syserr("Cannot create %s", CurEnv->e_df);
E 62
E 38
D 27
		return (NULL);
E 27
I 27
D 44
		return;
E 44
I 44
		NoReturn = TRUE;
		finis();
E 44
E 27
	}
I 48
D 53
	chmod(tempfname, 0600);
E 53
I 53
D 62
	(void) chmod(tempfname, 0600);
E 53
E 48
I 38
D 52
	InFileName = tempfname;
E 52
I 52
	CurEnv->e_df = tempfname;
E 62
I 62
D 66
	(void) chmod(CurEnv->e_df, 0600);
E 66
I 66
	(void) chmod(CurEnv->e_df, FileMode);
E 66
E 62
E 52
E 38

I 13
D 31
	/* try to read a UNIX-style From line */
E 31
I 31
	/*
I 42
D 61
	**  Create the Mail-From line if we want to.
E 61
I 61
D 63
	**  Create the Received: line if we want to.
E 61
	*/

D 44
	if (macvalue('s') != NULL)
E 44
I 44
	if (Smtp && macvalue('s') != NULL)
E 44
	{
		char xbuf[50];

D 43
		sprintf(xbuf, "Mail-From: %s$s received by $i at $b",
E 43
I 43
D 61
		(void) sprintf(xbuf, "Mail-From: %s$s received by $i at $b",
E 43
			macvalue('r') == NULL ? "" : "$r host ");
E 61
I 61
		/* this should be in the config file */
		(void) sprintf(xbuf, "Received: from $s by $i with SMTP; $b");
E 61
D 51
		(void) expand(xbuf, buf, &buf[sizeof buf - 1]);
E 51
I 51
		expand(xbuf, buf, &buf[sizeof buf - 1], CurEnv);
E 51
D 43
		chompheader(buf, FALSE);
E 43
I 43
		(void) chompheader(buf, FALSE);
E 43
	}

	/*
E 63
E 42
I 33
	**  Tell ARPANET to go ahead.
	*/

D 40
	if (ArpaMode == ARPA_MAIL)
	{
		extern char Arpa_Enter[];
E 40
I 40
	if (sayok)
		message("354", "Enter mail, end with \".\" on a line by itself");
E 40

D 40
		message(Arpa_Enter, "Enter mail, end with \".\" on a line by itself");
	}

E 40
	/*
E 33
	**  Try to read a UNIX-style From line
	*/

E 31
D 46
	if (fgets(buf, sizeof buf, stdin) == NULL)
E 46
I 46
D 74
	if (fgets(buf, sizeof buf, InChannel) == NULL)
E 74
I 74
D 76
	if (sfgets(buf, sizeof buf, InChannel) == NULL)
E 74
E 46
D 27
		return (NULL);
E 27
I 27
		return;
E 76
I 76
	(void) sfgets(buf, sizeof buf, InChannel);
E 76
I 37
	fixcrlf(buf, FALSE);
E 37
I 32
# ifndef NOTUNIX
E 32
E 27
D 33
	if (strncmp(buf, "From ", 5) == 0)
E 33
I 33
	if (!SaveFrom && strncmp(buf, "From ", 5) == 0)
E 33
	{
		eatfrom(buf);
D 23
		fgets(buf, sizeof buf, stdin);
E 23
I 23
D 46
		(void) fgets(buf, sizeof buf, stdin);
E 46
I 46
D 74
		(void) fgets(buf, sizeof buf, InChannel);
E 74
I 74
		(void) sfgets(buf, sizeof buf, InChannel);
E 74
E 46
I 37
		fixcrlf(buf, FALSE);
E 37
E 23
	}
I 32
# endif NOTUNIX
E 32

E 13
	/*
D 42
	**  Copy stdin to temp file & do message editting.
E 42
I 42
D 46
	**  Copy stdin to temp file & do message editing.
E 46
I 46
	**  Copy InChannel to temp file & do message editing.
E 46
E 42
D 13
	**	From person gets copied into fbuf.  At the end of
	**	this loop, if fbuf[0] == '\0' then there was no
	**	recognized from person in the message.  We also
	**	save the message id in MsgId.  The
	**	flag 'inheader' keeps track of whether we are
	**	in the header or in the body of the message.
	**	The flag 'firstline' is only true on the first
	**	line of a message.
E 13
	**	To keep certain mailers from getting confused,
	**	and to keep the output clean, lines that look
D 74
	**	like UNIX "From" lines are deleted in the header,
	**	and prepended with ">" in the body.
E 74
I 74
	**	like UNIX "From" lines are deleted in the header.
E 74
	*/

D 13
	inheader = TRUE;
	firstline = TRUE;
	fbuf[0] = '\0';
D 12
	while (fgets(buf, sizeof buf, stdin) != NULL)
E 12
I 12
	while (!feof(stdin) && fgets(buf, sizeof buf, stdin) != NULL)
E 13
I 13
D 38
	for (; !feof(stdin); !feof(stdin) && fgets(buf, sizeof buf, stdin))
E 38
I 38
D 46
	for (; !feof(stdin); !feof(stdin) && fgets(buf, sizeof buf, stdin) != NULL)
E 46
I 46
D 64
	for (; !feof(InChannel); !feof(InChannel) && fgets(buf, sizeof buf, InChannel) != NULL)
E 64
I 64
D 68
	for (; !feof(InChannel); !feof(InChannel) && fgets(buf, MAXFIELD, InChannel) != NULL)
E 68
I 68
D 74
	for (; !feof(InChannel); !feof(InChannel) &&
				 fgets(buf, MAXFIELD, InChannel) != NULL)
E 74
I 74
D 76
	for (; !feof(InChannel); !feof(InChannel) && !ferror(InChannel) &&
				 sfgets(buf, MAXFIELD, InChannel) != NULL)
E 76
I 76
	do
E 76
E 74
E 68
E 64
E 46
E 38
E 13
E 12
	{
I 31
D 76
		register char c;
E 76
I 76
		int c;
E 76
		extern bool isheader();

I 79
		/* drop out on error */
		if (ferror(InChannel))
			break;

E 79
I 58
		/* if the line is too long, throw the rest away */
		if (index(buf, '\n') == NULL)
		{
D 76
			while ((c = getc(InChannel)) != '\n')
E 76
I 76
			while ((c = getc(InChannel)) != '\n' && c != EOF)
E 76
				continue;
			/* give an error? */
		}

E 58
I 37
D 64
		fixcrlf(buf, FALSE);
E 64
I 64
		fixcrlf(buf, TRUE);
E 64

E 37
E 31
D 13
		if (inheader && isalnum(buf[0]))
E 13
I 13
		/* see if the header is over */
		if (!isheader(buf))
			break;

		/* get the rest of this field */
D 46
		while ((c = getc(stdin)) == ' ' || c == '\t')
E 46
I 46
		while ((c = getc(InChannel)) == ' ' || c == '\t')
E 46
E 13
		{
D 13
			/* get the rest of this field */
			while ((c = getc(stdin)) == ' ' || c == '\t')
			{
				p = &buf[strlen(buf)];
				*p++ = c;
				if (fgets(p, sizeof buf - (p - buf), stdin) == NULL)
					break;
			}
D 6
			ungetc(c, stdin);
E 6
I 6
			if (c != EOF)
				ungetc(c, stdin);
E 13
I 13
			p = &buf[strlen(buf)];
I 64
			*p++ = '\n';
E 64
			*p++ = c;
D 46
			if (fgets(p, sizeof buf - (p - buf), stdin) == NULL)
E 46
I 46
D 64
			if (fgets(p, sizeof buf - (p - buf), InChannel) == NULL)
E 64
I 64
D 74
			if (fgets(p, MAXFIELD - (p - buf), InChannel) == NULL)
E 74
I 74
			if (sfgets(p, MAXFIELD - (p - buf), InChannel) == NULL)
E 74
E 64
E 46
				break;
I 37
D 64
			fixcrlf(p, FALSE);
E 64
I 64
			fixcrlf(p, TRUE);
E 64
E 37
E 13
E 6
		}
I 13
D 23
		if (c != EOF)
			ungetc(c, stdin);
E 23
I 23
D 46
		if (!feof(stdin))
			(void) ungetc(c, stdin);
E 46
I 46
D 79
		if (!feof(InChannel))
E 79
I 79
		if (!feof(InChannel) && !ferror(InChannel))
E 79
			(void) ungetc(c, InChannel);
E 46
E 23
E 13

D 13
		if (!IgnrDot && buf[0] == '.' && (buf[1] == '\n' || buf[1] == '\0'))
			break;
E 13
I 13
D 49
		MsgSize += strlen(buf);
E 49
I 49
		CurEnv->e_msgsize += strlen(buf);
I 84
		if (MaxMessageSize != 0 && CurEnv->e_msgsize > MaxMessageSize)
		{
D 85
toobig:			nmessage("552",
E 85
I 85
			nmessage("552",
E 85
			"Messages longer than %ld bytes are not allowed",
				MaxMessageSize);
			Errors++;
			if (OpMode != MD_SMTP)
				CurEnv->e_flags |= EF_FATALERRS;
			else
				CurEnv->e_flags &= ~EF_FATALERRS;
			if (ExitStat == EX_OK)
				ExitStat = EX_UNAVAILABLE;
			finis();
		}
E 84
E 49
E 13

D 13
		/* are we still in the header? */
		if ((buf[0] == '\n' || buf[0] == '\0') && inheader)
E 13
I 13
		/*
		**  Snarf header away.
		*/

D 20
		/* strip off trailing newline */
		p = rindex(buf, '\n');
		if (p != NULL)
			*p = '\0';

		/* find canonical name */
		fname = buf;
		p = index(buf, ':');
		fvalue = &p[1];
		while (isspace(*--p))
			continue;
		*++p = '\0';
		makelower(fname);

		/* strip field value on front */
		if (*fvalue == ' ')
			fvalue++;

		/* search header list for this header */
		for (hp = &Header, h = Header; h != NULL; hp = &h->h_link, h = h->h_link)
E 13
		{
D 13
			inheader = FALSE;
			if (MsgId[0] == '\0')
E 13
I 13
D 14
			if (strcmp(fname, h->h_field) == 0 && flagset(H_CONCAT|H_DEFAULT, h->h_flags))
E 14
I 14
			if (strcmp(fname, h->h_field) == 0 && bitset(H_DEFAULT, h->h_flags))
E 14
				break;
		}
I 16

		/* see if it is a known type */
		for (hi = HdrInfo; hi->hi_field != NULL; hi++)
		{
			if (strcmp(hi->hi_field, fname) == 0)
				break;
		}

		/* if this means "end of header" quit now */
		if (bitset(H_EOH, hi->hi_flags))
E 20
I 20
D 22
		if (bitset(H_EOH, chompheader(buf, 0)))
E 22
I 22
		if (bitset(H_EOH, chompheader(buf, FALSE)))
E 22
E 20
			break;
D 20

		/* create/fill in a new node */
E 16
		if (h == NULL)
		{
			/* create a new node */
D 14
# ifdef DEBUG
			if (Debug)
				printf("new field '%s', value '%s'\n", fname, fvalue);
# endif DEBUG
E 14
			*hp = h = (HDR *) xalloc(sizeof *h);
			h->h_field = newstr(fname);
			h->h_value = NULL;
			h->h_link = NULL;
D 16
			h->h_flags = 0;

			/* see if it is a known type */
			for (hi = HdrInfo; hi->hi_field != NULL; hi++)
E 13
			{
D 13
				makemsgid();
				if (UseMsgId)
					fprintf(tf, "Message-Id: <%s>\n", MsgId);
E 13
I 13
				if (strcmp(hi->hi_field, h->h_field) == 0)
				{
					h->h_flags = hi->hi_flags;
					break;
				}
E 13
			}
E 16
I 16
			h->h_flags = hi->hi_flags;
E 16
I 13
		}
D 14
		else if (flagset(H_DEFAULT, h->h_flags))
E 14
I 14
D 16
		else if (bitset(H_DEFAULT, h->h_flags))
E 14
		{
			/* overriding default, throw out old value */
E 16
I 16
		if (h->h_value != NULL)
E 16
E 13
D 14
# ifdef DEBUG
			if (Debug)
D 13
				printf("EOH\n");
E 13
I 13
				printf("overriding '%s', old='%s', new='%s'\n",
				       fname, h->h_value, fvalue);
E 13
# endif DEBUG
E 14
I 13
			free(h->h_value);
D 16
			h->h_value = NULL;
E 13
		}
E 16
I 16
		h->h_value = newstr(fvalue);
E 16

D 13
		/* Hide UNIX-like From lines */
D 9
D 10
		if (buf[0] == 'F' && buf[1] == 'r' && buf[2] == 'o' &&
		    buf[3] == 'm' && buf[4] == ' ')
E 10
I 10
		if (strncmp(buf, "From ", 5) == 0)
E 13
I 13
D 16
		/* do something with the value */
		if (h->h_value == NULL)
E 13
E 10
E 9
I 9
		if (strncmp(buf, "From ", 5) == 0)
E 9
		{
D 10
			if (firstline && !SaveFrom)
I 9
			{
				savedate(buf);
E 9
				continue;
I 9
			}
E 9
			fputs(">", tf);
I 7
			MsgSize++;
E 10
I 10
D 13
			if (!firstline)
			{
				fputs(">", tf);
				MsgSize++;
			}
			else
I 11
			{
E 11
				GotHdr++;
E 13
I 13
D 14
# ifdef DEBUG
			if (Debug)
				printf("installing '%s: %s'\n", fname, fvalue);
# endif DEBUG
E 14
			h->h_value = newstr(fvalue);
E 13
I 11
				if (from != NULL)
				{
					fputs("From ", tf);
					fputs(from, tf);
					MsgSize += strlen(from) + 5;
					p = index(&buf[5], ' ');
					if (p != NULL)
					{
						fputs(p, tf);
						MsgSize += strlen(p);
					}
					continue;
				}
			}
E 11
E 10
E 7
		}
D 13

		if (inheader && !isspace(buf[0]))
E 13
I 13
		else
E 13
		{
D 13
			/* find out if this is really a header */
			for (p = buf; *p != ':' && *p != '\0' && !isspace(*p); p++)
				continue;
			while (*p != ':' && isspace(*p))
				p++;
			if (*p != ':')
			{
				inheader = FALSE;
E 13
I 13
D 15
			register int len;
E 15
I 15
			register unsigned len;
E 15

			/* concatenate the two values */
E 13
D 14
# ifdef DEBUG
D 13
				if (Debug)
					printf("EOH?\n");
E 13
I 13
			if (Debug)
				printf("concat '%s: %s' with '%s'\n", fname,
				       h->h_value, fvalue);
E 13
# endif DEBUG
E 14
D 13
			}
E 13
I 13
			len = strlen(h->h_value) + strlen(fvalue) + 2;
			p = xalloc(len);
			strcpy(p, h->h_value);
			strcat(p, ",");
			strcat(p, fvalue);
			free(h->h_value);
			h->h_value = p;
E 13
		}
E 16
I 16
		/* save the location of this field */
		if (hi->hi_pptr != NULL)
			*hi->hi_pptr = h->h_value;
E 20
E 16
I 13
D 76
	}
E 76
I 76
	} while (sfgets(buf, MAXFIELD, InChannel) != NULL);
E 76
E 13

D 13
		if (inheader)
		{
			/* find the sender */
			p = matchhdr(buf, "sender");
			if (p == NULL && fbuf[0] == '\0')
				p = matchhdr(buf, "from");
			if (p != NULL)
				prescan(p, fbuf, &fbuf[sizeof fbuf - 1], '\0');
E 13
I 13
# ifdef DEBUG
D 57
	if (Debug)
E 57
I 57
	if (tTd(30, 1))
E 57
		printf("EOH\n");
# endif DEBUG
E 13

D 13
			/* find the message id */
			p = matchhdr(buf, "message-id");
			if (p != NULL && MsgId[0] == '\0')
				prescan(p, MsgId, &MsgId[sizeof MsgId - 1], '\0');
E 13
I 13
	/* throw away a blank line */
D 64
	if (buf[0] == '\n')
E 64
I 64
	if (buf[0] == '\0')
E 64
I 37
D 76
	{
E 76
E 37
D 23
		fgets(buf, sizeof buf, stdin);
E 23
I 23
D 46
		(void) fgets(buf, sizeof buf, stdin);
E 46
I 46
D 64
		(void) fgets(buf, sizeof buf, InChannel);
E 46
I 37
		fixcrlf(buf, FALSE);
E 64
I 64
D 74
		(void) fgets(buf, MAXFIELD, InChannel);
E 74
I 74
		(void) sfgets(buf, MAXFIELD, InChannel);
E 74
D 76
		fixcrlf(buf, TRUE);
E 64
	}
E 76
E 37
E 23

	/*
	**  Collect the body of the message.
	*/

D 46
	for (; !feof(stdin); !feof(stdin) && fgets(buf, sizeof buf, stdin) != NULL)
E 46
I 46
D 68
	for (; !feof(InChannel); !feof(InChannel) && fgets(buf, sizeof buf, InChannel) != NULL)
E 68
I 68
D 74
	for (; !feof(InChannel); !feof(InChannel) &&
				 fgets(buf, sizeof buf, InChannel) != NULL)
E 74
I 74
D 76
	for (; !feof(InChannel); !feof(InChannel) && !ferror(InChannel) &&
				 sfgets(buf, sizeof buf, InChannel) != NULL)
E 76
I 76
	do
E 76
E 74
E 68
E 46
	{
I 26
D 68
		register int i;
E 68
I 36
		register char *bp = buf;
E 36

I 37
D 64
		fixcrlf(buf, FALSE);
E 64
I 64
		fixcrlf(buf, TRUE);
E 64

E 37
E 26
		/* check for end-of-message */
		if (!IgnrDot && buf[0] == '.' && (buf[1] == '\n' || buf[1] == '\0'))
			break;

I 36
		/* check for transparent dot */
D 67
		if (Smtp && *bp == '.')
E 67
I 67
D 68
		if (OpMode == MD_SMTP && *bp == '.')
E 68
I 68
		if (OpMode == MD_SMTP && !IgnrDot && bp[0] == '.' && bp[1] == '.')
E 68
E 67
			bp++;

E 36
I 32
D 73
# ifndef NOTUNIX
E 32
		/* Hide UNIX-like From lines */
D 36
		if (strncmp(buf, "From ", 5) == 0)
E 36
I 36
		if (strncmp(bp, "From ", 5) == 0)
E 36
		{
			fputs(">", tf);
D 49
			MsgSize++;
E 49
I 49
			CurEnv->e_msgsize++;
E 49
E 13
		}
I 32
# endif NOTUNIX
E 32
I 7
D 26
		MsgSize += strlen(buf);
E 26
I 26

E 73
		/*
		**  Figure message length, output the line to the temp
		**  file, and insert a newline if missing.
		*/

D 36
		i = strlen(buf);
E 36
I 36
D 68
		i = strlen(bp);
E 36
D 49
		MsgSize += i;
E 49
I 49
D 64
		CurEnv->e_msgsize += i;
E 64
I 64
		CurEnv->e_msgsize += i + 1;
E 68
I 68
D 85
		CurEnv->e_msgsize += strlen(bp) + 1;
I 84
		if (MaxMessageSize != 0 && CurEnv->e_msgsize > MaxMessageSize)
			goto toobig;
E 84
E 68
E 64
E 49
E 26
E 7
D 36
		fputs(buf, tf);
I 26
		if (buf[i - 1] != '\n')
E 36
I 36
		fputs(bp, tf);
D 64
		if (bp[i - 1] != '\n')
E 36
			fputs("\n", tf);
E 64
I 64
		fputs("\n", tf);
E 85
I 85
		if (!oversize && MaxMessageSize != 0 &&
			CurEnv->e_msgsize >= MaxMessageSize)
		{
			oversize = TRUE;
			fputs("\n*** Oversize message trimmed ***\n", tf);
		}
		if (!oversize)
		{
			CurEnv->e_msgsize += strlen(bp) + 1;
			fputs(bp, tf);
			putc('\n', tf);
		}
E 85
E 64
E 26
D 13
		firstline = FALSE;
E 13
		if (ferror(tf))
D 72
		{
D 5
			syserr("Cannot write %s", InFileName);
			clearerr(tf);
			break;
E 5
I 5
			if (errno == ENOSPC)
			{
D 23
				freopen(InFileName, "w", tf);
E 23
I 23
D 52
				(void) freopen(InFileName, "w", tf);
E 52
I 52
				(void) freopen(CurEnv->e_df, "w", tf);
E 52
E 23
				fputs("\nMAIL DELETED BECAUSE OF LACK OF DISK SPACE\n\n", tf);
D 35
				syserr("Out of disk space for temp file");
E 35
I 35
D 37
				syserr("collect: Out of disk space for temp file");
E 37
I 37
				usrerr("452 Out of disk space for temp file");
E 37
E 35
			}
			else
D 35
				syserr("Cannot write %s", InFileName);
E 35
I 35
D 52
				syserr("collect: Cannot write %s", InFileName);
E 52
I 52
				syserr("collect: Cannot write %s", CurEnv->e_df);
E 52
E 35
D 23
			freopen("/dev/null", "w", tf);
E 23
I 23
			(void) freopen("/dev/null", "w", tf);
E 23
E 5
		}
E 72
I 72
			tferror(tf);
E 72
D 76
	}
E 76
I 76
	} while (sfgets(buf, MAXFIELD, InChannel) != NULL);
E 76
I 72
	if (fflush(tf) != 0)
		tferror(tf);
E 72
D 23
	fclose(tf);
E 23
I 23
	(void) fclose(tf);
E 23
D 13
	if (MsgId[0] == '\0')
		makemsgid();
E 13
I 13

I 70
	/* An EOF when running SMTP is an error */
D 79
	if (feof(InChannel) && OpMode == MD_SMTP)
E 79
I 79
	if ((feof(InChannel) || ferror(InChannel)) && OpMode == MD_SMTP)
E 79
D 77
		syserr("collect: unexpected close");
E 77
I 77
	{
		syserr("collect: unexpected close, from=%s", CurEnv->e_from.q_paddr);

		/* don't return an error indication */
		CurEnv->e_to = NULL;
		CurEnv->e_flags &= ~EF_FATALERRS;

		/* and don't try to deliver the partial message either */
		finis();
	}
E 77

E 70
	/*
	**  Find out some information from the headers.
D 16
	**	Examples are who is the from person, the date, the
	**	message-id, etc.
E 16
I 16
D 20
	**	Examples are who is the from person & the date.  Some
	**	fields, e.g., Message-Id, may have been handled by
	**	the hi_pptr mechanism.
E 20
I 20
	**	Examples are who is the from person & the date.
E 20
E 16
	*/

I 57
D 60
	/* message id */
	h = hrvalue("message-id");
	if (h == NULL)
		syserr("No Message-Id spec");
	else if (bitset(H_DEFAULT, h->h_flags))
	{
		(void) expand(h->h_value, buf, &buf[sizeof buf - 1], CurEnv);
		MsgId = newstr(buf);
	}
	else
		MsgId = h->h_value;
# ifdef DEBUG
	if (tTd(30, 1))
		printf("Message-Id: %s\n", MsgId);
# endif DEBUG
E 60
I 60
D 68
	eatheader();
E 68
I 68
	eatheader(CurEnv);
E 68
E 60

E 57
I 47
D 60
	/* message priority */
E 47
I 38
D 41
	/* message priority */
	p = hvalue("priority");
	if (p != NULL)
		MsgPriority = priencode(p);
E 41
I 41
	if (!QueueRun)
	{
		/* adjust total priority by message priority */
D 49
		MsgPriority = MsgSize;
E 49
I 49
		CurEnv->e_msgpriority = CurEnv->e_msgsize;
E 49
		p = hvalue("priority");
		if (p != NULL)
D 49
			MsgPriority -= priencode(p) * WKPRIFACT;
E 49
I 49
D 50
			CurEnv->e_msgpriority -= priencode(p) * WKPRIFACT;
E 50
I 50
			CurEnv->e_class = priencode(p);
		else
			CurEnv->e_class = PRI_NORMAL;
		CurEnv->e_msgpriority -= CurEnv->e_class * WKPRIFACT;
E 50
E 49
	}
E 60
I 60
	/*
	**  Add an Apparently-To: line if we have no recipient lines.
	*/
E 60
E 41

I 47
D 60
	/* special handling */
	p = hvalue("special-handling");
	if (p != NULL)
		spechandling(p);

E 47
E 38
	/* from person */
	xfrom = hvalue("sender");
	if (xfrom == NULL)
D 30
		xfrom = hvalue("from");
E 30
I 30
D 34
		xfrom = hvalue("original-from");
E 34
I 34
D 49
		xfrom = OrigFrom;
E 49
I 49
		xfrom = CurEnv->e_origfrom;
E 49
E 34
E 30
I 27
D 40
	if (ArpaMode != ARPA_NONE)
E 40
I 40
	if (ArpaMode)
E 40
D 31
		setfrom(xfrom, NULL);
E 31
I 31
		setfrom(xfrom, (char *) NULL);
E 31
E 27

I 21
	/* full name of from person */
	p = hvalue("full-name");
	if (p != NULL)
		define('x', p);
I 30
	else
	{
D 45
		register char *q;
E 45
I 45
		extern char *getxpart();
E 45

		/*
		**  Try to extract the full name from a general From:
		**  field.  We take anything which is a comment as a
		**  first choice.  Failing in that, we see if there is
		**  a "machine readable" name (in <angle brackets>); if
		**  so we take anything preceeding that clause.
		**
		**  If we blow it here it's not all that serious.
		*/

		p = hvalue("original-from");
I 34
		if (p == NULL)
D 49
			p = OrigFrom;
E 49
I 49
			p = CurEnv->e_origfrom;
E 49
E 34
D 45
		q = index(p, '(');
		if (q != NULL)
		{
			int parenlev = 0;

			for (p = q; *p != '\0'; p++)
			{
				if (*p == '(')
					parenlev++;
				else if (*p == ')' && --parenlev <= 0)
					break;
			}
			if (*p == ')')
			{
				*p = '\0';
				if (*++q != '\0')
					define('x', newstr(q));
				*p = ')';
			}
		}
		else if ((q = index(p, '<')) != NULL)
		{
			char savec;

			while (*--q == ' ')
				continue;
			while (isspace(*p))
				p++;
			savec = *++q;
			*q = '\0';
			if (*p != '\0')
				define('x', newstr(p));
			*q = savec;
		}
E 45
I 45
		p = getxpart(p);
		if (p != NULL)
			define('x', newstr(p));
E 45
	}
E 30

E 21
	/* date message originated */
D 20
	/* we don't seem to have a good way to do canonical conversion ....
E 20
D 25
	p = hvalue("date");
E 25
I 25
	p = hvalue("posted-date");
	if (p == NULL)
		p = hvalue("date");
E 25
	if (p != NULL)
D 20
		Date = newstr(arpatounix(p));
	.... so we will ignore the problem for the time being */
	if (Date == NULL)
E 20
	{
D 18
		auto long t;
E 18
D 20
		extern char *ctime();

D 18
		time(&t);
		Date = newstr(ctime(&t));
E 18
I 18
		Date = newstr(ctime(&CurTime));
E 20
I 20
		define('a', p);
		/* we don't have a good way to do canonical conversion ....
		define('d', newstr(arpatounix(p)));
		.... so we will ignore the problem for the time being */
E 20
E 18
	}
D 16

	/* message id */
	MsgId = hvalue("message-id");
	if (MsgId == NULL)
		MsgId = makemsgid();
E 16

E 60
I 55
	if (hvalue("to") == NULL && hvalue("cc") == NULL &&
	    hvalue("bcc") == NULL && hvalue("apparently-to") == NULL)
	{
		register ADDRESS *q;

		/* create an Apparently-To: field */
		/*    that or reject the message.... */
		for (q = CurEnv->e_sendqueue; q != NULL; q = q->q_next)
		{
I 56
			if (q->q_alias != NULL)
				continue;
E 56
# ifdef DEBUG
D 57
			if (Debug > 1)
E 57
I 57
			if (tTd(30, 3))
E 57
				printf("Adding Apparently-To: %s\n", q->q_paddr);
# endif DEBUG
			addheader("apparently-to", q->q_paddr, CurEnv);
		}
	}

E 55
I 54
D 68
	/* check for hop count overflow */
	if (HopCount > MAXHOP)
		syserr("Too many hops (%d max); probably forwarding loop", MAXHOP);

E 68
E 54
E 13
D 28
	if (freopen(InFileName, "r", stdin) == NULL)
E 28
I 28
D 52
	if ((TempFile = fopen(InFileName, "r")) == NULL)
E 28
		syserr("Cannot reopen %s", InFileName);
E 52
I 52
D 69
	if ((TempFile = fopen(CurEnv->e_df, "r")) == NULL)
E 69
I 69
	if ((CurEnv->e_dfp = fopen(CurEnv->e_df, "r")) == NULL)
E 69
		syserr("Cannot reopen %s", CurEnv->e_df);
I 72
}
/*
**  TFERROR -- signal error on writing the temporary file.
**
**	Parameters:
**		tf -- the file pointer for the temporary file.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Gives an error message.
**		Arranges for following output to go elsewhere.
*/

tferror(tf)
	FILE *tf;
{
	if (errno == ENOSPC)
	{
		(void) freopen(CurEnv->e_df, "w", tf);
		fputs("\nMAIL DELETED BECAUSE OF LACK OF DISK SPACE\n\n", tf);
		usrerr("452 Out of disk space for temp file");
	}
	else
		syserr("collect: Cannot write %s", CurEnv->e_df);
	(void) freopen("/dev/null", "w", tf);
E 72
E 52
D 13
	return (ArpaFmt && fbuf[0] != '\0' ? fbuf : NULL);
E 13
I 13
D 71

D 60
# ifdef DEBUG
D 57
	if (Debug)
E 57
I 57
	if (tTd(30, 2))
E 57
	{
I 31
		HDR *h;
		extern char *capitalize();

E 31
		printf("----- collected header -----\n");
D 49
		for (h = Header; h != NULL; h = h->h_link)
E 49
I 49
		for (h = CurEnv->e_header; h != NULL; h = h->h_link)
E 49
			printf("%s: %s\n", capitalize(h->h_field), h->h_value);
		printf("----------------------------\n");
	}
# endif DEBUG
I 57

E 60
	/*
	**  Log collection information.
	*/

# ifdef LOG
	if (LogLevel > 1)
D 62
		syslog(LOG_INFO, "%s: from=%s, size=%ld, class=%d\n", MsgId,
		       CurEnv->e_from.q_paddr, CurEnv->e_msgsize,
E 62
I 62
		syslog(LOG_INFO, "%s: from=%s, size=%ld, class=%d\n",
		       CurEnv->e_id, CurEnv->e_from.q_paddr, CurEnv->e_msgsize,
E 62
D 59
		       CurEnv->e_msgpriority);
E 59
I 59
		       CurEnv->e_class);
E 59
# endif LOG
E 57
D 27
	return (ArpaFmt ? xfrom : NULL);
E 27
I 27
	return;
E 71
E 27
E 13
}
/*
I 13
**  EATFROM -- chew up a UNIX style from line and process
**
**	This does indeed make some assumptions about the format
**	of UNIX messages.
**
**	Parameters:
**		fm -- the from line.
**
**	Returns:
**		none.
**
**	Side Effects:
**		extracts what information it can from the header,
D 20
**		such as the Date.
E 20
I 20
**		such as the date.
E 20
*/

I 32
# ifndef NOTUNIX

E 32
I 29
char	*DowList[] =
{
	"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", NULL
};

E 29
char	*MonthList[] =
{
	"Jan", "Feb", "Mar", "Apr", "May", "Jun",
	"Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
	NULL
};

eatfrom(fm)
	char *fm;
{
	register char *p;
	register char **dt;

I 29
# ifdef DEBUG
D 57
	if (Debug > 1)
E 57
I 57
	if (tTd(30, 2))
E 57
		printf("eatfrom(%s)\n", fm);
# endif DEBUG

E 29
	/* find the date part */
	p = fm;
	while (*p != '\0')
	{
		/* skip a word */
		while (*p != '\0' && *p != ' ')
D 78
			*p++;
E 78
I 78
			p++;
E 78
		while (*p == ' ')
D 78
			*p++;
E 78
I 78
			p++;
E 78
		if (!isupper(*p) || p[3] != ' ' || p[13] != ':' || p[16] != ':')
			continue;

		/* we have a possible date */
D 29
		for (dt = MonthList; *dt != NULL; dt++)
E 29
I 29
		for (dt = DowList; *dt != NULL; dt++)
E 29
			if (strncmp(*dt, p, 3) == 0)
				break;
I 29
		if (*dt == NULL)
			continue;
E 29

I 29
		for (dt = MonthList; *dt != NULL; dt++)
			if (strncmp(*dt, &p[4], 3) == 0)
				break;
E 29
		if (*dt != NULL)
			break;
	}

	if (*p != NULL)
	{
I 20
		char *q;
I 44
		extern char *arpadate();
E 44

E 20
		/* we have found a date */
D 20
		Date = xalloc(25);
		strncpy(Date, p, 25);
		Date[24] = '\0';
E 20
I 20
		q = xalloc(25);
D 81
		strncpy(q, p, 25);
E 81
I 81
		(void) strncpy(q, p, 25);
E 81
		q[24] = '\0';
D 68
		define('d', q);
E 68
I 68
		define('d', q, CurEnv);
E 68
I 44
		q = arpadate(q);
D 68
		define('a', newstr(q));
E 68
I 68
		define('a', newstr(q), CurEnv);
E 68
E 44
E 20
	}
}
I 32

# endif NOTUNIX
I 38
D 60
/*
**  PRIENCODE -- encode external priority names into internal values.
**
**	Parameters:
**		p -- priority in ascii.
**
**	Returns:
**		priority as a numeric level.
**
**	Side Effects:
**		none.
*/

struct prio
{
	char	*pri_name;	/* external name of priority */
	int	pri_val;	/* internal value for same */
};

static struct prio	Prio[] =
{
D 39
	"normal",		PRI_NORMAL,
E 39
I 39
	"alert",		PRI_ALERT,
E 39
	"quick",		PRI_QUICK,
D 39
	"priority",		PRI_PRIORITY,
	"first-class",		PRI_NORMAL,
E 39
I 39
	"first-class",		PRI_FIRSTCL,
	"normal",		PRI_NORMAL,
E 39
	"second-class",		PRI_SECONDCL,
	"third-class",		PRI_THIRDCL,
I 50
	"junk",			PRI_JUNK,
E 50
	NULL,			PRI_NORMAL,
};

priencode(p)
	char *p;
{
	register struct prio *pl;
I 39
	extern bool sameword();
E 39

	for (pl = Prio; pl->pri_name != NULL; pl++)
	{
D 39
		if (strcmp(p, pl->pri_name) == 0)
E 39
I 39
		if (sameword(p, pl->pri_name))
E 39
			break;
	}
	return (pl->pri_val);
I 47
}
/*
**  SPECHANDLE -- do special handling
**
**	Parameters:
**		p -- pointer to list of special handling words.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Sets flags as indicated by p.
*/

struct handling
{
	char	*han_name;		/* word to get this magic */
	int	han_what;		/* what to do, see below */
};

/* modes for han_what */
# define	HAN_NONE	0	/* nothing special */
# define	HAN_RRECEIPT	1	/* give return receipt */

struct handling	Handling[] =
{
	"return-receipt-requested",	HAN_RRECEIPT,
	NULL,				HAN_NONE
};

spechandling(p)
	register char *p;
{
	register char *w;
	register struct handling *h;
	extern bool sameword();

	while (*p != '\0')
	{
		/* collect a word to compare to */
		while (*p != '\0' && (*p == ',' || isspace(*p)))
			p++;
		if (*p == '\0')
			break;
		w = p;
		while (*p != '\0' && *p != ',' && !isspace(*p))
			p++;
		if (*p != '\0')
			*p++ = '\0';

		/* scan the special handling table */
		for (h = Handling; h->han_name != NULL; h++)
			if (sameword(h->han_name, w))
				break;

		/* see if we can do anything interesting */
		switch (h->han_what)
		{
		  case HAN_NONE:	/* nothing to be done */
			break;

		  case HAN_RRECEIPT:	/* give return receipt */
D 49
			RetReceipt = TRUE;
E 49
I 49
			CurEnv->e_retreceipt = TRUE;
E 49
# ifdef DEBUG
D 57
			if (Debug > 2)
E 57
I 57
			if (tTd(30, 3))
E 57
				printf(">>> Return receipt requested\n");
# endif DEBUG
			break;

		  default:
			syserr("spechandling: handling %d (%s)", h->han_what, w);
		}
	}
E 47
}
E 60
E 38
E 32
D 24
/*
**  HVALUE -- return value of a header.
**
I 20
**	Only "real" fields (i.e., ones that have not been supplied
**	as a default) are used.
**
E 20
**	Parameters:
**		field -- the field name.
**
**	Returns:
**		pointer to the value part.
**		NULL if not found.
**
**	Side Effects:
**		sets the H_USED bit in the header if found.
*/

char *
hvalue(field)
	char *field;
{
	register HDR *h;

	for (h = Header; h != NULL; h = h->h_link)
	{
D 20
		if (strcmp(h->h_field, field) == 0)
E 20
I 20
		if (!bitset(H_DEFAULT, h->h_flags) && strcmp(h->h_field, field) == 0)
E 20
		{
			h->h_flags |= H_USED;
			return (h->h_value);
		}
	}
	return (NULL);
}
/*
E 13
D 20
**  MAKEMSGID -- Compute a message id for this process.
**
**	This routine creates a message id for a message if
**	it did not have one already.  If the MESSAGEID compile
**	flag is set, the messageid will be added to any message
**	that does not already have one.  Currently it is more
**	of an artifact, but I suggest that if you are hacking,
**	you leave it in -- I may want to use it someday if
**	duplicate messages turn out to be a problem.
**
**	Parameters:
**		none.
**
**	Returns:
D 13
**		none.
E 13
I 13
**		a message id.
E 13
**
**	Side Effects:
D 13
**		Stores a message-id into MsgId.
**
**	Called By:
**		maketemp
E 13
I 13
**		none.
E 13
*/

I 13
char *
E 13
makemsgid()
{
D 18
	auto long t;
D 17
	extern char *MyLocName;
	extern char *ArpaHost;
E 17
I 17
	register char *p;
	extern char *Macro[];
E 18
E 17
I 13
	static char buf[50];
I 15
D 18
	extern long time();
	extern char *sprintf();
E 18
I 18
	extern char *expand();
E 18
E 15
E 13

D 18
	time(&t);
D 13
	sprintf(MsgId, "%ld.%d.%s@%s", t, getpid(), MyLocName, ArpaHost);
E 13
I 13
D 17
	sprintf(buf, "<%ld.%d.%s@%s>", t, getpid(), MyLocName, ArpaHost);
E 17
I 17
	sprintf(buf, "<%ld.%d", t, getpid());
	p = Macro['l'];
	if (p != NULL)
	{
		strcat(buf, ".");
		strcat(buf, p);
	}
	p = Macro['A'];
	if (p != NULL)
	{
		strcat(buf, "@");
		strcat(buf, p);
	}
	strcat(buf, ">");

E 18
I 18
	expand("<$m>", buf, &buf[sizeof buf - 1]);
E 18
E 17
	return (buf);
}
/*
E 20
**  ISHEADER -- predicate telling if argument is a header.
**
**	Parameters:
**		s -- string to check for possible headerness.
**
**	Returns:
**		TRUE if s is a header.
**		FALSE otherwise.
**
**	Side Effects:
**		none.
*/

bool
isheader(s)
	register char *s;
{
	if (!isalnum(*s))
		return (FALSE);
	while (!isspace(*s) && *s != ':')
		s++;
	while (isspace(*s))
		s++;
	return (*s == ':');
I 20
}
/*
**  CHOMPHEADER -- process and save a header line.
**
**	Called by collect and by readcf to deal with header lines.
**
**	Parameters:
**		line -- header as a text line.
D 22
**		stat -- bits to set in the h_flags field.
E 22
I 22
**		def -- if set, this is a default value.
E 22
**
**	Returns:
**		flags for this header.
**
**	Side Effects:
**		The header is saved on the header list.
*/

D 22
chompheader(line, stat)
E 22
I 22
chompheader(line, def)
E 22
	char *line;
D 22
	int stat;
E 22
I 22
	bool def;
E 22
{
	register char *p;
D 23
	extern int errno;
E 23
	register HDR *h;
	HDR **hp;
	extern bool isheader();
D 23
	extern char *newstr();
	extern char *xalloc();
E 23
	char *fname;
	char *fvalue;
D 23
	extern char *index(), *rindex();
E 23
	struct hdrinfo *hi;
D 23
	extern char *strcpy(), *strcat(), *mktemp();
E 23

	/* strip off trailing newline */
	p = rindex(line, '\n');
	if (p != NULL)
		*p = '\0';

	/* find canonical name */
	fname = line;
	p = index(line, ':');
	fvalue = &p[1];
	while (isspace(*--p))
		continue;
	*++p = '\0';
	makelower(fname);

	/* strip field value on front */
	if (*fvalue == ' ')
		fvalue++;

	/* search header list for this header */
	for (hp = &Header, h = Header; h != NULL; hp = &h->h_link, h = h->h_link)
	{
		if (strcmp(fname, h->h_field) == 0 && bitset(H_DEFAULT, h->h_flags))
			break;
	}

	/* see if it is a known type */
	for (hi = HdrInfo; hi->hi_field != NULL; hi++)
	{
		if (strcmp(hi->hi_field, fname) == 0)
			break;
	}

	/* if this means "end of header" quit now */
	if (bitset(H_EOH, hi->hi_flags))
		return (hi->hi_flags);

	/* create/fill in a new node */
	if (h == NULL)
	{
		/* create a new node */
		*hp = h = (HDR *) xalloc(sizeof *h);
		h->h_field = newstr(fname);
		h->h_value = NULL;
		h->h_link = NULL;
D 22
		h->h_flags = hi->hi_flags | stat;
E 22
I 22
		h->h_flags = hi->hi_flags;
E 22
		h->h_mflags = hi->hi_mflags;
	}
I 22
	if (def)
		h->h_flags |= H_DEFAULT;
E 22
	else
D 22
		h->h_flags &= ~H_DEFAULT;
E 22
I 22
		h->h_flags &= ~H_CHECK;
E 22
	if (h->h_value != NULL)
		free(h->h_value);
	h->h_value = newstr(fvalue);

	return (h->h_flags);
E 20
E 13
I 9
}
/*
**  SAVEDATE -- find and save date field from a "From" line
**
**	This will be used by putheader when a From line is created.
**
**	Parameters:
**		buf -- a "From" line.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Saves the "date" part (with newline) in SentDate.
*/

char	SentDate[30];

savedate(buf)
	char *buf;
{
	register char *p;

	for (p = buf; p != '\0'; p++)
	{
		if (*p != ' ')
			continue;
		if (strncmp(p, " Sun ", 5) == 0 ||
		    strncmp(p, " Mon ", 5) == 0 ||
		    strncmp(p, " Tue ", 5) == 0 ||
		    strncmp(p, " Wed ", 5) == 0 ||
		    strncmp(p, " Thu ", 5) == 0 ||
		    strncmp(p, " Fri ", 5) == 0 ||
		    strncmp(p, " Sat ", 5) == 0)
		{
			if (p[4] != ' ' || p[8] != ' ' || p[11] != ' ' ||
			    p[14] != ':' || p[17] != ':' || p[20] != ' ')
				continue;
			strncpy(SentDate, ++p, 25);
			SentDate[24] = '\n';
			SentDate[25] = '\0';
			return;
		}
	}
E 9
}
E 24
E 2
I 1
E 1
