h33098
s 00011/00009/00569
d D 5.12 88/06/30 14:59:33 bostic 72 71
c install approved copyright notice
e
s 00016/00010/00562
d D 5.11 88/03/13 19:52:58 bostic 71 70
c add Berkeley specific header
e
s 00002/00004/00570
d D 5.10 88/03/13 18:21:47 bostic 70 69
c replace sameword with strcasecmp
e
s 00005/00002/00569
d D 5.9 86/10/23 10:21:52 eric 69 68
c set QBADADDR on illegal cases -- such as sending directly to files
e
s 00002/00002/00569
d D 5.8 86/10/23 10:11:07 eric 68 67
c Fix security bug allowing writing to arbitrary files; from Bart Miller
c at U. Wisconsin.
e
s 00008/00010/00563
d D 5.7 86/01/09 14:36:59 eric 67 66
c allow underscores in login names
e
s 00001/00001/00572
d D 5.6 85/12/07 08:57:01 eric 66 65
m 
c ischar => isascii
e
s 00002/00000/00571
d D 5.5 85/12/07 08:17:29 eric 65 64
m 
c several small bugs: don't die if no environment, don't look in
c ESM_DEADLETTER state in savemail; lowercase before getpwnam to
c allow upper case regular names in alias file
e
s 00001/00000/00570
d D 5.4 85/09/19 12:17:45 eric 64 63
m 
c count recipients
e
s 00001/00001/00569
d D 5.3 85/06/08 00:37:08 eric 63 62
m 
c lint
e
s 00000/00002/00570
d D 5.2 85/06/07 22:17:17 miriam 62 61
m 
c Resolve duplicate SccsId
e
s 00014/00000/00558
d D 5.1 85/06/07 15:10:29 dist 61 59
m 
c Add copyright
e
s 00000/00000/00558
d R 4.3.1.1 84/06/17 16:18:01 eric 60 59
m 
c abortive attempt to install a name server.... sigh.
e
s 00006/00000/00552
d D 4.3 84/03/11 19:58:07 eric 59 58
m 
c disable UPPER->lower case mapping in RHS's of aliases so that upper
c case letters can be used in file names and as args to programs.
e
s 00002/00001/00550
d D 4.2 83/10/29 16:45:59 eric 58 57
m 
c declare getpwnam in recipient.c for earlier systems
e
s 00000/00000/00551
d D 4.1 83/07/25 19:46:05 eric 57 56
m 
c 4.2 release version
e
s 00005/00000/00546
d D 3.54 83/05/21 11:01:31 eric 56 55
m 
c Miscellaneous changes for PDP-11's.
c Always send to a login name before a full name.
e
s 00008/00004/00538
d D 3.53 83/05/20 11:49:30 eric 55 54
m 238
m 239
c Don't stack processes when VRFY fails.
c Give an error message on multiple RCPT commands with a bad address.
e
s 00005/00001/00537
d D 3.52 83/03/08 19:22:13 eric 54 53
m 205
c Pass the delimiter character to parseaddr so that we can correctly
c decide between comma and space
e
s 00002/00002/00536
d D 3.51 83/01/03 18:01:57 eric 53 52
m 
c give more useful error messages (including the errno that caused
c a temporary failure); reflect these messages out to mailq
e
s 00001/00001/00537
d D 3.50 82/12/24 08:15:22 eric 52 51
m 108
c Change parse to parseaddr for BB&N TCP/IP implementation; clean up
c comments in daemon.c to simplify the poor alternate protocol type.
e
s 00004/00004/00534
d D 3.49 82/12/13 18:26:59 eric 51 50
m 085
c The routine "sendto" is now a system call (yeuch!); change our sendto
c to "sendtolist"
e
s 00013/00006/00525
d D 3.48 82/11/28 00:23:16 eric 50 49
m 
c Many changes resulting from a complete code readthrough.  Most of these
c fix minor bugs or change the internal structure for clarity, etc.  There
c should be almost no externally visible changes (other than some cleaner
c error message printouts and the like).
e
s 00001/00001/00530
d D 3.47 82/11/24 17:16:15 eric 49 48
m 026
c run SMTP jobs in a subprocess so that multiple jobs will work.  This
c delta also changes the envelope data structure so that flags are in
c a bit map, and adjusts some of the semantics.  The transcript is now
c local to an envelope.  A bunch of old code is deleted.  A serious bug
c was fixed in the "run in background" code.  Etc., etc.
e
s 00003/00005/00528
d D 3.46 82/11/18 17:58:43 eric 48 47
m 079
c minor cleanup from previous delta
e
s 00003/00000/00530
d D 3.45 82/11/18 17:54:40 eric 47 46
m 079
c Fix bug causing loops in sendto if there are scanner errors in addresses
e
s 00019/00022/00511
d D 3.44 82/11/14 15:14:17 eric 46 45
m 074
c fix quote processing on program mailers
e
s 00002/00002/00531
d D 3.43 82/11/03 09:49:36 eric 45 44
m 049
c Arrange to strip quote bits in message header; move SPACESUB into
c conf.c; change SpaceSub to unquoted dot
e
s 00003/00002/00530
d D 3.42 82/09/18 20:37:54 eric 44 43
c fix botch where it believes that a list is !oldstyle just because
c it has an alias expansion in it.
e
s 00007/00001/00525
d D 3.41 82/09/12 22:17:38 eric 43 42
c accept ": ... ;" syntax for groups if !oldstyle
e
s 00012/00027/00514
d D 3.40 82/09/06 16:25:15 eric 42 41
c install new state-driven scanner; make everyone use it, thus fixing
c problems of quoted commas, etc.
e
s 00006/00006/00535
d D 3.39 82/08/08 01:03:19 eric 41 40
c change debug level to a debug vector; add levels on logging (and the
c -L flag); change logging to be by message-id; elevate message-id;
c some lint-type cleanup
e
s 00004/00008/00537
d D 3.38 82/06/07 07:55:01 eric 40 39
c make transcripts verbose always; misc. message cleanup, etc.
e
s 00000/00029/00545
d D 3.37 82/06/07 07:06:18 eric 39 38
c strip out xlate stuff -- this belongs at a different level
e
s 00002/00002/00572
d D 3.36 82/05/31 18:50:21 eric 38 37
c pass lint.  notice that definitions in llib-lc have changed for
c alarm() and sleep() calls {arg was unsigned, is now int}.
e
s 00005/00005/00569
d D 3.35 82/05/22 01:38:39 eric 37 36
c add "envelopes" to contain the basic information needed as control
c info for each message.  currently there is only one envelope -- this
c being the obvious stupid conversion.  later there will be separate
c envelopes for error messages, return receipts, etc.
e
s 00029/00000/00545
d D 3.34 82/02/04 20:31:08 eric 36 35
c add host aliasing; add -p flag.  this version doesn't yet know about
c replacing the text of the host alias into the message however.  syntax
c is grotty: "/hostmatch:%s@newhost" or whatever.
e
s 00002/00001/00543
d D 3.33 82/01/23 14:18:57 eric 35 34
c only catch filenames if the "/" is leading
e
s 00003/00003/00541
d D 3.32 82/01/01 18:27:28 eric 34 33
c send to dead.letter using sendto/recipient/deliver mechanism rather
c than mailfile; this fixes a bug with the "from" name and seems like
c a better abstraction.
e
s 00002/00001/00542
d D 3.31 81/12/06 12:40:20 eric 33 32
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00021/00010/00522
d D 3.30 81/11/21 18:43:58 eric 32 31
c change the send queue to be only one queue instead of one per mailer.
c this is slightly inefficient but simpler.  also, pass this queue
c around so we can have multiple send queues.  this makes VRFY work.
e
s 00010/00001/00522
d D 3.29 81/11/21 16:38:54 eric 31 29
c convert to SMTP draft 3 -- finishing touches.  Punt on the VRFY/
c EXPN commands for now; they aren't required anyhow.  Move the fullname
c into the address structure so it can be inherited.
e
s 00094/00014/00509
d D 3.28.1.1 81/11/21 15:50:15 eric 30 29
c links together aliases into proper trees.  This is in part an
c attempt to do the SMTP VRFY command properly, but there are a number
c of annoying problems that convince me that this is the wrong way to
c do it.  Sigh.
e
s 00010/00007/00513
d D 3.28 81/10/26 14:23:15 eric 29 28
c Install new experimental queueing facility -- one stage timeout,
c etc.  This version is still quite incomplete.  It needs to reorder
c the queue after some interval, do two-stage timeout, take option
c info from the queue file instead of the command line, read the
c sender's .mailcf file, etc.  Some of this is useful for SMTP also.
e
s 00005/00006/00515
d D 3.27 81/10/23 19:38:33 eric 28 27
c Eliminate magic MN_LOCAL and MN_PROG; change q_mailer item in ADDRESS
c to be pointer to mailer rather than index.
e
s 00000/00000/00521
d D 3.26 81/10/19 22:27:46 eric 27 26
c implement SMTP mode -- doesn't support source routing or the
c HELP command, and doesn't give the correct code on VRFY or forwarding.
c Maybe someday....
e
s 00001/00001/00520
d D 3.25 81/10/17 16:58:24 eric 26 25
c initial prep to put in Daemon mode
e
s 00026/00006/00495
d D 3.24 81/09/28 19:17:32 eric 25 24
c enable aliases to self-reference themselves correctly.
e
s 00008/00001/00493
d D 3.23 81/09/22 11:33:20 eric 24 23
c finally make suppression of sender in mailing lists work -- this version
c also works correctly on simple aliases.
e
s 00007/00003/00487
d D 3.22 81/09/21 18:49:43 eric 23 22
c fix suppression of from address in mailing lists.
e
s 00014/00010/00476
d D 3.21 81/09/16 20:04:17 eric 22 21
c take underscore as well as space to separate parts of a person's
c full name.  Dot notation should be made to work someday also.
e
s 00013/00009/00473
d D 3.20 81/09/16 17:16:35 eric 21 20
c have .forward ownership stick harder than :include: ownership:
c this prevents cretins from using writable root files for nastiness.
c all this is pointless if /usr/lib/aliases is writable though....
e
s 00008/00001/00474
d D 3.19 81/09/16 16:39:58 eric 20 19
c be REALLY clever and inherit uid/gid from owner of :include:
c files also...   solves problem of alias to non-secure file
e
s 00004/00006/00471
d D 3.18 81/09/16 16:24:26 eric 19 18
c last delta was too paranoid -- this increases the number of
c cases that work (but is still safe -- I hope)
e
s 00061/00012/00416
d D 3.17 81/09/16 16:08:24 eric 18 17
c run as the user forwarding mail after a .forward operation;
c fix a bug in .forwarding that caused recursive expansion;
c restrict mail to programs, files, and with :include: for security
c reasons.
e
s 00008/00002/00420
d D 3.16 81/09/12 22:54:44 eric 17 16
c don't match on one-word gecos entries to avoid stealing mail
e
s 00004/00000/00418
d D 3.15 81/09/12 17:55:17 eric 16 15
c print message when sending to full name equivalent
e
s 00023/00002/00395
d D 3.14 81/09/12 17:34:21 eric 15 14
c match on full name for local users
e
s 00028/00002/00369
d D 3.13 81/09/12 16:37:14 eric 14 12
c preliminary work to take full names
e
s 00026/00002/00369
d R 3.13 81/09/12 16:33:17 eric 13 12
c preliminary work to take full names
e
s 00057/00002/00314
d D 3.12 81/09/07 14:13:07 eric 12 11
c fix up umask; allow setuid on files to take recipient owner;
c factor some configuration info into conf.c
e
s 00062/00002/00254
d D 3.11 81/09/07 12:33:55 eric 11 10
c add auto-rebuild on alias database; fix some aliasing bugs;
c add statistics to rebuild; slight code restructuring; change
c version handling one last (?) time
e
s 00017/00027/00239
d D 3.10 81/09/06 19:49:37 eric 10 9
c cleanup, commenting, linting, etc.
e
s 00002/00000/00264
d D 3.9 81/08/27 11:43:19 eric 9 8
c on -t, use argument list as a supress list
e
s 00007/00000/00257
d D 3.8 81/08/23 12:09:17 eric 8 7
c plug assorted security holes
e
s 00001/00000/00256
d D 3.7 81/08/22 19:36:41 eric 7 6
c only use a .forward file if owned by the receiver
e
s 00006/00002/00250
d D 3.6 81/08/22 14:31:21 eric 6 5
c fix mail to file problem (giving inappropriate diagnostic)
e
s 00005/00005/00247
d D 3.5 81/08/21 18:18:57 eric 5 4
c drop M_FINAL, change some other defined constant names
e
s 00000/00007/00252
d D 3.4 81/08/20 15:14:56 eric 4 3
c clean up some header information; don't reopen tempfile as
c stdin (to fix some problems with saving mail on interrupts)
e
s 00002/00001/00257
d D 3.3 81/08/20 14:50:19 eric 3 2
c pretty up message that include() prints
e
s 00009/00005/00249
d D 3.2 81/08/20 14:36:47 eric 2 1
c merge forwarding with :include:ing
e
s 00254/00000/00000
d D 3.1 81/08/20 14:33:05 eric 1 0
c split deliver.c and sendto.c
e
u
U
f b 
f i 
t
T
I 61
/*
I 72
 * Copyright (c) 1983 Eric P. Allman
E 72
D 71
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 71
I 71
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 72
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 72
I 72
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
E 72
 */
