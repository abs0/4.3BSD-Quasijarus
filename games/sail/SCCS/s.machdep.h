h37237
s 00010/00005/00022
d D 5.3 88/06/18 19:55:35 bostic 20 19
c install approved copyright notice
e
s 00008/00002/00019
d D 5.2 88/03/09 12:24:15 bostic 19 18
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00005/00007/00016
d D 5.1 85/05/29 16:13:27 dist 18 17
c Add copyright
e
s 00007/00001/00016
d D 2.7 85/04/23 21:50:42 edward 17 16
c copyright message
e
s 00002/00008/00015
d D 2.6 85/03/04 18:06:44 edward 16 15
c more cleanup; sail, driver, sail.log merged into single program
e
s 00002/00000/00021
d D 2.5 84/04/28 13:07:58 edward 15 14
c time out factor increased to 5 min, too long?
e
s 00000/00001/00021
d D 2.4 84/02/23 15:50:20 edward 14 13
c no more SAILLOGDEF
e
s 00010/00000/00012
d D 2.3 84/01/27 15:01:44 edward 13 12
c portability
e
s 00001/00001/00011
d D 2.2 84/01/19 16:03:51 edward 12 11
c larger buffer (4096)
e
s 00000/00000/00012
d D 2.1 83/10/31 13:44:44 edward 11 10
c new version
e
s 00003/00002/00009
d D 1.10 83/10/28 21:15:24 edward 10 9
c multiple driver locations, and initial pos bug.
e
s 00000/00000/00011
d D 1.9 83/07/20 17:24:38 edward 9 8
c 
e
s 00003/00004/00008
d D 1.8 83/05/20 19:09:35 edward 8 7
c moved driver to /usr/games/lib and merged externs.h and globals.c
e
s 00001/00000/00011
d D 1.7 83/05/20 17:56:22 root 7 6
c debugging flag -D
e
s 00000/00000/00011
d D 1.6 83/05/20 17:43:38 root 6 5
c merge
e
s 00002/00002/00009
d D 1.5 83/05/19 22:54:27 leres 5 4
c Changed from /usr/public to /usr/games
e
s 00001/00001/00010
d D 1.4 83/05/19 22:38:31 leres 4 3
c Move location of score file
e
s 00001/00000/00010
d D 1.3 83/03/18 14:31:43 leres 3 2
c Added SETUID define
e
s 00002/00002/00008
d D 1.2 83/03/18 11:16:38 leres 2 1
c Changed pathnames for /usr/public
e
s 00010/00000/00000
d D 1.1 83/03/17 21:18:43 leres 1 0
c date and time created 83/03/17 21:18:43 by leres
e
u
U
t
T
I 1
/*
D 17
 * sccsid = "%W% %G%";
E 17
I 17
D 18
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
 */

/*
 * %W% %G%
E 18
I 18
 * Copyright (c) 1983 Regents of the University of California.
D 19
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 19
I 19
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 20
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 20
I 20
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
E 20
E 19
 *
 *	%W% (Berkeley) %G%
E 18
E 17
 */
D 2
#define LOGFILE "/ya/staff/leres/etc/.shipslog"
#define DRIVER "/ya/staff/leres/bin/.driver"
E 2
I 2
D 4
#define LOGFILE "/usr/public/.shipslog"
E 4
I 4
D 5
#define LOGFILE "/usr/public/lib/shipslog"
E 4
#define DRIVER "/usr/public/.driver"
E 5
I 5
D 8
#define LOGFILE "/usr/games/lib/shipslog"
#define DRIVER "/usr/games/.driver"
E 8
I 8
D 16
#define LOGFILE "/usr/games/lib/saillog"
D 10
#define DRIVER "/usr/games/lib/saildriver"
E 8
I 7
#define DEBUGDRIVER "driver"
E 10
I 10
#define DRIVER1 "driver"
#define DRIVER2 "/usr/games/lib/saildriver"
#define DRIVER3 "/usr/public/.driver"
E 10
E 7
E 5
E 2
D 8
#define DRIVERNAME ".driver"
#define UCBCORY
E 8
I 8
#define DRIVERNAME "driver"
E 8
D 14
#define SAILLOGDEF 0		/* don't look up usernames */
E 14
I 3
#define SETUID			/* player and driver run setuid */
E 16
E 3

I 15
D 16
#define TIMEOUT 300		/* Sync() time out */
E 16
I 16
#define LOGFILE "/usr/games/lib/saillog"	/* has to match the makefile */
E 16

E 15
D 12
#define BUFSIZE 2024
E 12
I 12
D 16
#define BUFSIZE 4096
E 16
I 16
#define TIMEOUT 300				/* Sync() timeout in seconds */
E 16
I 13

/* for 4.2bsd machines */
#define blockalarm()	((void) sigblock(1 << SIGALRM-1))
#define unblockalarm()	((void) sigsetmask(sigblock(0) & ~(1 << SIGALRM-1)))

/* for 2.9bsd machines (onyx)
typedef int void;
#define blockalarm()	((void) sighold(SIGALRM))
#define unblockalarm()	((void) sigrelse(SIGALRM))
*/
E 13
E 12
E 1
