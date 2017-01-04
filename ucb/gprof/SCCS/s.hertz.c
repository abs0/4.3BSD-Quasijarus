h41627
s 00010/00005/00033
d D 5.3 88/06/29 19:23:14 bostic 7 6
c install approved copyright notice
e
s 00009/00003/00029
d D 5.2 88/05/05 17:50:15 bostic 6 5
c add Berkeley specific header; written by K. McKusick and P. Kessler
e
s 00008/00002/00024
d D 5.1 85/06/04 13:28:43 dist 5 4
c Add copyright
e
s 00012/00044/00014
d D 1.4 85/03/24 19:52:08 mckusick 4 3
c use ``setitimer'' to find out the clock frequency instead of looking in kmem
e
s 00007/00010/00051
d D 1.3 84/01/30 16:37:56 peter 3 2
c keep this function safe for others.  return impossible value on error.
e
s 00014/00007/00047
d D 1.2 84/01/30 16:15:27 peter 2 1
c default hertz to something other than 0.  use 1 (e.g. ticks) for now.
e
s 00054/00000/00000
d D 1.1 83/01/11 15:04:53 peter 1 0
c date and time created 83/01/11 15:04:53 by peter
e
u
U
t
T
I 5
/*
 * Copyright (c) 1983 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
E 6
 */

E 5
I 1
#ifndef lint
D 5
    static	char *sccsid = "%W% (Berkeley) %G%";
#endif lint
E 5
I 5
static char sccsid[] = "%W% (Berkeley) %G%";
D 6
#endif not lint
E 6
I 6
#endif /* not lint */
E 6
E 5

I 4
#include <sys/time.h>

E 4
    /*
     *	discover the tick frequency of the machine
I 2
D 3
     *	if something goes wrong, we return HZ_DEFAULT.
E 3
I 3
     *	if something goes wrong, we return 0, an impossible hertz.
E 3
E 2
     */
D 4
#include <nlist.h>
#include <stdio.h>

D 2
struct nlist	nl[] =	{{"_hz"},	/* clock ticks per second */
E 2
I 2
#define	HZ_SYMBOL	"_hz"
E 4
D 3
#define	HZ_DEFAULT	1
E 3
I 3
#define	HZ_WRONG	0
E 3

D 4
struct nlist	nl[] =	{{HZ_SYMBOL},	/* clock ticks per second */
E 2
			 {0}};

E 4
hertz()
{
D 4
    int		kmem;			/* file descriptor for /dev/kmem */
    long	lseek();
    long	seeked;			/* return value from lseek() */
    long	hz;			/* buffer for reading from system */
    int		red;			/* return value from read() */
    int		closed;			/* return value from close() */
E 4
I 4
	struct itimerval tim;
E 4

D 4
#   define	VMUNIX	"/vmunix"	/* location of the system namelist */
    nlist(VMUNIX, nl);
    if (nl[0].n_type == 0) {
D 2
	fprintf(stderr, "no %s namelist entry for _hz\n", VMUNIX);
	return 0;
E 2
I 2
	fprintf(stderr, "no %s namelist entry for %s\n", VMUNIX, HZ_SYMBOL);
D 3
wrong:
	fprintf(stderr, "times are in units of %d tick%s, not seconds\n",
			HZ_DEFAULT, HZ_DEFAULT==1?"":"s");
	return HZ_DEFAULT;
E 3
I 3
	return HZ_WRONG;
E 3
E 2
    }
#   define	KMEM	"/dev/kmem"	/* location of the system data space */
    kmem = open(KMEM, 0);
    if (kmem == -1) {
	perror("hertz()");
	fprintf(stderr, "open(\"%s\", 0)", KMEM);
D 2
	return 0;
E 2
I 2
D 3
	goto wrong;
E 3
I 3
	return HZ_WRONG;
E 3
E 2
    }
    seeked = lseek(kmem, nl[0].n_value, 0);
    if (seeked == -1) {
	fprintf(stderr, "can't lseek(kmem, 0x%x, 0)\n", nl[0].n_value);
D 2
	return 0;
E 2
I 2
D 3
	goto wrong;
E 3
I 3
	return HZ_WRONG;
E 3
E 2
    }
    red = read(kmem, &hz, sizeof hz);
    if (red != sizeof hz) {
	fprintf(stderr, "read(kmem, 0x%x, %d) returned %d\n",
		&hz, sizeof hz, red);
D 2
	return 0;
E 2
I 2
D 3
	goto wrong;
E 3
I 3
	return HZ_WRONG;
E 3
E 2
    }
    closed = close(kmem);
    if (closed != 0) {
	perror("hertz()");
	fprintf(stderr, "close(\"%s\")", KMEM);
D 2
	return 0;
E 2
I 2
D 3
	goto wrong;
E 3
I 3
	return HZ_WRONG;
E 3
E 2
    }
    return hz;
E 4
I 4
	tim.it_interval.tv_sec = 0;
	tim.it_interval.tv_usec = 1;
	tim.it_value.tv_sec = 0;
	tim.it_value.tv_usec = 0;
	setitimer(ITIMER_REAL, &tim, 0);
	setitimer(ITIMER_REAL, 0, &tim);
	if (tim.it_interval.tv_usec < 2)
		return(HZ_WRONG);
	return (1000000 / tim.it_interval.tv_usec);
E 4
}
E 1
