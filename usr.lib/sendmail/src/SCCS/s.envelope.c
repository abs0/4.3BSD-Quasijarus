h36100
s 00002/00000/00597
d D 5.17 00/04/03 09:51:36 msokolov 44 43
c Check the sender address for a null string and change it to "<>" if it is,
c as we can't handle null strings very well.
e
s 00002/00002/00595
d D 5.16 99/12/31 06:34:16 msokolov 43 42
c Y2K
e
s 00011/00009/00586
d D 5.15 88/06/30 14:58:53 bostic 42 41
c install approved copyright notice
e
s 00000/00002/00595
d D 5.14 88/04/01 16:50:46 bostic 41 40
c remove V6 #ifdefs
e
s 00016/00010/00581
d D 5.13 88/03/13 19:52:01 bostic 40 39
c add Berkeley specific header
e
s 00015/00007/00576
d D 5.12 85/12/17 21:34:48 eric 39 38
m 
c patch to clearenvelope to avoid dereferencing garbage pointers
e
s 00014/00013/00569
d D 5.11 85/11/21 18:48:49 eric 38 37
m 
c don't duplicate original envelope into error envelope
e
s 00001/00000/00581
d D 5.10 85/09/25 11:02:16 eric 37 36
m 
c DO use Ruleset 4 when defining $f -- it's very necessary (fix for <>
c will have to be done in configuration); pretty up mailq -v slightly
e
s 00000/00001/00581
d D 5.9 85/09/23 21:19:10 eric 36 35
m 
c deliver directly in SMTP if VERB command has been issued; don't
c externalize name using ruleset 4 when defining $f macro: this turns "<>"
c into "", which confuses local mail
e
s 00001/00001/00581
d D 5.8 85/09/21 16:24:10 eric 35 34
m 
c don't include ctime as part of priority, since the value affects the results of
c shouldqueue; we go back to adding ctime into the workcmpf in queue.c
e
s 00001/00000/00581
d D 5.7 85/09/21 14:44:33 eric 34 33
m 
c clean up priority handling, making several of the parameters configurable:
c y - WkRecipFact, z - WkClassFact, Z - WkTimeFact, Y - ForkQueueRuns; improve
c process title labelling; finish "errors to postmaster" option
e
s 00001/00001/00580
d D 5.6 85/09/19 17:43:23 eric 33 32
m 
c fix botch in clearenvelope
e
s 00002/00006/00579
d D 5.5 85/09/19 15:57:51 eric 32 31
m 
c updates to make it possible to run the queue in one process; this
c permits a database of host status to be built
e
s 00000/00000/00585
d D 5.4 85/09/19 01:25:49 eric 31 29
i 30
m 
c incorporate SMI changes -- still experimental
e
s 00018/00007/00567
d D 5.3.1.1 85/09/19 00:56:08 eric 30 29
m 
c SMI changes (somewhat)
e
s 00002/00002/00572
d D 5.3 85/06/15 18:52:01 eric 29 28
m 
c fix overzealous removal of df file
e
s 00002/00002/00572
d D 5.2 85/06/07 22:26:48 miriam 28 27
m 
c Resolve duplicate SccsId.  Ifdef variables for TTYNAME code.
e
s 00014/00000/00560
d D 5.1 85/06/07 15:04:37 dist 27 26
m 
c Add copyright
e
s 00008/00002/00552
d D 4.10 85/06/01 15:26:26 eric 26 25
m 
c More changes from Bill Nowicki -- file closing and improved logging.
e
s 00004/00005/00550
d D 4.9 85/04/20 15:14:02 eric 25 24
m 
c don't assume that all apparently local senders have passwd entries
e
s 00008/00175/00547
d D 4.8 84/12/05 23:15:29 eric 24 23
m 
c Try to use flock call (this doesn't work because we don't always have an
c open fd); security and performance fixes from Kirk Smith at Purdue; "a"
c option is now the number of minutes to wait for "@:@" alias; fix bug in
c $[ $] using -t; random cleanup
e
s 00002/00001/00720
d D 4.7 84/08/11 23:19:57 eric 23 22
m 
c Add $[ and $] as RHS operators to look up the contents and pass them
c to maphostname; maphostname currently looks them up in /etc/hosts and
c converts them to canonical form, but could be turned into a general
c name server.....   huzzah!!
e
s 00003/00003/00718
d D 4.6 84/08/11 16:55:15 eric 22 21
m 
c Changes from Greg Couch <ucsfcgl!gregc> for V7 compatibility and
c miscellaneous bug fixes; "clear" => "bzero" and "bmove" => "bcopy"
c throughout for consistency; bzero is now in bcopy.c (these are
c supplied by libc on 4.2bsd)
e
s 00001/00006/00720
d D 4.5 84/05/13 15:45:25 eric 21 20
m 
c remove .mailcf hack -- it's been abused.
e
s 00001/00000/00725
d D 4.4 84/03/11 19:58:35 eric 20 19
m 
c disable UPPER->lower case mapping in RHS's of aliases so that upper
c case letters can be used in file names and as args to programs.
e
s 00001/00001/00724
d D 4.3 84/03/11 16:55:30 eric 19 18
m 
c change macro expansion character from $ to \001 so that $'s can be
c used in headers -- the .cf file is unchanged by mapping $ to \001.
c \001 is now a manifest constant.
e
s 00001/00001/00724
d D 4.2 83/08/21 15:13:37 eric 18 17
m 
c Don't print out a null pointer in debugging info.
e
s 00000/00000/00725
d D 4.1 83/07/25 19:46:40 eric 17 16
m 
c 4.2 release version
e
s 00001/00001/00724
d D 3.16 83/07/01 23:04:54 wnj 16 15
m 
c 
e
s 00040/00020/00685
d D 3.15 83/04/17 17:13:17 eric 15 14
m 199
m 224
c put true current time on SMTP greeting message; fix *(0) problems
e
s 00012/00005/00693
d D 3.14 83/03/19 14:24:53 eric 14 13
m 211
c Don't have mail from su'ed people come from "daemon"
e
s 00002/00000/00696
d D 3.13 83/03/19 13:14:17 eric 13 12
m 147
c Fix botch of putting incorrect full names on some addresses (usually
c UNIX-to-UNIX Copy)
e
s 00002/00002/00694
d D 3.12 83/03/08 19:22:27 eric 12 11
m 205
c Pass the delimiter character to parseaddr so that we can correctly
c decide between comma and space
e
s 00001/00000/00695
d D 3.11 83/02/25 21:20:12 eric 11 10
m 181
c More attempts at insuring that everything goes through ruleset 4
e
s 00001/00001/00694
d D 3.10 83/02/10 10:00:26 eric 10 9
m 176
c avoid core dump on return receipt processing; clean up return receipt
c message.
e
s 00014/00001/00681
d D 3.9 83/02/08 10:49:32 eric 9 8
m 167
m 172
m 173
m 174
c clean up problems when QUEUE compile flag not defined; clean up hostname
c code to run on non-4.1c systems; fix use of -oeq (quiet on errors) flag.
e
s 00001/00004/00681
d D 3.8 83/02/03 10:30:02 eric 8 7
m 160
c $e macro is now SMTP entry message (so that configuration version can
c be included).
e
s 00001/00001/00684
d D 3.7 83/02/02 12:54:55 eric 7 6
m 165
c implement classes and mailer flags as a bit map; define new class 'w'
c as the set of all hosts we are known by
e
s 00035/00003/00650
d D 3.6 83/01/08 13:48:45 eric 6 5
m 
c be sure to open a new transcript on every queue run; when returning
c an SMTP transcript, only send the last half (i.e., that part which
c describes the sending half).
e
s 00001/00008/00652
d D 3.5 83/01/03 13:02:01 eric 5 4
m 
c process timeouts like normal errors, so that they will get delivered to
c the correct address (i.e., the Errors-To: address)
e
s 00002/00002/00658
d D 3.4 82/12/24 08:15:15 eric 4 3
m 108
c Change parse to parseaddr for BB&N TCP/IP implementation; clean up
c comments in daemon.c to simplify the poor alternate protocol type.
e
s 00001/00001/00659
d D 3.3 82/12/13 18:26:43 eric 3 2
m 085
c The routine "sendto" is now a system call (yeuch!); change our sendto
c to "sendtolist"
e
s 00002/00001/00658
d D 3.2 82/12/09 11:15:37 eric 2 1
m 103
c avoid putting in a full name in network forward operations
e
s 00659/00000/00000
d D 3.1 82/12/05 13:42:10 eric 1 0
m 092
c date and time created 82/12/05 13:42:10 by eric
e
u
U
f b 
f i 
t
T
I 27
/*
I 42
 * Copyright (c) 1983 Eric P. Allman
E 42
D 40
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 40
I 40
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 42
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 42
I 42
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
E 42
 */
