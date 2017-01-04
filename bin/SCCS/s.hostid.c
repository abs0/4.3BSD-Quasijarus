h41491
s 00012/00007/00058
d D 5.6 88/06/18 13:20:04 bostic 9 8
c install approved copyright notice
e
s 00019/00019/00046
d D 5.5 88/06/06 15:38:15 bostic 8 7
c add Berkeley specific header; lint cleanups
e
s 00014/00011/00051
d D 5.4 86/05/19 20:47:59 karels 7 6
c precedence problems
e
s 00003/00004/00059
d D 5.3 85/11/28 11:12:27 bloom 6 5
c some hostnames could be interepted wrong, types of gethostid/sethostid changed
e
s 00014/00003/00049
d D 5.2 85/09/18 17:06:37 karels 5 4
c allow internet hostname to be used as initializer
e
s 00013/00001/00039
d D 5.1 85/04/30 14:55:46 dist 4 3
c Add copyright
e
s 00030/00007/00010
d D 4.3 85/03/21 14:32:43 ralph 3 2
c allow internet address besides hex numbers
e
s 00003/00001/00014
d D 4.2 83/08/11 19:52:38 sam 2 1
c sccs keyword fixes
e
s 00015/00000/00000
d D 4.1 82/11/07 20:02:07 sam 1 0
c date and time created 82/11/07 20:02:07 by sam
e
u
U
t
T
I 4
/*
D 8
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
D 9
 * Copyright (c) 1983, 1988 Regents of the University of California.
E 9
I 9
 * Copyright (c) 1983, 1988 Regents of the University of California.
E 9
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

E 4
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
#ifndef lint
I 4
char copyright[] =
D 8
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 8
I 8
D 9
"%Z% Copyright (c) 1983, 1988 Regents of the University of California.\n\
E 9
I 9
"%Z% Copyright (c) 1983, 1988 Regents of the University of California.\n\
E 9
E 8
 All rights reserved.\n";
D 8
#endif not lint
E 8
I 8
#endif /* not lint */
E 8

#ifndef lint
E 4
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif
E 4
I 4
D 8
#endif not lint
E 8
I 8
#endif /* not lint */
E 8
E 4
E 2

I 5
#include <sys/types.h>
E 5
I 3
#include <stdio.h>
I 5
D 8
#include <ctype.h>
E 8
#include <netdb.h>
E 5

D 8
extern	char *index();
extern	unsigned long inet_addr();
I 6
extern	long gethostid();
E 6

E 8
E 3
main(argc, argv)
	int argc;
	char **argv;
{
I 3
	register char *id;
I 5
D 8
	u_long addr;
E 5
D 6
	int hostid;
E 6
I 6
	long hostid;
E 8
E 6
I 5
	struct hostent *hp;
I 8
	u_long addr, inet_addr();
	long hostid, gethostid();
	char *index();
E 8
E 5
E 3

D 3
	if (argc > 1) {
		int hostid;
		sscanf(argv[1], "%x", &hostid);
		if (sethostid(hostid) < 0)
			perror("hostid");
	} else
		printf("%x\n", gethostid());
E 3
I 3
	if (argc < 2) {
D 8
		printf("%#x\n", gethostid());
E 8
I 8
		printf("%#lx\n", gethostid());
E 8
		exit(0);
	}
D 7
	id = argv[1];
E 7

D 5
	if (index(id, '.') != NULL)
E 5
I 5
D 6
	if (isxdigit(id[0]) && index(id, '.') != NULL)
E 5
		hostid = (int) inet_addr(id);
	else {
E 6
I 6
D 7
	if ((hostid = inet_addr(id)) == -1) {
E 6
		if (*id == '0' && (id[1] == 'x' || id[1] == 'X'))
E 7
I 7
	id = argv[1];
	if (hp = gethostbyname(id)) {
		bcopy(hp->h_addr, &addr, sizeof(addr));
		hostid = addr;
	} else if (index(id, '.')) {
		if ((hostid = inet_addr(id)) == -1)
			goto usage;
	} else {
		if (id[0] == '0' && (id[1] == 'x' || id[1] == 'X'))
E 7
			id += 2;
D 8
		if (sscanf(id, "%x", &hostid) != 1) {
D 5
			fprintf(stderr, "usage: %s [hexnum or internet address]\n", argv[0]);
			exit(1);
E 5
I 5
D 7
			if (hp = gethostbyname(argv[1])) {
				bcopy(hp->h_addr, &addr, sizeof(addr));
				hostid = addr;
			} else {
				fprintf(stderr,
			"usage: %s [hexnum or internet address]\n", argv[0]);
				exit(1);
			}
E 7
I 7
usage:
			fprintf(stderr,
			    "usage: %s [hexnum or internet address]\n",
			    argv[0]);
E 8
I 8
		if (sscanf(id, "%lx", &hostid) != 1) {
usage:			fputs("usage: hostid [hexnum or internet address]\n",
			    stderr);
E 8
			exit(1);
E 7
E 5
		}
	}

	if (sethostid(hostid) < 0) {
		perror("sethostid");
		exit(1);
	}

	exit(0);
E 3
}
E 1
