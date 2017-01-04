h61324
s 00001/00001/00028
d D 4.3 86/05/15 17:58:38 bloom 3 2
c updates from John Kunze
e
s 00007/00002/00022
d D 4.2 83/04/25 23:58:58 mckusick 2 1
c 
e
s 00024/00000/00000
d D 4.1 83/02/24 12:55:57 mckusick 1 0
c date and time created 83/02/24 12:55:57 by mckusick
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%G%";
#endif not lint

#include "stdio.h"

makpipe()
{
	int f[2];

	pipe(f);
	if (fork()==0) {
		close(f[1]);
		close(0);
		dup(f[0]);
		close(f[0]);
I 2
D 3
#if vax
E 3
I 3
#if BSD4_2
E 3
E 2
		execl ("/bin/sh", "sh", "-i", 0);
D 2
		execl ("/usr/bin/sh", "sh", "-i", 0);
		write(2,"Exec error\n",11);
E 2
I 2
		execl ("/usr/ucb/bin/sh", "sh", "-i", 0);
#else
		execlp("/bin/csh", "csh", "-if", 0);
		/*execl ("/usr/ucb/bin/csh", "csh", "-if", 0);*/
#endif
		write(2, "Exec error\n", 11);
E 2
	}
	close(f[0]);
	sleep(2);	/* so shell won't eat up too much input */
	return(f[1]);
}
E 1