E 40

#ifndef lint
D 40
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint
E 40
I 40
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 40

E 27
I 1
#include <pwd.h>
D 16
#include <time.h>
E 16
I 16
#include <sys/time.h>
E 16
#include "sendmail.h"
#include <sys/stat.h>

D 28
SCCSID(%W%	%Y%	%G%);

E 28
/*
**  NEWENVELOPE -- allocate a new envelope
**
**	Supports inheritance.
**
**	Parameters:
**		e -- the new envelope to fill in.
**
**	Returns:
**		e.
**
**	Side Effects:
**		none.
*/

ENVELOPE *
newenvelope(e)
	register ENVELOPE *e;
{
D 38
	register HDR *bh;
	register HDR **nhp;
E 38
	register ENVELOPE *parent;
	extern putheader(), putbody();
I 39
	extern ENVELOPE BlankEnvelope;
E 39
D 38
	extern ENVELOPE BlankEnvelope;
E 38

	parent = CurEnv;
	if (e == CurEnv)
		parent = e->e_parent;
D 22
	clear((char *) e, sizeof *e);
	bmove((char *) &CurEnv->e_from, (char *) &e->e_from, sizeof e->e_from);
E 22
I 22
D 38
	bzero((char *) e, sizeof *e);
E 38
I 38
D 39
	clearenvelope(e);
E 39
I 39
	clearenvelope(e, TRUE);
E 39
E 38
D 30
	bcopy((char *) &CurEnv->e_from, (char *) &e->e_from, sizeof e->e_from);
E 30
I 30
	if (e == CurEnv)
		bcopy((char *) &NullAddress, (char *) &e->e_from, sizeof e->e_from);
	else
		bcopy((char *) &CurEnv->e_from, (char *) &e->e_from, sizeof e->e_from);
E 30
E 22
	e->e_parent = parent;
	e->e_ctime = curtime();
I 34
D 35
	e->e_msgpriority = parent->e_msgsize + e->e_ctime;
E 35
I 35
	e->e_msgpriority = parent->e_msgsize;
E 35
E 34
	e->e_puthdr = putheader;
	e->e_putbody = putbody;
D 38
	bh = BlankEnvelope.e_header;
	nhp = &e->e_header;
	while (bh != NULL)
	{
		*nhp = (HDR *) xalloc(sizeof *bh);
D 22
		bmove((char *) bh, (char *) *nhp, sizeof *bh);
E 22
I 22
		bcopy((char *) bh, (char *) *nhp, sizeof *bh);
E 22
		bh = bh->h_link;
		nhp = &(*nhp)->h_link;
	}
E 38
	if (CurEnv->e_xfp != NULL)
		(void) fflush(CurEnv->e_xfp);

	return (e);
}
/*
**  DROPENVELOPE -- deallocate an envelope.
**
**	Parameters:
**		e -- the envelope to deallocate.
**
**	Returns:
**		none.
**
**	Side Effects:
**		housekeeping necessary to dispose of an envelope.
**		Unlocks this queue file.
*/

