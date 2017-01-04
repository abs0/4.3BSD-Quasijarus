h05576
s 00010/00005/00073
d D 5.3 88/06/30 18:00:16 bostic 10 9
c install approved copyright notice
e
s 00009/00003/00069
d D 5.2 88/05/05 18:08:40 bostic 9 8
c written by Ralph Campbell; add Berkeley specific header
e
s 00007/00001/00065
d D 5.1 85/06/06 10:09:46 dist 8 7
c Add copyright
e
s 00004/00001/00062
d D 4.7 83/07/17 00:12:30 sam 7 6
c put sccs id's to some use
e
s 00038/00020/00025
d D 4.6 83/06/29 17:10:04 ralph 6 5
c changed to use unix domain ipc.
e
s 00003/00002/00042
d D 4.5 83/06/02 12:24:21 ralph 5 4
c made local variables static to improve separation between functions.
e
s 00017/00001/00027
d D 4.4 83/05/27 11:36:07 ralph 4 3
c improved error messages
e
s 00001/00001/00027
d D 4.3 83/05/18 16:46:05 ralph 3 2
c fixed lprm segmentation fault when remote is down.
e
s 00000/00000/00028
d D 4.2 83/05/13 11:54:01 ralph 2 1
c bug fixes and changes for lpc command.
e
s 00028/00000/00000
d D 4.1 83/04/29 11:30:46 ralph 1 0
c date and time created 83/04/29 11:30:46 by ralph
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
D 10
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
I 10
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
E 10
E 9
 */

E 8
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
#ifndef lint
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
/*
 * Tell the printer daemon that there are new files in the spool directory.
 */

D 6
#include "lp.h"
E 6
I 6
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "lp.local.h"
E 6

D 5
startdaemon()
E 5
I 5
D 6
startdaemon(ahost)
	char *ahost;
E 6
I 6
startdaemon(printer)
	char *printer;
E 6
E 5
{
D 6
	register int rem, i, err = 0;
E 6
I 6
	struct sockaddr_un sun;
	register int s, n;
E 6
	char buf[BUFSIZ];

D 3
	rem = getport();
E 3
I 3
D 5
	rem = getport(host);
E 5
I 5
D 6
	rem = getport(ahost);
E 5
E 3
D 4
	if (rem < 0)
E 4
I 4
	if (rem < 0) {
		perr();
E 6
I 6
	s = socket(AF_UNIX, SOCK_STREAM, 0);
	if (s < 0) {
		perr("socket");
E 6
E 4
		return(0);
I 4
	}
I 6
	sun.sun_family = AF_UNIX;
	strcpy(sun.sun_path, SOCKETNAME);
	if (connect(s, &sun, strlen(sun.sun_path) + 2) < 0) {
		perr("connect");
		(void) close(s);
		return(0);
	}
E 6
E 4
	(void) sprintf(buf, "\1%s\n", printer);
D 6
	i = strlen(buf);
	if (write(rem, buf, i) != i) {
I 4
		perr();
E 4
		(void) close(rem);
E 6
I 6
	n = strlen(buf);
	if (write(s, buf, n) != n) {
		perr("write");
		(void) close(s);
E 6
		return(0);
	}
D 6
	while ((i = read(rem, buf, sizeof(buf))) > 0) {
		(void) fwrite(buf, 1, i, stdout);
		err++;
E 6
I 6
	if (read(s, buf, 1) == 1) {
		if (buf[0] == '\0') {		/* everything is OK */
			(void) close(s);
			return(1);
		}
		putchar(buf[0]);
E 6
	}
I 4
D 6
	if (i < 0)
		perr();
E 4
	(void) close(rem);
	return(i == 0 && err == 0);
E 6
I 6
	while ((n = read(s, buf, sizeof(buf))) > 0)
		fwrite(buf, 1, n, stdout);
	(void) close(s);
	return(0);
E 6
I 4
}

static
D 6
perr()
E 6
I 6
perr(msg)
	char *msg;
E 6
{
I 6
	extern char *name;
E 6
	extern int sys_nerr;
	extern char *sys_errlist[];
I 6
	extern int errno;
E 6

D 6
	printf("%s: ", name);
E 6
I 6
	printf("%s: %s: ", name, msg);
E 6
	fputs(errno < sys_nerr ? sys_errlist[errno] : "Unknown error" , stdout);
	putchar('\n');
E 4
}
E 1
