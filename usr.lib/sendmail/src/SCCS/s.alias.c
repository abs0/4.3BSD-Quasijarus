h59298
s 00001/00001/00708
d D 5.19 06/05/20 01:12:23 msokolov 94 93
c brown paper bag
e
s 00120/00004/00589
d D 5.18 06/05/19 21:47:24 msokolov 93 92
c implemented alias attributes
e
s 00008/00008/00585
d D 5.17 99/10/01 18:58:17 msokolov 92 91
c get the SCCS ID right
e
s 00011/00009/00582
d D 5.16 88/07/14 17:32:43 bostic 91 89
c add approved copyright
e
s 00014/00009/00582
d R 5.16 88/06/30 14:58:15 bostic 90 89
c install approved copyright notice
e
s 00000/00004/00591
d D 5.15 88/04/01 16:22:10 bostic 89 88
c always use flock when rebuilding alias file
e
s 00022/00017/00573
d D 5.14 88/03/13 19:51:26 bostic 88 87
c add Berkeley specific header
e
s 00005/00000/00585
d D 5.13 86/04/17 20:17:54 eric 87 86
c don't ignore aliasing during queue runs in conjunction with -bd
e
s 00001/00001/00584
d D 5.12 86/03/08 09:27:59 eric 86 85
c do dbminit in a reasonable place
e
s 00008/00008/00577
d D 5.11 86/03/02 14:06:46 eric 85 84
c always ignore SIGCHLD in openmailer; get SccsId correct in alias.c
e
s 00001/00001/00584
d D 5.10 86/01/11 00:18:15 eric 84 83
c only check the RHS of aliases during newalias if the "n" option is set;
c this option should probably be set if you are not running the nameserver
e
s 00018/00001/00567
d D 5.9 86/01/05 18:48:46 eric 83 82
m 
c rewrite reply-to and resent-reply-to; save errorqueueu in qf file;
c some performance hacking; some alias handling cleanup; delete leading
c spaces from SMTP lines
e
s 00000/00001/00568
d D 5.8 85/12/17 23:54:27 eric 82 81
m 
c lint
e
s 00014/00001/00555
d D 5.7 85/11/22 08:26:00 eric 81 80
m 
c give error if alias file cannot be opened; log message when rebuilt
e
s 00012/00018/00544
d D 5.6 85/10/24 10:35:58 eric 80 79
m 
c don't create a queue name in syserr; permit trailing blanks and quoted
c commas in aliases.
e
s 00002/00000/00560
d D 5.5 85/10/19 09:53:53 eric 79 78
m 
c strip off spaces again so that blanks at end of line work
e
s 00000/00000/00560
d D 5.4 85/09/19 01:25:42 eric 78 76
i 77
m 
c incorporate SMI changes -- still experimental
e
s 00020/00006/00540
d D 5.3.1.1 85/09/19 00:56:04 eric 77 76
m 
c SMI changes (somewhat)
e
s 00001/00001/00545
d D 5.3 85/06/08 00:39:10 eric 76 75
m 
c lint
e
s 00005/00006/00541
d D 5.2 85/06/07 22:00:06 miriam 75 74
m 
c Resolve duplicate SccsId
e
s 00014/00000/00533
d D 5.1 85/06/07 14:27:12 dist 74 73
m 
c Add copyright
e
s 00066/00035/00467
d D 4.10 85/04/29 22:48:20 eric 73 72
m 
c lock alias file while rebuilding if flock system call available
e
s 00004/00005/00498
d D 4.9 85/04/28 10:43:58 eric 72 71
m 
c arrange tests to recover from trashed DBM files; avoid sending
c nonstandard 050 messages in SMTP transaction
e
s 00001/00001/00502
d D 4.8 85/02/15 09:27:39 eric 71 70
m 
c fix some bugs with -C flag; one with queuing from Teus
e
s 00008/00003/00495
d D 4.7 84/12/05 23:15:10 eric 70 69
m 
c Try to use flock call (this doesn't work because we don't always have an
c open fd); security and performance fixes from Kirk Smith at Purdue; "a"
c option is now the number of minutes to wait for "@:@" alias; fix bug in
c $[ $] using -t; random cleanup
e
s 00005/00010/00493
d D 4.6 84/09/18 19:52:52 eric 69 68
m 
c fix multiline aliases
e
s 00003/00003/00500
d D 4.5 84/08/11 17:49:17 eric 68 66
m 
c Assorted changes from Guy Harris <rlgvax!guy>: mostly lint & USG
e
s 00113/00015/00488
d D 4.4.1.1 84/06/17 16:18:10 eric 67 66
m 
c abortive attempt to install a name server.... sigh.
e
s 00001/00000/00502
d D 4.4 84/03/17 16:26:38 eric 66 65
m 
c always fold case on host names; fold case on the LHS of aliases
e
s 00001/00001/00501
d D 4.3 84/03/11 16:55:19 eric 65 64
m 
c change macro expansion character from $ to \001 so that $'s can be
c used in headers -- the .cf file is unchanged by mapping $ to \001.
c \001 is now a manifest constant.
e
s 00004/00001/00498
d D 4.2 83/12/27 21:19:54 eric 64 63
m 
c fix bug with un-DBM'ed alias files that adds a newline on the end of
c the last entry in the alias; found by John Gilmore, SMI
e
s 00000/00000/00499
d D 4.1 83/07/25 19:46:14 eric 63 62
m 
c 4.2 release version
e
s 00002/00000/00497
d D 3.47 83/04/17 17:15:50 eric 62 61
m 221
c fix bogus errno problems
e
s 00001/00001/00496
d D 3.46 83/03/10 00:47:49 eric 61 60
m 206
c Delete colon on front of aliases
e
s 00002/00004/00495
d D 3.45 83/03/08 19:21:35 eric 60 59
m 205
c Pass the delimiter character to parseaddr so that we can correctly
c decide between comma and space
e
s 00002/00002/00497
d D 3.44 82/12/24 08:14:05 eric 59 58
m 108
c Change parse to parseaddr for BB&N TCP/IP implementation; clean up
c comments in daemon.c to simplify the poor alternate protocol type.
e
s 00001/00001/00498
d D 3.43 82/12/13 18:23:22 eric 58 57
m 085
c The routine "sendto" is now a system call (yeuch!); change our sendto
c to "sendtolist"
e
s 00023/00030/00476
d D 3.42 82/11/28 00:18:06 eric 57 56
m 
c Many changes resulting from a complete code readthrough.  Most of these
c fix minor bugs or change the internal structure for clarity, etc.  There
c should be almost no externally visible changes (other than some cleaner
c error message printouts and the like).
e
s 00000/00027/00506
d D 3.41 82/11/24 18:43:11 eric 56 55
m 
c lint it
e
s 00002/00003/00531
d D 3.40 82/11/13 18:00:50 eric 55 54
m 066
c don't default to rebuilding alias file if needed; now requires the "D"
c option.  This "feature" causes big problems on loaded machines.
e
s 00003/00002/00531
d D 3.39 82/10/28 17:40:04 eric 54 53
m 039,
m 027
c Put the "@:@" trick on the "a" option.  Also, move TrustedUsers into
c sendmail.h (it should have gone here in the first place!)
e
s 00060/00008/00473
d D 3.38 82/10/09 20:27:30 eric 53 52
m 003
c Lock out interrupts during alias rebuild; add an alias "@:@" after
c rebuild that we can check for to insure that the alias file is up to
c date.  Times out after five minutes (is this reasonable on ucbvax?)
c and forces a rebuild.  It shouldn't matter in the long run if two
c people rebuild, so I think this is the right thing to do.
e
s 00001/00001/00480
d D 3.37 82/09/06 16:23:42 eric 52 51
c install new state-driven scanner; make everyone use it, thus fixing
c problems of quoted commas, etc.
e
s 00004/00004/00477
d D 3.36 82/08/08 01:01:01 eric 51 50
c change debug level to a debug vector; add levels on logging (and the
c -L flag); change logging to be by message-id; elevate message-id;
c some lint-type cleanup
e
s 00007/00006/00474
d D 3.35 82/06/07 07:53:44 eric 50 49
c make transcripts verbose always; misc. message cleanup, etc.
e
s 00000/00034/00480
d D 3.34 82/06/07 07:05:44 eric 49 47
c strip out xlate stuff -- this belongs at a different level
e
s 00028/00001/00513
d D 3.33.1.1 82/06/06 20:12:42 eric 48 47
c first cut at putting mailing list maintainers in -- there is a
c much better way though.
e
s 00002/00002/00512
d D 3.33 82/05/31 18:47:51 eric 47 46
c pass lint.  notice that definitions in llib-lc have changed for
c alarm() and sleep() calls {arg was unsigned, is now int}.
e
s 00000/00000/00514
d D 3.32 82/05/31 15:30:41 eric 46 44
i 45
c finish implementing envelopes.  it's not completely clear to me that
c this is really the way to go, but it seems clearly better than what
c i had before.  this delta includes many other minor changes, so it
c should probably not be blithely removed.
e
s 00001/00001/00513
d D 3.31.1.1 82/05/29 18:18:43 eric 45 44
c try to install envelopes.  is this really worth it???
e
s 00002/00002/00512
d D 3.31 82/05/22 01:35:52 eric 44 43
c add "envelopes" to contain the basic information needed as control
c info for each message.  currently there is only one envelope -- this
c being the obvious stupid conversion.  later there will be separate
c envelopes for error messages, return receipts, etc.
e
s 00001/00001/00513
d D 3.30 82/02/15 09:39:09 eric 43 42
c pass lint
e
s 00074/00018/00440
d D 3.29 82/02/04 20:29:09 eric 42 41
c add host aliasing; add -p flag.  this version doesn't yet know about
c replacing the text of the host alias into the message however.  syntax
c is grotty: "/hostmatch:%s@newhost" or whatever.
e
s 00002/00002/00456
d D 3.28 81/12/06 12:37:02 eric 41 40
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00010/00004/00448
d D 3.27 81/11/21 18:41:07 eric 40 38
c change the send queue to be only one queue instead of one per mailer.
c this is slightly inefficient but simpler.  also, pass this queue
c around so we can have multiple send queues.  this makes VRFY work.
e
s 00002/00001/00451
d D 3.26.1.1 81/11/21 15:44:47 eric 39 38
c links together aliases into proper trees.  This is in part an
c attempt to do the SMTP VRFY command properly, but there are a number
c of annoying problems that convince me that this is the wrong way to
c do it.  Sigh.
e
s 00002/00002/00450
d D 3.26 81/10/23 19:36:40 eric 38 37
c Eliminate magic MN_LOCAL and MN_PROG; change q_mailer item in ADDRESS
c to be pointer to mailer rather than index.
e
s 00002/00003/00450
d D 3.25 81/10/17 16:57:21 eric 37 36
c initial prep to put in Daemon mode
e
s 00001/00004/00452
d D 3.24 81/09/28 19:17:02 eric 36 35
c enable aliases to self-reference themselves correctly.
e
s 00001/00001/00455
d D 3.23 81/09/16 16:23:57 eric 35 34
c last delta was too paranoid -- this increases the number of
c cases that work (but is still safe -- I hope)
e
s 00002/00002/00454
d D 3.22 81/09/16 16:07:21 eric 34 33
c run as the user forwarding mail after a .forward operation;
c fix a bug in .forwarding that caused recursive expansion;
c restrict mail to programs, files, and with :include: for security
c reasons.
e
s 00002/00002/00454
d D 3.21 81/09/07 12:39:58 eric 33 32
c take mode 666 instead of 777 for database autorebuild
e
s 00070/00004/00386
d D 3.20 81/09/07 12:33:14 eric 32 31
c add auto-rebuild on alias database; fix some aliasing bugs;
c add statistics to rebuild; slight code restructuring; change
c version handling one last (?) time
e
s 00040/00008/00350
d D 3.19 81/09/06 19:47:25 eric 31 30
c cleanup, commenting, linting, etc.
e
s 00005/00001/00353
d D 3.18 81/08/22 19:36:21 eric 30 29
c only use a .forward file if owned by the receiver
e
s 00002/00002/00352
d D 3.17 81/08/21 18:17:36 eric 29 28
c drop M_FINAL, change some other defined constant names
e
s 00000/00002/00354
d D 3.16 81/08/20 15:12:57 eric 28 27
c clean up some header information; don't reopen tempfile as
c stdin (to fix some problems with saving mail on interrupts)
e
s 00002/00014/00354
d D 3.15 81/08/20 14:47:26 eric 27 25
c merge forwarding with :include:ing
e
s 00002/00014/00354
d R 3.15 81/08/20 14:36:40 eric 26 25
c merge forwarding with :include:ing
e
s 00002/00002/00366
d D 3.14 81/08/18 17:12:09 eric 25 24
c factor out ARPANET FTP reply codes into conf.c
e
s 00091/00025/00277
d D 3.13 81/08/18 10:38:59 eric 24 23
c put alias.{dir,pag} initialization into sendmail rather than
c a different program (on -I flag).
e
s 00019/00011/00283
d D 3.12 81/08/10 18:48:49 eric 23 22
c make the non-DBM case work
e
s 00001/00000/00293
d D 3.11 81/08/10 18:14:28 eric 22 21
c fix botch with $z macro that confused forwarding
e
s 00173/00065/00120
d D 3.10 81/08/10 16:55:45 eric 21 20
c totally rework aliasing scheme -- sucks when no DBM now,
c but works better for the usual case; fix some quoting problems
c (and how many did I add?); remove .mailer feature since .forward
c will simulate this happily
e
s 00046/00153/00139
d D 3.9 81/08/10 12:26:47 eric 20 19
c intermediate version -- NOT RUNNABLE
e
s 00008/00010/00284
d D 3.8 81/08/09 15:01:43 eric 19 18
c lint it
e
s 00004/00016/00290
d D 3.7 81/08/09 12:33:56 eric 18 17
c add private incoming mailers; add q_home field to ADDRESS struct;
c some general cleanup
e
s 00037/00001/00269
d D 3.6 81/08/08 16:09:04 eric 17 16
c install forwarding using .forward technique
e
s 00006/00000/00264
d D 3.5 81/08/08 15:04:40 eric 16 15
c implement blow-by-blow verbose mode
e
s 00001/00001/00263
d D 3.4 81/03/20 09:44:17 eric 15 14
c change name (again); from postbox to sendmail
e
s 00054/00090/00210
d D 3.3 81/03/11 10:44:52 eric 14 13
c general cleanup, esp. macro processor
e
s 00001/00001/00299
d D 3.2 81/03/07 16:58:24 eric 13 11
c change q_mailer to be index, not pointer
e
s 00003/00001/00299
d R 3.2 81/03/07 15:31:10 eric 12 11
c lint fixes
e
s 00011/00007/00289
d D 3.1 81/03/07 14:25:04 eric 11 10
c ----- delivermail ==> postbox -----
e
s 00031/00004/00265
d D 2.2 80/12/06 17:24:30 eric 10 9
c allow aliases of the form "eric:eric,i.eric"
e
s 00000/00000/00269
d D 2.1 80/11/05 11:00:43 eric 9 8
c release 2
e
s 00004/00000/00265
d D 1.8 80/10/28 23:52:32 eric 8 7
c fixed ANOTHER bug in aliasing (this is getting dull....)
e
s 00005/00001/00260
d D 1.7 80/10/27 19:09:44 eric 7 6
c fix botch with multiple aliases
e
s 00000/00001/00261
d D 1.6 80/10/21 12:12:20 eric 6 5
c fix bug in alias key
e
s 00043/00027/00219
d D 1.5 80/10/18 16:49:04 eric 5 4
c cleanup for dbm stuff: Error => Errors; move local host
c detection into parse; misc cleanup
e
s 00041/00009/00205
d D 1.4 80/10/17 13:41:46 mark 4 3
c uses dbm package for alias file to make it faster
e
s 00006/00028/00208
d D 1.3 80/08/02 13:47:37 eric 3 2
c cleaned up comments
e
s 00002/00000/00234
d D 1.2 80/07/25 22:02:01 eric 2 1
c add ID keywords
e
s 00234/00000/00000
d D 1.1 80/06/23 08:23:07 eric 1 0
e
u
U
f b 
f i 
t
T
I 74
/*
I 91
 * Copyright (c) 1983 Eric P. Allman
E 91
D 88
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 88
I 88
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 91
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 91
I 91
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
E 91
 */