E 71

#ifndef lint
D 71
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint
E 71
I 71
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 71

E 61
I 1
D 4
# include <stdio.h>
E 4
# include <pwd.h>
I 12
D 29
# include <sys/types.h>
# include <sys/stat.h>
E 29
E 12
D 4
# include <signal.h>
# include <ctype.h>
# include <errno.h>
E 4
# include "sendmail.h"
I 29
# include <sys/stat.h>
E 29
D 4
# ifdef LOG
# include <syslog.h>
# endif LOG
E 4

D 33
static char SccsId[] = "%W%	%G%";
E 33
I 33
D 62
SCCSID(%W%	%Y%	%G%);
E 33

E 62
/*
D 51
**  SENDTO -- Designate a send list.
E 51
I 51
**  SENDTOLIST -- Designate a send list.
E 51
**
**	The parameter is a comma-separated list of people to send to.
**	This routine arranges to send to all of them.
**
I 30
**	The `ctladdr' is the address that expanded to be this one,
**	e.g., in an alias expansion.  This is used for a number of
**	purposed, most notably inheritance of uid/gid for protection
**	purposes.  It is also used to detect self-reference in group
**	expansions and the like.
**
E 30
**	Parameters:
**		list -- the send list.
D 42
**		copyf -- the copy flag; passed to parse.
E 42
I 18
**		ctladdr -- the address template for the person to
**			send to -- effective uid/gid are important.
I 32
**			This is typically the alias that caused this
**			expansion.
**		sendq -- a pointer to the head of a queue to put
**			these people into.
E 32
I 30
**		qflags -- special flags to set in the q_flags field.
E 30
E 18
**
**	Returns:
D 30
**		none
E 30
I 30
**		pointer to chain of addresses.
E 30
**
**	Side Effects:
**		none.
*/

