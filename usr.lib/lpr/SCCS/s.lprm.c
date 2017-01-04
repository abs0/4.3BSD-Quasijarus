h46956
s 00010/00005/00105
d D 5.4 88/06/30 18:00:01 bostic 9 8
c install approved copyright notice
e
s 00010/00004/00100
d D 5.3 88/05/05 18:08:14 bostic 8 7
c written by Ralph Campbell; add Berkeley specific header
e
s 00001/00000/00103
d D 5.2 85/11/17 15:53:51 eric 7 6
c clean up logging
e
s 00013/00001/00090
d D 5.1 85/06/06 10:05:26 dist 6 5
c Add copyright
e
s 00004/00001/00087
d D 4.5 83/07/17 00:11:40 sam 5 4
c put sccs id's to some use
e
s 00007/00007/00081
d D 4.4 83/06/02 12:23:35 ralph 4 3
c made local variables static to improve separation between functions.
e
s 00006/00001/00082
d D 4.3 83/05/26 09:18:48 ralph 3 2
c fixed -P option so -Pprinter and -P printer both work.
e
s 00000/00000/00083
d D 4.2 83/05/13 11:53:09 ralph 2 1
c bug fixes and changes for lpc command.
e
s 00083/00000/00000
d D 4.1 83/04/29 11:29:13 ralph 1 0
c date and time created 83/04/29 11:29:13 by ralph
e
u
U
t
T
I 6
/*
 * Copyright (c) 1983 Regents of the University of California.
D 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 8
 */

E 6
I 1
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
#ifndef lint
I 6
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
D 8
#endif not lint
E 8
I 8
#endif /* not lint */
E 8

#ifndef lint
E 6
static char sccsid[] = "%W% (Berkeley) %G%";
D 6
#endif
E 6
I 6
D 8
#endif not lint
E 8
I 8
#endif /* not lint */
E 8
E 6

E 5
/*
 * lprm - remove the current user's spool entry
 *
 * lprm [-] [[job #] [user] ...]
 *
 * Using information in the lock file, lprm will kill the
 * currently active daemon (if necessary), remove the associated files,
 * and startup a new daemon.  Priviledged users may remove anyone's spool
 * entries, otherwise one can only remove their own.
 */

#include "lp.h"

/*
 * Stuff for handling job specifications
 */
D 4
char	*user[MAXUSERS];		/* users to process */
int	users;				/* # of users in user array */
int	requ[MAXREQUESTS];		/* job number of spool entries */
int	requests;			/* # of spool requests */
E 4
I 4
char	*user[MAXUSERS];	/* users to process */
int	users;			/* # of users in user array */
int	requ[MAXREQUESTS];	/* job number of spool entries */
int	requests;		/* # of spool requests */
char	*person;		/* name of person doing lprm */
E 4

D 4
extern char	*person;		/* name of person doing lprm */
char		luser[16];		/* buffer for person */
E 4
I 4
static char	luser[16];	/* buffer for person */
E 4

struct passwd *getpwuid();

main(argc, argv)
	char *argv[];
{
	register char *arg;
	struct passwd *p;
	struct direct **files;
	int nitems, assasinated = 0;
D 4
	int select();
E 4

	name = argv[0];
	gethostname(host, sizeof(host));
I 7
	openlog("lpd", 0, LOG_LPR);
E 7
	if ((p = getpwuid(getuid())) == NULL)
		fatal("Who are you?");
	if (strlen(p->pw_name) >= sizeof(luser))
		fatal("Your name is too long");
	strcpy(luser, p->pw_name);
	person = luser;
	while (--argc) {
		if ((arg = *++argv)[0] == '-')
			switch (arg[1]) {
			case 'P':
D 3
				printer = &arg[2];
E 3
I 3
				if (arg[2])
					printer = &arg[2];
				else if (argc > 1) {
					argc--;
					printer = *++argv;
				}
E 3
				break;
			case '\0':
				if (!users) {
					users = -1;
					break;
				}
			default:
				usage();
			}
		else {
			if (users < 0)
				usage();
			if (isdigit(arg[0])) {
				if (requests >= MAXREQUESTS)
					fatal("Too many requests");
				requ[requests++] = atoi(arg);
			} else {
				if (users >= MAXUSERS)
					fatal("Too many users");
				user[users++] = arg;
			}
		}
	}
	if (printer == NULL && (printer = getenv("PRINTER")) == NULL)
		printer = DEFLP;

	rmjob();
}

I 4
static
E 4
usage()
{
	printf("usage: lprm [-] [-Pprinter] [[job #] [user] ...]\n");
	exit(2);
}
E 1