E 88

I 88
D 92
#ifndef lint
#ifdef DBM
static char sccsid[] = "%W% (Berkeley) %G% (with DBM)";
#else
static char sccsid[] = "%W% (Berkeley) %G% (without DBM)";
#endif
#endif /* not lint */

E 92
E 88
D 85
#ifndef lint
D 75
static char	SccsId[] = "%W% (Berkeley) %G%";
E 75
I 75
# ifdef DBM
static char	SccsId[] = "%W% (Berkeley) %G%	(with DBM)";
# else DBM
static char	SccsId[] = "%W% (Berkeley) %G%	(without DBM)";
# endif DBM
E 75
#endif not lint

E 85
E 74
I 1
D 28
# include <stdio.h>
# include <ctype.h>
E 28
# include <pwd.h>
I 30
# include <sys/types.h>
# include <sys/stat.h>
I 53
# include <signal.h>
I 73
# include <errno.h>
E 73
E 53
E 30
D 11
# include "dlvrmail.h"
E 11
I 11
D 15
# include "postbox.h"
E 15
I 15
# include "sendmail.h"
I 73
D 89
# ifdef FLOCK
E 89
# include <sys/file.h>
I 92

#ifndef lint
#ifdef DBM
static char sccsid[] = "%W% (Berkeley) %G% (with DBM)";
#else
static char sccsid[] = "%W% (Berkeley) %G% (without DBM)";
#endif
#endif /* not lint */
E 92
D 89
# endif FLOCK
E 89
I 85
D 88

#ifndef lint
# ifdef DBM
static char	SccsId[] = "%W% (Berkeley) %G%	(with DBM)";
# else DBM
static char	SccsId[] = "%W% (Berkeley) %G%	(without DBM)";
# endif DBM
#endif not lint
E 85
E 73
E 15
E 11