# define MAXRCRSN	10

D 18
sendto(list, copyf)
E 18
I 18
D 30
D 32
sendto(list, copyf, ctladdr)
E 32
I 32
D 42
sendto(list, copyf, ctladdr, sendq)
E 42
I 42
D 51
sendto(list, ctladdr, sendq)
E 51
I 51
sendtolist(list, ctladdr, sendq)
E 51
E 42
E 32
E 30
I 30
ADDRESS *
sendto(list, copyf, ctladdr, qflags)
E 30
E 18
	char *list;
D 42
	int copyf;
E 42
I 18
	ADDRESS *ctladdr;
I 33
	ADDRESS **sendq;
E 33
I 30
	u_short qflags;
E 30
E 18
{
	register char *p;
D 10
	register char *q;
	register char c;
	ADDRESS *a;
	bool more;
E 10
I 10
D 42
	bool more;		/* set if more addresses to send to */
I 11
	ADDRESS *al;		/* list of addresses to send to */
E 42
I 42
D 43
	register ADDRESS *al;		/* list of addresses to send to */
E 43
I 43
	register ADDRESS *al;	/* list of addresses to send to */
E 43
E 42
I 24
	bool firstone;		/* set on first address sent */
I 25
	bool selfref;		/* set if this list includes ctladdr */
I 54
	char delimiter;		/* the address delimiter */
E 54
I 30
	ADDRESS *sibl;		/* sibling pointer in tree */
	ADDRESS *prev;		/* previous sibling */
E 30
E 25
E 24
E 11
E 10

I 11
# ifdef DEBUG
D 41
	if (Debug > 1)
E 41
I 41
	if (tTd(25, 1))
E 41
D 25
		printf("sendto: %s\n", list);
E 25
I 25
	{
		printf("sendto: %s\n   ctladdr=", list);
		printaddr(ctladdr, FALSE);
	}
E 25
# endif DEBUG

I 43
	/* heuristic to determine old versus new style addresses */
D 44
	if (index(list, ',') != NULL || index(list, ';') != NULL ||
	    index(list, '<') != NULL || index(list, '(') != NULL)
E 44
I 44
	if (ctladdr == NULL &&
	    (index(list, ',') != NULL || index(list, ';') != NULL ||
	     index(list, '<') != NULL || index(list, '(') != NULL))
E 44
D 49
		CurEnv->e_oldstyle = FALSE;
E 49
I 49
		CurEnv->e_flags &= ~EF_OLDSTYLE;
I 54
	delimiter = ' ';
	if (!bitset(EF_OLDSTYLE, CurEnv->e_flags) || ctladdr != NULL)
		delimiter = ',';
E 54
E 49

E 43
E 11
D 10
	/* more keeps track of what the previous delimiter was */
E 10
D 42
	more = TRUE;
E 42
I 24
	firstone = TRUE;
I 25
	selfref = FALSE;
E 25
E 24
I 11
	al = NULL;
I 43

E 43
E 11
D 42
	for (p = list; more; )
E 42
I 42
	for (p = list; *p != '\0'; )
E 42
	{
I 10
D 42
		register char *q;
		register char c;
		ADDRESS *a;
E 42
I 42
		register ADDRESS *a;
		extern char *DelimChar;		/* defined in prescan */
E 42

E 10
D 42
		/* find the end of this address */
		while (*p == ' ' || *p == '\t')
E 42
I 42
		/* parse the address */
		while (isspace(*p) || *p == ',')
E 42
			p++;
D 42
		q = p;
		while ((c = *p++) != '\0' && c != ',' && c != '\n')
E 42
I 42
D 48
		if ((a = parse(p, (ADDRESS *) NULL, 1)) == NULL)
I 47
		{
			p = DelimChar;
E 47
E 42
			continue;
I 47
		}
E 48
I 48
D 52
		a = parse(p, (ADDRESS *) NULL, 1);
E 52
I 52
D 54
		a = parseaddr(p, (ADDRESS *) NULL, 1);
E 54
I 54
		a = parseaddr(p, (ADDRESS *) NULL, 1, delimiter);
E 54
E 52
E 48
E 47
D 42
		more = c != '\0';
		*--p = '\0';
		if (more)
			p++;
I 11
		if (*q == '\0')
			continue;
E 11

		/* parse the address */
		if ((a = parse(q, (ADDRESS *) NULL, copyf)) == NULL)
			continue;
E 42
I 42
		p = DelimChar;
I 48
		if (a == NULL)
			continue;
E 48
E 42
D 25

D 11
		/* arrange to send to this person */
E 11
I 11
		/* put it on the local send list */
E 25
		a->q_next = al;
I 18
		a->q_alias = ctladdr;
I 30
		if (ctladdr != NULL)
			a->q_flags |= ctladdr->q_flags & ~QPRIMARY;
		a->q_flags |= qflags;
E 30
I 25

I 36
D 39
		/*
		**  If this address should have a host alias, take care
		**  of it now.
		*/

		if (strcmp(a->q_mailer->m_name, "xlate") == 0)
		{
			register char *newaddr;
			extern char *hostalias();

			newaddr = hostalias(a);
			if (newaddr == NULL)
			{
				/* couldn't do anything with it */
				giveresponse(EX_NOUSER, TRUE, a->q_mailer);
				continue;
			}

			if (Verbose)
				printf("%s... translated to %s\n", a->q_paddr, newaddr);

			/* change the print address so the message looks good */
			a->q_paddr = newaddr;

			/* call ourselves recursively to send to our friends */
			sendto(newaddr, copyf > 0 ? 0 : copyf, ctladdr, sendq);
			continue;
		}

E 39
E 36
		/* see if this should be marked as a primary address */
E 25
I 24
		if (ctladdr == NULL ||
D 42
		    (firstone && !more && bitset(QPRIMARY, ctladdr->q_flags)))
E 42
I 42
		    (firstone && *p == '\0' && bitset(QPRIMARY, ctladdr->q_flags)))
E 42
			a->q_flags |= QPRIMARY;
E 24
E 18
D 25
		al = a;
E 25
I 25

		/* put on send queue or suppress self-reference */
D 50
		if (ctladdr != NULL && sameaddr(ctladdr, a, FALSE))
E 50
I 50
		if (ctladdr != NULL && sameaddr(ctladdr, a))
E 50
			selfref = TRUE;
		else
			al = a;
E 25
I 24
		firstone = FALSE;
E 24
	}

