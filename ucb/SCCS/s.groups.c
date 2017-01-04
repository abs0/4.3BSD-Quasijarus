h01703
s 00010/00005/00079
d D 5.3 88/06/29 21:50:43 bostic 11 10
c install approved copyright notice
e
s 00012/00006/00072
d D 5.2 88/04/20 16:36:56 bostic 10 9
c add Berkeley specific header
e
s 00013/00001/00065
d D 5.1 85/05/31 09:16:40 dist 9 8
c Add copyright
e
s 00013/00001/00053
d D 4.8 83/09/25 12:51:37 sam 8 7
c print out base group when user supplied; from lepreau@utah-cs
e
s 00003/00001/00051
d D 4.7 83/08/11 21:30:56 sam 7 6
c standardize sccs keyword lines
e
s 00022/00003/00030
d D 4.6 83/06/29 12:56:02 sam 6 5
c lost delta kevin and I made some time back
e
s 00001/00001/00032
d D 4.5 83/02/15 21:51:46 mckusick 5 4
c groups go from short to int
e
s 00001/00001/00032
d D 4.4 83/02/10 21:05:35 sam 4 3
c gid's are shorts
e
s 00011/00011/00022
d D 4.3 82/11/15 11:32:40 sam 3 2
c conversion to 4.1c
e
s 00001/00001/00032
d D 4.2 82/09/11 19:07:31 mckusick 2 1
c change setgrp(0, grps) to getgrp(grps)
e
s 00033/00000/00000
d D 4.1 82/02/28 23:41:52 wnj 1 0
c date and time created 82/02/28 23:41:52 by wnj
e
u
U
t
T
I 9
/*
 * Copyright (c) 1980 Regents of the University of California.
D 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
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
E 10
 */

E 9
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
#ifndef lint
I 9
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 10
#endif not lint
E 10
I 10
#endif /* not lint */
E 10

#ifndef lint
E 9
static char sccsid[] = "%W% (Berkeley) %G%";
D 9
#endif
E 9
I 9
D 10
#endif not lint
E 10
I 10
#endif /* not lint */
E 10
E 9
E 7

/*
 * groups
 */

#include <sys/param.h>
#include <grp.h>
#include <pwd.h>
I 8
#include <stdio.h>
E 8

D 3
int	grps[NGRPS/(sizeof(int)*8)];
E 3
I 3
D 4
int	groups[NGROUPS];
E 4
I 4
D 5
short	groups[NGROUPS];
E 5
I 5
int	groups[NGROUPS];
E 5
E 4
E 3
D 6
struct	group *gr, *getgrgid();
E 6

main(argc, argv)
	int argc;
	char *argv[];
{
I 3
D 6
	int ngroups;
E 6
I 6
	int ngroups, i;
E 6
E 3
	char *sep = "";
D 6
	int i;
E 6
I 6
	struct group *gr;
E 6

I 6
	if (argc > 1)
		showgroups(argv[1]);
E 6
D 2
	setgrp(0, grps);
E 2
I 2
D 3
	getgrp(grps);
E 2
	for (i = 0; i < NGRPS; i++)
		if (grps[i/(sizeof(int)*8)] & (1<<(i%(sizeof(int)*8)))) {
			gr = getgrgid(i);
			if (gr == NULL)
				printf("%s%d", sep, i);
			else
				printf("%s%s", sep, gr->gr_name);
			sep = " ";
		}
E 3
I 3
	ngroups = getgroups(NGROUPS, groups);
	for (i = 0; i < ngroups; i++) {
		gr = getgrgid(groups[i]);
		if (gr == NULL)
			printf("%s%d", sep, groups[i]);
		else
			printf("%s%s", sep, gr->gr_name);
		sep = " ";
	}
I 6
	printf("\n");
	exit(0);
}

showgroups(user)
	register char *user;
{
	register struct group *gr;
I 8
	register struct passwd *pw;
E 8
	register char **cp;
	char *sep = "";

D 8
	while (gr = getgrent())
E 8
I 8
	if ((pw = getpwnam(user)) == NULL) {
D 10
		fprintf(stderr, "No such user\n");
E 10
I 10
		fprintf(stderr, "groups: no such user.\n");
E 10
		exit(1);
	}
	while (gr = getgrent()) {
		if (pw->pw_gid == gr->gr_gid) {
			printf("%s%s", sep, gr->gr_name);
			sep = " ";
			continue;
D 10
		}	
E 10
I 10
		}
E 10
E 8
		for (cp = gr->gr_mem; cp && *cp; cp++)
			if (strcmp(*cp, user) == 0) {
				printf("%s%s", sep, gr->gr_name);
				sep = " ";
				break;
			}
I 8
	}
E 8
E 6
E 3
	printf("\n");
	exit(0);
}
E 1
