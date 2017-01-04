h31555
s 00010/00005/00081
d D 4.5 88/06/27 18:25:54 bostic 5 4
c install approved copyright notice
e
s 00077/00009/00009
d D 4.4 88/06/08 18:06:45 bostic 4 3
c rewrite tmpnam(BA_LIB) from manual page and add Berkeley specific header
c add tempnam(BA_LIB) and tmpfile(BA_LIB)
e
s 00002/00002/00016
d D 4.3 86/03/09 19:37:07 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00010/00001/00008
d D 4.2 85/05/30 13:54:19 mckusick 2 1
c Add copyrights
e
s 00009/00000/00000
d D 4.1 80/12/21 16:51:02 wnj 1 0
c date and time created 80/12/21 16:51:02 by wnj
e
u
U
t
T
I 1
D 2
/* %W% (Berkeley) %G% */
E 2
I 2
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
E 4
 */

D 3
#ifndef lint
E 3
I 3
#if defined(LIBC_SCCS) && !defined(lint)
E 3
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
D 4
#endif LIBC_SCCS and not lint
E 4
I 4
#endif /* LIBC_SCCS and not lint */
E 4
E 3

E 2
D 4
char *tmpnam(s)
char *s;
E 4
I 4
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <stdio.h>

#define	P_tmpdir	"/usr/tmp"

FILE *
tmpfile()
E 4
{
D 4
	static seed;
E 4
I 4
	FILE *fp;
	char *f, name[MAXPATHLEN], *tmpnam();
E 4

D 4
	sprintf(s, "temp.%d.%d", getpid(), seed++);
	return(s);
E 4
I 4
	if (!(fp = fopen(f = tmpnam(name), "w+"))) {
		fprintf(stderr, "tmpfile: cannot open %s.\n", name);
		return(NULL);
	}
	(void)unlink(f);
	return(fp);
}

char *
tmpnam(s)
	char *s;
{
	static char name[MAXPATHLEN];
	char *mktemp();

	if (!s)
		s = name;
	(void)sprintf(s, "%s/XXXXXX", P_tmpdir);
	return(mktemp(s));
}

char *
tempnam(dir, pfx)
	char *dir, *pfx;
{
	struct stat buf;
	char *f, *name, *getenv(), *malloc(), *mktemp(), *strcat(), *strcpy();

	if (!(name = malloc((u_int)MAXPATHLEN)))
		return(NULL);
	if ((f = getenv("TMPDIR")) && !stat(f, &buf) &&
	    (buf.st_mode&S_IFMT) == S_IFDIR && !access(f, W_OK|X_OK)) {
		(void)strcpy(name, f);
		goto done;
	}
	if (dir && !stat(dir, &buf) &&
	    (buf.st_mode&S_IFMT) == S_IFDIR && !access(dir, W_OK|X_OK)) {
		(void)strcpy(name, dir);
		goto done;
	}
	if (!stat(P_tmpdir, &buf) &&
	    (buf.st_mode&S_IFMT) == S_IFDIR && !access(P_tmpdir, W_OK|X_OK)) {
		(void)strcpy(name, P_tmpdir);
		goto done;
	}
	if (!stat("/tmp", &buf) &&
	    (buf.st_mode&S_IFMT) == S_IFDIR && !access("/tmp", W_OK|X_OK)) {
		(void)strcpy(name, "/tmp");
		goto done;
	}
	return(NULL);
done:	(void)strcat(name, "/");
	if (pfx)
		(void)strcat(name, pfx);
	(void)strcat(name, "XXXXXX");
	return(mktemp(name));
E 4
}
E 1
