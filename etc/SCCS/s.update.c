h57947
s 00031/00018/00022
d D 4.3 87/03/28 11:15:24 bostic 3 2
c just hacking
e
s 00003/00000/00037
d D 4.2 80/10/16 01:07:31 bill 2 1
c open more directories
e
s 00037/00000/00000
d D 4.1 80/10/01 17:29:14 bill 1 0
c date and time created 80/10/01 17:29:14 by bill
e
u
U
t
T
I 1
D 3
static char *sccsid = "%W% (Berkeley) %G%";
E 3
/*
I 3
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

/*
E 3
 * Update the file system every 30 seconds.
 * For cache benefit, open certain system directories.
 */

D 3
#include <signal.h>
E 3
I 3
#include <sys/time.h>
#include <sys/file.h>
#include <sys/signal.h>
#include <syslog.h>
#include <stdio.h>
E 3

char *fillst[] = {
	"/bin",
I 2
	"/lib",
E 2
	"/usr",
	"/usr/bin",
I 2
	"/usr/lib",
	"/usr/ucb",
E 2
	0,
};

main()
{
D 3
	char **f;
E 3
I 3
	struct itimerval	value;
	register char	**f;
	extern int	sync();
E 3

D 3
	if(fork())
E 3
I 3
	if (fork())
E 3
		exit(0);
D 3
	close(0);
	close(1);
	close(2);
	for(f = fillst; *f; f++)
		open(*f, 0);
	dosync();
	for(;;)
E 3
I 3
	(void)close(0);
	(void)close(1);
	(void)close(2);
	for (f = fillst; *f; f++)
		(void)open(*f, O_RDONLY, 0);
	(void)signal(SIGALRM, sync);
	value.it_interval.tv_sec = 30;
	value.it_interval.tv_usec = 0;
	value.it_value = value.it_interval;
	if (setitimer(ITIMER_REAL, &value, (struct itimerval *)NULL)) {
		perror("update: setitimer");
		exit(1);
	}
	for (;;)
E 3
		pause();
D 3
}

dosync()
{
	sync();
	signal(SIGALRM, dosync);
	alarm(30);
E 3
I 3
	/*NOTREACHED*/
E 3
}
E 1
