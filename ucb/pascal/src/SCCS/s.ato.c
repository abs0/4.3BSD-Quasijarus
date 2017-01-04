h56975
s 00007/00004/00039
d D 5.1 85/06/04 11:34:48 dist 8 7
c Add copyright
e
s 00000/00000/00043
d D 2.1 84/02/08 20:40:47 aoki 7 6
c synchronize to version 2
e
s 00000/00000/00043
d D 1.6 83/09/19 07:03:41 thien 6 5
c 
e
s 00001/00000/00042
d D 1.5 83/09/19 06:51:44 thien 5 4
c 
e
s 00000/00000/00042
d D 1.4 83/09/19 06:48:44 thien 4 3
c 
e
s 00002/00000/00040
d D 1.3 83/08/19 04:55:07 thien 3 2
c The changes were made to allow successful linting
e
s 00002/00002/00038
d D 1.2 81/03/08 19:23:56 mckusic 2 1
c merge in onyx changes
e
s 00040/00000/00000
d D 1.1 80/08/27 19:54:38 peter 1 0
c date and time created 80/08/27 19:54:38 by peter
e
u
U
t
T
I 1
D 8
/* Copyright (c) 1979 Regents of the University of California */
E 8
I 8
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 8

I 3
#ifndef lint
E 3
D 2
static	char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
D 8
static char sccsid[] = "%Z%%M% %I% %G%";
I 3
#endif
I 5
/* This is an sccs experiment */
E 8
I 8
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 8
E 5
E 3
E 2

#include "whoami.h"
#include "0.h"

long
a8tol(cp)
	char *cp;
{
	int err;
	long l;
	register CHAR c;

	l = 0;
	err = 0;
	while ((c = *cp++) != '\0') {
		if (c == '8' || c == '9')
			if (err == 0) {
				error("8 or 9 in octal number");
				err++;
			}
		c -= '0';
D 2
		if ((l & 0160000000000L) != 0)
E 2
I 2
		if ((l & 016000000000L) != 0)
E 2
			if (err == 0) {
				error("Number too large for this implementation");
				err++;
			}
		l = (l << 3) | c;
	}
	return (l);
}

/*
 * Note that the version of atof
 * used in this compiler does not
 * (sadly) complain when floating
 * point numbers are too large.
 */
E 1