dropenvelope(e)
	register ENVELOPE *e;
{
	bool queueit = FALSE;
	register ADDRESS *q;

#ifdef DEBUG
	if (tTd(50, 1))
	{
		printf("dropenvelope %x id=", e);
		xputs(e->e_id);
		printf(" flags=%o\n", e->e_flags);
	}
#endif DEBUG
#ifdef LOG
	if (LogLevel > 10)
		syslog(LOG_DEBUG, "dropenvelope, id=%s, flags=%o, pid=%d",
				  e->e_id == NULL ? "(none)" : e->e_id,
				  e->e_flags, getpid());
#endif LOG

	/* we must have an id to remove disk files */
	if (e->e_id == NULL)
		return;

	/*
	**  Extract state information from dregs of send list.
	*/

	for (q = e->e_sendqueue; q != NULL; q = q->q_next)
	{
		if (bitset(QQUEUEUP, q->q_flags))
			queueit = TRUE;
	}

	/*
	**  Send back return receipts as requested.
	*/

	if (e->e_receiptto != NULL && bitset(EF_SENDRECEIPT, e->e_flags))
	{
D 10
		auto ADDRESS *rlist;
E 10
I 10
		auto ADDRESS *rlist = NULL;
E 10

D 3
		sendto(CurEnv->e_receiptto, (ADDRESS *) NULL, &rlist);
E 3
I 3
		sendtolist(CurEnv->e_receiptto, (ADDRESS *) NULL, &rlist);
E 3
		(void) returntosender("Return receipt", rlist, FALSE);
	}

	/*
D 5
	**  See if this message has timed out
	*/

	if (bitset(EF_TIMEOUT, e->e_flags) && queueit)
		timeout(e);

	/*
E 5
	**  Arrange to send error messages if there are fatal errors.
	*/

D 5
	if (bitset(EF_FATALERRS, e->e_flags))
E 5
I 5
D 9
	if (bitset(EF_FATALERRS|EF_TIMEOUT, e->e_flags))
E 9
I 9
	if (bitset(EF_FATALERRS|EF_TIMEOUT, e->e_flags) && ErrorMode != EM_QUIET)
E 9
E 5
		savemail(e);

	/*
	**  Instantiate or deinstantiate the queue.
	*/

	if ((!queueit && !bitset(EF_KEEPQUEUE, e->e_flags)) ||
	    bitset(EF_CLRQUEUE, e->e_flags))
	{
D 30
		if (e->e_dfp != NULL)
			(void) fclose(e->e_dfp);
E 30
I 29
		if (e->e_df != NULL)
			xunlink(e->e_df);
E 29
D 26
		if (e->e_df != NULL)
			xunlink(e->e_df);
E 26
		xunlink(queuename(e, 'q'));
	}
	else if (queueit || !bitset(EF_INQUEUE, e->e_flags))
I 9
	{
#ifdef QUEUE
E 9
		queueup(e, FALSE, FALSE);
I 9
#else QUEUE
		syserr("dropenvelope: queueup");
#endif QUEUE
	}
E 9

	/* now unlock the job */
D 6
	if (e->e_xfp != NULL)
		(void) fclose(e->e_xfp);
E 6
I 6
	closexscript(e);
E 6
	unlockqueue(e);

	/* make sure that this envelope is marked unused */
I 26
D 29
	if (e->e_df != NULL)
		xunlink(e->e_df);
E 29
E 26
	e->e_id = e->e_df = NULL;
I 30
	if (e->e_dfp != NULL)
		(void) fclose(e->e_dfp);
E 30
D 6
	e->e_dfp = e->e_xfp = NULL;
E 6
I 6
	e->e_dfp = NULL;
E 6
}
/*
**  CLEARENVELOPE -- clear an envelope without unlocking
**
**	This is normally used by a child process to get a clean
**	envelope without disturbing the parent.
**
**	Parameters:
**		e -- the envelope to clear.
I 39
**		fullclear - if set, the current envelope is total
**			garbage and should be ignored; otherwise,
**			release any resources it may indicate.
E 39
**
**	Returns:
**		none.
**
**	Side Effects:
**		Closes files associated with the envelope.
**		Marks the envelope as unallocated.
*/