E 88
I 2
D 23
static char SccsId[] = "%W%	%G%";
E 23
I 23
D 75
# ifdef DBM
D 41
static char SccsId[] = "%W%	%G%	(with DBM)";
E 41
I 41
SCCSID(%W%	%Y%	%G%	(with DBM));
E 41
# else DBM
D 41
static char SccsId[] = "%W%	%G%	(without DBM)";
E 41
I 41
SCCSID(%W%	%Y%	%G%	(without DBM));
E 41
# endif DBM
E 75
E 23

E 2
/*
**  ALIAS -- Compute aliases.
**
D 4
**	Scans the file /usr/lib/mailaliases for a set of aliases.
E 4
I 4
D 20
**	Scans the file ALIASFILE for a set of aliases.
E 20
I 20
D 21
**	Scans the file AliasFile for a set of aliases.
E 21
I 21
D 57
**	Scans the file /usr/lib/aliases for a set of aliases.
E 21
E 20
E 4
D 14
**	If found, it arranges to deliver to them by inserting the
D 4
**	new names onto the SendQ queue.
E 4
I 4
**	new names onto the SendQ queue.  Uses libdbm database if -DDBM.
E 14
I 14
**	If found, it arranges to deliver to them.  Uses libdbm
**	database if -DDBM.
E 57
I 57
**	Scans the alias file for an alias for the given address.
**	If found, it arranges to deliver to the alias list instead.
**	Uses libdbm database if -DDBM.
E 57
E 14
E 4
**
**	Parameters:
D 20
**		none
E 20
I 20
**		a -- address to alias.
I 40
**		sendq -- a pointer to the head of the send queue
**			to put the aliases in.
E 40
E 20
**
**	Returns:
**		none
**
**	Side Effects:
D 14
**		Aliases found on SendQ are removed and put onto
**		AliasQ; replacements are added to SendQ.  This is
**		done until no such replacement occurs.
E 14
I 14
**		Aliases found are expanded.
E 14
**
D 21
**	Defined Constants:
**		MAXRCRSN -- the maximum recursion depth.
D 5
**		ALIASFILE -- the pathname of the alias file.
E 5
**
E 21
D 3
**	Requires:
**		fopen (stdio)
**		fgets (stdio)
**		rewind (stdio)
**		isspace (sys)
**		printf (sys)
**		sendto
**		syserr
**		parse
**		nxtinq
**		sameaddr
**		tkoffq
**		putonq
**		fclose (sys)
**
E 3
D 14
**	Called By:
**		main
**
E 14
D 57
**	Files:
D 3
**		/usr/lib/mailaliases -- the mail aliases.
E 3
I 3
D 20
**		ALIASFILE -- the mail aliases.  The format is
E 20
I 20
D 21
**		AliasFile -- the mail aliases.  The format is
E 21
I 21
**		/usr/lib/aliases -- the mail aliases.  The format is
E 21
E 20
**			a series of lines of the form:
**				alias:name1,name2,name3,...
**			where 'alias' expands to all of
**			'name[i]'.  Continuations begin with
**			space or tab.
I 4
D 20
**		ALIASFILE.pag, ALIASFILE.dir: libdbm version
E 20
I 20
D 21
**		AliasFile.pag, AliasFile.dir: libdbm version
E 21
I 21
**		/usr/lib/aliases.pag, /usr/lib/aliases.dir: libdbm version
E 21
E 20
**			of alias file.  Keys are aliases, datums
**			(data?) are name1,name2, ...
E 4
E 3
**
E 57
**	Notes:
**		If NoAlias (the "-n" flag) is set, no aliasing is
**			done.
**
**	Deficiencies:
**		It should complain about names that are aliased to
**			nothing.
D 57
**		It is unsophisticated about line overflows.
E 57
D 3
**
**	History:
**		3/5/80 -- extensive mods to change internal address
**			format.
**		12/27/79 -- written.
E 3
*/


D 5
# define ALIASFILE	"/usr/lib/mailaliases"
E 5
D 21
# define MAXRCRSN	10

E 21
I 4
#ifdef DBM
D 11
typedef struct {char *dptr; int dsize;} datum;
E 11
I 11
typedef struct
{
	char	*dptr;
D 24
	int dsize;
} datum;
E 11
datum lhs, rhs;
D 5
datum fetch();
E 5
I 5
extern datum fetch();
E 24
I 24
	int	dsize;
} DATUM;
D 42
DATUM lhs, rhs;
E 42
extern DATUM fetch();
E 24
E 5
#endif DBM
E 4

D 20
alias()
E 20
I 20
D 40
alias(a)
E 40
I 40
alias(a, sendq)
E 40
	register ADDRESS *a;
I 40
	ADDRESS **sendq;
