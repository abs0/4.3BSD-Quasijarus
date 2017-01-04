h58218
s 00002/00002/00019
d D 1.3 82/11/12 14:48:48 mckusick 3 2
c make size last arg to blkcpy and blkclr to be compatable with bcopy and bcmp
e
s 00001/00001/00020
d D 1.2 81/09/28 22:00:55 mckusic 2 1
c fix for possibly overlapping strings
e
s 00021/00000/00000
d D 1.1 81/03/07 15:27:09 mckusick 1 0
c date and time created 81/03/07 15:27:09 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

D 3
blkcpy(siz, from, to)
	long		siz;
E 3
I 3
blkcpy(from, to, siz)
E 3
	register char	*from;
	register char	*to;
I 3
	long		siz;
E 3
{
	register int	size = siz;

D 2
	if (from + size < to)
E 2
I 2
	if (to < from)
E 2
		while(size-- > 0)
			*to++ = *from++;
	else {
		to += size;
		from += size;
		while(size-- > 0)
			*--to = *--from;
	}
}
E 1
