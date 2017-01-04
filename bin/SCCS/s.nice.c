h61495
s 00002/00001/00042
d D 5.2 86/01/12 02:04:42 lepreau 4 3
c nice is relative
e
s 00014/00002/00029
d D 5.1 85/04/30 15:05:02 dist 3 2
c Add copyright
e
s 00015/00011/00016
d D 4.2 83/05/22 18:16:13 sam 2 1
c replace nice with setpriority
e
s 00027/00000/00000
d D 4.1 80/10/01 17:27:39 bill 1 0
c date and time created 80/10/01 17:27:39 by bill
e
u
U
t
T
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 3
I 2
#ifndef lint
E 2
I 1
D 3
static char *sccsid = "%W% (Berkeley) %G%";
D 2
/* nice */
E 2
I 2
#endif
E 3
I 3
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 3
E 2

#include <stdio.h>

I 2
#include <sys/time.h>
#include <sys/resource.h>

E 2
main(argc, argv)
D 2
int argc;
char *argv[];
E 2
I 2
	int argc;
	char *argv[];
E 2
{
	int nicarg = 10;
D 2
	extern errno;
	extern char *sys_errlist[];
E 2

D 2
	if(argc > 1 && argv[1][0] == '-') {
E 2
I 2
	if (argc > 1 && argv[1][0] == '-') {
E 2
		nicarg = atoi(&argv[1][1]);
D 2
		argc--;
		argv++;
E 2
I 2
		argc--, argv++;
E 2
	}
D 2
	if(argc < 2) {
E 2
I 2
	if (argc < 2) {
E 2
		fputs("usage: nice [ -n ] command\n", stderr);
		exit(1);
	}
D 2
	nice(nicarg);
E 2
I 2
D 4
	if (setpriority(PRIO_PROCESS, 0, nicarg) < 0) {
E 4
I 4
	if (setpriority(PRIO_PROCESS, 0, 
	    getpriority(PRIO_PROCESS, 0) + nicarg) < 0) {
E 4
		perror("setpriority");
		exit(1);
	}
E 2
	execvp(argv[1], &argv[1]);
D 2
	fprintf(stderr, "%s: %s\n", sys_errlist[errno], argv[1]);
E 2
I 2
	perror(argv[1]);
E 2
	exit(1);
}
E 1
