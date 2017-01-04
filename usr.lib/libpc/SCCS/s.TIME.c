h31641
s 00019/00000/00000
d D 1.1 80/10/30 00:36:06 mckusick 1 0
c date and time created 80/10/30 00:36:06 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

extern char *ctime();

TIME(alfap)

	register char *alfap;
{
	register char *ap, *cp;
	register int i;
	long a;

	time(&a);
	cp = ctime(&a);
	ap = alfap;
	for (cp = cp + 10, i = 10; i; *ap++ = *cp++, i--);
}
E 1
