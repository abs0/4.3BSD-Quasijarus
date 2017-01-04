h52861
s 00010/00005/00055
d D 5.4 88/06/30 17:53:14 bostic 11 10
c install approved copyright notice
e
s 00000/00002/00060
d D 5.3 88/06/01 17:13:39 bostic 10 9
c rip out sobuf
e
s 00015/00003/00047
d D 5.2 88/03/08 08:30:00 bostic 9 8
c add Berkeley specific header
e
s 00007/00001/00043
d D 5.1 85/05/15 11:32:23 dist 8 7
c Add copyright notice
e
s 00004/00001/00040
d D 1.7 83/07/16 23:47:21 sam 7 6
c add useful sccs id's
e
s 00000/00020/00041
d D 1.6 83/04/29 11:51:46 ralph 6 5
c changes for new printer daemon.
e
s 00000/00000/00061
d D 1.5 83/01/05 11:27:25 root 5 4
c Working version of remote spooling.
e
s 00011/00001/00050
d D 1.4 81/08/24 10:49:42 sam 4 3
c parameterize baudrate so don't have to do gets
e
s 00008/00000/00043
d D 1.3 81/06/01 16:30:54 sam 3 2
c #define SHEETFEEDER conditionally compiles in what's needed
e
s 00022/00008/00021
d D 1.2 81/05/28 15:19:58 sam 2 1
c works with spinwriter on terminal port (with sheetfeeder)
e
s 00029/00000/00000
d D 1.1 81/05/09 16:34:36 root 1 0
c date and time created 81/05/09 16:34:36 by root
e
u
U
t
T
I 8
/*
 * Copyright (c) 1983 Regents of the University of California.
D 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 9
I 9
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 11
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
I 11
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
E 11
E 9
 */

E 8
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
#ifndef lint
I 9
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
E 9
static char sccsid[] = "%W% (Berkeley) %G%";
D 8
#endif
E 8
I 8
D 9
#endif not lint
E 9
I 9
#endif /* not lint */
E 9
E 8

E 7
#include <stdio.h>
#include <sgtty.h>
D 6
#include <signal.h>
E 6

I 2
#define PAGESIZE	66

I 4
D 6
#ifdef TTY
#ifndef BAUDRATE
#	define BAUDRATE	B300
#endif

E 4
E 2
struct sgttyb tty;
I 4
#endif
E 4

E 6
main()
{
D 10
	extern char _sobuf[BUFSIZ];
E 10
D 2
	register char c;
E 2
I 2
	extern char *rindex();
	char line[256];
	register char c, *cp;
	register lnumber;
E 2

D 6
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGHUP, SIG_IGN);
D 2
	signal(SIGTERM, SIG_IGN);
E 2

D 2
	tty.sg_ispeed = tty.sg_ospeed = B4800;
E 2
I 2
D 4
	tty.sg_ispeed = tty.sg_ospeed = B9600;
E 4
I 4
#ifdef TTY
	tty.sg_ispeed = tty.sg_ospeed = BAUDRATE;
E 4
E 2
	tty.sg_erase = tty.sg_kill = -1;
D 2
	tty.sg_flags = (ANYP|XTABS|CRMOD|FLCTRL);
E 2
I 2
	tty.sg_flags = (ANYP|XTABS|LDECCTQ);
E 2
	if (ioctl(1, TIOCSETP, (char *)&tty) < 0)
		exit (2);
I 4
#endif
E 6
E 4
D 10
	setbuf(stdout, _sobuf);
E 10
I 3
#ifdef SHEETFEEDER
E 3
D 2
	printf ("\033=\r");
	while ((c = getchar()) != EOF)
		putchar (c);
	printf ("\033=\r");
E 2
I 2
	printf("\033=\033\033\033O\f");
I 3
#else
	printf("\033=");
#endif
E 3
	lnumber = 0;
	while (fgets(line, sizeof(line), stdin) != NULL) {
I 3
#ifdef SHEETFEEDER
E 3
		if (lnumber == PAGESIZE-1) {
			putchar('\f');
			lnumber = 0;
		}
		if (lnumber >= 2) {
I 3
#endif
I 4
#ifdef TTY
E 4
E 3
			if ((cp = rindex(line, '\n')) != NULL)
				*cp = '\r';
I 4
#endif
E 4
			printf("%s", line);
I 3
#ifdef SHEETFEEDER
E 3
		}
		lnumber++;
I 3
#endif
E 3
	}
E 2
	fflush (stdout);
}
E 1
