h15516
s 00007/00003/00210
d D 5.1 85/06/05 15:00:49 dist 9 8
c Add copyright
e
s 00000/00000/00213
d D 2.1 84/02/08 20:43:30 aoki 8 7
c synchronize to version 2
e
s 00000/00000/00213
d D 1.7 83/09/19 07:01:16 thien 7 6
c Restoring to unlinted version
e
s 00014/00010/00199
d D 1.6 83/08/19 05:03:12 thien 6 5
c The changes were made to allow successful linting
e
s 00001/00001/00208
d D 1.5 82/04/16 14:27:05 peter 5 4
c stat.h moved from /usr/include to /usr/include/sys.
e
s 00001/00009/00208
d D 1.4 80/11/24 19:34:38 peter 4 3
c Perror writes to stderr
e
s 00002/00002/00215
d D 1.3 80/11/24 18:59:55 peter 3 2
c malloc returns 0 on out of memory, not -1 as in version 6.
e
s 00006/00000/00211
d D 1.2 80/11/13 08:57:35 peter 2 1
c fix perror not to try to write sys_errlist (wnj)
e
s 00211/00000/00000
d D 1.1 80/08/27 19:56:41 peter 1 0
c date and time created 80/08/27 19:56:41 by peter
e
u
U
t
T
I 1
D 9
/* Copyright (c) 1979 Regents of the University of California */
E 9
I 9
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 9

I 6
#ifndef lint
E 6
D 9
static	char sccsid[] = "%Z%%M% %I% %G%";
I 6
#endif
E 9
I 9
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 9
E 6

#include "whoami.h"
#include "0.h"

#ifndef PI1
/*
 * Does the string fp end in '.' and the character c ?
 */
dotted(fp, c)
	register char *fp;
	char c;
{
	register int i;

	i = strlen(fp);
	return (i > 1 && fp[i - 2] == '.' && fp[i - 1] == c);
}

/*
 * Toggle the option c.
 */
togopt(c)
	char c;
{
	register char *tp;

	tp = &opt( c );
	*tp = 1 - *tp;
}

/*
 * Set the time vector "tvec" to the
 * modification time stamp of a file.
 */
gettime( filename )
    char *filename;
{
D 5
#include <stat.h>
E 5
I 5
#include <sys/stat.h>
E 5
	struct stat stb;

	stat(filename, &stb);
	tvec = stb.st_mtime;
}

/*
 * Convert a "ctime" into a Pascal styple time line
 */
char *
myctime(tv)
	int *tv;
{
	register char *cp, *dp;
I 6
	extern char *ctime();
E 6
	char *cpp;
D 6
	register i;
E 6
	static char mycbuf[26];

	cpp = ctime(tv);
	dp = mycbuf;
	cp = cpp;
	cpp[16] = 0;
	while (*dp++ = *cp++);
	dp--;
	cp = cpp+19;
	cpp[24] = 0;
	while (*dp++ = *cp++);
	return (mycbuf);
}

/*
 * Is "fp" in the command line list of names ?
 */
inpflist(fp)
	char *fp;
{
D 6
	register i, *pfp;
E 6
I 6
	register i;
	register char **pfp;
E 6

	pfp = pflist;
	for (i = pflstc; i > 0; i--)
D 6
		if (strcmp(fp, *pfp++) == 0)
E 6
I 6
		if (pstrcmp(fp, *pfp++) == 0)
E 6
			return (1);
	return (0);
}
#endif

extern	int errno;
extern	char *sys_errlist[];

/*
 * Boom!
 */
Perror(file, error)
	char *file, *error;
{

I 2
D 4
	write(2, file, strlen(file));
	write(2, ": ", 2);
	write(2, error, strlen(error));
	write(2, "\n", 1);
/*
E 2
	errno = 0;
	sys_errlist[0] = error;
	perror(file);
I 2
*/
E 4
I 4
	fprintf( stderr , "%s: %s\n" , file , error );
E 4
E 2
}

int *
D 6
calloc(num, size)
E 6
I 6
pcalloc(num, size)
E 6
	int num, size;
{
D 6
	register int p1, *p2, nbyte;
E 6
I 6
	register int *p1, *p2, nbyte;
E 6

	nbyte = (num*size+( ( sizeof ( int ) ) - 1 ) ) & ~( ( sizeof ( int ) ) - 1 );
D 3
	if ((p1 = malloc(nbyte)) == -1 || p1==0)
		return (-1);
E 3
I 3
D 6
	if ((p1 = malloc(nbyte)) == 0)
E 6
I 6
	if ((p1 = (int *) malloc((unsigned) nbyte)) == 0)
E 6
		return (0);
E 3
D 6
	p2 = p1;
E 6
I 6
	p2 =  p1;
E 6
	nbyte /= sizeof ( int );
	do {
		*p2++ = 0;
	} while (--nbyte);
	return (p1);
}

/*
 * Compare strings:  s1>s2: >0  s1==s2: 0  s1<s2: <0
 */
D 6
strcmp(s1, s2)
E 6
I 6
pstrcmp(s1, s2)
E 6
	register char *s1, *s2;
{

	while (*s1 == *s2++)
		if (*s1++=='\0')
			return (0);
	return (*s1 - *--s2);
}

/*
 * Copy string s2 to s1.
 * S1 must be large enough.
 * Return s1.
 */
D 6
strcpy(s1, s2)
E 6
I 6
char *
pstrcpy(s1, s2)
E 6
	register char *s1, *s2;
{
D 6
	register os1;
E 6
I 6
	register char *os1;
E 6

	os1 = s1;
	while (*s1++ = *s2++)
		continue;
	return (os1);
}

/*
 * Strlen is currently a freebie of perror
 * Take the length of a string.
 * Note that this does not include the trailing null!
strlen(cp)
	register char *cp;
{
	register int i;

	for (i = 0; *cp != 0; cp++)
		i++;
	return (i);
}
 */
copy(to, from, bytes)
	register char *to, *from;
	register int bytes;
{

	if (bytes != 0)
		do
			*to++ = *from++;
		while (--bytes);
}

/*
 * Is ch one of the characters in the string cp ?
 */
any(cp, ch)
	register char *cp;
	char ch;
{

	while (*cp)
		if (*cp++ == ch)
			return (1);
	return (0);
}

opush(c)
	register CHAR c;
{

	c -= 'A';
	optstk[c] <<= 1;
	optstk[c] |= opts[c];
	opts[c] = 1;
#ifdef PI0
	send(ROPUSH, c);
#endif
}

opop(c)
	register CHAR c;
{

	c -= 'A';
	opts[c] = optstk[c] & 1;
	optstk[c] >>= 1;
#ifdef PI0
	send(ROPOP, c);
#endif
}
E 1
