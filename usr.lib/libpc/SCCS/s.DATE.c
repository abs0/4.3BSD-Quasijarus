h34236
s 00022/00000/00000
d D 1.1 80/10/30 00:33:02 mckusick 1 0
c date and time created 80/10/30 00:33:02 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

char	_pd_date[] = {
	8, 9, 10, 4, 5, 6, 10, 22, 23, 10, 0
};

extern char *ctime();

DATE(alfap)

	register char *alfap;
{
	register char *ap, *cp, *dp;
	long a;

	time(&a);
	cp = ctime(&a);
	ap = alfap;
	for (dp = _pd_date; *dp; *ap++ = cp[*dp++]);
}
E 1
