h06069
s 00002/00002/00024
d D 5.2 86/03/09 19:59:42 donn 4 3
c added LIBC_SCCS condition for sccs ids
e
s 00004/00001/00022
d D 5.1 85/06/05 12:39:49 mckusick 3 1
c Add copyright
e
s 00001/00001/00022
d R 4.2 82/11/14 14:08:50 sam 2 1
c vfork is on the way out, don't perpetuate binaries w/ sys call
e
s 00023/00000/00000
d D 4.1 80/12/21 16:51:01 wnj 1 0
c date and time created 80/12/21 16:51:01 by wnj
e
u
U
t
T
I 1
D 3
/* %W% (Berkeley) %G% */
E 3
I 3
D 4
#ifndef lint
E 4
I 4
#if defined(LIBC_SCCS) && !defined(lint)
E 4
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif not lint
E 4
I 4
#endif LIBC_SCCS and not lint
E 4

E 3
#include	<signal.h>

system(s)
char *s;
{
	int status, pid, w;
	register int (*istat)(), (*qstat)();

	if ((pid = vfork()) == 0) {
		execl("/bin/sh", "sh", "-c", s, 0);
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
}
E 1
