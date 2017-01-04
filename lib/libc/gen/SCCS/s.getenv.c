h06391
s 00010/00005/00054
d D 5.5 88/06/27 17:34:05 bostic 9 8
c install approved copyright notice
e
s 00026/00015/00033
d D 5.4 87/12/24 15:26:49 bostic 8 4
c add copyright, minor formatting changes
e
s 00100/00020/00034
d R 5.5 87/12/24 15:12:49 bostic 7 5
c fold in setenv() and unsetenv(); includes bug fix 4.3BSD/lib/70
c add Berkeley specific header, this is a rewrite
e
s 00002/00002/00052
d R 5.5 87/03/28 11:27:04 bostic 6 5
c new time package
e
s 00006/00000/00048
d R 5.4 87/03/13 14:00:53 bostic 5 4
c added copyright
e
s 00030/00026/00018
d D 5.3 87/03/11 16:14:29 bostic 4 3
c added _findenv, fixed getenv to use it
e
s 00002/00002/00042
d D 5.2 86/03/09 19:47:02 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00004/00001/00040
d D 5.1 85/06/05 12:18:27 mckusick 2 1
c Add copyright
e
s 00041/00000/00000
d D 4.1 80/12/21 16:39:41 wnj 1 0
c date and time created 80/12/21 16:39:41 by wnj
e
u
U
t
T
I 8
/*
 * Copyright (c) 1987 Regents of the University of California.
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
 */

E 8
I 1
D 2
/* %W% (Berkeley) %G% */
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
D 8
#endif LIBC_SCCS and not lint
E 8
I 8
#endif /* LIBC_SCCS and not lint */
E 8
E 3

I 4
#include <stdio.h>

E 4
E 2
/*
D 4
 *	getenv(name)
 *	returns ptr to value associated with name, if any, else NULL
E 4
I 4
D 8
 * getenv(name) --
E 8
I 8
 * getenv --
E 8
 *	Returns ptr to value associated with name, if any, else NULL.
E 4
 */
D 4
#define NULL	0
extern	char **environ;
char	*nvmatch();

E 4
char *
getenv(name)
D 4
register char *name;
E 4
I 4
	char *name;
E 4
{
D 4
	register char **p = environ;
	register char *v;
E 4
I 4
D 8
	int	offset;
	char	*_findenv();
E 8
I 8
	int offset;
	char *_findenv();
E 8
E 4

D 4
	while (*p != NULL)
		if ((v = nvmatch(name, *p++)) != NULL)
			return(v);
	return(NULL);
E 4
I 4
D 8
	return(_findenv(name,&offset));
E 8
I 8
	return(_findenv(name, &offset));
E 8
E 4
}

/*
D 4
 *	s1 is either name, or name=value
 *	s2 is name=value
 *	if names match, return value of s2, else NULL
 *	used for environment searching: see getenv
E 4
I 4
D 8
 * _findenv(name,offset) --
E 8
I 8
 * _findenv --
E 8
 *	Returns pointer to value associated with name, if any, else NULL.
 *	Sets offset to be the offset of the name/value combination in the
 *	environmental array, for use by setenv(3) and unsetenv(3).
 *	Explicitly removes '=' in argument name.
 *
 *	This routine *should* be a static; don't use it.
E 4
 */
D 4

static char *
nvmatch(s1, s2)
register char *s1, *s2;
E 4
I 4
char *
D 8
_findenv(name,offset)
E 8
I 8
_findenv(name, offset)
E 8
	register char *name;
D 8
	int	*offset;
E 8
I 8
	int *offset;
E 8
E 4
{
I 4
D 8
	extern char	**environ;
	register int	len;
	register char	**P,
			*C;
E 8
I 8
	extern char **environ;
	register int len;
	register char **P, *C;
E 8
E 4

D 4
	while (*s1 == *s2++)
		if (*s1++ == '=')
			return(s2);
	if (*s1 == '\0' && *(s2-1) == '=')
		return(s2);
E 4
I 4
D 8
	for (C = name,len = 0;*C && *C != '=';++C,++len);
	for (P = environ;*P;++P)
		if (!strncmp(*P,name,len))
E 8
I 8
	for (C = name, len = 0; *C && *C != '='; ++C, ++len);
	for (P = environ; *P; ++P)
		if (!strncmp(*P, name, len))
E 8
			if (*(C = *P + len) == '=') {
				*offset = P - environ;
				return(++C);
			}
E 4
	return(NULL);
}
E 1
