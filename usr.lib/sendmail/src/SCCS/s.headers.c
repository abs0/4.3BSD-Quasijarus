h49768
s 00011/00009/00840
d D 5.10 88/06/30 14:59:01 bostic 80 79
c install approved copyright notice
e
s 00016/00010/00833
d D 5.9 88/03/13 19:52:09 bostic 79 78
c add Berkeley specific header
e
s 00001/00002/00842
d D 5.8 88/03/13 18:21:38 bostic 78 77
c replace sameword with strcasecmp
e
s 00001/00001/00843
d D 5.7 85/09/21 16:23:56 eric 77 76
m 
c don't include ctime as part of priority, since the value affects the results of
c shouldqueue; we go back to adding ctime into the workcmpf in queue.c
e
s 00002/00002/00842
d D 5.6 85/09/21 14:44:21 eric 76 75
m 
c clean up priority handling, making several of the parameters configurable:
c y - WkRecipFact, z - WkClassFact, Z - WkTimeFact, Y - ForkQueueRuns; improve
c process title labelling; finish "errors to postmaster" option
e
s 00005/00002/00839
d D 5.5 85/09/19 00:45:09 eric 75 73
m 
c SMI changes (somewhat)
e
s 00010/00000/00841
d D 5.4.1.1 85/09/04 09:40:34 eric 74 73
m 
c save code to throw out invalid Sender: fields for validated senders
e
s 00001/00001/00840
d D 5.4 85/06/08 10:27:07 eric 73 72
m 
c lint for 4.3 release
e
s 00005/00005/00836
d D 5.3 85/06/08 00:03:06 eric 72 71
m 
c lint
e
s 00000/00004/00841
d D 5.2 85/06/07 22:28:45 miriam 71 70
m 
c Resolve duplicate SccsId.  Remove unused variable.
e
s 00014/00000/00831
d D 5.1 85/06/07 15:06:13 dist 70 69
m 
c Add copyright
e
s 00001/00001/00830
d D 4.6 85/05/24 10:54:55 eric 69 68
m 
c Changes from Bill Nowicki <sun!rose!nowicki> and Jay Lepreau <lepreau@utah-cs>:
c Fix "bad file number" problem; improve error reporting; try to keep messages
c closer to their original order.  Also, drop "safe" mode in readcf since we
c never run setuid when -C is specified.
e
s 00002/00001/00829
d D 4.5 84/08/11 23:18:02 eric 68 66
m 
c Add $[ and $] as RHS operators to look up the contents and pass them
c to maphostname; maphostname currently looks them up in /etc/hosts and
c converts them to canonical form, but could be turned into a general
c name server.....   huzzah!!
e
s 00000/00000/00830
d R 4.4.1.1 84/06/17 16:17:05 eric 67 66
m 
c abortive attempt to install a name server.... sigh.
e
s 00001/00001/00829
d D 4.4 84/03/11 16:52:39 eric 66 65
m 
c change macro expansion character from $ to \001 so that $'s can be
c used in headers -- the .cf file is unchanged by mapping $ to \001.
c \001 is now a manifest constant.
e
s 00002/00003/00828
d D 4.3 83/08/21 15:39:52 eric 65 64
m 
c Drop "Sender:" hack, since it doesn't work properly when relaying messages.
e
s 00017/00015/00814
d D 4.2 83/08/21 15:12:30 eric 64 63
m 
c Insert Sender: line if a From: line is specified and is different from
c what we would otherwise put in.
e
s 00000/00000/00829
d D 4.1 83/07/25 19:43:48 eric 63 62
m 
c 4.2 release version
e
s 00001/00001/00828
d D 3.59 83/06/14 11:04:47 eric 62 61
m 
c log the message-id only if non-null
e
s 00012/00014/00817
d D 3.58 83/06/11 19:28:31 eric 61 60
m 045
m 240
c don't rearrange input header lines; force Received: lines to be at the
c beginning by always adding new header fields at the end of the header.
e
s 00001/00001/00830
d D 3.57 83/05/01 15:02:39 eric 60 59
m 234
c don't add an extra tab in the header (white space should already exist)
e
s 00013/00001/00818
d D 3.56 83/05/01 14:27:41 eric 59 58
m 234
c avoid core dumps on messages with very long header fields
e
s 00001/00001/00818
d D 3.55 83/04/17 17:11:36 eric 58 57
m 224
c fix *(0) problems
e
s 00001/00001/00818
d D 3.54 83/03/12 15:39:19 eric 57 56
m 207
c Don't artifically add a "from: $q" when running the queue -- this seems
c to cause the from line in the qf file to be ignored.
e
s 00029/00004/00790
d D 3.53 83/03/06 16:30:04 eric 56 55
m 201
c Handle messages with "Resent-xxx:" header lines properly (basically mark
c the message as being resent); ignore incoming From: lines if their text
c exactly matches our machine-readable address exactly -- this causes the
c full name to be added when called from (e.g.) MH.  Both of these mode are
c to improve interaction with MH.
e
s 00003/00002/00791
d D 3.52 83/02/26 15:30:58 eric 55 54
m 193
c Don't log message-id mapping and from person in a queue run
e
s 00027/00000/00766
d D 3.51 83/02/26 11:51:16 eric 54 53
m 193
c log queueid <=> message-id correspondence
e
s 00002/00002/00764
d D 3.50 83/02/19 14:42:00 eric 53 52
m 188
c Avoid core dumps on very long addresses in headers.
e
s 00008/00007/00758
d D 3.49 83/02/02 12:54:33 eric 52 51
m 165
c implement classes and mailer flags as a bit map; define new class 'w'
c as the set of all hosts we are known by
e
s 00001/00001/00764
d D 3.48 83/01/15 17:41:17 eric 51 50
m 149
c be sure everything gets appropriately externalized; canonname goes away,
c since everything is now done by remotename
e
s 00001/00001/00764
d D 3.47 83/01/06 12:05:36 eric 50 49
m 
c fix (one more time!) long line wrapping.....
e
s 00008/00021/00757
d D 3.46 83/01/06 10:49:20 eric 49 48
m 
c split up FULLSMTP flag -- now have "X" (M_XDOT, use hidden dot algorithm),
c "p" (M_FROMPATH, use reverse-path in MAIL FROM:<> command), and "L"
c (M_LIMITS, enforce SMTP line limits).  I would like to change the format
c of the mail defn one more time to make named fields so that it would
c be more extensible.
e
s 00005/00003/00773
d D 3.45 83/01/05 20:29:58 eric 48 47
m 
c fix folded line output
e
s 00005/00000/00771
d D 3.44 83/01/04 10:04:26 eric 47 46
m 
c Detect an internal error that seems to be occuring
e
s 00003/00003/00768
d D 3.43 83/01/03 13:00:30 eric 46 45
m 
c fix bug in commaize so that it won't core dump on every message (sigh)
e
s 00013/00007/00758
d D 3.42 83/01/01 21:26:16 eric 45 44
m 123
c Put CRLF on all lines in user SMTP.  Pass this info down to
c innumerable routines.
e
s 00002/00002/00763
d D 3.41 82/12/13 18:26:17 eric 44 43
m 085
c The routine "sendto" is now a system call (yeuch!); change our sendto
c to "sendtolist"
e
s 00274/00035/00491
d D 3.40 82/11/28 00:24:06 eric 43 42
m 
c Many changes resulting from a complete code readthrough.  Most of these
c fix minor bugs or change the internal structure for clarity, etc.  There
c should be almost no externally visible changes (other than some cleaner
c error message printouts and the like).
e
s 00001/00097/00525
d D 3.39 82/11/24 18:45:14 eric 42 41
m 
c lint it
e
s 00001/00001/00621
d D 3.38 82/11/24 17:16:51 eric 41 40
m 026
c run SMTP jobs in a subprocess so that multiple jobs will work.  This
c delta also changes the envelope data structure so that flags are in
c a bit map, and adjusts some of the semantics.  The transcript is now
c local to an envelope.  A bunch of old code is deleted.  A serious bug
c was fixed in the "run in background" code.  Etc., etc.
e
s 00001/00001/00621
d D 3.37 82/11/17 09:37:39 eric 40 39
m 060
c split operation mode ("-bx" flag) and delivery mode ("d" option)
c so that operation mode can apply to SMTP/daemon connections also.
e
s 00006/00004/00616
d D 3.36 82/11/04 13:27:38 eric 39 38
m 037
c put header conditionals into the .cf file
e
s 00012/00025/00608
d D 3.35 82/09/24 09:38:57 eric 38 37
c arrange to be able to define options; put precedences in .cf file;
c send errors to an Errors-To: field; fix a serious bug causing mail
c to not be delivered to anyone if there were any errors.
e
s 00001/00001/00632
d D 3.34 82/09/06 19:55:29 eric 37 36
c more hacking on oldstyle -- always assume sender fields are in new
c style so that locally generated fields are edited correctly.
e
s 00004/00002/00629
d D 3.33 82/09/06 18:24:29 eric 36 35
c fix botch in computing e_oldstyle
e
s 00011/00003/00620
d D 3.32 82/09/06 16:25:32 eric 35 34
c install new state-driven scanner; make everyone use it, thus fixing
c problems of quoted commas, etc.
e
s 00023/00094/00600
d D 3.31 82/09/05 18:05:05 eric 34 33
c convert Return-Receipt-To: and Precedence: to NBS standard; correctly
c process all sender fields
e
s 00009/00006/00685
d D 3.30 82/08/27 18:01:05 eric 33 32
c hack crackaddr to strip blanks off the end of a cracked address; this
c happens because "u at h" becomes "$g  " (with two spaces at the end).
c this doesn't solve the general case (e.g., "u at h (me)" comes out as
c "$g   (me)", with three spaces), but does handle the ugliest case.
c besides, the "at" syntax is supposed to go away.
e
s 00014/00014/00677
d D 3.29 82/08/25 16:19:32 eric 32 31
c apply ruleset 4 to rewrite addresses in the body of the message; fix
c a clock.c bug that caused it to lose events; more time cleanup.
e
s 00001/00012/00690
d D 3.28 82/08/23 09:24:17 eric 31 30
c allow continuation lines in .cf file (particularly in headers)
e
s 00000/00024/00702
d D 3.27 82/08/22 23:07:32 eric 30 29
c change $i to $j; $i is now queue id; put "Received:" format in .cf
c file; minor cleanup
e
s 00013/00005/00713
d D 3.26 82/08/22 19:03:25 eric 29 28
c assign a unique id to each transaction that can be determined from
c the queue file name.
e
s 00002/00002/00716
d D 3.25 82/08/17 20:45:03 eric 28 27
c Mail-From: ==> Received: for new SMTP spec (RFC821)
e
s 00379/00008/00339
d D 3.24 82/08/17 16:17:42 eric 27 26
c rework header processing: do special purpose header munging in a
c separate routine so that the queue run can do it also.  Also, parse
c From: lines in a fancy way, extracting the address part and turning
c it into a $g macro.
e
s 00001/00005/00346
d D 3.23 82/08/15 17:34:00 eric 26 25
c make headers work properly when a message is queued up; this involves
c expanding the header before it is written into the queue.  However, it
c also means that we don't have to store the macro definitions (?)
e
s 00034/00000/00317
d D 3.22 82/08/08 01:03:47 eric 25 24
c change debug level to a debug vector; add levels on logging (and the
c -L flag); change logging to be by message-id; elevate message-id;
c some lint-type cleanup
e
s 00001/00001/00316
d D 3.21 82/07/05 18:49:54 eric 24 23
c add "Apparently-To:" field if no recipients are in the header.
e
s 00004/00000/00313
d D 3.20 82/07/05 13:19:55 eric 23 22
c count Mail-From: lines to avoid loops (simulates hop counts)
e
s 00000/00000/00313
d D 3.19 82/05/31 15:32:56 eric 22 20
i 21
c finish implementing envelopes.  it's not completely clear to me that
c this is really the way to go, but it seems clearly better than what
c i had before.  this delta includes many other minor changes, so it
c should probably not be blithely removed.
e
s 00049/00000/00264
d D 3.18.1.1 82/05/29 18:21:10 eric 21 20
c try to install envelopes.  is this really worth it???
e
s 00005/00005/00259
d D 3.18 82/05/22 01:39:02 eric 20 19
c add "envelopes" to contain the basic information needed as control
c info for each message.  currently there is only one envelope -- this
c being the obvious stupid conversion.  later there will be separate
c envelopes for error messages, return receipts, etc.
e
s 00001/00001/00263
d D 3.17 82/03/06 12:09:40 eric 19 18
c clean up error handling in IPC case; fix a minor bug in headers in
c queueing code; make SMTP mail multi user per connect.
e
s 00006/00000/00258
d D 3.16 82/02/22 19:31:56 eric 18 17
c become NewStyle automatically based on heuristics
e
s 00067/00001/00191
d D 3.15 82/02/20 19:16:28 eric 17 15
c make rewriting of addresses in headers really work.  This adds the $q
c macro.  The rewriting of the From: address is still ad hoc and should
c be integrated into this format.
c Note:  old .cf files will not work with this version.
e
s 00020/00002/00190
d D 3.14.1.1 82/02/20 15:51:28 eric 16 15
c put the type address headers into a per-header send queue
e
s 00001/00001/00191
d D 3.14 81/12/06 12:40:07 eric 15 14
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00009/00005/00183
d D 3.13 81/12/05 14:14:50 eric 14 13
c insert SMTP "Mail-From:" line.
e
s 00001/00001/00187
d D 3.12 81/11/22 19:18:08 eric 13 12
c Edit queue control files when running queue (assuming there are still
c recipients left).  Also, modify the MsgPriority to be the absolute
c number (not the Priority: value); this allows us to include aging into
c the priority algorithm.
e
s 00001/00001/00187
d D 3.11 81/11/21 18:43:47 eric 12 10
c change the send queue to be only one queue instead of one per mailer.
c this is slightly inefficient but simpler.  also, pass this queue
c around so we can have multiple send queues.  this makes VRFY work.
e
s 00002/00001/00187
d D 3.10.1.1 81/11/21 15:50:02 eric 11 10
c links together aliases into proper trees.  This is in part an
c attempt to do the SMTP VRFY command properly, but there are a number
c of annoying problems that convince me that this is the wrong way to
c do it.  Sigh.
e
s 00025/00005/00163
d D 3.10 81/10/26 14:23:07 eric 10 9
c Install new experimental queueing facility -- one stage timeout,
c etc.  This version is still quite incomplete.  It needs to reorder
c the queue after some interval, do two-stage timeout, take option
c info from the queue file instead of the command line, read the
c sender's .mailcf file, etc.  Some of this is useful for SMTP also.
e
s 00001/00001/00167
d D 3.9 81/09/16 16:24:22 eric 9 8
c last delta was too paranoid -- this increases the number of
c cases that work (but is still safe -- I hope)
e
s 00001/00001/00167
d D 3.8 81/09/16 16:08:21 eric 8 7
c run as the user forwarding mail after a .forward operation;
c fix a bug in .forwarding that caused recursive expansion;
c restrict mail to programs, files, and with :include: for security
c reasons.
e
s 00007/00004/00161
d D 3.7 81/09/12 15:49:17 eric 7 6
c change From: processing to reduce the number of Original-From:
c lines; change allocation of global variables.
e
s 00009/00000/00156
d D 3.6 81/09/06 19:49:24 eric 6 5
c cleanup, commenting, linting, etc.
e
s 00002/00000/00154
d D 3.5 81/08/24 14:06:17 eric 5 4
c Add "-t" option to read To:, Cc:, and Bcc: lines to get recipients
e
s 00004/00000/00150
d D 3.4 81/08/22 17:52:16 eric 4 3
c Arrange to pull full name out of From line if found; includes
c Original-From: hacking (oh so ugly).  There's got to be a better way
c to do this...
e
s 00000/00002/00150
d D 3.3 81/08/20 15:14:51 eric 3 2
c clean up some header information; don't reopen tempfile as
c stdin (to fix some problems with saving mail on interrupts)
e
s 00002/00001/00150
d D 3.2 81/08/17 09:37:58 eric 2 1
c add header fields from new BB&N proposal ICST/CBOS - 80-2,
c "Specification of a Draft Message Format Standard" for NBS.
e
s 00151/00000/00000
d D 3.1 81/08/09 16:40:48 eric 1 0
c date and time created 81/08/09 16:40:48 by eric
e
u
U
f b 
f i 
t
T
I 70
/*
I 80
 * Copyright (c) 1983 Eric P. Allman
E 80
D 79
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 79
I 79
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 80
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 80
I 80
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
E 80
 */
