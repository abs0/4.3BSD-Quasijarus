h31260
s 00007/00001/00072
d D 5.1 85/06/07 23:29:25 kre 6 5
c Add copyright
e
s 00044/00001/00029
d D 1.5 83/04/30 17:27:41 dlw 5 4
c allows NCARGS-50 string; uses SHELL if found. DLW
e
s 00003/00002/00027
d D 1.4 81/02/19 10:57:11 dlw 4 3
c fixed call to flush_(). DLW
e
s 00006/00001/00023
d D 1.3 81/02/17 19:29:10 dlw 3 2
c added null termination to command. DLW
e
s 00006/00000/00018
d D 1.2 81/02/15 17:53:34 dlw 2 1
c Added flushing of all lu's before the exec. DLW
e
s 00018/00000/00000
d D 1.1 81/02/10 14:00:09 dlw 1 0
c date and time created 81/02/10 14:00:09 by dlw
e
u
U
t
T
I 1
/*
D 6
char id_system[] = "%W%";
E 6
I 6
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
 *
I 6
 *	%W%	%G%
 */

/*
E 6
 * execute a unix command
 *
 * calling sequence:
 *	iexit = system(command)
 * where:
 *	iexit will return the exit status of the command
 *	command is a character string containing the command to be executed
 */

I 2
#include	"../libI77/fiodefs.h"
I 3
#include	"../libI77/f_errno.h"
I 5
#include <sys/param.h>
#ifndef	NCARGS
#define NCARGS	256
#endif
E 5
E 3

 
E 2
long system_(s, n)
char *s;
long n;
{
I 3
D 5
	char buf[256];
E 5
I 5
	char buf[NCARGS - 50];
E 5
E 3
I 2
D 4
	int i;
E 4
I 4
	long i;
E 4

I 3
	if (n >= sizeof buf)
		return(-(long)(errno=F_ERARG));
E 3
D 4
	for (i = 0; i < MXUNIT; flush(i++)) ;
E 4
I 4
	for (i = 0; i < MXUNIT; i++)
		flush_(&i);
E 4
E 2
D 3
	return((long)system(s));
E 3
I 3
	g_char(s, n, buf);
	return((long)system(buf));
I 5
}

/*
 * this is a sane version of the libc/stdio routine.
 */

#include	<signal.h>

char	*getenv();
char	*rindex();

system(s)
char *s;
{
	register int (*istat)(), (*qstat)();
	int status, pid, w;
	char	*shname, *shell;

	if ((shell = getenv("SHELL")) == NULL)
		shell = "/bin/sh";

	if (shname = rindex(shell, '/'))
		shname++;
	else
		shname = shell;

	if ((pid = fork()) == 0) {
		execl(shell, shname, "-c", s, 0);
		_exit(127);
	}
	istat = signal(SIGINT, SIG_IGN);
	qstat = signal(SIGQUIT, SIG_IGN);
	while ((w = wait(&status)) != pid && w != -1)
		;
	if (w == -1)
		status = -1;
	signal(SIGINT, istat);
	signal(SIGQUIT, qstat);
	return(status);
E 5
E 3
}
E 1