I 25
	/* if this alias doesn't include itself, delete ctladdr */
	if (!selfref && ctladdr != NULL)
		ctladdr->q_flags |= QDONTSEND;

E 25
	/* arrange to send to everyone on the local send list */
I 30
	prev = sibl = NULL;
	if (ctladdr != NULL)
		prev = ctladdr->q_child;
E 30
	while (al != NULL)
	{
		register ADDRESS *a = al;
I 55
		extern ADDRESS *recipient();
E 55
I 30
		extern ADDRESS *recipient();
E 30

		al = a->q_next;
E 11
D 30
D 32
		recipient(a);
E 32
I 32
D 55
		recipient(a, sendq);
E 55
I 55
		a = recipient(a, sendq);
E 55
E 32
I 31

		/* arrange to inherit full name */
		if (a->q_fullname == NULL && ctladdr != NULL)
			a->q_fullname = ctladdr->q_fullname;
E 31
E 30
I 30
		sibl = recipient(a);
		if (sibl != NULL)
		{
			extern ADDRESS *addrref();

			/* inherit full name */
			if (sibl->q_fullname == NULL && ctladdr != NULL)
				sibl->q_fullname = ctladdr->q_fullname;

			/* link tree together (but only if the node is new) */
			if (sibl == a)
			{
				sibl->q_sibling = prev;
				prev = sibl;
			}
		}
E 30
	}
I 11

E 11
D 37
	To = NULL;
E 37
I 37
	CurEnv->e_to = NULL;
E 37
I 30
	if (ctladdr != NULL)
		ctladdr->q_child = prev;
	return (prev);
E 30
}
/*
I 30
**  ADDRREF -- return pointer to address that references another address.
**
**	Parameters:
**		a -- address to check.
**		r -- reference to find.
**
**	Returns:
**		address of node in tree rooted at 'a' that references
**			'r'.
**		NULL if no such node exists.
**
**	Side Effects:
**		none.
*/

ADDRESS *
addrref(a, r)
	register ADDRESS *a;
	register ADDRESS *r;
{
	register ADDRESS *q;

	while (a != NULL)
	{
		if (a->q_child == r || a->q_sibling == r)
			return (a);
		q = addrref(a->q_child, r);
		if (q != NULL)
			return (q);
		a = a->q_sibling;
	}
	return (NULL);
}
/*
E 30
**  RECIPIENT -- Designate a message recipient
**
**	Saves the named person for future mailing.
**
**	Parameters:
**		a -- the (preparsed) address header for the recipient.
I 32
**		sendq -- a pointer to the head of a queue to put the
**			recipient in.  Duplicate supression is done
**			in this queue.
E 32
**
**	Returns:
D 30
D 55
**		none.
E 55
I 55
**		The actual address in the queue.  This will be "a" if
**		the address is not a duplicate, else the original address.
E 55
E 30
I 30
**		pointer to address actually inserted in send list.
E 30
**
**	Side Effects:
**		none.
*/

I 55
ADDRESS *
E 55
I 30
ADDRESS *
E 30
D 32
recipient(a)
E 32
I 32
recipient(a, sendq)
E 32
	register ADDRESS *a;
I 32
	register ADDRESS **sendq;