E 79

#ifndef lint
D 79
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint
E 79
I 79
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 79

E 70
I 1
D 3
# include <stdio.h>
# include <ctype.h>
E 3
# include <errno.h>
# include "sendmail.h"

D 15
static char	SccsId[] = "%W%	%G%";
E 15
I 15
D 71
SCCSID(%W%	%Y%	%G%);
E 15

E 71
/*
**  CHOMPHEADER -- process and save a header line.
**
**	Called by collect and by readcf to deal with header lines.
**
**	Parameters:
**		line -- header as a text line.
**		def -- if set, this is a default value.
**
**	Returns:
**		flags for this header.
**
**	Side Effects:
**		The header is saved on the header list.
I 6
**		Contents of 'line' are destroyed.
E 6
*/

chompheader(line, def)
	char *line;
	bool def;
{
	register char *p;
	register HDR *h;
	HDR **hp;
D 31
	extern bool isheader();
E 31
	char *fname;
	char *fvalue;
	struct hdrinfo *hi;
I 39
	bool cond = FALSE;
E 39
I 10
D 52
	u_long mopts;
	extern u_long mfencode();
E 52
I 52
	BITMAP mopts;
E 52
I 27
D 32
	extern char *crackfrom();
E 32
I 32
	extern char *crackaddr();
E 32
E 27
I 11
	extern ADDRESS *sendto();
E 11
E 10

I 25
# ifdef DEBUG
	if (tTd(31, 6))
		printf("chompheader: %s\n", line);
# endif DEBUG

E 25
D 31
	/* strip off trailing newline */
	p = rindex(line, '\n');
	if (p != NULL)
		*p = '\0';

E 31
I 10
	/* strip off options */
D 52
	mopts = 0;
E 52
I 52
	clrbitmap(mopts);
E 52
	p = line;
	if (*p == '?')
	{
		/* have some */
		register char *q = index(p + 1, *p);
		
		if (q != NULL)
		{
			*q++ = '\0';
D 52
			mopts = mfencode(p + 1);
E 52
I 52
			while (*++p != '\0')
				setbitn(*p, mopts);
E 52
			p = q;
		}
		else
			syserr("chompheader: syntax error, line \"%s\"", line);
I 39
		cond = TRUE;
E 39
	}

E 10
	/* find canonical name */
D 10
	fname = line;
	p = index(line, ':');
E 10
I 10
	fname = p;
	p = index(p, ':');
I 47
	if (p == NULL)
	{
		syserr("chompheader: syntax error, line \"%s\"", line);
		return (0);
	}
E 47
E 10
	fvalue = &p[1];
	while (isspace(*--p))
		continue;
	*++p = '\0';
	makelower(fname);

I 4
D 7
	/* hack, hack -- save the old From: address */
	if (!def && strcmp(fname, "from") == 0)
		fname = "original-from";

E 7
E 4
	/* strip field value on front */
	if (*fvalue == ' ')
		fvalue++;
I 7

D 27
	/* hack, hack -- save From: line specially */
D 19
	if (!def && strcmp(fname, "from") == 0)
E 19
I 19
D 26
	if (!def && !QueueRun && strcmp(fname, "from") == 0)
E 26
I 26
	if (!def && strcmp(fname, "from") == 0)
E 26
E 19
	{
D 20
		OrigFrom = newstr(fvalue);
E 20
I 20
		CurEnv->e_origfrom = newstr(fvalue);
E 20
		return (0);
	}
E 7

E 27
D 61
	/* search header list for this header */
E 61
I 61
D 64
	/* delete default value for this header */
E 61
D 20
	for (hp = &Header, h = Header; h != NULL; hp = &h->h_link, h = h->h_link)
E 20
I 20
D 43
	for (hp = &CurEnv->e_header, h = CurEnv->e_header; h != NULL; hp = &h->h_link, h = h->h_link)
E 43
I 43
	for (hp = &CurEnv->e_header, h = CurEnv->e_header; h != NULL;
		hp = &h->h_link, h = h->h_link)
E 43
E 20
	{
D 2
		if (strcmp(fname, h->h_field) == 0 && bitset(H_DEFAULT, h->h_flags))
E 2
I 2
D 14
		if (strcmp(fname, h->h_field) == 0 && bitset(H_DEFAULT, h->h_flags) &&
D 13
		    !bitset(H_FORCE, h->h_flags))
E 13
I 13
		    !(bitset(H_FORCE, h->h_flags) && !QueueRun))
E 14
I 14
D 61
		if (strcmp(fname, h->h_field) == 0 && bitset(H_DEFAULT, h->h_flags))
E 14
E 13
E 2
			break;
E 61
I 61
		if (strcmp(fname, h->h_field) == 0 &&
		    bitset(H_DEFAULT, h->h_flags) &&
		    !bitset(H_FORCE, h->h_flags))
			h->h_value = NULL;
E 61
	}

