h48680
s 00003/00002/00017
d D 1.2 81/03/07 15:58:14 mckusic 2 1
c merge in onyx changes
e
s 00019/00000/00000
d D 1.1 80/10/30 00:33:50 mckusick 1 0
c date and time created 80/10/30 00:33:50 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

long *
D 2
MULT(result0, left, right, size)
E 2
I 2
MULT(result0, left, right, siz)
E 2

	long		*result0;
	register long	*left;
	register long	*right;
D 2
	register int	size;
E 2
I 2
	long		siz;
E 2
{
	register long	*result = result0;
I 2
	register int	size = siz;
E 2

	do {
		*result++ = *left++ & *right++;
	} while (--size);
	return result0;
}
E 1
