h31128
s 00015/00001/00022
d D 5.1 85/06/05 15:54:44 dist 4 3
c Add copyright
e
s 00001/00001/00022
d D 2.2 84/04/02 14:04:47 peter 3 2
c time.h moves to sys/time.h.
e
s 00000/00000/00023
d D 2.1 84/02/08 20:23:54 aoki 2 1
c synchronizing at version 2
e
s 00023/00000/00000
d D 1.1 82/08/13 15:32:45 peter 1 0
c date and time created 82/08/13 15:32:45 by peter
e
u
U
t
T
I 1
D 4
static	char *sccsid = "%W% (Berkeley) %E%";
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 4

D 3
#include <time.h>
E 3
I 3
#include <sys/time.h>
E 3
#include <stdio.h>

extern char	version[];

main()
{
    long	time();
    long	clock;
    struct tm	*localtime();
    struct tm	*tmp;
    int		major;
    int		minor;

    time(&clock);
    tmp = localtime(&clock);
    sscanf(version, "%d.%d", &major, &minor);
    minor += 1;
    printf("char	version[] = \"%d.%d (%d/%d/%d)\";\n",
	    major, minor, tmp->tm_mon+1, tmp->tm_mday, tmp->tm_year);
}
E 1
