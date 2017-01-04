h38041
s 00010/00005/00079
d D 4.5 88/06/29 21:54:31 bostic 5 4
c install approved copyright notice
e
s 00062/00036/00022
d D 4.4 87/11/24 18:03:05 bostic 4 3
c make all errors return -1; general cleanup/lint; add copyright
e
s 00003/00003/00055
d D 4.3 86/03/13 20:28:13 mckusick 3 2
c setgid to group "write" so that terminals need not be world writable
e
s 00002/00002/00056
d D 4.2 80/10/19 02:04:30 bill 2 1
c compat with biff
e
s 00058/00000/00000
d D 4.1 80/10/01 17:27:25 bill 1 0
c date and time created 80/10/01 17:27:25 by bill
e
u
U
t
T
I 1
D 4
static char *sccsid = "%W% (Berkeley) %G%";
E 4
/*
I 4
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
I 5
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
E 5
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

/*
E 4
 * mesg -- set current tty to accept or
 *	forbid write permission.
 *
 *	mesg [y] [n]
 *		y allow messages
 *		n forbid messages
 */

D 4
#include <stdio.h>
E 4
#include <sys/types.h>
#include <sys/stat.h>
I 4
#include <stdio.h>
E 4

D 4
struct stat sbuf;
E 4
I 4
static char *tty;
E 4

D 4
char *tty;
char *ttyname();

E 4
main(argc, argv)
D 4
char *argv[];
E 4
I 4
	int argc;
	char **argv;
E 4
{
D 4
	int r=0;
	tty = ttyname(2);
	if (tty == 0)
		exit(13);
	if(stat(tty, &sbuf) < 0) error("cannot stat");
	if(argc < 2) {
D 3
		if(sbuf.st_mode & 02)
E 3
I 3
		if(sbuf.st_mode & 020)
E 3
			fprintf(stderr,"is y\n");
		else {	r=1;
			fprintf(stderr,"is n\n");
		}
	} else	switch(*argv[1]) {
		case 'y':
D 2
			newmode(0622); break;
E 2
I 2
D 3
			newmode(sbuf.st_mode|022); break;
E 3
I 3
			newmode(sbuf.st_mode|020); break;
E 4
I 4
	struct stat sbuf;
	char *ttyname();
E 4
E 3
E 2

D 4
		case 'n':
D 2
			newmode(0600); r=1; break;
E 2
I 2
D 3
			newmode(sbuf.st_mode&~022); r=1; break;
E 3
I 3
			newmode(sbuf.st_mode&~020); r=1; break;
E 3
E 2

		default:
			error("usage: mesg [y] [n]");
E 4
I 4
	if (!(tty = ttyname(2))) {
		fputs("mesg: not a device in /dev.\n", stderr);
		exit(-1);
	}
	if (stat(tty, &sbuf) < 0) {
		perror("mesg");
		exit(-1);
	}
	if (argc < 2) {
		if (sbuf.st_mode & 020) {
			fputs("is y\n", stderr);
			exit(0);
E 4
		}
D 4
	exit(r);
E 4
I 4
		fputs("is n\n", stderr);
		exit(1);
	}
#define	OTHER_WRITE	020
	switch(*argv[1]) {
	case 'y':
		newmode(sbuf.st_mode | OTHER_WRITE);
		exit(0);
	case 'n':
		newmode(sbuf.st_mode &~ OTHER_WRITE);
		exit(1);
	default:
		fputs("usage: mesg [y] [n]\n", stderr);
		exit(-1);
	}
	/*NOTREACHED*/
E 4
}

D 4
error(s)
char *s;
{
	fprintf(stderr,"mesg: %s\n",s);
	exit(-1);
}

E 4
I 4
static
E 4
newmode(m)
I 4
	u_short m;
E 4
{
D 4
	if(chmod(tty,m)<0)
		error("cannot change mode");
E 4
I 4
	if (chmod(tty, m) < 0) {
		perror("mesg");
		exit(-1);
	}
E 4
}
E 1
