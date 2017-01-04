h38836
s 00002/00002/00011
d D 1.2 82/11/12 14:48:44 mckusick 2 1
c make size last arg to blkcpy and blkclr to be compatable with bcopy and bcmp
e
s 00013/00000/00000
d D 1.1 81/03/07 15:27:28 mckusick 1 0
c date and time created 81/03/07 15:27:28 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

D 2
blkclr(siz, at)
	long		siz;
E 2
I 2
blkclr(at, siz)
E 2
	register char	*at;
I 2
	long		siz;
E 2
{
	register int	size = siz;

	while(size-- > 0)
		*at++ = 0;
}
E 1