E 64
	/* see if it is a known type */
	for (hi = HdrInfo; hi->hi_field != NULL; hi++)
	{
		if (strcmp(hi->hi_field, fname) == 0)
			break;
	}

I 56
	/* see if this is a resent message */
D 58
	if (!def && bitset(H_RESENT, h->h_flags))
E 58
I 58
	if (!def && bitset(H_RESENT, hi->hi_flags))
E 58
		CurEnv->e_flags |= EF_RESENT;

E 56
	/* if this means "end of header" quit now */
	if (bitset(H_EOH, hi->hi_flags))
		return (hi->hi_flags);
D 26

I 14
	/* don't put timestamps in every queue run */
	if (QueueRun && h != NULL && bitset(H_FORCE, h->h_flags))
		return (h->h_flags);
E 26

I 56
	/* drop explicit From: if same as what we would generate -- for MH */
D 57
	if (!def && strcmp(fvalue, CurEnv->e_from.q_paddr) == 0)
E 57
I 57
D 64
	if (!def && !QueueRun && strcmp(fvalue, CurEnv->e_from.q_paddr) == 0)
E 64
I 64
	p = "resent-from";
	if (!bitset(EF_RESENT, CurEnv->e_flags))
		p += 7;
	if (!def && !QueueRun && strcmp(fname, p) == 0)