E 32
{
	register ADDRESS *q;
I 10
	ADDRESS **pq;
E 10
	register struct mailer *m;
I 46
	register char *p;
	bool quoted = FALSE;		/* set if the addr has a quote bit */
	char buf[MAXNAME];		/* unquoted image of the user name */
E 46
I 18
	extern ADDRESS *getctladdr();
I 29
	extern bool safefile();
E 29
E 18
D 10
	char buf[MAXNAME];
E 10

D 37
	To = a->q_paddr;
E 37
I 37
	CurEnv->e_to = a->q_paddr;
E 37
D 28
	m = Mailer[a->q_mailer];
E 28
I 28
	m = a->q_mailer;
E 28
	errno = 0;
# ifdef DEBUG
D 41
	if (Debug)
E 41
I 41
	if (tTd(26, 1))
E 41
D 25
		printf("recipient(%s)\n", To);
E 25
I 25
	{
		printf("\nrecipient: ");
		printaddr(a, FALSE);
	}
E 25
# endif DEBUG

	/* break aliasing loops */
	if (AliasLevel > MAXRCRSN)
	{
		usrerr("aliasing/forwarding loop broken");
D 30
D 55
		return;
E 55
I 55
		return (a);
E 55
E 30
I 30
		return (NULL);
E 30
	}

	/*
D 29
	**  Do sickly crude mapping for program mailing, etc.
E 29
I 29
	**  Finish setting up address structure.
E 29
	*/

I 59
	/* set the queue timeout */
E 59
I 29
	a->q_timeout = TimeOut;

I 59
	/* map user & host to lower case if requested on non-aliases */
	if (a->q_alias == NULL)
		loweraddr(a);

	/* get unquoted user for file, program or user.name check */
E 59
I 46
	(void) strcpy(buf, a->q_user);
	for (p = buf; *p != '\0' && !quoted; p++)
	{
		if (!isascii(*p) && (*p & 0377) != (SpaceSub & 0377))
			quoted = TRUE;
	}
	stripquotes(buf, TRUE);

E 46
	/* do sickly crude mapping for program mailing, etc. */
E 29
D 5
	if (a->q_mailer == M_LOCAL)
E 5
I 5
D 28
	if (a->q_mailer == MN_LOCAL)
E 28
I 28
D 46
	if (a->q_mailer == LocalMailer)
E 46
I 46
	if (m == LocalMailer && buf[0] == '|')
E 46
E 28
E 5
	{
D 46
		if (a->q_user[0] == '|')
E 46
I 46
		a->q_mailer = m = ProgMailer;
		a->q_user++;
		if (a->q_alias == NULL && !tTd(0, 1) && !QueueRun && !ForceMail)
E 46
		{
D 5
			a->q_mailer = M_PROG;
			m = Mailer[M_PROG];
E 5
I 5
D 28
			a->q_mailer = MN_PROG;
			m = Mailer[MN_PROG];
E 28
I 28
D 46
			a->q_mailer = m = ProgMailer;
E 28
E 5
			a->q_user++;
I 8
D 18
# ifdef PARANOID
			if (AliasLevel <= 0)
E 18
I 18
D 19
			if (getctladdr(a) == &From && Debug == 0)
E 19
I 19
D 21
			if (getctladdr(a) == NULL && Debug == 0)
E 21
I 21
D 29
			if (a->q_alias == NULL && Debug == 0)
E 29
I 29
D 34
			if (a->q_alias == NULL && Debug == 0 && !QueueRun)
E 34
I 34
D 41
			if (a->q_alias == NULL && Debug == 0 && !QueueRun && !ForceMail)
E 41
I 41
			if (a->q_alias == NULL && !tTd(0, 1) && !QueueRun && !ForceMail)
E 41
E 34
E 29
E 21
E 19
E 18
			{
				usrerr("Cannot mail directly to programs");
				a->q_flags |= QDONTSEND;
			}
E 46
I 46
D 68
			usrerr("Cannot mail directly to programs");
E 68
D 69
			a->q_flags |= QDONTSEND;
E 69
I 69
			a->q_flags |= QDONTSEND|QBADADDR;
E 69
I 68
			usrerr("Cannot mail directly to programs");
E 68
E 46
D 18
# endif PARANOID
E 18
E 8
		}
	}

	/*
D 23
	**  Look up this person in the recipient list.  If they
	**  are there already, return, otherwise continue.
	**  If the list is empty, just add it.
E 23
I 23
	**  Look up this person in the recipient list.
	**	If they are there already, return, otherwise continue.
	**	If the list is empty, just add it.  Notice the cute
	**	hack to make from addresses suppress things correctly:
	**	the QDONTSEND bit will be set in the send list.
	**	[Please note: the emphasis is on "hack."]
E 23
	*/

D 10
	if (m->m_sendq == NULL)
E 10
I 10
D 32
	for (pq = &m->m_sendq; (q = *pq) != NULL; pq = &q->q_next)
E 32
I 32
	for (pq = sendq; (q = *pq) != NULL; pq = &q->q_next)
E 32
E 10
	{
D 10
		m->m_sendq = a;
	}
	else
	{
		ADDRESS *pq;

		for (q = m->m_sendq; q != NULL; pq = q, q = q->q_next)
E 10
I 10
D 50
		if (!ForceMail && sameaddr(q, a, FALSE))
E 50
I 50
		if (!ForceMail && sameaddr(q, a))
E 50
E 10
		{
D 10
			if (!ForceMail && sameaddr(q, a, FALSE))
			{
E 10
# ifdef DEBUG
D 10
				if (Debug)
					printf("(%s in sendq)\n", a->q_paddr);
E 10
I 10
D 41
			if (Debug)
E 41
I 41
			if (tTd(26, 1))
E 41
D 25
				printf("(%s in sendq)\n", a->q_paddr);
E 25
I 25
			{
				printf("%s in sendq: ", a->q_paddr);
				printaddr(q, FALSE);
			}
E 25
E 10
# endif DEBUG
D 10
				if (Verbose && !bitset(QDONTSEND, a->q_flags))
					message(Arpa_Info, "duplicate supressed");
				return;
			}
E 10
I 10
D 30
D 40
			if (Verbose && !bitset(QDONTSEND, a->q_flags))
E 40
I 40
			if (!bitset(QDONTSEND, a->q_flags))
E 40
E 30
I 30
			if (Verbose && !bitset(QDONTSEND|QPSEUDO, a->q_flags))
E 30
D 11
				message(Arpa_Info, "duplicate supressed");
E 11
I 11
				message(Arpa_Info, "duplicate suppressed");
I 23
D 24
			q->q_flags |= a->q_flags;
E 24
I 24
			if (!bitset(QPRIMARY, q->q_flags))
				q->q_flags |= a->q_flags;
E 24
E 23
E 11
D 30
D 55
			return;
E 55
I 55
			return (q);
E 55
E 30
I 30
			if (!bitset(QPSEUDO, a->q_flags))
				q->q_flags &= ~QPSEUDO;
			return (q);
E 30
E 10
		}
D 10

		/* add address on list */
		q = pq;
		q->q_next = a;
E 10
	}
I 10

	/* add address on list */
	*pq = a;
E 10
	a->q_next = NULL;
I 64
	CurEnv->e_nrcpts++;
E 64
I 9
D 50
	if (DontSend)
		a->q_flags |= QDONTSEND;
E 50
E 9

	/*
	**  Alias the name and handle :include: specs.
	*/

D 5
	if (a->q_mailer == M_LOCAL)
E 5
I 5
D 28
	if (a->q_mailer == MN_LOCAL)
E 28
I 28
D 46
	if (a->q_mailer == LocalMailer)
E 46
I 46
	if (m == LocalMailer && !bitset(QDONTSEND, a->q_flags))
E 46
E 28
E 5
	{
		if (strncmp(a->q_user, ":include:", 9) == 0)
		{
			a->q_flags |= QDONTSEND;
D 2
			include(&a->q_user[9]);
E 2
I 2
D 18
			if (Verbose)
				message(Arpa_Info, "including file %s", &a->q_user[9]);
			include(&a->q_user[9], " sending");
E 18
I 18
D 19
			if (getctladdr(a) == &From && Debug == 0)
E 19
I 19
D 21
			if (getctladdr(a) == NULL && Debug == 0)
E 21
I 21
D 29
			if (a->q_alias == NULL && Debug == 0)
E 29
I 29
D 34
			if (a->q_alias == NULL && Debug == 0 && !QueueRun)
E 34
I 34
D 41
			if (a->q_alias == NULL && Debug == 0 && !QueueRun && !ForceMail)
E 41
I 41
			if (a->q_alias == NULL && !tTd(0, 1) && !QueueRun && !ForceMail)
I 69
			{
				a->q_flags |= QBADADDR;
E 69
E 41
E 34
E 29
E 21
E 19
				usrerr("Cannot mail directly to :include:s");
I 69
			}
E 69
			else
			{
D 40
				if (Verbose)
					message(Arpa_Info, "including file %s", &a->q_user[9]);
E 40
I 40
				message(Arpa_Info, "including file %s", &a->q_user[9]);
E 40
D 32
				include(&a->q_user[9], " sending", a);
E 32
I 32
				include(&a->q_user[9], " sending", a, sendq);
E 32
			}
E 18
E 2
		}
		else
D 32
			alias(a);
E 32
I 32
			alias(a, sendq);
E 32
	}

	/*
	**  If the user is local and still being sent, verify that
	**  the address is good.  If it is, try to forward.
	**  If the address is already good, we have a forwarding
	**  loop.  This can be broken by just sending directly to
	**  the user (which is probably correct anyway).
	*/

D 5
	if (!bitset(QDONTSEND, a->q_flags) && a->q_mailer == M_LOCAL)
E 5
I 5
D 28
	if (!bitset(QDONTSEND, a->q_flags) && a->q_mailer == MN_LOCAL)
E 28
I 28
D 46
	if (!bitset(QDONTSEND, a->q_flags) && a->q_mailer == LocalMailer)
E 46
I 46
	if (!bitset(QDONTSEND, a->q_flags) && m == LocalMailer)
E 46
E 28
E 5
	{
D 46
		char buf[MAXNAME];
I 6
		register char *p;
E 46
I 12
		struct stat stb;
		extern bool writable();
I 18
D 46
		bool quoted = FALSE;
E 18
E 12
E 6

D 38
		strcpy(buf, a->q_user);
E 38
I 38
		(void) strcpy(buf, a->q_user);
E 38
I 18
		for (p = buf; *p != '\0' && !quoted; p++)
		{
D 30
D 31
			if (!isascii(*p))
E 31
I 31
D 45
			if (!isascii(*p) && (*p & 0377) != (SPACESUB & 0377))
E 45
I 45
			if (!isascii(*p) && (*p & 0377) != (SpaceSub & 0377))
E 45
E 31
E 30
I 30
			if (!isascii(*p) && (*p & 0377) != (SPACESUB) & 0377)
E 30
				quoted = TRUE;
		}
E 18
		stripquotes(buf, TRUE);
E 46

		/* see if this is to a file */
D 6
		if (index(buf, '/') != NULL)
E 6
I 6
D 35
		if ((p = rindex(buf, '/')) != NULL)
E 35
I 35
		if (buf[0] == '/')
E 35
E 6
		{
I 35
			p = rindex(buf, '/');
E 35
D 6
			if (access(buf, 2) < 0)
E 6
I 6
			/* check if writable or creatable */
D 12
			if ((access(buf, 0) >= 0) ?
			    (access(buf, 2) < 0) :
E 12
I 12
D 18
			if ((stat(buf, &stb) >= 0) ? (!writable(&stb)) :
E 18
I 18
D 19
			if (getctladdr(a) == &From && Debug == 0)
E 19
I 19
D 21
			if (getctladdr(a) == NULL && Debug == 0)
E 21
I 21
D 29
			if (a->q_alias == NULL && Debug == 0)
E 29
I 29
D 34
			if (a->q_alias == NULL && Debug == 0 && !QueueRun)
E 34
I 34
D 41
			if (a->q_alias == NULL && Debug == 0 && !QueueRun && !ForceMail)
E 41
I 41
			if (a->q_alias == NULL && !tTd(0, 1) && !QueueRun && !ForceMail)
E 41
E 34
E 29
E 21
E 19
			{
D 68
				usrerr("Cannot mail directly to files");
E 68
D 69
				a->q_flags |= QDONTSEND;
E 69
I 69
				a->q_flags |= QDONTSEND|QBADADDR;
E 69
I 68
				usrerr("Cannot mail directly to files");
E 68
			}
			else if ((stat(buf, &stb) >= 0) ? (!writable(&stb)) :
E 18
E 12
D 26
			    (*p = '\0', access(buf, 3) < 0))
E 26
I 26
			    (*p = '\0', !safefile(buf, getruid(), S_IWRITE|S_IEXEC)))
E 26
E 6
			{
				a->q_flags |= QBADADDR;
D 50
				giveresponse(EX_CANTCREAT, TRUE, m);
E 50
I 50
D 53
				giveresponse(EX_CANTCREAT, m);
E 53
I 53
				giveresponse(EX_CANTCREAT, m, CurEnv);
E 53
E 50
			}
		}
		else
		{
			register struct passwd *pw;
D 14
			extern struct passwd *getpwnam();
			pw = getpwnam(buf);
E 14
I 14
			extern struct passwd *finduser();

I 22
			/* warning -- finduser may trash buf */
E 22
			pw = finduser(buf);
E 14
			if (pw == NULL)
			{
				a->q_flags |= QBADADDR;
D 50
				giveresponse(EX_NOUSER, TRUE, m);
E 50
I 50
D 53
				giveresponse(EX_NOUSER, m);
E 53
I 53
				giveresponse(EX_NOUSER, m, CurEnv);
E 53
E 50
			}
			else
			{
I 31
				char nbuf[MAXNAME];

E 31
I 30
				char nbuf[MAXNAME];

E 30
I 15
				if (strcmp(a->q_user, pw->pw_name) != 0)
				{
					a->q_user = newstr(pw->pw_name);
D 38
					strcpy(buf, pw->pw_name);
E 38
I 38
					(void) strcpy(buf, pw->pw_name);
E 38
				}
E 15
				a->q_home = newstr(pw->pw_dir);
I 7
				a->q_uid = pw->pw_uid;
E 7
D 18
				if (strcmp(buf, a->q_user) == 0)
E 18
I 18
				a->q_gid = pw->pw_gid;
I 20
				a->q_flags |= QGOODUID;
I 31
				buildfname(pw->pw_gecos, pw->pw_name, nbuf);
				if (nbuf[0] != '\0')
					a->q_fullname = newstr(nbuf);
E 31
I 30
				fullname(pw, nbuf);
				if (nbuf[0] != '\0')
					a->q_fullname = newstr(nbuf);
E 30
E 20
				if (!quoted)
E 18
D 32
					forward(a);
E 32
I 32
					forward(a, sendq);
E 32
			}
		}
	}
I 55
	return (a);
E 55
I 30

	return (a);
E 30
I 14
}
/*
**  FINDUSER -- find the password entry for a user.
**
**	This looks a lot like getpwnam, except that it may want to
**	do some fancier pattern matching in /etc/passwd.
**
I 50
**	This routine contains most of the time of many sendmail runs.
**	It deserves to be optimized.
**
E 50
**	Parameters:
**		name -- the name to match against.
**
**	Returns:
**		A pointer to a pw struct.
**		NULL if name is unknown or ambiguous.
**
**	Side Effects:
D 22
**		none.
E 22
I 22
**		may modify name.
E 22
*/

struct passwd *
finduser(name)
	char *name;
{
D 15
	extern struct passwd *getpwnam();
E 15
I 15
D 58
	extern struct passwd *getpwent();
E 58
	register struct passwd *pw;
I 22
	register char *p;
I 58
	extern struct passwd *getpwent();
	extern struct passwd *getpwnam();
E 58
E 22
E 15

I 22
D 67
	/*
	**  Make name canonical.
	*/

E 67
I 67
	/* map upper => lower case */
E 67
	for (p = name; *p != '\0'; p++)
	{
D 45
		if (*p == (SPACESUB & 0177) || *p == '_')
E 45
I 45
D 67
		if (*p == (SpaceSub & 0177) || *p == '_')
E 45
			*p = ' ';
I 65
D 66
		else if (ischar(*p) && isupper(*p))
E 66
I 66
		else if (isascii(*p) && isupper(*p))
E 67
I 67
		if (isascii(*p) && isupper(*p))
E 67
E 66
			*p = tolower(*p);
E 65
	}

I 56
D 67
	/* look up this login name */
E 67
I 67
	/* look up this login name using fast path */
E 67
	if ((pw = getpwnam(name)) != NULL)
		return (pw);

	/* search for a matching full name instead */
I 67
	for (p = name; *p != '\0'; p++)
	{
		if (*p == (SpaceSub & 0177) || *p == '_')
			*p = ' ';
	}
E 67
E 56
E 22
D 15
	return (getpwnam(name));
E 15
I 15
D 63
	setpwent();
E 63
I 63
	(void) setpwent();
E 63
	while ((pw = getpwent()) != NULL)
	{
D 30
		char buf[MAXNAME];
E 30
D 22
		register char *p;
E 22
D 70
		extern bool sameword();
E 70
I 30
		char buf[MAXNAME];
E 30
I 17
D 22
		bool gotaspace;
E 22
E 17

D 67
		if (strcmp(pw->pw_name, name) == 0)
			return (pw);
E 67
D 30
		buildfname(pw->pw_gecos, pw->pw_name, buf);
E 30
I 30
		fullname(pw, buf);
E 30
I 17
D 22
		gotaspace = FALSE;
E 17
		for (p = buf; (p = index(p, ' ')) != NULL; )
I 17
		{
E 17
			*p++ = SPACESUB & 0177;
D 17
		if (sameword(buf, name))
E 17
I 17
			gotaspace = TRUE;
		}
		if (gotaspace && sameword(buf, name))
E 22
I 22
D 70
		if (index(buf, ' ') != NULL && sameword(buf, name))
E 70
I 70
		if (index(buf, ' ') != NULL && !strcasecmp(buf, name))
E 70
E 22
E 17
I 16
		{
D 40
			if (Verbose)
D 17
				message(Arpa_Info, "sending to login name %s", pw->pw_name);
E 17
I 17
D 30
				message(Arpa_Info, "sending to login name %s",
				    pw->pw_name);
E 40
I 40
			message(Arpa_Info, "sending to login name %s", pw->pw_name);
E 40
E 30
I 30
				message(Arpa_Info, "sending to %s <%s>",
				    buf, pw->pw_name);
E 30
E 17
E 16
			return (pw);
I 16
		}
E 16
	}
	return (NULL);
E 15
E 14
I 12
}
/*
**  WRITABLE -- predicate returning if the file is writable.
**
**	This routine must duplicate the algorithm in sys/fio.c.
**	Unfortunately, we cannot use the access call since we
**	won't necessarily be the real uid when we try to
**	actually open the file.
**
**	Notice that ANY file with ANY execute bit is automatically
**	not writable.  This is also enforced by mailfile.
**
**	Parameters:
**		s -- pointer to a stat struct for the file.
**
**	Returns:
**		TRUE -- if we will be able to write this file.
**		FALSE -- if we cannot write this file.
**
**	Side Effects:
**		none.
*/

bool
writable(s)
	register struct stat *s;
{
	int euid, egid;
	int bits;

	if (bitset(0111, s->st_mode))
		return (FALSE);
	euid = getruid();
	egid = getrgid();
	if (geteuid() == 0)
	{
		if (bitset(S_ISUID, s->st_mode))
			euid = s->st_uid;
		if (bitset(S_ISGID, s->st_mode))
			egid = s->st_gid;
	}

	if (euid == 0)
		return (TRUE);
	bits = S_IWRITE;
	if (euid != s->st_uid)
	{
		bits >>= 3;
		if (egid != s->st_gid)
			bits >>= 3;
	}
	return ((s->st_mode & bits) != 0);
E 12
}
/*
**  INCLUDE -- handle :include: specification.
**
**	Parameters:
**		fname -- filename to include.
I 2
**		msg -- message to print in verbose mode.
I 18
**		ctladdr -- address template to use to fill in these
**			addresses -- effective user/group id are
**			the important things.
I 32
**		sendq -- a pointer to the head of the send queue
**			to put these addresses in.
E 32
E 18
E 2
**
**	Returns:
**		none.
**
**	Side Effects:
**		reads the :include: file and sends to everyone
**		listed in that file.
*/

D 2
include(fname)
E 2
I 2
D 18
include(fname, msg)
E 18
I 18
D 32
include(fname, msg, ctladdr)
E 32
I 32
include(fname, msg, ctladdr, sendq)
E 32
E 18
E 2
	char *fname;
I 2
	char *msg;
I 18
	ADDRESS *ctladdr;
I 32
	ADDRESS **sendq;
E 32
E 18
E 2
{
	char buf[MAXLINE];
	register FILE *fp;
I 3
D 37
	char *oldto = To;
E 37
I 37
	char *oldto = CurEnv->e_to;
I 50
	char *oldfilename = FileName;
	int oldlinenumber = LineNumber;
E 50
E 37
I 20
D 21
	struct stat st;
E 21
E 20
E 3

D 2
	if (Verbose)
		message(Arpa_Info, "Including file %s", fname);
E 2
	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		usrerr("Cannot open %s", fname);
		return;
	}
I 20
D 21
	if (fstat(fileno(fp), &st) < 0)
		syserr("Cannot fstat %s!", fname);
	ctladdr->q_uid = st.st_uid;
	ctladdr->q_gid = st.st_gid;
	ctladdr->q_flags |= QGOODUID;
E 21
I 21
	if (getctladdr(ctladdr) == NULL)
	{
		struct stat st;

		if (fstat(fileno(fp), &st) < 0)
			syserr("Cannot fstat %s!", fname);
		ctladdr->q_uid = st.st_uid;
		ctladdr->q_gid = st.st_gid;
		ctladdr->q_flags |= QGOODUID;
	}
E 21
E 20

	/* read the file -- each line is a comma-separated list. */
I 50
	FileName = fname;
	LineNumber = 0;
E 50
	while (fgets(buf, sizeof buf, fp) != NULL)
	{
		register char *p = index(buf, '\n');

		if (p != NULL)
			*p = '\0';
		if (buf[0] == '\0')
			continue;
D 3
		To = fname;
E 3
I 3
D 37
		To = oldto;
E 37
I 37
		CurEnv->e_to = oldto;
E 37
E 3
D 40
		if (Verbose)
D 2
			message(Arpa_Info, " >> %s", buf);
E 2
I 2
			message(Arpa_Info, "%s to %s", msg, buf);
E 40
I 40
		message(Arpa_Info, "%s to %s", msg, buf);
E 40
		AliasLevel++;
E 2
D 18
		sendto(buf, 1);
E 18
I 18
D 30
D 32
		sendto(buf, 1, ctladdr);
E 32
I 32
D 42
		sendto(buf, 1, ctladdr, sendq);
E 42
I 42
D 51
		sendto(buf, ctladdr, sendq);
E 51
I 51
		sendtolist(buf, ctladdr, sendq);
E 51
E 42
E 32
E 30
I 30
		sendto(buf, 1, ctladdr, 0);
E 30
E 18
I 2
		AliasLevel--;
E 2
	}

D 10
	fclose(fp);
E 10
I 10
	(void) fclose(fp);
I 50
	FileName = oldfilename;
	LineNumber = oldlinenumber;
E 50
I 11
}
/*
**  SENDTOARGV -- send to an argument vector.
**
**	Parameters:
**		argv -- argument vector to send to.
**
**	Returns:
**		none.
**
**	Side Effects:
**		puts all addresses on the argument vector onto the
**			send queue.
*/

