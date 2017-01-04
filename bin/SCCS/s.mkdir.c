h22346
s 00012/00007/00035
d D 5.3 88/06/18 13:19:42 bostic 8 7
c install approved copyright notice
e
s 00019/00015/00023
d D 5.2 88/05/06 12:35:34 bostic 7 6
c don't need printf; add Berkeley header, this is a complete rewrite
e
s 00016/00001/00022
d D 5.1 85/04/30 15:04:44 dist 6 5
c Add copyright
e
s 00001/00001/00022
d D 4.5 85/01/31 14:01:55 serge 5 4
c reasonable error message
e
s 00001/00000/00022
d D 4.4 82/12/19 13:07:33 sam 4 3
c label perror's
e
s 00012/00067/00010
d D 4.3 82/12/19 13:05:37 sam 3 2
c use sys call
e
s 00006/00001/00071
d D 4.2 82/05/21 18:43:36 mckusick 2 1
c jkf's fix for group ownership
e
s 00072/00000/00000
d D 4.1 80/10/01 17:27:26 bill 1 0
c date and time created 80/10/01 17:27:26 by bill
e
u
U
t
T
I 1
D 6
static char *sccsid = "%W% (Berkeley) %G%";
E 6
I 6
/*
D 8
 * Copyright (c) 1983 Regents of the University of California.
E 8
I 8
 * Copyright (c) 1983 Regents of the University of California.
E 8
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
E 7
 */

#ifndef lint
char copyright[] =
D 8
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 8
I 8
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 8
 All rights reserved.\n";
D 7
#endif not lint
E 7
I 7
#endif /* not lint */
E 7

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif not lint
E 7
I 7
#endif /* not lint */
E 7

E 6
D 7
/*
D 3
** make directory
*/
E 3
I 3
 * make directory
 */
E 7
#include <stdio.h>
E 3

D 3
#include	<signal.h>
#include	<stdio.h>
I 2
#include	<sys/types.h>
#include	<stat.h>
E 2

int	Errors = 0;
char	*strcat();
char	*strcpy();

E 3
main(argc, argv)
D 3
char *argv[];
E 3
I 3
D 7
	char *argv[];
E 7
I 7
	int argc;
	char **argv;
E 7
E 3
{
I 3
D 7
	int errors = 0;
E 7
I 7
	int err;
E 7
E 3

D 3
	signal(SIGHUP, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);
	signal(SIGTERM, SIG_IGN);

	if(argc < 2) {
E 3
I 3
	if (argc < 2) {
E 3
D 5
		fprintf(stderr, "mkdir: arg count\n");
E 5
I 5
D 7
		fprintf(stderr, "usage: %s directory ...\n", argv[0]);
E 7
I 7
		fputs("usage: mkdir directory ...\n", stderr);
E 7
E 5
		exit(1);
	}
D 3
	while(--argc)
		mkdir(*++argv);
	exit(Errors!=0);
}

mkdir(d)
char *d;
{
	char pname[128], dname[128];
I 2
	struct stat statblk;
E 2
	register i, slash = 0;

	pname[0] = '\0';
	for(i = 0; d[i]; ++i)
		if(d[i] == '/')
			slash = i + 1;
	if(slash)
		strncpy(pname, d, slash);
	strcpy(pname+slash, ".");
	if (access(pname, 02)) {
		fprintf(stderr,"mkdir: cannot access %s\n", pname);
		++Errors;
		return;
	}
	if ((mknod(d, 040777, 0)) < 0) {
		fprintf(stderr,"mkdir: cannot make directory %s\n", d);
		++Errors;
		return;
	}
D 2
	chown(d, getuid(), getgid());
E 2
I 2
	(void) stat(d,&statblk);
	
	chown(d, getuid(), (int) statblk.st_gid);
E 2
	strcpy(dname, d);
	strcat(dname, "/.");
	if((link(d, dname)) < 0) {
		fprintf(stderr, "mkdir: cannot link %s\n", dname);
		unlink(d);
		++Errors;
		return;
	}
	strcat(dname, ".");
	if((link(pname, dname)) < 0) {
		fprintf(stderr, "mkdir: cannot link %s\n",dname);
		dname[strlen(dname)] = '\0';
		unlink(dname);
		unlink(d);
		++Errors;
	}
E 3
I 3
D 7
	while (--argc)
		if (mkdir(*++argv, 0777) < 0) {
I 4
			fprintf(stderr, "mkdir: ");
E 7
I 7
	for (err = 0; *++argv;)
		if (mkdir(*argv, 0777) < 0) {
			fputs("mkdir: ", stderr);
E 7
E 4
			perror(*argv);
D 7
			errors++;
E 7
I 7
			++err;
E 7
		}
D 7
	exit(errors != 0);
E 7
I 7
	exit(err ? 1 : 0);
E 7
E 3
}
E 1