E 64
E 57
	{
I 65
D 71
		ADDRESS fromaddr;

E 71
E 65
D 64
		p = "resent-from";
		if (!bitset(EF_RESENT, CurEnv->e_flags))
			p += 7;
		if (strcmp(fname, p) == 0)
E 64
I 64
D 75
		if (strcmp(fvalue, CurEnv->e_from.q_paddr) == 0)
E 75
I 75
		if (CurEnv->e_from.q_paddr != NULL &&
		    strcmp(fvalue, CurEnv->e_from.q_paddr) == 0)
E 75
E 64
			return (hi->hi_flags);
I 64
D 65

		/* different contents -- add a Sender: field */
		addheader("sender", "$q", CurEnv);
E 65
	}

I 74
	/* drop forged Sender: values */
	p = "resent-sender";
	if (!bitset(EF_RESENT, CurEnv->e_flags))
		p += 7;
	if (!def && !QueueRun && CurEnv->e_from.q_mailer == LocalMailer &&
	    bitset(H_VALID, hi->hi_flags))
	{
		return (hi->hi_flags);
	}

E 74
	/* delete default value for this header */
	for (hp = &CurEnv->e_header; (h = *hp) != NULL; hp = &h->h_link)
	{
		if (strcmp(fname, h->h_field) == 0 &&
		    bitset(H_DEFAULT, h->h_flags) &&
		    !bitset(H_FORCE, h->h_flags))
			h->h_value = NULL;
E 64
	}

E 56
I 23
D 28
	/* count Mail-From: lines to avoid loops (simulate hop counts) */
	if (strcmp(fname, "mail-from") == 0)
E 28
I 28
D 43
	/* count Received: lines to avoid loops (simulate hop counts) */
D 34
	if (strcmp(fname, "received") == 0)
E 34
I 34
	if (bitset(H_TRACE, hi->hi_flags))
E 34
E 28
		HopCount++;

E 43
E 23
E 14
D 61
	/* create/fill in a new node */
D 14
	if (h == NULL)
E 14
I 14
	if (h == NULL || bitset(H_FORCE, h->h_flags))
E 14
	{
		/* create a new node */
D 14
		*hp = h = (HDR *) xalloc(sizeof *h);
E 14
I 14
		h = (HDR *) xalloc(sizeof *h);
E 14
		h->h_field = newstr(fname);
		h->h_value = NULL;
D 14
		h->h_link = NULL;
E 14
I 14
		h->h_link = *hp;
E 14
D 34
		h->h_flags = hi->hi_flags;
E 34
D 10
		h->h_mflags = hi->hi_mflags;
E 10
I 10
D 39
		h->h_mflags = mopts | hi->hi_mflags;
E 39
I 39
D 52
		h->h_mflags = mopts;
E 52
I 52
		bcopy(mopts, h->h_mflags, sizeof mopts);
E 52
E 39
I 14
		*hp = h;
E 14
E 10
	}
E 61
I 61
	/* create a new node */
	h = (HDR *) xalloc(sizeof *h);
	h->h_field = newstr(fname);
	h->h_value = NULL;
	h->h_link = NULL;
D 73
	bcopy(mopts, h->h_mflags, sizeof mopts);
E 73
I 73
	bcopy((char *) mopts, (char *) h->h_mflags, sizeof mopts);
E 73
	*hp = h;
E 61
I 34
	h->h_flags = hi->hi_flags;
E 34
	if (def)
		h->h_flags |= H_DEFAULT;
D 10
	else
E 10
I 10
D 39
	else if (mopts == 0)
E 10
		h->h_flags &= ~H_CHECK;
E 39
I 39
	if (cond)
		h->h_flags |= H_CHECK;
E 39
	if (h->h_value != NULL)
D 42
		free(h->h_value);
E 42
I 42
		free((char *) h->h_value);
E 42
D 27
	h->h_value = newstr(fvalue);
E 27
I 27
D 34
	if (!def && strcmp(fname, "from") == 0)
	{
		/* turn it into a macro -- will be expanded later */
D 32
		h->h_value = newstr(crackfrom(fvalue));
E 32
I 32
		h->h_value = newstr(crackaddr(fvalue));
E 32
		h->h_flags |= H_DEFAULT;
	}
	else
		h->h_value = newstr(fvalue);
E 27
I 5
D 16
D 17
	if (!def && GrabTo && bitset(H_ADDR, h->h_flags))
E 17
I 17
	if (!def && GrabTo && bitset(H_RCPT, h->h_flags))
E 17
D 8
		sendto(h->h_value, 0);
E 8
I 8
D 9
		sendto(h->h_value, 0, &From);
E 9
I 9
D 10
		sendto(h->h_value, 0, NULL);
E 10
I 10
D 11
D 12
		sendto(h->h_value, 0, (ADDRESS *) NULL);
E 12
I 12
D 20
		sendto(h->h_value, 0, (ADDRESS *) NULL, &SendQueue);
E 20
I 20
		sendto(h->h_value, 0, (ADDRESS *) NULL, &CurEnv->e_sendqueue);
E 34
I 34
	h->h_value = newstr(fvalue);
E 34
E 20
E 16
I 16
	if (!def && bitset(H_ADDR, h->h_flags))
	{
		if (GrabTo)
			sendto(h->h_value, 0, (ADDRESS *) NULL, &SendQueue);
		if (!OldStyle)
			sendto(h->h_value, 0, (ADDRESS *) NULL, &h->h_addrq);
		else
		{
			p = fvalue;
			while (*p != '\0')
			{
				fvalue = p;
				while (*p != '\0' && !isspace(*p))
					p++;
				while (isspace(*p))
					*p++ = '\0';
				sendto(fvalue, 1, (ADDRESS *) NULL, &h->h_addrq);
			}
		}
	}
E 16
E 12
E 11
I 11
		(void) sendto(h->h_value, 0, (ADDRESS *) NULL, 0);
E 11
E 10
E 9
E 8
E 5

I 18
	/* hack to see if this is a new format message */
D 36
	if (bitset(H_RCPT, h->h_flags) &&
E 36
I 36
D 37
	if (!def && bitset(H_RCPT, h->h_flags) &&
E 37
I 37
	if (!def && bitset(H_RCPT|H_FROM, h->h_flags) &&
E 37
E 36
	    (index(fvalue, ',') != NULL || index(fvalue, '(') != NULL ||
D 34
	     index(fvalue, '<') != NULL))
E 34
I 34
D 36
	     index(fvalue, '<') != NULL) || index(fvalue, ';') != NULL)
E 36
I 36
	     index(fvalue, '<') != NULL || index(fvalue, ';') != NULL))
	{
E 36
E 34
D 20
		OldStyle = FALSE;
E 20
I 20
D 41
		CurEnv->e_oldstyle = FALSE;
E 41
I 41
		CurEnv->e_flags &= ~EF_OLDSTYLE;
E 41
I 36
	}
E 36
E 20

