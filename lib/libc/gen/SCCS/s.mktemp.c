h06003
s 00010/00005/00097
d D 5.7 88/06/27 17:34:08 bostic 8 7
c install approved copyright notice
e
s 00001/00001/00101
d D 5.6 88/05/23 20:42:00 bostic 7 6
c ANSI C fix
e
s 00008/00002/00094
d D 5.5 87/11/30 11:13:51 bostic 6 5
c Berkeley code; fix copyright
e
s 00017/00010/00079
d D 5.4 87/09/14 12:30:03 bostic 5 4
c use stat, not access; bug report 4.3BSD/lib/94
e
s 00076/00017/00013
d D 5.3 87/04/10 14:58:52 bostic 4 3
c bug report 4.2BSD/lib/63
e
s 00002/00002/00028
d D 5.2 86/03/09 19:50:51 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00003/00001/00027
d D 5.1 85/06/05 12:27:33 mckusick 2 1
c Add copyright
e
s 00028/00000/00000
d D 4.1 83/06/22 18:18:00 root 1 0
c date and time created 83/06/22 18:18:00 by root
e
u
U
t
T
I 4
/*
 * Copyright (c) 1987 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
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
E 6
 */

E 4
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
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
D 7
#endif LIBC_SCCS and not lint
E 7
I 7
#endif /* LIBC_SCCS and not lint */
E 7
E 3
E 2

I 4
#include <sys/types.h>
#include <sys/file.h>
I 5
#include <sys/stat.h>
#include <errno.h>
E 5
#include <stdio.h>
#include <ctype.h>

#define	YES	1
#define	NO	0

mkstemp(as)
	char	*as;
{
	int	fd;

	return (_gettemp(as, &fd) ? fd : -1);
}

E 4
char *
mktemp(as)
D 4
char *as;
E 4
I 4
	char	*as;
E 4
{
D 4
	register char *s;
	register unsigned pid;
	register i;
E 4
I 4
	return(_gettemp(as, (int *)NULL) ? as : (char *)NULL);
}
E 4

I 4
static
_gettemp(as, doopen)
	char	*as;
	register int	*doopen;
{
I 5
	extern int	errno;
E 5
	register char	*start, *trv;
I 5
	struct stat	sbuf;
E 5
	u_int	pid;
D 5
	char	savech;
E 5

E 4
	pid = getpid();
D 4
	s = as;
	while (*s++)
		;
	s--;
	while (*--s == 'X') {
		*s = (pid%10) + '0';
E 4
I 4

	/* extra X's get set to 0's */
D 5
	for (trv = as;*trv;++trv);
E 5
I 5
	for (trv = as; *trv; ++trv);
E 5
	while (*--trv == 'X') {
		*trv = (pid % 10) + '0';
E 4
		pid /= 10;
	}
D 4
	s++;
	i = 'a';
	while (access(as, 0) != -1) {
		if (i=='z')
			return("/");
		*s = i++;
E 4
I 4

	/*
	 * check for write permission on target directory; if you have
	 * six X's and you can't write the directory, this will run for
	 * a *very* long time.
	 */
D 5
	for (start = ++trv;trv > as && *trv != '/';--trv);
E 5
I 5
	for (start = ++trv; trv > as && *trv != '/'; --trv);
E 5
	if (*trv == '/') {
D 5
		savech = *++trv;
E 5
		*trv = '\0';
D 5
		if (access(as, W_OK))
E 5
I 5
		if (stat(as, &sbuf) || !(sbuf.st_mode & S_IFDIR))
E 5
			return(NO);
D 5
		*trv = savech;
E 5
I 5
		*trv = '/';
E 5
E 4
	}
D 4
	return(as);
E 4
I 4
D 5
	else if (access(".", W_OK))
E 5
I 5
	else if (stat(".", &sbuf) == -1)
E 5
		return(NO);

	for (;;) {
D 5
		if (doopen
		    && (*doopen = open(as, O_CREAT|O_EXCL|O_RDWR, 0600)) != -1
		    || access(as, F_OK))
E 5
I 5
		if (doopen) {
		    if ((*doopen = open(as, O_CREAT|O_EXCL|O_RDWR, 0600)) >= 0)
E 5
			return(YES);
I 5
		    if (errno != EEXIST)
			return(NO);
		}
		else if (stat(as, &sbuf))
			return(errno == ENOENT ? YES : NO);

E 5
		/* tricky little algorithm for backward compatibility */
		for (trv = start;;) {
			if (!*trv)
				return(NO);
			if (*trv == 'z')
				*trv++ = 'a';
			else {
				if (isdigit(*trv))
					*trv = 'a';
				else
					++*trv;
				break;
			}
		}
	}
	/*NOTREACHED*/
E 4
}
E 1