sendtoargv(argv)
	register char **argv;
{
	register char *p;
D 70
	extern bool sameword();
E 70

	while ((p = *argv++) != NULL)
	{
D 70
		if (argv[0] != NULL && argv[1] != NULL && sameword(argv[0], "at"))
E 70
I 70
		if (argv[0] != NULL && argv[1] != NULL && !strcasecmp(argv[0], "at"))
E 70
		{
			char nbuf[MAXNAME];

			if (strlen(p) + strlen(argv[1]) + 2 > sizeof nbuf)
				usrerr("address overflow");
			else
			{
				(void) strcpy(nbuf, p);
				(void) strcat(nbuf, "@");
				(void) strcat(nbuf, argv[1]);
				p = newstr(nbuf);
				argv += 2;
			}
		}
D 18
		sendto(p, 0);
E 18
I 18
D 19
		sendto(p, 0, &From);
E 19
I 19
D 29
		sendto(p, 0, NULL);
E 29
I 29
D 30
D 32
		sendto(p, 0, (ADDRESS *) NULL);
E 32
I 32
D 37
		sendto(p, 0, (ADDRESS *) NULL, &SendQueue);
E 37
I 37
D 42
		sendto(p, 0, (ADDRESS *) NULL, &CurEnv->e_sendqueue);
E 42
I 42
D 51
		sendto(p, (ADDRESS *) NULL, &CurEnv->e_sendqueue);
E 51
I 51
		sendtolist(p, (ADDRESS *) NULL, &CurEnv->e_sendqueue);
E 51
E 42
E 37
E 32
E 30
I 30
		sendto(p, 0, (ADDRESS *) NULL, 0);
E 30
E 29
E 19
E 18
	}
I 18
}
/*
**  GETCTLADDR -- get controlling address from an address header.
**
**	If none, get one corresponding to the effective userid.
**
**	Parameters:
**		a -- the address to find the controller of.
**
**	Returns:
**		the controlling address.
**
**	Side Effects:
**		none.
*/

ADDRESS *
getctladdr(a)
	register ADDRESS *a;
{
D 20
	while (a != NULL && a->q_home == NULL)
E 20
I 20
	while (a != NULL && !bitset(QGOODUID, a->q_flags))
E 20
		a = a->q_alias;
D 19
	if (a == NULL)
		return (&From);
E 19
	return (a);
E 18
E 11
E 10
}
E 1