I 34
D 56
	/* send to this person if we so desire */
	if (!def && GrabTo && bitset(H_RCPT, h->h_flags))
D 35
		sendto(h->h_value, 0, (ADDRESS *) NULL, &CurEnv->e_sendqueue);
E 35
I 35
D 44
		sendto(h->h_value, (ADDRESS *) NULL, &CurEnv->e_sendqueue);
E 44
I 44
		sendtolist(h->h_value, (ADDRESS *) NULL, &CurEnv->e_sendqueue);
E 44
E 35

E 56
E 34
E 18
	return (h->h_flags);
}
/*
I 21
**  ADDHEADER -- add a header entry to the end of the queue.
**
**	This bypasses the special checking of chompheader.
**
**	Parameters:
**		field -- the name of the header field.
**		value -- the value of the field.  It must be lower-cased.
**		e -- the envelope to add them to.
**
**	Returns:
**		none.
**
**	Side Effects:
**		adds the field on the list of headers for this envelope.
*/

addheader(field, value, e)
	char *field;
	char *value;
	ENVELOPE *e;
{
	register HDR *h;
	register struct hdrinfo *hi;
	HDR **hp;

	/* find info struct */
	for (hi = HdrInfo; hi->hi_field != NULL; hi++)
	{
		if (strcmp(field, hi->hi_field) == 0)
			break;
	}

	/* find current place in list -- keep back pointer? */
	for (hp = &e->e_header; (h = *hp) != NULL; hp = &h->h_link)
	{
		if (strcmp(field, h->h_field) == 0)
			break;
	}

	/* allocate space for new header */
	h = (HDR *) xalloc(sizeof *h);
	h->h_field = field;
	h->h_value = newstr(value);
D 24
	h->h_link = NULL;
E 24
I 24
	h->h_link = *hp;
E 24
	h->h_flags = hi->hi_flags | H_DEFAULT;
D 39
	h->h_mflags = hi->hi_mflags;
E 39
I 39
D 52
	h->h_mflags = 0;
E 52
I 52
	clrbitmap(h->h_mflags);
E 52
E 39
	*hp = h;
}
/*
E 21
**  HVALUE -- return value of a header.
**
**	Only "real" fields (i.e., ones that have not been supplied
**	as a default) are used.
**
**	Parameters:
**		field -- the field name.
**
**	Returns:
**		pointer to the value part.
**		NULL if not found.
**
**	Side Effects:
D 43
**		sets the H_USED bit in the header if found.
E 43
I 43
**		none.
E 43
*/

char *
hvalue(field)
	char *field;
{
	register HDR *h;

D 20
	for (h = Header; h != NULL; h = h->h_link)
E 20
I 20
	for (h = CurEnv->e_header; h != NULL; h = h->h_link)
E 20
	{
		if (!bitset(H_DEFAULT, h->h_flags) && strcmp(h->h_field, field) == 0)
D 43
		{
			h->h_flags |= H_USED;
E 43
			return (h->h_value);
D 43
		}
E 43
I 25
	}
	return (NULL);
}
/*
D 42
**  HRVALUE -- return pointer to header descriptor.
**
**	Like hvalue except returns header descriptor block and isn't
**	picky about "real" headers.
**
**	Parameters:
**		field -- name of field we are interested in.
**
**	Returns:
**		pointer to header descriptor.
**
**	Side Effects:
**		none.
*/

HDR *
hrvalue(field)
	char *field;
{
	register HDR *h;

	for (h = CurEnv->e_header; h != NULL; h = h->h_link)
	{
		if (strcmp(h->h_field, field) == 0)
			return (h);
E 25
	}
	return (NULL);
}
/*
E 42
**  ISHEADER -- predicate telling if argument is a header.
**
I 6
**	A line is a header if it has a single word followed by
**	optional white space followed by a colon.
**
E 6
**	Parameters:
**		s -- string to check for possible headerness.
**
**	Returns:
**		TRUE if s is a header.
**		FALSE otherwise.
**
**	Side Effects:
**		none.
I 6
D 31
**
**	Bugs:
**		According to RFC733, there should be a newline
**		permitted after the word but before the colon.
**		We don't seem to support that.....
E 31
E 6
*/

bool
isheader(s)
	register char *s;
{
D 43
	if (!isalnum(*s))
		return (FALSE);
D 31
	while (!isspace(*s) && *s != ':')
E 31
I 31
	while (!isspace(*s) && *s != ':' && *s != '\0')
E 43
I 43
	while (*s > ' ' && *s != ':' && *s != '\0')
E 43
E 31
		s++;
I 43

	/* following technically violates RFC822 */
E 43
	while (isspace(*s))
		s++;
I 43

E 43
	return (*s == ':');
I 17
}
/*
D 42
**  GETXPART -- extract the "signature" part of an address line.
**
**	Try to extract the full name from a general address
**	field.  We take anything which is a comment as a
**	first choice.  Failing in that, we see if there is
**	a "machine readable" name (in <angle brackets>); if
**	so we take anything preceeding that clause.
**
**	If we blow it here it's not all that serious.
**
**	Parameters:
**		p -- line to crack.
**
**	Returns:
**		signature part.
**		NULL if no signature part.
**
**	Side Effects:
**		none.
*/

char *
getxpart(p)
	register char *p;
{
	register char *q;
	register char *rval = NULL;

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
				rval = newstr(q);
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
			rval = newstr(p);
		*q = savec;
	}

	return (rval);
I 27
}
/*
E 42
**  EATHEADER -- run through the stored header and extract info.
**
**	Parameters:
D 43
**		none.
E 43
I 43
**		e -- the envelope to process.
E 43
**
**	Returns:
**		none.
**
**	Side Effects:
**		Sets a bunch of global variables from information
D 43
**		in the collected header.
E 43
I 43
**			in the collected header.
**		Aborts the message if the hop count is exceeded.
E 43
*/

D 43
eatheader()
E 43
I 43
eatheader(e)
	register ENVELOPE *e;
