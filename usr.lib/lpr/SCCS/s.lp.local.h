h23634
s 00010/00005/00088
d D 5.3 88/06/30 17:59:46 bostic 15 14
c install approved copyright notice
e
s 00008/00002/00085
d D 5.2 88/05/05 18:07:53 bostic 14 13
c written by Ralph Campbell; add Berkeley specific header
e
s 00008/00001/00079
d D 5.1 85/06/06 10:11:12 dist 13 12
c Add copyright
e
s 00000/00005/00080
d D 4.5 84/07/24 16:53:24 ralph 12 11
c use syslog().
e
s 00002/00001/00083
d D 4.4 83/08/24 15:17:26 ralph 11 10
c added master lock file so /dev/printer removed automatically
e
s 00005/00000/00079
d D 4.3 83/06/29 17:09:04 ralph 10 9
c changed to use unix domain ipc.
e
s 00001/00000/00078
d D 4.2 83/06/17 15:09:41 ralph 9 8
c fixed `fc' and `fs' when 0177777 is needed.
e
s 00018/00001/00060
d D 4.1 83/04/29 12:01:00 ralph 8 6
c changes for new printer daemon.
e
s 00017/00000/00061
d R 1.7 83/04/29 11:51:50 ralph 7 6
c changes for new printer daemon.
e
s 00002/00006/00059
d D 1.6 83/02/10 17:08:45 ralph 6 5
c bugs fixed and vpr options merged into lpr.
e
s 00003/00001/00062
d D 1.5 83/01/07 16:09:49 ralph 5 4
c added status file to spooldir and other improvements.
e
s 00005/00009/00058
d D 1.4 83/01/05 11:26:30 root 4 3
c Working version of remote spooling.
e
s 00000/00015/00067
d D 1.3 82/12/02 11:59:21 ralph 3 2
c Updated directory scanning and sorting for new dir.h
e
s 00005/00000/00077
d D 1.2 81/09/04 14:00:07 sam 2 1
c cut out extra form feed
e
s 00077/00000/00000
d D 1.1 81/05/09 16:36:30 root 1 0
c date and time created 81/05/09 16:36:30 by root
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
D 8
/*	lp.local.h	1.4	83/01/05	*/
E 8
I 8
D 13
/*	%M%	%I%	%E%	*/
E 13
I 13
/*
 * Copyright (c) 1983 Regents of the University of California.
D 14
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 14
I 14
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 15
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 15
I 15
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
E 15
E 14
 *
 *	%W% (Berkeley) %G%
 */

E 13
E 8
E 5
/*
 * Possibly, local parameters to the spooling system
 */

/*
 * Magic number mapping for binary files, used by lpr to avoid
 *   printing objects files.
 */

#include <a.out.h>
#include <ar.h>

#ifndef A_MAGIC1	/* must be a VM/UNIX system */
#	define A_MAGIC1	OMAGIC
#	define A_MAGIC2	NMAGIC
#	define A_MAGIC3	ZMAGIC
#	undef ARMAG
#	define ARMAG	0177545
#endif

/*
 * Defaults for line printer capabilities data base
 */
#define	DEFLP		"lp"
#define DEFLOCK		"lock"
I 5
#define DEFSTAT		"status"
E 5
#define	DEFSPOOL	"/usr/spool/lpd"
D 4
#define	DEFMX		1000
#define	DEFLOGF		"/dev/console"
#define DEFFF		"\f"
E 4
#define	DEFDAEMON	"/usr/lib/lpd"
I 4
#define	DEFLOGF		"/dev/console"
E 4
#define	DEFDEVLP	"/dev/lp"
I 4
#define DEFRLPR		"/usr/lib/rlpr"
#define DEFBINDIR	"/usr/ucb"
#define	DEFMX		1000
I 9
#define DEFMAXCOPIES	0
E 9
#define DEFFF		"\f"
I 6
#define DEFWIDTH	132
#define DEFLENGTH	66
E 6
I 5
#define DEFUID		1
E 5
E 4
D 3
#define	DEFUID		1

/*
 * The system name is normally imported from <whoami.h>,
 *   change it here if you want someting special on the JOB line
 *   of the burst page.
 */

#ifdef SYTEK
#	define	SYSTEM_NAME	"Sytek VAX/UNIX"
#else
#include <whoami.h>

#	define	SYSTEM_NAME	sysname
#endif
E 3
D 6

/*
 * Some utilities used by lpd
 */
#define PRLOC		"/bin/pr"
#define MAIL		"/bin/mail"
E 6

/*
 * When files are created in the spooling area, they are normally
 *   readable only by their owner and the spooling group.  If you
 *   want otherwise, change this mode.
 */
#define FILMOD		0660

/*
D 12
 * We choose not to include this from <sys/param.h>
 */
#define NOFILE		20

/*
E 12
 * Printer is assumed to support LINELEN (for block chars)
 *   and background character (blank) is a space
 */
#define LINELEN		132
#define BACKGND		' '

#define HEIGHT	9		/* height of characters */
#define WIDTH	8		/* width of characters */
#define DROP	3		/* offset to drop characters with descenders */
I 8

/*
I 10
D 11
 * path name of socket created by lpd.
E 11
I 11
 * path name of files created by lpd.
E 11
 */
I 11
#define MASTERLOCK "/usr/spool/lpd.lock"
E 11
#define SOCKETNAME "/dev/printer"

/*
E 10
 * Some utilities used by printjob.
 */
#define PR		"/bin/pr"
#define MAIL		"/usr/lib/sendmail"

/*
 * Define TERMCAP if the terminal capabilites are to be used for lpq.
 */
#define TERMCAP

/*
 * Maximum number of user and job requests for lpq and lprm.
 */
#define MAXUSERS	50
#define MAXREQUESTS	50
E 8
D 4

I 2
/*
 * Does lpd driver give a form feed on first open?  If so, set TOF to 1
 *  to save one page.
 */
#define TOF	1
E 4
E 2
E 1