D 39
clearenvelope(e)
E 39
I 39
clearenvelope(e, fullclear)
E 39
	register ENVELOPE *e;
I 39
	bool fullclear;
E 39
{
I 38
	register HDR *bh;
	register HDR **nhp;
	extern ENVELOPE BlankEnvelope;

E 38
D 39
	/* clear out any file information */
	if (e->e_xfp != NULL)
		(void) fclose(e->e_xfp);
	if (e->e_dfp != NULL)
		(void) fclose(e->e_dfp);
E 39
I 39
	if (!fullclear)
	{
		/* clear out any file information */
		if (e->e_xfp != NULL)
			(void) fclose(e->e_xfp);
		if (e->e_dfp != NULL)
			(void) fclose(e->e_dfp);
	}
E 39
D 32
	e->e_xfp = e->e_dfp = NULL;
E 32

D 32
	/* now expunge names of objects */
	e->e_df = e->e_id = NULL;

	/* and the flags which are now meaningless */
	e->e_flags = 0;
E 32
I 32
	/* now clear out the data */
D 33
	bzero((char *) e, sizeof *e);
E 33
I 33
	STRUCTCOPY(BlankEnvelope, *e);
I 38
	bh = BlankEnvelope.e_header;
	nhp = &e->e_header;
	while (bh != NULL)
	{
		*nhp = (HDR *) xalloc(sizeof *bh);
		bcopy((char *) bh, (char *) *nhp, sizeof *bh);
		bh = bh->h_link;
		nhp = &(*nhp)->h_link;
	}
E 38
E 33
E 32
}
/*
D 24
**  UNLOCKQUEUE -- unlock the queue entry for a specified envelope
**
**	Parameters:
**		e -- the envelope to unlock.
**
**	Returns:
**		none
**
**	Side Effects:
**		unlocks the queue for `e'.
*/

unlockqueue(e)
	ENVELOPE *e;
{
	/* remove the transcript */
#ifdef DEBUG
I 6
# ifdef LOG
	if (LogLevel > 19)
		syslog(LOG_DEBUG, "%s: unlock", e->e_id);
# endif LOG
E 6
	if (!tTd(51, 4))
#endif DEBUG
		xunlink(queuename(e, 'x'));

I 9
# ifdef QUEUE
E 9
	/* last but not least, remove the lock */
	xunlink(queuename(e, 'l'));
I 9
# endif QUEUE
E 9
}
/*
E 24
**  INITSYS -- initialize instantiation of system
**
**	In Daemon mode, this is done in the child.
**
**	Parameters:
**		none.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Initializes the system macros, some global variables,
**		etc.  In particular, the current time in various
**		forms is set.
*/