E 43
{
	register HDR *h;
	register char *p;
I 43
	int hopcnt = 0;
E 43
D 42
	char buf[MAXLINE];
E 42
I 29
D 30
	char *msgid;
E 30
E 29

D 43
# ifdef DEBUG
	if (tTd(32, 2))
E 43
I 43
#ifdef DEBUG
	if (tTd(32, 1))
		printf("----- collected header -----\n");
#endif DEBUG
	for (h = e->e_header; h != NULL; h = h->h_link)
E 43
	{
I 43
#ifdef DEBUG
E 43
		extern char *capitalize();

D 43
		printf("----- collected header -----\n");
		for (h = CurEnv->e_header; h != NULL; h = h->h_link)
E 43
I 43
		if (tTd(32, 1))
E 43
			printf("%s: %s\n", capitalize(h->h_field), h->h_value);
D 43
		printf("----------------------------\n");
E 43
I 43
#endif DEBUG
I 56
		/* count the number of times it has been processed */
E 56
		if (bitset(H_TRACE, h->h_flags))
			hopcnt++;
I 56

		/* send to this person if we so desire */
		if (GrabTo && bitset(H_RCPT, h->h_flags) &&
		    !bitset(H_DEFAULT, h->h_flags) &&
		    (!bitset(EF_RESENT, CurEnv->e_flags) || bitset(H_RESENT, h->h_flags)))
		{
			sendtolist(h->h_value, (ADDRESS *) NULL, &CurEnv->e_sendqueue);
		}

		/* log the message-id */
E 56
I 54
#ifdef LOG
D 55
		if (strcmp(h->h_field, "message-id") == 0 && LogLevel > 8)
E 55
I 55
D 62
		if (!QueueRun && LogLevel > 8 &&
E 62
I 62
		if (!QueueRun && LogLevel > 8 && h->h_value != NULL &&
E 62
		    strcmp(h->h_field, "message-id") == 0)
E 55
		{
			char buf[MAXNAME];

			p = h->h_value;
			if (bitset(H_DEFAULT, h->h_flags))
			{
				expand(p, buf, &buf[sizeof buf], e);
				p = buf;
			}
			syslog(LOG_INFO, "%s: message-id=%s", e->e_id, p);
		}
#endif LOG
E 54
E 43
	}
D 43
# endif DEBUG
E 43
I 43
#ifdef DEBUG
	if (tTd(32, 1))
		printf("----------------------------\n");
#endif DEBUG
E 43
D 30

	/* message id */
	h = hrvalue("message-id");
	if (h == NULL)
D 29
		syserr("No Message-Id spec");
E 29
I 29
		msgid = NULL;
E 29
	else if (bitset(H_DEFAULT, h->h_flags))
	{
		(void) expand(h->h_value, buf, &buf[sizeof buf - 1], CurEnv);
D 29
		MsgId = newstr(buf);
E 29
I 29
		msgid = buf;
E 29
	}
	else
D 29
		MsgId = h->h_value;
E 29
I 29
		msgid = h->h_value;
	if (msgid != NULL)
	{
E 29
# ifdef DEBUG
D 29
	if (tTd(32, 1))
		printf("Message-Id: %s\n", MsgId);
E 29
I 29
		if (tTd(32, 1))
			printf("Message-Id: %s\n", msgid);
E 29
# endif DEBUG
I 29
# ifdef LOG
		if (LogLevel > 1)
			syslog(LOG_INFO, "%s: messageid=%s", CurEnv->e_id, msgid);
# endif LOG
	}
E 30
E 29

I 43
	/* store hop count */
	if (hopcnt > e->e_hopcount)
		e->e_hopcount = hopcnt;

E 43
	/* message priority */
I 43
	p = hvalue("precedence");
	if (p != NULL)
		e->e_class = priencode(p);
E 43
	if (!QueueRun)
D 43
	{
		/* adjust total priority by message priority */
		CurEnv->e_msgpriority = CurEnv->e_msgsize;
D 34
		p = hvalue("priority");
E 34
I 34
		p = hvalue("precedence");
E 34
		if (p != NULL)
			CurEnv->e_class = priencode(p);
D 38
		else
			CurEnv->e_class = PRI_NORMAL;
E 38
		CurEnv->e_msgpriority -= CurEnv->e_class * WKPRIFACT;
	}
E 43
I 43
D 69
		e->e_msgpriority = e->e_msgsize - e->e_class * WKPRIFACT;
E 69
I 69
D 75
		e->e_msgpriority = e->e_msgsize + e->e_ctime - e->e_class * WKPRIFACT;
E 75
I 75
D 77
		e->e_msgpriority = e->e_msgsize + e->e_ctime
E 77
I 77
		e->e_msgpriority = e->e_msgsize
E 77
D 76
				 - e->e_class * WKPRIFACT
				 + e->e_nrcpts * WKRECIPFACT;
E 76
I 76
				 - e->e_class * WkClassFact
				 + e->e_nrcpts * WkRecipFact;
E 76
E 75
E 69
E 43

D 34
	/* special handling */
	p = hvalue("special-handling");
E 34
I 34
	/* return receipt to */
	p = hvalue("return-receipt-to");
E 34
	if (p != NULL)
D 34
		spechandling(p);
E 34
I 34
D 43
		CurEnv->e_receiptto = p;
E 43
I 43
		e->e_receiptto = p;
E 43
E 34

I 38
	/* errors to */
	p = hvalue("errors-to");
	if (p != NULL)
D 43
		sendto(p, (ADDRESS *) NULL, &CurEnv->e_errorqueue);
E 43
I 43
D 44
		sendto(p, (ADDRESS *) NULL, &e->e_errorqueue);
E 44
I 44
		sendtolist(p, (ADDRESS *) NULL, &e->e_errorqueue);
E 44
E 43

E 38
	/* from person */
D 34
	p = hvalue("sender");
	if (p == NULL)
		p = CurEnv->e_origfrom;
E 34
D 40
	if (ArpaMode)
E 40
I 40
	if (OpMode == MD_ARPAFTP)
E 40
D 34
		setfrom(p, (char *) NULL);
E 34
I 34
	{
		register struct hdrinfo *hi = HdrInfo;
E 34

I 34
		for (p = NULL; p == NULL && hi->hi_field != NULL; hi++)
		{
			if (bitset(H_FROM, hi->hi_flags))
				p = hvalue(hi->hi_field);
		}
		if (p != NULL)
D 43
			setfrom(p, (char *) NULL);
E 43
I 43
			setsender(p);
E 43
	}

E 34
	/* full name of from person */
	p = hvalue("full-name");
	if (p != NULL)
D 43
		define('x', p);
E 43
I 43
		define('x', p, e);
E 43

	/* date message originated */
	p = hvalue("posted-date");
	if (p == NULL)
		p = hvalue("date");
	if (p != NULL)
	{
D 43
		define('a', p);
E 43
I 43
		define('a', p, e);
E 43
		/* we don't have a good way to do canonical conversion ....
D 43
		define('d', newstr(arpatounix(p)));
E 43
I 43
		define('d', newstr(arpatounix(p)), e);
E 43
		.... so we will ignore the problem for the time being */
	}
I 54

	/*
	**  Log collection information.
	*/

# ifdef LOG
D 55
	if (LogLevel > 1)
E 55
I 55
	if (!QueueRun && LogLevel > 1)
E 55
	{
		syslog(LOG_INFO, "%s: from=%s, size=%ld, class=%d\n",
		       CurEnv->e_id, CurEnv->e_from.q_paddr, CurEnv->e_msgsize,
		       CurEnv->e_class);
	}
# endif LOG
E 54
}
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

D 38
struct prio
{
	char	*pri_name;	/* external name of priority */
	int	pri_val;	/* internal value for same */
};

static struct prio	Prio[] =
{
	"alert",		PRI_ALERT,
	"quick",		PRI_QUICK,
	"first-class",		PRI_FIRSTCL,
	"normal",		PRI_NORMAL,
	"second-class",		PRI_SECONDCL,
	"third-class",		PRI_THIRDCL,
	"junk",			PRI_JUNK,
	NULL,			PRI_NORMAL,
};

E 38
priencode(p)
	char *p;
{
D 38
	register struct prio *pl;
E 38
I 38
	register int i;
E 38
D 78
	extern bool sameword();
E 78

D 38
	for (pl = Prio; pl->pri_name != NULL; pl++)
E 38
I 38
	for (i = 0; i < NumPriorities; i++)
E 38
	{
D 38
		if (sameword(p, pl->pri_name))
			break;
E 38
I 38
D 78
		if (sameword(p, Priorities[i].pri_name))
E 78
I 78
		if (!strcasecmp(p, Priorities[i].pri_name))
E 78
			return (Priorities[i].pri_val);
E 38
	}
D 38
	return (pl->pri_val);
E 38
I 38

	/* unknown priority */
	return (0);
E 38
D 34
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
			CurEnv->e_retreceipt = TRUE;
# ifdef DEBUG
			if (tTd(30, 3))
				printf(">>> Return receipt requested\n");
# endif DEBUG
			break;

		  default:
			syserr("spechandling: handling %d (%s)", h->han_what, w);
		}
	}
