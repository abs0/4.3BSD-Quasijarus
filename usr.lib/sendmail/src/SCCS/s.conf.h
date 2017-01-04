h00513
s 00010/00000/00060
d D 5.13 88/12/28 19:45:41 bostic 19 18
c add NO_WILDCARD_MX #define
e
s 00001/00000/00059
d D 5.12 88/09/20 22:15:36 eric 18 17
c add I option to insist on Internet domain server; add NAMED_BIND
c compile option to compile in named routines.
e
s 00011/00010/00048
d D 5.11 88/06/30 14:58:32 bostic 17 16
c install approved copyright notice
e
s 00000/00001/00058
d D 5.10 88/04/01 16:21:18 bostic 16 15
c always use flock when rebuilding alias file
e
s 00017/00012/00042
d D 5.9 88/03/13 19:51:42 bostic 15 14
c add Berkeley specific header
e
s 00001/00000/00053
d D 5.8 86/07/21 10:21:13 bloom 14 13
c add support for MX use of the name server
e
s 00001/00000/00052
d D 5.7 86/01/05 19:56:31 eric 13 12
m 
c cleanup for various compilation flags and reasonable organization
e
s 00012/00009/00040
d D 5.6 86/01/05 17:52:18 eric 12 11
m 
c add NDBM compilation flag
e
s 00001/00000/00048
d D 5.5 86/01/05 16:57:09 eric 11 10
m 
c define QUEUESIZE to be the maximum number of jobs considered during
c a single queue run
e
s 00001/00000/00047
d D 5.4 85/09/24 15:09:32 eric 10 9
m 
c don't step on user environment
e
s 00000/00000/00047
d D 5.3 85/09/19 01:25:13 eric 9 7
i 8
m 
c incorporate SMI changes -- still experimental
e
s 00003/00002/00044
d D 5.1.1.1 85/09/19 00:55:22 eric 8 6
m 
c SMI changes (somewhat)
e
s 00002/00002/00044
d D 5.2 85/09/03 20:08:50 eric 7 6
m 
c increase MAXNAME and MAXLINE, as requested by Rick Adams, via
c George Goble, via Kirk Smith, via Miriam Amos (why????)
e
s 00012/00002/00034
d D 5.1 85/06/07 16:10:52 dist 6 5
m 
c Add copyright
e
s 00001/00000/00035
d D 4.3 85/04/28 11:51:34 eric 5 4
m 
c add #define FLOCK 1
e
s 00001/00001/00034
d D 4.2 84/03/11 13:37:36 eric 4 3
m 
c fixes from Greg Satz <satz@sri-tsc.ARPA>, mostly for PDP's
e
s 00000/00000/00035
d D 4.1 83/07/25 19:43:26 eric 3 2
m 
c 4.2 release version
e
s 00001/00003/00034
d D 3.2 82/11/13 18:45:04 eric 2 1
m 070
c put OS info back into the Makefile; sendmail discretionary info goes into
c conf.h.
e
s 00037/00000/00000
d D 3.1 82/11/13 17:57:12 eric 1 0
m 021,
m 070
c date and time created 82/11/13 17:57:12 by eric
e
u
U
f b 
f i 
t
T
I 1
/*
I 17
 * Copyright (c) 1983 Eric P. Allman
E 17
D 2
**  CONF.H -- All user-configurable parameters
E 2
I 2
D 6
**  CONF.H -- All user-configurable parameters for sendmail
E 6
I 6
D 15
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
E 6
E 2
**
D 6
**	%W%	%Y%	%G%
E 6
I 6
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
**
**	%W% (Berkeley) %G%
*/
E 15
I 15
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 17
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 17
I 17
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
E 17
 *
 *	%W% (Berkeley) %G%
D 17
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
 *
E 17
 */
E 15

/*
**  CONF.H -- All user-configurable parameters for sendmail
E 6
*/
D 15


E 15

/*
**  Table sizes, etc....
**	There shouldn't be much need to change these....
*/

D 4
# define MAXLINE	256		/* max line length */
E 4
I 4
D 7
# define MAXLINE	512		/* max line length */
E 4
# define MAXNAME	128		/* max length of a name */
E 7
I 7
# define MAXLINE	1024		/* max line length */
# define MAXNAME	256		/* max length of a name */
E 7
# define MAXFIELD	2500		/* max total length of a hdr field */
# define MAXPV		40		/* max # of parms to mailers */
D 8
# define MAXHOP		30		/* max value of HopCount */
E 8
I 8
# define MAXHOP		17		/* max value of HopCount */
E 8
# define MAXATOM	100		/* max atoms per address */
# define MAXMAILERS	25		/* maximum mailers known to system */
# define MAXRWSETS	30		/* max # of sets of rewriting rules */
# define MAXPRIORITIES	25		/* max values for Precedence: field */
# define MAXTRUST	30		/* maximum number of trusted users */
I 10
# define MAXUSERENVIRON	40		/* max # of items in user environ */
I 11
# define QUEUESIZE	600		/* max # of jobs per queue run */
I 14
# define MAXMXHOSTS	10		/* max # of MX records */
E 14
E 11
E 10

/*
**  Compilation options.
I 12
**
**	#define these if they are available; comment them out otherwise.
E 12
*/

D 12
#define DBM		1	/* use DBM library (requires -ldbm) */
#define DEBUG		1	/* enable debugging */
#define LOG		1	/* enable logging */
#define SMTP		1	/* enable user and server SMTP */
#define QUEUE		1	/* enable queueing */
#define UGLYUUCP	1	/* output ugly UUCP From lines */
D 8
#define DAEMON		1	/* include the daemon (requires IPC) */
E 8
I 8
#define DAEMON		1	/* include the daemon (requires IPC & SMTP) */
E 8
I 5
#define FLOCK		1	/* use flock file locking */
I 8
#define SETPROCTITLE	1	/* munge argv to display current status */
E 12
I 12
# define DBM		1	/* use DBM library (requires -ldbm) */
# define NDBM		1	/* new DBM library available (requires DBM) */
# define DEBUG		1	/* enable debugging */
# define LOG		1	/* enable logging */
# define SMTP		1	/* enable user and server SMTP */
# define QUEUE		1	/* enable queueing */
# define UGLYUUCP	1	/* output ugly UUCP From lines */
# define DAEMON		1	/* include the daemon (requires IPC & SMTP) */
D 16
# define FLOCK		1	/* use flock file locking */
E 16
# define SETPROCTITLE	1	/* munge argv to display current status */
I 13
/* # define WIZ		1	/* allow wizard mode */
I 18
# define NAMED_BIND	1	/* use Berkeley Internet Domain Server */
I 19

	/*
	 * Use query type of ANY if possible (NO_WILDCARD_MX), which will
	 * find types CNAME, A, and MX, and will cause all existing records
	 * to be cached by our local server.  If there is (might be) a
	 * wildcard MX record in the local domain or its parents that are
	 * searched, we can't use ANY; it would cause fully-qualified names
	 * to match as names in a local domain.
	 */
# define NO_WILDCARD_MX	1
E 19
E 18
E 13
E 12
E 8
E 5
D 2
#define VMUNIX		1	/* VMUNIX options (4.1bsd) */
/* #define NVMUNIX	1	/* new VMUNIX options (4.2bsd, requires VMUNIX) */
E 2
E 1
