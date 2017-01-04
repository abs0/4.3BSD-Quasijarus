h32093
s 00010/00005/00033
d D 5.3 88/06/29 21:51:18 bostic 5 4
c install approved copyright notice
e
s 00019/00015/00019
d D 5.2 88/06/09 19:52:53 bostic 4 3
c rewritten from the manual page; add Berkeley specific header
e
s 00016/00001/00018
d D 5.1 85/05/31 09:40:37 dist 3 2
c Add copyright
e
s 00001/00001/00018
d D 4.2 84/11/26 11:02:06 ralph 2 1
c use effective uid instead of real uid (for setuid scripts).
e
s 00019/00000/00000
d D 4.1 80/10/01 17:29:38 bill 1 0
c date and time created 80/10/01 17:29:38 by bill
e
u
U
t
T
I 1
D 3
static char *sccsid = "%W% (Berkeley) %G%";
E 3
I 3
/*
D 4
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
I 4
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
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
E 4
 */

#ifndef lint
char copyright[] =
D 4
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 4
I 4
"%Z% Copyright (c) 1988 Regents of the University of California.\n\
E 4
 All rights reserved.\n";
D 4
#endif not lint
E 4
I 4
#endif /* not lint */
E 4

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif not lint
E 4
I 4
#endif /* not lint */
E 4

I 4
#include <sys/types.h>
E 4
E 3
#include <pwd.h>
D 4
/*
 * whoami
 */
struct	passwd *getpwuid();
E 4

main()
{
D 4
	register struct passwd *pp;
E 4
I 4
	struct passwd *p, *getpwuid();
	uid_t uid;
E 4

D 2
	pp = getpwuid(getuid());
E 2
I 2
D 4
	pp = getpwuid(geteuid());
E 2
	if (pp == 0) {
		printf("Intruder alert.\n");
E 4
I 4
	uid = geteuid();
	if (!(p = getpwuid(uid))) {
		printf("whoami: no login associated with uid %u.\n", uid);
E 4
		exit(1);
	}
D 4
	printf("%s\n", pp->pw_name);
E 4
I 4
	printf("%s\n", p->pw_name);
E 4
	exit(0);
}
E 1