initsys()
{
D 15
	auto time_t now;
E 15
	static char cbuf[5];			/* holds hop count */
D 15
	static char dbuf[30];			/* holds ctime(tbuf) */
E 15
	static char pbuf[10];			/* holds pid */
I 28
#ifdef TTYNAME
E 28
D 15
	static char tbuf[20];			/* holds "current" time */
E 15
	static char ybuf[10];			/* holds tty id */
	register char *p;
I 28
#endif TTYNAME
E 28
D 15
	register struct tm *tm;
E 15
	extern char *ttyname();
D 15
	extern char *arpadate();
	extern struct tm *gmtime();
E 15
	extern char *macvalue();
	extern char Version[];

	/*
	**  Give this envelope a reality.
	**	I.e., an id, a transcript, and a creation time.
	*/

	openxscript(CurEnv);
	CurEnv->e_ctime = curtime();

	/*
	**  Set OutChannel to something useful if stdout isn't it.
	**	This arranges that any extra stuff the mailer produces
	**	gets sent back to the user on error (because it is
	**	tucked away in the transcript).
	*/

	if (OpMode == MD_DAEMON && QueueRun)
		OutChannel = CurEnv->e_xfp;

	/*
	**  Set up some basic system macros.
	*/

	/* process id */
	(void) sprintf(pbuf, "%d", getpid());
	define('p', pbuf, CurEnv);

	/* hop count */
	(void) sprintf(cbuf, "%d", CurEnv->e_hopcount);
	define('c', cbuf, CurEnv);

	/* time as integer, unix time, arpa time */
D 15
	now = curtime();
	tm = gmtime(&now);
D 8
	(void) sprintf(tbuf, "%02d%02d%02d%02d%02d", tm->tm_year, tm->tm_mon,
E 8
I 8
	(void) sprintf(tbuf, "%02d%02d%02d%02d%02d", tm->tm_year, tm->tm_mon+1,
E 8
			tm->tm_mday, tm->tm_hour, tm->tm_min);
	define('t', tbuf, CurEnv);
	(void) strcpy(dbuf, ctime(&now));
	*index(dbuf, '\n') = '\0';
	if (macvalue('d', CurEnv) == NULL)
		define('d', dbuf, CurEnv);
	p = newstr(arpadate(dbuf));
	if (macvalue('a', CurEnv) == NULL)
		define('a', p, CurEnv);
	define('b', p, CurEnv);
E 15
I 15
	settime();
E 15
D 8

	/* version */
	define('v', Version, CurEnv);
E 8

I 24
#ifdef TTYNAME
E 24
	/* tty name */
	if (macvalue('y', CurEnv) == NULL)
	{
		p = ttyname(2);
		if (p != NULL)
		{
			if (rindex(p, '/') != NULL)
				p = rindex(p, '/') + 1;
			(void) strcpy(ybuf, p);
			define('y', ybuf, CurEnv);
		}
	}
I 24
#endif TTYNAME
E 24
}
/*
I 15
**  SETTIME -- set the current time.
**
**	Parameters:
**		none.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Sets the various time macros -- $a, $b, $d, $t.
*/

settime()
{
	register char *p;
	auto time_t now;
	static char tbuf[20];			/* holds "current" time */
	static char dbuf[30];			/* holds ctime(tbuf) */
	register struct tm *tm;
	extern char *arpadate();
	extern struct tm *gmtime();
	extern char *macvalue();

	now = curtime();
	tm = gmtime(&now);
D 43
	(void) sprintf(tbuf, "%02d%02d%02d%02d%02d", tm->tm_year, tm->tm_mon+1,
			tm->tm_mday, tm->tm_hour, tm->tm_min);
E 43
I 43
	(void) sprintf(tbuf, "%02d%02d%02d%02d%02d", tm->tm_year % 100,
			tm->tm_mon+1, tm->tm_mday, tm->tm_hour, tm->tm_min);
E 43
	define('t', tbuf, CurEnv);
	(void) strcpy(dbuf, ctime(&now));
	*index(dbuf, '\n') = '\0';
	if (macvalue('d', CurEnv) == NULL)
		define('d', dbuf, CurEnv);
	p = newstr(arpadate(dbuf));
	if (macvalue('a', CurEnv) == NULL)
		define('a', p, CurEnv);
	define('b', p, CurEnv);
}
/*
E 15
D 24
**  QUEUENAME -- build a file name in the queue directory for this envelope.
**
**	Assigns an id code if one does not already exist.
**	This code is very careful to avoid trashing existing files
**	under any circumstances.
**		We first create an nf file that is only used when
**		assigning an id.  This file is always empty, so that
**		we can never accidently truncate an lf file.
**
**	Parameters:
**		e -- envelope to build it in/from.
**		type -- the file type, used as the first character
**			of the file name.
**
**	Returns:
**		a pointer to the new file name (in a static buffer).
**
**	Side Effects:
**		Will create the lf and qf files if no id code is
**		already assigned.  This will cause the envelope
**		to be modified.
*/

char *
queuename(e, type)
	register ENVELOPE *e;
	char type;
{
	static char buf[MAXNAME];
	static int pid = -1;
	char c1 = 'A';
	char c2 = 'A';

	if (e->e_id == NULL)
	{
		char qf[20];
		char lf[20];
		char nf[20];

		/* find a unique id */
		if (pid != getpid())
		{
			/* new process -- start back at "AA" */
			pid = getpid();
			c1 = 'A';
			c2 = 'A' - 1;
		}
		(void) sprintf(qf, "qfAA%05d", pid);
		strcpy(lf, qf);
		lf[0] = 'l';
		strcpy(nf, qf);
		nf[0] = 'n';

		while (c1 < '~' || c2 < 'Z')
		{
			int i;

			if (c2 >= 'Z')
			{
				c1++;
				c2 = 'A' - 1;
			}
			qf[2] = lf[2] = nf[2] = c1;
			qf[3] = lf[3] = nf[3] = ++c2;
# ifdef DEBUG
			if (tTd(7, 20))
				printf("queuename: trying \"%s\"\n", nf);
# endif DEBUG
I 9
# ifdef QUEUE
E 9
			if (access(lf, 0) >= 0 || access(qf, 0) >= 0)
				continue;
			errno = 0;
			i = creat(nf, FileMode);
			if (i < 0)
			{
				(void) unlink(nf);	/* kernel bug */
				continue;
			}
			(void) close(i);
			i = link(nf, lf);
			(void) unlink(nf);
			if (i < 0)
				continue;
			if (link(lf, qf) >= 0)
				break;
			(void) unlink(lf);
I 9
# else QUEUE
			if (close(creat(qf, FileMode)) < 0)
				continue;
# endif QUEUE
E 9
		}
		if (c1 >= '~' && c2 >= 'Z')
		{
			syserr("queuename: Cannot create \"%s\" in \"%s\"",
				lf, QueueDir);
			exit(EX_OSERR);
		}
		e->e_id = newstr(&qf[2]);
		define('i', e->e_id, e);
# ifdef DEBUG
		if (tTd(7, 1))
			printf("queuename: assigned id %s, env=%x\n", e->e_id, e);
I 6
# ifdef LOG
		if (LogLevel > 16)
			syslog(LOG_DEBUG, "%s: assigned id", e->e_id);
# endif LOG
E 6
# endif DEBUG
	}

	if (type == '\0')
		return (NULL);
	(void) sprintf(buf, "%cf%s", type, e->e_id);
# ifdef DEBUG
	if (tTd(7, 2))
		printf("queuename: %s\n", buf);
# endif DEBUG
	return (buf);
}
/*
E 24
**  OPENXSCRIPT -- Open transcript file
**
**	Creates a transcript file for possible eventual mailing or
**	sending back.
**
**	Parameters:
**		e -- the envelope to create the transcript in/for.
**
**	Returns:
**		none
**
**	Side Effects:
**		Creates the transcript file.
*/

openxscript(e)
	register ENVELOPE *e;
{
	register char *p;

I 6
# ifdef LOG
	if (LogLevel > 19)
		syslog(LOG_DEBUG, "%s: openx%s", e->e_id, e->e_xfp == NULL ? "" : " (no)");
# endif LOG
E 6
	if (e->e_xfp != NULL)
		return;
	p = queuename(e, 'x');
	e->e_xfp = fopen(p, "w");
	if (e->e_xfp == NULL)
		syserr("Can't create %s", p);
	else
		(void) chmod(p, 0644);
I 6
}
/*
**  CLOSEXSCRIPT -- close the transcript file.
**
**	Parameters:
**		e -- the envelope containing the transcript to close.
**
**	Returns:
**		none.
**
**	Side Effects:
**		none.
*/

closexscript(e)
	register ENVELOPE *e;
{
	if (e->e_xfp == NULL)
		return;
	(void) fclose(e->e_xfp);
	e->e_xfp = NULL;
E 6
}
/*
**  SETSENDER -- set the person who this message is from
**
**	Under certain circumstances allow the user to say who
**	s/he is (using -f or -r).  These are:
**	1.  The user's uid is zero (root).
**	2.  The user's login name is in an approved list (typically
**	    from a network server).
**	3.  The address the user is trying to claim has a
**	    "!" character in it (since #2 doesn't do it for
**	    us if we are dialing out for UUCP).
**	A better check to replace #3 would be if the
**	effective uid is "UUCP" -- this would require me
**	to rewrite getpwent to "grab" uucp as it went by,
**	make getname more nasty, do another passwd file
**	scan, or compile the UID of "UUCP" into the code,
**	all of which are reprehensible.
**
**	Assuming all of these fail, we figure out something
**	ourselves.
**
**	Parameters:
**		from -- the person we would like to believe this message
**			is from, as specified on the command line.
**
**	Returns:
**		none.
**
**	Side Effects:
**		sets sendmail's notion of who the from person is.
*/

setsender(from)
	char *from;
{
	register char **pvp;
D 24
	register struct passwd *pw = NULL;
E 24
	char *realname = NULL;
I 25
	register struct passwd *pw;
E 25
	char buf[MAXNAME];
I 23
	char pvpbuf[PSBUFSIZE];
I 25
	extern struct passwd *getpwnam();
E 25
E 23
	extern char *macvalue();
	extern char **prescan();
	extern bool safefile();
	extern char *FullName;

# ifdef DEBUG
	if (tTd(45, 1))
D 18
		printf("setsender(%s)\n", from);
E 18
I 18
		printf("setsender(%s)\n", from == NULL ? "" : from);
E 18
# endif DEBUG

	/*
	**  Figure out the real user executing us.
	**	Username can return errno != 0 on non-errors.
	*/

I 44
	if (from != NULL && from[0] == '\0')
		from = "<>";
E 44
	if (QueueRun || OpMode == MD_SMTP || OpMode == MD_ARPAFTP)
		realname = from;
	if (realname == NULL || realname[0] == '\0')
	{
		extern char *username();

		realname = username();
D 24
		errno = 0;
E 24
	}
D 24
	if (realname == NULL || realname[0] == '\0')
	{
		extern struct passwd *getpwuid();
E 24

D 24
		pw = getpwuid(getruid());
		if (pw != NULL)
			realname = pw->pw_name;
	}
	if (realname == NULL || realname[0] == '\0')
	{
		syserr("Who are you?");
		realname = "root";
	}

E 24
	/*
	**  Determine if this real person is allowed to alias themselves.
	*/

	if (from != NULL)
	{
		extern bool trusteduser();

		if (!trusteduser(realname) &&
# ifdef DEBUG
		    (!tTd(1, 9) || getuid() != geteuid()) &&
# endif DEBUG
		    index(from, '!') == NULL && getuid() != 0)
		{
			/* network sends -r regardless (why why why?) */
			/* syserr("%s, you cannot use the -f flag", realname); */
			from = NULL;
		}
I 13
D 24
		else if (strcmp(from, realname) != 0)
			pw = NULL;
E 24
E 13
	}

	SuprErrs = TRUE;
D 4
	if (from == NULL || parse(from, &CurEnv->e_from, 1) == NULL)
E 4
I 4
D 12
	if (from == NULL || parseaddr(from, &CurEnv->e_from, 1) == NULL)
E 12
I 12
	if (from == NULL || parseaddr(from, &CurEnv->e_from, 1, '\0') == NULL)
E 12
E 4
	{
I 26
		/* log garbage addresses for traceback */
		if (from != NULL)
		{
D 30
			syslog(LOG_ERR, "Unparseable user %s wants to be %s",
					realname, from);
E 30
I 30
# ifdef LOG
			if (LogLevel >= 1)
				syslog(LOG_ERR, "Unparseable user %s wants to be %s",
						realname, from);
# endif LOG
E 30
		}
E 26
		from = newstr(realname);
D 4
		(void) parse(from, &CurEnv->e_from, 1);
E 4
I 4
D 12
		(void) parseaddr(from, &CurEnv->e_from, 1);
E 12
I 12
D 30
		(void) parseaddr(from, &CurEnv->e_from, 1, '\0');
E 30
I 30
		if (parseaddr(from, &CurEnv->e_from, 1, '\0') == NULL &&
		    parseaddr("postmaster", &CurEnv->e_from, 1, '\0') == NULL)
		{
			syserr("setsender: can't even parse postmaster!");
		}
E 30
E 12
E 4
	}
	else
		FromFlag = TRUE;
	CurEnv->e_from.q_flags |= QDONTSEND;
I 20
	loweraddr(&CurEnv->e_from);
E 20
	SuprErrs = FALSE;

D 24
	if (pw == NULL && CurEnv->e_from.q_mailer == LocalMailer)
E 24
I 24
D 25
	if (CurEnv->e_from.q_mailer == LocalMailer)
E 25
I 25
	if (CurEnv->e_from.q_mailer == LocalMailer &&
	    (pw = getpwnam(CurEnv->e_from.q_user)) != NULL)
E 25
E 24
	{
I 24
D 25
		register struct passwd *pw;
E 24
		extern struct passwd *getpwnam();

E 25
I 24
		/*
		**  Process passwd file entry.
		*/

E 24
D 25
		pw = getpwnam(CurEnv->e_from.q_user);
E 25
D 24
	}
E 24

D 24
	/*
	**  Process passwd file entry.
	*/

	if (pw != NULL)
	{
E 24
		/* extract home directory */
		CurEnv->e_from.q_home = newstr(pw->pw_dir);
I 21
		define('z', CurEnv->e_from.q_home, CurEnv);
E 21

I 14
		/* extract user and group id */
		CurEnv->e_from.q_uid = pw->pw_uid;
		CurEnv->e_from.q_gid = pw->pw_gid;
D 21

E 14
		/* run user's .mailcf file */
		define('z', CurEnv->e_from.q_home, CurEnv);
D 19
		expand("$z/.mailcf", buf, &buf[sizeof buf - 1], CurEnv);
E 19
I 19
		expand("\001z/.mailcf", buf, &buf[sizeof buf - 1], CurEnv);
E 19
		if (safefile(buf, getruid(), S_IREAD))
			readcf(buf, FALSE);
E 21

		/* if the user has given fullname already, don't redefine */
		if (FullName == NULL)
			FullName = macvalue('x', CurEnv);
D 15
		if (FullName[0] == '\0')
E 15
I 15
		if (FullName != NULL && FullName[0] == '\0')
E 15
			FullName = NULL;

		/* extract full name from passwd file */
D 2
		if (FullName == NULL && pw->pw_gecos != NULL)
E 2
I 2
		if (FullName == NULL && pw->pw_gecos != NULL &&
		    strcmp(pw->pw_name, CurEnv->e_from.q_user) == 0)
E 2
		{
			buildfname(pw->pw_gecos, CurEnv->e_from.q_user, buf);
			if (buf[0] != '\0')
				FullName = newstr(buf);
		}
		if (FullName != NULL)
			define('x', FullName, CurEnv);
	}
D 14

E 14
I 14
	else
	{
E 14
D 41
#ifndef V6
E 41
D 14
	if (CurEnv->e_from.q_home == NULL)
		CurEnv->e_from.q_home = getenv("HOME");
E 14
I 14
		if (CurEnv->e_from.q_home == NULL)
			CurEnv->e_from.q_home = getenv("HOME");
E 14
D 41
#endif V6
E 41
D 14
	CurEnv->e_from.q_uid = getuid();
	CurEnv->e_from.q_gid = getgid();
E 14
I 14
		CurEnv->e_from.q_uid = getuid();
		CurEnv->e_from.q_gid = getgid();
	}

E 14
	if (CurEnv->e_from.q_uid != 0)
	{
		DefUid = CurEnv->e_from.q_uid;
		DefGid = CurEnv->e_from.q_gid;
	}

	/*
	**  Rewrite the from person to dispose of possible implicit
	**	links in the net.
	*/

D 23
	pvp = prescan(from, '\0');
E 23
I 23
	pvp = prescan(from, '\0', pvpbuf);
E 23
	if (pvp == NULL)
	{
		syserr("cannot prescan from (%s)", from);
		finis();
	}
	rewrite(pvp, 3);
	rewrite(pvp, 1);
I 37
	rewrite(pvp, 4);
E 37
I 11
D 36
	rewrite(pvp, 4);
E 36
E 11
	cataddr(pvp, buf, sizeof buf);
	define('f', newstr(buf), CurEnv);

	/* save the domain spec if this mailer wants it */
D 7
	if (bitset(M_CANONICAL, CurEnv->e_from.q_mailer->m_flags))
E 7
I 7
D 30
	if (bitnset(M_CANONICAL, CurEnv->e_from.q_mailer->m_flags))
E 30
I 30
	if (CurEnv->e_from.q_mailer != NULL &&
	    bitnset(M_CANONICAL, CurEnv->e_from.q_mailer->m_flags))
E 30
E 7
	{
		extern char **copyplist();

		while (*pvp != NULL && strcmp(*pvp, "@") != 0)
			pvp++;
		if (*pvp != NULL)
			CurEnv->e_fromdomain = copyplist(pvp, TRUE);
	}
}
/*
**  TRUSTEDUSER -- tell us if this user is to be trusted.
**
**	Parameters:
**		user -- the user to be checked.
**
**	Returns:
**		TRUE if the user is in an approved list.
**		FALSE otherwise.
**
**	Side Effects:
**		none.
*/

bool
trusteduser(user)
	char *user;
{
	register char **ulist;
	extern char *TrustedUsers[];

	for (ulist = TrustedUsers; *ulist != NULL; ulist++)
		if (strcmp(*ulist, user) == 0)
			return (TRUE);
	return (FALSE);
}
E 1