E 40
E 20
{
D 11
	register addrq *q;
I 7
	addrq *q2;
E 11
I 11
D 21
	register ADDRESS *q;
E 21
D 19
	ADDRESS *q2;
E 19
I 19
	register char *p;
I 39
	extern ADDRESS *sendto();
E 39
I 20
D 21
	extern char *AliasFile;
E 21
E 20
D 42
# ifndef DBM
E 19
E 11
E 7
D 21
	FILE *af;
	char line[MAXLINE+1];
D 19
	register char *p;
	extern int errno;
E 19
	bool didalias;
	bool gotmatch;
D 11
	auto addrq al;
E 11
I 11
	auto ADDRESS al;
E 21
I 21
	register STAB *s;
E 21
E 11
D 19
	extern bool sameaddr();
D 11
	extern addrq *parse();
E 11
I 11
	extern ADDRESS *parse();
E 19
I 19
D 20
# else
E 19
I 14
	int mno;
E 20
I 19
# endif DBM
E 42
I 42
	extern char *aliaslookup();
I 93
	struct aliasattrs attrs;
	extern char *username();
E 93
E 42
E 19
E 14
E 11

D 77
	if (NoAlias)
		return;
E 77
# ifdef DEBUG
D 51
	if (Debug)
E 51
I 51
	if (tTd(27, 1))
E 51
D 21
		printf("--- alias ---\n");
E 21
I 21
		printf("alias(%s)\n", a->q_paddr);
E 21
# endif

I 21
	/* don't realias already aliased names */
	if (bitset(QDONTSEND, a->q_flags))
		return;

D 44
	To = a->q_paddr;
E 44
I 44
	CurEnv->e_to = a->q_paddr;
E 44

I 31
	/*
	**  Look up this name
	*/

E 31
E 21
D 20
	/* open alias file if not already open */
I 4
#ifndef DBM
E 4
# ifdef DEBUG
	if (Debug && (af = fopen("mailaliases", "r")) != NULL)
		printf(" [using local alias file]\n");
	else
# endif
	if ((af = fopen(ALIASFILE, "r")) == NULL)
	{
# ifdef DEBUG
		if (Debug)
			printf("Can't open %s\n", ALIASFILE);
# endif
		errno = 0;
		return;
	}
I 4
#else DBM
	dbminit(ALIASFILE);
#endif DBM
E 20
I 20
D 42
# ifdef DBM
D 21
	dbminit(AliasFile);
E 21
I 21
	/* create a key for fetch */
	lhs.dptr = a->q_user;
	lhs.dsize = strlen(a->q_user) + 1;
	rhs = fetch(lhs);

	/* find this alias? */
	p = rhs.dptr;
E 42
I 42
D 77
	p = aliaslookup(a->q_user);
E 77
I 77
	if (NoAlias)
		p = NULL;
	else
D 93
		p = aliaslookup(a->q_user);
E 93
I 93
		p = aliaslookup(a->q_user, &attrs);
E 93
E 77
E 42
	if (p == NULL)
		return;
D 42
# else DBM
	s = stab(a->q_user, ST_ALIAS, ST_FIND);
	if (s == NULL)
		return;
	p = s->s_alias;
E 21
# endif DBM
E 42
E 20
E 4

I 4
D 20
#ifndef DBM
E 20
E 4
	/*
D 20
	**  Scan alias file.
	**	If we find any user that any line matches any user, we
	**	will send to the line rather than to the user.
	**
	**	We pass through the file several times.  Didalias tells
	**	us if we took some alias on this pass through the file;
	**	when it goes false at the top of the loop we don't have
	**	to scan any more.  Gotmatch tells the same thing, but
	**	on a line-by-line basis; it is used for processing
	**	continuation lines.
	*/

D 4
	didalias = TRUE;
	while (didalias)
E 4
I 4
	do
E 4
	{
		didalias = FALSE;
		gotmatch = FALSE;
		rewind(af);
		while (fgets(line, sizeof line, af) != NULL)
		{
			/* comments begin with `#' */
			if (line[0] == '#')
				continue;

			/* check for continuation lines */
			if (isspace(line[0]))
			{
				if (gotmatch)
				{
D 4
# ifdef DEBUG
					if (Debug)
						printf("   ... also aliased to %s", line);
# endif
E 4
					sendto(line, 1);
				}
				continue;
			}
			gotmatch = FALSE;

			/*
D 14
			**  Check to see if this pseudonym exists in SendQ.
E 14
I 14
			**  Check to see if this pseudonym exists.
E 14
			**	Turn the alias into canonical form.
D 14
			**	Then scan SendQ until you do (or do not)
			**	find that address.
E 14
I 14
			**	Then scan the send queue until you
			**	do (or do not) find that address.
E 14
			*/

			/*  Get a canonical form for the alias. */
			for (p = line; *p != '\0' && *p != ':' && *p != '\n'; p++)
				continue;
			if (*p == '\0' || *p == '\n')
			{
			 syntaxerr:
				syserr("Bad alias line `%s'", line);
				continue;
			}
			*p++ = '\0';
			if (parse(line, &al, -1) == NULL)
			{
				*--p = ':';
				goto syntaxerr;
			}

I 10
D 14
			/* if already in AliasQ don't realias */
			for (q = &AliasQ; (q = nxtinq(q)) != NULL; )
E 14
I 14
			/* if already queued up, don't realias */
			for (q = Mailer[al.q_mailer]->m_sendq; q != NULL; q = q->q_next)
E 14
			{
				if (sameaddr(&al, q, TRUE))
					break;
			}
D 14
			if (q != NULL)
E 14
I 14
			if (q == NULL || bitset(QDONTSEND, q->q_flags))
E 14
				continue;

E 10
D 14
			/*  Scan SendQ for that canonical form. */
			for (q = &SendQ; (q = nxtinq(q)) != NULL; )
			{
				if (sameaddr(&al, q, TRUE))
					break;
			}
			if (q != NULL)
			{
I 4
D 5
#else DBM
	/*
	**  Scan SendQ
	**	We pass through the queue several times.  Didalias tells
	**	us if we took some alias on this pass through the queue;
	**	when it goes false at the top of the loop we don't have
	**	to scan any more.
	*/

	do
	{
		didalias = FALSE;
		/*  Scan SendQ for that canonical form. */
		for (q = &SendQ; (q = nxtinq(q)) != NULL; )
		{
			lhs.dptr = q -> q_paddr;
			lhs.dsize = strlen(lhs.dptr)+1;
			rhs = fetch(lhs);
			p = rhs.dptr;
			if (p != NULL)
			{
#endif
E 5
E 4
				/*
				**  Match on Alias.
				**	Deliver to the target list.
				**	Remove the alias from the send queue
				**	  and put it on the Alias queue.
				*/
E 14
I 14
			/*
			**  Match on Alias.
			**	Deliver to the target list.
			**	Remove the alias from the send queue
			**	  and put it on the Alias queue.
			*/
E 14

# ifdef DEBUG
D 14
				if (Debug)
					printf("%s (%s, %s) aliased to %s (%s,%s,%s)\n",
					    q->q_paddr, q->q_host, q->q_user,
					    p, al.q_paddr, al.q_host, al.q_user);
E 14
I 14
			if (Debug)
				printf("%s (%s, %s) aliased to %s (%s,%s,%s)\n",
				    q->q_paddr, q->q_host, q->q_user,
				    p, al.q_paddr, al.q_host, al.q_user);
E 14
# endif
I 16
			if (Verbose)
				message("050", "aliased to %s", p);
E 16
D 14
				tkoffq(q, &SendQ);
D 10
				putonq(q, &AliasQ);
E 10
				didalias++;
				gotmatch++;
				sendto(p, 1);
I 10
				putonq(q, &AliasQ);
E 10
			}
E 14
I 14
			q->q_flags |= QDONTSEND;
			didalias++;
			gotmatch++;
			sendto(p, 1);
E 14
		}
D 4
	}
E 4
I 4
	} while (didalias);
D 5
#ifndef DBM
E 5
E 4
D 19
	fclose(af);
E 19
I 19
	(void) fclose(af);
E 19
I 4
D 5
#endif
E 5
I 5
#else DBM
	/*
D 14
	**  Scan SendQ
E 14
I 14
	**  Scan send queues
E 20
I 20
D 21
	**  Scan send queue for local mailer.
E 20
E 14
	**	We only have to do this once, since anything we alias
D 10
	**	two is being put at the end of the queue we are
E 10
I 10
	**	to is being put at the end of the queue we are
E 10
D 20
	**	scanning.
E 20
I 20
	**	scanning or another queue.  This is because we only
	**	scan the local mailer queue.
E 21
I 21
	**  Match on Alias.
	**	Deliver to the target list.
I 93
	**	Enforce restrictions first.
E 93
E 21
E 20
I 10
D 14
	**	If the alias on SendQ is also (already) on AliasQ, we
	**	have an alias such as:
	**		eric:eric,i:eric
	**	In this case we have already done this alias once, and
	**	we don't want to do it again (for obvious reasons!).
E 14
E 10
	*/
I 93
	if (attrs.aa_flags & AA_RESTRICTED && (OrigOpMode == MD_DAEMON ||
	    !trusteduser(username())))
	{
		a->q_flags |= QDONTSEND|QBADADDR;
		usrerr("Alias %s is restricted", a->q_user);
		return;
	}
E 93

D 7
	for (q = &SendQ; (q = nxtinq(q)) != NULL; )
E 7
I 7
D 10
	for (q2 = nxtinq(&SendQ); (q = q2) != NULL; )
E 10
I 10
D 14
	for (q2 = nxtinq(&SendQ); q2 != NULL; )
E 14
I 14
D 20
	for (mno = 0; Mailer[mno] != NULL; mno++)
E 20
I 20
D 21
	for (q = Mailer[M_LOCAL]->m_sendq; q != NULL; q = q->q_next)
E 21
I 21
# ifdef DEBUG
D 51
	if (Debug)
E 51
I 51
	if (tTd(27, 1))
E 51
		printf("%s (%s, %s) aliased to %s\n",
		    a->q_paddr, a->q_host, a->q_user, p);
# endif
D 50
	if (Verbose)
D 25
		message("050", "aliased to %s", p);
E 25
I 25
		message(Arpa_Info, "aliased to %s", p);
E 50
I 50
	message(Arpa_Info, "aliased to %s", p);
I 93
	if (attrs.aa_flags & AA_HASUID)
	{
		a->q_flags |= QGOODUID;
		a->q_uid = attrs.aa_uid;
		a->q_gid = attrs.aa_gid;
	}
E 93
E 50
E 25
D 36
	a->q_flags |= QDONTSEND;
E 36
	AliasLevel++;
D 34
	sendto(p, 1);
E 34
I 34
D 35
	sendto(p, 1, a);
E 35
I 35
D 36
	sendto(p, 1, (a->q_alias == NULL) ? &From : a);
E 36
I 36
D 39
D 40
	sendto(p, 1, a);
E 40
I 40
D 52
	sendto(p, 1, a, sendq);
E 52
I 52
D 58
	sendto(p, a, sendq);
E 58
I 58
	sendtolist(p, a, sendq);
E 58
E 52
E 40
E 39
I 39
	a->q_child = sendto(p, 1, a, 0);
E 39
E 36
E 35
E 34
	AliasLevel--;
}
/*
I 42
**  ALIASLOOKUP -- look up a name in the alias file.
**
**	Parameters:
**		name -- the name to look up.
I 93
**		attrs -- pointer, if not NULL, alias attributes
**			(struct aliasattrs) will be stored there.
E 93
**
**	Returns:
**		the value of name.
**		NULL if unknown.
**
**	Side Effects:
**		none.
**
**	Warnings:
**		The return value will be trashed across calls.
*/

char *
D 93
aliaslookup(name)
E 93
I 93
aliaslookup(name, attrs)
E 93
	char *name;
I 93
	struct aliasattrs *attrs;
E 93
{
# ifdef DBM
	DATUM rhs, lhs;
I 93
	register u_char *dp;
E 93

	/* create a key for fetch */
	lhs.dptr = name;
	lhs.dsize = strlen(name) + 1;
	rhs = fetch(lhs);
I 93
	if (attrs != NULL && rhs.dptr != NULL)
	{
		if (rhs.dsize == strlen(rhs.dptr) + 6)
		{
			dp = (u_char *)rhs.dptr + strlen(rhs.dptr) + 1;
			attrs->aa_flags = dp[0];
			bcopy(dp + 1, &attrs->aa_uid, 2);
			bcopy(dp + 3, &attrs->aa_gid, 2);
		}
		else
			bzero(attrs, sizeof(struct aliasattrs));
	}
E 93
	return (rhs.dptr);
# else DBM
	register STAB *s;

	s = stab(name, ST_ALIAS, ST_FIND);
	if (s == NULL)
		return (NULL);
	return (s->s_alias);
# endif DBM
}
/*
E 42
**  INITALIASES -- initialize for aliasing
**
**	Very different depending on whether we are running DBM or not.
**
**	Parameters:
**		aliasfile -- location of aliases.
I 24
**		init -- if set and if DBM, initialize the DBM files.
E 24
**
**	Returns:
**		none.
**
**	Side Effects:
**		initializes aliases:
**		if DBM:  opens the database.
**		if ~DBM: reads the aliases into the symbol table.
*/

D 24
initaliases(aliasfile)
E 24
I 24
# define DBMMODE	0666

initaliases(aliasfile, init)
E 24
	char *aliasfile;
I 24
	bool init;
E 24
{
I 57
#ifdef DBM
E 57
I 53
	int atcnt;
E 53
I 32
D 81
	char buf[MAXNAME];
E 81
D 57
	struct stat stb;
E 57
	time_t modtime;
I 81
	bool automatic = FALSE;
	char buf[MAXNAME];
E 81
I 53
D 73
	int (*oldsigint)();
E 73
I 57
#endif DBM
	struct stat stb;
I 87
	static bool initialized = FALSE;

	if (initialized)
		return;
	initialized = TRUE;
E 87
E 57
E 53

I 53
D 71
	if (stat(aliasfile, &stb) < 0)
E 71
I 71
	if (aliasfile == NULL || stat(aliasfile, &stb) < 0)
E 71
	{
I 81
		if (aliasfile != NULL && init)
			syserr("Cannot open %s", aliasfile);
E 81
		NoAlias = TRUE;
I 62
		errno = 0;
E 62
		return;
	}

I 54
# ifdef DBM
E 54
E 53
	/*
I 53
	**  Check to see that the alias file is complete.
	**	If not, we will assume that someone died, and it is up
	**	to us to rebuild it.
	*/

D 83
	dbminit(aliasfile);
E 83
I 83
	if (!init)
		dbminit(aliasfile);
E 83
D 54
	for (atcnt = 10; !init && atcnt-- >= 0 && aliaslookup("@") == NULL; )
E 54
I 54
D 70
	atcnt = 10;
	while (SafeAlias && !init && atcnt-- >= 0 && aliaslookup("@") == NULL)
E 54
		sleep(30);
E 70
I 70
	atcnt = SafeAlias * 2;
	if (atcnt > 0)
	{
D 93
		while (!init && atcnt-- >= 0 && aliaslookup("@") == NULL)
E 93
I 93
		while (!init && atcnt-- >= 0 && aliaslookup("@", NULL) == NULL)
E 93
I 83
		{
			/*
			**  Reinitialize alias file in case the new
			**  one is mv'ed in instead of cp'ed in.
			**
			**	Only works with new DBM -- old one will
			**	just consume file descriptors forever.
			**	If you have a dbmclose() it can be
			**	added before the sleep(30).
			*/

E 83
			sleep(30);
I 83
# ifdef NDBM
			dbminit(aliasfile);
# endif NDBM
		}
E 83
	}
	else
		atcnt = 1;
E 70

D 54
# ifdef DBM
E 54
	/*
E 53
	**  See if the DBM version of the file is out of date with
	**  the text version.  If so, go into 'init' mode automatically.
	**	This only happens if our effective userid owns the DBM
D 33
	**	version or if the mode of the database is 777 -- this
E 33
I 33
	**	version or if the mode of the database is 666 -- this
E 33
	**	is an attempt to avoid protection problems.  Note the
	**	unpalatable hack to see if the stat succeeded.
	*/

D 53
	if (stat(aliasfile, &stb) < 0)
		return;
E 32
# ifdef DBM
E 53
I 24
D 32
	if (init)
E 32
I 32
	modtime = stb.st_mtime;
	(void) strcpy(buf, aliasfile);
	(void) strcat(buf, ".pag");
	stb.st_ino = 0;
D 53
	if ((stat(buf, &stb) < 0 || stb.st_mtime < modtime) && !init)
E 53
I 53
D 55
	if ((stat(buf, &stb) < 0 || stb.st_mtime < modtime || atcnt < 0) &&
	    !init)
E 55
I 55
D 72
	if (!init && (atcnt < 0 || stat(buf, &stb) < 0 || stb.st_mtime < modtime))
E 72
I 72
	if (!init && (stat(buf, &stb) < 0 || stb.st_mtime < modtime || atcnt < 0))
E 72
E 55
E 53
E 32
	{
I 62
		errno = 0;
E 62
D 32
		char buf[MAXNAME];
E 32
I 32
D 55
		if (stb.st_ino != 0 &&
E 55
I 55
		if (AutoRebuild && stb.st_ino != 0 &&
E 55
D 33
		    ((stb.st_mode & 0777) == 0777 || stb.st_uid == geteuid()))
E 33
I 33
D 57
		    ((stb.st_mode & 0666) == 0666 || stb.st_uid == geteuid()))
E 57
I 57
		    ((stb.st_mode & 0777) == 0666 || stb.st_uid == geteuid()))
E 57
E 33
		{
			init = TRUE;
I 81
			automatic = TRUE;
E 81
D 50
			if (Verbose)
				message(Arpa_Info, "rebuilding alias database");
E 50
I 50
			message(Arpa_Info, "rebuilding alias database");
I 77
#ifdef LOG
			if (LogLevel >= 7)
				syslog(LOG_INFO, "rebuilding alias database");
#endif LOG
E 77
E 50
		}
		else
		{
I 50
D 72
			bool oldverb = Verbose;

			Verbose = TRUE;
E 72
I 72
#ifdef LOG
D 77
			syslog(LOG_INFO, "alias database out of date");
E 77
I 77
			if (LogLevel >= 7)
				syslog(LOG_INFO, "alias database out of date");
E 77
#endif LOG
E 72
E 50
			message(Arpa_Info, "Warning: alias database out of date");
I 50
D 72
			Verbose = oldverb;
E 72
E 50
		}
	}
D 53
# endif DBM
E 53
E 32

I 32
D 73
	/*
	**  If initializing, create the new files.
	**	We should lock the alias file here to prevent other
	**	instantiations of sendmail from reading an incomplete
	**	file -- or worse yet, doing a concurrent initialize.
	*/
E 73

D 53
# ifdef DBM
E 53
D 73
	if (init)
	{
I 53
		oldsigint = signal(SIGINT, SIG_IGN);
E 53
E 32
		(void) strcpy(buf, aliasfile);
		(void) strcat(buf, ".dir");
		if (close(creat(buf, DBMMODE)) < 0)
		{
			syserr("cannot make %s", buf);
I 57
			(void) signal(SIGINT, oldsigint);
E 57
			return;
		}
		(void) strcpy(buf, aliasfile);
		(void) strcat(buf, ".pag");
		if (close(creat(buf, DBMMODE)) < 0)
		{
			syserr("cannot make %s", buf);
I 57
			(void) signal(SIGINT, oldsigint);
E 57
			return;
		}
	}
I 32

E 73
	/*
D 53
	**  Open and, if necessary, load the DBM file.
E 53
I 53
	**  If necessary, load the DBM file.
E 53
	**	If running without DBM, load the symbol table.
I 53
D 73
	**	After loading the DBM file, add the distinquished alias "@".
E 73
E 53
	*/

E 32
E 24
D 53
	dbminit(aliasfile);
E 53
I 24
	if (init)
I 53
	{
I 81
#ifdef LOG
		if (LogLevel >= 6)
		{
			extern char *username();

			syslog(LOG_NOTICE, "alias database %srebuilt by %s",
				automatic ? "auto" : "", username());
		}
#endif LOG
E 81
D 73
		DATUM key;

E 73
E 53
		readaliases(aliasfile, TRUE);
I 53
D 73
		key.dsize = 2;
		key.dptr = "@";
		store(key, key);
		(void) signal(SIGINT, oldsigint);
E 73
	}
E 53
E 24
# else DBM
I 24
	readaliases(aliasfile, init);
# endif DBM
I 53
}
/*
I 93
**  PARSEALIASATTRS -- parse alias attributes in parentheses.
**
**	This routine is called by readaliases when an opening parenthesis
**	has been encountered before the colon.  It is supposed to parse the
**	attributes specified in parentheses and advance the parse char
**	pointer past the closing parenthesis.
**
**	Parameters:
**		cp -- parse char pointer, points just past '('.
**		attrs -- points to struct aliasattrs.
**
**	Returns:
**		parse char pointer advanced past ')'.
**		NULL on errors (err msg has been printed).
**
**	Side Effects:
**		none.
*/

static char *
parsealiasattrs(cp, attrs)
	register char *cp;
	struct aliasattrs *attrs;
{
	register char *np;
	register struct passwd *pw;
	char savech;

	for (;;)
	{
		while (isspace(*cp) || *cp == ',')
D 94
			;
E 94
I 94
			cp++;
E 94
		if (*cp == '\0')
		{
			syserr("unterminated alias attribute specification");
			return (NULL);
		}
		if (*cp == ')')
			break;
		for (np = cp; *cp && !isspace(*cp) && *cp != ',' && *cp != ')';
		     cp++)
			;
		savech = *cp;
		*cp = '\0';
		if (!strncmp(np, "user=", 5))
		{
			pw = getpwnam(np+5);
			if (pw != NULL)
			{
				attrs->aa_flags |= AA_HASUID;
				attrs->aa_uid = pw->pw_uid;
				attrs->aa_gid = pw->pw_gid;
			}
			else
				syserr("user %s unknown", np+5);
		}
		else if (!strcmp(np, "R"))
			attrs->aa_flags |= AA_RESTRICTED;
		else if (!strcmp(np, "noexpn"))
			attrs->aa_flags |= AA_NOEXPN;
		else
			syserr("unknown alias attribute \'%s\'", np);
		*cp = savech;
	}
	return (cp+1);
}
/*
E 93
D 56
**  DBMCLOSE -- close the dbm file.
**
**	This is highly implementation dependent.  It should be in the
**	DBM library rather than here.  So why isn't it?
**
**	This is really only needed to save file descriptors.  It can be
**	safely (??) replaced by the null routine.
**
**	Parameters:
**		none.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Closes the DBM file.
*/

dbmclose()
{
	/* hack attack!! -- see comment above */
	extern int pagf, dirf;

	(void) close(pagf);
	(void) close(dirf);
E 53
}
/*
E 56
**  READALIASES -- read and process the alias file.
**
**	This routine implements the part of initaliases that occurs
**	when we are not going to use the DBM stuff.
**
**	Parameters:
**		aliasfile -- the pathname of the alias file master.
**		init -- if set, initialize the DBM stuff.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Reads aliasfile into the symbol table.
**		Optionally, builds the .dir & .pag files.
*/

static
readaliases(aliasfile, init)
	char *aliasfile;
	bool init;
{
E 24
D 57
	char line[BUFSIZ];
E 57
	register char *p;
D 82
	char *p2;
E 82
I 67
	char *lhs;
E 67
	char *rhs;
	bool skipping;
D 57
	ADDRESS al, bl;
E 57
I 57
	int naliases, bytes, longest;
E 57
D 23
	extern char *prescan();
	bool contin;
E 23
I 23
	FILE *af;
I 73
	int (*oldsigint)();
E 73
D 57
	int lineno;
E 57
I 57
	ADDRESS al, bl;
E 57
	register STAB *s;
I 32
D 57
	int naliases, bytes, longest;
E 57
I 57
	char line[BUFSIZ];
I 93
	struct aliasattrs attrs;
E 93
E 57
E 32
E 23

	if ((af = fopen(aliasfile, "r")) == NULL)
E 21
E 20
E 14
E 10
E 7
	{
I 10
D 14
		/* if already in AliasQ, don't realias */
		for (q = &AliasQ; (q = nxtinq(q)) != NULL; )
E 14
I 14
D 20
		for (q = Mailer[mno]->m_sendq; q != NULL; q = q->q_next)
E 14
		{
I 16
			To = q->q_paddr;
E 20
I 20
D 21
		To = q->q_paddr;
E 21
I 21
# ifdef DEBUG
D 51
		if (Debug)
E 51
I 51
		if (tTd(27, 1))
E 51
D 23
			printf("Can't open %s\n", AliasFile);
E 23
I 23
			printf("Can't open %s\n", aliasfile);
E 23
# endif
		errno = 0;
		NoAlias++;
		return;
	}
D 31
	/* read and interpret lines */
E 31
I 31

I 73
# ifdef DBM
D 89
# ifdef FLOCK
E 89
	/* see if someone else is rebuilding the alias file already */
	if (flock(fileno(af), LOCK_EX | LOCK_NB) < 0 && errno == EWOULDBLOCK)
	{
		/* yes, they are -- wait until done and then return */
		message(Arpa_Info, "Alias file is already being rebuilt");
		if (OpMode != MD_INITALIAS)
		{
			/* wait for other rebuild to complete */
			(void) flock(fileno(af), LOCK_EX);
		}
D 76
		fclose(af);
E 76
I 76
		(void) fclose(af);
E 76
		errno = 0;
		return;
	}
D 89
# endif FLOCK
E 89
# endif DBM

E 73
	/*
I 73
	**  If initializing, create the new DBM files.
	*/

	if (init)
	{
		oldsigint = signal(SIGINT, SIG_IGN);
		(void) strcpy(line, aliasfile);
		(void) strcat(line, ".dir");
		if (close(creat(line, DBMMODE)) < 0)
		{
			syserr("cannot make %s", line);
			(void) signal(SIGINT, oldsigint);
			return;
		}
I 83
D 86
		dbminit(aliasfile);
E 86
E 83
		(void) strcpy(line, aliasfile);
		(void) strcat(line, ".pag");
		if (close(creat(line, DBMMODE)) < 0)
		{
			syserr("cannot make %s", line);
			(void) signal(SIGINT, oldsigint);
			return;
		}
I 86
		dbminit(aliasfile);
E 86
	}

	/*
E 73
	**  Read and interpret lines
	*/

E 31
D 57
	lineno = 0;
E 57
I 57
	FileName = aliasfile;
	LineNumber = 0;
E 57
I 32
	naliases = bytes = longest = 0;
E 32
	skipping = FALSE;
	while (fgets(line, sizeof (line), af) != NULL)
	{
I 32
		int lhssize, rhssize;

E 32
D 57
		lineno++;
E 57
I 57
		LineNumber++;
I 80
		p = index(line, '\n');
		if (p != NULL)
			*p = '\0';
E 80
E 57
		switch (line[0])
		{
		  case '#':
D 80
		  case '\n':
E 80
		  case '\0':
			skipping = FALSE;
			continue;
E 21
E 20

E 16
D 14
			if (sameaddr(q, q2, TRUE))
				break;
		}
		if (q != NULL)
		{
			q2 = nxtinq(q2);
			continue;
		}
E 14
I 14
D 20
			/* don't realias already aliased names */
			if (bitset(QDONTSEND, q->q_flags))
				continue;
E 20
I 20
D 21
		/* don't realias already aliased names */
		if (bitset(QDONTSEND, q->q_flags))
E 21
I 21
		  case ' ':
		  case '\t':
			if (!skipping)
D 57
				syserr("aliases: %d: Non-continuation line starts with space", lineno);
E 57
I 57
				syserr("Non-continuation line starts with space");
E 57
			skipping = TRUE;
E 21
			continue;
I 21
		}
		skipping = FALSE;
E 21
E 20
E 14

E 10
I 7
D 14
		/* save ptr to next address */
I 10
		q = q2;
E 10
		q2 = nxtinq(q);
E 14
I 14
D 20
			/* only alias local users */
D 18
			if (q->q_mailer != 0)
E 18
I 18
			if (q->q_mailer != M_LOCAL)
E 18
				continue;
E 20
I 20
D 21
# ifdef DBM
		/* create a key for fetch */
		lhs.dptr = q->q_user;
		lhs.dsize = strlen(q->q_user) + 1;
		rhs = fetch(lhs);
E 20
E 14

E 7
D 14
		/* only alias local users */
D 13
		if (q->q_mailer != &Mailer[0])
E 13
I 13
		if (q->q_mailer != 0)
E 13
			continue;
E 14
I 14
D 20
			/* create a key for fetch */
			lhs.dptr = q->q_user;
			lhs.dsize = strlen(q->q_user) + 1;
			rhs = fetch(lhs);
E 20
I 20
		/* find this alias? */
		p = rhs.dptr;
		if (p == NULL)
E 21
I 21
D 31
		/* process the LHS */
E 31
I 31
		/*
		**  Process the LHS
I 67
		**
E 67
		**	Find the final colon, and parse the address.
D 67
		**	It should resolve to a local name -- this will
		**	be checked later (we want to optionally do
		**	parsing of the RHS first to maximize error
		**	detection).
E 67
I 67
		**	It should resolve to a local name.
		**
		**	Alternatively, it can be "@hostname" for host
		**	aliases -- all we do here is map case.  Hostname
		**	need not be a single token.
E 67
		*/

E 31
D 93
		for (p = line; *p != '\0' && *p != ':' && *p != '\n'; p++)
E 93
I 93
		for (p = line; *p && *p != ':' && *p != '(' && *p != '\n'; p++)
E 93
E 21
			continue;
I 93
		bzero(&attrs, sizeof attrs);
		if (*p == '(')
		{
			p = parsealiasattrs(p+1, &attrs);
			if (p == NULL)	/* parsealiasattrs caught an error */
				continue;
			while (isspace(*p))
				p++;
		}
E 93
D 21
# else DBM
		s = stab(q->q_user, ST_ALIAS, ST_FIND);
		if (s == NULL)
E 21
I 21
D 61
		if (*p == '\0' || *p == '\n')
E 61
I 61
D 67
		if (*p++ != ':')
E 67
I 67
		if (*p != ':')
E 67
E 61
		{
D 57
		 syntaxerr:
D 48
			syserr("aliases: %d: missing colon", lineno);
E 57
I 57
			syserr("missing colon");
E 57
E 48
I 48
			syserr("%s, line %d: syntax error", aliasfile, lineno);
E 48
E 21
			continue;
D 21
		p = s->s_alias;
# endif DBM
E 21
I 21
		}
D 60
		*p++ = '\0';
D 59
		if (parse(line, &al, 1) == NULL)
E 59
I 59
		if (parseaddr(line, &al, 1) == NULL)
E 60
I 60
D 67
		if (parseaddr(line, &al, 1, ':') == NULL)
E 67
I 67
		*p++ = '\0';
		if (line[0] == '@')
E 67
E 60
E 59
		{
D 60
			*--p = ':';
E 60
D 57
			goto syntaxerr;
E 57
I 57
D 67
			syserr("illegal alias name");
			continue;
E 67
I 67
			/* a host alias */
			makelower(line);
			lhs = line;
E 67
E 57
		}
I 66
D 67
		loweraddr(&al);
E 67
I 67
		else
		{
			/* a user alias */
			if (parseaddr(line, &al, 1, ':') == NULL)
			{
				syserr("illegal alias name");
				continue;
			}
			loweraddr(&al);
			if (al.q_mailer != LocalMailer)
			{
				syserr("cannot alias non-local names");
				continue;
			}
			lhs = al.q_user;
		}
E 67
E 66
I 31

		/*
		**  Process the RHS.
		**	'al' is the internal form of the LHS address.
		**	'p' points to the text of the RHS.
I 48
		**		'p' may begin with a colon (i.e., the
		**		separator was "::") which will use the
		**		first address as the person to send
		**		errors to -- i.e., designates the
		**		list maintainer.
E 48
		*/

I 48
		if (*p == ':')
		{
			ADDRESS *maint;

			while (isspace(*++p))
				continue;
			rhs = p;
			while (*p != '\0' && *p != ',')
				p++;
			if (*p != ',')
				goto syntaxerr;
			*p++ = '\0';
			maint = parse(p, (ADDRESS *) NULL, 1);
			if (maint == NULL)
				syserr("Illegal list maintainer for list %s", al.q_user);
			else if (CurEnv->e_returnto == &CurEnv->e_from)
			{
				CurEnv->e_returnto = maint;
				MailBack++;
			}
		}
			
E 48
E 31
		rhs = p;
D 23
		contin = FALSE;
E 23
		for (;;)
		{
			register char c;
E 21
E 20
E 14

I 23
D 24
# ifdef SECURE
E 23
D 14
		/* create a key for fetch */
		lhs.dptr = q->q_user;
		lhs.dsize = strlen(q->q_user) + 1;
D 6
		lhs.dptr = line;
E 6
		rhs = fetch(lhs);
E 14
I 14
D 20
			/* find this alias? */
			p = rhs.dptr;
			if (p == NULL)
				continue;
E 20
I 20
D 21
		/*
		**  Match on Alias.
		**	Deliver to the target list.
		**	Remove the alias from the send queue
		**	  and put it on the Alias queue.
		*/
E 21
I 21
			/* do parsing & compression of addresses */
			c = *p;
			while (c != '\0')
E 24
I 24
D 84
			if (init)
E 84
I 84
			if (init && CheckAliases)
E 84
E 24
			{
D 24
				p2 = p;
				while (*p != '\n' && *p != ',' && *p != '\0')
					p++;
E 24
I 24
				/* do parsing & compression of addresses */
E 24
D 80
				c = *p;
D 24
				*p++ = '\0';
				if (*p2 == '\0')
E 24
I 24
				while (c != '\0')
E 80
I 80
				while (*p != '\0')
E 80
E 24
				{
I 24
D 80
					p2 = p;
					while (*p != '\n' && *p != ',' && *p != '\0')
E 80
I 80
					extern char *DelimChar;

					while (isspace(*p) || *p == ',')
E 80
						p++;
D 80
					c = *p;
D 69
					*p++ = '\0';
E 69
I 32
					if (c == '\n')
						c = '\0';
E 32
D 69
					if (*p2 == '\0')
					{
						p[-1] = c;
						continue;
					}
D 31
					parse(p2, &bl, -1);
E 31
I 31
D 59
					(void) parse(p2, &bl, -1);
E 59
I 59
D 60
					(void) parseaddr(p2, &bl, -1);
E 60
I 60
					(void) parseaddr(p2, &bl, -1, ',');
E 60
E 59
E 31
E 24
					p[-1] = c;
D 24
					continue;
E 24
I 24
					while (isspace(*p))
						p++;
E 69
I 69
					*p = '\0';
D 77
					if (*p2 != '\0')
						(void) parseaddr(p2, &bl, -1, ',');
E 77
I 77
					if (*p2 != '\0' &&
					    parseaddr(p2, &bl, -1, ',') == NULL)
					{
						usrerr("%s... bad address");
					}
E 77
					if (c != '\0')
						*p++ = c;
I 79
					while (isspace(*p))
						p++;
E 80
I 80
					if (*p == '\0')
						break;
					if (parseaddr(p, &bl, -1, ',') == NULL)
						usrerr("%s... bad address", p);
					p = DelimChar;
E 80
E 79
E 69
E 24
				}
D 24
				parse(p2, &bl, -1);
D 23
				contin = (c == ',');
E 23
				p[-1] = c;
				while (isspace(*p))
					p++;
E 24
			}
I 23
D 24
# else SECURE
			p = &p[strlen(p)];
# endif SECURE
E 24
I 24
			else
D 64
				p = &p[strlen(p)];
E 64
I 64
			{
D 68
				p = &p[strlen(p) - 1];
				*p = '\0';
E 68
I 68
				p = &p[strlen(p)];
				if (p[-1] == '\n')
					*--p = '\0';
E 68
			}
E 64
E 24
E 23
E 21
E 20
E 14

D 14
		/* find this alias? */
		p = rhs.dptr;
		if (p == NULL)
			continue;
E 14
I 14
D 20
			/*
			**  Match on Alias.
			**	Deliver to the target list.
			**	Remove the alias from the send queue
			**	  and put it on the Alias queue.
			*/
E 14

E 20
D 14
		/*
		**  Match on Alias.
		**	Deliver to the target list.
		**	Remove the alias from the send queue
		**	  and put it on the Alias queue.
		*/

E 14
D 21
# ifdef DEBUG
D 14
		if (Debug)
			printf("%s (%s, %s) aliased to %s\n",
			    q->q_paddr, q->q_host, q->q_user, p);
E 14
I 14
D 20
			if (Debug)
				printf("%s (%s, %s) aliased to %s\n",
				    q->q_paddr, q->q_host, q->q_user, p);
E 20
I 20
		if (Debug)
			printf("%s (%s, %s) aliased to %s\n",
			    q->q_paddr, q->q_host, q->q_user, p);
E 20
E 14
# endif
I 16
D 20
			if (Verbose)
				message("050", "aliased to %s", p);
E 16
D 14
		tkoffq(q, &SendQ);
D 10
		putonq(q, &AliasQ);
E 10
		sendto(p, 1);
I 10
		putonq(q, &AliasQ);
E 10
I 8

		/* if our last entry had an alias, process them */
		if (q2 == NULL)
			q2 = nxtinq(&SendQ);
E 14
I 14
			q->q_flags |= QDONTSEND;
			sendto(p, 1);
		}
E 20
I 20
		if (Verbose)
			message("050", "aliased to %s", p);
		q->q_flags |= QDONTSEND;
		sendto(p, 1);
E 21
I 21
			/* see if there should be a continuation line */
D 23
			if (!contin)
E 23
I 23
			c = fgetc(af);
			if (!feof(af))
D 31
				ungetc(c, af);
E 31
I 31
				(void) ungetc(c, af);
E 31
			if (c != ' ' && c != '\t')
E 23
				break;

			/* read continuation line */
D 68
			p--;
E 68
			if (fgets(p, sizeof line - (p - line), af) == NULL)
				break;
D 57
			lineno++;
E 57
I 57
			LineNumber++;
E 57
D 23

			if (!isspace(*p))
				syserr("aliases: %d: continuation line missing", lineno);
E 23
		}
D 29
		if (al.q_mailer != M_LOCAL)
E 29
I 29
D 38
		if (al.q_mailer != MN_LOCAL)
E 38
I 38
D 67
		if (al.q_mailer != LocalMailer)
E 38
E 29
		{
D 57
			syserr("aliases: %d: cannot alias non-local names", lineno);
E 57
I 57
			syserr("cannot alias non-local names");
E 57
			continue;
		}
E 67
I 31

		/*
		**  Insert alias into symbol table or DBM file
		*/

I 32
D 67
		lhssize = strlen(al.q_user) + 1;
E 67
I 67
		lhssize = strlen(lhs) + 1;
E 67
		rhssize = strlen(rhs) + 1;

E 32
E 31
D 23
		s = stab(al.q_user, ST_ALIAS, rhs);
E 23
I 23
D 24
		s = stab(al.q_user, ST_ALIAS, ST_ENTER);
		s->s_alias = newstr(rhs);
E 24
I 24
# ifdef DBM
		if (init)
		{
			DATUM key, content;

I 93
			if (attrs.aa_flags)
			{
				rhs[rhssize] = attrs.aa_flags;
				bcopy(&attrs.aa_uid, rhs+rhssize+1, 2);
				bcopy(&attrs.aa_gid, rhs+rhssize+3, 2);
				rhssize += 5;
			}
E 93
D 32
			key.dsize = strlen(al.q_user) + 1;
E 32
I 32
			key.dsize = lhssize;
E 32
			key.dptr = al.q_user;
D 32
			content.dsize = strlen(rhs) + 1;
E 32
I 32
			content.dsize = rhssize;
E 32
			content.dptr = rhs;
			store(key, content);
		}
		else
# endif DBM
		{
			s = stab(al.q_user, ST_ALIAS, ST_ENTER);
			s->s_alias = newstr(rhs);
		}
I 32

		/* statistics */
		naliases++;
		bytes += lhssize + rhssize;
		if (rhssize > longest)
			longest = rhssize;
E 32
E 24
E 23
E 21
E 20
E 14
E 8
	}
I 73

# ifdef DBM
	if (init)
	{
		/* add the distinquished alias "@" */
		DATUM key;

		key.dsize = 2;
		key.dptr = "@";
		store(key, key);

		/* restore the old signal */
		(void) signal(SIGINT, oldsigint);
	}
# endif DBM

	/* closing the alias file drops the lock */
E 73
I 21
	(void) fclose(af);
I 32
D 44
	To = NULL;
E 44
I 44
	CurEnv->e_to = NULL;
I 57
	FileName = NULL;
E 57
E 44
D 50
	if (Verbose)
		message(Arpa_Info, "%d aliases, longest %d bytes, %d bytes total",
E 50
I 50
	message(Arpa_Info, "%d aliases, longest %d bytes, %d bytes total",
E 50
			naliases, longest, bytes);
I 77
# ifdef LOG
	if (LogLevel >= 8)
		syslog(LOG_INFO, "%d aliases, longest %d bytes, %d bytes total",
			naliases, longest, bytes);
# endif LOG
E 77
E 32
D 24
# endif DBM
E 24
E 21
D 20
#endif DBM
E 20
E 5
E 4
}
/*
**  FORWARD -- Try to forward mail
**
**	This is similar but not identical to aliasing.
**
D 21
**	Currently it is undefined, until the protocol for userinfo
**	databases is finalized.
**
E 21
**	Parameters:
D 31
**		user -- the name of the user who's mail we
**			would like to forward to.
E 31
I 31
**		user -- the name of the user who's mail we would like
**			to forward to.  It must have been verified --
**			i.e., the q_home field must have been filled
**			in.
I 40
**		sendq -- a pointer to the head of the send queue to
**			put this user's aliases in.
E 40
E 31
**
**	Returns:
D 21
**		TRUE -- we have forwarded it somewhere.
**		FALSE -- not forwarded; go ahead & deliver.
E 21
I 21
**		none.
E 21
**
**	Side Effects:
D 14
**		New names are added to SendQ.
**
D 3
**	Requires:
**		none
**
E 3
**	Called By:
**		recipient
E 14
I 14
**		New names are added to send queues.
I 21
D 36
**		Sets the QDONTSEND bit in addresses that are forwarded.
E 36
E 21
E 14
D 3
**
**	History:
**		3/5/80 -- return value changed.
**		1/23/80 -- null version written.
E 3
*/

D 21
bool
E 21
D 40
forward(user)
E 40
I 40
forward(user, sendq)
E 40
D 11
	addrq *user;
E 11
I 11
	ADDRESS *user;
I 40
	ADDRESS **sendq;
E 40
E 11
{
D 17
	return (FALSE);
E 17
I 17
D 18
	register struct passwd *pw;
	char buf[50];
E 18
I 18
	char buf[60];
E 18
D 31
	register FILE *fp;
	register char *p;
E 31
I 30
D 37
	struct stat stbuf;
E 37
I 37
	extern bool safefile();
E 37
E 30
D 18
	extern struct passwd *getpwnam();
E 18
D 19
	extern char *index();
E 19

I 21
# ifdef DEBUG
D 51
	if (Debug)
E 51
I 51
	if (tTd(27, 1))
E 51
		printf("forward(%s)\n", user->q_paddr);
# endif DEBUG

E 21
D 18
	if (user->q_mailer != 0)
E 18
I 18
D 29
	if (user->q_mailer != M_LOCAL || bitset(QBADADDR, user->q_flags))
E 29
I 29
D 38
	if (user->q_mailer != MN_LOCAL || bitset(QBADADDR, user->q_flags))
E 38
I 38
	if (user->q_mailer != LocalMailer || bitset(QBADADDR, user->q_flags))
E 38
E 29
E 18
D 21
		return (FALSE);
E 21
I 21
		return;
I 31
# ifdef DEBUG
	if (user->q_home == NULL)
		syserr("forward: no home");
# endif DEBUG
E 31
E 21

D 18
	/* find the user's home directory */
	pw = getpwnam(user->q_user);
	if (pw == NULL)
	{
		/* bad address -- mark it */
		user->q_flags |= QBADADDR;
		return (FALSE);
	}

E 18
	/* good address -- look for .forward file in home */
I 22
D 57
	define('z', user->q_home);
E 57
I 57
	define('z', user->q_home, CurEnv);
E 57
E 22
D 18
	user->q_flags |= QGOODADDR;
	sprintf(buf, "%s/.forward", pw->pw_dir);
E 18
I 18
D 19
	expand("$z/.forward", buf, &buf[sizeof buf - 1]);
E 19
I 19
D 45
	(void) expand("$z/.forward", buf, &buf[sizeof buf - 1]);
E 45
I 45
D 65
	expand("$z/.forward", buf, &buf[sizeof buf - 1], CurEnv);
E 65
I 65
	expand("\001z/.forward", buf, &buf[sizeof buf - 1], CurEnv);
E 65
E 45
E 19
E 18
D 27
	fp = fopen(buf, "r");
	if (fp == NULL)
E 27
I 27
D 30
	if (access(buf, 4) < 0)
E 30
I 30
D 37
	if (stat(buf, &stbuf) < 0 || stbuf.st_uid != user->q_uid ||
	    !bitset(S_IREAD, stbuf.st_mode))
E 37
I 37
	if (!safefile(buf, user->q_uid, S_IREAD))
E 37
E 30
E 27
D 21
		return (FALSE);
E 21
I 21
		return;
E 21

	/* we do have an address to forward to -- do it */
I 21
D 36
	user->q_flags |= QDONTSEND;
E 36
E 21
D 19
	fgets(buf, sizeof buf, fp);
E 19
I 19
D 27
	(void) fgets(buf, sizeof buf, fp);
E 19
	if ((p = index(buf, '\n')) != NULL)
		*p = '\0';
D 19
	fclose(fp);
E 19
I 19
	(void) fclose(fp);
E 19
	if (buf[0] == '\0')
D 21
		return (FALSE);
E 21
I 21
		return;
E 21
	if (Verbose)
D 25
		message("050", "forwarded to %s", buf);
E 25
I 25
		message(Arpa_Info, "forwarded to %s", buf);
E 25
I 21
	AliasLevel++;
E 21
	sendto(buf, 1);
D 21
	return (TRUE);
E 21
I 21
	AliasLevel--;
	return;
E 27
I 27
D 34
	include(buf, "forwarding");
E 34
I 34
D 40
	include(buf, "forwarding", user);
E 40
I 40
	include(buf, "forwarding", user, sendq);
I 67
}
/*
**  MAPHOST -- given a host description, produce a mapping.
**
**	This is done by looking up the name in the alias file,
**	preceeded by an "@".  This can be used for UUCP mapping.
**	For example, a call with {blia, ., UUCP} as arguments
**	might return {ucsfcgl, !, blia, ., UUCP} as the result.
**
**	We first break the input into three parts -- before the
**	lookup, the lookup itself, and after the lookup.  We
**	then do the lookup, concatenate them together, and rescan
**	the result.
**
**	Parameters:
**		pvp -- the parameter vector to map.
**
**	Returns:
**		The result of the mapping.  If nothing found, it
**		should just concatenate the three parts together and
**		return that.
**
**	Side Effects:
**		none.
*/

char **
maphost(pvp)
	char **pvp;
{
	register char **avp;
	register char **bvp;
	char *p;
	char buf1[MAXNAME];
	char buf2[MAXNAME];
	char buf3[MAXNAME];
	extern char **prescan();

	/*
	**  Extract the three parts of the input as strings.
	*/

	/* find the part before the lookup */
	for (bvp = pvp; *bvp != NULL && **bvp != MATCHLOOKUP; bvp++)
		continue;
	if (*bvp == NULL)
		return (pvp);
	p = *bvp;
	*bvp = NULL;
	cataddr(pvp, buf1, sizeof buf1);
	*bvp++ = p;

	/* find the rest of the lookup */
	for (avp = bvp; *pvp != NULL && **bvp != MATCHELOOKUP; bvp++)
		continue;
	if (*bvp == NULL)
		return (pvp);
	p = *bvp;
	*bvp = NULL;
	cataddr(avp, buf2, sizeof buf2);
	*bvp++ = p;

	/* save the part after the lookup */
	cataddr(bvp, buf3, sizeof buf3);

	/*
	**  Now look up the middle part.
	*/

	p = aliaslookup(buf2);
	if (p != NULL)
		strcpy(buf2, p);

	/*
	**  Put the three parts back together and break into tokens.
	*/

	strcat(buf1, buf2);
	strcat(buf1, buf3);
	avp = prescan(buf1, '\0');

	/* return this mapping */
	return (avp);
E 67
I 42
}
D 49
/*
**  HOSTALIAS -- alias a host name
**
**	Given a host name, look it up in the host alias table
**	and return it's value.  If nothing, return NULL.
**
**	Parameters:
**		a -- address to alias.
**
**	Returns:
**		text result of aliasing.
**		NULL if none.
**
**	Side Effects:
**		none.
*/

char *
hostalias(a)
	register ADDRESS *a;
{
	char buf[MAXNAME+2];
	register char *p;

D 47
	strcpy(buf, "/");
	strcat(buf, a->q_host);
E 47
I 47
	(void) strcpy(buf, "/");
	(void) strcat(buf, a->q_host);
E 47
	makelower(buf);

	p = aliaslookup(buf);
	if (p == NULL)
		return (NULL);
D 43
	sprintf(buf, p, a->q_user);
E 43
I 43
	(void) sprintf(buf, p, a->q_user);
E 43
	return (newstr(buf));
E 42
E 40
E 34
E 27
E 21
E 17
}
E 49
E 1