E 34
}
/*
D 32
**  CRACKFROM -- parse the from line and turn it into a macro
E 32
I 32
**  CRACKADDR -- parse an address and turn it into a macro
E 32
**
**	This doesn't actually parse the address -- it just extracts
**	it and replaces it with "$g".  The parse is totally ad hoc
**	and isn't even guaranteed to leave something syntactically
**	identical to what it started with.  However, it does leave
**	something semantically identical.
**
**	The process is kind of strange.  There are a number of
**	interesting cases:
**		1.  comment <address> comment	==> comment <$g> comment
**		2.  address			==> address
**		3.  address (comment)		==> $g (comment)
**		4.  (comment) address		==> (comment) $g
**	And then there are the hard cases....
**		5.  add (comment) ress		==> $g (comment)
**		6.  comment <address (comment)>	==> comment <$g (comment)>
**		7.    .... etc ....
**
**	Parameters:
D 32
**		from -- the value part of the from line.
E 32
I 32
**		addr -- the address to be cracked.
E 32
**
**	Returns:
**		a pointer to the new version.
**
**	Side Effects:
D 32
**		The $f and $x macros may be defined.
E 32
I 32
**		none.
E 32
**
**	Warning:
**		The return value is saved in local storage and should
**		be copied if it is to be reused.
*/

char *
D 32
crackfrom(from)
	register char *from;
E 32
I 32
crackaddr(addr)
	register char *addr;
E 32
{
	register char *p;
	register int i;
	static char buf[MAXNAME];
	char *rhs;
	bool gotaddr;
	register char *bp;

# ifdef DEBUG
	if (tTd(33, 1))
D 32
		printf("crackfrom(%s)\n", from);
E 32
I 32
		printf("crackaddr(%s)\n", addr);
E 32
# endif DEBUG

D 72
	strcpy(buf, "");
E 72
I 72
	(void) strcpy(buf, "");
E 72
	rhs = NULL;

I 35
	/* strip leading spaces */
	while (*addr != '\0' && isspace(*addr))
		addr++;

E 35
	/*
	**  See if we have anything in angle brackets.  If so, that is
	**  the address part, and the rest is the comment.
	*/

D 32
	p = index(from, '<');
E 32
I 32
	p = index(addr, '<');
E 32
	if (p != NULL)
	{
D 32
		/* copy the beginning of the from field to the buffer */
E 32
I 32
		/* copy the beginning of the addr field to the buffer */
E 32
		*p = '\0';
D 32
		strcpy(buf, from);
E 32
I 32
D 72
		strcpy(buf, addr);
E 32
		strcat(buf, "<");
E 72
I 72
		(void) strcpy(buf, addr);
		(void) strcat(buf, "<");
E 72
D 35
		*p = '<';
E 35
I 35
		*p++ = '<';
E 35

I 35
		/* skip spaces */
		while (isspace(*p))
			p++;

E 35
		/* find the matching right angle bracket */
D 32
		from = ++p;
E 32
I 32
D 35
		addr = ++p;
E 35
I 35
		addr = p;
E 35
E 32
		for (i = 0; *p != '\0'; p++)
		{
			switch (*p)
			{
			  case '<':
				i++;
				break;

			  case '>':
				i--;
				break;
			}
			if (i < 0)
				break;
		}

		/* p now points to the closing quote (or a null byte) */
		if (*p != '\0')
		{
			/* make rhs point to the extra stuff at the end */
			rhs = p;
			*p++ = '\0';
		}
	}

	/*
D 33
	**  Now parse the real address part.  from points to the (null
E 33
I 33
	**  Now parse the real address part.  "addr" points to the (null
E 33
	**  terminated) version of what we are inerested in; rhs points
	**  to the extra stuff at the end of the line, if any.
	*/

D 32
	p = from;
E 32
I 32
	p = addr;
E 32

	/* now strip out comments */
	bp = &buf[strlen(buf)];
	gotaddr = FALSE;
	for (; *p != '\0'; p++)
	{
		if (*p == '(')
		{
			/* copy to matching close paren */
			*bp++ = *p++;
			for (i = 0; *p != '\0'; p++)
			{
				*bp++ = *p;
				switch (*p)
				{
				  case '(':
					i++;
					break;

				  case ')':
					i--;
					break;
				}
				if (i < 0)
					break;
			}
			continue;
		}

		/*
		**  If this is the first "real" character we have seen,
		**  then we put the "$g" in the buffer now.
		*/

		if (isspace(*p))
			*bp++ = *p;
		else if (!gotaddr)
		{
D 66
			strcpy(bp, "$g");
E 66
I 66
D 72
			strcpy(bp, "\001g");
E 72
I 72
			(void) strcpy(bp, "\001g");
E 72
E 66
			bp += 2;
			gotaddr = TRUE;
		}
	}

D 33
	/*
	**  If there is a tag at the end, insert it.
	*/
E 33
I 33
	/* hack, hack.... strip trailing blanks */
	do
	{
		*bp-- = '\0';
	} while (isspace(*bp));
	bp++;
E 33

D 33
	*bp = '\0';
E 33
I 33
	/* put any right hand side back on */
E 33
	if (rhs != NULL)
	{
		*rhs = '>';
D 72
		strcpy(bp, rhs);
E 72
I 72
		(void) strcpy(bp, rhs);
E 72
	}

# ifdef DEBUG
	if (tTd(33, 1))
D 32
		printf("crackfrom=>%s\n", buf);
E 32
I 32
D 33
		printf("crackaddr=>%s\n", buf);
E 33
I 33
		printf("crackaddr=>`%s'\n", buf);
E 33
E 32
# endif DEBUG

	return (buf);
I 43
}
/*
**  PUTHEADER -- put the header part of a message from the in-core copy
**
**	Parameters:
**		fp -- file to put it on.
**		m -- mailer to use.
**		e -- envelope to use.
I 45
D 49
**		crlf -- if set, output CRLF on the end of lines.
E 49
E 45
**
**	Returns:
**		none.
**
**	Side Effects:
**		none.
*/

