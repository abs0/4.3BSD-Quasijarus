h03411
s 00002/00000/00107
d D 5.7 04/09/03 21:49:55 msokolov 16 15
c pp and jp capabilities for printer prep and job prep
e
s 00001/00000/00106
d D 5.6 04/08/21 19:19:34 msokolov 15 14
c implement bf (banner filter) capability
e
s 00002/00000/00104
d D 5.5 04/08/04 06:08:22 msokolov 14 13
c add ea and pi capabilities to support smarter filters
e
s 00001/00000/00103
d D 5.4 04/07/30 08:31:37 msokolov 13 12
c new ct boolen capability to ensure printer readiness with ^T
e
s 00010/00005/00093
d D 5.3 88/06/30 17:59:44 bostic 12 11
c install approved copyright notice
e
s 00008/00002/00090
d D 5.2 88/05/05 18:07:50 bostic 11 10
c written by Ralph Campbell; add Berkeley specific header
e
s 00008/00001/00084
d D 5.1 85/06/06 10:10:50 dist 10 9
c Add copyright
e
s 00001/00000/00084
d D 4.9 85/02/27 16:19:36 ralph 9 8
c added 'hl' flag to printcap to print the banner last.
e
s 00001/00000/00083
d D 4.8 85/02/07 15:12:47 miriam 8 7
c Include restricted group.
e
s 00002/00001/00081
d D 4.7 84/07/24 16:52:47 ralph 7 6
c use syslog().
e
s 00001/00001/00081
d D 4.6 83/07/01 22:53:32 wnj 6 5
c <wait.h> -> <sys/wait.h>
e
s 00001/00000/00081
d D 4.5 83/06/29 17:08:59 ralph 5 4
c changed to use unix domain ipc.
e
s 00001/00000/00080
d D 4.4 83/06/22 09:33:49 ralph 4 3
c added -n option to print ditroff files.
e
s 00006/00004/00074
d D 4.3 83/06/17 15:09:37 ralph 3 2
c fixed `fc' and `fs' when 0177777 is needed.
e
s 00004/00000/00074
d D 4.2 83/05/13 11:54:11 ralph 2 1
c bug fixes and changes for lpc command.
e
s 00074/00000/00000
d D 4.1 83/04/29 11:39:42 ralph 1 0
c date and time created 83/04/29 11:39:42 by ralph
e
u
U
t
T
I 1
D 10
/*	%M%	%I%	%E%	*/
E 10
I 10
/*
 * Copyright (c) 1983 Regents of the University of California.
D 11
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 11
I 11
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 12
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 12
I 12
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
E 12
E 11
 *
 *	%W% (Berkeley) %G%
 */

E 10
/*
 * Global definitions for the line printer system.
 */

#include <stdio.h>
D 7
#include <sys/types.h>
E 7
I 7
#include <sys/param.h>
E 7
#include <sys/file.h>
#include <sys/dir.h>
#include <sys/stat.h>
#include <sys/socket.h>
I 5
#include <sys/un.h>
E 5
#include <netinet/in.h>
#include <netdb.h>
#include <pwd.h>
I 7
#include <syslog.h>
E 7
#include <signal.h>
D 6
#include <wait.h>
E 6
I 6
#include <sys/wait.h>
E 6
#include <sgtty.h>
#include <ctype.h>
#include <errno.h>
#include "lp.local.h"

extern int	DU;		/* daeomon user-id */
extern int	MX;		/* maximum number of blocks to copy */
I 3
extern int	MC;		/* maximum number of copies allowed */
E 3
extern char	*LP;		/* line printer device name */
extern char	*RM;		/* remote machine name */
I 8
extern char	*RG;		/* restricted group */
E 8
extern char	*RP;		/* remote printer name */
extern char	*LO;		/* lock file name */
extern char	*ST;		/* status file name */
extern char	*SD;		/* spool directory */
extern char	*AF;		/* accounting file */
extern char	*LF;		/* log file for error messages */
extern char	*OF;		/* name of output filter (created once) */
extern char	*IF;		/* name of input filter (created per job) */
I 2
extern char	*RF;		/* name of fortran text filter (per job) */
E 2
extern char	*TF;		/* name of troff(1) filter (per job) */
I 4
extern char	*NF;		/* name of ditroff(1) filter (per job) */
E 4
extern char	*DF;		/* name of tex filter (per job) */
extern char	*GF;		/* name of graph(1G) filter (per job) */
extern char	*VF;		/* name of raster filter (per job) */
extern char	*CF;		/* name of cifplot filter (per job) */
I 15
extern char	*BF;		/* name of banner filter */
I 16
extern char	*PP;		/* name of printer prep program */
extern char	*JP;		/* name of job prep program */
E 16
E 15
extern char	*FF;		/* form feed string */
extern char	*TR;		/* trailer string to be output when Q empties */
I 3
extern short	SC;		/* suppress multiple copies */
E 3
extern short	SF;		/* suppress FF on each print job */
extern short	SH;		/* suppress header page */
extern short	SB;		/* short banner instead of normal header */
I 9
extern short	HL;		/* print header last */
E 9
extern short	RW;		/* open LP for reading and writing */
I 13
extern short	CT;		/* check printer for readiness with ^T */
E 13
extern short	PW;		/* page width */
I 2
extern short	PX;		/* page width in pixels */
extern short	PY;		/* page length in pixels */
E 2
extern short	PL;		/* page length */
I 14
extern short	EA;		/* pass extended arguments to filters */
extern short	PI;		/* input filter incorporates pr functionality */
E 14
extern short	BR;		/* baud rate if lp is a tty */
D 3
extern short	FC;		/* flags to clear if lp is a tty */
extern short	FS;		/* flags to set if lp is a tty */
extern short	XC;		/* flags to clear for local mode */
extern short	XS;		/* flags to set for local mode */
E 3
I 3
extern int	FC;		/* flags to clear if lp is a tty */
extern int	FS;		/* flags to set if lp is a tty */
extern int	XC;		/* flags to clear for local mode */
extern int	XS;		/* flags to set for local mode */
E 3
I 2
extern short	RS;		/* restricted to those with local accounts */
E 2

extern char	line[BUFSIZ];
extern char	pbuf[];		/* buffer for printcap entry */
extern char	*bp;		/* pointer into ebuf for pgetent() */
extern char	*name;		/* program name */
extern char	*printer;	/* printer name */
extern char	host[32];	/* host machine name */
extern char	*from;		/* client's machine name */
extern int	errno;

/*
 * Structure used for building a sorted list of control files.
 */
struct queue {
	time_t	q_time;			/* modification time */
	char	q_name[MAXNAMLEN+1];	/* control file name */
};

char	*pgetstr();
char	*malloc();
char	*getenv();
char	*index();
char	*rindex();
E 1
