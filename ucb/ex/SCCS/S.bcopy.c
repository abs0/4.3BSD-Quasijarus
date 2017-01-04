h01218
s 00005/00001/00026
d D 7.4 87/03/09 12:46:09 conrad 8 7
c make ex/vi work on vms
e
s 00001/00001/00026
d D 7.3 85/06/07 18:18:06 bloom 7 6
c fix sccsid and copyright for xstr
e
s 00010/00001/00017
d D 7.2 85/05/31 13:49:36 dist 6 4
c Add copyright
e
s 00010/00001/00017
d D 5.1.1.1 85/05/31 11:55:58 dist 5 2
c Add copyright
e
s 00002/00002/00016
d D 7.1 81/07/08 22:36:38 mark 4 3
c release 3.7 - a few bug fixes and a few new features.
e
s 00000/00000/00018
d D 6.1 80/10/19 01:19:48 mark 3 2
c preliminary release 3.6 10/18/80
e
s 00000/00000/00018
d D 5.1 80/08/20 16:17:15 mark 2 1
c Release 3.5, August 20, 1980
e
s 00018/00000/00000
d D 4.1 80/08/01 21:04:02 mark 1 0
c date and time created 80/08/01 21:04:02 by mark
e
u
U
t
T
I 6
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 7
static char sccsid[] = "%W% (Berkeley) %G%";
E 7
I 7
static char *sccsid = "%W% (Berkeley) %G%";
E 7
#endif not lint

E 6
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 5
I 1
/* block copy from from to to, count bytes */
D 4
D 5
static char *sccsid = "%W% %G%";
E 5
E 4
I 4
D 6
static char *sccsid = "%W%	%G%";
E 6
E 4
bcopy(from, to, count)
#ifdef vax
	char *from, *to;
	int count;
{
D 8

E 8
I 8
#ifndef vms
E 8
	asm("	movc3	12(ap),*4(ap),*8(ap)");
I 8
	/* ARGSUSED */
#else
	lib$movc3(&count, from, to);
#endif
E 8
}
#else
	register char *from, *to;
	register int count;
{
D 4
	while (count--)
E 4
I 4
	while ((count--) > 0)	/* mjm */
E 4
		*to++ = *from++;
}
#endif
E 1
