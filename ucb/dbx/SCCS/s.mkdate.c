h42291
s 00010/00026/00028
d D 5.3 88/01/12 00:56:43 donn 8 7
c merge in latest Linton version
e
s 00001/00000/00053
d D 5.2 87/08/30 09:08:47 bostic 7 6
c add exit(0); bug report 4.3BSD/ucb/107
e
s 00008/00002/00045
d D 5.1 85/05/31 10:06:37 dist 6 5
c Add copyright
e
s 00002/00000/00045
d D 1.4 85/03/01 20:25:57 linton 5 4
c update to version 3.0
e
s 00001/00001/00044
d D 1.3 84/06/23 11:41:53 sam 4 2
i 3
c merge linton branch delta trail
e
s 00023/00001/00022
d D 1.2.1.1 84/06/23 10:47:50 sam 3 2
c branch delta of linton changes from net.sources
e
s 00001/00001/00022
d D 1.2 83/07/03 12:45:48 sam 2 1
c include fix
e
s 00023/00000/00000
d D 1.1 83/03/31 00:22:53 linton 1 0
c date and time created 83/03/31 00:22:53 by linton
e
u
U
f b 
t
T
I 1
D 6
/* Copyright (c) 1982 Regents of the University of California */
E 6
I 6
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 6

D 3
static char sccsid[] = "%Z%%M% %I% %G%";
E 3
I 3
D 4
static char rcsid[] = "$Header: mkdate.c,v 1.3 84/03/27 10:21:59 linton Exp $";
E 4
I 4
D 6
static	char sccsid[] = "%W% (Berkeley) %G%";
E 6
I 6
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 6
E 4
E 3

I 5
D 8
static char rcsid[] = "$Header: mkdate.c,v 1.5 84/12/26 10:40:30 linton Exp $";
E 8
I 8
static char rcsid[] = "$Header: mkdate.c,v 1.2 87/03/26 19:56:22 donn Exp $";
E 8

E 5
#include <stdio.h>
D 2
#include <time.h>
E 2
I 2
D 8
#include <sys/time.h>
E 8
I 8
#ifdef IRIS
#   include <time.h>
#else
#   include <sys/time.h>
#endif
E 8
E 2

main()
{
    struct tm *t;
    long clock;
    char name[100];
    int namelen;

    printf("char *date = \"");
    clock = time(0);
    t = localtime(&clock);
    printf("%d/%d/%d ", t->tm_mon + 1, t->tm_mday, t->tm_year % 100);
    printf("%d:%02d", t->tm_hour, t->tm_min);
D 8
    gethostname(name, &namelen);
    printf(" (%s)", name);
E 8
I 8
#   ifndef IRIS
	gethostname(name, &namelen);
	printf(" (%s)", name);
#   endif
E 8
    printf("\";\n");
I 3
D 8
    DoVersionNumber();
E 8
I 7
    exit(0);
E 7
D 8
}

DoVersionNumber()
{
    FILE *f;
    int n;

    f = fopen("version", "r");
    if (f == NULL) {
	n = 1;
    } else {
	fscanf(f, "%d", &n);
	n = n + 1;
	fclose(f);
    }
    f = fopen("version", "w");
    if (f != NULL) {
	fprintf(f, "%d\n", n);
	fclose(f);
    }
    printf("int versionNumber = %d;\n", n);
E 8
E 3
}
E 1
