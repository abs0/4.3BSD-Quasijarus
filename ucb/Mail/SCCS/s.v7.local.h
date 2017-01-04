h34627
s 00008/00002/00036
d D 5.4 88/02/18 17:04:32 bostic 14 13
c written by Kurt Shoens; added Berkeley specific header
e
s 00000/00005/00038
d D 5.3 87/05/18 12:28:34 edward 13 12
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00001/00001/00042
d D 5.2 85/09/19 00:32:51 lepreau 12 11
c Mail.help.~ renamed to avoid deletion by find's for CCA emacs chkpoint files.
e
s 00007/00001/00036
d D 5.1 85/06/06 10:48:51 dist 11 10
c Add copyright
e
s 00002/00004/00035
d D 2.6 83/08/11 22:20:32 sam 10 9
c standardize sccs keyword lines
e
s 00001/00001/00038
d D 2.5 83/01/29 19:51:25 leres 9 7
c Changed location of postage file
e
s 00000/00000/00039
d R 2.5 83/01/29 19:49:40 leres 8 7
c Changed location of the POSTAGE file.
e
s 00001/00001/00038
d D 2.4 82/12/26 21:16:23 eric 7 6
c change delivermail to sendmail throughout
e
s 00007/00001/00032
d D 2.3 82/09/02 12:36:36 mckusick 6 5
c added #define of GETHOST for systems that have gethostname();
c changed determination of local machine id to EMPTYID ifdef GETHOST
e
s 00006/00000/00027
d D 2.2 82/07/26 17:13:52 kurt 5 4
c Parameterized location of postage meter file as POSTAGE; 
c added include on sigretro.h if we're not a VMUNIX site. 
c 
e
s 00000/00000/00027
d D 2.1 81/07/01 11:11:35 kurt 4 3
c Release to Heidi Stettner
e
s 00001/00001/00026
d D 1.3 81/04/01 10:55:54 kurt 3 2
c changed local machine to ingvax.
e
s 00001/00000/00026
d D 1.2 80/10/10 12:01:15 kas 2 1
c Added define constant MORE == path of the more program
e
s 00026/00000/00000
d D 1.1 80/10/08 09:53:57 kas 1 0
c date and time created 80/10/08 09:53:57 by kas
e
u
U
f b 
t
T
I 10
D 11
/*	%M%	%I%	%E%	*/
E 11
I 11
/*
 * Copyright (c) 1980 Regents of the University of California.
D 14
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 14
I 14
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 14
 *
 *	%W% (Berkeley) %G%
 */
E 11

E 10
I 1
/*
 * Declarations and constants specific to an installation.
 *
 * Vax/Unix version 7.
D 10
 */
 
/*
 * Sccs Id = "%W% %G%";
E 10
 */

D 3
#define	LOCAL		'v'		/* Local machine id */
E 3
I 3
D 6
#define	LOCAL		'j'		/* Local machine id */
E 6
I 6
#define	GETHOST				/* System has gethostname syscall */
#ifdef	GETHOST
#define	LOCAL		EMPTYID		/* Dynamically determined local host */
#else
#define	LOCAL		'j'		/* Local host id */
#endif	GETHOST

E 6
E 3
#define	MAIL		"/bin/mail"	/* Name of mail sender */
D 7
#define DELIVERMAIL	"/etc/delivermail"
E 7
I 7
#define SENDMAIL	"/usr/lib/sendmail"
E 7
					/* Name of classy mail deliverer */
#define	EDITOR		"/usr/ucb/ex"	/* Name of text editor */
#define	VISUAL		"/usr/ucb/vi"	/* Name of display editor */
#define	SHELL		"/bin/csh"	/* Standard shell */
I 2
#define	MORE		"/usr/ucb/more"	/* Standard output pager */
E 2
#define	HELPFILE	"/usr/lib/Mail.help"
					/* Name of casual help file */
D 12
#define	THELPFILE	"/usr/lib/Mail.help.~"
E 12
I 12
#define	THELPFILE	"/usr/lib/Mail.tildehelp"
E 12
I 5
D 9
#define	POSTAGE		"/arch/kurt/postage"
E 9
I 9
#define	POSTAGE		"/usr/adm/maillog"
E 9
					/* Where to audit mail sending */
E 5
					/* Name of casual tilde help */
D 13
#define	UIDMASK		0177777		/* Significant uid bits */
E 13
#define	MASTER		"/usr/lib/Mail.rc"
#define	APPEND				/* New mail goes to end of mailbox */
#define CANLOCK				/* Locking protocol actually works */
#define	UTIME				/* System implements utime(2) */
I 5
D 13

#ifndef VMUNIX
#include "sigretro.h"			/* Retrofit signal defs */
#endif VMUNIX
E 13
E 5
E 1