D 45
putheader(fp, m, e)
E 45
I 45
D 49
putheader(fp, m, e, crlf)
E 49
I 49
putheader(fp, m, e)
E 49
E 45
	register FILE *fp;
	register MAILER *m;
	register ENVELOPE *e;
{
	char buf[BUFSIZ];
	register HDR *h;
	extern char *arpadate();
	extern char *capitalize();
	char obuf[MAXLINE];
D 49
	bool fullsmtp = bitset(M_FULLSMTP, m->m_flags);
E 49

	for (h = e->e_header; h != NULL; h = h->h_link)
	{
		register char *p;
I 52
		extern bool bitintersect();
E 52

		if (bitset(H_CHECK|H_ACHECK, h->h_flags) &&
D 52
		    !bitset(h->h_mflags, m->m_flags))
E 52
I 52
		    !bitintersect(h->h_mflags, m->m_flags))
I 56
			continue;

		/* handle Resent-... headers specially */
		if (bitset(H_RESENT, h->h_flags) && !bitset(EF_RESENT, e->e_flags))
E 56
E 52
			continue;

		p = h->h_value;
		if (bitset(H_DEFAULT, h->h_flags))
		{
			/* macro expand value if generated internally */
			expand(p, buf, &buf[sizeof buf], e);
			p = buf;
			if (p == NULL || *p == '\0')
				continue;
		}

		if (bitset(H_FROM|H_RCPT, h->h_flags))
		{
			/* address field */
			bool oldstyle = bitset(EF_OLDSTYLE, e->e_flags);

			if (bitset(H_FROM, h->h_flags))
				oldstyle = FALSE;
D 45
			commaize(h, p, fp, oldstyle, m);
E 45
I 45
D 49
			commaize(h, p, fp, oldstyle, m, crlf);
E 49
I 49
			commaize(h, p, fp, oldstyle, m);
E 49
E 45
		}
		else
		{
			/* vanilla header line */
D 59
			(void) sprintf(obuf, "%s: %s\n", capitalize(h->h_field), p);
E 59
I 59
			register char *nlp;

			(void) sprintf(obuf, "%s: ", capitalize(h->h_field));
			while ((nlp = index(p, '\n')) != NULL)
			{
				*nlp = '\0';
				(void) strcat(obuf, p);
				*nlp = '\n';
				putline(obuf, fp, m);
				p = ++nlp;
D 60
				(void) strcpy(obuf, "\t");
E 60
I 60
				obuf[0] = '\0';
E 60
			}
			(void) strcat(obuf, p);
E 59
D 45
			putline(obuf, fp, fullsmtp);
E 45
I 45
D 49
			putline(obuf, fp, crlf, fullsmtp);
E 49
I 49
			putline(obuf, fp, m);
E 49
E 45
		}
	}
}
/*
**  COMMAIZE -- output a header field, making a comma-translated list.
**
**	Parameters:
**		h -- the header field to output.
**		p -- the value to put in it.
**		fp -- file to put it to.
**		oldstyle -- TRUE if this is an old style header.
**		m -- a pointer to the mailer descriptor.  If NULL,
**			don't transform the name at all.
I 45
D 49
**		crlf -- set if we want CRLF's on the end of lines.
E 49
E 45
**
**	Returns:
**		none.
**
**	Side Effects:
**		outputs "p" to file "fp".
*/

D 45
commaize(h, p, fp, oldstyle, m)
E 45
I 45
D 49
commaize(h, p, fp, oldstyle, m, crlf)
E 49
I 49
commaize(h, p, fp, oldstyle, m)
E 49
E 45
	register HDR *h;
	register char *p;
	FILE *fp;
	bool oldstyle;
	register MAILER *m;
I 45
D 49
	bool crlf;
E 49
E 45
{
	register char *obp;
	int opos;
D 49
	bool fullsmtp = FALSE;
E 49
	bool firstone = TRUE;
D 53
	char obuf[MAXLINE];
E 53
I 53
	char obuf[MAXLINE + 3];
E 53

	/*
	**  Output the address list translated by the
	**  mailer and with commas.
	*/

# ifdef DEBUG
	if (tTd(14, 2))
		printf("commaize(%s: %s)\n", h->h_field, p);
# endif DEBUG

D 49
	if (m != NULL && bitset(M_FULLSMTP, m->m_flags))
		fullsmtp = TRUE;

E 49
	obp = obuf;
	(void) sprintf(obp, "%s: ", capitalize(h->h_field));
	opos = strlen(h->h_field) + 2;
	obp += opos;

	/*
	**  Run through the list of values.
	*/

	while (*p != '\0')
	{
		register char *name;
		char savechar;
		extern char *remotename();
		extern char *DelimChar;		/* defined in prescan */

		/*
		**  Find the end of the name.  New style names
		**  end with a comma, old style names end with
		**  a space character.  However, spaces do not
		**  necessarily delimit an old-style name -- at
		**  signs mean keep going.
		*/

		/* find end of name */
		while (isspace(*p) || *p == ',')
			p++;
		name = p;
		for (;;)
		{
			char *oldp;
I 68
			char pvpbuf[PSBUFSIZE];
E 68
			extern bool isatword();
			extern char **prescan();

D 68
			(void) prescan(p, oldstyle ? ' ' : ',');
E 68
I 68
			(void) prescan(p, oldstyle ? ' ' : ',', pvpbuf);
E 68
			p = DelimChar;

			/* look to see if we have an at sign */
			oldp = p;
			while (*p != '\0' && isspace(*p))
				p++;

			if (*p != '@' && !isatword(p))
			{
				p = oldp;
				break;
			}
			p += *p == '@' ? 1 : 2;
			while (*p != '\0' && isspace(*p))
				p++;
		}
		/* at the end of one complete name */

		/* strip off trailing white space */
		while (p >= name && (isspace(*p) || *p == ',' || *p == '\0'))
			p--;
		if (++p == name)
			continue;
		savechar = *p;
		*p = '\0';

		/* translate the name to be relative */
D 49
		if (m != NULL)
			name = remotename(name, m, bitset(H_FROM, h->h_flags));
E 49
I 49
D 51
		name = remotename(name, m, bitset(H_FROM, h->h_flags));
E 51
I 51
		name = remotename(name, m, bitset(H_FROM, h->h_flags), FALSE);
E 51
E 49
		if (*name == '\0')
		{
			*p = savechar;
			continue;
		}

		/* output the name with nice formatting */
		opos += qstrlen(name);
		if (!firstone)
			opos += 2;
		if (opos > 78 && !firstone)
		{
I 48
D 49
			*obp = '\0';
			putline(obuf, fp, crlf, fullsmtp);
E 48
D 45
			(void) sprintf(obp, ",\n");
			putline(obuf, fp, fullsmtp);
E 45
I 45
D 46
			fputc(',', obp);
E 46
I 46
			fputc(',', fp);
E 46
			if (crlf)
D 46
				fputc('\r', obp);
			fputc('\n', obp);
E 46
I 46
				fputc('\r', fp);
			fputc('\n', fp);
E 49
I 49
D 50
			(void) strcat(obp, ",\n");
E 50
I 50
			(void) strcpy(obp, ",\n");
E 50
			putline(obuf, fp, m);
E 49
E 46
D 48
			putline(obuf, fp, crlf, fullsmtp);
E 48
E 45
			obp = obuf;
			(void) sprintf(obp, "        ");
D 48
			obp += strlen(obp);
			opos = 8 + strlen(name);
E 48
I 48
			opos = strlen(obp);
			obp += opos;
			opos += qstrlen(name);
E 48
		}
		else if (!firstone)
		{
			(void) sprintf(obp, ", ");
			obp += 2;
		}

		/* strip off quote bits as we output */
D 53
		while (*name != '\0')
E 53
I 53
		while (*name != '\0' && obp < &obuf[MAXLINE])
E 53
		{
			if (bitset(0200, *name))
				*obp++ = '\\';
			*obp++ = *name++ & ~0200;
		}
		firstone = FALSE;
		*p = savechar;
	}
	(void) strcpy(obp, "\n");
D 45
	putline(obuf, fp, fullsmtp);
E 45
I 45
D 49
	putline(obuf, fp, crlf, fullsmtp);
E 49
I 49
	putline(obuf, fp, m);
E 49
E 45
}
/*
**  ISATWORD -- tell if the word we are pointing to is "at".
**
**	Parameters:
**		p -- word to check.
**
**	Returns:
**		TRUE -- if p is the word at.
**		FALSE -- otherwise.
**
**	Side Effects:
**		none.
*/

bool
isatword(p)
	register char *p;
{
	extern char lower();

	if (lower(p[0]) == 'a' && lower(p[1]) == 't' &&
	    p[2] != '\0' && isspace(p[2]))
		return (TRUE);
	return (FALSE);
E 43
E 27
E 17
}
E 1
